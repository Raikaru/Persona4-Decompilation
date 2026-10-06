"""Reproduce and validate the complete-owner guarded trail proposal."""
from pathlib import Path
import argparse
import hashlib
import importlib.util
import json
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path[:0] = [str(HERE), str(ROOT / "tools")]
import prepare
import probe_variants as P
import verify as V


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def module(name, relative):
    spec = importlib.util.spec_from_file_location(name, ROOT / relative)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


def compile_proposal(record, output):
    owner = ROOT / record["owner"]
    cfg = V.load_config()
    assert sha(Path(V.unit_compiler(owner, cfg)).read_bytes()) == record["compiler_sha256"]
    assert V.unit_compile_flags(owner, cfg["compile_flags"]) == record["compile_flags"]
    guarded_cfg = dict(cfg, compile_flags=[*cfg["compile_flags"], "-DNON_MATCHING"])
    proposal = prepare.proposal(owner)
    assert sha(proposal.encode()) == record["proposal_source_sha256"]
    (output / "proposal-owner.c").write_bytes(proposal.encode())
    (output / "reference-owner.c").write_bytes(owner.read_bytes())
    for label, source, profile in (
        ("reference-default", P._read_text(owner), cfg),
        ("reference-guarded", P._read_text(owner), guarded_cfg),
        ("proposal-default", proposal, cfg),
        ("proposal-guarded", proposal, guarded_cfg),
    ):
        with P.scratch_source(owner) as scratch:
            scratch.write_bytes(source.encode())
            ok, log = P._compile_in_context(scratch, owner, profile, output / (label + ".o"))
        (output / (label + ".log")).write_text(log, encoding="utf-8")
        assert ok, log


def validate(record, output):
    core = module("trail_core", "docs/probe_archive/YDraw_update_002b6ec0_20261005/proof_core.py")
    strict = module("trail_strict", "docs/probe_archive/List_item_contract_20261005_replay.py")
    cfg = V.load_config()
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), record["retail_sha1"])
    strict.RETAIL = retail
    strict.PROOFS = output
    original = V.ObjectFile(output / "reference-default.o")
    default = V.ObjectFile(output / "proposal-default.o")
    assert original.data == default.data
    assert sha(default.data) == record["production_object_sha256"]
    production = strict.prove_owner(record["owner"], output / "proposal-default.o", "production-proof")
    assert len(production["functions"]) == 52
    assert production["code_relocations_verified"] == 318
    assert production["storage_relocations_verified"] == 30
    before = V.ObjectFile(output / "reference-guarded.o")
    after = V.ObjectFile(output / "proposal-guarded.o")
    markers = {m["name"]: m for m in V.scan_markers(ROOT / record["owner"]) if m.get("name")}
    name = record["target"]["name"]
    bases, storage = core.prove_data(after, markers, retail, exclude=(name, "func_00375f00"))
    assert core.data_summary(before) == core.data_summary(after)
    assert core.canonical_data_relocs(before) == core.canonical_data_relocs(after)
    assert storage == record["storage"]
    for row in record["siblings"]:
        code, refs = after.function(row["name"])
        prior_code, prior_refs = before.function(row["name"])
        assert code == prior_code and sha(code) == row["code_sha256"]
        canonical = core.canonical_relocs(after, refs)
        assert canonical == core.canonical_relocs(before, prior_refs) == row["canonical_relocations"]
        marker = markers[row["name"]]
        target = retail.bytes_at(marker["addr"], windows["windows"][f'{marker["addr"]:08x}'])
        resolved, references, differences = core.resolve_function(after, row["name"], target, bases)
        assert len(differences) == row["differing_words"] and sha(resolved) == row["resolved_sha256"]
        assert all(r["target_bits_equal"] for r in references)
    target = retail.bytes_at(0x003768e0, record["target"]["window"])
    code, refs = after.function(name)
    resolved, references, differences = core.resolve_function(after, name, target, bases)
    assert len(code) == record["target"]["bytes"] == 4176
    assert core.word(code, 0) == 0x27bdf0b0
    assert differences == record["target"]["difference_offsets"]
    assert len(differences) == record["target"]["fully_resolved_differing_words"] == 511
    assert sha(resolved) == record["target"]["resolved_sha256"]
    assert references == record["target"]["code_relocations"] and len(references) == 55
    def calls(data):
        return [((core.word(data, off) & 0x3ffffff) << 2) for off in range(0, len(data), 4) if core.word(data, off) >> 26 == 3]
    assert calls(resolved) == calls(target) == record["target"]["direct_calls_match_retail"]
    assert len(calls(resolved)) == 28
    assert sum(core.word(resolved, off) & 0xfc00003f == 9 for off in range(0, len(resolved), 4)) == 3
    report = dict(target=name, fully_resolved_differing_words=len(differences), references=references,
                  siblings_preserved=len(record["siblings"]), storage=storage,
                  production_object_sha256=sha(default.data), guarded_object_sha256=sha(after.data))
    (output / "guarded-proof.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print("Target remains NONMATCHING:", len(differences), "resolved differing words;", len(code), "bytes")
    print("Preserved 51 guarded siblings, 4 exact owned sections; production object identical")
    print("Resolved all 55 target references; 28 direct calls and 3 indirect calls retain retail order/count")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--hashes-only", action="store_true")
    mode.add_argument("--objects", type=Path)
    mode.add_argument("--output", type=Path)
    args = parser.parse_args()
    record = json.loads((HERE / "receipt.json").read_text())
    for relative, expected in record["inputs"].items():
        path = (ROOT / relative).resolve()
        assert path.is_relative_to(ROOT) and sha(path.read_bytes()) == expected, relative
    print("Authenticated inputs:", len(record["inputs"]))
    if args.hashes_only:
        return
    output = (args.output or args.objects).resolve()
    assert output.is_relative_to((ROOT / "build").resolve())
    if args.output:
        output.mkdir(parents=True, exist_ok=False)
        compile_proposal(record, output)
    validate(record, output)


if __name__ == "__main__":
    main()
