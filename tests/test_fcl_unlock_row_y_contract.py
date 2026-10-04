"""Check retained row coordinates using the actual guarded Fcl renderer."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import measure_guarded
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

OWNER = ROOT / "src/Event/Fcl/y_fclCombineDraw.c"
FIXTURE = Path(__file__).with_name("fcl_unlock_row_y_fixture.c.in")


def actual_source():
    return measure_guarded.extract_guarded_body(OWNER.read_text(), "FUN_0031AC10", "func_0031ac10")


class FclUnlockRowYContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def execute(self, body, optimization):
        with tempfile.TemporaryDirectory(prefix="p4_unlock_row_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(RUNTIME_C + FIXTURE.read_text().replace("@BODY@", body) + ENTRY_C)
            executable = self.runtime.compile(source, directory / "fixture", optimization, (ROOT / "include",))
            return self.runtime.run(executable)

    def test_original_row_y_survives_name_sprite(self):
        for optimization in ("-O0", "-O2"):
            with self.subTest(optimization=optimization):
                result = self.execute(actual_source(), optimization)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "unlock_row_cases=115200\n")
                print(optimization, result.stdout.strip())

    def test_fixture_rejects_coordinate_regressions(self):
        body = actual_source()
        mutations = (
            ("old-row-shift", "        digitRow = (s8)(rowIndex + 0xC);", "        rowY = 2.0f + rowY;\n        digitRow = (s8)(rowIndex + 0xC);"),
            ("name-offset", "2.0f + rowY", "3.0f + rowY"),
            ("digit-offset", "func_002b2970(position.x - 16.0f, rowY)", "func_002b2970(position.x - 16.0f, rowY + 2.0f)"),
            ("decoration-offset", "rowY - 12.0f", "rowY - 10.0f"),
            ("hand-offset", "rowY - 8.0f", "rowY - 6.0f"),
        )
        for name, old, new in mutations:
            with self.subTest(mutation=name):
                self.assertIn(old, body)
                result = self.execute(body.replace(old, new), "-O2")
                self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                self.assertIn("scenario", result.stdout)


if __name__ == "__main__":
    unittest.main()
