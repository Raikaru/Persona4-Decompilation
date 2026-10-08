"""Source-bound, bounded witnesses; never execute the complete PS2 target."""
import hashlib
import importlib.util
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
OWNER = ROOT / 'src/promoted/k_fldEvent.c'
SOURCE_SHA256 = '0ba2684b49c11e82bb3a8138b2221a8f5cc4b369125225812d67cf5bca91f232'


def generator(name):
    path = ROOT / 'tests/fixtures/field_movement' / (name + '.py')
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module.fixture_from_source


class FieldMovementTests(unittest.TestCase):
    def test_reviewed_source_binding_and_guard(self):
        source = OWNER.read_bytes()
        self.assertEqual(hashlib.sha256(source).hexdigest(), SOURCE_SHA256)
        self.assertIn(b'// FUN_00174E10 NONMATCHING\n#ifdef NON_MATCHING', source)
        self.assertIn(b'#else\nINCLUDE_ASM("asm/nonmatchings/k_fldEvent", func_00174e10);\n#endif', source)

    @unittest.skipUnless(shutil.which('cc'), 'host compiler unavailable')
    def test_extracted_bounded_semantics(self):
        source = OWNER.read_text()
        expected = {'semantic_repairs': 'checks=14102 legacy_rounding_rejections=11',
                    'idle_threshold': 'checks=1065549'}
        with tempfile.TemporaryDirectory(prefix='field-movement-host-') as temp:
            for name, output in expected.items():
                fixture = Path(temp) / (name + '.c')
                fixture.write_text(generator(name)(source))
                for opt in ('-O0', '-O2'):
                    with self.subTest(name=name, opt=opt):
                        exe = Path(temp) / (name + opt)
                        subprocess.run(['cc', '-std=c99', opt, '-ffp-contract=off',
                                        '-fsanitize=undefined,bounds', '-fno-sanitize-recover=all',
                                        str(fixture), '-lm', '-o', str(exe)], check=True,
                                       capture_output=True, text=True)
                        result = subprocess.run([str(exe)], check=True, capture_output=True, text=True)
                        self.assertEqual(result.stdout.strip(), output)

    def test_bad_threshold_rejected(self):
        with self.assertRaises(AttributeError):
            generator('idle_threshold')(OWNER.read_text().replace('c148 > 360', 'c148 >= 360'))

    def test_bad_matrix_copy_rejected(self):
        with self.assertRaises(AssertionError):
            generator('semantic_repairs')(OWNER.read_text().replace(
                'modelMatrix = *(MovementMatrix *)((u8 *)mdlGetClumpFrame',
                'modelMatrix = *(MovementMatrix *)((u8 *)wrongFrame'))


if __name__ == '__main__':
    unittest.main()
