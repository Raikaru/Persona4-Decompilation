"""Complete owner/census replay for the bounded provider-sized vector objects."""
from pathlib import Path
import hashlib,importlib.util,json,struct,sys
ROOT=Path(__file__).resolve().parents[3]
path=ROOT/'docs/probe_archive/Large_Battle_storage_20261003/audit.py'
spec=importlib.util.spec_from_file_location('timing_storage_owner_audit',path)
audit=importlib.util.module_from_spec(spec);spec.loader.exec_module(audit)
audit.BASE='6db34823ac38e6b7833489795a4c52c871a5dcc0'
previous=audit.retail_evidence

def evidence(retail,windows):
    result=previous(retail,windows)
    expected={
      # Caller vector argument identities and neighboring ABI setup.
      0x1a5acc:0x3044ffff,0x1a5ad0:0x24050001,0x1a5ad4:0x27a60308,
      0x1a5ad8:0x0000382d,0x1a5adc:0x0000402d,0x1a5ae0:0x00a0482d,
      0x1a5ae4:0x0c065810,0x1a5aec:0x8e840030,0x1a5af0:0x27a50308,
      0x1a5af4:0x0000302d,0x1a5af8:0x0c065fd4,
      0x1a7a48:0x3044ffff,0x1a7a4c:0x24050001,0x1a7a50:0x27a60578,
      0x1a7a54:0x0000382d,0x1a7a58:0x0000402d,0x1a7a5c:0x00a0482d,
      0x1a7a60:0x0c065810,0x1a7a68:0x8e840030,0x1a7a6c:0x27a50578,
      0x1a7a70:0x03c0302d,0x1a7a74:0x0c065fd4,
      0x1a7ab0:0x8c820170,0x1a7ab4:0x8c440030,0x1a7ab8:0x27a50578,
      0x1a7abc:0x0c06563c,0x1a7ac4:0x8e840030,0x1a7ac8:0x27a50578,
      0x1a7acc:0x03c0302d,0x1a7ad0:0x0c065fd4,
      0x1a9d3c:0x24050001,0x1a9d40:0x27a60578,0x1a9d44:0x0000382d,
      0x1a9d48:0x0000402d,0x1a9d4c:0x00a0482d,0x1a9d50:0x0c065810,
      0x1a9d58:0x0000202d,0x1a9d5c:0x27a50578,0x1a9d60:0x24060001,
      0x1a9d64:0x0c067854,
      # Complete three-word producer writes and consumer reads/copies.
      0x196598:0xe6820000,0x19659c:0xe6810004,0x1965a0:0xe6800008,
      0x195974:0xe6000000,0x195984:0xe6000004,0x1959b4:0xe6000008,
      0x197f74:0x24050018,0x197fac:0xac900010,
      0x197fb8:0xc6220000,0x197fbc:0xc6210004,0x197fc0:0xc6200008,
      0x197fc4:0xe4820004,0x197fc8:0xe4810008,0x197fcc:0xe480000c,
      0x19e174:0x24050014,0x19e1ac:0xa4700010,
      0x19e1b0:0xc6220000,0x19e1b4:0xc6210004,0x19e1b8:0xc6200008,
      0x19e1bc:0xe4620004,0x19e1c0:0xe4610008,0x19e1c4:0xe460000c,
    }
    rows=[]
    for address,word in expected.items():
        actual=struct.unpack('<I',retail.bytes_at(address,4))[0]
        assert actual==word,(hex(address),hex(actual),hex(word))
        rows.append({'address':hex(address),'word':hex(word)})
    result['vector_instructions']=rows
    return result

audit.retail_evidence=evidence
audit.main()
out=Path(sys.argv[1]);path=out/'proof.json';report=json.loads(path.read_text())
for name in ['tests/test_large_battle_vector_storage.py','tests/large_battle_vector_storage_fixture.c.in']:
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

# Eight actual candidate calls transport the same three-word object per owner.
report['candidate_vector_calls']={}
for suffix,names in [('-59a0',('func_001a59a0',)),('-7720',('func_001a7720',)),('-both',audit.TARGETS)]:
    obj=audit.V.ObjectFile(out/('final'+suffix+'.o'));rows=[]
    for name in names:
        code,relocs=obj.function(name);words=list(struct.unpack('<'+'I'*(len(code)//4),code))
        targets={'func_00196040':6,'func_001958f0':5,'btlUnitCreateRotatePacket':5,'btlUnitCreateLookAtPacket':5}
        calls=[r for r in relocs if r['r_type']==4 and r['symbol'] in targets]
        expected=2 if name.endswith('59a0') else 6
        assert len(calls)==expected,(name,calls)
        offsets=set();frame=-(struct.unpack('<h',code[:2])[0])
        for call in calls:
            at=call['offset']//4;reg=targets[call['symbol']]
            # All these vector arguments are immediate SP addresses within the
            # straight-line setup. Do not carry register facts across a branch.
            candidates=[]
            for n in range(at-1,max(-1,at-12),-1):
                w=words[n];op=w>>26
                if op in (1,2,3,4,5,6,7) or (op==0 and (w&63) in (8,9)):break
                if op==9 and (w>>21)&31==29 and (w>>16)&31==reg:
                    candidates.append((n,w&0xffff));break
            assert len(candidates)==1,(name,call)
            n,offset=candidates[0];assert offset%4==0 and 0<=offset and offset+12<=frame
            offsets.add(offset)
            rows.append({'function':name,'call_offset':hex(at*4),'provider':call['symbol'],'vector_sp_offset':hex(offset),'frame_bytes':frame,'argument_window_words':[hex(w) for w in words[n:at+2]]})
        assert len(offsets)==1,(name,offsets)
    report['candidate_vector_calls'][suffix]=rows
path.write_text(json.dumps(report,indent=2)+'\n')
print('All eight caller/provider vector addresses and 12-byte frame extents verified')
