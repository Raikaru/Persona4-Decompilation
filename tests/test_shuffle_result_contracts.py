"""Exercise the full shuffle-result machine and its real rotation forwarder.

The state-machine oracle uses a separate raw-offset transition model and integer
random formulas. Production helpers and function bodies are included unchanged;
typed mocks check arguments, order, buffers, and callback-time mutations. These
are 32-bit C semantic tests, not a PS2 emulator or an instruction-match verdict.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q
import verify as V

RESULT = ROOT / "src/promoted/btlShuffleResult.c"
DRAW = ROOT / "src/Battle/btlShuffleDraw.c"
CALC = ROOT / "src/Battle/btlShuffleCalc.c"
HEADER = ROOT / "include/btl_shuffle_draw_internal.h"
FIXTURE = ROOT / "tests/shuffle_result_fixture.c.in"


def vector_contract() -> str:
    header = HEADER.read_text(encoding="utf-8")
    vector = re.search(r"typedef struct RwV3d\s*\{[^}]+\}\s*BtlShuffleVec3;", header)
    if vector is None:
        raise AssertionError("Shared three-component vector definition is missing")
    result = vector.group(0) + "\n"
    for name in ("func_003730f0", "func_003761f0"):
        declaration = re.search(r"void " + name + r"\([^;]+;", header)
        if declaration is None:
            raise AssertionError(name + ": missing shared declaration")
        result += declaration.group(0) + "\n"
    return result


def state_fixture(source: str | None = None) -> str:
    source = source if source is not None else RESULT.read_text(encoding="utf-8")
    prefix = source[:source.index("/* The list cursor")]
    prefix = "\n".join(line for line in prefix.splitlines() if not line.startswith("#include"))
    first = source.index("typedef struct ShuffleResultState")
    last = source.index("// FUN_00382BA0", first)
    body = source[first:last]
    if "NON_MATCHING" in body or "INCLUDE_ASM" in body:
        raise AssertionError("The runtime fixture requires active result C")
    sound = "s32 func_0045af60(s16, s16, s16, s16);\n"
    layout = '_Static_assert(sizeof(BtlShuffleVec3) == 12, "three-component vector");\n'
    layout += '_Static_assert(sizeof(ShuffleResultState) == 0x1C, "result payload prefix");\n'
    for member, offset in (("phase", 0), ("timer", 4), ("step", 6), ("spinsRemaining", 8),
                           ("resultCard", 12), ("isUpright", 16), ("uprightOverride", 20),
                           ("secondaryResult", 24)):
        layout += (f'_Static_assert(__builtin_offsetof(ShuffleResultState, {member}) == {offset}, '
                   f'"result payload {member}");\n')
    return (RUNTIME_C + '\n#include "type.h"\n' + vector_contract() + sound
            + prefix + "\n" + body + "\n" + layout + FIXTURE.read_text(encoding="utf-8") + ENTRY_C)


PROVIDER_FIXTURE = r'''
static unsigned scenario;
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__, scenario, #c); } while (0)
typedef union { u64 align; u8 bytes[0x24000]; } Context;
static Context actual, expected;
static f32 fromBits(u32 bits) { f32 result; memcpy(&result, &bits, 4); return result; }
int main(void) {
    const u16 times[] = {0, 1, 0x7FFF, 0x8000, 0xFFFF};
    const u32 values[] = {0, 0x80000000u, 0x3FA00000u, 0xC0200000u,
                          0x43340000u, 0x7F800000u, 0xFF800000u, 0x7FC12345u};
    for (s32 card = 0; card < 4; ++card)
    for (unsigned a = 0; a < 5; ++a) for (unsigned b = 0; b < 5; ++b)
    for (unsigned pattern = 0; pattern < 8; ++pattern) {
        BtlShuffleVec3 axis;
        f32 start, end;
        u8 *p;
        ++scenario;
        memset(&actual, 0xA5, sizeof actual); memcpy(&expected, &actual, sizeof actual);
        axis.x = fromBits(values[pattern]); axis.y = fromBits(values[(pattern + 1) % 8]);
        axis.z = fromBits(values[(pattern + 2) % 8]);
        start = fromBits(values[(pattern + 3) % 8]); end = fromBits(values[(pattern + 4) % 8]);
        p = expected.bytes + card * 0xE8 + 0x1D70C;
        *(u16 *)(p + 0) = 0; *(u16 *)(p + 2) = times[b]; *(u16 *)(p + 4) = times[a];
        memcpy(p + 0x18, p + 8, 16); memcpy(p + 0x28, &axis, 12);
        memcpy(p + 0x34, &start, 4); memcpy(p + 0x38, &end, 4);
        *(u32 *)(expected.bytes + card * 0xE8 + 0x1D6A8) = 4;
        func_003761f0(actual.bytes, card, times[a], times[b], &axis, start, end);
        memset(&axis, 0, sizeof axis);
        CHECK(memcmp(&actual, &expected, sizeof actual) == 0);
    }
    native32_text("shuffle rotation-forwarding scenarios: "); native32_number(scenario); native32_text("\n");
    return 0;
}
'''


def provider_fixture() -> str:
    aliases = ("typedef BtlShuffleVec3 ShuffleVec3;\n"
               "typedef struct { f32 x, y, z, w; } ShuffleVec4;\n")
    bodies = Q.function_bodies(CALC)["func_003730f0"][1] + "\n"
    bodies += Q.function_bodies(DRAW)["func_003761f0"][1] + "\n"
    return (RUNTIME_C + '\n#include "type.h"\n' + vector_contract() + aliases
            + bodies + PROVIDER_FIXTURE + ENTRY_C)


class ShuffleResultSourceTests(unittest.TestCase):
    def test_recovery_and_interfaces_are_active(self) -> None:
        for path, name in ((RESULT, "func_00381a70"), (DRAW, "func_003761f0"), (CALC, "func_003730f0")):
            marker = next(row for row in V.scan_markers(path) if row["name"] == name)
            self.assertFalse(marker.get("asm"), name)
            self.assertFalse(marker.get("nonmatching"), name)
        self.assertIn("func_00381a70(arg0)", RESULT.read_text(encoding="utf-8"))
        vector_contract()


class ShuffleResultRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def check_fixture(self, source_text: str, expected: str) -> None:
        with tempfile.TemporaryDirectory(prefix="p4_shuffle_result_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(source_text, encoding="utf-8")
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    executable = self.runtime.compile(source, directory / ("fixture" + level), level, (ROOT / "include",))
                    result = self.runtime.run(executable)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, expected)

    def test_all_phases_random_domain_and_callback_mutations(self) -> None:
        self.check_fixture(state_fixture(), "shuffle-result state scenarios: 3032; roll scenarios: 180224\n")

    def test_both_float_controls_and_unsigned_timings_are_forwarded(self) -> None:
        self.check_fixture(provider_fixture(), "shuffle rotation-forwarding scenarios: 800\n")


if __name__ == "__main__":
    unittest.main()
