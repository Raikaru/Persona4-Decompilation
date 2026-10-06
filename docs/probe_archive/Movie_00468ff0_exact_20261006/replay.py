"""Authenticate or replay the exact movie and its three coherent API owners.

All compilations use the actual owner context and the repository's normal
assembly-splice wrapper. Complete native references, data and every owning
function are checked. Live source and emitted objects are never patched.
"""
from __future__ import annotations
import argparse
from collections import defaultdict
import hashlib
import importlib.util
import json
from pathlib import Path
import shutil
import sys

ARCHIVE = Path(__file__).resolve().parent
ROOT = next(p for p in ARCHIVE.parents if (p / "tools/verify.py").is_file())
sys.path[:0] = [str(ARCHIVE), str(ROOT / "tools")]
from movie_context import V, CFG, WINDOWS, RETAIL
from patch_utils import apply_recorded_patch
from native_contracts import check as check_native_contracts
import build as B
import probe_variants as P


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def load(path):
    return json.loads(Path(path).read_text(encoding="utf-8-sig"))


def save(path, value):
    Path(path).write_bytes((json.dumps(value, indent=2) + "\n").encode())


def source_pair(info):
    actual = (ROOT / info["owner"]).read_bytes()
    patch = (ARCHIVE / info["patch"]).read_bytes()
    if sha(actual) == info["before_sha256"]:
        before, after = actual, apply_recorded_patch(actual, patch)
    else:
        assert sha(actual) == info["after_sha256"], info["owner"]
        after, before = actual, apply_recorded_patch(actual, patch, reverse=True)
    assert sha(before) == info["before_sha256"] and sha(after) == info["after_sha256"]
    assert apply_recorded_patch(before, patch) == after
    assert apply_recorded_patch(after, patch, reverse=True) == before
    return actual, {"before": before, "after": after}


def resolver(owner, name):
    spec = importlib.util.spec_from_file_location("pair_" + owner.stem, ARCHIVE / "resolve_owner.py")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    module.OWNER, module.NAME = owner, name
    gp, definitions = B.load_lcf_symbols()
    assert gp == module.GP
    for symbol, address in definitions.items():
        if symbol in module.ADDRESSES:
            assert module.ADDRESSES[symbol] == address, symbol
        module.ADDRESSES[symbol] = address
    return module


def coverage(proof, obj, expected):
    covered, actual = defaultdict(set), set()
    for symbol in obj.symbols:
        if symbol["info"] & 15 != 2 or not symbol["shndx"] or not symbol["size"]:
            continue
        name = symbol["name"]
        assert name in expected and name not in actual, name
        actual.add(name)
        used = set(range(symbol["value"], symbol["value"] + symbol["size"]))
        assert not covered[symbol["shndx"]].intersection(used)
        covered[symbol["shndx"]].update(used)
    assert actual == expected, (actual - expected, expected - actual)
    rows = []
    for section in obj.sections:
        if not section["flags"] & 2 or not section["flags"] & 4 or not section["size"]:
            continue
        raw = obj.data[section["offset"]:section["offset"] + section["size"]]
        used = covered[section["idx"]]
        assert used <= set(range(len(raw)))
        gaps = set(range(len(raw))) - used
        assert not any(raw[index] for index in gaps)
        for ref in proof.section_relocations(obj, section["idx"]):
            assert set(range(ref["offset"], ref["offset"] + 4)) <= used
        rows.append({"section": section["idx"], "bytes": len(raw), "owned_bytes": len(used),
                     "zero_alignment_bytes": len(gaps)})
    return rows


def canonical_refs(obj, refs):
    gp, addresses = V.symbol_addresses()
    addresses.update(B.load_symbol_addr_map())
    addresses.update(B.load_lcf_symbols()[1])
    result = []
    for original in refs:
        row = dict(original)
        name = row["symbol"]
        local = [s for s in obj.symbols if s["name"] == name and s["shndx"]]
        if name and name.startswith("@"):
            symbol, = local
            section = obj.sections[symbol["shndx"]]
            assert not section["flags"] & 4
            raw = (bytes(section["size"]) if section["type"] == 8 else
                   obj.data[section["offset"]:section["offset"] + section["size"]])
            row["symbol"] = {"section": section["name"], "size": section["size"],
                             "offset": symbol["value"], "payload_sha256": sha(raw)}
        else:
            value = V.resolve_symbol(name or "", gp, addresses)
            row["symbol"] = {"address": value} if value is not None else name
        result.append(row)
    return result


