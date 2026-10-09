#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "particle_spawn_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern void (*D_00713E70[])(u8 *object);
extern void (*D_00713E78[])(u8 *object);
extern void (*D_00713E7C[])(u8 *object);
extern void (*D_00713E80[])(u8 *object);
extern void (*D_00713F18[])(void *state);
extern void (*D_00713F10[])(u8 *object);
extern void (*D_00713F1C[])(u8 *object);
extern void (*D_00713F20[])(u8 *object);
extern void (*D_00713D54[])(u8 *emitter, f32 scale);
typedef struct EffRandState EffRandState;
extern u32 effMiscRand(EffRandState *state);
extern s32 D_00713D58[];
extern s32 D_00713D5C[];
extern u8 D_00713E10[];
extern void func_0044ea90(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void func_0046d730(const void *file, s32 line);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_0049Color;
extern Code1_0049Color iGpffffbb64;

extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0049_mul(f32 left, f32 right) {
    return left * right;
}

extern void func_004841c0(void *arg0);
extern void func_0048a1f0(u8 *arg0);

extern void func_00484280(u8 *object, s32 resource);



// FUN_00490360
void func_00490360(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00490360_check;
loop_00490360_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00490360_check:
    if (var_7 < 3U) {
        goto loop_00490360_body;
    }
}
/* Sway emitter update, ported from the matched func_0048e2f0: the same
 * owner identity, loop constants, clear-loop and snapshot shapes. The scale
 * locals are declared in retail FPR order (variation, E8, E4, F4, D8). The
 * live-particle height is read from VF10 through $v0 (qmfc2/prot3w), and
 * the floor blend and downward speed use a named product operand. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
// FUN_004903C0
void func_004903c0(u8 *arg0)
{
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern void func_004bceb0(void);
    extern f32 effMiscRandFloat(s32 arg0);
    extern s32 effMiscRand(s32 arg0);
    extern f32 fabsf(f32 arg0);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    EffectVuVector vec120;
    typedef struct SwayScale3 {
        f32 lane[3];
    } __attribute__((aligned(16))) SwayScale3;
    SwayScale3 vec110;
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
    f32 eE8;
    f32 eE4;
    f32 eF4;
    f32 eD8;
    f32 one;
    f32 half;
    f32 two;
    f32 zero;
    f32 g80;
    f32 negone;
    s32 v15;
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
    eE8 = *(f32 *)(config + 232);
    eF4 = *(f32 *)(config + 244);
    eE4 = *(f32 *)(config + 228);
    eD8 = *(f32 *)(config + 216);
    vec120.lane[3] = 0.0f;
    effectVuLoad10((const EffectVuVector *)(config + 16));
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        if (!(*(f32 *)(config + 40) <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)*(u32 *)(parent + 4);
            v15 = (s32)(ftmp2 * prerollScale);
        } else {
            v15 = *(s32 *)(parent + 4);
        }
        goto post_init;
    } else {
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
    one = 1.0f;
    half = 0.5f;
    two = 2.0f;
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
    variation = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    variation = *(f32 *)(config + 208) * ((one - variation) + variation * b);
    vec120.lane[0] = variation * ((effMiscRandFloat(0) - half) * two);
    vec120.lane[1] = -(one - variation);
    vec120.lane[2] = variation * ((effMiscRandFloat(0) - half) * two);
    effectVuLoad10(&vec120);
    spawnVuNormalize10();
    if ((flags & 1) == 0) {
        spawnVuTransform10();
    }
    effectVuStore10(&vec120);
    out[0] = vec120.lane[0];
    out[1] = vec120.lane[1];
    out[2] = vec120.lane[2];
    variation = *(f32 *)(config + 224);
    b = effMiscRandFloat(0);
    out[3] = fabsf(*(f32 *)(config + 220) * ((one - variation) + variation * b));
    variation = *(f32 *)(config + 240);
    b = effMiscRandFloat(0);
    ftmp1 = (one - variation) + variation * b;
    out[4] = -*(f32 *)(config + 236) * ftmp1;
    variation = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    vec110.lane[0] = *(f32 *)(config + 200) * ((one - variation) + variation * b);
    vec110.lane[1] = vec110.lane[0];
    vec110.lane[2] = vec110.lane[0];
    effectVuLoad10(&vec120);
    if (*(f32 *)(config + 220) < zero) {
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10", "memory");
    }
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&vec110), "m"(*(const u8 (*)[sizeof(vec110)])&vec110) : "$vf11");
        spawnVuMultiply10();
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&vec110), "m"(*(const u8 (*)[sizeof(vec110)])&vec110) : "$vf11");
        spawnVuMultiply10();
        effectVuLoad11((const EffectVuVector *)config);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)nodes);
    variation = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[5] = (one - variation) + variation * b;
    if (mode9C != 2) {
        variation = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[7] = (one - variation) + variation * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[6] = g80 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[7] = out[7] * negone;
            }
        } else {
            out[6] = zero;
        }
    } else {
        out[6] = zero;
        out[7] = one;
    }
    *(s32 *)(nodes + 16) = 0;
    func_0048b220(nodes, config, 0, (u_long128 *)nodes);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[5];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[7];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[6];
    v15 -= 1;
    goto next_iter;
else_branch:
    {
    f32 liveDistance;
    f32 height;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    effectVuLoad11((const EffectVuVector *)nodes);
    liveDistance = out[3] + eE4 * (f32)node10;
    if (liveDistance < zero) {
        liveDistance = zero;
    }
    out[1] = out[1] - eE8;
    vec120.lane[0] = liveDistance * out[0];
    vec120.lane[1] = out[1];
    vec120.lane[2] = liveDistance * out[2];
    effectVuLoad10(&vec120);
    spawnVuAdd10();
    effectVuStore10((EffectVuVector *)nodes);
    {
        __asm__ volatile(
            "qmfc2.ni $2, $vf10\n"
            "prot3w $2, $2\n"
            "mtc1 $2, %0\n"
            "nop\n"
            : "=f"(height) : : "$2");
    }
    if (height < eD8) {
        out[4] = out[4] * eF4;
        out[1] = out[1] * out[4];
        ftmp1 = out[4];
        *(f32 *)(nodes + 4) = eD8 + ftmp1 * (*(f32 *)(nodes + 4) - eD8);
    }
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[5];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[7];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[6];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
    }
next_iter:
    idx += 1;
    out += 8;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#pragma pop
// FUN_00490BB0
void func_00490bb0(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00490bb0_check;
loop_00490bb0_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00490bb0_check:
    if (var_7 < 3U) {
        goto loop_00490bb0_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
    *(f32 *)(temp_6 + 0xE8) = *(f32 *)(temp_5 + 0xE8) * fparg0;
}
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
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_propagation off
// FUN_00490C40
void func_00490c40(u8 *arg0)
{
    extern f32 effMiscRandFloat(s32 arg0);
    extern u32 effMiscRand(s32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern void memcpy(void *dst, void *src, u32 size);
    extern f32 fabsf(f32 x);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8088;
    extern f32 fGpffff808c;
    extern u_long128 D_00922D70;
    EffectVuVector dir;
    u_long128 prev;
    u_long128 origin;
    EffectVuVector bounce;
    u32 count;
    u32 flags;
    u8 *node;
    u8 *extra;
    u8 *config;
    u8 *self;
    s32 limit;
    s32 respawn;
    f32 dist;
    u8 mode;
    f32 half;
    s32 spawn;
    s64 burst;
    u32 i;
    s32 state;
    s32 divD8;
    f32 two;
    f32 one;
    f32 zero;
    f32 speed;
    f32 spin;
    f32 negone;
    f32 swayRange;
    f32 growth;
    f32 t;
    f32 travel;
    f32 swayBase;
    f32 reach;

    self = arg0;
    count = *(u32 *)(self + 4);
    flags = *(u32 *)(self + 0xC);
    node = *(u8 **)(self + 0x18);
    extra = *(u8 **)(self + 0x1C);
    config = *(u8 **)(self + 0x20);
    if (*(s32 *)(config + 0xB8) == 0) {
        return;
    }
    if ((flags & 1) == 0) {
        u_long128 *dst = &origin;

        /* lint: allow H009 -- retail copies this quad through $2 at 0x00490CDC; b210 keeps $v0 live (user-approved 2026-10-09) */
        __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(dst), "r"(config) : "$2", "memory");
    } else {
        u_long128 *dst = &origin;

        /* lint: allow H009 -- retail copies this quad through $2 at 0x00490CF8; b210 keeps $v0 live (user-approved 2026-10-09) */
        __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(dst), "r"(&D_00922D70) : "$2", "memory");
    }
    limit = *(s32 *)(config + 0xB8);
    respawn = *(s32 *)(config + 0x20);
    divD8 = *(s32 *)(config + 0xD8);
    mode = *(u8 *)(config + 0x9C);
    growth = *(f32 *)(config + 0xE4);
    dir.lane[3] = 0.0f;
    if (respawn != 0 && !(*(s32 *)(self + 0x10) < respawn)) {
        burst = 0;
        spawn = 0;
    } else if (*(s32 *)(self + 0x10) == 0 && *(u8 *)(config + 0xBD) != 0) {
        {
            u8 on;

            on = 1;
            burst = on;
        }
        if (!(*(f32 *)(config + 0x28) <= 0.0f)) {
            spawn = (s32)((f32)*(u32 *)(self + 4) * ((fGpffff807c - *(f32 *)(config + 0x28)) * effMiscRandFloat(0)));
        } else {
            spawn = *(u32 *)(self + 4);
        }
    } else {

        burst = 0;
        if (!(*(f32 *)(config + 0x28) <= 0.0f)) {
            f32 scale = (fGpffff807c - *(f32 *)(config + 0x28)) * effMiscRandFloat(0);

            *(f32 *)(self + 0x14) = *(f32 *)(self + 0x14) + (f32)*(u32 *)(config + 0x24) * scale;
        } else {
            *(f32 *)(self + 0x14) = *(f32 *)(self + 0x14) + (f32)*(u32 *)(config + 0x24);
        }
        swayBase = *(f32 *)(self + 0x14);
        spawn = (s32)fabsf(swayBase);
        *(f32 *)(self + 0x14) = swayBase - (f32)spawn;
    }
    i = 0;
    half = 0.5f;
    two = 2.0f;
    one = 1.0f;
    zero = 0.0f;
    spin = fGpffff8080;
    negone = -1.0f;
    swayRange = fGpffff8088;
    swayBase = fGpffff808c;
    for (; i < count; i++, extra += 0x24, node += 0x20) {
        if (!(*(s32 *)(node + 0x10) < limit)) {
            u8 *cfg;
            s32 nmult;

            *(s32 *)(node + 0x10) = respawn != 0 ? -2 : -1;
            cfg = *(u8 **)(self + 0x20);
            nmult = *(s32 *)(cfg + 0xC0) * *(s32 *)(cfg + 0xC4);
            if (nmult != 0) {
                u32 index = (u32)(node - *(u8 **)(self + 0x18)) >> 5;
                u8 *trail = *(u8 **)(self + 0x18) + ((*(u32 *)(self + 4) + index * nmult) << 5);
                s32 k;

                for (k = 0; k < nmult; trail += 0x20, k++) {
                    *(s32 *)(trail + 0x10) = -1;
                }
            }
        }
        state = *(s32 *)(node + 0x10);
        if (state == -2) {
            continue;
        }
        if (state == -1) {
            if (spawn == 0) {
                continue;
            }
            dir.lane[0] = two * (effMiscRandFloat(0) - half);
            dir.lane[1] = two * (effMiscRandFloat(0) - half);
            dir.lane[2] = two * (effMiscRandFloat(0) - half);
            effectVuLoad10(&dir);
            __asm__ volatile(
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
            effectVuStore10(&dir);
            *(f32 *)(extra + 0x0) = dir.lane[0];
            *(f32 *)(extra + 0x4) = dir.lane[1];
            *(f32 *)(extra + 0x8) = dir.lane[2];
            t = *(f32 *)(config + 0xE0);
            *(f32 *)(extra + 0x14) = fabsf(*(f32 *)(config + 0xDC) * ((one - t) + t * effMiscRandFloat(0)));
            t = *(f32 *)(config + 0xCC);
            speed = *(f32 *)(config + 0xC8) * ((one - t) + t * effMiscRandFloat(0));
            t = *(f32 *)(config + 0xD4);
            t = *(f32 *)(config + 0xD0) * ((one - t) + t * effMiscRandFloat(0));
            *(f32 *)(extra + 0xC) = speed;
            *(f32 *)(extra + 0x10) = (t - speed) / (f32)divD8;
            if (burst != 0) {
                f32 step;

                *(s32 *)(node + 0x10) = effMiscRand(0) % (u32)limit;
                *(f32 *)(extra + 0xC) = *(f32 *)(extra + 0xC) + *(f32 *)(extra + 0x10) * (f32)*(s32 *)(node + 0x10);
                step = *(f32 *)(extra + 0x10);
                if ((!(step <= zero) && !(*(f32 *)(extra + 0xC) <= t)) ||
                    ((step < zero) && (*(f32 *)(extra + 0xC) < t))) {
                    *(f32 *)(extra + 0xC) = t;
                }
                speed = *(f32 *)(extra + 0xC);
            } else {
                *(s32 *)(node + 0x10) = 0;
            }
            dir.lane[0] = two * (effMiscRandFloat(0) - half);
            dir.lane[1] = two * (effMiscRandFloat(0) - half);
            dir.lane[2] = two * (effMiscRandFloat(0) - half);
            effectVuLoad10(&dir);
            __asm__ volatile(
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
            effectVuScale10(speed);
            if ((flags & 1) == 0) {
                effectVuLoad11((EffectVuVector *)&origin);
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            }
            effectVuStore10((EffectVuVector *)node);
            t = *(f32 *)(config + 0x6C);
            *(f32 *)(extra + 0x18) = (one - t) + t * effMiscRandFloat(0);
            state = mode;
            if (state != 2) {
                t = *(f32 *)(config + 0x98);
                *(f32 *)(extra + 0x20) = (one - t) + t * effMiscRandFloat(0);
                if (state == 1) {
                    *(f32 *)(extra + 0x1C) = spin * effMiscRandFloat(0);
                    if ((effMiscRand(0) & 1) != 0) {
                        *(f32 *)(extra + 0x20) = *(f32 *)(extra + 0x20) * negone;
                    }
                } else {
                    *(f32 *)(extra + 0x1C) = zero;
                }
            } else {
                *(f32 *)(extra + 0x1C) = zero;
                *(f32 *)(extra + 0x20) = one;
            }
            func_0048b220(node, config, *(s32 *)(node + 0x10), (u_long128 *)node);
            *(f32 *)(node + 0x18) = *(f32 *)(node + 0x18) * *(f32 *)(extra + 0x18);
            *(f32 *)(node + 0x1C) = *(f32 *)(node + 0x1C) * *(f32 *)(extra + 0x20);
            *(f32 *)(node + 0x1C) = *(f32 *)(node + 0x1C) + *(f32 *)(extra + 0x1C);
            if (burst != 0) {
                u8 *cfg = *(u8 **)(self + 0x20);
                s32 nmult = *(s32 *)(cfg + 0xC0) * *(s32 *)(cfg + 0xC4);

                if (nmult != 0) {
                    u32 index = (u32)(node - *(u8 **)(self + 0x18)) >> 5;
                u8 *trail = *(u8 **)(self + 0x18) + ((*(u32 *)(self + 4) + index * nmult) << 5);

                    memcpy(trail, node, 0x20);
                    *(s32 *)(trail + 0x10) = -1;
                }
                *(s32 *)(node + 0x10) = *(s32 *)(node + 0x10) + 1;
            }
            spawn--;
            continue;
        }
        {
            u_long128 *dst = &prev;

            /* lint: allow H009 -- retail copies this quad through $2 at 0x004913DC; b210 keeps $v0 live (user-approved 2026-10-09) */
            __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(dst), "r"(node) : "$2", "memory");
        }
        reach = *(f32 *)(extra + 0xC);
        if (*(s32 *)(node + 0x10) < divD8) {
            *(f32 *)(extra + 0xC) = reach + *(f32 *)(extra + 0x10);
        }
        travel = *(f32 *)(extra + 0x14) + growth * (f32)state;
        if (travel < zero) {
            travel = zero;
        }
        dir.lane[0] = *(f32 *)(extra + 0x0);
        dir.lane[1] = *(f32 *)(extra + 0x4);
        dir.lane[2] = *(f32 *)(extra + 0x8);
        __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&dir), "m"(dir) : "$vf12");
        effectVuLoad11((EffectVuVector *)node);
        __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10");
        effectVuScale10(travel);
        __asm__ volatile("vadd.xyzw $vf11, $vf11, $vf10" : : : "$vf11");
        effectVuLoad10((EffectVuVector *)&origin);
        /* Retail moves the vsqrt result through $2 (cfc2/mtc1 bridge). */
        __asm__ volatile(
            "vsub.xyzw $vf10, $vf10, $vf11\n"
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vaddy.x $vf2, $vf2, $vf2y\n"
            "vaddz.x $vf2, $vf2, $vf2z\n"
            "vsqrt $Q, $vf2x\n"
            "vwaitq\n"
            "cfc2.ni $2, $vi22\n"
            "mtc1 $2, %0\n" : "=f"(dist) : : "$2", "$vf2", "$vf10");
        if (!(dist <= reach)) {
            f32 dot;
            f32 over;

            /* Retail moves the dot product through $2 (qmfc2/mtc1 bridge). */
            __asm__ volatile(
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n"
                "vmove.xyzw $vf11, $vf12\n"
                "vmul.xyz $vf2, $vf10, $vf11\n"
                "vaddy.x $vf2, $vf2, $vf2y\n"
                "vaddz.x $vf2, $vf2, $vf2z\n"
                "qmfc2.ni $2, $vf2\n"
                "mtc1 $2, %0\n" : "=f"(dot) : : "$2", "$vf2", "$vf10", "$vf11");
            effectVuScale10(two * (dot * (swayBase + swayRange * effMiscRandFloat(0))));
            __asm__ volatile("vsub.xyzw $vf11, $vf11, $vf10" : : : "$vf11");
            effectVuStore11(&bounce);
            *(f32 *)(extra + 0x0) = bounce.lane[0];
            *(f32 *)(extra + 0x4) = bounce.lane[1];
            *(f32 *)(extra + 0x8) = bounce.lane[2];
            over = dist - reach;
            effectVuLoad10((EffectVuVector *)node);
            __asm__ volatile(
                "qmtc2.ni %0, $vf2\n"
                "vmulx.xyzw $vf12, $vf12, $vf2x\n"
                "vadd.xyzw $vf10, $vf10, $vf12\n" : : "r"(travel - over) : "$vf2", "$vf10", "$vf12");
            effectVuScale11(over);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            effectVuStore10((EffectVuVector *)node);
        } else {
            effectVuStore11((EffectVuVector *)node);
        }
        func_0048b220(node, config, state, &prev);
        *(f32 *)(node + 0x18) = *(f32 *)(node + 0x18) * *(f32 *)(extra + 0x18);
        *(f32 *)(node + 0x1C) = *(f32 *)(node + 0x1C) * *(f32 *)(extra + 0x20);
        *(f32 *)(node + 0x1C) = *(f32 *)(node + 0x1C) + *(f32 *)(extra + 0x1C);
        func_0048b340(self, node);
        *(s32 *)(node + 0x10) = state + 1;
    }
}
#pragma pop
// FUN_00491660
void func_00491660(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00491660_check;
loop_00491660_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00491660_check:
    if (var_7 < 3U) {
        goto loop_00491660_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD0) = *(f32 *)(temp_5 + 0xD0) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}
