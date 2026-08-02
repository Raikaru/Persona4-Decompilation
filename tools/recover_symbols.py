#!/usr/bin/env python3
"""Recover named data/function symbol addresses from matched C.

The retail ELF is stripped, so there is no symbol table to link C objects
against. This tool bootstraps one: it compiles every source file, and for each
relocation in a byte-matching function it reads the resolved value out of the
retail bytes and backs out the compiled addend, yielding the referenced
symbol's address. Data-section relocations of matched objects are decoded the
same way, from the section base recovered out of the matched functions' own
relocations. A symbol is only emitted when every matched reference agrees on
the same address (cross-file consistency is the validator), so a single wrong
or shared-%hi reference drops the symbol instead of poisoning the table.

Addresses encoded in the names themselves (D_<addr>, DAT_<addr>[_abs],
PTR_DAT_<addr>, jtbl_<addr>, [ifsu]Gp<off>, gp0x<off>, func_<addr>/FUN_<addr>,
LAB_<addr>) are verified against the recovered value; a disagreement means
the source name is a mislabel (the retail instructions are ground truth), so
the symbol is emitted at the recovered address and the disagreement is
reported. Every emitted address is sanity-checked against the segment map and
the canonical function-window table. Names the splat undefined lists already
define are left to those lists; everything else is emitted, including names
also defined by C or asm objects -- mwldps2 prefers the object's definition
when both exist (both resolve to the same retail address), and the linker-
command-file entry is exactly what makes a reference resolvable when the
defining object is not linked.

Output: config/symbols_recovered.txt, consumed by build.py::load_lcf_symbols.
`_gp` comes from config/target.json and is cross-checked against the retail
ELF's .reginfo ri_gp_value.

Usage:
  python tools/recover_symbols.py            # write config/symbols_recovered.txt
  python tools/recover_symbols.py --print    # print, do not write
"""
from __future__ import annotations

import collections
import re
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import verify as V        # noqa: E402
import build as B         # noqa: E402
import build_cache as BC  # noqa: E402

OUT = REPO / "config" / "symbols_recovered.txt"

# MIPS ELF32 psABI relocation types used by mwccps2/mwldps2 output.
R_MIPS_32 = 2
R_MIPS_26 = 4
R_MIPS_HI16 = 5
R_MIPS_LO16 = 6
R_MIPS_GPREL16 = 7

# Legitimate absolute data targets outside the loadable image: EE RAM below
# and above the image (runtime heap, e.g. 0x008873ec), its KSEG0/KSEG1
# mirrors, the scratchpad, and the I/O controller / BIOS window.
ABSOLUTE_RANGES = (
    (0x00000000, 0x00100000),  # EE RAM below the image
    (0x00764280, 0x02000000),  # EE RAM above the image
    (0x70000000, 0x70004000),  # scratchpad
    (0x1F800000, 0x1FC00000),  # I/O controller + BIOS ROM window
    (0x80000000, 0x801FFFFF),  # KSEG0 RAM mirror
    (0xA0000000, 0xA01FFFFF),  # KSEG1 RAM mirror
    (0x9F800000, 0x9FC00000),  # KSEG1 I/O mirror
    (0xBF800000, 0xBFC00000),  # KSEG1 I/O mirror
)

_GP_NAME_RE = re.compile(r"^(?:[ifsu]Gp|gp0x)([0-9A-Fa-f]{6,8})$")
_DATA_NAME_RE = re.compile(r"^(?:(?:PTR_)?(?:D|DAT)|jtbl)_([0-9A-Fa-f]{8})(?:_\w+)*$")
_FUNC_NAME_RE = re.compile(r"^(?:func|FUN)_([0-9A-Fa-f]{8})(?:_\w+)*$")
_LABEL_NAME_RE = re.compile(r"^LAB_([0-9A-Fa-f]{8})(?:_\w+)*$")
_ASM_LABEL_RE = re.compile(r"^\s*(?:\.globl|glabel)\s+([A-Za-z_.$][\w.$]*)")
_LCF_LINE_RE = re.compile(r"\s*([A-Za-z_.$][\w.$]*)\s*=")


