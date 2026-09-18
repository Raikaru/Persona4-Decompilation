#!/usr/bin/env python3
"""Measure every cheap MWCC pragma, and every pair of them, on a banked floor.

Four pragmas had been swept tree-wide: `schedule on`, `opt_common_subs off`,
`opt_loop_invariants on` and `opt_propagation off`. Four more exist and cost
exactly one compile each. One of them, `opt_dead_assignments off`, took
`func_001dbba0` from a two-word floor to a byte-exact MATCH on its own, after
the usual four had all been measured and all failed. Reasoning about which
pragma "should" matter has a perfect record of being wrong; measuring costs
seconds.

Pairs matter too: two pragmas together are a different allocation from either
alone, and `--pairs` measures all 28 combinations.

`#pragma optimization_level` is a third axis and is always measured: 0, 1, 3
and 4 each compile differently from the -O2 baseline. Level 3 shrinks a
218-instruction body to 179, which is the direction a candidate that is over
retail's size needs to move. `decomp_lint` treats a non-2 level as an H003
warning, not an error, so it is allowed with a measured justification like any
other non-baseline pragma.

Beware that mwcc accepts unknown pragmas silently with no diagnostic: a
misspelling is a no-op that looks like a measurement. `inline_depth(0)` and
`optimize_for_size on` are both ignored by this compiler, as is any invented
name.

Usage:
  python3 -E -s tools/pragma_sweep.py src/foo.c func_00123456
  python3 -E -s tools/pragma_sweep.py src/foo.c func_00123456 --pairs
  python3 -E -s tools/pragma_sweep.py --board 50      # every floor <= 50 words,
                                                      # needs tools/floorboard.py first
"""
from __future__ import annotations

import argparse
import concurrent.futures as cf
import itertools
import re
import subprocess
import sys
import tempfile
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

# `optimization_level` is a separate axis from the on/off switches: every one
# of 0, 1, 3 and 4 produces different code from the -O2 baseline, and none of
# them had ever been measured in this tree. Level 3 and 4 are identical to each
# other on every body tested so far but both differ from 2.
LEVELS = [0, 1, 3, 4]

PRAGMAS = [
    ("schedule on", "schedule off"),
    ("opt_common_subs off", "opt_common_subs on"),
    ("opt_loop_invariants on", "opt_loop_invariants off"),
    ("opt_propagation off", "opt_propagation on"),
    ("opt_strength_reduction off", "opt_strength_reduction on"),
    ("opt_dead_assignments off", "opt_dead_assignments on"),
    ("opt_unroll_loops off", "opt_unroll_loops on"),
    ("peephole off", "peephole on"),
]

SCORE = re.compile(r"^\s*p\s+(\d+)", re.M)
GUARDED = re.compile(r"GUARDED_SCORE \S+: (\d+)")


def _probe(args):
    owner, func, text, label, scratch = args
    safe = re.sub(r"\W+", "_", label)
    path = scratch / ("%s_%s.c" % (func, safe))
    path.write_text(text)
    result = subprocess.run(
        [sys.executable, "-E", "-s", "tools/probe_variants.py", owner, func,
         "--candidate", "p=" + str(path)],
        cwd=REPO, capture_output=True, text=True)
    match = SCORE.search(result.stdout)
    return label, (int(match.group(1)) if match else None)


def _banked(owner: str, func: str, scratch: Path):
    body = scratch / ("%s_banked.c" % func)
    result = subprocess.run(
        [sys.executable, "-E", "-s", "tools/measure_guarded.py", owner, func,
         "--save-candidate", str(body)],
        cwd=REPO, capture_output=True, text=True)
    match = GUARDED.search(result.stdout)
    if not body.is_file() or match is None:
        return None, None
    return int(match.group(1)), body.read_text()


def _strip(body: str) -> tuple[str, list[str]]:
    """Remove pragma scaffolding already present so pairs are not doubled."""
    names = tuple("#pragma " + on.split()[0] for on, _ in PRAGMAS)
    kept, dropped = [], []
    for line in body.splitlines(keepends=True):
        if line.strip().startswith(names):
            dropped.append(line.strip())
        else:
            kept.append(line)
    return "".join(kept), dropped


def sweep(owner: str, func: str, pairs: bool, scratch: Path, quiet: bool = False):
    base, body = _banked(owner, func, scratch)
    if body is None:
        print("  %s: no banked guarded body" % func)
        return None
    bare, existing = _strip(body)
    jobs = [(owner, func, "#pragma %s\n" % on + bare + "\n#pragma %s\n" % off, on,
             scratch) for on, off in PRAGMAS]
    jobs += [(owner, func,
              "#pragma optimization_level %d\n" % lvl + bare +
              "\n#pragma optimization_level 2\n",
              "optimization_level %d" % lvl, scratch) for lvl in LEVELS]
    if pairs:
        for (on_a, off_a), (on_b, off_b) in itertools.combinations(PRAGMAS, 2):
            jobs.append((owner, func,
                         "#pragma %s\n#pragma %s\n" % (on_a, on_b) + bare +
                         "\n#pragma %s\n#pragma %s\n" % (off_b, off_a),
                         "%s + %s" % (on_a, on_b), scratch))
    scored = []
    with cf.ThreadPoolExecutor(max_workers=6) as pool:
        for label, value in pool.map(_probe, jobs):
            if value is not None:
                scored.append((value, label))
    scored.sort()
    if not quiet:
        print("%s @ %s  banked %d differing words%s"
              % (func, owner, base,
                 "  (already carries: %s)" % "; ".join(existing) if existing else ""))
        for value, label in scored:
            flag = "  <-- better" if value < base else ""
            print("   %5d  %s%s" % (value, label, flag))
    return base, scored


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("file", nargs="?")
    parser.add_argument("function", nargs="?")
    parser.add_argument("--pairs", action="store_true",
                        help="also measure all 28 pragma pairs")
    parser.add_argument("--board", type=int, metavar="WORDS",
                        help="sweep every floor in /var/tmp/floorboard.txt at or "
                             "below WORDS differing words")
    args = parser.parse_args()
    scratch = Path(tempfile.mkdtemp(prefix="pragma_sweep_"))

    if args.board is not None:
        board = Path("/var/tmp/floorboard.txt")
        if not board.is_file():
            print("run tools/floorboard.py first", file=sys.stderr)
            return 2
        rows = [line.split(None, 2) for line in board.read_text().splitlines()]
        wins = 0
        for words, func, owner in rows:
            if int(words) > args.board:
                continue
            outcome = sweep(owner, func, args.pairs, scratch, quiet=True)
            if outcome is None:
                continue
            base, scored = outcome
            if scored and scored[0][0] < base:
                wins += 1
                print("  WIN  %-15s %-42s %4d -> %4d   [%s]"
                      % (func, owner, base, scored[0][0], scored[0][1]), flush=True)
            else:
                print("       %-15s %-42s %4d" % (func, owner, base), flush=True)
        print("\n%d improvement(s)" % wins)
        return 0

    if not args.file or not args.function:
        parser.error("give a file and function, or --board WORDS")
    sweep(args.file, args.function, args.pairs, scratch)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
