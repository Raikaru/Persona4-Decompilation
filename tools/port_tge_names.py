#!/usr/bin/env python3
"""Port tge-was-taken's Persona 3 FES library names to Persona 4 by twin matching.

tge-was-taken's P3FES decompilation names its third-party library code under
`// lib/<dir>/<library>/<module>` section headers in
config/SLUS_216.21/symbol_addrs.txt. Only functions under those headers are
considered. Game-code names are never ported by this tool.

A P3 library name is written for a Persona 4 window only when all of these hold:

  * the P3 window and the P4 window are relocation-identical under the rule in
    port_rw_names.py: every word is byte-exact except demonstrated relocations
    (j/jal targets, gp-relative offsets, lui+%lo pairs with a loadable-segment
    address), which must sit at the same positions on both sides; a longer P4
    window is accepted only when its extra suffix is zero alignment padding;
  * the body is unique in its image: exactly one P3 window and exactly one P4
    window share the signature, and that P4 window has no other P3 partner;
  * the P4 window is not already implemented under a real name, is not named by
    another producer, and its owner is not first-party code;
  * the name is not already claimed by another producer and does not occur as an
    identifier in src/ or include/ (a declared API would need its prototype fixed
    first, so such names are reported instead of applied).

Output: config/symbol_names.tge.txt, one `evidence: tge-p3:<name>@0x<addr>` row
per accepted name. Usage:

    python tools/port_tge_names.py --tge <path to tge symbol_addrs.txt>
"""

from __future__ import annotations

import argparse
import collections
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import verify as V  # noqa: E402
from port_p3_names import name_junk, owners_by_address, write_output  # noqa: E402
from port_rw_names import _elf_spans, _reloc_words, _relaxed, _target_owned  # noqa: E402
from rw_reference import words  # noqa: E402

OUTPUT = REPO / "config" / "symbol_names.tge.txt"
DEFAULT_P3_ROOT = REPO.parents[2] / "Persona3-FES-Decompilation"
P3_ELF = Path("build") / "SLUS_216.21"
P3_WINDOWS = Path("tools") / "slus21621_functions.json"

# tge's line contract: `Name = 0xADDR; // type:func` (other types are data).
TGE_LINE = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]{8})\s*;\s*//\s*type:(\w+)")
MIN_BYTES = 16
COMMENT_OR_LITERAL = re.compile(
    r"/\*.*?\*/|//[^\n]*|\"(?:\\.|[^\"\\\n])*\"|'(?:\\.|[^'\\\n])*'", re.S
)
IDENTIFIER = re.compile(r"[A-Za-z_]\w*")


class ElfImage:
    """PT_LOAD view of a 32-bit little-endian ELF (same surface as V.RetailElf)."""

    def __init__(self, path: Path):
        self.data = path.read_bytes()
        if self.data[:4] != b"\x7fELF" or self.data[4] != 1:
            raise SystemExit(f"port_tge_names: {path} is not a 32-bit ELF")
        phoff = struct.unpack_from("<I", self.data, 28)[0]
        phentsize, phnum = struct.unpack_from("<HH", self.data, 42)
        self.segs: list[tuple[int, int, int]] = []
        for index in range(phnum):
            ptype, offset, vaddr, _paddr, filesz, _memsz, _flags, _align = \
                struct.unpack_from("<8I", self.data, phoff + index * phentsize)
            if ptype == 1 and filesz:
                self.segs.append((vaddr, offset, filesz))

    def bytes_at(self, address: int, size: int) -> bytes | None:
        for vaddr, offset, filesz in self.segs:
            if vaddr <= address and address + size <= vaddr + filesz:
                start = offset + address - vaddr
                return self.data[start:start + size]
        return None


def tge_library_names(path: Path) -> dict[int, list[tuple[str, str]]]:
    """P3 address -> [(name, library family)] for functions under `lib/` headers."""
    section = ""
    found: dict[int, list[tuple[str, str]]] = collections.defaultdict(list)
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if line.startswith("//"):
            section = line[2:].strip()
            continue
        match = TGE_LINE.match(line)
        if not match or match[3] != "func" or not section.startswith("lib/"):
            continue
        parts = section.split("/")
        family = parts[2] if len(parts) > 2 else parts[1]
        found[int(match[2], 16)].append((match[1], family))
    return found


