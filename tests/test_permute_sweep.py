from __future__ import annotations

import importlib.util
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_permute_sweep",
                                              REPO / "tools" / "permute_sweep.py")
assert SPEC is not None and SPEC.loader is not None
sweep = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(sweep)

FILE = """#include "include_asm.h"

// FUN_00123456 NONMATCHING
#ifdef NON_MATCHING
void func_00123456(void)
{
    return;
}
#else
INCLUDE_ASM("asm/nonmatchings/thing", func_00123456);
#endif

// FUN_00123500
void func_00123500(void)
{
}
"""


class SpliceTests(unittest.TestCase):
    """The permuters write only the mutated function to --out, with no marker.

    Pasting that over the marker-to-brace span used to delete the marker, which
    makes the function invisible to verify.py and to fndiff -- so the sweep could
    neither confirm nor deny its own hit.
    """

    def setUp(self) -> None:
        # enterContext is 3.11+, and this suite must run on 3.10 locally and 3.11 in CI
        self.tmp = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, self.tmp, True)
        self.path = self.tmp / "thing.c"
        self.path.write_bytes(FILE.encode())

    def test_keeps_the_marker_when_the_region_has_none(self) -> None:
        region = ["void func_00123456(void)", "{", "    return;", "}"]
        self.assertTrue(sweep.splice(self.path, "func_00123456", region))
        out = self.path.read_text().splitlines()
        self.assertIn("// FUN_00123456", out)
        self.assertEqual(out.count("// FUN_00123456"), 1)

    def test_strips_the_nonmatching_tag_when_splicing_a_winner(self) -> None:
        """Splicing a winner in is the moment the body stops being a non-match."""
        region = ["void func_00123456(void)", "{", "    return;", "}"]
        sweep.splice(self.path, "func_00123456", region)
        self.assertNotIn("NONMATCHING", self.path.read_text())

    def test_uses_the_regions_own_marker_when_present(self) -> None:
        region = ["// FUN_00123456", "void func_00123456(void)", "{", "}"]
        sweep.splice(self.path, "func_00123456", region)
        out = self.path.read_text().splitlines()
        self.assertEqual(out.count("// FUN_00123456"), 1)

    def test_leaves_a_sibling_function_alone(self) -> None:
        region = ["void func_00123456(void)", "{", "}"]
        sweep.splice(self.path, "func_00123456", region)
        text = self.path.read_text()
        self.assertIn("// FUN_00123500", text)
        self.assertIn("void func_00123500(void)", text)

    def test_reports_failure_for_an_unknown_function(self) -> None:
        self.assertFalse(sweep.splice(self.path, "func_00999999", ["x"]))


class ReproducesGuardTests(unittest.TestCase):
    def test_a_missing_marker_is_a_false_not_an_exit(self) -> None:
        """permute.Target calls sys.exit when it cannot find the marker.

        That SystemExit would tear down the sweep worker instead of failing one
        target, so the guard must swallow BaseException.
        """
        tmp = Path(tempfile.mkdtemp())
        self.addCleanup(shutil.rmtree, tmp, True)
        path = tmp / "x.c"
        path.write_bytes(b"int f(void) { return 0; }\n")
        before = path.read_bytes()
        self.assertFalse(sweep._reproduces(path, "func_00123456", ["int f(void){return 0;}"]))
        self.assertEqual(path.read_bytes(), before, "the file must be restored")


if __name__ == "__main__":
    unittest.main()
