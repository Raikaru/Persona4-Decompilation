"""Live source storage/call ABI test. Recorders are NOT matrix providers.

Inputs for unrecovered angle/model producers are explicitly supplied. Recorder
output bytes are tagged test data including pad words, not fabricated provider
initialization. Actual provider padding remains outside the execution claim.
"""
from pathlib import Path
import re,sys,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from test_title_fade_contract import runtime
from native32_support import RUNTIME_C,ENTRY_C

def parts():
 text=(ROOT/'src/promoted/code1_0012.c').read_text();body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
 types=(ROOT/'include/btl_shuffle_draw_internal.h').read_text()
 types='\n'.join(re.search(r'typedef struct '+tag+r' \{.*?\} '+name+r';',types,re.S)[0] for tag,name in [('RwV3d','BtlShuffleVec3'),('RwMatrixTag','BtlShuffleMatrix')])
 names=('titleYawAxis','titlePitchAxis','titleTranslation','titleMatrix')
 decls=[re.search(r'(?m)^    BtlShuffle\w+ '+name+r'[^;]*;',body)[0].strip() for name in names]
 copies=[re.search(r'(?m)^    '+name+r' = [^;]+;',body)[0].strip() for name in names[:2]]
 a=body.index('            RwMatrixRotate(&titleMatrix');b=body.index('\n',body.index('func_0047a1c0(var_16_2, &titleMatrix, 0);',a));calls=body[a:b]
 signatures=[re.search(r'(?m)^extern [^\n]*\b'+name+r'\([^;]+;',text)[0].removeprefix('extern ').removesuffix(';') for name in ('RwMatrixRotate','RwMatrixTranslate','func_0047a1c0')]
 assert not any(re.search(r'extern[^\n]*\b'+name+r'\(',body) for name in ('RwMatrixRotate','RwMatrixTranslate','func_0047a1c0'))
 globals=[re.search(r'extern BtlShuffleVec3 '+name+r';',body)[0].removeprefix('extern ') for name in ('D_005E5628','D_005E5638')]
 return types,names,decls,copies,calls,signatures,globals

