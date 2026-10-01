"""Execute live motion providers and their coherent unsigned-halfword contracts."""
from pathlib import Path
import re
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime
ROOT = Path(__file__).resolve().parents[1]
NAMES = ('func_001990d0', 'func_001991c0', 'func_00199350', 'func_00199500', 'func_001996d0', 'func_001999f0')


def definition(path, name):
    text = (ROOT / path).read_text()
    match = re.search(r'(?m)^(?:static inline )?[\w *]+\b' + name + r'\([^;]*?\)\s*\{', text)
    assert match, name
    end, depth = match.end(), 1
    while depth:
        depth += (text[end] == '{') - (text[end] == '}')
        end += 1
    return text[match.start():end]


PRELUDE = r'''
#include "type.h"
#include "btl_motion_internal.h"
static unsigned scenario;
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__, scenario, #c); } while (0)
typedef union { u64 align; u8 bytes[0xD00]; } Buffer;
static Buffer unit,battle,target;
static u8 overrides[30],enemyInfo[0x120*0xE8],playerInfo[0x120*0x14C];
u8 *DAT_0076449c=battle.bytes,*iGpffffb3cc=enemyInfo,*iGpffffb3c0=playerInfo;
u8 D_005F6CA0[90];
static s16 motionTable[256][5];
static s32 expectedMotion;
static unsigned frameCalls;
f32 func_0047a000(s32 resource,s32 layer,s64 motion) {
    CHECK(resource==1234&&layer==0&&motion==expectedMotion);++frameCalls;return 180.0f;
}
static void put16(u8 *p,u16 v) { memcpy(p,&v,2); }
static void put32(u8 *p,u32 v) { memcpy(p,&v,4); }
static void putptr(u8 *p,void *v) { memcpy(p,&v,4); }
static void putfloat(u8 *p,f32 v) { memcpy(p,&v,4); }
'''
CHECKS = r'''
static s32 oracleOverride(u32 kind,u32 id,u32 motion,u32 loaded,u32 phase,s8 local) {
    if(kind!=1||!loaded)return -1;
    if(id==0x10D||id==0x110||id==0x111)return overrides[motion];
    if(id==0x10F){if((motion==0||motion==18)&&phase!=3)return 11;return overrides[motion];}
    return local>=0?local:overrides[motion];
}
int main(void) {
    const u16 ids[]={1,2,0x10D,0x10F,0x110,0x111};
    const s8 localValues[]={-128,-1,0,7,127};
    const f32 rates[]={0.5f,1.0f,1.75f};
    const s16 speeds[]={50,100,125};
    for(u32 i=0;i<90;++i)D_005F6CA0[i]=i%16+16;
    for(u32 i=0;i<30;++i)overrides[i]=(u8)(i+40);
    putptr(unit.bytes+0x9F8,motionTable);put32(unit.bytes+0xA00,1234);
    for(u32 kind=0;kind<4;++kind)for(u32 n=0;n<6;++n)for(u32 loaded=0;loaded<2;++loaded)
    for(u32 phase=2;phase<=3;++phase)for(u32 local=0;local<5;++local)for(u32 motion=0;motion<30;++motion)
    for(u32 enabled=0;enabled<2;++enabled)for(u32 rate=0;rate<3;++rate){
        s32 chosen,override;f32 divisor;
        ++scenario;unit.bytes[0xA2]=kind;put16(unit.bytes+0xA4,ids[n]);
        put32(unit.bytes+0xC4,0x100);put32(unit.bytes+0x98,enabled?2:0);put16(unit.bytes+0x9E4,256);
        putptr(battle.bytes+0xC30,loaded?overrides:0);put16(battle.bytes+0xC34,phase);battle.bytes[0xC10+motion]=(u8)localValues[local];
        override=oracleOverride(kind,ids[n],motion,loaded,phase,localValues[local]);
        CHECK(func_0022cb90(unit.bytes,(s32)motion)==override);
        chosen=override;
        if(chosen<0){chosen=kind<3?D_005F6CA0[kind*30+motion]:0;if(kind==0&&ids[n]==1&&motion==1)chosen=28;}
        expectedMotion=chosen;
        for(u32 i=0;i<256;++i){motionTable[i][0]=120+i;motionTable[i][1]=speeds[rate]+(i%3)*25;motionTable[i][2]=(i&1)?-1:80+i;motionTable[i][4]=(s16)(i-80);}
        divisor=rates[rate]*((f32)motionTable[chosen][1]/100.0f);
        /* Call conversion must discard the high halfword, including sign bits. */
        const u32 rawMotion=motion|0xA5370000U;
        CHECK(func_001990d0(unit.bytes,rawMotion)==chosen);
        CHECK(func_001991c0(unit.bytes,rawMotion,rates[rate])==(s16)(s32)((f32)(120+chosen)/divisor));
        CHECK(func_00199350(unit.bytes,rawMotion,rates[rate])==((chosen&1)?0:(s16)(s32)((f32)(80+chosen)/divisor)));
        frameCalls=0;
        CHECK(func_00199500(unit.bytes,rawMotion,rates[rate])==(enabled?(s16)(s32)(180.0f/divisor):0));
        CHECK(frameCalls==enabled);
        CHECK(func_001996d0(unit.bytes,rawMotion)==(enabled?(s16)(chosen-80):6));
        for(u32 hit=0;hit<3;++hit){
            s32 cls=-1,numerator=0,expected=0;
            if(kind==1){if(motion>=4&&motion<=7)cls=0;}else{if(motion==5)cls=0;else if(motion==6||motion==7)cls=1;}
            if(cls>=0){
                if(kind==1){put16(enemyInfo+ids[n]*0xE8+cls*4+0x1C,9);numerator=(s16)(9*(s16)hit+motionTable[motion][0]);}
                else {numerator=70+hit*11;put16(playerInfo+ids[n]*0x14C+cls*0x12+hit*2+0x1A,(u16)numerator);}
                expected=(s16)(s32)((f32)numerator/divisor);
            }
            CHECK(func_001999f0(unit.bytes,rawMotion,rates[rate],(s64)hit)==expected);
        }
    }
    /* Invalid animation mappings retain each provider's explicit fallback. */
    unit.bytes[0xA2]=0;put16(unit.bytes+0x9E4,0);put32(unit.bytes+0x98,2);expectedMotion=D_005F6CA0[4];
    CHECK(func_001991c0(unit.bytes,4,1.0f)==0);CHECK(func_00199350(unit.bytes,4,1.0f)==0);
    CHECK(func_00199500(unit.bytes,4,1.0f)==180);CHECK(func_001996d0(unit.bytes,4)==6);
    native32_number(scenario);native32_text(" motion override scenarios passed\n");return 0;
}
'''


