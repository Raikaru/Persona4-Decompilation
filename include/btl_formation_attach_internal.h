#ifndef BTL_FORMATION_ATTACH_INTERNAL_H
#define BTL_FORMATION_ATTACH_INTERNAL_H

#include "type.h"

/* Allocated by btlFormationAllocEntry: 0x68-byte prefix and count handles.
 * Attachment callbacks and func_001d53e0 establish the vector and entry fields. */
typedef struct BtlAttachV3 { f32 x, y, z; } BtlAttachV3;
typedef struct BtlAttachV4 { f32 x, y, z, w; } BtlAttachV4;
typedef struct BtlAttachMode
{
    u8 type;
    u8 heightMode;
    u8 positionMode;
    u8 pad03;
    u16 matrixIndex;
    u16 kind;
} BtlAttachMode;
typedef struct BtlAttachEntry
{
    u8 state;
    u8 pad01[3];
    u8 *resource;
    BtlAttachMode mode;
    u32 start;
    u8 pad14[4];
} BtlAttachEntry; /* 0x18 */
/* AllocEntry selects records at a 0x314 stride, starting at owner+8.
 * UpdateAttachments starts the 0x18-byte entries at table+0x14. */
typedef struct BtlAttachTable {
    u32 unk00;
    u32 unk04; /* Compared with the attachment work frame for repeat refresh. */
    u16 count;
    u8 pad0A[6];
    u8 scaleMode;
    u8 pad11[3];
    BtlAttachEntry entries[32];
} BtlAttachTable;

typedef struct BtlFormationData {
    u8 pad00[8];
    BtlAttachTable tables[2];
    u16 flags; /* 0x630: bit 2 reuses template instances instead of cloning. */
} BtlFormationData;

typedef struct BtlAttachWork
{
    u8 *owner;
    u8 *table;
    u32 flags;
    u32 frame;
    u32 color;
    u8 level;
    u8 pad15[3];
    u8 *unit;
    u8 *target;
    BtlAttachV3 scale;
    f32 radius;
    f32 height;
    BtlAttachV3 pos;
    BtlAttachV4 center;
    f32 size;
    u16 count;
    u8 pad56[2];
    u8 **handles;
    BtlAttachV3 cachedPosition;
} BtlAttachWork; /* 0x68 */

#endif