def claimed_map() -> tuple[dict[str, int], dict[int, str]]:
    """Names and addresses already written by any other producer."""
    by_name: dict[str, int] = {}
    by_addr: dict[int, str] = {}
    for path in sorted((REPO / "config").glob("symbol_names*.txt")):
        if path == OUTPUT:
            continue
        for name, address in re.findall(r"^(\w+)\s*=\s*0x([0-9A-Fa-f]+)",
                                        path.read_text(encoding="utf-8"), re.M):
            by_name[name] = int(address, 16)
            by_addr[int(address, 16)] = name
    return by_name, by_addr


def code_identifiers() -> set[str]:
    """Identifiers that occur in code (comments and literals stripped)."""
    seen: set[str] = set()
    for root in (REPO / "src", REPO / "include"):
        for path in root.rglob("*"):
            if path.suffix not in (".c", ".h"):
                continue
            text = path.read_text(encoding="utf-8", errors="replace")
            seen.update(IDENTIFIER.findall(COMMENT_OR_LITERAL.sub(" ", text)))
    return seen


def forms(raw: list[int], spans: list[tuple[int, int]],
          pad_words: tuple[int, ...]) -> list[tuple]:
    """Comparison keys for one window.

    Each key is the window's first n words, relaxed at relocation positions,
    plus the relocation positions themselves. A longer window contributes a
    key only when its dropped suffix is all zero (alignment padding).
    """
    keys = []
    for pad in pad_words:
        count = len(raw) - pad
        if count <= 0 or any(raw[count:]):
            continue
        head = raw[:count]
        relocs = frozenset(_reloc_words(head, spans))
        masked = tuple(_relaxed(word) if index in relocs else word
                       for index, word in enumerate(head))
        keys.append((masked, relocs))
    return keys


def index_windows(image, windows: dict[str, int], spans, pad_words):
    """Signature -> window addresses, and window address -> its keys."""
    index: dict[tuple, set[int]] = collections.defaultdict(set)
    keys_of: dict[int, list[tuple]] = {}
    for text, size in windows.items():
        address = int(text, 16)
        data = image.bytes_at(address, int(size))
        if data is None or len(data) < MIN_BYTES:
            continue
        keys = forms(words(data), spans, pad_words)
        if not keys:
            continue
        keys_of[address] = keys
        for key in keys:
            index[key].add(address)
    return index, keys_of


