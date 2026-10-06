"""Rebuild the contour proposal from either archived source state.

This replay writes only to a fresh build/ui-contour-replay-* directory. It
accepts the pinned source before installation as well as the installed source.
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

TARGET = "func_00267b20"


def sha(value):
    return hashlib.sha256(value).hexdigest()


def apply_patch(source, patch, reverse=False):
    lines, changes = source.splitlines(True), patch.splitlines(True)
    result, cursor, index = [], 0, 0
    while index < len(changes):
        header = re.match(r"@@ -(\d+)(?:,\d+)? \+(\d+)(?:,\d+)? @@", changes[index])
        if not header:
            index += 1
            continue
        start = int(header[2 if reverse else 1]) - 1
        before, after = [], []
        index += 1
        while index < len(changes) and not changes[index].startswith("@@"):
            line = changes[index]
            if line.startswith((" ", "-")):
                before.append(line[1:])
            if line.startswith((" ", "+")):
                after.append(line[1:])
            index += 1
        if reverse:
            before, after = after, before
        assert start >= cursor and lines[start:start + len(before)] == before, "Patch context changed"
        result.extend(lines[cursor:start])
        result.extend(after)
        cursor = start + len(before)
    result.extend(lines[cursor:])
    return "".join(result)


def active_target(source):
    start, end = P.region_for(source, "FUN_00267B20", TARGET)
    region = source[start:end]
    opening = "#ifdef NON_MATCHING\n"
    assert region.startswith(opening) and region.count("\n#else\n") == 1
    body = region[len(opening):].split("\n#else\n", 1)[0] + "\n"
    return P.splice_region(source, start, end, body, "\n")


def identity(obj):
    return {"sections": O.data_summary(obj), "relocations": O.canonical_data_relocs(obj)}


def unchanged(left, right, names):
    for name in names:
        old, old_refs = left.function(name)
        new, new_refs = right.function(name)
        assert old == new, (name, "changed instruction bytes")
        assert O.canonical_relocs(left, old_refs) == O.canonical_relocs(right, new_refs), (name, "changed references")


def resolve(obj, marker, runtime, retail, windows):
    code, relocations = obj.function(marker["name"])
    gp, globals_ = O.globals_table()
    for relocation in relocations:
        if relocation["r_type"] not in (7, 8):
            continue
        local = O.local_target(obj, relocation)
        address = runtime[local[0]] + local[1] if local else V.resolve_symbol(relocation.get("symbol") or "", gp, globals_)
        assert gp is not None and address is not None
        instruction = O.word(code, relocation["offset"])
        displacement = address + O.signed16(instruction) - gp
        assert -32768 <= displacement < 32768
        if relocation["r_type"] == 8:
            assert (instruction >> 21) & 31 == 28, "Literal load must use GP"
    window = windows["windows"][f"{marker['addr']:08x}"]
    target = retail.bytes_at(marker["addr"], window)
    linked, references, offsets = O.resolve_function(obj, marker["name"], target.ljust(max(window, len(code)), b"\0"), runtime)
    return {"name": marker["name"], "size": len(code), "window": window, "resolved_words": len(offsets),
        "resolved_sha256": sha(linked), "zero_only_tail": len(code) <= window and not any(target[len(code):]),
        "references": len(references)}


def main():
    receipt = json.loads((ARCHIVE / "receipt.json").read_text())
    owner = ROOT / receipt["binding"]["source"]
    raw = owner.read_bytes()
    text = raw.decode("utf-8").replace("\r\n", "\n")
    patch = (ARCHIVE / "contour.patch").read_text()
    if sha(raw) == receipt["binding"]["owner_sha256"]:
        before, after = text, apply_patch(text, patch)
    else:
        assert sha(raw) == receipt["source_after_sha256"], "Replay at an archived source state"
        before, after = apply_patch(text, patch, reverse=True), text
    assert sha(before.encode()) == receipt["source_before_normalized_sha256"]
    assert sha(after.encode()) == receipt["source_after_normalized_sha256"]
    cfg = V.load_config()
    assert sha(Path(V.unit_compiler(owner, cfg)).read_bytes()) == receipt["binding"]["compiler_sha256"]
    assert V.unit_compile_flags(owner, cfg["compile_flags"]) == receipt["binding"]["profile"]
    for path, expected in receipt["binding"]["inputs"].items():
        if path != receipt["binding"]["source"]:
            assert sha((ROOT / path).read_bytes()) == expected, "Changed input: " + path
    out = ROOT / "build" / ("ui-contour-replay-" + uuid.uuid4().hex[:12])
    out.mkdir(parents=True, exist_ok=False)
    objects = {}
    for mode in ("production", "target", "guards"):
        for side, source in (("before", before), ("after", after)):
            code = active_target(source) if mode == "target" else ("#define NON_MATCHING\n" + source if mode == "guards" else source)
            destination = out / (mode + "-" + side)
            destination.mkdir()
            (destination / "owner.c").write_text(code, encoding="utf-8", newline="\n")
            with P.scratch_source(owner) as scratch:
                scratch.write_text(code, encoding="utf-8", newline="\n")
                ok, log = P._compile_in_context(scratch, owner, cfg, destination / "owner.o")
            (destination / "compiler.log").write_text(log, encoding="utf-8")
            assert ok, log
            objects[mode, side] = V.ObjectFile(destination / "owner.o")
        print("compiled", mode, "before/after", flush=True)
    markers = {marker["name"]: marker for marker in V.scan_markers(owner)}
    assert len(markers) == 65 and sum(not marker.get("asm") for marker in markers.values()) == 62
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), windows["sha1"])
    baseline = objects["production", "before"]
    addresses, storage = O.prove_data(baseline, markers, retail)
    keys = O.section_keys(baseline)
    placements = {keys[sid]: address for sid, address in addresses.items()}
    report = {"storage": storage, "functions": []}
    unchanged(baseline, objects["production", "after"], markers)
    unchanged(objects["guards", "before"], objects["guards", "after"], [name for name in markers if name != TARGET])
    assert identity(objects["guards", "before"]) == identity(objects["guards", "after"])
    for mode in ("production", "target"):
        for side in ("before", "after"):
            obj = objects[mode, side]
            assert identity(obj) == identity(baseline), (mode, side, "allocated storage changed")
            keys = O.section_keys(obj)
            runtime = {sid: placements[key] for sid, key in keys.items() if key in placements}
            for name, marker in markers.items():
                row = resolve(obj, marker, runtime, retail, windows)
                expected = receipt["target_" + side] if mode == "target" and name == TARGET else None
                assert row["zero_only_tail"]
                assert row["resolved_words"] == (expected["resolved_words"] if expected else 0), (mode, side, row)
                if expected:
                    assert row["resolved_sha256"] == expected["resolved_sha256"]
                report["functions"].append({"mode": mode, "side": side, **row})
    (out / "proof.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    assert owner.read_bytes() == raw
    print("PROVED 65 production functions, 608 references, four allocated data sections.")
    print("Guarded contour: 175 -> 31 resolved words; 64 target-active siblings exact.")
    print("All three guards compile; other guards and matched siblings preserve code and references.")
    print("Production remains 62 C matches and 3 ASM; no new C match credit.")
    print("Artifacts:", out.relative_to(ROOT).as_posix())


if __name__ == "__main__":
    main()
