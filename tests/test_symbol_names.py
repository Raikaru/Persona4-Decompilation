"""Contract tests for the curated recovered-name overlay.

config/symbol_addrs.txt is regenerated from the canonical boundary map and only
holds func_<address> placeholders. Real names live in config/symbol_names*.txt,
one file per recovery tool so producers never clobber each other. These tests
pin the rules that keep a bad entry from silently poisoning the symbol table.
"""

from __future__ import annotations

import importlib.util
import json
import unittest
import tempfile
from unittest.mock import patch
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "reconcile_function_boundaries.py"
SPEC = importlib.util.spec_from_file_location("p4_reconcile_names", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
reconcile = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(reconcile)

CANONICAL = {
    int(address, 16)
    for address in json.loads(
        (REPO / "tools" / "slus21782_functions.json").read_text(encoding="utf-8")
    )["windows"]
}


class CuratedNameTests(unittest.TestCase):
    def setUp(self) -> None:
        temporary = tempfile.TemporaryDirectory()
        self.addCleanup(temporary.cleanup)
        self.directory = Path(temporary.name)
        self.temporary = self.directory / "symbol_names.unittest.txt"
        self.address = 0x00100008
        self.canonical = {self.address, 0x00100010}
        self.committed = reconcile.CURATED_NAMES
        patcher = patch.object(reconcile, "CURATED_NAMES", self.directory / "symbol_names.txt")
        patcher.start()
        self.addCleanup(patcher.stop)

    def write(self, text: str) -> None:
        # Binary write: text mode would translate \n to \r\n on Windows.
        self.temporary.write_bytes(text.encode("utf-8"))

    def load(self) -> dict[int, str]:
        return reconcile.curated_names(self.canonical)

    def test_accepts_a_well_formed_entry_and_merges_it(self) -> None:
        self.write(f"UnitTestName = 0x{self.address:08X}; // type:func  evidence: p3:X@00100000\n")
        (self.directory / "symbol_names.txt").write_bytes(
            b"BaseName = 0x00100010; // type:func evidence: p3:B@00100010\n")
        self.assertEqual(self.load(), {self.address: "UnitTestName", 0x00100010: "BaseName"})

    def test_comments_and_blank_lines_are_ignored(self) -> None:
        self.write("// a comment\n\n   \n")
        self.assertEqual(self.load(), {})

    def test_rejects_address_outside_the_canonical_map(self) -> None:
        stray = 0x00999999
        self.write(f"Stray = 0x{stray:08X}; // type:func  evidence: p3:X@1\n")
        with self.assertRaisesRegex(RuntimeError, "not a canonical boundary"):
            self.load()

    def test_rejects_placeholder_name(self) -> None:
        """A func_<hex> 'name' carries no information and would mask a real one."""
        self.write(f"func_{self.address:08x} = 0x{self.address:08X}; // type:func  evidence: p3:X@1\n")
        with self.assertRaisesRegex(RuntimeError, "placeholder"):
            self.load()

    def test_requires_an_evidence_note(self) -> None:
        self.write(f"Unjustified = 0x{self.address:08X}; // type:func\n")
        with self.assertRaisesRegex(RuntimeError, "evidence"):
            self.load()

    def test_rejects_malformed_line(self) -> None:
        self.write("Name -> 0x00100008\n")
        with self.assertRaisesRegex(RuntimeError, "expected"):
            self.load()

    def test_rejects_duplicate_address_within_a_file(self) -> None:
        self.write(
            f"First = 0x{self.address:08X}; // type:func  evidence: p3:A@1\n"
            f"Second = 0x{self.address:08X}; // type:func  evidence: p3:B@2\n"
        )
        with self.assertRaisesRegex(RuntimeError, "duplicate address"):
            self.load()

    def test_rejects_duplicate_name_across_producer_files(self) -> None:
        """Two addresses sharing one symbol would break the link, so it must fail."""
        other = 0x00100010
        committed = self.directory / "symbol_names.txt"
        committed.write_bytes(
            f"Collide = 0x{self.address:08X}; // type:func  evidence: p3:A@1\n".encode()
        )
        self.write(f"Collide = 0x{other:08X}; // type:func  evidence: string:\"b\"\n")
        with self.assertRaisesRegex(RuntimeError, "already used"):
            self.load()

    def test_committed_name_files_are_valid(self) -> None:
        """Whatever is checked in must load; this is the tripwire for hand edits."""
        with patch.object(reconcile, "CURATED_NAMES", self.committed):
            names = reconcile.curated_names(CANONICAL)
        self.assertTrue(names, "committed recovered-name overlay is empty")
        self.assertLessEqual(set(names), CANONICAL)


if __name__ == "__main__":
    unittest.main()
