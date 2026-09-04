import importlib.util
import os
import struct
import unittest

_SPEC = importlib.util.spec_from_file_location(
    'delayslot_census', os.path.join(os.path.dirname(__file__), '..', 'tools',
                                     'delayslot_census.py'))
ds = importlib.util.module_from_spec(_SPEC)
_SPEC.loader.exec_module(ds)


def pack(*words):
    return b''.join(struct.pack('<I', w) for w in words)


class WordsOf(unittest.TestCase):
    def test_drops_trailing_alignment_padding(self):
        self.assertEqual(ds.words_of(pack(0x12345678, 0, 0)), [0x12345678])

    def test_keeps_interior_nops(self):
        # A nop inside the body is real code, only the tail is padding.
        self.assertEqual(ds.words_of(pack(1, 0, 2)), [1, 0, 2])

    def test_ignores_a_trailing_partial_word(self):
        self.assertEqual(ds.words_of(pack(7) + b'\x01\x02'), [7])


class SlotAfterJr(unittest.TestCase):
    def test_reports_the_filled_slot(self):
        sw = 0xAC4600AC          # sw $a2, 0xac($v0) - func_0041f2b8's slot
        self.assertEqual(ds.slot_after_jr([0x8C820040, ds.JR_RA, sw]), sw)

    def test_empty_slot_is_none(self):
        self.assertIsNone(ds.slot_after_jr([0x8C820040, ds.JR_RA, 0]))

    def test_stack_teardown_is_not_scheduling_evidence(self):
        # b210 emits `addiu $sp,$sp,K` in the slot for every framed function,
        # so counting it would swamp the census with ordinary epilogues.
        self.assertIsNone(ds.slot_after_jr([ds.JR_RA, 0x27BD0020]))

    def test_a_different_addiu_still_counts(self):
        addiu_a0 = 0x248401FC     # addiu $a0, $a0, 508
        self.assertEqual(ds.slot_after_jr([ds.JR_RA, addiu_a0]), addiu_a0)

    def test_no_jr_at_all_is_none(self):
        self.assertIsNone(ds.slot_after_jr([0x8C820040, 0x03E00009]))

    def test_jr_as_the_last_word_has_no_slot(self):
        self.assertIsNone(ds.slot_after_jr([0x8C820040, ds.JR_RA]))

    def test_finds_the_first_jr_when_there_are_several(self):
        first, second = 0xAC4600AC, 0xAC4600B0
        self.assertEqual(
            ds.slot_after_jr([ds.JR_RA, first, ds.JR_RA, second]), first)


class StoreClassification(unittest.TestCase):
    def test_sw_sh_sd_sq_are_stores(self):
        for opcode, name in ((43, "sw"), (41, "sh"), (63, "sd"), (57, "sq")):
            with self.subTest(instruction=name):
                self.assertIn(opcode, ds.STORE_OPS)

    def test_lw_and_andi_are_not_stores(self):
        # These are the shapes with no precedent among matched functions; the
        # census must keep them separate so they are not mistaken for leads.
        for op in (35, 12, 11, 0):
            self.assertNotIn(op, ds.STORE_OPS)


if __name__ == '__main__':
    unittest.main()
