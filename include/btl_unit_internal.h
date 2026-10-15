#ifndef BTL_UNIT_INTERNAL_H
#define BTL_UNIT_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

typedef struct RwRGBA RwRGBA;
struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
};

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
    u8 unk_ca[0x0A64 - 0x00CA]; /* 0xCA. Not yet named */
    DatUnit *datUnit;             /* 0xA64. Passed to datCalc accessors */
    BtlUnit *prevUnit;            /* 0xA68. Previous unit in the battle unit list */
    BtlUnit *nextUnit;            /* 0xA6C. Next unit in the battle unit list */
};

#endif
