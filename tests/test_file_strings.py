"""Unit tests for tools/file_strings.py's __FILE__ string recovery.

Two required behaviors are pinned here because they are the decoder's whole
correctness story (see the negative-control section of the tool's docstring):
the lui/addiu pairing must REJECT a mismatched-register sequence, and
asserting functions must be DEDUPED per function even when one function
references the same string several times.
"""
from __future__ import annotations

import importlib.util
import struct
import unittest
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MODULE_PATH = REPO / "tools" / "file_strings.py"
SPEC = importlib.util.spec_from_file_location("p4_file_strings", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
file_strings = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(file_strings)

BASE = 0x00100000
GP = 0x007690F0

LUI = 0x0F << 26
ADDIU = 0x09 << 26
ORI = 0x0D << 26
LW = 0x23 << 26
JAL = 0x03 << 26
NOP = 0x00000000


def lui(rt: int, hi: int) -> int:
    return LUI | (rt << 16) | (hi & 0xFFFF)


def addiu(rt: int, rs: int, lo: int) -> int:
    return ADDIU | (rs << 21) | (rt << 16) | (lo & 0xFFFF)


def ori(rt: int, rs: int, lo: int) -> int:
    return ORI | (rs << 21) | (rt << 16) | (lo & 0xFFFF)


def lw(rt: int, rs: int, lo: int) -> int:
    return LW | (rs << 21) | (rt << 16) | (lo & 0xFFFF)


def jal(rs: int = 0) -> int:
    return JAL | (rs & 0x03FFFFFF)


def pack(words: list[int]) -> bytes:
    return struct.pack("<%dI" % len(words), *words)


def pair(hi: int, lo: int) -> int:
    """Effective lui/addiu address: the low half sign-extends."""
    return (hi << 16) + (lo - 0x10000 if lo & 0x8000 else lo)


def decode(words: list[int], string_addrs: set[int], gp: int = GP) -> list[tuple[int, int]]:
    """Decode one window's words; the window starts at BASE."""
    return file_strings.decode_references(
        pack(words), BASE, string_addrs, gp, window_starts={BASE}
    )


def make_image(
    windows: dict[int, int], bodies: dict[int, list[int]], data: bytes = b""
) -> bytes:
    """Byte image from {address: size}, {address: [words]} and a data blob.

    The data blob is appended right after the last window end, so it is the
    complement of the windows (exactly what the tool scans).
    """
    order = sorted(windows)
    code_end = order[-1] + windows[order[-1]]
    image = bytearray(code_end - BASE + len(data))
    for address, words in bodies.items():
        offset = address - BASE
        image[offset : offset + 4 * len(words)] = pack(words)
    image[code_end - BASE :] = data
    return bytes(image)


class DecoderTests(unittest.TestCase):
    def test_lui_addiu_rejects_mismatched_register(self) -> None:
        """lui $2 followed by addiu $3,$3,lo must NOT pair: $3 has no base."""
        hi, lo = 0x0053, 0xDA00
        addr = pair(hi, lo)
        words = [lui(2, hi), addiu(3, 3, lo)]
        self.assertEqual(decode(words, {addr}), [])

    def test_lui_addiu_second_lui_does_not_steal_pending(self) -> None:
        """A second lui must not replace $2's pending base for the addiu."""
        hi_a, lo_a = 0x0053, 0xDA00
        hi_b = 0x0060
        addr_a = pair(hi_a, lo_a)
        addr_b = pair(hi_b, lo_a)
        words = [lui(2, hi_a), lui(3, hi_b), addiu(2, 2, lo_a)]
        self.assertEqual(decode(words, {addr_a, addr_b}), [(BASE + 8, addr_a)])

    def test_overwrite_invalidates_pending_base(self) -> None:
        """ori $2,$0,0 overwrites the lui base, so the later addiu emits nothing."""
        hi, lo = 0x0053, 0xDA00
        addr = pair(hi, lo)
        words = [lui(2, hi), ori(2, 0, 0), addiu(2, 2, lo)]
        self.assertEqual(decode(words, {addr}), [])

    def test_load_into_base_register_invalidates_pending(self) -> None:
        """A load into $2 clobbers the pending base; the addiu must not pair."""
        hi, lo = 0x0053, 0xDA00
        addr = pair(hi, lo)
        words = [lui(2, hi), lw(2, 0, 0), addiu(2, 2, lo)]
        self.assertEqual(decode(words, {addr}), [])

    def test_jal_clears_pending(self) -> None:
        """Pending bases do not survive a call."""
        hi, lo = 0x0053, 0xDA00
        addr = pair(hi, lo)
        words = [lui(2, hi), jal(0), addiu(2, 2, lo)]
        self.assertEqual(decode(words, {addr}), [])

    def test_lui_addiu_valid_pair_emits(self) -> None:
        hi, lo = 0x0053, 0xDA00
        addr = pair(hi, lo)
        words = [lui(2, hi), addiu(2, 2, lo)]
        self.assertEqual(decode(words, {addr}), [(BASE + 4, addr)])

    def test_lui_load_store_displacement_form(self) -> None:
        """lui $2,hi; lw $3,lo($2) is also a valid reference shape."""
        hi, lo = 0x0053, 0xDA00
        addr = pair(hi, lo)
        words = [lui(2, hi), lw(3, 2, lo)]
        self.assertEqual(decode(words, {addr}), [(BASE + 4, addr)])

    def test_gp_relative_reference(self) -> None:
        addr = GP + 0x1234
        words = [lw(3, 28, 0x1234)]
        self.assertEqual(decode(words, {addr}), [(BASE, addr)])
        words = [addiu(3, 28, 0x1234)]
        self.assertEqual(decode(words, {addr}), [(BASE, addr)])

    def test_non_matching_address_emits_nothing(self) -> None:
        hi, lo = 0x0053, 0xDA00
        words = [lui(2, hi), addiu(2, 2, lo)]
        self.assertEqual(decode(words, {pair(hi, lo) + 4}), [])


class ScanTests(unittest.TestCase):
    def test_scan_finds_only_source_filenames(self) -> None:
        data = (
            b"datCalc.c\0"
            b"battle.h\0"
            b"=CcmpStatus.c\0"
            b"not a file\0"
            b"../../rofs_cvfs.c\0"
            b"foo.cpp\0"
        )
        found = file_strings.scan_filename_strings(data, base_addr=0x500000)
        self.assertEqual(
            found,
            {
                0x500000: "datCalc.c",
                0x50002C: "../../rofs_cvfs.c",
                0x50003E: "foo.cpp",
            },
        )


class ExtractTests(unittest.TestCase):
    def _fixture(self):
        size = 32  # 8 words per window
        windows = {BASE + i * size: size for i in range(5)}
        # data blob starts right after the 5 windows (0xA0 bytes of code)
        hi, lo = 0x0010, 0x00A0
        alpha_addr = (hi << 16) + lo
        beta_addr = alpha_addr + 4
        bodies = {
            BASE: [lui(2, hi), addiu(2, 2, lo)] + [NOP] * 6,
            BASE + size: [NOP] * 8,
            BASE + 2 * size: [lui(2, hi), addiu(2, 2, lo + 12)] + [NOP] * 6,
            BASE + 3 * size: [NOP] * 8,
            BASE + 4 * size: [lui(2, hi), addiu(2, 2, lo)] + [NOP] * 6,
        }
        # "alpha.c\0" is 8 bytes; pad to 12 so beta.c starts at lo + 12.
        data = b"alpha.c\0" + b"\0" * 4 + b"beta.c\0" + b"\0" * 16
        image = make_image(windows, bodies, data)
        return windows, image, {alpha_addr: "alpha.c", beta_addr: beta_addr}

    def test_per_function_dedupe(self) -> None:
        """Two references inside ONE function count as one asserter."""
        size = 32
        windows = {BASE: size, BASE + size: size}
        hi, lo = 0x0010, 0x0040
        addr = (hi << 16) + lo
        bodies = {
            # window 1: addiu AND a 0-displacement load both hit the string.
            BASE: [lui(2, hi), addiu(2, 2, lo), lw(3, 2, 0)] + [NOP] * 5,
            # window 2: one reference.
            BASE + size: [lui(2, hi), addiu(2, 2, lo)] + [NOP] * 6,
        }
        image = make_image(windows, bodies, b"alpha.c\0" + b"\0" * 16)
        report = file_strings.extract(image, windows, GP)
        record = next(f for f in report["files"] if f["file"] == "alpha.c")
        self.assertEqual(record["asserting_count"], 2)
        self.assertEqual(record["span_length"], 2)
        self.assertEqual(record["gaps"], [1])

    def test_extract_span_silent_members_and_singleton_rejection(self) -> None:
        windows, image, _ = self._fixture()
        report = file_strings.extract(image, windows, GP)
        self.assertEqual(report["strings_found"], 2)
        self.assertEqual(report["strings_referenced"], 2)
        alpha = next(f for f in report["files"] if f["file"] == "alpha.c")
        self.assertTrue(alpha["kept"])
        self.assertEqual(alpha["asserting_count"], 2)
        self.assertEqual(alpha["span_first_index"], 0)
        self.assertEqual(alpha["span_last_index"], 4)
        self.assertEqual(alpha["span_length"], 5)
        self.assertEqual(alpha["gaps"], [4])
        self.assertEqual(alpha["silent_count"], 3)
        self.assertEqual(
            alpha["silent_members"],
            [f"{BASE + 32:08x}", f"{BASE + 64:08x}", f"{BASE + 96:08x}"],
        )
        beta = next(f for f in report["files"] if f["file"] == "beta.c")
        self.assertFalse(beta["kept"])
        self.assertIn(
            "beta.c", [entry["file"] for entry in report["trimmed_or_rejected"]]
        )
        self.assertEqual(report["named_tus"], 1)
        self.assertEqual(report["functions_covered"], 5)


if __name__ == "__main__":
    unittest.main()
