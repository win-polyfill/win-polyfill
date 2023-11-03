/* eslint-disable no-continue */
import * as path from 'path';
import * as fs from 'fs/promises';
import { exec } from '@esutils/process';

import { parseArchiveMember, newExportSymbolResult, ExportSymbolResult, readJson } from './ExportSymbol';

export { parseArchiveMember, newExportSymbolResult } from './ExportSymbol';

function findFilenameInFiles(files: string[], filename: string, ext?: string) {
  for (let j = 0; j < files.length; j += 1) {
    const thisFilename = path.basename(files[j].toLowerCase(), ext);
    if (thisFilename === filename) {
      return true;
    }
  }
  return false;
}

export async function getLibList(
  WinXpRtmDllDir: string,
  WinXpSp1LibDir: string,
  WinSdkLibDir: string,
) {
  const dllFiles = await fs.readdir(WinXpRtmDllDir);
  const libFiles = await fs.readdir(WinXpSp1LibDir);
  const libFilesNew = await fs.readdir(path.join(WinSdkLibDir));
  const result: string[] = [];
  for (let i = 0; i < libFiles.length; i += 1) {
    const libFile = libFiles[i].toLowerCase();
    if (libFile.endsWith('.lib')) {
      const libFilename = path.basename(libFile, '.lib');
      if (
        findFilenameInFiles(dllFiles, libFilename, '.dll')
        && findFilenameInFiles(libFilesNew, libFilename, '.lib')
      ) {
        result.push(libFilename);
      }
    }
  }
  return result;
}

export interface WinLibEntry {
  index: number;
  offset: number;
  names: string[];
  objectIndex?: number;
  objectName?: string; // dll for shared library and .o for static library
  exportName?: string;
  exportRaw?: string;
  ordinal?: number;
}

function parseSymbols(exportContent: string) {
  const exportItems = exportContent.split('\r\n');
  const archiveMembers: string[][] = [];
  let currentArhiveMember: string[] = [];
  for (let i = 0; i < exportItems.length; i += 1) {
    const exportItem = exportItems[i];
    if (exportItem === '  Summary') {
      break;
    }
    if (
      exportItem === '     Exports'
      || exportItem === '    ordinal hint RVA      name'
      || exportItem.startsWith('Archive member name at ')
    ) {
      currentArhiveMember = [exportItem];
      archiveMembers.push(currentArhiveMember);
    } else {
      currentArhiveMember.push(exportItem);
    }
  }
  const result = newExportSymbolResult();
  for (let i = 0; i < archiveMembers.length; i += 1) {
    parseArchiveMember(result, archiveMembers[i]);
  }
  return result;
}

async function getExports(
  filePath: string,
  outputDir: string,
  outputFile: string,
): Promise<string> {
  const args: string[] = [];
  if (filePath.toLowerCase().endsWith('.lib')) {
    Array.prototype.push.apply(args, [
      '-ARCHIVEMEMBERS',
      '-LINKERMEMBER:1',
      '-HEADERS',
      '-EXPORTS',
    ]);
    args.push();
  } else {
    Array.prototype.push.apply(args, ['-EXPORTS']);
  }
  args.push(filePath);
  const result = await exec('dumpbin', args, 'gbk', {
    maxBuffer: 1024 * 1024 * 64,
  });
  await fs.writeFile(
    `${outputDir}/txt/${outputFile}.txt`,
    result.stdout,
  );
  const exportsXpDllEntries = parseSymbols(result.stdout);
  await fs.writeFile(
    `${outputDir}/json/${outputFile}.json`,
    JSON.stringify(exportsXpDllEntries, null, 2),
  );
  return result.stdout;
}

async function generateDefFile(objectFileDir: string, outputDir: string) {
  const files = await fs.readdir(objectFileDir);
  const promises: Promise<string>[] = [];
  for (let i = 0; i < files.length; i += 1) {
    const libFile = files[i].toLowerCase();
    const extName = path.extname(libFile);
    if (extName === '.lib' || extName === '.dll') {
      promises.push(
        getExports(
          path.join(objectFileDir, libFile),
          outputDir,
          `${path.basename(libFile, extName)}`,
        ),
      );
    }
  }
  await Promise.all(promises);
}

