from __future__ import annotations

import importlib.util
import struct
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_twin_find", REPO / "tools" / "twin_find.py")
assert SPEC is not None and SPEC.loader is not None
twin = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(twin)


def lw(rt, rs, imm):
    return (0x23 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def addiu(rt, rs, imm):
    return (0x09 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def jal(target):
    return (0x03 << 26) | ((target >> 2) & 0x03FFFFFF)


def addu(rd, rs, rt):
    return (rs << 21) | (rt << 16) | (rd << 11) | 0x21


class MaskTests(unittest.TestCase):
    """Two functions are twins when only their CONSTANTS differ."""

    def test_load_offset_is_masked_out(self) -> None:
        self.assertEqual(twin.mask(lw(2, 4, 0x14)), twin.mask(lw(2, 4, 0x110)))

    def test_registers_are_kept(self) -> None:
        self.assertNotEqual(twin.mask(lw(2, 4, 0x14)), twin.mask(lw(3, 4, 0x14)))

    def test_jal_target_is_masked_but_the_opcode_is_kept(self) -> None:
        """Masking call targets is what makes the search useful, and is also why a
        hit must be checked with twin_diff: two functions can share a shape and
        still call different things."""
        self.assertEqual(twin.mask(jal(0x0046B0D0)), twin.mask(jal(0x003EF3A0)))
        self.assertNotEqual(twin.mask(jal(0x0046B0D0)), twin.mask(addiu(2, 0, 1)))

    def test_register_only_instructions_keep_every_field(self) -> None:
        self.assertNotEqual(twin.mask(addu(2, 4, 5)), twin.mask(addu(3, 4, 5)))
        self.assertEqual(twin.mask(addu(2, 4, 5)), twin.mask(addu(2, 4, 5)))

    def test_immediate_value_is_masked(self) -> None:
        self.assertEqual(twin.mask(addiu(4, 0, 1284)), twin.mask(addiu(4, 0, 1285)))


class SignatureTests(unittest.TestCase):
    def test_trailing_padding_is_ignored(self) -> None:
        body = [lw(2, 4, 8), 0x03E00008, 0]
        a = struct.pack("<3I", *body)
        b = struct.pack("<5I", *(body + [0, 0]))
        self.assertEqual(twin.signature(a), twin.signature(b))

    def test_two_functions_differing_only_in_constants_are_twins(self) -> None:
        one = struct.pack("<4I", addiu(4, 0, 1284), lw(2, 4, 0x14),
                          jal(0x0046B0D0), 0x03E00008)
        two = struct.pack("<4I", addiu(4, 0, 1285), lw(2, 4, 0x110),
                          jal(0x003EF3A0), 0x03E00008)
        self.assertEqual(twin.signature(one)[0], twin.signature(two)[0])

    def test_a_different_register_breaks_the_twin(self) -> None:
        one = struct.pack("<2I", lw(2, 4, 0x14), 0x03E00008)
        two = struct.pack("<2I", lw(3, 4, 0x14), 0x03E00008)
        self.assertNotEqual(twin.signature(one)[0], twin.signature(two)[0])

    def test_word_count_is_reported_after_padding_removal(self) -> None:
        _, n = twin.signature(struct.pack("<4I", lw(2, 4, 8), 0x03E00008, 0, 0))
        self.assertEqual(n, 2)


if __name__ == "__main__":
    unittest.main()
