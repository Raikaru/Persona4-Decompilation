#!/usr/bin/env python3
"""Repo-native permuter: randomized source-level search for byte-exact matches.

Ported from the sibling Persona 3 FES tree (tools/permute.py) -- the only change
needed was the boundary-map filename, because this repo's tools/verify.py already
exports the same REPO/TOOLS/ObjectFile/RetailElf/compare/load_config/compile_object
surface the P3 version was written against.

This is a lightweight alternative to decomp-permuter
(https://github.com/simonlindholm/decomp-permuter) wired directly to this
repo's proven toolchain: it compiles candidates with the project mwccps2
invocation (identical to tools/verify.py) and scores them with the same
reloc-masked comparison against the retail image. No pycparser / objdump /
cross-platform compile plumbing is required, so it runs wherever verify.py runs.

It mutates ONLY the target function's source text -- keeping the rest of the
translation unit byte-identical -- and hill-climbs toward normalized_diff == 0.
The mutation set targets the mwcc codegen levers that block hand-matching:

  * optimization_level pragma cycling (0/1/2/3)          -> scheduling, latency
  * local-declaration reordering                          -> register allocation
  * adjacent single-line statement reordering             -> instruction schedule
  * commutative operand swaps (+, *, &, |, ^, ==, !=)     -> operand/reg order
  * additive reassociation (a + b + c -> a + (b + c))     -> eval order

A semantics-breaking mutation cannot reach normalized_diff == 0 (it would have
to coincidentally reproduce retail's exact bytes), so bad variants are rejected
by the score. Always re-confirm a reported hit with `python tools/verify.py`
before committing.

Usage:
  python tools/permute.py src/Battle/btlMain.c btlMainUpdateStateLose --iters 4000
  python tools/permute.py <file.c> <func> [--iters N] [--seed S] [--out best.c]
                          [--time SECONDS]
"""

from pathlib import Path
import argparse
import json
import random
import re
import atexit
import shutil
import subprocess
import sys
import tempfile
import time

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import (REPO, TOOLS, ObjectFile, RetailElf, compare, load_config,
                    mask_bytes, scan_markers, strip_line_comment, window_for)

DECL_RE = re.compile(
    r"^\s*(?:const\s+|volatile\s+|unsigned\s+|signed\s+|struct\s+|union\s+|enum\s+)*"
    r"[A-Za-z_][A-Za-z0-9_]*\s*\**\s*"          # type (+ optional pointer stars)
    r"[A-Za-z_][A-Za-z0-9_]*\s*(?:\[[^\]]*\])?\s*;\s*$")  # name (+ optional array)
CTRL_RE = re.compile(r"\b(if|else|for|while|do|switch|case|default|return|goto|break|continue)\b")


def all_boundaries(sizes):
    bounds = {int(a, 16) for a in sizes["windows"]}
    last = max(bounds)
    lw = sizes["windows"][f"{last:08x}"]
    if lw:
        bounds.add(last + lw)
    for c in sorted((REPO / "src").rglob("*.c")):
        if c.name.startswith(".permute_"):
            continue
        for m in scan_markers(c):
            bounds.add(m["addr"])
    return sorted(bounds)


def find_region(lines, marker_idx):
    """Return (start, end) 0-based inclusive line range covering the function
    that begins at the // FUN_ marker on line `marker_idx`."""
    j = marker_idx + 1
    while j < len(lines) and "{" not in strip_line_comment(lines[j]):
        j += 1
    open_line = j
    depth = 0
    seen = False
    while j < len(lines):
        code = strip_line_comment(lines[j])
        depth += code.count("{") - code.count("}")
        if "{" in code:
            seen = True
        if seen and depth <= 0:
            break
        j += 1
    return marker_idx, j, open_line


