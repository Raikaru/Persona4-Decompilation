"""Prove native owner code and all owned storage without relocation masking."""
from collections import defaultdict
from functools import lru_cache
from pathlib import Path
import hashlib
import json
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import verify as V
import build as B
import probe_variants as P

META = V._read_json(V.FUNCTION_WINDOWS)
RETAIL = None
PROOFS = ROOT / "build/list-item-contract-replay"


def digest(data):
    return hashlib.sha256(data).hexdigest()


def word(data, offset):
    return struct.unpack_from("<I", data, offset)[0]


def signed16(value):
    return (value & 0x7fff) - (value & 0x8000)


@lru_cache(maxsize=1)
def named_source_addresses():
    addresses = defaultdict(set)
    for path in (ROOT / "src").rglob("*.c"):
        if V.is_generated(path) or path.name.startswith("."):
            continue
        for marker in V.scan_markers(path):
            if marker.get("name"):
                addresses[marker["name"]].add(marker["addr"])
    return {name: next(iter(values)) for name, values in addresses.items() if len(values) == 1}


def linked_function(obj, marker, gp, symbols):
    body, relocs = obj.function(marker["name"])
    size = META["windows"][f'{marker["addr"]:08x}']
    retail = RETAIL.bytes_at(marker["addr"], size)
    assert len(body) <= size and not any(retail[len(body):]), (marker["name"], len(body), size)
    linked = bytearray(body)
    pending = defaultdict(list)
    proven = []
    for relocation in relocs:
        offset, kind, name = relocation["offset"], relocation["r_type"], relocation["symbol"]
        address = V.resolve_symbol(name, gp, symbols)
        assert address is not None, (marker["name"], "unresolved", relocation)
        value = word(body, offset)
        if kind == 4:
            addend = (value & 0x3ffffff) << 2
            encoded = (value & 0xfc000000) | (((address + addend) >> 2) & 0x3ffffff)
        elif kind in (7, 8):
            addend = signed16(value)
            displacement = address + addend - gp
            assert -0x8000 <= displacement < 0x8000, (marker["name"], relocation)
            encoded = (value & 0xffff0000) | (displacement & 0xffff)
        elif kind == 5:
            pending[name].append((relocation, value & 0xffff))
            continue
        elif kind == 6:
            assert pending[name], (marker["name"], relocation)
            for high, addend_high in pending.pop(name):
                addend = (addend_high << 16) + signed16(value)
                resolved = address + addend
                encoded_high = (word(body, high["offset"]) & 0xffff0000) | (((resolved + 0x8000) >> 16) & 0xffff)
                assert encoded_high == word(retail, high["offset"]), (marker["name"], high)
                struct.pack_into("<I", linked, high["offset"], encoded_high)
                proven.append({**high, "address": address, "addend": addend, "word": encoded_high})
            encoded = (value & 0xffff0000) | (resolved & 0xffff)
        else:
            raise AssertionError((marker["name"], "unsupported relocation", relocation))
        assert encoded == word(retail, offset), (marker["name"], relocation, hex(encoded), hex(word(retail, offset)))
        struct.pack_into("<I", linked, offset, encoded)
        proven.append({**relocation, "address": address, "addend": addend, "word": encoded})
    assert not any(pending.values()) and len(proven) == len(relocs)
    assert linked == retail[:len(body)], (marker["name"], "resolved body differs")
    return {"name": marker["name"], "address": marker["addr"], "size": len(body), "window": size,
            "zero_tail": size - len(body), "resolved_sha256": digest(linked), "relocations": proven}


