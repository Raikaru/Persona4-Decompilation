"""Run the actual Flash constructors/reset with explicit allocation/geometry seams."""
from pathlib import Path
import argparse
import hashlib
import json
import re
import sys
import tempfile

ARCHIVE = Path(__file__).resolve().parent
ROOT = ARCHIVE.parents[2]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--output", type=Path, required=True)
parser.add_argument("--emit-only", action="store_true")
args = parser.parse_args()
OUT = args.output.resolve()
OUT.mkdir(parents=True, exist_ok=True)
sys.path.insert(0, str(ROOT / "tests"))
sys.path.insert(0, str(ROOT / "tools"))
from native32_support import RUNTIME_C, ENTRY_C, native32_runtime
import probe_variants as P

owner = ROOT / "src/promoted/effPolygonFlash.c"
original = owner.read_bytes()
text = P._read_text(owner)
functions = {}
for address in ("004a09e0", "004a0af0", "004a07b0"):
    a, b = P.region_for(text, "FUN_" + address.upper(), "func_" + address)
    functions[address] = text[a:b]
record_type = re.search(r"typedef struct FlashInclinedParticle \{.*?\} FlashInclinedParticle;", text, re.S).group()

common = RUNTIME_C + r'''
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
#define NULL ((void *)0)
static unsigned scenario, count, cloneCase, textureCase, dirty;
static unsigned allocations, creations, clones, locks, unlocks, uvCalls, textureCalls;
#define CHECK(value) do { if (!(value)) native32_failure(__LINE__, scenario, #value); } while (0)
static u8 arena[16 + 16 + 8 * 32 + 16] __attribute__((aligned(16)));
static u8 vertexStorage[16 + 8 * 4 * 12 + 16] __attribute__((aligned(16)));
static u8 model[0x20] __attribute__((aligned(16)));
static u8 frame[0x20] __attribute__((aligned(16)));
static u8 geometry[0x60] __attribute__((aligned(16)));
static u8 morph[0x18] __attribute__((aligned(16)));
static u8 originalModel[0x20] __attribute__((aligned(16)));
static u8 originalState[0x10] __attribute__((aligned(16)));
static u8 effect[0x44] __attribute__((aligned(16)));
static u8 config[0x98] __attribute__((aligned(16)));
static u8 texture, material;
static char D_00713FF0[1], D_00713408[1];
static void word(void *p, u32 value) { memcpy(p, &value, 4); }
static void half(void *p, u16 value) { memcpy(p, &value, 2); }
static u32 readWord(void *p) { u32 value; memcpy(&value, p, 4); return value; }
static u8 *allocate(s32 size, s32 alignment) {
    CHECK(size == (s32)(16 + count * 32) && alignment == 0x40000);
    ++allocations;
    return arena + 16;
}
static u8 *(*jtbl_008873E8[])(s32, s32) = {allocate};
static void func_0044ea90(char *file, s32 line) { CHECK(file == D_00713FF0 && line == 0xaf1); }
static void func_0046d730(char *file, s32 line) { (void)file; (void)line; CHECK(0); }
static u8 *func_00482f70(s32 copies, s32 triangles, s32 vertices, const void *indices, s32 flags) {
    CHECK(copies == (s32)count && triangles == 2 && vertices == 4 && indices == D_00713408 && flags == 0x4c);
    ++creations;
    return model;
}
static u8 *func_00483270(void *input) { CHECK(input == originalModel); ++clones; return model; }
static s32 func_00481300(s32 id) { CHECK(id == 0x13); return (s32)&texture; }
static void func_003c42b0(void *input, void *value) { CHECK(input == &material && value == &texture); ++textureCalls; }
static void func_00483970(void *input, void *value) { CHECK(input == model && value == &texture); ++textureCalls; }
static void func_004a08a0(u8 *state, u8 *parameters) { CHECK(state == arena + 16 && parameters == config); ++uvCalls; }
static void RpGeometryLock(void *input, s32 mode) { CHECK(input == geometry && mode == 2); ++locks; }
static void func_003c22f0(void *input) { CHECK(input == geometry); ++unlocks; }
/* The source owner's memset declaration accepts a 32-bit address word. */
static void addressMemset(s32 address, s32 value, s32 size) {
    CHECK((u8 *)address == vertexStorage + 16 && value == 0 && size == (s32)(count * 4 * 12));
    memset((void *)address, value, (unsigned)size);
}
''' + record_type + '\n'
source = common + functions["004a09e0"] + '\n' + functions["004a0af0"]
source += '\n#define memset addressMemset\n' + functions["004a07b0"] + '\n#undef memset\n'
source += r'''
int main(void) {
    u8 before[sizeof(arena)], expected[sizeof(arena)];
    CHECK(sizeof(FlashInclinedParticle) == 32);
    for (count=0; count<=8; ++count)
    for (cloneCase=0; cloneCase<2; ++cloneCase)
    for (textureCase=0; textureCase<2; ++textureCase)
    for (dirty=0; dirty<2; ++dirty) {
        u8 *state;
        allocations=creations=clones=locks=unlocks=uvCalls=textureCalls=0;
        memset(arena, 0x6b, sizeof(arena));
        memset(vertexStorage, 0x7c, sizeof(vertexStorage));
        memset(model, 0, sizeof(model));
        memset(frame, 0, sizeof(frame));
        memset(geometry, 0, sizeof(geometry));
        memset(morph, 0, sizeof(morph));
        memset(effect, 0, sizeof(effect));
        memset(config, 0, sizeof(config));
        half(model, dirty ? 4 : 0);
        half(model + 8, count * 4);
        word(model + 0x10, (u32)frame);
        word(model + 0x14, (u32)&material);
        word(frame + 0x18, (u32)geometry);
        half(geometry + 0xc, 0x20);
        word(geometry + 0x5c, (u32)morph);
        word(morph + 0x14, (u32)(vertexStorage + 16));
        word(config + 0x38, count);
        word(originalState + 4, (u32)originalModel);
        word(effect + 0x3c, (u32)originalState);
        word(effect + 0x40, (u32)config);
        memcpy(before, arena, sizeof(arena));
        state = cloneCase ? func_004a0af0(effect) : func_004a09e0(config, textureCase ? &texture : NULL);
        CHECK(state == arena + 16 && allocations == 1 && uvCalls == 1);
        CHECK(creations == !cloneCase && clones == cloneCase && textureCalls == !cloneCase);
        memcpy(expected, before, sizeof(expected));
        word(expected + 16, (u32)(state + 16));
        word(expected + 20, (u32)model);
        word(expected + 24, (u32)state);
        CHECK(memcmp(expected, arena, sizeof(arena)) == 0);
        word(effect + 0x3c, (u32)state);
        func_004a07b0(effect);
        CHECK(locks == 1 && unlocks == 1);
        for (unsigned i=0; i<count; ++i) word(expected + 32 + i * 32, 0xffffffffU);
        CHECK(memcmp(expected, arena, sizeof(arena)) == 0);
        for (unsigned i=0; i<sizeof(vertexStorage); ++i) {
            CHECK(vertexStorage[i] == ((i >= 16 && i < 16 + count * 48) ? 0 : 0x7c));
        }
        CHECK((readWord(geometry + 0xc) & 0xffff) == (dirty ? 0x21U : 0x20U));
        for (unsigned i=0; i<count; ++i) {
            FlashInclinedParticle *particle = (FlashInclinedParticle *)(state + 16 + 32 * i);
            CHECK(particle->age == -1);
        }
        ++scenario;
    }
    CHECK(scenario == 72);
    native32_text("72 constructor/reset lifecycle cases passed\n");
    return 0;
}
''' + ENTRY_C

