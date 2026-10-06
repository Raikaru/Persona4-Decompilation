"""Rebuild and resolve the complete map owner for its constructor recovery.

The baseline is read from git and the proposed source is reconstructed from
the retained patch. The active production source is never modified, so this
replay remains valid after subsequent map recoveries.
"""
from pathlib import Path
import argparse
import difflib
import json
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
ARCHIVE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / "tools"))
import probe_variants as P
import verify as V
import owner_proof as E

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--out", required=True, help="A fresh output directory under the repository")
args = parser.parse_args()
OUT = (ROOT / args.out).resolve()
OUT.relative_to(ROOT)
assert not OUT.exists(), "Use a fresh output directory to preserve previous evidence"
OWNER = ROOT / "src/promoted/y_smap.c"
BASELINE = '41a2002a50c30d68a08ca07e4a8850348796e13d'
BEFORE_SHA256 = 'd9839d28dd158ecb14a5900f48d915a5c234ab08bc1f6921a728cd050f423852'
AFTER_SHA256 = '35d8ab93d63052c1ced899e77da31979df7f5de660b20a01b6a5f5574203c2f6'
EXPECTED_HEADERS = {'include/fcl_scale_transition.h': '8a7d415d26dd0f76c3de90767ea4769414d8b9628ffd1352da46b6de818d3461', 'include/type.h': 'd98ec5482a2782c2a9ca41f93d590ab2007b9817936d5208746d6e8794906db3', 'include/fcl_color.h': 'e2714424eab279564c3dbf361c834693fec6324d1d94040873086d7d7ba2b085', 'include/include_asm.h': '8c2cde497ecdcafdb07af8d62c1e0eb1a30eeb14d1c4567128e5f2714e5cd963', 'include/sdk_task_registration.h': '7dbebce4a3eeb57f807e5f06a5cc1d6b16b89b644e4105bd2685000dd22075d1', 'include/fcl_draw_types.h': '74e28b6c0d04a9437a81b92da411259a187becb85f3d0a00a9bafe01a3a4a782'}


def apply_patch(original, patch):
    """Apply only this exact single-file unified patch, checking every old line."""
    source = original.decode().splitlines(True)
    lines = patch.splitlines(True)
    assert lines[:2] == ["--- a/src/promoted/y_smap.c\n", "+++ b/src/promoted/y_smap.c\n"]
    output, cursor, index = [], 0, 2
    while index < len(lines):
        match = re.fullmatch(r"@@ -(\d+),(\d+) \+(\d+),(\d+) @@\n", lines[index])
        assert match, lines[index]
        old_start, old_count, new_start, new_count = map(int, match.groups())
        old_start -= 1
        assert cursor <= old_start <= len(source)
        output.extend(source[cursor:old_start])
        assert len(output) == new_start - 1
        cursor, old_seen, new_seen = old_start, 0, 0
        index += 1
        while index < len(lines) and not lines[index].startswith("@@"):
            line = lines[index]
            assert line[:1] in (" ", "+", "-"), line
            if line[0] != "+":
                assert cursor < len(source) and source[cursor] == line[1:], (cursor, line)
                cursor += 1
                old_seen += 1
            if line[0] != "-":
                output.append(line[1:])
                new_seen += 1
            index += 1
        assert (old_seen, new_seen) == (old_count, new_count)
    output.extend(source[cursor:])
    return "".join(output).encode()


before = subprocess.check_output(["git", "show", BASELINE + ":src/promoted/y_smap.c"], cwd=ROOT)
assert E.sha(before) == BEFORE_SHA256
after = apply_patch(before, (ARCHIVE / "source.patch").read_text())
assert E.sha(after) == AFTER_SHA256
assert after.count(b"// FUN_002AE630\n") == 1
assert b'INCLUDE_ASM("asm/nonmatchings/y_smap", func_002ae630)' not in after
assert b"smapUnitPresent" not in after
assert after.count(b"*(u8 **)((u32)taskRow + (s32)offsetY * 0x40 + tileColumn * 4 + 0x148)") == 9
active_source = OWNER.read_bytes()
active_inputs = E.header_closure(OWNER)
OUT.mkdir(parents=True)
(OUT / "before.c").write_bytes(before)
(OUT / "after.c").write_bytes(after)
cfg = V.load_config()
assert E.sha(Path(V.unit_compiler(OWNER, cfg)).read_bytes()) == '286548490e2e902cfef21dcf39cd5af23766731585d90dea747f8781eadcafd7'
assert V.unit_compile_flags(OWNER, cfg["compile_flags"]) == ["-O2", "-Iinclude"]
metadata = V._read_json(V.FUNCTION_WINDOWS)
assert metadata["sha1"] == '4eeec0360cf2715535d9f7e52eb69d786fb0158c'
windows = metadata["windows"]
retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), metadata["sha1"])
with P.scratch_source(OWNER) as scratch:
    scratch.write_bytes(after)
    markers = {m["name"]: m for m in V.scan_markers(scratch)}
