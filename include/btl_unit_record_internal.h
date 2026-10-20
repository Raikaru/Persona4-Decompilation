#ifndef BTL_UNIT_RECORD_INTERNAL_H
#define BTL_UNIT_RECORD_INTERNAL_H

#include "btl_unit_internal.h"

/* btlUnitInitFromRecord reads these signed centers and unsigned dimensions.
 * btlUnitGetRecordPtr selects the normal or alternate ten-byte bounds. */
typedef struct BtlUnitBoundsRecord {
    s16 x, y, z;
    u16 height;
    u16 radius;
} BtlUnitBoundsRecord;

/* Record strides and motion counts come from btlUnitInitFromRecord. */
typedef struct BtlUnitPartyRecord {
    BtlUnitBoundsRecord bounds[2];
    u16 scalePercent;             /* 0x14 */
    u8 pad16[0x3C - 0x16];
    BtlMotionRate motions[27];    /* 0x3C */
    u8 pad14A[2];
} BtlUnitPartyRecord;

typedef struct BtlUnitEnemyRecord {
    BtlUnitBoundsRecord bounds[2];
    u16 scalePercent;             /* 0x14 */
    u16 unk16;
    s16 flags;                   /* 0x18: 0x100 tested when target hit rows are flagged */
    u8 pad1A[8];
    s16 unk22;                   /* 1 rejects the skill flags00 & 2 path */
    u8 pad24[2];
    s16 unk26;                   /* 1 rejects the active-entry path */
    u8 pad28[2];
    BtlMotionRate motions[19];    /* 0x2A */
} BtlUnitEnemyRecord;

typedef struct BtlUnitChildRecord {
    u16 unk00;
    BtlUnitBoundsRecord bounds;   /* 0x02 */
    u8 pad0C[0x18 - 0x0C];
    u16 scalePercent;             /* 0x18 */
    BtlMotionRate motions[6];     /* 0x1A */
    u8 pad56[2];
} BtlUnitChildRecord;

/* The body-size scale gate indexes a separate 0x3C-byte data table. */
typedef struct BtlUnitBodySizeRecord {
    u16 flags;                   /* 0x8000 bypasses body-size scaling */
    u8 pad02[0x3C - 2];
} BtlUnitBodySizeRecord;

#endif
