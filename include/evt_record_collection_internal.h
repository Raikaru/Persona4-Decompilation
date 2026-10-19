#ifndef EVT_RECORD_COLLECTION_INTERNAL_H
#define EVT_RECORD_COLLECTION_INTERNAL_H
#include "type.h"

/* Movie section code 3 uses 0x20-byte records; the type collectors read
 * the two resource values and kind at +0x10, +0x14 and +0x18. */
typedef struct EvtResourceRecord {
    u8 pad00[0x10];
    s32 offset;
    s32 value;
    s32 kind;
    u8 pad1C[4];
} EvtResourceRecord;

/* Inline event-work collections: type 1 at +0x5D8, type 2 at +0x640.
 * Collection limits and the parallel array strides prove these extents. */
typedef struct EvtTypeOneRecords {
    s32 count;
    s32 data[10];
    s16 ids[10];
    s32 values[10];
} EvtTypeOneRecords;
typedef struct EvtTypeTwoRecords {
    s32 count;
    s32 data[5];
    s16 ids[5];
    u8 pad22[2];
    s32 values[5];
} EvtTypeTwoRecords;

/* Packed scene-key coordinates occupy eight bytes at child +8. The following
 * command parameters are copied from file payloads at +0x14 (or +8 in the
 * compact directory). Their interpretation depends on the node kind, so
 * retain the observed byte, halfword, integer and float representations. */
typedef struct EvtRecordPosition {
    s16 x, y, z, w;
} EvtRecordPosition;
typedef union EvtRecordWord {
    s32 word;
    f32 scalar;
    s16 halfword;
    struct { s16 first, second; } halves;
    struct { s8 first, second, third, fourth; } bytes;
} EvtRecordWord;
typedef struct EvtRecordParameters {
    EvtRecordWord unk00;
    EvtRecordWord unk04;
    EvtRecordWord unk08;
    u8 pad0C[0x1C];
} EvtRecordParameters;
#endif
