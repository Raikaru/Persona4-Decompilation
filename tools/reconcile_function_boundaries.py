#!/usr/bin/env python3
"""Build the canonical Persona 4 function map from Splat and Ghidra evidence.

Code1 boundaries come from spimdisasm's control-flow scan after the executable
section split is known. Ghidra-only entries inside a Splat function are treated
as internal labels. Code2 is a shared PS2 SDK/kernel blob whose nine function
boundaries and layout match Persona 3 FES; Ghidra independently identifies the
same nine entries in Persona 4.

The reconciliation scans source ``// FUN_...`` markers and writes
``build/function_map.txt``. Every canonical boundary receives an owner: a
matching C translation unit when available, or an exact retail assembly
function inside a grouped generated C unit under ``build/function_sources``.
"""

from __future__ import annotations

import argparse
from bisect import bisect_left
from collections import defaultdict
from functools import lru_cache
import json
import re
from pathlib import Path
import sys

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))
from verify import is_generated, scan_markers


TARGET = REPO / "config" / "target.json"
GHIDRA_MAP = REPO / "tools" / "slus21782_functions.ghidra.json"
OUTPUT_MAP = REPO / "tools" / "slus21782_functions.json"
SYMBOLS = REPO / "config" / "symbol_addrs.txt"
CODE1_ASM = REPO / "asm" / "code1.s"
CODE2_ASM = REPO / "asm" / "code2.s"
FUNCTION_MAP = REPO / "build" / "function_map.txt"
FUNCTION_SOURCES = REPO / "build" / "function_sources"

GLABEL = re.compile(
    r"^glabel\s+(\S+)\s*\n\s*/\*\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+",
    re.MULTILINE,
)
LINE_ADDRESS = re.compile(r"/\*\s+(?:[0-9A-Fa-f]+\s+)?([0-9A-Fa-f]{8})(?:\s+|:)")
INSTRUCTION_WORD = re.compile(
    r"/\*\s+[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+([0-9A-Fa-f]{8})\s+\*/"
)
DATA_WORD = re.compile(r"\.word\s+(?:0x)?([0-9A-Fa-f]{8})\b")


def parse_int(value: int | str) -> int:
    return value if isinstance(value, int) else int(value, 0)


def segment_bounds(target: dict, name: str) -> tuple[int, int]:
    segment = next(segment for segment in target["segments"] if segment["name"] == name)
    return parse_int(segment["start"]), parse_int(segment["end"])


def splat_entries(path: Path) -> set[int]:
    text = path.read_text(encoding="utf-8")
    return {int(match.group(2), 16) for match in GLABEL.finditer(text)}




def source_markers() -> dict[int, list[tuple[Path, dict]]]:
    markers: dict[int, list[tuple[Path, dict]]] = defaultdict(list)
    for path in sorted(p for p in (REPO / "src").rglob("*.c") if not is_generated(p)):
        for marker in scan_markers(path):
            markers[marker["addr"]].append((path.relative_to(REPO), marker))
    return markers


def format_locations(entries: list[tuple[Path, dict]]) -> str:
    return ", ".join(f"{path}:{marker['line']} ({marker['name']})" for path, marker in entries)


@lru_cache(maxsize=None)
def assembly_index(path: Path) -> tuple[tuple[int, ...], tuple[str, ...]]:
    addresses: list[int] = []
    lines: list[str] = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        match = LINE_ADDRESS.search(line)
        if match:
            addresses.append(int(match.group(1), 16))
            lines.append(line)
    return tuple(addresses), tuple(lines)


def assembly_word(line: str) -> str:
    instruction = INSTRUCTION_WORD.search(line)
    if instruction:
        return instruction.group(1)
    data = DATA_WORD.search(line)
    if data:
        return data.group(1)
    raise RuntimeError(f"assembly line has no encodable word: {line}")


