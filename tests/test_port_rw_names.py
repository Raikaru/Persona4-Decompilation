from __future__ import annotations

import importlib.util
import json
import re
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
SPEC = importlib.util.spec_from_file_location("p4_port_rw_names",
                                              REPO / "tools" / "port_rw_names.py")
assert SPEC is not None and SPEC.loader is not None
port = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(port)

PRODUCED = REPO / "config" / "symbol_names.vendor.txt"
TRUTH = REPO / "docs" / "sky2" / "known_names.json"
LINE = re.compile(r"^(\w+) = 0x([0-9A-F]{8}); // type:func  evidence: (.+)$")


def produced() -> dict[int, tuple[str, str]]:
    out = {}
    for line in PRODUCED.read_text(encoding="utf-8").splitlines():
        match = LINE.match(line)
        if match:
            out[int(match[2], 16)] = (match[1], match[3])
    return out


class MaskWord(unittest.TestCase):
    """The mask defines what "the same object code" means across two links."""

    def test_jump_target_and_immediate_are_blanked_but_the_opcode_is_not(self):
        jal_low = (0x03 << 26) | 0x000100
        jal_high = (0x03 << 26) | 0x00BEEF
        self.assertEqual(port.fid.mask_word(jal_low), port.fid.mask_word(jal_high))
        j_low = (0x02 << 26) | 0x000100
        self.assertNotEqual(port.fid.mask_word(jal_low), port.fid.mask_word(j_low))

    def test_register_operands_survive_the_mask(self):
        """Masking an immediate must not also erase which registers are used.

        `addiu $4, $5, X` and `addiu $6, $7, X` are different code and have
        to stay distinguishable, or short functions all collapse together.
        """
        addiu_a = (0x09 << 26) | (5 << 21) | (4 << 16) | 0x20
        addiu_b = (0x09 << 26) | (7 << 21) | (6 << 16) | 0x20
        self.assertNotEqual(port.fid.mask_word(addiu_a), port.fid.mask_word(addiu_b))

    def test_a_register_only_instruction_is_compared_whole(self):
        addu = (0x00 << 26) | (5 << 21) | (6 << 16) | (4 << 11) | 0x21
        self.assertEqual(addu, port.fid.mask_word(addu))


class GeneratedFile(unittest.TestCase):
    def test_every_line_carries_its_reference_and_width(self):
        entries = produced()
        self.assertGreater(len(entries), 500)
        for address, (name, evidence) in entries.items():
            self.assertRegex(evidence, r"masked-exact over \d+ words, sole claimant")
            self.assertTrue(name.isidentifier(), name)

    def test_no_name_is_claimed_twice(self):
        """A name written at two addresses would fail the producer contract,
        and more importantly would mean the rule identified neither."""
        names = [name for name, _evidence in produced().values()]
        self.assertEqual(len(names), len(set(names)))

    def test_it_agrees_with_every_name_the_repo_already_proves(self):
        """The overlap with known names is the measurement, so it is the
        thing that must not silently regress."""
        truth = {int(address, 16): entry["name"]
                 for address, entry in json.loads(TRUTH.read_text()).items()}
        entries = produced()
        overlap = {address: entries[address][0]
                   for address in entries if address in truth}
        # Fewer than the 35 the rule itself scores: the file omits addresses
        # another producer already names, and some of the truth set is theirs.
        self.assertGreaterEqual(len(overlap), 25)
        disagreements = {f"{address:08x}": (name, truth[address])
                         for address, name in overlap.items()
                         if name != truth[address]}
        self.assertEqual({}, disagreements)

    def test_addresses_are_canonical_function_boundaries(self):
        windows = json.loads(
            (REPO / "tools" / "slus21782_functions.json").read_text())["windows"]
        canonical = {int(address, 16) for address in windows}
        self.assertLessEqual(set(produced()), canonical)


if __name__ == "__main__":
    unittest.main()
