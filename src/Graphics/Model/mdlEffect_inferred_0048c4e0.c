#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "mdl_effect_emitter_internal.h"
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

extern f32 mdlEffectSampleScalarKeys(u8 *keys, s32 frame, s32 duration);
extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
/* measured: retail leaves the copied quadword as the return value, which callers discard; the vf0
 * stores produce (0,0,0,1), not zero. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation is turned off here so the subtractions are scheduled in retail order. */
#pragma push
/* measured: keeps the two counters as separate variables while preserving the asm cursor. */
#pragma pop
/* measured: these scoped settings keep retail's evaluation order for the wave update. */
#pragma push
#pragma pop
/* Emit radial-motion particles and integrate speed, acceleration, gravity and keyed appearance;
 * scoped locals keep scalar operands live across RNG calls. */
// FUN_0048C4E0
#pragma push
/* measured: retail code generation for EffMotionEmitterUpdate depends on these optimizer settings;
 * the default settings produce different output. */
#pragma opt_propagation off
/* measured: retail's loop shape needs loop-invariant hoisting enabled. */
#pragma opt_loop_invariants on
void EffMotionEmitterUpdate(u8 *emitterData)
{
    extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    EffectVuVector direction;
    /* LQC2 reads the complete representation of this aligned XYZ vector.
     * The fourth word is the struct's unspecified tail padding, not a float
     * member. Preserve the hardware load and all four VU result lanes. */
    typedef struct MotionScale3 {
        f32 lane[3];
    } __attribute__((aligned(16))) MotionScale3;
    typedef char MotionScale3Size[(sizeof(MotionScale3) == 16) ? 1 : -1];
    MotionScale3 spreadVector;
    u_long128 previousPosition;
    u32 count;
    u32 flags;
    u8 *particle;
    f32 *state;
    u8 *parameters;
    u8 *const emitter = emitterData;
    s32 lifetime;
    s32 emissionDuration;
    u8 angleMode;
    f32 gravity;
    f32 acceleration;
    f32 half;
    f32 two;
    f32 one;
    f32 zero;
    f32 angleScale;
    f32 negativeOne;
    s32 spawnBudget;
    s32 preroll;
    u8 initialPreroll;
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
    f32 speedVariation;
    f32 spreadVariation;
    f32 sizeVariation;
    f32 angleVariation;
    f32 b;
    MdlEffectEmitter *work;
    MdlEffectMotionParameters *motion;
    SpawnParticle *sampleParticle;

    work = (MdlEffectEmitter *)emitter;
    count = work->primaryCount.value;
    flags = ((MdlEffectEmitter *)emitter)->flags;
    particle = ((MdlEffectEmitter *)emitter)->particles;
    state = ((MdlEffectEmitter *)emitter)->state.scalars;
    parameters = ((MdlEffectEmitter *)emitter)->parameters;
    motion = (MdlEffectMotionParameters *)parameters;
    lifetime = ((MdlEffectEmitterParameters *)parameters)->lifetime;
    if (lifetime == 0) {
        return;
    }
    emissionDuration = ((MdlEffectEmitterParameters *)parameters)->emissionDuration;
    angleMode = ((MdlEffectEmitterParameters *)parameters)->angleMode;
    gravity = ((MdlEffectMotionParameters *)parameters)->gravity;
    acceleration = ((MdlEffectMotionParameters *)parameters)->acceleration;
    direction.lane[3] = 0.0f;
    if ((emissionDuration != 0) && (((MdlEffectEmitter *)emitter)->ticks >= emissionDuration)) {
        preroll = 0;
        spawnBudget = 0;
        goto post_init;
    }
    if ((((MdlEffectEmitter *)emitter)->ticks == 0) && (((MdlEffectEmitterParameters *)parameters)->preroll != 0)) {
        initialPreroll = 1;
        preroll = initialPreroll;
        if (!(motion->common.emissionVariation <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - ((MdlEffectEmitterParameters *)parameters)->emissionVariation) * effMiscRandFloat(0);
            sampleValue = (f32)((MdlEffectEmitter *)emitter)->primaryCount.value;
            spawnBudget = (s32)(sampleValue * prerollScale);
        } else {
            spawnBudget = ((MdlEffectEmitter *)emitter)->primaryCount.signedValue;
        }
        goto post_init;
    } else {
        preroll = 0;
        if (!(motion->common.emissionVariation <= 0.0f)) {
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
    half = 0.5f;
    two = 2.0f;
    one = 1.0f;
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
    direction.lane[0] = (effMiscRandFloat(0) - half) * two;
    direction.lane[1] = (effMiscRandFloat(0) - half) * two;
    direction.lane[2] = (effMiscRandFloat(0) - half) * two;
    effectVuLoad10(&direction);
    spawnVuNormalize10();
    effectVuStore10(&direction);
    ((MdlEffectMotionState *)state)->direction[0] = direction.lane[0];
    ((MdlEffectMotionState *)state)->direction[1] = direction.lane[1];
    ((MdlEffectMotionState *)state)->direction[2] = direction.lane[2];
    speedVariation = ((MdlEffectMotionParameters *)parameters)->speedVariation;
    b = effMiscRandFloat(0);
    ((MdlEffectMotionState *)state)->speed = fabsf(motion->speed * ((one - speedVariation) + speedVariation * b));
    spreadVariation = ((MdlEffectMotionParameters *)parameters)->spreadVariation;
    b = effMiscRandFloat(0);
    spreadVector.lane[0] = ((MdlEffectMotionParameters *)parameters)->spread * ((one - spreadVariation) + spreadVariation * b);
    spreadVector.lane[1] = spreadVector.lane[0];
    spreadVector.lane[2] = spreadVector.lane[0];
    effectVuLoad10(&direction);
    if (((MdlEffectMotionParameters *)parameters)->speed < zero) {
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10", "memory");
    }
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)"
            : : "r"(&spreadVector), "m"(*(const u8 (*)[sizeof(spreadVector)])&spreadVector)
            : "$vf11");
        spawnVuMultiply10();
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)"
            : : "r"(&spreadVector), "m"(*(const u8 (*)[sizeof(spreadVector)])&spreadVector)
            : "$vf11");
        spawnVuMultiply10();
        effectVuLoad11((const EffectVuVector *)parameters);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)particle);
    sizeVariation = ((MdlEffectEmitterParameters *)parameters)->sizeVariation;
    b = effMiscRandFloat(0);
    ((MdlEffectMotionState *)state)->sizeScale = (one - sizeVariation) + sizeVariation * b;
    if (angleMode != 2) {
        angleVariation = ((MdlEffectEmitterParameters *)parameters)->angleVariation;
        b = effMiscRandFloat(0);
        state[6] = (one - angleVariation) + angleVariation * b;
        if (angleMode == 1) {
            b = effMiscRandFloat(0);
            ((MdlEffectMotionState *)state)->angleOffset = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                ((MdlEffectMotionState *)state)->angleScale = ((MdlEffectMotionState *)state)->angleScale * negativeOne;
            }
        } else {
            ((MdlEffectMotionState *)state)->angleOffset = zero;
        }
    } else {
        ((MdlEffectMotionState *)state)->angleOffset = zero;
        ((MdlEffectMotionState *)state)->angleScale = one;
    }
    sampleParticle->age = 0;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)particle;
    }
    if (preroll != 0) {
        f32 prerollElapsed;
        f32 prerollDistance;
        f32 travelled;
        f32 accelerationDistance;
        f32 accelerationSquaredDistance;
        f32 gravityDistance;
        f32 gravitySquaredDistance;
        sample = (u32)effMiscRand(0) % (u32)lifetime;
        prerollElapsed = (f32)(u32)sample;
        effectVuLoad11((const EffectVuVector *)particle);
        travelled = ((MdlEffectMotionState *)state)->speed * prerollElapsed;
        accelerationDistance = acceleration * prerollElapsed;
        accelerationSquaredDistance = prerollElapsed * accelerationDistance;
        prerollDistance = travelled + half * accelerationSquaredDistance;
        if (prerollDistance < zero) {
            prerollDistance = zero;
        }
        direction.lane[0] = prerollDistance * ((MdlEffectMotionState *)state)->direction[0];
        direction.lane[1] = prerollDistance * ((MdlEffectMotionState *)state)->direction[1];
        direction.lane[2] = prerollDistance * ((MdlEffectMotionState *)state)->direction[2];
        gravityDistance = gravity * prerollElapsed;
        gravitySquaredDistance = prerollElapsed * gravityDistance;
        direction.lane[1] = direction.lane[1] - half * gravitySquaredDistance;
        effectVuLoad10(&direction);
        spawnVuAdd10();
        effectVuStore10((EffectVuVector *)particle);
        ((SpawnParticle *)particle)->age = (s32)prerollElapsed;
    }
    mdlEffectSampleKeyState(particle, parameters, sampleParticle->age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectMotionState *)state)->sizeScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectMotionState *)state)->angleScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectMotionState *)state)->angleOffset;
    if (preroll != 0) {
        trailLength = ((MdlEffectEmitterParameters *)(((MdlEffectEmitter *)emitter)->parameters))->trailCount.signedValue * ((MdlEffectEmitterParameters *)(((MdlEffectEmitter *)emitter)->parameters))->trailWidth;
        if (trailLength != 0) {
            particleIndex = ((u32)particle - (u32)((MdlEffectEmitter *)emitter)->particles) >> 5;
            trail = ((MdlEffectEmitter *)emitter)->particles + ((((MdlEffectEmitter *)emitter)->primaryCount.value + particleIndex * (u32)trailLength) << 5);
            memcpy(trail, particle, 32);
            ((SpawnParticle *)trail)->age = -1;
        }
        ((SpawnParticle *)particle)->age = ((SpawnParticle *)particle)->age + 1;
    }
    spawnBudget -= 1;
    goto next_iter2;
