/* Consolidated Persona 4 source units. */
/* Original translation unit sdkOt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0046d730(u8 *file, s32 line);
extern u8 *iGpffffba98;   /* gp - 0x4568 = 0x00764b88 */
extern u8 *(*D_008873F8[])(u8 *, s32);
extern void func_0043f9c8(void *, s32, s32);
extern u8 iGpffffaf70;   /* gp - 0x5090 = 0x00764060 */
extern void func_004614b0(void);


// FUN_00460AC0
void func_00460ac0(u8 *list, u8 *node)
{
    u8 *tail;

    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
}


// FUN_00460B60
u8 *func_00460b60(u8 *list, s32 arg1, s32 arg2)
{
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0xDD);
    }
    *(u16 *)(node + 0x18) = 2;
    *(u32 *)(node + 0x1C) = arg1;
    *(u32 *)(node + 0x20) = arg2;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
    return node;
}


// FUN_00460C70
u8 *func_00460c70(u8 *list, s32 arg1, s32 arg2)
{
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0xE7);
    }
    *(u16 *)(node + 0x18) = 3;
    *(u32 *)(node + 0x1C) = arg1;
    *(u32 *)(node + 0x20) = arg2;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
    return node;
}


// FUN_00460D80
u8 *func_00460d80(u8 *list, s32 arg1)
{
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0xF1);
    }
    *(u16 *)(node + 0x18) = 4;
    *(u32 *)(node + 0x1C) = arg1;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
    return node;
}


// FUN_00460E80
u8 *func_00460e80(u8 *list, s32 arg1)
{
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0x106);
    }
    *(u16 *)(node + 0x18) = 6;
    *(u32 *)(node + 0x1C) = arg1;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
    return node;
}


// FUN_00460F80
u8 *func_00460f80(u8 *list, s32 arg1)
{
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0x111);
    }
    *(u16 *)(node + 0x18) = 7;
    *(u32 *)(node + 0x1C) = arg1;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
    return node;
}


// FUN_00461080
u8 *func_00461080(u8 *list, s32 arg1)
{
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0x11C);
    }
    *(u16 *)(node + 0x18) = 8;
    *(u32 *)(node + 0x1C) = arg1;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
    return node;
}


// FUN_00461180
u8 *func_00461180(u8 *list, s32 arg1)
{
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0x127);
    }
    *(u16 *)(node + 0x18) = 9;
    *(u32 *)(node + 0x1C) = arg1;
    *(u32 *)(node + 0x8) = (u32)func_004614b0;
    *(u32 *)(node + 0x10) = 0;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
    return node;
}


// FUN_00461290
u8 *func_00461290(u8 *list, s32 arg1)
{
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0x131);
    }
    *(u16 *)(node + 0x18) = 0xA;
    *(u32 *)(node + 0x1C) = arg1;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
    return node;
}


typedef struct OtPrimitiveNode OtPrimitiveNode;
struct OtPrimitiveNode {
    OtPrimitiveNode *next;
    OtPrimitiveNode *tail;
    void (*callback)(void *, void *);
    u32 reserved0C;
    void *callbackData;
    u32 reserved14;
    u16 command;
    u16 reserved1A;
    s32 primitive;
    void *vertices;
    s32 count;
    u32 reserved28[2];
};
typedef char OtPrimitiveNodeSize[(sizeof(OtPrimitiveNode) == 0x30) ? 1 : -1];

/* The vertex buffer is a pointer, matching all source callers. The complete
 * 0x30-byte node and late list view preserve the existing 284 native bytes.
 * See docs/probe_archive/Map_shape_002b0b10_20260924.md. */
// FUN_00461390
u8 *func_00461390(void *inputList, s32 primitive, void *vertices, s32 count)
{
    OtPrimitiveNode *node;
    OtPrimitiveNode *tail;
    OtPrimitiveNode *list;

    node = (OtPrimitiveNode *)D_008873F8[0](iGpffffba98, 0x41002);
    func_0043f9c8(node, 0, 0x30);
    if (node == 0) {
        func_0046d730(&iGpffffaf70, 0x13B);
    }
    node->command = 0xB;
    node->primitive = primitive;
    node->vertices = vertices;
    node->count = count;
    /* Interpret the queue links after constructing the primitive payload. */
    list = (OtPrimitiveNode *)inputList;
    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (list->tail != 0) {
        tail = list->tail;
    }
    if (tail->tail != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    tail->next = node;
    if (node->tail != 0) {
        list->tail = node->tail;
    } else {
        list->tail = node;
    }
    return (u8 *)node;
}
