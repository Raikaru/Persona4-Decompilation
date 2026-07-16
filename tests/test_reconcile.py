from __future__ import annotations

import importlib.util
import json
import tempfile
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "reconcile_function_boundaries.py"
SPEC = importlib.util.spec_from_file_location("p4_reconcile", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
reconcile = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(reconcile)


class ReconciliationHelpersTests(unittest.TestCase):
    def test_reads_instruction_address_after_glabel(self) -> None:
        assembly = """glabel func_00102030
    /* 2030 00102030 0800E003 */  jr $31
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "code.s"
            path.write_text(assembly, encoding="utf-8")
            self.assertEqual(reconcile.splat_entries(path), {0x00102030})

    def test_windows_cover_segment_through_final_byte(self) -> None:
        windows = reconcile.make_windows([0x1008, 0x1018, 0x1030], 0x1008, 0x1040)
        self.assertEqual(windows, {0x1008: 0x10, 0x1018: 0x18, 0x1030: 0x10})
        self.assertEqual(sum(windows.values()), 0x1040 - 0x1008)

    def test_rejects_unaligned_boundary(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "invalid function window"):
            reconcile.make_windows([0x1008, 0x1019], 0x1008, 0x1020)


    def test_function_map_rows_assign_sources_and_grouped_c_assembly(self) -> None:
        source_path = Path("src") / "Battle" / "example.c"
        assembly_path = Path("build") / "function_sources" / "code1_0010.c"
        windows = {0x1000: 0x10, 0x1010: 0x20}
        markers = {
            0x1000: [(source_path, {"line": 7, "name": "FUN_00001000"})],
        }
        assembly_owners = {0x1010: assembly_path}
        self.assertEqual(
            reconcile.function_map_rows(windows, markers, assembly_owners),
            [
                f"00001000 {0x10:>6} MAPPED   {source_path}",
                f"00001010     32 MAPPED   {assembly_path}",
            ],
        )

    def test_assembly_words_select_exact_window(self) -> None:
        assembly = """glabel func_00001000
    /* 0 00001000 00000000 */ nop
    /* 4 00001004 00000000 */ nop
    /* 8 00001008 00000000 */ nop
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "code.s"
            path.write_text(assembly, encoding="utf-8")
            self.assertEqual(
                reconcile.assembly_words(path, 0x1000, 0x8),
                ["00000000", "00000000"],
            )
class CanonicalMapTests(unittest.TestCase):
    def test_committed_map_covers_both_code_segments(self) -> None:
        target = json.loads((REPO / "config" / "target.json").read_text(encoding="utf-8"))
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}

        self.assertEqual(function_map["function_count"], 13080)
        self.assertEqual(len(windows), 13080)
        for segment_name, expected_count in (("code1", 13071), ("code2", 9)):
            start, end = reconcile.segment_bounds(target, segment_name)
            selected = {address: size for address, size in windows.items() if start <= address < end}
            if segment_name == "code1":
                start = int(target["elf"]["entry"], 0)
            self.assertEqual(len(selected), expected_count)
            self.assertEqual(sum(selected.values()), end - start)

    def test_shared_code2_windows_reach_segment_end(self) -> None:
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}
        expected = {
            0x0070C850: 0x6B0,
            0x0070CF00: 0x1E0,
            0x0070D0E0: 0xD0,
            0x0070D1B0: 0x388,
            0x0070D538: 0x108,
            0x0070D640: 0x140,
            0x0070D780: 0x1A0,
            0x0070D920: 0x48,
            0x0070D968: 0x7D8,
        }
        self.assertEqual({address: windows[address] for address in expected}, expected)

    def test_source_markers_are_unique_and_canonical(self) -> None:
        markers = reconcile.source_markers()
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}

        self.assertTrue(markers)
        self.assertTrue(all(len(entries) == 1 for entries in markers.values()))
        self.assertTrue(set(markers).issubset(windows))

    def test_every_canonical_boundary_gets_an_owner(self) -> None:
        target = json.loads((REPO / "config" / "target.json").read_text(encoding="utf-8"))
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}
        markers = reconcile.source_markers()
        code2_start, _code2_end = reconcile.segment_bounds(target, "code2")

        assembly_owners = reconcile.assembly_owner_paths(windows, markers, code2_start, write=False)
        rows = reconcile.function_map_rows(windows, markers, assembly_owners)
        self.assertEqual(len(rows), len(windows))
        self.assertEqual(set(assembly_owners), set(windows) - set(markers))
        self.assertTrue(all(owner.suffix == ".c" for owner in assembly_owners.values()))
        self.assertLess(len(set(assembly_owners.values())), len(assembly_owners))
        self.assertTrue(all(" MAPPED   " in row for row in rows))


if __name__ == "__main__":
    unittest.main()