def assembly_words(path: Path, address: int, size: int) -> list[str]:
    end = address + size
    addresses, lines = assembly_index(path)
    first = bisect_left(addresses, address)
    last = bisect_left(addresses, end)
    body = [assembly_word(line) for line in lines[first:last]]
    if not body:
        raise RuntimeError(f"no assembly bytes for function window {address:08x}+{size:x}")
    if len(body) * 4 != size:
        raise RuntimeError(
            f"assembly coverage mismatch for {address:08x}: "
            f"{len(body) * 4:#x} bytes for {size:#x}-byte window"
        )
    return body


def owner_bucket(address: int, code2_start: int) -> str:
    prefix = "code2" if address >= code2_start else "code1"
    return f"{prefix}_{address >> 16:04x}.c"


def assembly_owner_paths(
    windows: dict[int, int],
    markers: dict[int, list[tuple[Path, dict]]],
    code2_start: int,
    write: bool,
) -> dict[int, Path]:
    owners: dict[int, Path] = {}
    grouped: dict[Path, list[tuple[int, int, list[str]]]] = defaultdict(list)
    pending = [(address, size) for address, size in windows.items() if address not in markers]
    for address, size in pending:
        aggregate = CODE2_ASM if address >= code2_start else CODE1_ASM
        path = FUNCTION_SOURCES / owner_bucket(address, code2_start)
        owners[address] = path.relative_to(REPO)
        grouped[path].append((address, size, assembly_words(aggregate, address, size)))
    if not write:
        return owners

    FUNCTION_SOURCES.mkdir(parents=True, exist_ok=True)
    for stale in FUNCTION_SOURCES.iterdir():
        if stale.name.startswith(("func_", "code1_", "code2_")):
            stale.unlink()
    for path, functions in grouped.items():
        generated = [
            "/* Generated by tools/reconcile_function_boundaries.py. */",
            "/* Exact retail assembly ownership units grouped into a C translation unit. */",
            '#include "../../include/type.h"',
            "",
        ]
        for address, size, words in functions:
            label = f"func_{address:08x}"
            generated.extend(
                [
                    f"// FUN_{address:08X} RETAIL_ASM",
                    f"asm void {label}(void)",
                    "{",
                    "    .set noat",
                    "    .set noreorder",
                    *(f"    .word 0x{word}" for word in words),
                    "}",
                    "",
                ]
            )
        path.write_text("\n".join(generated), encoding="utf-8")
    return owners


def function_map_rows(
    windows: dict[int, int],
    markers: dict[int, list[tuple[Path, dict]]],
    assembly_owners: dict[int, Path],
) -> list[str]:
    rows: list[str] = []
    for address, size in windows.items():
        entries = markers.get(address)
        if entries:
            path, _marker = entries[0]
        else:
            path = assembly_owners[address]
        rows.append(f"{address:08x} {size:>6} MAPPED   {path}")
    return rows


