#ifndef MEMCARD_SUMMARY_INTERNAL_H
#define MEMCARD_SUMMARY_INTERNAL_H

#include "type.h"

/* Sixteen fixed 0x34-byte summaries follow the card table's sixteen state words.
 * H_Memcard_LoadStep checks the low-byte sum of bytes [0, 0x32) against checksum. */
typedef struct McSaveRecord {
    s16 day;
    s16 unk02;
    u32 playFrames;
    u8 level, mode, special, pad0B;
    u8 firstName[0x12];
    u8 secondName[0x12];
    u8 area, room;
    u16 checksum;
} McSaveRecord;

#endif
