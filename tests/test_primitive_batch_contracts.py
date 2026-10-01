"""The real queued constructors and consumer share one C object type.

Native32 executes unchanged extracted definitions at O0/O2. An independent
raw-offset oracle checks the allocated header, copied payload, queue handoff,
transformed vertices, state/alpha effects and release lifetime/order. Structural
checks separately reject the old distinct producer types: byte-equivalent
objects alone cannot establish a C effective-type contract.
"""
from pathlib import Path
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import probe_variants
OWNER = ROOT / 'src/sdkPrimitive.c'
FIXTURE = ROOT / 'tests/primitive_batch_fixture.c.in'
FUNCTIONS = ('func_0045e310', 'func_0045e8e0', 'func_0045eb20')


def bodies(source):
    result = {}
    for name in FUNCTIONS:
        start, end = probe_variants.region_for(source, 'FUN_' + name[5:].upper(), name)
        result[name] = source[start:end]
    return result


def types(source):
    first = source.index('typedef struct { u8 c[4]; } PrimByte4;')
    end = source.index('} PrimVertex;', first) + len('} PrimVertex;')
    batch_end = source.index('} PrimBatch;') + len('} PrimBatch;')
    batch_start = source.rindex('typedef struct {', 0, batch_end)
    return source[first:end] + '\n' + source[batch_start:batch_end]


def check_work_contract(source):
    actual = bodies(source)
    layout = types(source)
    assert layout.count('} PrimBatch;') == 1
    assert 'PrimByte4 *colors;' in layout
    assert 'void *positions;' in layout
    assert 'void func_0045e310(void *unused, PrimBatch *work)' in actual[FUNCTIONS[0]]
    assert 'colors = (u8 *)work->colors;' in actual[FUNCTIONS[0]]
    for name in FUNCTIONS[1:]:
        body = actual[name]
        assert 'typedef' not in body
        assert 'PrimBatch *work;' in body
        assert 'void *storage;' in body
        assert 'work = (PrimBatch *)storage;' in body
        assert 'colorBytes + sizeof(PrimBatch) + positionBytes' in body
        assert '*(void (**)(void *, PrimBatch *))(callback + 8) = func_0045e310;' in body
        assert '*(void **)(callback + 0x10) = work;' in body


# Each mutation changes only one real extracted definition. The independent
# model and input construction are never edited by a negative control.
MUTATIONS = {
    'allocation_header': (1, 'sizeof(PrimBatch) + positionBytes', 'sizeof(PrimBatch) + positionBytes + 4'),
    'allocation_alignment': (2, 'positionBytes, 0x40000)', 'positionBytes, 0x20000)'),
    'color_row_stride': (1, 'count * sizeof(PrimByte4)', 'count * sizeof(PrimByte4) - 1'),
    'position_row_stride': (2, 'count * sizeof(PrimFloat2)', 'count * sizeof(PrimFloat2) - 1'),
    'payload_start': (1, '(PrimByte4 *)(work + 1)', '(PrimByte4 *)(work + 2)'),
    'positions_start': (2, '(work->colors + count)', '(work->colors + count + 1)'),
    'stored_depth': (1, 'work->scale = depth;', 'work->scale = depth + 1.0f;'),
    'stored_count': (2, 'work->count = count;', 'work->count = count + 1;'),
    'stored_state': (1, 'work->enabled = preserveState;', 'work->enabled = 0;'),
    'stored_primitive': (2, 'work->primType = primitiveType;', 'work->primType = primitiveType + 1;'),
    'x_offset_width': (1, '(f32)offsetX', '(f32)(s16)offsetX'),
    'x_scale': (2, 'x *= scaleX;', 'x *= scaleY;'),
    'rotation_direction': (1, 'negSine = -sine;', 'negSine = sine;'),
    'transformed_y': (2, 'x * negSine + y * cosine', 'x * cosine + y * negSine'),
    'alpha_store': (2, 'work->alpha = 1;', 'work->alpha = 2;'),
    'nonalpha_store': (1, 'callback = func_00460990();', 'work->alpha = 0;\n    callback = func_00460990();'),
    'callback_slot': (1, '(callback + 8) = func_0045e310;', '(callback + 0xc) = func_0045e310;'),
    'work_slot': (2, '(callback + 0x10) = work;', '(callback + 0x14) = work;'),
    'queue_target': (1, 'func_00460ac0(queue, callback);', 'func_00460ac0(work, callback);'),
    'consumer_color_stride': (0, 'colors + k * 4', 'colors + k * 3'),
    'consumer_color_signedness': (0, '(f32)(u32)color[2]', '(f32)(s8)color[2]'),
    'consumer_depth': (0, 'D_008872F8[0] - scale', 'D_008872F8[0] + scale'),
    'consumer_reciprocal': (0, '1.0f / *(f32 *)', '2.0f / *(f32 *)'),
    'consumer_vertex_count': (0, 'k < count', 'k + 1 < count'),
    'consumer_render_type': (0, 'D_00887310[0](work->primType, out, count);', 'D_00887310[0](work->primType + 1, out, count);'),
    'consumer_alpha_predicate': (0, 'work->alpha == 1', 'work->alpha != 0'),
    'consumer_alpha_live_read': (0, 'u32 table_addr;', 'u32 table_addr;\n    s8 cachedAlpha = work->alpha;'),
    'consumer_saved_state': (0, 'work->enabled;', '0;'),
    'consumer_state_restore': (0, 'D_00887300[0](p[0], saved[j]);', 'D_00887300[0](p[0], saved[0]);'),
    'consumer_release_order': (0, 'release[0](out);\n    release[0](work);', 'release[0](work);\n    release[0](out);'),
    'consumer_missing_release': (0, 'release[0](work);', ''),
}


