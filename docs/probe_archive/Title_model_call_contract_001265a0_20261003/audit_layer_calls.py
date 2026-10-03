"""Check every retail/rebuilt layer argument setup, without stale CFG facts."""
from pathlib import Path
import hashlib,json,re,struct,sys
sys.path.insert(0,'tools');import verify as V
from measure_guarded import extract_guarded_body
OWNER=Path('src/promoted/code1_0012.c');source=OWNER.read_text()
body=extract_guarded_body(source,'FUN_001265A0','func_001265a0')
patterns=re.findall(r'func_0045d6e0\(\(u8 \*\)&(\w+), \(f32 \*\)&(\w+), (0\.0f|10\.0f), ([01])\);',body)
assert len(patterns)==30
cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
retail_code=retail.bytes_at(0x1265a0,17616)
def setup(code,call):
    g={0:0,29:('sp',0)};f={}
    for at in range(max(0,call-256),call,4):
        w=struct.unpack_from('<I',code,at)[0];op=w>>26;rs=(w>>21)&31;rt=(w>>16)&31;rd=(w>>11)&31;imm=w&65535;si=imm-65536 if imm&32768 else imm
        if op in (1,2,3,4,5,6,7) or (op==0 and w&63 in (8,9)) or (op==17 and rs==8):
            g={0:0,29:('sp',0)};f={};continue
        if op==15:g[rt]=imm<<16
        elif op==13:g[rt]=g[rs]|imm if isinstance(g.get(rs),int) else None
        elif op==9:
            base=g.get(rs);g[rt]=('sp',base[1]+si) if isinstance(base,tuple) and base[0]=='sp' else (base+si)&0xffffffff if isinstance(base,int) else None
        elif op==0 and w&63 in (33,45):
            a,b=g.get(rs),g.get(rt);g[rd]=a if b==0 else b if a==0 else (a+b)&0xffffffff if isinstance(a,int) and isinstance(b,int) else None
        elif op==0 and w!=0:g[rd]=None
        elif op==17:
            if rs==4:f[rd]=g.get(rt)
            elif rs in (16,17,20):f[(w>>6)&31]=None
        elif op in (8,10,11,12,14,24,25,26,27,30,32,33,34,35,36,37,38,39,55):g[rt]=None
        elif op in (49,53):f[rt]=None
    assert struct.unpack_from('<I',code,call+4)[0]==0
    return g,f
record=json.loads(Path('proof/title-model-owner/after-guard.json').read_text())
assert record['source_sha256']==hashlib.sha256(OWNER.read_bytes()).hexdigest()
target=record['functions']['func_001265a0'];candidate_code=bytes.fromhex(target['bytes'])
candidate_calls=[r['offset'] for r in target['relocations'] if r['symbol']=='func_0045d6e0']
retail_calls=[i for i in range(0,len(retail_code),4) if struct.unpack_from('<I',retail_code,i)[0]==(3<<26)|(0x45d6e0>>2)]
assert len(retail_calls)==len(candidate_calls)==30
rows=[];mapping={}
for index,((color,rect,depth,state),a,b) in enumerate(zip(patterns,retail_calls,candidate_calls)):
    rg,rf=setup(retail_code,a);cg,cf=setup(candidate_code,b)
    expected_color=0x688 if color=='layerColor' else int(color[2:],16)
    expected_rect=int(rect[2:],16);bits=0x41200000 if depth=='10.0f' else 0
    assert (rg.get(4),rg.get(5),rg.get(6),rf.get(12))==( ('sp',expected_color),('sp',expected_rect),int(state),bits),(index,rg,rf)
    assert cg.get(6)==int(state) and cf.get(12)==bits,(index,cg,cf)
    for name,reg,size in ((color,4,4),(rect,5,16)):
        value=cg.get(reg);assert isinstance(value,tuple) and value[0]=='sp',(index,name,cg)
        assert value[1]%4==0 and value[1]+size<=-(struct.unpack_from('<h',candidate_code,0)[0])
        if name in mapping:assert mapping[name]==(value[1],size)
        else:mapping[name]=(value[1],size)
    rows.append({'index':index,'retail_call':hex(0x1265a0+a),'candidate_call_offset':hex(b),'color':color,'rectangle':rect,'depth':float(depth[:-1]),'save_state':int(state),'retail_color_sp':hex(expected_color),'retail_rectangle_sp':hex(expected_rect),'candidate_color_sp':hex(cg[4][1]),'candidate_rectangle_sp':hex(cg[5][1])})
for n,(offset,size) in mapping.items():
    for other,(begin,length) in mapping.items():
        if n!=other:assert offset+size<=begin or begin+length<=offset,(n,other)
# Live matching provider prologue consumes the separate float/integer counters.
for address,w in {0x45d6fc:0x0080982d,0x45d700:0x46006506,0x45d704:0x00c0902d,0x45d708:0xc4a30000,0x45d70c:0xc4a20004,0x45d710:0xc4a10008,0x45d714:0xc4a0000c}.items():
    assert struct.unpack('<I',retail.bytes_at(address,4))[0]==w
out={'source_sha256':record['source_sha256'],'retail_sha1':windows['sha1'],'calls':rows,'candidate_objects':mapping,'candidate_size':len(candidate_code),'frame':-(struct.unpack_from('<h',candidate_code,0)[0]),'provider_prologue_verified':True,'control_transfer_facts_reset':True}
Path('proof/layer-call-proof.json').write_text(json.dumps(out,indent=2)+'\n')
print('All 30 retail/candidate layer calls agree on arguments; shared identities and object extents preserved')
