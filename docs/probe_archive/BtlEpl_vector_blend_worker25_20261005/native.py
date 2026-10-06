"""Strict whole-owner reference/storage proof; no instruction remapping is accepted."""
from collections import defaultdict
from pathlib import Path
import hashlib
import json
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools"))
import verify as V
import fnalign as F
import build as B

OWNER = ROOT / "src/promoted/btlEPL.c"
NAME, ADDR = "func_001fd790", 0x001FD790
CFG = V.load_config()
WINDOWS = V._read_json(V.FUNCTION_WINDOWS)
RETAIL = V.RetailElf(CFG["retail_elf"], V._read_json(V.TARGET), WINDOWS["sha1"])
MARKERS = V.scan_markers(OWNER)
GP, ADDRESSES = V.symbol_addresses()
ADDRESSES.update(B.load_symbol_addr_map())
assert GP is not None

def digest(data):
    return hashlib.sha256(data).hexdigest()

def signed16(value):
    return (value & 0x7fff) - (value & 0x8000)


def section_relocations(obj, index):
    result = []
    for section in obj.sections:
        if section["type"] != 9 or section["info"] != index:
            continue
        symtab = obj.symtabs[section["link"]]
        for i in range(section["size"] // (section["entsize"] or 8)):
            offset, info = struct.unpack_from(obj.endian + "II", obj.data,
                                              section["offset"] + i * (section["entsize"] or 8))
            target = symtab[info >> 8]
            row = dict(offset=offset, r_type=info & 255, symbol=target["name"])
            if not target["name"] and (target["info"] & 15) == 3:
                row.update(target_section=target["shndx"], target_value=target["value"])
            result.append(row)
    return result


def relocate(body, relocs, mapping, bases):
    output = bytearray(body)
    pending = defaultdict(list)
    errors = []
    for reloc in relocs:
        offset, kind = reloc["offset"], reloc["r_type"]
        name = reloc.get("symbol") or ""
        address = V.resolve_symbol(name, GP, mapping)
        key = (name, reloc.get("target_section"), reloc.get("target_value"))
        if not name and reloc.get("target_section") in bases:
            address = bases[reloc["target_section"]] + reloc.get("target_value", 0)
        if address is None:
            errors.append(dict(reloc, reason="unresolved symbol"))
            continue
        word, = struct.unpack_from("<I", body, offset)
        if kind == 4:
            value = (word & 0xfc000000) | (((address + ((word & 0x3ffffff) << 2)) >> 2) & 0x3ffffff)
        elif kind == 5:
            pending[key].append((offset, word))
            continue
        elif kind == 6:
            for high_offset, high_word in pending.pop(key, []):
                full = address + ((high_word & 0xffff) << 16) + signed16(word)
                struct.pack_into("<I", output, high_offset,
                                 (high_word & 0xffff0000) | (((full + 0x8000) >> 16) & 0xffff))
            value = (word & 0xffff0000) | ((address + signed16(word)) & 0xffff)
        elif kind in (7, 8):
            displacement = address + signed16(word) - GP
            if not -0x8000 <= displacement < 0x8000:
                errors.append(dict(reloc, reason="GP displacement out of range"))
            value = (word & 0xffff0000) | (displacement & 0xffff)
        elif kind == 2:
            value = (word + address) & 0xffffffff
        else:
            errors.append(dict(reloc, reason="unsupported relocation"))
            continue
        struct.pack_into("<I", output, offset, value)
    errors.extend(dict(symbol=str(key), reason="unpaired HI16") for key, entries in pending.items() if entries)
    return bytes(output), errors


def inspect(directory):
    directory = Path(directory)
    label = directory.name
    obj = V.ObjectFile(directory / "src_promoted_btlEPL.c.o")
    masked_exact = []
    for marker in MARKERS:
        code, relocs = obj.function(marker["name"])
        window = WINDOWS["windows"][f'{marker["addr"]:08x}']
        retail = RETAIL.bytes_at(marker["addr"], window)
        differences, _ = V.compare(code, relocs, retail)
        if marker["name"] != NAME and not differences and len(code) <= window and not any(retail[len(code):]):
            masked_exact.append(marker)
    # Data anchors come from already exact siblings, never the nonexact target.
    bases = B.recover_section_bases(obj, masked_exact, RETAIL, GP)
    more = B.recover_pointer_data_bases(obj, masked_exact, RETAIL, GP)
    if more is not None:
        bases.update(more)
    groups = defaultdict(list)
    for section in obj.sections:
        if section["flags"] & 2 and not section["flags"] & 4 and section["size"]:
            groups[section["name"]].append(section)
    layouts = {}
    for name, sections in groups.items():
        concatenated = B.recover_concatenated_layout(sections, bases)
        assert concatenated is not None, f"no independently anchored layout for {name}"
        base, offsets, total = concatenated
        layouts[name] = (base, offsets, total)
        for section, offset in zip(sections, offsets):
            assert bases.get(section["idx"], base + offset) == base + offset
            bases[section["idx"]] = base + offset
    mapping = dict(ADDRESSES)
    for symbol in obj.symbols:
        if symbol["name"] and symbol["shndx"] in bases:
            mapping[symbol["name"]] = bases[symbol["shndx"]] + symbol["value"]
    functions, resolved_functions, covered = [], {}, defaultdict(set)
    for marker in MARKERS:
        name = marker["name"]
        code, relocs = obj.function(name)
        resolved, errors = relocate(code, relocs, mapping, bases)
        window = WINDOWS["windows"][f'{marker["addr"]:08x}']
        retail = RETAIL.bytes_at(marker["addr"], window)
        differences = [i for i, byte in enumerate(resolved)
                       if i >= window or byte != retail[i]]
        tail_zero = len(code) <= window and not any(retail[len(code):])
        row = dict(name=name, address=f'{marker["addr"]:08x}', size=len(code), window=window,
                   exact=not errors and not differences and tail_zero,
                   differing_words=len({i//4 for i in differences}),
                   differing_bytes=len(differences), errors=errors,
                   relocations=len(relocs), code_sha256=digest(code),
                   resolved_sha256=digest(resolved),
                   zero_suffix=window-len(code) if tail_zero else None,
                   references=[dict(offset=r["offset"], kind=r["r_type"],
                                    symbol=r.get("symbol"),
                                    address=V.resolve_symbol(r.get("symbol") or "", GP, mapping))
                               for r in relocs])
        functions.append(row)
        resolved_functions[name] = resolved
        symbol = next(s for s in obj.symbols if s["name"] == name and s["size"] and 0 < s["shndx"] < len(obj.sections))
        covered[symbol["shndx"]].update(range(symbol["value"], symbol["value"] + symbol["size"]))
    data_rows, executable_rows, payloads = [], [], {}
    for section in obj.sections:
        if not section["flags"] & 2 or not section["size"]:
            continue
        raw = obj.data[section["offset"]:section["offset"] + section["size"]]
        relocs = section_relocations(obj, section["idx"])
        if section["flags"] & 4:
            extra = [i for i in range(section["size"]) if i not in covered[section["idx"]]]
            assert all(all(i in covered[section["idx"]] for i in range(r["offset"], r["offset"]+4)) for r in relocs)
            executable_rows.append(dict(index=section["idx"], name=section["name"], size=section["size"],
                                        covered_bytes=section["size"] - len(extra),
                                        zero_gap_bytes=len(extra), all_gaps_zero=not any(raw[i] for i in extra)))
            continue
        address = bases.get(section["idx"])
        assert section["type"] != 8 or not relocs
        payload, errors = (bytes(section["size"]), []) if section["type"] == 8 else relocate(raw, relocs, mapping, bases)
        exact = address is not None and not errors and payload == RETAIL.bytes_at(address, len(payload))
        payloads[section["idx"]] = payload
        data_rows.append(dict(index=section["idx"], name=section["name"], address=f'{address:08x}' if address is not None else None,
                              size=section["size"], alignment=section["addralign"],
                              errors=errors, relocations=len(relocs), exact=exact, sha256=digest(payload)))
    data_ok, layout = B.plan_data_sections(
        obj, masked_exact, RETAIL, GP, set(ADDRESSES),
        independent_literals=True, independent_rodata=True, independent_bss=True,
        independent_initialized=True, symbol_addresses=ADDRESSES)
    storage = []
    for name, sections in groups.items():
        address, offsets, size = layouts[name]
        payload = bytearray(size)
        for section, offset in zip(sections, offsets):
            payload[offset:offset+section["size"]] = payloads[section["idx"]]
        assert bytes(payload) == RETAIL.bytes_at(address, size)
        storage.append(dict(name=name, address=f'{address:08x}', size=size,
                            alignment_gap_bytes=size-sum(s["size"] for s in sections),
                            exact=True, sha256=digest(payload)))
    result = dict(label=label, logical_owner=OWNER.relative_to(ROOT).as_posix(),
                  source_sha256=digest((directory / "owner.c").read_bytes()),
                  object_sha256=digest(obj.data), compiler="MWCCPS2 3.0.1 b210",
                  retail_sha1=WINDOWS["sha1"], functions=functions, allocated_data=data_rows,
                  storage_spans=storage, executable_sections=executable_rows,
                  data_placeable=data_ok)
    (directory / "resolved-proof.json").write_text(json.dumps(result, indent=2) + "\n")
    assert all(not row["errors"] for row in functions + data_rows), "unresolved relocations"
    assert all(row["exact"] for row in data_rows) and data_ok, "data placement failure"
    assert all(row["all_gaps_zero"] for row in executable_rows), "unaccounted code bytes"
    print(label, "resolved exact functions", sum(f["exact"] for f in functions), "/", len(functions),
          "data", len(data_rows), "relocations", sum(f["relocations"] for f in functions+data_rows), flush=True)
    return result, resolved_functions


def classify_rotation(code, directory):
    retail = RETAIL.bytes_at(ADDR, len(code))
    differences = []
    unresolved = []
    rotation = {0: 1, 1: 2, 2: 0}
    for offset in range(0, len(code), 4):
        actual = struct.unpack_from("<I", code, offset)[0]
        expected = struct.unpack_from("<I", retail, offset)[0]
        if actual != expected:
            differences.append(offset)
        expected_text = F.disassemble(retail[offset:offset+4], ADDR + offset)
        actual_text = F.disassemble(code[offset:offset+4], ADDR + offset)
        mapped = expected_text
        if offset == 0x1bc:
            # The constant 1 is still in f0 when the complement is produced.
            mapped = expected_text.replace("sub.s $f2,", "sub.s $f0,", 1)
        elif offset > 0x1bc:
            mapped = re.sub(r"\$f(\d+)\b", lambda match: "$f" + str(rotation.get(int(match[1]), int(match[1]))), expected_text)
        if mapped != actual_text:
            unresolved.append(dict(offset=f'{offset:04x}', expected=expected_text, actual=actual_text, mapped=mapped))
    result = dict(actual_differing_words=len(differences),
                  actual_differing_offsets=[f'{i:04x}' for i in differences],
                  diagnostic_only=True, exact=False,
                  complement_destination="retail f2; candidate f0",
                  subsequent_register_map={"retail f0": "candidate f1", "retail f1": "candidate f2", "retail f2": "candidate f0"},
                  unexplained_differences=unresolved)
    (Path(directory) / "register-residual.json").write_text(json.dumps(result, indent=2) + "\n")
    print("Residual:", len(differences), "actual words;", len(unresolved), "not explained by the FPR rotation", flush=True)
    return result

