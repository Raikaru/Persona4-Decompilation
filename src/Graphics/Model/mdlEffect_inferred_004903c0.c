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
/* Emit downward cone particles, reflecting their vertical motion against the configured floor. */
// FUN_004903C0
void mdlEffectUpdateFloorEmitter(u8 *emitterData)
{
    extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
    extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
    extern void effMiscBuildRotationVU(void);
    extern f32 fabsf(f32 emitterData);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    EffectVuVector direction;
    typedef struct SwayScale3 {
        f32 lane[3];
    } __attribute__((aligned(16))) SwayScale3;
    SwayScale3 spreadVector;
    u_long128 previousPosition;
    u32 count;
    u32 flags;
    u8 *particle;
    /* measured: sizeScale, angleOffset, angleScale retain array addressing for MATCH. */
    f32 *state;
    u8 *parameters;
    u8 *const emitter = emitterData;
    s32 lifetime;
    s32 emissionDuration;
    u8 angleMode;
    f32 variation;
    f32 gravity;
    f32 acceleration;
    f32 bounceDecay;
    f32 floorHeight;
    f32 one;
    f32 half;
    f32 two;
    f32 zero;
    f32 angleScale;
    f32 negativeOne;
    s32 spawnBudget;
    u32 index;
    s32 sample;
    f32 scaledValue;
    f32 sampleValue;
    s32 age;
    s32 trailCount;
    s32 trailWidth;
    s32 trailLength;
    u8 *trail;
    s32 trailIndex;
    u32 particleIndex;
    f32 b;
    MdlEffectEmitter *work;
    MdlEffectFloorParameters *floor;
    SpawnParticle *sampleParticle;

    work = (MdlEffectEmitter *)emitter;
    count = work->primaryCount.value;
    flags = ((MdlEffectEmitter *)emitter)->flags;
    particle = ((MdlEffectEmitter *)emitter)->particles;
    state = ((MdlEffectEmitter *)emitter)->state.scalars;
    parameters = ((MdlEffectEmitter *)emitter)->parameters;
    floor = (MdlEffectFloorParameters *)parameters;
    lifetime = ((MdlEffectEmitterParameters *)parameters)->lifetime;
    if (lifetime == 0) {
        return;
    }
    emissionDuration = ((MdlEffectEmitterParameters *)parameters)->emissionDuration;
    angleMode = ((MdlEffectEmitterParameters *)parameters)->angleMode;
    gravity = ((MdlEffectFloorParameters *)parameters)->gravity;
    bounceDecay = ((MdlEffectFloorParameters *)parameters)->bounceDecay;
    acceleration = ((MdlEffectFloorParameters *)parameters)->acceleration;
    floorHeight = ((MdlEffectFloorParameters *)parameters)->floorHeight;
    direction.lane[3] = 0.0f;
    effectVuLoad10((const EffectVuVector *)(parameters + 16));
    effMiscBuildRotationVU();
    if ((emissionDuration != 0) && (((MdlEffectEmitter *)emitter)->ticks >= emissionDuration)) {
        spawnBudget = 0;
        goto post_init;
    }
    if ((((MdlEffectEmitter *)emitter)->ticks == 0) && (((MdlEffectEmitterParameters *)parameters)->preroll != 0)) {
        if (!(floor->common.emissionVariation <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - ((MdlEffectEmitterParameters *)parameters)->emissionVariation) * effMiscRandFloat(0);
            sampleValue = (f32)((MdlEffectEmitter *)emitter)->primaryCount.value;
            spawnBudget = (s32)(sampleValue * prerollScale);
        } else {
            spawnBudget = ((MdlEffectEmitter *)emitter)->primaryCount.signedValue;
        }
        goto post_init;
    } else {
        if (!(floor->common.emissionVariation <= 0.0f)) {
            scaledValue = (fGpffff807c - ((MdlEffectEmitterParameters *)parameters)->emissionVariation) * effMiscRandFloat(0);
            sample = ((MdlEffectEmitterParameters *)parameters)->emissionRate.signedValue;
            sampleValue = (f32)(u32)sample;
            ((MdlEffectEmitter *)emitter)->emissionAccumulator = ((MdlEffectEmitter *)emitter)->emissionAccumulator + sampleValue * scaledValue;
        } else {
            sample = ((MdlEffectEmitterParameters *)parameters)->emissionRate.signedValue;
            scaledValue = (f32)(u32)sample;
            ((MdlEffectEmitter *)emitter)->emissionAccumulator = ((MdlEffectEmitter *)emitter)->emissionAccumulator + scaledValue;
        }
        scaledValue = ((MdlEffectEmitter *)emitter)->emissionAccumulator;
        scaledValue = fabsf(scaledValue);
        spawnBudget = (s32)scaledValue;
        ((MdlEffectEmitter *)emitter)->emissionAccumulator = ((MdlEffectEmitter *)emitter)->emissionAccumulator - (f32)spawnBudget;
        goto post_init;
    }
post_init:
    index = 0;
    one = 1.0f;
    half = 0.5f;
    two = 2.0f;
    zero = 0.0f;
    angleScale = fGpffff8080;
    negativeOne = -1.0f;
    goto main_check;
main_body:
    sampleParticle = (SpawnParticle *)particle;
    if (sampleParticle->age < lifetime) {
        goto skip_clear;
    }
    if (emissionDuration != 0) {
        sample = -2;
    } else {
        sample = -1;
    }
    ((SpawnParticle *)particle)->age = sample;
    trailCount = ((MdlEffectEmitterParameters *)(((MdlEffectEmitter *)emitter)->parameters))->trailCount.signedValue;
    trailWidth = ((MdlEffectEmitterParameters *)(((MdlEffectEmitter *)emitter)->parameters))->trailWidth;
    trailLength = trailCount * trailWidth;
    if (trailLength != 0) {
        particleIndex = ((u32)particle - (u32)((MdlEffectEmitter *)emitter)->particles) >> 5;
        trail = ((MdlEffectEmitter *)emitter)->particles + ((((MdlEffectEmitter *)emitter)->primaryCount.value + particleIndex * (u32)trailLength) << 5);
        trailIndex = 0;
        goto clear_check;
clear_body:
        ((SpawnParticle *)trail)->age = -1;
        trail += 32;
        trailIndex += 1;
clear_check:
        if (trailIndex < trailLength) {
            goto clear_body;
        }
    }
skip_clear:
    age = ((SpawnParticle *)particle)->age;
    if (age == -2) {
        goto next_iter;
    }
    if (age != -1) {
        goto else_branch;
    }
    if (spawnBudget == 0) {
        goto next_iter;
    }
    variation = ((MdlEffectFloorParameters *)parameters)->coneVariation;
    b = effMiscRandFloat(0);
    variation = ((MdlEffectFloorParameters *)parameters)->cone * ((one - variation) + variation * b);
    direction.lane[0] = variation * ((effMiscRandFloat(0) - half) * two);
    direction.lane[1] = -(one - variation);
    direction.lane[2] = variation * ((effMiscRandFloat(0) - half) * two);
    effectVuLoad10(&direction);
    spawnVuNormalize10();
    if ((flags & 1) == 0) {
        spawnVuTransform10();
    }
    effectVuStore10(&direction);
    ((MdlEffectFloorState *)state)->direction[0] = direction.lane[0];
    ((MdlEffectFloorState *)state)->direction[1] = direction.lane[1];
    ((MdlEffectFloorState *)state)->direction[2] = direction.lane[2];
    variation = ((MdlEffectFloorParameters *)parameters)->speedVariation;
    b = effMiscRandFloat(0);
    ((MdlEffectFloorState *)state)->speed = fabsf(floor->speed * ((one - variation) + variation * b));
    variation = ((MdlEffectFloorParameters *)parameters)->bounceVariation;
    b = effMiscRandFloat(0);
    scaledValue = (one - variation) + variation * b;
    ((MdlEffectFloorState *)state)->bounce = -((MdlEffectFloorParameters *)parameters)->bounce * scaledValue;
    variation = ((MdlEffectFloorParameters *)parameters)->spreadVariation;
    b = effMiscRandFloat(0);
    spreadVector.lane[0] = ((MdlEffectFloorParameters *)parameters)->spread * ((one - variation) + variation * b);
    spreadVector.lane[1] = spreadVector.lane[0];
    spreadVector.lane[2] = spreadVector.lane[0];
    effectVuLoad10(&direction);
    if (((MdlEffectFloorParameters *)parameters)->speed < zero) {
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10", "memory");
    }
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&spreadVector), "m"(*(const u8 (*)[sizeof(spreadVector)])&spreadVector) : "$vf11");
        spawnVuMultiply10();
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&spreadVector), "m"(*(const u8 (*)[sizeof(spreadVector)])&spreadVector) : "$vf11");
        spawnVuMultiply10();
        effectVuLoad11((const EffectVuVector *)parameters);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)particle);
    variation = ((MdlEffectEmitterParameters *)parameters)->sizeVariation;
    b = effMiscRandFloat(0);
    state[5] = (one - variation) + variation * b;
    if (angleMode != 2) {
        variation = ((MdlEffectEmitterParameters *)parameters)->angleVariation;
        b = effMiscRandFloat(0);
        state[7] = (one - variation) + variation * b;
        if (angleMode == 1) {
            b = effMiscRandFloat(0);
            state[6] = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                ((MdlEffectFloorState *)state)->angleScale = ((MdlEffectFloorState *)state)->angleScale * negativeOne;
            }
        } else {
            ((MdlEffectFloorState *)state)->angleOffset = zero;
        }
    } else {
        ((MdlEffectFloorState *)state)->angleOffset = zero;
        ((MdlEffectFloorState *)state)->angleScale = one;
    }
    ((SpawnParticle *)particle)->age = 0;
    mdlEffectSampleKeyState(particle, parameters, 0, (u_long128 *)particle);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectFloorState *)state)->sizeScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectFloorState *)state)->angleScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectFloorState *)state)->angleOffset;
    spawnBudget -= 1;
    goto next_iter;
