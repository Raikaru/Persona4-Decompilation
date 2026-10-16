#include "btl_action_internal.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "particle_spawn_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct EffRandState EffRandState;
extern s32 D_00713D58[];
extern s32 D_00713D5C[];
extern u8 D_00713E10[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void *memcpy(void *dst, const void *src, u32 size);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_0049Color;
extern Code1_0049Color iGpffffbb64;

static inline f32 code1_0049_mul(f32 left, f32 right) {
    return left * right;
}

/* Source unit: src/promoted/code1_0049.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0049.c; members 004916f0-004916f0 */

/* Sway emitter update, ported from the matched func_0048e2f0: the same
 * owner identity, loop constants, clear-loop and snapshot shapes. The scale
 * locals are declared in retail FPR order (variation, E8, E4, F4, D8). The
 * live-particle height is read from VF10 through $v0 (qmfc2/prot3w), and
 * the floor blend and downward speed use a named product operand. */
#pragma push
#pragma pop
/* Particle emitter update: spawn/respawn bookkeeping, then per-particle
 * motion with VU0 direction, sway and bounce.
 * Matching notes: the config/D_00922D70/prev quad copies go through $2
 * (user-approved, as in func_0048d8c0); swayBase is declared last and also
 * holds the accumulated spawn value earlier (`acc` in the m2c output), which
 * with opt_lifetimes on gives it a late web number so b210 spills it rather
 * than the asm `dot`, as retail does; the trail index `(node - base) >> 5` is
 * a named u32 multiplied by nmult; and `burst = 1` goes through a u8 local
 * (with opt_propagation off the only spelling that gives `daddiu`). The
 * pragmas are measured: opt_lifetimes off leaves 25 edits (dot is spilled),
 * opt_loop_invariants is what hoists the constant block retail loads before
 * the particle loop, and opt_propagation off keeps the u8 copy. */
#pragma push
#pragma pop
/* Swirl emitter update, ported from the d8c0/c4e0 particle family: three
 * stack vectors with retail's w=0 stores, the captured origin quad, loop
 * constants in hoist order, u8 preroll flag and snapshot pointer. The spawn
 * angle forms (g84 * a) * b as one named product before the half-weighted
 * remainder; the radius pairs are both formed before the first is stored. */
#pragma push
/* measured: func_004916f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_004916f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_004916F0
void func_004916f0(u8 *arg0)
{
    extern void func_004bceb0(void);
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern f32 fabsf(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
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
    f32 variation;
    f32 eDC;
    f32 eD8;
    f32 angle;
    f32 g84;
    f32 one;
    f32 half;
    f32 g80;
    f32 negone;
    f32 zero;
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
    eDC = *(f32 *)(config + 220);
    eD8 = *(f32 *)(config + 216);
    sp150[3] = 0.0f;
    sp130[3] = 0.0f;
    sp140[3] = 0.0f;
    {
        u_long128 *const capture = &quad120;
        *capture = *(u_long128 *)(config + 0);
    }
    effectVuLoad10((const EffectVuVector *)(config + 16));
    func_004bceb0();
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
    g84 = fGpffff8084;
    one = 1.0f;
    half = 0.5f;
    g80 = fGpffff8080;
    negone = -1.0f;
    zero = 0.0f;
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
    angle = *(f32 *)(config + 224);
    b = effMiscRandFloat(0);
    ftmp1 = g84 * angle;
    ftmp1 = ftmp1 * b;
    angle = ftmp1 + half * (g84 * (one - angle));
    c = sinf(angle);
    ftmp1 = *(f32 *)(config + 200) * c;
    ftmp2 = *(f32 *)(config + 204) * c;
    out[0] = ftmp1;
    out[1] = (ftmp2 - ftmp1) / (f32)limitB8;
    if ((*(u8 *)(config + 228) == 0) || ((idx & 1) != 0)) {
        variation = *(f32 *)(config + 212);
        b = effMiscRandFloat(0);
        out[2] = *(f32 *)(config + 208) * ((one - variation) + variation * b);
    } else {
        variation = *(f32 *)(config + 212);
        b = effMiscRandFloat(0);
        ftmp1 = (one - variation) + variation * b;
        out[2] = -*(f32 *)(config + 208) * ftmp1;
    }
    b = effMiscRandFloat(0);
    out[3] = g80 * b;
    c = cosf(angle);
    ftmp1 = *(f32 *)(config + 200) * c;
    ftmp2 = *(f32 *)(config + 204) * c;
    out[4] = ftmp1;
    out[5] = (ftmp2 - ftmp1) / (f32)limitB8;
    angle = out[0];
    sp150[0] = angle * cosf(out[3]);
    sp150[1] = out[4];
    sp150[2] = angle * sinf(out[3]);
    effectVuLoad10((const EffectVuVector *)sp150);
    if ((flags & 1) == 0) {
        spawnVuTransform10();
        effectVuLoad11((const EffectVuVector *)&quad120);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)nodes);
    angle = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[6] = (one - angle) + angle * b;
    if (mode9C != 2) {
        angle = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[8] = (one - angle) + angle * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[7] = g80 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[8] = out[8] * negone;
            }
        } else {
            out[7] = zero;
        }
    } else {
        out[7] = zero;
        out[8] = one;
    }
    *(s32 *)(nodes + 16) = 0;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        angle = (f32)(u32)tmp;
        out[4] = out[4] - half * (angle * (eDC * angle));
        variation = out[0] + out[1] * angle;
        out[0] = variation;
        sp150[0] = variation * cosf(out[3]);
        sp150[1] = out[4];
        sp150[2] = variation * sinf(out[3]);
        effectVuLoad10((const EffectVuVector *)sp150);
        if ((flags & 1) == 0) {
            spawnVuTransform10();
            effectVuLoad11((const EffectVuVector *)&quad120);
            spawnVuAdd10();
        }
        effectVuStore10((EffectVuVector *)nodes);
        *(s32 *)(nodes + 16) = (s32)angle;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[8];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[7];
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
    if ((*(u8 *)(config + 228) == 0) || ((idx & 1) != 0)) {
        angle = ftmp1 * (out[2] + half * (eD8 * ftmp1));
    } else {
        angle = ftmp1 * (out[2] - half * (eD8 * ftmp1));
    }
    angle = angle + out[3];
    out[4] = out[4] - eDC * ftmp1;
    out[0] = out[0] + out[1];
    out[4] = out[4] + out[5];
    variation = out[0];
    sp130[0] = variation * cosf(angle);
    sp130[1] = out[4];
    sp130[2] = variation * sinf(angle);
    effectVuLoad10((const EffectVuVector *)sp130);
    if ((flags & 1) == 0) {
        spawnVuTransform10();
        effectVuLoad11((const EffectVuVector *)&quad120);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)nodes);
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[8];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[7];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 9;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}