def _s16(x: int) -> int:
    x &= 0xFFFF
    return x - 0x10000 if x & 0x8000 else x


def _s24(x: int) -> int:
    x &= 0xFFFFFF
    return x - 0x1000000 if x & 0x800000 else x


def _w32(blob: bytes, offset: int) -> int:
    return struct.unpack_from("<I", blob, offset)[0]


def _w16(blob: bytes, offset: int) -> int:
    return struct.unpack_from("<H", blob, offset)[0]


def decode_abs_pair(hi_compiled: int, hi_retail: int,
                    lo_compiled: int, lo_retail: int) -> int:
    """Reconstruct the 32-bit target of an R_MIPS_HI16/R_MIPS_LO16 pair.

    The LO16 field is sign-extended, so the HI16 half is the target's high
    half only after the negative low half is folded back in (e.g. target
    0x0088f3ec encodes as %hi 0x0089, %lo 0xf3ec). The compiled addend is
    reconstructed with the same convention and subtracted.
    """
    return (((hi_retail & 0xFFFF) << 16) + _s16(lo_retail)) - (
        ((hi_compiled & 0xFFFF) << 16) + _s16(lo_compiled)
    )


def decode_gprel(gp: int, imm_compiled: int, imm_retail: int) -> int:
    """R_MIPS_GPREL16: the linked field is S + A - gp, the compiled field A."""
    return gp + (_s16(imm_retail) - _s16(imm_compiled))


def decode_jump26(imm_compiled: int, imm_retail: int, pc: int) -> int:
    """R_MIPS_26: the linked field is the low 28 bits of S + A, upper bits PC."""
    target = ((imm_retail & 0x03FFFFFF) << 2) | ((pc + 4) & 0xF0000000)
    return target - ((imm_compiled & 0x03FFFFFF) << 2)


def decode_w32(word_compiled: int, word_retail: int) -> int:
    """R_MIPS_32 in a data section: the linked word is S + A."""
    return word_retail - word_compiled


def name_encoded_address(name: str, gp: int) -> tuple[int | None, str | None]:
    """Return (address, form) when the name itself encodes its address.

    Conventions in use across src/:
      D_<addr> / DAT_<addr> / PTR_DAT_<addr> / jtbl_<addr>  absolute address,
        with optional _<suffix> annotations (e.g. DAT_008873ec_abs);
      [ifsu]Gp<off> / gp0x<off>  _gp-relative offset, sign-extended from 24
        bits (e.g. iGpfffb3ac == _gp - 0x4c54 == 0x0076449c);
      func_<addr> / FUN_<addr>   function address, with optional _<suffix>
        annotations (e.g. func_00276e70_typed);
      LAB_<addr>                 code label inside a function (mid-function
        branch targets), so the address may sit inside a function window.
    """
    match = _GP_NAME_RE.match(name)
    if match:
        return gp + _s24(int(match.group(1), 16)), "gp"
    match = _DATA_NAME_RE.match(name)
    if match:
        return int(match.group(1), 16), "abs"
    match = _FUNC_NAME_RE.match(name)
    if match:
        return int(match.group(1), 16), "func"
    match = _LABEL_NAME_RE.match(name)
    if match:
        return int(match.group(1), 16), "label"
    return None, None


def classify_address(address: int, segments: list) -> str:
    """'code', 'data', 'absolute', or 'unknown' for a recovered address."""
    for _name, kind, start, end in segments:
        if start <= address < end:
            return kind
    for lo, hi in ABSOLUTE_RANGES:
        if lo <= address < hi:
            return "absolute"
    return "unknown"


