"""Resolve complete source-owner code and independently anchored owned data.

All resolutions are made in private byte copies. Unsupported or unanchored
storage is rejected, never masked or inferred from neighbouring objects.
"""
from collections import defaultdict
import hashlib
import struct

from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import verify
import build


def digest(raw):
    return hashlib.sha256(raw).hexdigest()


def s16(value):
    value &= 0xFFFF
    return value - 0x10000 if value & 0x8000 else value


def prove(obj, markers, retail, windows):
    gp, known = verify.symbol_addresses()
    assert gp is not None
    addresses = {m["name"]: m["addr"] for m in markers}
    assert len(addresses) == len(markers)
    for marker in markers:
        body, relocs = obj.function(marker["name"])
        target = retail.bytes_at(marker["addr"], windows[f'{marker["addr"]:08x}'])
        assert len(body) <= len(target) and not any(target[len(body):])
        assert verify.compare(body, relocs, target)[0] == 0, marker["name"]

    bases = build.recover_section_bases(obj, markers, retail, gp)
    for symbol in obj.symbols:
        index = symbol.get("shndx", 0)
        if not (0 < index < len(obj.sections)):
            continue
        section = obj.sections[index]
        if not section["flags"] & 2 or section["flags"] & 4:
            continue
        target = verify.resolve_symbol(symbol["name"] or "", gp, known)
        if target is not None:
            base = target - symbol["value"]
            assert index not in bases or bases[index] == base, symbol
            bases[index] = base

    local = {}
    for symbol in obj.symbols:
        index, name = symbol.get("shndx", 0), symbol["name"]
        if not name or not (0 < index < len(obj.sections)):
            continue
        section = obj.sections[index]
        if index in bases:
            address = bases[index] + symbol["value"]
        elif section["flags"] & 4 and name in addresses:
            address = addresses[name]
        else:
            continue
        assert name not in local or local[name] == address, name
        local[name] = address

    def lookup(name):
        address = verify.resolve_symbol(name or "", gp, known)
        if name in local:
            assert address is None or address == local[name], (name, address, local[name])
            return local[name]
        assert address is not None, f"Unresolved symbol {name}"
        return address

    data_proofs = []
    for section in obj.sections:
        if not section["flags"] & 2 or section["flags"] & 4 or not section["size"]:
            continue
        index = section["idx"]
        assert index in bases, ("Unanchored owned section", section)
        base = bases[index]
        assert base % max(section["addralign"], 1) == 0
        raw = (obj.data[section["offset"]:section["offset"] + section["size"]]
               if section["type"] != 8 else bytes(section["size"]))
        linked = bytearray(raw)
        relocs = build.section_relocs(obj, index)
        occupied = set()
        records = []
        for offset, kind, name in relocs:
            assert kind == 2 and offset % 4 == 0 and 0 <= offset <= len(linked) - 4
            assert offset not in occupied
            occupied.add(offset)
            address = lookup(name)
            addend = struct.unpack_from("<I", raw, offset)[0]
            value = address + addend
            assert 0 <= value <= 0xFFFFFFFF
            struct.pack_into("<I", linked, offset, value)
            records.append({"offset": offset, "symbol": name, "symbol_address": address,
                            "addend": addend, "value": value})
        assert bytes(linked) == retail.bytes_at(base, len(linked)), ("Owned data differs", section["name"], base)
        data_proofs.append({"section": section["name"], "index": index, "address": base,
            "size": len(linked), "alignment": section["addralign"], "type": section["type"],
            "raw_sha256": digest(raw), "resolved_sha256": digest(linked), "relocations": records})

    code_proofs = []
    for marker in markers:
        name, pc = marker["name"], marker["addr"]
        body, relocs = obj.function(name)
        linked = bytearray(body)
        pending = defaultdict(list)
        records = []
        for relocation in relocs:
            offset, kind, symbol = relocation["offset"], relocation["r_type"], relocation["symbol"]
            assert offset % 4 == 0 and offset <= len(body) - 4
            address = lookup(symbol)
            raw = struct.unpack_from("<I", body, offset)[0]
            if kind == 4:
                addend = (raw & 0x03FFFFFF) << 2
                value = address + addend
                assert value % 4 == 0 and ((pc + offset + 4) & 0xF0000000) == (value & 0xF0000000)
                word = (raw & 0xFC000000) | ((value >> 2) & 0x03FFFFFF)
            elif kind in (7, 8):
                addend = s16(raw)
                value = address + addend - gp
                assert -0x8000 <= value < 0x8000, (name, relocation, value)
                word = (raw & 0xFFFF0000) | (value & 0xFFFF)
            elif kind == 5:
                pending[symbol].append((relocation, raw & 0xFFFF))
                continue
            elif kind == 6:
                assert pending[symbol], (name, relocation)
                for high, high_addend in pending.pop(symbol):
                    addend = (high_addend << 16) + s16(raw)
                    value = address + addend
                    hi_word = struct.unpack_from("<I", body, high["offset"])[0]
                    hi_word = (hi_word & 0xFFFF0000) | (((value + 0x8000) >> 16) & 0xFFFF)
                    struct.pack_into("<I", linked, high["offset"], hi_word)
                    records.append({**high, "address": address, "addend": addend, "resolved_word": f"{hi_word:08x}"})
                word = (raw & 0xFFFF0000) | (value & 0xFFFF)
            else:
                raise AssertionError((name, relocation))
            struct.pack_into("<I", linked, offset, word)
            records.append({**relocation, "address": address, "addend": addend, "resolved_word": f"{word:08x}"})
        assert not any(pending.values()) and len(records) == len(relocs)
        target = retail.bytes_at(pc, windows[f"{pc:08x}"])
        assert bytes(linked) == target[:len(linked)] and not any(target[len(linked):]), name
        code_proofs.append({"function": name, "address": pc, "bytes": len(body),
            "window": len(target), "zero_tail": len(target) - len(body),
            "raw_sha256": digest(body), "resolved_sha256": digest(linked),
            "relocations": sorted(records, key=lambda r: r["offset"])})
    return {"function_count": len(code_proofs), "code_relocation_count": sum(len(f["relocations"]) for f in code_proofs),
            "owned_data_count": len(data_proofs), "owned_data_bytes": sum(d["size"] for d in data_proofs),
            "data_relocation_count": sum(len(d["relocations"]) for d in data_proofs),
            "functions": code_proofs, "owned_data": data_proofs}
