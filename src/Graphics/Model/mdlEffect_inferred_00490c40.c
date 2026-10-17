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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0049; members 00490c40-00490c40 */

/* Ported from the Cone emitter (EffConeEmitterUpdate): the same
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
/* measured: func_00490c40 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_00490c40 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* measured: func_00490c40 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00490C40
void func_00490c40(u8 *arg0)
{
    extern void mdlEffectSampleKeyState(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
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
            mdlEffectSampleKeyState(node, config, *(s32 *)(node + 0x10), (u_long128 *)node);
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
        mdlEffectSampleKeyState(node, config, state, &prev);
        *(f32 *)(node + 0x18) = *(f32 *)(node + 0x18) * *(f32 *)(extra + 0x18);
        *(f32 *)(node + 0x1C) = *(f32 *)(node + 0x1C) * *(f32 *)(extra + 0x20);
        *(f32 *)(node + 0x1C) = *(f32 *)(node + 0x1C) + *(f32 *)(extra + 0x1C);
        func_0048b340(self, node);
        *(s32 *)(node + 0x10) = state + 1;
    }
}

