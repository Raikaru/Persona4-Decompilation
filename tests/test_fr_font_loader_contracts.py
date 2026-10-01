"""Real font loader/wrappers and unsigned flag getter, with one pointer ABI."""
from pathlib import Path
import re
import sys
import tempfile
import unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
FONT=ROOT/'src/frFont.c'
FIXTURE=ROOT/'tests/fr_font_loader_fixture.c.in'
NAMES=('func_002716b0','func_00271380','func_002738a0')
MUTATIONS={
 'fallback_order':('func_00271380','func_002716b0(arg0, 0, arg1);','func_002716b0(arg0, arg1, 0);'),
 'fallback_slot':('func_00271380','func_002716b0(arg0, 0, arg1);','func_002716b0(8, 0, arg1);'),
 'selector_slot':('func_002738a0','func_002716b0(8, param_1, 0);','func_002716b0(7, param_1, 0);'),
 'selector_secondary':('func_002738a0','func_002716b0(8, param_1, 0);','func_002716b0(8, 0, param_1);'),
 'fallback_missing':('func_002716b0','if (arg1 == NULL && arg2 != NULL)', 'if (0)'),
 'slot_mask':('func_002716b0','temp_4 = arg0 & 0xFF;', 'temp_4 = arg0 & 7;'),
 'page_stride':('func_002716b0','<< 6','<< 5'),
 'first_header_size':('func_002716b0','temp_3 = var_17 + (slot->f08 + 4);','temp_3 = var_17 + (slot->f08 + 8);'),
 'empty_first_count':('func_002716b0','slot->f08 = 0;','slot->f08 = 1;'),
 'object_stride':('func_002716b0','(*(u16 *)(slot->f04 + 0xE) * 4)','(*(u16 *)(slot->f04 + 0xE) * 8)'),
 'cached_count':('func_002716b0','    temp_5 = arg1 + var_17;', '    u16 savedCount = *(u16 *)(slot->f04 + 0xE);\n    temp_5 = arg1 + var_17;'),
 'flag_mask':('func_00274650','return uGpffffa708 & value;','return uGpffffa708;'),
}
def fixture_source(mutation=None,wrong_declaration=None):
 text=FONT.read_text();definitions=Q.function_bodies(FONT);bodies={n:definitions[n][1]for n in NAMES}
 bodies['func_00274650']=Q.function_bodies(ROOT/'src/frFont_grouped.c')['func_00274650'][1]
 if mutation:
  n,a,b=MUTATIONS[mutation];assert bodies[n].count(a)==1;bodies[n]=bodies[n].replace(a,b)
  if mutation=='cached_count':bodies[n]=bodies[n].replace('(*(u16 *)(slot->f04 + 0xE) * 4)','(savedCount * 4)')
 end=text.index('} FrFontManagerData4;')+len('} FrFontManagerData4;');start=text.index('typedef struct FrFontSlot4 {')
 types=text[start:end]
 declarations=[]
 for p,name in [(FONT,'func_002716b0'),(ROOT/'src/Main/OpEd/ed_res.c','func_00271380'),(ROOT/'src/itfMesManager.c','func_002738a0'),(ROOT/'src/promoted/code1_0027.c','func_002738a0'),(ROOT/'src/itfMesManager.c','func_00274650')]:
  matches=re.findall(r'^\s*(?:extern\s+)?(?:void|s32|u32)\s+'+name+r'\([^;{}\n]*\);',p.read_text(),re.M);assert len(matches)==1,(p,name,matches);declarations.append(matches[0])
 decl='\n'.join(declarations)
 if wrong_declaration=='opaque_fallback':decl=decl.replace('void func_00271380(s32 slot, u8 *data);','void func_00271380(s32 slot, void *data);')
 if wrong_declaration=='signed_flag':decl=decl.replace('u32 func_00274650(u32 arg0);','s32 func_00274650(s32 arg0);')
 if wrong_declaration=='wide_selector':decl=decl.replace('void func_002738a0(u8 *arg0);','void func_002738a0(u64 arg0);')
 if wrong_declaration=='word_selector':decl=decl.replace('void func_002738a0(u8 *arg0);','void func_002738a0(s32 arg0);')
 return RUNTIME_C+FIXTURE.read_text().replace('/* @ACTUAL_TYPES@ */',types).replace('/* @ACTUAL_DECLARATIONS@ */',decl).replace('/* @ACTUAL_BODIES@ */','\n'.join(bodies.values()))+ENTRY_C
class FontLoaderContracts(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  try:cls.runtime=native32_runtime()
  except Native32Unavailable as error:raise unittest.SkipTest(str(error))from error
 def execute(self,mutation=None,wrong_declaration=None):
  with tempfile.TemporaryDirectory(prefix='p4_font_loader_')as temporary:
   d=Path(temporary);p=d/'fixture.c';p.write_text(fixture_source(mutation,wrong_declaration))
   for level in ('-O0','-O2'):
    with self.subTest(level=level,mutation=mutation,wrong_declaration=wrong_declaration):
     if wrong_declaration:
      with self.assertRaisesRegex(RuntimeError,'conflicting types'):self.runtime.compile(p,d/('fixture'+level),level,(ROOT/'include',))
      continue
     exe=self.runtime.compile(p,d/('fixture'+level),level,(ROOT/'include',));result=self.runtime.run(exe)
     if mutation:self.assertNotEqual(result.returncode,0,'negative control passed')
     else:
      self.assertEqual(result.returncode,0,result.stdout+result.stderr)
      self.assertEqual(result.stdout,'font loader contracts: 4006 scenarios passed\n')
 def test_real_loader_wrappers_and_flags(self):self.execute()
 def test_independent_body_controls(self):
  for mutation in MUTATIONS:self.execute(mutation)
 def test_old_incompatible_declarations_fail(self):
  for kind in ('signed_flag','wide_selector','word_selector','opaque_fallback'):self.execute(wrong_declaration=kind)
class FontLoaderSourceContracts(unittest.TestCase):
 def test_no_authoritative_wide_alias(self):
  for p in (ROOT/'src').rglob('*.c'):
   if 'generated'not in p.parts:self.assertNotIn('func_002716b0_typed',p.read_text(),str(p))
if __name__=='__main__':unittest.main()
