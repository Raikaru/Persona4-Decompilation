"""Exact non-palette instructions, explicit stack displacement and branch proof."""
from pathlib import Path
import hashlib,json,struct,collections
P=Path('proof/title-palette-owner');rec=[json.loads((P/(s+'-guard.json')).read_text()) for s in ('before','after')]
assert rec[1]['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
fns=[r['functions']['func_001265a0'] for r in rec];code=[bytes.fromhex(f['bytes']) for f in fns];words=[struct.unpack('<'+'I'*(len(c)//4),c) for c in code]
excluded=[];preserved=[]
for i,fn in enumerate(fns):
 starts=[r['offset']-4 for r in fn['relocations'] if r['symbol']=='D_005E5530' and r['r_type']==5][::(2 if i else 1)]
 ends=[r['offset']+8 for r in fn['relocations'] if r['symbol']=='func_00124bb0']
 assert len(starts)==len(ends)==5
 excluded.append(list(zip(starts,ends)));preserved.append(list(zip([0]+ends,starts+[fn['size']])))
mapping={};ranges=[]
for (sa,ea),(sb,eb) in zip(*preserved):
 assert ea-sa==eb-sb
 for oa,ob in zip(range(sa,ea,4),range(sb,eb,4)):mapping[oa]=ob
 ranges.append({'before':[sa,ea],'after':[sb,eb]})
for (sa,ea),(sb,eb) in zip(*excluded):mapping[sa]=sb;mapping[ea]=eb
# This exact home set was measured from the new complete object allocation;
# it is checked, not a blanket stack-displacement mask.
HOMES={**{v:v+0xd0 for v in range(0x2f0,0x381,16)},
 **{v:v+0x190 for v in (0x390,0x3a0,0x3b0,0x3b4,0x3c0,0x3c4,0x3d0,0x3f0)},
 0x408:0x590,0x410:0x598,
 **{v:v+0x160 for v in [*range(0x444,0x521,4),0x44f,0x457,0x45f,0x467,0x46f,0x477,0x47f,0x487,0x48f,0x497,0x49f,0x4ff,0x50b,0x50f]},
 0xfae0:0xf980}
def signed(v):return v-65536 if v&32768 else v
def branch(w):return w>>26 in (1,4,5,6,7) or w>>26==17 and w>>21&31==8
stack=[];branches=[];equal=0
for ran in ranges:
 for oa,ob in zip(range(*ran['before'],4),range(*ran['after'],4)):
  a,b=words[0][oa//4],words[1][ob//4]
  if branch(a):
   assert a>>16==b>>16
   ta=oa+4+signed(a&65535)*4;tb=ob+4+signed(b&65535)*4
   assert ta in mapping and mapping[ta]==tb,(hex(oa),hex(ta),hex(tb))
   branches.append({'before':oa,'after':ob,'destination_before':ta,'destination_after':tb})
  elif a!=b:
   assert a>>16==b>>16 and a>>21&31==29
   assert a>>26 in (9,30,31,35,40,43,49,55,57,63)
   assert HOMES[a&65535]==b&65535,(hex(oa),hex(a),hex(b))
   stack.append({'before':oa,'after':ob,'word_before':hex(a),'word_after':hex(b)})
  else:equal+=1
 # All references in these exact regions keep their position and meaning.
 def rels(fn,span):return [{**r,'offset':r['offset']-span[0]} for r in fn['relocations'] if span[0]<=r['offset']<span[1]]
 assert rels(fns[0],ran['before'])==rels(fns[1],ran['after'])
# Within excluded color/model subgraphs the only changed references are the
# five real tail loads and removal of ten fake external-SP loads.
def nonpalette(fn):
 return [(r['r_type'],r['symbol'],words[fns.index(fn)][r['offset']//4]&65535) for r in fn['relocations'] if r['symbol'] not in ('sp','D_005E5530','D_005E5540')]
assert nonpalette(fns[0])==nonpalette(fns[1])
boundaries=[]
for (sa,ea),(sb,eb) in zip(*excluded):
 def outside_palette(fn,words,start,stop):return [(r['offset']-start,r['r_type'],r['symbol'],words[r['offset']//4]&65535) for r in fn['relocations'] if start<=r['offset']<stop and r['symbol'] not in ('sp','D_005E5530','D_005E5540')]
 a=outside_palette(fns[0],words[0],sa,ea);b=outside_palette(fns[1],words[1],sb,eb)
 assert [(t,n,v) for o,t,n,v in a]==[(t,n,v) for o,t,n,v in b]
 assert a[-1][2]=='func_00124bb0'
 boundaries.append({'before':[sa,ea],'after':[sb,eb],'retained_reference_events':[(t,n,v) for o,t,n,v in a],'no_other_external_reference_changes':True})
# Switch entries preserve aliases and exact prefixes, allowing only proven homes.
for key in rec[0]['target_tables']:
 a,b=[r['target_tables'][key] for r in rec]
 for i,(oa,ob) in enumerate(zip(a['entries'],b['entries'])):
  assert mapping[oa]==ob
  for at in range(0,16,4):
   wa,wb=words[0][(oa+at)//4],words[1][(ob+at)//4]
   assert wa==wb or (wa>>16==wb>>16 and wa>>21&31==29 and HOMES[wa&65535]==wb&65535)
report={'source_sha256':rec[1]['source_sha256'],'non_palette_ranges':ranges,'excluded_palette_model_boundaries':boundaries,'exact_unchanged_words':equal,'explicit_stack_adjustments':stack,'branches_with_exact_corresponding_destinations':branches,'nonpalette_target_reference_sequence_and_addends_equal':True,'switch_prefixes_exact_except_explicit_color_home':True,'frame_before':0x520,'frame_after':0x680,'limits':'Five palette-through-model subgraphs are source-audited; model ABI/ACC are not asserted correct. No broad opcode/stack/relocation masking.'}
Path('proof/palette-preservation-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print(f'Outside five bounded subgraphs: {equal} identical words, {len(stack)} exact SP adjustments, {len(branches)} proven branch destinations; all other references preserved')
