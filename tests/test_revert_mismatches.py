"""Tests for tools/revert_mismatches.py.

Reverting is the safety valve after a matching wave: it must put back exactly
the `INCLUDE_ASM` line the file started with, name the right asm unit, and
never disturb a neighbouring function or a `// FUN_` marker. Getting the unit
wrong would point the fallback at another translation unit's bytes, which the
verifier would then happily accept as a match.

The verify call is stubbed so these run without the compiler.
"""

from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "revert_mismatches.py"
SPEC = importlib.util.spec_from_file_location("p4_revert_mismatches", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
revert = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(revert)

SOURCE = """\
#include "include_asm.h"

// FUN_00246910
s32 func_00246910(void) { return 1; }

// FUN_00246940
s32 func_00246940(s16 arg0) { return arg0; }

// FUN_00246970
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246970);
"""


class UnitNameTests(unittest.TestCase):
    def test_no_include_asm_means_no_unit(self) -> None:
        self.assertIsNone(revert.asm_unit("int f(void) { return 0; }\n"))

    def test_picks_the_majority_unit(self) -> None:
        text = (
            'INCLUDE_ASM("asm/nonmatchings/a", f1);\n'
            'INCLUDE_ASM("asm/nonmatchings/b", f2);\n'
            'INCLUDE_ASM("asm/nonmatchings/b", f3);\n'
        )
        self.assertEqual(revert.asm_unit(text), "asm/nonmatchings/b")


class RegionTests(unittest.TestCase):

    def test_unknown_marker_returns_none(self) -> None:
        self.assertIsNone(revert.region_after_marker(SOURCE, "FUN_DEADBEEF"))


class ApplyTests(unittest.TestCase):
    def setUp(self) -> None:
        self.tmp = tempfile.TemporaryDirectory()
        self.path = Path(self.tmp.name) / "cmmMisc.c"
        with open(self.path, "wb") as handle:
            handle.write(SOURCE.encode("utf-8"))
        self.addCleanup(self.tmp.cleanup)
        self._real_verify = revert.verify

        def cleanup() -> None:
            revert.verify = self._real_verify

        self.addCleanup(cleanup)

    def run_tool(self, rows, apply=True):
        revert.verify = lambda path: rows
        import sys

        saved = sys.argv
        sys.argv = ["revert_mismatches.py", str(self.path)] + (["--apply"] if apply else [])
        try:
            return revert.main()
        finally:
            sys.argv = saved

    def test_reverts_only_the_mismatching_function(self) -> None:
        rows = [
            {"status": "MATCH", "name": "func_00246910", "addr": "00246910"},
            {"status": "MISMATCH", "name": "func_00246940", "addr": "00246940"},
            {"status": "ASM", "name": "func_00246970", "addr": "00246970"},
        ]
        self.run_tool(rows)
        expected = SOURCE.replace(
            "s32 func_00246940(s16 arg0) { return arg0; }",
            'INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246940);',
        )
        self.assertEqual(self.path.read_bytes(), expected.encode("utf-8"))

    def test_dry_run_leaves_the_file_alone(self) -> None:
        rows = [{"status": "MISMATCH", "name": "func_00246940", "addr": "00246940"}]
        before = self.path.read_bytes()
        self.run_tool(rows, apply=False)
        self.assertEqual(self.path.read_bytes(), before)

    def test_compile_error_blocks_reverting(self) -> None:
        """One bad line usually gates a file of good matches; never mass-revert."""
        rows = [
            {"status": "COMPILE_ERROR", "name": "func_00246910", "addr": "00246910"},
            {"status": "MISMATCH", "name": "func_00246940", "addr": "00246940"},
        ]
        before = self.path.read_bytes()
        self.run_tool(rows)
        self.assertEqual(self.path.read_bytes(), before)

    def test_clean_file_is_untouched(self) -> None:
        rows = [{"status": "MATCH", "name": "func_00246910", "addr": "00246910"}]
        before = self.path.read_bytes()
        self.run_tool(rows)
        self.assertEqual(self.path.read_bytes(), before)



if __name__ == "__main__":
    unittest.main()
