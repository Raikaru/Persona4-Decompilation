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
extern void mdlEffectCommitTreeFrame(u8 *effect);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 0048d8c0-0048d8c0 */

extern f32 mdlEffectSampleScalarKeys(u8 *keys, s32 frame, s32 duration);
extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
extern void EffMotionEmitterUpdate(u8 *emitterData);
/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-state; the current C callers discard it. The four hardware vf0 stores
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
 * index, `angleMode != 2` first, snapshot pointer, stack vectors declared from
 * the highest frame slot down, and the parameters quads copied through $2.
 * The loop constants are assigned after the preroll in retail's hoist order.
 * b210 colours the saved FPRs from the highest-numbered local down, each
 * taking the lowest free register, and numbers locals by declaration: so
 * `a` (retail $f28) is declared first, then eF0val, eECval, `c` ($f25,
 * which also carries the preroll sample and the else-branch angle), and the
 * constants one..half ($f24-$f20). */
#pragma push
#pragma pop
/* Taken from the matched sibling EffMotionEmitterUpdate: the loop constants are
 * locals assigned after the preroll in retail's hoist order (one, orbit,
 * zero, half, two, tilt, angle, -1) and declared in its FPR order. `c`
 * carries the first, fifth and sixth scale (retail $f30) and `a` the second
 * and third ($f31). The 0x140 vector exists only for its retail w=0 store.
 * The parameters[0] snapshot at 0x0048D96C is an lq/sq that names $2, as in
 * func_00485630; the $2 def also frees $v0 for retail's emissionDuration/angleMode
 * spill stores. */
