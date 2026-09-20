from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_fnalign", REPO / "tools" / "fnalign.py")
assert SPEC is not None and SPEC.loader is not None
fnalign = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(fnalign)


def totals(retail: list[str], object_side: list[str]) -> tuple[int, int]:
    """Pure-delete and pure-insert instruction totals, as gate_audit counts them."""
    script, _edits, _reloc = fnalign.align(retail, object_side, set())
    missing = sum(i2 - i1 for t, i1, i2, _j1, _j2 in script if t == "delete")
    extra = sum(j2 - j1 for t, _i1, _i2, j1, j2 in script if t == "insert")
    return missing, extra


class CancellationTests(unittest.TestCase):
    """An EXACT instruction count is the best hiding place in the tree, because
    it reads as finished.  `func_001265a0` sat at 4404 against retail's 4404
    while calling `__fixsfdi` at a site where retail has
    `cvt.w.s`/`mfc1`/`nop`/`dsll32`/`dsra32` - one instruction short there and
    one instruction long somewhere else.  The run-length check that catches
    big splits needs a hole and a lump of 25 each; this was 1 against 1."""

    def test_equal_length_streams_can_still_be_missing_and_extra(self) -> None:
        retail = ["cvt.w.s $f0,$f2", "mfc1 $v0,$f0", "nop",
                  "dsll32 $t2,$v0,0x10", "dsra32 $t2,$t2,0x10", "sw $t2,($s0)"]
        # One instruction short at the conversion, one long at the store.
        object_side = ["cvt.w.s $f0,$f2", "mfc1 $v0,$f0",
                       "dsll32 $t2,$v0,0x10", "dsra32 $t2,$t2,0x10",
                       "addiu $s0,$s0,0", "sw $t2,($s0)"]
        self.assertEqual(len(retail), len(object_side))
        missing, extra = totals(retail, object_side)
        self.assertGreater(missing, 0)
        self.assertGreater(extra, 0)

    def test_an_identical_body_reports_neither(self) -> None:
        stream = ["addiu $sp,$sp,-0x20", "sd $ra,0x10($sp)", "jr $ra", "nop"]
        self.assertEqual(totals(stream, list(stream)), (0, 0))

    def test_a_pure_substitution_is_not_reported_as_cancellation(self) -> None:
        """A `replace` is a diverged region, not missing code plus surplus
        code, and flagging it would bury the real signal in noise."""
        retail = ["addiu $v0,$v0,1", "sw $v0,($s0)"]
        object_side = ["addiu $v0,$v0,2", "sw $v0,($s0)"]
        self.assertEqual(totals(retail, object_side), (0, 0))

    def test_a_body_that_is_only_short_reports_no_surplus(self) -> None:
        retail = ["lui $v0,0x10", "ori $v0,$v0,0x20", "jr $ra", "nop"]
        object_side = ["lui $v0,0x10", "jr $ra", "nop"]
        missing, extra = totals(retail, object_side)
        self.assertEqual((missing, extra), (1, 0))

    def test_a_body_that_is_only_long_reports_no_shortfall(self) -> None:
        retail = ["lui $v0,0x10", "jr $ra", "nop"]
        object_side = ["lui $v0,0x10", "ori $v0,$v0,0x20", "jr $ra", "nop"]
        missing, extra = totals(retail, object_side)
        self.assertEqual((missing, extra), (0, 1))


class WiringTests(unittest.TestCase):
    def test_gate_audit_reports_exact_count_cancellation(self) -> None:
        source = (REPO / "tools" / "gate_audit.py").read_text()
        self.assertIn("CANCELLED", source)
        self.assertIn("got == want and missing and extra", source)

    def test_an_in_band_floor_still_missing_code_is_reported_too(self) -> None:
        """An exact count is the clearest case but not the only one:
        func_0048c4e0 sits at +2.2% with a pure hole of 24 against a lump of
        1, so it is comfortably in band and still missing a block of retail
        code.  Requiring got == want would let every such floor through."""
        source = (REPO / "tools" / "gate_audit.py").read_text()
        self.assertIn("missing >= 10 and extra >= 1", source)

    def test_the_advice_names_the_floor_that_exposed_it(self) -> None:
        source = (REPO / "tools" / "gate_audit.py").read_text()
        self.assertIn("func_001265a0", source)


if __name__ == "__main__":
    unittest.main()
