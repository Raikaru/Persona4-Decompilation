"""Native 32-bit contract for the extracted title tail, not the full renderer.

The final counter gate, locals, union, declarations, and no-argument getter body
come from live source. A strictly typed renderer recorder consumes eight floats.
The getter's GP read is instrumented to observe order and optionally mutate the
state/source after the caller's snapshots. The actual renderer's NULL-matrix
path has a pre-existing uninitialized identity.flags read and is NOT executed.
"""
from pathlib import Path
import os
import re
import shlex
import shutil
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
from measure_guarded import extract_guarded_body
from test_btl_motion_override_contract import definition
from native32_support import (ENTRY_C, RUNTIME_C, Native32Runtime,
                              Native32Unavailable, native32_runtime)


def braced(text, start):
    end = text.index('{', start) + 1
    depth = 1
    while depth:
        depth += (text[end] == '{') - (text[end] == '}')
        end += 1
    return text[start:end]


def parts():
    text = (ROOT / 'src/promoted/code1_0012.c').read_text()
    body = extract_guarded_body(text, 'FUN_001265A0', 'func_001265a0')
    gate = 'if (M2C_FIELD(temp_20, s32 *, 0x2C) > 0) {'
    start = body.rindex(gate)
    block = braced(body, start)
    assert body[start + len(block):].strip() == '}'
    renderer = re.search(r'(?m)^extern s32 func_00366c70\([^;]+;', text)[0]
    assert renderer == ('extern s32 func_00366c70(s32 x, s32 y, f32 z, s32 width, '
                        's32 height, s32 rgb, s32 alpha, s32 mode, s16 centerX, '
                        's16 centerY, struct RwMatrixTag *matrix, s32 texture, f32 (*uv)[2]);')
    getter_prototype = re.search(r'extern s32 func_00401b80\(void\);', body)[0]
    uv = re.search(r'union \{ u32 words\[8\]; f32 pairs\[4\]\[2\]; \} fadeUv;', body)[0]
    source = re.search(r'extern u32 D_005E56B0\[8\];', body)[0]
    assert source
    names = ('fadeUvSource', 'fadeUvDestination', 'fadeAlpha', 'fadeTexture',
             'temp_2_27', 'temp_3_22', 'temp_3_23', 'var_4_17', 'var_4_18', 'temp_20')
    locals_ = '\n'.join(re.search(r'(?m)^    (?:s32|u32) \*?' + name + r';', body)[0]
                        for name in names)
    getter = definition('src/rw/basky.c', 'func_00401b80')
    assert re.fullmatch(r's32 func_00401b80\(void\)\s*\{\s*return iGpffffb900;\s*\}', getter)
    return dict(BLOCK=block, UV_DECLARATION=uv, LOCALS=locals_,
                RENDERER_PROTOTYPE=renderer, GETTER_PROTOTYPE=getter_prototype, GETTER=getter)


MUTATIONS = {
    'source_byte_stride': ('fadeUvSource += 2;', 'fadeUvSource = (u32 *)((u8 *)fadeUvSource + 4);'),
    'destination_byte_stride': ('fadeUvDestination += 2;', 'fadeUvDestination = (u32 *)((u8 *)fadeUvDestination + 4);'),
    'copy_short': ('var_4_17 = 4;', 'var_4_17 = 3;'),
    'pair_components_swapped': ('fadeUvDestination[0] = temp_3_22;\n            fadeUvDestination[1] = temp_2_27;',
                                'fadeUvDestination[0] = temp_2_27;\n            fadeUvDestination[1] = temp_3_22;'),
    'pair_order_swapped': ('temp_3_22 = fadeUvSource[0];\n            temp_2_27 = fadeUvSource[1];',
                           'temp_3_22 = D_005E56B0[((4 - var_4_17) ^ 1) * 2];\n            temp_2_27 = D_005E56B0[((4 - var_4_17) ^ 1) * 2 + 1];'),
    'copy_omitted': ('fadeUvDestination[0] = temp_3_22;\n            fadeUvDestination[1] = temp_2_27;', '(void)temp_3_22; (void)temp_2_27;'),
    'wrong_state_divisor': ('var_4_18 = 0xA;', 'var_4_18 = 0xD;'),
    'wrong_other_divisor': ('var_4_18 = 0xD;', 'var_4_18 = 0xA;'),
    'wrong_rounding': ('(s32)((f32)(temp_3_23 * 0xFF) / (f32)var_4_18)', '(s32)((f32)(temp_3_23 * 0xFF) / (f32)var_4_18 + 0.5f)'),
    'float_bits_alpha': ('(s32)((f32)(temp_3_23 * 0xFF) / (f32)var_4_18)', '(s32)float_bits((f32)(temp_3_23 * 0xFF) / (f32)var_4_18)'),
    'alpha_before_decrement': ('temp_3_23 * 0xFF', '(temp_3_23 + 1) * 0xFF'),
    'counter_not_stored': ('M2C_FIELD(temp_20, s32 *, 0x2C) = temp_3_23;', '(void)temp_3_23;'),
    'zero_gate': ('0x2C) > 0)', '0x2C) >= 0)'),
    'wrong_z': ('(0, 0, 0.0f, 0x280,', '(0, 0, 1.0f, 0x280,'),
    'wrong_width': ('0x280, 0x1C0,', '0x281, 0x1C0,'),
    'wrong_height': ('0x280, 0x1C0,', '0x280, 0x1C1,'),
    'wrong_color': ('0xFFFFFF, fadeAlpha,', '0xFFFFFE, fadeAlpha,'),
    'wrong_mode': ('1, 0, 0, NULL, fadeTexture,', '0, 0, 0, NULL, fadeTexture,'),
    'wrong_center': ('1, 0, 0, NULL, fadeTexture,', '1, 1, 0, NULL, fadeTexture,'),
    'wrong_matrix': ('NULL, fadeTexture,', '(struct RwMatrixTag *)temp_20, fadeTexture,'),
    'wrong_texture_identity': ('NULL, fadeTexture,', 'NULL, fadeTexture ^ 1,'),
    'getter_bypassed': ('fadeTexture = func_00401b80();', 'fadeTexture = textureWord;'),
    'wrong_uv_identity': ('fadeTexture, fadeUv.pairs);', 'fadeTexture, (f32 (*)[2])D_005E56B0);'),
}