def make_windows(boundaries: list[int], start: int, end: int) -> dict[int, int]:
    selected = sorted(address for address in boundaries if start <= address < end)
    if not selected:
        raise RuntimeError(f"no function boundaries in {start:#x}-{end:#x}")
    windows: dict[int, int] = {}
    for index, address in enumerate(selected):
        next_address = selected[index + 1] if index + 1 < len(selected) else end
        size = next_address - address
        if address % 4 or size <= 0 or size % 4:
            raise RuntimeError(f"invalid function window {address:#x}+{size:#x}")
        windows[address] = size
    return windows


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--check",
        action="store_true",
        help="validate C markers and assembly coverage without rewriting outputs",
    )
    args = parser.parse_args()

    target = json.loads(TARGET.read_text(encoding="utf-8"))
    ghidra = json.loads(GHIDRA_MAP.read_text(encoding="utf-8"))
    ghidra_addresses = {int(address, 16) for address in ghidra["windows"]}
    code1_start, code1_end = segment_bounds(target, "code1")
    code2_start, code2_end = segment_bounds(target, "code2")
    entry = parse_int(target["elf"]["entry"])

    code1 = splat_entries(CODE1_ASM)
    code1.discard(code1_start)  # two padding nops precede the ELF entry point
    code1 = {address for address in code1 if entry <= address < code1_end}
    code2 = {address for address in ghidra_addresses if code2_start <= address < code2_end}

    # The shared blob has nine functions in both Persona 4 Ghidra analysis and
    # the established Persona 3 FES map. Treat a count change as a hard failure.
    if len(code2) != 9:
        raise RuntimeError(f"expected 9 shared code2 functions, found {len(code2)}")

    windows = make_windows(sorted(code1), entry, code1_end)
    windows.update(make_windows(sorted(code2), code2_start, code2_end))
    windows = dict(sorted(windows.items()))

    markers = source_markers()
    canonical = set(windows)
    duplicates = {address: entries for address, entries in markers.items() if len(entries) > 1}
    nameless = {
        address: entries
        for address, entries in markers.items()
        if any(marker["name"] is None for _path, marker in entries)
    }
    source_only = set(markers) - canonical

    print(f"canonical boundaries: {len(canonical)}")
    print(f"unique C source markers: {len(markers)}")
    print(f"canonical without C source: {len(canonical - set(markers))}")
    print(f"source-only boundaries: {len(source_only)}")
    print(f"duplicate source addresses: {len(duplicates)}")
    print(f"markers without definitions: {len(nameless)}")
    for label, problems in (("duplicate", duplicates), ("nameless", nameless)):
        for address, entries in sorted(problems.items()):
            print(f"{label} {address:08x}: {format_locations(entries)}")
    if source_only:
        for address in sorted(source_only):
            print(f"source-only {address:08x}: {format_locations(markers[address])}")
    if duplicates or nameless or source_only:
        return 1

    assembly_owners = assembly_owner_paths(
        windows,
        markers,
        code2_start,
        write=not args.check,
    )
    print(f"generated C owner functions: {len(assembly_owners)}")
    if args.check:
        return 0

    metadata = {
        "program": target["serial"],
        "sha1": target["elf"]["sha1"],
        "generated_from": "Splat code1 control-flow scan plus Ghidra/shared-SDK code2 boundaries",
        "function_count": len(windows),
        "evidence": {
            "code1_splat": len(code1),
            "code2_ghidra_shared_sdk": len(code2),
            "ghidra_total": ghidra["function_count"],
        },
        "windows": {f"{address:08x}": size for address, size in windows.items()},
    }
    OUTPUT_MAP.write_text(json.dumps(metadata, indent=2) + "\n", encoding="utf-8")

    lines = [
        "// Canonical Persona 4 USA function symbols.",
        "// Address names are placeholders until evidence supports semantic names.",
    ]
    for address in windows:
        name = "_start" if address == entry else f"func_{address:08x}"
        lines.append(f"{name} = 0x{address:08X}; // type:func")
    SYMBOLS.write_text("\n".join(lines) + "\n", encoding="utf-8")

    FUNCTION_MAP.parent.mkdir(parents=True, exist_ok=True)
    FUNCTION_MAP.write_text(
        "\n".join(function_map_rows(windows, markers, assembly_owners)) + "\n",
        encoding="utf-8",
    )

    print(f"code1 boundaries: {len(code1)}")
    print(f"code2 boundaries: {len(code2)}")
    print(f"canonical functions: {len(windows)}")
    print(f"wrote {OUTPUT_MAP.relative_to(REPO)}")
    print(f"wrote {SYMBOLS.relative_to(REPO)}")
    print(f"wrote {FUNCTION_MAP.relative_to(REPO)} with {len(windows)} boundaries")
    print(f"wrote {FUNCTION_SOURCES.relative_to(REPO)} with {len(set(assembly_owners.values()))} C files")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
