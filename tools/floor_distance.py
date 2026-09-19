"""Rank every guarded floor in the tree by how far it is from a MATCH.

`gate_audit.py` answers "is this body the right length".  This answers "how
close is it", which is the question that decides what to work on next.  The
measure is the fnalign edit count - the number of instructions that would have
to change to turn the compiled body into retail - because it stays meaningful
when the counts differ, unlike a differing-word score (handoff 7y).

A floor at two edits is a register-allocation or scheduling wall an hour of
work can finish; a floor at nine hundred is a research project.  Without this
the two look identical in a file listing, and the cheap ones stay buried.

    python3 tools/floor_distance.py                    # closest 40
    python3 tools/floor_distance.py --max-edits 12     # the finishable band
    python3 tools/floor_distance.py --json out.json    # for batch selection
"""
from __future__ import annotations

import argparse
import json
import sys
import tempfile
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))

import fnalign                                        # noqa: E402
import verify                                         # noqa: E402
from measure_guarded import extract_guarded_body      # noqa: E402

GUARD = verify.MARKER if hasattr(verify, "MARKER") else None


def _guards(text: str):
    import re
    return re.finditer(r"// FUN_([0-9A-Fa-f]{8}) NONMATCHING", text)


def targets(only: set[Path]) -> list[tuple[str, str]]:
    out = []
    for path in sorted((REPO / "src").rglob("*.c")):
        if path.parent.name == "generated" or path.name.startswith("."):
            continue
        if only and path.resolve() not in only:
            continue
        rel = path.relative_to(REPO / "src").as_posix()
        if rel.startswith(verify.THIRD_PARTY_PREFIXES):
            continue
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue
        for m in _guards(text):
            out.append((str(path.relative_to(REPO)), m.group(1).upper()))
    return out


def measure(job: tuple[str, str]) -> dict:
    source, tag = job
    name = "func_%s" % tag.lower()
    path = REPO / source
    address = int(tag, 16)
    row: dict = {"function": name, "source": source, "address": tag}
    try:
        cfg = verify.load_config()
        text = path.read_text(errors="replace")
        with tempfile.TemporaryDirectory() as scratch:
            candidate = Path(scratch) / "c.c"
            candidate.write_text(extract_guarded_body(text, "FUN_" + tag, name))
            body, relocations = fnalign._object_for(path, name, candidate, cfg)
        windows = fnalign._read_json(fnalign.FUNCTION_WINDOWS)
        elf = fnalign.RetailElf(cfg["retail_elf"],
                                fnalign._read_json(fnalign.TARGET), windows["sha1"])
        bounds = {int(k, 16) for k in windows["windows"]}
        bounds.update(int(k, 16) + v for k, v in windows["windows"].items() if v)
        retail = elf.bytes_at(address, fnalign.window_for(address, sorted(bounds)))
        # Trim retail's alignment tail so the comparison is instructions
        # against instructions, exactly as gate_audit does.
        while (len(retail) >= 4 and not any(retail[-4:])
               and len(retail) > len(body)):
            retail = retail[:-4]
        script, edits, _reloc = fnalign.align(fnalign.decode(retail, address),
                                              fnalign.decode(body, 0), relocations)
        words = sum(1 for i in range(0, min(len(retail), len(body)), 4)
                    if retail[i:i + 4] != body[i:i + 4])
        words += abs(len(retail) - len(body)) // 4
        row.update(retail=len(retail) // 4, object=len(body) // 4,
                   edits=edits, words=words,
                   hole=max((i2 - i1 for t, i1, i2, _j1, _j2 in script
                             if t == "delete"), default=0),
                   lump=max((j2 - j1 for t, _i1, _i2, j1, j2 in script
                             if t == "insert"), default=0))
    except BaseException as exc:                      # noqa: BLE001
        row["error"] = f"{type(exc).__name__}: {str(exc)[:90]}"
    return row


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("files", nargs="*", help="limit to these source files")
    ap.add_argument("--max-edits", type=int, default=None,
                    help="only show floors at or below this edit distance")
    ap.add_argument("--top", type=int, default=40, help="how many rows to print")
    ap.add_argument("--json", help="write every measurement here")
    ap.add_argument("--jobs", type=int, default=4, help="parallel compiles")
    args = ap.parse_args()

    jobs = targets({Path(f).resolve() for f in args.files})
    print(f"measuring {len(jobs)} guarded floors", flush=True)
    rows = []
    with ProcessPoolExecutor(max_workers=args.jobs) as pool:
        for row in pool.map(measure, jobs):
            rows.append(row)
    if args.json:
        Path(args.json).write_text(json.dumps(rows, indent=1))
    measured = [r for r in rows if "error" not in r]
    measured.sort(key=lambda r: (r["edits"], r["words"]))
    shown = [r for r in measured
             if args.max_edits is None or r["edits"] <= args.max_edits]
    for r in shown[:args.top]:
        exact = "exact" if r["object"] == r["retail"] else "     "
        print(f"  edits {r['edits']:5d}  words {r['words']:5d}"
              f"  {r['object']:5d}/{r['retail']:<5d} {exact}"
              f"  {r['function']}  {r['source']}")
    bodyless = len(rows) - len(measured)
    print(f"\n{len(measured)} floors measured, {bodyless} markers carry no C body")
    if args.max_edits is not None:
        print(f"{len(shown)} at {args.max_edits} edits or fewer")


if __name__ == "__main__":
    main()
