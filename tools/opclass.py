#!/usr/bin/env python3
"""Opcode-class triage across every guarded first-party floor.

`fnalign` says *where* a candidate diverges from retail; this says *what kind*
of instruction it emits that retail never does, which names the defect class
and therefore the fix:

  ================  ====================================================
  surplus           usual cause
  ================  ====================================================
  dsll32 / dsra32   a local or parameter declared at the wrong width; a
                    shift of 0x10 means an s16/s8 holding 32 bits, a
                    shift of 0 means an s64 holding 32 bits
  lbu against lb    a u8 where retail reads s8 (or the reverse)
  lhu against lh    a u16 where retail reads s16 (or the reverse)
  cvt.s.w / mtc1    an extern declared with the wrong return type, or an
                    integer local that should be f32
  div against divu  a signed modulo or divide where retail is unsigned
  jalr against jal  a call through a pointer where retail calls directly
  lui               a constant rematerialised per iteration that retail
                    hoists - measure `opt_loop_invariants on`
  sltiu / slti      a bound spelled with the wrong signedness
  beql / beqz       a likely-branch form, usually a loop-shape difference
  ================  ====================================================

A negative delta is a shortfall: retail emits the instruction and the
candidate does not.  Both directions are actionable; a shortfall of a
dsll32/dsra32 pair means a local is too *wide*.

Every floor is recompiled from its guarded body, so this measures the code
that is actually banked - not the `#else INCLUDE_ASM` arm, which would be
retail against itself.

Usage:
  python tools/opclass.py                 # every guarded first-party floor
  python tools/opclass.py src/foo.c ...   # only these owners
"""
from __future__ import annotations

import collections
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import fnalign  # noqa: E402
import verify  # noqa: E402
from verify import RetailElf, load_config, _read_json, scan_markers, window_for  # noqa: E402
from measure_guarded import extract_guarded_body  # noqa: E402
import tempfile  # noqa: E402

GUARD = re.compile(
    r"// FUN_([0-9A-Fa-f]{8}) NONMATCHING\s*\r?\n#ifdef (NON_MATCHING|SKIP_ASM)")

# opcodes whose surplus in the object names a specific, fixable cause
INTERESTING = {
    "cvt.s.w", "cvt.w.s", "mtc1", "mfc1", "dsll32", "dsra32", "dsll", "dsra",
    "lbu", "lb", "lhu", "lh", "slti", "sltiu", "slt", "sltu", "div", "divu",
    "mult", "multu", "lui", "sll", "sra", "srl", "andi", "movz", "movn",
}


def opcode(text: str) -> str:
    return text.split()[0] if text else "?"


def main() -> None:
    cfg = load_config()
    target = _read_json(verify.TARGET)
    windows = _read_json(verify.FUNCTION_WINDOWS)
    retail_elf = RetailElf(cfg["retail_elf"], target, windows["sha1"])
    boundaries = {int(item, 16) for item in windows["windows"]}
    boundaries.update(int(item, 16) + size
                      for item, size in windows["windows"].items() if size)
    for path in (Path("src")).rglob("*.c"):
        try:
            boundaries.update(m["addr"] for m in scan_markers(path))
        except OSError:
            continue
    boundaries = sorted(boundaries)
    scratch = Path(tempfile.mkdtemp(prefix="opdiff_"))

    only = {Path(a).resolve() for a in sys.argv[1:]}
    rows = []
    for path in sorted(Path("src").rglob("*.c")):
        if "generated" in path.parts or path.name.startswith("."):
            continue
        if only and path.resolve() not in only:
            continue
        text = path.read_text(errors="replace")
        for m in GUARD.finditer(text):
            addr = int(m.group(1), 16)
            if verify.code_origin(path, addr) != "main":
                continue
            name = "func_%08x" % addr
            try:
                body = extract_guarded_body(text, "FUN_" + m.group(1).upper(), name)
                cand = scratch / ("%s.c" % name)
                cand.write_text(body)
                obj, _rel = fnalign._object_for(path, name, cand, cfg)
                size = window_for(addr, boundaries)
                retail = retail_elf.bytes_at(addr, size)
                while (len(retail) >= 4 and not any(retail[-4:])
                       and len(retail) > len(obj)):
                    retail = retail[:-4]
            except SystemExit as exc:  # noqa: BLE001
                rows.append((path, name, "compile %s" % exc, {}))
                continue
            except Exception as exc:  # noqa: BLE001
                rows.append((path, name, "ERROR %s" % exc, {}))
                continue
            if obj is None:
                continue
            ocodes = collections.Counter(
                opcode(t) for t in fnalign.decode(obj, 0))
            rcodes = collections.Counter(
                opcode(t) for t in fnalign.decode(retail, addr))
            delta = {}
            for op in set(ocodes) | set(rcodes):
                d = ocodes[op] - rcodes[op]
                if d and (op in INTERESTING or abs(d) >= 3):
                    delta[op] = d
            rows.append((path, name, None, delta))

    errs = [(p, n, e) for p, n, e, _ in rows if e]
    print("errors: %d" % len(errs))
    for p, n, e in errs[:12]:
        print("   %s %s :: %s" % (n, p, str(e)[:140]))
    print("guarded first-party floors with an opcode-class surplus\n")
    ranked = []
    for path, name, err, delta in rows:
        if err:
            continue
        score = sum(abs(v) for k, v in delta.items() if k in INTERESTING)
        if score:
            ranked.append((score, path, name, delta))
    ranked.sort(reverse=True, key=lambda r: r[0])
    for score, path, name, delta in ranked:
        pretty = ", ".join(
            "%s %+d" % (k, v) for k, v in sorted(delta.items(), key=lambda kv: -abs(kv[1])))
        print("%4d  %s  %s\n        %s" % (score, name, path, pretty))
    print("\nfloors scanned: %d, with a surplus: %d" % (len(rows), len(ranked)))



if __name__ == "__main__":
    main()
