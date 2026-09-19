from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_tail_classify",
                                              REPO / "tools" / "tail_classify.py")
assert SPEC is not None and SPEC.loader is not None
tail_classify = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(tail_classify)


class ClassifyTests(unittest.TestCase):
    """The tail is mostly allocator noise (handoff 7bf), so the only question
    worth asking of a near-MATCH floor is whether anything STRUCTURAL is left.
    Misclassifying a register rotation as structure sends a person to spend an
    afternoon on something no source change reaches."""

    def test_a_register_rotation_is_not_structure(self) -> None:
        """func_001b11c0's whole residual: same instruction, different register."""
        self.assertEqual(
            tail_classify.classify(["andi $t3, $a0, 0xffff"], ["andi $t1, $a0, 0xffff"]),
            "register")

    def test_a_reordering_of_the_same_instructions_is_schedule(self) -> None:
        """func_001130c0: b210 hoists two lbu above an andi; nothing else differs."""
        retail = ["andi $v1, $a1, 0xff", "lbu $s1, 0xde($sp)"]
        obj = ["lbu $s1, 0xde($sp)", "andi $v1, $a1, 0xff"]
        self.assertEqual(tail_classify.classify(retail, obj), "schedule")

    def test_a_different_mnemonic_is_structure(self) -> None:
        """func_00375f00: retail copies a live register, the object recomputes."""
        self.assertEqual(
            tail_classify.classify(["move $v1, $s2"], ["addu $v1, $s1, $s0"]),
            "structure")

    def test_an_instruction_on_one_side_only_is_structure(self) -> None:
        self.assertEqual(tail_classify.classify([], ["sd $zero, ($sp)"]), "structure")
        self.assertEqual(tail_classify.classify(["sd $zero, ($sp)"], []), "structure")

    def test_a_differing_immediate_is_not_hidden_by_register_masking(self) -> None:
        """Masking register names must not mask the operands that carry meaning."""
        self.assertEqual(
            tail_classify.classify(["addiu $a1, $zero, 0x45f"], ["addiu $a1, $zero, 0x460"]),
            "structure")

    def test_a_reordering_with_a_changed_instruction_is_not_schedule(self) -> None:
        """Same mnemonics in a different order, but one operand differs: the
        multiset test must not paper over the change."""
        retail = ["lwc1 $f1, 0x4c($sp)", "lwc1 $f2, 0x50($sp)"]
        obj = ["lwc1 $f2, 0x54($sp)", "lwc1 $f1, 0x4c($sp)"]
        self.assertNotEqual(tail_classify.classify(retail, obj), "schedule")


if __name__ == "__main__":
    unittest.main()
