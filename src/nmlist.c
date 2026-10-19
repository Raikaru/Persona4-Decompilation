#include "include_asm.h"
/* Original translation unit nmlist.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void chkmemAllocSiteTag(const void *msg, s32 id);
void kAssertFail(const void *file, s32 line);
void memset(void *dst, s32 value, u32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_0063FC38[];

typedef int (*code)();

typedef struct NmlistNode {
    void *owner;
    u32 unk4;
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
} NmlistList;
typedef struct NmlistManager {
    u8 *unk0;
    NmlistList list;
    code onInsert;
    code onRemove;
    code onUpdate;
    u32 size;
    u8 *data;
} NmlistManager;

void comuDataClearList(int managerAddress, int listAddress);

/* Allocate a list node with an optional inline payload after its 0x18-byte header. */
// FUN_002E1D00
u8 *nmListAllocNode(s32 payloadSize) {
    s32 size;
    u8 *node;

    size = payloadSize + 0x18;
    chkmemAllocSiteTag(&D_0063FC38, 0x5C);
    node = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (node == NULL) {
        kAssertFail(&D_0063FC38, 0x5E);
    }
    memset(node, 0, size);
    if (payloadSize != 0) {
        ((NmlistNode *)node)->data = node + 0x18;
    }
    ((NmlistNode *)node)->size = size;
    return node;
}

void func_002e1cd0(void);
void func_002e1ce0(void);
void func_002e1cf0(void);

/* Allocate a list manager and install supplied callbacks or the default callbacks. */
// FUN_002E1DB0
u8 *nmListAllocManager(s32 payloadSize, code onInsert, code onRemove, code onUpdate) {
    s32 size;
    u8 *node;

    size = payloadSize + 0x28;
    chkmemAllocSiteTag(&D_0063FC38, 0x33);
    node = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (node == NULL) {
        kAssertFail(&D_0063FC38, 0x35);
    }
    memset(node, 0, size);
    if (payloadSize != 0) {
        ((NmlistManager *)node)->data = node + 0x28;
    }
    ((NmlistManager *)node)->size = size;
    if (onInsert != NULL) {
        ((NmlistManager *)node)->onInsert = onInsert;
    } else {
        ((NmlistManager *)node)->onInsert = (code)func_002e1cd0;
    }
    if (onRemove != NULL) {
        ((NmlistManager *)node)->onRemove = onRemove;
    } else {
        ((NmlistManager *)node)->onRemove = (code)func_002e1ce0;
    }
    if (onUpdate != NULL) {
        ((NmlistManager *)node)->onUpdate = onUpdate;
    } else {
        ((NmlistManager *)node)->onUpdate = (code)func_002e1cf0;
    }
    return node;
}

/* Release the manager's list, clear its allocation, then free the manager. */
// FUN_002E1EF0
void nmListDestroyManager(u8 *manager) {
    comuDataClearList((int)manager, (int)(manager + 4));
    if (manager == NULL) {
        kAssertFail(&D_0063FC38, 0x49);
    }
    memset(manager, 0, ((NmlistManager *)manager)->size);
    (*jtbl_008873EC)(manager);
}

/* Link a node after the requested predecessor, or at the head when it is NULL. */
// FUN_002E1F70
void nmListInsertAfter(NmlistList *list, NmlistNode *after, NmlistNode *node) {
    if (list == NULL) {
        kAssertFail(&D_0063FC38, 0x113);
    }
    list->count++;
    if (node != NULL) {
        node->next = NULL;
        node->prev = NULL;
        if (after == NULL) {
            if (list->head != NULL) {
                node->prev = NULL;
                node->next = list->head;
                list->head->prev = node;
            }
            list->head = node;
            if (list->tail == NULL) {
                list->tail = node;
            }
        } else if (after->next != NULL) {
            node->prev = after;
            node->next = after->next;
            after->next = node;
            node->next->prev = node;
        } else {
            node->prev = after;
            node->next = NULL;
            after->next = node;
            list->tail = node;
        }
        if (list->cursor == NULL) {
            list->cursor = node;
        }
    }
}

/* Unlink a node and return the adjacent node selected by the retail traversal. */
// FUN_002E2080
NmlistNode *nmListUnlinkNode(NmlistList *list, NmlistNode *node) {
    NmlistNode *adjacent;
    NmlistNode *next;

    if (list == NULL) {
        kAssertFail(&D_0063FC38, 0x147);
    }
    if (node == NULL) {
        kAssertFail(&D_0063FC38, 0x148);
    }
    list->count--;
    adjacent = node->prev;
    if (adjacent == NULL) {
        adjacent = node->next;
        if (adjacent == NULL) {
            if (list->head == node) {
                list->cursor = NULL;
                list->tail = NULL;
                list->head = NULL;
            }
            adjacent = NULL;
        } else {
            adjacent->prev = NULL;
            list->head = adjacent;
        }
    } else {
        next = node->next;
        if (next == NULL) {
            adjacent->next = NULL;
            list->tail = adjacent;
        } else {
            adjacent->next = next;
            next->prev = adjacent;
            adjacent = adjacent->next;
        }
    }
    node->prev = NULL;
    node->next = NULL;
    return adjacent;
}

/* Allocate and append a node, then notify the manager's insertion callback. */
// FUN_002E2170
u8 *nmListAppendNode(u8 *manager, u8 *owner, s32 payloadSize) {
    u8 *node;

    if (manager == NULL) {
        kAssertFail(&D_0063FC38, 0x17B);
    }
    node = nmListAllocNode(payloadSize);
    if (owner == NULL) {
        ((NmlistNode *)node)->owner = node;
    } else {
        ((NmlistNode *)node)->owner = owner;
    }
    if (node == NULL) {
        kAssertFail(&D_0063FC38, 0x17E);
    }
    nmListInsertAfter((NmlistList *)(manager + 4), ((NmlistManager *)manager)->list.tail, (NmlistNode *)node);
    (((NmlistManager *)manager)->onInsert)(manager, node);
    return node;
}