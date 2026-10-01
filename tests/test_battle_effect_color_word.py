"""Actual update callback plus a separate 8-byte-alignment assignment check."""
from pathlib import Path
import os,re,shutil,subprocess,sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q

def callback():return Q.function_bodies(ROOT/'src/promoted/code1_001d.c')['func_001d6360'][1]
def fixture(mutation=None):
    body=callback()
    replacements={
        'wrong_color_mask':('0x00FFFFFF','0x0000FFFF'),
        'wrong_color_phase':('value == 2','value == 4'),
        'wrong_color_option':('& 0x10000','& 0x20000'),
        'wrong_freeze_flag':('& 0x40)','& 0x20)'),
        'wrong_abort_step':('= 7;','= 6;'),
        'wrong_frame_step':(' + 2;',' + 1;'),
    }
    if mutation:
        old,new=replacements[mutation];assert body.count(old)==1;body=body.replace(old,new)
    return RUNTIME_C+(ROOT/'tests/battle_effect_color_word_fixture.c.in').read_text().replace('%%CALLBACK%%',body)+ENTRY_C

def assignment_fixture(wide=False):
    # Exact source statement, without the callback's EE-sized pointer fields.
    match=re.search(r'\*\(s32 \*\)\(packet \+ 4\)\s*=\s*\*\(u32 \*\)\(packet \+ 4\) & 0x00FFFFFF;',callback())
    assert match
    statement=match[0]
    if wide:statement=statement.replace('*(u32 *)(packet + 4)', '(u32)*(u64 *)(packet + 4)')
    return '''#include "type.h"
typedef char RequireEightByteU64Alignment[__alignof__(u64)==8 ? 1 : -1];
static u8 storage[0x24] __attribute__((aligned(16)));
static int check(void) {
    u8 *packet=storage;
    *(u32 *)(packet+4)=0xaabbccddu;
    *(u32 *)(packet+8)=0x12345678u;
    '''+statement+'''
    return *(u32 *)(packet+4)!=0x00bbccddu || *(u32 *)(packet+8)!=0x12345678u;
}
void _start(void) {
    long result=check();
    __asm__ volatile("syscall" : : "a"(60L), "D"(result) : "rcx", "r11", "memory");
    __builtin_unreachable();
}
'''
class EffectColorWord(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as e:raise unittest.SkipTest(str(e))
    def execute(self,text,opt):
        with tempfile.TemporaryDirectory()as d:
            p=Path(d);f=p/'f.c';f.write_text(text);exe=self.runtime.compile(f,p/'f',opt,(ROOT/'include',));return self.runtime.run(exe)
    def test_actual_update_routes(self):
        for opt in ('-O0','-O2'):
            r=self.execute(fixture(),opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr)
            self.assertIn('4500 actual effect update cases passed',r.stdout)
    def test_independent_controls(self):
        for name in ('wrong_color_mask','wrong_color_phase','wrong_color_option','wrong_freeze_flag','wrong_abort_step','wrong_frame_step'):
            for opt in ('-O0','-O2'):
                with self.subTest(mutation=name,optimization=opt):
                    r=self.execute(fixture(name),opt);self.assertNotEqual(r.returncode,0)

class EffectColorWordAlignment(unittest.TestCase):
    def test_exact_assignment_eight_byte_alignment(self):
        if os.name!='posix' or os.uname().machine not in ('x86_64','amd64'):
            self.skipTest('Separate source-assignment sanitizer check needs x86_64 Linux')
        clang=shutil.which('clang');ld=shutil.which('ld')
        if not clang or not ld:self.skipTest('Clang and GNU ld required')
        for opt in ('-O0','-O2'):
            for wide in (False,True):
                with self.subTest(optimization=opt,original_wide_read=wide),tempfile.TemporaryDirectory()as d:
                    p=Path(d);source=p/'f.c';source.write_text(assignment_fixture(wide));obj=p/'f.o';exe=p/'f'
                    cmd=[clang,'--target=x86_64-linux-gnu','-std=c11',opt,'-ffreestanding','-fno-builtin','-fno-pie','-fno-stack-protector','-fno-strict-aliasing','-fsanitize=undefined,bounds','-fsanitize-trap=all','-I'+str(ROOT/'include'),'-c',str(source),'-o',str(obj)]
                    r=subprocess.run(cmd,capture_output=True,text=True);self.assertEqual(r.returncode,0,r.stderr)
                    r=subprocess.run([ld,'-m','elf_x86_64','-e','_start','-o',str(exe),str(obj)],capture_output=True,text=True);self.assertEqual(r.returncode,0,r.stderr)
                    r=subprocess.run([str(exe)],capture_output=True,text=True)
                    self.assertEqual(r.returncode,-4 if wide else 0,r.stdout+r.stderr)
