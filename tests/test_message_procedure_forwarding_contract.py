"""Actual current-main work/userdata providers and all repaired forwarding sites."""
from pathlib import Path
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
DISPATCHERS=('0027b7c0','0027b830','0027b8a0','0027b910','0027b980','0027b9e0','0027ba40','0027baa0','0027bb00','0027bb60','0027bbc0','0027bc20','0027bc80','0027bce0','0027bd40','0027bda0','0027be00')
SITES={suffix:('src/promoted/code1_0027.c','func_'+suffix) for suffix in DISPATCHERS}
SITES.update({'read':('src/itfMsgProcedure.c','func_0027b6e0'),
    'write':('src/itfMsgProcedure.c','func_0027b750'),
    'userdata':('src/Yajima/y_misc.c','func_0027BE60'),
    'store':('src/Event/Fcl/fclMisc.c','func_0027be90'),
    'word':('src/promoted/itfMsgProcedure_Window.c','func_002818a0')})
HANDLES=[(suffix,'func_00277840(arg0)') for suffix in DISPATCHERS]+[
    ('read','func_00277840(param_1)'),('write','func_00277840(param_1)'),
    ('userdata','func_00277840(handle)'),('store','func_00277840(handle)'),
    ('word','func_0027BE60(arg0)')]
def fixture_source(mutation=None):
    manager=ROOT/'src/itfMesManager.c'; text=manager.read_text()
    layout=text[text.index('typedef struct {'):text.index('void func_002746c0')]
    getter=Q.function_bodies(manager)['func_00277840'][1].replace('func_00277840','actualProcedureWork',1)
    bodies=[]
    for key,(path,name) in SITES.items():
        body=Q.function_bodies(ROOT/path)[name][1]
        if mutation and mutation[0]==key:
            before,after=mutation[1:];assert before in body,(key,before)
            body=body.replace(before,after,1)
        bodies.append(body)
    fixture=(ROOT/'tests/message_procedure_forwarding_fixture.c.in').read_text()
    fixture=fixture.replace('@DISPATCHERS@',','.join('func_'+suffix for suffix in DISPATCHERS))
    return RUNTIME_C+'''#include "message_procedure_api.h"
extern char D_0063BE10[],D_0063BF60[];
void func_0046d730(const void *,u32);
'''+layout+getter+'\n'+'\n'.join(bodies)+'\n'+fixture+ENTRY_C
class MessageProcedureForwardingContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,mutation=None,compile_failure=False):
        with tempfile.TemporaryDirectory(prefix='p4_message_forwarding_')as temporary:
            directory=Path(temporary);source=directory/'fixture.c';source.write_text(fixture_source(mutation))
            for level in ('-O0','-O2'):
                with self.subTest(level=level,mutation=mutation):
                    if compile_failure:
                        with self.assertRaisesRegex(RuntimeError,'too few arguments'):
                            self.runtime.compile(source,directory/('fixture'+level),level,(ROOT/'include',))
                        continue
                    exe=self.runtime.compile(source,directory/('fixture'+level),level,(ROOT/'include',));result=self.runtime.run(exe)
                    if mutation:self.assertNotEqual(result.returncode,0,'negative control passed')
                    else:
                        self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                        self.assertEqual(result.stdout,'message forwarding: 12800 scenarios passed\n')
    def test_actual_all_forwarding_chains(self):self.execute()
    def test_each_wrong_handle_is_rejected(self):
        for key,before in HANDLES:self.execute((key,before,before[:before.index('(')]+'(0)'))
    def test_each_omitted_handle_is_a_compile_error(self):
        for key,before in HANDLES:self.execute((key,before,before[:before.index('(')]+'()'),compile_failure=True)
    def test_argument_read_offset(self):self.execute(('read','addr + 4','addr + 8'))
    def test_argument_write_offset(self):self.execute(('write','addr + 4','addr + 8'))
    def test_userdata_read_offset(self):self.execute(('userdata','iVar1 + 0x18','iVar1 + 0x14'))
    def test_userdata_write_offset(self):self.execute(('store','iVar1 + 0x18','iVar1 + 0x14'))
    def test_full_pointer_value(self):self.execute(('store','= userdata;','= (void *)((u32)userdata & 0xFFFF);'))
    def test_word_write_offset(self):self.execute(('word','*temp_2 = arg1','temp_2[1] = arg1'))
    def test_phase_nine(self):self.execute(('0027bb60','temp_2(arg0, 9)','temp_2(arg0, 8)'))
    def test_both_work_lookups_remain(self):self.execute(('0027b980','    func_00277840(arg0);',''))
if __name__=='__main__':unittest.main()
