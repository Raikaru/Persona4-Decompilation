"""Replay the installed five-owner rotation-axis contract proof."""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import verify
import probe_variants
from Field_axis_contract_20261005_proof import prove


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--hashes-only", action="store_true")
    parser.add_argument("--out", type=Path, default=ROOT / "build/field-axis-20261005-replay")
    args = parser.parse_args()
    receipt = json.loads(Path(__file__).with_name("Field_axis_contract_20261005_receipt.json").read_text())
    for relative, expected in receipt["portable_inputs"].items():
        actual = sha(ROOT / relative)
        if actual != expected:
            raise SystemExit(f"Input changed: {relative}: expected {expected}, got {actual}")
    print(f"Authenticated {len(receipt['portable_inputs'])} project inputs.", flush=True)
    if args.hashes_only:
        return
    cfg = verify.load_config()
    meta = verify._read_json(verify.FUNCTION_WINDOWS)
    retail = verify.RetailElf(cfg["retail_elf"], verify._read_json(verify.TARGET), meta["sha1"])
    assert meta["sha1"] == receipt["retail_sha1"]
    bounds = {int(address, 16) for address in meta["windows"]}
    bounds.update(int(address, 16) + size for address, size in meta["windows"].items() if size)
    output = args.out.resolve()
    output.mkdir(parents=True, exist_ok=True)
    if any(output.iterdir()):
        raise SystemExit(f"Replay output already has evidence; choose a fresh --out: {output}")
    summaries = []
    for owner in receipt["installation"]["owners"]:
        source = ROOT / owner["owner"]
        compiler = Path(verify.unit_compiler(source, cfg))
        profile = receipt["compiler_profiles"][owner["owner"]]
        assert sha(compiler) == profile["compiler_sha256"]
        assert verify.unit_compile_flags(source, cfg["compile_flags"]) == profile["flags"]
        directory = output / source.stem
        directory.mkdir()
        rows = verify.verify_file(source, cfg, retail, sorted(bounds), directory)
        summary = dict(Counter(row["status"] for row in rows))
        assert summary == owner["default_summary"], (source, summary)
        default_object = directory / (owner["owner"].replace("/", "_") + ".o")
        assert sha(default_object) == owner["default_object"]["sha256"]
        proof = prove(verify.ObjectFile(default_object), verify.scan_markers(source), retail, meta["windows"])
        assert {k: v for k, v in proof.items() if k not in ("functions", "owned_data")} == owner["strict_default_summary"]
        guarded_source = directory / "guarded.c"
        guarded_source.write_bytes(b"#define NON_MATCHING 1\n" + source.read_bytes())
        guarded_object = directory / "guarded.o"
        ok, log = probe_variants._compile_in_context(guarded_source, source, cfg, guarded_object)
        (directory / "guarded.compile.log").write_text(log, encoding="utf-8")
        assert ok, log
        assert sha(guarded_object) == owner["guarded_object"]["sha256"]
        (directory / "default-proof.json").write_text(json.dumps(proof, indent=2) + "\n", encoding="utf-8")
        (directory / "verify.json").write_text(json.dumps({"summary":summary,"results":rows},indent=2) + "\n",encoding="utf-8")
        summaries.append({"owner": owner["owner"], "summary": summary})
        print(json.dumps(summaries[-1]), flush=True)
    (output / "completed.json").write_text(json.dumps({"owners": summaries,"new_functions": []},indent=2)+"\n",encoding="utf-8")


if __name__ == "__main__":
    main()
