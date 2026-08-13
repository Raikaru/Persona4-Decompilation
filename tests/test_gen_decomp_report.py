"""Contract tests for the decomp.dev report generator.

Three defects reached the published badges before these existed, so each test
here pins one of them:

  * `complete_*` was made to mean byte-exact-in-isolation, but every other
    decomp.dev project and objdiff's own schema use it for LINKED code -- Gauntlet:
    Dark Legacy labels `measure=complete_code` "Linked Code". The standard linked
    measure therefore had nothing behind it;
  * a nonstandard `linked` category was invented to carry that figure instead, and
    it was tagged from a build artifact absent in CI, so decomp.dev rendered
    "0 / 0" -- a number that reads as a measurement;
  * the denominator omitted the ~380 canonical functions no source file claims,
    which inflates every published percentage.
"""

import json
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import gen_decomp_report as gen  # noqa: E402
import verify as V  # noqa: E402

CANONICAL_TOTAL = len(V._read_json(V.FUNCTION_WINDOWS)["windows"])


class SimilarityTests(unittest.TestCase):
    def test_match_is_exactly_one_hundred(self) -> None:
        self.assertEqual(gen.similarity({"status": "MATCH", "window": 64}), 100.0)

    def test_assembly_fallback_scores_zero_not_full_credit(self) -> None:
        """An INCLUDE_ASM object trivially equals retail because it IS retail.

        Crediting it would report the extraction of assembly as decompilation
        progress, which is the most misleading thing this report could do.
        """
        self.assertEqual(gen.similarity({"status": "ASM", "window": 64}), 0.0)

    def test_partial_body_is_credited_by_measured_byte_difference(self) -> None:
        row = {"status": "MISMATCH", "window": 100, "normalized_diff": 25}
        self.assertAlmostEqual(gen.similarity(row), 75.0, places=4)

    def test_difference_larger_than_the_window_clamps_to_zero(self) -> None:
        row = {"status": "MISMATCH", "window": 40, "normalized_diff": 400}
        self.assertEqual(gen.similarity(row), 0.0)

    def test_missing_or_malformed_fields_never_raise(self) -> None:
        for row in ({}, {"status": "MISMATCH"}, {"status": "MISMATCH", "window": 0},
                    {"status": "MISMATCH", "window": 8, "normalized_diff": None},
                    {"status": "MISMATCH", "window": 8, "normalized_diff": -3}):
            self.assertEqual(gen.similarity(row), 0.0, row)


class MeasureTests(unittest.TestCase):
    def test_matched_is_byte_exact_and_complete_is_linked(self) -> None:
        """The two families answer different questions and must not be aliased.

        Here one function is byte-exact but not shipped and the other is shipped
        but not byte-exact, so any implementation that conflates them fails.
        """
        rows = [
            {"status": "MATCH", "window": 100, "_linked": False},
            {"status": "ASM", "window": 300, "_linked": True},
        ]
        m = gen.measures(rows)
        self.assertEqual(m["matched_code"], "100")
        self.assertEqual(m["complete_code"], "300")
        self.assertAlmostEqual(m["matched_code_percent"], 25.0, places=4)
        self.assertAlmostEqual(m["complete_code_percent"], 75.0, places=4)

    def test_fuzzy_is_never_below_matched(self) -> None:
        rows = [{"status": "MATCH", "window": 100},
                {"status": "MISMATCH", "window": 100, "normalized_diff": 50}]
        m = gen.measures(rows)
        self.assertGreaterEqual(m["fuzzy_match_percent"], m["matched_code_percent"])

    def test_code_percentages_are_size_weighted(self) -> None:
        m = gen.measures([{"status": "MATCH", "window": 300},
                          {"status": "ASM", "window": 100}])
        self.assertAlmostEqual(m["matched_code_percent"], 75.0, places=4)
        self.assertEqual(m["total_code"], "400")

    def test_empty_population_does_not_divide_by_zero(self) -> None:
        m = gen.measures([])
        self.assertNotIn("total_code", m)
        self.assertNotIn("total_functions", m)
        self.assertEqual(m["total_units"], 1)


class ReportShapeTests(unittest.TestCase):
    """Built from whichever real verifier report is on disk, so the invariants
    hold against the actual tree rather than a fixture that can drift."""

    @classmethod
    def setUpClass(cls) -> None:
        for name in ("verify_report.json", "objdiff_report.json", "verify_wave.json"):
            path = REPO / "build" / name
            if path.is_file() and len(json.loads(path.read_text())["results"]) > 5000:
                cls.report = gen.build_report(path, None)
                return
        raise unittest.SkipTest("no full verifier report in build/")

    def test_denominator_is_the_whole_program(self) -> None:
        """A shrunk denominator inflates every published percentage."""
        self.assertEqual(self.report["measures"]["total_functions"], CANONICAL_TOTAL)

    def test_every_declared_category_is_populated(self) -> None:
        """A category with zero units renders as "0 / 0", which reads as a real
        measurement rather than as missing data."""
        for category in self.report["categories"]:
            self.assertGreater(category["measures"].get("total_functions", 0), 0,
                               f"category {category['id']} tagged nothing")

    def test_linked_measures_come_from_the_committed_endpoint_without_artifacts(self) -> None:
        """setUpClass passed no linked report, so this exercises the CI path where
        build/linked_report.json does not exist."""
        self.assertGreater(int(self.report["measures"]["complete_code"]), 0)
        self.assertGreater(self.report["measures"]["complete_units"], 0)

    def test_linked_is_a_strict_subset_of_byte_exact_work(self) -> None:
        """Everything shipped is in some unit, and not everything is shipped."""
        m = self.report["measures"]
        self.assertLess(int(m["complete_code"]), int(m["total_code"]))
        self.assertLess(m["complete_units"], m["total_units"])

    def test_attribution_categories_partition_the_program(self) -> None:
        """main, third_party and unclassified are mutually exclusive and cover
        everything; `linked` is additive and deliberately overlaps them."""
        counts = {c["id"]: c["measures"].get("total_functions", 0)
                  for c in self.report["categories"]}
        self.assertEqual(counts["main"] + counts["third_party"] + counts["unclassified"],
                         self.report["measures"]["total_functions"])

    def test_schema_version_and_required_keys(self) -> None:
        self.assertEqual(self.report["version"], 2)
        for key in ("fuzzy_match_percent", "matched_functions", "matched_code",
                    "total_functions", "complete_code", "complete_units",
                    "total_units", "total_code"):
            self.assertIn(key, self.report["measures"], key)

    def test_unit_completeness_agrees_with_its_linked_code(self) -> None:
        for unit in self.report["units"]:
            complete = unit["metadata"]["complete"]
            linked_code = int(unit["measures"].get("complete_code", "0"))
            self.assertEqual(complete, linked_code > 0, unit["name"])


if __name__ == "__main__":
    unittest.main()
