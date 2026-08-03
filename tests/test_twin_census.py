"""The twin census claims "the donor already has this function's C" -- an
expensive claim, because a wave gets dispatched on it.

Two failure directions matter. Masking too little makes real twins invisible
(the same source compiled against different data addresses looks different).
Masking too much invents twins out of unrelated functions that merely share a
shape, which sends an agent chasing a port that cannot exist. These tests pin
which instruction fields are allowed to differ, and pin that the census counts
functions to port rather than candidate pairs.
"""

import json
import struct
import sys
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import twin_census as tc  # noqa: E402


def word(op, rs=0, rt=0, imm=0):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def special(funct, rs=0, rt=0, rd=0):
    return (rs << 21) | (rt << 16) | (rd << 11) | funct


def code(*words):
    return b"".join(struct.pack("<I", w) for w in words)


ADDIU, LW, BEQ, J, JAL, COP1 = 0x09, 0x23, 0x04, 0x02, 0x03, 0x11
ADDU = 0x21


def make_elf(chunks: dict[int, bytes], vaddr=0x00100000) -> bytes:
    """Minimal little-endian ELF with one PT_LOAD covering `chunks`."""
    body_start = 0x80
    end = max(addr + len(data) for addr, data in chunks.items())
    image = bytearray(end - vaddr)
    for addr, data in chunks.items():
        image[addr - vaddr : addr - vaddr + len(data)] = data
    header = bytearray(body_start)
    header[0:4] = b"\x7fELF"
    struct.pack_into("<I", header, 0x1C, 0x34)  # e_phoff
    struct.pack_into("<H", header, 0x2A, 0x20)  # e_phentsize
    struct.pack_into("<H", header, 0x2C, 1)  # e_phnum
    struct.pack_into(
        "<IIIII", header, 0x34, 1, body_start, vaddr, vaddr, len(image)
    )
    return bytes(header + image)


class StructuralMaskTests(unittest.TestCase):
    """Which fields are allowed to differ between the two games."""

    def test_immediate_is_masked_because_data_addresses_differ(self):
        # The same `lw $v0, off($a0)` against a different global.
        self.assertEqual(
            tc.structural_word(word(LW, 4, 2, 0x1234)),
            tc.structural_word(word(LW, 4, 2, 0x8888)),
        )

    def test_registers_are_not_masked_on_immediate_forms(self):
        # Register allocation is the signal we are matching on; it must survive.
        self.assertNotEqual(
            tc.structural_word(word(LW, 4, 2, 0)),
            tc.structural_word(word(LW, 4, 3, 0)),
        )

    def test_opcode_is_not_masked(self):
        self.assertNotEqual(
            tc.structural_word(word(LW, 4, 2, 0)),
            tc.structural_word(word(ADDIU, 4, 2, 0)),
        )

    def test_special_form_keeps_every_field(self):
        # No immediate exists to differ, so nothing may be dropped.
        self.assertEqual(tc.structural_word(special(ADDU, 1, 2, 3)), special(ADDU, 1, 2, 3))
        self.assertNotEqual(
            tc.structural_word(special(ADDU, 1, 2, 3)),
            tc.structural_word(special(ADDU, 1, 2, 4)),
        )

    def test_jump_target_is_masked_but_jal_and_j_stay_distinct(self):
        self.assertEqual(
            tc.structural_word(word(J) | 0x1000), tc.structural_word(word(J) | 0x2000)
        )
        self.assertNotEqual(tc.structural_word(word(J)), tc.structural_word(word(JAL)))

    def test_branch_displacement_is_masked_registers_kept(self):
        self.assertEqual(
            tc.structural_word(word(BEQ, 4, 5, 0x10)),
            tc.structural_word(word(BEQ, 4, 5, 0x40)),
        )
        self.assertNotEqual(
            tc.structural_word(word(BEQ, 4, 5, 0)),
            tc.structural_word(word(BEQ, 4, 6, 0)),
        )

    def test_cop_branch_displacement_masked_but_arithmetic_body_kept(self):
        bc1t = (COP1 << 26) | (0x08 << 21)
        self.assertEqual(
            tc.structural_word(bc1t | 0x0010), tc.structural_word(bc1t | 0x0040)
        )
        add_s = (COP1 << 26) | (0x10 << 21) | 0x1234
        self.assertNotEqual(
            tc.structural_word(add_s), tc.structural_word(add_s ^ 0x0F)
        )


