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
    u8 pad16[4];
    s16 hitIntervals[17];         /* 0x1A: motion-class stride 0x12, hit-ordinal stride 2 */
    BtlMotionRate motions[27];    /* 0x3C */
    u8 pad14A[2];
} BtlUnitPartyRecord;

typedef struct BtlUnitEnemyRecord {
    BtlUnitBoundsRecord bounds[2];
    u16 scalePercent;             /* 0x14 */
    u16 unk16;
    s16 flags;                   /* 0x18: 0x100 tested when target hit rows are flagged */
    struct {
        s16 classValue;          /* 0x1A + class * 4 */
        s16 hitInterval;         /* 0x1C + class * 4 */
    } hitClasses[2];
    s16 unk22;                   /* 1 rejects the skill flags00 & 2 path */
    u16 homeMove;                /* 0x24: home movement motion, skill flag 2 set */
    s16 unk26;                   /* 1 rejects the active-entry path */
    u16 homeMoveAlternate;       /* 0x28: home movement motion, skill flag 2 clear */
    BtlMotionRate motions[19];    /* 0x2A */
} BtlUnitEnemyRecord;

/* Formation offsets are signed XYZ halfwords; slot arithmetic advances by six bytes. */
typedef struct BtlUnitSlotOffset {
    s16 x, y, z;
} BtlUnitSlotOffset;

typedef struct BtlUnitChildRecord {
    u16 unk00;
    BtlUnitBoundsRecord bounds;   /* 0x02 */
    BtlUnitSlotOffset slots[2];   /* 0x0C: two six-byte formation offsets */
    u16 scalePercent;             /* 0x18 */
    BtlMotionRate motions[6];     /* 0x1A */
    u8 pad56[2];
} BtlUnitChildRecord;

typedef char BtlUnitSlotOffsetSizeCheck[sizeof(BtlUnitSlotOffset) == 6 ? 1 : -1];
typedef char BtlUnitChildSlotsOffsetCheck[(u32)&((BtlUnitChildRecord *)0)->slots == 0x0C ? 1 : -1];
typedef char BtlUnitChildRecordSizeCheck[sizeof(BtlUnitChildRecord) == 0x58 ? 1 : -1];

/* The body-size scale gate indexes a separate 0x3C-byte data table. */
typedef struct BtlUnitBodySizeRecord {
    u16 flags;                   /* 0x8000 bypasses body-size scaling */
    u8 pad02[0x3C - 2];
} BtlUnitBodySizeRecord;

#endif