cases = {"installed": source, "wrong-allocation-stride": source.replace("* 32;", "* 28;"),
         "wrong-reset-stride": source.replace("entry += 8;", "entry += 7;")}
assert len(set(cases.values())) == 3
directory = OUT / "native-lifecycle-aligned"
directory.mkdir(exist_ok=True)
tempfile.tempdir = str(directory)
if args.emit_only:
    for label, content in cases.items():
        (directory / (label + ".c")).write_text(content)
    print("Emitted authenticated fixture inputs; no compiler or runtime called")
    raise SystemExit(0)
runtime = native32_runtime()
rows = []
for label, content in cases.items():
    cpath = directory / (label + ".c")
    cpath.write_text(content)
    for opt in ("-O0", "-O2"):
        binary = runtime.compile(cpath, directory / (label + opt), opt)
        result = runtime.run(binary)
        if label == "installed":
            assert result.returncode == 0 and result.stdout == "72 constructor/reset lifecycle cases passed\n", result
        else:
            assert result.returncode == 1 and "scenario" in result.stdout, result
        row = {"case": label, "optimization": opt, "exit_code": result.returncode,
               "stdout": result.stdout, "source_sha256": hashlib.sha256(content.encode()).hexdigest()}
        rows.append(row)
        print(json.dumps(row), flush=True)
assert owner.read_bytes() == original
receipt = {"owner_sha256": hashlib.sha256(original).hexdigest(), "results": rows,
           "function_sha256": {address: hashlib.sha256(body.encode()).hexdigest() for address, body in functions.items()},
           "scope": "Actual current 004a09e0/004a0af0 constructors and 004a07b0 reset; controlled allocator, geometry/UV and texture leaf providers; counts 0..8. No VU or rendered output.",
           "host": "freestanding i386 with undefined/bounds sanitizers"}
(directory / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
