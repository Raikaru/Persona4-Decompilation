#!/usr/bin/env python3
"""Run the AST permuter against an archived near-miss body.

The permuter needs a live C body to mutate, but this tree holds 0 MISMATCH by
policy: every unmatched function is a bare INCLUDE_ASM fallback. The best
reconstructions live in docs/probe_archive/<LANE>_<addr>_body.c instead, so
tools/permute_sweep.py -- which discovers targets by scanning for `#ifdef
NON_MATCHING` bodies -- never sees them. That is the gap this closes: it
splices an archived body back in, drives tools/permute_ast.py on it, and
always restores the source.

There are 829 archived bodies for functions that are still unmatched, many
recorded at normalized_diff 2-9, which is exactly the residual range the
permuter is good at: small register-allocation, temporary-materialisation and
scheduling differences that respond to source-level permutation but not to
hand reasoning.

    python3 tools/permute_archived.py docs/probe_archive/S034_0034ac00_body.c \
        src/promoted/code1_0034.c --time 300

On success the winning source is left in place and reported; otherwise the
file is restored byte-for-byte. Note the permuter's raw output is usually not
committable (uninitialised reads, `if (1) {}`, comma operators, dead temps) --
run tools/permute_min.py on a hit before considering it for the tree.

Line endings are preserved: this tree is CRLF and rewriting it to LF produces
a whole-file diff.
"""

import argparse
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent


def splice(source: Path, name: str, body: str) -> tuple[str, str] | None:
    """Return (original, patched) with BODY replacing the bare INCLUDE_ASM row."""

    original = source.read_text(encoding="utf-8", errors="replace", newline="")
    # \r? because the tree is CRLF and the newlines are preserved above.
    include = re.search(r'^INCLUDE_ASM\("[^"]+", %s\);\r?$' % name, original, re.M)
    if include is None:
        return None
    return original, original[: include.start()] + body + original[include.end() :]


def strip_header(text: str) -> str:
    """Drop the archive's leading /* ... */ measurement headers."""

    out, depth = [], 0
    for line in text.splitlines():
        stripped = line.lstrip()
        if depth == 0 and stripped.startswith("/*"):
            depth = 1
            if "*/" in stripped:
                depth = 0
            continue
        if depth:
            if "*/" in line:
                depth = 0
            continue
        out.append(line)
    return "\n".join(out).strip("\n")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("archive", type=Path)
    ap.add_argument("source", type=Path)
    ap.add_argument("--time", type=int, default=300, help="permuter seconds")
    ap.add_argument("--seed", type=int, default=None)
    ap.add_argument(
        "--out",
        type=Path,
        default=None,
        help="write the permuter's best-found region here. Without this the "
             "search is throwaway: both back ends only print the score and "
             "discard the body, so a run that improves 45 -> 28 leaves nothing "
             "behind. Point it at the archive entry to keep the progress.",
    )
    ap.add_argument(
        "--text",
        action="store_true",
        help="drive tools/permute.py (text mutation) instead of permute_ast.py; "
             "required when pycparser cannot parse the TU, which it reports as "
             "CandidateConstructionFailure",
    )
    ap.add_argument(
        "--keep",
        action="store_true",
        help="leave the spliced body in place instead of restoring (debugging)",
    )
    args = ap.parse_args()

    match = re.search(r"([0-9a-fA-F]{8})", args.archive.name)
    if match is None:
        print("cannot read an address out of %s" % args.archive.name)
        return 1
    name = "func_" + match.group(1).lower()

    body = strip_header(args.archive.read_text(errors="replace"))
    spliced = splice(args.source, name, body)
    if spliced is None:
        print("no bare INCLUDE_ASM row for %s in %s" % (name, args.source))
        return 1
    original, patched = spliced

    driver = "tools/permute.py" if args.text else "tools/permute_ast.py"
    cmd = [sys.executable, driver, str(args.source), name,
           "--time", str(args.time)]
    if args.out is not None:
        cmd += ["--out", str(args.out)]
    if args.seed is not None:
        cmd += ["--seed", str(args.seed)]

    won = False
    args.source.write_text(patched, encoding="utf-8", newline="")
    try:
        proc = subprocess.run(cmd, cwd=REPO, stdout=subprocess.PIPE,
                              stderr=subprocess.STDOUT, text=True)
        print(proc.stdout)
        lowered = proc.stdout.lower()
        won = "found match" in lowered or "score 0" in lowered
    finally:
        # Restore unless the permuter actually won, so a losing run can never
        # leave a live non-MATCH body behind.
        if not won and not args.keep:
            args.source.write_text(original, encoding="utf-8", newline="")
    if won:
        print("PERMUTER HIT retained in %s -- reduce it with tools/permute_min.py"
              % args.source)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
