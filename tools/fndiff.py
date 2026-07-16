#!/usr/bin/env python3
"""Instruction-level diff of one Persona 4 USA function against retail.

Usage:
  python tools/fndiff.py src/foo.c FunctionName
  python tools/fndiff.py src/foo.c FunctionName --addr 00100008

The selected source unit is compiled with the same configured command and flags
as ``verify.py``. Object relocations are annotated and their linker-owned fields
"""
from __future__ import annotations

import argparse
from pathlib import Path
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (FUNCTION_WINDOWS, REPO, TARGET, ObjectFile, RetailElf,
                    _compile, _die, _read_json, load_config, mask_bytes,
                    scan_markers, source_units, window_for)

try:
    from capstone import Cs, CS_ARCH_MIPS, CS_MODE_LITTLE_ENDIAN, CS_MODE_MIPS64
    _DISASSEMBLER = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 | CS_MODE_LITTLE_ENDIAN)

    def disassemble(word: bytes, pc: int) -> str:
        for instruction in _DISASSEMBLER.disasm(word, pc):
            return f"{instruction.mnemonic} {instruction.op_str}"
        return "??"
except ImportError:
    def disassemble(word: bytes, pc: int) -> str:
        return ""


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("file", help="C source file containing the function")
    parser.add_argument("function", help="object symbol to compare")
    parser.add_argument("--addr", help="retail address in hex; defaults to its FUN_ marker")
    args = parser.parse_args()

    cfg, target, windows = load_config(), _read_json(TARGET), _read_json(FUNCTION_WINDOWS)
    if windows.get("program") != "SLUS_217.82" or windows.get("sha1") != target["elf"]["sha1"]:
        _die("slus21782_functions.json does not describe the configured P4 USA target")
    retail = RetailElf(cfg["retail_elf"], target, windows["sha1"])
    source = Path(args.file).resolve()
    if not source.is_file():
        _die(f"source file does not exist: {args.file}")
    unit = None
    units = source_units(source)
    if args.addr:
        try:
            address = int(args.addr, 16)
        except ValueError:
            _die(f"invalid hexadecimal address: {args.addr}")
    else:
        marker = next((item for item in scan_markers(source) if item["name"] == args.function), None)
        if marker is None:
            _die(f"no // FUN_ marker found for {args.function} in {args.file}; use --addr to override")
        address = marker["addr"]
    for candidate in units:
        if any(marker["addr"] == address or marker["name"] == args.function
               for marker in scan_markers(source, candidate)):
            unit = candidate
            break

    boundaries = {int(item, 16) for item in windows["windows"]}
    boundaries.update(int(item, 16) + size for item, size in windows["windows"].items() if size)
    for path in (REPO / "src").rglob("*.c"):
        boundaries.update(marker["addr"] for marker in scan_markers(path))
    window = window_for(address, sorted(boundaries))
    if window is None or window > 0x10000:
        _die(f"no plausible function window at {address:#010x}")

    with tempfile.TemporaryDirectory(prefix="p4fndiff_") as directory:
        output = Path(directory) / "out.o"
        compiled, log = _compile(source, cfg, output, unit)
        if not compiled:
            _die(log.strip() or "compiler did not produce an object")
        try:
            body, relocations = ObjectFile(output).function(args.function)
        except KeyError:
            _die(f"symbol not present in object: {args.function}")

    target_bytes = retail.bytes_at(address, window)
    mask = mask_bytes(max(len(body), len(target_bytes)), relocations)
    reloc_at: dict[int, list[str]] = {}
    for relocation in relocations:
        reloc_at.setdefault(relocation["offset"] & ~3, []).append(
            f"{relocation['type']}:{relocation['symbol']}")
    print(f"{args.function} @ {address:#010x}  obj {len(body)}B  window {window}B")
    print(f"{'off':>6} {'':1} {'object':<34} {'retail':<34} reloc")
    differing_words = 0
    for offset in range(0, max(len(body), len(target_bytes)), 4):
        object_word, retail_word = body[offset:offset + 4], target_bytes[offset:offset + 4]
        differs = any((object_word[index] if index < len(object_word) else None) !=
                      (retail_word[index] if index < len(retail_word) else None)
                      for index in range(4) if offset + index < len(mask) and not mask[offset + index])
        if differs:
            differing_words += 1
        if offset >= len(body) and not any(retail_word):
            continue
        object_text = f"{object_word.hex():<9} {disassemble(object_word, address + offset)}" if len(object_word) == 4 else object_word.hex()
        retail_text = f"{retail_word.hex():<9} {disassemble(retail_word, address + offset)}" if len(retail_word) == 4 else retail_word.hex()
        print(f"{offset:6} {'!' if differs else ' '} {object_text:<34} {retail_text:<34} {','.join(reloc_at.get(offset, []))}")
    print(f"\ndiffering words (reloc-masked): {differing_words}")


if __name__ == "__main__":
    main()
