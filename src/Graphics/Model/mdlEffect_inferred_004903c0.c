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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0049; members 004903c0-004903c0 */

/* Ported from the Cone emitter (EffConeEmitterUpdate): the same
 * owner identity, loop constants, clear-loop and snapshot shapes. The scale
 * locals are declared in retail FPR order (variation, E8, E4, F4, D8). The
 * live-particle height is read from VF10 through $v0 (qmfc2/prot3w), and
 * the floor blend and downward speed use a named product operand. */
#pragma push
/* measured: func_004903c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: func_004903c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_004903C0
void func_004903c0(u8 *arg0)
{
    extern void mdlEffectSampleKeyState(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern void effMiscBuildRotationVU(void);
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
    effMiscBuildRotationVU();
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
    mdlEffectSampleKeyState(nodes, config, 0, (u_long128 *)nodes);
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
    mdlEffectSampleKeyState(nodes, config, node10, &b220buf);
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

