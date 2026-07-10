from __future__ import annotations

import copy
import importlib.util
import json
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "progress.py"
SPEC = importlib.util.spec_from_file_location("p4_progress", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
progress = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(progress)

WINDOWS = {0x00100008: 16, 0x00100018: 16}
LINKED_REPORT = {
    "schema_version": 1,
    "build_succeeded": True,
    "image_sha1": "image",
    "retail_sha1": "retail",
    "function_total": 2,
    "linked_tu_count": 1,
    "linked_function_count": 1,
    "linked_functions": [{"address": "00100008", "name": "first", "file": "src/first.c"}],
}


class ProgressTests(unittest.TestCase):
    def test_rejects_malformed_verifier_report(self) -> None:
        with self.assertRaisesRegex(progress.ProgressError, "results"):
            progress.make_metrics({}, WINDOWS, None, "verify.json", None)
        with self.assertRaisesRegex(progress.ProgressError, "addr"):
            progress.make_metrics({"results": [{"status": "MATCH"}]}, WINDOWS, None, "verify.json", None)
        with self.assertRaisesRegex(progress.ProgressError, "status"):
            progress.make_metrics({"results": [{"addr": "00100008"}]}, WINDOWS, None, "verify.json", None)
        with self.assertRaisesRegex(progress.ProgressError, "missing"):
            progress.validate_linked_report({}, WINDOWS)

    def test_matching_deduplicates_addresses_and_ignores_unknown_rows(self) -> None:
        report = {"results": [
            {"addr": "00100008", "status": "MATCH", "object_size": 8},
            {"addr": 0x00100008, "status": "MATCH", "object_size": 12},
            {"addr": "00100018", "status": "MISMATCH"},
            {"addr": "00ffffff", "status": "MATCH"},
        ]}
        metrics, _matching, _linked = progress.make_metrics(report, WINDOWS, None, "verify.json", None)
        self.assertEqual(metrics["matching"]["addresses"], ["00100008"])
        self.assertEqual(metrics["matching"]["count"], 1)
        self.assertEqual(metrics["matching"]["matched_body_bytes"], 12)
        self.assertEqual(metrics["matching"]["known_rows"], 3)
        self.assertEqual(metrics["matching"]["unique_known_addresses"], 2)
        self.assertEqual(metrics["matching"]["duplicate_rows"], 1)
        self.assertEqual(metrics["source"]["ignored_unknown_rows"], 1)

    def test_rejects_linked_function_outside_matching_set(self) -> None:
        report = {"results": [{"addr": "00100008", "status": "MATCH"}]}
        linked = copy.deepcopy(LINKED_REPORT)
        linked["linked_functions"][0]["address"] = "00100018"
        linked = progress.validate_linked_report(linked, WINDOWS)
        with self.assertRaisesRegex(progress.ProgressError, "not in the matching"):
            progress.make_metrics(report, WINDOWS, linked, "verify.json", "build.json")

    def test_validates_generated_endpoints_and_rejects_non_subset(self) -> None:
        report = {"results": [{"addr": "00100008", "status": "MATCH", "object_size": 8}]}
        linked = progress.validate_linked_report(copy.deepcopy(LINKED_REPORT), WINDOWS)
        metrics, matching, linked_badge = progress.make_metrics(report, WINDOWS, linked, "verify.json", "build.json")
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            progress.write_endpoints(directory, metrics, matching, linked_badge)
            progress.validate_endpoints(directory, WINDOWS)
            corrupt = json.loads((directory / "metrics.json").read_text(encoding="utf-8"))
            corrupt["linked"]["addresses"] = ["00100018"]
            (directory / "metrics.json").write_text(json.dumps(corrupt), encoding="utf-8")
            with self.assertRaisesRegex(progress.ProgressError, "matching subset"):
                progress.validate_endpoints(directory, WINDOWS)


if __name__ == "__main__":
    unittest.main()
