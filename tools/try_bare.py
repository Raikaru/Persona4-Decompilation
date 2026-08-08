"""Score candidate bodies for a function whose marker is still a bare INCLUDE_ASM.

tools/try_bodies.py resolves the region to replace by scanning outward from the
marker, which over-reaches in files where a long /* measured */ comment sits
between two functions.  For a bare marker the region is exactly one line -- the
INCLUDE_ASM call -- so replacing it needs no scanning at all.

usage: python tools/try_bare.py <file> <func> <candidates.json> [--apply LABEL]

<candidates.json> maps a label to the whole function definition.  The file is
always restored unless --apply names a label, in which case that body is left
in place.  Line endings are preserved.
"""

import json
import os
import pathlib
import subprocess
import sys


def score(report, func):
    if not pathlib.Path(report).exists():
        return 10**6, None
    for r in json.load(open(report))["results"]:
        if r["name"] == func:
            if r["status"] == "MATCH":
                return -1, r
            if r["status"] == "MISMATCH":
                return r.get("normalized_diff", 10**6), r
            return 10**6, r
    return 10**6, None


def main(argv):
    path, func, cands = argv[0], argv[1], argv[2]
    apply_label = None
    if "--apply" in argv:
        apply_label = argv[argv.index("--apply") + 1]

    p = pathlib.Path(path)
    orig = p.read_bytes()
    crlf = b"\r\n" in orig
    unit = pathlib.Path(path).stem

    def enc(s):
        return (s.replace("\n", "\r\n") if crlf else s).encode()

    marker = enc('INCLUDE_ASM("asm/nonmatchings/%s", %s);' % (unit, func))
    if marker not in orig:
        sys.exit("no bare INCLUDE_ASM line for %s in %s" % (func, path))

    bodies = json.load(open(cands))
    # Concurrent lanes each probe their own function; a shared report path lets
    # one lane read another's run (and a failed verify re-read the last one).
    report = "build/_bare_%s_%d.json" % (func, os.getpid())
    best = (10**6, None)
    try:
        for label, body in bodies.items():
            p.write_bytes(orig.replace(marker, enc(body)))
            subprocess.run(
                [sys.executable, "tools/verify.py", "--json", report, path],
                capture_output=True,
            )
            nd, r = score(report, func)
            st = r["status"] if r else "GONE"
            obj = r.get("object_size") if r else None
            win = r.get("window") if r else None
            tag = "  <== MATCH" if nd == -1 else ""
            print("  %-22s %-14s nd=%s obj=%s/%s%s" % (label, st, nd if nd >= 0 else 0, obj, win, tag))
            if nd < best[0]:
                best = (nd, label)
    finally:
        if apply_label is not None:
            p.write_bytes(orig.replace(marker, enc(bodies[apply_label])))
            print("applied %s" % apply_label)
        else:
            p.write_bytes(orig)
    print("best: %s (nd %s)" % (best[1], best[0]))


if __name__ == "__main__":
    main(sys.argv[1:])
