"""Bind the approach speed multiplier to its actual retail GP-relative load."""
from pathlib import Path
import hashlib
import os
import re
import struct
import unittest

ROOT = Path(__file__).resolve().parents[1]
GP = 0x007690F0
ADDRESS = 0x00761450
INSTRUCTION = 0x001A5468
RETAIL_SHA1 = '4eeec0360cf2715535d9f7e52eb69d786fb0158c'


def address():
    source = (ROOT / 'config/symbols_recovered.txt').read_text()
    match = re.search(r'^fGpffff8360 = (0x[0-9a-fA-F]+); // type:data$', source, re.M)
    if match is None:
        raise ValueError('Missing approach speed alias')
    return int(match[1], 16)


def validate(value):
    if value - GP != -0x7CA0:
        raise ValueError('Approach speed alias does not encode retail GP displacement')


class ApproachAlias(unittest.TestCase):
    def test_generated_definition_encodes_retail_displacement(self):
        validate(address())
        self.assertEqual(address(), ADDRESS)

    def test_neighboring_addresses_are_rejected(self):
        for delta in (-4, 4, 0x10000):
            with self.subTest(delta=delta), self.assertRaises(ValueError):
                validate(address() + delta)

    def test_verified_retail_instruction_and_float(self):
        path = Path(os.environ.get('P4_RETAIL_ELF', ROOT / 'orig/SLUS_217.82'))
        if not path.is_file():
            self.skipTest('Verified retail ELF not configured')
        data = path.read_bytes()
        self.assertEqual(hashlib.sha1(data).hexdigest(), RETAIL_SHA1)
        read_word = lambda addr: struct.unpack_from('<I', data, addr - 0x100000 + 0x80)[0]
        self.assertEqual(read_word(INSTRUCTION), 0xC7808360)  # lwc1 f0,-0x7ca0(gp)
        self.assertEqual(read_word(address()), 0x3FB33333)   # 1.4f
        self.assertEqual(read_word(INSTRUCTION + 4), 0x4600A502)  # mul.s f20,f20,f0
