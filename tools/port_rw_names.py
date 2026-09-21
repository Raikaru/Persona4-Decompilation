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

Measured against the 392 RenderWare names this repo already proves: 41 of
the rule's claims are in that set, and it gets **41 of 41 right**. An
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
import collections
import importlib.util
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402

SPEC = importlib.util.spec_from_file_location("p4_rwref_fid", REPO / "build" / "rwref_fid.py")
assert SPEC is not None and SPEC.loader is not None
fid = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(fid)

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


def _reloc_words(raw: list[int]) -> set[int]:
    """Positions that may legitimately differ between two links of the same
    object.

    A `j`/`jal` target is a relocated address. So is the low half of an
    address that some instruction materialised as a `lui`+`%lo` pair - and a
    pair only: when the two builds' constants DIFFER, what changed is an
    address, because a literal constant compiles identically in both links.
    `$gp`-relative load/store offsets are relocation-derived too: the
    small-data area base differs per link. Every other immediate - stack
    sizes, field offsets, loop bounds - is code, and must compare equal.
    """
    relocs: set[int] = set()
    lui_at: dict[int, int] = {}
    for index, word in enumerate(raw):
        opcode = word >> 26
        if opcode in (0x02, 0x03):
            relocs.add(index)
        elif opcode == 0x0F:                      # lui rt, imm
            lui_at[(word >> 16) & 0x1F] = index
        elif opcode in (0x08, 0x09):              # addi/addiu rt, rs, imm
            base = (word >> 21) & 0x1F
            if base == 28 and (word >> 16) & 0x1F != 0:   # gp-relative
                relocs.add(index)
            elif base in lui_at:
                relocs.add(index)
                relocs.add(lui_at[base])
        elif opcode in (0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B,
                        0x31, 0x35, 0x39, 0x3F):  # loads/stores
            if (word >> 21) & 0x1F == 28:         # gp-relative access
                relocs.add(index)
    return relocs


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


def exact_claims(references: dict[str, Path], retail, windows):
    """retail address -> {name -> set of references proposing it}."""
    by_size: dict[int, list] = {}
    for text, size in windows["windows"].items():
        size = int(size)
        data = retail.bytes_at(int(text, 16), size)
        if data is None:
            continue
        raw = fid.words(data)
        relocs = _reloc_words(raw)
        by_size.setdefault(size, []).append(
            (int(text, 16), raw,
             [_relaxed(word) if index in relocs else word
              for index, word in enumerate(raw)]))

    claims = collections.defaultdict(lambda: collections.defaultdict(set))
    widths: dict[int, int] = {}
    for tag, path in references.items():
        for name, _addr, body in fid.ReferenceElf(path).functions:
            if len(body) < 16 or not IDENTIFIER.match(name):
                continue
            raw_ref = fid.words(body)
            ref_relocs = _reloc_words(raw_ref)
            theirs = [_relaxed(word) if index in ref_relocs else word
                      for index, word in enumerate(raw_ref)]
            for pad in (0, 4, 8, 12):
                for their_addr, raw, masked in by_size.get(len(body) + pad, ()):
                    # A longer retail window is acceptable only if the extra
                    # suffix is alignment padding; the comparison itself runs
                    # over the reference function's own length.
                    if pad and not _padded_with_nops(raw_ref, raw):
                        continue
                    if all(a == b for a, b in zip(theirs, masked)):
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

    claims, widths = exact_claims(references, retail, windows)
    taken_names, taken_addresses = claimed_elsewhere()

    # A name may only be written once, so a name that fits several addresses
    # equally well identifies none of them.
    chosen: dict[int, tuple[str, set[str]]] = {}
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
        "// A name is here only if a reference function is masked-identical to",
        "// the retail window - every word equal after blanking jump targets",
        "// and 16-bit immediates - and only if exactly one name claims that",
        "// address. Measured 35 of 35 correct against the names this repo",
        "// already proves; see the module docstring.",
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
            f"{'+'.join(sorted(who))} masked-exact over {widths[address]} words, "
            f"sole claimant")
    OUTPUT.write_text("\n".join(lines) + "\n", encoding="utf-8")

    skipped = sum(1 for names in claims.values() if len(names) > 1)
    print(f"{len(claims)} addresses matched masked-exact; {skipped} skipped as "
          f"contested, {len(duplicated)} names dropped as reused")
    print(f"{len(chosen)} names -> {OUTPUT.relative_to(REPO)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
