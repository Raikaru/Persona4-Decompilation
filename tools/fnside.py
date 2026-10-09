"""Side-by-side retail/object listing: tools/fnside.py OWNER ADDR CAND START END"""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import fnalign as F
from verify import load_config

owner, addr, cand, lo, hi = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4]), int(sys.argv[5])
address = int(addr, 16)
cfg = load_config()
target, windows = F._read_json(F.TARGET), F._read_json(F.FUNCTION_WINDOWS)
retail_elf = F.RetailElf(cfg["retail_elf"], target, windows["sha1"])
boundaries = {int(i, 16) for i in windows["windows"]}
boundaries.update(int(i, 16) + s for i, s in windows["windows"].items() if s)
for path in (ROOT / "src").rglob("*.c"):
    try:
        boundaries.update(m["addr"] for m in F.scan_markers(path))
    except OSError:
        pass
window = F.window_for(address, sorted(boundaries))
body, _ = F._object_for(Path(owner).resolve(), "func_" + addr.lower(), Path(cand).resolve(), cfg)
R, O = F.decode(retail_elf.bytes_at(address, window), address), F.decode(body, 0)
out = []
for i in range(lo, hi + 1):
    r = R[i] if i < len(R) else ""
    o = O[i] if i < len(O) else ""
    out.append(f"{i:5d} {'  ' if r == o else '* '}{r:38.38s} | {o}")
sys.stdout.buffer.write(("\n".join(out) + "\n").encode())
