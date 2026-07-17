#!/usr/bin/env python3
"""Source-honesty linter for the Persona 4 decompilation tree.

`verify.py` answers "do these bytes match retail?".  This answers the other
half: "is this source an honest decompilation, and is the tree structurally
sound?".  A function can be byte-perfect and still be a bad artifact -- built
out of compiler-steering pragmas or `volatile` on ordinary data.  Those are
exactly the defects this catches.

The compiler baseline is MWCCPS2 3.0.1 b210 invoked with `-O2`.  Anything
that steers codegen away from that baseline -- optimization_level 0/1/3,
`schedule off`, `opt_common_subs off`, `opt_loop_invariants` -- must be paid
for with a recorded measurement.  A redundant `#pragma optimization_level 2`
(which is the baseline already) is a warning.

Rules are grouped by prefix:

  H  source honesty     constructs that steer codegen instead of expressing
                        the program: `volatile` on non-hardware data, banned
                        optimization pragmas, dead stores, `register` locals
  M  marker hygiene     the `// FUN_xxxxxxxx` / `P4_UNIT_xxxxxxxx` contract
                        verify.py relies on
  P  pragma balance     on/off brackets that never close within a file

Severities are `error` (fails the run) and `warn`.

WAIVERS.  A finding is waived by a comment within three lines above the site
(marker lines are skipped when looking up) that either says `lint: allow CODE`
or contains the word `measured`.  A comment in the six lines above the nearest
enclosing `// FUN_xxxxxxxx` marker also waives every occurrence of the
construct in that function: the measurement behind an annotation is always
"removing this loses FUNCTION X", so one annotation covers the whole function.
An unannotated instance of the same construct is a finding, which is the
point: the rule is not "never use this", it is "never use this without paying
for it in measurement".

Usage:
    python tools/decomp_lint.py                     # lint src/ and include/
    python tools/decomp_lint.py src/Battle          # lint a subtree
    python tools/decomp_lint.py --errors-only       # errors only, exit 1 on any
    python tools/decomp_lint.py src/foo.c --json r.json
    python tools/decomp_lint.py --select H          # only honesty rules
    python tools/decomp_lint.py --ignore H003W      # drop the noisy warning
    python tools/decomp_lint.py --list              # describe every rule

Exit status is 1 if any `error` finding survives filtering, else 0.
`src/generated/` is never linted.
"""

import argparse
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Directories that are generated or otherwise not ours to police.
# `src/generated/` is raw m2c candidate output and is ALWAYS excluded.
DEFAULT_EXCLUDES = ("src/generated/",)

# PS2 hardware register windows.  `volatile` is legitimate here and nowhere
# else: EE core/peripheral MMIO, VU memory, GS privileged registers,
# scratchpad, and BIOS.
HARDWARE_RANGES = (
    (0x10000000, 0x10010000),   # EE peripherals: timers, DMAC, GIF, VIF, IPU
    (0x11000000, 0x11010000),   # VU0/VU1 micro and data memory
    (0x12000000, 0x12002000),   # GS privileged registers
    (0x1F800000, 0x1F810000),   # scratchpad / misc
    (0x1FC00000, 0x20000000),   # BIOS
    (0x70000000, 0x70004000),   # scratchpad mirror
)

RULES = {
    # ---- H: source honesty -------------------------------------------------
    "H001": ("error", "`volatile` on non-hardware data (compiler-steering, not a device access)"),
    "H003": ("error", "banned optimization pragma (optimization_level 0/1/3, schedule off, opt_common_subs off, opt_loop_invariants)"),
    "H003W": ("warn", "redundant `#pragma optimization_level 2` (that is the documented -O2 baseline)"),
    "H007": ("warn", "dead store: local is assigned once and never read"),
    "H008": ("error", "`register` storage class on an ordinary local"),
    # ---- M: marker hygiene -------------------------------------------------
    "M001": ("error", "marker hygiene: malformed FUN_ address, duplicate address in one file, or P4_UNIT guard that disagrees with the marker beneath it"),
    # ---- P: pragma balance -------------------------------------------------
    "P001": ("error", "unbalanced pragma on/off pairs within a file"),
}

