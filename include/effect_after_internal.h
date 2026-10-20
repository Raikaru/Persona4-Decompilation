#ifndef EFFECT_AFTER_INTERNAL_H
#define EFFECT_AFTER_INTERNAL_H

#include "type.h"

/* 12-byte vector copy; mwcc emits all loads then all stores for a struct
   assignment, matching retail, where per-element statements interleave. */
typedef struct {
    f32 c[3];
} EffAfterVec;
/* Ribbon sample queue shared by the sample writer and the offset builder. */
typedef struct {
    f32 mid[3];
    f32 headMid;
    f32 headNext;
    f32 tailMid;
    f32 tailPrev;
    f32 width[2];
    f32 alpha[2];
    f32 lengthScale; /* +0x2C: scales accumulated section lengths */
    f32 unk30; /* +0x30: final float copied by AfPackBindResource (0x34-byte stride) */
} EffAfterParam;

/* Material descriptor linked by the packed resource binder (0x18-byte stride). */
typedef struct EffAfterMaterial {
    u32 flags;
    s32 texture;
    u8 colors[16];
} EffAfterMaterial;

typedef struct {
    EffAfterParam *param;
    u8 *material;
    s32 capacity;
    s32 sectionCount; /* +0xC: ribbon subdivision count */
    s32 mode;
    f32 width;
} EffAfterConfig;

typedef struct EffAfterQueue {
    EffAfterConfig *config;
    u32 flags;
    s32 count;
    s32 writeIndex;
    EffAfterVec *positions;
    EffAfterVec *normals;
    EffAfterVec *positionOffsets[2];
    EffAfterVec *normalOffsets[2];
    u8 pad28[0x10];
    s16 mode; /* +0x38: copied from the section configuration */
} EffAfterQueue;

#endif