def fixture(mutation=None):
    parts = [definition('src/promoted/code1_0022.c', 'cb90AddBaseIndex'),
             definition('src/promoted/code1_0022.c', 'func_0022cb90'),
             definition('src/promoted/code1_0019.c', 'p4_base_add_00194590'),
             definition('src/promoted/code1_0019.c', 'p4_sign16_001991c0')]
    for name in NAMES:
        body = definition('src/promoted/code1_0019.c', name)
        if mutation == name:
            assert body.count('func_0022cb90(arg0, arg1)') == 1
            body = body.replace('func_0022cb90(arg0, arg1)', 'func_0022cb90(arg0, 0)')
        parts.append(body)
    return RUNTIME_C + PRELUDE + '\n'.join(parts) + CHECKS + ENTRY_C


DISTANCE_CHECKS = r'''
/* The retail switch is represented as an independent ID-indexed expectation.
 * Negative entries deliberately cover all explicit/default rejection arms. */
static const s16 bossDistances[20]={100,25,150,150,50,200,250,200,300,-1,
                                  500,-1,-1,-1,-1,250,150,150,-1,75};
int main(void) {
    const u32 high[]={0,0x10000U,0x80000000U,0xFFFF0000U};
    for(u32 i=0;i<90;++i)D_005F6CA0[i]=i%16+16;
    for(u32 i=0;i<256;++i)motionTable[i][3]=(s16)(20+i);
    putptr(unit.bytes+0x9F8,motionTable);put16(unit.bytes+0xA4,2);
    putfloat(unit.bytes+0x2C,2.0f);putfloat(unit.bytes+0x88,3.0f);
    putfloat(target.bytes+0x2C,0.5f);putfloat(target.bytes+0x88,4.0f);putfloat(target.bytes+0x90,10.0f);
    for(u32 flag=0;flag<2;++flag)for(u32 kind=0;kind<2;++kind)
    for(u32 id=0xFF;id<=0x114;++id)for(u32 motion=0;motion<30;++motion)
    for(u32 upper=0;upper<4;++upper)for(u32 valid=0;valid<2;++valid){
        f32 expectedOverride=-1.0f,expectedDistance=0.0f;
        u32 rawMotion=motion|high[upper];
        ++scenario;put32(battle.bytes+0xC,flag?0x200000:0);target.bytes[0xA2]=kind;
        put16(target.bytes+0xA4,(u16)id);put16(unit.bytes+0x9E4,valid?256:0);
        if(flag&&kind&&id>=0x100&&id<=0x113&&bossDistances[id-0x100]>=0&&
           ((0x10B0U>>motion)&1))expectedOverride=(f32)bossDistances[id-0x100]+5.0f;
        CHECK(func_0022cf00(unit.bytes,target.bytes,rawMotion)==expectedOverride);
        if(valid)expectedDistance=2.0f*(20.0f+D_005F6CA0[motion])+6.0f+
            (expectedOverride<0.0f?7.0f:expectedOverride);
        CHECK(func_00196bd0(unit.bytes,target.bytes,rawMotion)==expectedDistance);
    }
    native32_number(scenario);native32_text(" motion distance scenarios passed\n");return 0;
}
'''


