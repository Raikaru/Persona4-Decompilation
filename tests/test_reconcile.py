from __future__ import annotations

import importlib.util
import json
import tempfile
import sys
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

        # 13,077 boundaries the Splat control-flow scan and Ghidra find on their
        # own, plus every curated override: DATA_REACHABLE_ENTRIES (each backed by
        # a retail pointer site), EPILOGUE_SEPARATED_ENTRIES and
        # JAL_REACHABLE_ENTRIES. The old figure here was 13,080 + 4 because three
        # boundaries sat in the committed map with no declaration at all, which is
        # exactly what made the map unregenerable; they are now declared, so the
        # base is the true scan result. Bump these only alongside a documented
        # entry whose evidence the tests below re-check against the retail image.
        expected_total = (
            13077
            + len(reconcile.DATA_REACHABLE_ENTRIES)
            + len(reconcile.EPILOGUE_SEPARATED_ENTRIES)
            + len(reconcile.JAL_REACHABLE_ENTRIES)
            - len(reconcile.BRANCH_LANDING_ENTRIES)
        )
        self.assertEqual(expected_total, 13085)
        self.assertEqual(function_map["function_count"], expected_total)
        self.assertEqual(len(windows), expected_total)
        for segment_name, expected_count in (("code1", expected_total - 9), ("code2", 9)):
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
        """Every marker is a canonical boundary, or a declared exception.

        Three declared exceptions exist, each validated against the retail image
        by its own test: `DATA_REACHABLE_ENTRIES` (reachable only through a data
        pointer), `EPILOGUE_SEPARATED_ENTRIES` (no pointer, but the preceding
        function ends in a complete epilogue) and `JAL_REACHABLE_ENTRIES` (real
        entries whose first instruction is a `b` into their own condition check,
        which the scan mistakes for the branch landing point).
        """
        markers = reconcile.source_markers()
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}

        self.assertTrue(markers)
        self.assertTrue(all(len(entries) == 1 for entries in markers.values()))
        known = (
            set(windows)
            | set(reconcile.DATA_REACHABLE_ENTRIES)
            | set(reconcile.EPILOGUE_SEPARATED_ENTRIES)
            | set(reconcile.JAL_REACHABLE_ENTRIES)
        )
        orphans = sorted(f"{address:08X}" for address in set(markers) - known)
        self.assertEqual(orphans, [], f"markers outside the canonical map: {orphans}")

    def test_data_reachable_entries_are_backed_by_a_retail_pointer(self) -> None:
        """Each curated override must be a real entry the control-flow scan cannot see.

        Guards two failure modes: a mistyped pointer site (the address recorded in
        the tool does not actually hold the entry), and an override that has become
        redundant because Splat now finds the entry itself.

        The map IS regenerable now, so every override must actually appear in the
        committed map. That was previously impossible: the control-flow scan does
        not reproduce 0x0027A340, and dropping it widened func_0027a2d0's window
        from 112 to 128 and broke a byte-exact match. 0x0027A340 now has a
        documented entry in `EPILOGUE_SEPARATED_ENTRIES`, so the assertion below
        is tightened to require presence in the map.
        """
        import struct

        target = json.loads((REPO / "config" / "target.json").read_text(encoding="utf-8"))
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}
        elf = REPO / "orig" / target["elf"]["filename"]
        if not elf.exists():
            self.skipTest(f"retail ELF not present at {elf}")

        sys.path.insert(0, str(REPO / "tools"))
        import verify

        retail = verify.RetailElf(str(elf), target, function_map["sha1"])
        splat = reconcile.splat_entries(REPO / "asm" / "code1.s")

        for address, evidence in reconcile.DATA_REACHABLE_ENTRIES.items():
            with self.subTest(address=f"{address:08X}"):
                word = struct.unpack("<I", retail.bytes_at(evidence["pointer"], 4))[0]
                self.assertEqual(
                    word,
                    address,
                    f"pointer site {evidence['pointer']:08X} holds {word:08X}, not {address:08X}",
                )
                self.assertNotIn(address, splat, "override is redundant; Splat finds this entry")
                self.assertIn(
                    address,
                    windows,
                    "override is missing from the committed map; regenerate it",
                )
                self.assertGreater(windows[address], 0)

    def test_epilogue_separated_entries_follow_a_complete_epilogue(self) -> None:
        """These entries have no pointer evidence, so the epilogue IS the evidence.

        A `jr $ra` plus its delay slot immediately before the address means the
        preceding function's body ends there and the bytes at the address cannot
        belong to it. Without that, an address here would silently invent a
        boundary and corrupt every window after it.
        """
        import struct

        target = json.loads((REPO / "config" / "target.json").read_text(encoding="utf-8"))
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}
        elf = REPO / "orig" / target["elf"]["filename"]
        if not elf.exists():
            self.skipTest(f"retail ELF not present at {elf}")

        sys.path.insert(0, str(REPO / "tools"))
        import verify

        retail = verify.RetailElf(str(elf), target, function_map["sha1"])
        splat = reconcile.splat_entries(REPO / "asm" / "code1.s")

        self.assertTrue(reconcile.EPILOGUE_SEPARATED_ENTRIES)
        for address in sorted(reconcile.EPILOGUE_SEPARATED_ENTRIES):
            with self.subTest(address=f"{address:08X}"):
                jr, delay = struct.unpack("<II", retail.bytes_at(address - 8, 8))
                self.assertEqual(
                    jr, 0x03E00008, f"{address - 8:08X} is not `jr $ra` (got {jr:08X})"
                )
                self.assertEqual(
                    delay, 0x00000000, f"{address - 4:08X} is not a nop delay slot"
                )
                self.assertNotIn(
                    address, splat, "override is redundant; Splat finds this entry"
                )
                self.assertNotIn(
                    address,
                    reconcile.DATA_REACHABLE_ENTRIES,
                    "has pointer evidence; belongs in DATA_REACHABLE_ENTRIES",
                )
                self.assertIn(address, windows)

    def test_jal_reachable_entries_are_called_from_the_retail_image(self) -> None:
        """These are real functions the scan mis-locates, so the callers ARE the proof.

        Counting the `jal` sites guards the failure that produced this category: an
        earlier revision allow-listed these two addresses as "false splits that are
        never called" and let them drop out of the map, which removed the only
        definition of symbols six translation units reference and failed the link
        with `Undefined: func_00272b00`.
        """
        import struct

        target = json.loads((REPO / "config" / "target.json").read_text(encoding="utf-8"))
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}
        elf = REPO / "orig" / target["elf"]["filename"]
        if not elf.exists():
            self.skipTest(f"retail ELF not present at {elf}")

        image = elf.read_bytes()
        self.assertTrue(reconcile.JAL_REACHABLE_ENTRIES)
        for address, evidence in sorted(reconcile.JAL_REACHABLE_ENTRIES.items()):
            with self.subTest(address=f"{address:08X}"):
                word = struct.pack("<I", 0x0C000000 | ((address >> 2) & 0x03FFFFFF))
                sites = image.count(word)
                self.assertEqual(
                    sites,
                    evidence["jal_sites"],
                    f"{address:08X} has {sites} jal sites, not {evidence['jal_sites']}",
                )
                self.assertGreater(sites, 0, "no caller: this is not a real entry")
                self.assertIn(address, windows)

    @unittest.skipUnless((REPO / "asm" / "code1.s").is_file(),
                         "needs splat output (make split); absent on toolchain-free CI")
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
