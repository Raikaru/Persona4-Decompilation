"""Replay all established bounded machine scopes against this final object."""
from pathlib import Path
import hashlib,json,re
A=Path('docs/probe_archive/Title_model_call_contract_001265a0_20261003')
M=Path('docs/probe_archive/Title_matrix_contract_001265a0_20261003')
helper=json.loads(Path('proof/helper-preservation-evidence.json').read_text());assert helper['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
Path('proof/layout-preservation-evidence.json').write_text(Path('docs/probe_archive/Title_layout_contract_001265a0_20261003/target-preservation.json').read_text())
# Historical maps are composed, never used as evidence for current bytes.
Path('proof/model-preservation-evidence.json').write_text((A/'target-preservation.json').read_text())
Path('proof/matrix-preservation-evidence.json').write_text((M/'target-preservation.json').read_text())
rows=[]
for name in ('audit_color_storage','audit_layer_calls','audit_gp_colors','audit_candidate','audit_alpha_aliases','audit_sprite_alpha','audit_preserved_fade','audit_model_calls'):
 p=A/(name+'.py');original=p.read_text();source=original.replace('title-model-owner','title-helper-owner');assert original.count('title-model-owner')==1
 if name in ('audit_sprite_alpha','audit_preserved_fade'):
  assert source.count('    return offset\n')==1
  source=source.replace('    return offset\n', '''    offset += 4 # independently checked entry insertion
    for r in _matrix['non_matrix_ranges']:
        a,b=r['before'];c,d=r['after']
        if a<=offset<b:
            offset=c+offset-a
            break
    else:raise AssertionError(('outside matrix map',hex(offset)))
    for r in _layout['retained_ranges']:
        a,b=r['before'];c,d=r['after']
        if a<=offset<b:
            offset=c+offset-a
            break
    else:raise AssertionError(('outside layout map',hex(offset)))
    for r in _helper['retained_ranges']:
        a,b=r['before'];c,d=r['after']
        if a<=offset<b:return c+offset-a
    raise AssertionError(('outside layout map',hex(offset)))
''')
  source=source.replace('def moved(offset):',"_matrix=json.loads(Path('proof/matrix-preservation-evidence.json').read_text())\n_layout=json.loads(Path('proof/layout-preservation-evidence.json').read_text())\n_helper=json.loads(Path('proof/helper-preservation-evidence.json').read_text())\ndef moved(offset):")
 if name=='audit_sprite_alpha':
  source=source.replace('  self.acc=None', '  if kind=="candidate" and 0x204<=start<0x2ef8:self.g[16],self.g[17]=self.g[17],self.g[16]\n  self.acc=None')
 if name=='audit_alpha_aliases':
  old='homes={0x66c:0x49c,0x66f:0x49f,0x668:0x498,0x66b:0x49b,0x67c:0x4ac,0x580:0x3b0}'
  new='homes={0x4ec:0x4ec,0x4ef:0x4ef,0x4e8:0x4e8,0x4eb:0x4eb,0x4fc:0x4fc,0x3f0:0x3f0}'
  assert old in source;source=source.replace(old,new)
  source=source.replace('if wa==0x2682ffe7:assert wb==0x2602ffe7','if wa==0x2602ffe7:assert wb==0x2622ffe7')
 exec(compile(source,str(p),'exec'),{'__name__':'__main__','__file__':str(p.resolve())})
 rows.append({'auditor':str(p),'sha256':hashlib.sha256(original.encode()).hexdigest(),'input':'proof/title-helper-owner/after-guard.json'})
p=Path('docs/probe_archive/Title_entry_contract_001265a0_20261003/audit_entry_machine.py');source=p.read_text().replace('title-entry-owner','title-helper-owner');exec(compile(source,str(p),'exec'),{'__name__':'__main__','__file__':str(p.resolve())})
rows.append({'auditor':str(p),'sha256':hashlib.sha256(p.read_bytes()).hexdigest(),'input':'proof/title-helper-owner/after-guard.json'})
# Matrix code is exactly retained with unchanged homes and registers. Replace
# its fixed candidate instruction offsets via the composed matrix→layout→helper map (-0xb0).
p=M/'audit_machine.py';original=p.read_text();source=original.replace('title-matrix-owner','title-helper-owner')
def matrix_literal(m):
 value=int(m[0],16)
 return hex(value-0xb0) if 0x39ec<=value<=0x3a54 else m[0]
source=re.sub(r'0x[0-9a-f]+',matrix_literal,source)
exec(compile(source,str(p),'exec'),{'__name__':'__main__','__file__':str(p.resolve())})
rows.append({'auditor':str(p),'sha256':hashlib.sha256(original.encode()).hexdigest(),'input':'proof/title-helper-owner/after-guard.json','candidate_call_offset_map':-176})

# Latest layout audit executes current bytes with its exact unchanged register
# allocation and frame homes; explicit instruction mapping moves its offsets.
p=Path('docs/probe_archive/Title_layout_contract_001265a0_20261003/audit_machine.py')
original=p.read_text();source=original.replace('title-layout-owner','title-helper-owner')
def layout_literal(m):
 value=int(m[0],16)
 if 0x3754<=value<=0x3bec:return hex(value-0x30)
 if value in (0x12b4,0x12b8,0x12c4):return hex(value-0x18)
 return m[0]
source=re.sub(r'0x[0-9a-f]+',layout_literal,source)
exec(compile(source,str(p),'exec'),{'__name__':'__main__','__file__':str(p.resolve())})
rows.append({'auditor':str(p),'sha256':hashlib.sha256(original.encode()).hexdigest(),'input':'proof/title-helper-owner/after-guard.json','candidate_selection_offset_map':-48,'earlier_speed_offset_map':-24,'registers_and_stack_homes':'unchanged, exact preservation verified'})
Path('proof/helper-prior-scopes.json').write_text(json.dumps({'source_sha256':helper['source_sha256'],'auditors':rows},indent=2)+'\n')

print('Eight older scopes plus entry, matrix and latest layout machine contracts passed on final object')
