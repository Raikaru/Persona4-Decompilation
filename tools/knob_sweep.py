#!/usr/bin/env python3
"""Try MWCCPS2 codegen pragmas one at a time on functions that are stuck.

This exists because the campaign was using 19 pragma spellings while b210 accepts
**389**. `#pragma no_branch_likely on` was found this way and immediately turned
four documented "compiler floor" functions into byte-exact matches: b210 was
emitting a branch-likely (`beql`) where retail used a plain `beqz`.

The knob list is discovered, not hardcoded: identifiers are pulled out of the
compiler binary and validated with `#pragma warn_illpragma on`, the same mechanism
`tools/pragma_audit.py` uses, so it stays correct for any b210-family compiler.

A pragma is only ever proposed here, never adopted silently. A hit still has to
earn its place: `tools/decomp_lint.py` requires the literal word `measured` within
three lines, and a pragma that changes codegen without a reason recorded is exactly
the "window fill" this campaign treats as a defect.

Usage:
  python tools/knob_sweep.py --targets C:/tmp/stuck.json          # [{file, function}]
  python tools/knob_sweep.py --targets ... --knobs opt_lifetimes,schedule
  python tools/knob_sweep.py --list-knobs
  python tools/knob_sweep.py --targets ... --json out.json
"""
from pathlib import Path
import argparse
import json
import re
import subprocess
import sys

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))
import verify  # noqa: E402

MARK = re.compile(r'^\s*//\s*FUN_([0-9A-Fa-f]{8})\b')
IDENT = re.compile(rb'[a-z][a-z0-9_]{3,31}')

# Knobs worth trying first: these govern branch form, register lifetime, scheduling
# and arithmetic lowering, which is where residuals actually live. The full
# validated list is available with --list-knobs.
DEFAULT_KNOBS = [
    "no_branch_likely on",
    "conditional_move off", "conditional_move on",
    "schedule on", "schedule off",
    "opt_lifetimes off", "opt_scalarizeliveranges off", "reg_class_allocs off",
    "cse_hard_reg_gpr off", "cse_hard_reg_special off",
    "opt_strength_reduction off", "opt_strength_reduction_strict on",
    "optimize_for_size on",
    "opt_propagation off", "opt_common_subs off", "opt_dead_assignments off",
    "opt_rebuildconditionals off", "opt_rebuildlogicals off",
    "opt_optimizecontrolflow off", "opt_repositioncode off", "opt_movepostops off",
    "opt_loop_invariants on", "opt_loop_invariants off",
    "opt_pointer_analysis off", "opt_treetransformation off",
    "opt_serializeassignments on", "opt_prelinearize off",
    "opt_foldconstants off", "opt_pulloutconstants off",
    "opt_arithtransformation off", "opt_unpromotetypes off",
    "optimization_level 1", "optimization_level 3",
    "tailcall off",
]


def discover_knobs(mwcc):
    """Every pragma name the compiler binary contains AND actually accepts."""
    import importlib.util
    spec = importlib.util.spec_from_file_location("pa", TOOLS / "pragma_audit.py")
    pa = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(pa)
    blob = Path(mwcc).read_bytes()
    cands = {m.group().decode() for m in IDENT.finditer(blob)}
    cands = {c for c in cands if "_" in c or c in ("schedule", "inline", "align", "pack")}
    probes = {f"{c} on": 1 for c in sorted(cands)}
    bad = set(pa.illegal(probes, mwcc))
    return sorted(p[:-3] for p in probes if p not in bad)


def locate(lines, addr):
    mi = next(k for k, l in enumerate(lines)
              if MARK.match(l) and MARK.match(l).group(1).lower() == addr)
    j = next(k for k in range(mi, len(lines)) if lines[k].strip() == "#ifdef NON_MATCHING")
    e = next(k for k in range(j, len(lines)) if lines[k].strip() == "#else")
    z = next(k for k in range(e, len(lines)) if lines[k].strip() == "#endif")
    return mi, j, e, z


