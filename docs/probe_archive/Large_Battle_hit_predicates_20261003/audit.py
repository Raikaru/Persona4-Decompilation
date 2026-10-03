"""Reuse the complete owner audit with a pinned predicate-repair baseline.

Run from the checkout root: python THIS_SCRIPT ignored-output-directory
"""
from pathlib import Path
import hashlib
import importlib.util
import json
import struct
import sys
ROOT=Path(__file__).resolve().parents[3]
path=ROOT/'docs/probe_archive/Large_Battle_storage_20261003/audit.py'
spec=importlib.util.spec_from_file_location('storage_owner_audit',path)
audit=importlib.util.module_from_spec(spec);spec.loader.exec_module(audit)
audit.BASE='64ca61782d3251142af9cf5e6da62e84a79b4ea1'
previous_evidence=audit.retail_evidence

def evidence(retail,windows):
    result=previous_evidence(retail,windows)
    # Complete decisive pointer reload / signed-byte or word load / comparison
    # sequences, followed by the actual provider calls. These are observations,
    # not replacement instructions in the recovered source.
    expected={
      0x1a731c:0x7ba20100,0x1a7320:0x8c430000,0x1a7324:0x3c020010,
      0x1a7328:0x00621024,0x1a732c:0x10400012,0x1a7330:0,
      0x1aa238:0x7ba20100,0x1aa23c:0x80450000,0x1aa250:0x0c0667b8,
      0x1aa308:0x7ba20100,0x1aa30c:0x80430000,0x1aa310:0x24020009,
      0x1aa314:0x146200d1,0x1aa318:0,0x1aa31c:0x97a402a0,
      0x1aa320:0x0c08f7dc,0x1aa324:0,0x1aa328:0x144000cc,
      0x1aa668:0x7ba20100,0x1aa66c:0x80430000,0x1aa670:0x2402ffff,
      0x1aa674:0x14620007,0x1aa678:0,0x1aa67c:0x8e420030,
      0x1aa680:0x904300a2,0x1aa684:0x8e820030,0x1aa688:0x904200a2,
      0x1aa68c:0x10620027,0x1aa690:0,0x1aa694:0x8e420030,
      0x1aa698:0x8c440a64,0x1aa69c:0x3c020018,0x1aa6a0:0x34450001,
      0x1aa6a4:0x0c08c9c4,0x1aa6a8:0,0x1aa6ac:0x1440001f,
    }
    checked=[]
    for address,word in expected.items():
        actual=struct.unpack('<I',retail.bytes_at(address,4))[0]
        assert actual==word,(hex(address),hex(actual),hex(word))
        checked.append({'address':hex(address),'word':hex(word)})
    result['predicate_instructions']=checked
    return result

audit.retail_evidence=evidence
audit.main()
out=Path(sys.argv[1]);report_path=out/'proof.json';report=json.loads(report_path.read_text())
for name in ['tests/test_large_battle_hit_predicates.py','tests/large_battle_hit_predicate_fixture.c.in']:
    report['tests_sha256'][name]=hashlib.sha256((ROOT/name).read_bytes()).hexdigest()
report_path.write_text(json.dumps(report,indent=2)+'\n')
# The unchanged owner data is also checked directly, including references.
def data_snapshot(obj):
    sections=[];references=[]
    for sec in obj.sections:
        if sec['flags']&2 and not sec['flags']&4:
            sections.append((audit.skey(obj,sec['idx']),sec['size'],sec['addralign'],
                             obj.data[sec['offset']:sec['offset']+sec['size']].hex() if sec['type']!=8 else ''))
        if sec['type']==9:
            target=obj.sections[sec['info']]
            if not target['flags']&2 or target['flags']&4:continue
            for pos in range(sec['offset'],sec['offset']+sec['size'],sec['entsize'] or 8):
                offset,info=struct.unpack_from('<II',obj.data,pos)
                symbol=obj.symtabs[sec['link']][info>>8]
                key=('named',symbol['name']) if symbol['name'] and not symbol['name'].startswith('@') else (audit.skey(obj,symbol['shndx']),symbol['value'],symbol['size'])
                references.append((audit.skey(obj,sec['info']),offset,info&255,key))
    return sections,references
preserved={}
for suffix in ('','-59a0','-7720','-both'):
    before=data_snapshot(audit.V.ObjectFile(out/('baseline'+suffix+'.o')))
    after=data_snapshot(audit.V.ObjectFile(out/('final'+suffix+'.o')))
    assert before==after
    preserved[suffix or 'production']={'sections':len(after[0]),'bytes':sum(s[1] for s in after[0]),'references':len(after[1]),'identical':True}
report['allocated_data_preservation']=preserved
report_path.write_text(json.dumps(report,indent=2)+'\n')
print('All 148 allocated data bytes and their references preserved in all configurations')