/* Swirl emitter update, ported from the d8c0/c4e0 particle family: three
 * stack vectors with retail's w=0 stores, the captured origin quad, loop
 * constants in hoist order, u8 preroll flag and snapshot pointer. The spawn
 * angle forms (g84 * a) * b as one named product before the half-weighted
 * remainder; the radius pairs are both formed before the first is stored. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_004916F0
void func_004916f0(u8 *arg0)
{
    extern void func_004bceb0(void);
    extern f32 effMiscRandFloat(s32 arg0);
    extern s32 effMiscRand(s32 arg0);
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
#pragma pop
// FUN_00492080
void func_00492080(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00492080_check;
loop_00492080_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00492080_check:
    if (var_7 < 3U) {
        goto loop_00492080_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
}
/* Kind-11 Sway update. See docs/probe_archive/sway-update-20261005 for
 * the actual-provider domain, source measurements and independent review. */
// FUN_00492100
#include "sway_particle_internal.h"
/* measured: b210 -O2 needs independent value propagation and loop-invariant
 * constant materialization for the retail register and instruction schedule. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_00492100(u8 *arg0)
{
    extern void func_004bceb0(void);
    extern f32 fabsf(f32 value);
    extern f32 effMiscRandFloat(EffRandState *state);
    extern u32 effMiscRand(EffRandState *state);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 sinf(f32 arg0);
    extern u_long128 D_00713D40;
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    /* These are three separately live, complete 16-byte objects. */
    EffectVuVector direction;
    EffectVuVector spread;
    u_long128 previousPosition;
    u32 count;
    u32 flags;
    SpawnParticle *particle;
    SwayParticleState *state;
    SwayParticleParameters *parameters;
    SwayParticleEmitter *const emitter = (SwayParticleEmitter *)arg0;
    s32 lifetime;
    s32 emissionDuration;
    u8 angleMode;
    f32 initialAmplitude;
    f32 bounceDecay;
    f32 floorHeight;
    f32 deceleration;
    f32 zero;
    f32 one, half, two;
    f32 angleRange;
    f32 reverseAngle;
    s32 spawnBudget;
    u32 index;
    s32 preroll;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 age;
    s32 trailCount;
    s32 trailWidth;
    s32 trailSpan;
    SpawnParticle *trail;
    s32 trailIndex;
    u32 particleIndex;
    f32 a;
    f32 b;
    f32 c;
    count = emitter->primaryCount;
    flags = emitter->flags;
    particle = emitter->particles;
    state = emitter->state;
    parameters = emitter->parameters;
    lifetime = parameters->lifetime;
    if (lifetime == 0) {
        return;
    }
    emissionDuration = parameters->emissionDuration;
    angleMode = parameters->angleMode;
    deceleration = parameters->deceleration;
    bounceDecay = parameters->bounceDecay;
    floorHeight = parameters->floorHeight;
    spread.lane[3] = 0.0f;
    effectVuLoad10((const EffectVuVector *)&parameters->rotation);
    func_004bceb0();
    if ((emissionDuration != 0) && (emitter->ticks >= emissionDuration)) {
        preroll = 0;
        spawnBudget = 0;
        goto setup_loop;
    }
    if ((emitter->ticks == 0) && (parameters->preroll != 0)) {
        u8 initialPreroll = 1;
        preroll = initialPreroll;
        if (!(parameters->emissionVariation <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - parameters->emissionVariation) * effMiscRandFloat(0);
            ftmp2 = (f32)emitter->primaryCount;
            spawnBudget = (s32)(ftmp2 * prerollScale);
        } else {
            spawnBudget = (s32)emitter->primaryCount;
        }
        goto setup_loop;
    } else {
        preroll = 0;
        if (!(parameters->emissionVariation <= 0.0f)) {
            ftmp1 = (fGpffff807c - parameters->emissionVariation) * effMiscRandFloat(0);
            tmp = parameters->emissionRate;
            ftmp2 = (f32)(u32)tmp;
            emitter->emissionAccumulator = emitter->emissionAccumulator + ftmp2 * ftmp1;
        } else {
            tmp = parameters->emissionRate;
            ftmp1 = (f32)(u32)tmp;
            emitter->emissionAccumulator = emitter->emissionAccumulator + ftmp1;
        }
        ftmp1 = emitter->emissionAccumulator;
        ftmp1 = fabsf(ftmp1);
        spawnBudget = (s32)ftmp1;
        emitter->emissionAccumulator = emitter->emissionAccumulator - (f32)spawnBudget;
        goto setup_loop;
    }
