#!/usr/bin/env python3
"""Compile a standalone C file with b210 under the mwccps2-debugger snapshot
hooks and print the PCode of chosen backend stages for every function.

  b210_micro.py FILE.c [STAGE ...]

STAGE defaults to after_propagate_copy_instructions. Other useful stages:
codegen_entry, after_peephole, before_register_allocation. Set
MWCCPS2_DEBUGGER to the debugger checkout; the compiler comes from the
verify config. Use it to learn what a source shape does to the backend in
seconds, without an owner file.
"""
from __future__ import annotations

import importlib.util
import os
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import verify as V  # noqa: E402

GDB = os.environ.get("GDB", "gdb")


def main() -> None:
    debugger = os.environ.get("MWCCPS2_DEBUGGER")
    if not debugger or len(sys.argv) < 2:
        sys.exit(__doc__)
    tool = Path(debugger)
    src = Path(sys.argv[1]).resolve()
    stages = sys.argv[2:] or ["after_propagate_copy_instructions"]
    out = ROOT / "build/micro" / src.stem
    shutil.rmtree(out, ignore_errors=True)
    out.mkdir(parents=True)
    compiler = Path(V.load_config()["mwcc"]).resolve()
    args = ["-O2", "-Iinclude", "-c", str(src), "-o", str(out / "m.o")]
    spec = importlib.util.spec_from_file_location("drv", tool / "mwccps2_debugger.py")
    drv = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(drv)
    q = drv._quote
    script = ["set pagination off", "set confirm off", "set breakpoint pending on",
              "file " + q(str(compiler)), "set args " + " ".join(q(a) for a in args), "starti",
              "source " + str(tool / "gdb/mwccps2_b210_snapshot.py").replace("\\", "/"),
              "b210-snapshot start --profile " + q(str(tool / "profiles/mwcps2-3.0.1-b210.json"))
              + " --output " + q(str(out / "capture")),
              "continue", "b210-snapshot stop", "quit", ""]
    (out / "c.gdb").write_text("\n".join(script), encoding="utf-8", newline="\n")
    run = subprocess.run([GDB, "--batch", "--nx", "--quiet", "--command", str(out / "c.gdb")],
                         cwd=ROOT, capture_output=True, text=True, timeout=600)
    if not (out / "m.o").is_file():
        sys.exit(run.stdout[-3000:])
    for path in sorted((out / "capture").glob("*.pcode.txt")):
        if any(path.name.endswith(stage + ".pcode.txt") for stage in stages):
            print("=====", path.name)
            for line in path.read_text().splitlines()[1:]:
                if line.strip():
                    print(line.split("  ; flags")[0])


if __name__ == "__main__":
    main()
