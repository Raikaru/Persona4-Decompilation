#ifndef SWAY_PARTICLE_INTERNAL_H
#define SWAY_PARTICLE_INTERNAL_H
#include "particle_spawn_internal.h"

/* Kind 11 dispatch 0x00713e00: 64-byte work, 272-byte parameters. */
typedef struct SwayParticleState {
    f32 riseDirection[3], swayDirection[3];
    f32 phase, previousSine, amplitude, amplitudeStep, phaseStep;
    f32 speed, bounceScale, sizeScale, angleOffset, angleScale;
} SwayParticleState;
typedef struct SwayParticleParameters {
    f32 position[4], rotation[4];
    s32 emissionDuration;
    u32 emissionRate;
    f32 emissionVariation;
    u32 unknown2c[16];
    f32 sizeVariation;
    u32 unknown70[10];
    f32 angleVariation;
    u8 angleMode, unknown9d[27];
    s32 lifetime;
    u8 localSpace, preroll, unknownbe[2];
    s32 trailCount, trailWidth;
    f32 spread, speed, speedVariation, deceleration;
    f32 initialAmplitude, initialAmplitudeVariation;
    f32 finalAmplitude, finalAmplitudeVariation;
    f32 phaseStep, phaseVariation, floorHeight;
    f32 bounce, bounceVariation, bounceDecay;
    u32 unknown100[4];
} SwayParticleParameters;
typedef struct SwayParticleEmitter {
    u16 kind, unknown02;
    u32 primaryCount, totalCount, flags;
    s32 ticks;
    f32 emissionAccumulator;
    SpawnParticle *particles;
    SwayParticleState *state;
    SwayParticleParameters *parameters;
    void *originalParameters, *allocation;
    u32 unknown2c;
} SwayParticleEmitter;

#endif
