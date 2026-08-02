from __future__ import annotations

import importlib.util
import unittest
from collections import Counter
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "recover_symbols.py"
SPEC = importlib.util.spec_from_file_location("p4_recover_symbols", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
rs = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(rs)

GP = 0x007690F0
# (name, kind, start, end) mirroring build.TARGET_SEGMENTS kinds.
SEGMENTS = [
    ("code1", "code", 0x00100000, 0x0052DA00),
    ("data1", "data", 0x0052DA00, 0x0070C850),
    ("code2", "code", 0x0070C850, 0x0070E140),
    ("data2", "data", 0x0070E140, 0x00764280),
    ("zero_fill", "data", 0x00764280, 0x00938A00),
]
WINDOWS = {0x00400000, 0x00454BD0}


def select(recovered, kinds=None):
    return rs.select_symbols(recovered, kinds or {name: {"gp"} for name in recovered},
                             GP, WINDOWS, SEGMENTS, set())


class AbsPairDecodeTests(unittest.TestCase):
    def test_positive_low_half(self):
        # 0x008873EC: %hi = 0x0088, %lo = 0x73EC (positive, no carry).
        self.assertEqual(rs.decode_abs_pair(0, 0x0088, 0, 0x73EC), 0x008873EC)

    def test_negative_low_half(self):
        # 0x0088F3EC: %hi = 0x0089, %lo = 0xF3EC which sign-extends negative.
        # The HI16 half must be adjusted for the negative low half: a naive
        # (hi << 16) | lo would produce 0x0089F3EC, not the retail address.
        self.assertEqual(rs.decode_abs_pair(0, 0x0089, 0, 0xF3EC), 0x0088F3EC)

    def test_compiled_addend_is_backed_out(self):
        # sym + 4 with a negative low half: the linked pair encodes the
        # symbol address plus the addend, which must be subtracted.
        self.assertEqual(rs.decode_abs_pair(0, 0x0089, 4, 0xF3F0), 0x0088F3EC)


class GprelDecodeTests(unittest.TestCase):
    def test_positive_offset(self):
        # sw $zero, 0xb1c0($gp) -> 0x007690f0 + 0xb1c0.
        self.assertEqual(rs.decode_gprel(GP, 0, 0xB1C0), 0x007642B0)

    def test_negative_offset_is_sign_extended(self):
        # lw $t0, 0x81f4($gp): the 16-bit field is negative.
        self.assertEqual(rs.decode_gprel(GP, 0, 0x81F4), GP - 0x7E0C)

    def test_compiled_addend_is_backed_out(self):
        self.assertEqual(rs.decode_gprel(GP, 0x0004, 0xB1C4), 0x007642B0)


class Jump26DecodeTests(unittest.TestCase):
    def test_jal_target_reconstruction(self):
        # jal at 0x00202be0 (pc+4 = 0x00202be4) with field 0x1152f4.
        self.assertEqual(rs.decode_jump26(0, 0x1152F4, 0x00202BE4), 0x00454BD0)

    def test_compiled_addend_is_backed_out(self):
        # jal sym+4: the compiled field holds the addend in 4-byte units, the
        # linked field encodes (S + A) >> 2.
        self.assertEqual(rs.decode_jump26(1, 0x1152F5, 0x00202BE4), 0x00454BD0)


class NameEncodingTests(unittest.TestCase):
    def test_gp_relative_names_decode_against_gp(self):
        self.assertEqual(rs.name_encoded_address("iGpfffb3ac", GP), (0x0076449C, "gp"))
        self.assertEqual(rs.name_encoded_address("gp0xffff9df8", GP), (GP - 0x6208, "gp"))
        self.assertEqual(rs.name_encoded_address("fGpffff81f4", GP), (GP - 0x7E0C, "gp"))

    def test_absolute_names_encode_their_address(self):
        self.assertEqual(rs.name_encoded_address("D_008873ec", GP), (0x008873EC, "abs"))
        self.assertEqual(rs.name_encoded_address("DAT_008873ec_abs", GP), (0x008873EC, "abs"))
        self.assertEqual(rs.name_encoded_address("PTR_DAT_00762ea0", GP), (0x00762EA0, "abs"))

    def test_function_and_label_names(self):
        self.assertEqual(rs.name_encoded_address("func_00276e70_typed", GP), (0x00276E70, "func"))
        self.assertEqual(rs.name_encoded_address("FUN_003b3e00_raw", GP), (0x003B3E00, "func"))
        self.assertEqual(rs.name_encoded_address("LAB_00474a50_abs", GP), (0x00474A50, "label"))

    def test_plain_names_do_not_encode(self):
        self.assertEqual(rs.name_encoded_address("rwGlobals", GP), (None, None))


class ConsistencyGateTests(unittest.TestCase):
    def test_conflicting_addresses_are_rejected(self):
        """A symbol whose references disagree on the address must never be
        emitted: emitting one of the candidates would point half the
        references at the wrong bytes."""
        recovered = {"rwGlobals": Counter({0x00600000: 3, 0x00601000: 1})}
        emitted, conflicts, _agree, _disagree, _failures = select(recovered)
        self.assertNotIn("rwGlobals", emitted)
        self.assertIn("rwGlobals", conflicts)

    def test_consistent_symbol_is_emitted(self):
        recovered = {"rwGlobals": Counter({0x00600000: 3})}
        emitted, conflicts, _agree, _disagree, _failures = select(recovered)
        self.assertEqual(emitted, {"rwGlobals": 0x00600000})
        self.assertEqual(conflicts, {})


class SelectionPolicyTests(unittest.TestCase):
    def test_name_encoded_address_agreement_is_recorded(self):
        recovered = {"D_00600000": Counter({0x00600000: 1})}
        emitted, _conflicts, agree, disagree, _failures = select(recovered)
        self.assertEqual(emitted, {"D_00600000": 0x00600000})
        self.assertEqual(agree, ["D_00600000"])
        self.assertEqual(disagree, [])

    def test_name_encoded_disagreement_emits_recovered_address_and_reports(self):
        """The retail instructions are ground truth; a name that encodes a
        different address is a source mislabel (e.g. ported names), so the
        recovered address is emitted and the disagreement reported."""
        recovered = {"D_00600000": Counter({0x00600010: 1})}
        emitted, _conflicts, agree, disagree, _failures = select(recovered)
        self.assertEqual(emitted, {"D_00600000": 0x00600010})
        self.assertEqual(agree, [])
        self.assertEqual(len(disagree), 1)
        self.assertEqual(disagree[0][:2], ("D_00600000", 0x00600010))

    def test_data_kind_address_inside_function_window_is_rejected(self):
        recovered = {"D_00400004": Counter({0x00400004: 1})}
        emitted, _conflicts, _agree, _disagree, failures = select(recovered)
        self.assertNotIn("D_00400004", emitted)
        self.assertEqual(len(failures), 1)

    def test_function_kind_address_must_be_a_window_start(self):
        recovered = {"func_00400004": Counter({0x00400004: 1})}
        emitted, _conflicts, _agree, _disagree, failures = select(recovered)
        self.assertNotIn("func_00400004", emitted)
        self.assertTrue(any("window start" in f for f in failures))

    def test_function_pointer_to_window_start_is_allowed(self):
        # %hi/%lo of a function address (function pointer argument) carries no
        # "func" evidence, but landing exactly on a window start is the
        # signature of a function reference and must be accepted.
        recovered = {"btlCond_MYBAD": Counter({0x00454BD0: 2})}
        emitted, _conflicts, _agree, _disagree, failures = select(recovered)
        self.assertEqual(emitted, {"btlCond_MYBAD": 0x00454BD0})
        self.assertEqual(failures, [])

    def test_label_name_may_sit_mid_window(self):
        recovered = {"LAB_00474a50_abs": Counter({0x00474A50: 1})}
        emitted, _conflicts, _agree, _disagree, failures = select(recovered)
        self.assertEqual(emitted, {"LAB_00474a50_abs": 0x00474A50})
        self.assertEqual(failures, [])

    def test_zero_address_is_not_linkable(self):
        recovered = {"junk": Counter({0: 1})}
        emitted, _conflicts, _agree, _disagree, failures = select(recovered)
        self.assertNotIn("junk", emitted)
        self.assertTrue(failures)


if __name__ == "__main__":
    unittest.main()