setup_loop:
    /* Shared values remain live across all primaries and provider calls. */
    index = 0;
    zero = 0.0f;
    one = 1.0f;
    half = 0.5f;
    two = 2.0f;
    angleRange = fGpffff8080;
    reverseAngle = -1.0f;
    goto main_check;
main_body:
    if (particle->age < lifetime) {
        goto skip_clear;
    }
    if (emissionDuration != 0) {
        tmp = -2;
    } else {
        tmp = -1;
    }
    particle->age = tmp;
    trailCount = emitter->parameters->trailCount;
    trailWidth = emitter->parameters->trailWidth;
    trailSpan = trailCount * trailWidth;
    if (trailSpan != 0) {
        /* Derive the index from the live emitter base, not the loop count. */
        particleIndex = (u32)((u8 *)particle - (u8 *)emitter->particles) / sizeof(*particle);
        trail = emitter->particles + (emitter->primaryCount + particleIndex * trailSpan);
        trailIndex = 0;
        goto clear_check;
clear_body:
        trail->age = -1;
        trail += 1;
        trailIndex += 1;
clear_check:
        if (trailIndex < trailSpan) {
            goto clear_body;
        }
    }
skip_clear:
    age = particle->age;
    if (age == -2) {
        goto next_iter;
    }
    if (age != -1) {
        goto else_branch;
    }
    if (spawnBudget == 0) {
        goto next_iter;
    }
    if ((flags & 1) != 0) {
        state->riseDirection[0] = zero;
        state->riseDirection[1] = one;
        state->riseDirection[2] = zero;
    } else {
        effectVuLoad10((const EffectVuVector *)&D_00713D40);
        spawnVuTransform10();
        effectVuStore10(&direction);
        state->riseDirection[0] = direction.lane[0];
        state->riseDirection[1] = direction.lane[1];
        state->riseDirection[2] = direction.lane[2];
    }
    direction.lane[0] = two * (effMiscRandFloat(0) - half);
    direction.lane[1] = zero;
    direction.lane[2] = two * (effMiscRandFloat(0) - half);
    direction.lane[3] = zero;
    effectVuLoad10(&direction);
    spawnVuNormalize10();
    if ((flags & 1) == 0) {
        spawnVuTransform10();
    }
    effectVuStore10(&direction);
    state->swayDirection[0] = direction.lane[0];
    state->swayDirection[1] = direction.lane[1];
    state->swayDirection[2] = direction.lane[2];
    a = parameters->speedVariation;
    b = effMiscRandFloat(0);
    state->speed = parameters->speed * ((one - a) + a * b);
    a = parameters->bounceVariation;
    b = effMiscRandFloat(0);
    b = (one - a) + a * b;
    state->bounceScale = -parameters->bounce * b;
    a = parameters->initialAmplitudeVariation;
    b = effMiscRandFloat(0);
    initialAmplitude = parameters->initialAmplitude * ((one - a) + a * b);
    a = parameters->finalAmplitudeVariation;
    b = effMiscRandFloat(0);
    ftmp1 = parameters->finalAmplitude * ((one - a) + a * b);
    state->amplitude = initialAmplitude;
    state->amplitudeStep = (ftmp1 - initialAmplitude) / (f32)lifetime;
    a = parameters->phaseVariation;
    b = effMiscRandFloat(0);
    state->phaseStep = parameters->phaseStep * ((one - a) + a * b);
    b = effMiscRandFloat(0);
    state->phase = angleRange * b;
    state->previousSine = sinf(state->phase);
    b = effMiscRandFloat(0);
    c = two * (b - half);
    spread.lane[0] = parameters->spread * c;
    spread.lane[1] = spread.lane[0];
    spread.lane[2] = spread.lane[0];
    if ((flags & 1) != 0) {
        effectVuLoad10(&direction);
        effectVuLoad11(&spread);
        spawnVuMultiply10();
    } else {
        effectVuLoad10(&direction);
        effectVuLoad11(&spread);
        spawnVuMultiply10();
        effectVuLoad11((const EffectVuVector *)&parameters->position);
        spawnVuAdd10();
    }
    effectVuStore10(&particle->position);
    a = parameters->sizeVariation;
    b = effMiscRandFloat(0);
    state->sizeScale = (one - a) + a * b;
    if (angleMode != 2) {
        a = parameters->angleVariation;
        b = effMiscRandFloat(0);
        state->angleScale = (one - a) + a * b;
        if (angleMode == 1) {
            b = effMiscRandFloat(0);
            state->angleOffset = angleRange * b;
            if ((effMiscRand(0) & 1) != 0) {
                state->angleScale = state->angleScale * reverseAngle;
            }
        } else {
            state->angleOffset = zero;
        }
    } else {
        state->angleOffset = zero;
        state->angleScale = one;
    }
    particle->age = 0;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)&particle->position;
    }
    func_0048b220((u8 *)particle, (u8 *)parameters, particle->age, &previousPosition);
    particle->size = particle->size * state->sizeScale;
    particle->angle = particle->angle * state->angleScale;
    particle->angle = particle->angle + state->angleOffset;
    if (preroll != 0) {
        trailCount = emitter->parameters->trailCount;
        trailWidth = emitter->parameters->trailWidth;
        trailSpan = trailCount * trailWidth;
        if (trailSpan != 0) {
            particleIndex = (u32)((u8 *)particle - (u8 *)emitter->particles) / sizeof(*particle);
            trail = emitter->particles + (emitter->primaryCount + particleIndex * trailSpan);
            memcpy(trail, particle, sizeof(*particle));
            trail->age = -1;
        }
        particle->age = particle->age + 1;
    }
    spawnBudget -= 1;
    goto next_iter;
