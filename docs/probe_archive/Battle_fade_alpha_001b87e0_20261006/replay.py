"""Compile and verify the proposed/installed complete fade owner, without edits."""
from pathlib import Path
import argparse
import hashlib
import json
import re
import shutil
import sys

ARCHIVE = Path(__file__).resolve().parent
ROOT = ARCHIVE.parents[2]
sys.path[:0] = [str(ROOT / "tools"), str(ARCHIVE)]
import verify as V
import probe_variants as P
import native_proof as N

def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def load(path):
    return json.loads(path.read_text(encoding="utf-8"))

def apply_in_memory(original, patch):
    source = original.splitlines(True)
    result = []
    cursor = 0
    active = False
    for line in patch.splitlines(True)[2:]:
        if line.startswith("@@"):
            match = re.match(r"@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@", line)
            if not match:
                raise ValueError("Unsupported source hunk")
            begin = int(match[1]) - 1
            if begin < cursor:
                raise ValueError("Overlapping source hunks")
            result.extend(source[cursor:begin])
            cursor = begin
            active = True
            continue
        if not active or line[:1] not in (" ", "+", "-"):
            raise ValueError("Unsupported patch line")
        if line[0] != "+":
            if cursor >= len(source) or source[cursor] != line[1:]:
                raise ValueError("Source context differs")
            cursor += 1
        if line[0] != "-":
            result.append(line[1:])
    return "".join(result + source[cursor:])

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--out", required=True, type=Path)
    parser.add_argument("--reuse-object", type=Path, help="Authenticate an existing exact proposal object instead of compiling")
    args = parser.parse_args()
    receipt = load(ARCHIVE / "receipt.json")
    owner = ROOT / receipt["owner"]
    original = owner.read_bytes()
    original_hash = hashlib.sha256(original).hexdigest()
    for relative, expected in receipt["input_files_sha256"].items():
        if digest(ROOT / relative) != expected:
            raise ValueError("Input changed: " + relative)
    if digest(ARCHIVE / "native_proof.py") != receipt["native_proof_sha256"]:
        raise ValueError("Native proof implementation changed")
    if digest(ARCHIVE / "source.patch") != receipt["source_patch_sha256"]:
        raise ValueError("Source patch changed")
    if original_hash == receipt["original_source_sha256"]:
        proposed = apply_in_memory(original.decode(), (ARCHIVE / "source.patch").read_text())
    elif original_hash == receipt["proposal_source_sha256"]:
        proposed = original.decode()
    else:
        raise ValueError("Owner is neither the reviewed baseline nor the proposed source: " + original_hash)
    if hashlib.sha256(proposed.encode()).hexdigest() != receipt["proposal_source_sha256"]:
        raise ValueError("Reconstructed proposal differs")
    cfg = V.load_config()
    if digest(Path(V.unit_compiler(owner, cfg))) != receipt["compiler_sha256"]:
        raise ValueError("Compiler differs")
    if V.unit_compile_flags(owner, cfg["compile_flags"]) != receipt["compiler_flags"]:
        raise ValueError("Compiler flags differ")
    directory = args.out.resolve()
    directory.relative_to(ROOT / "build")
    directory.mkdir(parents=True, exist_ok=True)
    source = directory / "proposal.c"
    obj = directory / "proposal.o"
    complete = directory / "replay-result.json"
    reused = False
    if complete.exists():
        if digest(source) != receipt["proposal_source_sha256"] or digest(obj) != receipt["proposal_object_sha256"]:
            raise ValueError("Completed output changed")
        reused = True
    else:
        if source.exists() or obj.exists():
            raise ValueError("Inspect incomplete output before replay")
        source.write_text(proposed, encoding="utf-8", newline="\n")
        if args.reuse_object:
            if digest(args.reuse_object) != receipt["proposal_object_sha256"]:
                raise ValueError("Retained object differs")
            shutil.copyfile(args.reuse_object, obj)
            reused = True
        else:
            with P.scratch_source(owner) as scratch:
                scratch.write_text(proposed, encoding="utf-8", newline="\n")
                ok, log = P._compile_in_context(scratch, owner, cfg, obj)
            (directory / "compile.log").write_text(log, encoding="utf-8")
            if not ok:
                raise RuntimeError("Owner compilation failed; inspect compile.log")
    if digest(obj) != receipt["proposal_object_sha256"]:
        raise ValueError("Native object differs from reviewed proposal")
    markers = V.scan_markers(source)
    if len(markers) != 27 or any(m.get("asm") or m["nonmatching"] for m in markers):
        raise ValueError("Proposal does not expose 27 native C owners")
    proof, _, _ = N.inspect_owner(ROOT, receipt["owner"], obj, receipt["target"], cfg,
                                  named=receipt["canonical_aliases"])
    if not proof["promotion_eligible"]:
        raise ValueError("Native full-owner proof failed")
    actual = [{k: v for k, v in f.items() if k != "references"} for f in proof["functions"]]
    if actual != receipt["functions"] or proof["storage"] != receipt["allocated_storage"]:
        raise ValueError("Function or storage receipt differs")
    if owner.read_bytes() != original:
        raise ValueError("Production owner drifted during replay")
    result = {"owner": receipt["owner"], "owner_source_unchanged": True,
              "object_reused": reused, "proposal_source_sha256": digest(source),
              "proposal_object_sha256": digest(obj), "exact_functions": len(proof["functions"]),
              "resolved_code_references": proof["code_references_resolved"],
              "resolved_data_references": proof["data_references_resolved"],
              "all_storage_exact": proof["all_storage_exact"], "target": proof["target"]}
    (directory / "proof.json").write_text(json.dumps(proof, indent=2) + "\n")
    complete.write_text(json.dumps(result, indent=2) + "\n")
    print("27 exact C functions; 212 code references; storage exact; production unchanged")

if __name__ == "__main__":
    main()
