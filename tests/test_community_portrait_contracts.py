"""Native-32 actual-source portrait renderer and interpolation providers.

A separately written retail-offset model checks used vertex fields, all indices,
pass ordering, provider state writes, and callback-time mutations. Not EE/GPU
emulation: math/packet boundaries are deterministic instrumented providers.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import recovery_quality as Q
from measure_guarded import extract_guarded_body
OWNER = ROOT / 'src/promoted/code1_0035.c'

def target_source():
    return extract_guarded_body(OWNER.read_text(), 'FUN_0035AFF0', 'func_0035aff0')

def fixture_source(mutation=None, provider_mutation=None):
    source = OWNER.read_text()
    target = target_source()
    if mutation:
        old, new = mutation
        if old not in target: raise AssertionError('Missing mutation site: '+old)
        target = target.replace(old, new, 1)
    providers = '\n'.join(Q.function_bodies(OWNER)[name][1]
                          for name in ('func_0035bad0', 'func_0035bd20'))
    if provider_mutation:
        old, new = provider_mutation
        if old not in providers: raise AssertionError('Missing provider mutation: '+old)
        providers = providers.replace(old, new, 1)
    reset = Q.function_bodies(ROOT / 'src/promoted/code1_0034.c')['func_0034f1e0'][1]
    helper = re.search(r'static inline void interpolation_accumulate\([^}]+\}',source).group(0)
    decl = '''
#include "type.h"
typedef struct { f32 x,y; } Float2;
typedef s32 RwRenderState;
extern s32 (*D_00887300[])(RwRenderState, void *);
extern s32 RpSkyRenderStateSet(s32, void *);
extern f32 sinf(f32), cosf(f32), RwV3dNormalize(void *, const void *);
extern f32 fGpffff84a4;
extern u8 D_0064CC98[];
extern void func_0046d730(const void *, u32);
'''
    types = target[target.index('    typedef struct {'):target.index('    CommunityVertex qs[4];')]
    return RUNTIME_C+decl+helper+'\n'+types+'\n'+target+'\n'+providers+'\n'+reset+'\n'+(ROOT/'tests/community_portrait_fixture.c.in').read_text()+ENTRY_C

class CommunityPortraitContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try: cls.runtime = native32_runtime()
        except Native32Unavailable as exc: raise unittest.SkipTest(str(exc)) from exc

    def check(self, mutation=None, provider_mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_portrait_') as tmp:
            for level in ('-O0','-O2'):
                with self.subTest(level=level, mutation=mutation):
                    source=Path(tmp)/('portrait'+level+'.c');source.write_text(fixture_source(mutation, provider_mutation))
                    binary=self.runtime.compile(source,Path(tmp)/('portrait'+level),level,(ROOT/'include',))
                    result=self.runtime.run(binary)
                    if mutation or provider_mutation: self.assertNotEqual(result.returncode,0,'negative control escaped oracle')
                    else:
                        self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                        self.assertIn('community-portrait cases=',result.stdout)
                        print(level,result.stdout.strip())

    def test_actual_source_timeline(self): self.check()

    def test_provider_negative_controls(self):
        for mutation in (
            ('if (!(total <= 1.0f)) total = 1.0f;', 'if (total > 1.0f) total = 1.0f;'),
            ('*(s16 *)(arg0 + 0x24) >= 0x64', '*(s16 *)(arg0 + 0x24) > 0x64'),
            ('direction.z = 20.0f;', 'direction.z = 19.0f;'),
        ):
            self.check(provider_mutation=mutation)

    def test_negative_controls(self):
        mutations={
            'captured_work': ('CommunityPortrait *t = (CommunityPortrait *)((CommunityPortraitTask *)arg0)->work;', 'CommunityPortrait *t = portrait;'),
            'captured_depth': ('z = D_008872F8[0];','z = D_008872F8[0] + 1.0f;'),
            'clip_reciprocal': ('1.0f / ((CommunityCameraView *)func_00457120())->nearClip','2.0f / ((CommunityCameraView *)func_00457120())->nearClip'),
            'guard_loaded': ('t->loaded == 0','t->loaded != 0'),
            'guard_id': ('t->portraitId == 0','t->portraitId > 0'),
            'opacity': ('qs[0].alpha = (f32)arg1;', 'qs[0].alpha = (f32)(s8)arg1;'),
            'width': ('sx = 50.0f * portrait->scale.x;', 'sx = 49.0f * portrait->scale.x;'),
            'height': ('sy = 64.0f * portrait->scale.y;', 'sy = 63.0f * portrait->scale.y;'),
            'mirror': ('if (portrait->flags & 1)', 'if (portrait->flags & 2)'),
            'live_texture': ('func_0034f1e0();\n        stateSet = D_00887300;\n        stateSet[0](1, portrait->texture->raster);','void *savedTexture = portrait->texture->raster;\n        func_0034f1e0();\n        stateSet = D_00887300;\n        stateSet[0](1, savedTexture);'),
            'live_mode': ('mode = portrait->flags;', 'mode = 0;'),
            'red': ('color.red = 0xF2;', 'color.red = 0xF1;'),
            'green': ('color.green = 0x15;', 'color.green = 0x14;'),
            'blue': ('color.blue = 0xBA;', 'color.blue = 0xB9;'),
            'flat_alpha': ('color.alpha = 0xFF;', 'color.alpha = arg1;'),
            'wave_gate': ('else if (mode & 4)', 'else if (mode & 8)'),
            'wave_angle': ('/ 100.0f;', '/ 99.0f;'),
            'gray_channel': ('verts[vtx].green = (f32)g8;', 'verts[vtx].green = 0.0f;'),
            'index': ('(s16)(jj + (ii + 1) * 5)', '(s16)(jj + ii * 5)'),
            'count': ('&verts[0], 0x23,', '&verts[0], 0x22,'),
            'state': ('(void *)0x31801', '(void *)0x31800'),
            'state_callback_snapshot': ('stateSet = D_00887300;', 'static s32 (*snapshot[1])(s32, void *); snapshot[0] = D_00887300[0]; stateSet = snapshot;'),
            'primitive_callback_snapshot': ('drawPrimitive = D_00887310;', 'static s32 (*snapshot[1])(s32, void *, s32); snapshot[0] = D_00887310[0]; drawPrimitive = snapshot;'),
            'return': ('return blend;', 'return 0.0f;'),
        }
        for name, mutation in mutations.items():
            with self.subTest(name=name): self.check(mutation)

if __name__ == '__main__': unittest.main()