def twin_pairs(p3_index, p3_keys, p4_index, p4_keys, wanted):
    """P3 address -> P4 address for every unique, mutually-unique twin."""
    pairs: dict[int, int] = {}
    reasons: collections.Counter = collections.Counter()
    for p3 in wanted:
        key = p3_keys[p3][0]
        if len(p3_index[key]) != 1:
            reasons["p3_not_unique"] += 1
            continue
        partners = p4_index.get(key, set())
        if not partners:
            reasons["no_p4_twin"] += 1
            continue
        if len(partners) != 1:
            reasons["p4_not_unique"] += 1
            continue
        p4 = next(iter(partners))
        other_partners: set[int] = set()
        for p4_key in p4_keys[p4]:
            other_partners |= p3_index.get(p4_key, set())
        if other_partners != {p3}:
            reasons["p4_has_other_p3_partner"] += 1
            continue
        pairs[p3] = p4
    return pairs, reasons


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--tge", type=Path, required=True,
                        help="tge-was-taken's P3FES config/SLUS_216.21/symbol_addrs.txt")
    parser.add_argument("--p3-root", type=Path, default=DEFAULT_P3_ROOT,
                        help=f"Persona3-FES-Decompilation checkout (default: {DEFAULT_P3_ROOT})")
    parser.add_argument("--output", type=Path, default=OUTPUT,
                        help=f"producer file to write (default: {OUTPUT.relative_to(REPO)})")
    args = parser.parse_args()

    p3_root = args.p3_root.resolve()
    p3 = ElfImage(p3_root / P3_ELF)
    p3_windows = json.loads((p3_root / P3_WINDOWS).read_text(encoding="utf-8"))
    if p3_windows.get("sha1") and p3_windows["sha1"] != hashlib.sha1(p3.data).hexdigest():
        raise SystemExit("port_tge_names: P3 ELF sha1 does not match the P3 windows file")

    config = V.load_config()
    target = V._read_json(V.TARGET)
    p4_windows = V._read_json(V.FUNCTION_WINDOWS)
    p4 = V.RetailElf(config["retail_elf"], target, p4_windows["sha1"])

    p3_spans = [(vaddr, filesz) for vaddr, _offset, filesz in p3.segs]
    p4_spans = [(vaddr, filesz) for vaddr, _offset, filesz in p4.segs]
    p3_index, p3_keys = index_windows(p3, p3_windows["windows"], p3_spans, (0,))
    p4_index, p4_keys = index_windows(p4, p4_windows["windows"], p4_spans, (0, 1, 2, 3))
    print(f"P3 windows indexed: {len(p3_keys)}; P4 windows indexed: {len(p4_keys)}")

    library = tge_library_names(args.tge)
    p3_names: dict[int, tuple[str, str]] = {}
    dropped: collections.Counter = collections.Counter()
    for address, entries in library.items():
        if len(entries) != 1:
            dropped["p3_multiple_names"] += 1
            continue
        name, family = entries[0]
        if name_junk(name):
            dropped["p3_name_junk"] += 1
            continue
        p3_names[address] = (name, family)
    wanted = [address for address in p3_names if address in p3_keys]
    dropped["p3_window_missing"] = len(p3_names) - len(wanted)
    print(f"tge library names: {len(library)} addresses; usable: {len(p3_names)}; "
          f"with P3 window: {len(wanted)}; dropped: {dict(dropped)}")

    pairs, reasons = twin_pairs(p3_index, p3_keys, p4_index, p4_keys, wanted)
    print(f"unique twins: {len(pairs)}; rejected: {dict(reasons)}")

    owned = _target_owned()
    owners = owners_by_address()
    claimed_name, claimed_addr = claimed_map()
    identifiers = code_identifiers()
    skipped: collections.Counter = collections.Counter()
    conflicts: list[tuple[int, str, str]] = []
    accepted: list[dict] = []
    for p3_address, p4_address in sorted(pairs.items(), key=lambda item: item[1]):
        name, family = p3_names[p3_address]
        if p4_address in owned:
            skipped["already_implemented"] += 1
            continue
        owner = owners.get(p4_address)
        if V.code_origin(owner, p4_address) == "main":
            skipped["first_party_owner"] += 1
            continue
        if p4_address in claimed_addr:
            if claimed_addr[p4_address] == name:
                skipped["already_named"] += 1
            else:
                conflicts.append((p4_address, name, claimed_addr[p4_address]))
            continue
        if name in claimed_name:
            conflicts.append((p4_address, name, f"name@0x{claimed_name[name]:08x}"))
            continue
        if name in identifiers:
            conflicts.append((p4_address, name, "name_in_code"))
            continue
        accepted.append({"p4": p4_address, "p3": p3_address, "name": name,
                         "family": family,
                         "width": len(p3_keys[p3_address][0][0])})

    counts = collections.Counter(entry["name"] for entry in accepted)
    duplicates = {name for name, count in counts.items() if count > 1}
    kept = [entry for entry in accepted if entry["name"] not in duplicates]
    skipped["duplicate_name"] = len(accepted) - len(kept)

    lines = [
        "// Persona 4 third-party library function names ported from tge-was-taken's",
        "// Persona 3 FES decompilation (fork of snaku/Persona3-FES-Decompilation).",
        "// Generated by tools/port_tge_names.py; rewritten wholesale each run. Do not hand-edit.",
        f"// {len(kept)} names from {len(library)} tge library addresses "
        f"({len(pairs)} unique twins).",
        "",
    ]
    for entry in sorted(kept, key=lambda item: item["p4"]):
        lines.append(
            f"{entry['name']} = 0x{entry['p4']:08X}; // type:func  evidence: "
            f"tge-p3:{entry['name']}@0x{entry['p3']:08x} reloc-identical over "
            f"{entry['width']} words, sole claimant ({entry['family']})")
    write_output(args.output.resolve(), lines)

    by_family: collections.Counter = collections.Counter(e["family"] for e in kept)
    print(f"skipped: {dict(skipped)}")
    kinds = collections.Counter(
        "name_in_code" if how == "name_in_code"
        else "name_claimed" if how.startswith("name@")
        else "addr_claimed"
        for _p4, _name, how in conflicts)
    print(f"conflicts by kind: {dict(kinds)}")
    for p4_address, name, how in conflicts[:20]:
        print(f"  conflict 0x{p4_address:08x} {name} <- {how}")
    print("accepted by family: " + ", ".join(f"{f}={n}" for f, n in by_family.most_common()))
    print(f"wrote {len(kept)} names to {args.output.resolve()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