SEVERITY_ORDER = {"info": 0, "warn": 1, "error": 2}

MARKER_RE = re.compile(r"^\s*//\s*(FUN_([0-9a-fA-F]{8}))(.*)$")
# Any `// FUN_...` line, including ones whose address part is malformed.
MARKER_LINE_RE = re.compile(r"^\s*//\s*FUN_([0-9a-fA-F]*)(.*)$")
# The guard verify.py uses to select one consolidated translation unit.
UNIT_GUARD_RE = re.compile(r"^\s*#if\s+defined\(P4_UNIT_([0-9a-fA-F]{8})\)\s*$")
IDENT_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")


# --------------------------------------------------------------- source prep

def sanitize(lines):
    """Blank out comments and string/char literals, preserving line layout.

    Every rule below matches against the sanitized text so that a banned
    construct quoted inside a comment or a string is not a finding.
    """
    out_lines = []
    state = "code"
    for line in lines:
        out = []
        i = 0
        while i < len(line):
            ch = line[i]
            nxt = line[i + 1] if i + 1 < len(line) else ""
            if state == "block":
                if ch == "*" and nxt == "/":
                    out.extend("  ")
                    i += 2
                    state = "code"
                else:
                    out.append(" ")
                    i += 1
            elif state in ("str", "chr"):
                quote = '"' if state == "str" else "'"
                if ch == "\\":
                    out.extend("  ")
                    i += 2
                    continue
                out.append(" ")
                i += 1
                if ch == quote:
                    state = "code"
            else:
                if ch == "/" and nxt == "*":
                    out.extend("  ")
                    i += 2
                    state = "block"
                elif ch == "/" and nxt == "/":
                    out.extend(" " * (len(line) - i))
                    break
                elif ch == '"':
                    out.append(" ")
                    i += 1
                    state = "str"
                elif ch == "'":
                    out.append(" ")
                    i += 1
                    state = "chr"
                else:
                    out.append(ch)
                    i += 1
        out_lines.append("".join(out))
    return out_lines


class Source:
    """One .c/.h file, with the derived views every rule needs."""

    def __init__(self, path, raw):
        self.path = path
        self.raw = raw
        text = raw.decode("utf-8", errors="replace")
        self.crlf = raw.count(b"\r\n")
        self.lf = raw.count(b"\n") - self.crlf
        self.lines = text.replace("\r\n", "\n").split("\n")
        self.code = sanitize(self.lines)

    def rel(self):
        try:
            return self.path.relative_to(ROOT).as_posix()
        except ValueError:
            return self.path.as_posix()


class Finding:
    __slots__ = ("code", "severity", "file", "line", "message", "text")

    def __init__(self, code, file, line, message, text=""):
        self.code = code
        self.severity = RULES[code][0]
        self.file = file
        self.line = line
        self.message = message
        self.text = text

    def as_dict(self):
        return dict(code=self.code, severity=self.severity, file=self.file,
                    line=self.line, message=self.message, text=self.text)


# ------------------------------------------------------------------- waivers

# Codes are `H001`...`P001`; H003W carries an extra suffix letter.
WAIVER_ALLOW_RE = re.compile(r"lint:\s*allow\s+([A-Z]\d{3}[A-Z]?)")


