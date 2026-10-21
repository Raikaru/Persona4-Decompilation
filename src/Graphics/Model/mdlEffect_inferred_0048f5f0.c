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

extern f32 mdlEffectSampleScalarKeys(u8 *keys, s32 frame, s32 duration);
extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
extern void EffMotionEmitterUpdate(u8 *emitterData);
extern void mdlEffectUpdateOrbitEmitter(u8 *emitterData);
extern void EffConeAngleEmitterUpdate(u8 *emitterData);
/* measured: retail leaves the copied quadword in the return register; the four hardware-zero vector
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
#pragma push
/* measured: keeps the two counters as separate variables, as retail does. */
#pragma pop
/* measured: these settings keep retail's evaluation order in the wave update. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Same shape as sibling func_0048d8c0: loop constants are assigned after the preroll in retail's
 * hoist order, and locals are declared in retail's register order. */
#pragma push
#pragma pop
/* Same shape as sibling EffMotionEmitterUpdate; the 0x140 vector exists only for its retail w=0
 * store. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Bezier emitter update. The 76-byte work record separates control points, offsets and scalar
 * state; its length union keeps the hardware-Q bits. */
#pragma push
/* measured: EffBezierEmitterUpdate only matches retail with copy propagation disabled. */
#pragma opt_propagation off
/* measured: retail code for this function needs loop-invariant hoisting on. */
#pragma opt_loop_invariants on
// FUN_0048F5F0
void EffBezierEmitterUpdate(u8 *emitterData)
{
    typedef struct BezierParticleWork {
        f32 control0[3];
        f32 control1[3];
        f32 control2[3];
        f32 offset[3];
        f32 rotationSpeed;
        f32 travelSpeed;
        union { s32 bits; f32 value; } length;
        f32 progress;
        f32 opacity;
        f32 spin;
        f32 scale;
    } BezierParticleWork;
    extern f32 cosf(f32 emitterData);
    extern f32 sinf(f32 emitterData);
    extern void effMiscAxisAngleVU(void *axis, f32 angle);
    extern void mdlEffectSampleKeyState(u8 *particle, u8 *parameters, s32 frame, u_long128 *previousPosition);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void mdlEffectUpdateParticleTrail(u8 *emitter, u8 *particle);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff8090;
    extern u8 D_00713D00[];
    f32 endPosition[4] __attribute__((aligned(16)));
    u8 axis[16] __attribute__((aligned(16)));
    u_long128 previousPosition;
    f32 startPosition[4] __attribute__((aligned(16)));
    f32 controlVector[4] __attribute__((aligned(16)));
    u8 perpendicular[16] __attribute__((aligned(16)));
    f32 direction[4] __attribute__((aligned(16)));
    f32 secondBlend[4] __attribute__((aligned(16)));
    f32 firstBlend[4] __attribute__((aligned(16)));
    f32 prerollWeights[4] __attribute__((aligned(16)));
    f32 prerollPosition[4] __attribute__((aligned(16)));
    f32 weights[4] __attribute__((aligned(16)));
    f32 position[4] __attribute__((aligned(16)));
    f32 scaledValue;
    f32 travelAcceleration;
    f32 rotationAcceleration;
    f32 angle;
    f32 half, two, orbitScale, hundred, degreeScale, one, zero, spinScale, negativeOne, thousand, three;
    f32 progress;
    f32 inverseProgress;
    f32 inverseSquared;
    f32 inverseCubed;
    f32 progressInverseSquared;
    f32 firstWeight;
    f32 progressSquared;
    f32 inverseProgressSquared;
    f32 secondWeight;
    f32 progressCubed;
    f32 firstControlX;
    f32 firstControlY;
    f32 firstControlZ;
    f32 secondControlX;
    f32 secondControlY;
    f32 secondControlZ;
    f32 originX;
    f32 originY;
    f32 originZ;
    f32 elapsed;
    f32 travelDistance;
    f32 spinDistance;
    u32 count;
    u8 *particle;
    BezierParticleWork *state;
    u8 *parameters;
    u8 *const emitter = emitterData;
    s32 lifetime;
    s32 emissionDuration;
    u8 angleMode;
    s32 spawnBudget;
    s32 preroll;
    u8 initialPreroll;
    u32 index;
    s32 sample;
    s32 lengthBits;
    f32 sampleValue;
    f32 rotationDistance;
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
    f32 d;
    MdlEffectEmitter *work;
    MdlEffectBezierParameters *bezier;
    SpawnParticle *sampleParticle;
    work = (MdlEffectEmitter *)emitter;
    count = work->primaryCount.value;
    particle = ((MdlEffectEmitter *)emitter)->particles;
    state = (BezierParticleWork *)((MdlEffectEmitter *)emitter)->state.pointer;
    parameters = ((MdlEffectEmitter *)emitter)->parameters;
    bezier = (MdlEffectBezierParameters *)parameters;
    lifetime = ((MdlEffectEmitterParameters *)parameters)->lifetime;
    if (lifetime == 0) {
        return;
    }
    emissionDuration = ((MdlEffectEmitterParameters *)parameters)->emissionDuration;
    angleMode = ((MdlEffectEmitterParameters *)parameters)->angleMode;
    rotationAcceleration = ((MdlEffectBezierParameters *)parameters)->rotationAcceleration;
    travelAcceleration = ((MdlEffectBezierParameters *)parameters)->travelAcceleration;
    startPosition[0] = ((MdlEffectBezierParameters *)parameters)->start[0];
    startPosition[1] = ((MdlEffectBezierParameters *)parameters)->start[1];
    startPosition[2] = ((MdlEffectBezierParameters *)parameters)->start[2];
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(parameters), "m"(*(u_long128 *)bezier->common.rotation) : "$vf10", "memory"); /* Transfer the complete quadword representation, including the VU W lane. */
    effMiscBuildRotationVU();
    if ((emissionDuration != 0) && (((MdlEffectEmitter *)emitter)->ticks >= emissionDuration)) {
        preroll = 0;
        spawnBudget = 0;
        goto post_init;
    }
    if ((((MdlEffectEmitter *)emitter)->ticks == 0) && (((MdlEffectEmitterParameters *)parameters)->preroll != 0)) {
        initialPreroll = 1;
        preroll = initialPreroll;
        if (!(bezier->common.emissionVariation <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - ((MdlEffectEmitterParameters *)parameters)->emissionVariation) * effMiscRandFloat(0);
            sampleValue = (f32)((MdlEffectEmitter *)emitter)->primaryCount.value;
            spawnBudget = (s32)(sampleValue * prerollScale);
        } else {
            spawnBudget = ((MdlEffectEmitter *)emitter)->primaryCount.signedValue;
        }
        goto post_init;
    } else {
        preroll = 0;
        if (!(bezier->common.emissionVariation <= 0.0f)) {
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
    half = 0.5f;
    two = 2.0f;
    orbitScale = fGpffff8084;
    hundred = 100.0f;
    degreeScale = fGpffff8090;
    one = 1.0f;
    zero = 0.0f;
    spinScale = fGpffff8080;
    negativeOne = -1.0f;
    thousand = 1000.0f;
    three = 3.0f;
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
    b = effMiscRandFloat(0);
    c = two * (b - half);
    angle = orbitScale * c;
    a = bezier->offsetRadius * cosf(angle);
    state->offset[0] = a;
    state->offset[1] = -((MdlEffectBezierParameters *)parameters)->offsetHeight;
    a = ((MdlEffectBezierParameters *)parameters)->offsetRadius * sinf(angle);
    state->offset[2] = a;
    controlVector[0] = ((MdlEffectBezierParameters *)parameters)->end[0] + state->offset[0];
    controlVector[1] = ((MdlEffectBezierParameters *)parameters)->end[1] + state->offset[1];
    controlVector[2] = ((MdlEffectBezierParameters *)parameters)->end[2] + state->offset[2];
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(startPosition), "m"(*(u_long128 *)startPosition) : "$vf12", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(controlVector), "m"(*(u_long128 *)controlVector) : "$vf11", "memory");
    {
        s16 firstBlendPercent = ((MdlEffectBezierParameters *)parameters)->firstBlend;
        f32 firstBlendFactor = (f32)firstBlendPercent / hundred;
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(firstBlendFactor) : "$vf2", "memory");
    }
    __asm__ volatile("vsubx.w $vf3, $vf0, $vf2x \n vmulax.xyzw $ACC, $vf11, $vf2x \n vmaddw.xyzw $vf10, $vf10, $vf3w \n" : : : "$vf3", "$vf10", "$vf11", "$vf2", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)firstBlend) : "r"(firstBlend) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    {
        s16 secondBlendPercent = ((MdlEffectBezierParameters *)parameters)->secondBlend;
        f32 secondBlendFactor = (f32)secondBlendPercent / hundred;
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(secondBlendFactor) : "$vf2", "memory");
    }
    __asm__ volatile("vsubx.w $vf3, $vf0, $vf2x \n vmulax.xyzw $ACC, $vf11, $vf2x \n vmaddw.xyzw $vf10, $vf10, $vf3w \n" : : : "$vf3", "$vf10", "$vf11", "$vf2", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)secondBlend) : "r"(secondBlend) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("vmul.xyz $vf2, $vf10, $vf10 \n vaddy.x $vf2, $vf2, $vf2y \n vaddz.x $vf2, $vf2, $vf2z \n" : : : "$vf2", "$vf10", "memory");
    __asm__ volatile("vsqrt $Q, $vf2x" : : : "$Q", "$vf2", "memory");
    __asm__ volatile("vwaitq" : : : "memory");
    {
        f32 length;
        __asm__ volatile("cfc2.ni %0, $vi22\nmtc1 %0, %1" : "=r"(lengthBits), "=f"(length) : : "memory");
    }
    state->length.bits = lengthBits;
    __asm__ volatile("vmul.xyz $vf2, $vf10, $vf10 \n vmulax.w $ACC, $vf0, $vf2x \n vmadday.w $ACC, $vf0, $vf2y \n vmaddz.w $vf2, $vf0, $vf2z \n vrsqrt $Q, $vf0w, $vf2w \n vwaitq \n vmulq.xyz $vf10, $vf10, $Q \n" : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)axis) : "r"(axis) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12", "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(D_00713D00), "m"(*(u_long128 *)D_00713D00) : "$vf11", "memory");
    __asm__ volatile("vopmula.xyz $ACC, $vf10, $vf11 \n vopmsub.xyz $vf10, $vf11, $vf10 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
    __asm__ volatile("vopmula.xyz $ACC, $vf10, $vf11 \n vopmsub.xyz $vf10, $vf11, $vf10 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)perpendicular) : "r"(perpendicular) : "$vf10", "memory");
    {
        f32 rotationDegrees;
        b = effMiscRandFloat(0);
        c = two * (b - half);
        rotationDegrees = (f32)((MdlEffectBezierParameters *)parameters)->rotationSpan * c;
        scaledValue = half * rotationDegrees;
        effMiscAxisAngleVU(axis, degreeScale * scaledValue);
    }
    {
        angle = ((MdlEffectBezierParameters *)parameters)->firstVariation;
        b = effMiscRandFloat(0);
        {
            f32 firstDisplacementFactor = (one - angle) + angle * b;
            f32 firstDisplacement = ((MdlEffectBezierParameters *)parameters)->firstDisplacement * firstDisplacementFactor;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(firstBlend), "m"(*(u_long128 *)firstBlend) : "$vf10", "memory");
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(perpendicular), "m"(*(u_long128 *)perpendicular) : "$vf12", "memory");
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(firstDisplacement) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf11x \n vmadday.xyzw $ACC, $vf29, $vf11y \n vmaddz.xyzw $vf11, $vf30, $vf11z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)direction) : "r"(direction) : "$vf10", "memory");
            state->control0[0] = direction[0];
            state->control0[1] = direction[1];
            state->control0[2] = direction[2];
        }
    }
    {
        angle = ((MdlEffectBezierParameters *)parameters)->secondVariation;
        b = effMiscRandFloat(0);
        {
            f32 secondDisplacementFactor = (one - angle) + angle * b;
            f32 secondDisplacement = ((MdlEffectBezierParameters *)parameters)->secondDisplacement * secondDisplacementFactor;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(secondBlend), "m"(*(u_long128 *)secondBlend) : "$vf10", "memory");
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(secondDisplacement) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf11x \n vmadday.xyzw $ACC, $vf29, $vf11y \n vmaddz.xyzw $vf11, $vf30, $vf11z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)direction) : "r"(direction) : "$vf10", "memory");
            state->control1[0] = direction[0];
            state->control1[1] = direction[1];
            state->control1[2] = direction[2];
        }
    }
    angle = ((MdlEffectBezierParameters *)parameters)->travelVariation;
    b = effMiscRandFloat(0);
    state->travelSpeed = ((MdlEffectBezierParameters *)parameters)->travelSpeed * ((one - angle) + angle * b);
    angle = ((MdlEffectBezierParameters *)parameters)->rotationVariation;
    b = effMiscRandFloat(0);
    state->rotationSpeed = ((MdlEffectBezierParameters *)parameters)->rotationSpeed * ((one - angle) + angle * b);
    state->progress = zero;
    {
        u_long128 *origin = (u_long128 *)startPosition;
        *(u_long128 *)particle = *origin;
    }
    angle = ((MdlEffectEmitterParameters *)parameters)->sizeVariation;
    b = effMiscRandFloat(0);
    state->opacity = (one - angle) + angle * b;
    if (angleMode != 2) {
        angle = ((MdlEffectEmitterParameters *)parameters)->angleVariation;
        b = effMiscRandFloat(0);
        state->scale = (one - angle) + angle * b;
        if (angleMode == 1) {
            b = effMiscRandFloat(0);
            state->spin = spinScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                state->scale = state->scale * negativeOne;
            }
        } else {
            state->spin = zero;
        }
    } else {
        state->spin = zero;
        state->scale = one;
    }
    sampleParticle->age = 0;
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)particle;
    }
    if (preroll != 0) {
        sample = (u32)effMiscRand(0) % (u32)lifetime;
        scaledValue = (f32)(u32)sample;
        d = state->travelSpeed * scaledValue;
        d = d + half * (scaledValue * (travelAcceleration * scaledValue));
        if (d < zero) {
            d = zero;
        }
        rotationDistance = state->rotationSpeed * scaledValue;
        rotationDistance = rotationDistance + half * (scaledValue * (rotationAcceleration * scaledValue));
        if (rotationDistance < zero) {
            rotationDistance = zero;
        }
        c = rotationDistance;
        angle = d / thousand;
        if (!(angle <= one)) {
            angle = one;
        }
        if (state->progress > angle) {
            angle = state->progress;
        } else {
            state->progress = angle;
        }
        endPosition[0] = controlVector[0];
        endPosition[1] = controlVector[1];
        endPosition[2] = controlVector[2];
        progress = angle;
        inverseProgress = one - progress;
        inverseSquared = inverseProgress * inverseProgress;
        inverseCubed = inverseProgress * inverseSquared;
        prerollWeights[0] = inverseCubed;
        progressInverseSquared = progress * inverseSquared;
        firstWeight = three * progressInverseSquared;
        prerollWeights[1] = firstWeight;
        progressSquared = progress * progress;
        inverseProgressSquared = inverseProgress * progressSquared;
        secondWeight = three * inverseProgressSquared;
        prerollWeights[2] = secondWeight;
        progressCubed = progress * progressSquared;
        prerollWeights[3] = progressCubed;
        secondControlX = state->control1[0];
        originX = ((MdlEffectBezierParameters *)parameters)->start[0];
        firstControlX = state->control0[0];
        prerollPosition[0] = endPosition[0] * prerollWeights[3] +
            (originX * prerollWeights[0] + firstControlX * prerollWeights[1] +
             secondControlX * prerollWeights[2]);
        secondControlY = state->control1[1];
        originY = ((MdlEffectBezierParameters *)parameters)->start[1];
        firstControlY = state->control0[1];
        prerollPosition[1] = endPosition[1] * prerollWeights[3] +
            (originY * prerollWeights[0] + firstControlY * prerollWeights[1] +
             secondControlY * prerollWeights[2]);
        secondControlZ = state->control1[2];
        originZ = ((MdlEffectBezierParameters *)parameters)->start[2];
        firstControlZ = state->control0[2];
        prerollPosition[2] = endPosition[2] * prerollWeights[3] +
            (originZ * prerollWeights[0] + firstControlZ * prerollWeights[1] +
             secondControlZ * prerollWeights[2]);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(prerollPosition), "m"(*(u_long128 *)prerollPosition) : "$vf10", "memory");
        if (zero != rotationDistance) {
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)direction) : "r"(direction) : "$vf10", "memory");
            effMiscAxisAngleVU(axis, rotationDistance);
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(axis), "m"(*(u_long128 *)axis) : "$vf11", "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(state->length.value * angle) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x \n" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(direction), "m"(*(u_long128 *)direction) : "$vf10", "memory");
            __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmulax.xyzw $ACC, $vf28, $vf10x \n vmadday.xyzw $ACC, $vf29, $vf10y \n vmaddz.xyzw $vf10, $vf30, $vf10z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(particle) : "$vf10", "memory");
        ((SpawnParticle *)particle)->age = (s32)scaledValue;
    }
    mdlEffectSampleKeyState(particle, parameters, sampleParticle->age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * state->opacity;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * state->scale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + state->spin;
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
    {
        elapsed = (f32)age;
        travelDistance = state->travelSpeed * elapsed;
        travelDistance = travelDistance + half * (elapsed * (travelAcceleration * elapsed));
        if (travelDistance < zero) {
            travelDistance = zero;
        }
        spinDistance = state->rotationSpeed * elapsed;
        spinDistance = spinDistance + half * (elapsed * (rotationAcceleration * elapsed));
        if (spinDistance < zero) {
            spinDistance = zero;
        }
        angle = travelDistance / thousand;
        if (!(angle <= one)) {
            angle = one;
        }
        sampleValue = state->progress;
        if (sampleValue > angle) {
            angle = sampleValue;
        } else {
            state->progress = angle;
        }
    }
    endPosition[0] = ((MdlEffectBezierParameters *)parameters)->end[0] + state->offset[0];
    endPosition[1] = ((MdlEffectBezierParameters *)parameters)->end[1] + state->offset[1];
    endPosition[2] = ((MdlEffectBezierParameters *)parameters)->end[2] + state->offset[2];
    progress = angle;
    inverseProgress = one - progress;
    inverseSquared = inverseProgress * inverseProgress;
    inverseCubed = inverseProgress * inverseSquared;
    weights[0] = inverseCubed;
    progressInverseSquared = progress * inverseSquared;
    firstWeight = three * progressInverseSquared;
    weights[1] = firstWeight;
    progressSquared = progress * progress;
    inverseProgressSquared = inverseProgress * progressSquared;
    secondWeight = three * inverseProgressSquared;
    weights[2] = secondWeight;
    progressCubed = progress * progressSquared;
    weights[3] = progressCubed;
    secondControlX = state->control1[0];
    originX = ((MdlEffectBezierParameters *)parameters)->start[0];
    firstControlX = state->control0[0];
    position[0] = endPosition[0] * weights[3] +
        (originX * weights[0] + firstControlX * weights[1] +
         secondControlX * weights[2]);
    secondControlY = state->control1[1];
    originY = ((MdlEffectBezierParameters *)parameters)->start[1];
    firstControlY = state->control0[1];
    position[1] = endPosition[1] * weights[3] +
        (originY * weights[0] + firstControlY * weights[1] +
         secondControlY * weights[2]);
    secondControlZ = state->control1[2];
    originZ = ((MdlEffectBezierParameters *)parameters)->start[2];
    firstControlZ = state->control0[2];
    position[2] = endPosition[2] * weights[3] +
        (originZ * weights[0] + firstControlZ * weights[1] +
         secondControlZ * weights[2]);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(position), "m"(*(u_long128 *)position) : "$vf10", "memory");
    if (zero != spinDistance) {
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)direction) : "r"(direction) : "$vf10", "memory");
        controlVector[0] = state->control2[0];
        controlVector[1] = state->control2[1];
        controlVector[2] = state->control2[2];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(startPosition), "m"(*(u_long128 *)startPosition) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(controlVector), "m"(*(u_long128 *)controlVector) : "$vf11", "memory");
        __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmul.xyz $vf2, $vf10, $vf10 \n vmulax.w $ACC, $vf0, $vf2x \n vmadday.w $ACC, $vf0, $vf2y \n vmaddz.w $vf2, $vf0, $vf2z \n vrsqrt $Q, $vf0w, $vf2w \n vwaitq \n vmulq.xyz $vf10, $vf10, $Q \n" : : : "$vf2", "$vf10", "$vf11", "ACC", "Q", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(axis) : "memory");
        effMiscAxisAngleVU(axis, spinDistance);
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(axis), "m"(*(u_long128 *)axis) : "$vf11", "memory");
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(state->length.value * angle) : "$vf2", "memory");
        __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x \n" : : : "$vf11", "$vf2", "memory");
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(direction), "m"(*(u_long128 *)direction) : "$vf10", "memory");
        __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmulax.xyzw $ACC, $vf28, $vf10x \n vmadday.xyzw $ACC, $vf29, $vf10y \n vmaddz.xyzw $vf10, $vf30, $vf10z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(particle) : "$vf10", "memory");
    mdlEffectSampleKeyState(particle, parameters, age, &previousPosition);
    ((SpawnParticle *)particle)->size = ((SpawnParticle *)particle)->size * state->opacity;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle * state->scale;
    ((SpawnParticle *)particle)->angle = ((SpawnParticle *)particle)->angle + state->spin;
    mdlEffectUpdateParticleTrail(emitter, particle);
    ((SpawnParticle *)particle)->age = age + 1;
next_iter2:
next_iter:
    index += 1;
    state += 1;
    particle += 32;
main_check:
    if (index < count) {
        goto main_body;
    }
}


#pragma pop
