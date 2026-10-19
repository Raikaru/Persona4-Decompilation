#ifndef POLYGON_TRACK_INTERNAL_H
#define POLYGON_TRACK_INTERNAL_H

#include "effect_instance_internal.h"
#include "effect_mesh_internal.h"

typedef union EffTrackWord {
    u32 value;
    s32 signedValue;
    u16 low;
    u8 *bytes;
    void *pointer;
} EffTrackWord;

/* TrackLoadRecord copies exactly 0x1C bytes to instance +0x0C. */
typedef struct EffTrackRecord {
    u16 segments;
    u8 pad2[2];
    u32 drawStart;
    u8 pad8[0x10];
    f32 width;
} EffTrackRecord;

/* TrackAllocInstance reserves and clears 0x38 bytes. */
typedef struct EffTrackInstance {
    EffTrackWord count;
    EffTrackWord packedColor;
    f32 scale;
    EffTrackRecord record;
    EffTrackWord ribbons;
    EffTrackWord particle;
    EffTrackWord path;
    u16 active;
    u8 pad36[2];
} EffTrackInstance;

/* Common emitter parameter prefix; unlike SwayParticleParameters this is used
 * across all track emitter kinds. Reads at +0x20/+0x24/+0xB8 select the count;
 * func_00492b20 also uses +0xC0/+0xC4 when sizing its sample allocation. */
typedef struct EffTrackPathParameters {
    u8 pad0[0x20];
    EffTrackWord emissionDuration;
    s32 emissionRate;
    u8 pad28[0x2C];
    u16 unk54;
    u8 pad56[0x62];
    s32 lifetime;
    u8 padBC[4];
    u32 trailCount;
    s32 trailWidth;
} EffTrackPathParameters;

/* func_00492b20 allocates this 0x30-byte header followed by 0x20-byte samples,
 * parameter copies and kind-specific work. +0x28 remembers the allocation. */
typedef struct EffTrackPath {
    u16 kind;
    u8 pad2[2];
    u32 primaryCount;
    u32 totalCount;
    u32 flags;
    EffTrackWord ticks;
    f32 emissionAccumulator;
    u8 *samples;
    u8 *state;
    u8 *parameters;
    u8 *originalParameters;
    void *allocation;
    u32 unk2C;
} EffTrackPath;

typedef struct EffTrackSample {
    f32 position[3];
    u8 padC[4];
    s32 mode;
    s32 packedColor;
    f32 width;
    u8 pad1C[4];
} EffTrackSample;

/* TrackAllocRibbons appends one u16 count per ribbon to this 0x1C header. */
typedef struct EffTrackRibbons {
    u8 pad0[0x10];
    u16 *ribbon;
    u16 *cap;
    u8 *counts;
} EffTrackRibbons;

#endif
