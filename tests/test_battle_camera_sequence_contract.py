"""Exact controller/factory source, bounded native32 behavioral contracts.

This gate executes ordinary source-extracted C at -O0/-O2. The retail-derived
oracle and controlled-provider models are distinct; this is neither a retail
CPU execution nor a whole-engine/numeric SDK equivalence claim.
"""
import hashlib
import json
import re
from pathlib import Path
import sys
import unittest
from native32_support import ENTRY_C, RUNTIME_C, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import recovery_quality as Q
OWNERS = {
    'ALLOCATOR': ('src/promoted/code1_0019.c','func_00194470'),
    'WAIT_CALLBACK': ('src/promoted/code1_001b.c','func_001b4860'),
    'FACTORY_COLOR': ('src/promoted/code1_001b.c','func_001ba530'),
    'FACTORY_QUAT': ('src/promoted/code1_001b.c','func_001ba710'),
    'FACTORY_ACTION': ('src/Battle/btlFormation.c','func_001d3b50'),
    'COLOR_PROVIDER': ('src/Battle/btlMain.c','func_001b83f0'),
    'SOUND_STOP': ('src/promoted/code1_001e.c','func_001eb7f0'),
    'CONTROLLER': ('src/promoted/code1_001b.c','func_001b4880'),
    'AMBIENT_HELPER': ('src/promoted/code1_001b.c','btlCameraBlendAmbient'),
    'UNIT_ROTATION_SETTER': ('src/Battle/btlUnit.c','btlUnitSetRot'),
}

def body(key):
    owner,name=OWNERS[key]
    if key in ('AMBIENT_HELPER','CONTROLLER'):
        text=(ROOT/owner).read_text()
        matches=list(re.finditer(r'(?m)^[\w *]+\b'+name+r'\([^;]*?\)\s*\{',text))
        assert len(matches)==1,('Expected one exact definition',name,len(matches))
        match=matches[0]
        end=match.end();depth=1
        while depth:
            depth+=(text[end]=='{')-(text[end]=='}');end+=1
        start=match.start()
        if key=='AMBIENT_HELPER':
            # Execute the complete exact source prefix: its real-color type and
            # both input/output helpers are part of the source under test.
            declarations=list(re.finditer(r'(?m)^typedef struct BtlCameraColorReal\b',text))
            assert len(declarations)==1,('Expected one real-color type',len(declarations))
            start=text.rfind('#include "btl_camera_sequence_internal.h"',0,declarations[0].start())
            assert start>=0 and start<declarations[0].start()<match.start()
            for helper in ('btlCameraNormalizeColor','btlCameraMultiplyColor'):
                definitions=list(re.finditer(r'(?m)^static inline void '+helper+r'\([^;]*?\)\s*\{',text))
                assert len(definitions)==1,('Expected one exact helper',helper,len(definitions))
                assert start<definitions[0].start()<match.start()
        return text[start:end]
    return Q.function_bodies(ROOT/owner)[name][1]

def unit_prefix(path=None):
    unit=(path or ROOT/'src/Battle/btlUnit.c').read_text()
    return unit[unit.index('#define BTLUNIT_FLAG2_DIRTY'):unit.index('typedef struct BtlUnitPacketMove')]

def fixture(mutation=None):
    text=(ROOT/'tests/battle_camera_sequence_fixture.c.in').read_text()
    text=text.replace('%%UNIT_TYPES%%',unit_prefix())
    for key in OWNERS:
        source=body(key)
        if mutation and MUTATIONS[mutation][0]==key:
            for old,new,count in mutation_edits(mutation):
                assert source.count(old)==count,(mutation,old,source.count(old))
                source=source.replace(old,new)
        marker='%%'+key+'%%'
        assert text.count(marker)==1
        text=text.replace(marker,source)
    assert '%%' not in text
    return RUNTIME_C+text+ENTRY_C

