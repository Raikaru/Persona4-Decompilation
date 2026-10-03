"""Bounded typed model-call and defined packed top-byte transformation."""
import re
BASE='69799eb8fe97c414501d20af309688f147e0e5d2'
OWNER='src/promoted/code1_0012.c'

def arguments(line):
    inner=line[line.index('func_00124bb0(')+len('func_00124bb0('):-2]
    result=[]; depth=0; start=0
    for pos,ch in enumerate(inner):
        if ch in '([': depth+=1
        elif ch in ')]': depth-=1
        elif ch==',' and depth==0: result.append(inner[start:pos].strip());start=pos+1
    result.append(inner[start:].strip())
    return result

def transform(text):
    before,body=text.split('void func_001265a0(s32 arg1) {',1)
    body,after=body.split('\n#else\nINCLUDE_ASM("asm/nonmatchings/code1_0012", func_001265a0);',1)
    assert body.count('    extern s32 func_00124bb0();\n')==1
    body=body.replace('    extern s32 func_00124bb0();\n','')
    for suffix,channel in [('3','var_8'),('6','var_8_2'),('9','var_8_3')]:
        name='temp_9_'+suffix
        # Full original census: declaration, definition, packed use, fabricated float.
        assert len(re.findall(r'\b'+name+r'\b',body))==4
        assert body.count('    s32 '+name+';')==1
        body=body.replace('    s32 '+name+';','    u32 '+name+';')
        old='('+channel+' & 0xFF) << 0x18'; assert body.count(old)==1
        body=body.replace(old,'((u32) '+channel+' & 0xFF) << 0x18')
    for channel in ('var_7','var_7_2'):
        old='('+channel+' & 0xFF) << 0x18';assert body.count(old)==1
        body=body.replace(old,'((u32) '+channel+' & 0xFF) << 0x18')
    calls=re.findall(r'(?m)^ +func_00124bb0\([^\n]+;',body);assert len(calls)==5
    for i,line in enumerate(calls):
        args=arguments(line)
        if i in (0,1,4):
            assert len(args)==13
            assert args[5] in ('M2C_BITWISE(f32, temp_9_3)','M2C_BITWISE(f32, temp_9_6)','M2C_BITWISE(f32, temp_9_9)')
            order=(0,6,7,8,9,10,11,1,2,12,3,4)
        else:
            assert len(args)==12
            order=(0,5,6,7,8,9,10,1,2,11,3,4)
        indent=line[:len(line)-len(line.lstrip())]
        replacement=indent+'func_00124bb0('+', '.join(args[j] for j in order)+');'
        body=body.replace(line,replacement,1)
    body=body.replace('The model-draw ABI/ACC expressions below remain unrecovered.',
        'Model calls use the same-owner typed definition; special ACC\n                                 * producers remain supplied/unproven expressions.')
    for suffix in ('3','6','9'):
        assert len(re.findall(r'\btemp_9_'+suffix+r'\b',body))==3
    return before+'void func_001265a0(s32 arg1) {'+body+'\n#else\nINCLUDE_ASM("asm/nonmatchings/code1_0012", func_001265a0);'+after
