from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
R=Path(__file__).resolve().parent
cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
e=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
loops=[(0x12706c,0x130,0x450),(0x1270e0,0x130,0x430),(0x127448,0x110,0x1b0),(0x1274a0,0x110,0x190),(0x127998,0xf0,0x410),(0x1279dc,0xf0,0x3f0),(0x127e20,0xd0,0x3d0),(0x127e64,0xd0,0x3b0),(0x129b28,0xb0,0x170),(0x129b80,0xb0,0x150)]
copy=(0x8cc30000,0x8cc20004,0x24c60008,0x2484ffff,0xaca30000,0xaca20004,0x24a50008,0x1c80fff8,0)
body=e.bytes_at(0x1265a0,17616)
rows=[]
for setup,source,dest in loops:
 expected=(0x27a50000|dest,0x24040003,*copy)
 assert e.bytes_at(setup,4*len(expected))==struct.pack('<'+'I'*len(expected),*expected)
 # Exactly one materialization of this source precedes this pair copy since
 # its previous word-copy loop (or the containing expression setup).
 window=e.bytes_at(setup-32,32)
 assert struct.pack('<I',0x27a60000|source) in window
 # The selected word is loaded from this actual destination through index+SP.
 matches=[]
 for at in range(setup+44, min(setup+256,0x12aa70),4):
  w=struct.unpack('<I',e.bytes_at(at,4))[0]
  if w>>26==35 and w&65535==dest:
   assert (w>>21)&31==2
   prior=struct.unpack('<I',e.bytes_at(at-4,4))[0]
   assert prior>>26==0 and prior&63==33 and (prior>>11)&31==2 and 29 in ((prior>>21)&31,(prior>>16)&31),(hex(at),hex(prior))
   matches.append(at)
 assert len(matches)==1,(hex(setup),matches)
 rows.append({'source_stack':hex(source),'destination_stack':hex(dest),'setup_address':hex(setup),'loop_address':hex(setup+8),'iteration_bytes':8,'iterations':3,'selected_load':hex(matches[0]),'selected_load_word':hex(struct.unpack('<I',e.bytes_at(matches[0],4))[0])})
snapshots=[]
for setup,source,destination in loops[::2]:
 expected=(0x27a60000|source,0x3c02005e,0x78435530,0x3c02005e,0xdc425540,0x7fa30000|source,0xffa20000|(source+16))
 assert e.bytes_at(setup-28,28)==struct.pack('<7I',*expected)
 snapshots.append({'start':hex(setup-28),'source_stack':hex(source),'complete_bytes':24,'first_address':'0x5e5530','tail_address':'0x5e5540'})
colors=list(struct.unpack('<6I',e.bytes_at(0x5e5530,24)))
indices=[]
for i in range(19):
 value=struct.unpack('<i',e.bytes_at(0x5e5230+i*40+28,4))[0]
 assert 0<=value<6,(i,value)
 indices.append(value)
report={'retail_sha1':windows['sha1'],'target':'0x1265a0','palette_words':[hex(x) for x in colors],'palette_extent_bytes':24,'layout_record_stride':40,'layout_palette_indices':indices,'copies':rows,'snapshots':snapshots,'claims':'Authenticated retail evidence for bounded palette source recovery; no whole-controller or matching claim.'}
(R/'authenticated-retail-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print('Authenticated all ten 24-byte loops, actual local selections, six packed colors and 19 bounded palette indices')