MUTATIONS={
    'unsigned_animation':('CONTROLLER','u16 animationFrames;','s16 animationFrames;',1),
    'fallback_genus':('CONTROLLER','+ 0xA2) == 1))','+ 0xA2) != 0))',1),
    'formation_mask':('CONTROLLER','& 3) != 0','& 1) != 0',1),
    'animation_boundary':('CONTROLLER','animationFrames > 0x28','animationFrames > 0x27',2),
    'normal_soundframe_clobber':('CONTROLLER','work->duration = 0x14;','work->duration = 0x14; work->soundFrame = 0;',1),
    'clear_extra_flag':('CONTROLLER','& 0xFFFFDFFF','& 0xFFFF5FFF',1),
    'delay_wrong':('CONTROLLER','work->delay = 0xC;','work->delay = 0xB;',1),
    'wrong_alpha_channel':('CONTROLLER','(f32)palette[3]','(f32)palette[2]',1),
    'wrong_palette_channel':('CONTROLLER','(f32)palette[0]','(f32)palette[1]',1),
    'drop_palette_call':('CONTROLLER','palette = (u8 *)func_00457160();\n        ambientGreen','/* cached pointer */\n        ambientGreen',1),
    'wrong_action_uid_source':('CONTROLLER','*(s64 *)base','*(s64 *)*(u8 **)(iGpffffb3ac + 0x170)',15),
    'narrow_action_uid':('CONTROLLER','*(s64 *)base','(s64)*(u32 *)base',15),
    'narrow_group_dependency':('CONTROLLER','*(s64 *)(dependencyPacket + 0x58)','(s64)*(u32 *)(dependencyPacket + 0x58)',2),
    'narrow_move_dependency':('CONTROLLER','*(s64 *)(pkt2 + 0x58);\n                    *(s64 *)(pkt3','(s64)*(u32 *)(pkt2 + 0x58);\n                    *(s64 *)(pkt3',1),
    'fresh_node_model':('CONTROLLER','func_0019beb0(*(u8 **)(actionNode + 0x30))','func_0019beb0(unit)',1),
    'wrong_color_argument':('CONTROLLER','0xFF88C3FF','0x7F88C3FF',1),
    'wrong_move_flags':('CONTROLLER','NULL, fGpffff82cc, 0x18','NULL, fGpffff82cc, 0x10',1),
    'wrong_final_state':('CONTROLLER','base, 0x26','base, 0x25',1),
    'drop_quaternion_w':('FACTORY_QUAT','*(struct F4 *)p = value;','*(struct F4 *)p = value; p[3] = 0;',1),
    'color_wrong_kind':('COLOR_PROVIDER','0x602, 0x6c','0x607, 0x6c',1),
    'color_wrong_size':('COLOR_PROVIDER','0x602, 0x6c','0x602, 4',1),
    'factory_wrong_return':('FACTORY_COLOR','return o;','return o + 4;',1),
}

