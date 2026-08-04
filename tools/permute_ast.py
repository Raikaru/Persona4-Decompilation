#!/usr/bin/env python3
"""AST-level permuter: upstream decomp-permuter's randomizer, wired to this
repo's mwccps2 compile + verify.py reloc-masked scoring.

Ported from the sibling Persona 3 FES tree. Changes needed here: the boundary-map
filename, and RetailElf taking a target dict for config/target.json validation.
Reach for this when tools/permute.py has converged -- measured in
docs/matching.md, it converges inside a minute and a 7x budget buys nothing,
because text mutation cannot restructure code the way these AST passes do.

Where tools/permute.py mutates function *text*, this drives the full
decomp-permuter randomizer (https://github.com/simonlindholm/decomp-permuter):
~30 AST-level passes including temporary-for-expression, type randomization,
statement reordering, and reassociation -- strictly more powerful, and the tool
to reach for on register-allocation / scheduling walls that text mutation can't.

Pipeline (mirrors decomp-permuter's Candidate, minus its objdump scorer):
  1. Preprocess the TU with WSL `cpp -nostdinc` (the repo is self-contained).
  2. Parse with decomp-permuter's pycparser; extract + normalize the function.
  3. Hill-climb: deep-copy the best function, apply one randomizer mutation,
     unparse the whole TU, compile with mwccps2, and score the function's bytes
     against retail exactly as verify.py does (reloc-masked, tail-padding check).

decomp-permuter is cloned into tools/decomp-permuter on first run (gitignored).
Requires WSL Debian with `cpp` (build-essential) and system Python with
`pycparser`, `attrs`, `toml`.

IMPORTANT: a hit's source is usually heavily mutated (dead temps, `if (1)`,
reassociations). It compiles byte-exact, but you MUST read it, extract the one
change that matters, and write clean C -- then confirm with tools/verify.py.
This is the normal decomp-permuter workflow, not a drop-in patch.

Usage:
  python tools/permute_ast.py src/Battle/btlMain.c btlMainUpdateStateLose --time 120
  python tools/permute_ast.py <file.c> <func> [--time S] [--iters N] [--seed S] [--out F]
"""
import argparse
import atexit
import copy
import json
import os
import shlex
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
DP_URL = "https://github.com/simonlindholm/decomp-permuter"


def find_dp():
    for cand in (TOOLS / "decomp-permuter", REPO / "build" / "dp"):
        if (cand / "src" / "randomizer.py").is_file():
            return cand
    dest = TOOLS / "decomp-permuter"
    print(f"cloning decomp-permuter into {dest} ...", flush=True)
    r = subprocess.run(["git", "clone", "--depth", "1", DP_URL, str(dest)])
    if r.returncode or not (dest / "src" / "randomizer.py").is_file():
        sys.exit("failed to clone decomp-permuter; clone it manually to "
                 f"{dest} (git clone {DP_URL})")
    return dest


DP = find_dp()
sys.path.insert(0, str(DP))
sys.path.insert(0, str(TOOLS))
from src import ast_util
from src.randomizer import Randomizer
from src.helpers import get_default_randomization_weights
from verify import (ObjectFile, RetailElf, compare, load_config, scan_markers,
                    window_for)


def wslpath(p):
    s = str(p).replace("\\", "/")
    return "/mnt/" + s[0].lower() + s[2:]


def _clean_mwcc_pp(out):
    """Strip mwcc -E artifacts pycparser cannot digest: the '###' banner and
    '/* #line ... */' markers."""
    lines = []
    for ln in out.splitlines():
        s = ln.lstrip()
        if s.startswith("###") or s.startswith("#") or s.startswith("/* #line"):
            continue
        lines.append(ln)
    return "\n".join(lines)


def preprocess(rel, cfg):
    # Primary: the project compiler's own preprocessor (definitionally correct,
    # no WSL dependency). Fallback: GNU cpp (WSL on Windows).
    r = subprocess.run([cfg["mwcc"], "-E", "-Iinclude", rel],
                       cwd=str(REPO), capture_output=True, text=True)
    if r.returncode == 0 and len(r.stdout) > 100:
        return _clean_mwcc_pp(r.stdout)
    flags = ["-Iinclude", "-nostdinc", "-undef", "-D__MWERKS__=1", rel]
    if os.name == "nt":
        # Windows: cpp lives in WSL; distro overridable via P3_WSL_DISTRO.
        distro = os.environ.get("P3_WSL_DISTRO", "Debian")
        inner = f"cd {shlex.quote(wslpath(REPO))} && cpp " + " ".join(shlex.quote(f) for f in flags)
        r = subprocess.run(["wsl", "-d", distro, "--", "bash", "-lc", inner],
                           capture_output=True, text=True)
    else:
        r = subprocess.run(["cpp"] + flags, cwd=str(REPO), capture_output=True, text=True)
    if r.returncode or len(r.stdout) < 100:
        sys.exit(f"preprocessing failed (mwcc -E and cpp): {r.stderr[:600]}")
    return r.stdout


