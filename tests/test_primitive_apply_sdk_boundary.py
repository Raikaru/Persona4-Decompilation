"""Execute the exact caller with an explicitly controlled opaque SDK boundary.

The boundary supplies flags before the real Scale body reads them. This does
not execute retail's indeterminate word or prove the full provider is defined.
Scalar Multiply models data dependencies only; exact EE bytes are a separate
target gate. Source extraction leaves the game expressions unchanged.
"""
from pathlib import Path
import tempfile
import unittest
from native32_support import RUNTIME_C, ENTRY_C
from test_title_fade_contract import runtime

ROOT = Path(__file__).resolve().parents[1]
OWNER = ROOT / 'src/Graphics/primitive.c'
SCALE_OWNER = ROOT / 'src/renderware/plcore/bamatrix.c'
HEADER = ROOT / 'include/rw/inc/rwplcore.h'
FIXTURE = ROOT / 'tests/primitive_apply_sdk_boundary_fixture.c.in'


def parts():
    source = OWNER.read_text()
    header = HEADER.read_text()
    provider = SCALE_OWNER.read_text()
    def typedef(name):
        end = source.index('} ' + name + ';') + len('} ' + name + ';')
        return source[source.rindex('typedef struct', 0, end):end]
    def macro(name):
        start = header.index('#define ' + name)
        end = header.index('\n', start)
        while header[end - 1] == '\\':
            end = header.index('\n', end + 1)
        return header[start:end]
    marker = source.index('// FUN_00480940\n')
    start = source.index('void func_00480940(', marker)
    end = source.index('\n}\n', start) + 2
    body = source[start:end]
    start = provider.index('RwMatrix *\nRwMatrixScale(')
    end = provider.index('\n}\n', start) + 2
    scale = provider[start:end].replace('RwMatrixScale(', 'real_RwMatrixScale(', 1)
    return {
        'RUNTIME': RUNTIME_C, 'ENTRY': ENTRY_C, 'TARGET': body, 'SCALE': scale,
        'TYPES': '\n'.join(typedef(n) for n in ('RwV3d', 'RwMatrix', 'PrimQuaternion', 'PrimInterpData')),
        'MACROS': '\n'.join(macro(n) for n in ('RwMatrixSetIdentityMacro', 'RwV3dScaleMacro',
                                             'rwMatrixSetFlags', 'rwMatrixGetFlags')),
    }


def check_source_contract(body):
    assert body.startswith('void func_00480940(void* result, void* frame)')
    assert '    buffer.flags =' not in body
    assert 'RwMatrixMultiply((RwMatrix*)result, &buffer, &matrix);' in body
    assert '((RwMatrix*)result)->pos = *(const RwV3d*)&input->values[0];' in body
    assert '((RwMatrix*)result)->flags = ((RwMatrix*)result)->flags & 0xfffdffff;' in body
    assert body.index('RwMatrixScale(') < body.index('RwMatrixMultiply(') < body.index('->pos =')


MUTATIONS = {
    'provider_call_order': ('TARGET',
        '    RwMatrixScale(&buffer, (const RwV3d*)&input->values[3], 0);\n    RwMatrixMultiply((RwMatrix*)result, &buffer, &matrix);',
        '    RwMatrixMultiply((RwMatrix*)result, &buffer, &matrix);\n    RwMatrixScale(&buffer, (const RwV3d*)&input->values[3], 0);'),
    'quaternion_cross_sign': ('TARGET', 'matrix.right.y = (xy + wz) * 2.0f;', 'matrix.right.y = (xy - wz) * 2.0f;'),
    'scale_offset': ('TARGET', '&input->values[3]', '&input->values[2]'),
    'multiply_operand_order': ('TARGET', 'result, &buffer, &matrix);', 'result, &matrix, &buffer);'),
    'rotation_flags': ('TARGET', 'matrix.flags = 3;', 'matrix.flags = 7;'),
    'early_translation_snapshot': ('TARGET', '    x = input->quat.x;',
        '    RwV3d savedTranslation = *(const RwV3d*)&input->values[0];\n    x = input->quat.x;'),
    'translation_component': ('TARGET', '->pos = *(const RwV3d*)&input->values[0];', '->pos = *(const RwV3d*)&input->values[1];'),
    'scale_erases_persistent_bits': ('SCALE', 'rwMatrixGetFlags(matrix) &', '0 &'),
    'scale_touches_padding': ('SCALE', 'matrix->right.x = scale->x;', 'matrix->right.x = scale->x; matrix->pad1 = 0;'),
    'scale_wrong_mask': ('SCALE', 'rwMATRIXTYPEORTHONORMAL));', '1));'),
}


def fixture(mutation=None):
    p = parts()
    if mutation is not None:
        key, before, after = MUTATIONS[mutation]
        assert before in p[key], (mutation, before)
        p[key] = p[key].replace(before, after, 1)
    if mutation == 'early_translation_snapshot':
        p['TARGET'] = p['TARGET'].replace('->pos = *(const RwV3d*)&input->values[0];', '->pos = savedTranslation;')
    result = FIXTURE.read_text()
    for key, value in p.items():
        result = result.replace('@' + key + '@', value)
    return result


class PrimitiveApplySdkBoundary(unittest.TestCase):
    def run_fixture(self, optimization, mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_primitive_apply_') as directory:
            directory = Path(directory)
            source = directory / 'fixture.c'
            source.write_text(fixture(mutation))
            runner = runtime()
            return runner.run(runner.compile(source, directory / 'fixture', optimization))

    def test_source_contract(self):
        source = OWNER.read_text()
        self.assertNotIn('INCLUDE_ASM("asm/nonmatchings/primitive", func_00480940);', source)
        body = parts()['TARGET']
        check_source_contract(body)
        # The final mask is dead under these real provider flags. Preserve its
        # retail instruction structurally, without inventing nonzero outputs.
        with self.assertRaises(AssertionError):
            check_source_contract(body.replace('0xfffdffff', '0xffffffff'))
        with self.assertRaises(AssertionError):
            check_source_contract(body.replace('void* result, void* frame', 'RwMatrix* result, void* frame'))

    def test_seeded_sdk_boundary(self):
        for optimization in ('-O0', '-O2'):
            with self.subTest(optimization=optimization):
                result = self.run_fixture(optimization)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, 'matrix cases 368585 passed\n')
                print(optimization, 'opaque SDK boundary:', result.stdout.strip())

    def test_negative_controls(self):
        for optimization in ('-O0', '-O2'):
            for mutation in MUTATIONS:
                with self.subTest(optimization=optimization, mutation=mutation):
                    result = self.run_fixture(optimization, mutation)
                    self.assertNotEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertIn('scenario', result.stdout)
                    print(optimization, mutation, 'rejected:', result.stdout.strip())


if __name__ == '__main__':
    unittest.main()
