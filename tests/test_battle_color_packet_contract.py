"""Execute the exact color-packet constructor with bounded native32 seams.

The source prefix, constructor, and installed update callback are extracted from
btlMain.c without rewriting their statements. Allocation and the callback's
external renderer are test doubles. Native cases sample raw color words; they do
not prove all 2**32 conversions or execute the engine or either full caller.
"""
import hashlib
from pathlib import Path
import re
import subprocess
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q

SCENARIO_COUNT = 9282
OWNER = ROOT / "src/Battle/btlMain.c"


def provider_source():
    return Q.function_bodies(OWNER)["func_001b83f0"][1]


def callback_source():
    return Q.function_bodies(OWNER)["func_001b7e70"][1]


def source_prefix():
    text = OWNER.read_text()
    marker = "// FUN_001B5E60"
    assert text.count(marker) == 1
    return text.split(marker)[0]


def replace_once(text, old, new):
    assert text.count(old) == 1, (old, text.count(old))
    return text.replace(old, new, 1)


MUTANTS = {
    "wrong_color_bit": ("packed.value = (u32)param_1;", "packed.value = (u32)param_1 ^ 0x80000000U;"),
    "lost_sign_bit": ("packed.value = (u32)param_2;", "packed.value = (u32)param_2 & 0x7fffffffU;"),
    "wrong_channel": ("pfVar1[9] = fGpffff81f4 * (float)packed.bytes[1];", "pfVar1[9] = fGpffff81f4 * (float)packed.bytes[2];"),
    "wrong_row": ("pfVar1[0x12] =", "pfVar1[0x16] ="),
    "wrong_color_word": ("packed.value = (u32)param_3;", "packed.value = (u32)param_2;"),
    "wrong_scale": ("pfVar1[0] = fGpffff81f4 *", "pfVar1[0] = 1.0f *"),
    "narrow_frames": ("*(u32 *)((u8 *)pfVar1 + 0x60) = param_4;", "*(u16 *)((u8 *)pfVar1 + 0x60) = (u16)param_4;"),
    "wide_flags": ("*(u16 *)(pfVar1 + 0x1a) = param_5;", "*(u32 *)(pfVar1 + 0x1a) = param_5;"),
    "narrow_flags": ("*(u16 *)(pfVar1 + 0x1a) = param_5;", "*(u8 *)(pfVar1 + 0x1a) = (u8)param_5;"),
    "wrong_callback": ("(code *)func_001b7e70;", "(code *)wrong_update;"),
    "wrong_allocation_kind": ("func_00194470(0x602, 0x6c)", "func_00194470(0x600, 0x6c)"),
    "wrong_allocation_size": ("func_00194470(0x602, 0x6c)", "func_00194470(0x602, 0x68)"),
    "wrong_return": ("return (BtlPacket*)iVar2;", "return (BtlPacket*)((u8*)iVar2 + 4);"),
    "clobbered_current_frame": ("*(u16 *)(pfVar1 + 0x1a) = param_5;", "*(u16 *)(pfVar1 + 0x1a) = param_5;\n    *(u32 *)((u8 *)pfVar1 + 0x64) = 0;"),
}


def fixture_source(mutation=None):
    body = provider_source()
    if mutation:
        body = replace_once(body, *MUTANTS[mutation])
    template = (ROOT / "tests/battle_color_packet_fixture.c.in").read_text()
    return (RUNTIME_C + source_prefix()
            + template.replace("%%CALLBACK%%", callback_source()).replace("%%PROVIDER%%", body)
            + ENTRY_C)


def signature_source(signature):
    return '''#include "type.h"
typedef struct BtlPacket BtlPacket;
''' + signature + ''';
typedef BtlPacket *(*ExpectedColorContract)(s32, s32, s32, u32, u16);
_Static_assert(__builtin_types_compatible_p(__typeof__(&func_001b83f0), ExpectedColorContract),
               "color_packet_signature_mismatch");
'''