def fixture(mutation=None):
    values = parts()
    if mutation in ('copy_late', 'alpha_late', 'decrement_late'):
        block = values['BLOCK']
        if mutation == 'copy_late':
            begin = block.index('        fadeUvSource =')
            end = block.index('        var_4_18 =')
            moved = block[begin:end]
        elif mutation == 'alpha_late':
            moved = re.search(r'        fadeAlpha = [^;]+;\n', block)[0]
        else:
            moved = '        M2C_FIELD(temp_20, s32 *, 0x2C) = temp_3_23;\n'
        block = block.replace(moved, '', 1)
        anchor = '        fadeTexture = func_00401b80();\n'
        assert anchor in block
        values['BLOCK'] = block.replace(anchor, anchor + moved, 1)
    elif mutation == 'dummy_getter_argument':
        values['BLOCK'] = values['BLOCK'].replace('func_00401b80()', 'func_00401b80(123)')
    elif mutation:
        old, new = MUTATIONS[mutation]
        assert values['BLOCK'].count(old) == 1, mutation
        values['BLOCK'] = values['BLOCK'].replace(old, new, 1)
    template = Path(__file__).with_name('title_fade_contract_fixture.c.in').read_text()
    for key, value in values.items():
        template = template.replace('@' + key + '@', value)
    assert not re.search(r'@[A-Z_]+@', template)
    return RUNTIME_C + template + ENTRY_C


def runtime():
    """Honor an explicitly configured existing i386 runner, as archive runners do."""
    requested = os.environ.get('P4_NATIVE32_RUNNER')
    if not requested:
        return native32_runtime()
    runner = shlex.split(requested)
    compiler, linker = shutil.which('clang'), shutil.which('ld')
    executable = shutil.which(runner[0]) if runner else None
    if not all((compiler, linker, executable)):
        raise Native32Unavailable('Configured native32 runner, Clang, or GNU ld is unavailable')
    runner[0] = executable
    result = Native32Runtime(compiler, (linker,), tuple(runner), False)
    # Availability must be established independently of fixture behavior.
    with tempfile.TemporaryDirectory(prefix='p4_fade_preflight_') as temporary:
        directory = Path(temporary)
        source = directory / 'ready.c'
        source.write_text(RUNTIME_C + 'int main(void) { native32_text("ready\\n"); return 0; }' + ENTRY_C)
        executable = result.compile(source, directory / 'ready', '-O2')
        probe = result.run(executable)
        if probe.returncode or probe.stdout != 'ready\n':
            raise Native32Unavailable('Configured native32 runner failed preflight: ' + probe.stdout + probe.stderr)
    return result


class TitleFadeExtraction(unittest.TestCase):
    def test_final_gate_and_real_getter_are_extracted_verbatim(self):
        values = parts()
        rendered = fixture()
        for key in ('BLOCK', 'UV_DECLARATION', 'LOCALS', 'RENDERER_PROTOTYPE', 'GETTER_PROTOTYPE', 'GETTER'):
            self.assertIn(values[key], rendered)
        self.assertNotIn('RwMatrixSetIdentity', rendered)


class TitleFadeContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def execute(self, optimization, mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_title_fade_') as temporary:
            directory = Path(temporary)
            source = directory / 'fixture.c'
            source.write_text(fixture(mutation))
            executable = self.runtime.compile(source, directory / 'fixture', optimization, (ROOT / 'include',))
            return self.runtime.run(executable)

    def test_actual_tail_order_gate_arguments_and_uv_words(self):
        for optimization in ('-O0', '-O2'):
            with self.subTest(optimization=optimization):
                result = self.execute(optimization)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, '107904 title fade boundary cases passed\n')
                print(optimization, result.stdout.strip())

    def test_independent_negative_controls(self):
        for mutation in (*MUTATIONS, 'copy_late', 'alpha_late', 'decrement_late'):
            with self.subTest(mutation=mutation):
                result = self.execute('-O2', mutation)
                self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                self.assertIn('scenario', result.stdout)
                print(mutation + ': rejected: ' + result.stdout.strip())

    def test_no_argument_getter_rejects_dummy_parameter(self):
        with self.assertRaisesRegex(RuntimeError, r'too many arguments'):
            self.execute('-O2', 'dummy_getter_argument')


if __name__ == '__main__':
    unittest.main()