def address_problems(name: str, address: int, kinds: set, windows: set,
                     segments: list, gp: int) -> list[str]:
    """Sanity-check a recovered address against segments and function windows.

    Function-kind evidence (R_MIPS_26), an address-encoded func_/FUN_/LAB_
    name, or an address that is exactly a canonical window start (a function
    pointer loaded via %hi/%lo) must land on a canonical function window start
    (LAB_ labels may sit mid-window). Everything else must land in a data
    segment or a legitimate absolute range, and never inside a function window
    (the window table tiles every code byte of the image).
    """
    problems = []
    segment = classify_address(address, segments)
    encoded, form = name_encoded_address(name, gp)
    is_func = ("func" in kinds or form == "func" or address in windows)
    if form == "label":
        # A code label inside a function: allowed anywhere in code, but still
        # needs a sane location.
        if segment == "unknown":
            problems.append(
                f"{name}: label-kind address {address:#010x} is outside every "
                "segment and absolute range"
            )
    elif is_func:
        if address not in windows:
            problems.append(
                f"{name}: function-kind address {address:#010x} ({segment}) "
                "is not a canonical function window start"
            )
    else:
        if segment == "code":
            problems.append(
                f"{name}: data-kind address {address:#010x} lands in a code segment"
            )
        elif segment == "unknown":
            problems.append(
                f"{name}: data-kind address {address:#010x} is outside every "
                "segment and absolute range"
            )
    if address == 0:
        problems.append(f"{name}: recovered address 0 is not linkable")
    return problems


def select_symbols(recovered: dict, kinds: dict, gp: int, windows: set,
                   segments: list, exclude: set) -> tuple:
    """Split recovered evidence into emit-ready symbols and rejected ones.

    Returns (emitted, conflicts, name_agree, name_disagree, segment_failures).
    A symbol with more than one distinct recovered address is rejected
    outright: cross-file consistency is the whole safety argument.
    """
    consistent = {}
    conflicts = {}
    for name, counter in recovered.items():
        if len(counter) == 1:
            consistent[name] = next(iter(counter))
        else:
            conflicts[name] = dict(counter)
    emitted = {}
    name_agree = []
    name_disagree = []
    segment_failures = []
    for name, address in sorted(consistent.items()):
        if name in exclude:
            continue
        encoded, _form = name_encoded_address(name, gp)
        if encoded is not None:
            if encoded != address:
                # The name encodes a different address than every matched
                # reference resolves to. The recovered value is the ground
                # truth (byte-exact retail instructions), so the name is a
                # source mislabel: emit the recovered address anyway and
                # report the disagreement.
                name_disagree.append((name, address, encoded))
            else:
                name_agree.append(name)
        problems = address_problems(name, address, kinds.get(name, set()),
                                    windows, segments, gp)
        if problems:
            segment_failures.extend(problems)
            continue
        emitted[name] = address
    return emitted, conflicts, name_agree, name_disagree, segment_failures


def asm_defined_names() -> set:
    """Global labels the asm objects define (glabel/.globl under asm/)."""
    names = set()
    for path in (REPO / "asm").rglob("*.s"):
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue
        for line in text.splitlines():
            match = _ASM_LABEL_RE.match(line)
            if match:
                names.add(match.group(1))
    return names


