"""Source-bound, bounded witnesses; never execute the complete PS2 target."""
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
OWNER = ROOT / 'src/promoted/k_fldEvent.c'
sys.path.insert(0, str(ROOT / 'tools'))
from field_movement_source import movement_definition
import verify


def generator(name):
    path = ROOT / 'tests/fixtures/field_movement' / (name + '.py')
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module.fixture_from_source


class FieldMovementTests(unittest.TestCase):
    def test_current_source_remains_promoted(self):
        # The old whole-owner hash belongs to the historical guarded receipt.
        # Actual-source witnesses below survive legitimate codegen changes;
        # this assertion separately prevents a fallback from hiding a regression.
        markers = [m for m in verify.scan_markers(OWNER) if m['addr'] == 0x174e10]
        self.assertEqual(len(markers), 1)
        self.assertEqual(markers[0]['name'], 'func_00174e10')
        self.assertFalse(markers[0]['nonmatching'])
        self.assertFalse(markers[0].get('asm', False))
        self.assertNotRegex(OWNER.read_text(), r'INCLUDE_ASM\([^;]*\bfunc_00174e10\b')
        self.assertTrue(movement_definition(OWNER.read_text()).endswith('}'))

    def test_historical_replay_refuses_promoted_source_before_tool_lookup(self):
        env = {key: value for key, value in os.environ.items() if not key.startswith('P4_')}
        result = subprocess.run([sys.executable, str(ROOT / 'tools/replay_field00174e10.py'),
                                 '--baseline', 'HEAD'], env=env, cwd=ROOT,
                                capture_output=True, text=True, timeout=30)
        self.assertEqual(result.returncode, 1)
        receipt = json.loads(result.stdout)
        self.assertEqual(receipt['status'], 'FAIL')
        self.assertIn('historical guarded replay only', receipt['error'])
        self.assertIn('75f49b54d11d16c713a9fabbdd11469f26a680ae', receipt['error'])
        self.assertIn('verify promoted source', receipt['error'])

    def test_guarded_and_promoted_witnesses_agree(self):
        body = movement_definition(OWNER.read_text())
        guarded = '// FUN_00174E10 NONMATCHING\n#ifdef NON_MATCHING\n' + body + (
            '\n#else\nINCLUDE_ASM("asm/nonmatchings/k_fldEvent", func_00174e10);\n#endif\n')
        promoted = '// FUN_00174E10\n' + body + '\n#pragma pop\n'
        for source in (guarded, promoted):
            self.assertEqual(movement_definition(source), body)
            for name in ('semantic_repairs', 'idle_threshold'):
                self.assertEqual(generator(name)(source), generator(name)(OWNER.read_text()))
            with self.assertRaises(AttributeError):
                generator('idle_threshold')(source.replace('c148 > 360', 'c148 >= 360'))
            with self.assertRaises(AssertionError):
                generator('semantic_repairs')(source.replace(
                    'modelMatrix = *(MovementMatrix *)((u8 *)mdlGetClumpFrame',
                    'modelMatrix = *(MovementMatrix *)((u8 *)wrongFrame'))

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

    @unittest.skipUnless(shutil.which('cc'), 'host compiler unavailable')
    def test_mutated_rounding_rejected_by_runtime_witness(self):
        source = OWNER.read_text()
        self.assertEqual(source.count('f32 remainder = b - multiple;'), 1)
        changed = source.replace('f32 remainder = b - multiple;',
                                 'f32 remainder = b + multiple;')
        with tempfile.TemporaryDirectory(prefix='field-rounding-negative-') as temp:
            fixture = Path(temp) / 'negative.c'
            fixture.write_text(generator('semantic_repairs')(changed))
            for opt in ('-O0', '-O2'):
                exe = Path(temp) / ('negative' + opt)
                subprocess.run(['cc', '-std=c99', opt, '-ffp-contract=off',
                                '-fsanitize=undefined,bounds', '-fno-sanitize-recover=all',
                                str(fixture), '-lm', '-o', str(exe)], check=True,
                               capture_output=True, text=True)
                result = subprocess.run([str(exe)], capture_output=True, text=True)
                self.assertNotEqual(result.returncode, 0)
                self.assertIn('recovered(b)==retail(b)', result.stderr)

    def test_comment_shadows_cannot_hide_threshold_or_provider_mutations(self):
        source = OWNER.read_text()
        changed = source.replace('else if (c148 > 360)',
            '/* else if (c148 > 360) */\n    else if (c148 >= 360)')
        with self.assertRaises(AttributeError):
            generator('idle_threshold')(changed)
        copy = ('        modelMatrix = *(MovementMatrix *)((u8 *)mdlGetClumpFrame'
                '(*(void **)(*(s32 *)(h + 0x18) + 0x164)) + 0x10);')
        self.assertEqual(source.count(copy), 1)
        changed = source.replace(copy, '/*' + copy + '*/\n' + copy.replace('mdlGetClumpFrame', 'wrongFrame'))
        with self.assertRaises(AssertionError):
            generator('semantic_repairs')(changed)

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
