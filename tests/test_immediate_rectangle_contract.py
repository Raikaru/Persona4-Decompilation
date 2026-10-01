"""Immediate rectangle work-array and callback contracts, with honest type scope.

The unchanged helper body receives a declared Code45Float4 object. Its s32 *
geometry boundary is byte-copied, never dereferenced as s32. A separate replay
runs the real geometry body on real s32[4]/f32[64] objects. This does not close
all authoritative callers' rectangle input types or the actual helper/provider
aliasing boundary. No unsafe scalar-plus-padding version is executed.
"""
from pathlib import Path
import re
import subprocess
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import recovery_quality as Q

OWNER = ROOT / 'src/promoted/code1_0045.c'
FIXTURE = ROOT / 'tests/immediate_rectangle_fixture.c.in'
HELPER = 'func_0045d6e0'
GEOMETRY = 'func_0045ce40'
SUCCESS = ('immediate rectangle: 2304 controlled-boundary scenarios and '
           '6075 typed-provider scenarios passed\n')


def actual_types(text):
    float4 = re.search(r'typedef struct \{\s*f32 v\[4\];\s*\} Code45Float4;', text)
    state = re.search(r'typedef struct Code45RenderState \{.*?\} Code45RenderState;', text, re.S)
    assert float4 is not None and state is not None
    return float4.group(0) + '\n' + state.group(0)


def work_layout_assertions(body, scalar_output=False):
    """Compile the actual local work declaration as a separately named type."""
    match = re.search(r'\bstruct\s*\{.*?\}\s*work\s*;', body, re.S)
    assert match is not None
    declaration = match.group(0)
    if scalar_output:
        # The old scalar plus trailing padding has the same total byte span;
        # only the compiler's actual member extent can establish an array.
        declaration, changes = re.subn(
            r'f32\s+out\s*\[64\]\s*__attribute__\s*\(\(aligned\(16\)\)\)\s*;',
            'f32 out __attribute__((aligned(16)));\n        u8 pad2[0xFC];',
            declaration)
        assert changes == 1
    declaration = 'typedef ' + re.sub(r'\bwork\s*;$', 'ImmediateRectangleWork;', declaration)
    return declaration + r'''
_Static_assert(sizeof(((ImmediateRectangleWork *)0)->out) == 64 * sizeof(f32),
               "immediate output member must contain 64 floats");
_Static_assert(__alignof__(((ImmediateRectangleWork *)0)->out) == 16,
               "immediate output member must be aligned to 16 bytes");
_Static_assert(_Alignof(ImmediateRectangleWork) == 16,
               "immediate work must be aligned to 16 bytes");
_Static_assert(__builtin_offsetof(ImmediateRectangleWork, saved) == 0,
               "immediate saved state must start at offset 0");
_Static_assert(__builtin_offsetof(ImmediateRectangleWork, out) == 32,
               "immediate output must start at offset 32");
_Static_assert(__builtin_offsetof(ImmediateRectangleWork, pos) == 288,
               "immediate rectangle snapshot must start at offset 288");
_Static_assert(sizeof(ImmediateRectangleWork) == 304,
               "immediate work must occupy 304 bytes");
'''


