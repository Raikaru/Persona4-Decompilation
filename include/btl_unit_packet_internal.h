#ifndef BTL_UNIT_PACKET_INTERNAL_H
#define BTL_UNIT_PACKET_INTERNAL_H

#include "btl_unit_internal.h"

/* Work begins with the held unit in the packet constructors and lifecycle callbacks.
 * These are packet work allocations, not the dispatcher object itself. */
typedef struct BtlUnitPacketReference {
    u8 *unit;
} BtlUnitPacketReference;

typedef struct BtlUnitOverridePacket {
    u8 *unit;                   /* 0x00 */
    RwV3d position;              /* 0x04 */
    RtQuat rotation;            /* 0x10 */
    RwRGBA color;               /* 0x20 */
    u16 flags;                  /* 0x24: position/rotation/color = 1/2/4 */
    u8 pad26[2];
} BtlUnitOverridePacket;         /* btlPacketAlloc(0x11C, 0x28) */

typedef struct BtlUnitMovePacket {
    u8 *unit;                   /* 0x00 */
    RwV3d destination;           /* 0x04 */
    s32 flags;                  /* 0x10 */
    u16 state;                  /* 0x14 */
    u8 pad16[2];
    s32 counter;                /* 0x18 */
    f32 stoppingDistance;       /* 0x1C */
    f32 speed;                  /* 0x20: scaled by 27 in the update */
} BtlUnitMovePacket;

typedef struct BtlUnitArcMovePacket {
    u8 *unit;                   /* 0x00 */
    u16 mode;                   /* 0x04 */
    u16 counter;                /* 0x06 */
    f32 scale;                  /* 0x08 */
    RwV3d start;                /* 0x0C */
    RwV3d delta;                /* 0x18 */
    f32 progress;               /* 0x24 */
} BtlUnitArcMovePacket;          /* btlPacketAlloc(0x10C, 0x28) */

typedef struct BtlUnitRotatePacket {
    u8 *unit;
    RwV3d target;               /* 0x04 */
    s32 flags;                  /* 0x10 */
    s32 counter;                /* 0x14 */
} BtlUnitRotatePacket;

typedef struct BtlUnitMotionPacket {
    u8 *unit;
    s16 motion;                 /* 0x04 */
    u16 frame;                  /* 0x06 */
    f32 rate;                   /* 0x08 */
    u16 option;                 /* 0x0C */
    u8 pad0E[2];
} BtlUnitMotionPacket;

typedef struct BtlUnitFramePacket {
    u8 *unit;
    s16 frame;                  /* 0x04 */
} BtlUnitFramePacket;

/* Rest-motion requests load an unsigned frame; explicit model-frame work above is signed. */
typedef struct BtlUnitMotionRequestPacket {
    u8 *unit;
    u16 frame;                  /* 0x04 */
} BtlUnitMotionRequestPacket;

typedef struct BtlUnitResNullifiedPacket {
    u8 *unit;
    f32 amplitude;              /* 0x04 */
    s32 counter;                /* 0x08: low bit alternates displacement */
} BtlUnitResNullifiedPacket;

typedef struct BtlUnitDodgePacket {
    u8 *unit;
    s32 counter;                /* 0x04 */
    f32 progress;               /* 0x08 */
    f32 velocity;               /* 0x0C */
} BtlUnitDodgePacket;

typedef struct BtlUnitMotionSpeedPacket {
    u8 *unit;
    u16 frame;                  /* 0x04 */
    u8 pad06[2];
    f32 rate;                   /* 0x08 */
    u16 option;                 /* 0x0C */
    u8 pad0E[2];
} BtlUnitMotionSpeedPacket;

typedef struct BtlUnitModelLoadPacket {
    u8 *unit;
    s16 genus;                  /* 0x04 */
    s16 modelId;                /* 0x06 */
    union {
        s16 motion;             /* 0x08: model setup flags in the load callbacks */
        u16 flags;
    };
    u8 pad0A[2];
    union {
        s32 resource;           /* 0x0C: directory request handle */
        void *resourcePtr;
    };
} BtlUnitModelLoadPacket;        /* btlPacketAlloc(0x10F, 0x10) */

typedef struct BtlUnitResourceLoadPacket {
    u8 *unit;
    u8 pad04[4];
    u16 flags;                  /* 0x08 */
    u8 pad0A[2];
    s32 initialized;            /* 0x0C */
} BtlUnitResourceLoadPacket;

/* Embedded resource ownership block at unit+0xA04, initialized by btlUnitCreate
 * and cleared by both resource teardown paths. Handles retain their word ABI. */
typedef struct BtlUnitResources {
    s32 placement;
    s32 nodePool;
    u8 *child;
} BtlUnitResources;

/* Follow-up pair at unit+0x9E6, copied from the resolved motion-table row. */
typedef struct BtlUnitFollowMotion {
    s16 motion;
    s16 frame;
} BtlUnitFollowMotion;

/* Rest-playback state at unit+0x9EC, written together by UpdateStatusMotion. */
typedef struct BtlUnitRestMotion {
    s16 motion;
    s16 nextMotion;
    f32 rate;
    s8 option;
    u8 pad09[3];
} BtlUnitRestMotion;

/* Embedded color transition at unit+0x40. UpdateAll snapshots the start,
 * interpolates toward the target over eight ticks, and publishes packed RGBA. */
typedef struct BtlUnitColorTransition {
    RwRGBA current;
    RwRGBA start;
    RwRGBA target;
    u16 remaining;
    RwRGBA published;           /* unit+0x4E: byte-aligned, not a word field */
} BtlUnitColorTransition;

#endif
