"""Exercise the real field-file provider with complete word transport inputs."""
from pathlib import Path
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, native32_runtime
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import recovery_quality as Q
FIXTURE = r'''
#include "type.h"
#include "field_transition_internal.h"
static unsigned scenario, checks, stage, total;
static s32 mode, exists, expectedField, expectedRoom;
static char *path;
static u8 file[32];
char D_005F1118[] = "field/";
char D_005F1170[] = "%04d_%02d.hbn";
char D_005F1108[] = "k_fldHBN.c";
char iGpffff9ef0;
#define CHECK(x) do { ++checks; if (!(x)) native32_failure(__LINE__, scenario, #x); } while (0)
s32 func_0014eec0(void) { CHECK(stage++ == 0); return mode; }
void strcpy(void *dst, const char *src) {
    CHECK(stage++ == 1); CHECK(src == D_005F1118);
    for (unsigned i = 0; i < sizeof(D_005F1118); ++i) ((char *)dst)[i] = src[i];
}
s32 sprintf(void *destination, const char *format, ...) {
    char *dst = destination;
    __builtin_va_list ap;
    CHECK(stage++ == 2); CHECK(format == D_005F1170);
    __builtin_va_start(ap, format);
    s32 field = __builtin_va_arg(ap, s32);
    s32 room = __builtin_va_arg(ap, s32);
    __builtin_va_end(ap);
    CHECK(field == expectedField); CHECK(room == expectedRoom);
    path = dst; dst[0] = 'x'; dst[1] = 0; return 1;
}
s32 H_Cdvd_FileExists(void *arg) { CHECK(stage++ == 3); CHECK(arg == path); CHECK(path[0] == 'x'); return exists; }
void func_00440b68(char *arg, const char *source, s32 line) {
    CHECK(stage++ == 4); CHECK(arg == &iGpffff9ef0); CHECK(source == D_005F1108); CHECK(line == 0x27d);
}
u8 *func_00454a60(void *arg, s32 flags) {
    CHECK(stage++ == 5); CHECK(arg == path); CHECK(flags == 0); return file;
}
'''
MAIN = r'''
static void test_word(u32 field, u32 room, s32 selectedMode, s32 fileExists) {
    ++scenario; mode = selectedMode; exists = fileExists;
    expectedField = field & 0xffffu; expectedRoom = room & 0xffffu; stage = 0; path = 0;
    u8 *result = func_0015ff20((s32)field, (s32)room);
    CHECK(result == (mode ? (u8 *)1 : exists ? file : (u8 *)0));
    CHECK(stage == (mode ? 1u : exists ? 6u : 4u));
    ++total;
}
int main(void) {
    static const u32 high[] = {0, 0x00010000u, 0x7fff0000u, 0x80000000u, 0xffff0000u};
    for (unsigned h = 0; h < sizeof(high)/sizeof(high[0]); ++h) {
        for (u32 low = 0; low < 65536; ++low) {
            u32 field = high[h] | low;
            u32 room = high[(h + 2) % 5] | (65535 - low);
            test_word(field, room, 0, 1);
            test_word(field, room, 0, 0);
            test_word(field, room, 1, 1);
        }
    }
    static const u32 edge[] = {0, 1, 0x7fff, 0x8000, 0xffff, 0x10000, 0x7fffffff, 0x80000000u, 0xffffffffu};
    for (unsigned f=0;f<9;f++) for(unsigned r=0;r<9;r++) {
        test_word(edge[f],edge[r],-1,0);
        test_word(edge[f],edge[r],0,1);
    }
    native32_text("field file transport scenarios "); native32_number(total);
    native32_text(" checks "); native32_number(checks); native32_text("\n");
    return 0;
}
'''
def source(mutation=None):
    body = Q.function_bodies(ROOT/'src/promoted/k_fldHBN.c')['func_0015ff20'][1]
    if mutation:
        old, new = mutation
        if old not in body:
            raise AssertionError('stale negative control: '+old)
        body = body.replace(old, new, 1)
    return RUNTIME_C + FIXTURE + body + MAIN + ENTRY_C
class FieldFileTransport(unittest.TestCase):
    def run_fixture(self, code, opt):
        runtime = native32_runtime()
        with tempfile.TemporaryDirectory(prefix='field-file-transport-') as directory:
            root = Path(directory)
            src = root/'fixture.c'; src.write_text(code)
            return runtime.run(runtime.compile(src, root/'fixture', opt, (ROOT/'include',)))
    def test_full_word_boundaries(self):
        for opt in ('-O0', '-O2'):
            result = self.run_fixture(source(), opt)
            self.assertEqual(result.returncode, 0, result.stdout+result.stderr)
            print(result.stdout.strip())
    def test_negative_controls(self):
        for mutation in [
            ('temp_16 = (u16)arg0;', 'temp_16 = arg0;'),
            ('temp_16 = (u16)arg0;', 'temp_16 = (s16)arg0;'),
            ('if (temp_16 == -1)', 'if (arg0 == -1)'),
            ('arg1 & 0xFFFF', 'arg1'),
            ('H_Cdvd_FileExists(&sp30) == 0', 'H_Cdvd_FileExists(&sp30) != 0'),
        ]:
            with self.subTest(mutation=mutation[0]):
                result = self.run_fixture(source(mutation), '-O2')
                self.assertNotEqual(result.returncode, 0, 'negative control escaped: '+str(mutation))
if __name__ == '__main__':
    unittest.main()
