#!/usr/bin/env python3
"""Split the non-matching residual into "nobody has tried this" and "measured floor".

Wave targeting needs that split, and getting it wrong wastes a whole wave: a
function counted as floored is never assigned, and a floored function counted as
untried is handed to an agent who re-derives a known dead end.

Attribution is the entire difficulty. A floor note is prose of arbitrary length
above the marker it justifies, so no fixed window works -- measuring the same
tree with an 12-line window, a 4-line window and a contiguous-comment walk gave
500, 49 and 20 floored functions respectively. Only one rule is stable: a note
belongs to the next marker below it, and a note is a given function's floor only
if no other marker or INCLUDE_ASM sits between them.

The same walk finds two hygiene faults that are otherwise invisible:

* An UNATTRIBUTED note -- prose containing `measured` that no marker follows.
  Usually a floor note orphaned when its INCLUDE_ASM was replaced by C.
* A MISPLACED note -- prose between a `// FUN_` marker and its own INCLUDE_ASM.
  That unhooks the function from verify.py's marker scan, which silently dropped
  16 functions from the census once already.

Usage:
    python tools/floor_census.py --report build/verify.json
    python tools/floor_census.py --report build/verify.json --top 20
    python tools/floor_census.py --report build/verify.json --json build/floors.json
"""

from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

# A marker line, or the INCLUDE_ASM that a marker owns. Either one ends the
# territory of the note above it.
MARKER = re.compile(r"//\s*FUN_[0-9A-Fa-f]{8}\b|INCLUDE_ASM\s*\(")
MARKER_ONLY = re.compile(r"//\s*FUN_([0-9A-Fa-f]{8})\b")
INCLUDE_ASM = re.compile(r"INCLUDE_ASM\s*\(")
# The annotation `tools/decomp_lint.py` requires on a load-bearing construct.
MEASURED = "measured"


class CensusError(Exception):
    pass


def read_lines(path: Path) -> list[str]:
    return path.read_text(encoding="utf-8", errors="replace").split("\n")


def note_for(lines: list[str], index: int, limit: int = 120) -> str | None:
    """The measured note attached to the marker on `index`, or None.

    Walks upward and stops at the first marker or INCLUDE_ASM, because that
    belongs to the previous function and anything above it is not ours.
    """
    if index < 0 or index >= len(lines):
        raise CensusError(f"marker index {index} outside file of {len(lines)} lines")
    for j in range(index - 1, max(-1, index - limit) - 1, -1):
        line = lines[j]
        if MARKER.search(line):
            return None
        if MEASURED in line.lower():
            # Include a little of the surrounding prose so callers can show it.
            return "\n".join(lines[max(0, j - 4) : index]).strip()
    return None


def misplaced_notes(lines: list[str]) -> list[tuple[int, str]]:
    """Notes sitting between a `// FUN_` marker and the INCLUDE_ASM it owns.

    The verifier scans for a marker immediately above the body it introduces, so
    prose wedged in between makes the function invisible to the census.
    """
    out = []
    for i, line in enumerate(lines):
        m = MARKER_ONLY.search(line)
        if not m:
            continue
        for j in range(i + 1, min(len(lines), i + 12)):
            nxt = lines[j]
            if INCLUDE_ASM.search(nxt):
                between = [x for x in lines[i + 1 : j] if x.strip()]
                if any(MEASURED in x.lower() for x in between):
                    out.append((i + 1, m.group(1)))
                break
            if MARKER_ONLY.search(nxt) or nxt.strip().startswith(("static", "void", "int", "u32", "s32", "float")):
                break
    return out


def unattributed_notes(lines: list[str]) -> list[int]:
    """1-based lines holding `measured` prose that no marker follows."""
    out = []
    for i, line in enumerate(lines):
        if MEASURED not in line.lower():
            continue
        if not line.strip().startswith(("//", "*", "/*")) and "*/" not in line:
            continue  # not a comment; a real `measured` identifier in code
        for j in range(i + 1, len(lines)):
            if MARKER.search(lines[j]):
                break
            if lines[j].strip().startswith("#pragma"):
                break  # a pragma justification, which is legitimate
        else:
            out.append(i + 1)
    return out


def census(report: dict, include_third_party: bool = False) -> dict:
    """Classify every non-MATCH function in a verify.py report."""
    import verify

    rows = [r for r in report["results"] if r.get("status") != "MATCH"]
    if not include_third_party:
        rows = [r for r in rows if not verify.is_third_party(r["file"].replace("\\", "/"))]

    cache: dict[str, list[str]] = {}
    untried: list[dict] = []
    floored: list[dict] = []
    for r in rows:
        rel = r["file"].replace("\\", "/")
        if rel not in cache:
            cache[rel] = read_lines(REPO / rel)
        note = note_for(cache[rel], r["line"] - 1)
        entry = {
            "file": rel,
            "addr": r["addr"],
            "status": r.get("status"),
            "window": r.get("window"),
            "note": note,
        }
        (floored if note else untried).append(entry)

    hygiene = {"misplaced": [], "unattributed": []}
    for rel, lines in cache.items():
        for line_no, addr in misplaced_notes(lines):
            hygiene["misplaced"].append({"file": rel, "line": line_no, "addr": addr})
        for line_no in unattributed_notes(lines):
            hygiene["unattributed"].append({"file": rel, "line": line_no})

    return {
        "total": len(rows),
        "untried": untried,
        "floored": floored,
        "hygiene": hygiene,
        "untried_by_file": collections.Counter(e["file"] for e in untried),
    }


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--report", required=True, help="verify.py --json report")
    ap.add_argument("--json", help="write the census here")
    ap.add_argument("--top", type=int, default=0, help="show the N files with the most untried")
    ap.add_argument("--include-third-party", action="store_true")
    args = ap.parse_args(argv)

    report = json.loads(Path(args.report).read_text(encoding="utf-8"))
    result = census(report, args.include_third_party)

    print(
        "residual %d: untried %d, measured floors %d"
        % (result["total"], len(result["untried"]), len(result["floored"]))
    )
    hyg = result["hygiene"]
    if hyg["misplaced"]:
        print("\nMISPLACED notes (between marker and INCLUDE_ASM; hides the function):")
        for h in hyg["misplaced"]:
            print("  %s:%d  FUN_%s" % (h["file"], h["line"], h["addr"]))
    if hyg["unattributed"]:
        print("\nUNATTRIBUTED notes (no marker follows; likely orphaned):")
        for h in hyg["unattributed"][:40]:
            print("  %s:%d" % (h["file"], h["line"]))
        if len(hyg["unattributed"]) > 40:
            print("  ... and %d more" % (len(hyg["unattributed"]) - 40))
    if args.top:
        print("\nmost untried, best wave targets:")
        for rel, n in result["untried_by_file"].most_common(args.top):
            print("  %3d  %s" % (n, rel))

    if args.json:
        out = dict(result)
        out["untried_by_file"] = dict(result["untried_by_file"])
        Path(args.json).write_text(json.dumps(out, indent=1), encoding="utf-8")
        print("\ncensus written to %s" % args.json)
    return 1 if hyg["misplaced"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
