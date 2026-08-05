#!/usr/bin/env python3
"""Minimize a permuter hit down to committable C.

`tools/permute_ast.py` reaches byte-exact by throwing decomp-permuter's whole
randomizer at a function, and its winning source is unusable: uninitialized
reads, `if (1) {}` blocks, comma operators, self-assignments, `x & 0xFFFFFFFFu`
no-ops, and dozens of dead temps. Reducing that by hand does not work -- measured
on scrScriptProcess func_0029d1c0, where three independent seeds all won and
every hand-extracted candidate fell back to MISMATCH, because the essential
change is entangled with the noise rather than being one line of it.

This does the reduction mechanically. It reuses permute.py's Target, so scoring
is the same mwccps2 compile and the same reloc-masked comparison verify.py uses,
then greedily applies one candidate simplification at a time and keeps it only
while the score stays 0. What survives is a byte-exact body with every mutation
removed that was not load-bearing -- which is exactly the "extract the essential
change" step the permuter's own output tells you to do.

The function must already be LIVE in the file and byte-exact (score 0); point it
at a `--out` region spliced in, not at an `#ifdef NON_MATCHING` body.

Passes, cheapest first:
  * drop a whole statement line
  * drop an unused declaration
  * `(0, X)` -> `X`;  `X & 0xFFFFFFFF...u` -> `X`;  `(void *) 0` -> `NULL`
  * `if (1) { }` / `if (x) { }` / `do { } while (0...)` empty blocks -> nothing
  * collapse a temp assigned once and read once into its use
  * rename `new_varN` to something a human would write (last, cosmetic only)

Usage:
  python tools/permute_min.py src/Script/scrScriptProcess.c func_0029d1c0
  python tools/permute_min.py <file.c> <func> [--rounds N] [--out FILE]
"""
from pathlib import Path
import argparse
import json
import re
import sys

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))
import permute as P  # noqa: E402
from verify import RetailElf, load_config  # noqa: E402

DECL_RE = re.compile(r"^\s*(?:const\s+)?(?:unsigned\s+|signed\s+)?"
                     r"(?:[A-Za-z_]\w*)\s+\**\s*([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*;\s*$")
EMPTY_IF_RE = re.compile(r"^\s*if\s*\(.*\)\s*\{?\s*$")
COMMA_RE = re.compile(r"\(\s*0\s*,\s*")
MASK_RE = re.compile(r"\s*&\s*0[xX][fF]{8,16}[uU]?\b")
NULLCAST_RE = re.compile(r"\(\s*(?:void|char|u8)\s*\*\s*\)\s*\(?\s*(?:\(\s*long\s*\)\s*)?0\s*\)?")


def brace_depth(lines, upto):
    d = 0
    for l in lines[:upto]:
        d += l.count("{") - l.count("}")
    return d


def empty_block_span(region, i):
    """If line i opens a block whose body is empty, return the span to delete."""
    if not EMPTY_IF_RE.match(region[i]) and not region[i].strip().startswith("do"):
        return None
    j = i
    if region[i].rstrip().endswith("{"):
        pass
    elif j + 1 < len(region) and region[j + 1].strip() == "{":
        j += 1
    else:
        return None
    k = j + 1
    while k < len(region) and not region[k].strip():
        k += 1
    if k < len(region) and region[k].strip() == "}":
        # a `do { } while (...)` carries its condition on the closing line
        if k + 1 < len(region) and region[k + 1].strip().startswith("while"):
            return (i, k + 1)
        return (i, k)
    return None


def split_statements(region, b0, b1):
    """Yield candidates that put one statement per line.

    Purely cosmetic, but load-bearing for this tool: the randomizer packs several
    statements and whole braced blocks onto a single line, and every other pass
    here works line-at-a-time, so nothing can reach them until they are split.
    """
    for i in range(b0, b1):
        line = region[i]
        stripped = line.strip()
        if stripped.startswith(("#", "//", "/*")) or '"' in line or "'" in line:
            continue
        if "for" in stripped:
            continue          # a for-header's semicolons are not statement breaks
        pieces, depth, buf = [], 0, ""
        for ch in line:
            buf += ch
            if ch in "{(":
                depth += 1
            elif ch in "})":
                depth -= 1
                if depth == 0 and ch == "}" and buf.strip():
                    pieces.append(buf.strip())
                    buf = ""
            elif ch == ";" and depth == 0:
                pieces.append(buf.strip())
                buf = ""
        if buf.strip():
            pieces.append(buf.strip())
        pieces = [p for p in pieces if p and p != ";"]
        if len(pieces) < 2:
            continue
        indent = line[:len(line) - len(line.lstrip())] or "    "
        yield ("split line", region[:i] + [indent + p for p in pieces] + region[i + 1:])


