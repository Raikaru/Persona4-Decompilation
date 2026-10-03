"""Pin retail/rebuilt snapshot fields, float intermediate and complete copies."""
from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
retail_words={
  0x1266f0:0x78425650,0x1266f4:0x7fa20520,
  0x126704:0x46010041,0x126714:0x46010502,0x126718:0x4600a007,
  0x12671c:0x46000024,0x126720:0x44020000,0x126728:0xafa20524,
  0x12672c:0x27a50590,0x126730:0x7ba20520,0x126734:0x7fa20590,
  0x126738:0x44806000,0x12673c:0x24060001,0x126740:0x0c1175b8,
  0x12674c:0x78425660,0x126750:0x7fa20510,0x126754:0x3c0243cb,
  0x126760:0x46140000,0x126764:0x46000024,0x126768:0x44020000,
  0x126770:0xafa20514,0x126774:0x27a50590,0x126778:0x7ba20510,
  0x12677c:0x7fa20590,0x126780:0x44806000,0x126784:0x27a406bc,
  0x126788:0x24060001,0x12678c:0x0c1175b8,
}
for a,w in retail_words.items():assert struct.unpack('<I',retail.bytes_at(a,4))[0]==w,(hex(a),hex(w))
record=json.loads(Path('proof/title-rectangle-owner/after-guard.json').read_text())
assert record['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
fn=record['functions']['func_001265a0'];code=bytes.fromhex(fn['bytes'])
candidate_words={
  0x13c:0x7fa203c0,0x174:0x46010642,0x178:0x4600c807,0x17c:0x46000024,
  0x180:0x44020000,0x188:0xafa203c4,0x18c:0x7ba203c0,0x190:0x7fa203d0,
  0x194:0x44806000,0x19c:0x27a503d0,0x1a0:0x24060001,
  0x1b4:0x7fa203b0,0x1b8:0x3c0243cb,0x1c4:0x46190000,0x1c8:0x46000024,
  0x1cc:0x44020000,0x1d4:0xafa203b4,0x1d8:0x7ba203b0,0x1dc:0x7fa203d0,
  0x1e0:0x44806000,0x1e8:0x27a503d0,0x1ec:0x24060001,
}
for a,w in candidate_words.items():assert struct.unpack_from('<I',code,a)[0]==w,(hex(a),hex(w))
refs={r['offset']:r['symbol'] for r in fn['relocations']}
for off,name in {0x134:'D_005E5650',0x138:'D_005E5650',0x1ac:'D_005E5660',0x1b0:'D_005E5660',0x1a4:'func_0045d6e0',0x1f0:'func_0045d6e0'}.items():assert refs[off]==name
frame=-struct.unpack_from('<h',code)[0]
for off in (0x3b0,0x3c0,0x3d0):assert off%16==0 and off+16<=frame
# Source snapshots and the shared consumer snapshot cannot overlap colors.
colors=json.loads(Path('proof/candidate-color-families.json').read_text())['candidate_objects']
for off in (0x3b0,0x3c0,0x3d0):
    for color in colors.values():assert off+16<=color or color+4<=off
out={'source_sha256':record['source_sha256'],'retail_sha1':windows['sha1'],'retail_words':{hex(a):hex(w) for a,w in retail_words.items()},'candidate_words':{hex(a):hex(w) for a,w in candidate_words.items()},'candidate_references':{hex(a):refs[a] for a in (0x134,0x138,0x1ac,0x1b0,0x1a4,0x1f0)},'candidate_snapshot_offsets':[0x3b0,0x3c0,0x3d0],'frame':frame,'candidate_size':len(code),'field_offset':4,'snapshot_extent':16,'floating_product_retained':True,'complete_field_modified_snapshots_consumed':True,'all_three_snapshots_disjoint_from_colors':True}
Path('proof/rectangle-evidence.json').write_text(json.dumps(out,indent=2)+'\n')
print('Verified two Y fields, unrounded float product and complete retail/rebuilt snapshot copies')
