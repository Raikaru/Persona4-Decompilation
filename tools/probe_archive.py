#!/usr/bin/env python3
"""Temporarily install an archived candidate body and diff it against retail.

The wave archives near-miss bodies under docs/probe_archive/<LANE>_<addr>_body.c and revert
the source to INCLUDE_ASM, which is correct for the tree but makes the residual
unreadable afterwards. This splices one back in, runs tools/fndiff.py, prints
the differing rows, and always restores the file.

    python tools/probe_archive.py docs/probe_archive/FP3D_003d5710_body.c src/promoted/code1_003d.c
"""
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent


def main() -> int:
    archive, source = Path(sys.argv[1]), Path(sys.argv[2])
    addr = re.search(r"([0-9a-fA-F]{8})", archive.name).group(1).lower()
    name = "func_" + addr

    body = "\n".join(l for l in archive.read_text(errors="replace").splitlines()
                     if not l.lstrip().startswith("/*") or "*/" not in l)
    # newline="" preserves the file's existing line endings. Sources in this
    # tree are CRLF; reading in default text mode and writing back with
    # newline="\n" silently rewrote every line of the file, which showed up as
    # a whole-file diff after the "restore" in the finally block below.
    original = source.read_text(encoding="utf-8", errors="replace", newline="")
    # \r? because the tree is CRLF and `original` is now read with the line
    # endings preserved, so `$` would otherwise sit behind a carriage return.
    include = re.search(r'^INCLUDE_ASM\("[^"]+", %s\);\r?$' % name, original, re.M)
    if not include:
        print("no bare INCLUDE_ASM row for %s in %s" % (name, source))
        return 1

    patched = original[:include.start()] + body + original[include.end():]
    try:
        source.write_text(patched, encoding="utf-8", newline="")
        proc = subprocess.run(
            [sys.executable, "tools/fndiff.py", str(source), name],
            cwd=REPO, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        print(proc.stdout)
    finally:
        source.write_text(original, encoding="utf-8", newline="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
