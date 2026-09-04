"""`fndiff` must not report a meaningless zero for an unwritten function.

A function still served by its `INCLUDE_ASM` fallback compiles to the spliced
retail assembly, so diffing it against retail reports zero differing words no
matter what.  Waves read that as "this almost matches" and wrote it into floor
notes: `code1_004d.c` and `code1_004e.c` both ended up with `nd 0` claims on
functions that have no C body at all and measure `nd 2` once written.  The tool
now says so out loud, and these tests pin that.
"""

from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("fndiff", REPO / "tools" / "fndiff.py")
fndiff = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(fndiff)


class IncludeAsmDetectionTests(unittest.TestCase):
    def write(self, text: str) -> Path:
        tmp = Path(tempfile.mkdtemp()) / "unit.c"
        tmp.write_bytes(text.encode("utf-8"))
        return tmp

    def test_detects_an_include_asm_fallback(self) -> None:
        path = self.write(
            '// FUN_00100000\n'
            'INCLUDE_ASM("asm/nonmatchings/unit", func_00100000);\n'
        )
        self.assertTrue(fndiff._is_include_asm(path, "func_00100000"))

    def test_a_c_body_is_not_a_fallback(self) -> None:
        path = self.write(
            "// FUN_00100000\n"
            "void func_00100000(void) { return; }\n"
        )
        self.assertFalse(fndiff._is_include_asm(path, "func_00100000"))

    def test_another_functions_fallback_does_not_count(self) -> None:
        """The whole point is per-function; a neighbour's fallback must not leak."""
        path = self.write(
            '// FUN_00100000\n'
            "void func_00100000(void) { return; }\n"
            '// FUN_00100100\n'
            'INCLUDE_ASM("asm/nonmatchings/unit", func_00100100);\n'
        )
        self.assertFalse(fndiff._is_include_asm(path, "func_00100000"))
        self.assertTrue(fndiff._is_include_asm(path, "func_00100100"))

    def test_a_mention_inside_a_comment_is_not_a_fallback(self) -> None:
        path = self.write(
            "/* measured: restoring INCLUDE_ASM(func_00100000) was considered */\n"
            "// FUN_00100000\n"
            "void func_00100000(void) { return; }\n"
        )
        self.assertFalse(fndiff._is_include_asm(path, "func_00100000"))

    def test_a_name_that_is_a_prefix_of_another_does_not_match(self) -> None:
        path = self.write(
            '// FUN_00100000\n'
            'INCLUDE_ASM("asm/nonmatchings/unit", func_001000001);\n'
        )
        self.assertFalse(fndiff._is_include_asm(path, "func_00100000"))

    def test_a_missing_file_is_not_a_fallback(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            self.assertFalse(fndiff._is_include_asm(Path(temporary) / "missing.c", "func_00100000"))


if __name__ == "__main__":
    unittest.main()
