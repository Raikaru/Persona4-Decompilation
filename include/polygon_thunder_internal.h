#ifndef POLYGON_THUNDER_INTERNAL_H
#define POLYGON_THUNDER_INTERNAL_H

#include "effect_mesh_internal.h"
#include "effect_vu0_internal.h"

/* Words consumed with both signed counters and unsigned packed-color/count views. */
typedef union EffThunderWord {
    s32 signedValue;
    u32 value;
    u16 low;
    u8 *bytes;
    void *pointer;
} EffThunderWord;

/* ThunderTextureForIndex allocates this 0x40-byte header plus kind parameters;
 * despite its current name, it constructs the complete animated effect. */
typedef struct EffThunderInstance {
    EffectVuVector position;
    EffectVuVector rotation;
    union { f32 value; u32 bits; } scale;
    EffThunderWord packedColor;
    EffThunderWord age;
    u32 kind;
    EffThunderWord work;
    EffThunderWord parameters;
    u8 pad38[8];
} EffThunderInstance;

/* Kinds 1 and 4 have 0x88-byte parameters in the retail table at 0x00713E70.
 * Kind 3 adds the orbit extension below, for a complete 0xAC-byte record. */
typedef struct EffThunderParameters {
    u8 pad0[0x28];
    u16 resource;
    u8 pad2A[0xA];
    EffThunderWord duration;
    EffThunderWord copies;
    EffThunderWord segments;
    s32 respawnRange;
    f32 pairedAmplitude;
    u8 pad48[4];
    u32 waves;
    f32 amplitude;
    f32 lengthScale;
    f32 lengthSpread;
    u8 visible;
    u8 pad5D[0xB];
    f32 fadeStart;
    f32 fadeEnd;
    u32 centerColor;
    u32 innerColor;
    u32 outerColor;
    f32 innerWidth;
    f32 outerWidth;
    f32 length;
} EffThunderParameters;

typedef struct EffThunderOrbitParameters {
    EffThunderParameters base;
    u8 orbitMode;
    u8 pad89[3];
    f32 startRadius;
    f32 startRadiusSpread;
    f32 endRadius;
    f32 endRadiusSpread;
    f32 heightRange;
    f32 orbitSpeed;
    f32 orbitSpeedSpread;
    f32 orbitAcceleration;
} EffThunderOrbitParameters;

/* Allocations prove entry strides: simple 0x10, paired 0x0C, orbit 0x30.
 * The simple and paired list headers are only a pointer; orbit owns 0x10 bytes. */
typedef struct EffThunderList { u8 *entries; } EffThunderList;
typedef struct EffThunderOrbitList {
    u8 *entries;
    f32 radius;
    f32 radiusStep;
    void *allocation;
} EffThunderOrbitList;
typedef struct EffThunderBolt {
    u8 *geometry;
    s32 age;
    EffThunderWord color;
    f32 baseAngle;
} EffThunderBolt;
typedef struct EffThunderPairedBolt {
    u8 *geometry;
    s32 age;
    EffThunderWord color;
} EffThunderPairedBolt;
typedef struct EffThunderOrbitBolt {
    u8 *geometry;
    f32 previousPosition[3];
    u8 pad10[4];
    s32 age;
    EffThunderWord color;
    f32 tilt;
    f32 yaw;
    f32 speed;
    f32 angle;
    f32 height;
} EffThunderOrbitBolt;

#endif
