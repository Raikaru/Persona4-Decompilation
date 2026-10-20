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
extern void effMiscBuildRotationVU(void);
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
extern void mdlEffectUpdateOrbitEmitter(u8 *emitterData);
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
/* measured: with propagation and common-subexpression elimination on, retail's identity constants
 * merge and the scaled root copy is dropped; scoped settings keep them as separate values. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: these scoped settings keep retail's evaluation order for the wave update. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Shares its shape with the sibling orbit emitter; locals are declared in retail's float register
 * order and the loop constants are assigned after the preroll. */
#pragma push
/* measured: retail code generation for this function requires loop-invariant hoisting enabled here. */
#pragma opt_loop_invariants on
#pragma opt_propagation off
/* Emit a helical trajectory with changing radius, height and angular speed. */
// FUN_0048CDF0
void mdlEffectUpdateHelixEmitter(u8 *emitterData)
{
    extern f32 cosf(f32 emitterData);
    extern f32 sinf(f32 emitterData);
    extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    f32 direction[4] __attribute__((aligned(16)));
    f32 radiusVector[4] __attribute__((aligned(16)));
    f32 rotation[4] __attribute__((aligned(16)));
    u_long128 orientation;
    f32 position[4] __attribute__((aligned(16)));
    u_long128 origin;
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
    f32 a;
    f32 gravity;
    f32 angularAcceleration;
    f32 c;
    f32 one;
    f32 angleScale;
    f32 zero;
    f32 negativeOne;
    f32 half;
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
    f32 b;
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
    gravity = ((MdlEffectHelixParameters *)parameters)->gravity;
    angularAcceleration = ((MdlEffectHelixParameters *)parameters)->angularAcceleration;
    direction[3] = 0.0f;
    position[3] = 0.0f;
    radiusVector[3] = 0.0f;
    {
        u_long128 *capture;

        capture = &origin;
        /* lint: allow H009 -- retail copies this quad through $2, which the compiler will not do
         * from C. */
        __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(capture), "r"(parameters) : "$2", "memory");
        capture = &orientation;
        /* lint: allow H009 -- retail copies this quad through $2, which the compiler will not do
         * from C. */
        __asm__ volatile("lq $2, 16(%1)\n\tsq $2, 0(%0)" : : "r"(capture), "r"(parameters) : "$2", "memory");
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
    angleScale = fGpffff8080;
    zero = 0.0f;
    negativeOne = -1.0f;
    half = 0.5f;
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
    c = ((MdlEffectHelixParameters *)parameters)->radiusVariation;
    b = effMiscRandFloat(0);
    c = ((MdlEffectHelixParameters *)parameters)->radius * ((one - c) + c * b);
    a = ((MdlEffectHelixParameters *)parameters)->endRadiusVariation;
    b = effMiscRandFloat(0);
    scaledValue = ((MdlEffectHelixParameters *)parameters)->endRadius * ((one - a) + a * b);
    ((MdlEffectHelixState *)state)->radius = c;
    ((MdlEffectHelixState *)state)->radiusStep = (scaledValue - c) / (f32)lifetime;
    b = effMiscRandFloat(0);
    state[10] = angleScale * b;
    a = ((MdlEffectHelixParameters *)parameters)->angularSpeedVariation;
    b = effMiscRandFloat(0);
    ((MdlEffectHelixState *)state)->angularSpeed = ((MdlEffectHelixParameters *)parameters)->angularSpeed * ((one - a) + a * b);
    a = ((MdlEffectHelixParameters *)parameters)->speedVariation;
    b = effMiscRandFloat(0);
    ((MdlEffectHelixState *)state)->speed = ((MdlEffectHelixParameters *)parameters)->speed * ((one - a) + a * b);
    direction[0] = cosf(state[10]);
    direction[1] = zero;
    direction[2] = sinf(((MdlEffectHelixState *)state)->phase);
    b = effMiscRandFloat(0);
    ((MdlEffectHelixState *)state)->height = ((MdlEffectHelixParameters *)parameters)->heightRange * b;
    radiusVector[0] = c;
    radiusVector[1] = c;
    radiusVector[2] = c;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(direction), "m"(*(u_long128 *)direction) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(radiusVector), "m"(*(u_long128 *)radiusVector) : "$vf11", "memory");
    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile(
        "lw $2, 28(%0) \n"
        "nop \n"
        "qmtc2.ni $2, $vf2 \n"
        "vaddx.y $vf10, $vf0, $vf2x \n"
        : : "r"(state) : "$2", "$vf2", "$vf10", "memory");
    if ((flags & 1) == 0) {
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)position) : "r"(position) : "$vf10", "memory");
        ((MdlEffectHelixState *)state)->origin[0] = ((f32 *)&origin)[0];
        ((MdlEffectHelixState *)state)->origin[1] = ((f32 *)&origin)[1];
        ((MdlEffectHelixState *)state)->origin[2] = ((f32 *)&origin)[2];
        ((MdlEffectHelixState *)state)->orientation[0] = ((f32 *)&orientation)[0];
        ((MdlEffectHelixState *)state)->orientation[1] = ((f32 *)&orientation)[1];
        ((MdlEffectHelixState *)state)->orientation[2] = ((f32 *)&orientation)[2];
        ((MdlEffectHelixState *)state)->orientation[3] = ((f32 *)&orientation)[3];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&orientation), "m"(orientation) : "$vf10", "memory");
        effMiscBuildRotationVU();
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(position), "m"(*(u_long128 *)position) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&origin), "m"(origin) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)particle) : "r"(particle) : "$vf10", "memory");
    c = ((MdlEffectEmitterParameters *)parameters)->sizeVariation;
    b = effMiscRandFloat(0);
    ((MdlEffectHelixState *)state)->sizeScale = (one - c) + c * b;
    if (angleMode != 2) {
        c = ((MdlEffectEmitterParameters *)parameters)->angleVariation;
        b = effMiscRandFloat(0);
        state[15] = (one - c) + c * b;
        if (angleMode == 1) {
            b = effMiscRandFloat(0);
            ((MdlEffectHelixState *)state)->angleOffset = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                ((MdlEffectHelixState *)state)->angleScale = ((MdlEffectHelixState *)state)->angleScale * negativeOne;
            }
        } else {
            ((MdlEffectHelixState *)state)->angleOffset = zero;
        }
    } else {
        ((MdlEffectHelixState *)state)->angleOffset = zero;
        ((MdlEffectHelixState *)state)->angleScale = one;
    }
    sampleParticle->age = 0;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)particle;
    }
    if (preroll != 0) {
        sample = (u32)effMiscRand(0) % (u32)lifetime;
        c = (f32)(u32)sample;
        state[7] = state[7] + ((MdlEffectHelixState *)state)->speed * c;
        state[7] = state[7] - half * (c * (gravity * c));
        state[8] = state[8] + ((MdlEffectHelixState *)state)->radiusStep * c;
        position[0] = state[8] * cosf(state[10]);
        position[1] = ((MdlEffectHelixState *)state)->height;
        position[2] = ((MdlEffectHelixState *)state)->radius * sinf(((MdlEffectHelixState *)state)->phase);
        if ((flags & 1) == 0) {
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&orientation), "m"(orientation) : "$vf10", "memory");
            effMiscBuildRotationVU();
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(position), "m"(*(u_long128 *)position) : "$vf10", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&origin), "m"(origin) : "$vf11", "memory");
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        } else {
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(position), "m"(*(u_long128 *)position) : "$vf10", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)particle) : "r"(particle) : "$vf10", "memory");
        ((SpawnParticle *)particle)->age = (s32)c;
    }
    mdlEffectSampleKeyState(particle, parameters, sampleParticle->age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectHelixState *)state)->sizeScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectHelixState *)state)->angleScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectHelixState *)state)->angleOffset;
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
    c = scaledValue * (((MdlEffectHelixState *)state)->angularSpeed + half * (angularAcceleration * scaledValue));
    c = c + ((MdlEffectHelixState *)state)->phase;
    state[7] = state[7] + ((MdlEffectHelixState *)state)->speed;
    state[7] = state[7] - gravity * scaledValue;
    state[8] = state[8] + ((MdlEffectHelixState *)state)->radiusStep;
    position[0] = state[8] * cosf(c);
    position[1] = ((MdlEffectHelixState *)state)->height;
    position[2] = ((MdlEffectHelixState *)state)->radius * sinf(c);
    if ((flags & 1) == 0) {
        rotation[0] = ((MdlEffectHelixState *)state)->orientation[0];
        rotation[1] = ((MdlEffectHelixState *)state)->orientation[1];
        rotation[2] = ((MdlEffectHelixState *)state)->orientation[2];
        rotation[3] = ((MdlEffectHelixState *)state)->orientation[3];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(rotation), "m"(*(u_long128 *)rotation) : "$vf10", "memory");
        effMiscBuildRotationVU();
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(position), "m"(*(u_long128 *)position) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)position) : "r"(position) : "$vf10", "memory");
        position[0] = position[0] + ((MdlEffectHelixState *)state)->origin[0];
        position[1] = position[1] + ((MdlEffectHelixState *)state)->origin[1];
        position[2] = position[2] + ((MdlEffectHelixState *)state)->origin[2];
    }
    ((SpawnParticle *)particle)->position.lane[0] = position[0];
    ((SpawnParticle *)particle)->position.lane[1] = position[1];
    ((SpawnParticle *)particle)->position.lane[2] = position[2];
    mdlEffectSampleKeyState(particle, parameters, age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * ((MdlEffectHelixState *)state)->sizeScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * ((MdlEffectHelixState *)state)->angleScale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + ((MdlEffectHelixState *)state)->angleOffset;
    mdlEffectUpdateParticleTrail(emitter, particle);
    ((SpawnParticle *)particle)->age = age + 1;
next_iter2:
next_iter:
    index += 1;
    state += 16;
    particle += 32;
main_check:
    if (index < count) {
        goto main_body;
    }
}


#pragma pop
