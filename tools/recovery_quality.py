#!/usr/bin/env python3
"""Measure how far MATCHED functions are from readable recovered source.

A byte-identical function is not finished source. It can still carry every trace
of the decompiler it came from: an address for a name, `D_007973A0` for a global,
`u8 *` for an object pointer, numeric field offsets, `temp_3`/`var_2` locals, and
unexplained masks. Reporting only MATCH versus ASM makes that invisible, so a
match count reads as a count of finished functions when it is not.

This tool scores each matched first-party function on three axes that are
independent of matching, so the two can be tracked apart:

NAMED       the function's own identifier is not a `func_<address>` placeholder.
            Address names are the single biggest obstacle to navigating the tree,
            and a neutral descriptive name is recoverable from behaviour without
            claiming to be the original Atlus identifier.

TYPED       the body reaches its data through named types, not raw arithmetic.
            Disqualifiers are a cast-and-offset dereference (`*(T *)(p + 0x18)`),
            an `M2C_FIELD` macro, or an `arg`/`temp`/`var`/`sp` declared as a bare
            `u8 *` and then indexed. Raw offsets are an acceptable *starting*
            point per docs/style, but once the offsets are established the field
            should be named, and until then the function is not recovered.

DOCUMENTED  a non-trivial function carries prose explaining what it does or why a
            constant is what it is. Trivial bodies (a single statement, or a
            forwarding wrapper) are exempt: a comment restating one line is
            noise, not documentation.

A function also carries RESIDUE if it still uses decompiler-generated local
names (`temp_3`, `var_2`, `uVar1`, `iVar1`, `bVar1`, `spA0`, `param_1`). Residue
is a subset of not-TYPED but is worth counting on its own because it is the
cheapest thing to fix and the most jarring to read.

Only MATCHED first-party functions are scored. An `INCLUDE_ASM` fallback has no
source to judge, and middleware (`rw/`, `cri/`, `sce/`, crt0, libc) is out of
scope for the campaign.

Usage:
    python tools/recovery_quality.py --report C:/tmp/verify.json
    python tools/recovery_quality.py --report <r> --json build/recovery.json
    python tools/recovery_quality.py --report <r> --worst 20
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import verify as V  # noqa: E402

PLACEHOLDER_NAME = re.compile(r"^(?:func|FUN)_[0-9A-Fa-f]{8}$")

# `*(u32 *)(base + 0x18)` and `*(u8 **)(p + 4)` -- a cast-and-offset read or write.
RAW_FIELD = re.compile(r"\*\s*\(\s*[A-Za-z_][\w ]*\**\s*\*\s*\)\s*\(")
M2C_MACRO = re.compile(r"\bM2C_[A-Z_]+\b")

# Decompiler-generated local names, as produced by m2c and Ghidra.
RESIDUE_NAME = re.compile(
    r"\b(?:"
    r"temp_\d+(?:_\d+)?"
    r"|var_\d+(?:_\d+)?"
    r"|[uibfa]Var\d+"
    r"|param_\d+"
    r"|sp[0-9A-F]{2,3}"
    r"|unksp[0-9A-F]{2,3}"
    r")\b"
)

# Prose worth counting: a comment that is not a marker, a pragma justification we
# already lint for, or a bare address restatement.
NOISE_COMMENT = re.compile(
    r"^\s*(?://\s*FUN_[0-9A-Fa-f]{8}|/\*+\s*\*/|\*+/?|//+)\s*$"
)


def is_trivial(body: str) -> bool:
    """A body whose whole point is one statement needs no prose."""
    statements = [
        line.strip()
        for line in body.splitlines()
        if line.strip() and not line.strip().startswith(("//", "/*", "*", "}"))
    ]
    # signature + one statement + brace lines
    return len(statements) <= 3


def has_prose(before: list[str], body: str) -> bool:
    """Is there a human sentence attached to this function?"""
    for line in list(before) + body.splitlines():
        stripped = line.strip()
        if not ("//" in stripped or "/*" in stripped or stripped.startswith("*")):
            continue
        if NOISE_COMMENT.match(stripped):
            continue
        # Strip comment punctuation and require several real words.
        text = re.sub(r"[/*]+", " ", stripped).strip()
        if len(text.split()) >= 4:
            return True
    return False


def function_bodies(path: Path) -> dict[str, tuple[list[str], str]]:
    """Map each marked function name to (preceding lines, body text).

    The body runs from the definition line to its balanced closing brace, so a
    guarded `#ifdef NON_MATCHING` alternative is not mistaken for the real one.
    """
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    out: dict[str, tuple[list[str], str]] = {}
    for marker in V.scan_markers(path):
        name = marker.get("name")
        if not name:
            continue
        start = None
        for index in range(marker["line"], min(marker["line"] + 12, len(lines))):
            if re.search(r"\b%s\b\s*\(" % re.escape(name), lines[index]):
                start = index
                break
        if start is None:
            continue
        opened = False
        depth = 0
        end = start
        for index in range(start, len(lines)):
            depth += lines[index].count("{") - lines[index].count("}")
            if "{" in lines[index]:
                opened = True
            if opened and depth <= 0:
                end = index
                break
        before = lines[max(0, marker["line"] - 6):marker["line"]]
        out[name] = (before, "\n".join(lines[start:end + 1]))
    return out


def score(name: str, before: list[str], body: str) -> dict[str, bool]:
    code = "\n".join(V.sanitize_c_lines(body.splitlines()))
    named = not PLACEHOLDER_NAME.match(name)
    residue = bool(RESIDUE_NAME.search(code))
    typed = not (RAW_FIELD.search(code) or M2C_MACRO.search(code) or residue)
    documented = has_prose(before, body) or is_trivial(body)
    return {
        "named": named,
        "typed": typed,
        "documented": documented,
        "residue": residue,
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--report", required=True,
                        help="verify.py --json report to read MATCH status from")
    parser.add_argument("--json", metavar="PATH",
                        help="write the machine-readable summary here")
    parser.add_argument("--worst", type=int, default=0, metavar="N",
                        help="list the N files with the most unrecovered matches")
    args = parser.parse_args()

    report = json.loads(Path(args.report).read_text(encoding="utf-8"))
    matched: dict[str, list[str]] = {}
    for row in report["results"]:
        if row["status"] != "MATCH" or V.is_third_party(row["file"]):
            continue
        matched.setdefault(row["file"].replace("\\", "/"), []).append(row["name"])

    totals = {"matched": 0, "named": 0, "typed": 0, "documented": 0, "residue": 0}
    per_file: dict[str, dict[str, int]] = {}
    for rel, names in sorted(matched.items()):
        path = REPO / rel
        if not path.exists():
            continue
        bodies = function_bodies(path)
        counts = {"matched": 0, "named": 0, "typed": 0, "documented": 0, "residue": 0}
        for name in names:
            entry = bodies.get(name)
            if entry is None:
                continue
            flags = score(name, *entry)
            counts["matched"] += 1
            for key in ("named", "typed", "documented", "residue"):
                counts[key] += int(flags[key])
        if counts["matched"]:
            per_file[rel] = counts
            for key in totals:
                totals[key] += counts[key]

    def pct(part: int) -> float:
        return round(100.0 * part / totals["matched"], 3) if totals["matched"] else 0.0

    summary = {
        "schema_version": 1,
        "source_report": args.report,
        "matched_first_party": totals["matched"],
        "named": totals["named"],
        "typed": totals["typed"],
        "documented": totals["documented"],
        "decompiler_residue": totals["residue"],
        "named_percent": pct(totals["named"]),
        "typed_percent": pct(totals["typed"]),
        "documented_percent": pct(totals["documented"]),
        "residue_percent": pct(totals["residue"]),
        "files": per_file,
    }

    print(f"matched first-party functions scored: {totals['matched']}")
    print(f"  NAMED       {totals['named']:5d}  ({summary['named_percent']}%)"
          "  non-placeholder identifier")
    print(f"  TYPED       {totals['typed']:5d}  ({summary['typed_percent']}%)"
          "  no raw-offset/M2C access, no generated locals")
    print(f"  DOCUMENTED  {totals['documented']:5d}  ({summary['documented_percent']}%)"
          "  prose, or trivially self-evident")
    print(f"  residue     {totals['residue']:5d}  ({summary['residue_percent']}%)"
          "  still uses temp_/var_/uVar/param_/spNN names")

    if args.worst:
        ranked = sorted(per_file.items(),
                        key=lambda kv: kv[1]["matched"] - kv[1]["typed"],
                        reverse=True)
        print(f"\nfiles with the most matched-but-untyped functions:")
        for rel, counts in ranked[:args.worst]:
            gap = counts["matched"] - counts["typed"]
            print(f"  {gap:4d} of {counts['matched']:4d}  {rel}")

    if args.json:
        out = Path(args.json)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
        print(f"\nreport: {args.json}")


if __name__ == "__main__":
    main()