class Target:
    def __init__(self, cpath, funcname, boundaries, cfg, retail):
        self.cpath = cpath
        self.name = funcname
        self.cfg = cfg
        self.retail = retail
        self.dir = cpath.parent
        self.orig = cpath.read_text(errors="replace")
        self.lines = self.orig.splitlines()
        mk = next((m for m in scan_markers(cpath) if m["name"] == funcname), None)
        if not mk:
            sys.exit(f"permute: no // FUN_ marker for {funcname} in {cpath}")
        self.addr = mk["addr"]
        self.window = window_for(self.addr, boundaries)
        if not self.window:
            sys.exit("permute: could not determine retail window")
        s, e, o = find_region(self.lines, mk["line"] - 1)
        self.start, self.end, self.open_line = s, e, o
        self.region = self.lines[s:e + 1]
        hdr = " ".join(strip_line_comment(l) for l in self.lines[s + 1:o + 1]
                       if not strip_line_comment(l).strip().startswith("#"))
        self.params = parse_params(hdr)
        self.win_bytes = retail.bytes_at(self.addr, self.window)
        self._n = 0
        self.tmpdir = Path(tempfile.mkdtemp(prefix="p3perm_"))
        atexit.register(shutil.rmtree, self.tmpdir, ignore_errors=True)

    def score(self, region):
        """Compile the TU with `region` substituted; return (score, match, log).
        score == 0 and match == True means a verify.py MATCH."""
        self._n += 1
        content = "\n".join(self.lines[:self.start] + region +
                            self.lines[self.end + 1:]) + "\n"
        tmp = self.tmpdir / f"{self.name}.c"
        tmp.write_text(content, newline="\n")
        opath = tmp.with_suffix(".o")
        try:
            proc = subprocess.run(
                [self.cfg["mwcc"], "-O2", "-Iinclude", "-c", str(tmp), "-o", str(opath)],
                cwd=str(REPO), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
            if proc.returncode or not opath.is_file():
                return 10 ** 6, False, proc.stdout
            try:
                body, rels = ObjectFile(opath).function(self.name)
            except KeyError:
                return 10 ** 6, False, "symbol missing"
        finally:
            for p in (tmp, opath):
                try:
                    p.unlink()
                except OSError:
                    pass
        ndiff, _ = compare(body, rels, self.win_bytes)
        tail = self.win_bytes[len(body):]
        size_ok = len(body) <= self.window and not any(tail)
        match = ndiff == 0 and size_ok
        sc = ndiff + (0 if size_ok else 500 + abs(len(body) - self.window))
        return sc, match, ""

    def residual(self, region):
        """Recompile `region` and classify its remaining differing words into
        known wall classes (informational; see docs/matching.md)."""
        import collections
        content = "\n".join(self.lines[:self.start] + region +
                            self.lines[self.end + 1:]) + "\n"
        tmp = self.tmpdir / f"{self.name}.c"
        tmp.write_text(content, newline="\n")
        opath = tmp.with_suffix(".o")
        try:
            proc = subprocess.run(
                [self.cfg["mwcc"], "-O2", "-Iinclude", "-c", str(tmp), "-o", str(opath)],
                cwd=str(REPO), stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
            if proc.returncode or not opath.is_file():
                return None
            try:
                body, rels = ObjectFile(opath).function(self.name)
            except KeyError:
                return None
        finally:
            for p in (tmp, opath):
                try:
                    p.unlink()
                except OSError:
                    pass
        n = len(body)
        mask = mask_bytes(n, rels)
        words = sorted({i & ~3 for i in range(n)
                        if not mask[i] and i < len(self.win_bytes)
                        and self.win_bytes[i] != body[i]})
        kinds = collections.Counter()
        for o in words:
            mine = int.from_bytes(body[o:o + 4], "little")
            ret = int.from_bytes(self.win_bytes[o:o + 4], "little")
            op_m, op_r = mine >> 26, ret >> 26
            if op_m == op_r == 0 and (mine & 0x3F) == (ret & 0x3F) and (mine & 0x3F) in (0x21, 0x2D):
                # addu/daddu with rd equal and {rs, rt} swapped
                if ((mine >> 11) & 31) == ((ret >> 11) & 31) and \
                   {(mine >> 21) & 31, (mine >> 16) & 31} == {(ret >> 21) & 31, (ret >> 16) & 31}:
                    kinds["commutative-addu operand swap"] += 1
                    continue
            if op_m == op_r == 0x11 and (mine & 0x3F) == (ret & 0x3F) == 0x02:
                # mul.fmt with fd equal and {fs, ft} swapped
                if ((mine >> 6) & 31) == ((ret >> 6) & 31) and \
                   {(mine >> 11) & 31, (mine >> 16) & 31} == {(ret >> 11) & 31, (ret >> 16) & 31}:
                    kinds["commutative-mul.s operand swap"] += 1
                    continue
            if op_m == op_r and (op_m != 0 or (mine & 0x3F) == (ret & 0x3F)):
                kinds["register allocation / scheduling"] += 1
            else:
                kinds["other/structural"] += 1
        return kinds


# ------------------------------------------------------------------ mutations

def body_span(region, open_line_local):
    """Indices [b0, b1) of body lines inside region (exclusive of braces)."""
    b0 = open_line_local + 1
    b1 = len(region)
    while b1 > b0 and "}" not in region[b1 - 1]:
        b1 -= 1
    return b0, b1 - 1  # b1-1 is the closing-brace line


def strip_opt(region):
    return [l for l in region if "#pragma optimization_level" not in l]


def mut_opt(region, marker_idx_local, rng):
    n = rng.choice([0, 1, 3, 3])  # bias toward 3; 2 == file default (no-op)
    r = strip_opt(region)
    out = r[:marker_idx_local + 1] + [f"#pragma optimization_level {n}"] + r[marker_idx_local + 1:]
    out = out + ["#pragma optimization_level 2"]
    return out


def mut_schedule(region, marker_idx_local, rng):
    """Cycle b210's independent scheduler and tail-call controls.

    ``optimization_level 3`` bundles both passes, but retail functions
    sometimes use scheduling without tail-call collapse (or need O3 with the
    tail pass disabled).  Keep the reset pragmas in the candidate region so a
    successful mutation cannot leak into the following function.
    """
    r = [line for line in region
         if "#pragma schedule " not in line and "#pragma tailcall " not in line]
    mode = rng.choice(("schedule", "schedule", "tailcall", "no_tailcall", "default"))
    if mode == "default":
        return r
    prefix = []
    suffix = []
    if mode == "schedule":
        prefix.append("#pragma schedule on")
        suffix.append("#pragma schedule off")
    elif mode == "tailcall":
        prefix.append("#pragma tailcall on")
        suffix.append("#pragma tailcall off")
    else:
        prefix.append("#pragma tailcall off")
        suffix.append("#pragma tailcall on")
    return r[:marker_idx_local + 1] + prefix + r[marker_idx_local + 1:] + suffix


def leading_decls(region, b0, b1):
    idxs = []
    for i in range(b0, b1):
        s = strip_line_comment(region[i])
        if not s.strip():
            if idxs:
                break
            continue
        if DECL_RE.match(s) and "=" not in s:
            idxs.append(i)
        else:
            break
    return idxs


def mut_decls(region, open_line_local, rng):
    b0, b1 = body_span(region, open_line_local)
    decls = leading_decls(region, b0, b1)
    if len(decls) < 2:
        return None
    out = region[:]
    if rng.random() < 0.5:
        i = rng.randrange(len(decls) - 1)
        a, b = decls[i], decls[i + 1]
        out[a], out[b] = out[b], out[a]
    else:
        vals = [out[i] for i in decls]
        rng.shuffle(vals)
        for i, v in zip(decls, vals):
            out[i] = v
    return out


def simple_stmt(line):
    s = strip_line_comment(line).strip()
    return (s.endswith(";") and "{" not in s and "}" not in s
            and not CTRL_RE.search(s) and not DECL_RE.match(s) and s != ";")


def mut_stmts(region, open_line_local, rng):
    b0, b1 = body_span(region, open_line_local)
    cand = [i for i in range(b0, b1)
            if simple_stmt(region[i]) and simple_stmt(region[i + 1] if i + 1 < b1 else "")]
    cand = [i for i in cand if i + 1 < b1 and simple_stmt(region[i + 1])]
    if not cand:
        return None
    i = rng.choice(cand)
    out = region[:]
    out[i], out[i + 1] = out[i + 1], out[i]
    return out


# An operand is an identifier (with optional field/subscript suffixes) OR a
# numeric literal. The P3 original required identifiers on BOTH sides, so it
# could never transpose `x + 4`; but `addiu`/`addu` operand order is exactly what
# several residuals in this repo come down to, and half of those have a literal
# on one side. Excluding literals left that whole class unreachable.
_COMMUTE_OPERAND = (r"(?:[A-Za-z_][\w]*(?:(?:\.|->)[A-Za-z_]\w*|\[[^\]]*\])*"
                    r"|0[xX][0-9a-fA-F]+|\d+)")
COMMUTE_RE = re.compile(
    r"(" + _COMMUTE_OPERAND + r")"
    r"\s*(\+|\*|&|\||\^|==|!=)\s*"
    r"(" + _COMMUTE_OPERAND + r")")


DECL_TYPES = {"s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64",
              "void", "char", "short", "int", "long", "float", "double", "signed",
              "unsigned", "const", "struct", "union", "enum", "register", "static"}


def is_declaration(line):
    """True for a local declaration, which must never be operand-swapped.

    `u8 *second;` matches the commutative-operand pattern with `*` read as a
    multiply, and swapping it yields `second * u8;`. That cannot compile, so it
    only burns an iteration -- but a declaration is not an expression and
    rewriting one is always wrong.
    """
    stripped = line.strip()
    if not stripped.endswith(";") or "=" in stripped:
        return False
    head = stripped[:-1].replace("*", " ").split()
    return len(head) >= 2 and head[0] in DECL_TYPES


def mut_operands(region, open_line_local, rng):
    b0, b1 = body_span(region, open_line_local)
    body_idxs = [i for i in range(b0, b1)
                 if COMMUTE_RE.search(region[i]) and not is_declaration(region[i])]
    if not body_idxs:
        return None
    i = rng.choice(body_idxs)
    matches = list(COMMUTE_RE.finditer(region[i]))
    m = rng.choice(matches)
    a, op, b = m.group(1), m.group(2), m.group(3)
    if a == b:
        return None
    out = region[:]
    out[i] = region[i][:m.start()] + f"{b} {op} {a}" + region[i][m.end():]
    return out


REASSOC_RE = re.compile(
    r"([A-Za-z_][\w.\->\[\]]*)\s*([+])\s*([A-Za-z_][\w.\->\[\]]*)\s*([+])\s*([A-Za-z_][\w.\->\[\]]*)")


def mut_reassoc(region, open_line_local, rng):
    b0, b1 = body_span(region, open_line_local)
    idxs = [i for i in range(b0, b1) if REASSOC_RE.search(region[i])]
    if not idxs:
        return None
    i = rng.choice(idxs)
    m = REASSOC_RE.search(region[i])
    a, op1, b, op2, c = m.groups()
    repl = f"{a} {op1} ({b} {op2} {c})" if rng.random() < 0.5 else f"({a} {op1} {b}) {op2} {c}"
    out = region[:]
    out[i] = region[i][:m.start()] + repl + region[i][m.end():]
    return out


CMP_RE = re.compile(r"(<=|>=|<|>)\s*(-?\d+)\b")


def mut_compare(region, open_line_local, rng):
    """Rewrite an integer relational bound to an equivalent form:
    `>= K` <-> `> K-1`, `<= K` <-> `< K+1`, changing slt/slti codegen."""
    b0, b1 = body_span(region, open_line_local)
    hits = []
    for i in range(b0, b1):
        for m in CMP_RE.finditer(region[i]):
            hits.append((i, m))
    if not hits:
        return None
    i, m = rng.choice(hits)
    op, k = m.group(1), int(m.group(2))
    alt = {">=": f"> {k - 1}", ">": f">= {k + 1}",
           "<=": f"< {k + 1}", "<": f"<= {k - 1}"}[op]
    out = region[:]
    out[i] = region[i][:m.start()] + alt + region[i][m.end():]
    return out


COMPOUND_RE = re.compile(
    r"^(\s*)([A-Za-z_][\w.\->\[\]]*)\s*(\+|\-|\*|&|\||\^|<<|>>)=\s*(.+);\s*$")


def mut_compound(region, open_line_local, rng):
    """Expand `x OP= y;` into `x = x OP (y);` (identical semantics, different
    codegen for the intermediate)."""
    b0, b1 = body_span(region, open_line_local)
    idxs = [i for i in range(b0, b1) if COMPOUND_RE.match(region[i])]
    if not idxs:
        return None
    i = rng.choice(idxs)
    ind, lhs, op, rhs = COMPOUND_RE.match(region[i]).groups()
    out = region[:]
    out[i] = f"{ind}{lhs} = {lhs} {op} ({rhs});"
    return out


PARAM_RE = re.compile(
    r"^\s*((?:const\s+|volatile\s+|unsigned\s+|signed\s+|struct\s+|union\s+|enum\s+)*"
    r"[A-Za-z_]\w*(?:\s*\*+|\s+))\s*([A-Za-z_]\w*)\s*$")


def parse_params(header):
    """Parse a function header's parameter list -> [(type, name)]. Bails (returns
    []) on anything with function-pointer / array params."""
    lp, rp = header.find("("), header.rfind(")")
    if lp < 0 or rp < lp:
        return []
    inner = header[lp + 1:rp].strip()
    if inner in ("", "void"):
        return []
    out = []
    for part in inner.split(","):
        if "(" in part or "[" in part:
            return []
        m = PARAM_RE.match(part)
        if not m:
            return []
        out.append((m.group(1).strip(), m.group(2)))
    return out


def mut_param_temp(region, open_line_local, rng, params):
    """Copy a parameter into a fresh local of its declared type and substitute a
    random subset of its uses -- a signature-typed regalloc lever."""
    if not params:
        return None
    typ, name = rng.choice(params)
    b0, b1 = body_span(region, open_line_local)
    wb = re.compile(r"\b" + re.escape(name) + r"\b")
    lines_with = [i for i in range(b0, b1) if wb.search(region[i])]
    if not lines_with:
        return None
    nn = name + "_p"
    out = region[:]
    flips = [0]

    def repl(_m):
        if rng.random() < 0.6:
            flips[0] += 1
            return nn
        return name
    for i in lines_with:
        out[i] = wb.sub(repl, out[i])
    if flips[0] == 0:
        i = lines_with[0]
        out[i] = wb.sub(nn, region[i], count=1)
    sep = "    " if not typ.endswith("*") else "    "
    out = out[:b0] + [f"{sep}{typ} {nn} = {name};"] + out[b0:]
    return out


ASSIGN_RE = re.compile(r"^(\s*)([A-Za-z_][\w.\->\[\]]*)\s*=\s*(.+);\s*$")


def _stmt_runs(region, b0, b1):
    """Maximal runs (>=2) of adjacent single-line simple statements."""
    runs, cur = [], []
    for i in range(b0, b1):
        if simple_stmt(region[i]):
            cur.append(i)
        else:
            if len(cur) >= 2:
                runs.append(cur)
            cur = []
    if len(cur) >= 2:
        runs.append(cur)
    return runs


def mut_reverse_run(region, open_line_local, rng):
    """Reverse a random slice of a run of adjacent simple statements. Reaches
    non-adjacent reorderings (e.g. x,y,z -> z,y,x) that single adjacent swaps
    cannot without crossing a worse-scoring intermediate."""
    b0, b1 = body_span(region, open_line_local)
    runs = _stmt_runs(region, b0, b1)
    if not runs:
        return None
    run = rng.choice(runs)
    if len(run) < 2:
        return None
    a = rng.randrange(len(run) - 1)
    b = rng.randrange(a + 1, len(run))
    idxs = run[a:b + 1]
    out = region[:]
    vals = [region[i] for i in idxs][::-1]
    for i, v in zip(idxs, vals):
        out[i] = v
    return out


def mut_chain_assign(region, open_line_local, rng):
    """Fuse `a = EXPR;` immediately followed by `b = a;` into `b = a = EXPR;`
    (stores the fresh value to both targets before it is only in a saved reg)."""
    b0, b1 = body_span(region, open_line_local)
    cands = []
    for i in range(b0, b1 - 1):
        m1 = ASSIGN_RE.match(region[i])
        m2 = ASSIGN_RE.match(region[i + 1])
        if m1 and m2 and m2.group(3).strip() == m1.group(2).strip():
            cands.append((i, m1, m2))
    if not cands:
        return None
    i, m1, m2 = rng.choice(cands)
    ind = m1.group(1)
    out = region[:]
    out[i] = f"{ind}{m2.group(2)} = {m1.group(2)} = {m1.group(3)};"
    del out[i + 1]
    return out


PTR_DECL_RE = re.compile(
    r"^(\s*)((?:const\s+|volatile\s+|struct\s+|union\s+)*[A-Za-z_]\w*\s*\*+)\s*([A-Za-z_]\w*)\s*;\s*$")
ARROW_RE = re.compile(r"\b([A-Za-z_]\w*)->")


def mut_ptr_copy(region, open_line_local, rng):
    """Rewrite one `p->...` use as `(p_c = p)->...` through a fresh twin local.
    The inline register copy flips commutative-addu operand order in indexed
    member accesses (permuter-proven: btlUnit 285fa0/286130)."""
    b0, b1 = body_span(region, open_line_local)
    decls = {}
    for i in leading_decls(region, b0, b1):
        m = PTR_DECL_RE.match(strip_line_comment(region[i]))
        if m:
            decls[m.group(3)] = (i, m.group(1), m.group(2))
    if not decls:
        return None
    cands = []
    for i in range(b0, b1):
        code = strip_line_comment(region[i])
        for m in ARROW_RE.finditer(code):
            if m.group(1) in decls and not code[:m.start()].rstrip().endswith(")"):
                cands.append((i, m.start(), m.group(1)))
    if not cands:
        return None
    i, pos, name = rng.choice(cands)
    di, ind, typ = decls[name]
    twin = name + "_c"
    out = region[:]
    line = out[i]
    out[i] = line[:pos] + f"({twin} = {name})" + line[pos + len(name):]
    out.insert(di + 1, f"{ind}{typ} {twin};")
    return out


MEMBER_CHAIN_RE = re.compile(
    r"\b([A-Za-z_]\w*(?:(?:->|\.)\w+|\[[^\][]*\])+)\.(\w+)\b(?!\s*[=([])")


def mut_comma_copy(region, open_line_local, rng):
    """Rewrite `chain.member` as `(0, chain).member`. The comma expression
    copies the aggregate before extracting the member, forcing a whole-word
    load and retail's load order (permuter-proven: scrTraceCode 35ebf0)."""
    b0, b1 = body_span(region, open_line_local)
    hits = []
    for i in range(b0, b1):
        code = strip_line_comment(region[i])
        for m in MEMBER_CHAIN_RE.finditer(code):
            after = code[m.end():].lstrip()
            if not after.startswith("=") or after.startswith("=="):
                hits.append((i, m))
    if not hits:
        return None
    i, m = rng.choice(hits)
    out = region[:]
    line = out[i]
    out[i] = line[:m.start()] + f"(0, {m.group(1)}).{m.group(2)}" + line[m.end():]
    return out


MUTATORS = [mut_opt, mut_schedule, mut_decls, mut_stmts, mut_operands,
            mut_reassoc, mut_compare, mut_compound, mut_reverse_run,
            mut_chain_assign, mut_ptr_copy, mut_comma_copy]


def _open_line(region, marker_idx_local):
    """Locate the function's opening-brace line in the current region (robust to
    pragma insertions that shift it relative to the base)."""
    j = marker_idx_local + 1
    while j < len(region) and "{" not in strip_line_comment(region[j]):
        j += 1
    return j


def mutate(region, marker_idx_local, open_line_local, rng, params):
    oll = _open_line(region, marker_idx_local)
    if params and rng.random() < 0.25:
        return mut_param_temp(region, oll, rng, params)
    m = rng.choice(MUTATORS)
    if m in (mut_opt, mut_schedule):
        return m(region, marker_idx_local, rng)
    return m(region, oll, rng)


# ------------------------------------------------------------------ search

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("function")
    ap.add_argument("--iters", type=int, default=3000)
    ap.add_argument("--time", type=float, default=0.0, help="stop after N seconds")
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", help="write best-found region here on improvement")
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21782_functions.json").read_text())
    # This repo's RetailElf validates against config/target.json as well as the
    # boundary map's sha1, so it takes the target dict the P3 version did not.
    target = json.loads((REPO / "config" / "target.json").read_text())
    if sizes.get("program") != "SLUS_217.82" or sizes.get("sha1") != target["elf"]["sha1"]:
        sys.exit("permute: slus21782_functions.json does not describe the configured target")
    retail = RetailElf(cfg["retail_elf"], target, sizes["sha1"])
    bounds = all_boundaries(sizes)

    cpath = Path(args.file).resolve()
    t = Target(cpath, args.function, bounds, cfg, retail)
    rng = random.Random(args.seed)

    marker_local = 0
    open_local = t.open_line - t.start

    base = strip_opt(t.region)
    base_open = open_local - sum(1 for l in t.region[:t.open_line - t.start]
                                 if "#pragma optimization_level" in l)
    base_score, base_match, log = t.score(base)
    print(f"[{args.function}] addr={t.addr:#010x} window={t.window} "
          f"base_score={base_score} match={base_match}", flush=True)
    if base_score >= 10 ** 6:
        print("base does not compile:\n" + log[:800])
        sys.exit(2)

    best = base
    best_score = base_score
    cur = base
    cur_score = base_score
    t0 = time.time()
    stale = 0
    hit = None

    for it in range(args.iters):
        if args.time and time.time() - t0 > args.time:
            break
        cand = mutate(cur, marker_local, base_open, rng, t.params)
        if cand is None or cand == cur:
            continue
        sc, match, _ = t.score(cand)
        if match:
            hit = cand
            print(f"[{args.function}] MATCH at iter {it} (compiles+ndiff0)", flush=True)
            break
        if sc < cur_score or (sc == cur_score and rng.random() < 0.3):
            cur, cur_score = cand, sc
            stale = 0
        else:
            stale += 1
        if sc < best_score:
            best, best_score = cand, sc
            print(f"[{args.function}] iter {it}: new best score {best_score} "
                  f"(compiles={t._n})", flush=True)
            if args.out:
                Path(args.out).write_text("\n".join(best) + "\n", newline="\n")
        if stale > 60:                    # restart from base with a kick
            cur, cur_score = base, base_score
            stale = 0

    if hit is not None:
        # Never default the sidecar next to the source: build.py and verify.py both
        # glob src/**/*.c, so a `foo.match.c` beside foo.c gets compiled as if it
        # were a translation unit and its duplicate symbols break the link. Write
        # under build/ instead, which is gitignored and not globbed.
        if args.out:
            outp = Path(args.out)
        else:
            outp = REPO / "build" / "permute" / f"{cpath.stem}.{args.function}.match.c"
            outp.parent.mkdir(parents=True, exist_ok=True)
        Path(outp).write_text("\n".join(hit) + "\n", newline="\n")
        print(f"[{args.function}] wrote matching region to {outp}")
        print("--- region ---")
        print("\n".join(hit))
        sys.exit(0)

    print(f"[{args.function}] no match. best_score={best_score} "
          f"after {t._n} compiles / {time.time()-t0:.0f}s", flush=True)
    kinds = t.residual(best)
    if kinds:
        parts = ", ".join(f"{c}x {k}" for k, c in kinds.most_common())
        print(f"[{args.function}] residual: {parts} -- see docs/matching.md "
              f"for lever/wall status of each class", flush=True)
    sys.exit(1)


if __name__ == "__main__":
    main()
