"""Hash-check retail and execute real retail/emitted fade-tail instructions.

Only the renderer call is recorded. The actual two-instruction texture getter
executes. This does not execute the controller prefix, renderer, VU, GS or DMA.
"""
from pathlib import Path
import hashlib,json,math,re,struct,sys
sys.path.insert(0,'tools')
import verify as V

ROOT=Path.cwd();OUT=ROOT/'proof';OUT.mkdir(exist_ok=True)
cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
gp,symbols=V.symbol_addresses()
record=json.loads((OUT/'title-model-owner/after-guard.json').read_text())
source=(ROOT/'src/promoted/code1_0012.c').read_bytes()
assert record['source_sha256']==hashlib.sha256(source).hexdigest()
fn=record['functions']['func_001265a0'];candidate=bytearray.fromhex(fn['bytes'])

# The palette checkpoint changes instruction positions and proven stack homes.
# Translation is restricted to exact preservation ranges audited independently.
_palette=json.loads((ROOT/'docs/probe_archive/Title_palette_storage_001265a0_20261003/target-preservation.json').read_text())
_model=json.loads((ROOT/'proof/model-preservation-evidence.json').read_text())
def moved(offset):
    for proof,key in ((_palette,'non_palette_ranges'),(_model,'non_model_ranges')):
        for r in proof[key]:
            a,b=r['before'];c,d=r['after']
            if a<=offset<=b:offset=c+offset-a;break
        else:raise AssertionError(('offset outside bounded ranges',hex(offset)))
    return offset


start=moved(0x4314);stop=moved(0x43ec)
refs=[r for r in fn['relocations'] if start<=r['offset']<stop]
assert [(r['offset'],r['r_type'],r['symbol']) for r in refs]==[(moved(0x4320),5,'D_005E56B0'),(moved(0x4324),6,'D_005E56B0'),(moved(0x4378),4,'func_00401b80'),(moved(0x43e4),4,'func_00366c70')],refs
for r in refs:
    at=r['offset'];w=struct.unpack_from('<I',candidate,at)[0]
    address={'D_005E56B0':0x5e56b0,'func_00401b80':0x401b80,'func_00366c70':0x366c70}[r['symbol']]
    if r['r_type']==5:w=(w&0xffff0000)|((address+0x8000)>>16)
    elif r['r_type']==6:w=(w&0xffff0000)|(address&0xffff)
    else:w=(w&0xfc000000)|(address>>2)
    struct.pack_into('<I',candidate,at,w)
uvbits=[0x3a800000,0x3b000000,0x3f200000,0x3b000000,0x3a800000,0x3f600000,0x3f200000,0x3f600000]
assert retail.bytes_at(0x5e56b0,32)==struct.pack('<8I',*uvbits)
assert V.resolve_symbol('iGpffffb900',gp,symbols)==0x7649f0
assert retail.bytes_at(0x401b80,8)==struct.pack('<2I',0x03e00008,0x8f82b900)
provider_words={0x366ca4:0x0080b82d,0x366ca8:0x00a0f02d,0x366cac:0x46006546,0x366cb0:0x0100882d,0x366cb4:0x0120802d,0x366cb8:0x0140a82d,0x366cbc:0xa7ab00be,0x366cec:0x44860000,0x366cfc:0x44870000,0x366d48:0x8fa20258,0x366da4:0x8fa20268}
for a,w in provider_words.items():assert retail.bytes_at(a,4)==struct.pack('<I',w)

# The matching update callback seeds this countdown at precisely these three
# stores. Positive retail lifecycle inputs are bounded by 13, not arbitrary
# positive s32 values; no synthetic clamp or overflow-dependent claim is made.
producer_words={0x12ae48:0x2402000a,0x12ae4c:0xae42002c,
                0x12b23c:0x2405000a,0x12b240:0xae45002c,
                0x12b400:0x2402000d,0x12b404:0xae42002c}
for a,w in producer_words.items():assert retail.bytes_at(a,4)==struct.pack('<I',w)
producer_code=retail.bytes_at(0x12aa70,0x12b660-0x12aa70)
producer_stores=[0x12aa70+i for i in range(0,len(producer_code),4)
                 if (struct.unpack_from('<I',producer_code,i)[0]&0xffe0ffff)==0xae40002c]
assert producer_stores==[0x12ae4c,0x12b240,0x12b404]

def s32(v):
    v&=0xffffffff
    return v-0x100000000 if v&0x80000000 else v

def fbits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def asfloat(v):return struct.unpack('<f',struct.pack('<I',v&0xffffffff))[0]
def f32(v):return asfloat(fbits(v))

