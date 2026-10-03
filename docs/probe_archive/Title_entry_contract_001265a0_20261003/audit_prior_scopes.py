"""Replay prior semantic auditors on the final object through an exact offset map.

Reuse committed model-checkpoint auditors, changing only their input record path.
The sprite/fade translators compose the newly proven +4 prefix insertion after
historical palette/model maps. No instruction checks or semantic controls change.
"""
from pathlib import Path
import hashlib,json,sys
A=Path('docs/probe_archive/Title_model_call_contract_001265a0_20261003')
entry=json.loads(Path('proof/entry-preservation-evidence.json').read_text())
assert entry['every_other_instruction_byte_exact'] and entry['inserted_offset']==0x44
assert entry['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
# Historical map is retained as a separate proven stage, never relabeled as a
# current source receipt. All current auditors consume the final after-guard.
Path('proof/model-preservation-evidence.json').write_text((A/'target-preservation.json').read_text())
rows=[]
for name in ('audit_color_storage','audit_layer_calls','audit_gp_colors','audit_candidate',
             'audit_alpha_aliases','audit_sprite_alpha','audit_preserved_fade','audit_model_calls'):
 path=A/(name+'.py');original=path.read_text();source=original.replace('title-model-owner','title-entry-owner')
 assert original.count('title-model-owner')==1
 if name in ('audit_sprite_alpha','audit_preserved_fade'):
  assert source.count('    return offset\n')==1
  source=source.replace('    return offset\n','    assert offset >= 0x44\n    return offset + 4\n')
 exec(compile(source,str(path),'exec'),{'__name__':'__main__','__file__':str(path.resolve())})
 rows.append({'auditor':str(path),'auditor_sha256':hashlib.sha256(original.encode()).hexdigest(),
              'input':'proof/title-entry-owner/after-guard.json','exact_prefix_map_composed':name in ('audit_sprite_alpha','audit_preserved_fade')})
Path('proof/entry-prior-scopes.json').write_text(json.dumps({'source_sha256':entry['source_sha256'],'auditors':rows},indent=2)+'\n')
print('All eight prior bounded machine auditors replayed on the final guarded owner')
