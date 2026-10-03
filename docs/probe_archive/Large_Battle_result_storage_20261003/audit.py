"""Complete owner/census replay for the bounded provider-sized result objects."""
from pathlib import Path
import hashlib,importlib.util,json,struct,sys
ROOT=Path(__file__).resolve().parents[3]
path=ROOT/'docs/probe_archive/Large_Battle_storage_20261003/audit.py'
spec=importlib.util.spec_from_file_location('timing_storage_owner_audit',path)
audit=importlib.util.module_from_spec(spec);spec.loader.exec_module(audit)
audit.BASE='e324dcafd9c8f5d6e31e3a7aa1be3c2f66c04b6c'
previous=audit.retail_evidence

def evidence(retail,windows):
    result=previous(retail,windows)
    expected={
      # Small controller: one contiguous result, status at +8.
      0x1a6284:0x27a402e0,0x1a6288:0x0c07c284,0x1a6290:0x3c020010,
      0x1a6294:0xafa202e8,0x1a62a0:0x27a602e0,0x1a62ac:0x0c07cdb8,
      # Transfer result: signed halfwords become full result words at +0/+4.
      0x1aac10:0x27a40550,0x1aac14:0x0c07c284,
      0x1aac1c:0x97a203b0,0x1aac24:0x00021140,0x1aac28:0x02421821,
      0x1aac2c:0x7ba200e0,0x1aac30:0x84420000,0x1aac34:0xafa20550,
      0x1aac38:0x8462010a,0x1aac3c:0xafa20554,0x1aac48:0x27a60550,
      0x1aac54:0x0c07cdb8,0x1aaca8:0x27ab0550,0x1aacac:0x0c080778,
      # HP path computes -(unsigned HP - 1), not -HP - 1.
      0x1ab264:0x27a40550,0x1ab268:0x0c07c284,0x1ab274:0x8c440a64,
      0x1ab278:0x0c08c7b4,0x1ab280:0x3042ffff,0x1ab284:0x2442ffff,
      0x1ab288:0x00021023,0x1ab28c:0xafa20550,0x1ab298:0x27a60550,
      0x1ab2a4:0x0c07cdb8,0x1ab320:0x27ab0550,0x1ab324:0x0c080778,
      # Status-only path uses the same 32-byte object.
      0x1ab3a8:0x27a40550,0x1ab3ac:0x0c07c284,0x1ab3b4:0x3c020008,
      0x1ab3b8:0xafa20558,0x1ab3c4:0x27a60550,0x1ab3d0:0x0c07cdb8,
      # Clear and both factories establish the entire 32-byte extent.
      0x1f0a18:0x0000282d,0x1f0a1c:0x24060020,0x1f0a20:0x0c10fe72,
      0x1f371c:0x2405002c,0x1f375c:0x26040008,0x1f3760:0x0260282d,
      0x1f3764:0x24060020,0x1f3768:0x0c10fe04,
      0x201e30:0x2405003c,0x201e68:0x26040008,0x201e6c:0x03c0282d,
      0x201e70:0x24060020,0x201e74:0x0c10fe04,0x231ed0:0x94820008,
    }
    rows=[]
    for address,word in expected.items():
        actual=struct.unpack('<I',retail.bytes_at(address,4))[0]
        assert actual==word,(hex(address),hex(actual),hex(word))
        rows.append({'address':hex(address),'word':hex(word)})
    result['result_instructions']=rows
    return result

audit.retail_evidence=evidence
audit.main()
out=Path(sys.argv[1]);path=out/'proof.json';report=json.loads(path.read_text())
for name in ['tests/test_large_battle_result_storage.py','tests/large_battle_result_storage_fixture.c.in','tests/test_large_battle_hit_predicates.py']:
    report['tests_sha256'][name]=hashlib.sha256((ROOT/name).read_bytes()).hexdigest()
