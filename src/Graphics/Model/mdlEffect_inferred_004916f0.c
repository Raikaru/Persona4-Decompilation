#include "member_access.h"
#include "mdl_effect_drawable_internal.h"
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
    u8 trailCount;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_0049Color;
extern Code1_0049Color iGpffffbb64;


/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0049; members 004916f0-004916f0 */

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
 * a named u32 multiplied by trailSpan; and `burst = 1` goes through a u8 local
 * (with opt_propagation off the only spelling that gives `daddiu`). The
 * pragmas are measured: opt_lifetimes off leaves 25 edits (dot is spilled),
 * opt_loop_invariants is what hoists the constant block retail loads before
 * the particle loop, and opt_propagation off keeps the u8 copy. */
#pragma push
#pragma pop
/* Swirl emitter update, ported from the d8c0/c4e0 particle family: three
 * stack vectors with retail's w=0 stores, the captured origin quad, loop
 * constants in hoist order, u8 preroll flag and snapshot pointer. The spawn
 * angle forms (angleRange * a) * b as one named product before the half-weighted
 * remainder; the radius pairs are both formed before the first is stored. */
#pragma push
/* measured: func_004916f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_004916f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Spawn and advance orbiting particles, including preroll, key sampling and trail snapshots. */
/* measured: baseline removal and a structured primary loop still differ (best isolated nd 1235 bytes); retain both toggles. */
// FUN_004916F0
void mdlEffectUpdateSwirlEmitter(u8 *emitterBytes)
{
    MdlEffectEmitter *emitterCounts;
    MdlEffectSwirlParameters *prerollParameters;
    MdlEffectSwirlParameters *emissionParameters;
    SpawnParticle *activeParticle;
    SpawnParticle *resetParticle;
    SpawnParticle *sampledParticle;

    extern void effMiscBuildRotationVU(void);
    extern f32 cosf(f32 emitterBytes);
    extern f32 sinf(f32 emitterBytes);
    extern f32 fabsf(f32 emitterBytes);
    extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    f32 spawnPosition[4] __attribute__((aligned(16)));
    f32 motionVector[4] __attribute__((aligned(16)));
    f32 updatedPosition[4] __attribute__((aligned(16)));
    u_long128 origin;
    u_long128 previousPosition;
    u32 count;
    u32 flags;
    u8 *nodes;
    f32 *state;
    u8 *config;
    u8 *const parent = emitterBytes;
    s32 lifetime;
    s32 emissionDuration;
    u8 angleMode;
    f32 variation;
    f32 gravity;
    f32 angularAcceleration;
    f32 angle;
    f32 angleRange;
    f32 one;
    f32 half;
    f32 phaseRange;
    f32 reverseAngle;
    f32 zero;
    s32 spawnBudget;
    s32 preroll;
    u8 initialPreroll;
    u32 index;
    s32 countValue;
    f32 firstValue;
    f32 secondValue;
    s32 age;
    s32 trailCount;
    s32 trailWidth;
    s32 trailSpan;
    u8 *clear;
    s32 trailIndex;
    u32 particleIndex;
    f32 randomSample;
    f32 trigValue;

    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    count = (emitterCounts = (MdlEffectEmitter *)parent)->primaryCount.value;
    flags = ((MdlEffectEmitter *)parent)->flags;
    nodes = ((MdlEffectEmitter *)parent)->particles;
    state = ((MdlEffectEmitter *)parent)->state.scalars;
    config = ((MdlEffectEmitter *)parent)->parameters;
    lifetime = ((MdlEffectSwirlParameters *)config)->common.lifetime;
    if (lifetime == 0) {
        return;
    }
    emissionDuration = ((MdlEffectSwirlParameters *)config)->common.emissionDuration;
    angleMode = ((MdlEffectSwirlParameters *)config)->common.angleMode;
    gravity = ((MdlEffectSwirlParameters *)config)->gravity;
    angularAcceleration = ((MdlEffectSwirlParameters *)config)->angularAcceleration;
    spawnPosition[3] = 0.0f;
    updatedPosition[3] = 0.0f;
    motionVector[3] = 0.0f;
    {
        u_long128 *const capture = &origin;
        /* The complete 16-byte VU position copy retains its quadword storage representation. */
        *capture = *(u_long128 *)&((MdlEffectSwirlParameters *)config)->common.position;
    }
    effectVuLoad10((const EffectVuVector *)(config + 16));
    effMiscBuildRotationVU();
    if ((emissionDuration != 0) && (((MdlEffectEmitter *)parent)->ticks >= emissionDuration)) {
        preroll = 0;
        spawnBudget = 0;
        goto post_init;
    }
    if ((((MdlEffectEmitter *)parent)->ticks == 0) && (((MdlEffectSwirlParameters *)config)->common.preroll != 0)) {
        initialPreroll = 1;
        preroll = initialPreroll;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        if (!((prerollParameters = (MdlEffectSwirlParameters *)config)->common.emissionVariation <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - ((MdlEffectSwirlParameters *)config)->common.emissionVariation) * effMiscRandFloat(0);
            secondValue = (f32)((MdlEffectEmitter *)parent)->primaryCount.value;
            spawnBudget = (s32)(secondValue * prerollScale);
        } else {
            spawnBudget = (s32)((MdlEffectEmitter *)parent)->primaryCount.signedValue;
        }
        goto post_init;
    } else {
        preroll = 0;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        if (!((emissionParameters = (MdlEffectSwirlParameters *)config)->common.emissionVariation <= 0.0f)) {
            f32 scale = (fGpffff807c - ((MdlEffectSwirlParameters *)config)->common.emissionVariation) * effMiscRandFloat(0);
            countValue = ((MdlEffectSwirlParameters *)config)->common.emissionRate.signedValue;
            secondValue = (f32)(u32)countValue;
            ((MdlEffectEmitter *)parent)->emissionAccumulator = ((MdlEffectEmitter *)parent)->emissionAccumulator + secondValue * scale;
        } else {
            countValue = ((MdlEffectSwirlParameters *)config)->common.emissionRate.signedValue;
            firstValue = (f32)(u32)countValue;
            ((MdlEffectEmitter *)parent)->emissionAccumulator = ((MdlEffectEmitter *)parent)->emissionAccumulator + firstValue;
        }
        firstValue = ((MdlEffectEmitter *)parent)->emissionAccumulator;
        firstValue = fabsf(firstValue);
        spawnBudget = (s32)firstValue;
        ((MdlEffectEmitter *)parent)->emissionAccumulator = ((MdlEffectEmitter *)parent)->emissionAccumulator - (f32)spawnBudget;
        goto post_init;
    }
post_init:
    index = 0;
    angleRange = fGpffff8084;
    one = 1.0f;
    half = 0.5f;
    phaseRange = fGpffff8080;
    reverseAngle = -1.0f;
    zero = 0.0f;
    goto main_check;
main_body:
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    if ((activeParticle = (SpawnParticle *)nodes)->age < lifetime) {
        goto skip_clear;
    }
    if (emissionDuration != 0) {
        countValue = -2;
    } else {
        countValue = -1;
    }
    ((SpawnParticle *)nodes)->age = countValue;
    trailCount = ((MdlEffectSwirlParameters *)((MdlEffectEmitter *)parent)->parameters)->common.trailCount.signedValue;
    trailWidth = ((MdlEffectSwirlParameters *)((MdlEffectEmitter *)parent)->parameters)->common.trailWidth;
    trailSpan = trailCount * trailWidth;
    if (trailSpan != 0) {
        particleIndex = ((u32)nodes - (u32)((MdlEffectEmitter *)parent)->particles) >> 5;
        clear = ((MdlEffectEmitter *)parent)->particles + ((((MdlEffectEmitter *)parent)->primaryCount.value + particleIndex * (u32)trailSpan) << 5);
        trailIndex = 0;
        goto clear_check;
clear_body:
        ((SpawnParticle *)clear)->age = -1;
        clear += 32;
        trailIndex += 1;
clear_check:
        if (trailIndex < trailSpan) {
            goto clear_body;
        }
    }
skip_clear:
    age = ((SpawnParticle *)nodes)->age;
    if (age == -2) {
        goto next_iter;
    }
    if (age != -1) {
        goto else_branch;
    }
    if (spawnBudget == 0) {
        goto next_iter;
    }
    angle = ((MdlEffectSwirlParameters *)config)->angleSpan;
    randomSample = effMiscRandFloat(0);
    firstValue = angleRange * angle;
    firstValue = firstValue * randomSample;
    angle = firstValue + half * (angleRange * (one - angle));
    trigValue = sinf(angle);
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    firstValue = MEMBER(f32, config, MdlEffectSwirlParameters, startRadius) * trigValue;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    secondValue = MEMBER(f32, config, MdlEffectSwirlParameters, endRadius) * trigValue;
    state[0] = firstValue;
    state[1] = (secondValue - firstValue) / (f32)lifetime;
    if ((((MdlEffectSwirlParameters *)config)->alternateDirection == 0) || ((index & 1) != 0)) {
        variation = ((MdlEffectSwirlParameters *)config)->angularVariation;
        randomSample = effMiscRandFloat(0);
        state[2] = ((MdlEffectSwirlParameters *)config)->angularSpeed * ((one - variation) + variation * randomSample);
    } else {
        variation = ((MdlEffectSwirlParameters *)config)->angularVariation;
        randomSample = effMiscRandFloat(0);
        firstValue = (one - variation) + variation * randomSample;
        state[2] = -((MdlEffectSwirlParameters *)config)->angularSpeed * firstValue;
    }
    randomSample = effMiscRandFloat(0);
    state[3] = phaseRange * randomSample;
    trigValue = cosf(angle);
    firstValue = ((MdlEffectSwirlParameters *)config)->startRadius * trigValue;
    secondValue = ((MdlEffectSwirlParameters *)config)->endRadius * trigValue;
    state[4] = firstValue;
    state[5] = (secondValue - firstValue) / (f32)lifetime;
    angle = state[0];
    spawnPosition[0] = angle * cosf(state[3]);
    spawnPosition[1] = state[4];
    spawnPosition[2] = angle * sinf(state[3]);
    effectVuLoad10((const EffectVuVector *)spawnPosition);
    if ((flags & 1) == 0) {
        spawnVuTransform10();
        effectVuLoad11((const EffectVuVector *)&origin);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)nodes);
    angle = ((MdlEffectSwirlParameters *)config)->common.sizeVariation;
    randomSample = effMiscRandFloat(0);
    state[6] = (one - angle) + angle * randomSample;
    if (angleMode != 2) {
        angle = ((MdlEffectSwirlParameters *)config)->common.angleVariation;
        randomSample = effMiscRandFloat(0);
        state[8] = (one - angle) + angle * randomSample;
        if (angleMode == 1) {
            randomSample = effMiscRandFloat(0);
            state[7] = phaseRange * randomSample;
            if ((effMiscRand(0) & 1) != 0) {
                state[8] = state[8] * reverseAngle;
            }
        } else {
            state[7] = zero;
        }
    } else {
        state[7] = zero;
        state[8] = one;
    }
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    (resetParticle = (SpawnParticle *)nodes)->age = 0;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)nodes;
    }
    if (preroll != 0) {
        countValue = (u32)effMiscRand(0) % (u32)lifetime;
        angle = (f32)(u32)countValue;
        state[4] = state[4] - half * (angle * (gravity * angle));
        variation = state[0] + state[1] * angle;
        state[0] = variation;
        spawnPosition[0] = variation * cosf(state[3]);
        spawnPosition[1] = state[4];
        spawnPosition[2] = variation * sinf(state[3]);
        effectVuLoad10((const EffectVuVector *)spawnPosition);
        if ((flags & 1) == 0) {
            spawnVuTransform10();
            effectVuLoad11((const EffectVuVector *)&origin);
            spawnVuAdd10();
        }
        effectVuStore10((EffectVuVector *)nodes);
        ((SpawnParticle *)nodes)->age = (s32)angle;
    }
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    mdlEffectSampleKeyState(nodes, config, (sampledParticle = (SpawnParticle *)nodes)->age, &previousPosition);
    ((SpawnParticle *)nodes)->size = ((SpawnParticle *)nodes)->size * state[6];
    ((SpawnParticle *)nodes)->angle = ((SpawnParticle *)nodes)->angle * state[8];
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    MEMBER(f32, nodes, SpawnParticle, angle) = MEMBER(f32, nodes, SpawnParticle, angle) + state[7];
    if (preroll != 0) {
        trailSpan = ((MdlEffectSwirlParameters *)((MdlEffectEmitter *)parent)->parameters)->common.trailCount.signedValue * ((MdlEffectSwirlParameters *)((MdlEffectEmitter *)parent)->parameters)->common.trailWidth;
        if (trailSpan != 0) {
            particleIndex = ((u32)nodes - (u32)((MdlEffectEmitter *)parent)->particles) >> 5;
            clear = ((MdlEffectEmitter *)parent)->particles + ((((MdlEffectEmitter *)parent)->primaryCount.value + particleIndex * (u32)trailSpan) << 5);
            memcpy(clear, nodes, 32);
            ((SpawnParticle *)clear)->age = -1;
        }
        ((SpawnParticle *)nodes)->age = ((SpawnParticle *)nodes)->age + 1;
    }
    spawnBudget -= 1;
    goto next_iter2;
