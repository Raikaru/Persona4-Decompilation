"""Live registration and entry-prefix contract, not full dispatcher/renderer C.

The node layout, callback signature, registration block, first entry assignment,
and exact task getter definition are extracted from their current owners. A
small two-input dispatcher shim represents the independently authenticated retail
call boundary. Each buffer is distinct; the getter observer asserts identity
before reading, so a wrong first-input control cannot make an invalid read.
"""
from pathlib import Path
import re,sys,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from test_title_fade_contract import braced,runtime
from test_btl_motion_override_contract import definition
from native32_support import RUNTIME_C,ENTRY_C


def parts():
 text=(ROOT/'src/promoted/code1_0012.c').read_text()
 body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
 signature=re.search(r'void func_001265a0\([^\n]+\)',body)[0]
 assert signature=='void func_001265a0(void *unusedDrawData, void *task)'
 getter_declaration=re.search(r'    extern u32 func_00452560\(void \*task\);',body)[0]
 work_declaration=re.search(r'    u32 \*temp_20;',body)[0]
 entry=re.search(r'    temp_20 = [^;]+;',body)[0]
 assert entry=='    temp_20 = (u32 *)func_00452560(task);'
 updater=definition('src/promoted/code1_0012.c','func_0012aa70')
 declaration=re.search(r'    extern void func_001265a0\([^;]+;',updater)[0]
 assert declaration.strip()=='extern '+signature+';'
 start=updater.index('        u8 *drawTask = func_00460990();')
 stop=updater.index('        func_00460ac0(D_00795E60, drawTask);',start)+len('        func_00460ac0(D_00795E60, drawTask);')
 registration=updater[start:stop]
 assert '*(void (**)(void *, void *))(drawTask + 8) = func_001265a0;' in registration
 assert '*(u8 **)(drawTask + 0x10) = task;' in registration
 getter=definition('src/Kernel/sdkTask.c','func_00452560')
 assert re.fullmatch(r'u32 func_00452560\(void\* task\)\s*\{\s*return \*\(u32\*\)\(\(u8\*\)task \+ 0x38\);\s*\}',getter)
 sdk=(ROOT/'src/sdkOt.c').read_text()
 node=braced(sdk,sdk.index('struct OtPrimitiveNode {'))+';'
 assert 'void (*callback)(void *, void *);' in node
 return dict(signature=signature,getter_declaration=getter_declaration,work_declaration=work_declaration,
             entry=entry,declaration=declaration,registration=registration,getter=getter,node=node)


MUTATIONS=('first_input','swapped_dispatch','wrong_task_store','wrong_callback_slot','wrong_data_slot',
           'wrong_getter_offset','wrong_work_view','getter_bypassed','registration_omitted')


