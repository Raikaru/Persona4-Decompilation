"""Check actual GP bits, both alpha-byte aliases and rebuilt conversion paths."""
from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1']);gp,table=V.symbol_addresses()
constants={}
for name,address,bits in [('fGpffff9c80',0x762d70,0x00ffffff),('fGpffff9c84',0x762d74,0x00ffffff),('fGpffff8094',0x761184,0x3fc90fdb)]:
    assert V.resolve_symbol(name,gp,table)==address and struct.unpack('<I',retail.bytes_at(address,4))[0]==bits
    constants[name]={'address':hex(address),'bits':hex(bits)}
expected={
  0x1294cc:0xc7809c80,0x1294d0:0xe7a0069c,0x1294d4:0x3c02437f,
  0x1294e8:0x46010036,0x1294ec:0x45010007,0x1294f4:0x46000824,
  0x1294f8:0x44030000,0x129500:0x306300ff,0x12950c:0x46000801,
  0x129510:0x46000024,0x129518:0x3c028000,0x12951c:0x00621825,
  0x129520:0x306300ff,0x129524:0xa3a3069f,0x12952c:0xc7a0069c,
  0x129530:0xe7a006bc,0x129554:0x0c1175b8,
  0x12969c:0x2602ffe7,0x1296a8:0x46800020,0x1296ac:0xc7828094,
  0x1296b0:0x46001042,0x1296b4:0x3c024270,0x1296c0:0x46000803,
  0x1296cc:0x46001300,0x1296d0:0x0c112dec,
  0x1296d8:0xc7819c84,0x1296dc:0xe7a10698,0x1296ec:0x46000842,
  0x1296fc:0x46010036,0x129700:0x45010007,0x129708:0x46000824,
  0x12970c:0x44030000,0x129714:0x306300ff,0x129720:0x46000801,
  0x129724:0x46000024,0x12972c:0x3c028000,0x129730:0x00621825,
  0x129734:0x306300ff,0x129738:0xa3a3069b,0x129740:0xc7a00698,
  0x129744:0xe7a006bc,0x129768:0x0c1175b8,
}
for a,w in expected.items():assert struct.unpack('<I',retail.bytes_at(a,4))[0]==w,(hex(a),hex(w))
record=json.loads(Path('proof/title-alpha-owner/after-guard.json').read_text())
assert record['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
fn=record['functions']['func_001265a0'];code=bytes.fromhex(fn['bytes']);words=struct.unpack('<'+'I'*(len(code)//4),code);refs={r['offset']:r['symbol'] for r in fn['relocations']}
candidate={
  0x2e60:0xc7800000,0x2e64:0xe7a004ec,0x2e68:0x240200ff,0x2e6c:0xa3a204ef,
  0x2e74:0xc7a004ec,0x2e78:0xe7a004fc,
  0x2fd8:0xc7820000,0x2fdc:0x2682ffe7,0x2fe8:0x46800020,
  0x2fec:0x46001042,0x2ff0:0x3c024270,0x2ffc:0x46000803,0x3008:0x46001300,
  0x3014:0xc7810000,0x3018:0xe7a104e8,0x3028:0x46000842,
  0x3038:0x46000834,0x303c:0x45010009,0x3044:0x46000801,
  0x3048:0x46000024,0x304c:0x44030000,0x3050:0x3c028000,
  0x3054:0x00621025,0x3058:0x304200ff,0x3064:0x46000824,
  0x3068:0x44020000,0x3070:0x304200ff,0x3074:0xa3a204eb,
  0x307c:0xc7a004e8,0x3080:0xe7a004fc,
}
for a,w in candidate.items():assert struct.unpack_from('<I',code,a)[0]==w,(hex(a),hex(w))
for a,s in {0x2e60:'fGpffff9c80',0x2fd8:'fGpffff8094',0x300c:'sinf',0x3014:'fGpffff9c84',0x2e98:'func_0045d6e0',0x30a0:'func_0045d6e0'}.items():assert refs[a]==s
colors=json.loads(Path('proof/candidate-color-families.json').read_text())['candidate_objects'];assert len(colors)==50 and colors['sp6BC']==0x4fc
colors['sp69C']=0x4ec;colors['sp698']=0x4e8;assert len(set(colors.values()))==52
frame=-struct.unpack_from('<h',code)[0]
for off in colors.values():assert off%4==0 and off+4<=frame
# Include all direct overlapping accesses to the two new source objects, and
# exclude wider hidden operations spanning their sub-byte alpha field.
def census(data,start,objects):
    width={0x1E:16,0x1F:16,0x20:1,0x21:2,0x22:4,0x23:4,0x24:1,0x25:2,0x26:4,0x27:4,0x28:1,0x29:2,0x2A:4,0x2B:4,0x2C:8,0x2D:8,0x2E:4,0x31:4,0x35:8,0x37:8,0x39:4,0x3D:8,0x3F:8};rows=[]
    for i in range(0,len(data),4):
        w=struct.unpack_from('<I',data,i)[0];op,base,offset=w>>26,(w>>21)&31,w&65535
        if offset&32768:offset-=65536
        if base!=29:continue
        n=width.get(op);overlaps=[name for name,off in objects.items() if n and offset<off+4 and offset+n>off]
        if overlaps:
            assert len(overlaps)==1 and objects[overlaps[0]]<=offset and offset+n<=objects[overlaps[0]]+4
            rows.append({'address':hex(start+i),'word':hex(w),'object':overlaps[0],'width':n})
    return rows
out={'source_sha256':record['source_sha256'],'retail_sha1':windows['sha1'],'constants':constants,'retail_words':{hex(a):hex(w) for a,w in expected.items()},'candidate_words':{hex(a):hex(w) for a,w in candidate.items()},'candidate_objects':colors,'frame':frame,'candidate_size':len(code),'retail_source_census':census(retail.bytes_at(0x1265a0,17616),0x1265a0,{'sp69C':0x69c,'sp698':0x698}),'candidate_source_census':census(code,0,{'sp69C':0x4ec,'sp698':0x4e8}),'constant_alpha_folded_to_255':True,'both_dynamic_conversion_paths_verified':True,'raw_gp_load_store_verified':True}
assert len(out['retail_source_census'])==len(out['candidate_source_census'])==6
Path('proof/alpha-evidence.json').write_text(json.dumps(out,indent=2)+'\n')
print('Verified two raw GP colors, phase constant, alpha fields and all 52 distinct candidate color objects')
