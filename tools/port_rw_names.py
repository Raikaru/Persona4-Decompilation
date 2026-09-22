"""Name Persona 4's vendor-library functions from other games' symbol tables.

Atlus linked RenderWare as prebuilt vendor libraries, so any other title
that linked the same objects carries the same code - and if that title
shipped its symbol table, it names ours.  The transfer rule here is
deliberately narrow:

  * the reference function must be **relocation-identical** to the retail
    window: every word exactly equal, except at demonstrated relocations.
    A relocation is a `j`/`jal` target, the low half of a `lui`+`%lo`
    address pair, or a `$gp`-relative offset - and a differing constant
    pair proves relocation, since a literal compiles identically in both
    links. Everything else (stack sizes, field offsets, loop bounds, which
    registers, which opcode) compares byte-exact;
  * the retail address must be claimed by **one name only**.  Small bodies
    collide - five different `*Close` functions in NBA Ballers are
    byte-identical and all match `0x003C40D0` - and a colliding address
    tells you nothing about which name belongs to it.

Measured against the 392 RenderWare names this repo already proves: 3 of
the rule's claims are in that set, and it gets **3 of 3 right** - the
tree already owns most of the rest under its own names, which the
ownership veto excludes on purpose. An
earlier draft blanked ALL 16-bit immediates, which also erased stack
sizes and field offsets - two different functions then compared equal.
Preserving everything but demonstrated relocations is what makes the
match an identity.  For comparison, the structural matcher in
`docs/sky2/name-transfer-report.md` scored 0.650 on the same ground truth.
That gap is the difference between "these two functions look alike" and
"these two functions are the same object code".

A name is evidence of identity, not proof of authorship: where two games
give the same body two different names the address is skipped, and where a
body is shared the rule stays silent rather than guessing.

usage:
    python3 -E -s tools/port_rw_names.py \\
        --reference ballers=/path/to/SLUS_211.86 \\
        --reference burnout=/path/to/SLUS_212.42

The reference executables are commercial games and are not in the tree; the
generated `config/symbol_names.vendor.txt` is, and records which reference
backed each name.

Applying one of these is a separate decision, not automatic. Several of the
names are declared APIs - `RwFreeListCreate`, `memset` - and renaming a
definition to a declared name makes the header's prototype binding, so the
signature has to be right first. Running `apply_symbol_names.py` blindly
over `src/rw` turns 81 matched functions into 223 compile errors, which is
how this note got written.
"""
from __future__ import annotations

import argparse
import json
import collections
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402

from rw_reference import ReferenceElf, words  # noqa: E402

OUTPUT = REPO / "config" / "symbol_names.vendor.txt"
IDENTIFIER = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def claimed_elsewhere() -> tuple[set[str], set[int]]:
    """Names and addresses other producers in the contract already own."""
    names: set[str] = set()
    addresses: set[int] = set()
    for path in sorted((REPO / "config").glob("symbol_names*.txt")):
        if path == OUTPUT:
            continue
        for name, address in re.findall(r"^(\w+)\s*=\s*0x([0-9A-Fa-f]+)",
                                        path.read_text(encoding="utf-8"), re.M):
            names.add(name)
            addresses.add(int(address, 16))
    return names, addresses


