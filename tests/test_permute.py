from __future__ import annotations

import importlib.util
import random
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "permute.py"
SPEC = importlib.util.spec_from_file_location("p4_permute", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
permute = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(permute)

# A marker plus a body, exactly the slice shape main() hands every mutator.
REGION = [
    "// FUN_00123456",
    "s32 func_00123456(u8 *arg0, s32 arg1)",
    "{",
    "    s32 first;",
    "    u8 *second;",
    "",
    "    first = arg1 + 4;",
    "    second = arg0 + first;",
    "    return first;",
    "}",
]
OPEN_LINE = 2  # index of "{" within REGION


class RegionShapeTests(unittest.TestCase):
    """Mutators rewrite a function in place, so the slice must stay well formed.

    A mutator that loses the marker or the closing brace splices the following
    function into this one. That exact failure once deleted six functions from
    this repo through probe_variants, five of which were matching.
    """

    def test_body_span_brackets_the_braces(self) -> None:
        b0, b1 = permute.body_span(REGION, OPEN_LINE)
        self.assertEqual(REGION[b0 - 1], "{")
        self.assertEqual(REGION[b1], "}")

    def test_mutators_preserve_the_marker_and_closing_brace(self) -> None:
        rng = random.Random(0)
        params = permute.parse_params(REGION[1])
        produced = 0
        for _ in range(600):
            out = permute.mutate(list(REGION), 0, OPEN_LINE, rng, params)
            if out is None:
                continue
            produced += 1
            self.assertEqual(out[0], REGION[0], "marker line must survive")
            self.assertEqual(out.count("}"), 1, "exactly one closing brace")
            # mut_opt / mut_schedule legitimately append a closing pragma after
            # the brace, so the brace need not be last -- but nothing may follow
            # it except pragmas or comments.
            after = [l.strip() for l in out[out.index("}") + 1:] if l.strip()]
            self.assertTrue(all(l.startswith(("#pragma", "//", "/*", "*")) for l in after),
                            f"unexpected content after the closing brace: {after}")
        self.assertGreater(produced, 0, "mutate() never produced a variant")


class MutatorTests(unittest.TestCase):
    def test_declaration_reorder_keeps_every_declaration(self) -> None:
        """Local declaration order is the highest-yield lever in this campaign.

        It matched sdkWrap func_004672c0, sdkLbox func_00470280, sdkUttmx
        func_00463d60 and cmmMisc func_00249670 on its own, so a reorder that
        drops or duplicates a declaration would silently change semantics.
        """
        rng = random.Random(1)
        orders = set()
        for _ in range(300):
            out = permute.mut_decls(list(REGION), OPEN_LINE, rng)
            if out is None:
                continue
            decls = tuple(l.strip() for l in out if l.strip() in ("s32 first;", "u8 *second;"))
            self.assertEqual(sorted(decls), ["s32 first;", "u8 *second;"])
            orders.add(decls)
        self.assertIn(("u8 *second;", "s32 first;"), orders,
                      "mut_decls never produced the reversed order")

    def test_operand_swap_never_rewrites_a_declaration(self) -> None:
        """`u8 *second;` reads as a multiply, and swapping it gives `second * u8;`.

        That variant cannot compile, so it only ever burns an iteration, but a
        declaration is not an expression and rewriting one is always wrong.
        """
        self.assertTrue(permute.is_declaration("    u8 *second;"))
        self.assertTrue(permute.is_declaration("    s32 first;"))
        self.assertFalse(permute.is_declaration("    second = arg0 + first;"))
        self.assertFalse(permute.is_declaration("    return first;"))
        rng = random.Random(2)
        for _ in range(600):
            out = permute.mut_operands(list(REGION), OPEN_LINE, rng)
            if out is None:
                continue
            self.assertIn("    u8 *second;", out, "a declaration was rewritten")

    def test_operand_swap_does_transpose_expressions(self) -> None:
        rng = random.Random(3)
        seen = set()
        for _ in range(600):
            out = permute.mut_operands(list(REGION), OPEN_LINE, rng)
            if out is None:
                continue
            seen.update(l.strip() for l in out)
        self.assertTrue(any(s.startswith("second = first + arg0") for s in seen),
                        "identifier operands were never transposed")
        # widened here versus the P3 original: a numeric literal is a valid
        # operand, so `arg1 + 4` must be transposable too
        self.assertTrue(any(s.startswith("first = 4 + arg1") for s in seen),
                        "an identifier-plus-literal was never transposed")

    def test_parse_params_returns_type_and_name_pairs(self) -> None:
        self.assertEqual(permute.parse_params(REGION[1]),
                         [("u8 *", "arg0"), ("s32", "arg1")])
        self.assertEqual(permute.parse_params("void func_00000000(void)"), [])


if __name__ == "__main__":
    unittest.main()
