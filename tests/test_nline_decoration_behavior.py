"""Execute the recovered decoration mesh against indexed triangle geometry.

The complete helper/body region and real vertex writer come from the checkout.
Only the writer's entry name is changed to interpose observable provider calls.
All target pointer/integer casts execute unchanged in a real 32-bit process.
"""
from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
import re
import sys
import tempfile
import unittest

ROOT = Path(os.environ.get("P4_CONTRACT_ROOT", Path(__file__).resolve().parents[1])).resolve()
SOURCE = Path(os.environ.get("P4_NLINE_DECORATION_SOURCE", ROOT / "src/promoted/nLine.c")).resolve()
TEMPLATE = Path(__file__).with_name("nline_decoration_fixture.c.in")
sys.path.insert(0, str(ROOT / "tests"))
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime


def sha(raw: bytes) -> str:
    return hashlib.sha256(raw).hexdigest()


def code_mask(text: str) -> str:
    # Keep offsets while discarding comments and both kinds of C literals.
    pattern = re.compile(r'/\*[\s\S]*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'')
    return pattern.sub(lambda m: "".join("\n" if c == "\n" else " " for c in m.group()), text)


def function_span(text: str, name: str) -> tuple[int, int]:
    clean = code_mask(text)
    match = re.search(r"^\s*(?:s32|void)\s+" + re.escape(name) + r"\s*\([^;]*?\)\s*\{", clean, re.M)
    if match is None:
        raise AssertionError(f"Missing actual C definition {name}")
    opened = clean.index("{", match.start())
    level = 0
    for pos in range(opened, len(clean)):
        level += (clean[pos] == "{") - (clean[pos] == "}")
        if level == 0:
            return match.start(), pos + 1
    raise AssertionError(f"Unclosed definition {name}")


def extracted(source_path: Path = SOURCE) -> tuple[str, dict]:
    raw = source_path.read_bytes()
    owner = raw.decode("utf-8").replace("\r\n", "\n")
    marker = re.search(r"^// FUN_0034E360\b[^\n]*", owner, re.M)
    if marker is None or "NONMATCHING" in marker.group():
        raise AssertionError("Decoration callback must be recovered active C")
    start, end = function_span(owner, "func_0034e360")
    style = re.search(r"typedef\s+struct\s*\{\s*s16\s+count;[^}]*\}\s*NLineDecorationStyle\s*;", owner[:start])
    if style is None:
        raise AssertionError("Missing actual decoration style layout")
    region = owner[style.start():end]
    if "INCLUDE_ASM" in region or "#ifdef" in region:
        raise AssertionError("Fixture refuses an assembly fallback or conditional substitute")
    vector = re.search(r"typedef\s+struct\s*\{\s*f32\s+x;\s*f32\s+y;\s*\}\s*Vec2f\s*;", owner)
    if vector is None:
        raise AssertionError("Missing actual coordinate record")
    writer_path = ROOT / "src/promoted/code1_0034.c"
    writer_raw = writer_path.read_bytes()
    writer_owner = writer_raw.decode("utf-8").replace("\r\n", "\n")
    a, b = function_span(writer_owner, "func_0034f0d0")
    writer = writer_owner[a:b]
    renamed_writer = writer.replace("func_0034f0d0", "actual_vertex_writer", 1)
    # Compiler-control directives have no runtime semantics on the host.
    host_region = re.sub(r"^\s*#pragma[^\n]*\n", "", region, flags=re.M)
    fixture = TEMPLATE.read_text(encoding="utf-8")
    substitutions = {"@@RUNTIME@@": RUNTIME_C, "@@ENTRY@@": ENTRY_C,
                     "@@VECTOR_TYPE@@": vector.group(), "@@RECOVERED_SOURCE@@": host_region,
                     "@@WRITER_SOURCE@@": renamed_writer}
    for key, value in substitutions.items():
        assert fixture.count(key) == 1, key
        fixture = fixture.replace(key, value)
    return fixture, dict(source=str(source_path), source_sha256=sha(raw),
        function_sha256=sha(owner[start:end].encode()), region_sha256=sha(region.encode()),
        writer=str(writer_path), writer_owner_sha256=sha(writer_raw), writer_function_sha256=sha(writer.encode()),
        fixture_sha256=sha(fixture.encode()), template_sha256=sha(TEMPLATE.read_bytes()),
        target_body_rewritten_for_host=False, removed_compiler_pragmas=True,
        writer_entry_renamed_for_interposition=True)


EXPECTED_GROUPS = [12960, 5120, 18600, 5376, 1280]
EXPECTED_SCENARIOS = sum(EXPECTED_GROUPS)


class NLineDecorationBehaviorTests(unittest.TestCase):
    def test_actual_decoration_and_writer(self) -> None:
        try:
            runtime = native32_runtime()
        except Native32Unavailable as exc:
            self.skipTest(str(exc))
        fixture, identity = extracted()
        retained = os.environ.get("P4_CONTRACT_ARTIFACTS")
        temporary = tempfile.TemporaryDirectory(prefix="p4_decoration_") if not retained else None
        directory = Path(retained) if retained else Path(temporary.name)
        directory.mkdir(parents=True, exist_ok=True)
        try:
            path = directory / "fixture.c"
            if path.exists():
                self.assertEqual(path.read_bytes(), fixture.encode(), "Existing fixture differs")
            else:
                path.write_text(fixture, encoding="utf-8")
            reports = []
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = runtime.compile(path, directory / ("decoration" + level), level, (ROOT / "include",))
                    result = runtime.run(executable)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    summary = json.loads(result.stdout)
                    self.assertEqual(summary["scenarios"], EXPECTED_SCENARIOS)
                    self.assertEqual(summary["groups"], EXPECTED_GROUPS)
                    self.assertEqual(summary["pointer_bits"], 32)
                    self.assertGreater(summary["vertices"], 500000)
                    row = dict(optimization=level, **summary, exit_code=result.returncode,
                               executable_sha256=sha(executable.read_bytes()))
                    reports.append(row)
                    print("decoration-i386", level, json.dumps(summary), flush=True)
            self.assertEqual(sha(SOURCE.read_bytes()), identity["source_sha256"])
            if retained:
                (directory / "runtime.json").write_text(json.dumps(dict(identity=identity, executions=reports), indent=2) + "\n", encoding="utf-8")
        finally:
            if temporary:
                temporary.cleanup()


if __name__ == "__main__":
    unittest.main()