#pragma push
/* measured: func_0048d8c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_0048d8c0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Emit tilted orbit particles, evolving radius and angular speed while applying gravity. */
// FUN_0048D8C0
void mdlEffectUpdateOrbitEmitter(u8 *emitterData)
{
    extern f32 cosf(f32 emitterData);
    extern f32 sinf(f32 emitterData);
    extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
    extern void effMiscRotateXVU(f32 angle);
    extern void effMiscRotateYVU(f32 angle);
    extern void effMiscCombineRotationVU(void);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff8094;
    f32 orbitPosition[4] __attribute__((aligned(16)));
    f32 unusedVector[4] __attribute__((aligned(16)));
    f32 position[4] __attribute__((aligned(16)));
    u_long128 origin;
    u_long128 previousPosition;
    u32 count;
    u32 flags;
    u8 *particle;
    /* measured: tiltX, tiltY, radius, phase, angleScale retain array addressing for MATCH. */
    f32 *state;
    u8 *parameters;
    u8 *const emitter = emitterData;
    s32 lifetime;
    s32 emissionDuration;
    u8 angleMode;
    f32 gravity;
    f32 angularAcceleration;
    f32 one;
    f32 orbitScale;
    f32 zero;
    f32 half;
    f32 two;
    f32 tiltScale;
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
    f32 a;
    f32 b;
    f32 c;
    MdlEffectEmitterParameters *settings;
    SpawnParticle *sampleParticle;
    count = ((MdlEffectEmitter *)emitter)->primaryCount.value;
    flags = ((MdlEffectEmitter *)emitter)->flags;
    particle = ((MdlEffectEmitter *)emitter)->particles;
    state = ((MdlEffectEmitter *)emitter)->state.scalars;
    parameters = ((MdlEffectEmitter *)emitter)->parameters;
    settings = (MdlEffectEmitterParameters *)parameters;
    lifetime = ((MdlEffectEmitterParameters *)parameters)->lifetime;
    if (lifetime == 0) {
        return;
    }
    emissionDuration = ((MdlEffectEmitterParameters *)parameters)->emissionDuration;
    angleMode = ((MdlEffectEmitterParameters *)parameters)->angleMode;
    gravity = ((MdlEffectOrbitParameters *)parameters)->gravity;
    angularAcceleration = ((MdlEffectOrbitParameters *)parameters)->angularAcceleration;
    orbitPosition[3] = 0.0f;
    position[3] = 0.0f;
    unusedVector[3] = 0.0f;
    {
        u_long128 *const capture = &origin;
        /* lint: allow H009 -- retail copies this quad through $2 at 0x0048D96C, freeing $v0 for the spill stores (user-approved 2026-10-09) */
        __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(capture), "r"(parameters) : "$2", "memory");
    }
    if ((emissionDuration != 0) && (((MdlEffectEmitter *)emitter)->ticks >= emissionDuration)) {
        preroll = 0;
        spawnBudget = 0;
        goto post_init;
    }
    if ((((MdlEffectEmitter *)emitter)->ticks == 0) && (((MdlEffectEmitterParameters *)parameters)->preroll != 0)) {
        initialPreroll = 1;
        preroll = initialPreroll;
        if (!(settings->emissionVariation <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - ((MdlEffectEmitterParameters *)parameters)->emissionVariation) * effMiscRandFloat(0);
            sampleValue = (f32)((MdlEffectEmitter *)emitter)->primaryCount.value;
            spawnBudget = (s32)(sampleValue * prerollScale);
        } else {
            spawnBudget = ((MdlEffectEmitter *)emitter)->primaryCount.signedValue;
        }
        goto post_init;
    } else {
        preroll = 0;
        if (!(settings->emissionVariation <= 0.0f)) {
            f32 scale = (fGpffff807c - ((MdlEffectEmitterParameters *)parameters)->emissionVariation) * effMiscRandFloat(0);
            sample = ((MdlEffectEmitterParameters *)parameters)->emissionRate.signedValue;
            sampleValue = (f32)(u32)sample;
            ((MdlEffectEmitter *)emitter)->emissionAccumulator = ((MdlEffectEmitter *)emitter)->emissionAccumulator + sampleValue * scale;
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
    orbitScale = fGpffff8094;
    zero = 0.0f;
    half = 0.5f;
    two = 2.0f;
    tiltScale = fGpffff8084;
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
    c = ((MdlEffectOrbitParameters *)parameters)->radiusVariation;
    b = effMiscRandFloat(0);
    c = ((MdlEffectOrbitParameters *)parameters)->radius * ((one - c) + c * b);
    a = ((MdlEffectOrbitParameters *)parameters)->endRadiusVariation;
    b = effMiscRandFloat(0);
    scaledValue = ((MdlEffectOrbitParameters *)parameters)->endRadius * ((one - a) + a * b);
    ((MdlEffectOrbitState *)state)->radius = c;
    ((MdlEffectOrbitState *)state)->radiusStep = (scaledValue - c) / (f32)lifetime;
    a = ((MdlEffectOrbitParameters *)parameters)->angularSpeedVariation;
    b = effMiscRandFloat(0);
    ((MdlEffectOrbitState *)state)->angularSpeed = ((MdlEffectOrbitParameters *)parameters)->angularSpeed * ((one - a) + a * b);
    b = effMiscRandFloat(0);
    state[8] = orbitScale * b;
    ((MdlEffectOrbitState *)state)->height = zero;
    b = effMiscRandFloat(0);
    state[3] = tiltScale * (two * (b - half));
    b = effMiscRandFloat(0);
    state[4] = tiltScale * (two * (b - half));
    effMiscRotateXVU(((MdlEffectOrbitState *)state)->tiltX);
    effMiscRotateYVU(((MdlEffectOrbitState *)state)->tiltY);
    effMiscCombineRotationVU();
    orbitPosition[0] = c * cosf(state[8]);
    orbitPosition[1] = zero;
    orbitPosition[2] = c * sinf(((MdlEffectOrbitState *)state)->phase);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(orbitPosition), "m"(*(u_long128 *)orbitPosition) : "$vf10", "memory");
    __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
    if ((flags & 1) == 0) {
        ((MdlEffectOrbitState *)state)->origin[0] = ((f32 *)&origin)[0];
        ((MdlEffectOrbitState *)state)->origin[1] = ((f32 *)&origin)[1];
        ((MdlEffectOrbitState *)state)->origin[2] = ((f32 *)&origin)[2];
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&origin), "m"(origin) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)particle) : "r"(particle) : "$vf10", "memory");
    c = ((MdlEffectEmitterParameters *)parameters)->sizeVariation;
    b = effMiscRandFloat(0);
    ((MdlEffectOrbitState *)state)->sizeScale = (one - c) + c * b;
    if (angleMode != 2) {
        c = ((MdlEffectEmitterParameters *)parameters)->angleVariation;
        b = effMiscRandFloat(0);
        state[12] = (one - c) + c * b;
        if (angleMode == 1) {
            b = effMiscRandFloat(0);
            ((MdlEffectOrbitState *)state)->angleOffset = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                ((MdlEffectOrbitState *)state)->angleScale = ((MdlEffectOrbitState *)state)->angleScale * negativeOne;
            }
        } else {
            ((MdlEffectOrbitState *)state)->angleOffset = zero;
        }
    } else {
        ((MdlEffectOrbitState *)state)->angleOffset = zero;
        ((MdlEffectOrbitState *)state)->angleScale = one;
    }
    sampleParticle->age = 0;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)particle;
    }
    if (preroll != 0) {
        sample = (u32)effMiscRand(0) % (u32)lifetime;
        scaledValue = (f32)(u32)sample;
        ((MdlEffectOrbitState *)state)->height = ((MdlEffectOrbitState *)state)->height - half * (scaledValue * (gravity * scaledValue));
        c = ((MdlEffectOrbitState *)state)->radius + ((MdlEffectOrbitState *)state)->radiusStep * scaledValue;
        ((MdlEffectOrbitState *)state)->radius = c;
        orbitPosition[0] = c * cosf(state[8]);
        orbitPosition[1] = zero;
        orbitPosition[2] = c * sinf(((MdlEffectOrbitState *)state)->phase);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(orbitPosition), "m"(*(u_long128 *)orbitPosition) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        if ((flags & 1) == 0) {
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf10", "$vf11", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&origin), "m"(origin) : "$vf10", "memory");
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)particle) : "r"(particle) : "$vf10", "memory");
        ((SpawnParticle *)particle)->position.lane[1] = ((SpawnParticle *)particle)->position.lane[1] + ((MdlEffectOrbitState *)state)->height;
        ((SpawnParticle *)particle)->age = (s32)scaledValue;
    }
    mdlEffectSampleKeyState(particle, parameters, sampleParticle->age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectOrbitState *)state)->sizeScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectOrbitState *)state)->angleScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectOrbitState *)state)->angleOffset;
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
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)particle;
    }
    scaledValue = (f32)age;
    sampleValue = scaledValue * (((MdlEffectOrbitState *)state)->angularSpeed + half * (angularAcceleration * scaledValue));
    sampleValue = sampleValue + ((MdlEffectOrbitState *)state)->phase;
    ((MdlEffectOrbitState *)state)->height = ((MdlEffectOrbitState *)state)->height - gravity * scaledValue;
    state[5] = state[5] + ((MdlEffectOrbitState *)state)->radiusStep;
    effMiscRotateXVU(((MdlEffectOrbitState *)state)->tiltX);
    effMiscRotateYVU(((MdlEffectOrbitState *)state)->tiltY);
    effMiscCombineRotationVU();
    c = ((MdlEffectOrbitState *)state)->radius;
    orbitPosition[0] = c * cosf(sampleValue);
    orbitPosition[1] = zero;
    orbitPosition[2] = c * sinf(sampleValue);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(orbitPosition), "m"(*(u_long128 *)orbitPosition) : "$vf10", "memory");
    __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)position) : "r"(position) : "$vf10", "memory");
    if ((flags & 1) == 0) {
        position[0] = position[0] + ((MdlEffectOrbitState *)state)->origin[0];
        position[1] = position[1] + ((MdlEffectOrbitState *)state)->origin[1];
        position[2] = position[2] + ((MdlEffectOrbitState *)state)->origin[2];
    }
    ((SpawnParticle *)particle)->position.lane[0] = position[0];
    ((SpawnParticle *)particle)->position.lane[1] = position[1] + ((MdlEffectOrbitState *)state)->height;
    ((SpawnParticle *)particle)->position.lane[2] = position[2];
    mdlEffectSampleKeyState(particle, parameters, age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectOrbitState *)state)->sizeScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectOrbitState *)state)->angleScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectOrbitState *)state)->angleOffset;
    mdlEffectUpdateParticleTrail(emitter, particle);
    ((SpawnParticle *)particle)->age = age + 1;
next_iter2:
next_iter:
    index += 1;
    state += 13;
    particle += 32;
main_check:
    if (index < count) {
        goto main_body;
    }
}



#pragma pop
