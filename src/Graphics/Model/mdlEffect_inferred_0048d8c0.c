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
extern void func_00485630(u8 *arg0);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0048.c; members 0048d8c0-0048d8c0 */

extern f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
extern void func_0048b340(u8 *arg0, u8 *arg1);
extern void func_0048c4e0(u8 *arg0);
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
#pragma pop
/* Taken from the matched sibling func_0048c4e0: the loop constants are
 * locals assigned after the preroll in retail's hoist order (one, orbit,
 * zero, half, two, tilt, angle, -1) and declared in its FPR order. `c`
 * carries the first, fifth and sixth scale (retail $f30) and `a` the second
 * and third ($f31). The 0x140 vector exists only for its retail w=0 store.
 * The config[0] snapshot at 0x0048D96C is an lq/sq that names $2, as in
 * func_00485630; the $2 def also frees $v0 for retail's saved20/mode9C
 * spill stores. */
#pragma push
/* measured: func_0048d8c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_0048d8c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0048D8C0
void func_0048d8c0(u8 *arg0)
{
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern void effMiscRotateXVU(f32 arg0);
    extern void effMiscRotateYVU(f32 arg0);
    extern void effMiscCombineRotationVU(void);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff8094;
    f32 sp150[4] __attribute__((aligned(16)));
    f32 sp140[4] __attribute__((aligned(16)));
    f32 sp130[4] __attribute__((aligned(16)));
    u_long128 quad120;
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
    f32 one;
    f32 orbitScale;
    f32 zero;
    f32 half;
    f32 two;
    f32 tiltScale;
    f32 angleScale;
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
    f32 a;
    f32 b;
    f32 c;
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
    e4val = *(f32 *)(config + 228);
    e0val = *(f32 *)(config + 224);
    sp150[3] = 0.0f;
    sp130[3] = 0.0f;
    sp140[3] = 0.0f;
    {
        u_long128 *const capture = &quad120;
        /* lint: allow H009 -- retail copies this quad through $2 at 0x0048D96C, freeing $v0 for the spill stores (user-approved 2026-10-09) */
        __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(capture), "r"(config) : "$2", "memory");
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
    orbitScale = fGpffff8094;
    zero = 0.0f;
    half = 0.5f;
    two = 2.0f;
    tiltScale = fGpffff8084;
    angleScale = fGpffff8080;
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
    c = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    c = *(f32 *)(config + 200) * ((one - c) + c * b);
    a = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    ftmp1 = *(f32 *)(config + 208) * ((one - a) + a * b);
    out[5] = c;
    out[6] = (ftmp1 - c) / (f32)limitB8;
    a = *(f32 *)(config + 220);
    b = effMiscRandFloat(0);
    out[7] = *(f32 *)(config + 216) * ((one - a) + a * b);
    b = effMiscRandFloat(0);
    out[8] = orbitScale * b;
    out[9] = zero;
    b = effMiscRandFloat(0);
    out[3] = tiltScale * (two * (b - half));
    b = effMiscRandFloat(0);
    out[4] = tiltScale * (two * (b - half));
    effMiscRotateXVU(out[3]);
    effMiscRotateYVU(out[4]);
    effMiscCombineRotationVU();
    sp150[0] = c * cosf(out[8]);
    sp150[1] = zero;
    sp150[2] = c * sinf(out[8]);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp150), "m"(*(u_long128 *)sp150) : "$vf10", "memory");
    __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
    if ((flags & 1) == 0) {
        out[0] = ((f32 *)&quad120)[0];
        out[1] = ((f32 *)&quad120)[1];
        out[2] = ((f32 *)&quad120)[2];
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&quad120), "m"(quad120) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    c = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[10] = (one - c) + c * b;
    if (mode9C != 2) {
        c = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[12] = (one - c) + c * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[11] = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[12] = out[12] * negone;
            }
        } else {
            out[11] = zero;
        }
    } else {
        out[11] = zero;
        out[12] = one;
    }
    *(s32 *)(nodes + 16) = 0;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        ftmp1 = (f32)(u32)tmp;
        out[9] = out[9] - half * (ftmp1 * (e4val * ftmp1));
        c = out[5] + out[6] * ftmp1;
        out[5] = c;
        sp150[0] = c * cosf(out[8]);
        sp150[1] = zero;
        sp150[2] = c * sinf(out[8]);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp150), "m"(*(u_long128 *)sp150) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        if ((flags & 1) == 0) {
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf10", "$vf11", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&quad120), "m"(quad120) : "$vf10", "memory");
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
        *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[9];
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[10];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[12];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[11];
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
    ftmp2 = ftmp1 * (out[7] + half * (e0val * ftmp1));
    ftmp2 = ftmp2 + out[8];
    out[9] = out[9] - e4val * ftmp1;
    out[5] = out[5] + out[6];
    effMiscRotateXVU(out[3]);
    effMiscRotateYVU(out[4]);
    effMiscCombineRotationVU();
    c = out[5];
    sp150[0] = c * cosf(ftmp2);
    sp150[1] = zero;
    sp150[2] = c * sinf(ftmp2);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp150), "m"(*(u_long128 *)sp150) : "$vf10", "memory");
    __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)sp130) : "r"(sp130) : "$vf10", "memory");
    if ((flags & 1) == 0) {
        sp130[0] = sp130[0] + out[0];
        sp130[1] = sp130[1] + out[1];
        sp130[2] = sp130[2] + out[2];
    }
    *(f32 *)(nodes + 0) = sp130[0];
    *(f32 *)(nodes + 4) = sp130[1] + out[9];
    *(f32 *)(nodes + 8) = sp130[2];
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[10];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[12];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[11];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 13;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}

