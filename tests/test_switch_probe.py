import importlib.util
import os
import unittest

_SPEC = importlib.util.spec_from_file_location(
    'switch_probe', os.path.join(os.path.dirname(__file__), '..', 'tools',
                                 'switch_probe.py'))
sp = importlib.util.module_from_spec(_SPEC)
_SPEC.loader.exec_module(sp)


CHAIN = [
    "    if (v == 3) { f(3); }",
    "    else if (v == 1) { f(1); }",
    "    else if (v == 2) { f(2); }",
    "    else if (v == 0) { f(0); }",
    "    return 0;",
]


class RewriteOneLiners(unittest.TestCase):
    def test_cases_come_out_ascending(self) -> None:
        """MWCC lays switch arm bodies out in ascending case order; a chain
        written descending is exactly the defect this rewrite fixes."""
        out, converted = sp.rewrite_one_liners(CHAIN)
        self.assertEqual(converted, 1)
        self.assertEqual([line.strip() for line in out if line.strip().startswith("case")],
                         ["case 0:", "case 1:", "case 2:", "case 3:"])

    def test_each_arm_keeps_its_body_and_gains_a_break(self) -> None:
        out, _ = sp.rewrite_one_liners(CHAIN)
        text = "\n".join(out)
        for value in range(4):
            self.assertIn(f"case {value}:\n        f({value});\n        break;", text)

    def test_trailing_statements_survive(self) -> None:
        out, _ = sp.rewrite_one_liners(CHAIN)
        self.assertEqual(out[-1], "    return 0;")

    def test_short_chain_is_left_alone(self) -> None:
        short = CHAIN[:2] + ["    return 0;"]
        out, converted = sp.rewrite_one_liners(short)
        self.assertEqual(converted, 0)
        self.assertEqual(out, short)

    def test_a_chain_on_a_different_variable_ends_the_run(self) -> None:
        mixed = CHAIN[:3] + ["    else if (w == 9) { f(9); }", "    return 0;"]
        out, converted = sp.rewrite_one_liners(mixed, min_arms=3)
        self.assertEqual(converted, 1)
        self.assertIn("    else if (w == 9) { f(9); }", out)

    def test_hex_case_values_are_ordered_numerically(self) -> None:
        chain = [
            "    if (v == 0x10) { f(16); }",
            "    else if (v == 9) { f(9); }",
            "    else if (v == 0xA) { f(10); }",
            "    else if (v == 2) { f(2); }",
        ]
        out, _ = sp.rewrite_one_liners(chain)
        self.assertEqual([line.strip() for line in out if line.strip().startswith("case")],
                         ["case 2:", "case 9:", "case 10:", "case 16:"])


class ChainVariables(unittest.TestCase):
    def test_finds_the_tested_variable(self) -> None:
        self.assertEqual(sp.chain_variables("\n".join(CHAIN)), ["v"])

    def test_ignores_a_chain_below_the_threshold(self) -> None:
        self.assertEqual(sp.chain_variables("\n".join(CHAIN), min_arms=6), [])


if __name__ == '__main__':
    unittest.main()
