#ifndef BTL_UNIT_INTERNAL_H
#define BTL_UNIT_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"
#include "rw_types_internal.h"

/* One motion-table row: playback rate in percent at +0x2 (btlUnitSetMotion, btlUnit.c). */
typedef struct BtlMotionRate
{
    s16 unk0;
    s16 rate;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} BtlMotionRate;

/* Typed prefix of the retail BtlUnit. Offsets through 0xC8 agree with the
   P4 battle TUs; later fields are still reached through raw offsets. */
typedef struct BtlUnit BtlUnit;
struct BtlUnit
{
    u16 flags;               /* 0x00 */
    RwV3d pos;               /* 0x04 */
    RwV3d posOffset;         /* 0x10 */
    RtQuat rot;              /* 0x1C */
    f32 scale;               /* 0x2C */
    RwRGBA cols[5];          /* 0x30 */
    u8 unk_44[0x08];         /* 0x44 */
    u16 unk_4c;              /* 0x4C */
    u8 unk_4e[0x06];         /* 0x4E */
    RwV3d unk_54;            /* 0x54 */
    u8 unk_60[0x10];         /* 0x60 */
    RtQuat unk_70;           /* 0x70 */
    RwV3d sphereCenter;      /* 0x80 */
    f32 unk_8c;              /* 0x8C */
    f32 sphereRadius;        /* 0x90 */
    s16 unk_94;              /* 0x94 */
    s16 unk_96;              /* 0x96 */
    u32 flags2;              /* 0x98 */
    u32 flags3;              /* 0x9C. See BTLUNIT_FLAG3_* */
    u16 pendingPacketCount;  /* 0xA0. Packets currently holding the unit; the unit's state machine waits for 0 */
    u8 genus;                /* 0xA2. UnitGenus */
    u8 _padA3;               /* 0xA3 */
    u16 charId;              /* 0xA4 */
    u32 id;                  /* 0xA8 */
    s32 unk_ac;              /* 0xAC */
    u16 lookAtMode;          /* 0xB0 */
    u16 _padB2;              /* 0xB2 */
    u32 lookAtTargetId;      /* 0xB4 */
    RwV3d lookAtTargetPos;   /* 0xB8 */
    u32 stateFlags;          /* 0xC4 */
    u16 movementFlags;       /* 0xC8 */
    u8 unk_ca[0x00DC - 0x00CA];
    RwV3d moveDestination;        /* 0xDC. Written by btlUnitMovePacketUpdate, including the stopping-distance adjustment */
    f32 stoppingDistance;         /* 0xE8. Move-packet separation; btlUnitUpdateFollowPath stops this far from the route end */
    u8 unk_ec[0x09D8 - 0x00EC];
    u16 unk_9d8;                  /* 0x9D8. Motion-mode bits: 0x10 adds 0x100 to the packet flags, 0x20 zeroes the frame, 0x40 forces motion 27 */
    s16 currentMotion;            /* 0x9DA. Valid while flags2 bit 1 (0x2) is set; written by btlUnitSetMotion */
    s16 motionOption;             /* 0x9DC. Option argument of btlUnitSetMotion */
    f32 motionRate;               /* 0x9E0. Playback rate, scaled by the motion table's rate */
    u16 motionCount;              /* 0x9E4. Entries in motionRates */
    u8 unk_9e6[0x09EC - 0x09E6];
    s16 restMotion;               /* 0x9EC. Motion for the at-rest state */
    u8 unk_9ee[0x09F0 - 0x09EE];
    f32 restRate;                 /* 0x9F0 */
    s8 restOption;                /* 0x9F4 */
    u8 unk_9f5[0x09F8 - 0x09F5];
    BtlMotionRate *motionRates;   /* 0x9F8 */
    u8 unk_9fc[0x09FE - 0x09FC];
    u16 sceneDrawId;              /* 0x9FE. Scene draw id from MT_Scene_CreateModelCharRes, passed to SceneDraw_SetDirectionalOnly */
    u8 *layerHandle;              /* 0xA00. Model object passed to the mdl layer helpers */
    u8 unk_a04[0x0A0C - 0x0A04];
    BtlUnit *childUnit;           /* 0xA0C. Child unit allocated by btlUnitCreate(2) in btlUnitInitChild */
    u8 unk_a10[0x0A64 - 0x0A10];
    DatUnit *datUnit;             /* 0xA64. Passed to datCalc accessors */
    BtlUnit *prevUnit;            /* 0xA68. Previous unit in the battle unit list */
    BtlUnit *nextUnit;            /* 0xA6C. Next unit in the battle unit list */
};

#endif
