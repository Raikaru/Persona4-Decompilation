"""Actual queued rectangle payload ownership, typed snapshots and vertex extent."""
from pathlib import Path
import re,sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
OWNERS={
 'src/sdkOt.c':('func_00460ac0','func_00460b60','func_00460c70'),
 'src/promoted/code1_0045.c':('func_00457120','func_0045ce40','func_0045d890'),
 'src/sdkPrimitive.c':('func_0045da40',),
 'src/promoted/itfMsgProcedure_Window.c':('func_0027d660',),
}
HEADER=ROOT/'include/primitive_rectangle_packet.h'
FIXTURE=ROOT/'tests/rectangle_payload_fixture.c.in'
def source(mutation=None,header_mutation=None):
 bodies={name:Q.function_bodies(ROOT/owner)[name][1]for owner,names in OWNERS.items()for name in names}
 if mutation:
  name,before,after=mutation;assert bodies[name].count(before)==1,(name,before);bodies[name]=bodies[name].replace(before,after)
 header='#include "primitive_rectangle_packet.h"\n'
 if header_mutation:
  before,after=header_mutation;header=HEADER.read_text();assert header.count(before)==1;header=header.replace(before,after)
 text=(ROOT/'src/promoted/code1_0045.c').read_text();a=text.index('typedef struct Code45RenderState {');b=text.index('} Code45RenderState;',a)+len('} Code45RenderState;')
 return RUNTIME_C+'\n'+header+'#include "sdk_ot_state_api.h"\n'+text[a:b]+'''
extern s32 iGpffffba80;
extern u8 *iGpffffba98;
extern u8 iGpffffaf70, D_007124C0[];
extern f32 D_008872F8_abs[];
extern Code45RenderState D_00712490[6];
extern void *(*jtbl_008873E8[])(u32,u32);
extern u8 *(*D_008873F8[])(u8 *,s32);
extern void (*D_00887304[])();
extern void (*D_00887300[])();
extern void (*D_008873EC[])(void *);
extern s32 (*D_00887310[])(s32,void *,s32);
void func_0044ea90(void *,s32);
void func_0046d730(u8 *,s32);
u8 *func_00460990(void);
void RpSkyRenderStateSet(s32,s32);
void func_00489f80(void);
void func_0048a000(void);
'''+ '\n'.join(bodies.values())+'\n'+FIXTURE.read_text()+ENTRY_C
MUTATIONS={
 'color_channel':('func_0045da40','packet.color = arg0->bytes;','packet.color = arg0->bytes; packet.color.rgba[3] = packet.color.rgba[0];'),
 'rectangle_word':('func_0045da40','packet.rectangle.transport = pos.transport;','packet.rectangle.transport = pos.transport; packet.rectangle.bits[2] = packet.rectangle.bits[3];'),
 'depth':('func_0045da40','packet.depth = fparg0;','packet.depth = fparg0 + 1.0f;'),
 'save_state':('func_0045da40','packet.saveState = arg2;','packet.saveState = 0;'),
 'late_color_snapshot':('func_0045da40',
  'packet.color = arg0->bytes;\n    packet.rectangle.transport = pos.transport;\n    packet.depth = fparg0;\n    packet.saveState = arg2;\n    func_0044ea90(D_007124C0, 0x101);',
  'packet.rectangle.transport = pos.transport;\n    packet.depth = fparg0;\n    packet.saveState = arg2;\n    func_0044ea90(D_007124C0, 0x101);\n    packet.color = arg0->bytes;'),
 'late_rectangle_snapshot':('func_0045da40',
  'pos.transport = arg1->transport;\n    packet.color = arg0->bytes;\n    packet.rectangle.transport = pos.transport;\n    packet.depth = fparg0;\n    packet.saveState = arg2;\n    func_0044ea90(D_007124C0, 0x101);',
  'packet.color = arg0->bytes;\n    packet.depth = fparg0;\n    packet.saveState = arg2;\n    func_0044ea90(D_007124C0, 0x101);\n    pos.transport = arg1->transport;\n    packet.rectangle.transport = pos.transport;'),
 'allocation_size':('func_0045da40','(0x1C, 0x40000)','(0x18, 0x40000)'),
 'allocation_hint':('func_0045da40','(0x1C, 0x40000)','(0x1C, 0x40001)'),
 'copy_extent':('func_0045da40','memcpy(temp_2, &packet, 0x1C);','memcpy(temp_2, &packet, 0x18);'),
 'callback_slot':('func_0045da40','(temp_2_2 + 8) = func_0045d890;','(temp_2_2 + 12) = func_0045d890;'),
 'payload_slot':('func_0045da40','(temp_2_2 + 0x10) = temp_2;','(temp_2_2 + 0x14) = temp_2;'),
 'queue':('func_0045da40','func_00460ac0((void *)arg3, temp_2_2);','func_00460ac0((u8 *)arg3 + 0x80, temp_2_2);'),
 'signed_view':('func_0045d890','work.pos = packet->rectangle.signedWords;','work.pos = packet->rectangle.signedWords; work.pos.word[2] = work.pos.word[3];'),
 'state_field':('func_0045d890','D_00887300[0](p->state, p->val);','D_00887300[0](p->state, p->state);'),
 'restore_slot':('func_0045d890','p->state, work.saved[j]','p->state, work.saved[0]'),
 'draw_count':('func_0045d890','D_00887310[0](4, work.out, 4);','D_00887310[0](4, work.out, 3);'),
 'free':('func_0045d890','D_008873EC[0](arg1);',''),
 'last_vertex_alpha':('func_0045ce40','v7[59] = (f32)colors[3];','v7[59] = (f32)colors[2];'),
 'height_word':('func_0045ce40','v7[33] = (f32)(pos[1] + pos[3]);','v7[33] = (f32)(pos[1] + pos[2]);'),
 'camera_near':('func_0045ce40','inv = 1.0f / *(f32 *)((u8 *)result + 0x80);','inv = 1.0f;'),
 'helper_color':('func_0027d660','color = clearColor;','color = clearColor; color.bytes.rgba[0] = 1;'),
 'helper_rectangle':('func_0027d660','q1.bits[2] = arg2;','q1.bits[2] = arg3;'),
 'helper_state':('func_0027d660','func_00460c70(arg4, 0x3, 0x31003);','func_00460c70(arg4, 0x3, 0x31002);'),
 'helper_begin':('func_0027d660','func_00489f80();',''),
 'helper_end':('func_0027d660','func_0048a000();',''),
 'append_tail':('func_00460ac0','tail = *(u8 **)(list + 4);','tail = list;'),
}
class RectanglePayloadContracts(unittest.TestCase):
 @classmethod
 def setUpClass(cls):
  try:cls.runtime=native32_runtime()
  except Native32Unavailable as error:raise unittest.SkipTest(str(error))from error
 def execute(self,mutation=None):
  with tempfile.TemporaryDirectory(prefix='p4_rect_payload_')as temporary:
   d=Path(temporary);p=d/'fixture.c';p.write_text(source(mutation))
   for level in ('-O0','-O2'):
    with self.subTest(level=level,mutation=mutation):
     exe=self.runtime.compile(p,d/('fixture'+level),level,(ROOT/'include',));result=self.runtime.run(exe)
     if mutation is None:
      self.assertEqual(result.returncode,0,result.stdout+result.stderr);self.assertEqual(result.stdout,'rectangle payload: 17670 scenarios passed\n')
     else:self.assertNotEqual(result.returncode,0,'negative control passed')
 def test_actual_payload_pipeline(self):self.execute()
 def test_independent_runtime_controls(self):
  for name,mutation in MUTATIONS.items():
   with self.subTest(name=name):self.execute(mutation)
 def test_wrong_callback_signature_rejected(self):
  with tempfile.TemporaryDirectory(prefix='p4_rect_signature_')as temporary:
   d=Path(temporary);p=d/'fixture.c';p.write_text(source(header_mutation=('void func_0045d890(void *unused, u8 *work);','void func_0045d890(void);')))
   for level in ('-O0','-O2'):
    with self.assertRaisesRegex(RuntimeError,'conflicting types'):self.runtime.compile(p,d/('fixture'+level),level,(ROOT/'include',))
 def test_authoritative_caller_closure(self):
  found=set()
  for path in(ROOT/'src').rglob('*.c'):
   if 'generated' in path.parts or any(part.startswith('.')for part in path.parts):continue
   text=path.read_text(errors='replace')
   if not re.search(r'\bfunc_0045da40\b',text):continue
   found.add(str(path.relative_to(ROOT)));self.assertIn('#include "primitive_rectangle_packet.h"',text)
   self.assertNotRegex(text,r'extern\s+void\s+func_0045da40\s*\(')
  self.assertEqual(found,{'src/sdkPrimitive.c','src/promoted/itfMsgProcedure_Window.c'})
if __name__=='__main__':unittest.main()
