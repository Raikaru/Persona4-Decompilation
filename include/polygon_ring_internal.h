#ifndef POLYGON_RING_INTERNAL_H
#define POLYGON_RING_INTERNAL_H

#include "effect_mesh_internal.h"

/* RingCreateKindInstance allocates this 0x50-byte header followed by kind data.
 * Quadword transforms occupy +0x00/+0x10/+0x20; the update paths copy them whole. */
typedef unsigned int EffRingQuad __attribute__((mode(TI)));
typedef struct EffRingInstance {
    EffRingQuad position;
    EffRingQuad rotation;
    EffRingQuad scale;
    s32 packedColor;
    s32 age;
    s32 kind;
    union { u8 *bytes; u32 bits; s32 signedBits; } work;
    u8 *parameters;
    u8 pad44[0xC];
} EffRingInstance;

/* Shared 0x5C-byte parameter prefix, also copied by RingCreateRandomScaled. */
typedef struct EffRingParameters {
    u8 pad0[0x24];
    u32 color;
    u16 resource;
    u8 pad2A[0xA];
    s32 duration;
    union { u32 count; u16 low; } segments;
    u8 visible;
    u8 pad3D[3];
    f32 radius;
    s32 innerColor;
    s32 middleColor;
    s32 outerColor;
    f32 innerWidth;
    f32 middleWidth;
    f32 outerWidth;
} EffRingParameters;

typedef struct EffRingCircleParameters {
    EffRingParameters base;
    u8 pad5C[4];
    f32 speed;
    f32 acceleration;
    u8 reverse;
} EffRingCircleParameters;

typedef struct EffRingScaledParameters {
    EffRingParameters base;
    f32 speed;
    f32 acceleration;
    u8 reverse;
} EffRingScaledParameters;

typedef struct EffRingRandomParameters {
    EffRingParameters base;
    EffRingParameters copied;
    u8 padB8[0xC];
    u8 skipVertices;
    u8 padC5[3];
    f32 radialScale;
    f32 radialSpread;
} EffRingRandomParameters;

/* Random scale words precede this 0x10-byte tail in the same allocation. */
typedef struct EffRingRandomBlock {
    u8 *scales;
    u8 *sourceInstance;
    u8 *geometry;
    void *allocation;
} EffRingRandomBlock;

#endif
