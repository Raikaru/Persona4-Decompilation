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

        # This retail boundary census changes only with independently justified
        # additions/removals, never to accommodate lost source markers.
        expected_total = 13102
        self.assertEqual(function_map["function_count"], expected_total)
        self.assertEqual(len(windows), expected_total)
        for segment_name, expected_count in (("code1", expected_total - 9), ("code2", 9)):
            start, end = reconcile.segment_bounds(target, segment_name)
            selected = {address: size for address, size in windows.items() if start <= address < end}
            if segment_name == "code1":
                start = int(target["elf"]["entry"], 0)
            self.assertEqual(len(selected), expected_count)
            cursor = start
            for address, size in sorted(selected.items()):
                self.assertEqual(address, cursor, f"gap or overlap at {address:08X}")
                self.assertGreater(size, 0)
                self.assertEqual(address % 4, 0)
                self.assertEqual(size % 4, 0)
                cursor = address + size
            self.assertEqual(cursor, end)

    def test_source_markers_are_unique_and_canonical(self) -> None:
        """Every canonical boundary has exactly one source owner, even without Splat."""
        markers = reconcile.source_markers()
        function_map = json.loads((REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8"))
        windows = {int(address, 16): size for address, size in function_map["windows"].items()}

        duplicates = {
            f"{address:08X}": [str(path) for path, _marker in entries]
            for address, entries in markers.items() if len(entries) != 1
        }
        self.assertEqual(duplicates, {}, f"duplicate source owners: {duplicates}")
        missing = sorted(f"{address:08X}" for address in set(windows) - set(markers))
        extra = sorted(f"{address:08X}" for address in set(markers) - set(windows))
        self.assertEqual(missing, [], f"canonical boundaries without source owners: {missing}")
        self.assertEqual(extra, [], f"source owners outside the canonical map: {extra}")

    def test_data_reachable_entries_are_backed_by_a_retail_pointer(self) -> None:
        """Each curated boundary must have independent retail pointer evidence.

        Splat consumes config/symbol_addrs.txt, which reconciliation populates
        with these boundaries. Its output is not independent discovery evidence:
        a subsequent split is expected to contain the curated entries.

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

        for address, evidence in reconcile.DATA_REACHABLE_ENTRIES.items():
            with self.subTest(address=f"{address:08X}"):
                word = struct.unpack("<I", retail.bytes_at(evidence["pointer"], 4))[0]
                self.assertEqual(
                    word,
                    address,
                    f"pointer site {evidence['pointer']:08X} holds {word:08X}, not {address:08X}",
                )
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

        self.assertTrue(reconcile.EPILOGUE_SEPARATED_ENTRIES)
        for address in sorted(reconcile.EPILOGUE_SEPARATED_ENTRIES):
            with self.subTest(address=f"{address:08X}"):
                # Walk back over any inter-function zero padding to the last
                # real instruction, then require it to be a register jump with
                # a nop delay slot. Accepting `jr $rX` and not only `jr $ra` is
                # deliberate: a tail-jump stub ends `lw $v0,...; jr $v0; nop`
                # and terminates its function just as definitively as a return,
                # and 003C54A0 and 003E8790 are both exactly that shape. The
                # padding walk is bounded so a runaway scan cannot manufacture
                # evidence from an unrelated function further back.
                terminator = None
                for offset in range(4, 68, 4):
                    word = struct.unpack("<I", retail.bytes_at(address - offset, 4))[0]
                    if word != 0x00000000:
                        terminator = (address - offset, word)
                        break
                self.assertIsNotNone(
                    terminator, f"only padding precedes {address:08X}; no epilogue evidence"
                )
                jr_at, jr = terminator
                is_register_jump = (jr >> 26) == 0 and (jr & 0x3F) == 0x08
                # An unconditional backward branch is also a complete
                # terminator: func_00101350 ends `b .-3` and func_00466e80
                # ends `b` back to its own loop head, so nothing can fall
                # through into the next function. Encoding is BEQ $zero,$zero
                # with a negative displacement.
                is_self_loop = (jr >> 26) == 0x04 and ((jr >> 16) & 0x3FF) == 0 \
                    and (jr & 0x8000) != 0
                self.assertTrue(
                    is_register_jump or is_self_loop,
                    f"{jr_at:08X} is neither a register jump nor an infinite "
                    f"branch (got {jr:08X})",
                )
                delay = struct.unpack("<I", retail.bytes_at(jr_at + 4, 4))[0]
                self.assertEqual(
                    delay, 0x00000000, f"{jr_at + 4:08X} is not a nop delay slot"
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



if __name__ == "__main__":
    unittest.main()


class CompilerUnitsTests(unittest.TestCase):
    """config/compiler_units.txt names real units and well-formed keys."""

    def test_compiler_units_point_at_existing_units(self) -> None:
        sys.path.insert(0, str(REPO / "tools"))
        import verify

        units = verify.compiler_units()
        self.assertTrue(units, "config/compiler_units.txt should list at least one unit")
        for unit, key in units.items():
            with self.subTest(unit=unit):
                self.assertTrue((REPO / unit).is_file(), f"{unit} is not a file")
                self.assertRegex(key, r"^[A-Za-z0-9][\w.\-]*$")
