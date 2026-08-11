#!/usr/bin/env python3
"""Classify every archived near-miss body by the shape of its residual.

Waves archive near-misses under build/<LANE>_<addr>_body.c and revert the
source, which keeps the tree honest but throws away the diagnosis. This
re-installs each body in turn, runs tools/fndiff.py, and buckets the result, so
a defect shared by many functions shows up as a family worth one lever rather
than as N unrelated grinds.

    python tools/residual_census.py [max_nd]
"""
import json
import re
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
ROW = re.compile(r"^\s*(\d+) !\s*(\S*)\s+(\S*)", re.M)

# Little-endian encodings we care about when naming a residual.
def classify(rows, obj, window):
    """Name the dominant difference between candidate and retail."""
    if not rows:
        return "clean"
    if obj > window:
        return "oversized"
    first = rows[0][0]
    if first == 0:
        return "prologue-divergent-at-0"
    if all(int(a or 0, 16) == int(b or 0, 16) for _, a, b in rows if a and b):
        return "identical-words-shifted"
    tail_only = all(off >= obj - 16 for off, _, _ in rows)
    if tail_only:
        return "epilogue-only"
    return "body-%d-rows" % len(rows)


def main() -> int:
    limit = int(sys.argv[1]) if len(sys.argv) > 1 else 10
    report = json.load(open(REPO / "build/verify_wave.json"))["results"]
    where = {r["name"]: r["file"].replace("\\", "/") for r in report}

    found = defaultdict(list)
    for archive in sorted((REPO / "build").glob("*_body.c")):
        match = re.search(r"([0-9a-fA-F]{8})", archive.name)
        text = archive.read_text(errors="replace")[:400]
        nd = re.search(r"normalized[_ ]diff[ =:]*(\d+)", text) or \
             re.search(r"\bnd[ =:]*(\d+)\b", text)
        if not match or not nd or int(nd.group(1)) > limit:
            continue
        name = "func_" + match.group(1).lower()
        source = where.get(name)
        if not source:
            continue
        proc = subprocess.run(
            [sys.executable, "build/probe_archive.py", str(archive), source],
            cwd=REPO, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        out = proc.stdout
        head = re.search(r"obj (\d+)B\s+window (\d+)B", out)
        if not head:
            found["probe-failed"].append((name, archive.name)); continue
        obj, window = int(head.group(1)), int(head.group(2))
        rows = [(int(m.group(1)), m.group(2), m.group(3))
                for m in ROW.finditer(out)]
        found[classify(rows, obj, window)].append(
            (name, "obj%d/win%d/%drows" % (obj, window, len(rows))))
        print("%-16s %-24s %s" % (name, "obj%d/win%d" % (obj, window),
                                  classify(rows, obj, window)), flush=True)

    print("\n=== families ===")
    for kind, items in sorted(found.items(), key=lambda kv: -len(kv[1])):
        print("%4d  %s" % (len(items), kind))
        for n, d in items[:8]:
            print("        %s  %s" % (n, d))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
