"""Structural diff of a candidate against retail: tools/sdiff.py OWNER ADDR CAND [LIMIT] [--regs]

Branch offsets are masked; without --regs registers are masked too."""
import difflib, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import fnalign as F
from verify import load_config

args = [a for a in sys.argv[1:] if not a.startswith("--")]
regs = "--regs" in sys.argv
owner, addr, cand = args[:3]
limit = int(args[3]) if len(args) > 3 else 60
function = "func_" + addr.lower()
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
body, _ = F._object_for(Path(owner).resolve(), function, Path(cand).resolve(), cfg)
rb = retail_elf.bytes_at(address, window)
while len(rb) >= 4 and not any(rb[-4:]) and len(rb) > len(body):
    rb = rb[:-4]
R, O = F.decode(rb, address), F.decode(body, 0)


def norm_all(text):
    out, luireg = [], {}
    for k, t in enumerate(text):
        t = re.sub(r"\.[+-]\d+", ".L", t)
        t = re.sub(r"-?0x[0-9a-f]+\(\$gp\)|\(\$gp\)", "G($gp)", t)
        m = re.match(r"lui (\$\w+), ", t)
        if m:
            luireg[m.group(1)] = k
            t = f"lui {m.group(1)}, HI"
        else:
            m = re.match(r"(\w+) (\$\w+), (\$\w+), -?(0x[0-9a-f]+|\d+)$", t)
            if m and m.group(1) == "addiu" and k - luireg.get(m.group(3), -99) <= 4:
                t = f"addiu {m.group(2)}, {m.group(3)}, LO"
            m = re.match(r"(\w+) (\$\w+), (-?0x[0-9a-f]+)?\((\$\w+)\)$", t)
            if m and k - luireg.get(m.group(4), -99) <= 4:
                t = f"{m.group(1)} {m.group(2)}, LO({m.group(4)})"
        if not regs:
            t = re.sub(r"\$\w+", "$r", t)
        out.append(t)
    return out


rn, on = norm_all(R), norm_all(O)
sm = difflib.SequenceMatcher(None, rn, on, autojunk=False)
ops = [o for o in sm.get_opcodes() if o[0] != "equal"]
cost = sum(max(i2 - i1, j2 - j1) for _, i1, i2, j1, j2 in ops)
out = [f"retail {len(R)} object {len(O)} struct {cost}"]
for tag, i1, i2, j1, j2 in ops[:limit]:
    out.append(f"{tag:7s} R[{i1}:{i2}] O[{j1}:{j2}] | " + "; ".join(R[i1:min(i2, i1 + 6)])
               + " || " + "; ".join(O[j1:min(j2, j1 + 6)]))
sys.stdout.buffer.write(("\n".join(out) + "\n").encode())