# All allocated data and references are stable, not just function bytes.
def data_snapshot(obj):
    sections=[];references=[]
    for sec in obj.sections:
        if sec['flags']&2 and not sec['flags']&4:
            sections.append((audit.skey(obj,sec['idx']),sec['size'],sec['addralign'],obj.data[sec['offset']:sec['offset']+sec['size']].hex() if sec['type']!=8 else ''))
        if sec['type']==9:
            target=obj.sections[sec['info']]
            if not target['flags']&2 or target['flags']&4:continue
            for pos in range(sec['offset'],sec['offset']+sec['size'],sec['entsize'] or 8):
                offset,info=struct.unpack_from('<II',obj.data,pos);symbol=obj.symtabs[sec['link']][info>>8]
                key=('named',symbol['name']) if symbol['name'] and not symbol['name'].startswith('@') else (audit.skey(obj,symbol['shndx']),symbol['value'],symbol['size'])
                references.append((audit.skey(obj,sec['info']),offset,info&255,key))
    return sections,references
report['allocated_data_preservation']={}
for suffix in ('','-59a0','-7720','-both'):
    before=data_snapshot(audit.V.ObjectFile(out/('baseline'+suffix+'.o')))
    after=data_snapshot(audit.V.ObjectFile(out/('final'+suffix+'.o')))
    assert before==after
    report['allocated_data_preservation'][suffix or 'production']={'sections':len(after[0]),'bytes':sum(s[1] for s in after[0]),'references':len(after[1]),'identical':True}
path.write_text(json.dumps(report,indent=2)+'\n')
print('Allocated data and references preserved in all eight configurations')


# Each direct stack-result call uses one aligned, frame-contained 32-byte object.
report['candidate_result_calls']={}
for suffix,names in [('-59a0',('func_001a59a0',)),('-7720',('func_001a7720',)),('-both',audit.TARGETS)]:
    obj=audit.V.ObjectFile(out/('final'+suffix+'.o'));rows=[]
    for name in names:
        code,relocs=obj.function(name);words=list(struct.unpack('<'+'I'*(len(code)//4),code))
        targets={'func_001f0a10':4,'func_001f36e0':6,'func_00201de0':11}
        calls=[r for r in relocs if r['r_type']==4 and r['symbol'] in targets]
        offsets=set();frame=-struct.unpack('<h',code[:2])[0];found=[]
        for call in calls:
            at=call['offset']//4;reg=targets[call['symbol']];candidate=None
            for n in range(at-1,max(-1,at-14),-1):
                w=words[n];op=w>>26
                if op in (1,2,3,4,5,6,7) or (op==0 and (w&63) in (8,9)):break
                if op==9 and (w>>21)&31==29 and (w>>16)&31==reg:
                    candidate=(n,w&0xffff);break
            if candidate is None:continue # Other providers consume an action's existing hit record.
            n,offset=candidate;assert offset%4==0 and 0<=offset and offset+32<=frame
            offsets.add(offset);found.append(call['symbol'])
            rows.append({'function':name,'provider':call['symbol'],'call_offset':hex(at*4),'result_sp_offset':hex(offset),'frame_bytes':frame,'argument_window_words':[hex(w) for w in words[n:at+2]]})
        assert len(offsets)==1,(name,offsets)
        expected=['func_001f0a10','func_001f36e0'] if name.endswith('59a0') else ['func_001f0a10','func_001f36e0','func_00201de0','func_001f0a10','func_001f36e0','func_00201de0','func_001f0a10','func_001f36e0']
        assert found==expected,(name,found)
    report['candidate_result_calls'][suffix]=rows
path.write_text(json.dumps(report,indent=2)+'\n')
print('All ten direct result calls use a shared 32-byte object per controller')

# Inspect the rebuilt signed load and integer subtraction, not just source text.
report['candidate_payload_operations']={}
expected={0x34fc:0x84420000,0x3500:0xafa20660,0x3508:0x8442010a,0x350c:0xafa20664,
          0x3b24:0x3042ffff,0x3b28:0x24070001,0x3b2c:0x00e21023,0x3b30:0xafa20660,
          0x3c5c:0x3c020008,0x3c60:0xafa20668}
for suffix in ('-7720','-both'):
    code,_=audit.V.ObjectFile(out/('final'+suffix+'.o')).function('func_001a7720');rows=[]
    for offset,w in expected.items():
        assert struct.unpack_from('<I',code,offset)[0]==w,(suffix,hex(offset))
        rows.append({'offset':hex(offset),'word':hex(w)})
    report['candidate_payload_operations'][suffix]=rows
path.write_text(json.dumps(report,indent=2)+'\n')
print('Actual rebuilt LH, word stores, 1-HP subtraction and status field checked')