def measure(cfile, addr, wrap=None, report="build/knob_sweep.json"):
    """Score the preserved body, optionally wrapped in a pragma pair.

    Anything between the marker and `#ifdef` is PRESERVED: that region holds
    `#pragma schedule on` and floor notes, and dropping it makes a function look
    several instructions worse than it is.
    """
    path = Path(cfile)
    orig = path.read_bytes()
    txt = orig.decode("utf-8", errors="replace")
    nl = "\r\n" if txt.count("\r\n") >= max(1, txt.count("\n") // 2) else "\n"
    lines = txt.replace("\r\n", "\n").split("\n")
    try:
        mi, j, e, z = locate(lines, addr)
    except StopIteration:
        return ("NO_BODY", None, None, 0)
    keep, body = lines[mi + 1:j], lines[j + 1:e]
    if wrap:
        name, val = wrap.split(None, 1)
        inv = "off" if val == "on" else ("on" if val == "off" else "2")
        body = [f"#pragma {name} {val}"] + body + [f"#pragma {name} {inv}"]
    lines[mi:z + 1] = [re.sub(r"\s+NONMATCHING\b.*$", "", lines[mi])] + keep + body
    path.write_bytes(nl.join(lines).encode())
    rp = Path(report)
    rp.parent.mkdir(parents=True, exist_ok=True)
    try:
        subprocess.run([sys.executable, str(TOOLS / "verify.py"), "--json", str(rp), cfile],
                       cwd=str(REPO), capture_output=True, stdin=subprocess.DEVNULL)
        d = json.loads(rp.read_text())
        row = [r for r in d["results"] if r["name"] == f"func_{addr}"]
        if not row:
            return ("NO_ROW", None, None, 0)
        coll = [r["name"] for r in d["results"]
                if r["status"] in ("MISMATCH", "COMPILE_ERROR") and r["name"] != f"func_{addr}"]
        return (row[0]["status"], row[0].get("normalized_diff"),
                row[0].get("object_size"), len(coll))
    finally:
        path.write_bytes(orig)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--targets", type=Path, help='JSON list of {file, function}')
    ap.add_argument("--knobs", help="comma-separated overrides, e.g. 'schedule on,tailcall off'")
    ap.add_argument("--list-knobs", action="store_true")
    ap.add_argument("--json", type=Path)
    args = ap.parse_args()

    mwcc = verify.load_config()["mwcc"]
    if args.list_knobs:
        knobs = discover_knobs(mwcc)
        print(f"{len(knobs)} pragmas accepted by {Path(mwcc).name}")
        for k in knobs:
            print(" ", k)
        return 0
    if not args.targets:
        ap.error("--targets is required unless --list-knobs")

    knobs = [k.strip() for k in args.knobs.split(",")] if args.knobs else DEFAULT_KNOBS
    targets = json.loads(args.targets.read_text())
    results = []
    for t in targets:
        addr = t["function"][len("func_"):] if t["function"].startswith("func_") else t["function"]
        addr = addr.lower()
        base = measure(t["file"], addr)
        print(f"{addr}  base {base[0]} nd={base[1]}")
        if base[0] == "MATCH":
            continue
        for knob in knobs:
            st, nd, obj, coll = measure(t["file"], addr, wrap=knob)
            if st == "MATCH" and coll == 0:
                print(f"    MATCH  #pragma {knob}")
                results.append({**t, "knob": knob, "was_nd": base[1], "status": "MATCH"})
                break
            if nd is not None and base[1] is not None and nd < base[1] and coll == 0:
                print(f"    better #pragma {knob}: nd {base[1]} -> {nd}")
                results.append({**t, "knob": knob, "was_nd": base[1], "nd": nd,
                                "status": "IMPROVED"})
    print(f"\n{sum(1 for r in results if r['status'] == 'MATCH')} match(es), "
          f"{sum(1 for r in results if r['status'] == 'IMPROVED')} improvement(s)")
    if args.json:
        args.json.write_text(json.dumps(results, indent=2) + "\n")
    print("A hit is a PROPOSAL. Record why it is load-bearing (decomp_lint wants the "
          "word `measured` within three lines) before committing it.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
