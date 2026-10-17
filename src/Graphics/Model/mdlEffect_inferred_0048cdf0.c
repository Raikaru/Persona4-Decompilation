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
extern void effMiscBuildRotationVU(void);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 0048cdf0-0048cdf0 */

extern f32 mdlEffectSampleScalarKeys(u8 *arg0, s32 arg1, s32 arg2);
extern void mdlEffectSampleKeyState(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
extern void func_0048b340(u8 *arg0, u8 *arg1);
extern void func_0048d8c0(u8 *arg0);
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
#pragma push
#pragma pop
/* Ported from the matched sibling func_0048d8c0: function-scope u8
 * initialPreroll, `!(x <= 0)` first rand-scale arms, shift-based particle
 * index, `mode9C != 2` first, snapshot pointer, stack vectors declared from
 * the highest frame slot down, and the config quads copied through $2.
 * The loop constants are assigned after the preroll in retail's hoist order.
 * b210 colours the saved FPRs from the highest-numbered local down, each
 * taking the lowest free register, and numbers locals by declaration: so
 * `a` (retail $f28) is declared first, then eF0val, eECval, `c` ($f25,
 * which also carries the v14 sample and the else-branch angle), and the
 * constants one..half ($f24-$f20). */
#pragma push
/* measured: func_0048cdf0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_0048cdf0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0048CDF0
void func_0048cdf0(u8 *arg0)
{
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern void mdlEffectSampleKeyState(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    f32 tmp170[4] __attribute__((aligned(16)));
    f32 tmp160[4] __attribute__((aligned(16)));
    f32 tmp150[4] __attribute__((aligned(16)));
    u_long128 cfg10;
    f32 tmp130[4] __attribute__((aligned(16)));
    u_long128 cfg0;
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
    f32 a;
    f32 eF0val;
    f32 eECval;
    f32 c;
    f32 one;
    f32 angleScale;
    f32 zero;
    f32 negone;
    f32 half;
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
    eF0val = *(f32 *)(config + 240);
    eECval = *(f32 *)(config + 236);
    tmp170[3] = 0.0f;
    tmp130[3] = 0.0f;
    tmp160[3] = 0.0f;
    {
        u_long128 *capture;

        capture = &cfg0;
        /* lint: allow H009 -- retail copies this quad through $2 at 0x0048CE94; b210 keeps $v0 live (user-approved 2026-10-09) */
        __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(capture), "r"(config) : "$2", "memory");
        capture = &cfg10;
        /* lint: allow H009 -- retail copies this quad through $2 at 0x0048CEA0; b210 keeps $v0 live (user-approved 2026-10-09) */
        __asm__ volatile("lq $2, 16(%1)\n\tsq $2, 0(%0)" : : "r"(capture), "r"(config) : "$2", "memory");
    }
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
            f32 scale = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * scale;
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
    one = 1.0f;
    angleScale = fGpffff8080;
    zero = 0.0f;
    negone = -1.0f;
    half = 0.5f;
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
    c = *(f32 *)(config + 208);
    b = effMiscRandFloat(0);
    c = *(f32 *)(config + 204) * ((one - c) + c * b);
    a = *(f32 *)(config + 216);
    b = effMiscRandFloat(0);
    ftmp1 = *(f32 *)(config + 212) * ((one - a) + a * b);
    out[8] = c;
    out[9] = (ftmp1 - c) / (f32)limitB8;
    b = effMiscRandFloat(0);
    out[10] = angleScale * b;
    a = *(f32 *)(config + 224);
    b = effMiscRandFloat(0);
    out[11] = *(f32 *)(config + 220) * ((one - a) + a * b);
    a = *(f32 *)(config + 232);
    b = effMiscRandFloat(0);
    out[12] = *(f32 *)(config + 228) * ((one - a) + a * b);
    tmp170[0] = cosf(out[10]);
    tmp170[1] = zero;
    tmp170[2] = sinf(out[10]);
    b = effMiscRandFloat(0);
    out[7] = *(f32 *)(config + 200) * b;
    tmp160[0] = c;
    tmp160[1] = c;
    tmp160[2] = c;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp160), "m"(*(u_long128 *)tmp160) : "$vf11", "memory");
    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile(
        "lw $2, 28(%0) \n"
        "nop \n"
        "qmtc2.ni $2, $vf2 \n"
        "vaddx.y $vf10, $vf0, $vf2x \n"
        : : "r"(out) : "$2", "$vf2", "$vf10", "memory");
    if ((flags & 1) == 0) {
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp130) : "r"(tmp130) : "$vf10", "memory");
        out[0] = ((f32 *)&cfg0)[0];
        out[1] = ((f32 *)&cfg0)[1];
        out[2] = ((f32 *)&cfg0)[2];
        out[3] = ((f32 *)&cfg10)[0];
        out[4] = ((f32 *)&cfg10)[1];
        out[5] = ((f32 *)&cfg10)[2];
        out[6] = ((f32 *)&cfg10)[3];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&cfg10), "m"(cfg10) : "$vf10", "memory");
        effMiscBuildRotationVU();
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&cfg0), "m"(cfg0) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    c = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[13] = (one - c) + c * b;
    if (mode9C != 2) {
        c = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[15] = (one - c) + c * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[14] = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[15] = out[15] * negone;
            }
        } else {
            out[14] = zero;
        }
    } else {
        out[14] = zero;
        out[15] = one;
    }
    *(s32 *)(nodes + 16) = 0;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        c = (f32)(u32)tmp;
        out[7] = out[7] + out[12] * c;
        out[7] = out[7] - half * (c * (eF0val * c));
        out[8] = out[8] + out[9] * c;
        tmp130[0] = out[8] * cosf(out[10]);
        tmp130[1] = out[7];
        tmp130[2] = out[8] * sinf(out[10]);
        if ((flags & 1) == 0) {
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&cfg10), "m"(cfg10) : "$vf10", "memory");
            effMiscBuildRotationVU();
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&cfg0), "m"(cfg0) : "$vf11", "memory");
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        } else {
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
        *(s32 *)(nodes + 16) = (s32)c;
    }
    mdlEffectSampleKeyState(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[13];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[15];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[14];
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
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    ftmp1 = (f32)node10;
    c = ftmp1 * (out[11] + half * (eECval * ftmp1));
    c = c + out[10];
    out[7] = out[7] + out[12];
    out[7] = out[7] - eF0val * ftmp1;
    out[8] = out[8] + out[9];
    tmp130[0] = out[8] * cosf(c);
    tmp130[1] = out[7];
    tmp130[2] = out[8] * sinf(c);
    if ((flags & 1) == 0) {
        tmp150[0] = out[3];
        tmp150[1] = out[4];
        tmp150[2] = out[5];
        tmp150[3] = out[6];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp150), "m"(*(u_long128 *)tmp150) : "$vf10", "memory");
        effMiscBuildRotationVU();
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp130) : "r"(tmp130) : "$vf10", "memory");
        tmp130[0] = tmp130[0] + out[0];
        tmp130[1] = tmp130[1] + out[1];
        tmp130[2] = tmp130[2] + out[2];
    }
    *(f32 *)(nodes + 0) = tmp130[0];
    *(f32 *)(nodes + 4) = tmp130[1];
    *(f32 *)(nodes + 8) = tmp130[2];
    mdlEffectSampleKeyState(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[13];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[15];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[14];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 16;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}

