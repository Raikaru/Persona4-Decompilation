"""Execute the reconstructed trail against independent retail-derived expectations."""
from pathlib import Path
import hashlib
import json
import shutil
import struct
import subprocess
import sys
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import verify as V

candidate = HERE / "body.c"
out = (ROOT / (sys.argv[1] if len(sys.argv) > 1 else "build/shuffle-trail-behavior")).resolve()
assert out.is_relative_to((ROOT / "build").resolve())
out.mkdir(parents=True, exist_ok=False)
cfg = V.load_config()
windows = V._read_json(V.FUNCTION_WINDOWS)
retail = V.RetailElf(cfg["retail_elf"], V._read_json(V.TARGET), windows["sha1"])
gp, symbols = V.symbol_addresses()
constants = {}
for name in ("iGpffff8218", "iGpffff8308", "iGpffff8400", "iGpffff8404", "iGpffff8408", "D_0060A0E0", "D_0060A0E4", "D_0060A0E8"):
    address = V.resolve_symbol(name, gp, symbols)
    assert address is not None, name
    raw = retail.bytes_at(address, 4)
    value, = struct.unpack("<f", raw)
    constants[name] = dict(address=address, bytes=raw.hex(), value=value)
(out / "constants.json").write_text(json.dumps(constants, indent=2) + "\n")

header = r'''
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef uint8_t u8;
typedef int8_t s8;
typedef uint32_t u32;
typedef int32_t s32;
typedef float f32;
typedef struct RwV3d { f32 x, y, z; } ShuffleVec3;
typedef struct RwMatrixTag {
    ShuffleVec3 right; u32 flags;
    ShuffleVec3 up; u32 pad1;
    ShuffleVec3 at; u32 pad2;
    ShuffleVec3 pos; u32 pad3;
} BtlShuffleMatrix;
enum { rwRENDERSTATECULLMODE = 20, rwRENDERSTATEZTESTENABLE = 6, rwRENDERSTATEZWRITEENABLE = 8 };
typedef s32 (*BtlShuffleRenderStateSet)(s32, void *);
struct RxObjSpace3DVertex;
static void func_0046d730(const void *, s32);
static void RpSkyRenderStateSet(s32, s32);
static s32 set_state(s32, void *);
static void func_003764b0(u8 *, s32, f32, u8 *);
static f32 func_0036de70(u8 *);
static f32 func_0036deb0(u8 *);
static void *func_00410420(struct RxObjSpace3DVertex *, u32, BtlShuffleMatrix *, u32);
static s32 func_004106a0(s32);
static void *func_003e9700(s32);
static void *func_00457120(void);
static BtlShuffleRenderStateSet D_00887300[1] = {set_state};
static const u8 D_0064EA20[] = "btlShuffleDraw.c";
'''
source = candidate.read_text()
vector_view = "extern ShuffleVec3 D_0060A0E0;" in source
constant_defs = "\n".join("f32 " + name + " = " + row["value"].hex() + "f;" for name, row in constants.items() if not (vector_view and name.startswith("D_0060A0E"))) + "\n"
if vector_view:
    constant_defs += "ShuffleVec3 D_0060A0E0 = {" + ",".join(constants[name]["value"].hex() + "f" for name in ("D_0060A0E0", "D_0060A0E4", "D_0060A0E8")) + "};\n"
    constant_defs += "const float expected_direction[3] = {" + ",".join(constants[name]["value"].hex() + "f" for name in ("D_0060A0E0", "D_0060A0E4", "D_0060A0E8")) + "};\n"