def prove_owner(relative, object_path, label):
    owner = ROOT / relative
    obj = V.ObjectFile(object_path)
    markers = [m for m in V.scan_markers(owner) if m.get("name")]
    gp, symbols = V.symbol_addresses()
    assert gp is not None
    symbols = dict(symbols)
    for name, address in named_source_addresses().items():
        assert name not in symbols or symbols[name] == address, (name, "conflicting source address")
        symbols[name] = address
    for symbol in obj.symbols:
        resolved = V.resolve_symbol(symbol["name"], gp, symbols)
        if resolved is not None:
            symbols[symbol["name"]] = resolved
    symbols.update({m["name"]: m["addr"] for m in markers})
    votes = B._section_base_votes(obj, markers, RETAIL, gp)
    conflicts = {i: dict(v) for i, v in votes.items() if len(v) != 1}
    assert not conflicts, (relative, "storage address conflicts", conflicts)
    bases = {i: next(iter(v)) for i, v in votes.items()}
    sections = [s for s in obj.sections if s["flags"] & 2 and not s["flags"] & 4 and s["size"]]
    for symbol in obj.symbols:
        index = symbol["shndx"]
        if symbol["name"] in symbols and any(s["idx"] == index for s in sections):
            address = symbols[symbol["name"]] - symbol["value"]
            assert index not in bases or bases[index] == address, (relative, symbol)
            bases[index] = address
    if any(s["idx"] not in bases for s in sections):
        inferred = B.recover_pointer_data_bases(obj, markers, RETAIL, gp)
        if inferred:
            for index, address in inferred.items():
                assert index not in bases or bases[index] == address
                bases[index] = address
    storage = []
    for section in sections:
        index = section["idx"]
        assert index in bases, (relative, "unanchored owned data", index, section["name"], section["size"])
        address = bases[index]
        assert address % max(section["addralign"], 1) == 0, (relative, section, address)
        if section["type"] == 8:
            payload = bytes(section["size"])
            assert not B.section_relocs(obj, index)
        elif not B.section_relocs(obj, index):
            payload = obj.data[section["offset"]:section["offset"] + section["size"]]
        elif section["name"] == ".rodata" and B.section_relocs(obj, index):
            payload = B._independent_rodata_payload(obj, section, markers, RETAIL, address, symbols)
        else:
            payload = B.resolved_initialized_payload(obj, section, markers, bases, symbols)
            assert payload is not None, (relative, "unresolved storage", index)
        assert payload == RETAIL.bytes_at(address, section["size"]), (relative, "storage bytes differ", index, hex(address))
        storage.append({"index": index, "name": section["name"], "address": address,
                        "size": section["size"], "sha256": digest(payload),
                        "relocations": B.section_relocs(obj, index)})
    for symbol in obj.symbols:
        if symbol["shndx"] in bases:
            address = bases[symbol["shndx"]] + symbol["value"]
            if symbol["name"] in symbols:
                assert symbols[symbol["name"]] == address, (relative, symbol)
            symbols[symbol["name"]] = address
    functions = [linked_function(obj, marker, gp, symbols) for marker in markers]
    proof = {"owner": relative, "object": str(object_path.relative_to(ROOT)), "object_sha256": digest(obj.data),
             "functions": functions, "storage": storage, "fully_resolved_differing_words": 0,
             "code_relocations_verified": sum(len(f["relocations"]) for f in functions),
             "storage_relocations_verified": sum(len(s["relocations"]) for s in storage)}
    (PROOFS / (label + ".json")).write_text(json.dumps(proof, indent=2) + "\n")
    print(label, "PASS", len(functions), "functions", proof["code_relocations_verified"],
          "code relocations", len(storage), "owned sections", proof["storage_relocations_verified"], "storage relocations", flush=True)
    return proof



def main():
    import argparse
    from collections import Counter
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--hashes-only", action="store_true", help="Check archived sources without compiling")
    parser.add_argument("--allow-source-drift", action="store_true", help="Verify a later tree and record changed inputs")
    parser.add_argument("--owners", nargs="+", help="Limit native replay to these recorded owner paths")
    args = parser.parse_args()
    receipt_path = Path(__file__).with_name("List_item_contract_20261005_receipt.json")
    receipt = json.loads(receipt_path.read_text(encoding="utf-8"))
    drift = [s["path"] for s in receipt["sources"]
             if digest((ROOT / s["path"]).read_bytes()) != s["sha256"]]
    if drift and not args.allow_source_drift:
        raise SystemExit("Archived source hashes changed: " + ", ".join(drift))
    print("Source hashes:", len(receipt["sources"]), "checked;", len(drift), "changed", flush=True)
    if args.hashes_only:
        return
    global RETAIL
    cfg = V.load_config()
    RETAIL = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), META["sha1"])
    PROOFS.mkdir(parents=True, exist_ok=True)
    bounds = {int(addr, 16) for addr in META["windows"]}
    bounds.update(int(addr, 16) + size for addr, size in META["windows"].items())
    owners = {entry["owner"]: entry for entry in receipt["owners"]}
    selected = args.owners or list(owners)
    unknown = set(selected) - set(owners)
    if unknown:
        raise SystemExit("Unrecorded owners: " + ", ".join(sorted(unknown)))
    rows, proofs, guards = [], [], []
    for relative in selected:
        owner = ROOT / relative
        with P._owner_lock(owner):
            checked = V.verify_file(owner, cfg, RETAIL, sorted(bounds), PROOFS)
        assert all(r["status"] in ("MATCH", "ASM") for r in checked), checked
        rows.extend(checked)
        objpath = PROOFS / (relative.replace("/", "_") + ".o")
        proof = prove_owner(relative, objpath, owner.stem)
        proofs.append({"owner": relative, "object_sha256": proof["object_sha256"],
                       "matches_recorded_object": proof["object_sha256"] == owners[relative]["object_sha256"]})
        if relative in receipt["guarded_owners"]:
            text = owner.read_text(encoding="utf-8")
            with P.scratch_source(owner) as scratch:
                scratch.write_text("#define NON_MATCHING 1\n" + text, encoding="utf-8")
                ok, log = P._compile_in_context(scratch, owner, cfg, PROOFS / (owner.stem + "-guarded.o"))
            (PROOFS / (owner.stem + "-guarded.log")).write_text(log, encoding="utf-8")
            assert ok, log
            guards.append(relative)
    report = {"summary": dict(Counter(r["status"] for r in rows)), "source_drift": drift,
              "owners": proofs, "guarded_owners": guards, "results": rows}
    (PROOFS / "verification.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print("Replay:", report["summary"], len(guards), "guarded builds", flush=True)


if __name__ == "__main__":
    main()
