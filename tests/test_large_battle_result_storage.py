"""Execute live 32-byte result construction and unchanged packet factories."""
from pathlib import Path
import re
import sys
import tempfile
import unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from test_btl_motion_override_contract import definition
from test_large_battle_vector_storage import structure
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime

def parts():
    text=(ROOT/'src/promoted/code1_001a.c').read_text()
    small=extract_guarded_body(text,'FUN_001A59A0','func_001a59a0')
    large=extract_guarded_body(text,'FUN_001A7720','func_001a7720')
    typ=structure(text,'LargeBattleHitResult')
    for body in (small,large):
        assert 'LargeBattleHitResult result;' in body
        assert 'extern void func_001f0a10(u8 *result);' in body
    assert 'extern u16 datCalcGetHp(s32 unit);' in large
    def statement(prefix,body=large):
        rows=[l.strip() for l in body.splitlines() if l.strip().startswith(prefix)]
        assert len(rows)==1,(prefix,rows)
        return rows[0]
    blocks=[]
    for body in (small,large):
        lines=body.splitlines()
        for pos,line in enumerate(lines):
            if line.strip()!='func_001f0a10((u8 *)&result);':continue
            end=pos+1
            while 'func_001f36e0(' not in lines[end]:end+=1
            blocks.append('\n'.join(l.strip() for l in lines[pos:end+1]))
    assert len(blocks)==4
    return dict(TYPE=typ,SMALL=blocks[0],TRANSFER=blocks[1],HP=blocks[2],STATUS=blocks[3],
                POINTER=statement('hpTransfer = '),
                POINTER_DECLARATION=re.search(r'(?m)^\s*s16 \*hpTransfer;',large)[0].strip(),
                DISPLAY_TRANSFER=statement('temp_2_121 = '),DISPLAY_HP=statement('temp_2_132 = '),
                HP_NONZERO=next(l.strip()[4:-3] for l in large.splitlines() if l.strip()=='if (result.hpDelta != 0) {'),
                DECLARATION='LargeBattleHitResult result;',
                PROVIDERS='\n'.join(definition(path,name) for path,name in (
                    ('src/promoted/code1_001f.c','func_001f0a10'),('src/Battle/btlTarget.c','func_001f36e0'),
                    ('src/promoted/code1_0020.c','func_00201de0'),('src/datCalc/datCalc_grouped.c','datCalcGetHp'))))

def fixture(mutation=None):
    v=parts()
    changes={
      'byte_hp_load':('TRANSFER','result.hpDelta = *hpTransfer;','result.hpDelta = *(u8 *)hpTransfer;'),
      'unsigned_hp_load':('TRANSFER','result.hpDelta = *hpTransfer;','result.hpDelta = *(u16 *)hpTransfer;'),
      'wrong_hp_arithmetic':('HP','result.hpDelta = 1 - (s32)','result.hpDelta = -1 - (s32)'),
      'status_wrong_offset':('STATUS','result.addedStatus =','result.removedStatus ='),
      'small_status_wrong_offset':('SMALL','result.addedStatus =','result.removedStatus ='),
      'short_clear':('PROVIDERS','memset(arg0, 0, 0x20);','memset(arg0, 0, 0x10);'),
      'short_target_copy':('PROVIDERS','memcpy(work + 8, param_3, 0x20);','memcpy(work + 8, param_3, 0x10);'),
      'short_display_copy':('PROVIDERS','memcpy(temp_16 + 8, result, 0x20);','memcpy(temp_16 + 8, result, 0x10);'),
      'wrong_hp_data_width':('PROVIDERS','return *(u16*)(unit + 8);','return *(u8*)(unit + 8);'),
      'undersized_object':('DECLARATION','LargeBattleHitResult result;','struct { s32 hpDelta,spDelta; u32 addedStatus; } result;'),
    }
    if mutation:
        key,a,b=changes[mutation];assert a in v[key];v[key]=v[key].replace(a,b)
    text=Path(__file__).with_name('large_battle_result_storage_fixture.c.in').read_text()
    for key,value in v.items():text=text.replace('@'+key+'@',value)
    assert not re.search(r'@[A-Z_]+@',text)
    return RUNTIME_C+text+ENTRY_C

class LargeBattleResultStorage(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_result_storage_') as temporary:
            path=Path(temporary);source=path/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,path/'fixture',opt,(ROOT/'include',))
            return self.runtime.run(binary)
    def test_live_payload_construction_and_providers(self):
        for opt in ('-O0','-O2'):
            with self.subTest(optimization=opt):
                r=self.execute(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr)
                self.assertEqual(r.stdout,'196610 result construction/provider cases passed\n');print(opt,r.stdout.strip())
    def test_negative_controls(self):
        for m in ('byte_hp_load','unsigned_hp_load','wrong_hp_arithmetic','status_wrong_offset','small_status_wrong_offset','short_clear','short_target_copy','short_display_copy','wrong_hp_data_width','undersized_object'):
            with self.subTest(mutation=m):
                r=self.execute('-O2',m);self.assertEqual(r.returncode,1,r.stdout+r.stderr);self.assertIn('scenario',r.stdout)

if __name__=='__main__':unittest.main()