def all_boundaries(sizes):
    bounds = {int(a, 16) for a in sizes["windows"]}
    last = max(bounds)
    lw = sizes["windows"][f"{last:08x}"]
    if lw:
        bounds.add(last + lw)  # close the final window (parity with permute.py)
    for c in (REPO / "src").rglob("*.c"):
        for m in scan_markers(c):
            bounds.add(m["addr"])
    return sorted(bounds)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("function")
    ap.add_argument("--iters", type=int, default=10 ** 8)
    ap.add_argument("--time", type=float, default=120.0)
    ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--out")
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21782_functions.json").read_text())
    # This repo's RetailElf validates against config/target.json as well as the
    # boundary map's sha1, so it takes the target dict the P3 version did not.
    target = json.loads((REPO / "config" / "target.json").read_text())
    if sizes.get("program") != "SLUS_217.82" or sizes.get("sha1") != target["elf"]["sha1"]:
        sys.exit("permute_ast: slus21782_functions.json does not describe the target")
    retail = RetailElf(cfg["retail_elf"], target, sizes["sha1"])
    mk = next((m for m in scan_markers(REPO / args.file)
               if m["name"] == args.function), None)
    if not mk:
        sys.exit(f"no // FUN_ marker for {args.function} in {args.file}")
    addr = mk["addr"]
    window = window_for(addr, all_boundaries(sizes))
    win_bytes = retail.bytes_at(addr, window)

    source = ast_util.process_pragmas(preprocess(args.file, cfg))
    try:
        base_ast = ast_util.parse_c(source, from_import=True)
    except Exception as e:
        sys.exit(f"pycparser cannot parse the preprocessed TU ({e.__class__.__name__}): "
                 f"likely inline __asm__ or unsupported syntax. The AST permuter "
                 f"cannot handle this file; use tools/permute.py (text) instead.")
    orig_fn, fn_index = ast_util.extract_fn(base_ast, args.function)
    ast_util.normalize_ast(orig_fn, base_ast)

    rnd = Randomizer(get_default_randomization_weights("mwcc"), args.seed)
    tmpdir = Path(tempfile.mkdtemp(prefix="p3ast_"))
    atexit.register(shutil.rmtree, tmpdir, ignore_errors=True)
    ncompiles = [0]

    def make_ast(fn):
        ast = copy.copy(base_ast)
        ast.ext = copy.copy(base_ast.ext)
        ast.ext[fn_index] = fn
        return ast

    def score(ast):
        ncompiles[0] += 1
        cfile = tmpdir / "cand.c"
        cfile.write_text(ast_util.to_c(ast), newline="\n")
        ofile = tmpdir / "cand.o"
        p = subprocess.run(
            [cfg["mwcc"], "-O2", "-c", str(cfile), "-o", str(ofile)],
            cwd=str(REPO), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        if p.returncode or not ofile.is_file():
            return 10 ** 6, False
        try:
            body, rels = ObjectFile(ofile).function(args.function)
        except KeyError:
            return 10 ** 6, False
        ndiff, _ = compare(body, rels, win_bytes)
        tail = win_bytes[len(body):]
        ok = len(body) <= window and not any(tail)
        return ndiff + (0 if ok else 500 + abs(len(body) - window)), (ndiff == 0 and ok)

    base_score, base_match = score(make_ast(orig_fn))
    print(f"[{args.function}] addr={addr:#010x} window={window} "
          f"base_score={base_score} match={base_match}", flush=True)
    if base_score >= 10 ** 6:
        sys.exit("base TU failed the parse->unparse->compile round-trip (inline "
                 "__asm__ or constructs lost by the AST printer). The AST permuter "
                 "cannot handle this file; use tools/permute.py (text) instead.")

    best_fn, best_score = orig_fn, base_score
    cur_fn, cur_score = orig_fn, base_score
    t0 = time.time()
    stale = 0
    for it in range(args.iters):
        if args.time and time.time() - t0 > args.time:
            break
        fn = copy.deepcopy(cur_fn)
        ast = make_ast(fn)
        try:
            rnd.randomize(ast, args.function)
        except Exception:
            continue
        sc, match = score(ast)
        if match:
            out = args.out or str(REPO / "build" / f"{args.function}.ast.c")
            Path(out).parent.mkdir(parents=True, exist_ok=True)
            Path(out).write_text(ast_util.to_c(fn) + "\n", newline="\n")
            print(f"[{args.function}] MATCH at iter {it} ({ncompiles[0]} compiles). "
                  f"Mutated function -> {out}\n"
                  f"NOTE: extract the essential change and write clean C; "
                  f"re-confirm with tools/verify.py.", flush=True)
            print("--- mutated function ---\n" + ast_util.to_c(fn))
            return
        if sc < cur_score or (sc == cur_score and rnd.random.random() < 0.3):
            cur_fn, cur_score, stale = fn, sc, 0
        else:
            stale += 1
        if sc < best_score:
            best_fn, best_score = fn, sc
            print(f"[{args.function}] iter {it}: best {best_score} "
                  f"({ncompiles[0]} compiles)", flush=True)
        if stale > 80:
            cur_fn, cur_score, stale = best_fn, best_score, 0
    print(f"[{args.function}] no match. best={best_score} after "
          f"{ncompiles[0]} compiles / {time.time()-t0:.0f}s", flush=True)
    sys.exit(1)


if __name__ == "__main__":
    main()