# Controls only replace the indicated source text in the actual helper. They
# preserve bounded, initialized accesses and must exit through CHECK with 1;
# sanitizer traps, crashes, compilation failures and any other exit are failures.
MUTATIONS = {
    'partial_clear': ('memset(work.out, 0, 0x100);', 'memset(work.out, 0, 0xFC);'),
    'nonzero_clear': ('memset(work.out, 0, 0x100);', 'memset(work.out, 1, 0x100);'),
    'missing_clear': ('memset(work.out, 0, 0x100);', ''),
    'wrong_restore_slot': ('p->state, work.saved[j]', 'p->state, work.saved[0]'),
    'state_set_before_get': (
        'D_00887304[0](p->state, (void *)&work.saved[i]);\n            D_00887300[0](p->state, p->val);',
        'D_00887300[0](p->state, p->val);\n            D_00887304[0](p->state, (void *)&work.saved[i]);'),
    'narrow_save_predicate': ('if (arg2 != 0)', 'if ((u8)arg2 != 0)'),
    'wrong_state_value': ('p->state, p->val', 'p->state, p->state'),
    'wrong_sky_state': ('RpSkyRenderStateSet(3, 0x717FB);', 'RpSkyRenderStateSet(3, 0x717FA);'),
    'missing_save_path': ('if (arg2 != 0)', 'if (0)'),
    'wrong_draw_count': ('D_00887310[0](4, work.out, 4);', 'D_00887310[0](4, work.out, 3);'),
    'wrong_draw_kind': ('D_00887310[0](4, work.out, 4);', 'D_00887310[0](3, work.out, 4);'),
    'wrong_draw_buffer': ('D_00887310[0](4, work.out, 4);',
                          'D_00887310[0](4, work.out + 16, 4);'),
    'wrong_last_output_lane': ('D_00887310[0](4, work.out, 4);',
                               'work.out[63] += 1.0f;\n    D_00887310[0](4, work.out, 4);'),
    'wrong_color': ('work.out, arg0, (s32 *)&work.pos, fparg0',
                    'work.out, wrongColor, (s32 *)&work.pos, fparg0'),
    'wrong_depth': ('work.out, arg0, (s32 *)&work.pos, fparg0',
                    'work.out, arg0, (s32 *)&work.pos, fparg0 + 0.25f'),
    'live_rectangle': ('work.out, arg0, (s32 *)&work.pos, fparg0',
                       'work.out, arg0, (s32 *)arg1, fparg0'),
    'late_rectangle_snapshot': ('work.pos = *(Code45Float4 *)arg1;', ''),
    'early_color_snapshot': ('u32 i;', 'u8 colorSnapshot[4];\n    u32 i;'),
    'unexpected_free': ('D_00887310[0](4, work.out, 4);',
                        'D_00887310[0](4, work.out, 4);\n    D_008873EC[0](arg0);'),
    'unexpected_queue': ('D_00887310[0](4, work.out, 4);',
                         'D_00887310[0](4, work.out, 4);\n    func_00460ac0(arg0, arg1);'),
    'unexpected_allocation': ('D_00887310[0](4, work.out, 4);',
                              'D_00887310[0](4, work.out, 4);\n    jtbl_008873E8[0](28, 0x40000);'),
}


def fixture_source(mutation=None):
    text = OWNER.read_text()
    bodies = Q.function_bodies(OWNER)
    helper = bodies[HELPER][1]
    if mutation is not None:
        before, after = MUTATIONS[mutation]
        expected = 2 if mutation in ('missing_save_path', 'narrow_save_predicate') else 1
        assert helper.count(before) == expected, mutation
        helper = helper.replace(before, after)
        if mutation == 'late_rectangle_snapshot':
            helper = helper.replace('memset(work.out, 0, 0x100);',
                                    'work.pos = *(Code45Float4 *)arg1;\n    memset(work.out, 0, 0x100);')
        if mutation == 'early_color_snapshot':
            helper = helper.replace('work.pos = *(Code45Float4 *)arg1;',
                                    'memcpy(colorSnapshot, arg0, 4);\n    work.pos = *(Code45Float4 *)arg1;')
            helper = helper.replace('work.out, arg0, (s32 *)&work.pos, fparg0',
                                    'work.out, colorSnapshot, (s32 *)&work.pos, fparg0')
    # Rename only this separate replay's external symbol to avoid colliding
    # with the controlled geometry boundary used by the immediate helper.
    geometry = bodies[GEOMETRY][1].replace(GEOMETRY + '(', 'actual_rectangle_geometry(', 1)
    fixture = FIXTURE.read_text().replace('/* @ACTUAL_TYPES@ */',
                                         actual_types(text) + '\n' + work_layout_assertions(helper))
    fixture = fixture.replace('/* @ACTUAL_HELPER@ */', helper)
    fixture = fixture.replace('/* @ACTUAL_TYPED_GEOMETRY@ */', geometry)
    # Interpose only the library clear boundary. Its implementation delegates
    # to the same byte loop after validating size, so partial-clear controls
    # fail before any possibly uninitialized output lane can be inspected.
    runtime = RUNTIME_C.replace('void *memset(', 'void *raw_memory_clear(', 1)
    return runtime + fixture + ENTRY_C


