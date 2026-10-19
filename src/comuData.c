/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

typedef int (*code)();

typedef struct NmlistNode {
    u32 unk0[3];
    struct NmlistNode *prev;
    struct NmlistNode *next;
} NmlistNode;
typedef struct NmlistList {
    NmlistNode *head;
    NmlistNode *tail;
    NmlistNode *cursor;
    u16 count;
} NmlistList;

extern NmlistNode *func_002e2080(int *owner, int *source);
extern void FUN_0043f9c8(u32 dest, int value, u32 size);

extern code DAT_008873ec_abs[];

// FUN_002E2240
/* Unlink one node, update the source cursor, then notify the owner and release the node storage. */
NmlistNode *comuDataRemoveAndReleaseNode(NmlistList *owner, NmlistList *source, int *nodeStorage)
{
    NmlistNode *node;
    NmlistList *list2;
    NmlistList *list;
    NmlistNode *next;

    node = (NmlistNode *)nodeStorage;
    list2 = source;
    list = owner;
    next = func_002e2080((int *)list2, (int *)node);
    if (node == list2->cursor) {
        list2->cursor = (NmlistNode *)next;
    }
    /* +0x18 is the owner release callback; typed member access changed retail codegen. */
    (*(code *)((u8 *)list + 0x18))((int *)list, (int *)node);
    if (node != 0) {
        FUN_0043f9c8((u32)node, 0, (u32)node->unk0[2]);
        /* +0x18 is the owner release callback; typed member access changed retail codegen. */
    (*(code *)0x008873ec)((int *)node);
    }
    return next;
}

// FUN_002E22F0
/* Notify the owner and release every source node, then reset the emptied list header. */
void comuDataClearList(int owner, int source)
{
    NmlistList *list;
    NmlistNode *node;
    NmlistNode *next;

    if (owner != 0 && source != 0)
    {
        list = (NmlistList *)source;
        node = list->head;
        while (node != 0)
        {
            next = node->next;
            /* +0x18 is the owner release callback; typed member access changed retail codegen. */
    (*(code *)((u8 *)owner + 0x18))(owner, node);
            if (node != 0)
            {
                FUN_0043f9c8((u32)node, 0, node->unk0[2]);
                DAT_008873ec_abs[0](node);
            }
            node = next;
        }
        list->count = 0;
        list->cursor = 0;
        list->tail = 0;
        list->head = 0;
    }
}
