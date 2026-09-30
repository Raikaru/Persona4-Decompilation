#!/usr/bin/env python3
"""Verify the portrait's no-fog Sky2 strip path from authorized retail bytes.

This is a bounded data-flow proof for this 47-instruction VU1 program, not a
VU emulator. Instruction fields were cross-checked against PCSX2's primary
DisVU1Micro.cpp / DisVUmicro.h / DisVUops.h descriptions. No emulator source
is copied here. Unrecognized operations fail the proof.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
import verify as V

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    cfg=V.load_config()
    retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),V._read_json(V.FUNCTION_WINDOWS)['sha1'])
    word=lambda address:struct.unpack('<I',retail.bytes_at(address,4))[0]
    # Device descriptor's state setter and the setter's exact state14 branch.
    assert word(0x70c230)==0x003f5070
    assert word(0x3f50c8)==0x2402000e
    branch=word(0x3f50cc)
    assert branch>>26==4 and 0x3f50d0+4*(branch&0xffff)==0x3f5998
    assert word(0x3f5998)==0x12200008  # value==0 -> 003f59bc
    assert word(0x3f59c8)==0x304200fe  # clear fog selector bit0
    assert word(0x3f59d0)==0xa382b984  # store selector byte
    # Callback installation, then bit0-clear descriptor selection in each
    # dispatcher. These checks bind the table data to the actual call path.
    assert word(0x40d12c)==0x3c040041 and word(0x40d134)==0x2484c0f0
    assert word(0x40d140)==0xac447310
    assert word(0x40d13c)==0x3c030041 and word(0x40d144)==0x2463d0a0
    assert word(0x40d150)==0xac437314
    assert word(0x40c114)==0x30420001 and word(0x40c118)==0x10400004
    assert word(0x40c12c)==0x3c040075 and word(0x40c130)==0x24843330
    assert word(0x40d0c4)==0x30420001 and word(0x40d0c8)==0x10400004
    assert word(0x40d0dc)==0x3c040075 and word(0x40d0e0)==0x24843330
    # Draw function4 dispatches to the physical triangle-strip packers.
    assert word(0x70c2e0+4*4)==0x0040bac0
    assert word(0x70c300+4*4)==0x0040ca00
    assert [word(0x753330+i*4) for i in range(3)]==[0x40a650,0x5594a0,0x559600]
    # Nonindexed and indexed packers load all four 16-byte source blocks.
    for sites in ([0x40bc38,0x40bc70,0x40bc88,0x40bca0],
                  [0x40cbc0,0x40cbe0,0x40cbf8,0x40cc10]):
        values=[word(address) for address in sites]
        assert all(value>>26==0x1e for value in values)  # EE lq
        assert [value&0xffff for value in values]==[0,16,32,48]
    base=0x559600
    count=(word(base+12)>>16)&255
    assert count==47
    code=retail.bytes_at(base+16,count*8)
    # The only control transfers are the empty-input exit, the triangle loop,
    # and the restart after E-bit termination. Every delay pair is checked.
    pairs=list(struct.iter_unpack('<II',code))
    branch_info=[]
    for index,(lo,hi) in enumerate(pairs):
        if lo>>25 in (0x20,0x21,0x24,0x25,0x28,0x29,0x2c,0x2d,0x2e,0x2f):
            displacement=lo&0x7ff
            if displacement&0x400: displacement-=0x800
            branch_info.append(dict(instruction=index,target=index+1+displacement,
                                    delay=index+1,opcode=f'{lo:#010x}'))
    assert [(row['instruction'],row['target']) for row in branch_info]==[(4,43),(36,11),(45,1)]
    assert pairs[4][0]==0x500c0026 and pairs[5]==(0x0a2b03ff,0x000002ff)
    assert pairs[36][0]==0x5a0067e6 and pairs[37]==(0x8000033c,0x000002ff)
    assert pairs[45][0]==0x400007d3 and pairs[46]==(0x8000033c,0x000002ff)
    assert pairs[43]==(0x8000033c,0x400002ff) and pairs[44]==(0x8000033c,0x000002ff)
    # Block11..35 has no branch. Thus position loads14..16 always reach
    # overwrites22..24 before position stores29..31. The only backedge returns
    # to11, before both load and overwrite. Empty input goes straight to E43;
    # MSCNT restart at45 returns to1, before the input check and loop entry.
    # Taint bit0 is x, bit1 y, bit2 z, bit3 w. Only unknown incoming vertex
    # components are seeded; parameter-block data is a separate established API.
    taint=[0]*32
    input_loads=[]
    overwrites=[]
    output_stores=[]
    for index,(lo,hi) in enumerate(struct.iter_unpack('<II',code)):
        address=base+16+index*8
        before=taint[:]
        if hi>>31: raise AssertionError('Unexpected immediate-mode VU pair')
        ft=(hi>>16)&31;fs=(hi>>11)&31;fd=(hi>>6)&31
        mask=sum(1<<lane for lane,bit in enumerate([24,23,22,21]) if hi>>bit&1)
        op=hi&63
        # Upper and lower halves observe the old vector values in this cycle.
        if hi&0x3fffffff==0x000002ff:
            pass
        elif op in (0x28,0x2a):  # component-wise add or multiply
            assert not ((before[fs]|before[ft])&mask),(index,'arithmetic unknown lane')
            taint[fd]&=~mask
        elif op==0x1a:  # multiply xy by a source z (UV perspective multiply)
            assert not before[fs]&mask and not before[ft]&4,(index,'broadcast unknown lane')
            taint[fd]&=~mask
        elif op in (0x3c,0x3d) and fd==5:  # ftoi0 / ftoi4, component masks
            assert not before[fs]&mask,(index,'convert unknown lane')
            taint[ft]&=~mask
        else:
            raise AssertionError((index,'Unknown upper opcode',hex(hi)))
        ft=(lo>>16)&31;fs=(lo>>11)&31;fd=(lo>>6)&31
        mask=sum(1<<lane for lane,bit in enumerate([24,23,22,21]) if lo>>bit&1)
        op=lo>>25;imm=lo&2047
        if op==0:  # vector load
            if fs==10:  # input vertex array in vi10, four qwords per vertex
                field=imm%4
                assert field in (0,1,2),'normal/padding qword must never be loaded'
                unknown=8 if field in (0,1) else 0
                input_loads.append(dict(instruction=index,address=f'{address:#x}',
                                       vertex=imm//4,qword=field,lane_mask=mask))
                taint[ft]=(taint[ft]&~mask)|(unknown&mask)
            else:
                assert fs==0,'unexpected data-load base'
                taint[ft]&=~mask
        elif op==1:  # vector store to the output packet
            assert ft==11 and not before[fs]&mask,(index,'unknown lane reaches packet')
            output_stores.append(dict(instruction=index,vector=fs,lane_mask=mask))
        elif op==0x40:
            sub=lo&63
            if sub==0x3d and fd==15:  # integer-to-vector lane move
                assert fs in (13,14)
                taint[ft]&=~mask
                if ft in (8,9,10): overwrites.append(dict(instruction=index,vector=ft,lane_mask=mask))
            elif (sub,fd) in ((0x3c,12),(0x3c,26),(0x3d,26),(0x3c,27),(0x3f,15)):
                # nop, xtop, xitop, xgkick, iswr: no input-vector-lane read
                pass
            elif sub==0x30:  # integer add
                pass
            else:
                raise AssertionError((index,'Unknown lower special opcode',hex(lo)))
        elif op in (4,5,8,9,0x20,0x28,0x2d):
            # Integer parameter loads/stores, counters, branches.
            pass
        else:
            raise AssertionError((index,'Unknown lower opcode',hex(lo)))
    assert [(row['vector'],row['lane_mask']) for row in overwrites]==[(8,8),(9,8),(10,8)]
    assert len(input_loads)==9
    assert sorted((row['vertex'],row['qword'],row['lane_mask']) for row in input_loads)==[
        (vertex,field,7 if field==1 else 15) for vertex in range(3) for field in range(3)]
    result=dict(program_address='0x00559600',instructions=count,
                program_sha256=hashlib.sha256(code).hexdigest(),
                state14_zero_clears_fog_selector=True,
                default_triangle_strip_backends=['0x0040bac0','0x0040ca00'],
                full_64_bytes_physically_copied=True,
                normal_and_padding_qword_not_loaded=True,
                uv_padding_w_not_loaded=True,
                camera_z_w_overwritten_before_use=True,
                no_unwritten_lane_reaches_float_operation_or_output=True,
                input_loads=input_loads,camera_w_overwrites=overwrites,
                output_stores=output_stores,
                scope='Installed no-fog Sky2 triangle pipeline, not arbitrary replacement callbacks',
                branch_flow=branch_info,
                end_instruction=43,end_delay_instruction=44,
                overwrite_dominates_position_output_on_every_reachable_path=True,
                encoding_references=[
                    'https://github.com/PCSX2/pcsx2/blob/master/pcsx2/DebugTools/DisVU1Micro.cpp',
                    'https://github.com/PCSX2/pcsx2/blob/master/pcsx2/DebugTools/DisVUmicro.h',
                    'https://github.com/PCSX2/pcsx2/blob/master/pcsx2/DebugTools/DisVUops.h'])
    args.output.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k not in ('input_loads','camera_w_overwrites','output_stores','encoding_references')},indent=2))

if __name__=='__main__':main()