else_branch:
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)nodes;
    }
    firstValue = (f32)age;
    if ((((MdlEffectSwirlParameters *)config)->alternateDirection == 0) || ((index & 1) != 0)) {
        angle = firstValue * (state[2] + half * (angularAcceleration * firstValue));
    } else {
        angle = firstValue * (state[2] - half * (angularAcceleration * firstValue));
    }
    angle = angle + state[3];
    state[4] = state[4] - gravity * firstValue;
    state[0] = state[0] + state[1];
    state[4] = state[4] + state[5];
    variation = state[0];
    updatedPosition[0] = variation * cosf(angle);
    updatedPosition[1] = state[4];
    updatedPosition[2] = variation * sinf(angle);
    effectVuLoad10((const EffectVuVector *)updatedPosition);
    if ((flags & 1) == 0) {
        spawnVuTransform10();
        effectVuLoad11((const EffectVuVector *)&origin);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)nodes);
    mdlEffectSampleKeyState(nodes, config, age, &previousPosition);
    ((SpawnParticle *)nodes)->size = ((SpawnParticle *)nodes)->size * state[6];
    ((SpawnParticle *)nodes)->angle = ((SpawnParticle *)nodes)->angle * state[8];
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    ((SpawnParticle *)nodes)->angle = ((SpawnParticle *)nodes)->angle + state[7];
    mdlEffectUpdateParticleTrail(parent, nodes);
    ((SpawnParticle *)nodes)->age = age + 1;
next_iter2:
next_iter:
    index += 1;
    state += 9;
    nodes += 32;
main_check:
    if (index < count) {
        goto main_body;
    }
}
#pragma pop