def _reloc_words(raw: list[int], spans: list[tuple[int, int]]) -> set[int]:
    """Positions that may legitimately differ between two links of the same
    object.

    Three relocation shapes exist, and only demonstrated ones are relaxed:

      * a `j`/`jal` target;
      * a `$gp`-relative offset (addiu or load/store with base $28);
      * a `lui r,HI` whose VERY NEXT instruction consumes it as
        `%lo(r, HI)` in an addiu or load/store, and whose reconstructed
        32-bit value is an address in a loadable segment.

    At most one LUI can be pending, because a new LUI evicts it: with the
    single-slot rule, "very next instruction" is enforced by construction.
    No state survives any instruction that does not immediately consume
    the pending LUI, so pairing never crosses a basic block and an
    intermediate write of any kind - `ori`, `slti`, a load, another `lui`
    - kills it. After a pair completes, later `lw 4(r)` instructions are
    ordinary field accesses whose offsets are code.
    """
    relocs: set[int] = set()
    pending: tuple[int, int, int] | None = None   # (index, reg, hi half)
    for index, word in enumerate(raw):
        opcode = word >> 26
        rs = (word >> 21) & 0x1F
        rt = (word >> 16) & 0x1F
        if opcode == 0x0F:                        # lui rt, imm
            if rt:                                # a new LUI evicts any prior
                pending = (index, rt, word & 0xFFFF)
            else:
                pending = None
            continue
        if opcode in (0x08, 0x09):                # addi/addiu rt, rs, imm
            if rs == 28 and rt != 0:
                relocs.add(index)                 # gp-relative
            elif pending is not None and rs == rt and rt == pending[1]:
                relocs.update(_address_pair(pending, index, word, spans))
                pending = None
                continue
        elif opcode in (0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B,
                        0x31, 0x35, 0x39, 0x3F):  # loads/stores
            if rs == 28:
                relocs.add(index)                 # gp-relative access
            elif pending is not None and rs == pending[1]:
                relocs.update(_address_pair(pending, index, word, spans))
                pending = None
                continue
        elif opcode in (0x02, 0x03):
            relocs.add(index)
        # Anything else - arithmetic, logical, branches, anything that does
        # not immediately consume the pending LUI - clears it.
        pending = None
    return relocs


def _address_pair(entry: tuple[int, int, int], index: int, word: int,
                  spans: list[tuple[int, int]]) -> set[int]:
    """A lui+consumer pair is relocatable only if the reconstructed value is
    an address in a loadable segment; a large literal constant is code and
    must compare byte-exact."""
    lui_index, _reg, hi = entry
    low = word & 0xFFFF
    if low >= 0x8000:
        low -= 0x10000
    value = (hi << 16) + low
    if any(start <= value < start + size for start, size in spans):
        return {index, lui_index}
    return set()


def _padded_with_nops(raw: list[int], words: list[int]) -> bool:
    """An accepted window suffix must be alignment padding, nothing else."""
    return all(word == 0 for word in words[len(raw):])


def _relaxed(word: int) -> int:
    """A relocation word compares on everything but its address payload."""
    opcode = word >> 26
    if opcode in (0x02, 0x03):                   # j / jal: 6-bit opcode + target
        return word & 0xFC000000
    if opcode == 0x0F:                           # lui: opcode, rt, hi half
        return word & 0xFFFF0000
    return word & 0xFFFF0000                     # I-type: opcode, rs, rt


def _elf_spans(path: Path) -> list[tuple[int, int]]:
    """Loadable (vaddr, filesz) spans of a reference ELF, for the address test."""
    import struct as _struct
    data = path.read_bytes()
    if data[:4] != b"\x7fELF" or data[4] != 1:
        raise ValueError(f"{path}: not a 32-bit ELF")
    (_ident, _type, _machine, _version, _entry, phoff, _shoff, _flags,
     _ehsize, phentsize, phnum, *_rest) = \
        _struct.unpack_from("<16sHHIIIIIHHHHHH", data, 0)
    spans = []
    for index in range(phnum):
        ptype, _offset, vaddr, _paddr, filesz, _memsz, _flags, _align = \
            _struct.unpack_from("<8I", data, phoff + index * phentsize)
        if ptype == 1 and filesz:
            spans.append((vaddr, filesz))
    return spans


def vendor_family(name: str, authored: set, ref_addr: int | None = None) -> bool:
    """Whether a reference name comes from a library this transfer covers.

    The references carry their WHOLE image - game code, middleware, libc -
    and a unique masked shape does not make a Criterion game class method
    a Persona 4 fact. Authoritative membership is the Ballers RW DWARF
    unit inventory (which includes non-Rw spellings like matrixASMMult
    and DefaultGeomAnimCB); the spelling fallback covers libc and Sony
    runtime symbols Ballers does not compile from source. C++-mangled
    game names are rejected outright.
    """
    if "__" in name[2:] or re.match(r"^\w+__F", name):
        return False                            # C++-mangled game code
    if ref_addr is not None and (name, ref_addr) in authored:
        return True                             # RW units, authoritative
    return (name.startswith("__") or name in {
        "atof", "atoi", "exit", "malloc", "calloc", "realloc", "free",
        "memcpy", "memset", "memmove", "strcpy", "strncpy", "strlen",
        "strcmp", "strncmp", "strcat", "sprintf", "qsort", "sinf",
        "cosf", "tanf", "sqrtf", "powf", "logf", "expf", "fmodf",
        "ceilf", "floorf", "atan2f", "asinf", "acosf", "fabsf"})


