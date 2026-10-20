#include "member_access.h"
#include "btl_action_internal.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "mdl_effect_emitter_internal.h"
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


/* Shares the Cone emitter's (EffConeEmitterUpdate) loop constants, clear loop and snapshot shapes. */
#pragma push
#pragma pop
/* Particle emitter update: spawn/respawn bookkeeping, then per-particle motion with VU0 direction,
 * sway and bounce. */
#pragma push
/* measured: retail hoists the constant block out of the particle loop and loads it before the loop
 * starts. */
#pragma opt_loop_invariants on
/* measured: retail spills swayBase rather than the dot product. */
#pragma opt_lifetimes on
/* measured: retail keeps the u8 copy used for burst = 1. */
#pragma opt_propagation off
/* Emit particles inside a changing radius and reflect directions at its boundary. */
// FUN_00490C40
void mdlEffectUpdateBoundedEmitter(u8 *emitterData)
{
    MdlEffectEmitterParameters *prerollParameters;
    MdlEffectEmitterParameters *emissionParameters;

    extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
    extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
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
    u8 *particle;
    u8 *stateData;
    u8 *parameters;
    u8 *emitter;
    s32 lifetime;
    s32 emissionDuration;
    f32 dist;
    u8 angleMode;
    f32 half;
    s32 spawnBudget;
    s64 preroll;
    u32 i;
    s32 state;
    s32 radiusDuration;
    f32 two;
    f32 one;
    f32 zero;
    f32 speed;
    f32 spin;
    f32 negativeOne;
    f32 swayRange;
    f32 growth;
    f32 t;
    f32 travel;
    f32 swayBase;
    f32 reach;

    emitter = emitterData;
    count = ((MdlEffectEmitter *)emitter)->primaryCount.value;
    flags = ((MdlEffectEmitter *)emitter)->flags;
    particle = ((MdlEffectEmitter *)emitter)->particles;
    stateData = ((MdlEffectEmitter *)emitter)->state.bytes;
    parameters = ((MdlEffectEmitter *)emitter)->parameters;
    if (((MdlEffectEmitterParameters *)parameters)->lifetime == 0) {
        return;
    }
    if ((flags & 1) == 0) {
        u_long128 *dst = &origin;

        /* lint: allow H009 -- retail copies this quad through a fixed scratch register that the
         * compiler would otherwise keep live. */
        __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(dst), "r"(parameters) : "$2", "memory");
    } else {
        u_long128 *dst = &origin;

        /* lint: allow H009 -- retail copies this quad through a fixed scratch register that the
         * compiler would otherwise keep live. */
        __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(dst), "r"(&D_00922D70) : "$2", "memory");
    }
    lifetime = ((MdlEffectEmitterParameters *)parameters)->lifetime;
    emissionDuration = ((MdlEffectEmitterParameters *)parameters)->emissionDuration;
    radiusDuration = ((MdlEffectBoundParameters *)parameters)->radiusDuration;
    angleMode = ((MdlEffectEmitterParameters *)parameters)->angleMode;
    growth = ((MdlEffectBoundParameters *)parameters)->acceleration;
    dir.lane[3] = 0.0f;
    if (emissionDuration != 0 && !(((MdlEffectEmitter *)emitter)->ticks < emissionDuration)) {
        preroll = 0;
        spawnBudget = 0;
    } else if (((MdlEffectEmitter *)emitter)->ticks == 0 && ((MdlEffectEmitterParameters *)parameters)->preroll != 0) {
        {
            u8 on;

            on = 1;
            preroll = on;
        }
        if (!((prerollParameters = (MdlEffectEmitterParameters *)parameters)->emissionVariation <= 0.0f)) {
            spawnBudget = (s32)((f32)((MdlEffectEmitter *)emitter)->primaryCount.value * ((fGpffff807c - ((MdlEffectEmitterParameters *)parameters)->emissionVariation) * effMiscRandFloat(0)));
        } else {
            spawnBudget = ((MdlEffectEmitter *)emitter)->primaryCount.value;
        }
    } else {

        preroll = 0;
        if (!((emissionParameters = (MdlEffectEmitterParameters *)parameters)->emissionVariation <= 0.0f)) {
            f32 scale = (fGpffff807c - ((MdlEffectEmitterParameters *)parameters)->emissionVariation) * effMiscRandFloat(0);

            ((MdlEffectEmitter *)emitter)->emissionAccumulator = ((MdlEffectEmitter *)emitter)->emissionAccumulator + (f32)((MdlEffectEmitterParameters *)parameters)->emissionRate.value * scale;
        } else {
            MEMBER(f32, emitter, MdlEffectEmitter, emissionAccumulator) = MEMBER(f32, emitter, MdlEffectEmitter, emissionAccumulator) + (f32)((MdlEffectEmitterParameters *)parameters)->emissionRate.value;
        }
        swayBase = ((MdlEffectEmitter *)emitter)->emissionAccumulator;
        spawnBudget = (s32)fabsf(swayBase);
        ((MdlEffectEmitter *)emitter)->emissionAccumulator = swayBase - (f32)spawnBudget;
    }
    i = 0;
    half = 0.5f;
    two = 2.0f;
    one = 1.0f;
    zero = 0.0f;
    spin = fGpffff8080;
    negativeOne = -1.0f;
    swayRange = fGpffff8088;
    swayBase = fGpffff808c;
    for (; i < count; i++, stateData += 0x24, particle += 0x20) {
        if (!(MEMBER(s32, particle, SpawnParticle, age) < lifetime)) {
            u8 *cfg;
            s32 trailLength;

            ((SpawnParticle *)particle)->age = emissionDuration != 0 ? -2 : -1;
            cfg = ((MdlEffectEmitter *)emitter)->parameters;
            trailLength = ((MdlEffectEmitterParameters *)cfg)->trailCount.signedValue * ((MdlEffectEmitterParameters *)cfg)->trailWidth;
            if (trailLength != 0) {
                u32 index = (u32)(particle - ((MdlEffectEmitter *)emitter)->particles) >> 5;
                u8 *trail = ((MdlEffectEmitter *)emitter)->particles + ((((MdlEffectEmitter *)emitter)->primaryCount.value + index * trailLength) << 5);
                s32 k;

                for (k = 0; k < trailLength; trail += 0x20, k++) {
                    ((SpawnParticle *)trail)->age = -1;
                }
            }
        }
        state = ((SpawnParticle *)particle)->age;
        if (state == -2) {
            continue;
        }
        if (state == -1) {
            if (spawnBudget == 0) {
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
            ((MdlEffectBoundState *)stateData)->direction[0] = dir.lane[0];
            ((MdlEffectBoundState *)stateData)->direction[1] = dir.lane[1];
            ((MdlEffectBoundState *)stateData)->direction[2] = dir.lane[2];
            t = ((MdlEffectBoundParameters *)parameters)->speedVariation;
            ((MdlEffectBoundState *)stateData)->speed = fabsf(((MdlEffectBoundParameters *)parameters)->speed * ((one - t) + t * effMiscRandFloat(0)));
            t = ((MdlEffectBoundParameters *)parameters)->radiusVariation;
            speed = ((MdlEffectBoundParameters *)parameters)->radius * ((one - t) + t * effMiscRandFloat(0));
            t = ((MdlEffectBoundParameters *)parameters)->endRadiusVariation;
            t = ((MdlEffectBoundParameters *)parameters)->endRadius * ((one - t) + t * effMiscRandFloat(0));
            MEMBER(f32, stateData, MdlEffectBoundState, radius) = speed;
            MEMBER(f32, stateData, MdlEffectBoundState, radiusStep) = (t - speed) / (f32)radiusDuration;
            if (preroll != 0) {
                f32 step;

                MEMBER(s32, particle, SpawnParticle, age) = effMiscRand(0) % (u32)lifetime;
                MEMBER(f32, stateData, MdlEffectBoundState, radius) = MEMBER(f32, stateData, MdlEffectBoundState, radius) + MEMBER(f32, stateData, MdlEffectBoundState, radiusStep) * (f32)((SpawnParticle *)particle)->age;
                step = ((MdlEffectBoundState *)stateData)->radiusStep;
                if ((!(step <= zero) && !(MEMBER(f32, stateData, MdlEffectBoundState, radius) <= t)) ||
                    ((step < zero) && (((MdlEffectBoundState *)stateData)->radius < t))) {
                    ((MdlEffectBoundState *)stateData)->radius = t;
                }
                speed = ((MdlEffectBoundState *)stateData)->radius;
            } else {
                ((SpawnParticle *)particle)->age = 0;
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
            effectVuStore10((EffectVuVector *)particle);
            t = ((MdlEffectEmitterParameters *)parameters)->sizeVariation;
            MEMBER(f32, stateData, MdlEffectBoundState, sizeScale) = (one - t) + t * effMiscRandFloat(0);
            state = angleMode;
            if (state != 2) {
                t = ((MdlEffectEmitterParameters *)parameters)->angleVariation;
                MEMBER(f32, stateData, MdlEffectBoundState, angleScale) = (one - t) + t * effMiscRandFloat(0);
                if (state == 1) {
                    MEMBER(f32, stateData, MdlEffectBoundState, angleOffset) = spin * effMiscRandFloat(0);
                    if ((effMiscRand(0) & 1) != 0) {
                        ((MdlEffectBoundState *)stateData)->angleScale = ((MdlEffectBoundState *)stateData)->angleScale * negativeOne;
                    }
                } else {
                    ((MdlEffectBoundState *)stateData)->angleOffset = zero;
                }
            } else {
                ((MdlEffectBoundState *)stateData)->angleOffset = zero;
                ((MdlEffectBoundState *)stateData)->angleScale = one;
            }
            mdlEffectSampleKeyState(particle, parameters, MEMBER(s32, particle, SpawnParticle, age), (u_long128 *)particle); /* Transfer the complete quadword representation, including the VU W lane. */
            ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectBoundState *)stateData)->sizeScale;
            ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectBoundState *)stateData)->angleScale;
            ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectBoundState *)stateData)->angleOffset;
            if (preroll != 0) {
                u8 *cfg = ((MdlEffectEmitter *)emitter)->parameters;
                s32 trailLength = ((MdlEffectEmitterParameters *)cfg)->trailCount.signedValue * ((MdlEffectEmitterParameters *)cfg)->trailWidth;

                if (trailLength != 0) {
                    u32 index = (u32)(particle - ((MdlEffectEmitter *)emitter)->particles) >> 5;
                u8 *trail = ((MdlEffectEmitter *)emitter)->particles + ((((MdlEffectEmitter *)emitter)->primaryCount.value + index * trailLength) << 5);

                    memcpy(trail, particle, 0x20);
                    ((SpawnParticle *)trail)->age = -1;
                }
                ((SpawnParticle *)particle)->age = ((SpawnParticle *)particle)->age + 1;
            }
            spawnBudget--;
            continue;
        }
        {
            u_long128 *dst = &prev;

            /* lint: allow H009 -- retail copies this quad through a fixed scratch register that the
             * compiler would otherwise keep live. */
            __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(dst), "r"(particle) : "$2", "memory");
        }
        reach = MEMBER(f32, stateData, MdlEffectBoundState, radius);
        if (((SpawnParticle *)particle)->age < radiusDuration) {
            ((MdlEffectBoundState *)stateData)->radius = reach + ((MdlEffectBoundState *)stateData)->radiusStep;
        }
        travel = ((MdlEffectBoundState *)stateData)->speed + growth * (f32)state;
        if (travel < zero) {
            travel = zero;
        }
        dir.lane[0] = ((MdlEffectBoundState *)stateData)->direction[0];
        dir.lane[1] = ((MdlEffectBoundState *)stateData)->direction[1];
        dir.lane[2] = ((MdlEffectBoundState *)stateData)->direction[2];
        __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&dir), "m"(dir) : "$vf12");
        effectVuLoad11((EffectVuVector *)particle);
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
            ((MdlEffectBoundState *)stateData)->direction[0] = bounce.lane[0];
            ((MdlEffectBoundState *)stateData)->direction[1] = bounce.lane[1];
            ((MdlEffectBoundState *)stateData)->direction[2] = bounce.lane[2];
            over = dist - reach;
            effectVuLoad10((EffectVuVector *)particle);
            __asm__ volatile(
                "qmtc2.ni %0, $vf2\n"
                "vmulx.xyzw $vf12, $vf12, $vf2x\n"
                "vadd.xyzw $vf10, $vf10, $vf12\n" : : "r"(travel - over) : "$vf2", "$vf10", "$vf12");
            effectVuScale11(over);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            effectVuStore10((EffectVuVector *)particle);
        } else {
            effectVuStore11((EffectVuVector *)particle);
        }
        mdlEffectSampleKeyState(particle, parameters, state, &prev);
        ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectBoundState *)stateData)->sizeScale;
        ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectBoundState *)stateData)->angleScale;
        ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectBoundState *)stateData)->angleOffset;
        mdlEffectUpdateParticleTrail(emitter, particle);
        ((SpawnParticle *)particle)->age = state + 1;
    }
}


#pragma pop
