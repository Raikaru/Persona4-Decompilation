#!/usr/bin/env python3
"""Group open first-party functions by near-identical retail code.

Retail is full of families: the same routine instantiated per state, per slot
or per element, differing only in a constant or a target address. Matching one
member gives the exact source shape for the rest, so a cluster is worth far
more per unit of effort than an isolated function of the same size.

Similarity is computed on the OPCODE SKELETON - each instruction reduced to its
primary opcode and, for R-type, its function field, with all immediates,
offsets and register numbers discarded. That ignores exactly the things a
family varies and keeps the control flow and instruction mix that a source
shape determines.

    python tools/sibling_census.py [min_cluster] [min_window]
"""
import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
EDIT_SLACK = 6
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402
import build as B  # noqa: E402


def skeleton(data: bytes) -> tuple:
    out = []
    for i in range(0, len(data) - 3, 4):
        word = struct.unpack_from("<I", data, i)[0]
        op = word >> 26
        out.append((op, word & 0x3F) if op == 0 else (op,))
    return tuple(out)


def main() -> int:
    least = int(sys.argv[1]) if len(sys.argv) > 1 else 2
    smallest = int(sys.argv[2]) if len(sys.argv) > 2 else 32
    cfg = V.load_config()
    retail = V.RetailElf(cfg["retail_elf"], B.TARGET, B.RETAIL_SHA1)
    bounds = B.load_windows()
    import bisect

    rows = json.load(open(REPO / "build/verify_wave.json"))["results"]
    entries = []
    for r in rows:
        if r["status"] != "ASM":
            continue
        if V.is_third_party(r["file"]) or V.is_vendor_address(r.get("addr")):
            continue
        address = int(r["addr"], 16)
        index = bisect.bisect_right(bounds, address)
        window = bounds[index] - address if index < len(bounds) else None
        if not window or window < smallest or window > 0x4000:
            continue
        entries.append((skeleton(retail.bytes_at(address, window)),
                        r["addr"], r["name"], r["file"].replace("\\", "/"),
                        window))

    # Exact skeletons first, then absorb near neighbours. Grouping only on
    # exact equality demonstrably under-counts: a family member differing by a
    # single extra load falls out, yet takes the same source shape. A member
    # within EDIT_SLACK instructions of the seed, at the same length, is
    # treated as part of the family.
    exact = defaultdict(list)
    for entry in entries:
        exact[entry[0]].append(entry[1:])

    seeds = sorted(exact.items(), key=lambda kv: (-len(kv[1]), kv[1][0][2]))
    taken = set()
    clusters = []
    for shape, members in seeds:
        group = [m for m in members if m[0] not in taken]
        if not group:
            continue
        for other, others in exact.items():
            if other is shape:
                continue
            # Length may differ: a family member with one extra load or store
            # is still the same routine. Compare on the common prefix and
            # charge the length difference as edits.
            apart = (sum(1 for a, b in zip(shape, other) if a != b)
                     + abs(len(other) - len(shape)))
            if apart and apart <= EDIT_SLACK:
                group += [m for m in others if m[0] not in taken]
        if len(group) < least:
            continue
        taken.update(m[0] for m in group)
        clusters.append(sorted(group))
    clusters.sort(key=lambda v: (-len(v), v[0][2]))
    total = sum(len(c) for c in clusters)
    print("open first-party in clusters of >=%d: %d functions in %d clusters"
          % (least, total, len(clusters)))
    lines = []
    for c in clusters:
        head = "cluster of %d, window %d bytes" % (len(c), c[0][3])
        lines.append(head)
        for a, n, f, w in c:
            lines.append("    %s  %-18s %s" % (a, n, f))
        lines.append("")
    (REPO / "build/sibling_clusters.txt").write_text("\n".join(lines))
    for c in clusters[:12]:
        print("\n%d x %d bytes" % (len(c), c[0][3]))
        for a, n, f, w in c[:6]:
            print("    %s  %-18s %s" % (a, n, f.split("/")[-1]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
