from __future__ import annotations

import importlib.util
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "build.py"
SPEC = importlib.util.spec_from_file_location("p4_build", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
build = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(build)


class SectionLayoutTests(unittest.TestCase):
    def test_alignment_uses_absolute_addresses(self) -> None:
        sections = [
            {"idx": 5, "size": 12, "addralign": 8},
            {"idx": 7, "size": 9, "addralign": 8},
            {"idx": 8, "size": 16, "addralign": 16},
        ]
        recovered = {5: 0x005F1878, 7: 0x005F1888, 8: 0x005F18A0}
        self.assertEqual(
            build.recover_concatenated_layout(sections, recovered),
            (0x005F1878, [0, 16, 40], 56),
        )

    def test_rejects_inconsistent_recovered_addresses(self) -> None:
        sections = [
            {"idx": 1, "size": 8, "addralign": 8},
            {"idx": 2, "size": 8, "addralign": 16},
        ]
        self.assertIsNone(
            build.recover_concatenated_layout(
                sections,
                {1: 0x1008, 2: 0x1011},
            )
        )


if __name__ == "__main__":
    unittest.main()
