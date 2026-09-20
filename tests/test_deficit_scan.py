from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_deficit_scan",
                                              REPO / "tools" / "deficit_scan.py")
assert SPEC is not None and SPEC.loader is not None
deficit_scan = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(deficit_scan)


class MnemonicTests(unittest.TestCase):
    def test_the_opcode_is_taken_without_its_operands(self) -> None:
        self.assertEqual(deficit_scan.mnemonic("   andi $v0, $v0, 0x20"), "andi")

    def test_a_blank_line_has_no_mnemonic(self) -> None:
        self.assertEqual(deficit_scan.mnemonic("   "), "")


class VerdictArithmeticTests(unittest.TestCase):
    """A long retail-only run is not automatically missing code.  The
    discriminator is arithmetic: you cannot be missing more instructions than
    you are short.  func_001b2380 is 24 instructions short and carries a
    591-instruction retail-only run, so that run is code the object HAS and
    the aligner could not pair - sending someone to 'write' it wastes a
    session, which is what happened before the tool said so."""

    @staticmethod
    def verdict(length: int, deficit: int) -> str:
        return "CROSS" if length > max(deficit, 0) else "ABSENT"

    def test_a_run_longer_than_the_deficit_is_a_cross(self) -> None:
        self.assertEqual(self.verdict(591, 24), "CROSS")

    def test_a_run_inside_the_deficit_can_be_absent(self) -> None:
        self.assertEqual(self.verdict(44, 168), "ABSENT")

    def test_a_run_on_an_over_long_object_is_always_a_cross(self) -> None:
        """A negative deficit means the object is LONGER than retail, so
        nothing can be missing however long the unpaired run is."""
        self.assertEqual(self.verdict(164, -113), "CROSS")

    def test_the_boundary_belongs_to_absent(self) -> None:
        self.assertEqual(self.verdict(168, 168), "ABSENT")
        self.assertEqual(self.verdict(169, 168), "CROSS")


if __name__ == "__main__":
    unittest.main()
