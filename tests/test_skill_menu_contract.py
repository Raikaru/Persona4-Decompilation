"""Exercise the full skill-menu renderer and its real packed-color consumer.

The native test extracts active C, recovered layouts and declarations unchanged.
Its fixed trace was cross-checked against a separate retail-repaired draft at O0
and O2 before being recorded. The domain covers every visibility combination,
byte-alpha endpoints, selected/hidden rows, scrolling boundaries and callbacks
that mutate live menu fields. This is C behavior coverage, not PS2 execution.
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

OWNER = ROOT / "src/Camp/cmpSkill.c"
PROVIDER = ROOT / "src/promoted/code1_0013.c"
FIXTURE = ROOT / "tests/skill_menu_fixture.c.in"


def fixture_source() -> str:
    source = OWNER.read_text(encoding="utf-8")
    local_types = source[source.index("typedef struct {\n    f32 x;"):
                         source.index("s16 func_0010b510")]
    record = source[source.index("typedef struct SkillRec"):source.index("/* Inline search")]
    view = source[source.index("/* One 0x30-byte entry"):
                  source.index("/* Preserve the observed left/right")]
    declarations = []
    for name in ("func_0034f1e0", "func_0034c270", "func_0034f320", "func_0034f2e0",
                 "func_0034f9d0", "func_0013b370", "func_0013b420", "func_00113730",
                 "func_00113790", "func_0013ad40"):
        match = re.search(r"void " + name + r"\([^;]+;", source)
        if match is None:
            raise AssertionError(name + ": missing canonical declaration")
        declarations.append(match.group(0))
    for name in ("D_00762DC0", "D_005ED790", "D_0064B2E0", "D_0064B2E4",
                 "D_0064B2E8", "D_0064B2EC", "D_0064B2F4"):
        match = re.search(r"extern u8 " + name + r"\[[^\]]*\];", source)
        if match is None:
            raise AssertionError(name + ": missing data declaration")
        declarations.append(match.group(0))
    bodies = Q.function_bodies(OWNER)
    helper = source[source.index("static inline f32 skillPositionAdd"):
                    source.index("/* Draw the skill menu")]
    actual = helper + "\n" + bodies["func_00138bf0"][1]
    actual += "\n" + Q.function_bodies(PROVIDER)["func_0013b370"][1]
    return (RUNTIME_C + '\n#include "type.h"\n#include "shd_misc_internal.h"\n'
            + local_types + record + view + "\n".join(declarations) + "\n"
            + actual + "\n" + FIXTURE.read_text(encoding="utf-8") + ENTRY_C)


class SkillMenuSourceTests(unittest.TestCase):
    def test_renderer_and_packet_consumer_are_active(self) -> None:
        for path, name in ((OWNER, "func_00138bf0"), (PROVIDER, "func_0013b370")):
            marker = next(row for row in V.scan_markers(path) if row["name"] == name)
            self.assertFalse(marker.get("asm"), name)
            self.assertFalse(marker.get("nonmatching"), name)
        source = OWNER.read_text(encoding="utf-8")
        self.assertIn("extern u8 D_00762DC0[8];", source)
        self.assertIn("Vec2f arg1, PackedColor4 arg2", PROVIDER.read_text(encoding="utf-8"))
        fixture_source()


class SkillMenuRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def test_visibility_scrolling_color_packets_and_live_callbacks(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_skill_menu_") as temporary:
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
                                     "skill-menu cases: 6144; decoration calls: 81920; trace digest verified\n")


if __name__ == "__main__":
    unittest.main()
