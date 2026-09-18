#!/usr/bin/env python3
"""Compile a standalone C snippet with the project's mwcc and print one
function's decoded instructions.

Use this to isolate a codegen rule (argument emission order, register
colouring, addressing form) in five lines instead of re-probing a 400
instruction recovery.  The snippet needs no project headers; declare the
types it uses.

    python3 -E -s tools/micro_codegen.py /var/tmp/snippet.c funcname
"""
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
sys.path.insert(0, str(REPO / "tools" / "mwccgap"))

import verify  # noqa: E402
import fnalign  # noqa: E402
import subprocess  # noqa: E402
import tempfile  # noqa: E402

cfg = verify.load_config()


def build(path: Path, out: Path) -> None:
    cmd = [cfg["mwcc"], "-c", *cfg["compile_flags"], "-o", str(out), str(path)]
    r = subprocess.run(cmd, cwd=REPO, capture_output=True, text=True)
    if not out.is_file():
        raise SystemExit((r.stdout or "") + (r.stderr or "") or "compile failed")


def dump(obj_path: Path, name: str):
    from verify import ObjectFile
    try:
        body, _ = ObjectFile(obj_path).function(name)
    except KeyError:
        raise SystemExit("symbol %s not present in the object" % name)
    for i, ins in enumerate(fnalign.decode(body, 0)):
        print("%3d %s" % (i, ins))


if __name__ == "__main__":
    source = Path(sys.argv[1])
    with tempfile.TemporaryDirectory(prefix="micro_") as directory:
        obj = Path(directory) / "micro.o"
        build(source, obj)
        dump(obj, sys.argv[2])