# Host bridges adapt the vertex pointer width, the opaque 32-bit frame handle,
# and integer-valued render-state tokens. Arithmetic and control flow are intact.
source = source.replace("func_00410420((s32)first,", "func_00410420(first,")
source = source.replace("func_00410420((s32)second,", "func_00410420(second,")
source = source.replace("func_003e9700(*(struct RwFrame **)((u8 *)func_00457120() + 4))", "func_003e9700(*(s32 *)((u8 *)func_00457120() + 4))")
import re
source = re.sub(r"RpSkyRenderStateSet\((\d+), \(void \*\)(0x[0-9A-Fa-f]+)\)", r"RpSkyRenderStateSet(\1, \2)", source)
footer = r'''
static u8 *work;
static u8 rgba[4];
static struct { s32 reserved; s32 frame; } frame_holder;
static int mode_now, state_now, sample_count, submit_count, primitive_count;
static int sky_count, state_count, assert_count, camera_count, dimension_count;
static int phase, cases, tested_vertices;
static float input_length, input_opacity;
static ShuffleVec3 sampled[21];
static u8 sampled_rgb[21][3];
static float sampled_times[21];

static void equal_f(float got, float wanted) {
    if (!(fabsf(got - wanted) <= 0.0001f)) {
        fprintf(stderr, "mode=%d submit=%d float got %.9g expected %.9g\n", mode_now, submit_count, got, wanted);
        abort();
    }
}
static void func_0046d730(const void *file, s32 line) {
    assert(file == D_0064EA20 && line == 0x5DE);
    ++assert_count;
}
static void RpSkyRenderStateSet(s32 key, s32 value) {
    static const int keys[] = {2,3,2,3};
    static const int values[] = {0x48,0x71801,0x44,0x717FB};
    assert(sky_count < 4 && key == keys[sky_count] && value == values[sky_count]);
    if (sky_count >= 2) assert(phase == 2 && submit_count == primitive_count);
    ++sky_count;
}
static s32 set_state(s32 key, void *value) {
    static const int keys[] = {20,6,8};
    assert(sky_count == 2 && state_count < 3);
    assert(key == keys[state_count]);
    assert((uintptr_t)value == (state_count == 2 ? 0u : 1u));
    ++state_count;
    return 1;
}
static void func_003764b0(u8 *base, s32 index, f32 time, u8 *output) {
    ShuffleVec3 value;
    assert(base == work && index == 1 && state_count == 3);
    assert(sample_count < 21 && submit_count == 0 && dimension_count == 0);
    if (sample_count == 0) equal_f(time, 0.0f);
    else equal_f(time, sampled_times[sample_count - 1] - input_length / 21.0f);
    sampled_times[sample_count] = time;
    value.x = 200.0f + time * 1.25f;
    value.y = 400.0f + time * 2.5f;
    value.z = 600.0f - time * 0.5f;
    memcpy(output, &value, sizeof(value));
    sampled[sample_count] = value;
    /* A callback may change the referenced RGB storage. Retail reloads it
       after sampling and stores that sample's color into both strips. */
    rgba[0] = sampled_rgb[sample_count][0] = (u8)(11 + sample_count * 3);
    rgba[1] = sampled_rgb[sample_count][1] = (u8)(239 - sample_count * 2);
    rgba[2] = sampled_rgb[sample_count][2] = (u8)(41 + sample_count * 5);
    rgba[3] = 37; /* Alpha was captured before the callbacks. */
    ++sample_count;
    phase = 1;
}
static f32 func_0036de70(u8 *card) {
    assert(card == work + 0xFB0 && sample_count == 21 && dimension_count == 0);
    ++dimension_count;
    return 60.0f;
}
static f32 func_0036deb0(u8 *card) {
    assert(card == work + 0xFB0 && dimension_count == 1);
    ++dimension_count;
    phase = 2;
    return 80.0f;
}
static void *func_00457120(void) {
    assert(mode_now == 2 && sample_count == 0 && camera_count == 0);
    ++camera_count;
    return &frame_holder;
}
static void *func_003e9700(s32 frame) {
    assert(frame == 0x1234 && camera_count == 1);
    ++camera_count;
    return NULL;
}

static void *func_00410420(struct RxObjSpace3DVertex *vertices, u32 count, BtlShuffleMatrix *m, u32 flags) {
    int side = submit_count / 2, strip = submit_count % 2, i;
    float taper = 1.0f;
    assert(phase == 2 && primitive_count == submit_count);
    assert(count == 42 && flags == 2 && side < (mode_now == 2 ? 2 : 4));
    assert(m->flags == 0x20003);
    equal_f(m->right.x, 1); equal_f(m->right.y, 0); equal_f(m->right.z, 0);
    equal_f(m->up.x, 0); equal_f(m->up.y, 1); equal_f(m->up.z, 0);
    equal_f(m->at.x, 0); equal_f(m->at.y, 0); equal_f(m->at.z, 1);
    equal_f(m->pos.x, 0); equal_f(m->pos.y, 0); equal_f(m->pos.z, 0);
    for (i = 0; i < 21; ++i) {
        int edge;
        for (edge = 0; edge < 2; ++edge) {
            TrailVertex *vertex = &vertices[i * 2 + edge];
            float ex = sampled[i].x, ey = sampled[i].y, ez = sampled[i].z;
            u8 alpha;
            if (mode_now == 0) {
                static const int fixed_axis[4] = {0,0,1,1};
                static const int fixed_sign[4] = {1,-1,1,-1};
                int outward = strip ? edge : edge - 1;
                float fixed = fixed_sign[side] * (fixed_axis[side] ? 40.0f : 30.0f);
                if (fixed_axis[side]) { ey += fixed; ex -= outward * 30.0f; }
                else { ex += fixed; ey += outward * 40.0f; }
                alpha = (u8)(((strip ^ edge) ? iGpffff8400 * input_opacity : input_opacity) * taper);
            } else {
                int xsign = (side & 1) ? -1 : 1;
                int ysign = (mode_now == 1 && (side & 2)) ? -1 : 1;
                float ox = mode_now == 2 ? iGpffff8218 * (xsign * 30.0f) : xsign * 30.0f;
                float oy = mode_now == 2 ? iGpffff8308 * 40.0f : ysign * 40.0f;
                int flare = strip ? -edge : 1 - edge;
                float magnitude = (mode_now == 2 ? iGpffff8408 : 3.0f) * taper;
                float dx = D_0060A0E0 * magnitude;
                float dy = D_0060A0E4 * magnitude;
                float dz = D_0060A0E8 * magnitude;
                if (flare > 0) { ex = dx + ex; ey = dy + ey; ez = dz + ez; }
                if (flare < 0) { ex -= dx; ey -= dy; ez -= dz; }
                ex += ox; ey += oy;
                alpha = (strip ^ edge) ? (u8)input_opacity : 0;
            }
            equal_f(vertex->objVertex.x, ex);
            equal_f(vertex->objVertex.y, ey);
            equal_f(vertex->objVertex.z, ez);
            assert(vertex->c.color.red == sampled_rgb[i][0]);
            assert(vertex->c.color.green == sampled_rgb[i][1]);
            assert(vertex->c.color.blue == sampled_rgb[i][2]);
            assert(vertex->c.color.alpha == alpha);
            ++tested_vertices;
        }
        taper += iGpffff8404;
    }
    ++submit_count;
    return vertices;
}
static s32 func_004106a0(s32 primitive) {
    assert(primitive == 4 && submit_count == primitive_count + 1);
    ++primitive_count;
    return 1;
}

static void run_case(int mode, int motion_state, float length, int alpha) {
    int state = motion_state, frame = 0x1234;
    memset(work, 0, 0x20000);
    memcpy(work + 0x1D6A0 + 0xE8 + 4, &state, 4);
    work[0x1D6A0 + 0xE8 + 0xD8] = 173;
    frame_holder.frame = frame;
    rgba[0] = 1; rgba[1] = 2; rgba[2] = 3; rgba[3] = alpha;
    input_opacity = (float)(u32)alpha * ((float)(u32)173 / 255.0f);
    input_length = length; mode_now = mode; state_now = motion_state;
    phase = (mode < 0 || mode >= 3) ? 2 : 0;
    sample_count = submit_count = primitive_count = sky_count = state_count = 0;
    assert_count = camera_count = dimension_count = 0;
    func_003768e0(work, 1, mode, rgba, length);
    assert(state_count == 3 && assert_count == (mode >= 3 ? 1 : 0));
    assert(sky_count == (motion_state == 6 ? 4 : 2));
    if (motion_state == 6 && mode >= 0 && mode < 3) {
        assert(sample_count == 21 && dimension_count == 2);
        assert(submit_count == (mode == 2 ? 4 : 8));
        assert(primitive_count == submit_count);
        assert(camera_count == (mode == 2 ? 2 : 0));
    } else {
        assert(sample_count == 0 && submit_count == 0 && primitive_count == 0);
    }
    ++cases;
}
int main(void) {
    int mode, a, l;
    const int alphas[] = {0,1,128,255};
    const float lengths[] = {0.0f,8.5f,21.0f,-42.0f};
    work = malloc(0x20000);
    assert(work != NULL);
    for (mode = 0; mode < 3; ++mode)
        for (a = 0; a < 4; ++a)
            for (l = 0; l < 4; ++l)
                run_case(mode, 6, lengths[l], alphas[a]);
    run_case(-1,6,21,255);
    run_case(3,6,21,255);
    for (mode = 0; mode < 3; ++mode) run_case(mode,5,21,255);
    printf("PASS: %d cases; %d rendered vertices; finite passes, sample/color reloads, alpha and state order\n", cases, tested_vertices);
    free(work);
    return 0;
}
'''
host_source = out / "host.c"
if vector_view:
    for index, name in enumerate(("D_0060A0E0", "D_0060A0E4", "D_0060A0E8")):
        footer = footer.replace(name, "expected_direction[" + str(index) + "]")
host_source.write_text(header + constant_defs + source + footer)
compiler = shutil.which("gcc")
assert compiler, "Host GCC is required for behavioral execution"
command = [compiler, "-std=c99", "-O2", "-Wno-unknown-pragmas", str(host_source), "-o", str(out / "behavior.exe"), "-lm"]
compiled = subprocess.run(command, text=True, capture_output=True, timeout=45)
(out / "compile.log").write_text(compiled.stdout + compiled.stderr)
assert compiled.returncode == 0, compiled.stdout + compiled.stderr
result = subprocess.run([str(out / "behavior.exe")], text=True, capture_output=True, timeout=15)
(out / "result.log").write_text(result.stdout + result.stderr)
print(result.stdout + result.stderr)
record = dict(candidate_sha256=hashlib.sha256(candidate.read_bytes()).hexdigest(),
              host_source_sha256=hashlib.sha256(host_source.read_bytes()).hexdigest(),
              returncode=result.returncode, constants=constants,
              compile_command=command, output=result.stdout + result.stderr)
(out / "receipt.json").write_text(json.dumps(record, indent=2) + "\n")
assert result.returncode == 0
