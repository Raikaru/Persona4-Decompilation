#!/usr/bin/env python3
"""Temporarily install an archived candidate body and diff it against retail.

The wave archives near-miss bodies under build/<LANE>_<addr>_body.c and revert
the source to INCLUDE_ASM, which is correct for the tree but makes the residual
unreadable afterwards. This splices one back in, runs tools/fndiff.py, prints
the differing rows, and always restores the file.

    python tools/probe_archive.py build/FP3D_003d5710_body.c src/promoted/code1_003d.c
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
    original = source.read_text(encoding="utf-8", errors="replace")
    include = re.search(r'^INCLUDE_ASM\("[^"]+", %s\);$' % name, original, re.M)
    if not include:
        print("no bare INCLUDE_ASM row for %s in %s" % (name, source))
        return 1

    patched = original[:include.start()] + body + original[include.end():]
    try:
        source.write_text(patched, encoding="utf-8", newline="\n")
        proc = subprocess.run(
            [sys.executable, "tools/fndiff.py", str(source), name],
            cwd=REPO, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        print(proc.stdout)
    finally:
        source.write_text(original, encoding="utf-8", newline="\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
