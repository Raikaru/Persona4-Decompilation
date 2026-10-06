"""Complete-owner code and storage checks for the vector callback repair.

The relocation rules reproduce the independently applied MIPS relocations used
for the retained proof. Only tracked repository tools and this archive are
imported; no prior build directory is an input to this module.
"""
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools"))
import probe_variants as P
import verify as V


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def fingerprint(value):
    return sha(json.dumps(value, sort_keys=True, separators=(",", ":")).encode("utf-8"))


def word(data, offset):
    require(0 <= offset <= len(data) - 4 and offset % 4 == 0,
            "Instruction or relocation outside its object")
    return struct.unpack_from("<I", data, offset)[0]


def signed16(value):
    return (value & 0x7fff) - (value & 0x8000)


def addresses():
    gp, table = V.symbol_addresses()
    require(gp is not None, "Missing recovered GP address")
    pattern = r"\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0[xX][0-9A-Fa-f]+|\d+)\s*;"
    for line in (ROOT / "config/symbol_addrs.txt").read_text(encoding="utf-8").splitlines():
        found = re.match(pattern, line)
        if found:
            name, address = found[1], int(found[2], 0)
            table[name] = address
            table.setdefault(f"func_{address:08x}", address)
    return gp, table


def section_relocations(obj, section_index):
    result = []
    for section in obj.sections:
        if section["type"] != 9 or section["info"] != section_index:
            continue
        symbols = obj.symtabs[section["link"]]
        entry_size = section["entsize"] or 8
        require(entry_size >= 8 and section["size"] % entry_size == 0,
                "Invalid section relocation extent")
        for index in range(section["size"] // entry_size):
            offset, info = struct.unpack_from("<II", obj.data,
                                             section["offset"] + index * entry_size)
            require(info >> 8 < len(symbols), "Invalid relocation symbol")
            result.append(dict(offset=offset, r_type=info & 255,
                               symbol=symbols[info >> 8]["name"]))
    return result


def relocate(code, relocations, symbols, gp):
    """Apply complete relocation values, retaining their resolved destinations."""
    output = bytearray(code)
    pending = defaultdict(list)
    records = []
    occupied = set()
    for relocation in relocations:
        offset, kind = relocation["offset"], relocation["r_type"]
        name = relocation.get("symbol") or ""
        address = V.resolve_symbol(name, gp, symbols)
        require(address is not None, f"Unresolved symbol {name}")
        require(offset not in occupied, "Overlapping relocations")
        occupied.add(offset)
        original = word(code, offset)
        row = dict(offset=offset, kind=kind, symbol=name, address=f"{address:08x}")
        records.append(row)
        if kind == 4:
            target = address + ((original & 0x3ffffff) << 2)
            require(target % 4 == 0, "Unaligned call destination")
            value = (original & 0xfc000000) | ((target >> 2) & 0x3ffffff)
            row["destination"] = f"{target:08x}"
        elif kind == 5:
            pending[name].append((offset, original, row))
            continue
        elif kind == 6:
            highs = pending.pop(name, [])
            row["paired_high_offsets"] = [position for position, _, _ in highs]
            for position, high, high_row in highs:
                target = address + ((high & 0xffff) << 16) + signed16(original)
                struct.pack_into("<I", output, position,
                                 (high & 0xffff0000) | (((target + 0x8000) >> 16) & 0xffff))
                high_row["paired_low_offset"] = offset
                high_row["destination"] = f"{target & 0xffffffff:08x}"
            value = (original & 0xffff0000) | ((address + signed16(original)) & 0xffff)
        elif kind in (7, 8):
            target = address + signed16(original)
            displacement = target - gp
            require(-0x8000 <= displacement < 0x8000, "GP reference outside signed range")
            value = (original & 0xffff0000) | (displacement & 0xffff)
            row["destination"] = f"{target:08x}"
        elif kind == 2:
            value = (original + address) & 0xffffffff
            row["destination"] = f"{value:08x}"
        else:
            raise ValueError(f"Unsupported relocation {kind}")
        struct.pack_into("<I", output, offset, value)
    require(not any(pending.values()), "Unpaired HI16 reference")
    return bytes(output), records


def canonical_relocations(obj, relocations):
    result = []
    for relocation in relocations:
        row = dict(relocation)
        name = row.get("symbol") or ""
        if name.startswith("@"):
            matches = [symbol for symbol in obj.symbols if symbol["name"] == name]
            require(len(matches) == 1, "Ambiguous compiler-local symbol")
            symbol = matches[0]
            section = obj.sections[symbol["shndx"]]
            require(symbol["info"] >> 4 == 0 and not section["flags"] & 4,
                    "Unexpected compiler-local code symbol")
            payload = obj.data[section["offset"]:section["offset"] + section["size"]]
            row["symbol"] = dict(section=section["name"], offset=symbol["value"],
                                 size=symbol["size"], info=symbol["info"],
                                 alignment=section["addralign"], payload_sha256=sha(payload))
        result.append(row)
    return result


def place_data(obj, markers, retail, windows, symbols, gp):
    symbols = dict(symbols)
    symbols.update({marker["name"]: marker["addr"] for marker in markers})
    placements = []
    for section in obj.sections:
        if not section["flags"] & 2 or section["flags"] & 4 or not section["size"]:
            continue
        require(section["type"] != 8, "Unexpected allocated BSS requires a new proof")
        locals_by_name = {s["name"]: s for s in obj.symbols if s["shndx"] == section["idx"]}
        votes, witnesses = set(), []
        for marker in markers:
            code, relocs = obj.function(marker["name"])
            expected = retail.bytes_at(marker["addr"], windows[f"{marker['addr']:08x}"])
            highs = {}
            for relocation in relocs:
                symbol = locals_by_name.get(relocation.get("symbol"))
                if symbol is None:
                    continue
                offset, kind = relocation["offset"], relocation["r_type"]
                old, new = word(expected, offset), word(code, offset)
                if kind == 5:
                    highs[symbol["name"]] = (offset, old, new)
                    continue
                if kind in (7, 8):
                    require((old >> 21) & 31 == 28 and (new >> 21) & 31 == 28,
                            "Literal witness is not GP-relative")
                    target, addend = gp + signed16(old), signed16(new)
                elif kind == 6:
                    require(symbol["name"] in highs, "Missing data HI16 witness")
                    _, old_high, new_high = highs.pop(symbol["name"])
                    target = ((old_high & 0xffff) << 16) + signed16(old)
                    addend = ((new_high & 0xffff) << 16) + signed16(new)
                else:
                    raise ValueError(f"Unexpected data-placement relocation {kind}")
                base = target - addend - symbol["value"]
                votes.add(base)
                witnesses.append(dict(function=marker["name"], offset=offset, kind=kind,
                                      symbol_offset=symbol["value"], section_base=f"{base:08x}"))
            require(not highs, "Unpaired data-placement witness")
        require(len(votes) == 1, f"Ambiguous placement for {section['name']}: {votes}")
        base = next(iter(votes))
        require(section["addralign"] > 0 and base % section["addralign"] == 0,
                "Owned storage alignment differs")
        for name, symbol in locals_by_name.items():
            symbols[name] = base + symbol["value"]
        placements.append((section, base, witnesses))
    owned = []
    for section, base, witnesses in placements:
        raw = obj.data[section["offset"]:section["offset"] + section["size"]]
        relocs = section_relocations(obj, section["idx"])
        linked, references = relocate(raw, relocs, symbols, gp)
        require(linked == retail.bytes_at(base, len(raw)), f"Owned data differs: {section['name']}")
        owned.append(dict(section=section["name"], base=f"{base:08x}", size=len(raw),
                          alignment=section["addralign"], raw_sha256=sha(raw),
                          resolved_sha256=sha(linked), retail_equal=True,
                          witnesses=witnesses, relocations=references))
    return symbols, owned


def inspect(object_path, markers, source, mode, retail, windows, globals_, gp):
    obj = V.ObjectFile(object_path)
    require(obj.endian == "<", "Expected little-endian EE object")
    symbols, owned = place_data(obj, markers, retail, windows, globals_, gp)
    rows, functions, coverage = [], {}, defaultdict(set)
    for marker in markers:
        name, address = marker["name"], marker["addr"]
        code, relocs = obj.function(name)
        linked, references = relocate(code, relocs, symbols, gp)
        expected = retail.bytes_at(address, windows[f"{address:08x}"])
        differences = [offset for offset in range(0, max(len(linked), len(expected)), 4)
                       if not (offset >= len(linked) and not any(expected[offset:offset + 4]))
                       and linked[offset:offset + 4] != expected[offset:offset + 4]]
        enabled = False
        if mode == "guarded" and marker.get("asm"):
            start, end = P.region_for(source, f"FUN_{address:08X}", name)
            enabled = "NON_MATCHING" in source[start:end]
        kind = "ASM" if marker.get("asm") and not enabled else "C"
        for reference in references:
            offset = reference["offset"]
            reference["positional_retail_equal"] = linked[offset:offset + 4] == expected[offset:offset + 4]
        canonical = canonical_relocations(obj, relocs)
        row = dict(name=name, address=f"{address:08x}", kind=kind,
                   status=("ASM" if kind == "ASM" else "MATCH") if not differences else "NONMATCHING",
                   bytes=len(code), window=len(expected), differing_words=len(differences),
                   differing_offsets=differences, code_sha256=sha(code), resolved_sha256=sha(linked),
                   canonical_relocations_sha256=fingerprint(canonical), relocation_count=len(relocs),
                   zero_suffix=len(expected) - len(code) if len(code) <= len(expected)
                   and not any(expected[len(code):]) else None)
        rows.append(row)
        functions[name] = (code, canonical, linked)
        matches = [s for s in obj.symbols if s["name"] == name and s["size"] and s["shndx"]]
        require(len(matches) == 1, f"Ambiguous function extent for {name}")
        symbol = matches[0]
        interval = set(range(symbol["value"], symbol["value"] + symbol["size"]))
        require(not coverage[symbol["shndx"]].intersection(interval), "Overlapping function extents")
        coverage[symbol["shndx"]].update(interval)
    executable = []
    known = {marker["name"] for marker in markers}
    for section in obj.sections:
        if not section["flags"] & 2 or not section["flags"] & 4 or not section["size"]:
            continue
        raw = obj.data[section["offset"]:section["offset"] + section["size"]]
        require(coverage[section["idx"]] <= set(range(len(raw))), "Function outside text section")
        gaps = set(range(len(raw))) - coverage[section["idx"]]
        require(not any(raw[index] for index in gaps), "Unaccounted executable bytes")
        for symbol in obj.symbols:
            if symbol["shndx"] == section["idx"] and symbol["size"] and symbol["info"] & 15 == 2:
                require(symbol["name"] in known, "Unexpected out-of-line function")
        for relocation in section_relocations(obj, section["idx"]):
            offset = relocation["offset"]
            require(set(range(offset, offset + 4)) <= coverage[section["idx"]],
                    "Unaccounted text relocation")
        executable.append(dict(section=section["name"], size=len(raw),
                               covered_bytes=len(coverage[section["idx"]]), zero_gaps=len(gaps)))
    if mode == "default":
        require(all(row["status"] in ("MATCH", "ASM") for row in rows), "Default profile regressed")
    report = dict(status_counts=dict(Counter(row["status"] for row in rows)), functions=rows,
                  code_relocations=sum(row["relocation_count"] for row in rows), owned_data=owned,
                  data_relocations=sum(len(data["relocations"]) for data in owned),
                  executable_sections=executable)
    return report, functions
