"""Exact single-instruction insertion, complete reference and switch offset map."""
from pathlib import Path
import hashlib,json,struct
P=Path('proof/title-entry-owner');rec=[json.loads((P/(s+'-guard.json')).read_text()) for s in ('before','after')]
sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert rec[1]['source_sha256']==sha
f=[r['functions']['func_001265a0'] for r in rec];a,b=[bytes.fromhex(x['bytes']) for x in f]
insert=0x44
assert len(a)==16816 and len(b)==16820
assert a[:insert]==b[:insert] and a[insert:]==b[insert+4:]
assert struct.unpack_from('<I',b,insert)[0]==0x00a0202d
assert [r for r in f[0]['relocations'] if r['symbol']=='func_00452560']==[{'offset':insert,'r_type':4,'type':'R_MIPS_26','symbol':'func_00452560'}]
def moved(at):return at+4 if at>=insert else at
assert [{**r,'offset':moved(r['offset'])} for r in f[0]['relocations']]==f[1]['relocations']
switches=[]
for sec,t in rec[0]['target_tables'].items():
 now=rec[1]['target_tables'][sec]
 assert [moved(at) for at in t['entries']]==now['entries']
 assert t['entry_prefixes']==now['entry_prefixes']
 switches.append({'section':sec,'before':t['entries'],'after':now['entries'],'all_16_destinations_and_prefixes_exact':True})
for mode in ('production','guard'):
 before,after=[json.loads((P/(s+'-'+mode+'.json')).read_text()) for s in ('before','after')]
 assert before['functions']['func_0012aa70']==after['functions']['func_0012aa70']
report={'source_sha256':sha,'base':'81708cc4e9e63e3b1eae30f466c069359a8dff70','target_before_bytes':len(a),'target_after_bytes':len(b),
 'inserted_offset':insert,'inserted_word':'0x00a0202d','meaning':'daddu a0,a1,zero',
 'every_other_instruction_byte_exact':True,'every_relocation_type_symbol_addend_and_mapped_offset_exact':True,
 'reference_count':len(f[1]['relocations']),'offset_ranges':[{'before':[0,insert],'after':[0,insert]},
 {'before':[insert,len(a)],'after':[insert+4,len(b)]}],
 'switches':switches,'matched_updater_bytes_and_relocations_exact_in_both_configurations':True}
Path('proof/entry-preservation-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print('Exact a1-to-a0 insertion; all remaining bytes, references, 16 switch destinations and updater bytes/relocations preserved')
