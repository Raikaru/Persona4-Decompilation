from __future__ import annotations

import importlib.util
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]


def load_module(name: str, path: Path):
    spec = importlib.util.spec_from_file_location(name, path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


consolidate = load_module("p4_consolidate", REPO / "tools" / "consolidate_sources.py")
verify = load_module("p4_verify_units", REPO / "tools" / "verify.py")


class ConsolidationTests(unittest.TestCase):
    def test_address_suffix_maps_to_module_path(self) -> None:
        path = REPO / "src" / "Battle" / "btlUnit_00198300.c"
        self.assertEqual(
            consolidate.module_path(path),
            REPO / "src" / "Battle" / "btlUnit.c",
        )

    def test_guarded_units_are_selected_independently(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "group.c"
            path.write_text(
                """/* Consolidated Persona 4 source units. */
#if defined(P4_UNIT_00100000)
// FUN_00100000
void func_00100000(void) { }
#endif /* P4_UNIT_00100000 */
#if defined(P4_UNIT_00100010)
// FUN_00100010
void func_00100010(void) { }
#endif /* P4_UNIT_00100010 */
""",
                encoding="utf-8",
            )
            self.assertEqual(verify.source_units(path), [0x00100000, 0x00100010])
            self.assertEqual(verify.scan_markers(path, 0x00100010)[0]["addr"], 0x00100010)
            self.assertEqual(len(verify.scan_markers(path, 0x00100000)), 1)

    def test_current_grouped_tree_has_no_address_suffixed_sources(self) -> None:
        self.assertEqual(consolidate.check(), 0)
        sources = [
            path for path in (REPO / "src").rglob("*.c")
            if not consolidate.is_generated(path)
        ]
        self.assertFalse(any(consolidate.ADDRESS_SUFFIX.search(path.name) for path in sources))
        self.assertEqual(
            sum(len(verify.scan_markers(path)) for path in sources),
            873,
        )


if __name__ == "__main__":
    unittest.main()
