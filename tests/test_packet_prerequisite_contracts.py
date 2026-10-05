"""Source-bound finite packet-return and sound-stop prerequisite contracts.

Positive fixtures execute unmodified extracted production bodies, including the
real packet allocator. Explicit negative mutations apply only to separate test
strings; candidate/source files are never rewritten. No MWCC or engine run.
"""
from pathlib import Path
import hashlib
import json
import re
import subprocess
import sys
import tempfile
import unittest
from unittest import mock
from native32_support import ENTRY_C, RUNTIME_C, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import recovery_quality as Q

OWNERS = {
    'ALLOCATOR': ('src/promoted/code1_0019.c', 'func_00194470'),
    'FACTORY_COLOR': ('src/promoted/code1_001b.c', 'func_001ba530'),
    'FACTORY_QUAT': ('src/promoted/code1_001b.c', 'func_001ba710'),
    'FACTORY_ACTION': ('src/Battle/btlFormation.c', 'func_001d3b50'),
    'SOUND_STOP': ('src/promoted/code1_001e.c', 'func_001eb7f0'),
}

def body(key):
    owner, name = OWNERS[key]
    return Q.function_bodies(ROOT / owner)[name][1]

def caller_bodies(owner):
    """Preserve the finite census when a guard begins with a genuine helper."""
    path = ROOT / owner
    bodies = Q.function_bodies(path)
    if owner == 'src/promoted/code1_001b.c':
        text = path.read_text()
        for name, prefix, address in (
                ('func_001b4880', 'void', 0x001b4880),
                ('btlCameraNormalizeColor', 'static inline void', 0),
                ('btlCameraMultiplyColor', 'static inline void', 0),
                ('btlCameraBlendAmbient', 'static inline s32', 0)):
            matches = list(re.finditer(r'(?m)^' + prefix + ' ' + name + r'\([^;]*?\)\s*\{', text))
            assert len(matches) == 1, 'Expected one exact definition: ' + name
            match = matches[0]
            end, depth = match.end(), 1
            while depth:
                depth += (text[end] == '{') - (text[end] == '}')
                end += 1
            source = text[match.start():end]
            assert text.count(source) == 1
            bodies[name] = (address, source)
    return bodies

# Every control makes one narrow semantic defect. All compiled controls must
# report CHECK failure and exit(1); a crash/sanitizer trap is a failed control.
MUTATIONS = {
    'color_wrong_return': ('FACTORY_COLOR', 'return o;', 'return o + 4;'),
    'color_wrong_kind': ('FACTORY_COLOR', '0x608, 0x10', '0x607, 0x10'),
    'color_wrong_size': ('FACTORY_COLOR', '0x608, 0x10', '0x608, 0x14'),
    'color_wrong_callback': ('FACTORY_COLOR', '(void (*)(void))func_001ba0e0', '(void (*)(void))func_001ba590'),
    'color_narrow_word': ('FACTORY_COLOR', '*(s32 *)p = arg0;', '*(u8 *)p = (u8)arg0;'),
    'color_narrow_duration': ('FACTORY_COLOR', '*(s32 *)(p + 8) = arg1;', '*(u16 *)(p + 8) = (u16)arg1;'),
    'color_extra_write': ('FACTORY_COLOR', 'return o;', '*(u32 *)(p + 4) = 1;\n    return o;'),
    'quat_wrong_return': ('FACTORY_QUAT', 'return o;', 'return o + 4;'),
    'quat_wrong_kind': ('FACTORY_QUAT', '0x60A, 0x28', '0x60B, 0x28'),
    'quat_wrong_size': ('FACTORY_QUAT', '0x60A, 0x28', '0x60A, 0x2C'),
    'quat_wrong_callback': ('FACTORY_QUAT', '(void (*)(void))func_001ba590', '(void (*)(void))func_001ba0e0'),
    'quat_drop_w': ('FACTORY_QUAT', '*(struct F4 *)p = value;', 'p[0] = value.x0; p[1] = value.x1; p[2] = value.x2;'),
    'quat_wrong_frame_offset': ('FACTORY_QUAT', '*(s32 *)(p + 8) = arg1;', '*(s32 *)(p + 4) = arg1;'),
    'quat_narrow_frame': ('FACTORY_QUAT', '*(s32 *)(p + 8) = arg1;', '*(u16 *)(p + 8) = (u16)arg1;'),
    'quat_extra_write': ('FACTORY_QUAT', 'return o;', '*(u32 *)(p + 9) = 1;\n    return o;'),
    'action_wrong_return': ('FACTORY_ACTION', 'return packet;', 'return packet + 4;'),
    'action_wrong_kind': ('FACTORY_ACTION', '0xb06, 4', '0xb07, 4'),
    'action_wrong_size': ('FACTORY_ACTION', '0xb06, 4', '0xb06, 8'),
    'action_wrong_callback': ('FACTORY_ACTION', '(code *)func_001d3950', '(code *)func_001ba590'),
    'action_wrong_payload': ('FACTORY_ACTION', 'work[0] = action;', 'work[0] = action + 1;'),
    'action_corrupt_guard': ('FACTORY_ACTION', 'return packet;', '*((u8 *)work + 4) = 0;\n    return packet;'),
    'sound_wrong_predicate': ('SOUND_STOP', 'if (temp_4 & 0x1000)', 'if (temp_4 & 0x2000)'),
    'sound_wrong_clear': ('SOUND_STOP', 'temp_4 & ~0x1000;', 'temp_4 & ~0x3000;'),
    'sound_clear_high_bits': ('SOUND_STOP', 'temp_4 & ~0x1000;', '(temp_4 & ~0x1000) & 0x7fffffff;'),
    'sound_wrong_task': ('SOUND_STOP', 'iGpffffb3ac + 0xDD4', 'iGpffffb3ac + 0xDD0'),
    'sound_narrow_task': ('SOUND_STOP', '*(s32 *)(iGpffffb3ac + 0xDD4)', '*(u16 *)(iGpffffb3ac + 0xDD4)'),
    'sound_wrong_fade': ('SOUND_STOP', 'func_0045af60(1, 0xF, 2, 0x13);', 'func_0045af60(1, 0xF, 2, 0x12);'),
    'sound_reverse_calls': ('SOUND_STOP', 'func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));\n        func_0045af60(1, 0xF, 2, 0x13);', 'func_0045af60(1, 0xF, 2, 0x13);\n        func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));'),
    'sound_clear_after_stop': ('SOUND_STOP', '*(s32 *)temp_5 = temp_4 & ~0x1000;\n        func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));', 'func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));\n        *(s32 *)temp_5 = temp_4 & ~0x1000;'),
    'sound_missing_stop': ('SOUND_STOP', 'func_00212210(*(s32 *)(iGpffffb3ac + 0xDD4));', ''),
    'sound_missing_fade': ('SOUND_STOP', 'func_0045af60(1, 0xF, 2, 0x13);', ''),
}

