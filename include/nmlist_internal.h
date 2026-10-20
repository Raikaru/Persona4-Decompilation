#ifndef NMLIST_INTERNAL_H
#define NMLIST_INTERNAL_H
#include "type.h"

/* nmlist.c allocates 0x18-byte node and 0x28-byte manager prefixes, followed
 * by their inline payloads. The manager embeds its 0x10-byte list at +4. */
typedef struct NmlistNode {
    void *owner;
    u32 unk04;
    s32 size;
    struct NmlistNode *prev;
    struct NmlistNode *next;
    u8 *data;
} NmlistNode;
typedef struct NmlistList {
    NmlistNode *head;
    NmlistNode *tail;
    NmlistNode *cursor;
    u16 count;
    u8 pad0E[2];
} NmlistList;
typedef struct NmlistManager {
    u8 *unk00;
    NmlistList list;
    s32 (*onInsert)();
    s32 (*onRemove)();
    s32 (*onUpdate)();
    u32 size;
    u8 *data;
} NmlistManager;
#endif
