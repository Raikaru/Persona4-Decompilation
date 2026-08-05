#!/usr/bin/env python3
"""Attribute unscanned retail windows to first-party or middleware.

`verify.py` only sees windows that carry a `// FUN_` marker; the rest are handed to
the link as raw retail bytes and are invisible to every status count. Treating all
of them as first-party overstates the remaining work, because a large run of them
is CRI ADX and Sony ROFS code.

**Whole-file address spans cannot decide this.** `cri_adx_grouped.c` spans
`0x0044db98`-`0x0052d980` but is non-contiguous: 943 game functions from
`mdlManager.c`, `effBlurFilter.c`, `sdkSnd.c`, `sdkTask.c` and others sit inside
that range. A span test therefore reclassifies real game code as middleware, which
is exactly the wrong direction for an honesty fix.

What this uses instead is the nearest SCANNED neighbour on each side. A window
flanked by third-party functions on both sides is almost certainly part of the same
library; one flanked by first-party on both sides is game code; anything else is
reported as `mixed` and left for real attribution rather than guessed.

This only ever REPORTS. It does not edit sources, and it does not change the
published progress numbers - `verify.is_third_party` stays the single authority for
what is third-party.

Usage:
  python tools/attribute_windows.py --report build/verify.json
  python tools/attribute_windows.py --report build/verify.json --json build/attr.json
"""
from pathlib import Path
import argparse
import bisect
import json
import sys

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))
import verify  # noqa: E402


def load(report):
    data = json.loads(Path(report).read_text())
    scanned = []
    for row in data["results"]:
        name = row.get("name", "")
        if not name.startswith("func_"):
            continue                       # a named function still has an address below
        try:
            scanned.append((int(name[len("func_"):], 16), row["file"], row["status"]))
        except ValueError:
            continue
    # named (non func_) rows carry no address in the name; recover them by marker order
    for row in data["results"]:
        name = row.get("name", "")
        if name.startswith("func_"):
            continue
        addr = row.get("address") or row.get("addr")
        if isinstance(addr, str):
            try:
                scanned.append((int(addr, 16), row["file"], row["status"]))
            except ValueError:
                pass
        elif isinstance(addr, int):
            scanned.append((addr, row["file"], row["status"]))
    scanned.sort()
    return data, scanned


def bucket(unscanned, addrs, third):
    """Split `unscanned` by the third-party flag of its nearest scanned neighbours.

    `addrs` must be sorted and `third[i]` is the flag for `addrs[i]`. A window is
    only called middleware when BOTH neighbours are third-party; anything else goes
    to `mixed` rather than being guessed.
    """
    out = {"third_party_flanked": [], "first_party_flanked": [], "mixed": []}
    for a in unscanned:
        i = bisect.bisect_left(addrs, a)
        lo = third[i - 1] if i > 0 else None
        hi = third[i] if i < len(third) else None
        if lo is True and hi is True:
            out["third_party_flanked"].append(a)
        elif lo is False and hi is False:
            out["first_party_flanked"].append(a)
        else:
            out["mixed"].append(a)
    return out


def attribute(report):
    data, scanned = load(report)
    sizes = json.loads((TOOLS / "slus21782_functions.json").read_text())["windows"]
    addrs = [a for a, _, _ in scanned]
    third = [verify.is_third_party(f) for _, f, _ in scanned]
    seen = set(addrs)
    unscanned = sorted(int(a, 16) for a in sizes if int(a, 16) not in seen)

    buckets = bucket(unscanned, addrs, third)

    fp = [(a, f, s) for a, f, s in scanned if not verify.is_third_party(f)]
    matched = sum(1 for _, _, s in fp if s == "MATCH")
    asm = sum(1 for _, _, s in fp if s == "ASM")
    return {
        "total_windows": len(sizes),
        "scanned": len(scanned),
        "unscanned": len(unscanned),
        "first_party_matched": matched,
        "first_party_asm": asm,
        "unscanned_first_party_flanked": len(buckets["first_party_flanked"]),
        "unscanned_third_party_flanked": len(buckets["third_party_flanked"]),
        "unscanned_mixed": len(buckets["mixed"]),
    }, buckets


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--json", type=Path)
    args = ap.parse_args()
    summary, buckets = attribute(args.report)
    print(f"canonical windows              {summary['total_windows']}")
    print(f"  scanned by verify.py         {summary['scanned']}")
    print(f"    first-party MATCH          {summary['first_party_matched']}")
    print(f"    first-party ASM            {summary['first_party_asm']}")
    print(f"  unscanned                    {summary['unscanned']}")
    print(f"    flanked by first-party     {summary['unscanned_first_party_flanked']}"
          "   in scope")
    print(f"    flanked by third-party     {summary['unscanned_third_party_flanked']}"
          "   likely middleware")
    print(f"    mixed / edge               {summary['unscanned_mixed']}"
          "   needs real attribution")
    inscope = (summary["first_party_matched"] + summary["first_party_asm"] +
               summary["unscanned_first_party_flanked"] + summary["unscanned_mixed"])
    if inscope:
        pct = 100.0 * summary["first_party_matched"] / inscope
        print(f"\nfirst-party, excluding third-party-flanked windows: "
              f"{summary['first_party_matched']}/{inscope} = {pct:.1f}%")
    print("\nThis is a REPORT. verify.is_third_party remains the only authority for "
          "what is third-party; the mixed bucket is deliberately not guessed.")
    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps(
            {"summary": summary,
             "third_party_flanked": [f"{a:08x}" for a in buckets["third_party_flanked"]],
             "mixed": [f"{a:08x}" for a in buckets["mixed"]]}, indent=2) + "\n")
        print(f"wrote {args.json}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