else_branch:
    {
    f32 liveDistance;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)particle;
    }
    effectVuLoad11((const EffectVuVector *)particle);
    liveDistance = ((MdlEffectMotionState *)state)->speed + acceleration * (f32)age;
    if (liveDistance < zero) {
        liveDistance = zero;
    }
    direction.lane[0] = liveDistance * ((MdlEffectMotionState *)state)->direction[0];
    direction.lane[1] = liveDistance * ((MdlEffectMotionState *)state)->direction[1];
    direction.lane[2] = liveDistance * ((MdlEffectMotionState *)state)->direction[2];
    direction.lane[1] = direction.lane[1] - gravity * (f32)age;
    effectVuLoad10(&direction);
    spawnVuAdd10();
    effectVuStore10((EffectVuVector *)particle);
    mdlEffectSampleKeyState(particle, parameters, age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectMotionState *)state)->sizeScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectMotionState *)state)->angleScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectMotionState *)state)->angleOffset;
    mdlEffectUpdateParticleTrail(emitter, particle);
    ((SpawnParticle *)particle)->age = age + 1;
    }
next_iter2:
next_iter:
    index += 1;
    state += 7;
    particle += 32;
main_check:
    if (index < count) {
        goto main_body;
    }
}


#pragma pop
