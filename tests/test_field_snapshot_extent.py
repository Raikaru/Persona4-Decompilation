"""Run the actual seven-quadword snapshot provider with its complete storage."""
from pathlib import Path
import re
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
FIXTURE=r'''
#include "type.h"
#include "field_event_internal.h"
/* i386 lacks scalar __int128. These real 16-byte values only copy; the host
 * vector representation follows the project's existing quadword fixtures. */
typedef s32 s128 __attribute__((vector_size(16)));
static unsigned scenario, getterCalls;
#define CHECK(x) do { if (!(x)) native32_failure(__LINE__,scenario,#x); } while(0)
static u8 task[64] __attribute__((aligned(16)));
static u8 work[0x2b0] __attribute__((aligned(16)));
static u8 views[2][16] __attribute__((aligned(16)));
static u8 frames[2][0x50] __attribute__((aligned(16)));
static u32 fovBits;
u8 *func_00457120(void) { CHECK(getterCalls<2); return views[getterCalls++]; }
f32 K_View_GetFov(u8 *view) { f32 out; CHECK(view==views[1]); memcpy(&out,&fovBits,4); return out; }
'''
MAIN=r'''
_Static_assert(sizeof(F630Frame)==0x70,"complete real snapshot extent");
_Static_assert(__alignof__(F630Frame)==16,"quadword copy alignment");
static struct { u32 before[4]; FldEventSnapshot data; u32 after[4]; } result;
static u8 expected[0x70];
int main(void) {
    static const u32 fovs[]={0,0x80000000u,0x42340000u,0x7fc12345u,0x7f800000u};
    static const unsigned src[]={0x14,0x18,0x1c,0x20,0x24,0x28c,0x29c,0x2a0,0x2a4};
    for(unsigned sample=0;sample<64;sample++)for(unsigned f=0;f<5;f++) {
        ++scenario; getterCalls=0; fovBits=fovs[f];
        memset(&result,0xa5,sizeof(result)); memset(expected,0,sizeof(expected));
        memset(task,0,sizeof(task)); memset(work,0,sizeof(work)); memset(views,0,sizeof(views));
        *(u8 **)(task+0x38)=work;
        for(unsigned v=0;v<2;v++) {
            *(u8 **)(views[v]+4)=frames[v];
            for(unsigned b=0;b<0x50;b++)frames[v][b]=(u8)(sample*17+b*3+v*71);
        }
        u32 id=sample*0x10001u+0x7ff0u; memcpy(work+8,&id,4);
        for(unsigned i=0;i<9;i++) { u32 bits=0x3f000000u+sample*0x1000u+i*0x111u; memcpy(work+src[i],&bits,4); memcpy(expected+0x48+i*4,&bits,4); }
        memcpy(expected,frames[0]+0x10,0x40);memcpy(expected+0x40,&fovBits,4);
        u16 low=(u16)id;memcpy(expected+0x44,&low,2);
        func_0016f630(&result.data,task);
        CHECK(getterCalls==2);CHECK(memcmp(&result.data,expected,0x70)==0);
        for(unsigned i=0;i<4;i++){CHECK(result.before[i]==0xa5a5a5a5u);CHECK(result.after[i]==0xa5a5a5a5u);}
    }
    native32_text("field snapshot cases ");native32_number(scenario);native32_text("\n");return 0;
}
'''
def source(mutation=None):
    path=ROOT/'src/promoted/code1_0016.c'; text=path.read_text()
    frame=re.search(r'typedef struct F630Frame\b[\s\S]+?\bF630Frame;',text).group(0)
    body=Q.function_bodies(path)['func_0016f630'][1]
    if mutation:
        old,new=mutation
        if old not in body:raise AssertionError('stale mutant '+old)
        body=body.replace(old,new,1)
    return RUNTIME_C+FIXTURE+frame+'\n'+body+MAIN+ENTRY_C
class FieldSnapshotExtent(unittest.TestCase):
    def run_fixture(self,code,opt):
        runtime=native32_runtime()
        with tempfile.TemporaryDirectory(prefix='field-snapshot-') as d:
            p=Path(d);c=p/'fixture.c';c.write_text(code)
            return runtime.run(runtime.compile(c,p/'fixture',opt,(ROOT/'include',)))
    def test_real_snapshot(self):
        for opt in ('-O0','-O2'):
            result=self.run_fixture(source(),opt)
            self.assertEqual(result.returncode,0,result.stdout+result.stderr)
            print(result.stdout.strip())
    def test_negative_controls(self):
        for mutant in [('var_4 = 7;','var_4 = 6;'),('var_5 = 8;','var_5 = 7;'),
                       ('sp.spa8 = temp_f0;','sp.spa8 = temp_f0; sp.reserved6c = 1;'),
                       ('sp.sp84 = (s16)*(s32 *)(temp_16 + 8);','sp.sp84 = 0;'),
                       ('K_View_GetFov(func_00457120())','K_View_GetFov(temp_18)')]:
            with self.subTest(mutant=mutant[0]):
                result=self.run_fixture(source(mutant),'-O2')
                self.assertNotEqual(result.returncode,0,'mutant escaped '+str(mutant))
if __name__=='__main__':unittest.main()