def fixture(mutation=None):
 types,names,decls,copies,calls,sigs,glob=parts()
 replacements={
  'swap_axes':(' &titleYawAxis,',' &titlePitchAxis,'),
  'swap_angles':('temp_f23, 0','temp_f24, 0'),
  'first_mode':('temp_f23, 0','temp_f23, 1'),
  'second_mode':('temp_f24, 2','temp_f24, 1'),
  'translate_mode':('&titleTranslation, 1','&titleTranslation, 2'),
  'model_mode':('&titleMatrix, 0);','&titleMatrix, 1);'),
  'model_pointer':('var_16_2, &titleMatrix','var_16_2 + 1, &titleMatrix'),
  'translation_y':('= -90.0f;','= 90.0f;'),
  'translation_z':('titleTranslation.z = 0.0f;','titleTranslation.z = 1.0f;'),
  'wrong_matrix':('RwMatrixTranslate(&titleMatrix','RwMatrixTranslate(&titlePitchAxis'),
  'old_rotate_order':('temp_f23, 0','0, temp_f23'),
  'omitted_translate':('RwMatrixTranslate(&titleMatrix, &titleTranslation, 1);',''),
 }
 if mutation in replacements:
  a,b=replacements[mutation];assert a in calls;calls=calls.replace(a,b,1)
 if mutation=='wrong_copy':copies[1]=copies[1].replace('D_005E5638','D_005E5628')
 if mutation=='incomplete_copy':copies[0]='titleYawAxis.x = D_005E5628.x; titleYawAxis.y = D_005E5628.y; titleYawAxis.z = 0.0f;'
 if mutation=='short_matrix':decls[3]='u32 titleMatrix[15] __attribute__((aligned(16)));'
 guard='\n'.join('typedef struct { u32 pre[4]; '+d+' u32 post[4]; } Guard'+str(i)+';' for i,d in enumerate(decls))
 macros='\n'.join('#define '+n+' g'+str(i)+'->'+n for i,n in enumerate(names))
 sizes=''.join(' CHECK(sizeof('+n+')=='+str(12 if i<3 else 64)+');' for i,n in enumerate(names)) if mutation!='short_matrix' else ''
 return RUNTIME_C+'''\ntypedef unsigned u32;typedef unsigned char u8;typedef int s32;typedef float f32;\n'''+types+'\n'+guard+'\n'+'\n'.join(glob)+r'''
#define CHECK(x) do { if(!(x)) native32_failure(__LINE__,scenario,#x); } while(0)
static unsigned scenario,stage;static void *matrixPointer;static u8 *modelPointer;
static void *axisPointer[2], *translationPointer;static BtlShuffleVec3 axisWant[2];static f32 angles[2];static u8 matrixWant[64];
static void output(void *p) {
 for(unsigned i=0;i<64;++i) matrixWant[i]=(u8)(scenario*13+stage*79+i*3);
 memcpy(p,matrixWant,64);
}
'''+sigs[0]+r''' {
 CHECK(m==matrixPointer);CHECK(stage<2);CHECK(src==axisPointer[stage]);CHECK(!memcmp(src,&axisWant[stage],12));
 CHECK(angle==angles[stage]);CHECK(mode==(stage?2:0));
 if(stage) CHECK(!memcmp(m,matrixWant,64));
 output(m);++stage;return m;
}
'''+sigs[1]+r''' {
 BtlShuffleVec3 *translation=v;CHECK(stage==2);CHECK(m==matrixPointer);CHECK(mode==1);CHECK(v==translationPointer);
 CHECK(translation->x==0&&translation->y==-90&&translation->z==0);
 CHECK(!memcmp(m,matrixWant,64));output(m);++stage;return m;
}
'''+sigs[2]+r''' {
 CHECK(stage==3);CHECK(arg0==modelPointer);CHECK(arg1==matrixPointer);CHECK(arg2==0);
 CHECK(!memcmp(arg1,matrixWant,64));++stage;
}
'''+macros+r'''
static void boundary(Guard0 *g0,Guard1 *g1,Guard2 *g2,Guard3 *g3,
                     f32 temp_f23,f32 temp_f24,u8 *var_16_2) {
'''+sizes+'\n'+'\n'.join(copies)+'\n'+calls+r'''
}
'''+ '\n'.join('#undef '+n for n in names)+r'''
int main(void) {
 typedef char VectorSize[sizeof(BtlShuffleVec3)==12?1:-1];
 typedef char MatrixSize[sizeof(BtlShuffleMatrix)==64?1:-1];
 typedef char VectorX[__builtin_offsetof(BtlShuffleVec3,x)==0?1:-1];
 typedef char VectorY[__builtin_offsetof(BtlShuffleVec3,y)==4?1:-1];
 typedef char VectorZ[__builtin_offsetof(BtlShuffleVec3,z)==8?1:-1];
 typedef char FieldRight[__builtin_offsetof(BtlShuffleMatrix,right)==0?1:-1];
 typedef char FieldPad1[__builtin_offsetof(BtlShuffleMatrix,pad1)==28?1:-1];
 typedef char FieldPad2[__builtin_offsetof(BtlShuffleMatrix,pad2)==44?1:-1];
 typedef char FieldPad3[__builtin_offsetof(BtlShuffleMatrix,pad3)==60?1:-1];
 typedef char FieldFlags[__builtin_offsetof(BtlShuffleMatrix,flags)==12?1:-1];
 typedef char FieldUp[__builtin_offsetof(BtlShuffleMatrix,up)==16?1:-1];
 typedef char FieldAt[__builtin_offsetof(BtlShuffleMatrix,at)==32?1:-1];
 typedef char FieldPos[__builtin_offsetof(BtlShuffleMatrix,pos)==48?1:-1];
 for(scenario=1;scenario<=4096;++scenario) {
  Guard0 g0;Guard1 g1;Guard2 g2;Guard3 g3;u8 model[128],modelBefore[128];
  /* Only guard bytes are initialized. The first recorder writes its matrix
   * output before any test reads that output. No provider is substituted. */
  memset(g0.pre,0xa5,16);memset(g0.post,0x5a,16);
  memset(g1.pre,0xa5,16);memset(g1.post,0x5a,16);
  memset(g2.pre,0xa5,16);memset(g2.post,0x5a,16);
  memset(g3.pre,0xa5,16);memset(g3.post,0x5a,16);
  memset(model,(int)scenario,128);memcpy(modelBefore,model,128);
  axisWant[0]=(BtlShuffleVec3){scenario*.125f,-scenario*.25f,scenario*.5f};
  axisWant[1]=(BtlShuffleVec3){-scenario*.75f,scenario*1.25f,-scenario*1.5f};
  if(scenario==1) {axisWant[0]=(BtlShuffleVec3){0,1,0};axisWant[1]=(BtlShuffleVec3){1,0,0};}
  D_005E5628=axisWant[0];D_005E5638=axisWant[1];
  angles[0]=(f32)scenario*.375f-571.25f;angles[1]=-(f32)scenario*.625f+183.875f;
  axisPointer[0]=&g0.titleYawAxis;axisPointer[1]=&g1.titlePitchAxis;translationPointer=&g2.titleTranslation;
  matrixPointer=&g3.titleMatrix;modelPointer=model+(scenario&1?0:64);stage=0;
  CHECK(!((u32)matrixPointer&15));
  boundary(&g0,&g1,&g2,&g3,angles[0],angles[1],modelPointer);CHECK(stage==4);
  CHECK(!memcmp(&g0.titleYawAxis,&axisWant[0],12));CHECK(!memcmp(&g1.titlePitchAxis,&axisWant[1],12));
  CHECK(!memcmp(&D_005E5628,&axisWant[0],12));CHECK(!memcmp(&D_005E5638,&axisWant[1],12));
  CHECK(!memcmp(model,modelBefore,128));
  u32 *guards[]={g0.pre,g0.post,g1.pre,g1.post,g2.pre,g2.post,g3.pre,g3.post};
  for(unsigned j=0;j<8;++j) for(unsigned i=0;i<4;++i) CHECK(guards[j][i]==(j&1?0x5a5a5a5a:0xa5a5a5a5));
 }
 native32_text("4096 title matrix storage/call cases passed\n");return 0;
}
'''+ENTRY_C

