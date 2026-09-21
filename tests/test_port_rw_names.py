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
        # 418 under the relocation-identical rule with the immediate-pair
        # constraint (564 under the earlier all-immediates mask that equated
        # different constants, 482 without the constraint).
        self.assertGreater(len(entries), 380)
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
        # 20 of the truth pairs survive the tighter rule (41 under the
        # looser one); the assertion that matters is zero disagreements.
        self.assertGreaterEqual(len(overlap), 15)
        disagreements = {f"{address:08x}": (name, truth[address])
                         for address, name in overlap.items()
                         if name != truth[address]}
        self.assertEqual({}, disagreements)

    def test_addresses_are_canonical_function_boundaries(self):
        windows = json.loads(
            (REPO / "tools" / "slus21782_functions.json").read_text())["windows"]
        canonical = {int(address, 16) for address in windows}
        self.assertLessEqual(set(produced()), canonical)


class RelocClassifier(unittest.TestCase):
    """The rule defines what may differ between two links of one object."""

    SPANS = [(0x00100000, 0x838A00)]

    def relocs(self, words):
        return sorted(port._reloc_words(words, self.SPANS))

    def relaxed(self, words):
        r = self.relocs(words)
        return [port._relaxed(w) if i in r else w for i, w in enumerate(words)]

    @staticmethod
    def lui(reg, imm):
        return (0x0F << 26) | (reg << 16) | imm

    @staticmethod
    def addiu(rt, rs, imm):
        return (0x09 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)

    @staticmethod
    def lw(rt, base, off):
        return (0x23 << 26) | (base << 21) | (rt << 16) | (off & 0xFFFF)

    def test_immediate_address_pair_relaxes_both_words(self):
        pair = [self.lui(8, 0x0076), self.lw(3, 8, 0x7000)]
        self.assertEqual([0, 1], self.relocs(pair))

    def test_literal_constants_are_not_relocations(self):
        """0x12345678 vs 0x9ABCDEF0: differing large literals are code."""
        a = [self.lui(2, 0x1234), self.addiu(2, 2, 0x5678)]
        b = [self.lui(2, 0x9ABC), self.addiu(2, 2, 0xDEF0)]
        self.assertNotEqual(self.relaxed(a), self.relaxed(b))
        self.assertEqual([], self.relocs(a))

    def test_one_sided_relocation_cannot_match_exact_words(self):
        """A pair relaxed here must not equal a byte-exact load elsewhere."""
        target = [self.lui(9, 0x0076), self.lw(3, 9, 0x7000)]
        exact = [self.lui(9, 0x0076), self.lw(3, 8, 0x7000)]
        self.assertEqual([0, 1], self.relocs(target))
        self.assertEqual([], self.relocs(exact))
        self.assertNotEqual(self.relaxed(target), self.relaxed(exact))

    def test_field_offsets_after_the_pair_are_code(self):
        """`lw 4(r)` after the address is materialised is an ordinary
        access: 4 versus 8 must distinguish two functions."""
        lo = [self.lui(8, 0x0076), self.addiu(8, 8, 0x7000),
              self.addiu(9, 0, 0x40), self.lw(3, 8, 4)]
        hi = [self.lui(8, 0x0076), self.addiu(8, 8, 0x7000),
              self.addiu(9, 0, 0x40), self.lw(3, 8, 8)]
        self.assertNotEqual(self.relaxed(lo), self.relaxed(hi))
        self.assertEqual([0, 1], self.relocs(lo))

    def test_an_intermediate_writer_kills_the_pair(self):
        """lui; ori (same reg); lw - the ori is not %lo, so the lw is code.
        No state survives an instruction that did not consume it."""
        killed = [self.lui(8, 0x0076),
                  (0x0D << 26) | (8 << 21) | (8 << 16) | 0x7000,
                  self.lw(3, 8, 4)]
        self.assertEqual([], self.relocs(killed))

    def test_consecutive_luis_leave_only_the_last_pending(self):
        words = [self.lui(8, 0x0076), self.lui(9, 0x0076),
                 self.lw(3, 9, 0x7000), self.lw(4, 8, 8)]
        self.assertEqual([1, 2], self.relocs(words))

    def test_pairing_cannot_cross_a_branch(self):
        words = [self.lui(8, 0x0076), self.addiu(8, 8, 0x7000),
                 (0x04 << 26) | (0 << 21) | (9 << 16) | 0x0002,
                 self.lw(3, 8, 4)]
        self.assertEqual([0, 1], self.relocs(words))

    def test_gp_relative_accesses_stay_relocatable(self):
        words = [self.addiu(2, 28, 0x5430), self.lw(3, 28, 0x20)]
        self.assertEqual([0, 1], self.relocs(words))

    def test_lui_zero_is_never_pending(self):
        words = [self.lui(0, 0x0076), self.lw(3, 0, 0x7000)]
        self.assertEqual([], self.relocs(words))

    def test_one_sided_relocation_across_different_spans_is_rejected(self):
        """The guard the normalized-word comparison cannot give.

        With different load spans per side, `lui $8,0x0010; lw $3,0($8)`
        is a pair on the target (0x00100000 is loadable there) but plain
        code on the reference (its spans exclude that address). The
        relaxed words come out IDENTICAL - `lui` erases its own immediate
        - so only the relocation-class equality stops a false match.
        """
        target = [self.lui(8, 0x0010), self.lw(3, 8, 0)]
        reference = [self.lui(8, 0x0000), self.lw(3, 8, 0)]
        target_relocs = port._reloc_words(target, self.SPANS)
        ref_relocs = port._reloc_words(reference, [(0x00200000, 0x100000)])
        target_words = [port._relaxed(w) if i in target_relocs else w
                        for i, w in enumerate(target)]
        ref_words = [port._relaxed(w) if i in ref_relocs else w
                     for i, w in enumerate(reference)]
        self.assertEqual(target_words, ref_words)      # bytes cannot tell
        self.assertNotEqual(target_relocs, ref_relocs)  # classes can


if __name__ == "__main__":
    unittest.main()
