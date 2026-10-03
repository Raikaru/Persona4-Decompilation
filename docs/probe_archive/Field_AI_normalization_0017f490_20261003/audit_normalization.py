"""Check native-vector calling contracts in hash-validated retail and whole owners.

This is a bounded instruction/ABI audit, not execution of the AI controller.
"""
from pathlib import Path
import hashlib,json,re,struct,sys
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools'))
import verify as V
OUT=ROOT/'proof/field-ai'; OUT.mkdir(parents=True,exist_ok=True)
CFG=V.load_config();TARGET=json.loads((ROOT/'config/target.json').read_text())
RETAIL=V.RetailElf(CFG['retail_elf'],TARGET,TARGET['elf']['sha1'])
OWNER=ROOT/'src/Kosaka/Field/k_fldAI.c'
source=OWNER.read_text();body=source[source.index('int func_0017f490('):source.index('// FUN_001821D0')]
calls=re.findall(r'(?m)^\s*(?:(temp_v\d+) = )?RwV3dNormalize\(&(\w+),&(\w+)\);',body)
assert len(calls)==25 and all(a==b for _,a,b in calls)
assert sum(bool(result) for result,_,_ in calls)==10
vectors=set(a for _,a,_ in calls); assert len(vectors)==21
assert all(re.search(r'FldAIVec3 '+name+';',body) for name in vectors)
assert 'extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);' in source
sdk=(ROOT/'include/rw/plcore/bavector.h').read_text()
assert 'extern RwReal RwV3dNormalize(RwV3d * out, const RwV3d * in);' in sdk


def words(data): return list(struct.unpack('<'+'I'*(len(data)//4),data))
def simm(w): return (w&65535)-(65536 if w&32768 else 0)
def stack_args(ws,index):
    # Every target call constructs both argument addresses within this bounded
    # predecessor window. The SP is stable inside the controller body.
    regs={0:('constant',0),29:('stack',0)}
    for w in ws[max(0,index-16):index+2]:
        op=w>>26;rs=(w>>21)&31;rt=(w>>16)&31;rd=(w>>11)&31;fn=w&63
        if op in (9,25):
            v=regs.get(rs);regs[rt]=(v[0],v[1]+simm(w)) if v else None
        elif op==0 and fn in (0x21,0x25,0x2d):
            a,b=regs.get(rs),regs.get(rt)
            regs[rd]=a if b==('constant',0) else b if a==('constant',0) else None
        elif op in (0xf,0x23,0x24,0x25,0x27,0x37): regs[rt]=None
    assert regs.get(4) and regs.get(4)==regs.get(5) and regs[4][0]=='stack',(index,regs.get(4),regs.get(5))
    return regs[4][1]


def first_float_result_use(ws,index):
    # f0 is the SDK return register. A direct arithmetic/move use must happen
    # before it is overwritten or another call clobbers it. Branches are not
    # executed; the recorded first read precedes them at all ten consumed sites.
    for j in range(index+2,min(len(ws),index+35)):
        w=ws[j];op=w>>26;rs=(w>>21)&31;ft=(w>>16)&31;fs=(w>>11)&31;fd=(w>>6)&31;fn=w&63
        if op==3: return None
        if op==0x31 and ft==0: return None
        if op==0x11 and rs in (4,6) and fs==0: return None
        if op==0x11 and rs==16:
            # Single-precision arithmetic, conversions, moves and comparisons.
            reads=[fs]+([ft] if fn in (0,1,2,3,0x18,0x1a,0x1c,0x1e,0x30,0x32,0x34,0x36) else [])
            if 0 in reads: return {'instruction_offset':j*4,'operation':fn,'float_return_register':0}
            if fd==0 and fn<0x30:return None
    return None


retail_bytes=RETAIL.bytes_at(0x17f490,11584);rw=words(retail_bytes)
retail_calls=[i for i,w in enumerate(rw) if w>>26==3 and (w&0x3ffffff)*4==0x3e40b0]
assert len(retail_calls)==25
expected_offsets=[0x2a0,0x290,0x280,0x230,0x240,0x210,0x200,0x1f0,0x1f0,0x1b0,0x1d0,0x1c0,0x1b0,0x1b0,0x180,0x170,0x150,0x160,0x130,0x120,0x110,0xf0,0xe0,0xd0,0xd0]
report={'source_sha256':hashlib.sha256(OWNER.read_bytes()).hexdigest(),'retail_elf_sha1':TARGET['elf']['sha1'],'calls':[]}
for n,(i,expected,(result,name,_)) in enumerate(zip(retail_calls,expected_offsets,calls)):
    assert stack_args(rw,i)==expected
    use=first_float_result_use(rw,i)
    if result:assert use,(n,name)
    report['calls'].append({'index':n,'source_vector':name,'source_result':result or None,'retail_call':hex(0x17f490+i*4),'retail_stack_offset':hex(expected),'retail_first_result_use':use})
# Proven provider accesses: three input components, three output stores,
# and the float-length return move in a branch delay slot.
pw=words(RETAIL.bytes_at(0x3e40b0,0xd0))
inputs=[(0x3e40b0+i*4,simm(w)) for i,w in enumerate(pw) if w>>26==0x31 and (w>>21)&31==5]
outputs=[(0x3e40b0+i*4,simm(w)) for i,w in enumerate(pw) if w>>26==0x39 and (w>>21)&31==4]
assert set(o for _,o in inputs)=={0,4,8} and [o for _,o in outputs]==[0,4,8]
assert pw[(0x3e4144-0x3e40b0)//4]==0x4600a006
report['provider']={'address':'0x003e40b0','input_offsets':[o for _,o in inputs],'output_offsets':[o for _,o in outputs],'float_return_move':'0x003e4144: f20 to f0','in_place_supported':True,'sdk_header':'include/rw/plcore/bavector.h'}
for label in ('before','after'):
    obj=V.ObjectFile(OUT/'owner'/f'{label}-guard.o');data,rels=obj.function('func_0017f490');cw=words(data)
    selected=[r for r in rels if r['r_type']==4 and r['symbol'] in ('FUN_003e40b0','RwV3dNormalize')]
    assert len(selected)==25
    entries=[]
    for n,r in enumerate(selected):
        i=r['offset']//4;offset=stack_args(cw,i);use=first_float_result_use(cw,i)
        if calls[n][0]:
            assert (use is not None) == (label=='after'),(label,n)
        entries.append({'index':n,'call_offset':r['offset'],'stack_offset':offset,'float_result_use':use})
    # Reused vectors must keep object identity and different vectors cannot
    # overlap. This checks the compiler's complete guarded owner, not a fixture.
    if label=='after':
        by_name={}
        for (_,name,_),entry in zip(calls,entries):
            offset=entry['stack_offset']
            if name in by_name:assert offset==by_name[name]
            by_name[name]=offset
        intervals=sorted((offset,offset+12,name) for name,offset in by_name.items())
        assert all(left[1]<=right[0] for left,right in zip(intervals,intervals[1:]))
    report[label]={'object_sha256':hashlib.sha256(obj.data).hexdigest(),'target_size':len(data),'stack_frame':-simm(cw[0]),'normalization_calls':entries}
(OUT/'machine-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print('Verified 25 in-place calls, 21 independent XYZ objects and 10 floating return consumers')
