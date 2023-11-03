import * as fs from 'fs/promises'
import * as path from 'path'

interface Win32ApiEntry {
  file?: string
  lib: string
  size: number
  name: string
  isPolyfill: boolean
}

interface Win32ModuleEntry {
  name: string
}

function genModuleEnumName(name: string) {
  return  name[0].toUpperCase() + name.slice(1)
}

function gen_try_get_function(functino_name: string, module_name: string, isPolyfill: boolean) {
  let function_full_name = `::${functino_name}`
  if (isPolyfill) {
      function_full_name = `YY::Thunks::wp_${functino_name}`
  }
return `
            decltype(&${function_full_name}) try_get_${functino_name}()
            {
                static internal::WinPolyfillFunction function_info;
                return (decltype(&${function_full_name}))try_get_function(
                        &function_info, "${functino_name}",
                        WinPolyfillModuleId::WinPolyfillModuleId${genModuleEnumName(module_name)});
            }`
}

function get_try_get_module(module_enum_name: string, module_path: string) {
return `
    case WinPolyfillModuleId::WinPolyfillModuleId${module_enum_name}: {
      return try_get_module_by_name(module_id, L"${module_path}.dll");
    }`
}

async function loadPolyfillList(
  rootDir: string,
  polyfillList: Win32ApiEntry[],
  filename: string
) {
  // console.log(filename)
  const cppFilePath = path.join(rootDir, "src", "Thunks", filename);
  const content = await fs.readFile(cppFilePath, "utf8");
  const regexp =
    /__DEFINE_THUNK\(\s*([^,\s]*)\s*,\s*([^,\s]*)\s*,\s*([^,]*)\s*,\s*([^,\s]*)\s*,\s*([^,\s]*)\s*,/gm;

  for (let item of content.matchAll(regexp)) {
    // console.log(item[1], item[2], item[3], item[4], item[5])
    polyfillList.push({
      file: filename,
      name: item[5],
      lib: item[1].toLowerCase(),
      size: parseInt(item[2]),
      isPolyfill: true,
    });
  }
}

async function gen(rootDir: string) {
  const apiJsonPath = path.join(rootDir, 'src', 'Thunks', 'api.json')
  const content = await fs.readFile(apiJsonPath, 'utf8')
  const apiInfo = JSON.parse(content)
  const polyfillList: Win32ApiEntry[] = []
  const moduleNameMapping = apiInfo.moduleNameMapping
  for (let filename of apiInfo.polyfillList) {
    await loadPolyfillList(rootDir, polyfillList, filename)
  }
  const apiLoadList: Win32ApiEntry[] = apiInfo.loadList;
  const apiList: Win32ApiEntry[] = Array.prototype.concat(apiLoadList, polyfillList)
  const moduleList: Win32ModuleEntry[] = []
  const moduleSet = new Set()
  for (let moduleName of apiInfo.preloadedModuleList as string[]) {
    if (!moduleSet.has(moduleName)) {
      moduleSet.add(moduleName)
      moduleList.push({
        name: moduleName,
      })
    }
  }
  const modulePreloadedCount = moduleList.length;
  const generatedFunctionGetList: string[] = []
  const generatedFunctionEnumList: string[] = []
  for (let item of apiList) {
    generatedFunctionGetList.push(gen_try_get_function(item.name, item.lib, item.isPolyfill))
    generatedFunctionEnumList.push(`                WinPolyfillFunctionId${item.name},`)
    if (!moduleSet.has(item.lib)) {
      moduleSet.add(item.lib)
      moduleList.push({
        name: item.lib,
      })
    }
  }
  let generatedFunctionDefineList: string[] = []
  for (let item of apiLoadList) {
    generatedFunctionDefineList.push(`#define ${item.name} try_get_${item.name}()`)
  }
  generatedFunctionDefineList.push('')
  let generatedExportDefList: string[] = []
  for (let item of polyfillList) {
    generatedFunctionDefineList.push(`#define ${item.name} wp_${item.name}`)
    generatedExportDefList.push(`    wp_${item.name}`)
  }
  generatedFunctionEnumList.push(`                WinPolyfillFunctionIdCount,`)
  const generateModuleEnumList: string[] = []
  const generateModuleGetList: string [] = []
  for (let module of moduleList) {
    const module_enum_name = genModuleEnumName(module.name)
    let module_path = moduleNameMapping[module.name]
    if (!module_path) {
      module_path = module.name
    }
    generateModuleEnumList.push(`                WinPolyfillModuleId${module_enum_name},`)
    generateModuleGetList.push(get_try_get_module(module_enum_name, module_path))
  }
  generateModuleEnumList.push(`                WinPolyfillModuleIdCount,`)

  const apiIdHeaderContent: string = `\ufeff
#pragma once
namespace YY
{
    namespace Thunks
    {
        namespace internal {
            enum WinPolyfillModuleId
            {
${generateModuleEnumList.join('\n')}
            };
            constexpr int WinPolyfillModuleIdPreloadCount = ${modulePreloadedCount};

            enum WinPolyfillFunctionId
            {
${generatedFunctionEnumList.join('\n')}
            };
        }
    }
}
`
  const apiIdHeaderPath = path.join(rootDir, 'src', 'Thunks', 'win-polyfill-id.h')
  await fs.writeFile(apiIdHeaderPath, apiIdHeaderContent, {
      encoding: 'utf-8'
  })

  console.log(`Write to ${apiIdHeaderPath} finished`)

  const apiGetHeaderContent: string = `\ufeff
#pragma once
#include "win-polyfill.h"
#include "win-polyfill-id.h"

using YY::Thunks::internal::WinPolyfillModule;
using YY::Thunks::internal::WinPolyfillModuleId;
using YY::Thunks::internal::WinPolyfillFunction;
using YY::Thunks::internal::WinPolyfillFunctionId;

static void *__fastcall try_get_function(WinPolyfillFunction *function_info, const char *name, WinPolyfillModuleId module_id) noexcept;
static HMODULE __fastcall try_get_module_by_name(WinPolyfillModuleId module_id, const wchar_t *name) noexcept;

static HMODULE try_get_module(WinPolyfillModuleId module_id) noexcept
{
    switch (module_id) {${generateModuleGetList.join('')}
    default: break;
    }
    return nullptr;
}

namespace YY
{
    namespace Thunks
    {
        namespace TryGet
        {${generatedFunctionGetList.join('\n')}
        }
    }
}

${generatedFunctionDefineList.join('\n')}
`
  const apiGetHeaderPath = path.join(rootDir, 'src', 'Thunks', 'win-polyfill-get.h')
  await fs.writeFile(apiGetHeaderPath, apiGetHeaderContent, {
      encoding: 'utf-8'
  })
  console.log(`Write to ${apiGetHeaderPath} finished`)

  const apiExportDefContent = `EXPORTS
${generatedExportDefList.join('\n')}
`

  /*
  const apiExportDefPath = path.join(rootDir, 'src', 'Thunks', 'win-polyfill.def')
  await fs.writeFile(apiExportDefPath, apiExportDefContent, {
    encoding: 'utf-8'
  })
  console.log(`Write to ${apiExportDefPath} finished`)
  */

}

gen(path.join(__dirname, ".."))
const list: string[] = [
    "__WSAFDIsSet",
    "select",
    "WSASetLastError",
]

function genLibList(names: string[], lib: string) {
    const result:any[] = []
    for (let item_name of names) {
        result.push({
            lib: lib,
            name: item_name
        })
    }
    console.log(JSON.stringify(result, null, 2))
}

genLibList(list, 'ws2_32')
