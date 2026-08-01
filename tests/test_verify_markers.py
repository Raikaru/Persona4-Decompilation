"""Marker parsing rules that decide how a function is SCORED.

These shapes drive the progress metric, so a parsing slip does not just
mislabel a row -- it silently inflates or deflates the match count. The
`#ifdef NON_MATCHING` / `INCLUDE_ASM` shape is the subtle one: the object gets
the exact retail bytes from the assembly fallback, so a byte comparison always
succeeds. Without explicit handling such a row reads as MATCH (or as
STALE_NONMATCHING, inviting someone to remove a tag that is still true).
"""

from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("p4_verify_markers", REPO / "tools" / "verify.py")
assert SPEC is not None and SPEC.loader is not None
verify = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(verify)


def markers_for(source: str) -> list[dict]:
    with tempfile.TemporaryDirectory() as temporary:
        path = Path(temporary) / "unit.c"
        path.write_bytes(source.encode("utf-8"))
        return verify.scan_markers(path)


class MarkerScanTests(unittest.TestCase):
    def test_plain_function_is_not_an_assembly_fallback(self) -> None:
        markers = markers_for(
            "// FUN_00100010\n"
            "void func_00100010(void)\n{\n}\n"
        )
        self.assertEqual(len(markers), 1)
        self.assertEqual(markers[0]["name"], "func_00100010")
        self.assertFalse(markers[0].get("asm"))
        self.assertFalse(markers[0]["nonmatching"])

    def test_bare_include_asm_directly_under_the_marker(self) -> None:
        markers = markers_for(
            '// FUN_00100010\n'
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
        )
        self.assertEqual(len(markers), 1)
        self.assertTrue(markers[0].get("asm"))
        self.assertEqual(markers[0]["name"], "func_00100010")

    def test_non_matching_fallback_shape_is_an_assembly_fallback(self) -> None:
        markers = markers_for(
            "// FUN_00100010 NONMATCHING\n"
            "#ifdef NON_MATCHING\n"
            "s32 func_00100010(void)\n{\n    return 1;\n}\n"
            "#else\n"
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
            "#endif\n"
        )
        self.assertEqual(len(markers), 1)
        self.assertTrue(markers[0].get("asm"), "fallback must not be scored as decompiled C")
        self.assertTrue(markers[0]["nonmatching"])

    def test_line_comment_between_marker_and_ifdef_is_skipped(self) -> None:
        """Floor explanations live between the marker and the #ifdef."""
        markers = markers_for(
            "// FUN_00100010 NONMATCHING\n"
            "// Measured floor nd=19: retail keeps a dead addiu.\n"
            "// Probed if/else, goto and pragma shapes -- all nd>=19.\n"
            "#ifdef NON_MATCHING\n"
            "s32 func_00100010(void)\n{\n    return 1;\n}\n"
            "#else\n"
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
            "#endif\n"
        )
        self.assertTrue(markers[0].get("asm"))

    def test_block_comment_between_marker_and_ifdef_is_skipped(self) -> None:
        """The other comment style must work too; cldScheduler.c uses it."""
        markers = markers_for(
            "// FUN_00100010 NONMATCHING\n"
            "/* Floor: b210 allocates the day-of-week temp ahead of the\n"
            "   copy-loop counter, swapping two registers. */\n"
            "#ifdef NON_MATCHING\n"
            "s32 func_00100010(void)\n{\n    return 1;\n}\n"
            "#else\n"
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
            "#endif\n"
        )
        self.assertTrue(markers[0].get("asm"))

    def test_long_preserved_body_still_finds_the_fallback(self) -> None:
        """One real body is 435 lines; a fixed lookahead window would miss it."""
        body = "\n".join(f"    total += {n};" for n in range(500))
        markers = markers_for(
            "// FUN_00100010 NONMATCHING\n"
            "#ifdef NON_MATCHING\n"
            f"s32 func_00100010(void)\n{{\n    s32 total = 0;\n{body}\n    return total;\n}}\n"
            "#else\n"
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
            "#endif\n"
        )
        self.assertEqual(len(markers), 1)
        self.assertTrue(markers[0].get("asm"))

    def test_ifdef_without_a_fallback_is_not_treated_as_assembly(self) -> None:
        """A guard that never reaches INCLUDE_ASM must fall through to normal parsing."""
        markers = markers_for(
            "// FUN_00100010\n"
            "#ifdef SOMETHING_ELSE\n"
            "s32 func_00100010(void)\n{\n    return 1;\n}\n"
            "#endif\n"
        )
        self.assertEqual(len(markers), 1)
        self.assertFalse(markers[0].get("asm"))

    def test_following_marker_is_still_found_after_a_fallback(self) -> None:
        """The scanner must resume after the #endif, not swallow the next function."""
        markers = markers_for(
            "// FUN_00100010 NONMATCHING\n"
            "#ifdef NON_MATCHING\n"
            "s32 func_00100010(void)\n{\n    return 1;\n}\n"
            "#else\n"
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
            "#endif\n"
            "\n"
            "// FUN_00100020\n"
            "void func_00100020(void)\n{\n}\n"
        )
        self.assertEqual([m["addr"] for m in markers], [0x00100010, 0x00100020])
        self.assertTrue(markers[0].get("asm"))
        self.assertFalse(markers[1].get("asm"))

    def test_scoped_pragma_between_marker_and_ifdef_is_skipped(self) -> None:
        """A pragma scoped to the function may sit above its #ifdef."""
        markers = markers_for(
            "// FUN_00100010 NONMATCHING\n"
            "// Measured floor nd=2 with the pragma, nd=18 without.\n"
            "#pragma schedule on\n"
            "#ifdef NON_MATCHING\n"
            "s32 func_00100010(void)\n{\n    return 1;\n}\n"
            "#else\n"
            'INCLUDE_ASM("asm/nonmatchings/thing", func_00100010);\n'
            "#endif\n"
        )
        self.assertTrue(markers[0].get("asm"))


if __name__ == "__main__":
    unittest.main()
