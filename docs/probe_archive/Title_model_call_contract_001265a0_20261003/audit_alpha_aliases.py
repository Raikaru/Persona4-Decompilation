"""Revalidate the two earlier alpha slices and all 52 color extents after reallocation."""
from pathlib import Path
import hashlib,json,struct
P=Path('proof/title-model-owner');rec=[json.loads((P/(s+'-guard.json')).read_text()) for s in ('before','after')]
sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert rec[1]['source_sha256']==sha
f=[r['functions']['func_001265a0'] for r in rec];d=[bytes.fromhex(x['bytes']) for x in f];objects={};rows=[]
# Explicit object/frame allocation observations, not a general immediate mask.
homes={0x66c:0x49c,0x66f:0x49f,0x668:0x498,0x66b:0x49b,0x67c:0x4ac,0x580:0x3b0}
for sym in ('fGpffff9c80','fGpffff9c84'):
 loads=[next(r['offset'] for r in x['relocations'] if r['symbol']==sym) for x in f];starts=loads[:]
 if sym.endswith('84'):starts=[max(r['offset'] for r in x['relocations'] if r['symbol']=='fGpffff8094' and r['offset']<at) for x,at in zip(f,starts)]
 ends=[next(r['offset']+8 for r in x['relocations'] if r['symbol']=='func_0045d6e0' and r['offset']>at) for x,at in zip(f,starts)]
 assert ends[0]-starts[0]==ends[1]-starts[1]
 changes=[]
 for a,b in zip(range(starts[0],ends[0],4),range(starts[1],ends[1],4)):
  wa,wb=[struct.unpack_from('<I',dd,at)[0] for dd,at in zip(d,(a,b))]
  if wa==wb:continue
  if wa==0x2682ffe7:assert wb==0x2602ffe7 # live frame s4->s0, still frame-25
  else:assert wa>>16==wb>>16 and wa>>21&31==29 and homes[wa&65535]==wb&65535
  changes.append({'before':a,'after':b,'word_before':hex(wa),'word_after':hex(wb)})
 def rels(fn,start,end):return [{**r,'offset':r['offset']-start} for r in fn['relocations'] if start<=r['offset']<end]
 assert rels(f[0],starts[0],ends[0])==rels(f[1],starts[1],ends[1])
 w=struct.unpack_from('<I',d[1],loads[1]+4)[0];assert w>>26==57 and w>>21&31==29
 objects[sym]=w&65535;rows.append({'symbol':sym,'before':[starts[0],ends[0]],'after':[starts[1],ends[1]],'all_words_and_references_checked':True,'explicit_allocation_changes':changes})
colors=json.loads(Path('proof/candidate-color-families.json').read_text())['candidate_objects'];all_colors=list(colors.values())+list(objects.values());assert len(all_colors)==len(set(all_colors))==52
palette=json.loads(Path('proof/palette-machine-evidence.json').read_text());palettes=[r['source_sp'] for r in palette['snapshots']]+[r['destination_sp'] for r in palette['copies']]
for p in palettes:
 for c in all_colors:assert p+24<=c or c+4<=p
widths={30:16,31:16,32:1,33:2,34:4,35:4,36:1,37:2,38:4,39:4,40:1,41:2,42:4,43:4,44:8,45:8,46:4,49:4,53:8,55:8,57:4,61:8,63:8};accesses=[]
for at in range(0,len(d[1]),4):
 w=struct.unpack_from('<I',d[1],at)[0];width=widths.get(w>>26);off=w&65535
 if w>>21&31!=29 or width is None:continue
 hit=[c for c in objects.values() if off<c+4 and off+width>c]
 if hit:assert len(hit)==1 and hit[0]<=off and off+width<=hit[0]+4;accesses.append({'offset':at,'home':hit[0],'width':width})
assert len(accesses)==6
Path('proof/alpha-alias-evidence.json').write_text(json.dumps({'source_sha256':sha,'slices':rows,'alpha_accesses':accesses,'52colors_disjoint':True,'15palettes_disjoint_from52colors':True},indent=2)+'\n')
print('Both alpha slices retain exact operations/references with explicit homes; all 52 colors and 15 palettes remain disjoint')
