"""Authenticate exact storage, ABI and provider write/read boundaries."""
from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
A=Path(__file__).resolve().parent;cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS);e=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
def ws(at,n):return list(struct.unpack('<'+'I'*n,e.bytes_at(at,n*4)))
expected={
 0x1265e4:[0x3c02005e,0xdc435628,0x3c02005e,0xc4405630,0xffa305c8,0xe7a005d0,0x3c02005e,0xdc435638,0x3c02005e,0xc4405640,0xffa305b8,0xe7a005c0],
 0x12a25c:[0x27a40550,0x27a505c8,0x4600bb06,0x0000302d,0x0c0f821c,0,0x27a40550,0x27a505b8,0x4600c306,0x24060002,0x0c0f821c,0,0xafa005a8,0x3c02c2b4,0xafa205ac,0xafa005b0,0x27a40550,0x27a505a8,0x24060001,0x0c0f8324,0,0x0200202d,0x27a50550,0x0000302d,0x0c11e870,0],
 0x3e0770:[0x27a60060,0x24040008,0x0200282d,0x8cc30000,0x2484ffff,0x8cc20004,0xaca30000,0x24c60008,0xaca20004,0x1c80fff9,0x24a50008],
 0x3e0e54:[0x24040008,0x0200302d,0x8ca30000,0x2484ffff,0x8ca20004,0xacc30000,0xacc20004,0x24a50008,0x1c80fff9,0x24c60008],
 0x47a1c0:[0x27bdfff0,0xffbf0000,0x0c0f8388,0,0xdfbf0000,0x27bd0010,0x03e00008,0],
}
checks={}
for address,words in expected.items():
 assert ws(address,len(words))==words,hex(address)
 checks[hex(address)]={'words':[hex(w) for w in words],'sha256':hashlib.sha256(e.bytes_at(address,len(words)*4)).hexdigest()}
# Rotation ABI: 12-byte input read; angle is f12; mode is a2 and forwarded.
for at,w in {0x3e0878:0xc4a00004,0x3e088c:0xc4a20000,0x3e089c:0x00c0802d,0x3e08a0:0x460c0d02,0x3e08a8:0xc4a00008,0x3e0928:0x0200302d,0x3e0930:0x0220202d,0x3e0938:0x27a50040,0x3e093c:0x0c0f81a0,0x3e0944:0x0220102d}.items():assert ws(at,1)==[w],hex(at)
# All stores into local rotation [SP+0x60,SP+0xa0) are enumerated from the
# complete provider prefix. Flags=3 is unconditional; the 3 pad words are not.
stores=[]
for at in range(0x3e0680,0x3e0754,4):
 w=ws(at,1)[0];op=w>>26;rs=w>>21&31;off=w&65535
 if op in (43,57) and rs==29 and 0x60<=off<0xa0:stores.append((at,off-0x60,op,w>>16&31))
assert sorted(x[1] for x in stores)==[0,4,8,12,16,20,24,32,36,40,48,52,56]
assert ws(0x3e06a0,1)==[0x24020003] and ws(0x3e06ac,1)==[0xafa2006c]
assert not any((w>>26) in (35,39,49,55) and (w>>21&31)==16 for w in ws(0x3e0680,(0x3e07a4-0x3e0680)//4))
# Mode 2 multiply physically loads four 16-byte rows, reads flags, computes
# xyz lanes in VU0, writes four rows and explicit AND flags. No VU execution
# claim follows from documenting its bounds.
loads=[];writes=[]
for at in range(0x3e05f0,0x3e066c,4):
 w=ws(at,1)[0];op=w>>26;rs=w>>21&31;off=w&65535
 if op==54:loads.append((at,rs,off,16))
 if op==62:writes.append((at,rs,off,16))
assert [(x[1],x[2]) for x in loads]==[(5,0),(5,16),(5,32),(5,48),(6,0),(6,16),(6,32),(6,48)]
assert [(x[1],x[2]) for x in writes]==[(4,0),(4,16),(4,32),(4,48)]
for at,w in {0x3e0600:0x9ca3000c,0x3e0614:0x9cc2000c,0x3e064c:0x00431024,0x3e0660:0xac82000c}.items():assert ws(at,1)==[w]
# Translate PRECONCAT reads all twelve xyz fields, writes only position and
# later clears identity in flags; it does not enter mode-0 old-flags OR.
readmatrix=[];readvec=[];writematrix=[]
for at in range(0x3e0d20,0x3e0d9c,4):
 w=ws(at,1)[0];op=w>>26;rs=w>>21&31;off=w&65535
 if op==49:(readmatrix if rs==4 else readvec).append(off)
 if op==57:assert rs==4;writematrix.append(off)
assert sorted(readmatrix)==[0,4,8,16,20,24,32,36,40,48,52,56]
assert readvec==[4,0,8] and writematrix==[48,52,56]
assert ws(0x3e0df4,6)==[0x8c85000c,0x3c02fffd,0x3443ffff,0x0080102d,0x00a31824,0xac83000c]
axes={hex(a):{'words':[hex(w) for w in ws(a,3)],'values':list(struct.unpack('<3f',e.bytes_at(a,12)))} for a in (0x5e5628,0x5e5638)}
assert axes['0x5e5628']['values']==[0,1,0] and axes['0x5e5638']['values']==[1,0,0]
slices={hex(a):{'size':n,'sha256':hashlib.sha256(e.bytes_at(a,n)).hexdigest()} for a,n in [(0x3e0680,0x1f0),(0x3e0870,0xf0),(0x3e05f0,0x80),(0x3e0c90,0x190),(0x3e0e20,0x120),(0x47a1c0,0x20)]}
r={'retail_sha1':windows['sha1'],'exact_slices':checks,'provider_bodies':slices,'axes':axes,'matrix_size':64,'matrix_alignment':16,'field_offsets':{'right':0,'flags':12,'up':16,'pad1':28,'at':32,'pad2':44,'pos':48,'pad3':60},'replace_rotation_written_fields':stores,'replace_reads_old_destination_flags':False,'replace_flags_written':3,'unspecified_source_padding_offsets':[28,44,60],'multiply_row_reads':loads,'multiply_row_writes':writes,'translate_mode1_reads':readmatrix,'translate_mode1_writes':writematrix,'model_replace_copy_bytes':64,'limits':'Actual rotate provider normalizes and uses trigonometry/VU multiplication; no full-provider native execution. Its local padding is uninitialized and copied. Different providers/modes with old-flags OR are not repaired.'}
(A/'authenticated-retail-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print('Authenticated 12-byte axes, exact f32/mode ABI, 64-byte provider copies and exact flags/padding boundary')
