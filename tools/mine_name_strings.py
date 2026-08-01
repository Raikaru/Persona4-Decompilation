#!/usr/bin/env python3
"""Mine retail strings that name individual Persona 4 functions.

Every non-``__FILE__`` naming signal in ``orig/SLUS_217.82`` is investigated
here; the ``__FILE__`` assert-filename signal is owned by a separate tool.
The output is ``config/symbol_names.strings.txt`` in the shared contract
format (``Name = 0xADDR; // type:func  evidence: string:"<text>"``), which
``tools/reconcile_function_boundaries.py`` folds into ``symbol_addrs.txt``.

Evidence classes mined (with measured outcomes):

A. {name, fn} record adjacency  -- the only paying class (89 names accepted)
   A C-identifier string whose address appears as a data word immediately
   beside (within one word of) exactly one canonical function address, with
   no second canonical function on the far side of that field.  PS2 task,
   command and message-condition dispatch tables store a name string and a
   handler pointer in the same record; when the record contains exactly one
   canonical function, the name unambiguously labels that handler.  Both
   observed layouts are covered: {name, fn, ...} and {fn, name, ...}.

B. panic/assert/debug strings referenced from exactly one function -- 0 names
   Measured and rejected: the only uniquely-referenced strings whose text
   carries a function-name-shaped tag (``E0082101:... (htCiGetFileSize)``)
   belong to CRI middleware (htCi*/dvCi*/mfCi*/adxf_*/LSC_*), which is out of
   scope, and the leading ``IDENT:`` tags that do occur in first-party code
   (SCRIPT:, MOVIE:, TTY:, libpad:, sceGs*) are module/file tags, not
   function names.

C. task-name identifiers loaded from code -- 0 names
   305 first-party identifier strings are loaded from exactly one function
   each but never appear in a data record; the name is handed to a
   task-create call whose callback arrives through s-registers set by
   callers reachable only via pointer tables, so the named function cannot
   be verified.

D. C++ RTTI/class-name strings -- absent
   Zero strings contain ``::`` or a ``_Z`` mangling prefix and the ELF
   compiler comment is "MW MIPS C Compiler (2.4.1.01)", i.e. the image is
   C, not C++.

Identifier transform (documented contract):
  ``to_identifier()`` only accepts strings that are already legal C
  identifiers (``[A-Za-z_][A-Za-z0-9_]*``).  No case change, no separator
  substitution and no prefix is ever applied to the string itself: the
  record class requires the retail name to BE a valid identifier, so
  anything requiring a transform (spaces, punctuation, file names, leading
  digits) is rejected at extraction rather than silently rewritten.

  A ROLE PREFIX is prepended to the accepted name at emission time (the
  string itself is untouched and stays in the ``evidence:`` note verbatim):

    btlAct_   table A: the battle command/action dispatch table
              (records at 0x5f74xx-0x5f78xx; the consumer takes the
              selected command index and calls the handler).  Names such
              as NOP/ANALYZE/ATTACK_*/SKILL_*/TARGET are script command
              keywords; the functions are the command handlers.
    btlCond_  table B: the battle condition-predicate dispatch table
              ({fn, name, flag} records at 0x6098xx-0x609exx; consumers
              index a state and call the predicate, branching on the
              return).  Names such as MYHP/FRHP/ENBAD are condition
              keywords.  The table's role is a condition predicate; whether
              the conditions feed the AI or the message system is not
              provable from the image, so the neutral btlCond_ prefix is
              used rather than inventing a semantic one.
    tbl_      neutral fallback for any future record region whose role is
              unknown (currently unused).

  The evidence note always carries the raw keyword (``string:"MYHP"``),
  so the unprefixed source name is preserved for every symbol.
"""

from __future__ import annotations

import argparse
from collections import defaultdict
import json
import re
from pathlib import Path
import sys

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))
from verify import RetailElf, is_generated, is_third_party, scan_markers

TARGET = REPO / "config" / "target.json"
FUNCTION_WINDOWS = TOOLS / "slus21782_functions.json"
OUTPUT = REPO / "config" / "symbol_names.strings.txt"
P3_SYMBOLS = REPO.parent / "Persona3-FES-Decompilation" / "config" / "symbol_addrs.txt"