else_branch:
    {
    f32 liveDistance;
    f32 height;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)particle;
    }
    effectVuLoad11((const EffectVuVector *)particle);
    liveDistance = ((MdlEffectFloorState *)state)->speed + acceleration * (f32)age;
    if (liveDistance < zero) {
        liveDistance = zero;
    }
    ((MdlEffectFloorState *)state)->direction[1] = ((MdlEffectFloorState *)state)->direction[1] - gravity;
    direction.lane[0] = liveDistance * ((MdlEffectFloorState *)state)->direction[0];
    direction.lane[1] = ((MdlEffectFloorState *)state)->direction[1];
    direction.lane[2] = liveDistance * ((MdlEffectFloorState *)state)->direction[2];
    effectVuLoad10(&direction);
    spawnVuAdd10();
    effectVuStore10((EffectVuVector *)particle);
    {
        __asm__ volatile(
            "qmfc2.ni $2, $vf10\n"
            "prot3w $2, $2\n"
            "mtc1 $2, %0\n"
            "nop\n"
            : "=f"(height) : : "$2");
    }
    if (height < floorHeight) {
        ((MdlEffectFloorState *)state)->bounce = ((MdlEffectFloorState *)state)->bounce * bounceDecay;
        ((MdlEffectFloorState *)state)->direction[1] = ((MdlEffectFloorState *)state)->direction[1] * ((MdlEffectFloorState *)state)->bounce;
        scaledValue = ((MdlEffectFloorState *)state)->bounce;
        ((SpawnParticle *)particle)->position.lane[1] = floorHeight + scaledValue * (((SpawnParticle *)particle)->position.lane[1] - floorHeight);
    }
    mdlEffectSampleKeyState(particle, parameters, age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectFloorState *)state)->sizeScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectFloorState *)state)->angleScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectFloorState *)state)->angleOffset;
    mdlEffectUpdateParticleTrail(emitter, particle);
    ((SpawnParticle *)particle)->age = age + 1;
    }
next_iter:
    index += 1;
    state += 8;
    particle += 32;
main_check:
    if (index < count) {
        goto main_body;
    }
}



#pragma pop
