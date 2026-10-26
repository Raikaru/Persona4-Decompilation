from __future__ import annotations

import json
import sys
import tempfile
import unittest
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[1] / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))
import regenerate_asm as regeneration


class ManifestInputTests(unittest.TestCase):
    def test_committed_generator_inputs_match_the_audited_manifest(self) -> None:
        root = TOOLS.parent
        manifest = json.loads((root / regeneration.MANIFEST).read_text(encoding="utf-8"))
        for relative, expected in manifest["inputs"].items():
            with self.subTest(path=relative):
                self.assertEqual(regeneration.digest((root / relative).read_bytes()), expected,
                                 "Audit generator changes and update the manifest before publishing")


class PinnedSymbolNameTests(unittest.TestCase):
    def test_live_rename_or_reuse_cannot_change_pinned_targets(self) -> None:
        for live in ("renamed_entry = 0x00100000;\n",
                     "old_entry = 0x00100020;\n"):
            with self.subTest(live=live), tempfile.TemporaryDirectory() as temporary:
                root = Path(temporary)
                (root / "config").mkdir()
                (root / "config/asm_symbol_baseline.txt").write_text(
                    "old_entry = 0x00100000;\n", encoding="utf-8")
                (root / "config/symbol_addrs.txt").write_text(live, encoding="utf-8")
                pattern, names = regeneration.canonical_names(
                    root, {"00100000": 0x20, "00100020": 0x20})
                text = "glabel old_entry\njal old_entry\n"
                result = pattern.sub(lambda match: names[match[0]], text)
                self.assertEqual(result,
                                 "glabel func_00100000\njal func_00100000\n")


    def test_audited_spelling_correction_precedes_pinned_normalization(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "config").mkdir()
            (root / "config/asm_symbol_baseline.txt").write_text(
                "old_entry = 0x00100020;\n", encoding="utf-8")
            source = ("glabel func_00100000\n"
                      "/* 000000 00100000 0800040C */ jal old_entry\n")
            (root / "code1.s").write_text(source, encoding="utf-8")
            expected = ("".join(regeneration.extractor.HEADER_LINES)
                        + source.replace("old_entry", "func_00100020")
                        + ".size func_00100000, 0x4\n").encode("utf-8")
            entry = {"path": "asm/nonmatchings/test/func_00100000.s",
                     "recipe": "slice-canonical",
                     "sha256": regeneration.digest(expected),
                     "correction": {"symbol_spellings": [
                         ["old_entry", "func_00100020"]]}}
            windows = {"00100000": 4, "00100020": 4}
            result = regeneration.render(
                entry, regeneration.SplitIndex(root), None, windows,
                regeneration.canonical_names(root, windows))
            self.assertEqual(result, expected)


class OutputProtectionTests(unittest.TestCase):
    def test_changed_generated_file_is_rejected_before_fresh_removal(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            path = root / "asm/nonmatchings/group/func_00100000.s"
            path.parent.mkdir(parents=True)
            path.write_bytes(b"user edit\n")
            manifest = {"generated": [{"path": path.relative_to(root).as_posix(),
                                       "sha256": regeneration.digest(b"baseline\n")}],
                        "retained": []}
            with self.assertRaises(regeneration.RegenerationError):
                regeneration.preflight(root, manifest, require_generated=False)
            self.assertEqual(path.read_bytes(), b"user edit\n")

    def test_unknown_file_cannot_be_silently_excluded_from_corpus(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            path = root / "asm/nonmatchings/handwritten.s"
            path.parent.mkdir(parents=True)
            path.write_bytes(b"handwritten\n")
            with self.assertRaises(regeneration.RegenerationError):
                regeneration.preflight(root, {"generated": [], "retained": []},
                                       require_generated=False)
            self.assertEqual(path.read_bytes(), b"handwritten\n")

    def test_output_directory_symlink_cannot_write_outside_checkout(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary) / "checkout"
            outside = Path(temporary) / "outside"
            (root / "asm/nonmatchings").mkdir(parents=True)
            outside.mkdir()
            try:
                (root / "asm/nonmatchings/group").symlink_to(outside, target_is_directory=True)
            except OSError as error:
                if getattr(error, "winerror", None) == 1314:
                    self.skipTest("Windows requires symlink creation privileges for this test")
                raise
            manifest = {"generated": [{"path": "asm/nonmatchings/group/func_00100000.s",
                                       "sha256": regeneration.digest(b"baseline\n")}],
                        "retained": []}
            with self.assertRaises(regeneration.RegenerationError):
                regeneration.preflight(root, manifest, require_generated=False)
            self.assertEqual(list(outside.iterdir()), [])


if __name__ == "__main__":
    unittest.main()
