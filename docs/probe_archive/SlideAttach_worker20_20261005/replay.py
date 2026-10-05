"""Replay the native callback repair and both retained guarded candidates.

Run from the repository with a configured native compiler and retail ELF:
  build/venv/Scripts/python.exe docs/probe_archive/SlideAttach_worker20_20261005/replay.py
Outputs go to a fresh build/worker20-replay-* directory. No source is modified.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import re
import sys
import uuid

ARCHIVE = Path(__file__).resolve().parent
ROOT = ARCHIVE.parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import fnalign
import probe_variants as probe
import verify
from measure_guarded import extract_guarded_body


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def reverse_patch(source: str, patch: str) -> str:
    """Reverse the retained unified patch after checking every context line."""
    source_lines = source.splitlines(keepends=True)
    patch_lines = patch.splitlines(keepends=True)
    result, cursor, index = [], 0, 0
    while index < len(patch_lines):
        match = re.match(r"@@ -\d+(?:,\d+)? \+(\d+)(?:,\d+)? @@", patch_lines[index])
        if not match:
            index += 1
            continue
        start = int(match[1]) - 1
        old, new = [], []
        index += 1
        while index < len(patch_lines) and not patch_lines[index].startswith("@@"):
            line = patch_lines[index]
            if line.startswith((" ", "-")):
                old.append(line[1:])
            if line.startswith((" ", "+")):
                new.append(line[1:])
            index += 1
        assert start >= cursor and source_lines[start:start + len(new)] == new, "Source no longer matches retained patch"
        result.extend(source_lines[cursor:start])
        result.extend(old)
        cursor = start + len(new)
    result.extend(source_lines[cursor:])
    return "".join(result)


def lift(source: str, address: str) -> str:
    name, marker = "func_" + address, "FUN_" + address.upper()
    body = extract_guarded_body(source, marker, name)
    start, end = probe.region_for(source, marker, name)
    return probe.splice_region(source, start, end, body, "\n")


def main() -> None:
    receipt = json.loads((ARCHIVE / "receipt.json").read_text())
    cfg = verify.load_config()
    compiler = Path(verify.unit_compiler(ROOT / receipt["source"], cfg))
    assert sha(compiler.read_bytes()) == receipt["compiler_sha256"], "Native compiler hash differs from the retained measurement"
    source_path = ROOT / receipt["source"]
    after_bytes = source_path.read_bytes()
    assert sha(after_bytes) == receipt["source_after_sha256"], "Owner changed; replay at the archived source revision"
    after = after_bytes.decode("utf-8").replace("\r\n", "\n")
    before = reverse_patch(after, (ARCHIVE / "callback_contract.patch").read_text())
    assert sha(before.encode()) == receipt["source_before_normalized_sha256"]
    scratch = ROOT / "build" / ("worker20-replay-" + uuid.uuid4().hex[:12])
    scratch.mkdir(parents=True, exist_ok=False)
    objects = {}

    def compile_case(label: str, text: str, logical_source: Path) -> Path:
        folder = scratch / label
        folder.mkdir()
        cpath, opath = folder / "owner.c", folder / "owner.o"
        cpath.write_text(text, encoding="utf-8", newline="\n")
        ok, log = probe._compile_in_context(cpath, logical_source, cfg, opath)
        (folder / "compiler.log").write_text(log, encoding="utf-8")
        assert ok, label + ": " + log
        return opath

    for mode, transform in [("production", lambda text: text),
                            ("attach-enabled", lambda text: lift(text, "001d53e0"))]:
        for side, text in [("before", before), ("after", after)]:
            path = compile_case(mode + "-" + side, transform(text), source_path)
            objects[mode, side] = path
            assert sha(path.read_bytes()) == receipt["native_objects"][mode][side + "_sha256"]
        assert objects[mode, "before"].read_bytes() == objects[mode, "after"].read_bytes()
        print(mode + ": complete native objects identical; retained code/data/reference proof reproduced")

    windows = verify._read_json(verify.FUNCTION_WINDOWS)
    elf = verify.RetailElf(cfg["retail_elf"], verify._read_json(verify.TARGET), windows["sha1"])
    for target in receipt["targets"]:
        path = ROOT / target["source"]
        if target["name"] == "func_001d53e0":
            object_path = objects["attach-enabled", "after"]
        else:
            assert sha(path.read_bytes()) == target["source_sha256"], "Slide owner changed since measurement"
            object_path = compile_case("slide-enabled", lift(path.read_text(), "0029fbb0"), path)
        obj = verify.ObjectFile(object_path)
        body, relocations = obj.function(target["name"])
        address = int(target["address"], 16)
        retail = elf.bytes_at(address, target["window"])
        trimmed = retail
        while len(trimmed) > len(body) and trimmed[-4:] == b"\0" * 4:
            trimmed = trimmed[:-4]
        _, edits, _ = fnalign.align(fnalign.decode(trimmed, address), fnalign.decode(body, 0),
                                    {relocation["offset"] // 4 for relocation in relocations})
        assert len(body) == target["object_size"] and edits == target["aligned_edits"]
        assert sha(body) == target["function_sha256"]
        assert sha(retail) == target["retail_window_sha256"]
        print(f"{target['name']}: {len(body)}/{len(retail)} bytes, {edits} aligned edits; remains guarded")
    assert source_path.read_bytes() == after_bytes
    print("Artifacts:", scratch.relative_to(ROOT).as_posix())


if __name__ == "__main__":
    main()
