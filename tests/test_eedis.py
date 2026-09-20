from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_eedis", REPO / "tools" / "eedis.py")
assert SPEC is not None and SPEC.loader is not None
eedis = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(eedis)


class QuadwordDecodeTests(unittest.TestCase):
    """The bytes below are lifted straight out of retail's `func_001ee610`
    prologue, which is where this defect surfaced."""

    def test_sq_of_a_saved_register(self) -> None:
        self.assertEqual(eedis.quadword_access(bytes.fromhex("6000B57F")),
                         "sq $s5, 0x60($sp)")

    def test_a_second_sq_decodes_its_own_register_and_offset(self) -> None:
        self.assertEqual(eedis.quadword_access(bytes.fromhex("5000B47F")),
                         "sq $s4, 0x50($sp)")

    def test_lq_uses_the_other_major_opcode(self) -> None:
        word = (0x1E << 26) | (29 << 21) | (20 << 16) | 0x50
        self.assertEqual(eedis.quadword_access(word.to_bytes(4, "little")),
                         "lq $s4, 0x50($sp)")

    def test_a_negative_displacement_keeps_its_sign(self) -> None:
        word = (0x1F << 26) | (29 << 21) | (16 << 16) | 0xFFF0
        self.assertEqual(eedis.quadword_access(word.to_bytes(4, "little")),
                         "sq $s0, -0x10($sp)")

    def test_an_ordinary_instruction_is_left_to_capstone(self) -> None:
        self.assertIsNone(eedis.quadword_access(bytes.fromhex("7000BFFF")))  # sd
        self.assertIsNone(eedis.quadword_access(bytes.fromhex("20FBBD27")))  # addiu

    def test_a_short_word_is_not_guessed_at(self) -> None:
        self.assertIsNone(eedis.quadword_access(b"\x7f\xb5"))


class WrapperTests(unittest.TestCase):
    def test_the_wrapper_prefers_the_quadword_decode(self) -> None:
        disassemble = eedis.build(lambda word, pc: "subu.qb $zero, $sp, $s4")
        self.assertEqual(disassemble(bytes.fromhex("6000B57F"), 0),
                         "sq $s5, 0x60($sp)")

    def test_the_wrapper_defers_for_everything_else(self) -> None:
        disassemble = eedis.build(lambda word, pc: "sd $ra, 0x70($sp)")
        self.assertEqual(disassemble(bytes.fromhex("7000BFFF"), 0),
                         "sd $ra, 0x70($sp)")


class AlignerIntegrationTests(unittest.TestCase):
    """Two different `sq` rows used to decode to `"??"` each, and `"??"`
    compares equal to `"??"` - so a body that saved the WRONG registers, or a
    different number of them, cost nothing in the edit count.  That is the
    regression worth pinning: not that the text is prettier, but that the
    aligner can now see a difference at all."""

    def _fnalign(self):
        spec = importlib.util.spec_from_file_location("p4_fnalign",
                                                      REPO / "tools" / "fnalign.py")
        assert spec is not None and spec.loader is not None
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        return module

    def test_two_different_register_saves_no_longer_compare_equal(self) -> None:
        fnalign = self._fnalign()
        saves_s5 = fnalign.decode(bytes.fromhex("6000B57F"), 0)
        saves_s4 = fnalign.decode(bytes.fromhex("5000B47F"), 0)
        self.assertNotEqual(saves_s5, saves_s4)
        self.assertNotIn("??", saves_s5 + saves_s4)

    def test_a_missing_save_now_costs_an_edit(self) -> None:
        fnalign = self._fnalign()
        retail = fnalign.decode(bytes.fromhex("7000BFFF6000B57F5000B47F"), 0)
        shorter = fnalign.decode(bytes.fromhex("7000BFFF"), 0)
        _script, edits, _reloc = fnalign.align(retail, shorter, set())
        self.assertEqual(edits, 2)


if __name__ == "__main__":
    unittest.main()
