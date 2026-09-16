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


class NormaliseTests(unittest.TestCase):
    def test_branch_target_becomes_relative(self) -> None:
        """The same loop compiled at two addresses has to read the same, or every
        branch in an object linked at 0 would differ from retail."""
        self.assertEqual(fnalign.normalise("bnez $v0, 0x1dd624", 0x1dd7f8),
                         fnalign.normalise("bnez $v0, 0x2b4", 0x488))

    def test_a_branch_somewhere_else_still_differs(self) -> None:
        near = fnalign.normalise("beqz $v0, 0x1dd8d4", 0x1dd848)
        far = fnalign.normalise("beqz $v0, 0x1dd8e0", 0x1dd848)
        self.assertNotEqual(near, far)

    def test_jump_targets_are_dropped(self) -> None:
        """`jal` is relocated in the object and absolute in retail."""
        self.assertEqual(fnalign.normalise("jal 0x1dd1c0", 0x1dd840),
                         fnalign.normalise("jal 0", 0x38))


class AlignTests(unittest.TestCase):
    def test_one_missing_instruction_is_one_delete(self) -> None:
        """The reason this tool exists: positional diffing reports every later
        word as different, which hides the single missing instruction."""
        retail = ["addiu $v0, $s2, 1", "andi $s2, $v0, 0xffff", "lw $a0, 0xa64($s0)",
                  "jal", "sll $zero, $zero, 0"]
        candidate = ["daddiu $s2, $zero, 1", "lw $a0, 0xa64($s0)", "jal",
                     "sll $zero, $zero, 0"]
        script, edits, reloc_only = fnalign.align(retail, candidate, set())
        self.assertEqual([op[0] for op in script], ["replace"])
        self.assertEqual((edits, reloc_only), (2, 0))

    def test_an_extra_instruction_is_reported_as_an_insert(self) -> None:
        retail = ["lw $a0, 0($s0)", "jal", "nop"]
        candidate = ["lw $a0, 0($s0)", "jal", "nop", "addiu $v0, $zero, 1"]
        script, edits, _ = fnalign.align(retail, candidate, set())
        self.assertEqual([op[0] for op in script], ["insert"])
        self.assertEqual(edits, 1)

    def test_relocated_immediates_are_not_edits(self) -> None:
        """The linker owns those fields; counting them would report a match as a
        near miss."""
        retail = ["lui $a0, 0x61", "addiu $a0, $a0, -0x6a20"]
        candidate = ["lui $a0, 0", "addiu $a0, $a0, 0"]
        script, edits, reloc_only = fnalign.align(retail, candidate, {0, 1})
        self.assertEqual([op[0] for op in script], ["reloc"])
        self.assertEqual((edits, reloc_only), (0, 2))

    def test_an_unrelocated_immediate_difference_is_an_edit(self) -> None:
        retail = ["addiu $a1, $zero, 0x45f"]
        candidate = ["addiu $a1, $zero, 0x460"]
        _, edits, reloc_only = fnalign.align(retail, candidate, set())
        self.assertEqual((edits, reloc_only), (1, 0))

    def test_a_register_difference_at_a_relocated_word_is_an_edit(self) -> None:
        """Only the immediate is linker-owned; a different register there is real."""
        retail = ["lui $a0, 0x61"]
        candidate = ["lui $a1, 0"]
        _, edits, reloc_only = fnalign.align(retail, candidate, {0})
        self.assertEqual((edits, reloc_only), (1, 0))


if __name__ == "__main__":
    unittest.main()
