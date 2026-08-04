#!/usr/bin/env python3
"""Batch-drive tools/permute.py across the functions that have a starting body.

Adapted from the sibling Persona 3 FES tree. The P3 version discovers targets
from a verify scan looking for NONMATCHING/MISMATCH rows, which finds nothing
here: this repo holds 0 MISMATCH by policy, and its unmatched functions are
INCLUDE_ASM fallbacks with no live C at all. What it does have is 86 functions
whose best-known body was preserved under `#ifdef NON_MATCHING` when it was
documented as a floor. Those bodies are exactly what a permuter needs as a
starting point, so this version discovers them instead.

Per target it: activates the preserved body, runs the permuter under a time
budget, and then either keeps the winning region (dropping the #ifdef wrapper)
or restores the file byte-for-byte. A function that does not crack must leave no
trace -- a half-activated body is a MISMATCH, which is a hard failure here.

Files are the unit of mutual exclusion: permute.py edits the real source in
place, so two workers must never hold the same file. Targets are grouped by file
and each group runs on one worker.

Usage:
  python tools/permute_sweep.py --time 120 --workers 3
  python tools/permute_sweep.py --targets build/perm_targets.json --time 300
  python tools/permute_sweep.py --list          # show targets and exit
"""

from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
import argparse
import collections
import json
import re
import subprocess
import sys
import time

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))
import verify  # noqa: E402

MARKER_RE = re.compile(r"^\s*//\s*FUN_([0-9A-Fa-f]{8})\b")


