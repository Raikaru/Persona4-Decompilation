#include "btl_action_internal.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "particle_spawn_internal.h"
#include "effect_vu0_internal.h"
#include "sway_particle_internal.h"
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0049.c; members 00492100-00492100 */

#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Kind-11 Sway update. See docs/probe_archive/sway-update-20261005 for
 * the actual-provider domain, source measurements and independent review. */
// FUN_00492100
#include "sway_particle_internal.h"
/* measured: b210 -O2 needs independent value propagation and loop-invariant
 * constant materialization for the retail register and instruction schedule. */
#pragma push
/* measured: EffSwayParticleUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: EffSwayParticleUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void EffSwayParticleUpdate(u8 *arg0)
{
    extern void effMiscBuildRotationVU(void);
    extern f32 fabsf(f32 value);
    extern void mdlEffectSampleKeyState(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
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
    effMiscBuildRotationVU();
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
    mdlEffectSampleKeyState((u8 *)particle, (u8 *)parameters, particle->age, &previousPosition);
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
    mdlEffectSampleKeyState((u8 *)particle, (u8 *)parameters, age, &previousPosition);
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

