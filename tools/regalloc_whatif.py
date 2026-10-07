#!/usr/bin/env python3
"""Replay b210's simplify-stack builder on a captured colouring and ask
which virtual-register renumbering gives the colours you want.

Input is an `after_colorgraph_assignment.json` snapshot from mwccps2-debugger.
Point MWCCPS2_DEBUGGER at a checkout of that repository.

  regalloc_whatif.py SNAP --show 128,130
  regalloc_whatif.py SNAP --at 128=36.5 --show 128,130,37
  regalloc_whatif.py SNAP --search 621,59 --anchors 40,58,60,700 --target 621:20,59:18

`--at N=F` scans virtual N just after virtual int(F); the fraction orders
several moved virtuals after the same anchor. `--swap A,B` exchanges two
virtuals' scan positions, and `--score N=S` overrides a spill score. The
script first checks that the unmodified model reproduces the captured stack.

Model (docs/matching.md, "Read a colouring residual as an ordering problem"):
- nodes whose degree is below K (ordinary colours plus fallback saved
  registers) are pushed in ascending scan order;
- otherwise the lowest spill-score/degree node is pushed, and an exact tie
  goes to the later one;
- nodes are coloured in reverse push order, each taking the lowest free
  colour.
"""
from __future__ import annotations

import argparse
import itertools
import os
import sys
from pathlib import Path

debugger = os.environ.get("MWCCPS2_DEBUGGER")
if not debugger:
    sys.exit("set MWCCPS2_DEBUGGER to an mwccps2-debugger checkout")
sys.path.insert(0, debugger)
from decomp import register_allocation as RA  # noqa: E402


class Model:
    def __init__(self, path: Path):
        snap = RA._read_json(path)
        self.cap = RA._parse_capture(snap)
        self.raw = {n["array_index"]: n for n in snap["register_allocation"]["nodes"]}
        self.P = self.cap.physical_slots
        self.number = {i: int(n.node_id.split("-")[-1]) for i, n in enumerate(self.cap.nodes)}
        self.index = {v: k for k, v in self.number.items()}
        self.K = bin(self.cap.ordinary_mask).count("1") + len(self.cap.fallback_colors)
        self.observed = RA._work_list(self.cap)

    def stack(self, pos: dict[int, float], scores: dict[int, int]) -> list[int]:
        nodes = self.cap.nodes
        active = [i for i in range(self.P, len(nodes)) if nodes[i].flags & 0x2]

        def weight(a: int, b: int) -> int:
            return 2 if (nodes[a].is_paired or nodes[b].is_paired) else 1

        deg = {i: sum(weight(i, j) for j in nodes[i].neighbors) for i in active}
        done: set[int] = set()
        pushed: list[int] = []

        def push(i: int) -> None:
            done.add(i)
            pushed.append(i)
            for j in nodes[i].neighbors:
                if j in deg and j not in done:
                    deg[j] -= weight(i, j)

        def cost(i: int) -> float:
            if nodes[i].flags & 0x80 or not deg[i]:
                return float("inf")
            return scores.get(self.number[i], self.raw[i].get("spill_score_i32", 0)) / deg[i]

        scan = sorted(active, key=lambda i: pos[i])
        while True:
            while True:
                progressed, remaining = False, []
                for i in scan:
                    if i in done:
                        continue
                    if deg[i] < self.K:
                        push(i)
                        progressed = True
                    else:
                        remaining.insert(0, i)
                if not progressed:
                    break
            if not remaining:
                return list(reversed(pushed))
            best = remaining[0]
            for i in remaining[1:]:
                if cost(i) < cost(best):
                    best = i
            push(best)

    def colour(self, order: list[int]) -> list[int]:
        nodes, cap = self.cap.nodes, self.cap
        colours = [n.assigned_color if n.index < self.P else -1 for n in nodes]
        mask, cursor = cap.ordinary_mask, cap.fallback_cursor
        for i in order:
            while True:
                avail = mask
                for nb in nodes[i].neighbors:
                    if colours[nb] != -1:
                        avail &= ~((3 << colours[nb]) if nodes[nb].is_paired else (1 << colours[nb]))
                c = RA._lowest_color(avail, self.P, nodes[i].is_paired)
                if c is not None:
                    colours[i] = c
                    break
                if cursor < len(cap.fallback_colors):
                    mask |= 1 << cap.fallback_colors[cursor]
                    cursor += 1
                    continue
                break
        return colours

    def run(self, ats=(), swaps=(), scores=None) -> dict[int, int]:
        pos = {i: float(i) for i in range(len(self.cap.nodes))}
        for a, b in swaps:
            pos[self.index[a]], pos[self.index[b]] = pos[self.index[b]], pos[self.index[a]]
        for n, f in ats:
            pos[self.index[n]] = self.index[int(f)] + (f - int(f))
        colours = self.colour(self.stack(pos, scores or {}))
        return {self.number[i]: c for i, c in enumerate(colours)}


def pairs(text: str, sep: str, cast) -> list:
    return [tuple(cast(x) for x in item.split(sep)) for item in text.split(",") if item] if text else []


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("snapshot", type=Path)
    ap.add_argument("--at", action="append", default=[], help="N=F")
    ap.add_argument("--swap", action="append", default=[], help="A,B")
    ap.add_argument("--score", action="append", default=[], help="N=S")
    ap.add_argument("--show", default="")
    ap.add_argument("--search", help="virtuals to place, e.g. 621,59")
    ap.add_argument("--anchors", help="anchor virtuals for --search")
    ap.add_argument("--target", help="N:C,... colours every --search hit must give")
    args = ap.parse_args()

    model = Model(args.snapshot)
    base = model.run()
    reproduced = model.stack({i: float(i) for i in range(len(model.cap.nodes))}, {}) == model.observed
    print("model reproduces captured stack:", reproduced)
    if args.search:
        moves = [int(x) for x in args.search.split(",")]
        anchors = [int(x) for x in args.anchors.split(",")]
        target = dict(pairs(args.target, ":", int))
        for combo in itertools.product(anchors, repeat=len(moves)):
            got = model.run(ats=[(m, a + 0.5) for m, a in zip(moves, combo)])
            if all(got[n] == c for n, c in target.items()):
                print("HIT", " ".join(f"{m}@{a}" for m, a in zip(moves, combo)))
        return
    ats = [(int(a), float(b)) for a, b in (x.split("=") for x in args.at)]
    swaps = [tuple(int(v) for v in x.split(",")) for x in args.swap]
    scores = {int(a): int(b) for a, b in (x.split("=") for x in args.score)}
    got = model.run(ats, swaps, scores)
    for n in (int(x) for x in args.show.split(",") if x):
        print(f"r{n}: {base[n]} -> {got[n]}")


if __name__ == "__main__":
    main()
