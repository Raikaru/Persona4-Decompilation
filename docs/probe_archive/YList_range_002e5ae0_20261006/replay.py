"""Verify the installed guarded range builder and every owned code/data reference."""
from pathlib import Path
import argparse
import hashlib
import importlib.util
import json
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import verify as V
import probe_variants as P


def module(name, relative):
    spec = importlib.util.spec_from_file_location(name, ROOT / relative)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def canonical_hash(value):
    return sha(json.dumps(value, sort_keys=True, separators=(",", ":")).encode())


def compact_storage(rows):
    return [{"section": row["section"], "retail_address": row["retail_address"],
             "bytes": row["bytes"], "fully_resolved_sha256": row["fully_resolved_sha256"],
             "pointer_entries": len(row["pointer_entries"])} for row in rows]


def compile_owner(record, directory):
    cfg = V.load_config()
    owner = ROOT / record["owner"]
    assert sha(Path(V.unit_compiler(owner, cfg)).read_bytes()) == record["compiler_sha256"]
    assert V.unit_compile_flags(owner, cfg["compile_flags"]) == record["compile_flags"]
    guarded = dict(cfg, compile_flags=[*cfg["compile_flags"], "-DNON_MATCHING"])
    for label, profile in (("default", cfg), ("guarded", guarded)):
        ok, log = P._compile_in_context(owner, owner, profile, directory / (label + ".o"))
        (directory / (label + ".log")).write_text(log, encoding="utf-8")
        assert ok, log


def validate(record, directory):
    core = module("range_core", "docs/probe_archive/YDraw_update_002b6ec0_20261005/proof_core.py")
    strict = module("range_strict", "docs/probe_archive/List_item_contract_20261005_replay.py")
    cfg = V.load_config()
    windows = V._read_json(V.FUNCTION_WINDOWS)
    assert windows["sha1"] == record["retail_sha1"]
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), record["retail_sha1"])
    strict.RETAIL = retail
    strict.PROOFS = directory
    production = strict.prove_owner(record["owner"], directory / "default.o", "production-proof")
    assert len(production["functions"]) == record["production_function_count"]
    assert production["code_relocations_verified"] == record["production_code_relocations"]
    assert len(production["storage"]) == record["production_storage_sections"]
    assert production["storage_relocations_verified"] == record["production_data_relocations"]

    owner = ROOT / record["owner"]
    markers = {m["name"]: m for m in V.scan_markers(owner) if m.get("name")}
    obj = V.ObjectFile(directory / "guarded.o")
    bases, storage = core.prove_data(obj, markers, retail)
    assert compact_storage(storage) == record["guarded_storage"]
    sibling_reports = []
    for row in record["unchanged_siblings"]:
        name = row["name"]
        code, relocs = obj.function(name)
        assert sha(code) == row["code_sha256"], (name, "sibling bytes changed")
        assert canonical_hash(core.canonical_relocs(obj, relocs)) == row["canonical_relocations_sha256"], name
        marker = markers[name]
        target = retail.bytes_at(marker["addr"], windows["windows"][f'{marker["addr"]:08x}'])
        resolved, references, differences = core.resolve_function(obj, name, target, bases)
        assert not differences and all(r["target_bits_equal"] for r in references), name
        assert sha(resolved) == row["resolved_sha256"]
        sibling_reports.append({"name": name, "bytes": len(code), "references": len(references), "retail_equal": True})
    assert len(sibling_reports) + 1 == len(markers)

    target = retail.bytes_at(int(record["address"], 16), record["target_window_bytes"])
    resolved, references, differences = core.resolve_function(obj, record["target"], target, bases)
    assert len(resolved) == record["target_bytes"]
    assert len(references) == record["target_code_relocations"]
    assert all(r["target_bits_equal"] for r in references)
    assert differences == record["difference_offsets"]
    assert len(differences) == record["resolved_differing_words"] == 45
    assert sha(resolved) == record["resolved_target_sha256"]
    assert len(resolved) <= len(target) and not any(target[len(resolved):])
    report = {"target": record["target"], "resolved_differing_words": len(differences),
              "target_bytes": len(resolved), "zero_tail_bytes": len(target) - len(resolved),
              "difference_offsets": differences, "target_references": references,
              "siblings": sibling_reports, "storage": storage,
              "default_object_sha256": sha((directory / "default.o").read_bytes()),
              "guarded_object_sha256": sha(obj.data)}
    (directory / "guarded-proof.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print("Guarded target:", len(resolved), "bytes;", len(differences), "resolved differing words;", len(references), "verified references")
    print("Preserved:", len(sibling_reports), "exact siblings;", len(storage), "exact owned data sections;",
          sum(len(row["pointer_entries"]) for row in storage), "resolved data entries")
    print("The NON_MATCHING guard and ASM fallback remain; no new C match is claimed.")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--hashes-only", action="store_true")
    mode.add_argument("--objects", type=Path, help="Use existing default.o and guarded.o")
    mode.add_argument("--output", type=Path, help="Compile into a new directory under build")
    args = parser.parse_args()
    record = json.loads((HERE / "receipt.json").read_text(encoding="utf-8"))
    for relative, expected in record["inputs"].items():
        path = (ROOT / relative).resolve()
        if not path.is_relative_to(ROOT) or not path.is_file() or sha(path.read_bytes()) != expected:
            raise SystemExit("Recorded input changed: " + relative)
    print("Authenticated inputs:", len(record["inputs"]))
    if args.hashes_only:
        return
    directory = (args.objects or args.output).resolve()
    if not directory.is_relative_to((ROOT / "build").resolve()):
        raise SystemExit("Proof output must be inside this repository's build directory")
    if args.output:
        directory.mkdir(parents=True, exist_ok=False)
        compile_owner(record, directory)
    validate(record, directory)


if __name__ == "__main__":
    main()
