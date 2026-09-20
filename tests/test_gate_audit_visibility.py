from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_gate_audit",
                                              REPO / "tools" / "gate_audit.py")
assert SPEC is not None and SPEC.loader is not None
gate_audit = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(gate_audit)


class ReasonTests(unittest.TestCase):
    """A floor that cannot be measured has no score, no gate, and no proof it
    still compiles.  `func_0023e6f0` sat in exactly that state for weeks: a
    prototype added elsewhere in datCalc.c broke its guarded body, and because
    a guarded body is never compiled by tools/build.py the only symptom was a
    bare "could not be measured" tally that read like rounding noise.  These
    tests pin the distinction that makes such a floor visible."""

    def test_a_body_that_does_not_compile_is_named_as_broken(self) -> None:
        exc = SystemExit("verify: ### mwccps2.exe Compiler:\n"
                         "Error compiling src/promoted/.code1_003e.probe_x.c")
        self.assertEqual(gate_audit.reason_for(exc),
                         "guarded body does not compile")

    def test_a_failed_subprocess_is_also_named_as_broken(self) -> None:
        exc = SystemExit("build: command failed: /usr/bin/python3")
        self.assertEqual(gate_audit.reason_for(exc),
                         "guarded body does not compile")

    def test_a_bare_marker_over_include_asm_is_not_called_broken(self) -> None:
        """23 markers in the tree sit directly on an INCLUDE_ASM row with no
        `#ifdef` body.  That is an honest "not started", and lumping it in with
        real breakage is what let the broken floors hide."""
        exc = SystemExit("verify: symbol not present in object: func_003962e0")
        self.assertEqual(gate_audit.reason_for(exc),
                         "no guarded body: marker sits directly on INCLUDE_ASM")

    def test_a_missing_region_is_named_distinctly(self) -> None:
        exc = ValueError("could not find a definition or INCLUDE_ASM row for f")
        self.assertEqual(gate_audit.reason_for(exc),
                         "no body or INCLUDE_ASM row found")

    def test_an_unrecognised_failure_still_says_something_useful(self) -> None:
        reason = gate_audit.reason_for(KeyError("0x00123456"))
        self.assertIn("KeyError", reason)
        self.assertIn("0x00123456", reason)

    def test_an_empty_exception_message_still_names_the_type(self) -> None:
        self.assertEqual(gate_audit.reason_for(RuntimeError()), "RuntimeError")


class SummaryWordingTests(unittest.TestCase):
    def test_the_summary_separates_broken_floors_from_bodyless_markers(self) -> None:
        source = (REPO / "tools" / "gate_audit.py").read_text()
        self.assertIn('f", {len(broken)} broken"', source)
        self.assertIn('f", {len(bodyless)} markers with no body"', source)
        self.assertIn("BROKEN", source)

    def test_the_broken_advice_says_a_guarded_body_is_never_built(self) -> None:
        source = (REPO / "tools" / "gate_audit.py").read_text()
        self.assertIn("never built", source)
        self.assertIn("func_0023e6f0", source)


if __name__ == "__main__":
    unittest.main()
