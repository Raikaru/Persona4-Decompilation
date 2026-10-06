"""Replay the actual installed motion owner using the existing native proof."""
from pathlib import Path
from importlib.util import spec_from_file_location, module_from_spec
from collections import Counter
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
    parser.add_argument("--output", type=Path, default=Path("build/motion-scale-replay"))
    args = parser.parse_args()
    record = json.loads((HERE / "receipt.json").read_text())
    drift = [p for p, digest in record["inputs"].items() if not (ROOT / p).is_file() or sha(ROOT / p) != digest]
    if drift:
        raise SystemExit("Recorded inputs changed: " + ", ".join(drift))
    print("Input hashes verified:", len(record["inputs"]))
    if args.hashes_only:
        return
    output = (ROOT / args.output).resolve()
    output.relative_to((ROOT / "build").resolve())
    output.mkdir(parents=True, exist_ok=False)
    spec = spec_from_file_location("native_proof", ROOT / "docs/probe_archive/List_item_contract_20261005_replay.py")
    proof = module_from_spec(spec)
    spec.loader.exec_module(proof)
    proof.PROOFS = output
    cfg = proof.V.load_config()
    proof.RETAIL = proof.V.RetailElf(cfg["retail_elf"], proof.V._read_json(proof.V.TARGET), proof.META["sha1"])
    owner = ROOT / record["owner"]
    marker = next(m for m in proof.V.scan_markers(owner) if m["addr"] == 0x0048C4E0)
    assert not marker.get("asm") and not marker.get("nonmatching")
    bounds = sorted({n for address, size in proof.META["windows"].items() for n in (int(address, 16), int(address, 16) + size)})
    with proof.P._owner_lock(owner):
        rows = proof.V.verify_file(owner, cfg, proof.RETAIL, bounds, output)
    assert dict(Counter(r["status"] for r in rows)) == record["summary"]
    obj = output / (record["owner"].replace("/", "_") + ".o")
    verified = proof.prove_owner(record["owner"], obj, "whole-owner")
    assert verified["code_relocations_verified"] == record["code_relocations_verified"]
    expected = {f["name"]: f for f in record["functions"]}
    for function in verified["functions"]:
        assert all(function[key] == expected[function["name"]][key]
                   for key in ("address", "size", "window", "zero_tail", "resolved_sha256"))
    assert not verified["storage"]
    assert all(sha(ROOT / p) == digest for p, digest in record["inputs"].items())
    print("Exact motion target and all 72 siblings verified")


if __name__ == "__main__":
    main()
