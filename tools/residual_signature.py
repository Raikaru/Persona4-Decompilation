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
import re
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


CALLER_SAVED = ({f"$a{n}" for n in range(4)} | {f"$t{n}" for n in range(10)}
                | {f"$v{n}" for n in range(2)})
CALLEE_SAVED = {f"$s{n}" for n in range(9)}
REGISTER = re.compile(r"\$(?:[a-z]{1,2}\d|zero|sp|ra|fp|gp|at)")


def _register_pairs(left: str, right: str) -> list[tuple[str, str]] | None:
    """Register substitutions turning `left` into `right`, or None if the two
    instructions differ by more than their register names."""
    left_registers, right_registers = REGISTER.findall(left), REGISTER.findall(right)
    if len(left_registers) != len(right_registers):
        return None
    if REGISTER.sub("$", left) != REGISTER.sub("$", right):
        return None
    return [pair for pair in zip(left_registers, right_registers) if pair[0] != pair[1]]


def classify(source: Path, function: str, candidate: Path, cfg: dict,
             elf: RetailElf, bounds: list[int]) -> dict:
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
    counts = {"mask": 0, "cvt": 0, "class": 0, "perm": 0, "other": 0}
    mapping: dict[str, set[str]] = {}
    for tag, i1, i2, j1, j2 in script:
        if tag not in ("replace", "delete", "insert"):
            continue
        left, right = " ".join(retail_text[i1:i2]), " ".join(object_text[j1:j2])
        if "cvt." in left and "cvt." in right:
            counts["cvt"] += 1
            continue
        if ("andi" in left and "move" in right) or ("move" in left and "andi" in right):
            counts["mask"] += 1
            continue
        pairs = _register_pairs(left, right) if i2 - i1 == j2 - j1 == 1 else None
        if not pairs:
            counts["other"] += 1
            continue
        for retail_register, object_register in pairs:
            mapping.setdefault(retail_register, set()).add(object_register)
        if any(a in CALLER_SAVED and b in CALLEE_SAVED
               or a in CALLEE_SAVED and b in CALLER_SAVED for a, b in pairs):
            counts["class"] += 1          # handoff 7n: a live range crossing a call
        else:
            counts["perm"] += 1           # handoff 7m: same class, different number
    stable = {a: next(iter(b)) for a, b in mapping.items() if len(b) == 1}
    return {"edits": edits, "counts": counts, "mapping": stable}


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

    rows: list[tuple[int, str, str, dict]] = []
    with tempfile.TemporaryDirectory() as tmp:
        for source, function in targets:
            candidate = Path(tmp) / f"{function}.c"
            subprocess.run([sys.executable, "-E", "-s", str(TOOLS / "measure_guarded.py"),
                            str(source), function, "--save-candidate", str(candidate)],
                           capture_output=True, text=True, cwd=REPO)
            if not candidate.is_file():
                continue
            try:
                result = classify(source, function, candidate, cfg, elf, bounds)
            except BaseException:  # noqa: BLE001 - _die raises SystemExit
                continue
            rows.append((result["edits"], function, str(source), result))

    print(f"{'edits':>5}  {'mask':>4} {'cvt':>4} {'class':>5} {'perm':>4} {'other':>5}"
          "  function        source")
    for edits, function, source, result in sorted(rows):
        counts = result["counts"]
        mapping = " ".join(f"{a}->{b}" for a, b in sorted(result["mapping"].items())[:4])
        print(f"{edits:5d}  {counts['mask']:4d} {counts['cvt']:4d} {counts['class']:5d} "
              f"{counts['perm']:4d} {counts['other']:5d}  {function}  {source}"
              + (f"   [{mapping}]" if mapping else ""))

    def tally(key: str) -> int:
        return sum(1 for row in rows if row[3]["counts"][key])

    print(f"\n{len(rows)} floors measured")
    print(f"  {tally('mask') + tally('cvt'):3d} carry a mask or conversion signature "
          "(handoff 7h-sexies / 7h-quinquies)")
    print(f"  {tally('class'):3d} carry a caller-versus-callee-saved register class "
          "difference (handoff 7n: check for a counter shared across two loops)")
    print(f"  {tally('perm'):3d} carry a same-class register permutation "
          "(handoff 7m: two probes, then stop)")


if __name__ == "__main__":
    main()
