"""Resolve the follower's native code without claiming an exact match."""
from collections import defaultdict
import hashlib
from pathlib import Path
import struct
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/"tools"))
import verify

def digest(raw):
    return hashlib.sha256(raw).hexdigest()

def signed16(value):
    value &= 0xFFFF
    return value-0x10000 if value&0x8000 else value

def resolve(obj, name: str, address: int, retail, window: int, exact: bool) -> dict:
    """Resolve each actual code relocation; leave both input objects untouched."""
    body, relocations = obj.function(name)
    linked = bytearray(body)
    gp, symbols = verify.symbol_addresses()
    assert gp is not None
    pending = defaultdict(list)
    records = []
    for relocation in relocations:
        offset, kind, symbol = relocation["offset"], relocation["r_type"], relocation["symbol"]
        target = verify.resolve_symbol(symbol or "", gp, symbols)
        assert target is not None, (name, relocation)
        raw = struct.unpack_from("<I", body, offset)[0]
        if kind == 4:
            addend = (raw & 0x03FFFFFF) << 2
            value = target + addend
            assert value % 4 == 0 and ((address + offset + 4) & 0xF0000000) == (value & 0xF0000000)
            encoded = (raw & 0xFC000000) | ((value >> 2) & 0x03FFFFFF)
        elif kind == 7:
            addend = signed16(raw)
            value = target + addend - gp
            assert -0x8000 <= value < 0x8000
            encoded = (raw & 0xFFFF0000) | (value & 0xFFFF)
        elif kind == 5:
            pending[symbol].append((relocation, raw & 0xFFFF))
            continue
        elif kind == 6:
            assert pending[symbol], (name, relocation)
            for high, high_addend in pending.pop(symbol):
                addend = (high_addend << 16) + signed16(raw)
                value = target + addend
                high_word = struct.unpack_from("<I", body, high["offset"])[0]
                high_word = (high_word & 0xFFFF0000) | (((value + 0x8000) >> 16) & 0xFFFF)
                struct.pack_into("<I", linked, high["offset"], high_word)
                records.append({**high, "symbol_address": target, "addend": addend,
                                "resolved_word": f"{high_word:08x}"})
            encoded = (raw & 0xFFFF0000) | (value & 0xFFFF)
        else:
            raise AssertionError((name, relocation))
        struct.pack_into("<I", linked, offset, encoded)
        records.append({**relocation, "symbol_address": target, "addend": addend,
                        "resolved_word": f"{encoded:08x}"})
    assert not any(pending.values()) and len(records) == len(relocations)
    expected = retail.bytes_at(address, window)
    count = max(len(linked), len(expected))
    differing_words = [offset for offset in range(0, count, 4)
                       if not (offset >= len(linked) and not any(expected[offset:offset + 4]))
                       and linked[offset:offset + 4] != expected[offset:offset + 4]]
    if exact:
        assert len(linked) <= len(expected) and not any(expected[len(linked):]) and not differing_words, name
    return {"function": name, "address": f"{address:08x}", "code_bytes": len(body),
            "window": window, "resolved_relocations": len(records),
            "resolved_sha256": digest(linked), "fully_resolved_differing_words": len(differing_words),
            "zero_retail_tail": not any(expected[len(linked):]),
            "relocations": sorted(records, key=lambda item: item["offset"])}
