"""Run the real persona-menu renderer and its grid-gradient provider.

All 1024 visibility combinations and 1024 callback-mutation scenarios exercise
full RGBA copies, base-alpha preservation, wide scales, live portrait timers,
model opacity, assertion paths and repeatedly queried persona counts. The
recorded trace was cross-checked against the retail-repaired pre-allocation C
at O0/O2. The bounded cosine stub records its exact argument; this is not PS2
execution or a claim about numerical cosine implementation.
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

OWNER = ROOT / "src/Camp/cmpPersona.c"
PROVIDER = ROOT / "src/promoted/code1_0034.c"
FIXTURE = ROOT / "tests/persona_menu_fixture.c.in"


def fixture_source() -> str:
    source = OWNER.read_text(encoding="utf-8")
    types = source[source.index("/* Both 0x14-byte grids"):source.index("/* Draw the persona menu")]
    body = Q.function_bodies(OWNER)["func_00135dc0"][1]
    declarations = "\n".join(re.findall(r"extern [^;]+;", body))
    gradient = Q.function_bodies(PROVIDER)["func_0034f720"][1]
    return (RUNTIME_C + '\n#include "type.h"\n#include "shd_misc_internal.h"\n'
            + types + declarations + '\nextern char D_0064B310[16];\n'
            + body + "\n" + gradient + "\n"
            + FIXTURE.read_text(encoding="utf-8") + ENTRY_C)


class PersonaMenuSourceTests(unittest.TestCase):
    def test_renderer_and_native_byte_interface_are_active(self) -> None:
        marker = next(row for row in V.scan_markers(OWNER) if row["name"] == "func_00135dc0")
        self.assertFalse(marker.get("asm"))
        self.assertFalse(marker.get("nonmatching"))
        source = OWNER.read_text(encoding="utf-8")
        self.assertIn("func_00355410(u8 *task, u8 alpha)", source)
        self.assertIn("extern PersonaMenuColor D_005EB540[8];", source)
        self.assertIn("0.3f, 0.3f, 0.6f", source)
        fixture_source()


class PersonaMenuRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def test_grid_alpha_portrait_timing_and_mutating_callbacks(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_persona_menu_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(fixture_source(), encoding="utf-8")
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = self.runtime.compile(source, directory / ("fixture" + level),
                                                      level, (ROOT / "include",))
                    result = self.runtime.run(executable)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout,
                                     "persona-menu cases: 2048; grid draws: 277784; trace digest verified\n")


if __name__ == "__main__":
    unittest.main()
