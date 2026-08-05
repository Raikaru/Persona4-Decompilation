from __future__ import annotations

import importlib.util
import struct
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_file_evidence",
                                              REPO / "tools" / "file_evidence.py")
assert SPEC is not None and SPEC.loader is not None
fe = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(fe)


def w(*words):
    return list(words)


def lui(rt, imm):
    return (0x0F << 26) | (rt << 16) | (imm & 0xFFFF)


def addiu(rt, rs, imm):
    return (0x09 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def lw(rt, rs, imm):
    return (0x23 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


class MaterialisedAddressTests(unittest.TestCase):
    """A __FILE__ string reference is a lui/%lo pair, and the %lo half may live in
    an addiu, an ori, or the displacement of any load or store."""

    def test_lui_plus_addiu(self) -> None:
        self.assertIn(0x00714C3C,
                      fe.materialised_addresses(w(lui(4, 0x71), addiu(4, 4, 0x4C3C))))

    def test_lui_plus_load_displacement(self) -> None:
        self.assertIn(0x00714C3C,
                      fe.materialised_addresses(w(lui(3, 0x71), lw(2, 3, 0x4C3C))))

    def test_negative_lo_half_is_sign_extended(self) -> None:
        """0xE3D0 as a displacement is -0x1C30, so %hi is one higher."""
        got = fe.materialised_addresses(w(lui(4, 0x64), addiu(4, 4, 0xE3D0)))
        self.assertIn(0x0063E3D0, got)

    def test_an_unrelated_base_register_is_not_combined(self) -> None:
        """lui into $a0 must not pair with a displacement off $s0."""
        got = fe.materialised_addresses(w(lui(4, 0x71), lw(2, 16, 0x4C3C)))
        self.assertNotIn(0x00714C3C, got)

    def test_a_lone_lui_yields_nothing(self) -> None:
        self.assertEqual(fe.materialised_addresses(w(lui(4, 0x71))), set())

    def test_a_later_lui_replaces_the_high_half(self) -> None:
        got = fe.materialised_addresses(w(lui(4, 0x71), lui(4, 0x64), addiu(4, 4, 0x10)))
        self.assertIn(0x00640010, got)
        self.assertNotIn(0x00710010, got)


class FindStringsTests(unittest.TestCase):
    def test_finds_nul_terminated_source_names_with_addresses(self) -> None:
        image = b"\x00\x00btlSupport.c\x00k_fldRain.c\x00"
        out = fe.find_strings(image, 0x00100000)
        self.assertEqual(out["btlSupport.c"], [0x00100002])
        self.assertEqual(out["k_fldRain.c"],
                         [0x00100002 + len(b"btlSupport.c\x00")])

    def test_an_adjacent_printable_prefix_is_absorbed(self) -> None:
        """Known limitation, pinned rather than papered over.

        String pools in this binary are NUL-separated, so a match starts cleanly.
        If a name were butted directly against preceding letters the captured key
        would carry them, and the caller has to treat that as one string.
        """
        out = fe.find_strings(b"padk_fldRain.c\x00", 0)
        self.assertIn("padk_fldRain.c", out)
        self.assertNotIn("k_fldRain.c", out)

    def test_a_non_identifier_prefix_is_not_absorbed(self) -> None:
        """`?btlPanelAdvantage.c` in a raw scan is really `btlPanelAdvantage.c`."""
        out = fe.find_strings(b"?btlPanelAdvantage.c\x00", 0)
        self.assertEqual(list(out), ["btlPanelAdvantage.c"])

    def test_requires_a_nul_terminator(self) -> None:
        """Without the terminator it is a substring of something else, not a literal."""
        self.assertEqual(fe.find_strings(b"btlSupport.cX", 0), {})

    def test_records_every_address_for_a_repeated_string(self) -> None:
        image = b"item.c\x00" * 3
        out = fe.find_strings(image, 0)
        self.assertEqual(len(out["item.c"]), 3)

    def test_ignores_names_that_are_too_short(self) -> None:
        self.assertEqual(fe.find_strings(b"a.c\x00", 0), {})


if __name__ == "__main__":
    unittest.main()
