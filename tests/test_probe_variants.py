"""Regression tests for the isolated probe workflow."""

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
    def test_region_is_only_the_target_definition(self) -> None:
        source = """\
// FUN_00246940
static int helper_value;
void func_00246940(void)
{
    return;
}
static int neighboring_value;
// FUN_00246970
INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246970);
"""
        start, end = probe.region_for(source, "FUN_00246940", "func_00246940")
        span = source[start:end]
        self.assertIn("void func_00246940", span)
        self.assertNotIn("helper_value", span)
        self.assertNotIn("neighboring_value", span)

    def test_single_line_definition_preserves_following_declaration(self) -> None:
        source = "// FUN_00246940\nint func_00246940(void) { return 2; } int next;\n"
        start, end = probe.region_for(source, "FUN_00246940")
        self.assertEqual(source[start:end], "int func_00246940(void) { return 2; }")
        self.assertEqual(source[end:], " int next;\n")

    def test_last_fallback_span_reaches_end_of_file_only_when_needed(self) -> None:
        row = 'INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246970);\n'
        for suffix in ("", "static int trailing_value;\n"):
            with self.subTest(suffix=suffix):
                source = SOURCE + suffix
                start, end = probe.region_for(source, "FUN_00246970")
                self.assertEqual(source[start:end], row)
                self.assertEqual(start, SOURCE.index(row))
                self.assertEqual(end, len(SOURCE))
                self.assertEqual(source[end:], suffix)

    def test_unknown_marker_is_rejected(self) -> None:
        with self.assertRaises(SystemExit):
            probe.region_for(SOURCE, "FUN_DEADBEEF")

    def test_address_requires_hex_digits(self) -> None:
        with self.assertRaises(SystemExit):
            probe.address_of("memset")


class IsolationTests(unittest.TestCase):
    def setUp(self) -> None:
        self.tmp = tempfile.TemporaryDirectory()
        self.path = Path(self.tmp.name) / "cmmMisc.c"
        self.path.write_bytes(SOURCE.encode("utf-8"))
        self.original = self.path.read_bytes()
        self.addCleanup(self.tmp.cleanup)

    def run_probe(self, scores, candidates):
        """Drive main() with a stubbed score while recording scratch copies."""
        seen = []
        real = probe.differing_words

        def fake(source: Path, function: str):
            self.assertNotEqual(Path(source).resolve(), self.path.resolve())
            self.assertEqual(self.path.read_bytes(), self.original)
            seen.append(Path(source).read_bytes())
            return scores[len(seen) - 1]

        probe.differing_words = fake
        argv = [str(self.path), "func_00246940"]
        for name, path in candidates:
            argv += ["--candidate", f"{name}={path}"]
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
        path.write_text(text, encoding="utf-8")
        return name, str(path)

    def test_compile_failure_leaves_source_and_neighbor_unchanged(self) -> None:
        candidate = self.candidate("bad", "this is not C\n")
        status, seen = self.run_probe([None], [candidate])
        self.assertEqual(status, 1)
        self.assertEqual(self.path.read_bytes(), self.original)

    def test_match_is_reported_but_source_and_neighbor_stay_unchanged(self) -> None:
        candidate = self.candidate(
            "win", "int func_00246940(void) { return 2; }"
        )
        status, seen = self.run_probe([0], [candidate])
        self.assertEqual(status, 0)
        self.assertEqual(self.path.read_bytes(), self.original)
        expected = self.original.replace(
            b'INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246940);\n',
            b"int func_00246940(void) { return 2; }\n",
        )
        # Scratch splicing may normalize blank separators, never code or markers.
        self.assertEqual(
            [[line for line in source.splitlines() if line.strip()] for source in seen],
            [[line for line in expected.splitlines() if line.strip()]],
        )

    def test_include_asm_baseline_is_never_scored(self) -> None:
        candidate = self.candidate(
            "a", "int func_00246940(void) { return 1; }\n"
        )
        status, seen = self.run_probe([6], [candidate])
        self.assertEqual(status, 1)
        expected = self.original.replace(
            b'INCLUDE_ASM("asm/nonmatchings/cmmMisc", func_00246940);\n',
            b"int func_00246940(void) { return 1; }\n",
        )
        self.assertEqual(
            [[line for line in source.splitlines() if line.strip()] for source in seen],
            [[line for line in expected.splitlines() if line.strip()]],
        )
        self.assertEqual(self.path.read_bytes(), self.original)

    def test_interrupt_does_not_restore_over_concurrent_source_edit(self) -> None:
        import sys
        from unittest.mock import patch

        candidate = self.candidate("interrupt", "int func_00246940(void) { return 2; }")
        changed = self.original + b"/* concurrent editor change */\n"
        scratch_paths = []

        def interrupted(source, function):
            scratch_paths.append(source)
            self.path.write_bytes(changed)
            raise KeyboardInterrupt

        args = ["probe_variants.py", str(self.path), "func_00246940",
                "--candidate", f"{candidate[0]}={candidate[1]}"]
        with patch.object(sys, "argv", args), patch.object(
            probe, "differing_words", interrupted
        ):
            with self.assertRaises(KeyboardInterrupt):
                probe.main()
        self.assertEqual(self.path.read_bytes(), changed)
        self.assertEqual(len(scratch_paths), 1)
        self.assertFalse(scratch_paths[0].exists())


if __name__ == "__main__":
    unittest.main()
