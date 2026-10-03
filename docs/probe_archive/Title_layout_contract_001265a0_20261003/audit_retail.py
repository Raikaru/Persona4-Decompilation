"""Authenticate actual fallback, records, direct words and provider instructions."""
from pathlib import Path
import sys,struct,json,hashlib,re
sys.path[:0]=['tools','tests'];import verify as V
from test_title_layout_contract import RECORD_WORDS
cfg=V.load_config();w=V._read_json(V.FUNCTION_WINDOWS);e=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),w['sha1'])
asm=Path('asm/nonmatchings/code1_0012/func_001265a0.s');count=0
for line in asm.read_text().splitlines():
 m=re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/',line)
 if m:assert e.bytes_at(int(m[1],16),4)==bytes.fromhex(m[2]);count+=1
assert count==4404
records=e.bytes_at(0x5e5230,760)
assert records==b''.join(struct.pack('<10I',*r) for r in RECORD_WORDS)
# Selection conversion and signed >=15 rejection; direct paths have no roundtrip.
expected={0x12a04c:0xc4400000,0x12a050:0x46800020,0x12a054:0x46000024,0x12a058:0x44030000,0x12a060:0x2862000f,0x12a118:0xc4400000,0x12a11c:0x46800020,0x12a120:0x46000024,0x12a124:0x44030000,0x12a12c:0x2862000f,0x12a1b8:0xc4580000,0x12a1c8:0xc4570000,0x12a1d8:0xc4550000,0x12a210:0x2e220013,0x12a250:0xc44c0000,0x12a254:0x0c11e838,0x1278ec:0xc78c8110,0x1278f0:0x0c11e838}
for a,v in expected.items():assert struct.unpack('<I',e.bytes_at(a,4))[0]==v,(hex(a),hex(v))
for a in (0x127858,0x127910):
 word=struct.unpack('<I',e.bytes_at(a,4))[0];assert word>>26==35 # plain signed word load
 word=struct.unpack('<I',e.bytes_at(a+4,4))[0];assert word>>26==10 and word&65535==15
provider=[struct.unpack('<I',e.bytes_at(a,4))[0] for a in range(0x47a0e0,0x47a120,4)]
assert provider[0]==0x30a5ffff and provider[7]==0xe46c00f4 and provider[8]==0x14a00002 and provider[10]==0xe48c0244
r={'retail_sha1':w['sha1'],'retail_sha256':hashlib.sha256(Path(cfg['retail_elf']).read_bytes()).hexdigest(),'target_window_sha256':hashlib.sha256(e.bytes_at(0x1265a0,17616)).hexdigest(),'all_fallback_words_authenticated':count,'record_bytes_sha256':hashlib.sha256(records).hexdigest(),'native_record_words_equal_actual_retail':True,'record_count':19,'record_byte_stride':40,'selected_words':{hex(a):hex(v) for a,v in expected.items()},'provider_words':[hex(x) for x in provider],'provider_sha256':hashlib.sha256(e.bytes_at(0x47a0e0,64)).hexdigest(),'direct_row_zero_no_float_conversion':True}
Path('proof/layout-retail-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print('Authenticated all 4404 fallback words, nineteen native record rows, signed index/direct-word/raw-float contracts and actual speed provider')
