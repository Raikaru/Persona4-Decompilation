"""Verify signed message handles through the real manager and visibility predicate."""
from pathlib import Path
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q

MANAGER = ROOT / "src/itfMesManager.c"
PROCEDURE = ROOT / "src/promoted/code1_0027.c"


def fixture_source(mutation=None):
    manager = MANAGER.read_text()
    layout = manager[manager.index("typedef struct {"):manager.index("void func_002746c0")]
    bodies = Q.function_bodies(MANAGER)
    body = "\n".join(bodies[name][1] for name in ("func_00277070", "func_00279010", "func_00278110"))
    body += "\n" + Q.function_bodies(PROCEDURE)["func_0027bec0"][1]
    if mutation:
        before, after = mutation
        if body.count(before) != 1:
            raise AssertionError("Negative control does not identify one source expression")
        body = body.replace(before, after)
    return RUNTIME_C + '''
#include "type.h"
#include "message_handle.h"
extern char D_0063BE10[];
void func_0046d730(const char *file, s32 line);
''' + layout + body + r'''
static unsigned scenario;
#define CHECK(x) do { if (!(x)) native32_failure(__LINE__, scenario, #x); } while (0)
D_00881808_t D_00881808[18];
char D_0063BE10[1];
static u32 objects[18][20];
void func_0046d730(const char *file, s32 line) {
    native32_failure(line, scenario, "unexpected missing message object");
}
int main(void) {
    static const s32 handles[] = {0, 1, 17};
    static const u32 flags[] = {0, 0x100, 0x80000, 0x80100, 0x80200, 0x80300, 0xffffffff, 0x80400};
    static const s16 selected[] = {-32768, -3, -1, 0, 1, 32767};
    static const s16 counts[] = {-32768, -1, 0, 1, 5, 32767};
    for (unsigned i = 0; i < 18; ++i) D_00881808[i].unk0 = (u8 *)objects[i];
    CHECK(sizeof(D_00881808_t) == 32);
    for (unsigned h = 0; h < 3; ++h) for (unsigned f = 0; f < 8; ++f)
    for (unsigned s = 0; s < 6; ++s) for (unsigned c = 0; c < 6; ++c) {
        s32 handle = handles[h];
        u8 *object = D_00881808[handle].unk0;
        objects[0][0] = flags[(f + 3) % 8];
        *(s32 *)object = flags[f];
        *(s16 *)(object + 0x4A) = selected[s];
        *(s16 *)(object + 0x4E) = counts[c];
        ++scenario;
        CHECK(func_00278110(handle) == (s32)flags[f]);
        CHECK(func_00277070(handle) == selected[s]);
        CHECK(func_00279010(handle) == counts[c]);
        CHECK(func_0027bec0(handle) == (!(flags[f] & 0x80000) || (flags[f] & 0x300) < 0x100));
    }
    native32_text("message-handle contracts: 864 scenarios passed\n");
    return 0;
}
''' + ENTRY_C


class MessageHandleContractTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def run_fixture(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix="p4_message_handle_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(fixture_source(mutation))
            for level in ("-O0", "-O2"):
                executable = self.runtime.compile(source, directory / ("fixture" + level), level, (ROOT / "include",))
                result = self.runtime.run(executable)
                if mutation is None:
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, "message-handle contracts: 864 scenarios passed\n")
                else:
                    self.assertNotEqual(result.returncode, 0, "Negative control was not rejected")

    def test_real_getters_and_handle_forwarding(self):
        self.run_fixture()

    def test_wrong_handle_is_rejected(self):
        self.run_fixture(("temp_2 = func_00278110(handle);", "temp_2 = func_00278110(0);"))

    def test_wrong_selection_field_is_rejected(self):
        self.run_fixture(("return *(s16 *)(object + 0x4A);", "return *(s16 *)(object + 0x48);"))


if __name__ == "__main__":
    unittest.main()
