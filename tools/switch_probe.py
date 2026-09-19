#!/usr/bin/env python3
"""Measure the `switch` spelling of an equality chain against the chain.

MWCC lowers a `switch` as **descending** comparisons with the arm bodies laid
out in **ascending** case order.  An `if (v == c) ... else if` chain cannot
produce that shape however the arms are ordered in source, so a body that
writes a chain where the original wrote a switch pays for it in every arm.

Measured both ways across the tree, the lever is large and it is not
universal:

    func_001441e0   668 -> 47     func_002b0b10    97 -> 114
    func_00288af0   409 -> 104    func_001b3a00    91 -> 115
    func_0025b240   276 -> 226    func_00467bd0   368 -> 382
    func_00146a10   182 -> 99     func_001adea0    49 -> 51
    func_00233bc0   148 -> 70

So measure, never assume.  This probes one function, or sweeps every
first-party floor that carries a chain of at least `--min-arms` arms.

**Scope**: the rewrite handles the single-line arm form m2c emits for a
dispatch table, `if (v == 3) { call(); }`.  Chains whose arms are braced
blocks spanning several lines have to be converted by hand - there are 22
such floors and `chain_variables()` will name the tested variable for you.
The sweep reporting no wins means the single-line form is exhausted, not
that the lever is.

    python3 tools/switch_probe.py src/foo.c func_00123456 --var mode
    python3 tools/switch_probe.py --sweep
"""
from __future__ import annotations

import argparse
import re
import subprocess
import sys
from collections import Counter
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import verify  # noqa: E402
from measure_guarded import extract_guarded_body  # noqa: E402

# `if (v == 3) { one_statement; }` all on one line, the shape m2c emits for a
# dispatch table of single calls.
ONE_LINER = re.compile(
    r"^(\s*)(\}\s*)?(else\s+)?if \((\w+) == (0x[0-9A-Fa-f]+|-?\d+)\) \{ (.*) \}$")
# `} else if (v == 3) {` opening a braced arm.
ARM_OPEN = re.compile(
    r"^(\s*)(\}\s*)?(else\s+)?if \(\s*(\w+) == (0x[0-9A-Fa-f]+|-?\d+)\s*\)\s*\{\s*$")


def rewrite_one_liners(lines, min_arms=4):
    """Rewrite runs of single-line equality arms as ascending-case switches."""
    out, index, converted = [], 0, 0
    while index < len(lines):
        head = ONE_LINER.match(lines[index])
        if not head or head.group(3):          # an `else if` cannot start a run
            out.append(lines[index])
            index += 1
            continue
        indent, variable = head.group(1), head.group(4)
        arms = [(int(head.group(5), 0), head.group(6))]
        cursor = index + 1
        while cursor < len(lines):
            arm = ONE_LINER.match(lines[cursor])
            if not arm or not arm.group(3) or arm.group(4) != variable:
                break
            arms.append((int(arm.group(5), 0), arm.group(6)))
            cursor += 1
        if len(arms) < min_arms:
            out.append(lines[index])
            index += 1
            continue
        converted += 1
        out.append(f"{indent}switch ({variable}) {{")
        for value, body in sorted(arms):
            out.append(f"{indent}case {value}:")
            out.append(f"{indent}    {body}")
            out.append(f"{indent}    break;")
        out.append(f"{indent}}}")
        index = cursor
    return out, converted


def chain_variables(body, min_arms=4):
    """Variables tested by a chain of at least `min_arms` equality arms."""
    counts = Counter(
        match.group(1) for match in
        re.finditer(r"else\s+if\s*\(\s*(\w+)\s*==\s*(?:0x[0-9A-Fa-f]+|-?\d+)\s*\)", body))
    return [name for name, seen in counts.items() if seen + 1 >= min_arms]


def _edits(source, function, candidate):
    out = subprocess.run(
        [sys.executable, "-E", "-s", "tools/fnalign.py", source, function,
         "--candidate", str(candidate), "--quiet"],
        cwd=REPO, capture_output=True, text=True, timeout=900).stdout
    found = re.search(r"edit instructions: (\d+)", out)
    return int(found.group(1)) if found else None


def probe(rel, function, scratch, min_arms):
    text = (REPO / rel).read_text(errors="replace")
    addr = function[5:].upper()
    body = extract_guarded_body(text, f"FUN_{addr}", function)
    if not body:
        return None
    rewritten, converted = rewrite_one_liners(body.split("\n"), min_arms)
    if not converted:
        return None
    base = scratch / f"{function}_chain.c"
    switch = scratch / f"{function}_switch.c"
    base.write_text(body)
    switch.write_text("\n".join(rewritten))
    return converted, _edits(rel, function, base), _edits(rel, function, switch)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", nargs="?")
    ap.add_argument("function", nargs="?")
    ap.add_argument("--sweep", action="store_true",
                    help="probe every first-party floor carrying a chain")
    ap.add_argument("--min-arms", type=int, default=4)
    args = ap.parse_args()

    scratch = Path("/var/tmp/switch_probe")
    scratch.mkdir(exist_ok=True)

    if args.source and args.function:
        targets = [(args.source, args.function)]
    elif args.sweep:
        targets = []
        for path in sorted((REPO / "src").rglob("*.c")):
            if path.parent.name == "generated" or path.name.startswith("."):
                continue
            text = path.read_text(errors="replace")
            rel = str(path.relative_to(REPO))
            for match in re.finditer(r"// FUN_([0-9A-Fa-f]{8}) NONMATCHING", text):
                if verify.code_origin(rel, match.group(1)) == "main":
                    targets.append((rel, "func_" + match.group(1).lower()))
    else:
        ap.error("pass a source and function, or --sweep")

    better = 0
    for rel, function in targets:
        try:
            found = probe(rel, function, scratch, args.min_arms)
        except Exception as exc:
            print(f"  {function}: {type(exc).__name__}: {exc}", file=sys.stderr)
            continue
        if not found:
            continue
        converted, before, after = found
        if before is None or after is None:
            print(f"{function}  {converted} chain(s)  measurement failed  {rel}")
            continue
        verdict = ""
        if after < before:
            verdict = f"  <<< switch is better by {before - after}"
            better += 1
        elif after > before:
            verdict = f"  (chain is better by {after - before})"
        print(f"{function}  {converted} chain(s)  {before} -> {after}{verdict}  {rel}",
              flush=True)
    if args.sweep:
        print(f"\n{better} floor(s) where the switch spelling wins")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
