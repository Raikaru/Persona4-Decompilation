#ifndef MDL_EFFECT_EMITTER_INTERNAL_H
#define MDL_EFFECT_EMITTER_INTERNAL_H

#include "particle_spawn_internal.h"

/* Shared 0x30-byte emitter prefix: primary particles precede their trail
 * records. Kind-specific state has its own stride in each update routine. */
typedef struct MdlEffectEmitter {
    u16 kind;
    u16 unk2;
    union { u32 value; s32 signedValue; } primaryCount;
    u32 totalCount;
    u32 flags;
    s32 ticks;
    f32 emissionAccumulator;
    u8 *particles;
    union { u8 *bytes; f32 *scalars; void *pointer; } state;
    u8 *parameters;
    u8 *originalParameters;
    void *allocation;
    u32 unk2C;
} MdlEffectEmitter;

/* All controller readers agree on this common 0xC8-byte parameter prefix.
 * Key-block boundaries follow the sample calls, not guessed field meanings. */
typedef struct MdlEffectEmitterParameters {
    u8 position[0x10];
    u8 rotation[0x10];
    s32 emissionDuration;
    union { s32 signedValue; u32 value; } emissionRate;
    f32 emissionVariation;
    u8 colorKeys[0x24];
    u8 opacityKeys[0x10];
    u8 sizeKeys[0xC];
    f32 sizeVariation;
    u8 pad70[0x1C];
    u8 angleKeys[0xC];
    f32 angleVariation;
    u8 angleMode;
    u8 pad9D[0x1B];
    s32 lifetime;
    u8 unkBC;
    u8 preroll;
    u8 padBE[2];
    union { s32 signedValue; u32 value; } trailCount;
    s32 trailWidth;
} MdlEffectEmitterParameters;

typedef struct MdlEffectMotionParameters {
    MdlEffectEmitterParameters common;
    f32 spread, spreadVariation, speed, speedVariation;
    f32 acceleration, gravity;
} MdlEffectMotionParameters;
typedef struct MdlEffectConeParameters {
    MdlEffectEmitterParameters common;
    f32 spread, spreadVariation, cone, coneVariation;
    f32 speed, speedVariation, acceleration, gravity;
    s32 angleSpan;
} MdlEffectConeParameters;
typedef struct MdlEffectOrbitParameters {
    MdlEffectEmitterParameters common;
    f32 radius, radiusVariation, endRadius, endRadiusVariation;
    f32 angularSpeed, angularSpeedVariation, angularAcceleration, gravity;
} MdlEffectOrbitParameters;
typedef struct MdlEffectHelixParameters {
    MdlEffectEmitterParameters common;
    f32 heightRange, radius, radiusVariation, endRadius, endRadiusVariation;
    f32 angularSpeed, angularSpeedVariation, speed, speedVariation;
    f32 angularAcceleration, gravity;
} MdlEffectHelixParameters;
typedef struct MdlEffectFloorParameters {
    MdlEffectEmitterParameters common;
    f32 spread, spreadVariation, cone, coneVariation;
    f32 floorHeight, speed, speedVariation, acceleration, gravity;
    f32 bounce, bounceVariation, bounceDecay;
} MdlEffectFloorParameters;
typedef struct MdlEffectBoundParameters {
    MdlEffectEmitterParameters common;
    f32 radius, radiusVariation, endRadius, endRadiusVariation;
    s32 radiusDuration;
    f32 speed, speedVariation, acceleration;
} MdlEffectBoundParameters;
typedef struct MdlEffectBoundState {
    f32 direction[3];
    f32 radius, radiusStep, speed, sizeScale, angleOffset, angleScale;
} MdlEffectBoundState;

/* Bezier control offsets and percentage blends have different widths from the
 * cone/orbit parameters; do not interpret this suffix as those subtypes. */
typedef struct MdlEffectBezierParameters {
    MdlEffectEmitterParameters common;
    s16 firstBlend;
    u8 padCA[2];
    f32 firstDisplacement, firstVariation;
    s16 secondBlend;
    u8 padD6[2];
    f32 secondDisplacement, secondVariation;
    s16 rotationSpan;
    u8 padE2[2];
    f32 rotationSpeed, rotationVariation, rotationAcceleration;
    f32 travelSpeed, travelVariation, travelAcceleration;
    f32 start[3];
    f32 end[3];
    u8 pad114[8];
    f32 offsetRadius, offsetHeight;
} MdlEffectBezierParameters;

typedef struct MdlEffectScalarKeys {
    u8 mode;
    u8 pad1[3];
    f32 start, end;
    u8 padC[8];
    f32 firstMiddle, firstFraction, secondMiddle, secondFraction;
} MdlEffectScalarKeys;

/* Per-particle state strides follow the controller's state cursor increments. */
typedef struct MdlEffectMotionState {
    f32 direction[3];
    f32 speed, sizeScale, angleOffset, angleScale;
} MdlEffectMotionState;
typedef struct MdlEffectFloorState {
    f32 direction[3];
    f32 speed, bounce, sizeScale, angleOffset, angleScale;
} MdlEffectFloorState;
typedef struct MdlEffectOrbitState {
    f32 origin[3];
    f32 tiltX, tiltY;
    f32 radius, radiusStep, angularSpeed, phase, height;
    f32 sizeScale, angleOffset, angleScale;
} MdlEffectOrbitState;
typedef struct MdlEffectHelixState {
    f32 origin[3];
    f32 orientation[4];
    f32 height, radius, radiusStep, phase, angularSpeed, speed;
    f32 sizeScale, angleOffset, angleScale;
} MdlEffectHelixState;

#endif
