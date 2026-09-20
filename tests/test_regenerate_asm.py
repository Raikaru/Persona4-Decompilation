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
            (root / "asm/nonmatchings/group").symlink_to(outside, target_is_directory=True)
            manifest = {"generated": [{"path": "asm/nonmatchings/group/func_00100000.s",
                                       "sha256": regeneration.digest(b"baseline\n")}],
                        "retained": []}
            with self.assertRaises(regeneration.RegenerationError):
                regeneration.preflight(root, manifest, require_generated=False)
            self.assertEqual(list(outside.iterdir()), [])


if __name__ == "__main__":
    unittest.main()
