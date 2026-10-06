"""Replay byte-aligned digit-color storage in four complete-owner contexts.

Requires configured retail/compiler tools. Inputs remain private and are
never bundled. This script does not edit source; each run writes fresh
evidence beneath build/ui-digit-packed-replay-<id>.
"""
from collections import Counter
from pathlib import Path
import hashlib
import json
import re
import struct
import sys
import uuid

sys.dont_write_bytecode = True

ROOT = Path(__file__).resolve().parents[3]
ARCHIVE = Path(__file__).resolve().parent
sys.path[:0] = [str(ARCHIVE), str(ROOT / "tools")]
import native_references as O
import verify as V
import probe_variants as P
import fnalign as F


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def patch_source(source, patch, reverse=False):
    lines = source.splitlines(keepends=True)
    patch_lines = patch.splitlines(keepends=True)
    result, cursor, index = [], 0, 0
    while index < len(patch_lines):
        header = re.match(r"@@ -(\d+)(?:,\d+)? \+(\d+)(?:,\d+)? @@", patch_lines[index])
        if not header:
            index += 1
            continue
        start = int(header.group(2 if reverse else 1)) - 1
        assert cursor <= start
        result.extend(lines[cursor:start])
        cursor = start
        index += 1
        while index < len(patch_lines) and not patch_lines[index].startswith("@@ "):
            line = patch_lines[index]
            if line.startswith(("--- ", "+++ ")):
                break
            if line.startswith("\\"):
                index += 1
                continue
            tag, content = line[:1], line[1:]
            if reverse:
                tag = {"+": "-", "-": "+"}.get(tag, tag)
            if tag in (" ", "-"):
                assert lines[cursor] == content, (cursor, lines[cursor], content)
                cursor += 1
            if tag in (" ", "+"):
                result.append(content)
            assert tag in (" ", "+", "-"), tag
            index += 1
    result.extend(lines[cursor:])
    return "".join(result)


def resolve(obj, name, target, bases):
    code, relocs = obj.function(name)
    gp, symbols = O.globals_table()
    for reloc in relocs:
        if reloc["r_type"] == 7:
            local = O.local_target(obj, reloc)
            address = bases[local[0]] + local[1] if local else V.resolve_symbol(reloc.get("symbol") or "", gp, symbols)
            assert address is not None and gp is not None
            relative = address + O.signed16(O.word(code, reloc["offset"])) - gp
            assert -32768 <= relative <= 32767
    linked, references, _ = O.resolve_function(obj, name, target.ljust(max(len(code), len(target)), b"\0"), bases)
    differences = [offset for offset in range(0, max(len(code), len(target)), 4)
                   if (offset < len(code) or any(target[offset:offset + 4])) and
                   linked[offset:offset + 4] != target[offset:offset + 4]]
    calls = lambda data: [((O.word(data, offset) & 0x03ffffff) << 2) for offset in range(0, len(data), 4)
                          if O.word(data, offset) >> 26 == 3]
    return {"size": len(code), "window": len(target), "resolved_words": len(differences),
            "resolved_offsets": differences, "resolved_sha256": sha(linked),
            "references": references, "call_sequence_equal": calls(linked) == calls(target),
            "zero_only_tail": len(code) <= len(target) and not any(target[len(code):])}


