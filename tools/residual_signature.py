#!/usr/bin/env python3
"""Classify what every banked floor's residual actually is.

`tools/floorboard.py` says how many words a floor is away from retail;
`tools/opclass.py` says which opcodes differ.  Neither says *why*, and the two
causes that turned out to be fixable in source are easy to recognise once they
are named:

  * mask rematerialisation - retail keeps a wide value in a saved register and
    re-emits the narrowing `andi` at every call, where the candidate hoists the
    mask into a saved register and emits `move` at each call.  Fixed by
    declaring the callee's parameter narrow so the mask becomes an argument
    conversion instead of a common subexpression (handoff section 7h-sexies).
  * conversion-register selection - the destination register of a `cvt.w.s` or
    `cvt.s.w` differs.  Usually an `optimization_level 1` or
    `opt_common_subs off` pragma in scope, which takes the conversion
    temporary out of the CSE table (handoff section 7h-quinquies).

Both were found while matching `func_00311930`, and this scan is what makes
them cheap to look for across the rest of the board.

Usage:
  python tools/residual_signature.py                    # every banked floor
  python tools/residual_signature.py src/foo.c func_x   # one function
  python tools/residual_signature.py --list floors.txt  # "<file> <func>" lines

Output is one row per floor, sorted by edit count:

  edits  sig=N  func_0012d630  src/promoted/code1_0012.c

`sig` counts the alignment rows carrying one of the two signatures.  A floor
whose `sig` is close to its edit count is one of these two classes and is worth
a source experiment; a floor with `sig=0` is a plain colouring or scheduling
wall and is not.
"""

from __future__ import annotations

import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))

from fnalign import (FUNCTION_WINDOWS, TARGET, RetailElf, _object_for,  # noqa: E402
                     _read_json, align, decode, load_config, scan_markers,
                     window_for)

REPO = TOOLS.parent


def _boundaries(windows: dict) -> list[int]:
    bounds = {int(item, 16) for item in windows["windows"]}
    bounds.update(int(item, 16) + size for item, size in windows["windows"].items() if size)
    for path in (REPO / "src").rglob("*.c"):
        try:
            bounds.update(marker["addr"] for marker in scan_markers(path))
        except OSError:
            continue
    return sorted(bounds)


def _floors() -> list[tuple[Path, str]]:
    """Every guarded NON_MATCHING body in the tree, as (file, symbol)."""
    found: list[tuple[Path, str]] = []
    for path in sorted((REPO / "src").rglob("*.c")):
        if path.parent.name == "generated":
            continue
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue
        if "NONMATCHING" not in text:
            continue
        for marker in scan_markers(path):
            name = marker["name"]
            if f"// FUN_{name[5:].upper()} NONMATCHING" in text:
                found.append((path.relative_to(REPO), name))
    return found


def classify(source: Path, function: str, candidate: Path, cfg: dict,
             elf: RetailElf, bounds: list[int]) -> tuple[int, int]:
    body, relocations = _object_for((REPO / source).resolve(), function,
                                    candidate.resolve(), cfg)
    address = int(function[5:], 16)
    window = window_for(address, bounds)
    retail = elf.bytes_at(address, window)
    while len(retail) >= 4 and not any(retail[-4:]) and len(retail) > len(body):
        retail = retail[:-4]
    retail_text, object_text = decode(retail, address), decode(body, 0)
    relocated = {relocation["offset"] // 4 for relocation in relocations}
    script, edits, _reloc = align(retail_text, object_text, relocated)
    signature = 0
    for tag, i1, i2, j1, j2 in script:
        if tag not in ("replace", "delete", "insert"):
            continue
        left, right = " ".join(retail_text[i1:i2]), " ".join(object_text[j1:j2])
        if "cvt." in left and "cvt." in right:
            signature += 1
        if ("andi" in left and "move" in right) or ("move" in left and "andi" in right):
            signature += 1
    return edits, signature


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("file", nargs="?", help="C source file")
    parser.add_argument("function", nargs="?", help="object symbol")
    parser.add_argument("--list", dest="listing", help='file of "<path> <symbol>" lines')
    args = parser.parse_args()

    if args.listing:
        targets = [(Path(parts[0]), parts[1])
                   for parts in (line.split() for line in Path(args.listing).read_text().split("\n"))
                   if len(parts) >= 2]
    elif args.file and args.function:
        targets = [(Path(args.file), args.function)]
    else:
        targets = _floors()

    cfg = load_config()
    windows = _read_json(FUNCTION_WINDOWS)
    elf = RetailElf(cfg["retail_elf"], _read_json(TARGET), windows["sha1"])
    bounds = _boundaries(windows)

    rows: list[tuple[int, int, str, str]] = []
    with tempfile.TemporaryDirectory() as tmp:
        for source, function in targets:
            candidate = Path(tmp) / f"{function}.c"
            subprocess.run([sys.executable, "-E", "-s", str(TOOLS / "measure_guarded.py"),
                            str(source), function, "--save-candidate", str(candidate)],
                           capture_output=True, text=True, cwd=REPO)
            if not candidate.is_file():
                continue
            try:
                edits, signature = classify(source, function, candidate, cfg, elf, bounds)
            except BaseException:  # noqa: BLE001 - _die raises SystemExit
                continue
            rows.append((edits, signature, function, str(source)))

    for edits, signature, function, source in sorted(rows):
        print(f"{edits:5d}  sig={signature:2d}  {function}  {source}")
    flagged = sum(1 for row in rows if row[1])
    print(f"\n{len(rows)} floors measured, {flagged} carry a mask/conversion signature")


if __name__ == "__main__":
    main()
