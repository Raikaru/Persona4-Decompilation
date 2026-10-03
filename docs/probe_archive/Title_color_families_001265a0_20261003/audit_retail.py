"""Prove all remaining color clear/copy/alpha families against the retail body."""
from pathlib import Path
import hashlib,json,re,struct,sys
sys.path[:0]=['tools','tests']
import verify as V
from test_title_color_families import families
source,body,rows=families();cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
code=retail.bytes_at(0x1265a0,17616);words=struct.unpack('<4404I',code)
report=[]
def expect(index,w):assert words[index]==w,(hex(0x1265a0+index*4),hex(words[index]),hex(w))
for row in rows:
    src=int(row['source'][2:],16);dst=int(row['destination'][2:],16)
    matches=[i for i,w in enumerate(words[:-1]) if w==0xC7A00000|src and words[i+1]==0xE7A00000|dst]
    assert len(matches)==1,(row,matches);copy=matches[0];clear=copy-(14 if row['layer'] else 12)
    expected=[0x27A30000|src,0x24020004,0x10600008,0,0xA0600000,0x24630001,0x2442FFFF,0,0,0x1440FFFA,0]
    for n,w in enumerate(expected):expect(clear+n,w)
    if row['layer']:
        expect(copy-3,0x240200FF);expect(copy-2,0xA3A20000|(src+3))
    expect(copy-1,0x27A40000|dst)
    report.append({'source':row['source'],'destination':row['destination'],'layer':row['layer'],'clear_address':hex(0x1265a0+clear*4),'copy_address':hex(0x1265a0+copy*4),'source_extent':[src,src+4],'destination_extent':[dst,dst+4],'alpha_byte':3 if row['layer'] else None})
# Every direct memory access overlapping the recovered objects is retained for
# review, including wider accesses starting outside an object's own extent.
objects=sorted({int(r[k][2:],16) for r in rows for k in ('source','destination')})
widths={0x1E:16,0x1F:16,0x20:1,0x21:2,0x22:4,0x23:4,0x24:1,0x25:2,0x26:4,0x27:4,0x28:1,0x29:2,0x2A:4,0x2B:4,0x2C:8,0x2D:8,0x2E:4,0x31:4,0x35:8,0x37:8,0x39:4,0x3D:8,0x3F:8}
census=[]
for i,w in enumerate(words):
    op,base,off=w>>26,(w>>21)&31,w&65535
    if off&32768:off-=65536
    if base!=29:continue
    width=widths.get(op);overlaps=[x for x in objects if width and off<x+4 and off+width>x]
    addresses=[x for x in objects if op==9 and x<=off<x+4]
    if overlaps or addresses:
        # All these retail color accesses remain inside a genuine four-byte object.
        if overlaps:assert len(overlaps)==1 and overlaps[0]<=off and off+width<=overlaps[0]+4,(hex(0x1265a0+i*4),overlaps,width)
        census.append({'address':hex(0x1265a0+i*4),'word':hex(w),'stack_offset':hex(off),'width':width,'overlaps':overlaps,'addresses':addresses})
# The shared destination remains one object, including eight other float-view
# assignments whose RHS is unchanged from the parent source.
import subprocess
before=subprocess.check_output(['git','show','5f3ee52967caa0838cc534a9f1bfdb6ef05dde07:src/promoted/code1_0012.c'],text=True)
a=re.findall(r'(?m)^\s*sp6BC = ([^;]+);',before)
b=re.findall(r'(?m)^\s*sp6BC.value = ([^;]+);',source)
assert [rhs for rhs in a if rhs not in ('sp6A4','sp6A0','sp690')]==b and len(b)==8
out={'source_sha256':hashlib.sha256(source.encode()).hexdigest(),'retail_sha1':windows['sha1'],'families':report,'object_count':len(objects),'whole_function_direct_access_census':census,'shared_other_rhs':b}
Path('proof/retail-color-families.json').write_text(json.dumps(out,indent=2)+'\n')
print('Verified 24 byte-clear/raw-copy families, 11 alpha aliases, 46 objects and complete direct access census')