# Data segments that hold the string pool and the dispatch tables.
DATA1_LO, DATA1_HI = 0x0052DA00, 0x0070C850
DATA2_LO, DATA2_HI = 0x0070E140, 0x00764280
CODE1_LO, CODE1_HI = 0x00100000, 0x0052DA00
CODE2_LO, CODE2_HI = 0x0070C850, 0x0070E140

MIN_STRING = 3
LUI_OP, ADDIU_OP, ORI_OP = 0x0F, 0x09, 0x0D

IDENTIFIER = re.compile(rb"^[A-Za-z_][A-Za-z0-9_]*$")
PLACEHOLDER = re.compile(r"^(?:FUN|func)_[0-9A-Fa-f]+$")
C_KEYWORDS = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "inline", "int", "long", "register", "restrict", "return", "short",
    "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while",
}


# Role prefixes per record-region, applied at emission (see module docstring).
PREFIX_REGIONS = (
    (0x005F7400, 0x005F7900, "btlAct_"),    # battle command/action dispatch table
    (0x00609800, 0x00609F00, "btlCond_"),   # battle condition-predicate dispatch table
)
NEUTRAL_PREFIX = "tbl_"


def role_prefix(site: int) -> str:
    """Prefix for the table region containing *site* (``tbl_`` if unknown)."""
    for low, high, prefix in PREFIX_REGIONS:
        if low <= site < high:
            return prefix
    return NEUTRAL_PREFIX


def parse_int(value: int | str) -> int:
    return value if isinstance(value, int) else int(value, 0)


def to_identifier(text: bytes | str, prefix: str = "") -> str | None:
    """Return *text* (with an optional role *prefix*) as a legal C identifier.

    The core transform is the identity function on strings that already are
    legal C identifiers (case and separators preserved); everything else is
    rejected.  ``prefix``, when given, must itself be a legal identifier and
    is prepended as ``prefix + name`` -- it is presentation for the emitted
    symbol; the raw retail string is preserved in the ``evidence:`` note.
    ``text`` may be bytes or str; NUL bytes are never part of a mined
    string.
    """
    if isinstance(text, str):
        text = text.encode("ascii", "replace")
    if not IDENTIFIER.match(text):
        return None
    name = text.decode("ascii")
    if name in C_KEYWORDS or PLACEHOLDER.match(name):
        return None
    if prefix:
        if not re.match(r"[A-Za-z_]\w*$", prefix):
            return None
        name = prefix + name
    return name


def truncate(text: str, limit: int = 60) -> str:
    """Shorten an evidence string sensibly (for the ``evidence:`` note)."""
    return text if len(text) <= limit else text[: limit - 3] + "..."


def extract_strings(blob: bytes, lo: int, hi: int, base: int, min_len: int = MIN_STRING) -> dict[int, bytes]:
    """Return {vaddr: bytes} for printable-ASCII NUL-terminated runs.

    ``blob`` is the raw segment image, ``base`` its load vaddr.  Runs of
    ``min_len`` or more printable bytes (0x20..0x7e) terminated by a NUL
    are string candidates.
    """
    strings: dict[int, bytes] = {}
    start = lo - base
    end = hi - base
    cursor = start
    while cursor < end:
        byte = blob[cursor]
        if 0x20 <= byte <= 0x7E:
            stop = cursor
            while stop < end and 0x20 <= blob[stop] <= 0x7E:
                stop += 1
            if stop - cursor >= min_len:
                strings[base + cursor] = blob[cursor:stop]
            cursor = min(stop + 1, end)
        else:
            cursor += 1
    return strings


def sign_extend(value: int, bits: int = 16) -> int:
    value &= (1 << bits) - 1
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def decode_instruction(word: int) -> tuple[int, int, int, int]:
    """Decode (op, rs, rt, imm16) of a MIPS word."""
    return (
        (word >> 26) & 0x3F,
        (word >> 21) & 0x1F,
        (word >> 16) & 0x1F,
        word & 0xFFFF,
    )


