"""Replay the local renderer contracts against fully resolved retail bytes.

Run with the configured native compiler from the pinned owner revision. This
script writes only to a new build/ui-renderer-replay-* directory.
"""
from pathlib import Path
import hashlib
import json
import re
import sys
import uuid

ARCHIVE = Path(__file__).resolve().parent
ROOT = ARCHIVE.parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import verify as V
import probe_variants as P
import native_references as O


def sha(data):
    return hashlib.sha256(data).hexdigest()


def reverse_patch(source, patch):
    lines = source.splitlines(True)
    changes = patch.splitlines(True)
    result, cursor, index = [], 0, 0
    while index < len(changes):
        match = re.match(r"@@ -\d+(?:,\d+)? \+(\d+)(?:,\d+)? @@", changes[index])
        if not match:
            index += 1
            continue
        start = int(match[1]) - 1
        before, after = [], []
        index += 1
        while index < len(changes) and not changes[index].startswith("@@"):
            line = changes[index]
            if line.startswith((" ", "-")):
                before.append(line[1:])
            if line.startswith((" ", "+")):
                after.append(line[1:])
            index += 1
        assert start >= cursor and lines[start:start + len(after)] == after, "Patch context moved"
        result.extend(lines[cursor:start])
        result.extend(before)
        cursor = start + len(after)
    result.extend(lines[cursor:])
    return "".join(result)


def main():
    receipt = json.loads((ARCHIVE / "receipt.json").read_text())
    owner = ROOT / receipt["source"]
    raw = owner.read_bytes()
    assert sha(raw) == receipt["source_after_sha256"], "Replay at the archived source revision"
    cfg = V.load_config()
    assert sha(Path(V.unit_compiler(owner, cfg)).read_bytes()) == receipt["binding"]["compiler_sha256"]
    assert V.unit_compile_flags(owner, cfg["compile_flags"]) == receipt["binding"]["profile"]
    for path, expected in receipt["binding"]["inputs"].items():
        if path != receipt["source"]:
            assert sha((ROOT / path).read_bytes()) == expected, "Changed input: " + path
    after = raw.decode("utf-8").replace("\r\n", "\n")
    before = reverse_patch(after, (ARCHIVE / "caller_contract.patch").read_text())
    assert sha(before.encode()) == receipt["source_before_normalized_sha256"]
    out = ROOT / "build" / ("ui-renderer-replay-" + uuid.uuid4().hex[:12])
    out.mkdir(parents=True, exist_ok=False)
    objects = {}
    for mode, prefix in (("production", ""), ("guards", "#define NON_MATCHING\n")):
        for side, source in (("before", before), ("after", after)):
            dest = out / (mode + "-" + side)
            dest.mkdir()
            text = prefix + source
            (dest / "owner.c").write_text(text, encoding="utf-8", newline="\n")
            with P.scratch_source(owner) as scratch:
                scratch.write_text(text, encoding="utf-8", newline="\n")
                ok, log = P._compile_in_context(scratch, owner, cfg, dest / "owner.o")
            (dest / "compiler.log").write_text(log, encoding="utf-8")
            assert ok, log
            objects[mode, side] = V.ObjectFile(dest / "owner.o")
    markers = {m["name"]: m for m in V.scan_markers(owner)}
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), windows["sha1"])
    baseline = objects["production", "before"]
    bases, storage = O.prove_data(baseline, markers, retail)
    keys = O.section_keys(baseline)
    placements = {keys[sid]: address for sid, address in bases.items()}
    identity = {"data": O.data_summary(baseline), "relocations": O.canonical_data_relocs(baseline)}
    report = {"storage": storage, "functions": []}
    expected_guards = {r["name"]: r for r in receipt["guards"]}
    for mode in ("production", "guards"):
        left, right = objects[mode, "before"], objects[mode, "after"]
        assert {"data": O.data_summary(right), "relocations": O.canonical_data_relocs(right)} == identity
        keys = O.section_keys(right)
        runtime = {sid: placements[key] for sid, key in keys.items() if key in placements}
        for name, marker in markers.items():
            old_code, old_relocs = left.function(name)
            code, relocs = right.function(name)
            assert old_code == code, (mode, name, "changed instruction bytes")
            assert O.canonical_relocs(left, old_relocs) == O.canonical_relocs(right, relocs), (mode, name)
            size = windows["windows"][f"{marker['addr']:08x}"]
            target = retail.bytes_at(marker["addr"], size)
            resolved, references, offsets = O.resolve_function(right, name, target.ljust(max(size, len(code)), b"\0"), runtime)
            expected = expected_guards[name]["resolved_words"] if mode == "guards" and marker.get("asm") else 0
            assert len(offsets) == expected, (mode, name, len(offsets), expected)
            if expected == 0:
                assert len(code) <= size and not any(target[len(code):]), (mode, name, "nonzero tail")
            if mode == "guards" and marker.get("asm"):
                assert sha(resolved) == expected_guards[name]["resolved_sha256"]
            report["functions"].append({"mode": mode, "name": name, "resolved_words": len(offsets),
                "resolved_sha256": sha(resolved), "size": len(code), "relocations": len(references)})
        print(mode, ":", len(markers), "functions preserve code and references", flush=True)
    (out / "proof.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    assert owner.read_bytes() == raw
    print("126 production functions fully resolve to retail; 124 C matches, 2 ASM.")
    print("Both guarded bodies remain non-exact; no new C match credit.")
    print("Artifacts:", out.relative_to(ROOT).as_posix())


if __name__ == "__main__":
    main()