else_branch:
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)&particle->position;
    }
    ftmp1 = sinf(state->phase);
    ftmp2 = ftmp1 - state->previousSine;
    c = state->amplitude * ftmp2;
    particle->position.lane[0] = particle->position.lane[0] + state->swayDirection[0] * c;
    particle->position.lane[1] = particle->position.lane[1] + state->swayDirection[1] * c;
    particle->position.lane[2] = particle->position.lane[2] + state->swayDirection[2] * c;
    state->speed = state->speed - deceleration;
    c = state->speed;
    particle->position.lane[0] = particle->position.lane[0] + state->riseDirection[0] * c;
    particle->position.lane[1] = particle->position.lane[1] + state->riseDirection[1] * c;
    particle->position.lane[2] = particle->position.lane[2] + state->riseDirection[2] * c;
    state->phase = state->phase + state->phaseStep;
    state->amplitude = state->amplitude + state->amplitudeStep;
    state->previousSine = ftmp1;
    if (particle->position.lane[1] < floorHeight) {
        state->bounceScale = state->bounceScale * bounceDecay;
        state->speed = state->speed * state->bounceScale;
        particle->position.lane[1] = floorHeight + state->bounceScale * (particle->position.lane[1] - floorHeight);
    }
    func_0048b220((u8 *)particle, (u8 *)parameters, age, &previousPosition);
    particle->size = particle->size * state->sizeScale;
    particle->angle = particle->angle * state->angleScale;
    particle->angle = particle->angle + state->angleOffset;
    func_0048b340((u8 *)emitter, (u8 *)particle);
    particle->age = age + 1;
