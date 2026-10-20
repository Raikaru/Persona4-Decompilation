#ifndef FCL_ASSIST_INTERNAL_H
#define FCL_ASSIST_INTERNAL_H

#include "type.h"

/* Layouts shared by the message-assist queue and its sprite-loading queue.
 * fclMiscCreateAssistTask allocates 0xA0 bytes: a 0x1C prefix and eleven
 * 0x0C slots. fclMiscAddRecord allocates each 0x30-byte queued entry. */
typedef struct FclAssistHandle {
    s32 handle;
    s8 mode;
    s8 suspended;
    u8 pad06[2];
    s32 pending;
    s8 unk0c;
    s8 unk0d;
    u8 pad0e[2];
} FclAssistHandle;

typedef struct FclAssistSlot {
    s32 flags;
    s32 index;
    s32 sprite;
} FclAssistSlot;

typedef struct FclAssistNode {
    u8 pad00[0x10];
    struct FclAssistNode *next;
    void *data;
} FclAssistNode;

typedef struct FclAssistList {
    u8 pad00[4];
    FclAssistNode *head;
    u8 pad08[8];
    u16 count;
    u8 pad12[0x12];
    void *work;
} FclAssistList;

typedef struct FclAssistEntry {
    FclAssistNode *node;
    s32 flags;
    u8 pad08[6];
    s16 unk0e;
    FclAssistHandle window;
    s32 record;
    s32 unk24;
    s32 source;
    s32 slotIndex;
} FclAssistEntry;

typedef struct FclAssistManager {
    FclAssistList *entries;
    s32 flags;
    u8 pad08[4];
    s32 source;
    u8 pad10[4];
    u32 stateFlags;
    FclAssistList *pending;
    FclAssistSlot slots[11];
} FclAssistManager;

#endif
