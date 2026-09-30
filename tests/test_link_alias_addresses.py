"""Six inferred data aliases restore C linkage without changing source code."""
from pathlib import Path
import hashlib
import os
import re
import struct
import unittest

ROOT = Path(__file__).resolve().parents[1]
GP = 0x007690F0
RETAIL_SHA1 = '4eeec0360cf2715535d9f7e52eb69d786fb0158c'
ALIASES = {
    'D_007611AC': (0x007611ac, ((0x117c00, 0x80bc),)),
    'D_00762FD8': (0x00762fd8, ((0x15ea5c, 0x9ee8),)),
    'D_00764340': (0x00764340, ((0x15eb2c, 0xb250), (0x15ebe0, 0xb250),)),
    'D_0076439C': (0x0076439c, ((0x15e994, 0xb2ac), (0x15ed6c, 0xb2ac), (0x15eea0, 0xb2ac),)),
    'iGpffffa980': (0x00763a70, ((0x362320, 0xa980),)),
    'iGpffffb528': (0x00764618, ((0x2a118c, 0xb528), (0x2a11c4, 0xb528), (0x2a1244, 0xb528), (0x2a127c, 0xb528),)),
}

def recovered_addresses():
    text = (ROOT / 'config/symbols_recovered.txt').read_text()
    rows = re.findall(r'^([A-Za-z_]\w*) = (0x[0-9a-fA-F]+);', text, re.M)
    return {name: int(value, 16) for name, value in rows}

def from_gp_immediate(immediate):
    return GP + (immediate - 0x10000 if immediate & 0x8000 else immediate)

def validate_aliases(values):
    for name, (_, references) in ALIASES.items():
        for _, immediate in references:
            if values.get(name) != from_gp_immediate(immediate):
                raise ValueError('Incorrect recovered address for ' + name)

class LinkAliasAddresses(unittest.TestCase):
    def test_all_six_generated_definitions_are_present(self):
        values = recovered_addresses()
        validate_aliases(values)
        for name, (address, references) in ALIASES.items():
            with self.subTest(symbol=name):
                self.assertEqual(values[name], address)
                for _, immediate in references:
                    self.assertEqual(values[name], from_gp_immediate(immediate))

    def test_wrong_offsets_are_rejected(self):
        for name, (address, references) in ALIASES.items():
            with self.subTest(symbol=name):
                for delta in (-4, 4):
                    wrong = recovered_addresses()
                    wrong[name] = address + delta
                    with self.assertRaises(ValueError):
                        validate_aliases(wrong)

class RetailLinkAliasEvidence(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        path = Path(os.environ.get('P4_RETAIL_ELF', ROOT / 'orig/SLUS_217.82'))
        if not path.is_file():
            raise unittest.SkipTest('Verified retail ELF not configured')
        cls.data = path.read_bytes()
        if hashlib.sha1(cls.data).hexdigest() != RETAIL_SHA1:
            raise AssertionError('Retail ELF identity mismatch')

    def test_all_twelve_retail_gp_references(self):
        count = 0
        values = recovered_addresses()
        for name, (_, references) in ALIASES.items():
            for address, expected_immediate in references:
                with self.subTest(symbol=name, instruction=hex(address)):
                    word, = struct.unpack_from('<I', self.data, address - 0x00100000 + 0x80)
                    self.assertEqual((word >> 21) & 31, 28)
                    self.assertEqual(word & 0xFFFF, expected_immediate)
                    self.assertEqual(values[name], from_gp_immediate(word & 0xFFFF))
                    count += 1
        self.assertEqual(count, 12)

if __name__ == '__main__':
    unittest.main()
