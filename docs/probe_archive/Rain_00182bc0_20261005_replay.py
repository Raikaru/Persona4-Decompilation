"""Replay the rain recovery's native owner, relocation, and 32-bit behavior checks."""
from collections import Counter
from importlib.util import module_from_spec, spec_from_file_location
from pathlib import Path
import argparse
import hashlib
import json
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent
sys.path[:0] = [str(ROOT / "tools"), str(ROOT / "tests")]
spec = spec_from_file_location("rain_owner_proof", HERE / "List_item_contract_20261005_replay.py")
proof = module_from_spec(spec)
spec.loader.exec_module(proof)
V, P = proof.V, proof.P
OWNERS = ("src/promoted/code1_0018.c", "src/promoted/code1_003a.c", "src/promoted/effParticle.c")
OUT = ROOT / "build/rain-20261005-replay"


def digest(data):
    return hashlib.sha256(data).hexdigest()


def smoke():
    from native32_support import native32_runtime, RUNTIME_C, ENTRY_C
    source = (ROOT / OWNERS[0]).read_text(encoding="utf-8")
    start, end = P.region_for(source, "FUN_00182BC0", "func_00182bc0")
    body = source[start:end]
    types = source[source.index("typedef struct RwV3d"):source.index('#include "scene_event_internal.h"')]
    fixture = (HERE / "Rain_00182bc0_20261005_fixture.c").read_text(encoding="utf-8")
    path = OUT / "behavior.c"
    path.write_text('#include "type.h"\nstruct RpMaterial;\n' + types + RUNTIME_C + "\n" +
                    body + "\n" + fixture + ENTRY_C, encoding="utf-8")
    runtime = native32_runtime()
    results = []
    for optimization in ("-O0", "-O2"):
        executable = runtime.compile(path, OUT / ("behavior-" + optimization[1:]), optimization, (ROOT / "include",))
        result = runtime.run(executable)
        record = {"optimization": optimization, "exit_code": result.returncode,
                  "stdout": result.stdout, "stderr": result.stderr,
                  "body_sha256": digest(body.encode()), "fixture_sha256": digest(path.read_bytes()),
                  "executable_sha256": digest(executable.read_bytes())}
        results.append(record)
        assert result.returncode == 0 and result.stdout == "rain scenarios=6 checks=254\n", record
        print(optimization, result.stdout.strip(), flush=True)
    return results


def relocation_controls(object_path):
    """Reject a wrong orphan-LO16 target and an unrelated altered instruction."""
    obj = V.ObjectFile(object_path)
    marker = next(m for m in V.scan_markers(ROOT / OWNERS[1]) if m.get("name") == "func_003a4270")
    gp, symbols = V.symbol_addresses()
    symbols = dict(symbols)
    symbols.update(proof.named_source_addresses())
    baseline = proof.linked_function(obj, marker, gp, symbols)
    hardware_name = "D_70000080"
    hardware_address = V.resolve_symbol(hardware_name, gp, symbols)
    assert hardware_address == 0x70000080
    original_resolve = V.resolve_symbol

    def wrong_address(name, selected_gp, addresses):
        value = original_resolve(name, selected_gp, addresses)
        return value + 4 if name == hardware_name else value

    try:
        V.resolve_symbol = wrong_address
        try:
            proof.linked_function(obj, marker, gp, symbols)
        except AssertionError:
            wrong_target_rejected = True
        else:
            raise AssertionError("The wrong low-half target was accepted")
    finally:
        V.resolve_symbol = original_resolve
    body, relocs = obj.function(marker["name"])
    relocated_offsets = {r["offset"] for r in relocs}
    literal_offset = next(i for i in range(0, len(body), 4) if i not in relocated_offsets)
    mutated = bytearray(body)
    struct.pack_into("<I", mutated, literal_offset, struct.unpack_from("<I", mutated, literal_offset)[0] ^ 1)

    class ChangedInstruction:
        def function(self, name):
            assert name == marker["name"]
            return bytes(mutated), relocs

    try:
        proof.linked_function(ChangedInstruction(), marker, gp, symbols)
    except AssertionError:
        wrong_instruction_rejected = True
    else:
        raise AssertionError("An altered non-relocated instruction was accepted")
    return {"function": marker["name"], "baseline_resolved_sha256": baseline["resolved_sha256"],
            "wrong_low_half_target_rejected": wrong_target_rejected,
            "changed_nonrelocated_instruction_rejected": wrong_instruction_rejected,
            "changed_instruction_offset": literal_offset}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--hashes-only", action="store_true")
    parser.add_argument("--allow-source-drift", action="store_true")
    args = parser.parse_args()
    archived_path = HERE / "Rain_00182bc0_20261005_receipt.json"
    drift = []
    if archived_path.exists():
        archived = json.loads(archived_path.read_text(encoding="utf-8"))
        drift = [path for path, expected in archived["inputs"].items()
                 if digest((ROOT / path).read_bytes()) != expected]
        if drift and not args.allow_source_drift:
            raise SystemExit("Archived inputs changed: " + ", ".join(drift))
    elif args.hashes_only:
        raise SystemExit("The archived receipt does not exist")
    if args.hashes_only:
        print("All archived input hashes match.")
        return
    OUT.mkdir(parents=True, exist_ok=True)
    proof.PROOFS = OUT
    cfg = V.load_config()
    proof.RETAIL = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), proof.META["sha1"])
    bounds = {int(address, 16) for address in proof.META["windows"]}
    bounds.update(int(address, 16) + size for address, size in proof.META["windows"].items())
    inputs = {relative: digest((ROOT / relative).read_bytes()) for relative in OWNERS}
    inputs.update({path.relative_to(ROOT).as_posix(): digest(path.read_bytes())
                   for path in (ROOT / "include").rglob("*.h")})
    owners, rows = [], []
    for relative in OWNERS:
        owner = ROOT / relative
        with P._owner_lock(owner):
            checked = V.verify_file(owner, cfg, proof.RETAIL, sorted(bounds), OUT)
        assert checked and all(r["status"] in ("MATCH", "ASM") for r in checked), checked
        rows.extend(checked)
        owners.append(proof.prove_owner(relative, OUT / (relative.replace("/", "_") + ".o"), owner.stem))
    control = relocation_controls(OUT / "src_promoted_code1_003a.c.o")
    behavior = smoke()
    changed = [path for path, expected in inputs.items() if digest((ROOT / path).read_bytes()) != expected]
    assert not changed, changed
    record = {"summary": dict(Counter(row["status"] for row in rows)), "inputs": inputs,
              "owners": owners, "results": rows, "negative_controls": control,
              "behavior": behavior, "source_drift_from_archive": drift, "changed_inputs_during_run": changed}
    (OUT / "receipt.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
    print("Rain recovery replay PASS:", record["summary"], "and both relocation negative controls", flush=True)


if __name__ == "__main__":
    main()
