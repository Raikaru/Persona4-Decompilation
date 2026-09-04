from __future__ import annotations

import importlib.util
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("p4_permute_min", REPO / "tools" / "permute_min.py")
assert SPEC is not None and SPEC.loader is not None
pmin = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(pmin)

REGION = [
    "// FUN_00123456",
    "void func_00123456(void *arg0)",
    "{",
    "    u8 *node;",
    "    u8 *new_var1;",
    "    int unused_one;",
    "",
    "    if (1)",
    "    {",
    "    }",
    "    new_var1 = (u8 *)arg0;",
    "    node = new_var1 + 8;",
    "    *(s32 *)(node + (4 & 0xFFFFFFFFu)) = (0, 1);",
    "}",
]
OPEN_LINE = 2


def labels(region, open_line=OPEN_LINE):
    return [lbl for lbl, _ in pmin.candidates(region, open_line)]


class CandidateTests(unittest.TestCase):
    """Every candidate must be a strict simplification of committable C.

    The minimizer only ever KEEPS a candidate that still scores 0, so a wrong
    candidate cannot corrupt a match. But a candidate that changes meaning while
    coincidentally still matching would put dishonest source in the tree, which is
    the thing this tool exists to prevent.
    """

    def test_finds_an_empty_block(self) -> None:
        self.assertIn("drop empty block", labels(REGION))
        out = next(r for lbl, r in pmin.candidates(REGION, OPEN_LINE)
                   if lbl == "drop empty block")
        self.assertNotIn("if (1)", "\n".join(out))
        self.assertIn("node = new_var1 + 8;", "\n".join(out))

    def test_finds_the_noise_rewrites(self) -> None:
        expected_lines = {
            "comma": "    *(s32 *)(node + (4 & 0xFFFFFFFFu)) = (1);",
            "no-op mask": "    *(s32 *)(node + (4)) = (0, 1);",
        }
        for label, line in expected_lines.items():
            out = next(r for lbl, r in pmin.candidates(REGION, OPEN_LINE) if lbl == label)
            self.assertEqual(out, REGION[:12] + [line] + REGION[13:])

    def test_drops_an_unused_declaration_only_when_unused(self) -> None:
        got = labels(REGION)
        self.assertIn("drop unused decl unused_one", got)
        self.assertNotIn("drop unused decl node", got)
        self.assertNotIn("drop unused decl new_var1", got)
        out = next(r for lbl, r in pmin.candidates(REGION, OPEN_LINE)
                   if lbl == "drop unused decl unused_one")
        self.assertEqual(out, REGION[:5] + REGION[6:])

    def test_inlines_a_single_use_tool_temp(self) -> None:
        got = labels(REGION)
        self.assertIn("inline new_var1", got)
        out = next(r for lbl, r in pmin.candidates(REGION, OPEN_LINE)
                   if lbl == "inline new_var1")
        self.assertEqual(out, REGION[:4] + REGION[5:10]
                         + ["    node = ((u8 *)arg0) + 8;"] + REGION[12:])

    def test_never_inlines_a_name_a_human_chose(self) -> None:
        """`node` is a real name; folding it would rewrite intended source."""
        self.assertNotIn("inline node", labels(REGION))

    def test_never_inlines_a_temp_read_twice(self) -> None:
        for same_line in (True, False):
            with self.subTest(same_line=same_line):
                region = REGION[:]
                if same_line:
                    region[11] = "    node = (u8 *)arg0;"
                    region[12] = "    *(s32 *)(new_var1 + 4) = *(s32 *)(new_var1 + 8);"
                else:
                    region[12] = "    *(s32 *)(new_var1 + 4) = 1;"
                self.assertNotIn("inline new_var1", labels(region))

    def test_splits_a_packed_line(self) -> None:
        """The randomizer packs several statements per line; every other pass here
        works line-at-a-time, so nothing can reach them until they are split."""
        region = [
            "// FUN_00123456",
            "void func_00123456(void *arg0)",
            "{",
            "    int new_var2;",
            " new_var2 = 0xB & 0xFFFF; new_var2 = 0; { new_var2 = 1; }",
            "}",
        ]
        out = next((r for lbl, r in pmin.candidates(region, OPEN_LINE)
                    if lbl == "split line"), None)
        self.assertIsNotNone(out)
        body = [l.strip() for l in out[4:-1]]
        self.assertEqual(body, ["new_var2 = 0xB & 0xFFFF;", "new_var2 = 0;",
                                "{ new_var2 = 1; }"])

    def test_never_splits_a_for_header(self) -> None:
        """A for-header's semicolons are not statement breaks."""
        region = [
            "// FUN_00123456",
            "void func_00123456(void *arg0)",
            "{",
            "    int i;",
            "    for (i = 0; i < 4; i++) { }",
            "}",
        ]
        self.assertNotIn("split line", labels(region))

    def test_statement_drops_stay_at_top_level(self) -> None:
        """A statement inside a braced block must not be dropped on its own.

        Dropping one arm of a conditional changes control flow, and the score
        would not necessarily catch it.
        """
        region = [
            "// FUN_00123456",
            "void func_00123456(void *arg0)",
            "{",
            "    u8 *node;",
            "",
            "    node = (u8 *)arg0;",
            "    if (node != NULL)",
            "    {",
            "        *(s32 *)node = 1;",
            "    }",
            "}",
        ]
        drops = [out for lbl, out in pmin.candidates(region, OPEN_LINE) if lbl == "drop statement"]
        self.assertIn(region[:5] + region[6:], drops)
        for out in drops:
            self.assertIn("*(s32 *)node = 1;", "\n".join(out),
                          "dropped a statement from inside a block")


if __name__ == "__main__":
    unittest.main()