class FingerprintTests(unittest.TestCase):
    def test_same_shape_different_constants_is_one_fingerprint(self):
        a = code(word(ADDIU, 29, 29, -0x40), word(LW, 4, 2, 0x10), word(J) | 0x111)
        b = code(word(ADDIU, 29, 29, -0x40), word(LW, 4, 2, 0x99), word(J) | 0x222)
        self.assertEqual(tc.fingerprint(a), tc.fingerprint(b))

    def test_different_register_allocation_is_a_different_fingerprint(self):
        a = code(word(LW, 4, 2, 0))
        b = code(word(LW, 4, 3, 0))
        self.assertNotEqual(tc.fingerprint(a), tc.fingerprint(b))

    def test_raw_similarity_counts_whole_word_identity(self):
        a = code(1, 2, 3, 4)
        self.assertEqual(tc.raw_similarity(a, a), 1.0)
        self.assertEqual(tc.raw_similarity(a, code(1, 2, 3, 9)), 0.75)
        self.assertEqual(tc.raw_similarity(b"", b""), 0.0)


class DonorPortabilityTests(unittest.TestCase):
    """A donor match is only useful if it is C we are allowed to copy."""

    def classify(self, src):
        lines = src.strip("\n").split("\n")
        return tc.classify_donor(*tc.donor_body(lines, 1))

    def test_plain_c_is_portable(self):
        self.assertEqual(
            self.classify("int f(int a)\n{\n    return a + 1;\n}"), "portable"
        )

    def test_mwcc_asm_function_is_not_portable(self):
        # Hand-written assembly is what INCLUDE_ASM already gives us.
        self.assertEqual(
            self.classify("asm void f(int a)\n{\n    nop\n    jr $ra\n}"),
            "asm_function",
        )

    def test_assembler_directives_mark_an_asm_body(self):
        self.assertEqual(
            self.classify("void f(void)\n{\n  .set noreorder\n  .word 0x1480fff4\n}"),
            "asm_function",
        )

    def test_inline_asm_for_ordinary_computation_is_banned_here(self):
        # decomp_lint H009 permits COP2/VU0 only.
        self.assertEqual(
            self.classify(
                'void f(int a)\n{\n    __asm__ ("sd %0, 0($sp)" : : "r"(a));\n}'
            ),
            "banned_asm",
        )

    def test_inline_asm_touching_vu0_is_allowed(self):
        self.assertEqual(
            self.classify(
                'void f(void *p)\n{\n    __asm__ ("lqc2 $vf1, 0(%0)" : : "r"(p));\n}'
            ),
            "vu0_asm",
        )

    def test_body_stops_at_the_closing_brace(self):
        lines = "int f(void)\n{\n    return 1;\n}\nint g(void)\n{\n    return 2;\n}".split("\n")
        _decl, body = tc.donor_body(lines, 1)
        self.assertIn("return 1;", body)
        self.assertNotIn("return 2;", body)

    def test_asm_double_underscore_volatile_is_detected(self):
        """The spelling that slipped through and cost an agent a wasted port:
        rw/rwplcore.c writes `asm __volatile__` with .word directives inside
        string operands, so neither `asm volatile` nor a line-anchored `.word`
        match."""
        src = (
            "int f()\n{\n"
            '    asm __volatile__(".set noreorder ;"\n'
            '                     ".word 0x00451818 ;"\n'
            '                     "jr $31");\n}'
        )
        self.assertEqual(self.classify(src), "asm_function")

    def test_bare_asm_block_is_detected(self):
        # Inline asm inside an otherwise-C body, so `banned_asm` rather than
        # `asm_function`. Either way it is not portable.
        self.assertEqual(
            self.classify('int f()\n{\n    asm ("nop");\n}'), "banned_asm"
        )

    def test_a_variable_named_asmsomething_is_not_asm(self):
        # `\basm\b` must not fire on an identifier that merely starts with asm.
        self.assertEqual(
            self.classify("int f(int asmCount)\n{\n    return asmCount + 1;\n}"),
            "portable",
        )