next_iter:
    index += 1;
    state += 1;
    particle += 1;
main_check:
    if (index < count) {
        goto main_body;
    }
}
#pragma pop
// FUN_00492A80
void func_00492a80(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00492a80_check;
loop_00492a80_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00492a80_check:
    if (var_7 < 3U) {
        goto loop_00492a80_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xD4) = *(f32 *)(temp_5 + 0xD4) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
}
// FUN_00492B20
u8 *func_00492b20(u16 arg0, s32 arg1, u8 *arg2)
{
    u8 *temp_2;
    u8 *temp_2_2;
    s32 temp_16;
    s32 temp_22;
    s32 temp_17;
    s32 temp_18;

    if ((arg0 & 0xFFFF) >= 0xC) {
        func_0046d730(D_00713E10, 0xD66);
    }
    temp_16 = arg1 * (*(s32 *)(arg2 + 0xC4) * *(s32 *)(arg2 + 0xC0) + 1);
    temp_22 = temp_16 << 5;
    temp_17 = arg1 * D_00713D58[(arg0 & 0xFFFF) * 4];
    temp_18 = D_00713D5C[(arg0 & 0xFFFF) * 4];
    temp_17 += temp_22 + 0x30;
    temp_17 += temp_18 * 2;
    func_0044ea90(D_00713E10, 0xD73);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_17, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_00713E10, 0xD74);
    }
    temp_2_2 = temp_2 + 0x30;
    *(u8 **)(temp_2 + 0x18) = temp_2_2;
    temp_2_2 += temp_22;
    *(u8 **)(temp_2 + 0x20) = temp_2_2;
    temp_2_2 += temp_18;
    *(u8 **)(temp_2 + 0x24) = temp_2_2;
    temp_2_2 += temp_18;
    *(u8 **)(temp_2 + 0x1C) = temp_2_2;
    *(u16 *)(temp_2 + 0x00) = arg0;
    *(s32 *)(temp_2 + 0x04) = arg1;
    *(s32 *)(temp_2 + 0x08) = temp_16;
    *(s32 *)(temp_2 + 0x0C) = 0;
    *(s32 *)(temp_2 + 0x10) = 0;
    *(s32 *)(temp_2 + 0x14) = 0;
    *(u8 **)(temp_2 + 0x28) = temp_2;
    memcpy(*(void **)(temp_2 + 0x20), arg2, temp_18);
    memcpy(*(void **)(temp_2 + 0x24), arg2, temp_18);
    temp_2_2 = *(u8 **)(temp_2 + 0x20);
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(temp_2_2) : "memory");
    __asm__ volatile ("sqc2 vf0, 0x10(%0)" : : "r"(temp_2_2) : "memory");
    if (*(u8 *)(temp_2_2 + 0xBC) != 0) {
        *(s32 *)(temp_2 + 0x0C) |= 1;
    }
    return temp_2;
}
// FUN_00492CD0
void func_00492cd0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x28));
}



// FUN_00492D00
void func_00492d00(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}