def waived(src, idx, code):
    """True if the site on line `idx` (0-based) carries a justification.

    Three scopes are honoured:

    * INLINE scope -- a comment on the site line itself, e.g.
      `*(volatile /* measured: see FUN_001EC630 */ f32*)&x`.
    * SITE scope -- a comment within three lines above the site.
    * FUNCTION scope -- a comment in the six lines above the nearest
      enclosing `// FUN_xxxxxxxx` marker.  The measurement behind an
      annotation is always "removing this loses FUNCTION X", so one
      annotation covers every occurrence of the construct in that function.

    A justification is either an explicit `lint: allow CODE` or a comment
    containing `measured`, the tree's convention for recording a retained
    construct's measured removal cost.
    """
    line = src.lines[idx]
    m = WAIVER_ALLOW_RE.search(line)
    if m and m.group(1) == code and WAIVER_ALLOW_RE.search(src.code[idx]) is None:
        return True
    # `measured` counts only inside a comment: present in the raw line but
    # blanked out of the sanitized view.
    if "measured" in line and "measured" not in src.code[idx]:
        return True
    if _scan_waiver(src, idx, code, 3):
        return True
    marker = _enclosing_marker(src, idx)
    return marker is not None and _scan_waiver(src, marker, code, 6)


def _scan_waiver(src, idx, code, depth):
    checked = 0
    j = idx
    while j > 0 and checked < depth:
        j -= 1
        line = src.lines[j]
        stripped = line.strip()
        if not stripped:
            continue
        if MARKER_RE.match(line):
            continue  # annotations sit above the marker, the site below it
        m = WAIVER_ALLOW_RE.search(line)
        if m:
            return m.group(1) == code
        # `measured` counts only inside a comment.  The sanitized view blanks
        # comment text, so presence in `lines` but absence in `code` proves it.
        if "measured" in line and "measured" not in src.code[j]:
            return True
        checked += 1
        is_comment = (stripped.startswith("/*") or stripped.startswith("//")
                      or stripped.startswith("*") or stripped.endswith("*/")
                      or not src.code[j].strip())
        if not (is_comment or stripped.startswith("#")):
            break
    return False


def _enclosing_marker(src, idx):
    """Index of the nearest `// FUN_` marker at or above `idx`, else None."""
    for j in range(idx, max(-1, idx - 600), -1):
        if MARKER_RE.match(src.lines[j]):
            return j
    return None


# --------------------------------------------------------------------- rules
# Each rule is `def check_xxx(src) -> iterable[Finding]`.

VOLATILE_RE = re.compile(r"\bvolatile\b")
HEX_RE = re.compile(r"0[xX]([0-9a-fA-F]{6,8})")


def _is_hardware_line(line):
    for m in HEX_RE.finditer(line):
        v = int(m.group(1), 16)
        for lo, hi in HARDWARE_RANGES:
            if lo <= v < hi:
                return True
    return False


def check_volatile(src):
    for i, line in enumerate(src.code):
        if not VOLATILE_RE.search(line):
            continue
        if re.search(r"\basm\b", line):
            continue  # asm volatile is out of scope for this rule
        if _is_hardware_line(line):
            continue
        if waived(src, i, "H001"):
            continue
        yield Finding("H001", src.rel(), i + 1,
                      "volatile on data with no hardware address in scope",
                      src.lines[i].strip())


# Steering pragmas that deviate from the documented -O2 baseline.  Note that
# opt_loop_invariants is banned in BOTH directions: `on` and `off` both
# deviate from the default state, and retail builds were made with the
# default.
BANNED_PRAGMA_RE = re.compile(
    r"#\s*pragma\s+(optimization_level\s+[013]\b"
    r"|schedule\s+off\b"
    r"|opt_common_subs\s+off\b"
    r"|opt_loop_invariants\s+(?:on|off)\b)")
REDUNDANT_PRAGMA_RE = re.compile(r"#\s*pragma\s+optimization_level\s+2\b")


def check_banned_pragma(src):
    for i, line in enumerate(src.code):
        m = BANNED_PRAGMA_RE.search(line)
        if m:
            if not waived(src, i, "H003"):
                yield Finding("H003", src.rel(), i + 1,
                              f"banned pragma `{m.group(1).strip()}` with no measured justification",
                              src.lines[i].strip())
            continue
        if REDUNDANT_PRAGMA_RE.search(line):
            if not waived(src, i, "H003W"):
                yield Finding("H003W", src.rel(), i + 1,
                              "redundant `#pragma optimization_level 2`; -O2 is already the baseline",
                              src.lines[i].strip())


