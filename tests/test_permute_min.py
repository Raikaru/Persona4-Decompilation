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
        got = labels(REGION)
        for want in ("comma", "no-op mask"):
            self.assertIn(want, got)

    def test_drops_an_unused_declaration_only_when_unused(self) -> None:
        got = labels(REGION)
        self.assertIn("drop unused decl unused_one", got)
        self.assertNotIn("drop unused decl node", got)
        self.assertNotIn("drop unused decl new_var1", got)

    def test_inlines_a_single_use_tool_temp(self) -> None:
        got = labels(REGION)
        self.assertIn("inline new_var1", got)
        out = next(r for lbl, r in pmin.candidates(REGION, OPEN_LINE)
                   if lbl == "inline new_var1")
        joined = "\n".join(out)
        self.assertNotIn("new_var1 = ", joined)
        self.assertIn("((u8 *)arg0)", joined)

    def test_never_inlines_a_name_a_human_chose(self) -> None:
        """`node` is a real name; folding it would rewrite intended source."""
        self.assertNotIn("inline node", labels(REGION))

    def test_never_inlines_a_temp_read_twice(self) -> None:
        region = REGION[:]
        region[-2] = "    *(s32 *)(new_var1 + 4) = *(s32 *)(new_var1 + 8);"
        self.assertNotIn("inline new_var1", labels(region))

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
        for lbl, out in pmin.candidates(region, OPEN_LINE):
            if lbl == "drop statement":
                self.assertIn("*(s32 *)node = 1;", "\n".join(out),
                              "dropped a statement from inside a block")


if __name__ == "__main__":
    unittest.main()
