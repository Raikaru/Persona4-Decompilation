#!/usr/bin/env python3
"""Build the canonical Persona 4 function map from Splat and Ghidra evidence.

Code1 boundaries come from spimdisasm's control-flow scan after the executable
section split is known. Ghidra-only entries inside a Splat function are treated
as internal labels. Code2 is a shared PS2 SDK/kernel blob whose nine function
boundaries and layout match Persona 3 FES; Ghidra independently identifies the
same nine entries in Persona 4.
"""

from __future__ import annotations

import json
import re
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TARGET = REPO / "config" / "target.json"
GHIDRA_MAP = REPO / "tools" / "slus21782_functions.ghidra.json"
OUTPUT_MAP = REPO / "tools" / "slus21782_functions.json"
SYMBOLS = REPO / "config" / "symbol_addrs.txt"
CODE1_ASM = REPO / "asm" / "code1.s"

GLABEL = re.compile(
    r"^glabel\s+(\S+)\s*\n\s*/\*\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+",
    re.MULTILINE,
)


def parse_int(value: int | str) -> int:
    return value if isinstance(value, int) else int(value, 0)


def segment_bounds(target: dict, name: str) -> tuple[int, int]:
    segment = next(segment for segment in target["segments"] if segment["name"] == name)
    return parse_int(segment["start"]), parse_int(segment["end"])


def splat_entries(path: Path) -> set[int]:
    text = path.read_text(encoding="utf-8")
    return {int(match.group(2), 16) for match in GLABEL.finditer(text)}


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

    print(f"code1 boundaries: {len(code1)}")
    print(f"code2 boundaries: {len(code2)}")
    print(f"canonical functions: {len(windows)}")
    print(f"wrote {OUTPUT_MAP.relative_to(REPO)}")
    print(f"wrote {SYMBOLS.relative_to(REPO)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
