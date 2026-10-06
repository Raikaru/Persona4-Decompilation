"""Reproduce current-owner native preservation without modifying source or caches."""
from pathlib import Path
import argparse
import hashlib
import importlib.util
import json
import sys
import tempfile

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


def validate(record, default_path, guarded_path, output):
    core = module("field_guard_core", "docs/probe_archive/YDraw_update_002b6ec0_20261005/proof_core.py")
    strict = module("field_guard_strict", "docs/probe_archive/List_item_contract_20261005_replay.py")
    cfg = V.load_config()
    owner = ROOT / record["owner"]
    compiler = Path(V.unit_compiler(owner, cfg))
    assert sha(compiler.read_bytes()) == record["compiler_sha256"]
    assert V.unit_compile_flags(owner, cfg["compile_flags"]) == record["compile_flags"]
    assert sha(default_path.read_bytes()) == record["default_object_sha256"]
    assert sha(guarded_path.read_bytes()) == record["guarded_object_sha256"]
    strict.RETAIL = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), record["retail_sha1"])
    strict.PROOFS = output
    default = strict.prove_owner(record["owner"], default_path, "default-proof")
    assert len(default["functions"]) == record["default_function_count"]
    assert default["code_relocations_verified"] == record["default_code_relocations"]
    guarded = V.ObjectFile(guarded_path)
    for row in record["unchanged_guarded_siblings"]:
        code, references = guarded.function(row["name"])
        assert sha(code) == row["code_sha256"], row["name"]
        assert canonical_hash(core.canonical_relocs(guarded, references)) == row["canonical_relocations_sha256"], row["name"]
    assert core.data_summary(guarded) == record["guarded_storage"]
    assert canonical_hash(core.canonical_data_relocs(guarded)) == record["guarded_data_relocations_sha256"]
    code, references = guarded.function(record["target"])
    assert sha(code) == record["target_code_sha256"]
    assert len(code) == record["target_bytes"] and len(references) == record["target_relocation_count"]
    print("Default owner exact;", len(record["unchanged_guarded_siblings"]), "guarded siblings preserved; all current storage authenticated")
    print("Target remains NONMATCHING; no C promotion")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument("--hashes-only", action="store_true")
    group.add_argument("--objects", type=Path)
    group.add_argument("--output", type=Path)
    args = parser.parse_args()
    record = json.loads((HERE / "receipt.json").read_text(encoding="utf-8"))
    for relative, expected in record["inputs"].items():
        path = (ROOT / relative).resolve()
        if not path.is_relative_to(ROOT) or not path.is_file() or sha(path.read_bytes()) != expected:
            raise SystemExit("Recorded input changed: " + relative)
    print("Authenticated inputs:", len(record["inputs"]))
    if args.hashes_only:
        return
    if args.objects:
        directory = args.objects.resolve()
        with tempfile.TemporaryDirectory(prefix="field-guard-proof-", dir=ROOT / "build") as temporary:
            validate(record, directory / "src_promoted_code1_0016.c.o",
                     directory / "code1_0016-guarded.o", Path(temporary))
        return
    directory = args.output.resolve()
    if not directory.is_relative_to((ROOT / "build").resolve()):
        raise SystemExit("Replay output must be inside this repository's build directory")
    directory.mkdir(parents=True, exist_ok=False)
    cfg = V.load_config()
    owner = ROOT / record["owner"]
    guarded_cfg = dict(cfg, compile_flags=[*cfg["compile_flags"], "-DNON_MATCHING"])
    for label, profile, filename in (
        ("default", cfg, "src_promoted_code1_0016.c.o"),
        ("guarded", guarded_cfg, "code1_0016-guarded.o"),
    ):
        ok, log = P._compile_in_context(owner, owner, profile, directory / filename)
        (directory / (label + ".log")).write_text(log, encoding="utf-8")
        assert ok, log
    validate(record, directory / "src_promoted_code1_0016.c.o", directory / "code1_0016-guarded.o", directory)


if __name__ == "__main__":
    main()
