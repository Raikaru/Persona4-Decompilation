"""Verify the retained startup owner and its real linker-defined BSS address."""
from collections import Counter
from importlib.util import module_from_spec, spec_from_file_location
from pathlib import Path
import hashlib
import json
import sys

ROOT = Path(__file__).resolve().parents[2]
OWNER = ROOT / "src/promoted/code1_0010.c"
OUT = ROOT / "build/bootstrap-boundary-20261005"
spec = spec_from_file_location("bootstrap_owner_proof", Path(__file__).with_name("List_item_contract_20261005_replay.py"))
proof = module_from_spec(spec)
spec.loader.exec_module(proof)
V, B = proof.V, proof.B


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    proof.PROOFS = OUT
    cfg = V.load_config()
    proof.RETAIL = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), proof.META["sha1"])
    boundaries = {int(address, 16) for address in proof.META["windows"]}
    boundaries.update(int(address, 16) + size for address, size in proof.META["windows"].items())
    source_hash = hashlib.sha256(OWNER.read_bytes()).hexdigest()
    with proof.P._owner_lock(OWNER):
        rows = V.verify_file(OWNER, cfg, proof.RETAIL, sorted(boundaries), OUT)
    assert rows and all(row["status"] in ("MATCH", "ASM") for row in rows), rows
    relative = OWNER.relative_to(ROOT).as_posix()
    obj = OUT / (relative.replace("/", "_") + ".o")
    record = proof.prove_owner(relative, obj, "resolved-startup-owner")
    original = B.load_lcf_symbols

    def wrong_bss_end():
        gp, symbols = original()
        symbols = dict(symbols)
        assert symbols["D_938A00"] == 0x938a00
        symbols["D_938A00"] += 4
        return gp, symbols

    try:
        B.load_lcf_symbols = wrong_bss_end
        try:
            proof.prove_owner(relative, obj, "wrong-bss-end")
        except AssertionError as error:
            rejection = str(error)
            assert "func_00100008" in rejection, rejection
        else:
            raise AssertionError("An incorrect startup BSS end was accepted")
    finally:
        B.load_lcf_symbols = original
    assert hashlib.sha256(OWNER.read_bytes()).hexdigest() == source_hash
    record.update(source_sha256=source_hash, summary=dict(Counter(row["status"] for row in rows)),
                  new_c_matches=0, wrong_bss_end_rejected=True, negative_control=rejection,
                  changed_inputs_during_run=[])
    (OUT / "receipt.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8", newline="\n")
    print("Startup owner verified:", record["summary"], "; wrong BSS end rejected; no new C credit.")


if __name__ == "__main__":
    main()
