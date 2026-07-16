from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "m2c_decompile.py"
SPEC = importlib.util.spec_from_file_location("p4_m2c_decompile", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
m2c_decompile = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(m2c_decompile)


class M2cWorkflowTests(unittest.TestCase):
    def test_extracts_only_requested_function(self) -> None:
        assembly = """glabel first
    addiu $2, $0, 1
    jr $31
    nop
glabel second
    addiu $2, $0, 2
    jr $31
    nop
"""
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "code.s"
            output = root / "second.s"
            source.write_text(assembly, encoding="utf-8")

            m2c_decompile.extract_function("second", [source], output)
            result = output.read_text(encoding="utf-8")

        self.assertIn("glabel second", result)
        self.assertIn("addiu $2, $0, 2", result)
        self.assertNotIn("glabel first", result)
        self.assertTrue(result.startswith(".set noat\n.set noreorder\n.text\n"))

    def test_missing_function_is_an_explicit_error(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "code.s"
            source.write_text("glabel present\n    jr $31\n    nop\n", encoding="utf-8")
            with self.assertRaisesRegex(SystemExit, "was not found"):
                m2c_decompile.extract_function("missing", [source], root / "out.s")

    def test_explicit_m2c_path_takes_precedence(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            script = Path(temporary) / "m2c.py"
            script.write_text("# test executable\n", encoding="utf-8")
            self.assertEqual(m2c_decompile.find_m2c(script), script.resolve())


if __name__ == "__main__":
    unittest.main()
