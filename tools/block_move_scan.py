#!/usr/bin/env python3
"""Tell a relocated block apart from a wholesale recolouring.

`fnalign`'s edit script shows both as the same shape: a long run of retail
instructions against one object instruction, and the reverse somewhere else.
The two want opposite fixes - a move wants the blocks reordered, a recolouring
wants the liveness changed - and guessing wrong costs a full pass (handoff
7ay, where an asymmetric pair of 56 and 68 instructions turned out to be
difflib failing to anchor across a recoloured region).

The discriminator is the **opcode sequence**.  A real move carries the same
opcodes in the same order to a different offset; a recolouring rewrites the
register fields and leaves the opcodes where they are; and two regions that
genuinely compute different things agree on neither.

    python3 tools/block_move_scan.py src/foo.c func_00123456
    python3 tools/block_move_scan.py --floors /var/tmp/fp_now.json --limit 30
"""
from __future__ import annotations

import argparse
import difflib
import json
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import fnalign  # noqa: E402
import verify  # noqa: E402
from measure_guarded import extract_guarded_body  # noqa: E402

# Below this many instructions an asymmetric pair is noise, not a block.
MIN_RUN = 12
# difflib ratios that separate the three verdicts.  A move keeps nearly every
# opcode; a recolouring keeps them all but fnalign lost the alignment; genuine
# divergence sits well below both.
MOVE_RATIO = 0.95
RECOLOUR_RATIO = 0.80
# A move has to travel: two runs at the same index are local divergence.
MIN_DISPLACEMENT = 24


def opcodes(instructions):
    return [str(i).split()[0] for i in instructions]


def asymmetric_pairs(script):
    """Runs where one side is at least MIN_RUN and the other is at most 2."""
    out = []
    for kind, r0, r1, o0, o1 in script:
        retail_len, object_len = r1 - r0, o1 - o0
        if retail_len >= MIN_RUN and object_len <= 2:
            out.append(("retail", retail_len, r0, r1, o0, o1))
        elif object_len >= MIN_RUN and retail_len <= 2:
            out.append(("object", object_len, r0, r1, o0, o1))
    out.sort(key=lambda row: -row[1])
    return out


def verdict(ratio, displacement=None, length=None):
    """Classify a candidate pair.

    `displacement` is how far apart the two ranges sit.  Without it a region
    that merely diverges in place scores like a move, because difflib splits
    it into a retail-only and an object-only run at almost the same index.
    A move has to actually go somewhere.
    """
    if displacement is not None and length:
        if displacement < max(MIN_DISPLACEMENT, length // 4):
            return ("IN-PLACE   the two runs sit at the same offset; this is "
                    "local divergence, not a move")
    if ratio >= MOVE_RATIO:
        return "MOVE       reorder the blocks; the opcode sequence is intact"
    if ratio >= RECOLOUR_RATIO:
        return "RECOLOUR   same code, different registers; change the liveness"
    return "MIXED      neither a clean move nor a clean recolour; read both ranges"


def scan(source: Path, function: str, cfg, elf, windows):
    address = int(function[5:], 16)
    span = windows["windows"].get(function[5:].lower())
    if not span:
        raise SystemExit(f"no recorded window for {function}")
    retail = fnalign.decode(elf.bytes_at(address, span), address)

    body = extract_guarded_body(source.read_text(errors="replace"),
                                f"FUN_{address:08X}", function)
    if body is None:
        raise SystemExit(f"{function} has no guarded body to compare")
    with tempfile.TemporaryDirectory() as tmp:
        candidate = Path(tmp) / "candidate.c"
        candidate.write_text(body)
        obj, _ = fnalign._object_for(source.resolve(), function, candidate, cfg)
    objects = fnalign.decode(obj, 0)

    matcher = difflib.SequenceMatcher(None, retail, objects, autojunk=False)
    script = [(tag, r0, r1, o0, o1)
              for tag, r0, r1, o0, o1 in matcher.get_opcodes()
              if tag != "equal"]
    pairs = asymmetric_pairs(script)
    if not pairs:
        return None

    side, length, r0, r1, o0, o1 = pairs[0]
    # The counterpart is the largest run on the other side.
    counterparts = [p for p in pairs if p[0] != side]
    if not counterparts:
        return {"function": function, "source": str(source), "side": side,
                "length": length, "ratio": None,
                "verdict": "UNPAIRED   one-sided run: code is missing or surplus, not moved",
                "retail_range": (r0, r1), "object_range": (o0, o1)}
    _, other_len, cr0, cr1, co0, co1 = counterparts[0]

    if side == "retail":
        left, right = opcodes(retail[r0:r1]), opcodes(objects[co0:co1])
        ranges = ((r0, r1), (co0, co1))
    else:
        left, right = opcodes(retail[cr0:cr1]), opcodes(objects[o0:o1])
        ranges = ((cr0, cr1), (o0, o1))

    ratio = difflib.SequenceMatcher(None, left, right, autojunk=False).ratio()
    return {"function": function, "source": str(source),
            "retail_range": ranges[0], "object_range": ranges[1],
            "retail_len": len(left), "object_len": len(right),
            "retail_address": f"0x{address + ranges[0][0] * 4:08x}",
            "ratio": round(ratio, 3),
            "displacement": abs(ranges[0][0] - ranges[1][0]),
            "verdict": verdict(ratio, abs(ranges[0][0] - ranges[1][0]),
                               max(len(left), len(right)))}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("source", nargs="?", type=Path)
    ap.add_argument("function", nargs="?")
    ap.add_argument("--floors", type=Path,
                    help="floor_distance --json output to sweep instead")
    ap.add_argument("--limit", type=int, default=25)
    ap.add_argument("--json", type=Path)
    args = ap.parse_args()

    cfg = verify.load_config()
    windows = fnalign._read_json(fnalign.FUNCTION_WINDOWS)
    elf = fnalign.RetailElf(cfg["retail_elf"], fnalign._read_json(fnalign.TARGET),
                            windows["sha1"])

    if args.source and args.function:
        targets = [(args.source, args.function)]
    elif args.floors:
        rows = [r for r in json.loads(args.floors.read_text())
                if "error" not in r and r.get("origin") == "main"]
        rows.sort(key=lambda r: -r["edits"])
        targets = [(Path(r["source"]), r["function"]) for r in rows[: args.limit]]
    else:
        ap.error("pass a source and function, or --floors")

    results = []
    for source, function in targets:
        try:
            found = scan(source, function, cfg, elf, windows)
        except Exception as exc:
            print(f"  {function}: {type(exc).__name__}: {exc}", file=sys.stderr)
            continue
        if not found:
            continue
        results.append(found)
        if found["ratio"] is None:
            print(f"{found['function']}  {found['verdict']}")
            continue
        print(f"{found['function']}  ratio {found['ratio']:.3f}  {found['verdict']}")
        print(f"    retail[{found['retail_range'][0]}:{found['retail_range'][1]}]"
              f" ({found['retail_len']}) at {found['retail_address']}"
              f"  against object[{found['object_range'][0]}:{found['object_range'][1]}]"
              f" ({found['object_len']})")
        print(f"    {found['source']}")

    if args.json:
        args.json.write_text(json.dumps(results, indent=2))
        print(f"wrote {args.json}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
