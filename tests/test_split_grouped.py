from __future__ import annotations

import importlib.util
import sys
import tempfile
import unittest
from pathlib import Path

MODULE_PATH = Path(__file__).resolve().parents[1] / "tools" / "split_grouped.py"
sys.path.insert(0, str(MODULE_PATH.parent))
SPEC = importlib.util.spec_from_file_location("p4_split_grouped", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
split_grouped = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(split_grouped)


class SplitGroupedTests(unittest.TestCase):
    def test_existing_owner_aborts_before_any_file_changes(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "grouped.c"
            text = (
                "extern int shared;\n"
                "// FUN_00000010\nint first(void) { return shared; }\n"
                "// FUN_00000020\nint second(void) { return shared + 1; }\n"
            )
            source.write_text(text)
            outdir = root / "owners"
            outdir.mkdir()
            old = outdir / "old.c"
            old.write_bytes(b"previously split body\n")
            with self.assertRaisesRegex(FileExistsError, "refusing to overwrite"):
                split_grouped.split(source, {"00000010": "new.c", "00000020": "old.c"}, outdir)
            self.assertEqual(old.read_bytes(), b"previously split body\n")
            self.assertFalse((outdir / "new.c").exists())
            self.assertEqual(source.read_text(), text)

    def test_comment_brace_and_nonmatching_guard_preserve_each_marker(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "grouped.c"
            source.write_text(
                "extern int shared;\n"
                "// FUN_00000010\n"
                "int first(void) { /* { */ return shared; }\n"
                "// FUN_00000020 NONMATCHING\n"
                "#ifdef NON_MATCHING\n"
                "int second(void) { return shared + 1; }\n"
                "#else\n"
                "INCLUDE_ASM(\"asm/nonmatchings/grouped\", func_00000020);\n"
                "#endif\n"
                "// FUN_00000030\n"
                "INCLUDE_ASM(\"asm/nonmatchings/grouped\", func_00000030);\n"
            )
            outdir = root / "owners"
            counts = split_grouped.split(source, {
                "00000010": "first.c", "00000020": "second.c"
            }, outdir)
            self.assertEqual(counts, {"<unattributed>": 1, "first.c": 1, "second.c": 1})
            self.assertIn("// FUN_00000010", (outdir / "first.c").read_text())
            second = (outdir / "second.c").read_text()
            self.assertIn("#ifdef NON_MATCHING", second)
            self.assertIn("#endif", second)
            self.assertNotIn("FUN_00000030", second)
            self.assertIn("// FUN_00000030", source.read_text())
            self.assertIn("extern int shared;", source.read_text())


if __name__ == "__main__":
    unittest.main()
