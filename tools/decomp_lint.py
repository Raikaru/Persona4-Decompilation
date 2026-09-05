#!/usr/bin/env python3
"""Source-honesty linter for the Persona 4 decompilation tree.

`verify.py` answers "do these bytes match retail?". This checks structural
integrity and flags source constructs that need review. Byte equality alone
does not establish semantic fidelity; ordinary assembly transcription can
match by construction. Compiler settings and volatile accesses are heuristics,
not proof of dishonesty.

The compiler baseline is MWCCPS2 3.0.1 b210 with `-O2`. H001 (unknown
volatile context), H003 (nonbaseline optimization settings), and H007 (dead
stores) are advisory warnings, not proof of dishonest source. H002 rejects
allocation barriers but permits pure compiler memory barriers. H009 rejects
ordinary assembly and unparsed templates; small hardware wrappers may carry
bounded ordinary register plumbing. M001 validates function markers. P001
checks only real pragma push/pop stacks, not on/off settings.

WAIVERS must occur in lexical comments. Nearby comments (up to three lines)
or annotations immediately above a function marker (up to six lines) may
waive advisory rules with `measured` or `lint: allow CODE`. Integrity rules
require a rule-specific reason: `lint: allow H009 -- unsupported wrapper`
(a colon also separates the reason). Generic measurements never waive H002
or H009. Waivers cannot cross another function or marker. M001 and P001
are structural checks and are not waived.

The tree is split like verify.py splits it: first-party code is what this
project wrote and polices; third-party middleware (RenderWare under `rw/`,
CRI under `cri/`, the Sony SDK under `sce/`, and the C runtime files) is
retail-tracked but nobody's to restyle.  By default only first-party sources
are linted; `--include-third-party` scans everything and reports both
populations separately in the summary. First-party integrity errors and scan
failures drive the exit status; third-party findings remain informational.

Usage:
    python tools/decomp_lint.py                     # lint first-party src/ and include/
    python tools/decomp_lint.py --include-third-party   # also lint rw/ cri/ sce/ + C runtime
    python tools/decomp_lint.py src/Battle          # lint a subtree
    python tools/decomp_lint.py --errors-only       # errors only, exit 1 on any first-party error
    python tools/decomp_lint.py src/foo.c --json r.json
    python tools/decomp_lint.py --select H          # only honesty rules
    python tools/decomp_lint.py --ignore H007       # omit dead-store advisories
    python tools/decomp_lint.py --list              # describe every rule

Exit status is 1 if any first-party `error` finding survives filtering or
any requested input cannot be scanned, else 0. Scan errors are always printed
and included in JSON `scan_errors`, regardless of rule/severity filtering.
Third-party findings never fail the run. `src/generated/` is never linted.
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

# Known PS2 hardware windows: direct volatile pointer casts to these addresses
# need no context warning. Other volatile uses may be legitimate too; H001 asks
# for review rather than rejecting them.
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
    "H001": ("warn", "`volatile` with no recognized hardware address; review context"),
    "H002": ("error", "zero-instruction asm allocation barrier (pure memory barriers are allowed)"),
    "H003": ("warn", "nonbaseline optimization pragma; review measured justification"),
    "H007": ("warn", "dead store: local is assigned once and never read"),
    "H009": ("error", "inline asm emitting ordinary instructions (not syscall/privileged/COP2/VU0); use honest C"),
    # ---- M: marker hygiene -------------------------------------------------
    "M001": ("error", "marker hygiene: malformed FUN_ address or duplicate address in one file"),
    # ---- P: pragma balance -------------------------------------------------
    "P001": ("error", "pragma push/pop stack underflow or unclosed push"),
}

SEVERITY_ORDER = {"info": 0, "warn": 1, "error": 2}

MARKER_RE = re.compile(r"^\s*//\s*(FUN_([0-9a-fA-F]{8}))\b(.*)$")
INCLUDE_ASM_RE = re.compile(r'^\s*INCLUDE_ASM\s*\(\s*"')
# Any `// FUN_...` line, including ones whose address part is malformed.
MARKER_LINE_RE = re.compile(r"^\s*//\s*FUN_([0-9a-fA-F]*)(.*)$")
IDENT_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")


# --------------------------------------------------------------- source prep

def lexical_views(lines):
    """Return code, comments, comment-free text, and genuine line comments.

    C line splicing precedes comment recognition. Logical lines are placed at
    their first physical line, with empty continuation slots, preserving all
    later diagnostic line numbers.
    """
    logical = [""] * len(lines)
    i = 0
    while i < len(lines):
        start = i
        text = lines[i]
        while text.endswith("\\") and i + 1 < len(lines):
            i += 1
            text = text[:-1] + lines[i]
        logical[start] = text
        i += 1
    code, comments, text_view, line_comments = [], [], [], []
    state = "code"
    for line in logical:
        c, notes, text = [], [], []
        line_comment = ""
        i = 0
        while i < len(line):
            ch = line[i]
            pair = line[i:i + 2]
            if state == "block":
                size = 2 if pair == "*/" else 1
                c.append(" " * size)
                notes.append(line[i:i + size])
                text.append(" " * size)
                i += size
                if pair == "*/":
                    state = "code"
            elif state in ('"', "'"):
                size = min(2, len(line) - i) if ch == "\\" else 1
                c.append(" " * size)
                notes.append(" " * size)
                text.append(line[i:i + size])
                i += size
                if ch == state:
                    state = "code"
            elif pair == "//":
                line_comment = " " * i + line[i:] if not line[:i].strip() else ""
                c.append(" " * (len(line) - i))
                notes.append(line[i:])
                text.append(" " * (len(line) - i))
                break
            elif pair == "/*":
                state = "block"
                c.append("  ")
                notes.append(pair)
                text.append("  ")
                i += 2
            elif ch in ('"', "'"):
                state = ch
                c.append(" ")
                notes.append(" ")
                text.append(ch)
                i += 1
            else:
                c.append(ch)
                notes.append(" ")
                text.append(ch)
                i += 1
        code.append("".join(c))
        comments.append("".join(notes))
        text_view.append("".join(text))
        line_comments.append(line_comment)
    return code, comments, text_view, line_comments


def sanitize(lines):
    return lexical_views(lines)[0]


class Source:
    """One .c/.h file, with the derived views every rule needs."""

    def __init__(self, path, raw):
        self.path = Path(path).resolve()
        self.raw = raw
        text = raw.decode("utf-8", errors="replace")
        self.crlf = raw.count(b"\r\n")
        self.lf = raw.count(b"\n") - self.crlf
        self.lines = text.replace("\r\n", "\n").split("\n")
        self.code, self.comments, self.text, self.line_comments = lexical_views(self.lines)

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

ADVISORY_RULES = frozenset(("H001", "H003", "H007"))
WAIVER_ALLOW_RE = re.compile(
    r"\blint:\s*allow\s+([A-Z]\d{3})\b(?:\s*(?::|--)\s*([^\r\n]*))?")


def _comment_waives(comment, code):
    for match in WAIVER_ALLOW_RE.finditer(comment):
        if match.group(1) == code:
            reason = (match.group(2) or "").split("*/", 1)[0].strip()
            if code in ADVISORY_RULES or reason:
                return True
    return code in ADVISORY_RULES and re.search(r"\bmeasured\b", comment) is not None


def waived(src, idx, code):
    if _comment_waives(src.comments[idx], code):
        return True
    if _scan_waiver(src, idx, code, 3):
        return True
    marker = _enclosing_marker(src, idx)
    return marker is not None and _scan_waiver(src, marker, code, 6)


def _scan_waiver(src, idx, code, depth):
    for j in range(idx - 1, max(-1, idx - depth - 1), -1):
        if MARKER_LINE_RE.match(src.line_comments[j]) or re.search(r"[{}]", src.code[j]):
            break
        if _comment_waives(src.comments[j], code):
            return True
        if src.code[j].strip():
            break
    return False


def _enclosing_marker(src, idx):
    # A completed top-level body or INCLUDE_ASM fallback terminates marker
    # ownership, even if the following function has no marker.
    ends = {end for _, end in iter_functions(src)}
    for j in range(idx, -1, -1):
        if j < idx and (j in ends or INCLUDE_ASM_RE.match(src.text[j])):
            return None
        if MARKER_LINE_RE.match(src.line_comments[j]):
            return j if MARKER_RE.match(src.line_comments[j]) else None
    return None


# --------------------------------------------------------------------- rules
# Each rule is `def check_xxx(src) -> iterable[Finding]`.

VOLATILE_RE = re.compile(r"\bvolatile\b")


# Bit patterns that are overwhelmingly float constants rather than addresses.
# 0xBF800000 is -1.0f and it collides exactly with the KSEG1 mirror of the
# scratchpad base, so masking it would hand a free H001 waiver to any line
# mentioning -1.0f. Retail's own func_001774a0 does `lui v0,0xbf80; mtc1 v0,f1`
# -- that is the float, not the scratchpad. Genuine scratchpad accesses carry a
# non-zero offset (0xBF800004, 0xBF800018, ...) and are unaffected.
FLOAT_CONSTANTS = frozenset((0x3F800000, 0xBF800000))


def _physical(v):
    """Physical address behind a KSEG0/KSEG1 pointer, else `v` unchanged.

    EE code reaches most devices through the uncached mirror, so the
    scratchpad at physical 0x1F800000 is written `0xBF800004` in source and
    the fromSPR DMA channel at 0x1000D000 as `0xB000D000`. Range-testing the
    literal without masking rejects those as non-hardware and reports a
    legitimate device access as H001.
    """
    if v in FLOAT_CONSTANTS:
        return v
    return v & 0x1FFFFFFF if 0x80000000 <= v <= 0xBFFFFFFF else v


def _is_hardware_line(line):
    # A scalar constant elsewhere on the line is not evidence of MMIO.
    for m in re.finditer(r"\([^();]*\bvolatile\b[^();]*\*[^();]*\)\s*(0[xX][0-9a-fA-F]+)\b", line):
        v = _physical(int(m.group(1), 16))
        for lo, hi in HARDWARE_RANGES:
            if lo <= v < hi:
                return True
    return False


def check_volatile(src):
    # Only the asm qualifier is exempt, not unrelated volatile data on the
    # same line. Preserve newlines when the qualifier spans logical lines.
    code = ASM_KEYWORD_RE.sub(
        lambda m: re.sub(r"[^\n]", " ", m.group()), "\n".join(src.code))
    for i, line in enumerate(code.split("\n")):
        if not VOLATILE_RE.search(line):
            continue
        if _is_hardware_line(line):
            continue
        if waived(src, i, "H001"):
            continue
        yield Finding("H001", src.rel(), i + 1,
                      "volatile context is not a recognized direct hardware access; review justification",
                      src.lines[i].strip())


BANNED_PRAGMA_RE = re.compile(
    r"^\s*#\s*pragma\s+(optimization_level\s+(?!2(?:\s|$))\S+"
    r"|schedule\s+off\b|opt_common_subs\s+off\b"
    r"|opt_loop_invariants\s+(?:on|off)\b)")


def check_banned_pragma(src):
    for i, line in enumerate(src.code):
        m = BANNED_PRAGMA_RE.search(line)
        if m and not waived(src, i, "H003"):
            yield Finding("H003", src.rel(), i + 1,
                          f"nonbaseline pragma `{m.group(1).strip()}`; review justification",
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
# Both assembly forms share instruction decoding and bounded hardware-plumbing
# policy: ordinary instructions need hardware context, and beyond 16 ordinary
# instructions their count must not exceed eight times the hardware count.

ASM_KEYWORD_RE = re.compile(
    r"\b(?:__asm__|__asm|asm)\b(?:\s+(?:volatile|inline|goto))*\s*\(")

# Instructions with no C expression.  VU0 ops are any mnemonic base starting
# with `v` (`vmul`, `vadd`, `vsub`, `vmove`, `vftoi`, `vitof`, `vclip`,
# `vopmula`, ...), including their `.xyzw`/`.x`/`ACC` suffix forms.  `sync`
# covers `sync.l`/`sync.p`; the base strips the suffix before lookup.
# `bc0f`/`bc0t` branch on the COP0 condition line, a hardware side-channel
# (e.g. the DMAC channel-drain arbitration signal) with no readable GPR
# expression -- there is no `mfc0` for it, only the branch.
ASM_ALLOWED = frozenset({
    "syscall", "sync", "ei", "di", "cache",
    "mfc0", "mtc0", "eret", "tlbwi", "bc0f", "bc0t",
    "qmtc2", "qmfc2", "lqc2", "sqc2", "cfc2", "ctc2",
})

_ASM_ESCAPES = {"n": "\n", "t": "\t", "r": "\r", "\\": "\\", '"': '"'}


def _inline_asm(src):
    """Yield physical line, decoded template (or None), and operand suffix."""
    code = "\n".join(src.code)
    text = "\n".join(src.text)
    for match in ASM_KEYWORD_RE.finditer(code):
        start = match.end()
        pos, depth, quote = start, 1, None
        while pos < len(text) and depth:
            ch = text[pos]
            if quote:
                if ch == "\\":
                    pos += 2
                    continue
                if ch == quote:
                    quote = None
            elif ch in "\"'":
                quote = ch
            elif ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
            pos += 1
        body = text[start:pos - 1] if depth == 0 else ""
        cursor, parts = 0, []
        while True:
            literal = re.match(r'\s*"((?:\\.|[^"\\])*)"', body[cursor:], re.S)
            if not literal:
                break
            parts.append(re.sub(r"\\(.)", lambda m: _ASM_ESCAPES.get(
                m.group(1), "\\" + m.group(1)), literal.group(1), flags=re.S))
            cursor += literal.end()
        suffix = body[cursor:].strip()
        template = "".join(parts) if parts and (not suffix or suffix.startswith(":")) else None
        yield code.count("\n", 0, match.start()), template, suffix




def _asm_mnemonics(template):
    """Decode instruction chunks, including labels and encoded .word lists."""
    out = []
    for line in template.splitlines():
        for chunk in line.split("#", 1)[0].split(";"):
            chunk = chunk.strip()
            while re.match(r"^[\w.$]+:", chunk):
                chunk = chunk.split(":", 1)[1].strip()
            if not chunk:
                continue
            fields = chunk.split(None, 1)
            token = fields[0].lower()
            if token == ".word":
                for value in (fields[1] if len(fields) > 1 else "").split(","):
                    try:
                        word = int(value.strip(), 0)
                    except ValueError:
                        out.append("<unparsed>")
                    else:
                        out.append("<hardware>" if 0 <= word <= 0xFFFFFFFF
                                   and _word_is_hardware(word) else ".word")
            elif token in {".set", ".align", ".balign", ".globl", ".global",
                           ".ent", ".end", ".type", ".size", ".text"}:
                continue
            else:
                out.append(token.split(".", 1)[0] if not token.startswith(".") else token)
    return out


def check_asm_barrier(src):
    for i, template, suffix in _inline_asm(src):
        if template is None or _asm_mnemonics(template):
            continue
        # No output/input operands and exactly the memory clobber: this is a
        # compiler ordering primitive, not a register-allocation constraint.
        if re.fullmatch(r':\s*:\s*:\s*"memory"\s*', suffix):
            continue
        if not waived(src, i, "H002"):
            yield Finding("H002", src.rel(), i + 1,
                          "zero-instruction asm allocation barrier; use a genuine memory barrier or explain the integrity exception",
                          src.lines[i].strip())


ASM_FUNC_RE = re.compile(r"\basm\s+[A-Za-z_][\w \*]*\b\w+\s*\([^;{}]*\)\s*\{")


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


def _asm_problem(template):
    if template is None:
        return "unparsed asm template; cannot establish source honesty"
    instructions = _asm_mnemonics(template)
    hardware = sum(base == "<hardware>" or base in ASM_ALLOWED or
                   bool(re.fullmatch(
                       r"v(?:abs|(?:add|sub|mul|madd|msub)a?[iqxyzw]?|"
                       r"max[iqxyzw]?|mini[iqxyzw]?|move|mr32|ftoi[0-9]*|itof[0-9]*|clipw?|"
                       r"opmula|opmsub|div|sqrt|rsqrt|waitq|nop|callmsr?|"
                       r"iadd|iaddi|isub|iand|ior|ilw|isw|lqi|lqd|sqi|sqd|"
                       r"mfir|mtir|rget|rinit|rnext|rxor)", base))
                   for base in instructions)
    ordinary = len(instructions) - hardware
    if "<unparsed>" in instructions or any(base.startswith(".") and base != ".word"
                                            for base in instructions):
        return "unparsed assembly directive; cannot establish source honesty"
    if ordinary and (not hardware or (ordinary > 16 and ordinary > 8 * hardware)):
        return (f"asm emits {ordinary} ordinary instruction(s) against {hardware} "
                "hardware instruction(s); use honest C rather than transcription")
    return None


def check_asm_function_body(src):
    code = "\n".join(src.code)
    for match in ASM_FUNC_RE.finditer(code):
        start, pos, depth = match.end(), match.end(), 1
        while pos < len(code) and depth:
            depth += (code[pos] == "{") - (code[pos] == "}")
            pos += 1
        i = code.count("\n", 0, match.start())
        problem = _asm_problem(code[start:pos - 1] if depth == 0 else None)
        if problem and not waived(src, i, "H009"):
            yield Finding("H009", src.rel(), i + 1, problem, src.lines[i].strip())


def check_asm_instructions(src):
    for i, template, _ in _inline_asm(src):
        if template is not None and not _asm_mnemonics(template):
            continue  # H002 owns zero-instruction templates.
        problem = _asm_problem(template)
        if problem and not waived(src, i, "H009"):
            yield Finding("H009", src.rel(), i + 1, problem, src.lines[i].strip())


# ------------------------------------------------------------ marker hygiene

def check_markers(src):
    """M001: malformed addresses and duplicates within one file.

    The contract verify.py relies on: every tracked function carries a
    `// FUN_<8 hex digits>` marker, and no address appears twice in one file.
    """
    markers = []          # (idx, addr)
    seen = defaultdict(list)
    for i, line in enumerate(src.line_comments):
        m = MARKER_LINE_RE.match(line)
        if not m:
            continue
        hexpart = m.group(1)
        if not MARKER_RE.match(line):
            yield Finding("M001", src.rel(), i + 1,
                          f"malformed marker address `FUN_{hexpart}` "
                          f"({len(hexpart)} hex digits; expected 8 followed by a token boundary)",
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

PUSH_RE = re.compile(r"^\s*#\s*pragma\s+push\b")
POP_RE = re.compile(r"^\s*#\s*pragma\s+pop\b")


def check_pragma_balance(src):
    """Track actual stack transitions; mode settings are not brackets."""
    stack = []
    for i, line in enumerate(src.code):
        if PUSH_RE.search(line):
            stack.append(i + 1)
        elif POP_RE.search(line):
            if stack:
                stack.pop()
            else:
                yield Finding("P001", src.rel(), i + 1, "#pragma pop without a preceding push")
    for line in stack:
        yield Finding("P001", src.rel(), line, "#pragma push has no closing pop")


CHECKS = (
    check_volatile,
    check_banned_pragma,
    check_dead_store,
    check_asm_barrier,
    check_asm_instructions,
    check_asm_function_body,
    check_markers,
    check_pragma_balance,
)


def _reference_condition(directive, expression):
    """Recognize only exact NON_MATCHING tests, not arbitrary preprocessing."""
    expression = expression.strip()
    if directive in ("ifdef", "ifndef") and expression == "NON_MATCHING":
        return directive == "ifdef"
    if directive in ("if", "elif"):
        if re.fullmatch(r"(?:NON_MATCHING|defined\s*(?:NON_MATCHING|\(\s*NON_MATCHING\s*\)))", expression):
            return True
        if re.fullmatch(r"!\s*(?:NON_MATCHING|defined\s*(?:NON_MATCHING|\(\s*NON_MATCHING\s*\)))", expression):
            return False
    return None


def non_matching_lines(src):
    """Exclude reference arms only, preserving nested branch ownership."""
    skip, stack = set(), []
    for index, line in enumerate(src.code):
        match = re.match(r"^\s*#\s*(ifdef|ifndef|if|elif|else|endif)\b(.*)", line)
        if match:
            directive, expression = match.groups()
            if directive in ("if", "ifdef", "ifndef"):
                reference = _reference_condition(directive, expression)
                # Track whether an exact negative test makes its else the
                # reference arm. Unknown branches remain lintable.
                stack.append([reference is True, reference is False])
            elif directive == "elif" and stack:
                reference = _reference_condition("elif", expression)
                stack[-1][0] = reference is True or stack[-1][1]
                stack[-1][1] |= reference is False
            elif directive == "else" and stack:
                stack[-1][0] = stack[-1][1]
            elif directive == "endif" and stack:
                stack.pop()
        if any(frame[0] for frame in stack):
            skip.add(index)
    return skip


def lint_source(src):
    # Filter all lexical views before aggregate checks: reference pragmas,
    # declarations, comments and braces cannot affect compiled source.
    skip = non_matching_lines(src)
    active = Source.__new__(Source)
    active.__dict__ = src.__dict__.copy()
    for name in ("code", "comments", "text", "line_comments"):
        setattr(active, name, ["" if i in skip else line
                               for i, line in enumerate(getattr(src, name))])
    out = [finding for check in CHECKS for finding in check(active)]
    out.sort(key=lambda f: (f.line, f.code))
    return out


# ----------------------------------------------------------------------- CLI

def gather(paths, excludes, scan_errors=None):
    """Return normalized files; optionally collect unfilterable scan failures."""
    import os

    errors = scan_errors if scan_errors is not None else []
    files = []

    def failure(path, message):
        errors.append(dict(file=str(path), message=message))
        sys.stderr.write(f"decomp_lint: {path}: {message}\n")

    for requested in paths:
        p = Path(requested)
        try:
            p = p.resolve()
            p.stat()
            if p.is_dir():
                def onerror(exc):
                    failure(exc.filename or p, str(exc))
                for directory, _, names in os.walk(p, onerror=onerror):
                    files.extend(Path(directory) / name for name in sorted(names)
                                 if Path(name).suffix in (".c", ".h"))
            elif p.is_file():
                files.append(p)
            else:
                failure(p, "not a regular file or directory")
        except OSError as exc:
            failure(p, str(exc))
    out = []
    for f in sorted(set(files)):
        f = f.resolve()
        try:
            rel = f.relative_to(ROOT).as_posix()
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

    scan_errors = []
    files = gather(paths, excludes, scan_errors)
    # Split by ownership, like verify.py: default mode reads only first-party
    # sources; third-party files are linted only when explicitly requested.
    first_srcs, third_srcs = [], []
    for f in files:
        try:
            src = Source(f, f.read_bytes())
        except OSError as exc:
            scan_errors.append(dict(file=str(f), message=str(exc)))
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
            scan_errors=scan_errors,
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

    # Scan failures cannot be hidden by severity, rule or ownership filters.
    return 1 if fp_sev["error"] or scan_errors else 0


if __name__ == "__main__":
    sys.exit(main())
