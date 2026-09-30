"""Exercise the actual 32-bit debug-window controller against a state oracle.

The fixture covers all states, themes, flags, entry kinds and modifier masks,
selection bounds, analog deadzone boundaries, and live callback mutations.
This is source-level behavior and ABI testing, not PS2 gameplay execution.
"""
from pathlib import Path
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q
import verify as V

OWNER = ROOT / "src/promoted/code1_0046.c"
FIXTURE = ROOT / "tests/window_controller_fixture.c.in"


def fixture_source() -> str:
    source = OWNER.read_text(encoding="utf-8")
    engine = source[source.index("typedef struct WindowDeviceStatePrefix"):
                    source.index("/* Initialize and animate the border")]
    types = source[source.index("/* sdkLbox allocates a 0x190-byte controller"):
                   source.index("/* Process the debug list window")]
    body = Q.function_bodies(OWNER)["func_0046f2b0"][1]
    declarations = """
#include "type.h"
#include "rw/plcore/barenderstate.h"
typedef void (*KWindowEntryCallback)(void *);
typedef s32 (*WindowRenderStateSet)(RwRenderState, void *);
"""
    return RUNTIME_C + declarations + engine + types + body + FIXTURE.read_text() + ENTRY_C


class WindowControllerSourceTests(unittest.TestCase):
    def test_controller_is_active_and_owns_complete_records(self) -> None:
        marker = next(row for row in V.scan_markers(OWNER) if row["name"] == "func_0046f2b0")
        self.assertFalse(marker.get("asm"))
        self.assertFalse(marker.get("nonmatching"))
        source = fixture_source()
        self.assertIn("ControllerRect rectangle = { x, y, width, height };", source)
        self.assertIn("ControllerVertex vertices[4];", source)
        self.assertIn("void *argument;", source)


class WindowControllerRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def test_state_input_and_live_callback_contracts(self) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_window_controller_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(fixture_source(), encoding="utf-8")
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = self.runtime.compile(source, directory / ("fixture" + level),
                                                      level, (ROOT / "include",))
                    result = self.runtime.run(executable)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, "window-controller cases: 20288; state, callback, input, and render contracts verified\n")


if __name__ == "__main__":
    unittest.main()