# ------------------------------------------------------- function extraction

DECL_RE = re.compile(
    r"^\s*(?:const\s+|static\s+|volatile\s+|unsigned\s+|signed\s+)*"
    r"([A-Za-z_][A-Za-z0-9_]*)\s+(\**)\s*([A-Za-z_][A-Za-z0-9_]*)\s*"
    r"(?:\[[^\]]*\])*\s*;\s*$")

CONTROL_KEYWORDS = {
    "if", "else", "for", "while", "do", "switch", "case", "default", "return",
    "break", "continue", "goto", "sizeof", "struct", "union", "enum", "typedef",
}


def iter_functions(src):
    """Yield (start_idx, end_idx) for each top-level `{...}` function body."""
    depth = 0
    start = None
    for i, line in enumerate(src.code):
        if re.match(r"\s*#", line):
            continue
        opens = line.count("{")
        closes = line.count("}")
        if depth == 0 and opens:
            start = i
        depth += opens - closes
        if start is not None and depth <= 0 and (opens or closes):
            yield start, i
            start = None
            depth = 0


def check_dead_store(src):
    """A local declared, assigned exactly once, and never read.

    Two very different defects produce this shape, and both matter:

    * WINDOW FILL -- a store added only so the instructions exist.  Banned.
    * A SILENTLY ELIMINATED STORE -- the decompiler emitted separate stack
      scalars where the original had one aggregate whose address was taken.
      Only the addressed member survives; MWCC dead-store-eliminates the
      rest, so the function compiles UNDERSIZED against its retail window.

    Either way the store is not doing what the source claims.  Anything read
    anywhere, or whose address is taken, is left alone.
    """
    for start, end in iter_functions(src):
        body = src.code[start:end + 1]
        decls = {}
        for off, line in enumerate(body):
            m = DECL_RE.match(line)
            if not m:
                continue
            base, stars, name = m.group(1), m.group(2), m.group(3)
            if base in CONTROL_KEYWORDS or name in CONTROL_KEYWORDS:
                continue
            if "volatile" in line:
                continue  # H001 owns that; do not double-report
            decls[name] = off
        if not decls:
            continue
        counts = Counter()
        for line in body:
            for tok in IDENT_RE.findall(line):
                counts[tok] += 1
        for name, off in decls.items():
            if counts[name] != 2:
                continue
            # Locate the single non-declaration mention and require it to be a
            # plain assignment target.
            hits = [k for k, l in enumerate(body)
                    if k != off and re.search(r"\b" + re.escape(name) + r"\b", l)]
            if len(hits) != 1:
                continue
            use = body[hits[0]]
            if not re.match(r"\s*" + re.escape(name) + r"\s*(?:=[^=]|\+=|-=|\*=|/=)", use):
                continue
            if "&" + name in use.replace(" ", ""):
                continue
            idx = start + hits[0]
            if waived(src, idx, "H007"):
                continue
            yield Finding("H007", src.rel(), idx + 1,
                          f"`{name}` is assigned here and never read",
                          src.lines[idx].strip())


REGISTER_RE = re.compile(r"(?:^|[{};])\s*register\s+[A-Za-z_]")


def check_register_local(src):
    for i, line in enumerate(src.code):
        if not REGISTER_RE.search(line):
            continue
        if waived(src, i, "H008"):
            continue
        yield Finding("H008", src.rel(), i + 1,
                      "`register` on an ordinary local is a codegen hint, not a decompilation",
                      src.lines[i].strip())


# ------------------------------------------------------------ marker hygiene

