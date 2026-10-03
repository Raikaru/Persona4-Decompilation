"""Whole-owner exact transformation; no unlisted source change is accepted."""
from pathlib import Path
import hashlib,json,subprocess,re
BASE='c0da65b93e785858dad848163c2482b7b0d533cb'
OWNER='src/promoted/code1_0012.c'
CHANGES=[(2455, 2456, ['    extern s32 func_0047a0e0();\n'], ['    extern void func_0047a0e0(u8 *model, s32 layer, f32 speed);\n']), (2458, 2459, ['    extern s32 D_005E5230;\n'], ['    extern u8 D_005E5230[];\n']), (3015, 3016, ['                        temp_21 = (u8 *)((s32)&D_005E5230 + (var_19 * 0x28));\n'], ['                        temp_21 = D_005E5230 + var_19 * 0x28;\n']), (3079, 3080, ['                                temp_7 = (u8 *)((s32)&D_005E5230 + (var_19 * 0x28));\n'], ['                                temp_7 = D_005E5230 + var_19 * 0x28;\n']), (3115, 3116, ['                        temp_7_2 = (u8 *)((s32)&D_005E5230 + (var_17_2 * 0x28));\n'], ['                        temp_7_2 = D_005E5230 + var_17_2 * 0x28;\n']), (3152, 3153, ['                        if (D_005E5230 >= 0xF) {\n'], ['                        if (*(s32 *)D_005E5230 >= 0xF) {\n']), (3155, 3156, ['                            temp_2_11 = (u32 *)(&temp_20[D_005E5230]);\n'], ['                            temp_2_11 = (u32 *)(&temp_20[*(s32 *)D_005E5230]);\n']), (3172, 3173, ['                        if (D_005E5230 >= 0xF) {\n'], ['                        if (*(s32 *)D_005E5230 >= 0xF) {\n']), (3175, 3176, ['                            temp_2_12 = (u32 *)(&temp_20[D_005E5230]);\n'], ['                            temp_2_12 = (u32 *)(&temp_20[*(s32 *)D_005E5230]);\n']), (3753, 3754, ['            temp_7_5 = (u8 *)((s32)&D_005E5230 + (var_16 * 0x28));\n'], ['            temp_7_5 = D_005E5230 + var_16 * 0x28;\n']), (3797, 3798, ['            temp_f0_7 = (f32) *((u8 *)(&D_005E5230 + (M2C_FIELD(temp_20, u32 *, 0x84) * 0x28)));\n'], ['            temp_f0_7 = (f32)*(s32 *)(D_005E5230 + M2C_FIELD(temp_20, u32 *, 0x84) * 0x28);\n']), (3820, 3821, ['        temp_f0_9 = (f32) *((u8 *)(&D_005E5230 + (M2C_FIELD(temp_20, u32 *, 0x84) * 0x28)));\n'], ['        temp_f0_9 = (f32)*(s32 *)(D_005E5230 + M2C_FIELD(temp_20, u32 *, 0x84) * 0x28);\n']), (3833, 3836, ['            temp_f24 = (f32)(s32)(*((u8 *)((s32)&D_005E523C + temp_3_19)));\n', '            temp_f23 = (f32)(s32)(*((u8 *)((s32)&D_005E5240 + temp_3_19)));\n', '            temp_f21_3 = (f32)(s32)(*((u8 *)((s32)&D_005E5248 + temp_3_19)));\n'], ['            temp_f24 = *(f32 *)(D_005E523C + temp_3_19);\n', '            temp_f23 = *(f32 *)(D_005E5240 + temp_3_19);\n', '            temp_f21_3 = *(f32 *)(D_005E5248 + temp_3_19);\n']), (3847, 3848, ['            func_0047a0e0(var_16_2, 0, *((u8 *)((s32)&D_005E5254 + (temp_17_2 * 0x28))));\n'], ['            func_0047a0e0(var_16_2, 0, *(f32 *)(D_005E5254 + temp_17_2 * 0x28));\n'])]
old=subprocess.check_output(['git','show',BASE+':'+OWNER]).decode();lines=old.splitlines(keepends=True)
for first,last,before,after in reversed(CHANGES):
 assert lines[first:last]==before;lines[first:last]=after
new=Path(OWNER).read_text();assert ''.join(lines)==new
unchanged=[]
for path in ('src/Graphics/Model/mdlManager.c','include/btl_shuffle_draw_internal.h','src/promoted/code1_003e.c','src/renderware/plcore/bamatrix.c'):
 content=Path(path).read_bytes();assert content==subprocess.check_output(['git','show',BASE+':'+path]);unchanged.append({'path':path,'sha256':hashlib.sha256(content).hexdigest()})
fixture_path='tests/test_title_palette_storage.py'
fixture_before=subprocess.check_output(['git','show',BASE+':'+fixture_path]).decode()
fixture_after=Path(fixture_path).read_text()
assert fixture_before.count('#define D_005E5230 table[0]')==1
assert fixture_before.replace('#define D_005E5230 table[0]','#define D_005E5230 ((u8 *)table)')==fixture_after
census=[{'line':i,'text':line.strip()} for i,line in enumerate(new.splitlines(),1) if re.search(r'D_005E52(?:30|3C|40|48|54)|func_0047a0e0',line)]
uses=[]
for root in ('src','include'):
 for p in sorted(Path(root).rglob('*')):
  if p.suffix not in ('.c','.h') or 'generated' in p.parts:continue
  for i,line in enumerate(p.read_text(errors="replace").splitlines(),1):
   if 'func_0047a0e0' in line:uses.append({'path':str(p),'line':i,'text':line.strip()})
r={'base':BASE,'owner':OWNER,'source_sha256':hashlib.sha256(new.encode()).hexdigest(),'exact_source_transform':True,'changed_blocks':len(CHANGES),'palette_fixture_exact_byte_alias_update':True,'owner_census':census,'provider_use_census':uses,'provider_and_type_sources_unchanged':unchanged,'limits':'Guard-local table/read/speed contract only. Matrix/vector repair, all helpers, ACC expressions, call order, direct row-zero semantics and updater/provider remain unchanged.'}
Path('proof/layout-source-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print('Exact source transformation and complete table/provider use census verified')
