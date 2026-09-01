#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit nmlist.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0044ea90(const void *msg, s32 id);
void func_0046d730(const void *file, s32 line);
void func_0043f9c8(void *dst, s32 value, u32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_0063FC38[];

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
typedef struct NmlistManager {
    u8 *unk0;
    NmlistList list;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 size;
} NmlistManager;

void func_002e22f0(int param_1, int param_2);

// FUN_002E1D00
u8 *func_002e1d00(s32 arg0) {
    s32 size;
    u8 *node;

    size = arg0 + 0x18;
    func_0044ea90(&D_0063FC38, 0x5C);
    node = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (node == NULL) {
        func_0046d730(&D_0063FC38, 0x5E);
    }
    func_0043f9c8(node, 0, size);
    if (arg0 != 0) {
        *(u8 **)(node + 0x14) = node + 0x18;
    }
    *(s32 *)(node + 8) = size;
    return node;
}

void func_002e1cd0(void);
void func_002e1ce0(void);
void func_002e1cf0(void);

// FUN_002E1DB0
u8 *func_002e1db0(s32 arg0, code arg1, code arg2, code arg3) {
    s32 size;
    u8 *node;

    size = arg0 + 0x28;
    func_0044ea90(&D_0063FC38, 0x33);
    node = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    if (node == NULL) {
        func_0046d730(&D_0063FC38, 0x35);
    }
    func_0043f9c8(node, 0, size);
    if (arg0 != 0) {
        *(u8 **)(node + 0x24) = node + 0x28;
    }
    *(s32 *)(node + 0x20) = size;
    if (arg1 != NULL) {
        *(code *)(node + 0x14) = arg1;
    } else {
        *(code *)(node + 0x14) = (code)func_002e1cd0;
    }
    if (arg2 != NULL) {
        *(code *)(node + 0x18) = arg2;
    } else {
        *(code *)(node + 0x18) = (code)func_002e1ce0;
    }
    if (arg3 != NULL) {
        *(code *)(node + 0x1C) = arg3;
    } else {
        *(code *)(node + 0x1C) = (code)func_002e1cf0;
    }
    return node;
}

// FUN_002E1EF0
void func_002e1ef0(u8 *arg0) {
    func_002e22f0((int)arg0, (int)(arg0 + 4));
    if (arg0 == NULL) {
        func_0046d730(&D_0063FC38, 0x49);
    }
    func_0043f9c8(arg0, 0, ((NmlistManager *)arg0)->size);
    (*jtbl_008873EC)(arg0);
}

// FUN_002E1F70
void func_002e1f70(NmlistList *list, NmlistNode *after, NmlistNode *node) {
    if (list == NULL) {
        func_0046d730(&D_0063FC38, 0x113);
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

// FUN_002E2080
NmlistNode *func_002e2080(NmlistList *list, NmlistNode *node) {
    NmlistNode *var_2;
    NmlistNode *temp_3;

    if (list == NULL) {
        func_0046d730(&D_0063FC38, 0x147);
    }
    if (node == NULL) {
        func_0046d730(&D_0063FC38, 0x148);
    }
    list->count--;
    var_2 = node->prev;
    if (var_2 == NULL) {
        var_2 = node->next;
        if (var_2 == NULL) {
            if (list->head == node) {
                list->cursor = NULL;
                list->tail = NULL;
                list->head = NULL;
            }
            var_2 = NULL;
        } else {
            var_2->prev = NULL;
            list->head = var_2;
        }
    } else {
        temp_3 = node->next;
        if (temp_3 == NULL) {
            var_2->next = NULL;
            list->tail = var_2;
        } else {
            var_2->next = temp_3;
            temp_3->prev = var_2;
            var_2 = var_2->next;
        }
    }
    node->prev = NULL;
    node->next = NULL;
    return var_2;
}

// FUN_002E2170
u8 *func_002e2170(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *node;

    if (arg0 == NULL) {
        func_0046d730(&D_0063FC38, 0x17B);
    }
    node = func_002e1d00(arg2);
    if (arg1 == NULL) {
        *(u8 **)(node + 0) = node;
    } else {
        *(u8 **)(node + 0) = arg1;
    }
    if (node == NULL) {
        func_0046d730(&D_0063FC38, 0x17E);
    }
    func_002e1f70((NmlistList *)(arg0 + 4), *(NmlistNode **)(arg0 + 8), (NmlistNode *)node);
    (*(code *)(arg0 + 0x14))(arg0, node);
    return node;
}