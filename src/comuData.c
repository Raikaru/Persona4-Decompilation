/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

typedef int (*code)(...);

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

extern NmlistNode *func_002e2080(int *param_1, int *param_2);
extern void FUN_0043f9c8(u32 dest, int value, u32 size);

extern code DAT_008873ec_abs[];

// FUN_002E2240
NmlistNode *func_002e2240(NmlistList *param_1, NmlistList *param_2, int *param_3)
{
    NmlistNode *node;
    NmlistList *list2;
    NmlistList *list;
    NmlistNode *next;

    node = (NmlistNode *)param_3;
    list2 = param_2;
    list = param_1;
    next = func_002e2080((int *)list2, (int *)node);
    if (node == list2->cursor) {
        list2->cursor = (NmlistNode *)next;
    }
    (*(code *)((u8 *)list + 0x18))((int *)list, (int *)node);
    if (node != 0) {
        FUN_0043f9c8((u32)node, 0, (u32)node->unk0[2]);
        (*(code *)0x008873ec)((int *)node);
    }
    return next;
}

// FUN_002E22F0
void func_002e22f0(int param_1, int param_2)
{
    NmlistList *list;
    NmlistNode *node;
    NmlistNode *next;

    if (param_1 != 0 && param_2 != 0)
    {
        list = (NmlistList *)param_2;
        node = list->head;
        while (node != 0)
        {
            next = node->next;
            (*(code *)((u8 *)param_1 + 0x18))(param_1, node);
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
