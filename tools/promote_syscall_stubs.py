#!/usr/bin/env python3
"""Convert PS2 kernel syscall trampolines from INCLUDE_ASM to whole-function asm.

A syscall trampoline is four words and nothing else::

    240300NN   addiu $v1, $zero, NN
    0000000C   syscall
    03E00008   jr $ra
    00000000   nop

There is no C expression for `syscall`, so whole-function asm is the honest
representation -- decomp_lint's H009 allows it as a Category B kernel-convention
body -- and MWCC's assembler rejects the mnemonic, so the words are emitted as
`.word` literals. `src/promoted/code1_0042.c` already carries nine of these as
verified byte-exact matches; this generates the rest from the retail image, so
the form is proven before a single one is written.

The syscall number is the only thing that varies, so this is a substitution, not
a decompilation. Doing it by hand across 150+ functions would be slower and less
reliable than reading the bytes.
"""
from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SRC = REPO / "src"
RETAIL = REPO / "orig" / "SLUS_217.82"

MARKER_RE = re.compile(r"^\s*//\s*FUN_([0-9A-Fa-f]{8})\s*$")
INCLUDE_RE = re.compile(r'^\s*INCLUDE_ASM\("[^"]+",\s*func_[0-9a-f]{8}\);\s*$')

SYSCALL = 0x0000000C
JR_RA = 0x03E00008
NOP = 0x00000000
ADDIU_V1_MASK = 0xFFFF0000
ADDIU_V1 = 0x24030000


class Image:
    """Address-indexed view of the retail ELF's loadable segments."""

    def __init__(self, path: Path) -> None:
        self.blob = path.read_bytes()
        phoff = struct.unpack_from("<I", self.blob, 0x1C)[0]
        phentsize = struct.unpack_from("<H", self.blob, 0x2A)[0]
        phnum = struct.unpack_from("<H", self.blob, 0x2C)[0]
        self.segments = []
        for index in range(phnum):
            base = phoff + index * phentsize
            _type, offset, vaddr, _paddr, filesz, _memsz = struct.unpack_from(
                "<IIIIII", self.blob, base)
            self.segments.append((vaddr, offset, filesz))

    def words(self, addr: int, count: int) -> list[int] | None:
        for vaddr, offset, filesz in self.segments:
            if vaddr <= addr and addr + count * 4 <= vaddr + filesz:
                start = offset + (addr - vaddr)
                return list(struct.unpack_from(f"<{count}I", self.blob, start))
        return None


def syscall_number(image: Image, addr: int) -> int | None:
    """The trampoline's syscall number, or None if this is not one."""
    words = image.words(addr, 4)
    if words is None:
        return None
    first, second, third, fourth = words
    if (first & ADDIU_V1_MASK) != ADDIU_V1:
        return None
    if second != SYSCALL or third != JR_RA or fourth != NOP:
        return None
    return first & 0xFFFF


def body(addr: int, number: int) -> list[str]:
    return [
        f"asm void func_{addr:08x}(void)",
        "{",
        "    .set noreorder",
        f"    .word 0x2403{number:04X} /* addiu $v1, $zero, {number} */",
        "    .word 0x0000000C /* syscall */",
        "    .word 0x03E00008 /* jr $ra */",
        "    .word 0x00000000 /* nop */",
        "}",
        "",
    ]


def convert(path: Path, image: Image, windows: dict[int, int],
            apply: bool) -> list[int]:
    raw = path.read_bytes()
    text = raw.decode("utf-8", "replace")
    newline = "\r\n" if text.count("\r\n") * 2 >= text.count("\n") else "\n"
    lines = [l.rstrip("\r") for l in text.replace("\r\n", "\n").split("\n")]

    converted: list[int] = []
    index = len(lines) - 1
    while index > 0:
        include = lines[index]
        marker = MARKER_RE.match(lines[index - 1])
        if not marker or not INCLUDE_RE.match(include):
            index -= 1
            continue
        addr = int(marker.group(1), 16)
        if windows.get(addr) != 16:
            index -= 1
            continue
        number = syscall_number(image, addr)
        if number is None:
            index -= 1
            continue
        lines[index:index + 1] = body(addr, number)
        converted.append(addr)
        index -= 1

    if converted and apply:
        path.write_bytes(newline.join(lines).encode("utf-8"))
    return converted


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--apply", action="store_true",
                        help="write the conversions (default: report only)")
    parser.add_argument("--file", help="restrict to one source file")
    args = parser.parse_args()

    if not RETAIL.is_file():
        raise SystemExit(f"syscall stubs: {RETAIL} is missing")
    image = Image(RETAIL)
    data = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(
        encoding="utf-8"))
    windows = {int(k, 16): v for k, v in data["windows"].items()}

    paths = [REPO / args.file] if args.file else sorted(SRC.rglob("*.c"))
    total = 0
    for path in paths:
        if "generated" in path.parts:
            continue
        converted = convert(path, image, windows, args.apply)
        if converted:
            total += len(converted)
            print(f"  {path.relative_to(REPO)}: {len(converted)}")
    verb = "converted" if args.apply else "would convert"
    print(f"{verb} {total} syscall trampoline(s)")


if __name__ == "__main__":
    main()
