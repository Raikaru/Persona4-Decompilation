#ifndef ITF_MES_OBJECTS_H
#define ITF_MES_OBJECTS_H

#include "type.h"
#include "fr_font_objects.h"

/* EE message data stores addresses in 32-bit words. Keep the signed handle,
 * unsigned mask and pointer accesses used by the original readers/writers. */
typedef union ItfMesWord {
    s32 value;
    u32 bits;
    u8 *bytes;
    s32 *words;
} ItfMesWord;
typedef union ItfMesByte {
    s8 value;
    u8 bits;
} ItfMesByte;

/* Reset by itfMesSlotReset; embedded at window +0x14. */
typedef struct ItfMesLabel {
    ItfMesWord list;
    u16 index;
    u8 pad06[2];
} ItfMesLabel;

/* Reset by itfMesRecordReset; embedded at window +0x1C. */
typedef struct ItfMesRow {
    ItfMesWord record;
    ItfMesWord list;
    ItfMesByte state;
    ItfMesByte flags;
    ItfMesByte style;
    ItfMesByte palette;
    ItfMesByte effect;
    ItfMesByte intensity;
    s16 lineCount;
    s16 index;
    s16 count;
    ItfMesWord elapsed;
    s16 transition;
    u8 pad1A[6];
} ItfMesRow;

typedef struct ItfMesInputBinding {
    s16 button;
    s16 entry;
} ItfMesInputBinding;

/* Reset by itfMesEntryReset; 16 four-byte bindings fill +0x18..+0x57. */
typedef struct ItfMesSelection {
    ItfMesWord recordIndex;
    ItfMesWord list;
    ItfMesWord hiddenMask;
    s16 state;
    s16 cursor;
    s16 selected;
    s16 count;
    s16 alpha;
    s16 bindingCount;
    ItfMesInputBinding bindings[16];
} ItfMesSelection;

/* itfMesWindowSetProcedure clears 0x1C bytes. The four parameters are accessed
 * by itfMsgProcedure; dispatch wrappers store the current operation at +0x14. */
typedef struct ItfMesProcedure {
    s32 (*callback)(s32, s32);
    s32 parameters[4];
    s32 operation;
    void *userdata;
} ItfMesProcedure;

/* itfMesObjectCreate allocates/clears 0x130 bytes. All embedded boundaries
 * follow its reset calls and the corresponding row/selection/slot readers. */
typedef struct ItfMesWindow {
    /* Packed phase groups: row 0x7, choice 0x38, transitions 0x300/0xC00.
     * High-word mode bits are manipulated separately by the public setters. */
    ItfMesWord flags;
    ItfMesWord record;
    ItfMesWord font;
    ItfMesWord value;
    ItfMesWord kind;
    ItfMesLabel label;
    ItfMesRow row;
    ItfMesSelection selection;
    ItfMesWord slots[32];
    ItfMesProcedure procedure;
} ItfMesWindow;

/* fmGslContPoolInit uses 0x20-byte entries; install uses four object slots. */
typedef struct ItfMesManagerEntry {
    ItfMesWord previous;
    ItfMesWord next;
    ItfMesWord handle;
    ItfMesWord object;
    ItfMesWord slots[4];
} ItfMesManagerEntry;

/* Manager globals start at 0x008817E0; the pool entries begin at +0x1C. */
typedef struct ItfMesManager {
    s32 windowCount;
    u32 flushCount;
    u16 flags;
    u8 pad0A[2];
    ItfMesWord activeHead;
    ItfMesWord activeTail;
    ItfMesWord freeHead;
    ItfMesWord freeTail;
    ItfMesManagerEntry entries[64];
} ItfMesManager;

/* MSG0/MSG1 header validated by itfMesRecordIsValid and fixed up in place. */
typedef struct ItfMesRecordEntry {
    s32 kind;
    ItfMesWord data;
} ItfMesRecordEntry;
typedef struct ItfMesRecord {
    u8 pad00[8];
    u32 magic;
    u8 pad0C[4];
    s32 relocationOffset;
    s32 relocationSize;
    s32 entryCount;
    u8 relocated;
    u8 pad1D[3];
    ItfMesRecordEntry entries[1];
} ItfMesRecord;

/* The variable entry table is followed by the label-name table and font data. */
typedef struct ItfMesRecordTail {
    ItfMesWord names;
    s32 unk04;
    ItfMesWord font;
} ItfMesRecordTail;

/* The two on-disc record kinds have distinct text-table starts. */
typedef struct ItfMesTextRecord {
    u8 pad00[0x18];
    s16 count;
    u16 labelIndex;
    ItfMesWord texts[1];
} ItfMesTextRecord;
typedef struct ItfMesChoiceRecord {
    u8 pad00[0x1A];
    s16 count;
    u8 pad1C[4];
    ItfMesWord texts[1];
} ItfMesChoiceRecord;

typedef char ItfMesRowSizeCheck[sizeof(ItfMesRow) == 0x20 ? 1 : -1];
typedef char ItfMesSelectionSizeCheck[sizeof(ItfMesSelection) == 0x58 ? 1 : -1];
typedef char ItfMesProcedureSizeCheck[sizeof(ItfMesProcedure) == 0x1C ? 1 : -1];
typedef char ItfMesWindowSizeCheck[sizeof(ItfMesWindow) == 0x130 ? 1 : -1];
typedef char ItfMesManagerEntrySizeCheck[sizeof(ItfMesManagerEntry) == 0x20 ? 1 : -1];


/* Existing callers supply these inputs; unused inputs are retained explicitly. */
void itfMesSlotReset(u8 *record, s32 unusedIndex);
void itfMesRecordReset(u8 *record, s32 unusedIndex);

#endif
