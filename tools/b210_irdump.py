#!/usr/bin/env python3
"""Dump b210's frontend IR after every IRO_* pass for one owner + candidate.

  b210_irdump.py OWNER ADDR CANDIDATE OUT.log

CANDIDATE replaces the FUN_<ADDR> region of OWNER in a scratch copy, which is
compiled with the owner's flags under GDB. The IR-dump gates documented in
docs/matching.md ("Frontend IR dumps") are set: 0x00637374 after its clear at
0x004d1272, and 0x006365e8 at each function entry (0x004d13a0). The compiler
writes the whole TU's dump next to the scratch source; it is moved to OUT.
Search OUT for "Dumping function func_<addr> after" to step through passes.
Set GDB to a gdb that can run the Windows compiler.
"""
from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import verify as V  # noqa: E402
import probe_variants as PV  # noqa: E402

GDB = os.environ.get("GDB", "gdb")

if len(sys.argv) != 5:
    sys.exit(__doc__)

owner, addr, candidate, out_log = sys.argv[1:5]
source = (ROOT / owner).resolve()
text = PV._read_text(source)
start, end = PV.region_for(text, "FUN_" + addr.upper())
newline = PV._newline_for(source.read_bytes())
body = PV._normalise_candidate(Path(candidate).read_text(), newline)
spliced = PV.splice_region(text, start, end, body, newline)
scratch = source.with_name(".ird_" + source.name)
scratch.write_text(spliced, encoding="utf-8", errors="surrogateescape", newline="")
work = ROOT / "build/irdump"
work.mkdir(parents=True, exist_ok=True)
try:
    cfg = V.load_config()
    compiler = Path(V.unit_compiler(source, cfg)).resolve()
    flags = V.unit_compile_flags(source, cfg["compile_flags"])
    args = [*flags, "-c", str(scratch), "-o", str(work / "ird.o")]
    q = lambda s: '"' + s.replace("\\", "/") + '"'
    script = [
        "set pagination off", "set confirm off",
        "file " + q(str(compiler)), "set args " + " ".join(q(a) for a in args),
        "break *0x004d1279", "commands", "silent", "set *(unsigned char *)0x00637374 = 1",
        "continue", "end",
        "break *0x004d13a0", "commands", "silent", "set *(unsigned char *)0x006365e8 = 1",
        "continue", "end",
        "run", "quit", "",
    ]
    (work / "ird.gdb").write_text("\n".join(script), encoding="utf-8", newline="\n")
    r = subprocess.run([GDB, "--batch", "--nx", "--quiet", "--command", str(work / "ird.gdb")],
                       cwd=ROOT, capture_output=True, text=True, timeout=900)
    log = scratch.with_suffix(".log")
    if not log.is_file():
        sys.exit("no IR log produced\n" + r.stdout[-2000:] + r.stderr[-2000:])
    Path(out_log).write_bytes(log.read_bytes())
    log.unlink()
    print("IR dump ->", out_log)
finally:
    scratch.unlink(missing_ok=True)