def compile_strict(runtime, source, output, level):
    """Same native32 ABI/sanitizers, with strict aliasing explicitly enabled."""
    obj = output.with_suffix('.o')
    command = [runtime.compiler, '--target=i386-linux-gnu', '-m32', '-msse2', '-mfpmath=sse',
               '-std=c11', level, '-ffreestanding', '-fno-builtin', '-fno-pie',
               '-fno-stack-protector', '-ffp-contract=off', '-fstrict-aliasing',
               '-fsanitize=undefined,bounds', '-fsanitize-trap=all',
               '-Werror=implicit-function-declaration', '-Werror=incompatible-pointer-types',
               '-Werror=int-conversion', '-I' + str(ROOT / 'include'),
               '-c', str(source), '-o', str(obj)]
    result = subprocess.run(command, capture_output=True, text=True, timeout=60)
    if result.returncode:
        raise RuntimeError('Strict native32 compilation failed:\n' + result.stdout + result.stderr)
    result = subprocess.run([*runtime.linker, '-m', 'elf_i386', '-e', '_start', '-o',
                             runtime.execution_path(output), runtime.execution_path(obj)],
                            capture_output=True, text=True, timeout=60)
    if result.returncode:
        raise RuntimeError('Strict native32 linking failed:\n' + result.stdout + result.stderr)
    header = output.read_bytes()[:20]
    assert header[:5] == b'\x7fELF\x01' and header[5] == 1 and header[18:20] == b'\x03\0'
    return output


class ImmediateRectangleSourceContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def compile_layout(self, scalar_output):
        text = OWNER.read_text()
        body = Q.function_bodies(OWNER)[HELPER][1]
        source_text = (RUNTIME_C + '#include "type.h"\n' + actual_types(text)
                       + '\n' + work_layout_assertions(body, scalar_output)
                       + '\nint main(void) { return 0; }\n' + ENTRY_C)
        with tempfile.TemporaryDirectory(prefix='p4_immediate_rectangle_layout_') as temporary:
            directory = Path(temporary)
            source = directory / 'layout.c'
            source.write_text(source_text)
            for level in ('-O0', '-O2'):
                with self.subTest(level=level, scalar_output=scalar_output):
                    if scalar_output:
                        with self.assertRaisesRegex(RuntimeError,
                                                    'immediate output member must contain 64 floats'):
                            self.runtime.compile(source, directory / ('layout' + level), level,
                                                 (ROOT / 'include',))
                    else:
                        self.runtime.compile(source, directory / ('layout' + level), level,
                                             (ROOT / 'include',))
        # This declaration-only proof deliberately never executes either form.

    def test_compiler_evaluated_work_layout(self):
        self.compile_layout(scalar_output=False)

    def test_scalar_plus_padding_fails_member_size_assertion(self):
        self.compile_layout(scalar_output=True)


class ImmediateRectangleNativeContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def execute(self, mutation=None, strict=False):
        with tempfile.TemporaryDirectory(prefix='p4_immediate_rectangle_') as temporary:
            directory = Path(temporary)
            source = directory / 'fixture.c'
            source.write_text(fixture_source(mutation))
            for level in ('-O0', '-O2'):
                with self.subTest(mutation=mutation, level=level, strict=strict):
                    if strict:
                        executable = compile_strict(self.runtime, source, directory / ('fixture' + level), level)
                    else:
                        executable = self.runtime.compile(source, directory / ('fixture' + level), level,
                                                          (ROOT / 'include',))
                    result = self.runtime.run(executable)
                    if mutation is None:
                        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                        self.assertEqual(result.stdout, SUCCESS)
                    else:
                        self.assertEqual(result.returncode, 1,
                                         'control must fail through CHECK: ' + str(result))
                        self.assertRegex(result.stdout, r'^line \d+, scenario \d+: .+\n$')
                        self.assertEqual(result.stderr, '')

    def test_actual_helper_and_separate_typed_provider(self):
        self.execute()

    def test_strict_aliasing_positive_replay(self):
        self.execute(strict=True)

    def test_independent_normal_exit_controls(self):
        for mutation in MUTATIONS:
            self.execute(mutation)


if __name__ == '__main__':
    unittest.main()
