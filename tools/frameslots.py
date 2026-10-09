#!/usr/bin/env python3
"""Map a candidate's stack offsets to retail's: frameslots.py OWNER ADDR CAND

Aligns the two instruction streams (registers masked) and, for every aligned
pair whose only difference is a $sp displacement, records object offset ->
retail offset. Prints each object offset with the retail offsets it was paired
with and how often, sorted by object offset, so a frame-layout difference can be
read as "this local sits at X, retail wants Y".
"""
import collections
import difflib
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import fnalign as F  # noqa: E402
from verify import load_config  # noqa: E402

owner, addr, cand = sys.argv[1:4]
address = int(addr, 16)
cfg = load_config()
target, windows = F._read_json(F.TARGET), F._read_json(F.FUNCTION_WINDOWS)
retail_elf = F.RetailElf(cfg["retail_elf"], target, windows["sha1"])
bounds = {int(i, 16) for i in windows["windows"]}
bounds.update(int(i, 16) + s for i, s in windows["windows"].items() if s)
for path in (ROOT / "src").rglob("*.c"):
    try:
        bounds.update(m["addr"] for m in F.scan_markers(path))
    except OSError:
        pass
window = F.window_for(address, sorted(bounds))
body, _ = F._object_for(Path(owner).resolve(), "func_" + addr.lower(), Path(cand).resolve(), cfg)
rb = retail_elf.bytes_at(address, window)
R, O = F.decode(rb, address), F.decode(body, 0)

SP = re.compile(r"(-?0x[0-9a-f]+|\d+)?\(\$sp\)|\$sp, (-?0x[0-9a-f]+|\d+)")


def key(t):
    t = re.sub(r"\.[+-]\d+", ".L", t)
    t = SP.sub("SP", t)
    t = re.sub(r"\$\w+", "$r", t)
    return re.sub(r"-?0x[0-9a-f]+\(\$gp\)|\(\$gp\)", "G", t)


def spoff(t):
    m = SP.search(t)
    if not m:
        return None
    v = m.group(1) or m.group(2) or "0"
    return int(v, 0)


pairs = collections.defaultdict(collections.Counter)
sm = difflib.SequenceMatcher(None, [key(t) for t in R], [key(t) for t in O], autojunk=False)
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag != "equal":
        continue
    for k in range(i2 - i1):
        r, o = spoff(R[i1 + k]), spoff(O[j1 + k])
        if r is not None and o is not None and "addiu $sp, $sp" not in R[i1 + k]:
            pairs[o][r] += 1
frame_r = next((spoff(t) for t in R if t.startswith("addiu $sp, $sp")), None)
frame_o = next((spoff(t) for t in O if t.startswith("addiu $sp, $sp")), None)
print(f"frame retail {frame_r} object {frame_o}")
for o in sorted(pairs):
    best = pairs[o].most_common()
    flag = "" if len(best) == 1 and best[0][0] == o else "  *"
    print(f"{o:#06x} -> " + ", ".join(f"{r:#06x}x{n}" for r, n in best) + flag)
