#!/usr/bin/env python3
"""A/B many source spellings of ONE function and print each one's score.

The loop this replaces -- edit, verify, read, undo, edit again -- costs a
couple of minutes per idea. Here a variant costs about two seconds, so a batch
of eight is cheaper than a single hand round-trip, and the numbers arrive side
by side instead of scattered through a transcript.

The file is restored on the way out, including after an exception or a
Ctrl-C, so a probe never leaves a body live in the tree.

Usage:
    python -E -s tools/recon_probe.py <func_name> <variants.json> <file>

variants.json is a list of [label, source] pairs:

    [["plain",     "void f(void)\\n{\\n    g();\\n}"],
     ["schedule",  "#pragma schedule on\\nvoid f(void)\\n{\\n    g();\\n}"]]

`source` is the complete replacement text for the function INCLUDING any
pragmas it needs, but WITHOUT the `// FUN_XXXXXXXX` marker comment: the marker
is re-emitted for you. That is not a convenience. verify.py counts markers to
decide what exists, so a variant that swallowed its own marker would silently
drop the function from scoring and report a meaningless result.

Scores are read straight from verify.py, so `nd` and `obj/win` mean exactly
what they mean everywhere else in this repo. Read `obj` against `win` before
believing a low `nd`: a body that compiled to almost nothing scores well and
is worth nothing.
"""

import json
import os
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def marker_for(fn):
    return "// " + fn.replace("func_", "FUN_").upper()


def main(argv):
    if len(argv) != 3:
        print(__doc__.strip())
        return 2
    fn, varfile, path = argv

    with open(path, "r", newline="") as f:
        original = f.read()
    variants = json.load(open(varfile))

    marker = marker_for(fn)
    try:
        start = original.index(marker)
    except ValueError:
        print("recon_probe: no %s marker in %s" % (marker, path), file=sys.stderr)
        return 2
    # Take the marker LINE verbatim rather than rebuilding it. Many markers
    # carry a suffix -- `// FUN_003E46E0 NONMATCHING` -- and re-emitting a bare
    # `// FUN_003E46E0` would silently rewrite it. verify.py keys off these
    # comments, so quietly editing one corrupts the very measurement the probe
    # is taking.
    eol = original.index("\n", start)
    marker_line = original[start:eol]
    # The next marker bounds the region this function owns.
    end = original.index("// FUN_", eol)
    head, tail = original[:start], original[end:]

    report = os.path.join(REPO, "build", "recon_probe.json")
    scored = []
    try:
        for label, body in variants:
            with open(path, "w", newline="") as f:
                f.write(head + marker_line + "\n" + body + "\n" + tail)
            subprocess.run([sys.executable, "-E", "-s", "tools/verify.py", path,
                            "--json", report],
                           cwd=REPO, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            try:
                rows = json.load(open(report))["results"]
            except Exception:
                print("%-28s COMPILE_ERROR" % label)
                continue
            row = next((x for x in rows if x["name"] == fn), None)
            if row is None:
                print("%-28s NOT SCANNED (marker lost?)" % label)
                continue
            nd = row.get("normalized_diff")
            print("%-28s %-9s nd=%s obj=%s/%s"
                  % (label, row["status"], nd, row.get("object_size"), row.get("window")))
            if nd is not None:
                scored.append((nd, label))
    finally:
        with open(path, "w", newline="") as f:
            f.write(original)

    print("best:", sorted(scored)[:3])
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