def _target_owned() -> set:
    """Canonical addresses the tree already implements under a real name.

    Uses verify's own marker scan: every `// FUN_XXXXXXXX` marker paired
    with what follows it. A marker followed by a named definition (not a
    placeholder, not INCLUDE_ASM) is owned - e.g. CRI's `MWSTM_Create` at
    0x00512138, which a vendor `atof` claim must not overwrite even
    though the bytes happen to agree. INCLUDE_ASM markers are NOT owned;
    those are exactly what this transfer is allowed to name.
    """
    owned = set()
    for path in (REPO / "src").rglob("*.c"):
        for marker in V.scan_markers(path):
            if marker.get("asm") or marker.get("stub"):
                continue
            name = marker.get("name") or ""
            if not name or re.match(r"^func_[0-9a-f]{8}$", name):
                continue
            owned.add(marker["addr"])
    return owned


def rw_unit_names() -> set:
    """(name, reference address) pairs the Ballers DWARF attributes to a
    RenderWare unit.

    Keyed by address as well as name: a RW name attached to a different
    address is not the DWARF's function, it is a same-named symbol
    elsewhere in the image. Burnout contributes nothing here - it has no
    DWARF unit inventory, so its symbols may only corroborate a claim
    Ballers already originated.
    """
    pairs = set()
    for path in ("ballers_rw_units.json", "ballers_sky2_units.json"):
        try:
            units = json.loads((REPO / "docs" / "sky2" / path).read_text())
        except (OSError, ValueError):
            continue
        for fns in units.values():
            for fn in fns:
                pairs.add((fn["name"], int(fn["addr"], 16)))
    return pairs


