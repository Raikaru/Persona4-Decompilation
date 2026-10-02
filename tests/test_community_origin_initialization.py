"""Strict actual-statement proof of the shared menu origin initialization.

This deliberately covers the changed four stores and the matched renderer's actual two-component
readback, not the unrelated full menu constructor or controller branches.
"""
from pathlib import Path
import re,subprocess,sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
OWNER=ROOT/'src/promoted/code1_0035.c'

def source(mutation=None):
 bodies=Q.function_bodies(OWNER);initializers=[]
 for name,arg in [('func_00356250','arg0'),('func_0035e8b0','arg2')]:
  body=bodies[name][1];statements=[]
  for offset in (4,8):
   statement=f'*(f32 *)({arg} + {offset}) = 0.0f;'
   assert body.count(statement)==1,(name,statement);statements.append(statement)
  if name=='func_00356250':assert body.index(statements[1])<body.index('id = func_00107180(m)')
  else:assert body.index('case 0:')<body.index(statements[0])<body.index(statements[1])<body.index('func_00356250(arg2);')
  if mutation=='creator_missing_x'and name=='func_00356250':statements[0]=''
  if mutation=='creator_missing_y'and name=='func_00356250':statements[1]=''
  if mutation=='creator_negative_zero'and name=='func_00356250':statements[0]=statements[0].replace('0.0f','-0.0f')
  if mutation=='controller_wrong_x'and name=='func_0035e8b0':statements[0]=statements[0].replace('0.0f','1.0f')
  if mutation=='controller_duplicate_x'and name=='func_0035e8b0':statements[1]=statements[1].replace(' + 8',' + 4')
  initializers.append('static void '+name+'_origin(u8 *'+arg+'){\n'+'\n'.join(statements)+'\n}')
 reads=[]
 for label,body in [('matched',bodies['func_00356a10'][1])]:
  assignments=[]
  for name in ('originX','originY'):
   statement=re.search(r'\b'+name+r' = \(?menu->origin\.[xy]\)?;',body).group(0);assignments.append(statement)
  reads.append('static void '+label+'_read(MenuOriginPrefix *menu,f32 *x,f32 *y){f32 originX,originY;'+''.join(assignments)+'*x=originX;*y=originY;}')
 return RUNTIME_C+r'''
#include "type.h"
#include "shd_misc_internal.h"
/* A genuine declared prefix, not an entire reconstructed menu object. */
typedef struct MenuOriginPrefix{u8 opacity;u8 unknown01[3];Vec2f origin;}MenuOriginPrefix;
_Static_assert(__builtin_offsetof(MenuOriginPrefix,origin)==4,"origin offset");
_Static_assert(__builtin_offsetof(Vec2f,y)==4,"component offset");
_Static_assert(sizeof(Vec2f)==8 && sizeof(MenuOriginPrefix)==12,"real extent");
static unsigned scenario;
#define CHECK(x)do{if(!(x))native32_failure(__LINE__,scenario,#x);}while(0)
'''+ '\n'.join(initializers+reads)+r'''
int main(void){
 static const u32 bits[]={0x3f800000u,0xbf800000u,0,0x80000000u,1,0x7fc12345u,0x7f800001u,0xff800001u};
 for(unsigned operation=0;operation<2;++operation)for(unsigned x=0;x<8;++x)
 for(unsigned y=0;y<8;++y)for(unsigned opacity=0;opacity<256;++opacity){
  struct{u32 before;MenuOriginPrefix menu;u32 after;}value;
  u8 expected[sizeof(value)];f32 rx,ry;u32 observedX,observedY;
  memset(&value,0xa5,sizeof(value));value.before=0xabcdef01;value.after=0xface3579;value.menu.opacity=(u8)opacity;
  memcpy(&value.menu.origin.x,&bits[x],4);memcpy(&value.menu.origin.y,&bits[y],4);
  memcpy(expected,&value,sizeof(value));
  unsigned offset=__builtin_offsetof(__typeof__(value),menu)+__builtin_offsetof(MenuOriginPrefix,origin);
  for(unsigned i=0;i<8;++i)expected[offset+i]=0;
  ++scenario;
  if(operation)func_0035e8b0_origin((u8*)&value.menu);else func_00356250_origin((u8*)&value.menu);
  CHECK(memcmp(&value,expected,sizeof(value))==0);
  matched_read(&value.menu,&rx,&ry);memcpy(&observedX,&rx,4);memcpy(&observedY,&ry,4);
  CHECK(observedX==0&&observedY==0);
 }
 CHECK(scenario==32768);native32_text("community origin: 32768 genuine-prefix scenarios passed\n");return 0;
}
'''+ENTRY_C

def compile_strict(runtime, source, output, level):
    """Same native32 ABI/sanitizers, with strict aliasing explicitly enabled."""
    obj = output.with_suffix('.o')
    command = [runtime.compiler, '--target=i386-linux-gnu', '-m32', '-msse2', '-mfpmath=sse',
               '-std=c11', level, '-ffreestanding', '-fno-builtin', '-fno-pie',
               '-fno-stack-protector', '-ffp-contract=off', '-fstrict-aliasing',
               '-fsanitize=undefined,bounds', '-fsanitize-trap=all',
               '-Werror=implicit-function-declaration', '-Werror=incompatible-pointer-types',
               '-Werror=int-conversion', '-I' + str(ROOT / 'include'),
               '-c', str(source), '-o', str(obj)]
    result = subprocess.run(command, capture_output=True, text=True, timeout=60)
    if result.returncode:
        raise RuntimeError('Strict native32 compilation failed:\n' + result.stdout + result.stderr)
    result = subprocess.run([*runtime.linker, '-m', 'elf_i386', '-e', '_start', '-o',
                             runtime.execution_path(output), runtime.execution_path(obj)],
                            capture_output=True, text=True, timeout=60)
    if result.returncode:
        raise RuntimeError('Strict native32 linking failed:\n' + result.stdout + result.stderr)
    header = output.read_bytes()[:20]
    assert header[:5] == b'\x7fELF\x01' and header[5] == 1 and header[18:20] == b'\x03\0'
    return output


class CommunityOriginInitialization(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  try:cls.runtime=native32_runtime()
  except Native32Unavailable as error:raise unittest.SkipTest(str(error))from error
 def execute(self,mutation=None):
  with tempfile.TemporaryDirectory(prefix='p4_community_origin_')as tmp:
   d=Path(tmp);p=d/'fixture.c';p.write_text(source(mutation))
   for level in('-O0','-O2'):
    with self.subTest(mutation=mutation,level=level):
     exe=compile_strict(self.runtime,p,d/('fixture'+level),level);result=self.runtime.run(exe)
     if mutation:
      self.assertEqual(result.returncode,1,result.stdout+result.stderr);self.assertEqual(result.stderr,'');self.assertRegex(result.stdout,r'line \d+, scenario \d+:')
     else:
      self.assertEqual(result.returncode,0,result.stdout+result.stderr);self.assertEqual(result.stdout,'community origin: 32768 genuine-prefix scenarios passed\n')
 def test_strict_initialization_and_actual_readbacks(self):self.execute()
 def test_independent_origin_controls(self):
  for mutation in ('creator_missing_x','creator_missing_y','creator_negative_zero','controller_wrong_x','controller_duplicate_x'):self.execute(mutation)

if __name__=='__main__':unittest.main()
