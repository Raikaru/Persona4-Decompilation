import importlib.util
import os
import struct
import unittest

_SPEC = importlib.util.spec_from_file_location(
    'regsave_scan', os.path.join(os.path.dirname(__file__), '..', 'tools',
                                 'regsave_scan.py'))
rs = importlib.util.module_from_spec(_SPEC)
_SPEC.loader.exec_module(rs)


def pack(*words):
    return list(words)


# func_001400f0's real prologue, the case that motivated the tool: retail keeps
# three more callee-saved GPRs than the body and the frame is 0x30 larger.
ADDIU_SP_230 = 0x27BDFDD0       # addiu $sp, $sp, -0x230
SD_RA_C0 = 0xFFBF00C0           # sd    $ra, 0xc0($sp)
SQ_FP_B0 = 0x7FBE00B0           # sq    $fp, 0xb0($sp)
SQ_S7_A0 = 0x7FB700A0           # sq    $s7, 0xa0($sp)
SQ_S0_30 = 0x7FB00030           # sq    $s0, 0x30($sp)
SWC1_F20_10 = 0xE7B40010        # swc1  $f20, 0x10($sp)
SW_A0_40 = 0xAFA40040           # sw    $a0, 0x40($sp) - an argument spill
SQ_S0_OF_A1 = 0x7CB00030        # sq    $s0, 0x30($a1) - not a frame save


class Prologue(unittest.TestCase):
    def test_reads_frame_saves_and_ra_offset(self):
        frame, gpr, fpr, ra = rs._prologue(
            pack(ADDIU_SP_230, SD_RA_C0, SQ_FP_B0, SQ_S7_A0, SQ_S0_30,
                 SWC1_F20_10))
        self.assertEqual(frame, 0x230)
        self.assertEqual(gpr, {30, 23, 16})
        self.assertEqual(fpr, {20})
        self.assertEqual(ra, 0xC0)

    def test_ignores_stores_through_other_registers(self):
        # A store through $a1 is data, not a callee save; counting it would
        # invent a saved register and send an agent after a value retail never
        # keeps.
        _, gpr, _, _ = rs._prologue(pack(ADDIU_SP_230, SQ_S0_OF_A1))
        self.assertEqual(gpr, set())

    def test_word_stores_are_not_callee_saves(self):
        # Only `sq` saves a GPR on this ABI.  An argument spilled with `sw`
        # does not consume a 16-byte slot and must not widen the frame math.
        _, gpr, _, _ = rs._prologue(pack(ADDIU_SP_230, SW_A0_40))
        self.assertEqual(gpr, set())

    def test_positive_stack_adjustment_is_the_epilogue(self):
        # `addiu $sp, $sp, 0x230` at the end must not be read as a frame of
        # 0xFDD0; only the negative adjustment opens the frame.
        frame, _, _, _ = rs._prologue(pack(0x27BD0230))
        self.assertIsNone(frame)


class NopDensity(unittest.TestCase):
    def test_reports_the_share_of_nops(self):
        density, count = rs._nop_density(pack(ADDIU_SP_230, 0, SD_RA_C0, 0))
        self.assertEqual(count, 2)
        self.assertAlmostEqual(density, 0.5)

    def test_empty_window_is_not_a_division_error(self):
        self.assertEqual(rs._nop_density([]), (0.0, 0))


if __name__ == '__main__':
    unittest.main()