class BattleColorSourceBinding(unittest.TestCase):
    def test_mutations_bind_once_to_actual_source(self):
        for name, mutation in MUTANTS.items():
            with self.subTest(mutation=name):
                replace_once(provider_source(), *mutation)

    def test_complete_declaration_family(self):
        declarations = []
        for path, expected_count in (("src/promoted/code1_001a.c", 3),
                                     ("src/promoted/code1_001b.c", 1)):
            text = (ROOT / path).read_text()
            found = re.findall(r"extern\s+BtlPacket\s*\*\s*func_001b83f0\([^;]*\);", text)
            self.assertEqual(len(found), expected_count)
            declarations.extend(found)
        for declaration in declarations:
            args = declaration.split("(", 1)[1].split(")")[0].split(",")
            self.assertEqual([arg.strip().split()[0] for arg in args],
                             ["s32", "s32", "s32", "u32", "u16"])
        self.assertIn("BtlPacket* func_001b83f0(s32 param_1, s32 param_2, s32 param_3, u32 param_4, u16 param_5)", provider_source())


class BattleColorPacketContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as exc:
            raise unittest.SkipTest(str(exc)) from exc

    def run_fixture(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix="p4_color_packet_") as directory:
            directory = Path(directory)
            source = directory / "fixture.c"
            source.write_text(fixture_source(mutation))
            for optimization in ("-O0", "-O2"):
                with self.subTest(mutation=mutation, optimization=optimization):
                    executable = self.runtime.compile(source, directory / ("fixture" + optimization),
                                                      optimization, (ROOT / "include",))
                    result = self.runtime.run(executable)
                    diagnostic = result.stdout + result.stderr
                    if mutation is None:
                        self.assertEqual(result.returncode, 0, diagnostic)
                        self.assertEqual(result.stdout, f"color packet scenarios: {SCENARIO_COUNT} passed; callback smoke paths: 4 passed\n")
                    else:
                        self.assertEqual(result.returncode, 1,
                                         "A semantic control must fail an ordinary assertion, never crash: " + diagnostic)
                        self.assertRegex(result.stdout, r"line [0-9]+, scenario [0-9]+: ")
                    print((mutation or "actual") + " " + optimization + ": " + result.stdout.strip())

    def test_actual_provider(self):
        for name, text in (("provider", provider_source()), ("callback", callback_source()),
                           ("prefix", source_prefix())):
            print(name + " source SHA256: " + hashlib.sha256(text.encode()).hexdigest())
        self.run_fixture()

    def test_signature_and_compile_negative_controls(self):
        signature = provider_source().split("\n{", 1)[0]
        mutations = {
            "unsigned_first": ("s32 param_1", "u32 param_1"),
            "unsigned_second": ("s32 param_2", "u32 param_2"),
            "unsigned_third": ("s32 param_3", "u32 param_3"),
            "signed_frames": ("u32 param_4", "s32 param_4"),
            "narrow_frames": ("u32 param_4", "u16 param_4"),
            "wide_flags": ("u16 param_5", "u32 param_5"),
            "signed_flags": ("u16 param_5", "s16 param_5"),
            "wrong_pointer_return": ("BtlPacket* func_", "u8* func_"),
            "integer_return": ("BtlPacket* func_", "s32 func_"),
            "wrong_arity": (", u16 param_5", ""),
            "old_style": (signature.split("(", 1)[1], ")"),
        }
        with tempfile.TemporaryDirectory(prefix="p4_color_signature_") as directory:
            source = Path(directory) / "signature.c"
            for name in [None, *mutations]:
                with self.subTest(signature=name):
                    text = signature if name is None else replace_once(signature, *mutations[name])
                    source.write_text(signature_source(text))
                    result = subprocess.run([self.runtime.compiler, "--target=i386-linux-gnu", "-std=c11",
                                             "-fsyntax-only", "-I" + str(ROOT / "include"), str(source)],
                                            capture_output=True, text=True, timeout=60)
                    self.assertEqual(result.returncode, 0 if name is None else 1, result.stderr)
                    if name is not None:
                        self.assertIn("color_packet_signature_mismatch", result.stderr)
                    print("signature " + (name or "actual") + ": " + ("accepted" if name is None else "rejected by type assertion"))


def add_mutant_test(name):
    def test(self):
        self.run_fixture(name)
    test.__name__ = "test_control_" + name
    setattr(BattleColorPacketContract, test.__name__, test)


for _name in MUTANTS:
    add_mutant_test(_name)
