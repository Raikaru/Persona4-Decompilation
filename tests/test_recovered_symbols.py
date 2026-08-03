"""Curated data addresses must stay evidence-backed and must survive regeneration.

`tools/recover_symbols.py` rewrites `config/symbols_recovered.txt` from scratch on
every run, so anything hand-appended there disappears the next time anyone runs
it. That is silent: the per-function verifier masks relocations, so the build
still reproduces both retail hashes and only the count of linked C objects drops.
It happened -- four translation units lost their link that way.

`config/symbol_data_addrs.txt` is the durable home for the addresses the
relocation scan genuinely cannot derive. These tests keep it honest: every entry
must parse, must carry an `evidence:` note, and must actually reach the generated
output. The one entry whose evidence is checkable from the retail image is
re-checked here rather than trusted.
"""

import re
import struct
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

CURATED = REPO / "config" / "symbol_data_addrs.txt"
GENERATED = REPO / "config" / "symbols_recovered.txt"
RETAIL = REPO / "orig" / "SLUS_217.82"

LOAD_OFFSET = 0x80
LOAD_VRAM = 0x00100000

ENTRY = re.compile(
    r"^\s*(?P<name>[A-Za-z_]\w*)\s*=\s*(?P<addr>0x[0-9A-Fa-f]{8})\s*;"
    r"\s*//\s*type:data\b(?P<rest>.*)$"
)


def entries():
    out = []
    for number, line in enumerate(
            CURATED.read_text(encoding="utf-8").splitlines(), 1):
        if not line.strip() or line.lstrip().startswith("//"):
            continue
        match = ENTRY.match(line)
        assert match, f"{CURATED}:{number}: malformed: {line!r}"
        out.append((number, match.group("name"),
                    int(match.group("addr"), 16), match.group("rest")))
    return out


class CuratedDataAddressTests(unittest.TestCase):
    def test_file_parses_and_is_not_empty(self) -> None:
        self.assertTrue(entries(), "curated data address file is empty")

    def test_every_entry_carries_evidence(self) -> None:
        for number, name, _addr, rest in entries():
            with self.subTest(name=name):
                self.assertIn("evidence:", rest,
                              f"{CURATED}:{number}: {name} has no evidence: note")

    def test_no_duplicate_names(self) -> None:
        names = [name for _n, name, _a, _r in entries()]
        self.assertEqual(len(names), len(set(names)))

    def test_addresses_are_word_aligned(self) -> None:
        for _number, name, addr, _rest in entries():
            with self.subTest(name=name):
                self.assertEqual(addr % 4, 0, f"{name} is not word aligned")

    def test_curated_entries_reach_the_generated_output(self) -> None:
        """The whole point: regeneration must not drop them again."""
        generated = GENERATED.read_text(encoding="utf-8")
        for _number, name, addr, _rest in entries():
            with self.subTest(name=name):
                self.assertIn(f"{name} = {addr:#010x}; // type:data", generated)

    def test_loader_rejects_an_entry_with_no_evidence(self) -> None:
        import recover_symbols

        original = recover_symbols.CURATED_DATA
        try:
            import tempfile

            with tempfile.TemporaryDirectory() as tmp:
                path = Path(tmp) / "curated.txt"
                path.write_text("D_00760000 = 0x00760000; // type:data\n",
                                encoding="utf-8")
                recover_symbols.CURATED_DATA = path
                with self.assertRaises(SystemExit):
                    recover_symbols.curated_data_addresses()
        finally:
            recover_symbols.CURATED_DATA = original

    def test_loader_rejects_a_malformed_entry(self) -> None:
        import recover_symbols

        original = recover_symbols.CURATED_DATA
        try:
            import tempfile

            with tempfile.TemporaryDirectory() as tmp:
                path = Path(tmp) / "curated.txt"
                path.write_text("this is not an entry\n", encoding="utf-8")
                recover_symbols.CURATED_DATA = path
                with self.assertRaises(SystemExit):
                    recover_symbols.curated_data_addresses()
        finally:
            recover_symbols.CURATED_DATA = original


@unittest.skipUnless(RETAIL.exists(), "retail executable not present")
class RetailEvidenceTests(unittest.TestCase):
    """Re-check the evidence that can be checked, instead of trusting the note."""

    def word_at(self, address: int) -> int:
        data = RETAIL.read_bytes()
        offset = LOAD_OFFSET + (address - LOAD_VRAM)
        return struct.unpack("<I", data[offset:offset + 4])[0]

    def test_gPI_really_holds_pi(self) -> None:
        by_name = {name: addr for _n, name, addr, _r in entries()}
        self.assertIn("gPI", by_name)
        word = self.word_at(by_name["gPI"])
        self.assertEqual(word, 0x40490FDB)
        self.assertAlmostEqual(
            struct.unpack("<f", struct.pack("<I", word))[0], 3.14159274, places=6
        )

    def test_aliases_agree_on_the_address(self) -> None:
        by_name = {name: addr for _n, name, addr, _r in entries()}
        self.assertEqual(by_name["gPI"], by_name["D_007613EC"])

    def test_every_curated_address_is_inside_the_image(self) -> None:
        size = RETAIL.stat().st_size - LOAD_OFFSET
        for _number, name, addr, _rest in entries():
            with self.subTest(name=name):
                offset = addr - LOAD_VRAM
                self.assertTrue(0 <= offset < size,
                                f"{name} at {addr:#010x} is outside the image")


if __name__ == "__main__":
    unittest.main()