/* measured: probing opt_loop_invariants for the preheader -1 and loop branch. */
#pragma opt_loop_invariants on
// FUN_00492D10
void func_00492d10(void *object) {
    u8 *arg0 = object;
    extern void (*D_00713D50[])(u8 *emitter);
    u32 count;
    u32 var_6;
    u8 *var_5;

    if (*(s32 *)(arg0 + 0x10) == 0) {
        count = *(u32 *)(arg0 + 8);
        var_5 = *(u8 **)(arg0 + 0x18);
        var_6 = 0;
        goto loop_00492d10_check;
loop_00492d10_body:
        *(s32 *)(var_5 + 0x10) = -1;
        var_5 += 0x20;
        var_6 += 1;
loop_00492d10_check:
        if (var_6 < count) {
            goto loop_00492d10_body;
        }
    }
    D_00713D50[*(u16 *)arg0 * 4](arg0);
    *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x10) + 1;
}
/* measured: closes opt_loop_invariants at its prior file baseline. */
#pragma opt_loop_invariants off
// FUN_00492E30
void func_00492e30(u16 *arg0, f32 scale) {
    D_00713D54[*arg0 * 4]((u8 *)arg0, scale);
}
/* measured: probing opt_propagation off for func_004940d0 load and branch order. */
#pragma opt_propagation off
/* measured: probing opt_common_subs off for color byte reloads. */
#pragma opt_common_subs off
// FUN_004940D0
void func_004940d0(u8 *arg0, u16 arg1, Code1_0049Color *arg2)
{
    u32 var_3;
    u32 max_1;
    u32 max_2;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;
    u8 *temp_10;
    u8 *temp_10_2;
    u8 *temp_5;
    u8 *temp_7;
    u8 *temp_8;
    u8 *temp_8_2;

    temp_7 = *(u8 **)(arg0 + 0x10);
    c3 = arg2->c3;
    max_1 = 0xFF;
    if (c3 != max_1) {
        var_3 = (arg1 & 0xFFFF) * 4;
        temp_10 = *(u8 **)(*(u8 **)(temp_7 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_10[4] = c0;
        temp_10[5] = c1;
        temp_10[6] = c2;
        temp_10[7] = c3;
    } else {
        arg2->c3 = 0xFE;
        var_3 = (arg1 & 0xFFFF) * 4;
        temp_10_2 = *(u8 **)(*(u8 **)(temp_7 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_10_2[4] = c0;
        temp_10_2[5] = c1;
        temp_10_2[6] = c2;
        temp_10_2[7] = c3;
        arg2->c3 = max_1;
    }
    temp_5 = *(u8 **)(arg0 + 0x14);
    c3 = arg2->c3;
    max_2 = 0xFF;
    if (c3 != max_2) {
        temp_8 = *(u8 **)(*(u8 **)(temp_5 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_8[4] = c0;
        temp_8[5] = c1;
        temp_8[6] = c2;
        temp_8[7] = c3;
        return;
    }
    arg2->c3 = 0xFE;
    temp_8_2 = *(u8 **)(*(u8 **)(temp_5 + 0x54) + var_3);
    c0 = arg2->c0;
    c1 = arg2->c1;
    c2 = arg2->c2;
    c3 = arg2->c3;
    temp_8_2[4] = c0;
    temp_8_2[5] = c1;
    temp_8_2[6] = c2;
    temp_8_2[7] = c3;
    arg2->c3 = max_2;
}
/* measured: closing opt_common_subs after func_004940d0 probe. */
#pragma opt_common_subs on
/* measured: closing opt_propagation after func_004940d0 probe. */
#pragma opt_propagation on
/* func_004941f0, MATCH 2026-10-07. Counts are unsigned after the signed-short
   loads; complete vector and packed-colour objects keep the VU transfers, and
   the colour unpacks use effectVuUnpackColor10V0. `opt_loop_invariants on`
   hoists the loop's vector addresses and 255.0f as retail does (measured:
   without it the body differs by 65 words). `opt_pulloutconstants off`
   stops IRO_CommonSubs from sharing the entry's 1.0f with the loop, so the
   loop preheader rematerialises it as retail does. The first unpack reads its
   word through a `const u32 *` local, which schedules the scale load after
   the address. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_pulloutconstants off
/* Interpolate the ribbon colors, then repeat its first row and the cap colors. */
// FUN_004941F0
void func_004941f0(u8 *track, u32 *colors)
{
    extern u8 *RpGeometryLock(u8 *geometry, s32 lockMode);
    extern u8 *func_003c22f0(u8 *geometry);
    extern f32 fGpffff8044;
    u32 firstWord;
    u32 secondWord;
    u32 thirdWord;
    u32 fourthWord;
    u32 firstPacked;
    u32 secondPacked;
    EffectVuVector first;
    EffectVuVector third;
    EffectVuVector second;
    EffectVuVector fourth;
    u8 *work;
    u32 rowCount;
    u32 vertexCount;
    u32 segmentCount;
    u8 *destination;
    u8 *firstRow;
    f32 fraction;
    f32 fractionStep;
    f32 scale;
    u32 index;
    u32 rowBytes;
    u32 rowIndex;
    u8 *geometry;
    u8 *cap;
    u8 *capColors;
    u8 *nextCapRow;
    u32 capRowIndex;

    work = *(u8 **)(track + 0x10);
    RpGeometryLock(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 8);
    rowCount = *(s16 *)(work + 0x48);
    vertexCount = *(s16 *)(work + 8);
    segmentCount = vertexCount / 3U;
    destination = *(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x30);
    firstRow = destination;
    fractionStep = 1.0f / (f32)segmentCount;
    fraction = 0.0f;
    firstWord = colors[0];
    {
        const u32 *word = &firstWord;

        scale = fGpffff8044;
        effectVuUnpackColor10V0(word, scale);
    }
    effectVuStore10(&first);
    secondWord = colors[1];
    effectVuUnpackColor10V0(&secondWord, scale);
    effectVuStore10(&second);
    thirdWord = colors[2];
    effectVuUnpackColor10V0(&thirdWord, scale);
    effectVuStore10(&third);
    fourthWord = colors[3];
    effectVuUnpackColor10V0(&fourthWord, scale);
    effectVuStore10(&fourth);
    index = 0;
    while (index < segmentCount) {
        f32 inverse;
        effectVuLoad11(&first);
        effectVuLoad10(&third);
        effectVuScale10(fraction);
        inverse = 1.0f - fraction;
        effectVuScale11(inverse);
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
        {
            /* Binary32 255.0f converts normalized VU color lanes back to bytes. */
            u32 packed;
            __asm__ volatile(
                "qmtc2.ni %2, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2.ni %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, firstPacked\n"
                : "=&r"(packed), "=m"(firstPacked)
                : "r"(0x437F0000U)
                : "$vf2", "$vf10", "memory");
        }
        *(u32 *)(destination + 4) = firstPacked;
        effectVuLoad11(&second);
        effectVuLoad10(&fourth);
        effectVuScale10(fraction);
        effectVuScale11(inverse);
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
        {
            /* Binary32 255.0f converts normalized VU color lanes back to bytes. */
            u32 packed;
            __asm__ volatile(
                "qmtc2.ni %2, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2.ni %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, secondPacked\n"
                : "=&r"(packed), "=m"(secondPacked)
                : "r"(0x437F0000U)
                : "$vf2", "$vf10", "memory");
        }
        *(u32 *)destination = secondPacked;
        *(Code1_0049Color *)(destination + 8) = *(Code1_0049Color *)destination;
        fraction += fractionStep;
        destination += 12;
        index++;
    }
    rowIndex = 1;
    rowBytes = vertexCount * 4;
    while (rowIndex < rowCount) {
        memcpy(destination, firstRow, rowBytes);
        destination += rowBytes;
        rowIndex++;
    }
    geometry = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(geometry);
    if (*(u16 *)work & 4) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
    cap = *(u8 **)(track + 0x14);
    RpGeometryLock(*(u8 **)(*(u8 **)(cap + 0x10) + 0x18), 8);
    capColors = *(u8 **)(*(u8 **)(*(u8 **)(cap + 0x10) + 0x18) + 0x30);
    *(u32 *)capColors = colors[0];
    *(u32 *)(capColors + 4) = colors[1];
    *(Code1_0049Color *)(capColors + 8) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 12) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 16) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 20) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 24) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 28) = *(Code1_0049Color *)(capColors + 4);
    nextCapRow = capColors + 32;
    capRowIndex = 1;
    while (capRowIndex < rowCount) {
        memcpy(nextCapRow, capColors, 32);
        nextCapRow += 32;
        capRowIndex++;
    }
    geometry = *(u8 **)(*(u8 **)(cap + 0x10) + 0x18);
    func_003c22f0(geometry);
    if (*(u16 *)cap & 4) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
}
#pragma pop
// FUN_00494680
void func_00494680(void *arg0)
{
    func_004841c0(*(void **)((u8 *)arg0 + 0x10));
    func_004841c0(*(void **)((u8 *)arg0 + 0x14));
    jtbl_008873EC[0](arg0);
}



/* Expand the stored halfword index separately at each primitive lookup. */
static inline u32 track_index(u16 value)
{
    return value;
}
#pragma push
#pragma opt_loop_invariants on
/* The geometry contains left/center/right rows of three 12-byte vertices. */
typedef struct TrackVertex
{
    f32 x, y, z;
} TrackVertex;
/* Advance one track's center history, build the tapered ribbon, and mirror
 * the cap vertices from the retained head tangent and side vector.
 * measured: b210 -O2, 2120/2128 bytes with eight zero tail bytes; all 104
 * relocations resolve to retail. Loop invariants retain the narrowed tail
 * bound. The scalar width expression preserves the cap width and VU input
 * as distinct lifetimes; all vector transfers declare their memory operands. */
// FUN_00494740
void func_00494740(u8 *track, u16 trackIndex, u8 *point, f32 width) {
    extern void func_0048a340(f32 angle);
    extern u_long128 D_00713D00;
    extern f32 D_00713D10[4];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    extern f32 fGpffff8094;
    extern f32 fGpffff80bc;
    extern f32 fGpffff80c0;
    extern f32 fGpffff80c8;
    extern f32 fGpffff80cc;
    u_long128 headTangent;
    u_long128 headSide;
    u8 *followingCenter;
    u8 *previousCenter;
    s32 vertexCount;
    u16 shiftedVertex;
    s32 rowCount;
    u32 lastRow;
    u8 *countSlot;
    u32 activeRows;
    u8 *row;
    u8 *firstRow;
    f32 fraction;
    f32 fractionStep;
    f32 headWidth;
    f32 rotation;
    u16 rowIndex;
    u16 lastActiveRow;
    u8 *cap;
    f32 capLength;
    f32 capWidth;

    {
        u8 *t10 = *(u8 **)(track + 0x10);
        vertexCount = *(u16 *)(t10 + 8);
        {
            u8 *t1 = *(u8 **)(t10 + 0x10);
            u8 *t2 = *(u8 **)(t1 + 0x18);
            u8 *t3 = *(u8 **)(t2 + 0x5C);
            u8 *tab = *(u8 **)(t3 + 0x14);
            row = tab + (u32)vertexCount * track_index(trackIndex) * 12;
        }
        previousCenter = row + (vertexCount - 5) * 12;
        followingCenter = row + (vertexCount - 2) * 12;
    }
    shiftedVertex = 3;
    goto shift_check;
shift_center:
    *(TrackVertex *)(followingCenter) = *(const TrackVertex *)(previousCenter);
    previousCenter -= 0x24;
    followingCenter -= 0x24;
    shiftedVertex += 3;
shift_check:
    if (shiftedVertex < vertexCount) {
        goto shift_center;
    }
    *(TrackVertex *)(row + 0xc) = *(const TrackVertex *)(point);
    rowCount = (s32)vertexCount / 3 - 1;
    lastRow = (u16)rowCount;
    countSlot = *(u8 **)(track + 0x18) + (track_index(trackIndex) * 2);
    activeRows = *(u16 *)countSlot;
    if ((s32)activeRows <= (s32)lastRow) {
        u32 nv = activeRows + 1;
        activeRows = (u16)nv;
        *(u16 *)countSlot = (u16)nv;
    }
    firstRow = row;
    headWidth = 0.0f;
    __asm__ volatile("sqc2 $vf0, 0(%1)" : "=m"(headTangent) : "r"(&headTangent) : "memory");
    __asm__ volatile("sqc2 $vf0, 0(%1)" : "=m"(headSide) : "r"(&headSide) : "memory");
    rowIndex = 0;
    if ((s32)(u16)activeRows <= 1) {
        goto collapse_tail;
    }
    {
        fraction = (f32)(u32)activeRows / (f32)(u32)lastRow;
        fractionStep = fraction / (f32)(u32)activeRows;
        headWidth = width * fraction;
    }
    lastActiveRow = activeRows - 1;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D00), "m"(D_00713D00) : "$vf10", "memory");
    __asm__ volatile(
        "vmove.xyzw $vf24, $vf10 \n"
        : : : "$vf24", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(track), "m"(*(u_long128 *)track) : "$vf11", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf11 \n"
        "vaddy.x $vf2, $vf2, $vf2y \n"
        "vaddz.x $vf2, $vf2, $vf2z \n"
        : : : "$vf2", "memory");
    {
        f32 dot;
        __asm__ volatile(
            "qmfc2 %0, $vf2 \n"
            : "=r"(dot) : : "memory");
        rotation = fGpffff8094 * dot;
    }
    D_00713D10[0] = *(f32 *)(row + 12);
    D_00713D14[0] = *(f32 *)(row + 16);
    D_00713D18[0] = *(f32 *)(row + 20);
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
    D_00713D10[0] = *(f32 *)(row + 48);
    D_00713D14[0] = *(f32 *)(row + 52);
    D_00713D18[0] = *(f32 *)(row + 56);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf10", "memory");
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf12 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(headTangent) : "r"(&headTangent) : "memory");
    func_0048a340(rotation);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf24 \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        : : : "$vf10", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(headSide) : "r"(&headSide) : "memory");
    {
            /* The unmodified inputs describe this row's width independently of
         * the retained cap width. Both are the same product at the head. */
        f32 rowWidth = width * fraction;
        __asm__ volatile("qmtc2 %0, $vf2" : : "r"(rowWidth) : "$vf2", "memory");
        __asm__ volatile(
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vadd.xyzw $vf12, $vf12, $vf10 \n"
            : : : "$vf10", "$vf12", "memory");
    }
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    *(f32 *)row = D_00713D10[0];
    *(f32 *)(row + 4) = D_00713D14[0];
    *(f32 *)(row + 8) = D_00713D18[0];
    __asm__ volatile(
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        : : : "$vf12", "memory");
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    *(f32 *)(row + 24) = D_00713D10[0];
    *(f32 *)(row + 28) = D_00713D14[0];
    *(f32 *)(row + 32) = D_00713D18[0];
    fraction = fraction - fractionStep;
    row += 0x24;
    rowIndex++;
    goto ribbon_check;
