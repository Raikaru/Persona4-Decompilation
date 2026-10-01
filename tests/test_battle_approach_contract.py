"""Execute the actual approach controller, packet factories, and predicates.

Geometry, allocation, queueing and unrelated state changes are audited external
boundaries. Tests cover only admitted action actors (kind 0/1), not invalid data.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from measure_guarded import extract_guarded_body

PROVIDERS={
'btlUnitCreateLookAtUnitPacket':'src/Battle/btlUnit_functions.c',
'btlUnitCreateLookAtDeactivatePacket':'src/Battle/btlUnit_functions.c',
'btlUnitCreateMoveToUnitPacket':'src/Battle/btlUnit.c',
'btlCameraCreateSetStatePacket':'src/Battle/btlCamera.c',
'func_00195730':'src/promoted/code1_0019.c',
'func_00196bd0':'src/promoted/code1_0019.c',
'func_001f0bf0':'src/promoted/code1_001f.c',
'func_001f0a50':'src/promoted/code1_001f.c',
'func_00243d80':'src/Main/Battle/Data/datCalc.c'}

def definition(path,name):
    s=(ROOT/path).read_text();m=re.search(r'(?m)^(?:static inline )?[\w *]+\b'+name+r'\([^;]*?\)\s*\{',s)
    assert m,name
    end=m.end();depth=1
    while depth:depth+=(s[end]=='{')-(s[end]=='}');end+=1
    return s[m.start():end]

def target_body():
    s=(ROOT/'src/promoted/code1_001a.c').read_text()
    return extract_guarded_body(s,'FUN_001A4C80','func_001a4c80')

def fixture(mutation=None):
    body=target_body();providers='\n'.join(definition(path,name) for name,path in PROVIDERS.items())
    if mutation:
        before,after=mutation
        assert before in body or before in providers,before
        body=body.replace(before,after)
        providers=providers.replace(before,after)
    layouts='\n'.join(re.findall(r'typedef struct (?:UnitView|ActionView) \{.*?\} (?:UnitView|ActionView);',body,re.S))
    layouts+=r"""
_Static_assert(__builtin_offsetof(UnitView,y)==8, "unit y");
_Static_assert(__builtin_offsetof(UnitView,scale)==0x2C, "unit scale");
_Static_assert(__builtin_offsetof(UnitView,radius)==0x90, "unit radius");
_Static_assert(__builtin_offsetof(UnitView,kind)==0xA2, "unit kind");
_Static_assert(__builtin_offsetof(UnitView,data)==0xA64, "unit data");
_Static_assert(__builtin_offsetof(ActionView,flags)==0x18, "action flags");
_Static_assert(__builtin_offsetof(ActionView,unit)==0x30, "action unit");
_Static_assert(__builtin_offsetof(ActionView,target)==0x38, "first target");
_Static_assert(__builtin_offsetof(ActionView,skill)==0x6E, "action skill");
_Static_assert(sizeof(BtlPacket)==0x90, "packet size");
_Static_assert(__builtin_offsetof(BtlPacket,actionUID)==0x60, "packet action UID");
_Static_assert(__builtin_offsetof(BtlPacket,workData)==0x78, "packet work");
"""
    return RUNTIME_C+(ROOT/'tests/battle_approach_fixture.c.in').read_text().replace('%%LAYOUT%%',layouts).replace('%%PROVIDERS%%',providers).replace('%%TARGET%%',body)+ENTRY_C

class BattleApproachContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as exc:raise unittest.SkipTest(str(exc))
    def exercise(self,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_approach_') as tmp:
            p=Path(tmp);source=p/'fixture.c';source.write_text(fixture(mutation))
            for level in ('-O0','-O2'):
                exe=self.runtime.compile(source,p/('fixture'+level),level,(ROOT/'include',ROOT/'tests'));result=self.runtime.run(exe)
                if mutation:self.assertNotEqual(result.returncode,0,'Mutation escaped fixture: '+mutation[0])
                else:
                    self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                    self.assertEqual(result.stdout,'69 approach scenarios passed\n')
    def test_live_controller_and_providers(self):self.exercise()
    def test_wrong_uid_width(self):self.exercise(('= action->uid;', '= (s32)action->uid;'))
    def test_wrong_motion(self):self.exercise(('motion = 7;', 'motion = 6;'))
    def test_wrong_speed_stride(self):self.exercise(('selector = (u16)speedVariant * 4;', 'selector = (u16)speedVariant * 2;'))
    def test_wrong_enemy_stride(self):self.exercise(('offset = (u32)unitId * 0xE8;', 'offset = (u8)((u32)unitId * 0xE8);'))
    def test_wrong_rotation_copy_extent(self):self.exercise(('*(P4_95730_Vec4 *)(work + 0x10) = *(P4_95730_Vec4 *)rotation;', '*(P4_95730_Vec3 *)(work + 0x10) = *(P4_95730_Vec3 *)rotation;'))
    def test_wrong_signed_opening_motion(self):self.exercise(('(s16)openingMotion, destination.values','(u16)openingMotion, destination.values'))
    def test_wrong_camera_state(self):self.exercise(('(BtlAction *)action, 0x17','(BtlAction *)action, 0x16'))
    def test_stale_skill(self):self.exercise(('action->skill * 0x28','skill * 0x28'))
    def test_wrong_range_boundary(self):self.exercise(('func_001ec250(&unitCenter, &targetCenter) < 500.0f','func_001ec250(&unitCenter, &targetCenter) <= 500.0f'))
    def test_wrong_queue(self):self.exercise(('func_00194590(packet, 1)','func_00194590(packet, 0)'))