def check_markers(src):
    """M001: malformed addresses, duplicates within one file, guard mismatch.

    The contract verify.py relies on: every tracked function carries a
    `// FUN_<8 hex digits>` marker, no address appears twice in one file, and
    every `#if defined(P4_UNIT_xxxxxxxx)` guard contains a marker for exactly
    that address as its first function.
    """
    markers = []          # (idx, addr)
    seen = defaultdict(list)
    for i, line in enumerate(src.lines):
        m = MARKER_LINE_RE.match(line)
        if not m:
            continue
        hexpart = m.group(1)
        if len(hexpart) != 8:
            yield Finding("M001", src.rel(), i + 1,
                          f"malformed marker address `FUN_{hexpart}` "
                          f"({len(hexpart)} hex digits, expected 8)",
                          src.lines[i].strip())
            continue
        addr = hexpart.lower()
        markers.append((i, addr))
        seen[addr].append(i + 1)
    for addr, lines in seen.items():
        if len(lines) > 1:
            yield Finding("M001", src.rel(), lines[0],
                          f"marker FUN_{addr} appears {len(lines)} times "
                          f"(lines {', '.join(map(str, lines))})")
    for i, line in enumerate(src.lines):
        g = UNIT_GUARD_RE.match(line)
        if not g:
            continue
        guard_addr = g.group(1).lower()
        end = next((c for c in range(i + 1, len(src.lines))
                    if re.match(r"^\s*#endif\b", src.lines[c])), None)
        body = src.lines[i + 1:end]
        first = next((MARKER_RE.match(l) for l in body if MARKER_RE.match(l)), None)
        if first is None:
            yield Finding("M001", src.rel(), i + 1,
                          f"P4_UNIT_{guard_addr} guard has no FUN_ marker beneath it",
                          src.lines[i].strip())
        elif first.group(2).lower() != guard_addr:
            yield Finding("M001", src.rel(), i + 1,
                          f"P4_UNIT_{guard_addr} guard disagrees with the marker "
                          f"FUN_{first.group(2)} beneath it",
                          src.lines[i].strip())


# ------------------------------------------------------------ pragma balance

ONOFF_RE = re.compile(r"#\s*pragma\s+([A-Za-z_][A-Za-z0-9_]*)\s+(on|off)\b")
PUSH_RE = re.compile(r"#\s*pragma\s+push\b")
POP_RE = re.compile(r"#\s*pragma\s+pop\b")

# Pragmas whose on/off is a genuine mode switch, not a bracket.
ONOFF_EXEMPT = {"once"}


def check_pragma_balance(src):
    """P001: on/off brackets that never close within the file.

    `#pragma push` saves the whole pragma state and `#pragma pop` restores it,
    so an `on`/`off` switched inside a push/pop bracket is NOT an imbalance --
    the pop undoes it.  Only state that differs from the file's starting state
    at EOF leaks into whatever includes or follows this translation unit.
    """
    push = pop = 0
    first_unmatched_pop = None
    stack = []
    bal = defaultdict(int)      # +1 per `on`, -1 per `off`; zero == restored
    firstline = {}
    for i, line in enumerate(src.code):
        if PUSH_RE.search(line):
            push += 1
            stack.append(dict(bal))
            continue
        if POP_RE.search(line):
            pop += 1
            if stack:
                bal = defaultdict(int, stack.pop())
            elif first_unmatched_pop is None:
                first_unmatched_pop = i + 1
            continue
        m = ONOFF_RE.search(line)
        if not m:
            continue
        name, mode = m.group(1), m.group(2)
        if name in ONOFF_EXEMPT:
            continue
        bal[name] += 1 if mode == "on" else -1
        firstline.setdefault(name, i + 1)

    if push != pop:
        yield Finding("P001", src.rel(), first_unmatched_pop or 1,
                      f"#pragma push/pop unbalanced: {push} push, {pop} pop")
    for name, n in sorted(bal.items()):
        if n == 0:
            continue
        left = "off" if n < 0 else "on"
        yield Finding("P001", src.rel(), firstline[name],
                      f"pragma `{name}` is left `{left}` at end of file "
                      f"({abs(n)} unmatched on/off pair(s))")