bindings = {}
variant = "native-task-slot-addresses"

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
        closure = E.header_closure(scratch)
        bindings[name] = {("src/promoted/y_smap.c" if path == scratch.resolve() else path.relative_to(ROOT).as_posix()): digest
                          for path, digest in closure.items()}
        assert bindings[name] == dict(EXPECTED_HEADERS, **{"src/promoted/y_smap.c": E.sha(source)})
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
        if function == "func_002ae630":
            (OUT / (name + "-002ae630-resolved.bin")).write_bytes(code)
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
           if r["function"] not in {"func_002ae630"}), guard_rows
assert OWNER.read_bytes() == active_source
assert E.header_closure(OWNER) == active_inputs
source_diff = "".join(difflib.unified_diff(before.decode().splitlines(True), after.decode().splitlines(True),
                                        fromfile="src/promoted/y_smap.c", tofile="proposed/y_smap.c", n=3))
(OUT / "source.diff").write_text(source_diff)
receipt = {"variant": variant, "owner": "src/promoted/y_smap.c",
           "baseline_source_sha256": E.sha(before), "proposed_source_sha256": E.sha(after),
           "compiler_sha256": E.sha(Path(V.unit_compiler(OWNER, cfg)).read_bytes()),
           "compile_flags": V.unit_compile_flags(OWNER, cfg["compile_flags"]),
           "retail_sha1": metadata["sha1"],
           "baseline_commit": BASELINE,
           "baseline_source_inputs": bindings["default-before"],
           "proposed_source_inputs": bindings["default-after"],
           "default_before": {k: v for k, v in before_proof.items() if k not in ("functions", "owned_data")},
           "default_after": {k: v for k, v in after_proof.items() if k not in ("functions", "owned_data")},
           "guarded_provider_002ac750_unchanged": True,
           "guarded_changes": [r for r in guard_rows if not r["code_equal"] or not r["relocations_equal"]]}
save("receipt.json", receipt)
print("PROVED", OUT.relative_to(ROOT), flush=True)

assert bindings["default-before"] == bindings["guarded-before"]
assert bindings["default-after"] == bindings["guarded-after"]
target = next(row for row in after_proof["functions"] if row["function"] == "func_002ae630")
before_by_name = {row["function"]: row for row in before_proof["functions"]}
siblings = []
for row in after_proof["functions"]:
    if row["function"] == "func_002ae630":
        continue
    old = before_by_name[row["function"]]
    assert row["size"] == old["size"] and row["resolved_sha256"] == old["resolved_sha256"]
    siblings.append({key: value for key, value in row.items() if key != "relocations"})
emitted = sorted({s["name"] for s in candidate.symbols if s["size"] and s["info"] & 15 == 2 and s["name"]})
assert emitted == sorted(markers)
receipt.update(target=target, default_siblings=siblings, owned_data_after=after_proof["owned_data"],
               all_emitted_functions_accounted_for=emitted,
               source_patch_sha256=E.sha((ARCHIVE / "source.patch").read_bytes()),
               reference_inputs={relative: E.sha((ROOT / relative).read_bytes()) for relative in [
                   "tools/verify.py", "tools/probe_variants.py", "config/symbol_addrs.txt", "config/symbol_data_addrs.txt",
                   "asm/nonmatchings/y_smap/func_002ae630.s", "asm/nonmatchings/y_smap/func_002b2290.s",
                   "src/Kernel/sdkSpr.c", "src/Yajima/y_symbol.c", "src/promoted/y_draw.c"]})
save("receipt.json", receipt)
print("SEALED", AFTER_SHA256, len(target["relocations"]), "target relocations", len(siblings), "unchanged siblings", flush=True)
