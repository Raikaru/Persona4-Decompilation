#!/usr/bin/env python3
"""Compare the callee-saved register set a guarded body allocates against retail's.

A body that saves fewer registers than retail is holding values in memory that
retail holds in registers: every displacement after ``$ra`` shifts and the
fnalign edit count explodes while the instruction count can stay exact.  A body
that saves more is keeping values live that retail recomputes.

Neither shows up in the word score and neither is reachable by padding the
frame, which is why they survive so many passes.  See handoff 7as and 7at.

    python3 tools/regsave_scan.py                     # every measured floor
    python3 tools/regsave_scan.py --json out.json
    python3 tools/regsave_scan.py src/foo.c func_0012 # one function
"""
from __future__ import annotations

import argparse
import json
import struct
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import fnalign  # noqa: E402
import verify  # noqa: E402
from measure_guarded import extract_guarded_body  # noqa: E402

# A prologue is a contiguous run of stores through $sp.  Scanning a fixed
# window is enough: MWCCPS2 emits every callee save before the first branch.
PROLOGUE_WINDOW = 40

SQ, SD, SWC1, SDC1 = 0x1F, 0x3F, 0x39, 0x3D
GPR = {
    16: "$s0", 17: "$s1", 18: "$s2", 19: "$s3", 20: "$s4", 21: "$s5",
    22: "$s6", 23: "$s7", 30: "$fp", 31: "$ra",
}


def _prologue(words):
    """Return (frame_size, {gpr saves}, {fpr saves}, ra_offset)."""
    frame = None
    gpr, fpr, ra = set(), set(), None
    for word in words:
        op = word >> 26
        rs = (word >> 21) & 31
        rt = (word >> 16) & 31
        imm = word & 0xFFFF
        if op == 0x09 and rs == 29 and rt == 29:  # addiu $sp, $sp, -N
            if frame is None and imm > 0x8000:
                frame = 0x10000 - imm
            continue
        if rs != 29:
            continue
        if op == SQ:
            gpr.add(rt)
        elif op == SD and rt == 31:
            ra = imm
        elif op in (SWC1, SDC1):
            fpr.add(rt)
    return frame, gpr, fpr, ra


def _names(regs):
    return " ".join(GPR.get(r, f"$r{r}") for r in sorted(regs))


def scan(source: Path, function: str, addr: int, elf, cfg):
    retail_words = list(struct.unpack(f"<{PROLOGUE_WINDOW}I",
                                      elf.bytes_at(addr, PROLOGUE_WINDOW * 4)))
    text = source.read_text(errors="replace")
    body = extract_guarded_body(text, f"FUN_{addr:08X}", function)
    if body is None:
        return None
    with tempfile.TemporaryDirectory() as tmp:
        candidate = Path(tmp) / "candidate.c"
        candidate.write_text(body)
        obj, _ = fnalign._object_for(source.resolve(), function, candidate, cfg)
    count = min(PROLOGUE_WINDOW, len(obj) // 4)
    object_words = list(struct.unpack(f"<{count}I", obj[: count * 4]))

    rframe, rgpr, rfpr, rra = _prologue(retail_words)
    oframe, ogpr, ofpr, ora = _prologue(object_words)
    return {
        "function": function,
        "source": str(source),
        "retail_frame": rframe,
        "object_frame": oframe,
        "retail_ra": rra,
        "object_ra": ora,
        "missing_gpr": sorted(rgpr - ogpr),
        "extra_gpr": sorted(ogpr - rgpr),
        "missing_fpr": sorted(rfpr - ofpr),
        "extra_fpr": sorted(ofpr - rfpr),
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", nargs="?", type=Path)
    ap.add_argument("function", nargs="?")
    ap.add_argument("--floors", type=Path, default=Path("/var/tmp/fp_now.json"),
                    help="floor_distance --json output to sweep")
    ap.add_argument("--json", type=Path)
    ap.add_argument("--limit", type=int, default=40)
    args = ap.parse_args()

    cfg = verify.load_config()
    windows = fnalign._read_json(fnalign.FUNCTION_WINDOWS)
    elf = fnalign.RetailElf(cfg["retail_elf"], fnalign._read_json(fnalign.TARGET),
                            windows["sha1"])

    if args.source and args.function:
        targets = [(args.source, args.function, int(args.function[5:], 16), None)]
    else:
        if not args.floors.exists():
            print(f"no floor list at {args.floors}; pass source and function",
                  file=sys.stderr)
            return 2
        rows = [r for r in json.loads(args.floors.read_text())
                if "error" not in r and r.get("origin") == "main"]
        rows.sort(key=lambda r: -(r["edits"] / max(r["retail"], 1)))
        targets = [(Path(r["source"]), r["function"], int(r["function"][5:], 16), r)
                   for r in rows[: args.limit]]

    results = []
    for source, function, addr, row in targets:
        try:
            found = scan(source, function, addr, elf, cfg)
        except Exception as exc:  # a body that will not compile alone is not our problem
            print(f"  {function}: {type(exc).__name__}: {exc}", file=sys.stderr)
            continue
        if found is None:
            continue
        if row:
            found["edits"] = row["edits"]
            found["object"] = row["object"]
            found["retail"] = row["retail"]
        results.append(found)

    mismatched = [r for r in results
                  if r["missing_gpr"] or r["extra_gpr"]
                  or r["missing_fpr"] or r["extra_fpr"]]
    for r in sorted(mismatched, key=lambda r: -r.get("edits", 0)):
        head = f"{r['function']}"
        if "edits" in r:
            head += f"  {r['object']}/{r['retail']}  {r['edits']} edits"
        print(head)
        print(f"    frame  retail 0x{r['retail_frame']:x}  object 0x{r['object_frame']:x}"
              if r["retail_frame"] and r["object_frame"] else "    frame  ?")
        if r["missing_gpr"]:
            print(f"    retail also saves  {_names(r['missing_gpr'])}"
                  "   (body holds these in memory: hoist into scalars live across the body)")
        if r["extra_gpr"]:
            print(f"    body saves spare   {_names(r['extra_gpr'])}"
                  "   (retail recomputes these: sink or recompute at the use)")
        if r["missing_fpr"]:
            print(f"    retail also saves  {' '.join('$f%d' % f for f in r['missing_fpr'])}")
        if r["extra_fpr"]:
            print(f"    body saves spare   {' '.join('$f%d' % f for f in r['extra_fpr'])}")
        print(f"    {r['source']}")

    print(f"\n{len(mismatched)} of {len(results)} scanned bodies allocate a different "
          "callee-saved set than retail")
    if args.json:
        args.json.write_text(json.dumps(results, indent=2))
        print(f"wrote {args.json}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