def newline_of(raw: bytes) -> str:
    return "\r\n" if raw.count(b"\r\n") >= max(1, raw.count(b"\n") // 2) else "\n"


def discover_targets():
    """Every first-party function with a preserved `#ifdef NON_MATCHING` body."""
    found = []
    for path in sorted(REPO.glob("src/**/*.c")):
        rel = path.relative_to(REPO).as_posix()
        if verify.is_third_party(rel) or "/generated/" in rel:
            continue
        lines = path.read_text(errors="replace").splitlines()
        for i, line in enumerate(lines):
            if line.strip() != "#ifdef NON_MATCHING":
                continue
            marker = next((k for k in range(i - 1, max(-1, i - 30), -1)
                           if MARKER_RE.match(lines[k])), None)
            if marker is None:
                continue
            other = next((k for k in range(i, len(lines))
                          if lines[k].strip() == "#else"), None)
            if other is None:
                continue
            end = next((k for k in range(other, len(lines))
                        if lines[k].strip() == "#endif"), None)
            if end is None:
                continue
            addr = MARKER_RE.match(lines[marker]).group(1).lower()
            found.append({"file": rel, "function": f"func_{addr}",
                          "body_lines": other - i - 1})
    return found


def activate(path: Path, function: str):
    """Make the preserved body live. Returns the original bytes, or None."""
    original = path.read_bytes()
    nl = newline_of(original)
    lines = original.decode("utf-8", errors="replace").splitlines()
    addr = function[len("func_"):]
    marker = next((k for k, l in enumerate(lines)
                   if MARKER_RE.match(l) and MARKER_RE.match(l).group(1).lower() == addr), None)
    if marker is None:
        return None
    ifdef = next((k for k in range(marker, min(len(lines), marker + 40))
                  if lines[k].strip() == "#ifdef NON_MATCHING"), None)
    if ifdef is None:
        return None
    other = next((k for k in range(ifdef, len(lines)) if lines[k].strip() == "#else"), None)
    end = next((k for k in range(other, len(lines)) if lines[k].strip() == "#endif"), None) \
        if other is not None else None
    if other is None or end is None:
        return None
    body = lines[ifdef + 1:other]
    # Drop the NONMATCHING suffix so the marker parses as a plain marker.
    lines[marker] = re.sub(r"\s+NONMATCHING\b.*$", "", lines[marker])
    lines[ifdef:end + 1] = body
    path.write_bytes((nl.join(lines) + nl).encode())
    return original


def splice(path: Path, function: str, region):
    """Replace the function's marker-to-closing-brace span with `region`."""
    raw = path.read_bytes()
    nl = newline_of(raw)
    lines = raw.decode("utf-8", errors="replace").splitlines()
    addr = function[len("func_"):]
    marker = next((k for k, l in enumerate(lines)
                   if MARKER_RE.match(l) and MARKER_RE.match(l).group(1).lower() == addr), None)
    if marker is None:
        return False
    close = next((k for k in range(marker, len(lines)) if lines[k].startswith("}")), None)
    if close is None:
        return False
    lines[marker:close + 1] = region
    path.write_bytes((nl.join(lines) + nl).encode())
    return True


def run_one(target, budget, outdir, engine="text"):
    path = REPO / target["file"]
    original = activate(path, target["function"])
    if original is None:
        return {**target, "status": "SKIP", "reason": "could not activate the body"}
    out = outdir / f"{path.stem}.{target['function']}.match.c"
    tool = "permute_ast.py" if engine == "ast" else "permute.py"
    try:
        proc = subprocess.run(
            [sys.executable, str(TOOLS / tool), str(path), target["function"],
             "--time", str(budget), "--out", str(out)],
            cwd=str(REPO), capture_output=True, text=True, timeout=budget + 180)
        text = proc.stdout + proc.stderr
        cracked = "MATCH at iter" in text or "match=True" in text
        score = None
        hit = re.findall(r"best_score=(\d+)", text)
        if hit:
            score = int(hit[-1])
        if cracked:
            # permute.py restores the source it was given and writes the WINNING
            # region to --out, so the activated file still holds the losing body.
            # Leaving it as-is reports CRACKED for a function verify.py then calls
            # MISMATCH, which is a hard failure here -- splice the winner in.
            if not out.is_file():
                path.write_bytes(original)
                return {**target, "status": "SKIP", "reason": "no --out region written"}
            # An AST hit is heavily mutated (dead temps, empty ifs) and is NOT
            # committable as-is; restore and report so it can be reduced by hand
            # from the saved region. A text hit is a plain reordering and can be
            # spliced straight in.
            if engine == "ast":
                path.write_bytes(original)
                return {**target, "status": "CRACKED_AST", "score": 0, "out": str(out)}
            if not splice(path, target["function"], out.read_text().rstrip("\n").split("\n")):
                path.write_bytes(original)
                return {**target, "status": "SKIP", "reason": "could not splice the winner"}
            return {**target, "status": "CRACKED", "score": 0, "out": str(out)}
        path.write_bytes(original)
        return {**target, "status": "no", "score": score}
    except subprocess.TimeoutExpired:
        path.write_bytes(original)
        return {**target, "status": "TIMEOUT"}
    except BaseException:
        path.write_bytes(original)
        raise


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--time", type=float, default=120.0, help="seconds per function")
    ap.add_argument("--workers", type=int, default=2)
    ap.add_argument("--targets", type=Path, help="JSON list of {file, function}")
    ap.add_argument("--outdir", type=Path, default=REPO / "build" / "permute")
    ap.add_argument("--json", type=Path, help="write the sweep report here")
    ap.add_argument("--limit", type=int, default=0, help="only the first N targets")
    ap.add_argument("--list", action="store_true", help="print targets and exit")
    ap.add_argument("--engine", choices=("text", "ast"), default="text",
                    help="text = permute.py (fast, commit-ready hits); "
                         "ast = permute_ast.py (stronger, hits need reducing by hand)")
    args = ap.parse_args()

    targets = json.loads(args.targets.read_text()) if args.targets else discover_targets()
    targets.sort(key=lambda t: t.get("body_lines", 0))
    if args.limit:
        targets = targets[:args.limit]
    if args.list:
        for t in targets:
            print(f"  {t.get('body_lines','?'):4} lines  {t['function']:18} {t['file']}")
        print(f"{len(targets)} target(s)")
        return

    args.outdir.mkdir(parents=True, exist_ok=True)
    # One worker per file: permute.py edits the source in place.
    by_file = collections.defaultdict(list)
    for t in targets:
        by_file[t["file"]].append(t)

    results, started = [], time.time()

    def do_group(group):
        return [run_one(t, args.time, args.outdir, args.engine) for t in group]

    with ThreadPoolExecutor(max_workers=max(1, args.workers)) as pool:
        futures = [pool.submit(do_group, g) for g in by_file.values()]
        for fut in as_completed(futures):
            for row in fut.result():
                results.append(row)
                if row["status"] in ("CRACKED", "CRACKED_AST", "TIMEOUT", "SKIP"):
                    print(f"[{row['status']}] {row['function']} ({row['file']})", flush=True)

    cracked = [r for r in results if r["status"].startswith("CRACKED")]
    print(f"\nswept {len(results)} function(s) in {time.time()-started:.0f}s; "
          f"cracked {len(cracked)}")
    for r in cracked:
        print(f"  CRACKED {r['function']}  {r['file']}")
    if cracked:
        if any(r["status"] == "CRACKED_AST" for r in cracked):
            print("\nAST hits are left OUT of the tree: their source carries dead temps and "
                  "empty ifs.\nReduce each saved region to honest C by hand, then confirm "
                  "with tools/verify.py.")
        else:
            print("\nRe-run tools/verify.py before committing: a permuter hit is a byte "
                  "match, not a semantic proof.")
    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps(results, indent=2) + "\n")
        print(f"report: {args.json}")


if __name__ == "__main__":
    main()