def exact_claims(references: dict[str, Path], retail, windows):
    """retail address -> {name -> set of references proposing it}."""
    spans = [(vaddr, filesz) for vaddr, _offset, filesz in retail.segs]
    by_size: dict[int, list] = {}
    for text, size in windows["windows"].items():
        size = int(size)
        data = retail.bytes_at(int(text, 16), size)
        if data is None:
            continue
        raw = words(data)
        relocs = _reloc_words(raw, spans)
        by_size.setdefault(size, []).append(
            (int(text, 16), raw, relocs,
             [_relaxed(word) if index in relocs else word
              for index, word in enumerate(raw)]))

    authored = rw_unit_names()
    owned = _target_owned()
    claims = collections.defaultdict(lambda: collections.defaultdict(set))
    widths: dict[int, int] = {}
    ballers_first = list(references) == ["ballers"] + [
        t for t in references if t != "ballers"]
    for tag, path in references.items():
        # One read per reference, not one per function: a 48 MB image read
        # 20k times is a terabyte of pointless page-cache traffic.
        ref_spans = _elf_spans(path)
        for name, _addr, body in ReferenceElf(path).functions:
            if len(body) < 16 or not IDENTIFIER.match(name):
                continue
            if not vendor_family(name, authored, _addr):
                continue
            raw_ref = words(body)
            ref_relocs = _reloc_words(raw_ref, ref_spans)
            theirs = [_relaxed(word) if index in ref_relocs else word
                      for index, word in enumerate(raw_ref)]
            for pad in (0, 4, 8, 12):
                for their_addr, raw, relocs, masked in by_size.get(len(body) + pad, ()):
                    # A longer retail window is acceptable only if the extra
                    # suffix is alignment padding; the comparison itself runs
                    # over the reference function's own length.
                    if pad and not _padded_with_nops(raw_ref, raw):
                        continue
                    # A word relaxed on one side only must not match an exact
                    # word on the other: the classes have to agree, since a
                    # relocation exists in both links of the same object or
                    # in neither.
                    if ref_relocs != {i for i in relocs if i < len(raw_ref)}:
                        continue
                    if all(a == b for a, b in zip(theirs, masked)):
                        if their_addr in owned:
                            continue
                        rw_origin = (name, _addr) in authored
                        if (tag != "ballers" and rw_origin
                                and name not in claims[their_addr]):
                            continue    # Burnout corroborates, never originates
                        claims[their_addr][name].add(tag)
                        widths[their_addr] = len(raw_ref)
    return claims, widths


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--reference", action="append", default=[],
                        metavar="TAG=PATH", help="a symbol-bearing reference ELF")
    args = parser.parse_args()
    references = {}
    for item in args.reference:
        tag, _, path = item.partition("=")
        if not path:
            print(f"--reference wants TAG=PATH, got {item!r}", file=sys.stderr)
            return 2
        references[tag] = Path(path)

    config = V.load_config()
    target = V._read_json(V.TARGET)
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(config["retail_elf"], target, windows["sha1"])
    canonical = {int(address, 16) for address in windows["windows"]}

    # Ballers first: its DWARF gives RW claims authoritative origin, keyed
    # by (name, reference address). Burnout may then only corroborate an
    # existing claim - it never originates one, because it has no CU
    # inventory to prove a same-named symbol is the same function.
    ordered = {tag: references[tag] for tag in
               ("ballers", "burnout") if tag in references}
    ordered.update({t: p for t, p in references.items()
                    if t not in ("ballers", "burnout")})
    claims, widths = exact_claims(ordered, retail, windows)
    taken_names, taken_addresses = claimed_elsewhere()

    # A name may only be written once, so a name that fits several addresses
    # equally well identifies none of them.
    chosen: dict[int, tuple[str, set[str]]] = {}
    authored = rw_unit_names()
    for address, names in sorted(claims.items()):
        if len(names) != 1 or address not in canonical or address in taken_addresses:
            continue
        name, who = next(iter(names.items()))
        if name in taken_names:
            continue
        chosen[address] = (name, who)
    duplicated = {name for name, count in collections.Counter(
        name for name, _who in chosen.values()).items() if count > 1}
    for address in [a for a, (n, _w) in chosen.items() if n in duplicated]:
        del chosen[address]

    lines = [
        "// Persona 4 vendor-library function names transferred from other",
        "// games' symbol tables - RenderWare, and the Sony/CRT code linked",
        "// beside it. Generated by tools/port_rw_names.py; rewritten",
        "// wholesale each run. Do not hand-edit.",
        "//",
        "// A name is here only if the reference function is",
        "// relocation-class-identical to the retail window: every word",
        "// byte-exact except at demonstrated relocations (j/jal targets,",
        "// gp-relative offsets, and a lui whose very next instruction",
        "// consumes it as %lo with a loadable-segment address), with both",
        "// sides agreeing on where the relocations are, and only if exactly",
        "// one name claims that address. Measured 3 of 3 correct against the",
        "// names this repo already proves; see the module docstring.",
        "//",
        "// Ballers' DWARF originates every RenderWare claim; Burnout (no CU",
        "// inventory) may only corroborate - except CRT/libc spellings,",
        "// which carry no CU provenance anywhere and stand on its symtab.",
        "//",
        "// Applying one is a separate decision: where the name is a declared",
        "// API the header's prototype becomes binding, so fix the signature",
        "// in the same change or the unit stops compiling.",
        f"// {len(chosen)} names from {', '.join(sorted(references))}.",
        "",
    ]
    for address, (name, who) in sorted(chosen.items()):
        lines.append(
            f"{name} = 0x{address:08X}; // type:func  evidence: "
            f"{'+'.join(sorted(who))} reloc-identical over {widths[address]} words, "
            f"sole claimant")
    OUTPUT.write_text("\n".join(lines) + "\n", encoding="utf-8")

    skipped = sum(1 for names in claims.values() if len(names) > 1)
    print(f"{len(claims)} addresses reloc-identical; {skipped} skipped as "
          f"contested, {len(duplicated)} names dropped as reused")
    print(f"{len(chosen)} names -> {OUTPUT.relative_to(REPO)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
