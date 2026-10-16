#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
#include "particle_spawn_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

extern f32 fabsf(f32 value);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Source unit: src/promoted/code1_0048.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0048.c; members 0048c4e0-0048c4e0 */

extern f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
extern void func_0048b340(u8 *arg0, u8 *arg1);
/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-out; the current C callers discard it. The four hardware vf0 stores
 * produce (0,0,0,1), not a zero quadword. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation off keeps `alloc` live in $s1 across all three
   allocations instead of re-materialising the table address at the first use. */
/* measured: closes the propagation bracket; the file default is on. */
    /* measured: O1 probe for initial flag and aggregate register colours. */
    /* measured: closes O1 probe for initial flag and aggregate register colours. */
/* measured: opening optimization_level 1 for the parked 00486970 body. */
/* measured: closes optimization_level 1 for the parked 00486970 body. */
/* Measured with b210 -O2: keeping the trace/diagonal stages and the scaled
   root as distinct lifetimes reproduces the scalar calculation. Propagation
   and common-subexpression elimination otherwise merge the identity
   constants and discard the root copy before register coalescing. */
#pragma push
#pragma pop
/* measured: opt_propagation off tested for target subtraction scheduling. */
/* measured: restore opt_propagation after func_0048aff0. */
#pragma push
/* measured: split the two counter webs, but preserve the native-asm cursor. */
#pragma pop
/* Measured: these scoped settings preserve the recovered wave update
 * evaluation order and the complete retail 2652-byte executable body. */
#pragma push
#pragma pop
/* Motion emitter: ordinary C emission, random and integration calculations;
 * VU instructions preserve the full hardware vector operations. The aligned
 * XYZ scale's complete object representation is described at its declaration.
 * Proof: docs/probe_archive/Motion_scale_0048c4e0_20261005/README.md.
 * Measured scopes preserve scalar operand lifetimes across RNG calls. */
// FUN_0048C4E0
#pragma push
/* measured: func_0048c4e0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: func_0048c4e0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void func_0048c4e0(u8 *arg0)
{
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    EffectVuVector vec130;
    /* LQC2 reads the complete representation of this aligned XYZ vector.
     * The fourth word is the struct's unspecified tail padding, not a float
     * member. Preserve the hardware load and all four VU result lanes. */
    typedef struct MotionScale3 {
        f32 lane[3];
    } __attribute__((aligned(16))) MotionScale3;
    typedef char MotionScale3Size[(sizeof(MotionScale3) == 16) ? 1 : -1];
    MotionScale3 vec120;
    u_long128 b220buf;
    u32 count;
    u32 flags;
    u8 *nodes;
    f32 *out;
    u8 *config;
    u8 *const parent = arg0;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 e4val;
    f32 e0val;
    f32 half;
    f32 two;
    f32 one;
    f32 zero;
    f32 g80;
    f32 negone;
    s32 v15;
    s32 v14;
    u8 initialPreroll;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    u32 particleIndex;
    f32 speedVariation;
    f32 spreadVariation;
    f32 sizeVariation;
    f32 angleVariation;
    f32 b;

    count = *(u32 *)(parent + 4);
    flags = *(u32 *)(parent + 12);
    nodes = *(u8 **)(parent + 24);
    out = *(f32 **)(parent + 28);
    config = *(u8 **)(parent + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    e4val = *(f32 *)(config + 220);
    e0val = *(f32 *)(config + 216);
    vec130.lane[3] = 0.0f;
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        initialPreroll = 1;
        v14 = initialPreroll;
        if (!(*(f32 *)(config + 40) <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)*(u32 *)(parent + 4);
            v15 = (s32)(ftmp2 * prerollScale);
        } else {
            v15 = *(s32 *)(parent + 4);
        }
        goto post_init;
    } else {
        v14 = 0;
        if (!(*(f32 *)(config + 40) <= 0.0f)) {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * ftmp1;
        } else {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp1;
        }
        ftmp1 = *(f32 *)(parent + 20);
        ftmp1 = fabsf(ftmp1);
        v15 = (s32)ftmp1;
        *(f32 *)(parent + 20) = *(f32 *)(parent + 20) - (f32)v15;
        goto post_init;
    }