class FindTwinsTests(unittest.TestCase):
    """End-to-end joins over synthetic images."""

    def setUp(self):
        holder = __import__("tempfile").TemporaryDirectory()
        self.addCleanup(holder.cleanup)
        self.tmp = Path(holder.name)
        # Target and donor share a shape but differ in the masked immediate.
        self.shape_own = code(word(ADDIU, 29, 29, -0x10), word(LW, 4, 2, 0x10))
        self.shape_donor = code(word(ADDIU, 29, 29, -0x10), word(LW, 4, 2, 0x20))
        self.other = code(word(ADDIU, 29, 29, -0x10), special(ADDU, 1, 2, 3))

    def _write(self, name, payload):
        path = self.tmp / name
        path.write_text(json.dumps(payload), encoding="utf-8")
        return path

    def _census(self, own_status="ASM", own_file="src/a.c", donor_status="MATCH",
                donor_extra=None, own_size=8):
        own_elf = self.tmp / "own.elf"
        own_elf.write_bytes(make_elf({0x00100000: self.shape_own}))
        chunks = {0x00100000: self.shape_donor}
        if donor_extra:
            chunks.update(donor_extra)
        donor_elf = self.tmp / "donor.elf"
        donor_elf.write_bytes(make_elf(chunks))
        donor_windows = {"%08x" % a: len(d) for a, d in chunks.items()}
        donor_results = [
            {"addr": "%08x" % a, "name": "donor_%08x" % a,
             "file": "src/d.c", "line": 5, "status": donor_status}
            for a in chunks
        ]
        return tc.find_twins(
            report=self._write("own.json", {"results": [
                {"addr": "00100000", "name": "func_00100000", "file": own_file,
                 "line": 1, "status": own_status}]}),
            windows=self._write("ownw.json", {"windows": {"00100000": own_size}}),
            elf=str(own_elf),
            donor_report=self._write("donor.json", {"results": donor_results}),
            donor_windows=self._write("donorw.json", {"windows": donor_windows}),
            donor_elf=str(donor_elf),
            min_size=8,
        )

    def test_matches_across_images_despite_differing_immediates(self):
        rows = self._census()
        self.assertEqual([r["donor_addr"] for r in rows], ["00100000"])
        self.assertEqual(rows[0]["raw_similarity"], 0.5)

    def test_already_matched_target_is_not_offered(self):
        self.assertEqual(self._census(own_status="MATCH"), [])

    def test_third_party_target_is_excluded(self):
        self.assertEqual(self._census(own_file="src/rw/rwplcore.c"), [])

    def test_donor_must_have_byte_exact_c_to_be_portable(self):
        self.assertEqual(self._census(donor_status="NONMATCHING"), [])

    def test_size_mismatch_is_not_a_twin(self):
        # A donor function of a different length cannot be the same function.
        self.assertEqual(self._census(own_size=4), [])

    def test_duplicate_shapes_collapse_to_one_row_with_a_count(self):
        # Same shape at a second donor address: one row to port, not two.
        rows = self._census(donor_extra={0x00100100: self.shape_donor})
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]["donor_alternatives"], 1)

    def test_unrelated_shape_is_not_reported(self):
        rows = self._census(donor_extra={0x00100100: self.other})
        self.assertEqual([r["donor_addr"] for r in rows], ["00100000"])


if __name__ == "__main__":
    unittest.main()