def absolute_references(words: list[int]) -> set[int]:
    """Resolve lui+addiu/ori pairs to absolute data addresses.

    For every ``lui rt, hi`` whose ``rt`` is next written by an
    ``addiu rt, rt, lo`` or ``ori rt, rt, lo`` within the following 16
    instructions, yield ``(hi << 16) + sext(lo)``.  Any other write to
    ``rt`` ends the pair, mirroring how MWCC materializes 32-bit addresses.
    """
    refs: set[int] = set()
    count = len(words)
    for index, word in enumerate(words):
        op, _rs, rt, hi = decode_instruction(word)
        if op != LUI_OP:
            continue
        for follow in range(index + 1, min(index + 17, count)):
            op2, rs2, rt2, imm2 = decode_instruction(words[follow])
            if rt2 != rt:
                continue
            if op2 == ADDIU_OP and rs2 == rt:
                refs.add((hi << 16) + sign_extend(imm2) & 0xFFFFFFFF)
            elif op2 == ORI_OP and rs2 == rt:
                refs.add(((hi << 16) + imm2) & 0xFFFFFFFF)
            break
    return refs


def record_candidates(
    str_sites: dict[int, list[int]],
    string_at: dict[int, bytes],
    word_at,
    is_fn_word,
) -> tuple[list[tuple[int, int, int]], list[tuple[int, frozenset, int]]]:
    """Classify every data site holding a string address.

    Returns ``(records, ambiguous)`` where each record is
    ``(string_addr, fn_addr, site)`` for a site whose string is adjacent to
    exactly one canonical function (and that function is not itself flanked
    by a second canonical function), and each ambiguous entry is
    ``(string_addr, frozenset(fns), site)`` for a site with canonical
    functions on BOTH sides (the name binds no single function).
    """
    records: list[tuple[int, int, int]] = []
    ambiguous: list[tuple[int, frozenset, int]] = []
    for string_addr, sites in str_sites.items():
        text = string_at[string_addr]
        if not IDENTIFIER.match(text) or len(text) < 3:
            continue
        for site in sites:
            plus4 = word_at(site + 4)
            minus4 = word_at(site - 4)
            fns: set[int] = set()
            if is_fn_word(plus4):
                fns.add(plus4)
            if is_fn_word(minus4):
                fns.add(minus4)
            if len(fns) > 1:
                ambiguous.append((string_addr, frozenset(fns), site))
                continue
            if not fns:
                continue
            function = next(iter(fns))
            if is_fn_word(plus4) and is_fn_word(word_at(site + 8)):
                continue  # {name, fn, fn}: which fn is the handler is unknowable
            if is_fn_word(minus4) and is_fn_word(word_at(site - 8)):
                continue  # {fn, fn, name}: same problem on the other side
            records.append((string_addr, function, site))
    return records, ambiguous


def single_function_records(
    records: list[tuple[int, int, int]]
) -> dict[int, int]:
    """{string_addr: fn_addr} for strings whose records name exactly one fn.

    A string that appears in records of two distinct functions names neither
    (the same name string is shared by two dispatch entries), so it is
    dropped here.  Duplicate records for the same (string, fn) collapse.
    """
    by_string: dict[int, set[int]] = defaultdict(set)
    for string_addr, fn_addr, _site in records:
        by_string[string_addr].add(fn_addr)
    return {s: next(iter(fns)) for s, fns in by_string.items() if len(fns) == 1}


def unique_reference_names(
    ref_users: dict[int, set[int]],
    string_at: dict[int, bytes],
    allow: set[int],
) -> dict[int, int]:
    """Identifier strings referenced from exactly one allowed function.

    Returns {string_addr: fn_addr} where ``string_addr`` is a bare C
    identifier referenced from exactly one function in ``allow``.  This is
    the class-B/C candidate generator: a string referenced from two
    functions names neither, so it never appears here.
    """
    names: dict[int, int] = {}
    for string_addr, users in ref_users.items():
        text = string_at.get(string_addr)
        if text is None or not IDENTIFIER.match(text) or len(text) < 3:
            continue
        in_allow = users & allow
        if len(in_allow) != 1:
            continue  # zero or multiple referencers: no unique name
        names[string_addr] = next(iter(in_allow))
    return names


def load_owners() -> dict[int, list[Path]]:
    """Map canonical addresses to their src marker owners (relative paths)."""
    owners: dict[int, list[Path]] = defaultdict(list)
    for path in sorted(p for p in (REPO / "src").rglob("*.c") if not is_generated(p)):
        relative = path.relative_to(REPO)
        for marker in scan_markers(path):
            owners[marker["addr"]].append(relative)
    return dict(owners)


