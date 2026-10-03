"""Complete owner/census replay for the bounded signed timing calculation."""
from pathlib import Path
import hashlib,importlib.util,json,struct,sys
ROOT=Path(__file__).resolve().parents[3]
path=ROOT/'docs/probe_archive/Large_Battle_storage_20261003/audit.py'
spec=importlib.util.spec_from_file_location('timing_storage_owner_audit',path)
audit=importlib.util.module_from_spec(spec);spec.loader.exec_module(audit)
audit.BASE='1999e7d6360015ae6e7f1ca8f687d3db5a65c8a7'
previous=audit.retail_evidence

def evidence(retail,windows):
    result=previous(retail,windows)
    expected={
      0x1a5d1c:0x0017943c,0x1a5d20:0x0012943f,
      0x1a5d30:0x00571023,0x1a5d34:0x44820000,0x1a5d3c:0x46800060,
      0x1a5d40:0xc7808128,0x1a5d44:0x46010002,0x1a5d48:0x46000024,
      0x1a5d4c:0x44020000,0x1a5d54:0x2841001a,0x1a5d58:0x14200002,
      0x1a5d60:0x24020019,0x1a5d64:0x0002143c,0x1a5d68:0x0002143f,
      0x1a5d6c:0x02421021,0x1a5d70:0x0002943c,0x1a5d74:0x0012943f,
      0x1a5d90:0x26420008,0x1a5d94:0x0002943c,0x1a5d98:0x0012943f,
      0x1a5dc4:0x0002143c,0x1a5dc8:0x0002143f,0x1a5dcc:0x2442fffc,
      0x1a5dfc:0x2642000c,0x1a5e00:0x0002943c,0x1a5e04:0x0012943f,
    }
    rows=[]
    for address,word in expected.items():
        actual=struct.unpack('<I',retail.bytes_at(address,4))[0]
        assert actual==word,(hex(address),hex(actual),hex(word))
        rows.append({'address':hex(address),'word':hex(word)})
    gp,table=audit.V.symbol_addresses();address=audit.V.resolve_symbol('fGpffff8128',gp,table)
    assert address==0x761218 and retail.bytes_at(address,4)==bytes.fromhex('3333b33e')
    result['timing_instructions']=rows
    result['factor']={'symbol':'fGpffff8128','address':hex(address),'bits':'0x3eb33333'}
    return result

audit.retail_evidence=evidence
audit.main()
out=Path(sys.argv[1]);path=out/'proof.json';report=json.loads(path.read_text())
for name in ['tests/test_large_battle_timing_clamp.py','tests/large_battle_timing_clamp_fixture.c.in']:
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
# Only 59a0 changes in this checkpoint. Check 7720 itself even in the both-
# guarded configuration, rather than merely inheriting the older two-target
# audit's shared-sibling exclusion list.
report['single_target_preservation']={}
for suffix in ('','-59a0','-7720','-both'):
    before=audit.V.ObjectFile(out/('baseline'+suffix+'.o'))
    after=audit.V.ObjectFile(out/('final'+suffix+'.o'))
    names=lambda obj:{s['name'] for s in obj.symbols if s['info']&15==2 and s['size'] and s['shndx'] not in (0,0xfff1)}
    assert names(before)==names(after)
    preserved=[]
    for name in sorted(names(before)):
        if name=='func_001a59a0' and suffix in ('-59a0','-both'):continue
        assert audit.canonical(before,name)==audit.canonical(after,name),name
        preserved.append(name)
    report['single_target_preservation'][suffix or 'production']={'preserved_functions':preserved,'7720_unchanged':True}
assert (out/'baseline-7720.o').read_bytes()==(out/'final-7720.o').read_bytes()
path.write_text(json.dumps(report,indent=2)+'\n')
print('7720 and every other unaffected function are also preserved explicitly')
