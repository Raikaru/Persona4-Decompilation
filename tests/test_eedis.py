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

    def test_lqc2_is_a_vu_load_not_an_octeon_branch(self) -> None:
        """Capstone reads major opcode 0x36 as Octeon `bbit0` and renders the
        displacement as a pc-relative BRANCH TARGET, so two byte-identical
        `lqc2` rows at different addresses disassembled differently and
        compared unequal.  Every VU load and store counted as an edit."""
        self.assertEqual(eedis.quadword_access(bytes.fromhex("40008ADA")),
                         "lqc2 $vf10, 0x40($s4)")

    def test_sqc2_is_a_vu_store(self) -> None:
        self.assertEqual(eedis.quadword_access(bytes.fromhex("0000AAF8")),
                         "sqc2 $vf10, 0x0($a1)")

    def test_the_vu_forms_name_a_vector_register_not_a_gpr(self) -> None:
        """`lqc2 $vf11` and `lq $s5` take their register number from the same
        field but from different files; printing `$s5` for a VU transfer would
        make two different instructions read alike."""
        self.assertIn("$vf11", eedis.quadword_access(bytes.fromhex("00008BDA")))
        self.assertIn("$s5", eedis.quadword_access(bytes.fromhex("6000B57F")))

    def test_the_same_vu_load_decodes_alike_at_any_address(self) -> None:
        """The defect in one line: the text must not depend on the pc."""
        disassemble = eedis.build(lambda word, pc: f"bbit032 $v0, 0xb, {pc:#x}")
        word = bytes.fromhex("00008BDA")
        self.assertEqual(disassemble(word, 0x004859B8), disassemble(word, 0x148))

    def test_an_ordinary_instruction_is_left_to_capstone(self) -> None:
        self.assertIsNone(eedis.quadword_access(bytes.fromhex("7000BFFF")))  # sd
        self.assertIsNone(eedis.quadword_access(bytes.fromhex("20FBBD27")))  # addiu

    def test_a_short_word_is_not_guessed_at(self) -> None:
        self.assertIsNone(eedis.quadword_access(b"\x7f\xb5"))


class AccumulateTests(unittest.TestCase):
    """The EE floating-point multiply-accumulate family, COP1 fmt=S with
    function 0x18-0x1F.  Capstone knows none of them and returned `"??"` for
    all six - and every `"??"` compared equal to every other, so `adda.s`,
    `madd.s`, `mula.s`, `msub.s` and `madda.s` were indistinguishable from
    each other AND from every undecoded VU op in the same function.  A whole
    session of accumulator work was measured through that hole, which is why
    two probes on `func_00471370` measured perfectly flat.

    Words below are taken from the tree's own listings."""

    def test_madd_s_has_three_operands(self) -> None:
        self.assertEqual(eedis.fpu_accumulate(bytes.fromhex("1C100346")),
                         "madd.s $f0, $f2, $f3")

    def test_adda_s_has_two(self) -> None:
        """`adda.s fs, ft` sets ACC = fs * ft.  It is a multiply, not an add,
        and reading it as add-to-accumulator sent an agent hunting for a
        zeroing of $f12 that does not exist."""
        self.assertEqual(eedis.fpu_accumulate(bytes.fromhex("18000146")),
                         "adda.s $f0, $f1")

    def test_mula_msub_madda_and_suba_are_distinguished(self) -> None:
        got = [eedis.fpu_accumulate(bytes.fromhex(h)) for h in
               ("1A080046", "1D080246", "1E600C46", "19580246")]
        self.assertEqual([t.split()[0] for t in got],
                         ["mula.s", "msub.s", "madda.s", "suba.s"])
        self.assertEqual(len(set(got)), 4)

    def test_a_plain_cop1_op_is_left_alone(self) -> None:
        self.assertIsNone(eedis.fpu_accumulate(bytes.fromhex("24000046")))  # cvt.w.s

    def test_a_non_cop1_word_is_left_alone(self) -> None:
        self.assertIsNone(eedis.fpu_accumulate(bytes.fromhex("20FBBD27")))  # addiu


class MultimediaTests(unittest.TestCase):
    """Opcode 0x1C, the EE's 128-bit MMI set.  Capstone knows none of it and
    mis-NAMED three forms outright - `psraw` as `sdbbp`, `mthi1` as `v3mulu`,
    `mfhi1` as `vmm0`.  Words below come from the tree's own listings."""

    def test_the_mmi0_and_mmi2_subtables_are_selected_by_the_shift_field(self) -> None:
        self.assertEqual(eedis.multimedia(bytes.fromhex("891BA370")),
                         "pcpyld $v1, $a1, $v1")
        self.assertEqual(eedis.multimedia(bytes.fromhex("88150270")),
                         "pextlh $v0, $zero, $v0")
        self.assertEqual(eedis.multimedia(bytes.fromhex("88160270")),
                         "pextlb $v0, $zero, $v0")

    def test_function_0x28_is_mmi1_not_mmi0(self) -> None:
        """Getting this wrong named 18 `pextub` as `pextlb`.  The two differ
        only in which half is extended, so nothing but the listing would have
        caught it - which is the argument for auditing rather than eyeballing."""
        self.assertEqual(
            eedis.multimedia(bytes.fromhex("A84E0A70")).split()[0], "pextub")

    def test_pmfhl_carries_its_half_selector_in_the_shift_field(self) -> None:
        self.assertEqual(
            eedis.multimedia(bytes.fromhex("30080070")).split()[0], "pmfhl.lw")

    def test_the_three_previously_misnamed_forms_are_right_now(self) -> None:
        for word, want in (("3F530A70", "psraw"), ("11000070", "mthi1"),
                           ("10100070", "mfhi1")):
            self.assertEqual(eedis.multimedia(bytes.fromhex(word)).split()[0], want)

    def test_the_pipeline_one_multiply_unit_is_distinguished(self) -> None:
        """`mult1` and `multu1` target the second multiplier; confusing them
        with `mult`/`multu` would make two different instructions match."""
        self.assertEqual(eedis.multimedia(bytes.fromhex("18207270")).split()[0], "mult1")
        self.assertEqual(eedis.multimedia(bytes.fromhex("19000272")).split()[0], "multu1")

    def test_a_non_mmi_word_is_left_alone(self) -> None:
        self.assertIsNone(eedis.multimedia(bytes.fromhex("20FBBD27")))


class UndecodedTests(unittest.TestCase):
    """118 forms - the MMI integer ops, VU macro-mode, the EE three-operand
    `mult` - remain unknown to capstone.  Naming them is a refinement; not
    collapsing them onto one token is a correctness requirement."""

    def test_two_different_unknown_words_do_not_compare_equal(self) -> None:
        disassemble = eedis.build(lambda word, pc: "??")
        vmulx = disassemble(bytes.fromhex("D85AE24B"), 0)
        vadd = disassemble(bytes.fromhex("A852EB4B"), 0)
        self.assertNotEqual(vmulx, vadd)

    def test_the_same_unknown_word_compares_equal_at_any_address(self) -> None:
        disassemble = eedis.build(lambda word, pc: "??")
        word = bytes.fromhex("D85AE24B")
        self.assertEqual(disassemble(word, 0x1852f0), disassemble(word, 0x400))

    def test_an_unknown_word_is_rendered_as_its_own_raw_word(self) -> None:
        disassemble = eedis.build(lambda word, pc: "??")
        self.assertEqual(disassemble(bytes.fromhex("D85AE24B"), 0), ".word 0x4be25ad8")


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
