#!/usr/bin/env python3
"""Measure the guarded NON_MATCHING body of one function.

Usage: measure_guarded.py <source> <func> [--save-candidate PATH]

A banked floor lives behind `#ifdef NON_MATCHING`, so the production arm is
the `INCLUDE_ASM` fallback -- which reproduces retail by construction.
Running `fnalign` or `fndiff` against the owner therefore measures retail
against itself and reports zero differing words, which has already been
mistaken once for a matched function.  This tool does the only correct
thing: it lifts the guarded body out, splices it over the region in a
scratch copy of the translation unit, and scores that.

`--save-candidate PATH` also writes the extracted body, so the same bytes
can be handed to `tools/fnalign.py --candidate PATH` for the edit script and
to `tools/wscan_pairs.py` for the sign-extension counts.
"""
import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import probe_variants as probe

GUARD_RE = re.compile(r"#\s*(?:ifdef|ifndef|if|else|elif|endif)\b")
INCLUDE_RE = re.compile(r"INCLUDE_ASM\s*\(")


def extract_guarded_body(text: str, marker: str, function: str) -> str:
    """Return the region with its guard scaffolding removed.

    Inner `#pragma` lines are part of the measured body and are kept; only
    the conditional directives and the `INCLUDE_ASM` fallback row go.
    """
    start, end = probe.region_for(text, marker, function)
    kept = [line for line in text[start:end].splitlines(keepends=True)
            if not GUARD_RE.match(line.strip())
            and not INCLUDE_RE.match(line.strip())]
    return "".join(kept)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("source")
    parser.add_argument("function")
    parser.add_argument("--save-candidate", dest="save", metavar="PATH",
                        help="also write the extracted body here")
    args = parser.parse_args()

    source = Path(args.source)
    match = re.search(r"([0-9a-fA-F]{8})", args.function)
    if match is None:
        parser.error(f"cannot read an address out of {args.function!r}")
    marker = "FUN_" + match.group(1).upper()

    text = probe._read_text(source)
    body = extract_guarded_body(text, marker, args.function)
    if args.save:
        Path(args.save).write_text(body)
        print(f"saved candidate to {args.save} ({len(body)} bytes)")

    start, end = probe.region_for(text, marker, args.function)
    newline = probe._newline_for(source.read_bytes())
    patched = probe.splice_region(
        text, start, end, probe._normalise_candidate(body, newline), newline)
    with probe.scratch_source(source.resolve()) as scratch:
        scratch.write_bytes(patched.encode("utf-8", errors="surrogateescape"))
        score, diagnostics = probe.run_fndiff(
            scratch, args.function, source.resolve())
    print(diagnostics.rstrip())
    if score is None:
        print(f"probe failed for {args.function}")
        return 1
    print(f"GUARDED_SCORE {args.function}: {score}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
