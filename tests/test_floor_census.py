"""Floor attribution decides what a wave works on, so a wrong rule wastes a wave.

Measuring one tree with a 12-line window, a 4-line window and a contiguous-comment
walk produced 500, 49 and 20 floored functions. These tests pin the only rule that
holds: a note belongs to the next marker below it, and it is a given function's
floor only when no other marker sits between them.
"""

import sys
import textwrap
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import floor_census as fc  # noqa: E402


def L(src: str) -> list[str]:
    return textwrap.dedent(src).strip("\n").split("\n")


def marker_index(lines: list[str], addr: str) -> int:
    for i, line in enumerate(lines):
        if addr in line and "FUN_" in line:
            return i
    raise AssertionError(f"no marker for {addr}")


class AttributionTests(unittest.TestCase):
    def test_note_directly_above_the_marker_is_its_floor(self) -> None:
        lines = L(
            """
            // measured: nd 4, load sinking; tried s32/u32 and reordered locals.
            // FUN_00100000
            INCLUDE_ASM("asm/x", func_00100000);
            """
        )
        self.assertIsNotNone(fc.note_for(lines, marker_index(lines, "00100000")))

    def test_multiline_block_comment_note_is_found(self) -> None:
        """Interior lines of a /* */ block match no comment prefix; naive walks stop."""
        lines = L(
            """
            /* measured: tried $s0 first, then $s1 first, then a struct temp;
               all three land on nd 10. Register-coalescing floor. */
            // FUN_00100000
            INCLUDE_ASM("asm/x", func_00100000);
            """
        )
        self.assertIsNotNone(fc.note_for(lines, marker_index(lines, "00100000")))

    def test_blank_lines_between_note_and_marker_do_not_break_it(self) -> None:
        lines = L(
            """
            // measured: nd 6, delay-slot fill.

            // FUN_00100000
            INCLUDE_ASM("asm/x", func_00100000);
            """
        )
        self.assertIsNotNone(fc.note_for(lines, marker_index(lines, "00100000")))

    def test_a_previous_functions_note_is_not_ours(self) -> None:
        """The rule that matters: a marker in between ends the note's territory."""
        lines = L(
            """
            // measured: nd 9, this floor belongs to the function below it.
            // FUN_00100000
            INCLUDE_ASM("asm/x", func_00100000);

            // FUN_00100100
            INCLUDE_ASM("asm/x", func_00100100);
            """
        )
        self.assertIsNotNone(fc.note_for(lines, marker_index(lines, "00100000")))
        self.assertIsNone(
            fc.note_for(lines, marker_index(lines, "00100100")),
            "a note above a DIFFERENT marker was credited to this function",
        )

    def test_matched_c_above_does_not_leak_its_note(self) -> None:
        lines = L(
            """
            // measured: opt_loop_invariants is load-bearing here, nd 0 -> nd 12.
            #pragma opt_loop_invariants on
            // FUN_00100000
            void func_00100000(void) { return; }
            #pragma opt_loop_invariants off

            // FUN_00100100
            INCLUDE_ASM("asm/x", func_00100100);
            """
        )
        self.assertIsNone(fc.note_for(lines, marker_index(lines, "00100100")))

    def test_no_note_is_untried(self) -> None:
        lines = L(
            """
            // FUN_00100000
            INCLUDE_ASM("asm/x", func_00100000);
            """
        )
        self.assertIsNone(fc.note_for(lines, marker_index(lines, "00100000")))

    def test_index_outside_the_file_is_an_error_not_a_silent_none(self) -> None:
        with self.assertRaises(fc.CensusError):
            fc.note_for(["// FUN_00100000"], 99)


class MisplacedNoteTests(unittest.TestCase):
    """A note between a marker and its INCLUDE_ASM hides the function entirely."""

    def test_note_between_marker_and_include_asm_is_reported(self) -> None:
        lines = L(
            """
            // FUN_00100000
            // measured: nd 3, argument evaluation order.
            INCLUDE_ASM("asm/x", func_00100000);
            """
        )
        self.assertEqual(fc.misplaced_notes(lines), [(1, "00100000")])

    def test_note_above_the_marker_is_not_misplaced(self) -> None:
        lines = L(
            """
            // measured: nd 3, argument evaluation order.
            // FUN_00100000
            INCLUDE_ASM("asm/x", func_00100000);
            """
        )
        self.assertEqual(fc.misplaced_notes(lines), [])

    def test_a_clean_tree_reports_nothing(self) -> None:
        lines = L(
            """
            // FUN_00100000
            INCLUDE_ASM("asm/x", func_00100000);

            // FUN_00100100
            void func_00100100(void) { return; }
            """
        )
        self.assertEqual(fc.misplaced_notes(lines), [])


class UnattributedNoteTests(unittest.TestCase):
    def test_note_with_no_following_marker_is_orphaned(self) -> None:
        lines = L(
            """
            // FUN_00100000
            void func_00100000(void) { return; }

            // measured: nd 5, saved-register rotation.
            """
        )
        self.assertEqual(fc.unattributed_notes(lines), [4])

    def test_pragma_justification_is_not_orphaned(self) -> None:
        """A measured note above a pragma justifies the pragma, not a function."""
        lines = L(
            """
            // measured: without this pragma the file regresses nd 0 -> nd 12.
            #pragma opt_propagation off
            """
        )
        self.assertEqual(fc.unattributed_notes(lines), [])

    def test_note_followed_by_a_marker_is_attributed(self) -> None:
        lines = L(
            """
            // measured: nd 5, saved-register rotation.
            // FUN_00100000
            INCLUDE_ASM("asm/x", func_00100000);
            """
        )
        self.assertEqual(fc.unattributed_notes(lines), [])


class CensusTests(unittest.TestCase):
    def test_census_splits_untried_from_floored(self) -> None:
        import tempfile

        with tempfile.TemporaryDirectory() as tmp:
            rel = "src/probe_census.c"
            path = REPO / rel
            self.assertFalse(path.exists(), "fixture name collides with a real file")
            path.write_bytes(
                b"// measured: nd 8, CSE of the loop-test load.\n"
                b"// FUN_00100000\n"
                b'INCLUDE_ASM("asm/x", func_00100000);\n'
                b"\n"
                b"// FUN_00100100\n"
                b'INCLUDE_ASM("asm/x", func_00100100);\n'
            )
            try:
                report = {
                    "results": [
                        {"file": rel, "addr": "00100000", "line": 2, "status": "ASM", "window": 48},
                        {"file": rel, "addr": "00100100", "line": 5, "status": "ASM", "window": 32},
                    ]
                }
                out = fc.census(report)
                self.assertEqual(out["total"], 2)
                self.assertEqual([e["addr"] for e in out["floored"]], ["00100000"])
                self.assertEqual([e["addr"] for e in out["untried"]], ["00100100"])
                self.assertEqual(out["untried_by_file"][rel], 1)
            finally:
                path.unlink()


if __name__ == "__main__":
    unittest.main()