post_init:
    idx = 0;
    half = 0.5f;
    two = 2.0f;
    one = 1.0f;
    zero = 0.0f;
    g80 = fGpffff8080;
    negone = -1.0f;
    goto main_check;
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 != 0) {
        tmp = -2;
    } else {
        tmp = -1;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(*(u8 **)(parent + 32) + 192);
    c4 = *(s32 *)(*(u8 **)(parent + 32) + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        particleIndex = ((u32)nodes - (u32)*(u8 **)(parent + 24)) >> 5;
        clear = *(u8 **)(parent + 24) + ((*(u32 *)(parent + 4) + particleIndex * (u32)nmult) << 5);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    vec130.lane[0] = (effMiscRandFloat(0) - half) * two;
    vec130.lane[1] = (effMiscRandFloat(0) - half) * two;
    vec130.lane[2] = (effMiscRandFloat(0) - half) * two;
    effectVuLoad10(&vec130);
    spawnVuNormalize10();
    effectVuStore10(&vec130);
    out[0] = vec130.lane[0];
    out[1] = vec130.lane[1];
    out[2] = vec130.lane[2];
    speedVariation = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    out[3] = fabsf(*(f32 *)(config + 208) * ((one - speedVariation) + speedVariation * b));
    spreadVariation = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    vec120.lane[0] = *(f32 *)(config + 200) * ((one - spreadVariation) + spreadVariation * b);
    vec120.lane[1] = vec120.lane[0];
    vec120.lane[2] = vec120.lane[0];
    effectVuLoad10(&vec130);
    if (*(f32 *)(config + 208) < zero) {
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10", "memory");
    }
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)"
            : : "r"(&vec120), "m"(*(const u8 (*)[sizeof(vec120)])&vec120)
            : "$vf11");
        spawnVuMultiply10();
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)"
            : : "r"(&vec120), "m"(*(const u8 (*)[sizeof(vec120)])&vec120)
            : "$vf11");
        spawnVuMultiply10();
        effectVuLoad11((const EffectVuVector *)config);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)nodes);
    sizeVariation = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[4] = (one - sizeVariation) + sizeVariation * b;
    if (mode9C != 2) {
        angleVariation = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[6] = (one - angleVariation) + angleVariation * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[5] = g80 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[6] = out[6] * negone;
            }
        } else {
            out[5] = zero;
        }
    } else {
        out[5] = zero;
        out[6] = one;
    }
    *(s32 *)(nodes + 16) = 0;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    if (v14 != 0) {
        f32 prerollElapsed;
        f32 prerollDistance;
        f32 travelled;
        f32 accelerationDistance;
        f32 accelerationSquaredDistance;
        f32 gravityDistance;
        f32 gravitySquaredDistance;
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        prerollElapsed = (f32)(u32)tmp;
        effectVuLoad11((const EffectVuVector *)nodes);
        travelled = out[3] * prerollElapsed;
        accelerationDistance = e0val * prerollElapsed;
        accelerationSquaredDistance = prerollElapsed * accelerationDistance;
        prerollDistance = travelled + half * accelerationSquaredDistance;
        if (prerollDistance < zero) {
            prerollDistance = zero;
        }
        vec130.lane[0] = prerollDistance * out[0];
        vec130.lane[1] = prerollDistance * out[1];
        vec130.lane[2] = prerollDistance * out[2];
        gravityDistance = e4val * prerollElapsed;
        gravitySquaredDistance = prerollElapsed * gravityDistance;
        vec130.lane[1] = vec130.lane[1] - half * gravitySquaredDistance;
        effectVuLoad10(&vec130);
        spawnVuAdd10();
        effectVuStore10((EffectVuVector *)nodes);
        *(s32 *)(nodes + 16) = (s32)prerollElapsed;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[4];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[5];
    if (v14 != 0) {
        nmult = *(s32 *)(*(u8 **)(parent + 32) + 192) * *(s32 *)(*(u8 **)(parent + 32) + 196);
        if (nmult != 0) {
            particleIndex = ((u32)nodes - (u32)*(u8 **)(parent + 24)) >> 5;
            clear = *(u8 **)(parent + 24) + ((*(u32 *)(parent + 4) + particleIndex * (u32)nmult) << 5);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    {
    f32 liveDistance;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    effectVuLoad11((const EffectVuVector *)nodes);
    liveDistance = out[3] + e0val * (f32)node10;
    if (liveDistance < zero) {
        liveDistance = zero;
    }
    vec130.lane[0] = liveDistance * out[0];
    vec130.lane[1] = liveDistance * out[1];
    vec130.lane[2] = liveDistance * out[2];
    vec130.lane[1] = vec130.lane[1] - e4val * (f32)node10;
    effectVuLoad10(&vec130);
    spawnVuAdd10();
    effectVuStore10((EffectVuVector *)nodes);
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[4];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[5];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
    }
next_iter2:
next_iter:
    idx += 1;
    out += 7;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}

