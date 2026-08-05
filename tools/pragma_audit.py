#!/usr/bin/env python3
"""Check that every #pragma the tree uses is one MWCCPS2 actually recognizes.

b210 accepts an unknown `#pragma` silently: no warning, no error, no effect. So a
typo like `#pragma scheduling off` for `#pragma schedule off` compiles clean and
does nothing, while `tools/decomp_lint.py` still demands a `measured` justification
for it and a floor note still credits it with holding a match together. Nothing in
the normal gate can see that.

`#pragma warn_illpragma on` turns the silence into a warning, so collecting every
distinct spelling into one throwaway translation unit checks the whole tree in a
single compile. Three things have to be right or the probe cries wolf:

  * Comments must be stripped first. Floor notes in this tree quote pragmas at the
    start of a line inside `/* ... */`, and a naive line regex reads those as real
    directives.
  * `#pragma alias A B` warns when A and B are not declared, so every identifier
    named by an alias is forward-declared in the probe.
  * `#pragma pop` warns without a matching `push`, so the probe brackets the whole
    list in one push/pop pair.

Anything still flagged is re-probed on its own before being reported, so a single
awkward spelling cannot mask the rest.

Usage:
  python tools/pragma_audit.py            # exits non-zero if any spelling is illegal
  python tools/pragma_audit.py --list     # also print every spelling and its use count
"""
from collections import Counter
from pathlib import Path
import argparse
import re
import subprocess
import sys
import tempfile

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))

PRAGMA_RE = re.compile(r"^\s*#pragma\s+(.+?)\s*$")
WARN_RE = re.compile(r"#\s+(\d+): #pragma (.+?)\n")
IDENT_RE = re.compile(r"[A-Za-z_]\w*")


def strip_comments(text):
    """Remove /* */ and // comments, preserving line structure.

    Line count is preserved so callers may still report line numbers, and string
    literals are respected so a `/*` inside one is not treated as an opener.
    """
    out = []
    i, n = 0, len(text)
    state = None          # None | 'block' | 'line' | '"' | "'"
    while i < n:
        c = text[i]
        nxt = text[i + 1] if i + 1 < n else ""
        if state is None:
            if c == "/" and nxt == "*":
                state, i = "block", i + 2
                continue
            if c == "/" and nxt == "/":
                state, i = "line", i + 2
                continue
            if c in '"\'':
                state = c
            out.append(c)
        elif state == "block":
            if c == "*" and nxt == "/":
                state, i = None, i + 2
                continue
            out.append("\n" if c == "\n" else " ")
        elif state == "line":
            if c == "\n":
                state = None
                out.append("\n")
            else:
                out.append(" ")
        else:                       # inside a string or char literal
            out.append(c)
            if c == "\\":
                if nxt:
                    out.append(nxt)
                    i += 2
                    continue
            elif c == state:
                state = None
        i += 1
    return "".join(out)


def collect(roots=("src", "include")):
    """Count every distinct pragma spelling under `roots`, ignoring comments."""
    seen = Counter()
    for root in roots:
        base = REPO / root
        if not base.is_dir():
            continue
        for path in sorted(base.rglob("*")):
            if path.suffix not in (".c", ".h") or not path.is_file():
                continue
            body = strip_comments(path.read_text(errors="replace"))
            for line in body.splitlines():
                m = PRAGMA_RE.match(line)
                if m:
                    seen[m.group(1).strip()] += 1
    return seen


def _probe_source(spellings):
    """Build a probe TU for `spellings`, with the scaffolding they need."""
    names = set()
    for s in spellings:
        parts = s.split()
        if parts and parts[0] in ("alias", "overload"):
            names.update(IDENT_RE.findall(" ".join(parts[1:])))
    src = ["#pragma warn_illpragma on"]
    src += [f"extern int {n};" for n in sorted(names)]
    src += ["#pragma push"]
    body_start = len(src)
    src += [f"#pragma {s}" for s in spellings]
    src += ["#pragma pop", "int pragma_audit_probe(int a) { return a + 1; }"]
    return "\n".join(src) + "\n", body_start


def _compile_probe(spellings, mwcc):
    """Return the subset of `spellings` b210 flagged, by line position."""
    if not spellings:
        return set()
    src, body_start = _probe_source(spellings)
    with tempfile.TemporaryDirectory() as td:
        cpath = Path(td) / "pragma_audit.c"
        cpath.write_text(src, newline="\n")
        proc = subprocess.run([mwcc, "-O2", "-Iinclude", "-c", str(cpath),
                               "-o", str(cpath.with_suffix(".o"))],
                              cwd=str(REPO), stdout=subprocess.PIPE,
                              stderr=subprocess.STDOUT, text=True)
    flagged = set()
    for m in WARN_RE.finditer(proc.stdout or ""):
        idx = int(m.group(1)) - 1 - body_start
        if 0 <= idx < len(spellings):
            flagged.add(spellings[idx])
        else:
            text = m.group(2).strip()
            if text in spellings:
                flagged.add(text)
    return flagged


def illegal(spellings, mwcc):
    """Return the spellings MWCCPS2 does not recognize.

    One batch compile finds candidates; each is then re-probed alone so an
    interaction between two spellings in the batch cannot produce a false report.
    """
    ordered = sorted(spellings)
    if not ordered:
        return []
    candidates = _compile_probe(ordered, mwcc)
    confirmed = [s for s in sorted(candidates) if _compile_probe([s], mwcc)]
    return confirmed


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--list", action="store_true")
    args = ap.parse_args()

    from verify import load_config
    mwcc = load_config()["mwcc"]
    seen = collect()
    bad = illegal(seen, mwcc)
    print(f"pragma_audit: {len(seen)} distinct spellings, {sum(seen.values())} uses")
    if args.list:
        for p, n in sorted(seen.items()):
            print(f"  {n:5}x  {p}")
    if bad:
        print("ILLEGAL (b210 ignores these silently):")
        for p in bad:
            print(f"  {p}   (used {seen[p]}x)")
        return 1
    print("all pragmas recognized by MWCCPS2")
    return 0


if __name__ == "__main__":
    sys.exit(main())
