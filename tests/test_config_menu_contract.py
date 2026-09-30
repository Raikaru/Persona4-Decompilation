"""Exercise the actual configuration renderer with real 32-bit pointers.

The 1008 base cases cover visibility, backdrop modes, opacity boundaries,
selection and option enable state. Another 1008 cases mutate live animation,
graph and timer fields across rendering callbacks. The expected trace was
cross-checked against the original guarded C at O0/O2. This is a source contract
test under typed mocks, not a claim of PS2 gameplay execution.
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

OWNER = ROOT / "src/Camp/cmpConfig.c"
FIXTURE = ROOT / "tests/config_menu_fixture.c.in"


def fixture_source() -> str:
    source = OWNER.read_text(encoding="utf-8")
    types = source[source.index("/* The menu owns"):source.index("/* Draw the live configuration")]
    body = Q.function_bodies(OWNER)["func_0035d0a0"][1]
    names = ("func_0034f1e0", "func_0034c270", "func_0034f2e0", "func_0034f9d0", "func_0035dfb0")
    declarations = "\n".join(re.search(r"^void " + name + r"\([^;]+;", source, re.M).group(0)
                             for name in names)
    data = """
extern u8 D_0064B2E0[4], D_0064B2E8[4], D_0064B2EC[4], D_0064B304[4];
extern s32 D_0064D230[7], D_0064D380[7];
"""
    return (RUNTIME_C + '\n#include "type.h"\ntypedef struct { f32 x, y; } Vec2f;\n'
            + types + declarations + data + "\n" + body + "\n"
            + FIXTURE.read_text(encoding="utf-8") + ENTRY_C)


class ConfigMenuSourceTests(unittest.TestCase):
    def test_renderer_and_backdrop_contract_are_active(self) -> None:
        marker = next(row for row in V.scan_markers(OWNER) if row["name"] == "func_0035d0a0")
        self.assertFalse(marker.get("asm"))
        self.assertFalse(marker.get("nonmatching"))
        source = OWNER.read_text(encoding="utf-8")
        self.assertIn("func_0034c270(Vec2f position, s32 alpha, s32 mode, f32 depth)", source)
        self.assertIn("ConfigMotion motion[18];", source)
        self.assertIn("ConfigGraphEntry graph[11];", source)
        fixture_source()


class ConfigMenuRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def test_graph_colors_and_live_timer_and_button_fields(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_config_menu_") as temporary:
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
                                     "config-menu cases: 2016; live callbacks and trace digest verified\n")


if __name__ == "__main__":
    unittest.main()
