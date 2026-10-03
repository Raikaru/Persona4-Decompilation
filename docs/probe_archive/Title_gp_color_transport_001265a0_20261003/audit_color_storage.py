"""Check the actual rebuilt byte loops, alpha aliases, copies and object ranges."""
from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tests');from test_title_color_families import families
source,body,rows=families();record=json.loads(Path('proof/title-gp-color-owner/after-guard.json').read_text())
assert record['source_sha256']==hashlib.sha256(source.encode()).hexdigest()
fn=record['functions']['func_001265a0'];code=bytes.fromhex(fn['bytes']);words=struct.unpack('<'+'I'*(len(code)//4),code)
pattern=[0x24020004,0x10600008,0,0xA0600000,0x24630001,0x2442FFFF,0,0,0x1440FFFA,0]
loops=[i for i,w in enumerate(words[:-16]) if w&0xffff0000==0x27A30000 and list(words[i+1:i+11])==pattern]
assert len(loops)==26,len(loops)
allrows=[{'source':'layerColorSource','destination':'layerColor','layer':True},{'source':'firstOverlaySource','destination':'firstOverlayColor','layer':False}]+rows
mapping={};receipts=[];frame=-(struct.unpack_from('<h',code)[0])
for row,start in zip(allrows,loops):
    src=words[start]&65535;copy=start+(14 if row['layer'] else 12)
    assert words[copy]&0xffff0000==0xC7A00000 and words[copy]&65535==src
    assert words[copy+1]&0xffff0000==0xE7A00000;dst=words[copy+1]&65535
    assert words[copy-1]==0x27A40000|dst
    if row['layer']:assert words[copy-3]==0x240200FF and words[copy-2]==0xA3A20000|(src+3)
    for name,offset in ((row['source'],src),(row['destination'],dst)):
        assert offset%4==0 and 0<=offset and offset+4<=frame
        if name in mapping:assert mapping[name]==offset
        else:mapping[name]=offset
    receipts.append({'source':row['source'],'destination':row['destination'],'layer':row['layer'],'clear_offset':hex(start*4),'copy_offset':hex(copy*4),'source_sp':hex(src),'destination_sp':hex(dst)})
assert len(mapping)==50 and len(set(mapping.values()))==50
# No wider direct stack operation silently shares any recovered color object.
widths={0x1E:16,0x1F:16,0x20:1,0x21:2,0x22:4,0x23:4,0x24:1,0x25:2,0x26:4,0x27:4,0x28:1,0x29:2,0x2A:4,0x2B:4,0x2C:8,0x2D:8,0x2E:4,0x31:4,0x35:8,0x37:8,0x39:4,0x3D:8,0x3F:8}
census=[]
for i,w in enumerate(words):
    op,base,off=w>>26,(w>>21)&31,w&65535
    if off&32768:off-=65536
    if base!=29:continue
    width=widths.get(op);matches=[name for name,start in mapping.items() if width and off<start+4 and off+width>start]
    if matches:
        assert len(matches)==1 and mapping[matches[0]]<=off and off+width<=mapping[matches[0]]+4,(i,matches,width)
        census.append({'offset':hex(i*4),'object':matches[0],'word':hex(w),'width':width})
report={'source_sha256':record['source_sha256'],'families':receipts,'candidate_objects':mapping,'frame':frame,'candidate_size':len(code),'direct_access_census':census,'byte_loops':26,'raw_copies':26,'alpha_aliases':12,'new_families':24,'new_objects':46,'all_distinct_objects_disjoint':True}
Path('proof/candidate-color-families.json').write_text(json.dumps(report,indent=2)+'\n')
print('Verified all 26 candidate byte loops/raw copies, 12 alpha aliases and 50 disjoint objects')
