#!/usr/bin/env python3
"""Repo-wide match verifier for the Persona 4 USA decompilation.

For every ``// FUN_xxxxxxxx`` marker in ``src/**/*.c`` this tool compiles the
containing translation unit (one C file == one unit) with the configured MWCC
compiler, extracts the marked function and its MIPS relocations from the
relocatable object, masks relocated fields, and compares the remaining bytes
with retail ``SLUS_217.82``.

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
INCLUDE_MARKER_RE = re.compile(
    r'^\s*INCLUDE_(?:ASM|RODATA)\s*\(\s*"[^"]*"\s*,\s*'
    r"([A-Za-z_][A-Za-z0-9_]*)\s*\)\s*;?\s*$"
)

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


# Middleware and platform code we did not write: RenderWare, CRI, the Sony SDK,
# and the C runtime. It is tracked because it occupies retail windows, but it is
# not the decompilation's goal, so progress is reported separately for it.
# "middleware/" holds code proven to be ee-gcc output rather than MWCCPS2 (see
# src/middleware/gcc_ee_grouped.c for the per-signature evidence); the vendor is
# unknown so it is filed by toolchain instead of under cri/ or sce/.
THIRD_PARTY_PREFIXES = ("rw/", "cri/", "sce/", "middleware/")
THIRD_PARTY_FILES = {"crt0.c", "libc_core.c", "libcdvd.c"}


def is_third_party(rel_file: str) -> bool:
    norm = str(rel_file).replace("\\", "/")
    if norm.startswith("src/"):
        norm = norm[len("src/"):]
    return norm in THIRD_PARTY_FILES or norm.startswith(THIRD_PARTY_PREFIXES)


# The same judgement applied by ADDRESS rather than by path. Three contiguous
# spans of the retail image are prebuilt vendor libraries -- CRI Sofdec/ADX/ROFS,
# the Sony PS2 SDK, and the C runtime -- linked in as objects. They are filed
# here rather than under cri/ or sce/ because the promotion step named their
# translation units generically (code1_0041.c .. code1_0052.c, code2_0070.c),
# and those units cannot simply be MOVED: four of them are mixed, holding game
# code as well, and relocating a .c file would change object boundaries and
# break the byte-exact link.
#
# Three independent lines of evidence, all reproducible from the retail image:
#
#  1. Stack prologue. MWCCPS2 saves and restores registers across the stack
#     with `sq`/`lq`; GCC (Cygnus) uses `sd`/`ld`. Retail uses `sd` of an $s
#     register here, which no MWCCPS2 build or option emits. Note the test is
#     specifically the PROLOGUE/EPILOGUE: `sd` also appears in ordinary MWCCPS2
#     code for 64-bit data, so a bare "contains sd" scan false-positives on
#     about thirty scattered game functions.
#
#  2. Function alignment, which is the cleanest discriminator. GCC aligns
#     functions to 8 bytes and MWCCPS2 to 16, so any function whose address is
#     8 mod 16 cannot be MWCCPS2 output. Inside these spans 42-50% of functions
#     are 8-aligned; outside them 0.23% are (19 of 8250, and those 19 sit
#     against these very boundaries). That two-hundred-fold separation is what
#     fixed the boundaries below -- an earlier hand-written set was too tight at
#     the bottom of each span and ran 1.9 MB too far past the top of the third.
#
#  3. Strings. Decoding the %hi/%lo string references that originate inside
#     these spans yields "(c)CRI", "CRI-MW", "../../rofs_mai.c", "rofs_if.c",
#     "rofs_hn.c", "rofs_pfs.c", "MWSST_Create", "MWSFSVR_*", "MWSTM_ReqStart",
#     "mwPlyStartXX", "SceStdioIoctlSema", "Sony PS2 Memory Card Format",
#     "bug in vfprintf", and MPEG macroblock decoder errors.
#
# Worked example: func_0050b6b8 scores 899 under mwcps2-3.0.1b210-060308 and is
# instruction-identical under ee-gcc2.96 -O2 -G0, the only differing row being
# the `jal` label name. Four different C spellings gave the same score, so the
# compiler was the variable, not the source. Reproduce with
# `tools/decompme.py --try 0050b6b8 --against ee-gcc2.96,mwcps2-3.0.1b210-060308`.
#
# Note the CONVERSE does not hold: a function in these spans that is neither
# 8-aligned nor uses `sd` is not thereby game code. Most such functions are
# 16-40 byte leaf accessors where GCC and MWCCPS2 happen to emit identical
# bytes, which is also why some already report MATCH. Membership is decided by
# the span, not by the instruction mix of an individual function.
VENDOR_CODE_RANGES = (
    (0x00417510, 0x0044E830),
    (0x004BD628, 0x0052D8C0),
    (0x0070C850, 0x0070E140),
)


def is_vendor_address(address) -> bool:
    """True when a retail address falls inside a prebuilt vendor library."""
    if address is None:
        return False
    if isinstance(address, str):
        try:
            address = int(address, 16)
        except ValueError:
            return False
    return any(low <= address < high for low, high in VENDOR_CODE_RANGES)


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
    cfg["mwcc_versions"] = compiler_versions(cfg)
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


def scan_markers(cpath: Path) -> list[dict]:
    try:
        lines = cpath.read_text(errors="replace").splitlines()
    except FileNotFoundError:
        # Concurrent lanes write and delete their own probe scratch files; a
        # source that vanished between the directory walk and this read has no
        # markers to contribute and must not abort the whole run.
        return []
    code_lines, markers, index = sanitize_c_lines(lines), [], 0
    while index < len(lines):
        marker = MARKER_RE.match(lines[index])
        if not marker:
            index += 1; continue
        address, name, cursor, header = int(marker.group(2), 16), None, index + 1, ""
        if index + 1 < len(lines):
            asm_line = lines[index + 1].split("//", 1)[0].rstrip()
            asm_marker = INCLUDE_MARKER_RE.match(asm_line)
            if asm_marker:
                markers.append(dict(
                    addr=address, name=asm_marker.group(1), line=index + 1,
                    stub=False, nonmatching="NONMATCHING" in lines[index],
                    asm=True,
                ))
                index += 2
                continue
            # A function kept as near-miss C behind `#ifdef NON_MATCHING` with an
            # INCLUDE_ASM fallback in the `#else` arm. The object gets the exact
            # retail bytes, so a byte comparison always succeeds and would score
            # the row MATCH (or STALE_NONMATCHING, inviting someone to drop the
            # tag and inflate progress). What is actually true is that this
            # function is NOT yet matching C, so classify it as the assembly
            # fallback it is and keep the C body findable for whoever finishes it.
            # The floor explanation sits between the marker and the `#ifdef`, in
            # either comment style, and a scoped `#pragma` for the function may
            # sit there too, so skip blanks, comments and pragmas first. Use the
            # comment-stripped view so a `/* ... */` block is handled as well.
            probe = index + 1
            while probe < len(lines) and (
                not code_lines[probe].strip()
                or code_lines[probe].lstrip().startswith("#pragma")
            ):
                probe += 1
            if probe < len(lines) and code_lines[probe].strip().startswith("#ifdef NON_MATCHING"):
                # Search to the NEXT marker rather than a fixed window: the C body
                # being preserved can be arbitrarily long (one is 435 lines).
                fallback, end = None, probe
                for look in range(probe + 1, len(lines)):
                    if MARKER_RE.match(lines[look]):
                        break
                    end = look
                    found = INCLUDE_MARKER_RE.match(lines[look].split("//", 1)[0].rstrip())
                    if found:
                        fallback = found
                        break
                if fallback:
                    markers.append(dict(
                        addr=address, name=fallback.group(1), line=index + 1,
                        stub=False, nonmatching=True, asm=True,
                    ))
                    index = end + 1
                    continue
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


def decode_reloc_values(relocations: list[dict], retail: bytes, body: bytes = b"") -> list[dict]:
    for relocation in relocations:
        offset = relocation["offset"] & ~3
        if offset + 4 > len(retail): continue
        word = struct.unpack_from("<I", retail, offset)[0]
        if relocation["r_type"] == 4: relocation["retail_target"] = f"{(word & 0x03ffffff) << 2:#010x}"
        elif relocation["r_type"] in (5, 6, 7):
            relocation["retail_imm"] = f"{word & 0xffff:#06x}"
            # The candidate's immediate is the relocation addend (MWCC emits REL,
            # not RELA): what the linker adds to the symbol's address. Kept so a
            # wrong-but-plausible symbol can be caught without a full link.
            if offset + 4 <= len(body):
                relocation["addend"] = f"{struct.unpack_from('<I', body, offset)[0] & 0xffff:#06x}"
    return relocations


SYMBOL_ADDRESSES_PATH = REPO / "config" / "symbols_recovered.txt"


def symbol_addresses() -> tuple[int | None, dict[str, int]]:
    """gp and every data symbol the linker will define, from the recovered symbol
    table; a symbol whose name encodes its own address resolves without an entry."""
    gp, table = None, {}
    if SYMBOL_ADDRESSES_PATH.is_file():
        for line in SYMBOL_ADDRESSES_PATH.read_text().splitlines():
            found = re.match(r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9A-Fa-f]+).*?type:(\w+)", line)
            if not found: continue
            if found.group(3) == "gp": gp = int(found.group(2), 16)
            elif found.group(3) == "data": table[found.group(1)] = int(found.group(2), 16)
    return gp, table


def resolve_symbol(name: str, gp: int | None, table: dict[str, int]) -> int | None:
    if name in table: return table[name]
    encoded = re.fullmatch(r"(?:func|FUN|D|DAT|jtbl|LAB)_([0-9a-fA-F]{8})(?:_abs)?", name)
    if encoded: return int(encoded.group(1), 16)
    gp_relative = re.fullmatch(r"[a-z]Gp([0-9a-f]{8})", name)
    if gp_relative and gp is not None:
        return gp + struct.unpack("<i", struct.pack("<I", int(gp_relative.group(1), 16)))[0]
    return None


def wrong_symbol_relocations(result: dict, gp: int | None, table: dict[str, int]) -> list[str]:
    """Relocations of a MATCH function whose symbol+addend cannot produce the
    immediate retail encodes. Byte comparison masks these fields, so a sibling
    symbol a few bytes off scores MATCH; the link would catch it only for units
    that are link-eligible, and the b119 units are not."""
    problems, pending_hi = [], None
    for reloc in result.get("relocations", []):
        rtype, name = reloc["r_type"], reloc.get("symbol") or ""
        if rtype not in (5, 6, 7) or "retail_imm" not in reloc or "addend" not in reloc:
            pending_hi = None
            continue
        address = resolve_symbol(name, gp, table)
        if address is None:
            pending_hi = None
            continue
        retail_imm, addend = int(reloc["retail_imm"], 16), int(reloc["addend"], 16)
        signed = addend - 0x10000 if addend & 0x8000 else addend
        if rtype == 7:
            if gp is None: continue
            displacement = address - gp + signed
            expected = displacement & 0xffff
            if not -0x8000 <= displacement < 0x8000:
                # Only the low half is compared, so a symbol a multiple of 64K
                # away from the real one (D_008872F8 for the float at 0x7672F8)
                # would otherwise pass; nothing outside gp's reach can be right.
                problems.append(f"+{reloc['offset']}: gp-relative {name}{signed:+#x} is {displacement:#x} from gp, out of reach")
            elif expected != retail_imm:
                problems.append(f"+{reloc['offset']}: gp-relative {name}{signed:+#x} encodes {expected:#06x}, retail {retail_imm:#06x}")
            pending_hi = None
        elif rtype == 5:
            pending_hi = (name, addend, reloc)
        else:
            if pending_hi and pending_hi[0] == name:
                value = address + (pending_hi[1] << 16) + signed
                expected_hi = ((value + 0x8000) >> 16) & 0xffff
                hi_retail = int(pending_hi[2]["retail_imm"], 16)
                if expected_hi != hi_retail:
                    problems.append(f"+{pending_hi[2]['offset']}: %hi({name}{signed:+#x}) encodes {expected_hi:#06x}, retail {hi_retail:#06x}")
            expected = (address + signed) & 0xffff
            if expected != retail_imm:
                problems.append(f"+{reloc['offset']}: %lo({name}{signed:+#x}) encodes {expected:#06x}, retail {retail_imm:#06x}")
            pending_hi = None
    return problems


def window_for(address: int, boundaries: list[int]) -> int | None:
    index = bisect.bisect_right(boundaries, address)
    return boundaries[index] - address if index < len(boundaries) else None


def _mwccgap_command(cpath: Path, cfg: dict, output: Path) -> list[str]:
    mwccgap = TOOLS / "mwccgap" / "mwccgap.py"
    flags = [
        "--mwcc-path", unit_compiler(cpath, cfg),
        "--asm-dir-prefix", str(REPO),
        "--macro-inc-path", str(REPO / "asm" / "macro.inc"),
        "--as-march", "r5900", "--as-mabi", "eabi",
        *unit_compile_flags(cpath, cfg["compile_flags"]),
    ]
    as_path = cfg.get("as_path") or os.environ.get("P4_AS")
    if as_path:
        flags[0:0] = ["--as-path", str(as_path)]
    return [sys.executable, str(mwccgap), str(cpath), str(output), *flags]


def _compile(cpath: Path, cfg: dict, output: Path) -> tuple[bool, str]:
    process = subprocess.run(
        _mwccgap_command(cpath, cfg, output),
        cwd=REPO,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    return process.returncode == 0 and output.is_file(), process.stdout


# Part of P4 was not built with Metrowerks.  Functions whose retail prologue
# saves callee-saved `$s` registers with `sd` rather than `sq` come from
# ee-gcc 2.96, and MWCCPS2 cannot reproduce them at any optimisation level.
# Those translation units are listed in config/gcc_units.txt and compiled with
# tools/eegcc_shim.py instead.  The split is per translation unit because the
# two compilers separate cleanly by file in this game.
#
# mwccgap is not used for them: it splices assembly through MWCC's `asm void
# f() {}` extension, which GCC cannot parse.  The shim splices the same
# assembly as file-scope `__asm__`, which keeps retail's function order.
GCC_UNITS_PATH = REPO / "config" / "gcc_units.txt"
_GCC_UNITS: set[str] | None = None


def gcc_units() -> set[str]:
    global _GCC_UNITS
    if _GCC_UNITS is None:
        _GCC_UNITS = set()
        if GCC_UNITS_PATH.is_file():
            for line in GCC_UNITS_PATH.read_text().splitlines():
                line = line.split("#", 1)[0].strip()
                if line:
                    _GCC_UNITS.add(line)
    return _GCC_UNITS


def is_gcc_unit(cpath: Path) -> bool:
    try:
        return cpath.resolve().relative_to(REPO).as_posix() in gcc_units()
    except ValueError:
        return False


# A second per-unit split, this time inside MWCC: retail built some translation
# units with the "optimize for speed" variant (`-O2,p`).  It is a command-line
# state -- no #pragma spelling reaches it, and it survives a later `#pragma
# optimization_level N` -- so it has to be carried per unit.  Measured
# 2026-09-02: a global `-O2,p` verify loses 962 matched functions, while the
# units in config/speed_units.txt lose none and only they show the `,p`
# signature (an alignment nop after a filled back-edge delay slot).
SPEED_UNITS_PATH = REPO / "config" / "speed_units.txt"
_SPEED_UNITS: set[str] | None = None


def speed_units() -> set[str]:
    global _SPEED_UNITS
    if _SPEED_UNITS is None:
        _SPEED_UNITS = set()
        if SPEED_UNITS_PATH.is_file():
            for line in SPEED_UNITS_PATH.read_text().splitlines():
                line = line.split("#", 1)[0].strip()
                if line:
                    _SPEED_UNITS.add(line)
    return _SPEED_UNITS


def is_speed_unit(cpath: Path) -> bool:
    try:
        return cpath.resolve().relative_to(REPO).as_posix() in speed_units()
    except ValueError:
        return False


# A third per-unit split: the compiler BUILD.  The RenderWare-derived block
# contains functions that MWCCPS2 3.0.1 b210 cannot produce at any option
# (`movz` conditional moves, measured 2026-09-03: every `-O` level, `,p`, C and
# C++) while the 2003-2005 builds b74/b119/b151 emit them byte-exact from a
# one-line ternary.  Retail linked prebuilt RenderWare objects next to Atlus's
# b210 code, so the compiler is carried per unit here, the same way
# config/gcc_units.txt carries ee-gcc units and config/speed_units.txt carries
# `-O2,p`.  Each line is `<unit path> <version key>`; the key names an entry of
# `mwcc_versions` in the local config (or the environment variable
# `P4_MWCC_<KEY>` with non-alphanumerics folded to `_`).  A unit that names a
# version with no configured compiler is an error, never a silent fallback to
# b210: that would score its functions against the wrong compiler.
COMPILER_UNITS_PATH = REPO / "config" / "compiler_units.txt"
_COMPILER_UNITS: dict[str, str] | None = None


def compiler_units() -> dict[str, str]:
    global _COMPILER_UNITS
    if _COMPILER_UNITS is None:
        _COMPILER_UNITS = {}
        if COMPILER_UNITS_PATH.is_file():
            for line in COMPILER_UNITS_PATH.read_text().splitlines():
                line = line.split("#", 1)[0].strip()
                if not line:
                    continue
                parts = line.split()
                if len(parts) != 2:
                    _die(f"{COMPILER_UNITS_PATH.name}: expected `<unit> <version>`, got {line!r}")
                _COMPILER_UNITS[parts[0]] = parts[1]
    return _COMPILER_UNITS


def _version_env_name(key: str) -> str:
    return "P4_MWCC_" + re.sub(r"[^A-Za-z0-9]", "_", key).upper()


def compiler_versions(cfg: dict) -> dict[str, str]:
    """Version key -> compiler path, from config `mwcc_versions` plus environment."""
    versions = dict(cfg.get("mwcc_versions") or {})
    for key in set(compiler_units().values()) | set(versions):
        env = os.environ.get(_version_env_name(key))
        if env:
            versions[key] = env
    return versions


def unit_compiler(cpath: Path, cfg: dict) -> str:
    """The compiler binary this unit is verified and built with."""
    try:
        relative = cpath.resolve().relative_to(REPO).as_posix()
    except ValueError:
        return cfg["mwcc"]
    key = compiler_units().get(relative)
    if key is None:
        return cfg["mwcc"]
    path = (cfg.get("mwcc_versions") or compiler_versions(cfg)).get(key)
    if not path or not Path(path).is_file():
        _die(f"{relative} is built with compiler version {key!r}, which is not configured: "
             f"add it to `mwcc_versions` in tools/verify_config.local.json / "
             f"tools/build_config.local.json or set {_version_env_name(key)}")
    return path


def unit_compile_flags(cpath: Path, flags: list[str]) -> list[str]:
    """`-O<n>` becomes `-O<n>,p` for speed units; everything else is unchanged."""
    if not is_speed_unit(cpath):
        return list(flags)
    return [f + ",p" if re.fullmatch(r"-O[0-4]", f) else f for f in flags]


def _compile_gcc(cpath: Path, cfg: dict, output: Path) -> tuple[bool, str]:
    shim = TOOLS / "eegcc_shim.py"
    process = subprocess.run(
        [sys.executable, str(shim), "-c", *cfg["compile_flags"],
         "-o", str(output), str(cpath)],
        cwd=REPO,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    return process.returncode == 0 and output.is_file(), process.stdout



def compile_object(
    cpath: Path,
    cfg: dict,
    objdir: Path | None = None,
) -> tuple[ObjectFile | None, str]:
    """Compile one source file (one translation unit)."""
    if objdir is None:
        objdir = Path(tempfile.mkdtemp(prefix="p4-verify-"))
    relative = cpath.relative_to(REPO)
    output = objdir / (relative.as_posix().replace("/", "_") + ".o")
    output.parent.mkdir(parents=True, exist_ok=True)
    if is_gcc_unit(cpath):
        compiled, log = _compile_gcc(cpath, cfg, output)
    else:
        compiled, log = _compile(cpath, cfg, output)
    return (ObjectFile(output) if compiled else None), log


def verify_file(
    cpath: Path,
    cfg: dict,
    retail: RetailElf,
    boundaries: list[int],
    objdir: Path,
) -> list[dict]:
    relative, markers = cpath.relative_to(REPO), scan_markers(cpath)
    if not markers: return []
    output = objdir / (relative.as_posix().replace("/", "_") + ".o")
    if is_gcc_unit(cpath):
        compiled, log = _compile_gcc(cpath, cfg, output)
    else:
        compiled, log = _compile(cpath, cfg, output)
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
                    elif marker.get("asm"):
                        # An INCLUDE_ASM fallback reproduces retail by construction:
                        # it IS the extracted assembly. It is tracked and byte-correct,
                        # but it is NOT decompiled C, so it must never be counted as
                        # MATCH or the progress metric becomes meaningless. This is
                        # checked BEFORE the stale-tag branch: such a row always
                        # compares equal, so otherwise it would read as
                        # STALE_NONMATCHING and invite someone to drop a tag that is
                        # still true.
                        entry.update(status="ASM", detail="assembly fallback; not yet decompiled to C")
                    elif marker["nonmatching"]:
                        entry.update(status="STALE_NONMATCHING", detail="function now matches; remove the NONMATCHING tag")
                    else: entry["status"] = "MATCH"
                    entry["relocations"] = decode_reloc_values(relocs, target, body)
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

    # config/gcc_units.txt units are linked from their extracted retail
    # assembly rather than compiled, because building them needs an ee-gcc
    # toolchain this repo does not ship. Scoring them here would report
    # COMPILE_ERROR wherever that toolchain is absent -- CI included -- while
    # reporting MATCH on a developer machine that happens to have it, so the
    # same tree would grade differently in two places. They hold no first-party
    # functions, so excluding them costs the project's metric nothing.
    source_files = sorted(
        path for path in (REPO / "src").rglob("*.c")
        if (args.include_generated or not is_generated(path))
        and not is_gcc_unit(path)
    )
    requested = [Path(file).resolve() for file in args.files] if args.files else source_files
    files: list[Path] = list(requested)

    bounds = {int(address, 16) for address in windows["windows"]}
    bounds.update(int(address, 16) + size for address, size in windows["windows"].items() if size)
    for path in source_files:
        bounds.update(marker["addr"] for marker in scan_markers(path))
    results: list[dict] = []
    with tempfile.TemporaryDirectory(prefix="p4verify_") as directory:
        for path in files:
            results.extend(verify_file(path, cfg, retail, sorted(bounds), Path(directory)))
    counts: dict[str, int] = {}
    for result in results: counts[result["status"]] = counts.get(result["status"], 0) + 1
    first_party = [
        r for r in results
        if not is_third_party(r["file"]) and not is_vendor_address(r.get("addr"))
    ]
    fp_counts: dict[str, int] = {}
    for result in first_party: fp_counts[result["status"]] = fp_counts.get(result["status"], 0) + 1
    order = ("MATCH", "ASM", "STUB", "NONMATCHING", "STALE_NONMATCHING", "MISMATCH", "SIZE_MISMATCH", "NO_SYMBOL", "COMPILE_ERROR", "UNKNOWN_ADDR")
    print(f"functions scanned: {len(results)}")
    for status in order:
        if counts.get(status): print(f"  {status:<18} {counts[status]}")
    # First-party is the decomp's actual goal; rw/cri/sce, the C runtime, and the
    # prebuilt vendor libraries in VENDOR_CODE_RANGES are code we did not write,
    # tracked only because they occupy retail windows.
    fp_match = fp_counts.get("MATCH", 0)
    fp_pct = f" ({100 * fp_match / len(first_party):.1f}%)" if first_party else ""
    print(f"first-party functions scanned: {len(first_party)}")
    print(f"  {'MATCH':<18} {fp_match}{fp_pct}")
    for status in order[1:]:
        if fp_counts.get(status): print(f"  {status:<18} {fp_counts[status]}")
    # Relocation TARGETS are masked by the byte comparison, so a call to the
    # wrong function is invisible to `normalized_diff` -- it matches per-function
    # and then corrupts the linked image by exactly that one jal word. Where the
    # callee's symbol name encodes an address, cross-check it against the target
    # retail actually calls. This caught a real defect (nmCmdList func_002bbdd0
    # calling func_00278170 where retail calls func_002781e0) that had passed
    # per-function verification and broke the byte-exact image.
    wrong_callees = []
    for result in results:
        # Only meaningful where our layout already agrees with retail. On a
        # NONMATCHING function the instruction at the same offset need not be a
        # call at all, so `retail_target` decodes to a garbage address and the
        # comparison would cry wolf.
        if result["status"] != "MATCH":
            continue
        for reloc in result.get("relocations", []):
            target = reloc.get("retail_target")
            named = re.fullmatch(r"(?:func|FUN)_([0-9a-fA-F]{8})", reloc.get("symbol", "") or "")
            if not target or not named:
                continue
            if int(named.group(1), 16) != int(target, 16):
                wrong_callees.append((result, reloc))
    if wrong_callees:
        print(f"WRONG CALLEE: {len(wrong_callees)} relocation(s) name a function other than the one retail calls")
        for result, reloc in wrong_callees:
            print(f"  {result['file']}:{result.get('line', '?')} {result.get('name')} "
                  f"+{reloc['offset']}: calls {reloc['symbol']}, retail calls {reloc['retail_target']}")
    # Data symbols have the same blind spot: %hi/%lo and gp-relative immediates
    # are masked, so a MATCH can name a symbol whose address plus addend does
    # not produce retail's immediate. The full link exposes that only for
    # link-eligible units; the b119 units are not linked, and three of their
    # functions carried a sibling symbol off by 8..0xC04 bytes until this check.
    gp, table = symbol_addresses()
    wrong_symbols = []
    for result in results:
        if result["status"] != "MATCH":
            continue
        for problem in wrong_symbol_relocations(result, gp, table):
            wrong_symbols.append((result, problem))
    if wrong_symbols:
        print(f"WRONG SYMBOL: {len(wrong_symbols)} relocation(s) name a data symbol whose address cannot encode retail's immediate")
        for result, problem in wrong_symbols:
            print(f"  {result['file']}:{result.get('line', '?')} {result.get('name')} {problem}")

    # ASM is a healthy in-progress state (byte-correct assembly fallback), so it
    # does not fail the run -- but it is deliberately excluded from MATCH above.
    # A wrong callee is a hard failure: it silently breaks the linked image.
    bad = [result for result in results if result["status"] not in ("MATCH", "ASM", "STUB", "NONMATCHING")]
    if wrong_callees:
        bad.append({"status": "WRONG_CALLEE", "file": "", "name": None, "addr": None})
    if wrong_symbols:
        bad.append({"status": "WRONG_SYMBOL", "file": "", "name": None, "addr": None})
    if args.show_mismatches:
        for result in bad:
            print(f"\n{result['status']}: {result['file']}:{result.get('line', '?')} {result.get('name')} @ {result.get('addr')}")
            if "normalized_diff" in result: print(f"  obj {result['object_size']}B window {result['window']}B normalized_diff {result['normalized_diff']} first {result.get('first_diffs', [])}")
            if result.get("detail"): print(f"  {result['detail']}")
    if args.json:
        Path(args.json).write_text(json.dumps(dict(summary=counts, summary_first_party=fp_counts, results=results), indent=1) + "\n", encoding="utf-8")
        print(f"report: {args.json}")
    raise SystemExit(1 if bad else 0)

if __name__ == "__main__":
    main()