class TailMachine:
    def __init__(self,kind,state,count,words,texture,mutation=None):
        self.kind=kind;self.initial_count=count;self.state=state;self.words=words;self.texture=texture
        self.code={};self.memory={};self.reads=[];self.writes=[];self.calls=[];self.cop1=[];self.instructions=0
        self.g=[0x1212121200000000+i for i in range(32)];self.g[0]=0
        self.f=[0x7fc00000+i for i in range(32)];self.sp=0x10000000;self.work=0x20000000
        if kind=='retail':
            self.pc=0x12a948;self.stop=0x12aa28;self.state_register=20;self.uv_sp=0x530
            self.install(self.pc,retail.bytes_at(self.pc,self.stop-self.pc))
        else:
            self.pc=0x100000+start;self.stop=0x100000+stop;self.state_register=20;self.uv_sp=0x390
            self.install(self.pc,candidate[start:stop])
        self.install(0x401b80,retail.bytes_at(0x401b80,8))
        if mutation:
            at=0x100000+{'stride':moved(0x4338),'alpha':moved(0x43a8),'height':moved(0x43d0),'uv_address':moved(0x43b8)}[mutation]
            w=self.code[at]
            self.code[at]={'stride':(w&0xffff0000)|32,'alpha':0x44080000,'height':(w&0xffff0000)|447,'uv_address':(w&0xffff0000)|0x394}[mutation]
        self.g[29]=self.sp;self.g[28]=gp;self.g[self.state_register]=self.work
        self.seed(self.work,b'\xa5'*0x90);self.seed(self.work,struct.pack('<I',state));self.seed(self.work+44,struct.pack('<i',count))
        self.seed(0x5e56b0,struct.pack('<8I',*words));self.seed(0x7649f0,struct.pack('<I',texture))
    def install(self,start,data):
        for i in range(0,len(data),4):self.code[start+i]=struct.unpack_from('<I',data,i)[0]
    def seed(self,address,data):
        for i,b in enumerate(data):self.memory[address+i]=b
    def read(self,address,n):
        assert all(address+i in self.memory for i in range(n)),('unwritten read',self.kind,hex(self.pc),hex(address),n)
        self.reads.append((address,n));return int.from_bytes(bytes(self.memory[address+i] for i in range(n)),'little')
    def write(self,address,value,n):
        self.writes.append((address,n));self.seed(address,(value&((1<<(n*8))-1)).to_bytes(n,'little'))
    def check_renderer(self):
        assert self.calls==['getter'];self.calls.append('renderer')
        alpha=math.trunc(f32(f32((self.initial_count-1)*255)/f32(10 if self.state==16 else 13)))
        assert [s32(self.g[i]) for i in range(4,12)]==[0,0,640,448,0xffffff,alpha,1,0]
        assert self.f[12]==0
        assert self.read(self.sp,8)==0 and self.read(self.sp+8,8)==0
        assert self.read(self.sp+16,4)==self.texture
        pointer=self.read(self.sp+24,4);assert pointer==self.sp+self.uv_sp
        assert [self.read(pointer+i*4,4) for i in range(8)]==self.words
    def run(self):
        pending=None
        while self.pc!=self.stop:
            self.instructions+=1;assert self.instructions<256
            w=self.code[self.pc];op=w>>26;rs=w>>21&31;rt=w>>16&31;rd=w>>11&31;sh=w>>6&31;fn=w&63;imm=w&65535;si=imm-65536 if imm&32768 else imm
            target=None;next_pc=self.pc+4
            if w==0:pass
            elif op==15:self.g[rt]=s32(imm<<16)
            elif op==13:self.g[rt]=self.g[rs]|imm
            elif op==9:self.g[rt]=s32(self.g[rs]+si)
            elif op==35:self.g[rt]=s32(self.read((self.g[rs]+si)&0xffffffff,4))
            elif op==43:self.write((self.g[rs]+si)&0xffffffff,self.g[rt],4)
            elif op==63:self.write((self.g[rs]+si)&0xffffffff,self.g[rt],8)
            elif op==0:
                if fn==0:self.g[rd]=s32(self.g[rt]<<sh)
                elif fn==35:self.g[rd]=s32(self.g[rs]-self.g[rt])
                elif fn==45:self.g[rd]=(self.g[rs]+self.g[rt])&0xffffffffffffffff
                elif fn==8:target=self.g[rs]&0xffffffff
                else:raise AssertionError(('special',hex(w)))
            elif op in (5,6,7):
                take=self.g[rs]!=self.g[rt] if op==5 else s32(self.g[rs])<=0 if op==6 else s32(self.g[rs])>0
                if take:target=self.pc+4+si*4
            elif op==3:
                address=(w&0x3ffffff)<<2
                assert self.code[self.pc+4]==0
                if address==0x366c70:self.check_renderer();next_pc=self.pc+8
                else:
                    assert address==0x401b80 and not self.calls
                    assert self.read(self.work+44,4)==(self.initial_count-1)&0xffffffff
                    self.calls.append('getter');self.g[31]=self.pc+8;target=address
            elif op==17:
                fs=rd;fd=sh
                if rs==4:self.f[fs]=self.g[rt]&0xffffffff
                elif rs==0:self.g[rt]=s32(self.f[fs])
                elif rs==20 and fn==32:self.f[fd]=fbits(s32(self.f[fs]));self.cop1.append('cvt.s.w')
                elif rs==16 and fn==3:self.f[fd]=fbits(asfloat(self.f[fs])/asfloat(self.f[rt]));self.cop1.append('div.s')
                elif rs==16 and fn==36:self.f[fd]=math.trunc(asfloat(self.f[fs]))&0xffffffff;self.cop1.append('cvt.w.s')
                else:raise AssertionError(('cop1',hex(w)))
            else:raise AssertionError(('instruction',hex(self.pc),hex(w)))
            assert self.g[0]==0
            old=pending;pending=target
            if old is not None:assert target is None;next_pc=old
            self.pc=next_pc
        assert pending is None
        if self.initial_count<=0:
            assert not self.calls and not self.writes
            assert self.read(self.work+44,4)==self.initial_count&0xffffffff
        else:
            assert self.calls==['getter','renderer']
            assert [a for a,n in self.reads if 0x5e56b0<=a<0x5e56d0]==list(range(0x5e56b0,0x5e56d0,4))
            assert self.writes==[(self.sp+self.uv_sp+i*4,4) for i in range(8)]+[(self.work+44,4)]+[(self.sp+i,8) for i in (0,8,16,24)]
            assert self.read(self.work+44,4)==self.initial_count-1
        return {'calls':self.calls,'instructions':self.instructions,'unwritten_stack_reads':0}

