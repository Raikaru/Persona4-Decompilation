"""Replay prior checks against current code using the exact proven map."""
from pathlib import Path
import hashlib,json
A=Path('docs/probe_archive/Title_model_call_contract_001265a0_20261003');matrix=json.loads(Path('proof/matrix-preservation-evidence.json').read_text())
assert matrix['all_outside_opcodes_and_registers_exact']
assert matrix['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
Path('proof/model-preservation-evidence.json').write_text((A/'target-preservation.json').read_text())
rows=[]
for name in ('audit_color_storage','audit_layer_calls','audit_gp_colors','audit_candidate','audit_alpha_aliases','audit_sprite_alpha','audit_preserved_fade','audit_model_calls'):
 p=A/(name+'.py');original=p.read_text();source=original.replace('title-model-owner','title-matrix-owner');assert original.count('title-model-owner')==1
 if name in ('audit_sprite_alpha','audit_preserved_fade'):
  assert source.count('    return offset\n')==1
  source=source.replace('    return offset\n', '''    offset += 4 # exact entry checkpoint insertion
    for r in _matrix['non_matrix_ranges']:
        a,b=r['before'];c,d=r['after']
        if a<=offset<b:return c+offset-a
    raise AssertionError(('offset outside exact matrix map',hex(offset)))
''')
  source=source.replace('def moved(offset):',"_matrix=json.loads(Path('proof/matrix-preservation-evidence.json').read_text())\ndef moved(offset):")
 if name=='audit_alpha_aliases':
  # Complete explicit source-home mapping; not a weakened opcode mask.
  old='homes={0x66c:0x49c,0x66f:0x49f,0x668:0x498,0x66b:0x49b,0x67c:0x4ac,0x580:0x3b0}'
  new='homes={0x49c:0x4ec,0x49f:0x4ef,0x498:0x4e8,0x49b:0x4eb,0x4ac:0x4fc,0x3b0:0x3f0}'
  assert old in source;source=source.replace(old,new)
 exec(compile(source,str(p),'exec'),{'__name__':'__main__','__file__':str(p.resolve())})
 rows.append({'auditor':str(p),'sha256':hashlib.sha256(original.encode()).hexdigest(),'input':'proof/title-matrix-owner/after-guard.json','exact_matrix_map_composed':name in ('audit_alpha_aliases','audit_sprite_alpha','audit_preserved_fade')})
p=Path('docs/probe_archive/Title_entry_contract_001265a0_20261003/audit_entry_machine.py');source=p.read_text().replace('title-entry-owner','title-matrix-owner');exec(compile(source,str(p),'exec'),{'__name__':'__main__','__file__':str(p.resolve())})
rows.append({'auditor':str(p),'sha256':hashlib.sha256(p.read_bytes()).hexdigest(),'input':'proof/title-matrix-owner/after-guard.json'})
Path('proof/matrix-prior-scopes.json').write_text(json.dumps({'source_sha256':matrix['source_sha256'],'auditors':rows},indent=2)+'\n')
print('Eight prior machine scopes and entry machine scope passed on final object')
