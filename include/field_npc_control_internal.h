#ifndef FIELD_NPC_CONTROL_INTERNAL_H
#define FIELD_NPC_CONTROL_INTERNAL_H
#include "type.h"

/* Scalar/word aliases preserve the path initializer's IEEE-754 bit stores. */
typedef union FldNpcMotionValue {
    u32 bits;
    f32 value;
} FldNpcMotionValue;

/* Three-component heading copied from the model matrix before a turn. */
typedef struct FldNpcHeading {
    f32 x, y, z;
} FldNpcHeading;

/* Field npc control task work, the 0x58-byte block at task+0x38 (allocated in
 * FldNpcControlTaskCreate). FldNpcControlUpdate establishes the path, facing,
 * fade, pause and position-slot fields; gaps have no established meaning. */
typedef struct FldNpcControlWork {
    u32 state;             /* 0x00: update step; FldNpcControlReady reports state >= 4 */
    u8 unk04[0x04];
    u32 hidden;            /* 0x08: 1 suppresses the update */
    s32 actor;             /* 0x0C: actor argument passed to FldNpcControlTaskCreate */
    s32 effectTask;        /* 0x10: model fade task */
    s32 handle;            /* 0x14: handle released by func_003e0f40 on destroy */
    FldNpcMotionValue progress; /* 0x18: spline parameter */
    FldNpcMotionValue step;
    FldNpcMotionValue direction;
    u32 turnFrames;
    u32 pauseFrames;
    s32 savedAnimation;
    FldNpcHeading savedHeading; /* 0x30: normalized heading before facing the player */
    union {
        FldNpcHeading heading; /* 0x3C: desired normalized heading */
        struct { f32 headingX, headingY, headingZ; };
    };
    f32 cameraHeight;      /* 0x48: camera height copied at create */
    u32 cameraNear;        /* 0x4C: camera-distance fade latch */
    s32 actorIndex;        /* 0x50: scene resource-list index */
    s32 positionSlot;      /* 0x54: requested position slot */
} FldNpcControlWork;

#endif