def auto_defined_names() -> set:
    """Symbols splat's undefined lists already ask the linker to define."""
    names = set()
    for fname in ("undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
        path = REPO / fname
        if not path.is_file():
            continue
        for line in path.read_text(errors="replace").splitlines():
            match = _LCF_LINE_RE.match(line)
            if match:
                names.add(match.group(1))
    return names


def gp_value(retail_path: str) -> int | None:
    """Read ri_gp_value from the retail ELF .reginfo section (o32 layout)."""
    data = Path(retail_path).read_bytes()
    _endian, sections = V.elf_sections(data)
    for section in sections:
        if section.get("name") == ".reginfo" and section["size"] >= 24:
            return _w32(data, section["offset"] + 20)
    return None


def recover(c: dict) -> tuple:
    """Compile every source file and collect relocation-derived addresses.

    Returns (gp, recovered, kinds, c_exports). Only byte-matched functions
    contribute evidence -- matching C bodies, and INCLUDE_ASM fallbacks whose
    assembled bytes are the retail bytes verbatim (their relocations are real
    link requirements with the same addend semantics). Stubs, NONMATCHING C
    bodies (never compiled) and generated candidates are skipped, exactly as
    the eligibility planner treats them.
    """
    retail = V.RetailElf(c["retail_elf"], B.TARGET, B.RETAIL_SHA1)
    gp = B.parse_int(B.ELF_TARGET["gp"])
    cache = BC.ObjectCache(B.BUILD / "cache" / "c", B.REPO)
    recovered = collections.defaultdict(collections.Counter)
    kinds = collections.defaultdict(set)
    c_exports = set()

    sources = sorted(p for p in (B.REPO / "src").rglob("*.c")
                     if not V.is_generated(p))
    for cpath in sources:
        try:
            markers = V.scan_markers(cpath)
        except OSError:
            continue  # source vanished mid-scan (parallel tooling); skip it
        matched = [m for m in markers
                   if m["name"] and not m["stub"]
                   and (not m["nonmatching"] or m.get("asm"))]
        try:
            obj = B.compile_eligibility(c, cpath, cache)
        except OSError:
            continue
        if obj is None:
            continue
        symtab = {s["name"]: s.get("shndx", 0) for s in obj.symbols}
        c_exports |= {s["name"] for s in obj.symbols
                      if s["name"] and s.get("shndx", 0) != 0}
        good = []
        for m in matched:
            try:
                body, rels = obj.function(m["name"])
            except (KeyError, ValueError):
                continue
            try:
                win = retail.bytes_at(m["addr"], len(body))
            except ValueError:
                continue
            if V.compare(body, rels, win)[0] != 0:
                continue
            good.append(m)
            pending = collections.defaultdict(list)
            for r in rels:
                offset, rtype, nm = r["offset"], r["r_type"], r["symbol"]
                if not nm or symtab.get(nm, 0) != 0 or offset + 4 > len(body):
                    continue
                wc, wr = _w32(body, offset), _w32(win, offset)
                if rtype == R_MIPS_26:
                    recovered[nm][decode_jump26(wc, wr, m["addr"] + offset)] += 1
                    kinds[nm].add("func")
                elif rtype == R_MIPS_HI16:
                    pending[nm].append((wc, wr))
                elif rtype == R_MIPS_LO16:
                    for hc, hr in pending[nm]:
                        recovered[nm][decode_abs_pair(hc, hr, wc, wr)] += 1
                        kinds[nm].add("abs")
                    pending[nm] = []
                elif rtype == R_MIPS_GPREL16:
                    recovered[nm][decode_gprel(gp, wc, wr)] += 1
                    kinds[nm].add("gp")
        if not good:
            continue
        # Data-section relocations resolve against retail at the section base
        # recovered from the matched functions' own data references.
        bases = B.recover_section_bases(obj, good, retail, gp)
        for section in obj.sh:
            if (section.get("name") not in B.DATA_SECTIONS
                    or section["idx"] not in bases):
                continue
            base = bases[section["idx"]]
            for offset, rtype, nm in B.section_relocs(obj, section["idx"]):
                if not nm or symtab.get(nm, 0) != 0 or offset + 4 > section["size"]:
                    continue
                try:
                    rw = retail.bytes_at(base + offset, 4)
                except ValueError:
                    continue
                if rtype == R_MIPS_32:
                    recovered[nm][decode_w32(
                        _w32(obj.data, section["offset"] + offset), _w32(rw, 0))] += 1
                    kinds[nm].add("abs")
                elif rtype == R_MIPS_GPREL16:
                    recovered[nm][decode_gprel(
                        gp, _w16(obj.data, section["offset"] + offset), _w16(rw, 0))] += 1
                    kinds[nm].add("gp")
    return gp, recovered, kinds, c_exports


def main() -> None:
    c = B.cfg()
    B.AS_TOOL = B.A.find_gnu_tool("mipsel-linux-gnu-as", "P4_AS")
    B.OBJCOPY_TOOL = B.A.find_gnu_tool("mipsel-linux-gnu-objcopy", "P4_OBJCOPY")
    B.CACHE_TOOL_VERSIONS = {
        "assembler": BC.tool_version_identity(B.AS_TOOL.argv),
        "objcopy": BC.tool_version_identity(B.OBJCOPY_TOOL.argv),
        "python": {
            "implementation": sys.implementation.name,
            "cache_tag": sys.implementation.cache_tag,
            "version": list(sys.version_info[:3]),
        },
    }
    gp, recovered, kinds, c_exports = recover(c)
    reginfo_gp = gp_value(c["retail_elf"])
    if reginfo_gp is not None and reginfo_gp != gp:
        sys.stderr.write(
            f"recover_symbols: WARNING target.json gp {gp:#x} disagrees with "
            f".reginfo ri_gp_value {reginfo_gp:#x}\n"
        )
    windows = set(B.load_windows())
    # Names the splat undefined lists already ask the linker to define (at the
    # same address recovery finds: 170/170 agree). Emitting them would be a
    # no-op, so they are left to those lists. Everything else -- including
    # names also defined by C or asm objects -- is emitted: mwldps2 prefers the
    # object's definition when both exist, and both resolve to the same retail
    # address, while the LCF entry is what makes a reference resolvable when
    # the defining object is not linked (the case the eligibility check and
    # the link both need).
    exclude = {"_gp"} | auto_defined_names()
    emitted, conflicts, name_agree, name_disagree, segment_failures = (
        select_symbols(recovered, kinds, gp, windows, B.TARGET_SEGMENTS, exclude)
    )
    markers = B.source_marker_names()
    glabels = asm_defined_names()
    already_owned = {nm for nm in emitted
                     if nm in markers or nm in c_exports or nm in glabels}
    lines = [
        "// Recovered symbol addresses (generated by tools/recover_symbols.py).",
        "// Addresses inferred from matched-function relocations against the",
        "// retail image; only cross-file-consistent symbols are emitted (a",
        "// symbol with conflicting evidence is dropped). Do not hand-edit.",
        f"_gp = {gp:#010x}; // type:gp",
    ]
    for name, address in sorted(emitted.items(), key=lambda kv: (kv[1], kv[0])):
        lines.append(f"{name} = {address:#010x}; // type:data")
    text = "\n".join(lines) + "\n"
    if "--print" in sys.argv:
        sys.stdout.write(text)
    else:
        OUT.write_bytes(text.encode("utf-8"))
    excluded = sorted(set(recovered) & exclude)
    sys.stderr.write(
        f"recover_symbols: gp={gp:#x} emitted={len(emitted)} "
        f"conflicts={len(conflicts)} name_encoded_agree={len(name_agree)} "
        f"name_encoded_disagree={len(name_disagree)} "
        f"segment_failures={len(segment_failures)} "
        f"left_to_auto_lists={len(excluded)} "
        f"emitted_but_also_object_defined={len(already_owned)} -> {OUT.name}\n"
    )
    if conflicts:
        sys.stderr.write("  dropped (inconsistent evidence): "
                         + ", ".join(sorted(conflicts)) + "\n")
    if name_disagree:
        sys.stderr.write("  emitted despite name-encoded disagreement "
                         "(source mislabels; recovered value is retail truth): "
                         + ", ".join(f"{nm}={addr:#x} (name says {enc:#x})"
                                     for nm, addr, enc in name_disagree) + "\n")
    if segment_failures:
        sys.stderr.write("  dropped (segment/window check): "
                         + "; ".join(segment_failures) + "\n")
    if excluded:
        sys.stderr.write("  left to splat undefined lists: "
                         + ", ".join(excluded) + "\n")


if __name__ == "__main__":
    main()