def candidates(region, open_line):
    """Yield (label, new_region) simplifications, cheapest and safest first."""
    b0, b1 = P.body_span(region, open_line)
    # Splitting first is what lets every later pass see packed statements at all.
    for cand in split_statements(region, b0, b1):
        yield cand
    for i in range(b0, b1):
        span = empty_block_span(region, i)
        if span:
            lo, hi = span
            yield ("drop empty block", region[:lo] + region[hi + 1:])
    for i in range(b0, b1):
        s = region[i].strip()
        if not s or s == "{" or s == "}" or s.startswith(("if", "else", "while", "do", "for",
                                                          "return", "#", "//", "/*", "goto",
                                                          "switch", "case", "default")):
            continue
        if s.endswith(("{", ":")) or "}" in s:
            continue
        if brace_depth(region, i) != brace_depth(region, b0):
            continue          # only touch top-level statements, never inside a block
        yield ("drop statement", region[:i] + region[i + 1:])
    for i in range(open_line + 1, b1):
        m = DECL_RE.match(region[i])
        if not m:
            continue
        name = m.group(1)
        uses = sum(len(re.findall(r"\b" + re.escape(name) + r"\b", l))
                   for k, l in enumerate(region) if k != i)
        if uses == 0:
            yield ("drop unused decl " + name, region[:i] + region[i + 1:])
    for i in range(b0, b1):
        for label, rx, rep in (("comma", COMMA_RE, "("),
                               ("no-op mask", MASK_RE, ""),
                               ("null cast", NULLCAST_RE, "NULL")):
            if rx.search(region[i]):
                out = region[:]
                out[i] = rx.sub(rep, region[i])
                yield (label, out)
    for cand in inline_single_use_temps(region, b0, b1):
        yield cand
    for cand in noise_rewrites(region, b0, b1):
        yield cand
    for cand in dead_temp_assignments(region, b0, b1):
        yield cand


SIMPLE_ASSIGN_RE = re.compile(r"^(\s*)([A-Za-z_]\w*)\s*=\s*(.+);\s*$")
ADDR_DEREF_RE = re.compile(r"\*\s*\(\s*&\s*([A-Za-z_]\w*)\s*\)")
EMBEDDED_ASSIGN_RE = re.compile(r"\(\s*((?:new_var|temp_|var_)\w*)\s*=\s*")
PAREN_NUM_RE = re.compile(r"\(\s*\(\s*(\d+|0[xX][0-9a-fA-F]+)\s*\)\s*\)")


def noise_rewrites(region, b0, b1):
    """Yield in-line rewrites that cannot change meaning, at any brace depth.

    These are the residue the permuter leaves that dropping whole lines cannot
    reach: `*(&x)` for `x`, an assignment buried inside an expression, and
    doubled parens around a literal.
    """
    for i in range(b0, b1):
        line = region[i]
        if ADDR_DEREF_RE.search(line):
            out = region[:]
            out[i] = ADDR_DEREF_RE.sub(r"\1", line)
            yield ("deref-of-addr", out)
        m = EMBEDDED_ASSIGN_RE.search(line)
        if m:
            name = m.group(1)
            # Only safe when the temp is not read anywhere else: the assignment is
            # then pure bookkeeping and the value flows on regardless.
            elsewhere = sum(1 for k, l in enumerate(region)
                            if k != i and not DECL_RE.match(l)
                            and re.search(r"\b" + re.escape(name) + r"\b", l))
            if elsewhere == 0:
                out = region[:]
                out[i] = line[:m.start()] + "(" + line[m.end():]
                out = [l for k, l in enumerate(out)
                       if not (DECL_RE.match(l) and DECL_RE.match(l).group(1) == name)]
                yield ("unbury assign " + name, out)
        if PAREN_NUM_RE.search(line):
            out = region[:]
            out[i] = PAREN_NUM_RE.sub(r"(\1)", line)
            yield ("un-double parens", out)


def dead_temp_assignments(region, b0, b1):
    """Yield candidates dropping a whole-line assignment to a tool temp.

    Unlike the general statement pass this works at ANY brace depth, because a
    simple assignment to a compiler-invented name carries no control flow: if the
    score still says 0 the store was dead.
    """
    for i in range(b0, b1):
        m = SIMPLE_ASSIGN_RE.match(region[i])
        if not m:
            continue
        name = m.group(2)
        if not name.startswith(("new_var", "temp_", "var_")):
            continue
        if "(" in m.group(3) and re.search(r"\w\s*\(", m.group(3)):
            continue          # right-hand side calls something; dropping it would
                              # remove the call, not just the store
        yield ("drop dead store " + name, region[:i] + region[i + 1:])


