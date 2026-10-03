"""Prove all six raw GP color transports and four fullscreen arguments."""
from pathlib import Path
import hashlib,json,struct,sys,subprocess
sys.path.insert(0,'tools');import verify as V
cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1']);gp,syms=V.symbol_addresses()
record=json.loads(Path('proof/title-palette-owner/after-guard.json').read_text())
assert record['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
fn=record['functions']['func_001265a0'];code=bytes.fromhex(fn['bytes']);refs={r['offset']:r['symbol'] for r in fn['relocations']};retail_code=retail.bytes_at(0x1265a0,17616)
shared_sp=json.loads(Path("proof/candidate-color-families.json").read_text())["candidate_objects"]["sp6BC"]
rows=[]
for suffix,address,bits in [('70',0x762d60,0xff000000),('74',0x762d64,0xffffffff),('78',0x762d68,0xffffffff),('7c',0x762d6c,0xff000000),('88',0x762d78,0xff000000),('8c',0x762d7c,0xff41ebff)]:
    name='fGpffff9c'+suffix;assert V.resolve_symbol(name,gp,syms)==address
    assert struct.unpack('<I',retail.bytes_at(address,4))[0]==bits
    gp_imm=(address-gp)&65535
    loads=[i for i in range(0,len(retail_code),4) if struct.unpack_from('<I',retail_code,i)[0]==0xc7800000|gp_imm]
    assert len(loads)==1,(name,loads);at=loads[0]
    # Retail writes the backup scalar then forwards the same float register's
    # raw bits into the shared color before any opaque call or arithmetic.
    shared=[];backup=[]
    for i in range(at+4,at+24,4):
        w=struct.unpack_from('<I',retail_code,i)[0]
        if w>>26==3:break
        assert not (w>>26==17 and (w>>21)&31 in (16,17,20))
        if w&0xffff0000==0xe7a00000:
            (shared if w&65535==0x6bc else backup).append(i)
    assert len(shared)==1 and len(backup)==1,(name,shared,backup)
    candidate=[o for o,s in refs.items() if s==name];assert len(candidate)==1
    ca=candidate[0];assert struct.unpack_from('<I',code,ca)[0]==0xc7800000
    assert struct.unpack_from('<I',code,ca+4)[0]==0xe7a00000|shared_sp
    rows.append({'symbol':name,'data_address':hex(address),'bits':hex(bits),'retail_load':hex(0x1265a0+at),'retail_backup_store':hex(0x1265a0+backup[0]),'retail_shared_store':hex(0x1265a0+shared[0]),'candidate_load_offset':hex(ca),'candidate_shared_store_offset':hex(ca+4),'candidate_shared_color_sp':hex(shared_sp)})
# All four actual fullscreen calls use the same shared object and enabled=1.
retail_calls=[i for i in range(0,len(retail_code),4) if struct.unpack_from('<I',retail_code,i)[0]==(3<<26)|(0x45c870>>2)]
candidate_calls=[o for o,s in refs.items() if s=='func_0045c870'];assert len(retail_calls)==len(candidate_calls)==4
calls=[]
for r,c in zip(retail_calls,candidate_calls):
    for data,call,offset in ((retail_code,r,0x6bc),(code,c,shared_sp)):
        setup=[struct.unpack_from('<I',data,i)[0] for i in range(call-24,call,4)]
        assert 0x27a40000|offset in setup and 0x24050001 in setup
        assert struct.unpack_from('<I',data,call+4)[0]==0
    calls.append({'retail_call':hex(0x1265a0+r),'candidate_call_offset':hex(c),'color_sp_before':hex(0x6bc),'color_sp_after':hex(shared_sp),'enabled':1})
for address,w in {0x45c88c:0x0080982d,0x45c890:0x00a0902d,0x45c894:0x12400029}.items():assert struct.unpack('<I',retail.bytes_at(address,4))[0]==w
# The separate alpha block genuinely admits frame25. Preserve this independent
# retail predicate evidence while expanding the formerly narrower fixture.
assert struct.unpack('<I',retail.bytes_at(0x129394,4))[0]==0x2a010019
out={'source_sha256':record['source_sha256'],'retail_sha1':windows['sha1'],'colors':rows,'fullscreen_calls':calls,'provider_signature':'void func_0045c870(u8 *, s32)','provider_prologue_verified':True,'raw_gp_words_preserved':True,'candidate_backup_scalars_elided':True,'dynamic_alpha_lower_predicate':{'address':'0x129394','word':'0x2a010019','first_dynamic_frame':25},'candidate_size':len(code),'frame':-struct.unpack_from('<h',code)[0]}
Path('proof/gp-color-evidence.json').write_text(json.dumps(out,indent=2)+'\n')
print('Verified six raw GP color words, four fullscreen calls and the real two-argument provider')
