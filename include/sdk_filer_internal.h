#ifndef SDK_FILER_INTERNAL_H
#define SDK_FILER_INTERNAL_H

#include "type.h"

/* sdkFilerScanDirectory copies and sorts 0x108-byte records after the path. */
typedef struct FilerEntry {
    char name[256];
    s32 type;
    s32 active;
} FilerEntry;

typedef struct FilerTable {
    u8 path[256];
    FilerEntry entries[2000];
    s16 unk80F80;
    s16 selection;
    s16 firstVisible;
    s16 entryCount;
} FilerTable;

/* Each of the 256 request pool slots has a word in-use flag followed by
 * this 0x1D8-byte request, cleared by func_004667d0. Result members are
 * selected by kind in func_004669d0; unknown kinds retain offset names. */
typedef struct FilerRequest {
    u8 *next;
    u8 *previous;
    s32 source;
    u8 *unkC;
    u8 *unk10;
    u8 *unk14;
    u8 *unk18;
    u8 *unk1C;
    s32 resultKind;
    char name[128];
    char path[128];
    char cacheName[128];
    s32 state;
    s32 flags;
    s32 kind;
    s32 unk1B0;
    u8 *unk1B4;
    u8 *unk1B8;
    u8 *unk1BC;
    s32 byteCount;
    s32 buffer;
    u8 *unk1C8;
    s32 memoryKind;
    u8 *unk1D0;
    s16 unk1D4;
    u8 pad1D6[2];
} FilerRequest;

typedef struct FilerRequestSlot {
    s32 inUse;
    FilerRequest request;
} FilerRequestSlot;

#endif