class TitleMatrix(unittest.TestCase):
 def run_fixture(self,opt,mutation=None):
  with tempfile.TemporaryDirectory(prefix='p4_title_matrix_') as tmp:
   p=Path(tmp);src=p/'test.c';src.write_text(fixture(mutation));rt=runtime();return rt.run(rt.compile(src,p/'test',opt))
 def test_live_storage_and_declarations(self):
  _,_,decls,copies,calls,sigs,_=parts();self.assertEqual(len(copies),2)
  self.assertIn('BtlShuffleMatrix titleMatrix',decls[-1]);self.assertIn('f32 angle, s32 mode',sigs[0])
  self.assertIn('titleTranslation.y = -90.0f;',calls)
 def test_native_boundaries(self):
  for opt in ('-O0','-O2'):
   with self.subTest(opt=opt):
    r=self.run_fixture(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr)
    self.assertEqual(r.stdout,'4096 title matrix storage/call cases passed\n');print(opt,r.stdout.strip())
 def test_negative_controls(self):
  names=('swap_axes','swap_angles','first_mode','second_mode','translate_mode','model_mode','model_pointer','translation_y','translation_z','wrong_matrix','old_rotate_order','omitted_translate','wrong_copy','incomplete_copy','short_matrix')
  for opt in ('-O0','-O2'):
   for name in names:
    with self.subTest(opt=opt,mutation=name):
     r=self.run_fixture(opt,name);self.assertNotEqual(r.returncode,0,r.stdout+r.stderr);self.assertIn('scenario',r.stdout);print(opt,name,'rejected:',r.stdout.strip())
if __name__=='__main__':unittest.main()