rows=[];total=0
for state in (0,6,15,16,17,0xffffffff):
    for count in (-2147483648,-1,0,*range(1,15),255,512):
        for words in (uvbits,[0x3e800001+i*0x10203 for i in range(8)]):
            for texture in (0,0x34567890,0xf1234560):
                rr=[TailMachine(kind,state,count,words,texture).run() for kind in ('retail','candidate')]
                assert rr[0]['calls']==rr[1]['calls'];total+=2
                rows.append({'state':state,'counter':count,'texture':texture,'retail':rr[0],'candidate':rr[1]})
negative=[]
for mutation in ('stride','alpha','height','uv_address'):
    try:TailMachine('candidate',16,10,uvbits,0x34567890,mutation).run()
    except AssertionError as error:negative.append({'mutation':mutation,'rejected':True,'reason':str(error)})
    else:raise AssertionError(('mutation survived',mutation))
report={'source_sha256':record['source_sha256'],'retail_sha1':windows['sha1'],'retail_tail':['0x12a948','0x12aa28'],'candidate_tail_offsets':[hex(start),hex(stop)],'candidate_bytes':len(candidate),'retail_uv_words':[hex(v) for v in uvbits],'retail_uv_pairs':[list(struct.unpack('<2f',struct.pack('<2I',*uvbits[i:i+2]))) for i in range(0,8,2)],'provider_prologue_words_verified':{hex(a):hex(w) for a,w in provider_words.items()},'getter_actual_instructions_executed':True,'getter_storage':'0x7649f0','candidate_references':refs,'counter_contract':{'producer_stores':[hex(a) for a in producer_stores],'seed_values':[10,10,13],'positive_lifecycle_domain':[1,13],'nonpositive_gate_skips_arithmetic':True,'bounded_extra_machine_counts':[14,255,512],'arbitrary_positive_s32_claim':False},'machine_invocations':total,'scenarios':len(rows),'unwritten_stack_reads':0,'negative_controls':negative,'rows':rows,'scope':'actual retail/emitted tail instructions with actual getter leaf; renderer boundary recorded; no controller prefix, renderer, VU, GS, DMA, or gameplay execution'}
(OUT/'fade-machine-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print(f'{total} real retail/emitted tail invocations passed; {len(negative)} machine negative controls rejected')
