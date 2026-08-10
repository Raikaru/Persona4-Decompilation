from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import verify  # noqa: E402

MIDDLEWARE = REPO / "src" / "middleware" / "gcc_ee_grouped.c"


class PrefixTests(unittest.TestCase):
    def test_middleware_is_third_party(self) -> None:
        self.assertTrue(verify.is_third_party("src/middleware/gcc_ee_grouped.c"))
        self.assertTrue(verify.is_third_party("middleware/gcc_ee_grouped.c"))

    def test_windows_separators_are_handled(self) -> None:
        self.assertTrue(verify.is_third_party("src\\middleware\\gcc_ee_grouped.c"))

    def test_the_existing_prefixes_still_classify(self) -> None:
        for rel in ("src/cri/cri_adx.c", "src/sce/rofs_if.c", "src/rw/rwcore_grouped.c",
                    "src/crt0.c", "src/libc_core.c"):
            self.assertTrue(verify.is_third_party(rel), rel)

    def test_game_code_is_not_third_party(self) -> None:
        """The prefix must not accidentally swallow real game files."""
        for rel in ("src/g_data/g_data.c", "src/Battle/btlShuffleDraw.c",
                    "src/promoted/code1_0044.c", "src/middlewareish.c"):
            self.assertFalse(verify.is_third_party(rel), rel)


class VendorAddressTests(unittest.TestCase):
    """Vendor libraries are excluded by ADDRESS, because their units are mixed.

    CRI Sofdec/ADX/ROFS, the Sony SDK and the C runtime were linked in as
    prebuilt ee-gcc objects, but the promotion step filed them under generic
    `code1_00xx.c` names. Four of those units also hold real game code, so the
    exclusion cannot be a path rule and the files must not be moved -- relocating
    a translation unit would change object boundaries and break the exact link.
    """

    def test_known_vendor_addresses_are_excluded(self) -> None:
        # func_0050b6b8 is the worked example: byte-exact under ee-gcc2.96 and
        # 899 under MWCCPS2 b210. Then one probe per declared range.
        for addr in (0x0050B6B8, 0x00417510, 0x004BD628, 0x0070C850):
            self.assertTrue(verify.is_vendor_address(addr), hex(addr))

    def test_game_addresses_are_not_excluded(self) -> None:
        # Boundaries are half-open, so each range END belongs to game code.
        # 0x00100008 and 0x00100218 are 8-aligned but are a data table and a
        # `j` thunk, not GCC functions -- the alignment signal alone is not
        # sufficient at the very start of code1.
        for addr in (0x00100008, 0x00100218, 0x0044E830, 0x004BD620,
                     0x0052D8C0, 0x0070E140):
            self.assertFalse(verify.is_vendor_address(addr), hex(addr))

    def test_accepts_the_hex_string_form_used_in_report_rows(self) -> None:
        self.assertTrue(verify.is_vendor_address("0050b6b8"))
        self.assertFalse(verify.is_vendor_address("00100008"))

    def test_missing_or_malformed_addresses_are_not_vendor(self) -> None:
        for value in (None, "", "not-hex"):
            self.assertFalse(verify.is_vendor_address(value), repr(value))

    def test_ranges_are_ordered_and_disjoint(self) -> None:
        ranges = verify.VENDOR_CODE_RANGES
        for low, high in ranges:
            self.assertLess(low, high)
        for (a_low, a_high), (b_low, b_high) in zip(ranges, ranges[1:]):
            self.assertLessEqual(a_high, b_low)

    def test_gcc_alignment_stragglers_are_covered(self) -> None:
        """GCC aligns to 8, MWCCPS2 to 16, so 8-aligned code cannot be ours.

        These addresses sat just outside an earlier, hand-written set of
        boundaries and are what proved that set wrong.
        """
        for addr in (0x0042BA88, 0x0042BB08, 0x00442388, 0x00442DE8,
                     0x0044E658, 0x0044E7D8, 0x004BD628, 0x004BD688):
            self.assertTrue(verify.is_vendor_address(addr), hex(addr))


@unittest.skipUnless(MIDDLEWARE.is_file(), "middleware unit not present")
class MiddlewareUnitTests(unittest.TestCase):
    """The unit only holds functions with a signature b210 cannot emit.

    Reclassifying is a claim about authorship, so the file has to keep carrying its
    evidence and must never become a dumping ground for merely-hard functions.
    """

    def setUp(self) -> None:
        self.text = MIDDLEWARE.read_text(errors="replace")

    def test_every_entry_is_include_asm(self) -> None:
        markers = self.text.count("// FUN_")
        self.assertEqual(markers, self.text.count("INCLUDE_ASM"))
        self.assertGreater(markers, 0)

    def test_any_preserved_body_stays_behind_include_asm(self) -> None:
        """Some entries kept a reverse-engineered body, and that is deliberate.

        The bodies cannot match under MWCCPS2 - that is precisely why these functions
        were reclassified - but they document the semantics and would be the starting
        point if ee-gcc is ever added to the build. What must NOT happen is a body
        being compiled in place of the retail bytes, so every one stays inside
        `#ifdef NON_MATCHING` with `INCLUDE_ASM` on the `#else` arm.
        """
        self.assertEqual(self.text.count("#ifdef NON_MATCHING"),
                         self.text.count("#else"))
        for chunk in self.text.split("#ifdef NON_MATCHING")[1:]:
            head = chunk.split("#endif")[0]
            self.assertIn("#else", head)
            self.assertIn("INCLUDE_ASM", head.split("#else", 1)[1])

    def test_the_evidence_is_recorded(self) -> None:
        for needle in ("ee-gcc", "lui rX", "framed tail jump", "permute_ast",
                       "flanked by genuine third-party"):
            self.assertIn(needle, self.text, needle)

    def test_preprocessor_blocks_are_balanced(self) -> None:
        self.assertEqual(self.text.count("#ifdef"), self.text.count("#endif"))


if __name__ == "__main__":
    unittest.main()
