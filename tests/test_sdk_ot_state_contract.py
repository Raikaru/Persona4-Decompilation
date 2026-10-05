"""Actual SDK state constructors, shared declarations, and queued-node returns."""
from pathlib import Path
import re,sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
OWNER=ROOT/'src/sdkOt.c';HEADER=ROOT/'include/sdk_ot_state_api.h'
FIXTURE=ROOT/'tests/sdk_ot_state_fixture.c.in'
NAMES=('func_00460b60','func_00460c70')
def authoritative_path(path):
    return 'generated' not in path.parts and not any(part.startswith('.') for part in path.parts)
def source(mutation=None,header_mutation=None):
    bodies={name:Q.function_bodies(OWNER)[name][1]for name in NAMES}
    if mutation:
        name,before,after=mutation;assert bodies[name].count(before)==1
        bodies[name]=bodies[name].replace(before,after)
    header='#include "sdk_ot_state_api.h"\n'
    if header_mutation:
        before,after=header_mutation;header=HEADER.read_text();assert header.count(before)==1;header=header.replace(before,after)
    return RUNTIME_C+'\n'+header+'''
extern u8 *iGpffffba98;
extern u8 *(*D_008873F8[])(u8 *,s32);
extern u8 iGpffffaf70;
void func_0046d730(u8 *,s32);
'''+ '\n'.join(bodies.values())+'\n'+FIXTURE.read_text()+ENTRY_C
MUTATIONS={
 'kind2':(NAMES[0],'*(u16 *)(node + 0x18) = 2;','*(u16 *)(node + 0x18) = 3;'),
 'kind3':(NAMES[1],'*(u16 *)(node + 0x18) = 3;','*(u16 *)(node + 0x18) = 2;'),
 'state':(NAMES[0],'*(u32 *)(node + 0x1C) = arg1;','*(u32 *)(node + 0x1C) = arg2;'),
 'value':(NAMES[1],'*(u32 *)(node + 0x20) = arg2;','*(u32 *)(node + 0x20) = arg1;'),
 'return2':(NAMES[0],'return node;','return list;'),
 'return3':(NAMES[1],'return node;','return list;'),
 'clear2':(NAMES[0],'memset(node, 0, 0x30);','memset(node, 0, 0x2C);'),
 'clear3':(NAMES[1],'memset(node, 0, 0x30);','memset(node, 0, 0x2C);'),
 'allocator_flags':(NAMES[0],'iGpffffba98, 0x41002','iGpffffba98, 0x41001'),
 'existing_tail':(NAMES[1],'tail = *(u8 **)(list + 4);','tail = list;'),
}
class SdkOtStateContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error))from error
    def execute(self,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_ot_state_')as temporary:
            d=Path(temporary);p=d/'fixture.c';p.write_text(source(mutation))
            for level in ('-O0','-O2'):
                with self.subTest(level=level,mutation=mutation):
                    exe=self.runtime.compile(p,d/('fixture'+level),level,(ROOT/'include',));result=self.runtime.run(exe)
                    if mutation is None:
                        self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                        self.assertEqual(result.stdout,'SDK state constructors: 392 scenarios passed\n')
                    else:self.assertNotEqual(result.returncode,0,'negative control passed')
    def test_actual_constructor_bodies(self):self.execute()
    def test_independent_runtime_controls(self):
        for name,mutation in MUTATIONS.items():
            with self.subTest(name=name):self.execute(mutation)
    def test_void_return_declarations_rejected(self):
        for name in NAMES:
            with self.subTest(name=name),tempfile.TemporaryDirectory(prefix='p4_ot_abi_')as temporary:
                d=Path(temporary);p=d/'fixture.c';p.write_text(source(header_mutation=('u8 *'+name+'(', 'void '+name+'(')))
                for level in ('-O0','-O2'):
                    with self.assertRaisesRegex(RuntimeError,'conflicting types'):
                        self.runtime.compile(p,d/('fixture'+level),level,(ROOT/'include',))
    def test_authoritative_declaration_closure(self):
        self.assertTrue(authoritative_path(Path('src/sdkOt.c')))
        self.assertFalse(authoritative_path(Path('src/generated/code1_0046.c')))
        self.assertFalse(authoritative_path(Path('src/promoted/.code1_0010.probe_example.c')))
        found=set()
        for path in(ROOT/'src').rglob('*.c'):
            if not authoritative_path(path):continue
            text=path.read_text(errors='replace')
            if not any(re.search(r'\b'+name+r'\b',text)for name in NAMES):continue
            found.add(path.relative_to(ROOT).as_posix())
            self.assertIn('#include "sdk_ot_state_api.h"',text)
            self.assertNotRegex(text,r'extern\s+(?:void|u8\s*\*)\s*func_00460(?:b60|c70)\s*\(')
        self.assertEqual(found,{'src/sdkOt.c','src/promoted/code1_0010.c','src/promoted/itfMsgProcedure_Window.c'})
if __name__=='__main__':unittest.main()
