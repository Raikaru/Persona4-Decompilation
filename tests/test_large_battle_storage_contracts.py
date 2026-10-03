"""Execute guarded controller UID statements and hit selections verbatim.

The complete unfinished controllers are deliberately not executed. These
fixtures cover real source expressions, declarations, and the unchanged UID
payload factory; expectations use retail load/store widths and record layout.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime
from test_large_battle_animation_contracts import calls, guarded
from test_btl_motion_override_contract import definition

ROOT = Path(__file__).resolve().parents[1]
TARGETS = ('func_001a7720', 'func_001a59a0')
IDS = r'''0ULL, 1ULL, 0x7fffffffULL, 0x80000000ULL, 0x100000000ULL,
0x1122334455667788ULL, 0x8765432155667788ULL, 0x89abcdef01234567ULL,
0xffffffff00000000ULL, 0xffffffffffffffffULL'''
PRELUDE = r'''
#include "type.h"
static unsigned scenario;
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__,scenario,#c); } while(0)
static const u64 uids[] = { %%IDS%% };
'''.replace('%%IDS%%', IDS)
NAME = r'(?:arg0|temp_\w+|var_\w+|sp[0-9A-F]+)'


def declaration(body, name):
    if name == 'arg0':
        return re.search(r'void func_\w+\(([^)]+)\)', body)[1] + ';'
    return re.search(r'(?m)^    (?:s64|s32|u8) \*?' + name + r';', body)[0].strip()


def memory(expr):
    """Read only the known UID byte-view forms, without rewriting test input."""
    simple = re.search(r'\*\(s(?:32|64) \*\)\((' + NAME + r') \+ (0x[0-9A-F]+|8)\)', expr)
    if simple:
        return simple[1], int(simple[2], 0)
    old = re.search(r'\*\(\s*s(?:32|64) \*\s*\)\(\(u8 \*\)\((' + NAME + r')\) \+ \((0x[0-9A-F]+|8|0)\)\)', expr)
    if old:
        return old[1], int(old[2], 0)
    if re.search(r'\*\(s64 \*\)arg0', expr) or re.search(r'\*\(\s*s(?:32|64) \*\s*\)\(\(u8 \*\)\(\(u8 \*\)arg0\) \+ \(0\)\)', expr):
        return 'arg0', 0
    return None


def uid_statements(body):
    stores, loads = [], []
    for line in body.splitlines():
        if ' = ' not in line or not line.rstrip().endswith(';'):
            continue
        lhs, rhs = line.strip().rstrip(';').split(' = ', 1)
        if 'func_' in rhs:
            continue
        target, source = memory(lhs), memory(rhs)
        if target and target[1] in (8, 0x18, 0x28, 0x60):
            stores.append((line.strip(), target, source, rhs))
        elif re.fullmatch(NAME, lhs) and source and source[1] in (0, 0x58):
            loads.append((line.strip(), lhs, source))
    return stores, loads


def uid_fixture(mutation=None):
    # Hundreds of independent sites otherwise inline into one enormous main at
    # O2. Fixture-only noinline keeps optimizer cost bounded; no source statement
    # or source declaration under test is changed.
    wrappers, invoke = [], []
    count = 0
    for name in TARGETS:
        body = guarded(name)
        stores, loads = uid_statements(body)
        assert len(stores) == (272 if name.endswith('7720') else 81)
        for statement, target, source, rhs in stores:
            names = sorted(set(re.findall(NAME, statement)))
            declarations = []
            for identifier in names:
                decl = declaration(body, identifier)
                typ = decl[:-len(identifier)-1].strip()
                init = '(s64)uid' if '*' not in decl else ('(' + typ + ')'+('destination' if identifier == target[0] else 'input'))
                declarations.append(decl + '\n    '+identifier+' = '+init+';')
            if mutation == 'store32':
                statement = statement.replace('s64', 's32', 1)
            elif mutation == 'load32' and source:
                lhs, rhs0 = statement.split(' = ')
                statement = lhs + ' = ' + rhs0.replace('s64', 's32')
            elif mutation == 'slot' and target[1] == 8:
                statement = statement.replace('+ 8)', '+ 0x10)', 1).replace('+ (8)', '+ (0x10)', 1)
            wrapper = 'site_'+str(count)
            setup = ''
            if source:
                source_array = 'destination' if source[0] == target[0] else 'input'
                setup = 'memcpy('+source_array+' + '+str(source[1])+', &uid, 8);'
            wrappers.append('static __attribute__((noinline)) void '+wrapper+'(u64 uid) {\n'+r'''
    _Alignas(16) u8 destination[0x90], input[0x90], expected[0x90], saved[0x90];
    memset(destination,0xa5,sizeof destination); memset(input,0x3c,sizeof input);
''' + '\n'.join(declarations) + '\n' + setup + r'''
    memcpy(expected,destination,sizeof expected); memcpy(saved,input,sizeof saved);
''' + '    memcpy(expected+'+str(target[1])+', &uid, 8);\n    '+statement+r'''
    CHECK(memcmp(destination,expected,sizeof expected)==0);
    CHECK(memcmp(input,saved,sizeof saved)==0);
}
''')
            invoke.append(wrapper+'(uids[i]); ++scenario;'); count += 1
        for statement, target, source in loads:
            wrapper = 'site_'+str(count)
            decl = declaration(body, target)
            srcdecl = declaration(body, source[0])
            typ = srcdecl[:-len(source[0])-1].strip()
            if mutation == 'local32':
                decl = decl.replace('s64','s32')
            if mutation == 'load32':
                statement = statement.replace('s64','s32')
            wrappers.append('static __attribute__((noinline)) void '+wrapper+'(u64 uid) {\n'+r'''
    _Alignas(16) u8 input[0x90]; memset(input,0x3c,sizeof input);
''' + decl+'\n'+srcdecl+'\n'+source[0]+' = ('+typ+')input;\n'+
                'memcpy(input+'+str(source[1])+', &uid, 8);\n'+statement+'\n'+
                'CHECK((u64)'+target+' == uid);\n}\n')
            invoke.append(wrapper+'(uids[i]); ++scenario;'); count += 1
    # The saved dependency is a real scalar copy between two source locals.
    body = guarded(TARGETS[0])
    copy = re.search(r'(?m)^\s*sp468 = var_17_3;',body)[0].strip()
    decls = declaration(body,'sp468')+'\n'+declaration(body,'var_17_3')
    if mutation == 'local32': decls=decls.replace('s64','s32')
    wrappers.append('static __attribute__((noinline)) void copy_uid(u64 uid) {\n'+decls+'\nvar_17_3=(s64)uid;\n'+copy+'\nCHECK((u64)sp468==uid);\n}')
    invoke.append('copy_uid(uids[i]); ++scenario;');count += 1
    code=RUNTIME_C+PRELUDE+'\n'.join(wrappers)+'\nint main(void) {\nfor(unsigned i=0;i<sizeof uids/sizeof uids[0];++i) {\n'+'\n'.join(invoke)+'\n}\nnative32_text("UID cases passed\\n");return 0;\n}\n'+ENTRY_C
    return code, count*10


def one_line(body, prefix):
    found = [l.strip() for l in body.splitlines() if l.strip().startswith(prefix)]
    assert len(found) == 1, (prefix, found)
    return found[0]


def hit_fixture(mutation=None):
    small, large = guarded('func_001a59a0'), guarded('func_001a7720')
    hit_type=re.search(r'typedef struct LargeBattleHitResult \{.*?\} LargeBattleHitResult;', (ROOT/'src/promoted/code1_001a.c').read_text(), re.S)[0]
    select=one_line(small,'hit = ')
    if mutation=='stride': select=select.replace('[sp1D0]','[sp1D0 * 8]')
    if mutation=='base': select=select.replace('+ 0xF0', '+ 0x780')
    motion=one_line(small,'temp_2_27 = ')
    if mutation=='unsigned_motion': motion=motion.replace('hit->motion','(u8)hit->motion')
    small_calls=[c for c in calls(small,'func_001f36e0') if 'temp_2_48' in c]
    assert len(small_calls)==1
    display_calls=calls(small,'func_00201de0');assert len(display_calls)==1
    larger_select='\n'.join(one_line(large,p) for p in ('temp_2_95 = ','sp120 = ','temp_2_96 = ','sp110 = ','hitMotion = '))
    if mutation=='large_stride': larger_select=larger_select.replace('sp3B0 << 5','sp3B0 << 8')
    fixture=(ROOT/'tests/large_battle_storage_fixture.c.in').read_text()
    if mutation=='unsigned_motion': fixture=fixture.replace('s8 temp_2_27;', 's32 temp_2_27;')
    return RUNTIME_C+PRELUDE+fixture.replace('%%HIT_TYPE%%',hit_type).replace('%%SMALL_SELECT%%',select).replace('%%MOTION%%',motion).replace('%%SMALL_RESULT_SETUP%%','\n'.join(one_line(small,p) for p in ('temp_2_48 = ','sp1F0 = '))).replace('%%RESULT_CALL%%',small_calls[0]).replace('%%DISPLAY_CALL%%',display_calls[0]).replace('%%LARGE_SELECT%%',larger_select).replace('%%LARGE_RESULT_SETUP%%','\n'.join(one_line(large,p) for p in ('temp_2_108 = ','sp240 = ')))+ENTRY_C


def payload_fixture(mutation=None):
    body=guarded('func_001a7720')
    expressions=calls(body,'func_001d65d0');assert len(expressions)==7
    provider=definition('src/promoted/code1_001d.c','func_001d65d0')
    prototype=re.search(r'(?m)^u8 \*func_001d65d0\([^;]+;', (ROOT/'src/promoted/code1_001a.c').read_text())[0]
    if mutation=='signature32': provider=provider.replace('s64 arg3', 's32 arg3')
    if mutation=='payload32': provider=provider.replace('*(s64 *)(work + 0x10) = arg3;', '*(s32 *)(work + 0x10) = (s32)arg3;')
    if mutation=='argument32': expressions[0]=expressions[0].replace('(*(s64 *)(temp_2_23 + 0x58))','(*(s32 *)(temp_2_23 + 0x58))')
    wrappers=[]
    for i,expr in enumerate(expressions):
        wrappers.append('static u8 *call_'+str(i)+'(void) {\n'+r'''
    u8 *arg0=action, *temp_2_23=inputPacket, *sp4D0=unit;
    s32 sp598=101,sp59C=202,sp5A0=303,var_2_7=505,sp400=-37;
    s16 var_17=-17;
    return '''+expr+';\n}')
    fixture=(ROOT/'tests/large_battle_uid_payload_fixture.c.in').read_text()
    return RUNTIME_C+PRELUDE+fixture.replace('%%PROTOTYPE%%',prototype).replace('%%PROVIDER%%',provider).replace('%%CALLS%%','\n'.join(wrappers))+ENTRY_C


class LargeBattleStorageContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try: cls.runtime=native32_runtime()
        except Native32Unavailable as exc: raise unittest.SkipTest(str(exc))

    def exercise(self,code,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_battle_storage_') as directory:
            p=Path(directory);src=p/'fixture.c';src.write_text(code)
            for opt in ('-O0','-O2'):
                executable=self.runtime.compile(src,p/('fixture'+opt),opt,(ROOT/'include',ROOT/'tests'))
                result=self.runtime.run(executable)
                if mutation: self.assertNotEqual(result.returncode,0,mutation+' escaped '+opt)
                else: self.assertEqual(result.returncode,0,result.stdout+result.stderr)

    def test_all_uid_stores_and_locals(self):
        code,count=uid_fixture(); self.assertEqual(count,3710); self.exercise(code)

    def test_uid_mutations(self):
        for mutation in ('store32','load32','local32','slot'):
            with self.subTest(mutation=mutation): self.exercise(uid_fixture(mutation)[0],mutation)

    def test_hit_records(self): self.exercise(hit_fixture())

    def test_hit_mutations(self):
        for mutation in ('stride','base','unsigned_motion','large_stride'):
            with self.subTest(mutation=mutation): self.exercise(hit_fixture(mutation),mutation)

    def test_actual_uid_payload_provider(self): self.exercise(payload_fixture())

    def test_uid_payload_signature(self):
        with tempfile.TemporaryDirectory(prefix='p4_uid_signature_') as directory:
            p=Path(directory);src=p/'fixture.c';src.write_text(payload_fixture('signature32'))
            with self.assertRaisesRegex(RuntimeError,'conflicting types'):
                self.runtime.compile(src,p/'fixture','-O2',(ROOT/'include',ROOT/'tests'))

    def test_payload_mutations(self):
        for mutation in ('payload32','argument32'):
            with self.subTest(mutation=mutation): self.exercise(payload_fixture(mutation),mutation)


if __name__=='__main__': unittest.main()
