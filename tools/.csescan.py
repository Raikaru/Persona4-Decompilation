#!/usr/bin/env python3
"""Find floors whose residual is the 'retail rematerialises, b210 CSEs' shape.

For each guarded floor: extract the body, align it against retail and report
rows where retail has a narrowing `andi`/`sll`/`sra` and the object has a
`move` (or vice versa), plus rows where only the FP destination register of a
`cvt.w.s` differs.  Those two signatures are the ones the 2026-09-18
func_00311930 match turned into levers.
"""
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, "tools")
from fnalign import decode, _object_for, RetailElf, load_config, _read_json, TARGET, FUNCTION_WINDOWS, align, window_for, scan_markers


CFG = load_config()
TGT = _read_json(TARGET)
WIN = _read_json(FUNCTION_WINDOWS)
ELF = RetailElf(CFG["retail_elf"], TGT, WIN["sha1"])

BOUNDS = {int(i, 16) for i in WIN["windows"]}
BOUNDS.update(int(i, 16) + s for i, s in WIN["windows"].items() if s)
for path in Path("src").rglob("*.c"):
    try:
        BOUNDS.update(m["addr"] for m in scan_markers(path))
    except OSError:
        pass
SORTED = sorted(BOUNDS)


def classify(src: Path, fn: str, addr: int, cand: Path):
    body, _rel = _object_for(src.resolve(), fn, cand.resolve(), CFG)
    win = window_for(addr, SORTED)
    rb = ELF.bytes_at(addr, win)
    while len(rb) >= 4 and not any(rb[-4:]) and len(rb) > len(body):
        rb = rb[:-4]
    rt, ot = decode(rb, addr), decode(body, 0)
    script, _edits, _reloc = align(rt, ot, set())
    cvt = remat = 0
    for tag, i1, i2, j1, j2 in script:
        if tag not in ("replace", "delete", "insert"):
            continue
        r = " ".join(rt[i1:i2])
        o = " ".join(ot[j1:j2])
        if "cvt." in r and "cvt." in o:
            cvt += 1
        if ("andi" in r and "move" in o) or ("move" in r and "andi" in o):
            remat += 1
    return cvt, remat, len(rt), len(ot)


def main() -> None:
    targets = [line.split() for line in Path(sys.argv[1]).read_text().split("\n") if line.strip()]
    for parts in targets:
        src, fn = Path(parts[0]), parts[1]
        addr = int(fn[5:], 16)
        cand = Path(f"/var/tmp/csescan/{fn}.c")
        cand.parent.mkdir(parents=True, exist_ok=True)
        r = subprocess.run([sys.executable, "-E", "-s", "tools/measure_guarded.py", str(src), fn,
                            "--save-candidate", str(cand)], capture_output=True, text=True)
        if not cand.is_file():
            print(f"{fn}  no body")
            continue
        try:
            cvt, remat, nr, no = classify(src, fn, addr, cand)
        except Exception as exc:  # noqa: BLE001
            print(f"{fn}  ERR {exc}")
            continue
        flag = []
        if cvt:
            flag.append(f"cvt:{cvt}")
        if remat:
            flag.append(f"remat:{remat}")
        print(f"{fn}  retail={nr} obj={no}  {' '.join(flag) or '-'}")


if __name__ == "__main__":
    main()
