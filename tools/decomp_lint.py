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
                        optimization pragmas, dead stores, `register` locals,
                        inline asm that forces codegen for ordinary computation
  M  marker hygiene     the `// FUN_xxxxxxxx` marker contract
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

The tree is split like verify.py splits it: first-party code is what this
project wrote and polices; third-party middleware (RenderWare under `rw/`,
CRI under `cri/`, the Sony SDK under `sce/`, and the C runtime files) is
retail-tracked but nobody's to restyle.  By default only first-party sources
are linted; `--include-third-party` scans everything and reports both
populations separately in the summary.  The exit status is always driven by
FIRST-PARTY `error` findings alone, so the tool can gate CI honestly no
matter how much middleware noise is present.

Usage:
    python tools/decomp_lint.py                     # lint first-party src/ and include/
    python tools/decomp_lint.py --include-third-party   # also lint rw/ cri/ sce/ + C runtime
    python tools/decomp_lint.py src/Battle          # lint a subtree
    python tools/decomp_lint.py --errors-only       # errors only, exit 1 on any first-party error
    python tools/decomp_lint.py src/foo.c --json r.json
    python tools/decomp_lint.py --select H          # only honesty rules
    python tools/decomp_lint.py --ignore H003W      # drop the noisy warning
    python tools/decomp_lint.py --list              # describe every rule