def fixture(mutation=None):
 p=parts()
 if mutation=='first_input':p['entry']=p['entry'].replace('func_00452560(task)','func_00452560(unusedDrawData)')
 if mutation=='wrong_work_view':p['entry']=p['entry'].replace('func_00452560(task);','func_00452560(task) + 1;')
 if mutation=='getter_bypassed':p['entry']='    temp_20 = (u32 *)expectedWork;'
 if mutation=='wrong_getter_offset':p['getter']=p['getter'].replace('+ 0x38','+ 0x34')
 if mutation=='wrong_task_store':p['registration']=p['registration'].replace('= task;','= (u8 *)expectedPayload;')
 if mutation=='wrong_callback_slot':p['registration']=p['registration'].replace('drawTask + 8','drawTask + 0xC')
 if mutation=='wrong_data_slot':p['registration']=p['registration'].replace('drawTask + 0x10','drawTask + 0x14')
 if mutation=='registration_omitted':p['registration']=p['registration'].replace('*(void (**)(void *, void *))(drawTask + 8) = func_001265a0;','(void)drawTask;')
 dispatch='node.callback(expectedPayload, node.callbackData);'
 if mutation=='swapped_dispatch':dispatch='node.callback(node.callbackData, expectedPayload);'
 return RUNTIME_C+r'''
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned u32; typedef int s32;
typedef struct OtPrimitiveNode OtPrimitiveNode;
'''+p['node']+r'''
_Static_assert(sizeof(OtPrimitiveNode)==0x30,"node size");
_Static_assert(__builtin_offsetof(OtPrimitiveNode,callback)==8,"callback offset");
_Static_assert(__builtin_offsetof(OtPrimitiveNode,callbackData)==0x10,"data offset");
_Static_assert(__builtin_offsetof(OtPrimitiveNode,primitive)==0x1c,"payload offset");
#define CHECK(x) do { if(!(x)) native32_failure(__LINE__,scenario,#x); } while(0)
static unsigned scenario,seen,getters,allocations,submissions;
static void *expectedTask,*expectedPayload,*expectedWork;
static struct {u32 before[4]; OtPrimitiveNode value; u32 after[4];} nodeGuard;
#define node nodeGuard.value
static struct {u32 before[4];u32 words[16];u32 after[4];} taskGuard[2],workGuard[2];
static char queue[4];
#define D_00795E60 queue
'''+p['getter']+r'''
static u32 observed_getter(void *task) {
 CHECK(task==expectedTask);++getters;
 return func_00452560(task);
}
#define func_00452560 observed_getter
'''+p['signature']+' {\n'+p['getter_declaration']+'\n'+p['work_declaration']+'\n'+p['entry']+r'''
 CHECK(temp_20==expectedWork); CHECK(unusedDrawData==expectedPayload); ++seen;
}
#undef func_00452560
_Static_assert(__builtin_types_compatible_p(__typeof__(&func_001265a0),void (*)(void*,void*)),"entry exact type");
_Static_assert(__builtin_types_compatible_p(__typeof__(node.callback),__typeof__(&func_001265a0)),"node exact type");
static u8 *func_00460990(void) { ++allocations;return (u8 *)&node; }
static void func_00460ac0(void *q,void *n) {
 CHECK(q==queue); CHECK(n==&node);
 CHECK(node.callback==func_001265a0); CHECK(node.callbackData==expectedTask);
 ++submissions;
}
static void register_draw(u8 *task) {
'''+p['declaration']+'\n'+p['registration']+r'''
}
static void run_case(unsigned selected,unsigned pattern) {
 u8 originalNode[sizeof(node)];
 u32 originalTask[2][16],originalWork[2][16];
 for(unsigned i=0;i<4;++i) nodeGuard.before[i]=nodeGuard.after[i]=0xc125a470u+i;
 for(unsigned i=0;i<sizeof(node);++i) ((u8 *)&node)[i]=(u8)(pattern+i*17);
 node.callback=0;node.callbackData=0;
 memcpy(originalNode,&node,sizeof(node));
 for(unsigned b=0;b<2;++b) {
  for(unsigned i=0;i<4;++i) {
   taskGuard[b].before[i]=taskGuard[b].after[i]=0x5e745001u+b*16+i;
   workGuard[b].before[i]=workGuard[b].after[i]=0x14c52601u+b*16+i;
  }
  for(unsigned i=0;i<16;++i) {
   taskGuard[b].words[i]=0x68412603u^pattern^(i*0x3517u)^(b*0x18032u);
   workGuard[b].words[i]=0x91483507u^pattern^(i*0x7531u)^(b*0x32081u);
  }
  taskGuard[b].words[0x38/4]=(u32)workGuard[b].words;
  taskGuard[b].words[0x34/4]=(u32)workGuard[b^1].words;
  memcpy(originalTask[b],taskGuard[b].words,64);memcpy(originalWork[b],workGuard[b].words,64);
 }
 expectedTask=taskGuard[selected].words;expectedWork=workGuard[selected].words;
 expectedPayload=(u8 *)&node+0x1c;
 CHECK(expectedTask!=expectedPayload&&expectedWork!=expectedTask&&expectedWork!=expectedPayload);
 seen=getters=allocations=submissions=0;
 register_draw(expectedTask);
 CHECK(allocations==1&&submissions==1);
 for(unsigned i=0;i<sizeof(node);++i)
  if(!(i>=8&&i<12)&&!(i>=16&&i<20)) CHECK(((u8 *)&node)[i]==originalNode[i]);
 '''+dispatch+r'''
 CHECK(seen==1&&getters==1);
 for(unsigned b=0;b<2;++b) {
  CHECK(!memcmp(originalTask[b],taskGuard[b].words,64));CHECK(!memcmp(originalWork[b],workGuard[b].words,64));
  for(unsigned i=0;i<4;++i) {
   CHECK(taskGuard[b].before[i]==0x5e745001u+b*16+i&&taskGuard[b].after[i]==taskGuard[b].before[i]);
   CHECK(workGuard[b].before[i]==0x14c52601u+b*16+i&&workGuard[b].after[i]==workGuard[b].before[i]);
  }
 }
 for(unsigned i=0;i<4;++i) CHECK(nodeGuard.before[i]==0xc125a470u+i&&nodeGuard.after[i]==nodeGuard.before[i]);
}
int main(void) {
 for(unsigned selected=0;selected<2;++selected) for(unsigned pattern=0;pattern<256;++pattern) {
  ++scenario;run_case(selected,pattern);
 }
 native32_number(scenario);native32_text(" title entry cases passed\n");return 0;
}
'''+ENTRY_C


class TitleEntryContract(unittest.TestCase):
 def execute(self,opt,mutation=None,source=None):
  with tempfile.TemporaryDirectory(prefix='p4_entry_') as tmp:
   p=Path(tmp);s=p/'test.c';s.write_text(fixture(mutation) if source is None else source);rt=runtime()
   return rt.run(rt.compile(s,p/'test',opt))
 def test_live_parts(self):
  p=parts();self.assertIn(p['getter'],fixture());self.assertIn(p['registration'],fixture())
 def test_two_input_registration_and_entry(self):
  for opt in ('-O0','-O2'):
   result=self.execute(opt);self.assertEqual(result.returncode,0,result.stdout+result.stderr)
   self.assertEqual(result.stdout,'512 title entry cases passed\n');print(opt,result.stdout.strip())
 def test_independent_controls(self):
  for mutation in MUTATIONS:
   result=self.execute('-O2',mutation);self.assertEqual(result.returncode,1,result.stdout+result.stderr)
   self.assertIn('scenario',result.stdout);print(mutation+': rejected: '+result.stdout.strip())
 def test_incompatible_callback_types_are_rejected(self):
  for old,new in [('void (*callback)(void *, void *);','s32 (*callback)(void *);'),
                  ('extern void func_001265a0(void *unusedDrawData, void *task);','extern s32 func_001265a0(void *task);')]:
   source=fixture();self.assertEqual(source.count(old),1)
   with self.assertRaisesRegex(RuntimeError,'Native32 compilation failed'):
    self.execute('-O2',source=source.replace(old,new))
   print('incompatible callback type: compile rejected')
if __name__=='__main__':unittest.main()
