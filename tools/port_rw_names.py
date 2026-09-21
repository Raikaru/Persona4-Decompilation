"""Name Persona 4's vendor-library functions from other games' symbol tables.

Atlus linked RenderWare as prebuilt vendor libraries, so any other title
that linked the same objects carries the same code - and if that title
shipped its symbol table, it names ours.  The transfer rule here is
deliberately narrow:

  * the reference function must be **masked-identical** to the retail
    window: every instruction word equal after blanking `j`/`jal` targets
    and 16-bit immediates, which are exactly what relinking changes;
  * the retail address must be claimed by **one name only**.  Small bodies
    collide - five different `*Close` functions in NBA Ballers are
    byte-identical and all match `0x003C40D0` - and a colliding address
    tells you nothing about which name belongs to it.

Measured against the 392 RenderWare names this repo already proves: of the
634 addresses the rule fires on, 35 are in that set, and it gets **35 of 35
right**.  For comparison, the structural matcher in
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


def exact_claims(references: dict[str, Path], retail, windows):
    """retail address -> {name -> set of references proposing it}."""
    by_size: dict[int, list] = {}
    for text, size in windows["windows"].items():
        size = int(size)
        data = retail.bytes_at(int(text, 16), size)
        if data is None:
            continue
        raw = fid.words(data)
        by_size.setdefault(size, []).append(
            (int(text, 16), [fid.mask_word(word) for word in raw]))

    claims = collections.defaultdict(lambda: collections.defaultdict(set))
    widths: dict[int, int] = {}
    for tag, path in references.items():
        for name, _addr, body in fid.ReferenceElf(path).functions:
            if len(body) < 16 or not IDENTIFIER.match(name):
                continue
            mine = [fid.mask_word(word) for word in fid.words(body)]
            for pad in (0, 4, 8, 12):
                for their_addr, masked in by_size.get(len(body) + pad, ()):
                    if all(a == b for a, b in zip(mine, masked)):
                        claims[their_addr][name].add(tag)
                        widths[their_addr] = len(mine)
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
