"""Source-extracted seven helper calls, exact provider types, 32-bit observers.

These execute the preserved source X expressions with initialized finite locals.
They do not establish EE ABI, upstream sine/ACC correctness or provider behavior.
"""
from pathlib import Path
import re,sys,struct,math,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tests'),str(ROOT/'tools')]
from native32_support import RUNTIME_C,ENTRY_C
from test_title_fade_contract import runtime,braced
from measure_guarded import extract_guarded_body

def parts():
 source=(ROOT/'src/promoted/code1_0012.c').read_text()
 body=extract_guarded_body(source,'FUN_001265A0','func_001265a0')
 rows=[];providers={}
 for name,count in [('func_00124f70',3),('func_00125e80',4)]:
  providers[name]=re.search(r'(?m)^void '+name+r'\([^\n]+\)',source)[0]
  assert not re.search(r'extern [^;]*'+name,body)
  calls=re.findall(r'(?m)^ +'+name+r'\([^\n]+;',body);assert len(calls)==count
  rows += [dict(callee=name,site_index=i,call=c.strip()) for i,c in enumerate(calls)]
 return rows,providers
def args(line):
 inner=line[line.index('(')+1:-2];level=0;start=0;out=[]
 for i,c in enumerate(inner):
  if c in '([':level+=1
  if c in ')]':level-=1
  if c==',' and level==0:out.append(inner[start:i].strip());start=i+1
 return out+[inner[start:].strip()]
def pack(f):return struct.unpack('<f',struct.pack('<f',f))[0]
phases=[.75,-.875,-.5,-.125,-0.,0.,.125,.49,.5,.999]
fixtures=[(2.,.5,.25,8.),(-3.,.25,-.5,4.),(.125,.75,8.,-.25),(0.,0.,0.,1.)]
case_rows=[]
for j,p in enumerate(phases):
 for a,b,c,d in fixtures:
  x=pack(pack(a*b)-pack(c*d));bright=math.trunc(pack(255*p))
  case_rows.append('{'+','.join([float(v).hex()+'f' for v in [p,a,b,c,d,x]])+','+str(bright)+'}')
def fixture(mutation=None):
 rows,providers=parts();calls=[x['call'] for x in rows]
 if mutation:
  site,field,value=mutation
  if field=='whole':calls[site]=value
  else:
   ar=args(calls[site]);ar[field]=value;calls[site]=calls[site][:calls[site].index('(')+1]+', '.join(ar)+');'
 pre=RUNTIME_C+r'''
typedef signed char s8; typedef unsigned char u8; typedef int s32; typedef unsigned u32; typedef float f32;
static unsigned scenario,seen; static u32 scenes[2][24];
static s32 exI,exB,exU,exM; static u8 *exP; static f32 exX,exY,exZ;
#define CHECK(x) do {if(!(x)) native32_failure(__LINE__,scenario,#x);}while(0)
void func_00124f70(s32 titleIndex,s32 brightness,s32 unusedArgument,s32 drawMode,u8 *sceneContext) {
 CHECK(titleIndex==exI);CHECK(brightness==exB);CHECK(unusedArgument==exU);CHECK(drawMode==exM);CHECK(sceneContext==exP);++seen;
}
void func_00125e80(f32 x,f32 y,f32 z,s32 brightness,u8 *sceneContext) {
 CHECK(x==exX);CHECK(y==exY);CHECK(z==exZ);CHECK(brightness==exB);CHECK(sceneContext==exP);++seen;
}
_Static_assert(__builtin_types_compatible_p(__typeof__(&func_00124f70),void (*)(s32,s32,s32,s32,u8*)),"124f70 exact type");
_Static_assert(__builtin_types_compatible_p(__typeof__(&func_00125e80),void (*)(f32,f32,f32,s32,u8*)),"125e80 exact type");
struct Probe {f32 phase,a,b,c,d,x;s32 brightness;};
static const struct Probe inputs[]={
'''+',\n'.join(case_rows)+'};\n'
 pre=pre.replace('void func_00124f70(s32 titleIndex,s32 brightness,s32 unusedArgument,s32 drawMode,u8 *sceneContext)',providers['func_00124f70'])
 pre=pre.replace('void func_00125e80(f32 x,f32 y,f32 z,s32 brightness,u8 *sceneContext)',providers['func_00125e80']).replace('CHECK(x==exX);CHECK(y==exY);CHECK(z==exZ);CHECK(brightness==exB);CHECK(sceneContext==exP);++seen;', 'CHECK(fparg0==exX);CHECK(fparg1==exY);CHECK(fparg2==exZ);CHECK(arg0==exB);CHECK(arg1==exP);++seen;')
 for n,call in enumerate(calls):
  pre+=f'void site{n}(s32 var_19, u32 *temp_20, f32 temp_f21, f32 temp_f20, f32 temp_f7, f32 temp_f8) {{\n'+call+'\n}\n'
 # Inputs: temp_f21 serves both dynamic phase and pulse b. Calls use distinct copies.
 body=r'''
int main(void) {
 for(unsigned p=0;p<2;++p) for(unsigned n=0;n<sizeof(inputs)/sizeof(inputs[0]);++n) {
  const struct Probe *v=&inputs[n];
  u32 saved[2][24];
  for(unsigned a=0;a<2;++a) for(unsigned i=0;i<24;++i) scenes[a][i]=0x61956241u^(a<<20)^(i*0x36175u)^n;
  memcpy(saved,scenes,sizeof(scenes));exP=(u8*)scenes[p];
'''
 for n,row in enumerate(rows):
  s=row['site_index']
  if row['callee'].endswith('4f70'):
   body+=f'exI={"(s32)(n%7+1)" if s==0 else "10"};exB={"v->brightness" if s==0 else "255"};exU={0 if s==0 else 255};exM={1 if s==0 else 64};'
   body+=f'++scenario;seen=0;site{n}((s32)(n%7+1),scenes[p],v->phase,v->a,v->c,v->d);CHECK(seen==1);\n'
  else:
   body+=f'exX={"200.0f" if s==1 else "v->x"};exY=0.;exZ=10.;exB={[178,255,255,153][s]};'
   body+=f'++scenario;seen=0;site{n}((s32)(n%7+1),scenes[p],v->b,v->a,v->c,v->d);CHECK(seen==1);\n'
 body+=r'''
  CHECK(!memcmp(saved,scenes,sizeof(scenes)));
 }
 native32_number(scenario);native32_text(" live helper expression cases passed\n");return 0;
}
'''
 return pre+body+ENTRY_C

