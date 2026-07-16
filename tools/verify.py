#!/usr/bin/env python3
"""Repo-wide match verifier for the Persona 4 USA decompilation.

For every ``// FUN_xxxxxxxx`` marker in ``src/**/*.c`` this tool selects the
containing source unit (or compiles the ordinary translation unit) with the
configured MWCC compiler, extracts the marked function and its MIPS relocations
from the relocatable object, masks relocated fields, and
compares the remaining bytes with retail ``SLUS_217.82``.

Configuration precedence (highest first): ``P4_MWCC`` / ``P4_RETAIL_ELF``
environment variables, ``tools/verify_config.local.json`` (gitignored), then
``tools/verify_config.json`` (committed).  The committed file deliberately
contains no machine-specific absolute paths.
"""
from __future__ import annotations

import argparse
import bisect
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"
FUNCTION_WINDOWS = TOOLS / "slus21782_functions.json"
TARGET = REPO / "config" / "target.json"

R_MIPS_NAMES = {
    1: "R_MIPS_16", 2: "R_MIPS_32", 3: "R_MIPS_REL32", 4: "R_MIPS_26",
    5: "R_MIPS_HI16", 6: "R_MIPS_LO16", 7: "R_MIPS_GPREL16",
    8: "R_MIPS_LITERAL", 9: "R_MIPS_GOT16", 10: "R_MIPS_PC16",
    11: "R_MIPS_CALL16", 12: "R_MIPS_GPREL32",
}
# Relocated fields are linker-owned and therefore not a compiler-match signal.
RELOC_MASK_SIZE = {2: 4, 4: 4, 5: 2, 6: 2, 7: 2}
MARKER_RE = re.compile(r"^\s*//\s*(FUN_([0-9a-fA-F]{8}))", re.MULTILINE)
NAME_RE = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*\(")
UNIT_GUARD_RE = re.compile(r"^\s*#if\s+defined\(P4_UNIT_([0-9a-fA-F]{8})\)\s*$")

def is_generated(path: Path) -> bool:
    try:
        relative = path.relative_to(REPO / "src")
    except ValueError:
        relative = path
    return (
        path.name.endswith(".match.c")
        or path.name.startswith(".permute_")
        or any(part.startswith("generated") for part in relative.parts)
    )


def source_units(cpath: Path) -> list[int]:
    """Return selectable function addresses for a consolidated C source."""
    lines = cpath.read_text(errors="replace").splitlines()
    units: list[int] = []
    for index, line in enumerate(lines):
        guard = UNIT_GUARD_RE.match(line)
        if not guard:
            continue
        address = int(guard.group(1), 16)
        end = next(
            (cursor for cursor in range(index + 1, len(lines))
             if re.match(r"^\s*#endif\b", lines[cursor])),
            None,
        )
        if end is None:
            raise ValueError(f"unterminated P4_UNIT guard in {cpath}")
        body = "\n".join(lines[index + 1:end])
        markers = MARKER_RE.findall(body)
        if not markers or int(markers[0][1], 16) != address:
            raise ValueError(f"invalid P4_UNIT body in {cpath} at {address:08x}")
        units.append(address)
    return units


def _die(message: str) -> None:
    raise SystemExit(f"verify: {message}")


def _read_json(path: Path) -> dict:
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        _die(f"cannot read {path.relative_to(REPO)}: {error}")


def _parse_int(value: int | str) -> int:
    return value if isinstance(value, int) else int(value, 0)


def load_config() -> dict:
    """Load committed defaults, then local overrides, then P4 environment."""
    cfg: dict = {}
    for name in ("verify_config.json", "verify_config.local.json"):
        path = TOOLS / name
        if path.is_file():
            loaded = _read_json(path)
            if not isinstance(loaded, dict):
                _die(f"{name} must contain a JSON object")
            cfg.update(loaded)
    for key, env_name in (("mwcc", "P4_MWCC"), ("retail_elf", "P4_RETAIL_ELF")):
        if os.environ.get(env_name):
            cfg[key] = os.environ[env_name]
    missing = [key for key in ("mwcc", "retail_elf") if not cfg.get(key)]
    if missing:
        _die("missing config value(s): %s\n"
             "Set P4_MWCC / P4_RETAIL_ELF or create tools/verify_config.local.json, e.g.\n"
             '  {"mwcc": "D:/mwcc/mwccps2.exe",\n'
             '   "retail_elf": "D:/p4/SLUS_217.82"}' % ", ".join(missing))
    if not isinstance(cfg.get("compile_flags"), list) or not all(
            isinstance(flag, str) and flag for flag in cfg["compile_flags"]):
        _die("compile_flags must be a non-empty JSON string array")
    for key in ("mwcc", "retail_elf"):
        if not isinstance(cfg[key], str) or not Path(cfg[key]).is_file():
            _die(f"{key} does not exist: {cfg[key]}")
    return cfg


def _cstr(blob: bytes, offset: int) -> str:
    end = blob.find(b"\0", offset)
    return blob[offset:end if end >= 0 else len(blob)].decode("ascii", "replace")


def elf_sections(data: bytes) -> tuple[str, list[dict]]:
    if len(data) < 52 or data[:4] != b"\x7fELF":
        raise ValueError("not an ELF32 file")
    if data[4] != 1 or data[5] not in (1, 2):
        raise ValueError("unsupported ELF class or byte order")
    endian = "<" if data[5] == 1 else ">"
    header = struct.unpack_from(endian + "HHIIIIIHHHHHH", data, 16)
    shoff, shentsize, shnum, shstrndx = header[5], header[10], header[11], header[12]
    if not shnum:
        return endian, []
    if shentsize < 40 or shoff + shentsize * shnum > len(data) or shstrndx >= shnum:
        raise ValueError("invalid ELF section-header table")
    sections = []
    for index in range(shnum):
        fields = struct.unpack_from(endian + "IIIIIIIIII", data, shoff + index * shentsize)
        sections.append(dict(idx=index, name_off=fields[0], type=fields[1], flags=fields[2],
                             addr=fields[3], offset=fields[4], size=fields[5],
                             link=fields[6], info=fields[7], addralign=fields[8],
                             entsize=fields[9]))
    strings = sections[shstrndx]
    if strings["offset"] + strings["size"] > len(data):
        raise ValueError("invalid ELF section-name table")
    names = data[strings["offset"]:strings["offset"] + strings["size"]]
    for section in sections:
        section["name"] = _cstr(names, section["name_off"]) if section["name_off"] < len(names) else ""
    return endian, sections


class ObjectFile:
    """A relocatable ELF object with function-relative relocation records."""
    def __init__(self, path: Path):
        self.data = path.read_bytes()
        self.endian, self.sections = elf_sections(self.data)
        self.sh = self.sections  # Compatibility with the shared build/link planner.
        self.symtabs: dict[int, list[dict]] = {}
        self.symbols: list[dict] = []
        for section in self.sections:
            if section["type"] not in (2, 11):
                continue
            if section["link"] >= len(self.sections) or section["offset"] + section["size"] > len(self.data):
                raise ValueError("invalid ELF symbol table")
            strings = self.sections[section["link"]]
            blob = self.data[strings["offset"]:strings["offset"] + strings["size"]]
            entsize = section["entsize"] or 16
            if entsize < 16:
                raise ValueError("invalid ELF symbol size")
            symbols = []
            for index in range(section["size"] // entsize):
                offset = section["offset"] + index * entsize
                name, value, size, info, _other, shndx = struct.unpack_from(
                    self.endian + "IIIBBH", self.data, offset)
                symbols.append(dict(name=_cstr(blob, name) if name < len(blob) else "",
                                    value=value, size=size, shndx=shndx, info=info))
            self.symtabs[section["idx"]] = symbols
            self.symbols.extend(symbols)

    def function(self, name: str) -> tuple[bytes, list[dict]]:
        candidates = [symbol for symbol in self.symbols if symbol["name"] == name
                      and symbol["size"] and symbol["shndx"] not in (0, 0xFFF1)]
        if not candidates:
            raise KeyError(name)
        symbol = candidates[0]
        if symbol["shndx"] >= len(self.sections):
            raise ValueError(f"symbol {name} has invalid section index")
        section = self.sections[symbol["shndx"]]
        start, end = section["offset"] + symbol["value"], section["offset"] + symbol["value"] + symbol["size"]
        if end > len(self.data):
            raise ValueError(f"symbol {name} extends beyond object")
        relocations = []
        for relsec in self.sections:
            if relsec["type"] != 9 or relsec["info"] != section["idx"]:
                continue
            if relsec["link"] not in self.symtabs:
                raise ValueError("relocation section has no usable symbol table")
            entries = relsec["entsize"] or 8
            if entries < 8 or relsec["offset"] + relsec["size"] > len(self.data):
                raise ValueError("invalid ELF relocation table")
            symtab = self.symtabs[relsec["link"]]
            for index in range(relsec["size"] // entries):
                offset, info = struct.unpack_from(self.endian + "II", self.data, relsec["offset"] + index * entries)
                if symbol["value"] <= offset < symbol["value"] + symbol["size"]:
                    rtype, symidx = info & 0xff, info >> 8
                    relocations.append(dict(offset=offset - symbol["value"], r_type=rtype,
                        type=R_MIPS_NAMES.get(rtype, str(rtype)),
                        symbol=symtab[symidx]["name"] if symidx < len(symtab) else None))
        return self.data[start:end], relocations


class RetailElf:
    """Validated Persona 4 USA executable and addressable PT_LOAD segment."""
    def __init__(self, path: str, target: dict, expected_sha1: str):
        self.data = Path(path).read_bytes()
        elf = target["elf"]
        expected_size = int(elf["size"])
        if len(self.data) != expected_size:
            _die(f"retail ELF size mismatch: got {len(self.data)}, expected {expected_size}")
        actual_sha1 = hashlib.sha1(self.data).hexdigest()
        if actual_sha1 != expected_sha1:
            _die(f"retail ELF sha1 mismatch: got {actual_sha1}, expected {expected_sha1}")
        if len(self.data) < 52 or self.data[:4] != b"\x7fELF" or self.data[4:6] != b"\x01\x01":
            _die("retail ELF must be a 32-bit little-endian ELF")
        fields = struct.unpack_from("<HHIIIIIHHHHHH", self.data, 16)
        elf_type, machine, _version, entry, phoff = fields[:5]
        phentsize, phnum = fields[8], fields[9]
        if (elf_type, machine, entry) != (2, 8, _parse_int(elf["entry"])):
            _die("retail ELF type, machine, or entry point does not match target layout")
        if phentsize < 32 or phoff + phentsize * phnum > len(self.data):
            _die("retail ELF program-header table is malformed")
        expected = (_parse_int(elf["load_offset"]), _parse_int(elf["load_vram"]), _parse_int(elf["load_size"]))
        loads = []
        for index in range(phnum):
            load = struct.unpack_from("<IIIIIIII", self.data, phoff + index * phentsize)
            ptype, offset, vaddr, _paddr, filesz, memsz, flags, _align = load
            if ptype == 1 and filesz and flags & 1:
                if offset + filesz > len(self.data):
                    _die("retail ELF PT_LOAD extends beyond file")
                if vaddr <= entry < vaddr + memsz:
                    loads.append((vaddr, offset, filesz))
        if len(loads) != 1 or (loads[0][1], loads[0][0], loads[0][2]) != expected:
            _die("retail ELF executable PT_LOAD does not match P4 USA layout")
        self.segs = loads

    def bytes_at(self, address: int, size: int) -> bytes:
        for vaddr, offset, filesz in self.segs:
            if vaddr <= address and address + size <= vaddr + filesz:
                start = offset + address - vaddr
                return self.data[start:start + size]
        raise ValueError(f"address {address:#x}+{size:#x} not in retail PT_LOAD")


def strip_line_comment(line: str) -> str:
    return line.split("//", 1)[0]


def sanitize_c_lines(lines: list[str]) -> list[str]:
    """Blank comments/literals without changing line or brace structure."""
    output, state, escaped = [], "code", False
    for line in lines:
        chars, index = [], 0
        while index < len(line):
            char, next_char = line[index], line[index + 1] if index + 1 < len(line) else ""
            if state == "block":
                if char == "*" and next_char == "/":
                    chars.extend("  "); index += 2; state = "code"
                else:
                    chars.append(" "); index += 1
            elif state in ("string", "char"):
                chars.append(" ")
                if escaped: escaped = False
                elif char == "\\": escaped = True
                elif (state == "string" and char == '"') or (state == "char" and char == "'"):
                    state = "code"
                index += 1
            elif char == "/" and next_char == "/":
                chars.extend(" " * (len(line) - index)); index = len(line)
            elif char == "/" and next_char == "*":
                chars.extend("  "); index += 2; state = "block"
            elif char == '"': chars.append(" "); index += 1; state = "string"
            elif char == "'": chars.append(" "); index += 1; state = "char"
            else: chars.append(char); index += 1
        output.append("".join(chars))
        if state in ("string", "char") and not escaped: state = "code"
        escaped = False
    return output


def scan_markers(cpath: Path, unit: int | None = None) -> list[dict]:
    lines = cpath.read_text(errors="replace").splitlines()
    if unit is not None:
        selected: list[str] = []
        active = False
        for line in lines:
            guard = UNIT_GUARD_RE.match(line)
            if guard:
                active = int(guard.group(1), 16) == unit
                selected.append(line if active else "")
                continue
            if active and re.match(r"^\s*#endif\b", line):
                selected.append(line)
                active = False
                continue
            selected.append(line if active else "")
        lines = selected
    code_lines, markers, index = sanitize_c_lines(lines), [], 0
    while index < len(lines):
        marker = MARKER_RE.match(lines[index])
        if not marker:
            index += 1; continue
        address, name, cursor, header = int(marker.group(2), 16), None, index + 1, ""
        while cursor < len(lines) and cursor < index + 12:
            if MARKER_RE.match(lines[cursor]): break
            code = code_lines[cursor].strip()
            if not code.startswith("#"):
                header += " " + code
                if "{" in header: break
            cursor += 1
        address_name = re.search(
            rf"\b(?:func|FUN)_{address:08x}\s*\(", header, flags=re.IGNORECASE
        )
        if address_name:
            name = address_name.group(0).split("(", 1)[0].strip()
        if not address_name:
            found = NAME_RE.search(header.split("{", 1)[0])
            if found: name = found.group(1)
        stub, end = False, cursor
        if name is not None:
            depth, body = 0, []
            while end < len(lines):
                code = code_lines[end]; depth += code.count("{") - code.count("}"); body.append(lines[end])
                if depth <= 0 and "{" in "".join(body): break
                end += 1
            text = "\n".join(body)
            if "// TODO" in text or "/* TODO" in text:
                meat = [strip_line_comment(line).strip() for line in body]
                meat = [line for line in meat if line and line not in ("{", "}") and not line.startswith("return") and not re.match(r"^[A-Za-z_].*\)\s*\{?$", line)]
                stub = not meat
        markers.append(dict(addr=address, name=name, line=index + 1, stub=stub,
                            nonmatching="NONMATCHING" in lines[index]))
        index = end + 1 if name is not None else index + 1
    return markers


def mask_bytes(size: int, relocations: list[dict]) -> bytearray:
    mask = bytearray(size)
    for relocation in relocations:
        for offset in range(RELOC_MASK_SIZE.get(relocation["r_type"], 0)):
            where = relocation["offset"] + offset
            if 0 <= where < size: mask[where] = 1
    return mask


def compare(body: bytes, relocations: list[dict], retail: bytes) -> tuple[int, list[int]]:
    mask = mask_bytes(len(body), relocations)
    differences = [index for index, byte in enumerate(body)
                   if not mask[index] and (retail[index] if index < len(retail) else None) != byte]
    return len(differences), differences[:16]


def decode_reloc_values(relocations: list[dict], retail: bytes) -> list[dict]:
    for relocation in relocations:
        offset = relocation["offset"] & ~3
        if offset + 4 > len(retail): continue
        word = struct.unpack_from("<I", retail, offset)[0]
        if relocation["r_type"] == 4: relocation["retail_target"] = f"{(word & 0x03ffffff) << 2:#010x}"
        elif relocation["r_type"] in (5, 6, 7): relocation["retail_imm"] = f"{word & 0xffff:#06x}"
    return relocations


def window_for(address: int, boundaries: list[int]) -> int | None:
    index = bisect.bisect_right(boundaries, address)
    return boundaries[index] - address if index < len(boundaries) else None


def _unit_suffix(unit: int | None) -> str:
    return "" if unit is None else f"_unit_{unit:08x}"


def _compile(cpath: Path, cfg: dict, output: Path, unit: int | None = None) -> tuple[bool, str]:
    defines = [] if unit is None else [f"-DP4_UNIT_{unit:08X}"]
    command = [cfg["mwcc"], *cfg["compile_flags"], *defines, "-c", str(cpath), "-o", str(output)]
    process = subprocess.run(command, cwd=REPO, stdout=subprocess.PIPE,
                             stderr=subprocess.STDOUT, text=True)
    return process.returncode == 0 and output.is_file(), process.stdout


def compile_object(
    cpath: Path,
    cfg: dict,
    objdir: Path | None = None,
    unit: int | None = None,
) -> tuple[ObjectFile | None, str]:
    """Compile one source file or one selectable consolidated source unit."""
    if objdir is None:
        objdir = Path(tempfile.mkdtemp(prefix="p4-verify-"))
    relative = cpath.relative_to(REPO)
    output = objdir / (relative.as_posix().replace("/", "_") + _unit_suffix(unit) + ".o")
    output.parent.mkdir(parents=True, exist_ok=True)
    compiled, log = _compile(cpath, cfg, output, unit)
    return (ObjectFile(output) if compiled else None), log


def verify_file(
    cpath: Path,
    cfg: dict,
    retail: RetailElf,
    boundaries: list[int],
    objdir: Path,
    unit: int | None = None,
) -> list[dict]:
    relative, markers = cpath.relative_to(REPO), scan_markers(cpath, unit)
    if not markers: return []
    output = objdir / (relative.as_posix().replace("/", "_") + _unit_suffix(unit) + ".o")
    compiled, log = _compile(cpath, cfg, output, unit)
    if not compiled:
        return [dict(file=str(relative), **marker, status="COMPILE_ERROR", detail=log.strip()[:400]) for marker in markers]
    obj, results = ObjectFile(output), []
    for marker in markers:
        entry = dict(file=str(relative), addr=f"{marker['addr']:08x}", name=marker["name"], line=marker["line"])
        if marker["stub"]: entry["status"] = "STUB"
        elif not marker["name"]: entry.update(status="NO_SYMBOL", detail="could not parse function name after marker")
        else:
            window = window_for(marker["addr"], boundaries)
            if window is None or window > 0x10000:
                entry.update(status="UNKNOWN_ADDR", detail="no plausible function boundary above marker address")
            else:
                try: body, relocs = obj.function(marker["name"])
                except KeyError: entry["status"] = "NO_SYMBOL"
                else:
                    target = retail.bytes_at(marker["addr"], window)
                    difference, first = compare(body, relocs, target)
                    tail = target[len(body):]
                    entry.update(object_size=len(body), window=window, normalized_diff=difference)
                    if difference or len(body) > window or any(tail):
                        entry["status"] = "NONMATCHING" if marker["nonmatching"] else ("SIZE_MISMATCH" if not difference else "MISMATCH")
                        if difference: entry["first_diffs"] = first
                    elif marker["nonmatching"]:
                        entry.update(status="STALE_NONMATCHING", detail="function now matches; remove the NONMATCHING tag")
                    else: entry["status"] = "MATCH"
                    entry["relocations"] = decode_reloc_values(relocs, target)
        results.append(entry)
    return results

def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("files", nargs="*", help="specific .c files (default: all of src/)")
    parser.add_argument("--json", metavar="PATH", help="write full JSON report")
    parser.add_argument("--show-mismatches", action="store_true", help="print non-MATCH/non-STUB detail")
    parser.add_argument("--include-generated", action="store_true",
                        help="include src/generated candidate files in the scan")
    args = parser.parse_args()
    cfg, target, windows = load_config(), _read_json(TARGET), _read_json(FUNCTION_WINDOWS)
    if windows.get("program") != "SLUS_217.82" or windows.get("sha1") != target["elf"]["sha1"]:
        _die("slus21782_functions.json does not describe the configured P4 USA target")
    retail = RetailElf(cfg["retail_elf"], target, windows["sha1"])

    source_files = sorted(
        path for path in (REPO / "src").rglob("*.c")
        if args.include_generated or not is_generated(path)
    )
    requested = [Path(file).resolve() for file in args.files] if args.files else source_files
    files: list[tuple[Path, int | None]] = []
    for path in requested:
        units = source_units(path)
        if units:
            files.extend((path, unit) for unit in units)
        else:
            files.append((path, None))

    bounds = {int(address, 16) for address in windows["windows"]}
    bounds.update(int(address, 16) + size for address, size in windows["windows"].items() if size)
    for path in source_files:
        bounds.update(marker["addr"] for marker in scan_markers(path))
    results: list[dict] = []
    with tempfile.TemporaryDirectory(prefix="p4verify_") as directory:
        for path, unit in files:
            results.extend(verify_file(path, cfg, retail, sorted(bounds), Path(directory), unit))
    counts: dict[str, int] = {}
    for result in results: counts[result["status"]] = counts.get(result["status"], 0) + 1
    print(f"functions scanned: {len(results)}")
    for status in ("MATCH", "STUB", "NONMATCHING", "STALE_NONMATCHING", "MISMATCH", "SIZE_MISMATCH", "NO_SYMBOL", "COMPILE_ERROR", "UNKNOWN_ADDR"):
        if counts.get(status): print(f"  {status:<18} {counts[status]}")
    bad = [result for result in results if result["status"] not in ("MATCH", "STUB", "NONMATCHING")]
    if args.show_mismatches:
        for result in bad:
            print(f"\n{result['status']}: {result['file']}:{result.get('line', '?')} {result.get('name')} @ {result.get('addr')}")
            if "normalized_diff" in result: print(f"  obj {result['object_size']}B window {result['window']}B normalized_diff {result['normalized_diff']} first {result.get('first_diffs', [])}")
            if result.get("detail"): print(f"  {result['detail']}")
    if args.json:
        Path(args.json).write_text(json.dumps(dict(summary=counts, results=results), indent=1) + "\n", encoding="utf-8")
        print(f"report: {args.json}")
    raise SystemExit(1 if bad else 0)

if __name__ == "__main__":
    main()
