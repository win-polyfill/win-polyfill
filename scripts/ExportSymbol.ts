import * as fs from 'fs/promises';
export interface DllExport {
  name: string;
  ordinal: number;
  hint: number;
  rva: number;
}
export interface LibExport {
  ordinal?: number;
  name: string;
}

export interface LibPublicSymbol {
  offset: number;
  name: string;
}

export type LibSymbolNameType = "undecorate" | "ordinal" | "name" | "no prefix";

export interface LibSymbol {
  offset: number;
  version: number;
  machine: number;
  timeDateStamp: number;
  sizeOfData: number;
  dllName: string;
  symbolName: string;
  type: string;
  nameType: LibSymbolNameType;
  ordinal?: number;
  hint?: number;
  name?: string;
}

export function StringToLibSymbolNameType(str: string): LibSymbolNameType {
  if (str === "undecorate") {
    return "undecorate";
  }
  if (str === "ordinal") {
    return "ordinal";
  }
  if (str === "name") {
    return "name";
  }
  if (str === "no prefix") {
    return "no prefix";
  }
  throw new Error(`Invalid name type: ${str}`);
}

export interface ExportSymbolResult {
  dllExports: DllExport[];
  libExports: LibExport[];
  libPublicSymbols: LibPublicSymbol[];
  libSymbols: LibSymbol[];
}

export function extractValue(str: string, key: string): string {
  // *  "  Version      : 0",
  const keyLength = 15;
  const strKey = str.slice(0, keyLength).trim();
  if (strKey !== key) {
    throw new Error(`Invalid ${str} for ${key}`);
  }
  return str.slice(keyLength + 1).trim();
}

export function newExportSymbolResult(): ExportSymbolResult {
  return {
    dllExports: [],
    libExports: [],
    libPublicSymbols: [],
    libSymbols: [],
  };
}

export function parseArchiveMember(
  result: ExportSymbolResult,
  archiveMember: string[]
) {
  if (archiveMember[0] === "    ordinal hint RVA      name") {
    // parse dll exports
    for (let j = 2; j < archiveMember.length - 1; j += 1) {
      /**
       * `    ordinal hint RVA      name`
       * `          3    0 0001DD15 AccessibleChildren`
       */
      const ordinalSepPos = 11;
      const hintSepPos = 16;
      const rvaSepPos = 26;
      const ordinalString = archiveMember[j].slice(0, ordinalSepPos);
      const hintString = archiveMember[j].slice(ordinalSepPos, hintSepPos);
      const rvaString = archiveMember[j].slice(hintSepPos, rvaSepPos);
      const name = archiveMember[j].slice(rvaSepPos);
      const ordinal: number = parseInt(ordinalString, 10);
      const dllExport: DllExport = {
        name,
        ordinal,
        hint: parseInt(hintString, 16),
        rva: parseInt(rvaString, 16),
      };
      result.dllExports.push(dllExport);
    }
  } else if (archiveMember[0] === "     Exports") {
    // parse exports
    for (let j = 4; j < archiveMember.length - 1; j += 1) {
      const ordinalSepPos = 18;
      const ordinalString = archiveMember[j].slice(0, ordinalSepPos);
      const name = archiveMember[j].slice(ordinalSepPos);
      let ordinal: number | undefined = parseInt(ordinalString, 10);
      const libExport: LibExport = {
        name,
      };
      if (!Number.isNaN(ordinal)) {
        libExport.ordinal = ordinal;
        ordinal = undefined;
      }
      result.libExports.push(libExport);
    }
  } else if (archiveMember.length >= 9) {
    const identity = archiveMember[8];
    if (identity.indexOf("public symbols") > 0) {
      for (let j = 10; j < archiveMember.length - 1; j += 1) {
        const [offsetString, name] = archiveMember[j].trim().split(" ");
        result.libPublicSymbols.push({
          offset: parseInt(offsetString, 16),
          name,
        });
      }
    } else if (identity === "FILE HEADER VALUES") {
      // ignore
    } else if (identity.startsWith("  Version      :")) {
      /**
       * Parsing the following archive member
       * "Archive member name at B04: ACLUI.dll/      ",
       * "FFFFFFFF time/date",
       *  "         uid",
       *  "         gid",
       *  "       0 mode",
       *  "      38 size",
       *  "correct header end",
       *  "",
       *  "  Version      : 0",
       *  "  Machine      : 14C (x86)",
       *  "  TimeDateStamp: FBF21643",
       *  "  SizeOfData   : 00000024",
       *  "  DLL name     : ACLUI.dll",
       *  "  Symbol name  : _IID_ISecurityInformation",
       *  "  Type         : code",
       *  "  Name type    : ordinal",
       *  "  Ordinal      : 16",
       *  ""
       *  "  Name type    : name",
       *  "  Hint         : 0",
       *  "  Name         : ??0BUFFER@@QAE@I@Z",
       */
      try {
        const newSymbol: LibSymbol = {
          offset: parseInt(archiveMember[0].split(":")[0].slice(23), 16),
          version: parseInt(extractValue(archiveMember[8], "Version"), 10),
          machine: parseInt(extractValue(archiveMember[9], "Machine"), 16),
          timeDateStamp: parseInt(
            extractValue(archiveMember[10], "TimeDateStamp"),
            16
          ),
          sizeOfData: parseInt(
            extractValue(archiveMember[11], "SizeOfData"),
            16
          ),
          dllName: extractValue(archiveMember[12], "DLL name"),
          symbolName: extractValue(archiveMember[13], "Symbol name"),
          type: extractValue(archiveMember[14], "Type"),
          nameType: StringToLibSymbolNameType(
            extractValue(archiveMember[15], "Name type")
          ),
        };
        if (newSymbol.nameType === "ordinal") {
          newSymbol.ordinal = parseInt(
            extractValue(archiveMember[16], "Ordinal"),
            10
          );
        } else {
          newSymbol.hint = parseInt(
            extractValue(archiveMember[16], "Hint"),
            10
          );
          newSymbol.name = extractValue(archiveMember[17], "Name");
        }
        result.libSymbols.push(newSymbol);
      } catch (error) {
        console.log(error);
        throw error;
      }
    }
  }
}

export async function readJson(p: string) {
  const content = await fs.readFile(p, { encoding: 'utf-8' });
  return JSON.parse(content);
}
