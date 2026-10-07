#!/usr/bin/env python3
"""Search declaration (scan) orders that give retail's colouring.

  regalloc_order_search.py FAIL_SNAP OK_SNAP --nodes 32,33,... --anchor 31
      --target 32:25,33:22,... [--spills 44,45,...] [--exhaustive]
      [--iterations 24000]

FAIL_SNAP and OK_SNAP are the failed and the successful
`after_colorgraph_assignment.json` captures of one class (a spilling
function colours twice). The listed virtuals are placed, in the searched
order, just after the anchor virtual. An order is accepted only if the
failure snapshot still spills exactly --spills (and none of the targets).
The success snapshot must then give the --target colours. The default
search anneals over permutations; --exhaustive tries them all (use it for up
to about eight nodes). Each order printed is a declaration order: declare
those locals in that sequence after the anchor's declaration. The model is
tools/regalloc_whatif.py's replay of b210's simplify stack. Set
MWCCPS2_DEBUGGER to the debugger checkout.
"""
from __future__ import annotations

import argparse
import itertools
import math
import random
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import regalloc_whatif as WI  # noqa: E402


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("fail", type=Path)
    ap.add_argument("ok", type=Path)
    ap.add_argument("--nodes", required=True)
    ap.add_argument("--anchor", type=int, required=True)
    ap.add_argument("--target", required=True)
    ap.add_argument("--spills", default="")
    ap.add_argument("--exhaustive", action="store_true")
    ap.add_argument("--iterations", type=int, default=24000)
    args = ap.parse_args()

    fail, ok = WI.Model(args.fail), WI.Model(args.ok)
    nodes = [int(x) for x in args.nodes.split(",")]
    targets = {int(a): int(b) for a, b in (x.split(":") for x in args.target.split(","))}
    spills = {int(x) for x in args.spills.split(",") if x}

    def score(perm) -> int:
        ats = [(n, args.anchor + (k + 1) / 100.0) for k, n in enumerate(perm)]
        spilled = fail.run(ats=ats)
        if any(spilled.get(n) != -1 for n in spills) or any(spilled.get(n) == -1 for n in targets):
            return -1
        colours = ok.run(ats=ats)
        return sum(1 for n, c in targets.items() if colours.get(n) == c)

    if args.exhaustive:
        ranked = sorted(((score(p), p) for p in itertools.permutations(nodes)), reverse=True)
        for row in ranked[:10]:
            print(row)
        return
    best = None
    for _ in range(8):
        cur = nodes[:]
        random.shuffle(cur)
        cur_score, temp = score(cur), 2.0
        for _ in range(args.iterations // 8):
            cand = cur[:]
            i, j = random.sample(range(len(cand)), 2)
            if random.random() < 0.5:
                cand[i], cand[j] = cand[j], cand[i]
            else:
                cand.insert(j, cand.pop(i))
            s = score(cand)
            if s >= cur_score or random.random() < math.exp((s - cur_score) / max(temp, 0.01)):
                cur, cur_score = cand, s
                if best is None or cur_score > best[0]:
                    best = (cur_score, cur[:])
                    print(best, flush=True)
                    if cur_score == len(targets):
                        return
            temp *= 0.9995
    print("best", best)


if __name__ == "__main__":
    main()