MUTATIONS.update({
    'deferred_palette_reads': ('CONTROLLER', [
        ('ambientRed = (1.0f / 255.0f) * (f32)palette[0];', '', 1),
        ('ambientGreen = (1.0f / 255.0f) * (f32)palette[1];', '', 1),
        ('ambientBlue = (1.0f / 255.0f) * (f32)palette[2];', '', 1),
        ('ambientAlpha = (1.0f / 255.0f) * (f32)palette[3];', 'ambientAlpha = (1.0f / 255.0f) * (f32)palette[3];\n        ambientRed = (1.0f / 255.0f) * (f32)palette[0];\n        ambientGreen = (1.0f / 255.0f) * (f32)palette[1];\n        ambientBlue = (1.0f / 255.0f) * (f32)palette[2];', 1),
    ]),
    'ambient_helper_scale': ('AMBIENT_HELPER','result->red = (1.0f / 255.0f)','result->red = (1.0f / 128.0f)',1),
    'rotation_source_inverted': ('CONTROLLER', 'if (work->singleUnit == 1)', 'if (work->singleUnit == 0)', 1),
    'voice_replaces_group': ('CONTROLLER', [
        ('func_00194590(dependencyPacket, 0);', 'func_00194590(dependencyPacket, 0);\n        u8 *wrongDependency = dependencyPacket;', 1),
        ('pkt = (u8 *)func_001f99c0((BtlAction *)base, 4, 0, 0, 0);', 'pkt = (u8 *)func_001f99c0((BtlAction *)base, 4, 0, 0, 0); wrongDependency = pkt;', 2),
        ('*(s64 *)(dependencyPacket + 0x58)', '*(s64 *)(wrongDependency + 0x58)', 2),
    ]),
    'cached_group_uid_model': ('CONTROLLER', [
        ('*(s64 *)(dependencyPacket + 0x58)', 'cachedDependencyUID', 2),
        ('func_00194590(dependencyPacket, 0);', 'func_00194590(dependencyPacket, 0);\n        s64 cachedDependencyUID = *(s64 *)(dependencyPacket + 0x58);', 1),
    ]),
    'cached_move_uid_model': ('CONTROLLER', [
        ('pkt3 = (u8 *)btlUnitCreateAnimPacket', 's64 cachedMoveUID = *(s64 *)(pkt2 + 0x58);\n                    pkt3 = (u8 *)btlUnitCreateAnimPacket', 1),
        ('*(s64 *)(pkt3 + 8) = *(s64 *)(pkt2 + 0x58);', '*(s64 *)(pkt3 + 8) = cachedMoveUID;', 1),
    ]),
})
# This mutant's group-local temporary must not leak into the later single path.
MUTATIONS['voice_replaces_group'][1][1] = (
    'pkt = (u8 *)func_001f99c0((BtlAction *)base, 4, 0, 0, 0);\n            *(u16 *)',
    'pkt = (u8 *)func_001f99c0((BtlAction *)base, 4, 0, 0, 0); wrongDependency = pkt;\n            *(u16 *)', 1)

def mutation_edits(name):
    value=MUTATIONS[name]
    return value[1] if len(value)==2 else [value[1:]]

class CameraSequenceContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.runtime=native32_runtime()

    def execute(self,mutation,opt):
        directory=ROOT/'proof/native-controller-runs'/((mutation or 'actual')+opt[1:])
        directory.mkdir(parents=True,exist_ok=True)
        source=directory/'fixture.c';source.write_text(fixture(mutation))
        exe=self.runtime.compile(source,directory/'fixture',opt,(ROOT/'include',))
        result=self.runtime.run(exe)
        report={'mutation':mutation,'optimization':opt,'returncode':result.returncode,
                'stdout':result.stdout,'stderr':result.stderr,
                'source_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),
                'executable_sha256':hashlib.sha256(exe.read_bytes()).hexdigest()}
        (directory/'result.json').write_text(json.dumps(report,indent=2)+'\n')
        print((mutation or 'actual')+' '+opt+': '+result.stdout.strip())
        return result

    def test_exact_controller(self):
        for opt in ('-O0','-O2'):
            with self.subTest(optimization=opt):
                r=self.execute(None,opt)
                self.assertEqual(r.returncode,0,r.stdout+r.stderr)
                self.assertEqual(r.stdout,'2464 ordinary controller scenarios; 192 provider-model scenarios; exact factories and allocator passed\n')

    def test_semantic_negative_controls(self):
        for mutation in MUTATIONS:
            for opt in ('-O0','-O2'):
                with self.subTest(mutation=mutation,optimization=opt):
                    r=self.execute(mutation,opt)
                    self.assertEqual(r.returncode,1,'Expected ordinary CHECK failure, never crash/trap: '+r.stdout+r.stderr)
                    self.assertRegex(r.stdout,r'^line [0-9]+, scenario [0-9]+: ')
                    self.assertNotIn('passed',r.stdout)
                    failed=int(r.stdout.split('scenario ')[1].split(':')[0])
                    if mutation in ('fresh_node_model','cached_group_uid_model','cached_move_uid_model','deferred_palette_reads'):
                        self.assertGreater(failed,2464,'Model control failed before model matrix')
                    else:
                        self.assertLessEqual(failed,2464,'Ordinary semantic mutant escaped ordinary cases')

    def test_source_mutations_bind(self):
        for name,value in MUTATIONS.items():
            with self.subTest(mutation=name):
                source=body(value[0])
                for old,new,count in mutation_edits(name):
                    self.assertEqual(source.count(old),count,(name,old))
                    source=source.replace(old,new)

if __name__=='__main__':unittest.main()