ribbon_row:
    D_00713D10[0] = *(f32 *)(row + 12);
    D_00713D14[0] = *(f32 *)(row + 16);
    D_00713D18[0] = *(f32 *)(row + 20);
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
    D_00713D10[0] = *(f32 *)(row + 48);
    D_00713D14[0] = *(f32 *)(row + 52);
    D_00713D18[0] = *(f32 *)(row + 56);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf10", "memory");
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf12 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    func_0048a340(rotation);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf24 \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        : : : "$vf10", "ACC", "memory");
    {
        f32 t = width * fraction;
        __asm__ volatile("qmtc2 %0, $vf2" : : "r"(t) : "$vf2", "memory");
        __asm__ volatile(
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vadd.xyzw $vf12, $vf12, $vf10 \n"
            : : : "$vf10", "$vf12", "memory");
    }
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    {
        u8 *dst = row;
        *(f32 *)dst = D_00713D10[0];
        *(f32 *)(dst + 4) = D_00713D14[0];
        *(f32 *)(dst + 8) = D_00713D18[0];
    }
    __asm__ volatile(
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        : : : "$vf12", "memory");
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    *(f32 *)(row + 24) = D_00713D10[0];
    *(f32 *)(row + 28) = D_00713D14[0];
    *(f32 *)(row + 32) = D_00713D18[0];
    fraction = fraction - fractionStep;
    row += 0x24;
    rowIndex++;
ribbon_check:
    if (rowIndex < lastActiveRow) {
        goto ribbon_row;
    }
collapse_tail:
    *(TrackVertex *)(row) = *(const TrackVertex *)(row + 0xc);
    *(TrackVertex *)(row + 0x18) = *(const TrackVertex *)(row + 0xc);
    {
        u8 *nxt = row + 0x24;
        goto tail_check;
tail_row:
        *(TrackVertex *)(nxt) = *(const TrackVertex *)(row);
        *(TrackVertex *)(nxt + 0xc) = *(const TrackVertex *)(row + 0xc);
        *(TrackVertex *)(nxt + 0x18) = *(const TrackVertex *)(row + 0x18);
        nxt += 0x24;
        rowIndex++;
tail_check:
        if (rowIndex < (s32)(u16)lastRow) {
            goto tail_row;
        }
        {
            u8 *t = *(u8 **)(track + 0x14);
            u32 c2 = *(u16 *)(t + 8);
            u8 *t1 = *(u8 **)(t + 0x10);
            u8 *t2 = *(u8 **)(t1 + 0x18);
            u8 *t3 = *(u8 **)(t2 + 0x5C);
            u8 *tab2 = *(u8 **)(t3 + 0x14);
            cap = tab2 + (u32)c2 * track_index(trackIndex) * 12;
            *(TrackVertex *)cap = *(const TrackVertex *)(firstRow + 12);
            *(TrackVertex *)(cap + 0xc) = *(const TrackVertex *)(firstRow);
            *(TrackVertex *)(cap + 0x54) = *(const TrackVertex *)(firstRow + 0x18);
        }
        {
            f32 wide;
            f32 inner;
            f32 blendWide;
            f32 blendInner;
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&headTangent), "m"(headTangent) : "$vf11", "memory");
            __asm__ volatile("vsub.xyz $vf11, $vf0, $vf11" : : : "$vf11", "memory");
            capLength = 2.0f * headWidth;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capLength) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "memory");
            }
            D_00713D10[0] = *(f32 *)(firstRow + 12);
            D_00713D14[0] = *(f32 *)(firstRow + 16);
            D_00713D18[0] = *(f32 *)(firstRow + 20);
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            wide = fGpffff80bc * headWidth;
            capWidth = wide;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capWidth) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "memory");
            }
            {
                blendWide = fGpffff80c0;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendWide) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 24) = D_00713D10[0];
            *(f32 *)(cap + 28) = D_00713D14[0];
            *(f32 *)(cap + 32) = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            inner = 1.7f * headWidth;
            capWidth = inner;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capWidth) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "memory");
            }
            {
                blendInner = fGpffff80c8;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendInner) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 36) = D_00713D10[0];
            *(f32 *)(cap + 40) = D_00713D14[0];
            *(f32 *)(cap + 44) = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(wide) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vsub.xyz $vf10, $vf0, $vf10 \n"
                    : : : "$vf10", "memory");
            }
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendWide) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 72) = D_00713D10[0];
            *(f32 *)(cap + 76) = D_00713D14[0];
            *(f32 *)(cap + 80) = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            {
                f32 t2 = inner;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(t2) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vsub.xyz $vf10, $vf0, $vf10 \n"
                    : : : "$vf10", "memory");
            }
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendInner) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 60) = D_00713D10[0];
            *(f32 *)(cap + 64) = D_00713D14[0];
            *(f32 *)(cap + 68) = D_00713D18[0];
            {
                f32 endpoint = fGpffff80cc;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(endpoint) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                    "vadd.xyzw $vf11, $vf11, $vf12 \n"
                    : : : "$vf11", "memory");
            }
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            *(f32 *)(cap + 48) = D_00713D10[0];
            *(f32 *)(cap + 52) = D_00713D14[0];
            *(f32 *)(cap + 56) = D_00713D18[0];
        }
    }
}