def native_contracts():
    assert check_native_contracts() == load(ARCHIVE / "native-contracts.json")
    dma = load(ARCHIVE / "sdk-native-contract.json")["native_identity"]
    assert sha(RETAIL.bytes_at(int(dma["table_address"], 16), 40)) == dma["table_sha256"]
    for name, hash_name in (("getter", "getter_sha256"), ("sync", "sync_sha256"), ("blocking_wait", "wait_sha256")):
        address = dma[name]
        assert sha(RETAIL.bytes_at(int(address, 16), WINDOWS["windows"][address])) == dma[hash_name]
    for witness in load(ARCHIVE / "texture-native-contract.json"):
        address = int(witness["address"], 16)
        assert sha(RETAIL.bytes_at(address, len(witness["instructions"]) * 4)) == witness["sha256"]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", type=Path, default=ROOT / "build/movie-dma-texture-replay")
    parser.add_argument("--hashes-only", action="store_true")
    parser.add_argument("--reuse-retained", action="store_true",
                        help="Reuse only byte-authenticated, source-bound completed compilation objects")
    args = parser.parse_args()
    receipt = load(ARCHIVE / "receipt.json")
    for relative, expected in receipt["archive_payload_sha256"].items():
        assert sha((ARCHIVE / relative).read_bytes()) == expected, relative
    for relative, expected in receipt["project_inputs"].items():
        assert sha((ROOT / relative).read_bytes()) == expected, relative
    sources = {}
    for label, info in receipt["owners"].items():
        original, pair = source_pair(info)
        owner = ROOT / info["owner"]
        assert sha(Path(V.unit_compiler(owner, CFG)).read_bytes()) == info["compiler_sha256"]
        assert V.unit_compile_flags(owner, CFG["compile_flags"]) == info["flags"]
        sources[label] = original, pair
    native_contracts()
    if args.hashes_only:
        print(json.dumps({"owners_authenticated": len(sources), "archive_and_project_inputs_authenticated": True,
                          "native_contracts_checked": True, "compile_performed": False}, indent=2), flush=True)
        return
    output = args.out.resolve()
    output.relative_to(ROOT / "build")
    assert not output.exists(), "Choose a new output directory; preserve completed evidence"
    output.mkdir(parents=True)
    manifests = load(ARCHIVE / "retained-compilations.json")
    reports, objects, contexts = {}, {}, {}
    for label, info in receipt["owners"].items():
        owner = ROOT / info["owner"]
        expected = {m["name"] for m in V.scan_markers(owner)}
        assert len(expected) == info["function_count"]
        proof = resolver(owner, info["target"])
        for mode in ("default", "guarded"):
            prefix = b"#define NON_MATCHING 1\n" if mode == "guarded" else b""
            for variant, payload in sources[label][1].items():
                key = label + "-" + mode + "-" + variant
                directory = output / key
                directory.mkdir()
                source_repair = None
                if label == "movie" and mode == "guarded" and variant == "before":
                    compatibility = receipt["original_guard_compatibility"]
                    assert sha(payload) == compatibility["original_source_sha256"]
                    payload = apply_recorded_patch(payload, (ARCHIVE / compatibility["patch"]).read_bytes())
                    assert sha(payload) == compatibility["repaired_source_sha256"]
                    source_repair = compatibility["description"]
                compiled_source = prefix + payload
                (directory / "owner.c").write_bytes(compiled_source)
                reused = False
                if args.reuse_retained and key in manifests:
                    bound = manifests[key]
                    source = ROOT / bound["source"]
                    object_path = ROOT / bound["object"]
                    assert source.read_bytes() == compiled_source and sha(compiled_source) == bound["source_sha256"], key
                    assert sha(object_path.read_bytes()) == bound["object_sha256"], key
                    shutil.copyfile(object_path, directory / "owner.o")
                    (directory / "compile.log").write_text("Reused authenticated completed compilation: " + bound["object"] + "\n")
                    reused = True
                else:
                    with P.scratch_source(owner) as temporary:
                        temporary.write_bytes(compiled_source)
                        ok, log = P._compile_in_context(temporary, owner, CFG, directory / "owner.o")
                    (directory / "compile.log").write_bytes(log.encode())
                    assert ok, str(directory / "compile.log")
                obj = V.ObjectFile(directory / "owner.o")
                table = label == "movie" and (variant == "after" or mode == "guarded")
                report = proof.inspect(directory, target_table=table)
                assert len(report["functions"]) == len(expected)
                assert all(not r["errors"] for r in report["functions"] + report["data_sections"])
                spans = coverage(proof, obj, expected)
                save(directory / "text-coverage.json", spans)
                permitted = set(info["guarded_nonmatches"]) if mode == "guarded" else set()
                if label == "movie" and variant == "before" and mode == "guarded":
                    permitted.add(info["target"])
                assert {r["name"] for r in report["functions"] if not r["exact"]} <= permitted, key
                for data in report["data_sections"]:
                    if label == "movie" and variant == "before" and mode == "guarded" and data["address"] == "007566f0":
                        continue
                    assert data["exact"], (key, data)
                reports[key], objects[key] = report, obj
                contexts[key] = {"reused_completed_compile": reused, "source_sha256": sha(compiled_source),
                                 "private_declaration_repair": source_repair,
                                 "object_sha256": sha(obj.data), "functions": len(expected),
                                 "nonmatching_functions": [r["name"] for r in report["functions"] if not r["exact"]],
                                 "code_references": sum(r["relocations"] for r in report["functions"]),
                                 "data_references": sum(r["relocations"] for r in report["data_sections"])}
        for mode in ("default", "guarded"):
            before_key, after_key = label + "-" + mode + "-before", label + "-" + mode + "-after"
            before_obj, after_obj = objects[before_key], objects[after_key]
            before_rows = {r["name"]: r for r in reports[before_key]["functions"]}
            for row in reports[after_key]["functions"]:
                if label == "movie" and row["name"] == info["target"]:
                    assert row["exact"] and row["size"] == 4132 and row["window"] == 4144
                    assert row["zero_suffix"] == 12 and row["relocations"] == 152
                    assert row["resolved_sha256"] == receipt["movie_target_resolved_sha256"]
                    continue
                name = row["name"]
                old_bytes, old_refs = before_obj.function(name)
                new_bytes, new_refs = after_obj.function(name)
                assert old_bytes == new_bytes and canonical_refs(before_obj, old_refs) == canonical_refs(after_obj, new_refs), (label, mode, name)
                assert before_rows[name] == row, (label, mode, name)
            def unrelated_data(report):
                return sorted((r["name"], r["size"], r["address"], r["payload_sha256"], r["relocations"])
                              for r in report["data_sections"] if not (label == "movie" and r["address"] == "007566f0"))
            assert unrelated_data(reports[before_key]) == unrelated_data(reports[after_key]), (label, mode)
            if label != "movie":
                assert before_obj.data == after_obj.data, (label, mode, "whole object changed")
        if label == "movie":
            # The historical raw guard could not compile because its header was
            # absent. The private declaration restoration is not misrepresented
            # as a successful compilation of that original source. Both the
            # restored old guard and the new guard preserve every production
            # sibling against the independently compiled original default owner.
            baseline = objects["movie-default-before"]
            baseline_rows = {r["name"]: r for r in reports["movie-default-before"]["functions"]}
            for key in ("movie-guarded-before", "movie-guarded-after"):
                for row in reports[key]["functions"]:
                    name = row["name"]
                    if name == info["target"]:
                        continue
                    old_bytes, old_refs = baseline.function(name)
                    new_bytes, new_refs = objects[key].function(name)
                    assert old_bytes == new_bytes
                    assert canonical_refs(baseline, old_refs) == canonical_refs(objects[key], new_refs)
                    assert baseline_rows[name] == row, (key, name)
        assert (ROOT / info["owner"]).read_bytes() == sources[label][0], info["owner"]
    for relative, expected in receipt["project_inputs"].items():
        assert sha((ROOT / relative).read_bytes()) == expected, relative
    result = {"source_unchanged": True, "native_contracts_checked": True, "contexts": contexts,
              "original_guard_as_committed_compiles": False,
              "original_guard_private_declarations_restored": True,
              "new_exact_movie": True, "default_and_guarded_siblings_preserved": True,
              "all_code_data_references_resolved": True, "all_allocated_sections_checked": True,
              "additional_match_credit_from_API_repairs": 0}
    save(output / "completed.json", result)
    print(json.dumps({"completed_contexts": len(contexts), "reused_compilations": sum(r["reused_completed_compile"] for r in contexts.values()),
                      "source_unchanged": True, "all_code_data_references_resolved": True}, indent=2), flush=True)


if __name__ == "__main__":
    main()
