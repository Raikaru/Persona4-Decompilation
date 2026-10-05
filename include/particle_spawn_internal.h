#ifndef PARTICLE_SPAWN_INTERNAL_H
#define PARTICLE_SPAWN_INTERNAL_H
#include "type.h"
#include "effect_vu0_internal.h"

/* Recovered from the controller loads and the dispatch allocation sizes.
 * Names describe behavior; these are not recovered original symbols. */
typedef struct SpawnParticle {
    EffectVuVector position;
    s32 age;
    u32 color;
    f32 size, angle;
} SpawnParticle;

typedef struct WaveSpawnState {
    f32 direction[3];
    f32 waveDirection[3];
    f32 phase, previousSine, amplitude, amplitudeStep, phaseStep, speed;
    f32 sizeScale, angleOffset, angleScale;
} WaveSpawnState;

typedef struct WaveSpawnParameters {
    EffectVuVector position, rotation;
    s32 emissionDuration;
    u32 emissionRate;
    f32 emissionVariation;
    u32 unknown2c[16];
    f32 sizeVariation;
    u32 unknown70[10];
    f32 angleVariation;
    u8 angleMode, unknown9d[27];
    s32 lifetime;
    u8 unknownbc, preroll, unknownbe[2];
    s32 trailCount, trailWidth;
    f32 spread, speed, speedVariation, gravity;
    f32 initialAmplitude, initialAmplitudeVariation;
    f32 finalAmplitude, finalAmplitudeVariation;
    f32 phaseStep, phaseStepVariation;
} WaveSpawnParameters;

typedef struct WaveSpawnEmitter {
    u16 kind, unknown02;
    u32 primaryCount, totalCount, flags;
    s32 ticks;
    f32 emissionAccumulator;
    SpawnParticle *particles;
    WaveSpawnState *state;
    WaveSpawnParameters *parameters;
    void *originalParameters, *allocation;
    u32 unknown2c;
} WaveSpawnEmitter;

/* VF28..30 contain the basis established by func_004bceb0. The W lane is
 * transformed too; normalization below intentionally changes XYZ only. */
static inline void spawnVuTransform10(void)
{
    __asm__ volatile(
        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
        : : : "$vf10", "ACC");
}
static inline void spawnVuNormalize10(void)
{
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10\n"
        "vmulax.w $ACC, $vf0, $vf2x\n"
        "vmadday.w $ACC, $vf0, $vf2y\n"
        "vmaddz.w $vf2, $vf0, $vf2z\n"
        "vrsqrt $Q, $vf0w, $vf2w\n"
        "vwaitq\n"
        "vmulq.xyz $vf10, $vf10, $Q\n"
        : : : "$vf2", "$vf10", "ACC", "Q");
}
static inline void spawnVuMultiply10(void)
{
    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
}
static inline void spawnVuAdd10(void)
{
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
}
#endif
