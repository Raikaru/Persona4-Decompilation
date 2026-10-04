"""Retail-derived transition trace for the actual guarded combination-row C.

The full body, native point/color constructors, typed layouts, signed inputs,
provider mutations, trace and all backing bytes run under native32 UB traps.
"""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import measure_guarded
import probe_variants
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

OWNER = ROOT / "src/Event/Fcl/y_fclCombineDraw.c"
FIXTURE = ROOT / "tests/fcl_combine_row_fixture.c.in"


def target_body():
    return measure_guarded.extract_guarded_body(OWNER.read_text(), "FUN_0031AC10", "func_0031ac10")


def fixture_source(body=None):
    constructors = (ROOT / "src/promoted/code1_002b.c").read_text()
    providers = []
    for address in ("002B2970", "002B2A60"):
        start, end = probe_variants.region_for(constructors, "FUN_" + address, "func_" + address.lower())
        providers.append(constructors[start:end])
    fixture = FIXTURE.read_text().replace("/* @PROVIDERS@ */", "\n".join(providers))
    fixture = fixture.replace("/* @BODY@ */", target_body() if body is None else body)
    return RUNTIME_C + fixture + ENTRY_C


MUTATIONS = {
    "stale_persona_reaches_digit_delay": ("        persona = delay;", "        /* stale lookup value */", 1),
    "digit_delay_zero_extended": ("        persona = delay;", "        persona = (u16)delay;", 1),
    "persona_overwritten_before_lookup": ("        persona = delay;", "", 1),
    "name_offset_leaks_into_tail": ("        digitRow = (s8)(rowIndex + 0xC);", "        rowY = 2.0f + rowY;\n        digitRow = (s8)(rowIndex + 0xC);", 1),
    "nonpositive_rows_are_visible": ("(rowAvailability = availability) > 0", "(rowAvailability = availability) != 0", 1),
    "second_exclusion_ignored": ("work->secondSelectedRow != rowIndex", "1", 1),
    "nonzero_check_mode": ("if (checkAvailability == 1)", "if (checkAvailability != 0)", 1),
    "special_row_uses_normal_tail": ("if (rowAvailability == 2)", "if (rowAvailability == 3)", 1),
    "name_offset_removed": ("2.0f + rowY", "rowY", 5),
    "row_spacing": ("rowIndex * 23", "rowIndex * 22", 1),
    "special_right_edge": ("(f32)0x11D + position.x", "286.0f + position.x", 5),
    "digit_row_width": ("digitRow = (s8)(rowIndex + 0xC)", "digitRow = (s16)(rowIndex + 0xC)", 1),
    "digit_level_signedness": ("digitRow, (s16)level", "digitRow, (s16)(level & 0x7FFF)", 1),
    "entrance_delay": ("delay + 3", "delay + 2", 7),
    "live_alpha": ("((FclCombineRowSprite *)func_002b6150(sprite))->alpha", "255", 4),
    "transition_scale_reload": ("1.0f, transitionScale,", "1.0f, iGpffff8504,", 14),
    "tail_scale_reload": ("        if (rowAvailability == 2) {", "        if (rowAvailability == 2) {\n            transitionScale = iGpffff8504;", 1),
    "cursor_position": ("position.x - 60.0f", "position.x - 59.0f", 3),
    "cursor_mode_nonzero": ("if (mode == 0)", "if (mode != 1)", 1),
    "work_pointer_reloaded": ("    if (work->firstSelectedRow", "    work = ((FclCombineRowTask *)task)->work;\n    if (work->firstSelectedRow", 1),
    "image_provider_not_reread": ("((FclCombineRowSprite *)func_002b6150(sprite))->image = (func_00109280((u16)persona) & 0xFF) + 0x1B;", "((FclCombineRowSprite *)func_002b6150(sprite))->image = 0x1B;", 1),
    "task_pointer_reloaded_for_digits": ("work->digitTask", "((FclCombineRowTask *)task)->work->digitTask", 2),
    "digit_color": ("func_002b2a60(0xCC, 0xFF, 0xFF, 0x80)", "func_002b2a60(0xCD, 0xFF, 0xFF, 0x80)", 1),
}


class FclCombineRowBehavior(unittest.TestCase):
    def runtime(self):
        try:
            return native32_runtime()
        except Native32Unavailable as error:
            self.skipTest(str(error))

    def test_retail_trace_and_backing_objects(self):
        runtime = self.runtime()
        with tempfile.TemporaryDirectory(prefix="p4_combine_row_") as directory:
            directory = Path(directory)
            source = directory / "fixture.c"
            source.write_text(fixture_source())
            outputs = []
            for opt in ("-O0", "-O2"):
                binary = runtime.compile(source, directory / opt[1:], opt, (ROOT / "include",))
                result = runtime.run(binary)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "PASS combine row scenarios=1620\n")
                outputs.append(result.stdout)
            self.assertEqual(*outputs)

    def test_negative_controls(self):
        runtime = self.runtime()
        body = target_body()
        with tempfile.TemporaryDirectory(prefix="p4_combine_row_negative_") as directory:
            directory = Path(directory)
            for name, (old, new, count) in MUTATIONS.items():
                with self.subTest(name=name):
                    self.assertEqual(body.count(old), count)
                    source = directory / (name + ".c")
                    mutated = body.replace(old, new)
                    if name == "persona_overwritten_before_lookup":
                        anchor = "    availability = 1;"
                        self.assertEqual(mutated.count(anchor), 1)
                        mutated = mutated.replace(anchor, "    persona = delay;\n" + anchor)
                    source.write_text(fixture_source(mutated))
                    binary = runtime.compile(source, directory / name, "-O2", (ROOT / "include",))
                    result = runtime.run(binary)
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertIn("scenario", result.stdout)


if __name__ == "__main__":
    unittest.main()