def p3_human_names() -> set[str]:
    """Human (non-placeholder) function names in the P3 FES decomp.

    The P3 producer will emit those names for the mapped P4 functions; any
    overlap would hard-fail reconciliation, so every colliding candidate is
    discarded.  Missing P3 checkout is not an error -- the check is skipped.
    """
    if not P3_SYMBOLS.is_file():
        return set()
    names: set[str] = set()
    line_re = re.compile(
        r"\s*([A-Za-z_]\w*)\s*=\s*0x[0-9A-Fa-f]{8}\s*;\s*//\s*type:func\b"
    )
    for line in P3_SYMBOLS.read_text(encoding="utf-8").splitlines():
        match = line_re.match(line)
        if match and not PLACEHOLDER.match(match.group(1)):
            names.add(match.group(1))
    return names


def existing_curated_names() -> set[str]:
    """Names already claimed by other config/symbol_names*.txt producers.

    The tool's own output file is excluded: it is the file being
    regenerated, not a competing producer.
    """
    names: set[str] = set()
    for path in sorted((REPO / "config").glob("symbol_names*.txt")):
        if path == OUTPUT:
            continue
        for line in path.read_text(encoding="utf-8").splitlines():
            stripped = line.strip()
            if not stripped or stripped.startswith("//"):
                continue
            match = re.match(r"\s*([A-Za-z_]\w*)\s*=", line)
            if match:
                names.add(match.group(1))
    return names


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--check",
        action="store_true",
        help="print the candidate census without writing the output file",
    )
    args = parser.parse_args()

    target = json.loads(TARGET.read_text(encoding="utf-8"))
    elf = RetailElf(str(REPO / "orig" / "SLUS_217.82"), target, target["elf"]["sha1"])
    windows = json.loads(FUNCTION_WINDOWS.read_text(encoding="utf-8"))["windows"]
    canonical = {int(address, 16): size for address, size in windows.items()}

    # Raw segment images (RetailElf validates the image; one read per segment).
    data1 = elf.bytes_at(DATA1_LO, DATA1_HI - DATA1_LO)
    data2 = elf.bytes_at(DATA2_LO, DATA2_HI - DATA2_LO)
    code1 = elf.bytes_at(CODE1_LO, CODE1_HI - CODE1_LO)
    code2 = elf.bytes_at(CODE2_LO, CODE2_HI - CODE2_LO)

    strings = extract_strings(data1, DATA1_LO, DATA1_HI, DATA1_LO)
    strings.update(extract_strings(data2, DATA2_LO, DATA2_HI, DATA2_LO))

    # Data-word indexes: which words hold a string address / a canonical fn.
    str_sites: dict[int, list[int]] = defaultdict(list)
    fn_word_sites: set[int] = set()
    for address, segment in ((DATA1_LO, data1), (DATA2_LO, data2)):
        for offset in range(0, len(segment), 4):
            site = address + offset
            value = int.from_bytes(segment[offset:offset + 4], "little")
            if value in strings:
                str_sites[value].append(site)
            if value in canonical:
                fn_word_sites.add(site)
    str_sites = dict(str_sites)

    def word_at(site: int) -> int:
        if DATA1_LO <= site < DATA1_HI:
            return int.from_bytes(data1[site - DATA1_LO:site - DATA1_LO + 4], "little")
        if DATA2_LO <= site < DATA2_HI:
            return int.from_bytes(data2[site - DATA2_LO:site - DATA2_LO + 4], "little")
        return 0

    def is_fn_word(value: int) -> bool:
        return value in canonical

    # Class A: {name, fn} record adjacency.
    records, ambiguous = record_candidates(str_sites, strings, word_at, is_fn_word)

    # Class B/C: strings referenced from code (all canonical functions).
    code_base = CODE1_LO
    code_bytes = code1 + code2
    code_words: list[int] = []
    for offset in range(0, len(code_bytes), 4):
        code_words.append(int.from_bytes(code_bytes[offset:offset + 4], "little"))
    ref_users: dict[int, set[int]] = defaultdict(set)
    for address, size in canonical.items():
        if address < CODE1_LO or address >= CODE2_HI:
            continue
        start = (address - code_base) // 4
        words = code_words[start:start + size // 4]
        for ref in absolute_references(words):
            if ref in strings:
                ref_users[ref].add(address)
    ref_users = dict(ref_users)

    # Third-party / SDK targets.
    owners = load_owners()
    code2_start = CODE2_LO

    def third_party(address: int) -> bool:
        if address >= code2_start:  # shared PS2 SDK/kernel blob, like libc_core
            return True
        return any(is_third_party(str(owner)) for owner in owners.get(address, []))

    # --- Class A acceptance -------------------------------------------------
    by_string = single_function_records(records)
    raw: dict[int, set[int]] = defaultdict(set)
    for string_addr, fn_addr, _site in records:
        raw[string_addr].add(fn_addr)
    discarded_multi_fn = {s for s, fns in raw.items() if len(fns) > 1}
    multi_ref_shared = {
        s for s, fns in by_string.items()
        if len(ref_users.get(s, ())) >= 2
    }
    accepted: dict[int, str] = {}
    accepted_strings: dict[int, bytes] = {}
    discarded_no_identifier = 0
    discarded_third_party = 0
    discarded_collision = 0
    p3_names = p3_human_names()
    existing = existing_curated_names()
    sites_of: dict[int, list[int]] = defaultdict(list)
    for string_addr, _fn_addr, site in records:
        sites_of[string_addr].append(site)
    prefix_counts: dict[str, int] = defaultdict(int)
    for string_addr, fn_addr in sorted(by_string.items()):
        if string_addr in discarded_multi_fn or string_addr in multi_ref_shared:
            continue
        if third_party(fn_addr):
            discarded_third_party += 1
            continue
        prefixes = {role_prefix(site) for site in sites_of[string_addr]}
        prefix = prefixes.pop() if len(prefixes) == 1 else NEUTRAL_PREFIX
        name = to_identifier(strings[string_addr], prefix)
        if name is None:
            discarded_no_identifier += 1
            continue
        if name in p3_names or name in existing:
            discarded_collision += 1
            continue
        accepted[fn_addr] = name
        accepted_strings[fn_addr] = strings[string_addr]
        prefix_counts[prefix] += 1

    # --- Report -------------------------------------------------------------
    class_a_candidates = len(by_string)
    print(f"class A  {{name,fn}} record adjacency")
    print(f"  data words holding a canonical fn address: {len(fn_word_sites)}")
    print(f"  data words holding a string address: {sum(len(v) for v in str_sites.values())}")
    print(f"  unambiguous record candidates: {class_a_candidates} strings")
    print(f"  ambiguous string-sites (canonical fns on both sides): {len(ambiguous)}")
    print(
        f"  discarded: names >1 distinct fn: {len(discarded_multi_fn)} | "
        f"referenced from >=2 functions: {len(multi_ref_shared)} | "
        f"third-party target: {discarded_third_party} | "
        f"not an identifier: {discarded_no_identifier} | "
        f"P3/curated name collision: {discarded_collision}"
    )
    print(f"  ACCEPTED: {len(accepted)}")
    for prefix in sorted(prefix_counts):
        print(f"    {prefix}: {prefix_counts[prefix]}")

    first_party = {
        a for a in canonical
        if a < CODE2_LO and not third_party(a)
    }
    unique_ref = unique_reference_names(ref_users, strings, first_party)
    print(f"class B/C debug/task-name strings referenced from exactly one function")
    print(f"  strings referenced from code: {len(ref_users)}")
    print(f"  referenced from >=2 functions (name none): {sum(1 for u in ref_users.values() if len(u) >= 2)}")
    print(f"  referenced from exactly 1 function: {len(unique_ref)}")
    print(f"  ACCEPTED: 0 (tags are CRI/SDK module names or unverifiable task callbacks; see module docstring)")
    print(f"class D  C++ RTTI: 0 strings with '::' or '_Z' mangling; ELF comment is the MW C compiler")

    if args.check:
        return 0

    if not accepted:
        raise SystemExit("no accepted names; refusing to write an empty symbol file")

    lines = [
        "// String-evidenced Persona 4 function names, mined from orig/SLUS_217.82",
        "// by tools/mine_name_strings.py. Regenerate with:",
        "//   python tools/mine_name_strings.py",
        "// Evidence: the name string sits in a data record whose function-pointer",
        "// field is the only canonical function in the record.",
    ]
    for fn_addr, name in sorted(accepted.items()):
        text = truncate(accepted_strings[fn_addr].decode("ascii", "replace"))
        lines.append(f'{name} = 0x{fn_addr:08X}; // type:func  evidence: string:"{text}"')
    OUTPUT.write_bytes(("\n".join(lines) + "\n").encode("utf-8"))
    print(f"wrote {OUTPUT.relative_to(REPO)} with {len(accepted)} names")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
