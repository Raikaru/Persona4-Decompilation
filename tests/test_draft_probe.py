from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_draft_probe",
                                              REPO / "tools" / "draft_probe.py")
assert SPEC is not None and SPEC.loader is not None
probe = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(probe)


class CleanTests(unittest.TestCase):
    def test_expands_m2c_field(self) -> None:
        out = probe.clean("x = M2C_FIELD(p, s32 *, 0x10);")
        self.assertEqual(out, "x = *(s32 *)((u8 *)(p) + 0x10);")

    def test_expands_nested_m2c_field(self) -> None:
        """The inner one has to be rewritten too, so the pass repeats to a fixpoint."""
        out = probe.clean("y = M2C_FIELD(M2C_FIELD(p, u8 **, 4), s32 *, 8);")
        self.assertNotIn("M2C_FIELD", out)
        self.assertIn("*(u8 **)((u8 *)(p) + 4)", out)

    def test_rejects_a_draft_with_placeholders(self) -> None:
        """M2C_UNK/M2C_ERROR mean m2c could not decode part of the function; such a
        draft compiles into something confidently wrong, which is worse than none."""
        for bad in ("a = M2C_UNK;", "M2C_ERROR(/* unknown instruction */);"):
            self.assertIsNone(probe.clean(f"void f(void) {{ {bad} }}"))

    def test_keeps_a_clean_draft_unchanged(self) -> None:
        src = "void f(void) {\n    g();\n}"
        self.assertEqual(probe.clean(src), src)


class FindDraftTests(unittest.TestCase):
    def test_returns_none_for_an_unknown_function(self) -> None:
        self.assertIsNone(probe.find_draft("func_deadbeef"))

    def test_a_forward_declaration_is_not_mistaken_for_a_definition(self) -> None:
        """m2c files open with declarations like `s32 func_001077f0();`.

        Matching one and then walking braces captures the NEXT function's body, so
        the tool measures one function's draft against another's window - which
        reads as a plausible bad score rather than an error. Found in the wild.
        """
        import tempfile, shutil, os
        tmp = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, tmp, True)
        gen = probe.Path("src/generated")
        cwd = os.getcwd()
        try:
            (tmp / "src" / "generated").mkdir(parents=True)
            (tmp / "src" / "generated" / "x.c").write_text(
                "s32 func_00111111();\n"
                "void func_00222222(void) {\n    other();\n}\n"
                "s32 func_00111111(s16 a) {\n    return a;\n}\n")
            os.chdir(tmp)
            got = probe.find_draft("func_00111111")
        finally:
            os.chdir(cwd)
        self.assertIsNotNone(got)
        self.assertIn("s16 a", got.split("\n")[0])
        self.assertNotIn("other()", got)

    @unittest.skipUnless((REPO / "src" / "generated").is_dir(), "no drafts present")
    def test_a_found_draft_is_brace_balanced(self) -> None:
        """The extractor walks braces, so a truncated draft would corrupt the file
        it is spliced into."""
        found = 0
        for name in ("func_00107a00", "func_001077f0", "func_00288020"):
            text = probe.find_draft(name)
            if text is None:
                continue
            found += 1
            self.assertEqual(text.count("{"), text.count("}"), name)
            self.assertTrue(text.rstrip().endswith("}"), name)
            self.assertIn(name, text.split("\n")[0])
        self.assertGreater(found, 0, "expected at least one known draft")


if __name__ == "__main__":
    unittest.main()
