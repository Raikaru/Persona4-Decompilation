#!/usr/bin/env python3
"""Count sign/zero-extension pairs in obj vs retail for a guarded body.

Usage: wscan_pairs.py <source> <func>
"""
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import probe_variants as probe
import verify


def extract_guarded_body(text, address, function):
    start, end = probe.region_for(text, address, function)
    region = text[start:end]
    out = []
    for line in region.splitlines(keepends=True):
        s = line.strip()
        if re.match(r"#\s*(ifdef|ifndef|if|else|elif|endif)\b", s):
            continue
        if re.match(r"INCLUDE_ASM\s*\(", s):
            continue
        out.append(line)
    return "".join(out), start, end


def compile_candidate(source, func, body_text):
    src = Path(source)
    text = probe._read_text(src)
    m = re.search(r"([0-9a-fA-F]{8})", func)
    address = "FUN_" + m.group(1).upper()
    body, start, end = extract_guarded_body(text, address, func)
    # caller may supply replacement body
    if body_text is not None:
        body = body_text
    newline = probe._newline_for(src.read_bytes())
    body_n = probe._normalise_candidate(body, newline)
    patched = probe.splice_region(text, start, end, body_n, newline)
    tmp_c = src.parent / f".wscan_{src.stem}.c"
    tmp_o = Path(f"/tmp/wscan/{func}.o")
    tmp_o.parent.mkdir(parents=True, exist_ok=True)
    tmp_c.write_bytes(patched.encode("utf-8", errors="surrogateescape"))
    try:
        cfg = verify.load_config()
        ok, log = probe._compile_in_context(tmp_c.resolve(), src.resolve(), cfg, tmp_o)
        if not ok:
            print(f"COMPILE FAILED:\n{log[-3000:]}")
            return None
        return tmp_o
    finally:
        tmp_c.unlink(missing_ok=True)


def obj_disasm(obj_path, func):
    out = subprocess.run(
        ["mipsel-linux-gnu-objdump", "-d", "--disassemble=" + func, str(obj_path)],
        capture_output=True, text=True)
    if out.returncode != 0:
        # fall back to full dump grepped
        out = subprocess.run(
            ["mipsel-linux-gnu-objdump", "-d", str(obj_path)],
            capture_output=True, text=True)
        lines = out.stdout.splitlines()
        keep, on = [], False
        for line in lines:
            if f"<{func}>:" in line:
                on = True
            elif on and re.match(r"^[0-9a-f]+ <\S+>:", line):
                break
            if on:
                keep.append(line)
        return "\n".join(keep)
    return out.stdout


def count_ext_sequences(disasm):
    """Find extension sequences. Returns dict kind -> list of (line_no, text)."""
    lines = [l for l in disasm.splitlines() if re.search(r"^\s*[0-9a-f]+:\s+[0-9a-f ]{8,}\s+\S", l)
             or re.match(r"\s*/\*.*\*/\s+\S", l)]
    # normalize: extract mnemonic + operands
    insns = []
    for line in disasm.splitlines():
        m = re.search(r"(dsll32|dsra32|dsll|dsra|sll|sra|move|daddu|addu|or)\s+(\$?\w+)?,?\s*(\$?\w+)?,?\s*(\S+)?", line)
        if m and ("0x" in line or "$" in line):
            insns.append((m.group(1), line.strip()))
    pairs = {"dsll32/dsra32": 0, "dsll/dsra": 0, "sll/sra": 0,
             "move": 0, "daddu": 0}
    pair_lines = []
    # adjacent-pair scan on raw lines
    norm = []
    for line in disasm.splitlines():
        m = re.search(r"\b(dsll32|dsra32|dsll|dsra|sll|sra|daddu|or)\b\s+([^\n;]*)", line)
        if m:
            norm.append((m.group(1), m.group(2).strip(), line.strip()))
    for i in range(len(norm) - 1):
        a, b = norm[i], norm[i + 1]
        if a[0] == "dsll32" and b[0] == "dsra32":
            pairs["dsll32/dsra32"] += 1
            pair_lines.append((a[2], b[2]))
        elif a[0] == "dsll" and b[0] == "dsra":
            pairs["dsll/dsra"] += 1
            pair_lines.append((a[2], b[2]))
        elif a[0] == "sll" and b[0] == "sra":
            pairs["sll/sra"] += 1
            pair_lines.append((a[2], b[2]))
    for op, ops, _ in norm:
        if op == "daddu":
            pairs["daddu"] += 1
    return pairs, pair_lines, norm


def main():
    source, func = sys.argv[1], sys.argv[2]
    body_override = None
    if "--candidate" in sys.argv:
        body_override = Path(sys.argv[sys.argv.index("--candidate") + 1]).read_text()
    obj = compile_candidate(source, func, body_override)
    if obj is None:
        return 1
    dis = obj_disasm(obj, func)
    pairs, pair_lines, norm = count_ext_sequences(dis)
    print(f"OBJ {func}: {pairs}")
    for a, b in pair_lines:
        print(f"   obj-pair: {a}  ||  {b}")
    # retail side
    m = re.search(r"([0-9a-fA-F]{8})", func)
    addr = m.group(1).lower()
    src = Path(source)
    # owner dir guess: asm/nonmatchings/<stem>/
    stem = src.stem
    retail_s = REPO / "asm" / "nonmatchings" / stem / f"func_{addr}.s"
    if retail_s.is_file():
        rp, rpl, _ = count_ext_sequences(retail_s.read_text())
        print(f"RETAIL {func}: {rp}")
        for a, b in rpl:
            print(f"   ret-pair: {a}  ||  {b}")
    else:
        print(f"no retail asm at {retail_s}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
