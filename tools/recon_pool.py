#!/usr/bin/env python3
"""Rank what is actually worth attempting next, from measurement.

Two pools, and the distinction matters because they fail for different
reasons and respond to different work:

  --pool fresh    first-party functions with no archived attempt at all.
                  Cold reconstruction. Measured to work only at a retail
                  window of about 256 bytes or less: across two waves,
                  3 of 8 closed at <= 256 B and 0 of 12 closed above it.
                  Only a handful of these remain under the cliff.

  --pool nearmiss (default) functions still INCLUDE_ASM that already carry an
                  archived body scoring 0 < nd <= 25. Their nd is recovered by
                  parsing the archive notes under docs/probe_archive/. This is the pool with
                  volume left in it. Permuting their spelling is a measured
                  zero; re-deriving their logic from the retail disassembly is
                  not, which is how func_0028b6b0 closed from a parked nd 8.

Archives are matched as both `*_body.c` and `*_body.c.txt`; globbing only the
first overstates the untouched population by about three hundred.

**The nd read out of an archive is a CLAIM, not a measurement.** Notes are
written by hand at the end of a lane and they go stale: the tree moves, a
declaration environment changes, and the number stops being reproducible.
`func_003bcf10` was listed at nd 2 and measures nd 32 when its archived body is
actually installed today. Worse, some notes quote an `nd 0` that came from an
`INCLUDE_ASM` self-compare rather than from a compiled body. So the column is
reported as `claimed_nd`, and `--measure` exists to replace it with a real one:
it installs each archived body over the `INCLUDE_ASM`, runs a scoped verify,
records what actually happens, and restores the file. That costs a couple of
seconds per target and is the only ranking worth acting on.

Usage:
    python -E -s tools/recon_pool.py [--report build/verify_report.json]
                                     [--pool nearmiss|fresh]
                                     [--max-window 400] [--max-nd 25]
                                     [--measure] [--limit 40]
                                     [--json build/recon_pool.json] [--top 25]
"""

import argparse
import glob
import json
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, "tools"))

from verify import is_third_party, is_vendor_address  # noqa: E402

# "normalized_diff 42", "nd 42", "nd=42" -- lanes have written all three.
ND = re.compile(r"normalized[_ ]diff[ =]*(\d+)|\bnd[ =]+(\d+)", re.I)
# "object 204 / window 208", "object_size 204/208", "obj 204B / 208B"
OW = re.compile(r"obj(?:ect)?(?:[_ ]size)?[ =]*(\d+)\s*B?\s*/\s*(?:window\s*)?(\d+)", re.I)


def addr_of(row):
    a = row.get("addr")
    return int(str(a), 16) if isinstance(a, str) else a


def archives():
    """addr -> (best_nd, object, window, path) parsed out of the archive notes.

    Lanes have never agreed on a filename. `*_body.c` and `*_body.c.txt` are
    the common forms, but the tree also holds `WT17_004140F0.c`,
    `WLFcl_004555d0_base.c` and others -- 137 still-unmatched functions have an
    attempt recorded under a name the `_body` globs miss, and every one of them
    would otherwise be handed to a lane as "never attempted". A wave-4 lane
    burned most of its run rediscovering three such archives.

    So the rule is: any `.c`/`.txt` under `build/` whose NAME encodes an
    address, whose CONTENT looks like C. The content test is what keeps probe
    drivers, disassembly dumps and scope reports out; matching on the name
    alone overstates the attempted population badly.
    """
    best = {}
    for path in glob.glob(os.path.join(REPO, "docs", "probe_archive", "*")):
        name = os.path.basename(path)
        if os.path.splitext(name)[1].lower() not in (".c", ".txt"):
            continue
        m = re.search(r"([0-9a-fA-F]{8})", name)
        if not m:
            continue
        try:
            text = open(path, errors="ignore").read()
        except OSError:
            continue
        if "{" not in text or ";" not in text:
            continue
        nds = [int(g) for mm in ND.finditer(text) for g in mm.groups() if g]
        ow = OW.search(text)
        entry = (min(nds) if nds else None,
                 int(ow.group(1)) if ow else None,
                 int(ow.group(2)) if ow else None,
                 os.path.relpath(path, REPO).replace("\\", "/"))
        addr = int(m.group(1), 16)
        prev = best.get(addr)
        # Prefer the record that actually carries a measurement, then the
        # lowest one; an archive with no nd still proves the function was
        # attempted, which is what the `fresh` pool needs to know.
        if prev is None or (entry[0] is not None
                            and (prev[0] is None or entry[0] < prev[0])):
            best[addr] = entry
    return best