function setupPath() {
  process.env.PATH = `C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin;${process.env.PATH}`;
}

export async function main(rootDir: string) {
  setupPath();
  const results: Promise<void>[] = [];
  const arch = 'x86'
  const objectFileDir =`C:/Program Files (x86)/Windows Kits/10/Lib/10.0.20348.0/um/${arch}`
  const outputDir = `${rootDir}/exports/win-10.0.20348.0-${arch}`
  results.push(generateDefFile(objectFileDir, outputDir));
  await Promise.all(results);

  // console.log(`Generate sdk ${result.stdout}`);
}

main(path.join(__dirname, '..'))


const BlockList = [
  '_GetScaleFactorForWindow@8',
  '_SHGetSpecialFolderPath@16',
];

/* eslint-disable no-await-in-loop */
export async function merge(rootDir: string, name: string, deps: string[]) {
  setupPath();
  const symbolResultForDeps: ExportSymbolResult[] = [];
  for (let i = 0; i < deps.length; i += 1) {
    const p = path.join(rootDir, 'exports', 'x86', 'json', `${name}--${deps[i]}.json`);
    let hasPath = true;
    try {
      await fs.access(p);
    } catch (error) {
      hasPath = false;
    }

    if (hasPath) {
      const j = (await readJson(p)) as ExportSymbolResult;
      symbolResultForDeps.push(j);
    }
  }
  const ordinalToName = new Map<number, Set<string>>();
  for (let i = 0; i < symbolResultForDeps.length; i += 1) {
    const symbolResult = symbolResultForDeps[i];
    for (let j = 0; j < symbolResult.dllExports.length; j += 1) {
      const dllExport = symbolResult.dllExports[j];
      [dllExport.name] = dllExport.name.split(' ');
      if (dllExport.name !== '[NONAME]') {
        if (!ordinalToName.has(dllExport.ordinal)) {
          ordinalToName.set(dllExport.ordinal, new Set<string>());
        }
        ordinalToName.get(dllExport.ordinal)!.add(dllExport.name);
      }
    }
  }

  const symbols = new Map<string, ExportSymbolResult>();

  for (let i = 0; i < symbolResultForDeps.length; i += 1) {
    const symbolResult = symbolResultForDeps[i];
    for (let j = 0; j < symbolResult.libSymbols.length; j += 1) {
      const libSymbol = symbolResult.libSymbols[j];
      if (libSymbol.dllName !== '') {
        if (BlockList.indexOf(libSymbol.symbolName) >= 0) {
          continue;
        }
        let symbolName = libSymbol.name;
        if (libSymbol.nameType === 'ordinal') {
          const names = ordinalToName.get(libSymbol.ordinal!);
          if (names) {
            if (names.size !== 1) {
              console.log(`There is multiple name for ordinal in ${name}:${deps[i]} ord:${libSymbol.ordinal} ${libSymbol.symbolName} with ${Array.from(names.values())}`);
            }
            const namesArray = Array.from(names.values());
            symbolName = namesArray[namesArray.length - 1];
          } else {
            symbolName = undefined;
          }
        }
        if (!symbolName) {
          console.log(`Can not found original name in ${name}:${deps[i]} ord:${libSymbol.ordinal} ${libSymbol.symbolName}`);
          symbolName = libSymbol.symbolName;
        }
        if (symbolName) {
          if (!symbols.has(symbolName)) {
            symbols.set(symbolName, newExportSymbolResult());
          }
          symbols.get(symbolName)!.libSymbols.push(libSymbol);
        }
      }
    }
  }
  const mergedPath = path.join(rootDir, 'exports', 'x86', 'merged', `${name}.json`);
  const entries = Array.from(symbols.entries());
  await fs.writeFile(mergedPath, JSON.stringify(entries, null, 2));
}