def fixture_source(mutation=None):
    source = OWNER.read_text()
    actual = bodies(source)
    if mutation is not None:
        index, before, after = MUTATIONS[mutation]
        name = FUNCTIONS[index]
        assert before in actual[name], mutation
        actual[name] = actual[name].replace(before, after)
        if mutation == 'consumer_alpha_live_read':
            actual[name] = actual[name].replace('work->alpha == 1', 'cachedAlpha == 1')
    fixture = FIXTURE.read_text().replace('/* @ACTUAL_TYPES@ */', types(source))
    fixture = fixture.replace('/* @ACTUAL_BODIES@ */', '\n'.join(actual.values()))
    return RUNTIME_C + fixture + ENTRY_C


class PrimitiveBatchSourceContracts(unittest.TestCase):
    def test_one_canonical_work_type_and_raw_storage(self):
        check_work_contract(OWNER.read_text())

    def test_distinct_producer_type_is_rejected(self):
        source = OWNER.read_text()
        layout = types(source)
        start = layout.rindex('typedef struct {')
        duplicate = layout[start:].replace('PrimBatch', 'TypedPrimBatch')
        for name in FUNCTIONS[1:]:
            original = bodies(source)[name]
            changed = original.replace('PrimBatch *work;', duplicate + '\nTypedPrimBatch *work;')
            changed = changed.replace('(PrimBatch *)storage', '(TypedPrimBatch *)storage')
            changed = changed.replace('sizeof(PrimBatch)', 'sizeof(TypedPrimBatch)')
            with self.subTest(producer=name), self.assertRaises(AssertionError):
                check_work_contract(source.replace(original, changed))

    def test_byte_pointer_header_is_rejected(self):
        with self.assertRaises(AssertionError):
            check_work_contract(OWNER.read_text().replace('PrimByte4 *colors;', 'u8 *colors;'))


class PrimitiveBatchNativeContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def execute(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_primitive_batch_') as temporary:
            directory = Path(temporary)
            source = directory / 'fixture.c'
            source.write_text(fixture_source(mutation))
            for level in ('-O0', '-O2'):
                with self.subTest(mutation=mutation, level=level):
                    executable = self.runtime.compile(source, directory / ('fixture' + level), level,
                                                      (ROOT / 'include',))
                    result = self.runtime.run(executable)
                    if mutation is None:
                        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                        self.assertEqual(result.stdout, 'primitive batch: 3200 queued scenarios passed\n')
                    else:
                        self.assertNotEqual(result.returncode, 0, 'negative control passed: ' + mutation)

    def test_actual_constructor_callback_lifetime(self):
        self.execute()

    def test_independent_negative_controls(self):
        for mutation in MUTATIONS:
            self.execute(mutation)


if __name__ == '__main__':
    unittest.main()