def distance_fixture(mutation=None):
    names = [('src/promoted/code1_0022.c','cb90AddBaseIndex'),
             ('src/promoted/code1_0022.c','func_0022cb90'),
             ('src/promoted/code1_0022.c','func_0022cf00'),
             ('src/promoted/code1_0019.c','p4_base_add_00194590'),
             ('src/promoted/code1_0019.c','func_001990d0'),
             ('src/promoted/code1_0019.c','func_00196bd0')]
    parts=[]
    for path,name in names:
        body=definition(path,name)
        if mutation=='mapping_selector' and name=='func_00196bd0':
            assert body.count('func_001990d0(unit, motion)')==1
            body=body.replace('func_001990d0(unit, motion)','func_001990d0(unit, 0)')
        if mutation=='boss_selector' and name=='func_00196bd0':
            assert body.count('func_0022cf00(unit, target, motion)')==1
            body=body.replace('func_0022cf00(unit, target, motion)','func_0022cf00(unit, target, 0)')
        parts.append(body)
    return RUNTIME_C+PRELUDE+'\n'.join(parts)+DISTANCE_CHECKS+ENTRY_C


class MotionOverrideContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as exc:
            raise unittest.SkipTest(str(exc))

    def run_fixture(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_motion_override_') as tmp:
            p = Path(tmp); source = p/'fixture.c'; source.write_text(fixture(mutation))
            for level in ('-O0','-O2'):
                exe = self.runtime.compile(source, p/('fixture'+level), level, (ROOT/'include',))
                result = self.runtime.run(exe)
                if mutation:
                    self.assertNotEqual(result.returncode,0,'Wrong-motion negative control was not rejected')
                else:
                    self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                    self.assertEqual(result.stdout,'86400 motion override scenarios passed\n')

    def run_distance_fixture(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_motion_distance_') as tmp:
            p = Path(tmp); source = p/'fixture.c'; source.write_text(distance_fixture(mutation))
            for level in ('-O0','-O2'):
                exe = self.runtime.compile(source, p/('fixture'+level), level, (ROOT/'include',))
                result = self.runtime.run(exe)
                if mutation:
                    self.assertNotEqual(result.returncode,0,'Wrong distance selector was not rejected')
                else:
                    self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                    self.assertEqual(result.stdout,'21120 motion distance scenarios passed\n')

    def test_distance_providers_and_narrow_boundaries(self):
        self.run_distance_fixture()

    def test_wrong_distance_selectors_are_rejected(self):
        for mutation in ('mapping_selector','boss_selector'):
            with self.subTest(mutation=mutation):
                self.run_distance_fixture(mutation)

    def test_actual_provider_and_all_consumers(self):
        self.run_fixture()

    def test_each_missing_motion_argument_is_rejected(self):
        for name in NAMES:
            with self.subTest(consumer=name):
                self.run_fixture(name)


if __name__=='__main__':unittest.main()
