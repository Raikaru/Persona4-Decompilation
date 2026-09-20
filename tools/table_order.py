#!/usr/bin/env python3
"""Reorder a switch's arms into retail's jump-table LAYOUT order and measure.

Ascending case order is what a lowered if-chain wants.  A jump table already
encodes its own order, and the source has to agree with it: on
`func_0023a6b0`, matching `jtbl_00747C40`'s layout - 9, 8, 10, 13, 11, 15,
14, 12 - was worth 824 edits on its own and was count-neutral.

The layout order is read out of the retail ELF rather than guessed: the
`sltiu` bound gives the entry count, each 4-byte entry gives an arm address,
and sorting the case values by arm address is the order retail emitted them
in.  Entries sharing the most common address are the default.

Swept over every first-party floor carrying a table: 20 were already in
layout order, 5 improved (274, 88, 50, 37 and 7 edits) and 13 got worse.  It
is a per-function measurement, never an automatic rewrite - reordering a
switch whose source order is already right costs hundreds of edits
(func_00380ea0 125 -> 676, func_002b1520 163 -> 622, func_0012aa70 187 -> 539).

    python3 -E -s tools/table_order.py < floors.txt   # "<file> <func>" rows
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import verify  # noqa: E402
from measure_guarded import extract_guarded_body  # noqa: E402

CFG = verify.load_config()
TARGET = verify._read_json(verify.TARGET)
WINDOWS = verify._read_json(verify.FUNCTION_WINDOWS)
ELF = verify.RetailElf(CFG["retail_elf"], TARGET, WINDOWS["sha1"])

JTBL = re.compile(r"%hi\(jtbl_([0-9A-Fa-f]{8})\)")
SLTIU = re.compile(r"sltiu\s+\$\d+,\s*\$\d+,\s*(0x[0-9A-Fa-f]+|\d+)")
CASE = re.compile(r"^(\s*)case\s+(-?\d+|0x[0-9A-Fa-f]+)\s*:\s*$")
SWITCH = re.compile(r"^(\s*)switch\s*\(")


def table_layout(asm_path):
    """Return [(case value, arm address)] for the function's jump table."""
    text = Path(asm_path).read_text(errors="replace")
    m = JTBL.search(text)
    if not m:
        return None
    base = int(m.group(1), 16)
    bound = None
    for line in text.split("\n")[:text[:m.start()].count("\n") + 1][::-1]:
        s = SLTIU.search(line)
        if s:
            bound = int(s.group(1), 0)
            break
    if not bound or bound > 64:
        return None
    raw = ELF.bytes_at(base, bound * 4)
    if raw is None or len(raw) < bound * 4:
        return None
    return [(i, int.from_bytes(raw[i * 4:i * 4 + 4], "little")) for i in range(bound)]


def arms_of(lines):
    """Locate the largest switch and split it into (values, body) arms."""
    best = None
    for i, line in enumerate(lines):
        if not SWITCH.match(line):
            continue
        depth, end = 0, None
        for j in range(i, len(lines)):
            depth += lines[j].count("{") - lines[j].count("}")
            if depth == 0 and j > i:
                end = j
                break
        if end and (best is None or end - i > best[1] - best[0]):
            best = (i, end, SWITCH.match(line).group(1))
    if best is None:
        return None
    start, end, indent = best
    label = re.compile(rf"^{re.escape(indent)}(?:case\s+(-?\d+|0x[0-9A-Fa-f]+)|default)\s*:\s*$")
    groups, cur, depth = [], None, 0
    for k in range(start + 1, end):
        line = lines[k]
        if depth == 0 and label.match(line):
            m = CASE.match(line)
            if cur is None or cur["closed"]:
                cur = {"values": [], "body": [], "closed": False, "default": m is None}
                groups.append(cur)
            if m is None:
                cur["default"] = True
            else:
                cur["values"].append(int(m.group(2), 0))
            continue
        if cur is None:
            return None
        cur["body"].append(line)
        if depth == 0 and re.match(r"^\s*(break;|return\b|goto\b)", line):
            cur["closed"] = True
        depth += line.count("{") - line.count("}")
    if len(groups) < 3 or any(not g["closed"] for g in groups):
        return None
    return start, end, indent, groups


def render(indent, groups, order):
    out = []
    for g in order:
        if g["default"]:
            out.append(f"{indent}default:")
        for v in g["values"]:
            out.append(f"{indent}case {v}:")
        out.extend(g["body"])
    return out


def edits(rel, fn, path):
    out = subprocess.run([sys.executable, "-E", "-s", "tools/fnalign.py", rel, fn,
                          "--candidate", str(path), "--quiet"],
                         cwd=REPO, capture_output=True, text=True, timeout=1800).stdout
    e = re.search(r"edit instructions: (\d+)", out)
    n = re.search(r"object (\d+) instrs", out)
    r = re.search(r"retail (\d+) instrs", out)
    return (int(e.group(1)) if e else None, int(n.group(1)) if n else None,
            int(r.group(1)) if r else None)


def main():
    scratch = Path(tempfile.gettempdir()) / "p4_table_order"
    scratch.mkdir(parents=True, exist_ok=True)
    for raw in sys.stdin:
        raw = raw.strip()
        if not raw:
            continue
        rel, fn = raw.split()[-2:]
        stem = Path(rel).stem
        asm = REPO / f"asm/nonmatchings/{stem}/{fn}.s"
        if not asm.is_file():
            continue
        layout = table_layout(asm)
        if not layout:
            continue
        body = extract_guarded_body((REPO / rel).read_text(errors="replace"),
                                    f"FUN_{fn[5:].upper()}", fn)
        if not body:
            continue
        got = arms_of(body.split("\n"))
        if not got:
            continue
        start, end, indent, groups = got
        common = max({a for _, a in layout}, key=[a for _, a in layout].count)
        rank = {}
        for value, addr in layout:
            if addr != common:
                rank.setdefault(value, addr)
        keyed = [g for g in groups if not g["default"]]
        tail = [g for g in groups if g["default"]]
        if not keyed or any(not g["values"] for g in keyed):
            continue
        ordered = sorted(keyed, key=lambda g: rank.get(min(g["values"]), 1 << 62))
        if [g["values"] for g in ordered] == [g["values"] for g in keyed]:
            print(f"{fn}: already in table layout order", flush=True)
            continue
        lines = body.split("\n")
        new = lines[:start + 1] + render(indent, groups, ordered + tail) + lines[end:]
        a, b = scratch / f"{fn}_a.c", scratch / f"{fn}_b.c"
        a.write_text(body)
        b.write_text("\n".join(new))
        e0, n0, r0 = edits(rel, fn, a)
        e1, n1, _ = edits(rel, fn, b)
        if e0 is None or e1 is None:
            print(f"{fn}: compile failed", flush=True)
            continue
        inside = r0 and abs(n1 - r0) <= r0 * 0.03
        mark = (f"   <<< better by {e0 - e1}" if e1 < e0 and inside
                else "   (better but OUTSIDE the gate)" if e1 < e0 else "")
        print(f"{fn}  edits {e0} -> {e1}  count {n0} -> {n1} (retail {r0}){mark}", flush=True)


if __name__ == "__main__":
    main()