Exit status is 1 if any first-party `error` finding survives filtering,
else 0.  Third-party findings (visible with `--include-third-party`) never
fail the run.  `src/generated/` is never linted.
"""

import argparse
import importlib.util
import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Directories that are generated or otherwise not ours to police.
# `src/generated/` is raw m2c candidate output and is ALWAYS excluded.
DEFAULT_EXCLUDES = ("src/generated/",)

# Third-party classification is owned by verify.py: the `rw/`, `cri/`, `sce/`
# prefixes plus the C runtime files.  We reuse that exact classification so
# the match verifier and this linter can never disagree about what is
# middleware.  verify.py has no import-time side effects (it only defines
# constants and functions), so executing it here is safe.  If it ever grows
# an import-time side effect, mirror the three definitions below instead
# and keep them in sync with verify.py.
_VERIFY_SPEC = importlib.util.spec_from_file_location(
    "p4_verify_classification", Path(__file__).resolve().parent / "verify.py")
assert _VERIFY_SPEC is not None and _VERIFY_SPEC.loader is not None
_VERIFY = importlib.util.module_from_spec(_VERIFY_SPEC)
_VERIFY_SPEC.loader.exec_module(_VERIFY)

THIRD_PARTY_PREFIXES = _VERIFY.THIRD_PARTY_PREFIXES
THIRD_PARTY_FILES = _VERIFY.THIRD_PARTY_FILES
is_third_party = _VERIFY.is_third_party

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
    "H002": ("error", "zero-instruction asm barrier: empty template emits nothing and exists only to perturb the optimizer"),
    "H003": ("error", "banned optimization pragma (optimization_level 0/1/3, schedule off, opt_common_subs off, opt_loop_invariants)"),
    "H003W": ("warn", "redundant `#pragma optimization_level 2` (that is the documented -O2 baseline)"),
    "H007": ("warn", "dead store: local is assigned once and never read"),
    "H008": ("error", "`register` storage class on an ordinary local"),
    "H009": ("error", "inline asm emitting ordinary instructions (not syscall/privileged/COP2/VU0); use honest C"),
    # ---- M: marker hygiene -------------------------------------------------
    "M001": ("error", "marker hygiene: malformed FUN_ address or duplicate address in one file"),
    # ---- P: pragma balance -------------------------------------------------
    "P001": ("error", "unbalanced pragma on/off pairs within a file"),
}

SEVERITY_ORDER = {"info": 0, "warn": 1, "error": 2}

MARKER_RE = re.compile(r"^\s*//\s*(FUN_([0-9a-fA-F]{8}))(.*)$")
INCLUDE_ASM_RE = re.compile(r'^\s*INCLUDE_ASM\s*\(\s*"')
# Any `// FUN_...` line, including ones whose address part is malformed.
MARKER_LINE_RE = re.compile(r"^\s*//\s*FUN_([0-9a-fA-F]*)(.*)$")
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
        if INCLUDE_ASM_RE.search(line):
            # Another function's whole body, onboarded as an assembly fallback.
            # A run of these between an annotation and the marker it belongs to
            # is not intervening code that should hide the annotation -- the two
            # were adjacent before the stubs were inserted, and the measurement
            # still describes the same construct. Skip without counting depth.
            continue
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
        # `asm`, `__asm`, `__asm__` are all inline-assembly spellings MWCC/GCC
        # accept; none is the compiler-steering `volatile` this rule targets.
        if re.search(r"\b_{0,2}asm_{0,2}\b", line):
            continue
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


# ----------------------------------------------------------------- inline asm
# Inline asm is permitted ONLY where there is genuinely no C expression for
# the operation: PS2 kernel syscall trampolines, privileged instructions,
# and COP2/VU0 register moves.  Using it to force register allocation,
# instruction selection, or scheduling for ordinary arithmetic, loads,
# stores, or control flow is banned even when it matches byte-for-byte.
#
# H002 catches the zero-instruction barrier (`asm ("" : "+r"(x))`): it emits
# nothing and exists only to perturb the optimizer.
#
# H009 catches statements whose template emits real instructions.  The
# allowlist below is the hardware vocabulary with no C expression.  A
# statement that contains ANY allowlisted instruction is treated as one
# hardware idiom: its GPR plumbing -- an `addiu` computing an address fed to
# `lqc2`/`sqc2`, a `pextuw` unwrapping a `qmfc2` result -- rides along with
# the COP2 move.  Only statements made up SOLELY of ordinary mnemonics are
# optimizer-steering and flagged.

ASM_KEYWORD_RE = re.compile(
    r"\b(?:__asm__|__asm|asm)\b(?:\s+(?:volatile|inline|goto))*\s*\(")

# Instructions with no C expression.  VU0 ops are any mnemonic base starting
# with `v` (`vmul`, `vadd`, `vsub`, `vmove`, `vftoi`, `vitof`, `vclip`,
# `vopmula`, ...), including their `.xyzw`/`.x`/`ACC` suffix forms.  `sync`
# covers `sync.l`/`sync.p`; the base strips the suffix before lookup.
ASM_ALLOWED = frozenset({
    "syscall", "sync", "ei", "di", "cache",
    "mfc0", "mtc0", "eret", "tlbwi",
    "qmtc2", "qmfc2", "lqc2", "sqc2", "cfc2", "ctc2",
})

_ASM_ESCAPES = {"n": "\n", "t": "\t", "r": "\r", "\\": "\\", '"': '"'}


def _asm_template(src, line_idx, col):
    """Concatenated template of the asm statement whose opening paren sits at
    (line_idx, col) in the raw text; None if the statement is malformed.

    The template is the run of adjacent C string literals before the first
    `:` (operand separator) or `)` (close), so multi-line statements with
    `\n\t` separators are scanned as one template, not line by line.
    """
    i = line_idx
    line = src.lines[i]
    # `col` points just past the opening `(` of the asm statement, i.e. at
    # the first template character (or whitespace before it).
    parts = []
    while True:
        n = len(line)
        while col < n and line[col] in " \t":
            col += 1
        if col >= n:
            i += 1
            if i >= len(src.lines):
                return None
            line = src.lines[i]
            col = 0
            continue
        ch = line[col]
        if ch == '"':
            col += 1
            buf = []
            while True:
                if col >= n:
                    return None          # unterminated string literal
                c = line[col]
                col += 1
                if c == "\\":
                    if col >= n:
                        return None
                    esc = line[col]
                    col += 1
                    buf.append(_ASM_ESCAPES.get(esc, "\\" + esc))
                elif c == '"':
                    break
                else:
                    buf.append(c)
            parts.append("".join(buf))
            continue
        if ch in ":)":
            return "".join(parts)
        return None                      # template must be a string literal


def _asm_mnemonics(template):
    """Base mnemonics of the real instructions in an asm template.

    Assembler directives (`.set`, `.word`, ...), `#` comments, labels, and
    empty chunks are skipped; `add.s` -> `add`, `vsub.xyzw` -> `vsub`.
    """
    out = []
    for chunk in re.split(r"[\n;]", template):
        chunk = chunk.strip()
        if not chunk or chunk[0] in ".#":
            continue
        tok = chunk.split(None, 1)[0]
        if tok.endswith(":"):
            continue                      # label, e.g. `1:`
        out.append(tok.split(".", 1)[0])
    return out


def check_asm_barrier(src):
    """H002: an asm statement whose template is empty or whitespace-only."""
    for i, line in enumerate(src.code):
        for m in ASM_KEYWORD_RE.finditer(line):
            template = _asm_template(src, i, m.end())
            if template is None or template.strip():
                continue
            if waived(src, i, "H002"):
                continue
            yield Finding("H002", src.rel(), i + 1,
                          "empty asm template emits no instructions; it exists only to perturb the optimizer",
                          src.lines[i].strip())


ASM_FUNC_RE = re.compile(r"^\s*asm\s+[A-Za-z_][\w \*]*\b\w+\s*\(")
WORD_DIRECTIVE_RE = re.compile(r"^\s*\.word\s+(0[xX][0-9A-Fa-f]+)")


def _word_is_hardware(word):
    """True if a raw encoded instruction has no C expression.

    A `.word` blob is machine code with the mnemonic hidden, so the allowlist
    cannot be applied by name.  Decoding the few fields that matter is enough:
    COP0 (`mfc0`/`mtc0`/`eret`/`tlbwi`) and COP2/VU0 are whole opcode spaces,
    and `syscall`/`break`/`sync` are SPECIAL functs.  Everything else -- loads,
    stores, arithmetic, branches, even COP1 float -- is ordinary computation
    that belongs in C.
    """
    op = word >> 26
    if op in (0x10, 0x12):                # COP0, COP2/VU0
        return True
    if op == 0:
        return (word & 0x3F) in (0x0C, 0x0D, 0x0F)   # syscall, break, sync
    return False


def check_asm_function_body(src):
    """H009 for MWCC's `asm void f(void) { ... }` whole-function form.

    ASM_KEYWORD_RE only matches the statement form `asm (`, so a function
    DEFINITION qualified with `asm` slipped past every asm rule.  That is the
    most dangerous shape available: a body of `.word` literals copied from the
    retail bytes matches byte-for-byte by construction, so it reads as a
    genuine result to every other tool in the campaign.  m2c emits exactly
    that form for functions it cannot lift, which is how one reached a
    placeholder file.

    The legitimate case is real: PS2 kernel syscall trampolines have no C
    expression, and MWCC's assembler rejects the `syscall` mnemonic, so they
    must be `.word` literals.  Those decode as hardware and stay allowed.
    """
    for i, line in enumerate(src.code):
        if not ASM_FUNC_RE.match(line):
            continue
        depth, ordinary, hardware = 0, 0, False
        for j in range(i, len(src.code)):
            body = src.code[j]
            m = WORD_DIRECTIVE_RE.match(body)
            if m:
                if _word_is_hardware(int(m.group(1), 16)):
                    hardware = True
                else:
                    ordinary += 1
            else:
                for base in _asm_mnemonics(body if j > i else ''):
                    if base.startswith("v") or base in ASM_ALLOWED:
                        hardware = True
                    else:
                        ordinary += 1
            depth += body.count("{") - body.count("}")
            if depth <= 0 and j > i:
                break
        if hardware or not ordinary:
            continue
        if waived(src, i, "H009"):
            continue
        yield Finding("H009", src.rel(), i + 1,
                      f"whole-function asm body of {ordinary} ordinary instruction(s) "
                      "with no privileged/COP2/VU0 op; this matches by construction, "
                      "not by decompilation",
                      src.lines[i].strip())


def check_asm_instructions(src):
    """H009: inline asm emitting real instructions for ordinary computation."""
    for i, line in enumerate(src.code):
        for m in ASM_KEYWORD_RE.finditer(line):
            template = _asm_template(src, i, m.end())
            if template is None or not template.strip():
                continue                  # H002 owns the empty case
            mnemonics = _asm_mnemonics(template)
            if not mnemonics:
                continue                  # directives only: nothing to flag
            ordinary = []
            hardware = False
            for base in mnemonics:
                if base.startswith("v") or base in ASM_ALLOWED:
                    hardware = True
                else:
                    ordinary.append(base)
            if hardware or not ordinary:
                continue
            if waived(src, i, "H009"):
                continue
            yield Finding("H009", src.rel(), i + 1,
                          "inline asm emits ordinary instructions ("
                          + ", ".join(sorted(set(ordinary)))
                          + ") with no privileged/COP2/VU0 op; use honest C",
                          src.lines[i].strip())


# ------------------------------------------------------------ marker hygiene

def check_markers(src):
    """M001: malformed addresses and duplicates within one file.

    The contract verify.py relies on: every tracked function carries a
    `// FUN_<8 hex digits>` marker, and no address appears twice in one file.
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
    check_asm_barrier,
    check_asm_instructions,
    check_asm_function_body,
    check_markers,
    check_pragma_balance,
)


