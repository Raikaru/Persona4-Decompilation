"""Exercise the recovered Fcl provider contracts with real 32-bit pointers."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import probe_variants
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

SOURCES = {
    "0010CE10": "src/Main/Battle/Data/datPersona.c",
    "0010CD70": "src/Main/Battle/Data/datPersona.c",
    "0011B9E0": "src/Kosaka/k_footstep_grouped.c",
    "003146C0": "src/Event/Fcl/y_fclCombineDraw.c",
    "00313690": "src/promoted/code1_0031.c",
}

PREFIX = r'''
#include "type.h"
static unsigned scenario, assertions;
static u8 D_005E4318[1];
static s8 D_00641E60[0x240];
#define CHECK(condition) do { if (!(condition)) native32_failure(__LINE__, scenario, #condition); } while (0)
void func_0046d730(void *file, s32 line) {
    CHECK(file == D_005E4318);
    CHECK(line == 0x6FE || line == 0x70A);
    ++assertions;
}
typedef union { u32 alignment; u8 bytes[0x600]; } Work;
typedef union { u32 alignment; u8 bytes[0x40]; } Task;
static Work work[2], wrapperWork;
static Task task[2], wrapper;
static u16 record[24], expected[24];
'''

SUFFIX = r'''
static void prepare_skills(u32 key, s32 selected, u16 replacement) {
    for (u32 i = 0; i < 24; ++i) record[i] = 0x3CC3;
    for (u32 i = 0; i < 8; ++i) record[6 + i] = (u16)(key + i + 1);
    if (selected >= 0) {
        record[6 + selected] = (u16)key;
        if (selected < 7) record[13] = (u16)key;
    }
    memcpy(expected, record, sizeof(record));
    if (selected >= 0) expected[6 + selected] = replacement;
    assertions = 0;
}

int main(void) {
    /* Cover the full previous-skill halfword domain at each slot, including
       duplicate IDs. Only the first occurrence may be changed. Guard words,
       unrelated skills and a missing-key record must remain untouched. */
    for (u32 key = 0; key < 0x10000; ++key) {
        u16 replacement = (u16)(key ^ 0xA55A);
        for (s32 selected = 0; selected < 8; ++selected) {
            prepare_skills(key, selected, replacement);
            CHECK(func_0010cd70((u8 *)record, (s16)key, replacement) == selected);
            CHECK(memcmp(record, expected, sizeof(record)) == 0);
            CHECK(assertions == ((key == 0 || replacement == 0) ? 1u : 0u) + (key == 0 ? 1u : 0u));
            ++scenario;
        }
        prepare_skills(key, -1, replacement);
        CHECK(func_0010cd70((u8 *)record, (s16)key, replacement) == -1);
        CHECK(memcmp(record, expected, sizeof(record)) == 0);
        CHECK(assertions == ((key == 0 || replacement == 0) ? 1u : 0u) + (key == 0 ? 1u : 0u));
        ++scenario;
    }

    /* Exercise the actual wrapper and setter together. Both child choices and
       the complete signed-word boundary must be forwarded without truncation. */
    u32 values[] = {0, 1, 0x7FFFFFFFu, 0x80000000u, 0xFFFFFFFFu, 0x12345678u,
                    0xFFFF0000u, 0x0000FFFFu, 0xA55AA55Au};
    for (u32 target = 0; target < 2; ++target) {
        *(u8 **)(wrapper.bytes + 0x38) = wrapperWork.bytes;
        *(u8 **)(wrapperWork.bytes + 4) = task[target].bytes;
        *(u8 **)(task[target].bytes + 0x38) = work[target].bytes;
        for (u32 index = 0; index < sizeof(values) / sizeof(values[0]); ++index) {
            memset(work, 0xCC, sizeof(work));
            func_003146c0(wrapper.bytes, (s32)values[index]);
            CHECK(*(u32 *)(work[target].bytes + 0x44) == values[index]);
            for (u32 other = 0; other < 2; ++other) {
                for (u32 offset = 0; offset < sizeof(work[other].bytes); ++offset) {
                    if (other != target || offset < 0x44 || offset >= 0x48)
                        CHECK(work[other].bytes[offset] == 0xCC);
                }
            }
            ++scenario;
        }
    }

    /* The table contains signed bytes, including negative values. Every valid
       index is queried through the actual signed-halfword provider. */
    for (u32 pattern = 0; pattern < 3; ++pattern) {
        for (u32 index = 0; index < sizeof(D_00641E60); ++index)
            D_00641E60[index] = (s8)((index * 37u + pattern * 113u) & 255u);
        for (s32 index = 0; index < sizeof(D_00641E60); ++index) {
            s32 value = ((u8 *)D_00641E60)[index];
            if (value >= 128) value -= 256;
            CHECK(func_00313690((s16)index) == value);
            ++scenario;
        }
    }
    native32_text("fcl state contract scenarios passed: ");
    native32_number(scenario); native32_text("\n");
    return 0;
}
'''


def fixture_source(overrides=None):
    overrides = overrides or {}
    bodies = []
    for address, relative in SOURCES.items():
        source = Path(overrides.get(relative, ROOT / relative)).read_text(encoding="utf-8")
        start, end = probe_variants.region_for(source, "FUN_" + address, "func_" + address.lower())
        bodies.append(source[start:end])
    return "\n".join((RUNTIME_C, PREFIX, *bodies, SUFFIX, ENTRY_C))


class FclStateContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def check_optimization(self, optimization):
        with tempfile.TemporaryDirectory(prefix="p4_fcl_state_") as directory:
            directory = Path(directory)
            source = directory / "fixture.c"
            source.write_text(fixture_source(), encoding="utf-8")
            executable = self.runtime.compile(source, directory / "fixture", optimization, (ROOT / "include",))
            result = self.runtime.run(executable)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertEqual(result.stdout, "fcl state contract scenarios passed: 591570\n")

    def test_provider_contracts_unoptimized(self):
        self.check_optimization("-O0")

    def test_provider_contracts_optimized(self):
        self.check_optimization("-O2")


if __name__ == "__main__":
    unittest.main()