#pragma pop
// FUN_00494F90
void func_00494f90(u8 *arg0) {
    func_0048a1f0(arg0);
    RpGeometryLock(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x10)) + 0x10)) + 0x18), 0xA);
    RpGeometryLock(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x14)) + 0x10)) + 0x18), 0xA);
}

// FUN_00494FF0
void func_00494ff0(u8 *arg0) {
    extern void func_003c22f0(void *);
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;
    u8 *temp_18;

    temp_18 = *(u8 **)(arg0 + 0x14);
    temp_17 = *(u8 **)(*(u8 **)(temp_18 + 0x10) + 0x18);
    func_003c22f0(temp_17);
    if (*(u16 *)temp_18 & 4) {
        *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
    }
    temp_17_2 = *(u8 **)(arg0 + 0x10);
    temp_16 = *(u8 **)(*(u8 **)(temp_17_2 + 0x10) + 0x18);
    func_003c22f0(temp_16);
    if (*(u16 *)temp_17_2 & 4) {
        *(u16 *)(temp_16 + 0xC) = *(u16 *)(temp_16 + 0xC) | 1;
    }
}
// FUN_00495090
void func_00495090(u8 *arg0, u32 arg1)
{
    func_00484280(*(u8 **)(arg0 + 0x10), (s32)arg1);
    func_00484280(*(u8 **)(arg0 + 0x14), (s32)arg1);
}

// FUN_004950E0
void func_004950e0(u8 *arg0) {
    u32 temp_16;
    u8 *var_18;
    u32 var_17;

    var_18 = *(u8 **)(*(u8 ***)(arg0 + 0x30));
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    var_17 = 0;
    goto loop_004950e0_check;
loop_004950e0_body:
    *(s32 *)(var_18 + 4) = -1 - (effMiscRand(0) & 3);
    var_17 += 1;
    var_18 += 0x10;
loop_004950e0_check:
    if (var_17 < temp_16) {
        goto loop_004950e0_body;
    }
}
// FUN_00498AC0
void func_00498ac0(u8 *arg0) {
    D_00713E78[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    jtbl_008873EC[0](arg0);
}
// FUN_00498B20
void *func_00498b20(void *source) {
    u8 *arg0 = source;

    return func_004988c0(*(u16 *)(arg0 + 0x2C), *(u8 **)(arg0 + 0x34));
}
// FUN_00498B50
void func_00498b50(u8 *arg0) {
    D_00713E70[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    *(s32 *)(arg0 + 0x28) = 0;
}
// FUN_00498BA0
void func_00498ba0(u8 *arg0) {
    D_00713E7C[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    *(s32 *)(arg0 + 0x28) = *(s32 *)(arg0 + 0x28) + 1;
}
// FUN_00498C00
void func_00498c00(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x28) > 0) {
        D_00713E80[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    }
}
// FUN_00498CE0
u_long128 func_00498ce0(u_long128 *arg0, u_long128 *arg1) {
    return *arg0 = *arg1;
}
// FUN_00498CF0
u_long128 func_00498cf0(u_long128 *arg0, u_long128 *arg1) {
    return arg0[1] = *arg1;
}
// FUN_00498D00
void func_00498d00(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = arg1;
}
// FUN_00498D10
void func_00498d10(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x20) = fparg0;
}
// FUN_00498D20
void func_00498d20(u8 *arg0) {
    u8 *temp_4;
    u8 *temp_7;
    u8 *temp_7_2;

    temp_4 = *(u8 **)(*(u8 **)(arg0 + 0x3C));
    if (iGpffffbb64.c3 != 0xFF) {
        temp_7 = *(u8 **)(temp_4 + 0x14);
        *(Code1_0049Color *)(temp_7 + 4) = iGpffffbb64;
        return;
    }
    iGpffffbb64.c3 = 0xFE;
    temp_7_2 = *(u8 **)(temp_4 + 0x14);
    *(Code1_0049Color *)(temp_7_2 + 4) = iGpffffbb64;
    iGpffffbb64.c3 = 0xFF;
}
// FUN_0049A570
void func_0049a570(u8 *arg0) {
    D_00713F18[*(s32 *)(arg0 + 0x38) * 6](*(void **)(arg0 + 0x3C));
    jtbl_008873EC[0](arg0);
}
// FUN_0049A5E0
void *func_0049a5e0(void *source) {
    u8 *arg0 = source;

    return func_0049a370(*(u16 *)(arg0 + 0x38), *(u8 **)(arg0 + 0x40));
}
// FUN_0049A610
void func_0049a610(u8 *arg0) {
    D_00713F10[*(s32 *)(arg0 + 0x38) * 6](arg0);
    *(s32 *)(arg0 + 0x34) = 0;
}
// FUN_0049A660
void func_0049a660(u8 *arg0) {
    D_00713F1C[*(s32 *)(arg0 + 0x38) * 6](arg0);
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x34) + 1;
}
// FUN_0049A6C0
void func_0049a6c0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x34) > 0) {
        D_00713F20[*(s32 *)(arg0 + 0x38) * 6](arg0);
    }
}
// FUN_0049A7A0
u_long128 func_0049a7a0(u_long128 *arg0, u_long128 *arg1) {
    return *arg0 = *arg1;
}
// FUN_0049A7B0
u_long128 func_0049a7b0(u_long128 *arg0, u_long128 *arg1) {
    return arg0[1] = *arg1;
}
// FUN_0049A7C0
void func_0049a7c0(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x30) = arg1;
}
// FUN_0049A7D0
void func_0049a7d0(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x20) = fparg0;
    *(f32 *)(arg0 + 0x24) = fparg0;
    *(f32 *)(arg0 + 0x28) = fparg0;
}
// FUN_0049A7F0
void func_0049a7f0(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}
/* measured: the sibling 0049b470 body matches this routine's control-flow and
   call sequence; target entries are 0x18 bytes, so the fill stride is six words. */
#pragma opt_loop_invariants on
// FUN_0049A810
void func_0049a810(u8 *arg0)
{
    extern void RpGeometryLock(void *, s32);
    extern void func_003c22f0(void *);
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    RpGeometryLock(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    memset((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
/* measured: closes the opt_loop_invariants scope for 0049a810 at the file baseline. */
#pragma opt_loop_invariants off