def inline_single_use_temps(region, b0, b1):
    """Yield candidates that fold `t = EXPR;` into the one place `t` is read.

    This is the pass that matters on permuter output: the randomizer's signature
    move is a chain of `new_varN` temps, each assigned once and read once, and no
    amount of dropping whole lines removes them.
    """
    for i in range(b0, b1):
        m = SIMPLE_ASSIGN_RE.match(region[i])
        if not m:
            continue
        _indent, name, expr = m.groups()
        if not name.startswith(("new_var", "temp_", "var_")):
            continue          # only fold names the tools invented, never a real one
        if re.search(r"\b" + re.escape(name) + r"\b", expr):
            continue          # self-referential, folding would change meaning
        # The declaration is not a read. Counting it was a bug that made this pass
        # silently yield nothing, which looked like "every temp is load-bearing".
        decl = next((k for k, l in enumerate(region)
                     if DECL_RE.match(l) and DECL_RE.match(l).group(1) == name), None)
        reads = [(k, len(re.findall(r"\b" + re.escape(name) + r"\b", l)))
                 for k, l in enumerate(region)
                 if k != i and k != decl and re.search(r"\b" + re.escape(name) + r"\b", l)]
        # Exactly one read. A second assignment means the temp is genuinely live and
        # folding it would change the program.
        if len(reads) != 1 or reads[0][1] != 1:
            continue
        k = reads[0][0]
        second = SIMPLE_ASSIGN_RE.match(region[k])
        if second and second.group(2) == name:
            continue
        out = region[:]
        out[k] = re.sub(r"\b" + re.escape(name) + r"\b", "(" + expr + ")", out[k])
        for gone in sorted([x for x in (i, decl) if x is not None], reverse=True):
            del out[gone]
        yield ("inline " + name, out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("function")
    ap.add_argument("--rounds", type=int, default=8)
    ap.add_argument("--out", help="write the minimized region here")
    args = ap.parse_args()

    cfg = load_config()
    sizes = json.loads((TOOLS / "slus21782_functions.json").read_text())
    target_cfg = json.loads((REPO / "config" / "target.json").read_text())
    if sizes.get("sha1") != target_cfg["elf"]["sha1"]:
        sys.exit("permute_min: boundary map does not describe the configured target")
    retail = RetailElf(cfg["retail_elf"], target_cfg, sizes["sha1"])
    bounds = P.all_boundaries(sizes)
    t = P.Target(Path(args.file), args.function, bounds, cfg, retail)

    score, match, log = t.score(t.region)
    print(f"[{args.function}] starting score={score} match={match}")
    if score != 0:
        sys.exit(f"permute_min: the live body must already be byte-exact "
                 f"(score {score}); splice a permuter --out region in first")

    region = t.region[:]
    # Target stores file-absolute indices; every permute.py helper that takes a
    # region wants an index LOCAL to that region.
    open_local = t.open_line - t.start
    # Passes that rewrite in place (or deliberately grow, like `split line`) never
    # reduce the line count, so gating purely on "must be shorter" silently
    # disabled them. Name them instead.
    NON_SHRINKING = {"comma", "no-op mask", "null cast", "deref-of-addr",
                     "un-double parens", "split line"}
    applied = set()
    for rnd in range(args.rounds):
        improved = False
        for label, cand in candidates(region, open_local):
            if len(cand) >= len(region) and label not in NON_SHRINKING:
                continue
            key = (label, "\n".join(cand))
            if key in applied:
                continue          # an in-place rewrite that already lost; do not requeue
            s, m, _ = t.score(cand)
            applied.add(key)
            if s == 0:
                print(f"  round {rnd}: {label}  ({len(region)} -> {len(cand)} lines)")
                region = cand
                improved = True
                break
        if not improved:
            break
    print(f"[{args.function}] minimized to {len(region)} lines "
          f"from {len(t.region)} in {t._n} compiles")
    out = Path(args.out) if args.out else REPO / "build" / "permute" / \
        f"{Path(args.file).stem}.{args.function}.min.c"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text("\n".join(region) + "\n", newline="\n")
    print(f"wrote {out}")
    print("--- minimized region ---")
    print("\n".join(region))
    print("\nRe-confirm with tools/verify.py, and read it: minimal is not the same "
          "as honest. Anything left that a human would not write (dead blocks, "
          "uninitialized reads) means the function is still not committable.")


if __name__ == "__main__":
    main()
