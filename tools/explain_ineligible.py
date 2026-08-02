#!/usr/bin/env python3
"""Say why each matching translation unit is or is not link-eligible.

`tools/build.py` prints how many C objects it placed, but not why a unit was
rejected. After a big matching wave that number can fall even though the image
is still byte-exact, because a unit that stops linking silently reverts to
retail bytes. The usual cause is a newly referenced data symbol that exists in
no symbol config, which is invisible to `verify.py` (it masks relocations).

    python tools/explain_ineligible.py                 # summary by reason
    python tools/explain_ineligible.py --reason symbol # list the unresolved names

Reasons reported:
  no-markers       nothing the verifier tracks in this file
  blocking-fn      a stub, or a NONMATCHING body with no INCLUDE_ASM fallback
  compile          the eligibility compile produced no object
  missing-symbol   a function's own symbol is absent from the object
  window           no plausible retail window for a function
  bytes            compiled bytes differ from retail, or overflow the window
  unresolved       a relocation names a symbol nothing can resolve
"""

from __future__ import annotations

import argparse
import bisect
import collections
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import build as B  # noqa: E402
import verify as V  # noqa: E402


def classify(c, resolvable, boundaries, window_sizes, retail, cache, cpath):
    """Return (reason, detail) for one source file; reason None means eligible."""
    markers = V.scan_markers(cpath)
    real = [m for m in markers if m["name"]]
    if not real:
        return "no-markers", ""
    blocking = [m for m in real
                if m["stub"] or (m["nonmatching"] and not m.get("asm"))]
    if blocking:
        return "blocking-fn", blocking[0]["name"] or hex(blocking[0]["addr"])

    obj = B.compile_eligibility(c, cpath, cache)
    if obj is None:
        return "compile", ""
    symtab = {s["name"]: s.get("shndx", 0) for s in obj.symbols}

    for m in real:
        try:
            body, rels = obj.function(m["name"])
        except KeyError:
            return "missing-symbol", m["name"]
        i = bisect.bisect_right(boundaries, m["addr"])
        win = (boundaries[i] - m["addr"] if i < len(boundaries)
               else (window_sizes or {}).get(m["addr"]))
        if not win or win > 0x10000:
            return "window", m["name"]
        wb = retail.bytes_at(m["addr"], win)
        if (V.compare(body, rels, wb[:len(body)])[0] != 0
                or len(body) > win or any(wb[len(body):])):
            return "bytes", m["name"]
        for r in rels:
            nm = r["symbol"]
            if nm and symtab.get(nm, 0) == 0 and nm not in resolvable:
                return "unresolved", f"{nm} (in {m['name']})"
    return None, ""


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reason", help="list only files with this reason")
    args = parser.parse_args()

    c = B.cfg()
    cache = B.BC.ObjectCache(B.BUILD / "cache" / "c", REPO)
    retail = V.RetailElf(c["retail_elf"], B.TARGET, B.RETAIL_SHA1)
    gp, defs = B.load_lcf_symbols()
    resolvable = set(defs) | B.load_symbol_names() | B.source_marker_names()
    boundaries = B.load_windows()
    window_sizes = B.load_window_sizes()
    counts: collections.Counter[str] = collections.Counter()
    details: dict[str, list[tuple[str, str]]] = collections.defaultdict(list)
    for cpath in sorted(p for p in (REPO / "src").rglob("*.c")
                        if not V.is_generated(p)):
        reason, detail = classify(c, resolvable, boundaries, window_sizes,
                                  retail, cache, cpath)
        key = reason or "ELIGIBLE"
        counts[key] += 1
        details[key].append((str(cpath.relative_to(REPO)), detail))

    if args.reason:
        for path, detail in details.get(args.reason, []):
            print(f"  {path:<52} {detail}")
        print(f"\n{len(details.get(args.reason, []))} file(s) with reason "
              f"{args.reason!r}")
        return 0

    print("link eligibility by reason:")
    for key, n in counts.most_common():
        print(f"  {key:<16} {n}")
    print("\nrerun with --reason <name> to list the files")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
