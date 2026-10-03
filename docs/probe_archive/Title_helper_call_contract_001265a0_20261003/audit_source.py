"""Exact whole-source repair and complete authoritative helper use census."""
from pathlib import Path
import hashlib,json,subprocess,re
BASE='6807e26bf4896fd803f01b9cb9182ea3df8d3a86';OWNER='src/promoted/code1_0012.c'
ROWS=[{'callee': 'func_00124f70', 'site_index': 0, 'retail_call': '0x126fd0', 'old': 'func_00124f70(var_19, M2C_BITWISE(s8, (255.0f * temp_f21)), 0, (u32 *)1, temp_20);', 'proposed': 'func_00124f70(var_19, (s32)(255.0f * temp_f21), 0, 1, (u8 *)temp_20);'}, {'callee': 'func_00124f70', 'site_index': 1, 'retail_call': '0x128258', 'old': 'func_00124f70(0xA, 0xFF, 0xFF, (u32 *)0x40, temp_20);', 'proposed': 'func_00124f70(0xA, 0xFF, 0xFF, 0x40, (u8 *)temp_20);'}, {'callee': 'func_00124f70', 'site_index': 2, 'retail_call': '0x129ee4', 'old': 'func_00124f70(0xA, 0xFF, 0xFF, (u32 *)0x40, temp_20);', 'proposed': 'func_00124f70(0xA, 0xFF, 0xFF, 0x40, (u8 *)temp_20);'}, {'callee': 'func_00125e80', 'site_index': 0, 'retail_call': '0x126cd0', 'old': 'func_00125e80(0xB2, temp_20, (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f);', 'proposed': 'func_00125e80((temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f, 0xB2, (u8 *)temp_20);'}, {'callee': 'func_00125e80', 'site_index': 1, 'retail_call': '0x128e54', 'old': 'func_00125e80(0xFF, temp_20, 200.0f, 0.0f, 10.0f);', 'proposed': 'func_00125e80(200.0f, 0.0f, 10.0f, 0xFF, (u8 *)temp_20);'}, {'callee': 'func_00125e80', 'site_index': 2, 'retail_call': '0x129008', 'old': 'func_00125e80(0xFF, temp_20, (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f);', 'proposed': 'func_00125e80((temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f, 0xFF, (u8 *)temp_20);'}, {'callee': 'func_00125e80', 'site_index': 3, 'retail_call': '0x129a88', 'old': 'func_00125e80(0x99, temp_20, (temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f);', 'proposed': 'func_00125e80((temp_f20 * temp_f21 - temp_f7 * temp_f8), 0.0f, 10.0f, 0x99, (u8 *)temp_20);'}]
PROVIDERS={'0x124f70': {'signature': 'void func_00124f70(s32 titleIndex, s32 brightness, s32 unusedArgument, s32 drawMode, u8 *sceneContext)', 'source_body_sha256': 'c80db20c0bac99d5e3cc33b49ed23a461bd482f5a95c2649e9b56dc8e1e66cc9', 'retail_sha256': '8fc5ab1ddf822fcac3af00df7b6977c2957204b44aa4203bda4a0eb99b35e07b'}, '0x125e80': {'signature': 'void func_00125e80(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, u8 *arg1)', 'source_body_sha256': '245380dfb2f3bfb4280dea34ae41c34dd452dfbd23ba67eff6685bd96dffd7d4', 'retail_sha256': 'e2d8357bcb621d8ecda764d53c95d5e4b58bda3c0643efc460eb79647ca428c6'}}
old=subprocess.check_output(['git','show',BASE+':'+OWNER]).decode();expected=old
for name in ('func_00124f70','func_00125e80'):
 line='    extern s32 '+name+'();\n';assert expected.count(line)==1;expected=expected.replace(line,'')
for row in ROWS:
 assert row['old'] in expected;expected=expected.replace(row['old'],row['proposed'],1)
new=Path(OWNER).read_text();assert expected==new
# Whole-source exact reconstruction also preserves every provider and 00126090.
def definition(text,name):
 first=text.index('void '+name+'(');end=text.index('{',first)+1;depth=1
 while depth:depth+=(text[end]=='{')-(text[end]=='}');end+=1
 return text[first:end]
providers={}
for key,p in PROVIDERS.items():
 name='func_'+key[2:].zfill(8);body=definition(new,name)
 assert body==definition(old,name) and body.startswith(p['signature']+'\n{')
 assert hashlib.sha256(body.encode()).hexdigest()==p['source_body_sha256']
 providers[name]=p
census=[]
files=subprocess.check_output(['git','ls-files','src','include'],text=True).splitlines()
for f in files:
 if f.startswith('src/generated/') or Path(f).suffix not in ('.c','.h'):continue
 for n,line in enumerate(Path(f).read_text(errors='replace').splitlines(),1):
  if re.search(r'\bfunc_0012(?:4f70|5e80|6090)\b',line):census.append({'path':f,'line':n,'text':line.strip()})
assert sum('func_00124f70(' in x['text'] for x in census)==4
assert sum('func_00125e80(' in x['text'] for x in census)==5
before26090=[l.strip() for l in old.splitlines() if 'func_00126090' in l];after26090=[l.strip() for l in new.splitlines() if 'func_00126090' in l];assert before26090==after26090
r={'base':BASE,'source_sha256':hashlib.sha256(new.encode()).hexdigest(),'exact_whole_source_transform':True,'removed_shadows':2,'calls':ROWS,'providers':providers,'authoritative_use_census':census,'00126090_unchanged':after26090,'pulse_X_expressions_unchanged':3,'limits':'Source expressions retained without claiming their sine/ACC geometry is correct. Five integer lanes retained despite unused a2. No provider body or signature change.'}
Path('proof/helper-source-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print('Exact whole-source transform: two shadows, seven calls; all provider bodies, pulse X expressions and 00126090 unchanged')