def fixture(sound=False, mutation=None):
    name = 'sound_stop_prerequisite_fixture.c.in' if sound else 'packet_prerequisite_fixture.c.in'
    text = (ROOT / 'tests' / name).read_text()
    keys = ('SOUND_STOP',) if sound else ('ALLOCATOR', 'FACTORY_COLOR', 'FACTORY_QUAT', 'FACTORY_ACTION')
    for key in keys:
        source = body(key)
        if mutation and MUTATIONS[mutation][0] == key:
            _, old, new = MUTATIONS[mutation]
            assert source.count(old) == 1, (mutation, old)
            source = source.replace(old, new)
        marker = '%%' + key + '%%'
        assert text.count(marker) == 1
        text = text.replace(marker, source)
    assert '%%' not in text
    return RUNTIME_C + text + ENTRY_C

class PacketPrerequisites(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        # Missing native tooling is an actual failure for this independent gate.
        cls.runtime = native32_runtime()

    def execute(self, text, optimization, label):
        # Persist exact executed fixtures and binaries for an auditable receipt.
        directory = ROOT / 'proof' / 'native-runs' / (label + optimization[1:])
        directory.mkdir(parents=True, exist_ok=True)
        source = directory / 'fixture.c'
        source.write_text(text)
        executable = self.runtime.compile(source, directory / 'fixture', optimization, (ROOT / 'include',))
        result = self.runtime.run(executable)
        (directory / 'result.json').write_text(json.dumps({
            'returncode': result.returncode, 'stdout': result.stdout, 'stderr': result.stderr,
            'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
            'executable_sha256': hashlib.sha256(executable.read_bytes()).hexdigest(),
            'optimization': optimization,
        }, indent=2) + '\n')
        return result

    def test_exact_factories_and_real_allocator(self):
        for opt in ('-O0', '-O2'):
            with self.subTest(optimization=opt):
                result = self.execute(fixture(), opt, 'positive-packets-')
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, '669 packet batches; 2007 exact factory calls passed\n')

    def test_exact_sound_stop(self):
        for opt in ('-O0', '-O2'):
            with self.subTest(optimization=opt):
                result = self.execute(fixture(sound=True), opt, 'positive-sound-')
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, '1424 sound flag/task cases; 2848 exact stop calls passed\n')

    def test_factory_semantic_negatives(self):
        for name, (key, _, _) in MUTATIONS.items():
            if key == 'SOUND_STOP':
                continue
            for opt in ('-O0', '-O2'):
                with self.subTest(control=name, optimization=opt):
                    result = self.execute(fixture(mutation=name), opt, name + '-')
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertRegex(result.stdout, r'^line [0-9]+, scenario [0-9]+: ')
                    self.assertNotIn('passed', result.stdout)

    def test_sound_semantic_negatives(self):
        for name, (key, _, _) in MUTATIONS.items():
            if key != 'SOUND_STOP':
                continue
            for opt in ('-O0', '-O2'):
                with self.subTest(control=name, optimization=opt):
                    result = self.execute(fixture(sound=True, mutation=name), opt, name + '-')
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertRegex(result.stdout, r'^line [0-9]+, scenario [0-9]+: ')
                    self.assertNotIn('passed', result.stdout)

    def test_false_void_factory_signatures_do_not_compile(self):
        calls = {'FACTORY_COLOR': 'func_001ba530(0, 0)',
                 'FACTORY_QUAT': 'func_001ba710((f32 *)0, 0)',
                 'FACTORY_ACTION': 'func_001d3b50((u8 *)0)'}
        for key, call in calls.items():
            signature = body(key).split('{', 1)[0].strip()
            bad_signature = re.sub(r'^u8 \*', 'void ', signature)
            self.assertNotEqual(signature, bad_signature)
            for bad in (False, True):
                with self.subTest(factory=key, false_void=bad), tempfile.TemporaryDirectory() as directory:
                    source = Path(directory) / 'signature.c'
                    source.write_text('#include "type.h"\n' + (bad_signature if bad else signature) + ';\nu8 *observe(void) { return ' + call + '; }\n')
                    command = [self.runtime.compiler, '--target=i386-linux-gnu', '-m32', '-std=c11',
                               '-ffreestanding', '-Werror', '-I' + str(ROOT / 'include'),
                               '-fsyntax-only', str(source)]
                    result = subprocess.run(command, capture_output=True, text=True)
                    report = ROOT / 'proof' / (key.lower() + ('-false-void' if bad else '-true-pointer') + '.json')
                    report.write_text(json.dumps({'source': source.read_text(), 'command': command,
                                                 'returncode': result.returncode, 'stderr': result.stderr}, indent=2) + '\n')
                    self.assertEqual(result.returncode != 0, bad, result.stderr)
                    if bad:
                        self.assertIn('void', result.stderr)

    def test_sound_prototype_rejects_invented_argument(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / 'signature.c'
            source.write_text('void func_001eb7f0(void);\nvoid observe(void) { func_001eb7f0((void *)0); }\n')
            result = subprocess.run([self.runtime.compiler, '-std=c11', '-Werror', '-fsyntax-only', str(source)], capture_output=True, text=True)
            (ROOT / 'proof' / 'sound-invented-argument.json').write_text(json.dumps(
                {'source': source.read_text(), 'returncode': result.returncode, 'stderr': result.stderr}, indent=2) + '\n')
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('too many arguments', result.stderr)

    def test_finite_source_caller_contracts(self):
        callers = {}
        for owner in ('src/promoted/code1_001a.c', 'src/promoted/code1_001b.c', 'src/promoted/code1_001e.c'):
            text = (ROOT / owner).read_text()
            self.assertNotRegex(text, r'void func_001eb7f0\(u8')
            self.assertRegex(text, r'void func_001eb7f0\(void\)')
            for name, (_, source) in caller_bodies(owner).items():
                calls = re.findall(r'^\s*func_001eb7f0\(([^)]*)\)\s*;', source, re.MULTILINE)
                if calls:
                    self.assertTrue(all(not call.strip() for call in calls), (owner, name, calls))
                    callers[name] = len(calls)
        self.assertEqual(callers, {'func_001a06d0': 1, 'func_001b1b30': 1, 'func_001b2380': 1,
                                   'func_001b3870': 1, 'func_001b4880': 1, 'func_001eaac0': 1})
        b = caller_bodies('src/promoted/code1_001b.c')
        for function in ('func_001ba530', 'func_001ba710', 'func_001d3b50'):
            actual = []
            for name, (_, source) in b.items():
                if name == function:
                    continue
                # Count real invocations regardless of the result local's name.
                # Exact source extraction excludes the helper and local declarations
                # are removed explicitly; the finite expected caller stays unchanged.
                code = re.sub(r'(?m)^\s*extern [^;]+;', '', source)
                calls = re.findall(r'\b' + function + r'\s*\(', code)
                if calls:
                    self.assertEqual(len(calls), 1, (name, function))
                    actual.append(name)
            self.assertEqual(actual, ['func_001b4880'])

    def test_finite_census_rejects_helper_calls(self):
        owner = ROOT / 'src/promoted/code1_001b.c'
        original = owner.read_text()
        read_text = Path.read_text
        for helper in ('btlCameraNormalizeColor', 'btlCameraMultiplyColor',
                       'btlCameraBlendAmbient'):
            anchor = original.index(' ' + helper + '(')
            start = original.index('{', anchor) + 1
            for call in ('func_001eb7f0();', 'func_001ba530(0, 0);',
                         'func_001ba710((f32 *)0, 0);', 'func_001d3b50((u8 *)0);'):
                changed = original[:start] + '\n    ' + call + original[start:]
                def substituted(path, *args, **kwargs):
                    return changed if path == owner else read_text(path, *args, **kwargs)
                with self.subTest(helper=helper, extra_helper_call=call):
                    with mock.patch.object(Path, 'read_text', substituted):
                        with self.assertRaises(AssertionError):
                            self.test_finite_source_caller_contracts()

if __name__ == '__main__':
    unittest.main()
