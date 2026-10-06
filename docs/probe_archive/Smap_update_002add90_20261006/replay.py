"""Rebuild and fully resolve the map owner before and after its C recovery.

Run from the repository root. Compiler and retail ELF locations come from the
existing local verifier configuration. No build/ scratch helper is required.
"""
from pathlib import Path
from collections import Counter
import argparse
import difflib
import json
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools"))
import probe_variants as P
import verify as V
import owner_proof as E

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--out", required=True, help="Fresh output directory beneath the repository")
args = parser.parse_args()
OUT = (ROOT / args.out).resolve()
OUT.relative_to(ROOT)
assert not OUT.exists(), "Use a fresh output directory to preserve prior evidence"
OWNER = ROOT / "src/promoted/y_smap.c"
BASELINE = "4b32b6ccbb935945461838d8981ba508f675358a"
before = subprocess.check_output(["git", "show", BASELINE + ":src/promoted/y_smap.c"], cwd=ROOT)
after = OWNER.read_bytes()
assert E.sha(before) == "fdc023222cb22dc83e8c4064658515498e8882bdf895108a961c03592ece2b6d", "Baseline source drift"
assert E.sha(after) == "d9839d28dd158ecb14a5900f48d915a5c234ab08bc1f6921a728cd050f423852", "Installed source drift"
assert after.count(b"// FUN_002ADD90\n") == 1
assert b'INCLUDE_ASM("asm/nonmatchings/y_smap", func_002add90)' not in after
assert b"void func_002ac750(u8 arg0, u8 arg1)" in after
OUT.mkdir(parents=True)
(OUT / "before.c").write_bytes(before)
(OUT / "after.c").write_bytes(after)
cfg = V.load_config()
metadata = V._read_json(V.FUNCTION_WINDOWS)
windows = metadata["windows"]
retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), metadata["sha1"])
inputs = E.header_closure(OWNER)
markers = {m["name"]: m for m in V.scan_markers(OWNER)}
variant = "reviewed-final"


def save(name, data):
    (OUT / name).write_text(json.dumps(data, indent=2) + "\n")


def compile_source(name, source, guarded=False):
    folder = OUT / name
    folder.mkdir()
    config = dict(cfg)
    if guarded:
        config["compile_flags"] = [*cfg["compile_flags"], "-DNON_MATCHING"]
    output = folder / "owner.o"
    with P.scratch_source(OWNER) as scratch:
        scratch.write_bytes(source)
        ok, log = P._compile_in_context(scratch, OWNER, config, output)
    (folder / "compile.log").write_text(log)
    assert ok, log
    return V.ObjectFile(output)


def prove_default(name, obj):
    try:
        bases, data = E.prove_data(obj, markers, retail)
    except Exception:
        save(name + "-storage-debug.json", {
            "sections": obj.sections, "symbols": obj.symbols,
            "data_relocations": E.data_relocs(obj),
        })
        raise
    rows = []
    for function, marker in markers.items():
        window = windows[f'{marker["addr"]:08x}']
        target = retail.bytes_at(marker["addr"], window)
        code, relocations, offsets = E.resolve_function(obj, function, target, bases)
        row = {"function": function, "address": f'{marker["addr"]:08x}',
               "size": len(code), "window": window, "differing_words": len(offsets),
               "resolved_sha256": E.sha(code), "zero_tail": len(target) - len(code),
               "relocations": relocations}
        assert not offsets and len(code) <= len(target) and not any(target[len(code):]), row
        rows.append(row)
        if function == "func_002add90":
            (OUT / (name + "-002add90-resolved.bin")).write_bytes(code)
    result = {"object_sha256": E.sha(obj.data), "functions": rows,
              "function_count": len(rows), "code_relocation_count": sum(len(r["relocations"]) for r in rows),
              "owned_data": data, "owned_data_bytes": sum(r["bytes"] for r in data),
              "owned_data_relocation_count": sum(len(r["pointer_entries"]) for r in data)}
    save(name + ".json", result)
    print(name, len(rows), "exact functions", result["code_relocation_count"],
          "resolved code relocs", result["owned_data_bytes"], "data bytes", flush=True)
    return result


baseline = compile_source("default-before", before)
candidate = compile_source("default-after", after)
before_proof = prove_default("default-before", baseline)
after_proof = prove_default("default-after", candidate)

guard_before = compile_source("guarded-before", before, True)
guard_after = compile_source("guarded-after", after, True)
guard_rows = []
for name, marker in markers.items():
    old_code, old_refs = guard_before.function(name)
    new_code, new_refs = guard_after.function(name)
    target = retail.bytes_at(marker["addr"], windows[f'{marker["addr"]:08x}'])
    row = {"function": name, "before_size": len(old_code), "after_size": len(new_code),
           "code_equal": old_code == new_code,
           "relocations_equal": E.canonical_relocs(guard_before, old_refs) == E.canonical_relocs(guard_after, new_refs),
           "before_masked_difference_bytes": V.compare(old_code, old_refs, target)[0],
           "after_masked_difference_bytes": V.compare(new_code, new_refs, target)[0],
           "before_code_sha256": E.sha(old_code), "after_code_sha256": E.sha(new_code)}
    guard_rows.append(row)
    if not row["code_equal"] or not row["relocations_equal"]:
        print("GUARDED_CHANGE", name, row["before_size"], row["after_size"],
              row["before_masked_difference_bytes"], row["after_masked_difference_bytes"], flush=True)
save("guarded-comparison.json", guard_rows)
assert next(r for r in guard_rows if r["function"] == "func_002ac750")["code_equal"]
assert all(r["code_equal"] and r["relocations_equal"] for r in guard_rows
           if r["function"] not in {"func_002add90", "func_002ae630"}), guard_rows
assert OWNER.read_bytes() == after
assert E.header_closure(OWNER) == inputs
source_diff = "".join(difflib.unified_diff(before.decode().splitlines(True), after.decode().splitlines(True),
                                        fromfile="src/promoted/y_smap.c", tofile="proposed/y_smap.c", n=3))
(OUT / "source.diff").write_text(source_diff)
receipt = {"variant": variant, "owner": "src/promoted/y_smap.c",
           "baseline_source_sha256": E.sha(before), "proposed_source_sha256": E.sha(after),
           "compiler_sha256": E.sha(Path(V.unit_compiler(OWNER, cfg)).read_bytes()),
           "compile_flags": V.unit_compile_flags(OWNER, cfg["compile_flags"]),
           "retail_sha1": metadata["sha1"],
           "source_inputs": {p.relative_to(ROOT).as_posix(): value for p, value in inputs.items()},
           "default_before": {k: v for k, v in before_proof.items() if k not in ("functions", "owned_data")},
           "default_after": {k: v for k, v in after_proof.items() if k not in ("functions", "owned_data")},
           "guarded_provider_002ac750_unchanged": True,
           "guarded_changes": [r for r in guard_rows if not r["code_equal"] or not r["relocations_equal"]]}
save("receipt.json", receipt)
print("PROVED", OUT.relative_to(ROOT), flush=True)
