"""Tests for tools/probe_variants.py.

The prober edits a real source file in place and is expected to put it back.
The behaviour that actually matters is therefore restoration: a candidate that
fails to compile, or a run that raises, must not leave a half-written function
behind. These tests drive the region logic and the restore path directly with a
stubbed diff, so they do not need the compiler.
"""

from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "probe_variants.py"
SPEC = importlib.util.spec_from_file_location("p4_probe_variants", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
probe = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(probe)

SOURCE = """\
#include "include_asm.h"

// FUN_00246910
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246910);

// FUN_00246940
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246940);

// FUN_00246970
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246970);
"""


class RegionTests(unittest.TestCase):
    def test_region_stops_at_the_next_marker(self) -> None:
        start, end = probe.region_for(SOURCE, "FUN_00246940")
        body = SOURCE[start:end]
        self.assertIn("func_00246940", body)
        self.assertNotIn("func_00246910", body)
        self.assertNotIn("func_00246970", body)

    def test_region_of_last_marker_runs_to_eof(self) -> None:
        start, end = probe.region_for(SOURCE, "FUN_00246970")
        self.assertEqual(end, len(SOURCE))
        self.assertIn("func_00246970", SOURCE[start:end])

    def test_region_excludes_the_marker_line_itself(self) -> None:
        """The marker must survive replacement; it is how verify.py tracks it."""
        start, end = probe.region_for(SOURCE, "FUN_00246940")
        replaced = SOURCE[:start] + "int f(void) { return 0; }\n" + SOURCE[end:]
        self.assertIn("// FUN_00246940", replaced)
        self.assertEqual(replaced.count("// FUN_"), SOURCE.count("// FUN_"))

    def test_unknown_marker_is_rejected(self) -> None:
        with self.assertRaises(SystemExit):
            probe.region_for(SOURCE, "FUN_DEADBEEF")

    def test_address_is_derived_from_the_symbol(self) -> None:
        self.assertEqual(probe.address_of("func_00246940"), "FUN_00246940")

    def test_address_requires_hex_digits(self) -> None:
        with self.assertRaises(SystemExit):
            probe.address_of("memset")


class RestoreTests(unittest.TestCase):
    """A probe run must never leave the file in a candidate state."""

    def setUp(self) -> None:
        self.tmp = tempfile.TemporaryDirectory()
        self.path = Path(self.tmp.name) / "cmmMisc.c"
        with open(self.path, "wb") as handle:
            handle.write(SOURCE.encode("utf-8"))
        self.original = self.path.read_bytes()
        self.addCleanup(self.tmp.cleanup)

    def run_probe(self, scores, candidates, keep=None):
        """Drive main() with a stubbed compiler."""
        seen = []
        real = probe.differing_words

        def fake(source: Path, function: str):
            seen.append(Path(source).read_text(encoding="utf-8"))
            return scores[len(seen) - 1]

        probe.differing_words = fake
        argv = [str(self.path), "func_00246940"]
        for name, path in candidates:
            argv += ["--candidate", f"{name}={path}"]
        if keep:
            argv += ["--keep", keep]
        try:
            import sys

            saved = sys.argv
            sys.argv = ["probe_variants.py", *argv]
            try:
                status = probe.main()
            finally:
                sys.argv = saved
        finally:
            probe.differing_words = real
        return status, seen

    def candidate(self, name: str, text: str) -> tuple[str, str]:
        path = Path(self.tmp.name) / f"{name}.c"
        with open(path, "wb") as handle:
            handle.write(text.encode("utf-8"))
        return name, str(path)

    def test_no_match_restores_the_file_exactly(self) -> None:
        cand = self.candidate("a", "int func_00246940(void) { return 1; }\n")
        status, seen = self.run_probe([7, 4], [cand])
        self.assertEqual(status, 1)
        self.assertEqual(self.path.read_bytes(), self.original)
        # The candidate really was compiled, so restoration is not a no-op.
        self.assertIn("return 1", seen[1])

    def test_compile_error_still_restores(self) -> None:
        cand = self.candidate("bad", "this is not C\n")
        status, _ = self.run_probe([7, None], [cand])
        self.assertEqual(status, 1)
        self.assertEqual(self.path.read_bytes(), self.original)

    def test_zero_diff_candidate_is_kept(self) -> None:
        cand = self.candidate("win", "int func_00246940(void) { return 2; }\n")
        status, _ = self.run_probe([7, 0], [cand])
        self.assertEqual(status, 0)
        kept = self.path.read_text(encoding="utf-8")
        self.assertIn("return 2", kept)
        self.assertIn("// FUN_00246940", kept)
        self.assertNotIn("INCLUDE_ASM(\"asm/nonmatchings/cmmMisc\", func_00246940)", kept)
        # Neighbours are untouched.
        self.assertIn("func_00246910", kept)
        self.assertIn("func_00246970", kept)

    def test_keep_forces_a_non_matching_candidate_to_stay(self) -> None:
        cand = self.candidate("near", "int func_00246940(void) { return 3; }\n")
        status, _ = self.run_probe([7, 5], [cand], keep="near")
        self.assertEqual(status, 1)
        self.assertIn("return 3", self.path.read_text(encoding="utf-8"))

    def test_restore_writes_lf_not_crlf(self) -> None:
        """Round-tripping through text mode would reflow the whole file."""
        cand = self.candidate("a", "int func_00246940(void) { return 1; }\n")
        self.run_probe([7, 4], [cand])
        self.assertNotIn(b"\r\n", self.path.read_bytes())


if __name__ == "__main__":
    unittest.main()
