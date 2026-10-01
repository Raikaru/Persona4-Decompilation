"""Execute the recovered Persona task renderer and actual meter provider.

The frozen pre-typing reference was instruction-audited against retail, with
only six independent argument-load order swaps. Differential traces cover
1024 visibility combinations, then 1024 callback mutations, at O0 and O2.
This tests recovered C semantics on 32-bit pointers, not PS2 execution.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q
import verify as V
from measure_guarded import extract_guarded_body
OWNER = ROOT / "src/promoted/shdPersona.c"


def fixture_source(mutation=None, provider_mutation=None):
    text = OWNER.read_text()
    types = text[text.index("/* Renderer view of the existing"):text.index("/* Update task counters")]
    target = extract_guarded_body(text, "FUN_00119E10", "func_00119e10")
    provider = Q.function_bodies(OWNER)["func_00116d40"][1]
    if provider_mutation:
        before, after = provider_mutation
        if provider.count(before) != 1:
            raise AssertionError(f"Expected one provider mutation site: {before}")
        provider = provider.replace(before, after)
    if mutation:
        before, after = mutation
        if target.count(before) != 1:
            raise AssertionError(f"Expected one mutation site: {before}")
        target = target.replace(before, after)
    fixture = (ROOT / "tests/persona_task_renderer_fixture.c.in").read_text()
    fixture = fixture.replace("/* ACTUAL_PROVIDER */", provider)
    fixture = fixture.replace("/* ACTUAL_TARGET */", target)
    fixture = fixture.replace("/* REFERENCE_TARGET */", (ROOT / "tests/persona_task_renderer_reference.c.in").read_text())
    return RUNTIME_C + '\n#include "type.h"\n#include "shd_misc_internal.h"\n' + types + fixture + ENTRY_C


class PersonaTaskSourceTests(unittest.TestCase):
    def test_active_and_coherent_byte_contract_remain(self):
        marker = next(r for r in V.scan_markers(OWNER) if r["name"] == "func_00119e10")
        self.assertFalse(marker.get("nonmatching"))
        self.assertFalse(marker.get("asm"))
        text = OWNER.read_text()
        for signature in (
            "void func_00116610(s64 arg0, f32 fparg0, u8 arg1",
            "void func_001163e0(s64 arg0, f32 fparg0, u8 arg1",
            "void func_00116820(Vec2f position, f32 depth, u8 alpha",
            "void func_00116d40(Vec2f position, f32 depth, u8 alpha",
        ):
            self.assertIn(signature, text)
        self.assertIn("colors[0].rgba[3] = (u8)((f32)alpha * rate);", text)
        fixture_source()


class PersonaTaskRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def run_fixture(self, source, optimization):
        with tempfile.TemporaryDirectory(prefix="p4_persona_task_") as directory:
            directory = Path(directory)
            path = directory / "fixture.c"
            path.write_text(source)
            binary = self.runtime.compile(path, directory / "fixture", optimization, (ROOT / "include",))
            return self.runtime.run(binary)

    def test_visibility_mutations_counters_and_actual_meter(self):
        for level in ("-O0", "-O2"):
            with self.subTest(optimization=level):
                result = self.run_fixture(fixture_source(), level)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "persona-task cases: 2052; callback traces, alpha and meter provider verified\n")

    def test_negative_controls_reject_semantic_regressions(self):
        mutations = {
            "gate": ("((flags & 1) == 0) || ((flags & 8) == 0)", "((flags & 1) == 0) && ((flags & 8) == 0)"),
            "alpha": ("work->channels[1].alpha,", "work->channels[1].alpha ^ 1,"),
            "comparison_record": ("work->channels[7].alpha, (u8 *)&work->persona[1]", "work->channels[7].alpha, (u8 *)&work->persona[0]"),
            "coordinate": ("qx = (f32)0x131;", "qx = (f32)0x132;"),
            "meter_step": ("(f32)(i * 19)", "(f32)(i * 20)"),
            "live_flags": ("if ((work->flags & 0x800000) != 0)", "if ((flags & 0x800000) != 0)"),
        }
        for name, mutation in mutations.items():
            with self.subTest(mutation=name):
                result = self.run_fixture(fixture_source(mutation), "-O2")
                self.assertNotEqual(result.returncode, 0, "negative control survived: " + name)
                self.assertIn("scenario", result.stdout)


    def test_negative_controls_reject_meter_regressions(self):
        mutations = {
            "bonus_alpha": ("(u8)((f32)alpha * rate)", "(u8)alpha"),
            "meter_width": ("((filled & 0xFF) * 204) / 99 + 10", "((filled & 0xFF) * 204) / 99 + 11"),
        }
        for name, mutation in mutations.items():
            with self.subTest(mutation=name):
                result = self.run_fixture(fixture_source(provider_mutation=mutation), "-O2")
                self.assertNotEqual(result.returncode, 0, "provider negative control survived: " + name)
                self.assertIn("scenario", result.stdout)


if __name__ == "__main__":
    unittest.main()
