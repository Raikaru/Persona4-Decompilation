from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_knob_sweep",
                                              REPO / "tools" / "knob_sweep.py")
assert SPEC is not None and SPEC.loader is not None
knob = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(knob)

LINES = [
    '#include "include_asm.h"',
    "",
    "// FUN_00123456 NONMATCHING",
    "/* measured: note text */",
    "#pragma schedule on",
    "#ifdef NON_MATCHING",
    "void func_00123456(void)",
    "{",
    "}",
    "#else",
    'INCLUDE_ASM("asm/nonmatchings/thing", func_00123456);',
    "#endif",
    "",
    "// FUN_00123500",
    "void func_00123500(void) {}",
]


def mwcc_path() -> str | None:
    """Must never raise: evaluated at import time by @skipUnless.

    load_config calls sys.exit when the toolchain is absent, and that is a
    BaseException.
    """
    try:
        from verify import load_config
        p = load_config().get("mwcc")
        return p if p and Path(p).is_file() else None
    except BaseException:
        return None


MWCC = mwcc_path()


class LocateTests(unittest.TestCase):
    def test_finds_the_marker_ifdef_else_endif_span(self) -> None:
        mi, j, e, z = knob.locate(LINES, "00123456")
        self.assertEqual(LINES[mi], "// FUN_00123456 NONMATCHING")
        self.assertEqual(LINES[j], "#ifdef NON_MATCHING")
        self.assertEqual(LINES[e], "#else")
        self.assertEqual(LINES[z], "#endif")

    def test_the_region_between_marker_and_ifdef_is_not_the_body(self) -> None:
        """That region holds `#pragma schedule on` and floor notes.

        Treating it as part of the body and replacing it drops the pragma, which
        leaves an unfilled jr delay slot and makes the function look several
        instructions worse than it is. That bug poisoned a whole census.
        """
        mi, j, e, z = knob.locate(LINES, "00123456")
        keep = LINES[mi + 1:j]
        self.assertIn("#pragma schedule on", keep)
        self.assertIn("/* measured: note text */", keep)
        body = LINES[j + 1:e]
        self.assertNotIn("#pragma schedule on", body)

    def test_unknown_address_raises_stopiteration(self) -> None:
        with self.assertRaises(StopIteration):
            knob.locate(LINES, "00999999")

    def test_case_insensitive_on_the_marker_hex(self) -> None:
        mi, _, _, _ = knob.locate(LINES, "00123456")
        self.assertEqual(mi, 2)


class KnobListTests(unittest.TestCase):
    def test_default_knobs_are_well_formed(self) -> None:
        """Every entry must split into a name and a value for the wrap builder."""
        for k in knob.DEFAULT_KNOBS:
            parts = k.split(None, 1)
            self.assertEqual(len(parts), 2, k)
            self.assertNotIn("#", k)

    def test_the_branch_likely_knob_is_present(self) -> None:
        """It is the one that produced four matches; keep it in the default set."""
        self.assertIn("no_branch_likely on", knob.DEFAULT_KNOBS)


@unittest.skipUnless(MWCC, "MWCCPS2 not available")
class CompilerTests(unittest.TestCase):
    def test_every_default_knob_is_a_real_pragma(self) -> None:
        """A misspelled knob is silently ignored by b210, so it would look like a
        clean negative result forever."""
        import importlib.util as iu
        spec = iu.spec_from_file_location("pa", REPO / "tools" / "pragma_audit.py")
        pa = iu.module_from_spec(spec)
        spec.loader.exec_module(pa)
        self.assertEqual(pa.illegal({k: 1 for k in knob.DEFAULT_KNOBS}, MWCC), [])

    def test_discovery_finds_more_than_the_defaults(self) -> None:
        found = knob.discover_knobs(MWCC)
        self.assertGreater(len(found), 100)
        self.assertIn("no_branch_likely", found)
        self.assertIn("schedule", found)
        self.assertNotIn("alias", found)


if __name__ == "__main__":
    unittest.main()