def non_matching_lines(src):
    """Line indices inside `#ifdef NON_MATCHING` reference blocks.

    A function that could not be matched keeps its near-miss C behind
    `#ifdef NON_MATCHING`, with an `INCLUDE_ASM` fallback in the `#else` arm.
    That C is NEVER compiled -- it is preserved so whoever finishes the function
    does not have to start over. Linting it produces false positives by
    construction: a faithful reconstruction reproduces stores retail makes even
    where the reconstruction itself does not consume them, which reads as a dead
    store. Style rules apply to code that ships, so skip these blocks.
    """
    skip, depth = set(), 0
    for index, line in enumerate(src.lines):
        stripped = line.strip()
        if stripped.startswith("#ifdef NON_MATCHING") or (depth and stripped.startswith("#if")):
            depth += 1
        elif depth:
            if stripped.startswith("#endif"):
                depth -= 1
            elif depth == 1 and stripped.startswith("#else"):
                depth = 0          # the #else arm is the INCLUDE_ASM that DOES build
                continue
        if depth:
            skip.add(index)
    return skip


def lint_source(src):
    out = []
    skip = non_matching_lines(src)
    for check in CHECKS:
        out.extend(f for f in check(src) if (f.line - 1) not in skip)
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
    ap.add_argument("--include-third-party", action="store_true",
                    help="also lint third-party middleware (rw/, cri/, sce/ and the C runtime "
                         "files); default is first-party only")
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
    # Split by ownership, like verify.py: default mode reads only first-party
    # sources; third-party files are linted only when explicitly requested.
    first_srcs, third_srcs = [], []
    for f in files:
        try:
            src = Source(f, f.read_bytes())
        except OSError as exc:
            sys.stderr.write(f"decomp_lint: cannot read {f}: {exc}\n")
            continue
        (third_srcs if is_third_party(src.rel()) else first_srcs).append(src)

    findings = []
    for src in first_srcs:
        findings.extend(x for x in lint_source(src) if keep(x.code))
    third_findings = []
    if args.include_third_party:
        for src in third_srcs:
            third_findings.extend(x for x in lint_source(src) if keep(x.code))
    all_findings = findings + third_findings

    by_code = Counter(f.code for f in all_findings)
    by_sev = Counter(f.severity for f in all_findings)
    fp_sev = Counter(f.severity for f in findings)
    tp_sev = Counter(f.severity for f in third_findings)

    if not args.summary:
        for f in sorted(all_findings, key=lambda x: (x.file, x.line, x.code)):
            print(f"{f.file}:{f.line}: {f.severity}: [{f.code}] {f.message}")
            if f.text:
                print(f"    {f.text}")

    if args.include_third_party:
        print(f"\ndecomp_lint: {len(first_srcs) + len(third_srcs)} files, "
              f"{len(all_findings)} findings "
              f"({by_sev['error']} error, {by_sev['warn']} warn)")
        print(f"  first-party: {len(first_srcs)} files, {len(findings)} findings "
              f"({fp_sev['error']} error, {fp_sev['warn']} warn)")
        print(f"  third-party: {len(third_srcs)} files, {len(third_findings)} findings "
              f"({tp_sev['error']} error, {tp_sev['warn']} warn)")
    else:
        print(f"\ndecomp_lint: {len(first_srcs)} first-party files, "
              f"{len(findings)} findings "
              f"({fp_sev['error']} error, {fp_sev['warn']} warn)")
        if third_srcs:
            print(f"  (skipped {len(third_srcs)} third-party files; "
                  f"use --include-third-party to lint them)")
    for code, n in sorted(by_code.items()):
        print(f"  {code}  {RULES[code][0]:<5} {n:>7}  {RULES[code][1]}")

    if args.json:
        Path(args.json).write_text(json.dumps(dict(
            files=len(files),
            include_third_party=args.include_third_party,
            first_party_files=len(first_srcs),
            third_party_files=len(third_srcs),
            summary_by_code={c: n for c, n in sorted(by_code.items())},
            summary_by_severity=dict(by_sev),
            first_party=dict(
                summary_by_code={c: n for c, n in sorted(Counter(f.code for f in findings).items())},
                summary_by_severity=dict(fp_sev)),
            third_party=dict(
                summary_by_code={c: n for c, n in sorted(Counter(f.code for f in third_findings).items())},
                summary_by_severity=dict(tp_sev)),
            rules={c: dict(severity=s, description=d) for c, (s, d) in RULES.items()},
            findings=[f.as_dict() for f in all_findings]), indent=1))
        print(f"report: {args.json}")

    # The exit status is driven by FIRST-PARTY errors only: middleware noise
    # must never fail a run that gates CI on first-party honesty.
    return 1 if fp_sev["error"] else 0


if __name__ == "__main__":
    sys.exit(main())