def body_text(archive_path):
    """The C out of an archive file, with the trailing prose note dropped.

    Lanes append a `/* ... */` findings block after the body. Splicing that in
    is harmless to the compiler but makes the installed region hard to read,
    and a stray unterminated comment would take the whole unit down.
    """
    text = open(os.path.join(REPO, archive_path), errors="ignore").read()
    cut = text.rfind("\n/*")
    return (text[:cut] if cut > 0 else text).rstrip() + "\n"


def measure(entry):
    """Install the archived body, score it, restore. -> (nd, object_size)."""
    path = os.path.join(REPO, entry["file"])
    with open(path, "r", newline="") as f:
        original = f.read()

    marker = "// " + entry["name"].replace("func_", "FUN_").upper()
    start = original.find(marker)
    if start < 0:
        return None, None
    eol = original.index("\n", start)
    end = original.find("// FUN_", eol)
    if end < 0:
        return None, None

    report = os.path.join(REPO, "build", "recon_pool_probe.json")
    try:
        with open(path, "w", newline="") as f:
            # Keep the marker line verbatim: several carry a NONMATCHING
            # suffix, and verify.py keys off these comments.
            f.write(original[:start] + original[start:eol] + "\n"
                    + body_text(entry["archive"]) + original[end:])
        subprocess.run([sys.executable, "-E", "-s", "tools/verify.py",
                        entry["file"], "--json", report],
                       cwd=REPO, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        try:
            rows = json.load(open(report))["results"]
        except Exception:
            return None, None
        row = next((x for x in rows if x["name"] == entry["name"]), None)
        if row is None or row["status"] == "COMPILE_ERROR":
            return None, None
        return row.get("normalized_diff"), row.get("object_size")
    finally:
        with open(path, "w", newline="") as f:
            f.write(original)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", default="build/verify_report.json")
    ap.add_argument("--pool", choices=("nearmiss", "fresh"), default="nearmiss")
    ap.add_argument("--max-window", type=int, default=400)
    ap.add_argument("--max-nd", type=int, default=25)
    ap.add_argument("--json", default="build/recon_pool.json")
    ap.add_argument("--top", type=int, default=25)
    ap.add_argument("--measure", action="store_true",
                    help="install each archived body and score it for real, "
                         "replacing the claimed nd from the archive notes")
    ap.add_argument("--limit", type=int, default=40,
                    help="how many targets --measure actually compiles")
    args = ap.parse_args()

    rows = json.load(open(os.path.join(REPO, args.report)))["results"]
    asm = [r for r in rows
           if r["status"] == "ASM"
           and not is_third_party(r["file"])
           and not is_vendor_address(r.get("addr"))]
    arch = archives()

    out = []
    for r in asm:
        addr = addr_of(r)
        window = r.get("window") or 0
        hit = arch.get(addr)
        if args.pool == "fresh":
            if hit is not None or window > args.max_window:
                continue
            nd = None
        else:
            # An archive with no parsed nd still proves the function was
            # attempted, so it stays out of `fresh`, but it cannot be ranked
            # here and is not a nearmiss candidate.
            if hit is None or hit[0] is None:
                continue
            if not (0 < hit[0] <= args.max_nd) or window > args.max_window:
                continue
            nd = hit[0]
        out.append({"addr": "%08x" % addr,
                    "name": r["name"],
                    "file": r["file"].replace("\\", "/"),
                    "window": window,
                    "claimed_nd": nd,
                    "measured_nd": None,
                    "measured_object": None,
                    "archive": hit[3] if hit else None})

    out.sort(key=lambda e: (e["claimed_nd"] if e["claimed_nd"] is not None else 0,
                            e["window"]))

    if args.measure:
        for e in out[:args.limit]:
            nd, obj = measure(e)
            e["measured_nd"], e["measured_object"] = nd, obj
        # A target whose archive will not even compile is worth less than one
        # that compiles badly, so sort unmeasurable entries to the back.
        out.sort(key=lambda e: (e["measured_nd"] if e["measured_nd"] is not None
                                else 10 ** 6, e["window"]))

    with open(os.path.join(REPO, args.json), "w") as f:
        json.dump(out, f, indent=1)

    print("pool=%s  max_window=%d  max_nd=%s  ->  %d targets  (%s)"
          % (args.pool, args.max_window,
             args.max_nd if args.pool == "nearmiss" else "n/a", len(out), args.json))
    for e in out[:args.top]:
        if args.measure:
            print("  measured %-6s claimed %-5s win %-5d %-18s %-34s %s"
                  % (e["measured_nd"], e["claimed_nd"], e["window"],
                     e["name"], e["file"], e["archive"] or ""))
        else:
            print("  claimed nd %-5s win %-5d %-18s %-34s %s"
                  % (e["claimed_nd"], e["window"], e["name"], e["file"],
                     e["archive"] or ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
