"""Identify the target's owned switch table from native dispatch and references.

This establishes placement for resolved diagnostic comparison. It never makes
the different candidate entry bytes exact and never modifies an object file.
"""
import json
import struct
from movie_context import OUT, ADDR, TARGET, RETAIL, sha


def partition(values):
    classes = {}
    return [classes.setdefault(value, len(classes)) for value in values]


def recover(obj, section_relocations):
    high, low = struct.unpack_from("<II", TARGET, 0x34)
    assert high >> 26 == 15 and (high >> 16) & 31 == 4
    assert low >> 26 == 9 and (low >> 21) & 31 == 4 and (low >> 16) & 31 == 4
    address = ((high & 0xffff) << 16) + ((low & 0x7fff) - (low & 0x8000))
    assert address == 0x7566F0
    limit, = struct.unpack_from("<I", TARGET, 0x28)
    assert limit >> 26 == 11 and limit & 0xffff == 12
    native = RETAIL.bytes_at(address, 48)
    native_entries = struct.unpack("<12I", native)
    assert all(ADDR <= entry < ADDR + len(TARGET) for entry in native_entries)
    owned = []
    for section in obj.sections:
        if section["size"] != 48 or section["flags"] & 4:
            continue
        refs = section_relocations(obj, section["idx"])
        if len(refs) == 12 and all(r["symbol"] == "func_00468ff0" and r["r_type"] == 2 for r in refs):
            assert sorted(r["offset"] for r in refs) == list(range(0, 48, 4))
            owned.append(section)
    assert len(owned) == 1, owned
    section = owned[0]
    raw = obj.data[section["offset"]:section["offset"] + section["size"]]
    entries = struct.unpack("<12I", raw)
    assert partition(entries) == partition(native_entries), (entries, native_entries)
    symbols = {s["name"] for s in obj.symbols if s["shndx"] == section["idx"] and s["name"]}
    code, code_refs = obj.function("func_00468ff0")
    refs = [r for r in code_refs if r.get("symbol") in symbols]
    assert len(refs) == 2 and [r["r_type"] for r in refs] == [5, 6], refs
    result = {"native_table_address": f"{address:08x}", "native_dispatch_offset": "0034",
              "native_dispatch_words": [f"{high:08x}", f"{low:08x}"],
              "bound": 12, "native_table_sha256": sha(native),
              "native_entries": [f"{entry:08x}" for entry in native_entries],
              "candidate_data_section": section["idx"], "candidate_table_symbols": sorted(symbols),
              "candidate_entry_offsets": [f"{entry:04x}" for entry in entries],
              "state_group_partition": partition(entries), "candidate_code_references": refs,
              "ownership": "sole twelve-entry table with all R_MIPS_32 references to this function and matching native state grouping",
              "scope": "placement identity only; all emitted table entries must still compare against native bytes"}
    return {section["idx"]: address}, result
