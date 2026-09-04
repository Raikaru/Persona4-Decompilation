#!/usr/bin/env python3
"""Measure an archived candidate in an isolated translation-unit copy.

The wave archives near-miss bodies under
``docs/probe_archive/<LANE>_<addr>_body.c`` while production sources retain
their ``INCLUDE_ASM`` fallback.  This command replaces only the target
definition or fallback row in a temporary copy beside the source, runs the
normal ``fndiff`` comparison, prints its diagnostics, and removes the copy.
Quoted local includes, file-scope declarations, static helpers, and
translation-unit compiler settings therefore remain the same as the source
being measured.

    python tools/probe_archive.py \
        docs/probe_archive/FP3D_003d5710_body.c src/promoted/code1_003d.c

Exit status is 0 when fndiff produced a score (whether matching or not), and
1 for an invalid archive, missing target, or compile/diff failure.  The source
is never installed or otherwise written.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))

import probe_variants as probe  # noqa: E402


ADDRESS_RE = re.compile(r"([0-9a-fA-F]{8})")


def archive_body(text: str, address: str, function: str) -> str:
    """Keep the archive's required declarations and measured pragma context."""
    normalized = text.replace("\r\n", "\n").replace("\r", "\n")
    # Some older archives copied the marker line into the body.  The synthetic
    # marker below is the one region_for should own; discard copied markers so
    # they cannot make the parser stop before the definition.
    normalized = "".join(
        line
        for line in normalized.splitlines(keepends=True)
        if not probe.MARKER_RE.match(line)
    )
    synthetic = f"// FUN_{address.upper()}\n" + normalized
    start, end = probe.region_for(
        synthetic,
        f"FUN_{address.upper()}",
        function,
    )
    # Validate the target, but retain its surrounding declarations/helpers and
    # pragma brackets. Dropping those silently measures a different candidate.
    if not synthetic[start:end].strip():
        raise SystemExit(f"archive has no definition for {function}")
    return normalized


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("archive", type=Path)
    parser.add_argument("source", type=Path)
    args = parser.parse_args()

    matches = list(ADDRESS_RE.finditer(args.archive.name))
    if not matches:
        print(f"cannot read an address out of {args.archive.name}")
        return 1
    # A few archives carry adjacent functions under a compound lane name.  The
    # first address is the owner used by residual_census and by the historical
    # archive naming convention; archive_body validates that target.
    match = matches[0]
    address = match.group(1).lower()
    function = "func_" + address

    try:
        archive_text = probe._read_text(args.archive)
    except OSError as error:
        print(f"cannot read archive {args.archive}: {error}")
        return 1

    source = args.source.resolve()
    if not source.is_file():
        print(f"source file does not exist: {args.source}")
        return 1
    original = source.read_bytes()
    text = original.decode("utf-8", errors="surrogateescape")
    marker = f"FUN_{address.upper()}"
    try:
        start, end = probe.region_for(text, marker, function)
        body = archive_body(archive_text, address, function)
    except (OSError, UnicodeError, SystemExit) as error:
        print(f"cannot prepare {function}: {error}")
        return 1
    newline = probe._newline_for(original)
    body = probe._normalise_candidate(body, newline)
    patched = probe.splice_region(text, start, end, body, newline)

    try:
        with probe.scratch_source(source) as scratch:
            scratch.write_bytes(patched.encode("utf-8", errors="surrogateescape"))
            score, diagnostics = probe.run_fndiff(scratch, function, source)
            if diagnostics.strip():
                print(diagnostics.rstrip())
            if score is None:
                print(f"probe failed for {function}; source unchanged")
                return 1
    except OSError as error:
        print(f"cannot create or write isolated probe copy: {error}")
        return 1
    print(f"measured {function}: {score} differing words; source unchanged")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