class TitleHelperCalls(unittest.TestCase):
 def execute(self,opt,mutation=None,compile_reject=False):
  with tempfile.TemporaryDirectory(prefix='p4_title_helpers_') as tmp:
   p=Path(tmp);src=p/'fixture.c';src.write_text(fixture(mutation));rt=runtime()
   if compile_reject:
    with self.assertRaisesRegex(RuntimeError,'Native32 compilation failed'):rt.compile(src,p/'test',opt)
    return
   return rt.run(rt.compile(src,p/'test',opt))
 def test_live_source_and_provider_types(self):
  rows,providers=parts()
  self.assertEqual(providers['func_00124f70'],'void func_00124f70(s32 titleIndex, s32 brightness, s32 unusedArgument, s32 drawMode, u8 *sceneContext)')
  self.assertEqual(providers['func_00125e80'],'void func_00125e80(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, u8 *arg1)')
  self.assertEqual([args(r['call'])[0] for r in rows[3:]],['(temp_f20 * temp_f21 - temp_f7 * temp_f8)','200.0f','(temp_f20 * temp_f21 - temp_f7 * temp_f8)','(temp_f20 * temp_f21 - temp_f7 * temp_f8)'])
 def test_native_expressions(self):
  for opt in ('-O0','-O2'):
   r=self.execute(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr);print(opt,r.stdout.strip())
 def test_all_argument_fields(self):
  rows,_=parts()
  for opt in ('-O0','-O2'):
   for n,row in enumerate(rows):
    values=['99','0','1','2','(u8 *)0'] if n<3 else ['201.0f','1.0f','11.0f','1','(u8 *)0']
    for field,value in enumerate(values):
     with self.subTest(opt=opt,site=n,field=field):
      r=self.execute(opt,(n,field,value));self.assertEqual(r.returncode,1,r.stdout+r.stderr);self.assertIn('scenario',r.stdout)
   print(opt,'35 independent argument-field controls rejected')
 def test_direct_narrowing_traps(self):
  for opt in ('-O0','-O2'):
   r=self.execute(opt,(0,1,'(s8)(255.0f * temp_f21)'))
   # WSL --exec reports the signal number directly on Windows.
   # Trap must be SIGILL, not the recorder's ordinary mismatch exit(1).
   sigill_codes = (-4, 132, 4) if runtime().windows else (-4, 132)
   self.assertIn(r.returncode,sigill_codes,r.stdout+r.stderr);self.assertNotIn('scenario',r.stdout)
   print(opt,'direct float-to-s8 sanitizer SIGILL:',r.returncode)
 def test_compile_type_controls(self):
  rows,_=parts();mutations=[]
  for n,row in enumerate(rows):
   ar=args(row['call'])
   if n>=3:
    old=[ar[3],'temp_20',*ar[:3]];mutations.append((n,'whole',row['callee']+'('+', '.join(old)+');'))
   else:
    ar.pop(2);mutations.append((n,'whole',row['callee']+'('+', '.join(ar)+');'))
   mutations.append((n,4,'temp_20'))
  mutations.append((0,3,'(u32 *)1'))
  for opt in ('-O0','-O2'):
   for mutation in mutations:
    with self.subTest(opt=opt,mutation=mutation):self.execute(opt,mutation,True)
   print(opt,'15 wrong-order/arity/pointer-type controls rejected')
if __name__=='__main__':unittest.main()
