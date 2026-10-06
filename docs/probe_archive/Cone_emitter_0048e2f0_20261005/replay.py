"""Rebuild the exact installed cone-emitter owner, rejecting source drift."""
from collections import Counter
from importlib.util import module_from_spec, spec_from_file_location
from pathlib import Path
import argparse
import hashlib
import json

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--hashes-only", action="store_true")
    parser.add_argument("--output", type=Path, default=Path("build/cone-emitter-replay"))
    args = parser.parse_args()
    record = json.loads((HERE / "receipt.json").read_text(encoding="utf-8"))
    drift = [name for name, digest in record["inputs"].items()
             if not (ROOT / name).is_file() or sha(ROOT / name) != digest]
    if drift:
        raise SystemExit("Recorded inputs changed: " + ", ".join(drift))
    print("Authenticated input hashes:", len(record["inputs"]), flush=True)
    if args.hashes_only:
        return
    output = (ROOT / args.output).resolve()
    output.relative_to((ROOT / "build").resolve())
    output.mkdir(parents=True, exist_ok=False)
    spec = spec_from_file_location("cone_native_proof", ROOT / "docs/probe_archive/List_item_contract_20261005_replay.py")
    proof = module_from_spec(spec)
    spec.loader.exec_module(proof)
    proof.PROOFS = output
    cfg = proof.V.load_config()
    proof.RETAIL = proof.V.RetailElf(cfg["retail_elf"], proof.V._read_json(proof.V.TARGET), proof.META["sha1"])
    owner = ROOT / record["owner"]
    marker = next(m for m in proof.V.scan_markers(owner) if m["addr"] == 0x0048E2F0)
    assert not marker.get("asm") and not marker.get("nonmatching")
    assert sha(Path(proof.V.unit_compiler(owner, cfg))) == record["compiler_sha256"]
    assert proof.V.unit_compile_flags(owner, cfg["compile_flags"]) == record["flags"]
    bounds = sorted({n for address, size in proof.META["windows"].items()
                     for n in (int(address, 16), int(address, 16) + size)})
    with proof.P._owner_lock(owner):
        rows = proof.V.verify_file(owner, cfg, proof.RETAIL, bounds, output)
    assert dict(Counter(row["status"] for row in rows)) == record["summary"]
    native = output / (record["owner"].replace("/", "_") + ".o")
    current = proof.prove_owner(record["owner"], native, "whole-owner")
    assert current["code_relocations_verified"] == record["code_relocations_verified"]
    assert not current["storage"]
    previous = {row["name"]: row for row in record["functions"]}
    for function in current["functions"]:
        assert all(function[key] == previous[function["name"]][key]
                   for key in ("address", "size", "window", "zero_tail", "resolved_sha256"))
    assert all(sha(ROOT / name) == digest for name, digest in record["inputs"].items())
    print("Exact cone emitter and all 72 siblings verified", flush=True)


if __name__ == "__main__":
    main()
