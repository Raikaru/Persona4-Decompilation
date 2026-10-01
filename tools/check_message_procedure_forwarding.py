#!/usr/bin/env python3
"""Verify the narrow main projection, with no allowed code/data differences."""
from pathlib import Path
import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import verify as V
import probe_variants as P
import recovery_quality as Q
OWNERS = ('src/promoted/code1_0027.c', 'src/itfMsgProcedure.c', 'src/itfMesManager.c',
          'src/Event/Fcl/fclMisc.c', 'src/Yajima/y_misc.c', 'src/promoted/itfMsgProcedure_Window.c')
WINDOW = OWNERS[-1]
GUARDS = ('func_0027d970', 'func_0027f6f0', 'func_00282250', 'func_00283490')
def sha(data): return hashlib.sha256(data).hexdigest()
def section_key(obj, index):
    section = obj.sections[index]
    key = (section['name'], section['type'], section['flags'])
    return (*key, sum((s['name'], s['type'], s['flags']) == key for s in obj.sections[:index]))
def allocated(obj, gp, addresses):
    sections, relocations = [], []
    for index, section in enumerate(obj.sections):
        if section['flags'] & 2:
            data = obj.data[section['offset']:section['offset']+section['size']] if section['type'] != 8 else b''
            sections.append((section_key(obj,index), section['size'], section['addralign'], sha(data)))
        if section['type'] != 9 or not obj.sections[section['info']]['flags'] & 2: continue
        for n in range(section['size'] // (section['entsize'] or 8)):
            offset, info = struct.unpack_from(obj.endian+'II',obj.data,section['offset']+n*(section['entsize'] or 8))
            symbol = obj.symtabs[section['link']][info>>8]
            name = symbol['name']
            if name and not name.startswith('@'):
                address = V.resolve_symbol(name,gp,addresses)
                identity = ('address',address) if address is not None else ('named',name)
            else:
                identity = ('section',section_key(obj,symbol['shndx']),symbol['value'],symbol['size'])
            relocations.append((section_key(obj,section['info']),offset,info&255,identity))
    # All raw allocated bytes, including code relocation addends and padding,
    # are compared above. Resolving names here permits only address aliases.
    return sections, sorted(relocations)
def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--base',default='55484acc8a525b07c7faf0e4ebcfec540baea36e')
    parser.add_argument('--output',type=Path,default=ROOT/'build/message-forwarding/preservation')
    args=parser.parse_args(); args.output.mkdir(parents=True,exist_ok=True)
    cfg=V.load_config(); gp,addresses=V.symbol_addresses()
    for line in (ROOT/'config/symbol_addrs.txt').read_text().splitlines():
        match=re.match(r'(\w+) = (0x[0-9a-fA-F]+);',line)
        if match: addresses[match[1]]=int(match[2],16)
    report={'base':args.base,'owners':{},'full_link':'not run','new_matches':0}
    for relative in OWNERS:
        owner=ROOT/relative
        before=subprocess.check_output(['git','show',args.base+':'+relative],cwd=ROOT,text=True)
        after=owner.read_text()
        if relative==WINDOW:
            baseline_copy=args.output/'baseline-window.c';baseline_copy.write_text(before)
            old_bodies=Q.function_bodies(baseline_copy);new_bodies=Q.function_bodies(owner)
            report['guarded_body_hashes']={}
            for function in GUARDS:
                old=old_bodies[function][1];new=new_bodies[function][1]
                assert old==new,function
                report['guarded_body_hashes'][function]=sha(new.encode())
        record={'source_sha256':sha(after.encode()),'modes':{}}
        for mode in ('production','all_guards') if relative==WINDOW else ('production',):
            pair=[]
            for version,text in [('baseline',before),('retained',after)]:
                output=args.output/(owner.stem+'-'+version+'-'+mode+'.o')
                with P.scratch_source(owner) as scratch:
                    scratch.write_text(('#define NON_MATCHING\n' if mode=='all_guards' else '')+text)
                    ok,log=P._compile_in_context(scratch,owner,cfg,output)
                output.with_suffix('.log').write_text(log);assert ok,log
                pair.append(V.ObjectFile(output))
            old,new=pair;left=allocated(old,gp,addresses);right=allocated(new,gp,addresses)
            assert left==right,(relative,mode,'allocated code/data/layout or relocation meanings differ')
            markers=V.scan_markers(owner)
            for marker in markers:
                a,ar=old.function(marker['name']);b,br=new.function(marker['name'])
                assert a==b,(relative,mode,marker['name'])
            record['modes'][mode]={'functions':len(markers),'all_function_bytes_and_sizes_preserved':True,
                'all_allocated_bytes_layouts_and_relocation_meanings_preserved':True,
                'relocations':len(left[1]),'object_sha256':sha(new.data)}
        report['owners'][relative]=record
    report['header_sha256']=sha((ROOT/'include/message_procedure_api.h').read_bytes())
    (args.output/'receipt.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(report,indent=2))
if __name__=='__main__':main()
