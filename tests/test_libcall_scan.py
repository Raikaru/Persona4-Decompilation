from __future__ import annotations

import importlib.util
import subprocess
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_libcall_scan",
                                              REPO / "tools" / "libcall_scan.py")
assert SPEC is not None and SPEC.loader is not None
libcall_scan = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(libcall_scan)


class RelocationParsingTests(unittest.TestCase):
    """The scanner reads helper names out of measure_guarded's relocation
    column.  fnalign prints the same call as `jal 0` with the symbol stripped,
    so a parser that drifts onto the wrong column silently reports zero for
    every function - which is how a vacuous check gets shipped."""

    def test_a_helper_relocation_is_recognised(self) -> None:
        self.assertEqual(libcall_scan.RELOC.findall("R_MIPS_26:__fixsfdi"), ["__fixsfdi"])

    def test_an_ordinary_call_is_not_a_helper(self) -> None:
        names = libcall_scan.RELOC.findall("R_MIPS_26:func_00370410")
        self.assertEqual(names, ["func_00370410"])
        self.assertFalse(any(libcall_scan.HELPER.fullmatch(n) for n in names))

    def test_a_gp_relative_data_relocation_is_not_a_helper(self) -> None:
        names = libcall_scan.RELOC.findall("R_MIPS_GPREL16:iGpffff8044")
        self.assertFalse(any(libcall_scan.HELPER.fullmatch(n) for n in names))

    def test_the_known_conversion_helpers_match(self) -> None:
        for name in ("__fixsfdi", "__floatdisf", "__adddf3", "__extendsfdf2"):
            self.assertTrue(libcall_scan.HELPER.fullmatch(name), name)

    def test_a_symbol_merely_containing_a_helper_word_does_not_match(self) -> None:
        """`printfloat` is a real symbol in this image; matching it would
        invent helper calls that do not exist."""
        self.assertFalse(libcall_scan.HELPER.fullmatch("printfloat"))
        self.assertFalse(libcall_scan.HELPER.fullmatch("func_0018df30"))


class ScopeWordingTests(unittest.TestCase):
    """The tool counts the OBJECT side only.  It never inspects retail: the
    disassembly names every callee by address, and the shipped images carry no
    helper symbols, so nothing here establishes that retail omits the call.
    The wording has to keep saying so, because a stronger reading of this
    output was already used once to call a lead a proven defect."""

    def test_the_cli_marks_the_retail_side_unverified(self) -> None:
        source = (REPO / "tools" / "libcall_scan.py").read_text()
        self.assertIn("retail side not machine-checked", source)
        self.assertIn("OBJECT", source)

    def test_the_docstring_does_not_claim_retail_makes_no_such_call(self) -> None:
        doc = libcall_scan.__doc__ or ""
        self.assertNotIn("retail does not make", doc)
        self.assertNotIn("retail makes none", doc)
        self.assertIn("not \"retail does not\"", doc)

    def test_the_docstring_does_not_call_a_hit_a_proven_defect(self) -> None:
        doc = libcall_scan.__doc__ or ""
        self.assertIn("strong lead to verify", doc)

    def test_the_cli_runs_and_reports_nothing_for_an_empty_input(self) -> None:
        done = subprocess.run([sys.executable, "-E", "-s", "tools/libcall_scan.py"],
                              cwd=REPO, input="", capture_output=True, text=True,
                              timeout=600)
        self.assertEqual(done.returncode, 0)
        self.assertEqual(done.stdout.strip(), "")


class SiteReportingTests(unittest.TestCase):
    """A count alone stalls as soon as a body has more candidate sites than
    helper calls.  `func_002be530` has roughly thirty float-to-s64 stores and
    eleven of the reverse but emits only three helpers; narrowing all of them
    to find the three would have cost about 120 instructions and pushed the
    floor out of the band.  The relocation already knows where the call is."""

    def test_each_site_is_reported_with_its_object_offset(self) -> None:
        source = (REPO / "tools" / "libcall_scan.py").read_text()
        self.assertIn('f"{name}@+{offset:#x}"', source)

    def test_the_offsets_come_from_the_relocation_not_from_parsed_text(self) -> None:
        """Scraping measure_guarded's stdout cost a second compile and gave no
        position at all; reading the ELF relocation gives both."""
        source = (REPO / "tools" / "libcall_scan.py").read_text()
        self.assertIn('r["offset"]', source)
        self.assertNotIn("subprocess", source)

    def test_a_floor_with_no_guarded_body_is_skipped_not_crashed(self) -> None:
        self.assertIsNone(libcall_scan.helpers_in("src/promoted/code1_0039.c",
                                                  "func_003962e0"))

if __name__ == "__main__":
    unittest.main()
