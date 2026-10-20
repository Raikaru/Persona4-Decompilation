/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "nmlist_internal.h"

typedef int (*code)();

extern NmlistNode *nmListUnlinkNode(int *list, int *node);
extern void FUN_0043f9c8(u32 dest, int value, u32 size);

extern code DAT_008873ec_abs[];

/* Unlink one node, update the source cursor, then notify the owner and release the node storage. */
// FUN_002E2240
NmlistNode *comuDataRemoveAndReleaseNode(NmlistList *owner, NmlistList *source, int *nodeStorage)
{
    NmlistNode *node;
    NmlistList *list2;
    NmlistList *list;
    NmlistNode *next;

    node = (NmlistNode *)nodeStorage;
    list2 = source;
    list = owner;
    next = nmListUnlinkNode((int *)list2, (int *)node);
    if (node == list2->cursor) {
        list2->cursor = (NmlistNode *)next;
    }
    ((NmlistManager *)list)->onRemove((int *)list, (int *)node);
    if (node != 0) {
        FUN_0043f9c8((u32)node, 0, (u32)*(u32 *)&node->size);
        (*(code *)0x008873ec)((int *)node);
    }
    return next;
}

/* Notify the owner and release every source node, then reset the emptied list header. */
// FUN_002E22F0
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
            ((NmlistManager *)owner)->onRemove(owner, node);
            if (node != 0)
            {
                FUN_0043f9c8((u32)node, 0, *(u32 *)&node->size);
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
