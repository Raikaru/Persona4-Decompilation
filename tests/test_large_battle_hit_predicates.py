"""Check actual guarded hit predicates and their current pointed-to values."""
from pathlib import Path
import re
import sys
import tempfile
import unittest
ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT/'tools'), str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from test_btl_motion_override_contract import definition
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime
OWNER = ROOT/'src/promoted/code1_001a.c'


def condition_at(body, token):
    at = body.index(token)
    start = body.rfind('if (', 0, at)
    assert start >= 0
    cursor = start + 4
    begin, depth = cursor, 1
    while depth:
        depth += (body[cursor] == '(') - (body[cursor] == ')')
        cursor += 1
    return body[begin:cursor-1]


def parts():
    text=OWNER.read_text()
    small=extract_guarded_body(text,'FUN_001A59A0','func_001a59a0')
    large=extract_guarded_body(text,'FUN_001A7720','func_001a7720')
    hit_type=re.search(r'typedef struct LargeBattleHitResult\s*\{.*?\}\s*LargeBattleHitResult;',text,re.S)[0]
    status_assignment=next(l.strip() for l in small.splitlines() if l.strip().startswith('addedStatus = '))
    motion_assignment=next(l.strip() for l in large.splitlines() if l.strip().startswith('hitMotion = '))
    return dict(HIT_TYPE=hit_type, STATUS_ASSIGN=status_assignment,
                MOTION_ASSIGN=motion_assignment, STATUS_TEST=condition_at(small,'*addedStatus &'),
                MOTION_NINE=condition_at(large,'*hitMotion == 9'),
                MOTION_MINUS_ONE=condition_at(large,'*hitMotion != -1'),
                SKILL_PROVIDER=definition('src/Main/Battle/Data/datCalc.c','func_0023df70'),
                STATUS_PROVIDER=definition('src/datCalc/datCalc_grouped.c','datCalcChkBadStatus'))


def fixture(mutation=None):
    values=parts()
    if mutation=='motion_address_nine':values['MOTION_NINE']=values['MOTION_NINE'].replace('*hitMotion == 9','(s32)(u32)hitMotion == 9')
    if mutation=='motion_address_minus_one':values['MOTION_MINUS_ONE']=values['MOTION_MINUS_ONE'].replace('*hitMotion != -1','(s32)(u32)hitMotion != -1')
    if mutation=='unsigned_motion':values['MOTION_MINUS_ONE']=values['MOTION_MINUS_ONE'].replace('*hitMotion != -1','*(u8 *)hitMotion != -1')
    if mutation=='status_address':values['STATUS_TEST']=values['STATUS_TEST'].replace('*addedStatus','(u32)addedStatus')
    if mutation=='cached_motion':
        values['MOTION_NINE']=values['MOTION_NINE'].replace('*hitMotion','cachedMotion')
        values['MOTION_MINUS_ONE']=values['MOTION_MINUS_ONE'].replace('*hitMotion','cachedMotion')
    if mutation=='cached_status':values['STATUS_TEST']=values['STATUS_TEST'].replace('*addedStatus','cachedStatus')
    text=Path(__file__).with_name('large_battle_hit_predicate_fixture.c.in').read_text()
    for key,value in values.items():text=text.replace('@'+key+'@',value)
    assert not re.search(r'@[A-Z_]+@',text)
    return RUNTIME_C+text+ENTRY_C


class LargeBattleHitPredicates(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error

    def execute(self,optimization,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_hit_predicate_') as temporary:
            directory=Path(temporary);source=directory/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,directory/'fixture',optimization,(ROOT/'include',))
            return self.runtime.run(binary)

    def test_actual_predicates_reload_signed_motion_and_status(self):
        for opt in ('-O0','-O2'):
            with self.subTest(optimization=opt):
                result=self.execute(opt)
                self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                self.assertEqual(result.stdout,'motion_predicates=327680 status_word_predicates=262144\n')
                print(opt,result.stdout.strip())

    def test_negative_controls(self):
        for mutation in ('motion_address_nine','motion_address_minus_one','unsigned_motion','status_address','cached_motion','cached_status'):
            with self.subTest(mutation=mutation):
                result=self.execute('-O2',mutation)
                self.assertEqual(result.returncode,1,result.stdout+result.stderr)
                self.assertIn('scenario',result.stdout)


if __name__=='__main__':unittest.main()
