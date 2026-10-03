"""Live typed model call boundaries; ACC producers are explicit supplied inputs.

The actual provider is NOT executed: its pre-existing uninitialized matrix
flags OR prevents claiming defined native execution. Its exact source signature
is extracted for the recorder, and the whole-owner MATCH is gated separately.
"""
from pathlib import Path
import re,sys,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests'),str(ROOT/'docs/probe_archive/Title_model_call_contract_001265a0_20261003')]
from measure_guarded import extract_guarded_body
from test_title_fade_contract import runtime
from native32_support import RUNTIME_C,ENTRY_C
from model_recovery import arguments


def parts():
 text=(ROOT/'src/promoted/code1_0012.c').read_text()
 body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
 calls=re.findall(r'(?m)^ +func_00124bb0\([^\n]+;',body)
 assert len(calls)==5 and all(len(arguments(c))==12 for c in calls)
 signature=re.search(r'void func_00124bb0\(s32 arg0,.*?u32 \*arg4\)',text,re.S)[0]
 assert 'extern s32 func_00124bb0' not in body
 decls=[]
 names=set(re.findall(r'\b(?:temp|var)_\w+\b','\n'.join(calls)))
 for name in sorted(names):
  decls.append(re.search(r'(?m)^    (?:s32|u32|f32|u8) \*?'+name+r';',body)[0].strip())
 top=[]
 for name in ('temp_9_3','temp_9_6','temp_9_9'):
  assert len(re.findall(r'\b'+name+r'\b',body))==3
  assert 'u32 '+name+';' in body
  top.append(re.search(r'(?m)^ +'+name+r' = [^;]+;',body)[0].strip())
 for name in ('var_8','var_8_2','var_8_3'):
  if name not in names:decls.append(re.search(r'(?m)^    (?:s32|u32|f32|u8) '+name+r';',body)[0].strip())
 return signature,calls,decls,top