def main():
    receipt = json.loads((ARCHIVE / "receipt.json").read_text())
    owner = ROOT / receipt["owner"]
    original = owner.read_bytes()
    owner_digest = sha(original)
    text = original.decode().replace("\r\n", "\n")
    patch = (ARCHIVE / "owner.patch").read_text()
    if owner_digest == receipt["source_before_sha256"]:
        before = text
        after = patch_source(before, patch)
    elif owner_digest == receipt["source_after_sha256"]:
        after = text
        before = patch_source(after, patch, reverse=True)
    else:
        raise AssertionError("Owner changed; review source and binding before replay")
    assert sha(before.encode()) == receipt["source_before_normalized_sha256"]
    assert sha(after.encode()) == receipt["source_after_normalized_sha256"]
    for path, digest in receipt["inputs"].items():
        assert sha((ROOT / path).read_bytes()) == digest, path
    cfg = V.load_config()
    assert sha(Path(V.unit_compiler(owner, cfg)).read_bytes()) == receipt["compiler_sha256"]
    assert V.unit_compile_flags(owner, cfg["compile_flags"]) == receipt["profile"]
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), windows["sha1"])
    markers = {m["name"]: m for m in V.scan_markers(owner)}
    assert len(markers) == 75
    output = ROOT / "build" / ("ui-digit-packed-replay-" + uuid.uuid4().hex[:12])
    output.mkdir()
    objects, files = {}, {}
    for mode, source in (("production-before", before), ("production-after", after),
                         ("guarded-before", "#define NON_MATCHING\n" + before),
                         ("guarded-after", "#define NON_MATCHING\n" + after)):
        directory = output / mode
        directory.mkdir()
        files[mode] = directory / "owner.c"
        files[mode].write_text(source, encoding="utf-8", newline="\n")
        with P.scratch_source(owner) as scratch:
            scratch.write_text(source, encoding="utf-8", newline="\n")
            ok, log = P._compile_in_context(scratch, owner, cfg, directory / "owner.o")
        (directory / "compiler.log").write_text(log)
        assert ok, (mode, log[-2000:])
        objects[mode] = V.ObjectFile(directory / "owner.o")

    production = objects["production-before"]
    bases, storage = O.prove_data(production, markers, retail)
    identity = {"sections": O.data_summary(production), "relocations": O.canonical_data_relocs(production)}
    keys_to_bases = {O.section_keys(production)[sid]: address for sid, address in bases.items()}
    functions = []
    for mode, obj in objects.items():
        assert {"sections": O.data_summary(obj), "relocations": O.canonical_data_relocs(obj)} == identity
        placed = {sid: keys_to_bases[key] for sid, key in O.section_keys(obj).items() if key in keys_to_bases}
        for name, marker in markers.items():
            target = retail.bytes_at(marker["addr"], windows["windows"][f"{marker['addr']:08x}"])
            result = resolve(obj, name, target, placed)
            if mode.startswith("production") or name != receipt["target"]:
                assert result["resolved_words"] == 0 and result["zero_only_tail"], (mode, name, result)
            else:
                expected = receipt["target_after" if mode.endswith("after") else "target_before"]
                for key in ("size", "window", "resolved_words", "resolved_sha256", "zero_only_tail"):
                    assert result[key] == expected[key], (mode, key, result[key], expected[key])
                assert result["call_sequence_equal"]
            if name != receipt["target"]:
                old_code, old_refs = production.function(name)
                code, refs = obj.function(name)
                assert code == old_code
                assert O.canonical_relocs(obj, refs) == O.canonical_relocs(production, old_refs)
            functions.append({"mode": mode, "name": name, **result})

    trace = F.decode(objects["guarded-after"].function(receipt["target"])[0], 0)
    assert len([instruction for instruction in trace if instruction.startswith(("lwr ", "lwl "))]) == 4
    assert not any(instruction.startswith("lwc1 ") and any(offset in instruction for offset in ("0x75(", "0x179(")) for instruction in trace)
    bounds = {int(address, 16) for address in windows["windows"]}
    bounds.update(int(address, 16) + size for address, size in windows["windows"].items() if size)
    compiler = V._compile
    def reuse(path, configuration, destination):
        assert path == files["production-after"]
        destination.write_bytes(objects["production-after"].data)
        return True, "Reused the just-compiled logical-owner production object."
    try:
        V._compile = reuse
        normal = V.verify_file(files["production-after"], cfg, retail, sorted(bounds), output)
    finally:
        V._compile = compiler
    counts = dict(Counter(row["status"] for row in normal))
    assert counts == {"MATCH": 74, "ASM": 1}, counts
    assert owner.read_bytes() == original
    for path, digest in receipt["inputs"].items():
        assert sha((ROOT / path).read_bytes()) == digest, path
    proof = {"source_changed": False, "normal_verifier": counts, "storage": storage,
             "functions": functions, "new_C_matches": 0,
             "target_status": "Still guarded; 192 resolved differing words, 1348/1360 bytes."}
    (output / "proof.json").write_text(json.dumps(proof, indent=2) + "\n")
    (output / "normal-verifier.json").write_text(json.dumps(normal, indent=2) + "\n")
    print("PASS: 75 exact production functions; 74 exact guarded siblings; allocated data preserved")
    print("TARGET: 244 -> 192 resolved words; 1380 -> 1348 / 1360 bytes; 12 zero tail bytes")
    print(output.relative_to(ROOT).as_posix())


if __name__ == "__main__":
    main()