CHECKS = (
    check_volatile,
    check_banned_pragma,
    check_dead_store,
    check_register_local,
    check_markers,
    check_pragma_balance,
)


def lint_source(src):
    out = []
    for check in CHECKS:
        out.extend(check(src))
    out.sort(key=lambda f: (f.line, f.code))
    return out


# ----------------------------------------------------------------------- CLI

def gather(paths, excludes):
    files = []
    for p in paths:
        p = Path(p)
        if p.is_dir():
            files.extend(sorted(p.rglob("*.c")) + sorted(p.rglob("*.h")))
        elif p.exists():
            files.append(p)
        else:
            sys.stderr.write(f"decomp_lint: no such path: {p}\n")
    out = []
    for f in files:
        try:
            rel = f.resolve().relative_to(ROOT).as_posix()
        except ValueError:
            rel = f.as_posix()
        if any(rel.startswith(x) or rel == x.rstrip("/") for x in excludes):
            continue
        out.append(f)
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(
        description=__doc__.splitlines()[0],
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("paths", nargs="*", help="files or directories (default: src include)")
    ap.add_argument("--errors-only", action="store_true",
                    help="report only error-severity findings (suppress warnings)")
    ap.add_argument("--json", metavar="OUT", help="write findings as JSON")
    ap.add_argument("--select", help="comma-separated codes or prefixes to keep")
    ap.add_argument("--ignore", help="comma-separated codes or prefixes to drop")
    ap.add_argument("--summary", action="store_true", help="counts only, no per-finding lines")
    ap.add_argument("--exclude", action="append", default=[],
                    help="extra path prefix to skip (repeatable)")
    ap.add_argument("--list", action="store_true", help="describe every rule and exit")
    args = ap.parse_args(argv)

    if args.list:
        for code in sorted(RULES):
            sev, desc = RULES[code]
            print(f"{code}  {sev:<5}  {desc}")
        return 0

    paths = args.paths or [ROOT / "src", ROOT / "include"]
    excludes = list(args.exclude) + list(DEFAULT_EXCLUDES)

    def keep(code):
        if args.select:
            if not any(code.startswith(s.strip()) for s in args.select.split(",") if s.strip()):
                return False
        if args.ignore:
            if any(code.startswith(s.strip()) for s in args.ignore.split(",") if s.strip()):
                return False
        if args.errors_only and RULES[code][0] != "error":
            return False
        return True

    files = gather(paths, excludes)
    findings = []
    for f in files:
        try:
            src = Source(f, f.read_bytes())
        except OSError as exc:
            sys.stderr.write(f"decomp_lint: cannot read {f}: {exc}\n")
            continue
        findings.extend(x for x in lint_source(src) if keep(x.code))

    by_code = Counter(f.code for f in findings)
    by_sev = Counter(f.severity for f in findings)

    if not args.summary:
        for f in sorted(findings, key=lambda x: (x.file, x.line, x.code)):
            print(f"{f.file}:{f.line}: {f.severity}: [{f.code}] {f.message}")
            if f.text:
                print(f"    {f.text}")

    print(f"\ndecomp_lint: {len(files)} files, {len(findings)} findings "
          f"({by_sev['error']} error, {by_sev['warn']} warn)")
    for code, n in sorted(by_code.items()):
        print(f"  {code}  {RULES[code][0]:<5} {n:>7}  {RULES[code][1]}")

    if args.json:
        Path(args.json).write_text(json.dumps(dict(
            files=len(files),
            summary_by_code={c: n for c, n in sorted(by_code.items())},
            summary_by_severity=dict(by_sev),
            rules={c: dict(severity=s, description=d) for c, (s, d) in RULES.items()},
            findings=[f.as_dict() for f in findings]), indent=1))
        print(f"report: {args.json}")

    return 1 if by_sev["error"] else 0


if __name__ == "__main__":
    sys.exit(main())
