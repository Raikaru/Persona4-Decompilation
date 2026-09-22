from __future__ import annotations

import importlib.util
import subprocess
import tempfile
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
VU_LISTING = REPO / "asm" / "nonmatchings" / "code1_0048" / "func_00485870.s"
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_decoder_audit",
                                              REPO / "tools" / "decoder_audit.py")
assert SPEC is not None and SPEC.loader is not None
audit = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(audit)


class RowParsingTests(unittest.TestCase):
    """The audit's whole value is that it reads the tree's OWN disassembly,
    which is authoritative, instead of trusting capstone.  If the row parser
    drifts it silently checks nothing and reports a clean bill of health -
    the same vacuous-check failure mode the helper scanner nearly shipped."""

    def test_a_listing_row_yields_address_word_and_mnemonic(self) -> None:
        row = "    /* EE610 001EE610 20FBBD27 */  addiu      $29, $29, -0x4E0"
        match = audit.ROW.match(row)
        assert match is not None
        self.assertEqual(match.groups(), ("001EE610", "20FBBD27", "addiu"))

    def test_a_vu_row_parses(self) -> None:
        row = "    /* 3858A8 004858A8 40008ADA */  lqc2       $vf10, 0x40($20)"
        match = audit.ROW.match(row)
        assert match is not None
        self.assertEqual(match.group(3), "lqc2")

    def test_directives_and_labels_are_not_rows(self) -> None:
        for line in (".set noreorder", "glabel func_001ee610",
                     ".size func_001ee610, 0xa0", "  .L001EEACC:", ""):
            self.assertIsNone(audit.ROW.match(line), line)


class AliasTests(unittest.TestCase):
    def test_known_aliases_are_not_reported_as_defects(self) -> None:
        for pair in (("nop", "sll"), ("move", "daddu"), ("b", "beq"),
                     ("c.le.s", "c.ole.s"), ("sync.p", "sync"),
                     ("qmtc2.ni", "dmtc2")):
            self.assertIn(pair, audit.ALIASES)

    def test_a_real_defect_is_not_hidden_in_the_alias_table(self) -> None:
        """These three were genuine mis-decodes; aliasing them away would
        have buried exactly what the audit exists to find."""
        for pair in (("lqc2", "bbit032"), ("sq", "??"), ("madd.s", "??")):
            self.assertNotIn(pair, audit.ALIASES)


class EndToEndTests(unittest.TestCase):
    def test_vu_quadword_fixture_is_not_decoded_as_branches(self) -> None:
        """VU quadword transfers must not decode as Octeon branches."""
        with tempfile.TemporaryDirectory() as directory:
            listing = Path(directory) / "vu_quadword.s"
            listing.write_text(
                "    /* 3858A8 004858A8 40008ADA */  lqc2       $vf10, 0x40($20)\n"
                "    /* 3858AC 004858AC 80008AFA */  sqc2       $vf10, 0x80($20)\n"
            )
            done = subprocess.run(
                [sys.executable, "-E", "-s", "tools/decoder_audit.py", "--quiet",
                 str(listing)],
                cwd=REPO, capture_output=True, text=True, timeout=600)
        self.assertNotIn("listing says", done.stdout)
        self.assertEqual(done.returncode, 0)

    @unittest.skipUnless(VU_LISTING.is_file(), "repo asm listing not present")
    def test_no_instruction_in_a_vu_heavy_listing_is_decoded_wrong(self) -> None:
        """Keep the real listing that exposed the branch-on-bit defect covered."""
        done = subprocess.run(
            [sys.executable, "-E", "-s", "tools/decoder_audit.py", "--quiet",
             str(VU_LISTING)],
            cwd=REPO, capture_output=True, text=True, timeout=600)
        self.assertNotIn("listing says", done.stdout)
        self.assertEqual(done.returncode, 0)

    def test_the_audit_reports_a_mnemonic_that_is_simply_wrong(self) -> None:
        """Feed it a listing row whose mnemonic cannot match the word."""
        forged = Path(REPO / "build" / "decoder_audit_forged.s")
        forged.parent.mkdir(parents=True, exist_ok=True)
        forged.write_text(
            "    /* 000000 00100000 20FBBD27 */  jal        func_00100000\n")
        try:
            done = subprocess.run(
                [sys.executable, "-E", "-s", "tools/decoder_audit.py", "--quiet",
                 str(forged)],
                cwd=REPO, capture_output=True, text=True, timeout=600)
            self.assertIn("listing says jal", done.stdout)
            self.assertIn("addiu", done.stdout)
            self.assertEqual(done.returncode, 1)
        finally:
            forged.unlink()


if __name__ == "__main__":
    unittest.main()