def fixture(mutation=None,supplied=True):
 signature,calls,decls,top=parts();generated=[]
 for group,line in enumerate(calls):
  args=arguments(line)
  if group in (2,3):
   assert [args[i] for i in (1,3,4,5,6,9)]==['(temp_f20 * temp_f21 + temp_f7 * temp_f8)']*6
   # The six occurrences are unrecovered producer boundaries. This explicit
   # fixture mode supplies independently tagged outputs, not guessed arithmetic.
   if supplied:
    for lane,pos in enumerate((1,2,3,4,5,6,9)):
     if lane!=1:args[pos]='supplied['+str(lane)+']'
  if mutation and mutation.startswith('site_'):
   _,site,kind=mutation.split('_');site=int(site)
   if site==group:
    if kind.startswith('float'):
     lane=int(kind[5:]);positions=(1,2,3,4,5,6,9);a=positions[lane];b=positions[(lane+1)%7];args[a],args[b]=args[b],args[a]
    elif kind=='colors':args[7],args[8]=args[8],args[7]
    elif kind=='flags':args[10]='0'
    elif kind=='pointer':args[11]='temp_20 + 1'
    elif kind=='model':args[0]='0'
    elif kind=='roundtrip':args[0]=re.sub(r'^M2C_BITWISE\(s32, \(f32\) (.*)\)$',r'\1',args[0])
    elif kind=='basealpha':args[7]=args[7].replace(' | 0xFF','')
    elif kind=='highlightalpha':args[8]=args[8].rsplit(' | 0xFF',1)[0]
  packed=top[(0,1,4).index(group)] if group in (0,1,4) else ''
  if mutation=='signed_top' and group==0:packed=packed.replace('(u32) ','')
  generated.append('case '+str(group)+': '+packed+'\n func_00124bb0('+', '.join(args)+'); break;')
 return RUNTIME_C+r'''
typedef unsigned char u8; typedef unsigned u32; typedef int s32; typedef float f32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((u8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
typedef struct { u32 words[6]; } TitlePalette;
typedef union { u32 bits; f32 value; } Word;
typedef struct { s32 model; f32 x,z,pitch,yaw,roll,scale; s32 palette,extra1,extra2; } Record;
typedef char RecordSize[sizeof(Record)==40?1:-1];
#define CHECK(x) do { if(!(x)) native32_failure(__LINE__,scenario,#x); } while(0)
static unsigned scenario,group,row,index,pattern,seen;
static u32 base,highlight,models[128];
static f32 want[7];static s32 want_model;
'''+signature+r''' {
 f32 actual[7]={fparg0,fparg1,fparg2,fparg3,fparg4,fparg5,fparg6};
 CHECK(!memcmp(actual,want,sizeof(actual)));CHECK(arg0==want_model);
 CHECK(arg1==base);CHECK(arg2==highlight);CHECK(arg3==(group==2||group==3?0x40:0x42));
 CHECK(arg4==models+row);++seen;
}
static void run_case(unsigned raw) {
 Record records[19];
 TitlePalette firstBase,secondBase,thirdBase,fourthBase,fifthBase;
 s32 D_005E5370,D_005E5398;
 f32 supplied[7];
'''+ '\n'.join(decls)+r'''
 u8 red=(u8)(pattern*37+19),green=(u8)(pattern*71+41),blue=(u8)(pattern*109+83);
 u32 sample=0x96c31547u;
 if(pattern<1024) { unsigned channel=pattern/256,byte=pattern%256;
  sample=(sample&~(255u<<(channel*8)))|(byte<<(channel*8)); }
 if(pattern<768) { if(pattern<256) red=pattern;else if(pattern<512) green=pattern-256;else blue=pattern-512; }
 for(unsigned i=0;i<19;++i) {
  records[i].model=(i&1)?-(s32)i-1:(s32)i+1;
  records[i].x=(f32)i*1.25f-9.75f;records[i].z=(f32)i*-2.25f+13.125f;
  records[i].pitch=(f32)i*3.5f-74.5f;records[i].yaw=(f32)i*-4.75f+53.25f;
  records[i].roll=(f32)i*5.25f-117.875f;records[i].scale=(f32)i*.375f+1.0625f;
  records[i].palette=i%6;
 }
 records[17].model=-16777217;records[18].model=16777217;
 for(unsigned i=0;i<6;++i) firstBase.words[i]=secondBase.words[i]=thirdBase.words[i]=fourthBase.words[i]=fifthBase.words[i]=sample^(i*0x132735u);
 base=(firstBase.words[index]&0xffffff00u)|255u;
 highlight=((u32)red<<24)|((u32)green<<16)|((u32)blue<<8)|255u;
 temp_7=temp_7_2=temp_7_5=(u8 *)&records[row];
 temp_9=temp_9_4=temp_9_7=temp_8_3=temp_8_5=index;
 temp_20=models+row;
 var_8=var_8_2=var_8_3=var_7=var_7_2=red;
 var_6_3=var_6_6=var_6_9=var_6_12=var_6_15=green;
 var_3_6=var_3_7=var_3_8=var_3_9=var_3_34=blue;
 D_005E5370=D_005E5398=records[row].model;
 want_model=(s32)(f32)records[row].model;
 supplied[0]=want[0]=records[row].x; supplied[1]=want[1]=0;
 supplied[2]=want[2]=records[row].z; supplied[3]=want[3]=records[row].pitch;
 supplied[4]=want[4]=records[row].yaw; supplied[5]=want[5]=records[row].roll;
 supplied[6]=want[6]=records[row].scale;
 temp_f20=1.25f;temp_f21=-.5f;temp_f7=2.75f;temp_f8=.125f;
 if(raw&&(group==2||group==3)) for(unsigned i=0;i<7;++i) if(i!=1) want[i]=1.25f*-.5f+2.75f*.125f;
 seen=0;switch(group) {
'''+ '\n'.join(generated)+r'''
 }
 CHECK(seen==1);
}
int main(void) {
 for(group=0;group<5;++group) for(row=0;row<19;++row)
 for(index=0;index<6;++index) for(pattern=0;pattern<1024;++pattern) {
  ++scenario;run_case('''+str(0 if supplied else 1)+r''');
 }
 native32_number(scenario);native32_text(" title model call cases passed\n");return 0;
}
'''+ENTRY_C

class TitleModelCalls(unittest.TestCase):
 def execute(self,opt,mutation=None,supplied=True):
  with tempfile.TemporaryDirectory(prefix='p4_model_') as tmp:
   p=Path(tmp);src=p/'test.c';src.write_text(fixture(mutation,supplied));rt=runtime()
   return rt.run(rt.compile(src,p/'test',opt))
 def test_live_source_and_signature(self):
  signature,calls,decls,top=parts();self.assertEqual(len(calls),5)
  self.assertIn('u32 arg1, u32 arg2',signature)
  self.assertEqual(len(top),3)
 def test_call_transport(self):
  for opt in ('-O0','-O2'):
   for supplied in (False,True):
    with self.subTest(opt=opt,supplied=supplied):
     result=self.execute(opt,supplied=supplied)
     self.assertEqual(result.returncode,0,result.stdout+result.stderr)
     self.assertEqual(result.stdout,'583680 title model call cases passed\n')
     print(opt,'supplied' if supplied else 'unaltered expressions',result.stdout.strip())
 def test_independent_controls(self):
  for site in range(5):
   for kind in [*['float'+str(i) for i in range(7)],'colors','flags','pointer','model','roundtrip','basealpha','highlightalpha']:
    name='site_'+str(site)+'_'+kind
    with self.subTest(mutation=name):
     result=self.execute('-O2',name)
     self.assertNotEqual(result.returncode,0,result.stdout+result.stderr)
     self.assertIn('scenario',result.stdout);print(name+': rejected: '+result.stdout.strip())
  result=self.execute('-O2','signed_top');self.assertNotEqual(result.returncode,0)
  print('signed top-byte shift: sanitizer rejected')
if __name__=='__main__':unittest.main()
