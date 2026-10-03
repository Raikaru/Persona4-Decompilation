"""Execute the four actual caller pairs with their unchanged vector providers.

Allocation, group selection and geometry helpers are controlled boundaries.
The source contract covers admitted nonempty target groups, not the whole
controllers or a PS2 FPU emulator.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from test_btl_motion_override_contract import definition
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
OWNER=ROOT/'src/promoted/code1_001a.c'
PROVIDER=ROOT/'src/Battle/btlUnit.c'
NAMES=('func_00196040','func_001958f0','btlUnitCreateRotatePacket','btlUnitCreateLookAtPacket')

def structure(text,name):
    match=re.search(r'(?:typedef )?struct '+name+r'\s*\{.*?\}\s*(?:'+name+r')?;',text,re.S)
    assert match,name
    body=match[0]
    return body if body.startswith('typedef') else 'typedef struct '+name+' '+name+';\n'+body

def parts():
    text=OWNER.read_text();provider=PROVIDER.read_text()
    small=extract_guarded_body(text,'FUN_001A59A0','func_001a59a0')
    large=extract_guarded_body(text,'FUN_001A7720','func_001a7720')
    types='\n'.join(structure(provider,n) for n in ('RwV3d','RtQuat','RwRGBA','BtlUnit','BtlPacket','BtlUnitPacketCountRef','BtlUnitPacketRotate','BtlUnitPacketLookAt'))
    assert 'extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);' in small
    assert 'extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);' in large
    assert 'extern void func_001958f0(BtlUnit *unit, RwV3d *dst);' in large
    assert 'extern BtlPacket *btlUnitCreateLookAtPacket(BtlUnit *unit, const RwV3d *targetPos, u16 flags);' in large
    assert 'extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);' in text
    wrappers=[];sites=[]
    for controller,body in enumerate((small,large)):
        declaration=re.search(r'(?m)^\s*RwV3d targetPosition;',body)[0].strip()
        lines=body.splitlines()
        for pos,line in enumerate(lines):
            if not re.match(r'\s*func_001(?:96040|958f0)\(',line):continue
            pair='\n'.join(l.strip() for l in lines[pos:pos+2])
            assert '&targetPosition' in pair and re.search(r'btlUnitCreate(?:Rotate|LookAt)Packet',pair)
            name=re.search(r'\b(temp_2_\d+) = ',lines[pos+1])[1]
            number=len(wrappers)
            arg='(s64 *)action.bytes' if controller==0 else 'action.bytes'
            argtype='s64 *' if controller==0 else 'u8 *'
            wrapper='''static void call_%d(void) {
    struct { u32 before[4]; %s u32 after[4]; } storage;
    %sarg0=%s;
    u8 *temp_4_2=iGpffffb3ac,*%s;
    s32 var_30=(s32)flags, temp_4_13=(s32)mask;
    memset(&storage,0xA5,sizeof(storage));
    CHECK(sizeof(storage.targetPosition)==12);
#define targetPosition storage.targetPosition
    %s
#undef targetPosition
    CHECK(%s==(u8 *)&packet);
    for(u32 i=0;i<4;++i)CHECK(storage.before[i]==0xA5A5A5A5U&&storage.after[i]==0xA5A5A5A5U);
    CHECK(storage.targetPosition.x==expected.x&&storage.targetPosition.y==expected.y&&storage.targetPosition.z==expected.z);
}'''%(number,declaration,argtype,arg,name,pair,name)
            wrappers.append(wrapper);sites.append(pair)
    assert len(wrappers)==4 and sum('func_001958f0(' in s for s in sites)==1
    assert sum('btlUnitCreateLookAtPacket(' in s for s in sites)==1
    return {'TYPES':types,'PROVIDERS':'\n'.join(definition('src/Battle/btlUnit.c',n) for n in NAMES),'CALLERS':'\n'.join(wrappers)}

def fixture(mutation=None):
    values=parts()
    changes={
      'undersized_object':('CALLERS','RwV3d targetPosition;','struct { f32 x; } targetPosition;'),
      'group_exclusion':('CALLERS',', 1, &targetPosition, 0, 0, 1)',', 0, &targetPosition, 0, 0, 1)'),
      'wrong_unit_source':('CALLERS','func_001958f0((*( BtlUnit ** )((u8 *)((*( u8 ** )((u8 *)(temp_4_2) + (0x170)))) + (0x30))),','func_001958f0((BtlUnit *)action.bytes,'),
      'wrong_lookat_unit':('CALLERS','btlUnitCreateLookAtPacket(0,','btlUnitCreateLookAtPacket((BtlUnit *)action.bytes,'),
      'narrow_rotate_flags':('CALLERS','&targetPosition, var_30)','&targetPosition, (u16)var_30)'),
      'group_z_missing':('PROVIDERS','*outCenter = center;','outCenter->x = center.x; outCenter->y = center.y;'),
      'rotate_z_missing':('PROVIDERS','work->rot = *rot;','work->rot.x = rot->x; work->rot.y = rot->y;'),
      'lookat_z_missing':('PROVIDERS','work->targetPos = *targetPos;','work->targetPos.x = targetPos->x; work->targetPos.y = targetPos->y;'),
    }
    if mutation:
        key,before,after=changes[mutation];assert before in values[key];values[key]=values[key].replace(before,after)
        if mutation=='undersized_object':
            # Fail the object extent check before invoking any provider; no
            # deliberately undefined overwrite is executed by this control.
            values['CALLERS']=values['CALLERS'].replace('&targetPosition','(RwV3d *)&targetPosition').replace('storage.targetPosition.y','0.0f').replace('storage.targetPosition.z','0.0f')
    text=Path(__file__).with_name('large_battle_vector_storage_fixture.c.in').read_text()
    for key,value in values.items():text=text.replace('@'+key+'@',value)
    assert not re.search(r'@[A-Z_]+@',text)
    return RUNTIME_C+text+ENTRY_C

class LargeBattleVectorStorage(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_vector_storage_') as temporary:
            path=Path(temporary);source=path/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,path/'fixture',opt,(ROOT/'include',))
            return self.runtime.run(binary)
    def test_real_caller_pairs_and_providers(self):
        for opt in ('-O0','-O2'):
            with self.subTest(optimization=opt):
                result=self.execute(opt);self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                self.assertEqual(result.stdout,'65536 vector caller/provider cases passed\n');print(opt,result.stdout.strip())
    def test_negative_controls(self):
        for mutation in ('undersized_object','group_exclusion','wrong_unit_source','wrong_lookat_unit','narrow_rotate_flags','group_z_missing','rotate_z_missing','lookat_z_missing'):
            with self.subTest(mutation=mutation):
                result=self.execute('-O2',mutation);self.assertEqual(result.returncode,1,result.stdout+result.stderr);self.assertIn('scenario',result.stdout)

if __name__=='__main__':unittest.main()
