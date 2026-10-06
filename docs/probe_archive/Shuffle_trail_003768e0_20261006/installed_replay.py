"""Validate the installed guarded trail owner against the sealed native proof."""
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


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def module(name, relative):
    spec = importlib.util.spec_from_file_location(name, ROOT / relative)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


def compile_owner(record, output):
    cfg = V.load_config()
    owner = ROOT / record["owner"]
    assert sha(Path(V.unit_compiler(owner, cfg)).read_bytes()) == record["compiler_sha256"]
    assert V.unit_compile_flags(owner, cfg["compile_flags"]) == record["compile_flags"]
    guarded_cfg = dict(cfg, compile_flags=[*cfg["compile_flags"], "-DNON_MATCHING"])
    for name, profile in (("default", cfg), ("guarded", guarded_cfg)):
        ok, log = P._compile_in_context(owner, owner, profile, output / (name + ".o"))
        (output / (name + ".log")).write_text(log, encoding="utf-8")
        assert ok, log


def validate(record, output):
    original = json.loads((HERE / "receipt.json").read_text())
    assert sha((HERE / "receipt.json").read_bytes()) == record["native_receipt_sha256"]
    assert sha((HERE / "behavior-receipt.json").read_bytes()) == record["behavior_receipt_sha256"]
    cfg = V.load_config()
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), original["retail_sha1"])
    strict = module("installed_trail_strict", "docs/probe_archive/List_item_contract_20261005_replay.py")
    core = module("installed_trail_core", "docs/probe_archive/YDraw_update_002b6ec0_20261005/proof_core.py")
    strict.RETAIL = retail
    strict.PROOFS = output
    default = V.ObjectFile(output / "default.o")
    guarded = V.ObjectFile(output / "guarded.o")
    assert sha(default.data) == original["production_object_sha256"]
    assert sha(guarded.data) == original["guarded_object_sha256"]
    production = strict.prove_owner(record["owner"], output / "default.o", "production-proof")
    assert len(production["functions"]) == 52
    assert production["code_relocations_verified"] == 318
    assert production["storage_relocations_verified"] == 30
    markers = {m["name"]: m for m in V.scan_markers(ROOT / record["owner"]) if m.get("name")}
    bases, storage = core.prove_data(guarded, markers, retail, exclude=("func_003768e0", "func_00375f00"))
    assert storage == original["storage"]
    for row in original["siblings"]:
        code, refs = guarded.function(row["name"])
        assert sha(code) == row["code_sha256"]
        assert core.canonical_relocs(guarded, refs) == row["canonical_relocations"]
        marker = markers[row["name"]]
        target = retail.bytes_at(marker["addr"], windows["windows"][f'{marker["addr"]:08x}'])
        resolved, references, differences = core.resolve_function(guarded, row["name"], target, bases)
        assert len(differences) == row["differing_words"] and sha(resolved) == row["resolved_sha256"]
        assert all(r["target_bits_equal"] for r in references)
    target = retail.bytes_at(0x003768e0, original["target"]["window"])
    resolved, references, differences = core.resolve_function(guarded, "func_003768e0", target, bases)
    assert len(resolved) == original["target"]["bytes"] == 4176
    assert differences == original["target"]["difference_offsets"] and len(differences) == 511
    assert references == original["target"]["code_relocations"] and len(references) == 55
    assert sha(resolved) == original["target"]["resolved_sha256"]
    report = dict(owner=record["owner"], installed_source_sha256=sha((ROOT / record["owner"]).read_bytes()),
                  production_object_identical_to_sealed=True, guarded_object_identical_to_sealed=True,
                  default_object_sha256=sha(default.data), guarded_object_sha256=sha(guarded.data),
                  target_bytes=len(resolved), target_resolved_differing_words=len(differences),
                  target_references=references, unchanged_guarded_siblings=len(original["siblings"]),
                  storage=storage, new_C_matches=0)
    (output / "guarded-proof.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print("Installed production/guarded objects exactly reproduce the sealed proposal")
    print("Guarded target:4176bytes,511resolved differing words,55references;51siblings/data preserved")
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--hashes-only", action="store_true")
    mode.add_argument("--objects", type=Path)
    mode.add_argument("--output", type=Path)
    args = parser.parse_args()
    record = json.loads((HERE / "installed-receipt.json").read_text())
    for relative, expected in record["inputs"].items():
        path = (ROOT / relative).resolve()
        assert path.is_relative_to(ROOT) and sha(path.read_bytes()) == expected, relative
    print("Authenticated installed inputs:", len(record["inputs"]))
    if args.hashes_only:
        return
    output = (args.output or args.objects).resolve()
    assert output.is_relative_to((ROOT / "build").resolve())
    if args.output:
        output.mkdir(parents=True, exist_ok=False)
        compile_owner(record, output)
    validate(record, output)


if __name__ == "__main__":
    main()
