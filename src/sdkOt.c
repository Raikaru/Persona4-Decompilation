/* Original translation unit sdkOt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "sdk_ot_state_api.h"
#include "sdk_ot_node.h"

extern void kAssertFail(u8 *file, s32 line);
extern u8 *iGpffffba98;   /* gp - 0x4568 = 0x00764b88 */
extern u8 *(*D_008873F8[])(u8 *, s32);
extern void memset(void *, s32, s32);
extern u8 iGpffffaf70;   /* gp - 0x5090 = 0x00764060 */
extern void movieNativeSkyStateEnter(void);


// Intent: Append a node to the tail of an ordering-table list [inferred]
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00460AC0
void PrimAppendNode(u8 *list, u8 *node)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *tail;

    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
}


// Intent: Queue a state-set node (command 2) carrying a state and a value [inferred]
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00460B60
u8 *PrimQueueStateSet(u8 *list, s32 stateId, s32 stateValue)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0xDD);
    }
    ((OtPrimitiveNode *)node)->command = 2;
    ((OtPrimitiveNode *)node)->primitive = stateId;
    ((OtPrimitiveNode *)node)->vertices = (void *)stateValue;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
    return node;
}


// Intent: Queue a state-set node (command 3) carrying a state and a value; same as PrimQueueStateSet with command 3 [inferred]
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00460C70
u8 *PrimQueueStateSetAlt(u8 *list, s32 stateId, s32 stateValue)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0xE7);
    }
    ((OtPrimitiveNode *)node)->command = 3;
    ((OtPrimitiveNode *)node)->primitive = stateId;
    ((OtPrimitiveNode *)node)->vertices = (void *)stateValue;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
    return node;
}


/* Queues a command-four draw-object payload; y_misc stores the returned draw node. */
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00460D80
u8 *sdkOtQueueDrawObject(u8 *list, s32 stateId)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0xF1);
    }
    ((OtPrimitiveNode *)node)->command = 4;
    ((OtPrimitiveNode *)node)->primitive = stateId;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
    return node;
}


/* Queues a command-six clump payload used by field resource clump drawing. */
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00460E80
u8 *sdkOtQueueClump(u8 *list, s32 stateId)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0x106);
    }
    ((OtPrimitiveNode *)node)->command = 6;
    ((OtPrimitiveNode *)node)->primitive = stateId;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
    return node;
}


/* Queues the command-seven clump payload used by FldResource_QueueDrawCallbacksPrimary. */
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00460F80
u8 *sdkOtQueueClumpPrimaryPass(u8 *list, s32 stateId)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0x111);
    }
    ((OtPrimitiveNode *)node)->command = 7;
    ((OtPrimitiveNode *)node)->primitive = stateId;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
    return node;
}


/* Queues the command-eight clump payload used by FldResource_QueueDrawCallbacksSecondary. */
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00461080
u8 *sdkOtQueueClumpSecondaryPass(u8 *list, s32 stateId)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0x11C);
    }
    ((OtPrimitiveNode *)node)->command = 8;
    ((OtPrimitiveNode *)node)->primitive = stateId;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
    return node;
}


// Intent: Queue a node (command 9) whose callback is the sky-state entry routine [inferred]
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00461180
u8 *PrimQueueSkyStateEnter(u8 *list, s32 stateId)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0x127);
    }
    ((OtPrimitiveNode *)node)->command = 9;
    ((OtPrimitiveNode *)node)->primitive = stateId;
    *(u32 *)&((OtPrimitiveNode *)node)->callback = (u32)movieNativeSkyStateEnter;
    ((OtPrimitiveNode *)node)->callbackData = 0;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
    return node;
}


/* Queues the command-ten world payload selected by the field resource world path. */
/* measured: direct tail fields change instructions; typed list aliases retain the byte-pointer representation stores after updating next. */
// FUN_00461290
u8 *sdkOtQueueWorld(u8 *list, s32 stateId)
{
    OtPrimitiveNode *typedList = (OtPrimitiveNode *)list;
    u8 *node;
    u8 *tail;

    node = D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0x131);
    }
    ((OtPrimitiveNode *)node)->command = 0xA;
    ((OtPrimitiveNode *)node)->primitive = stateId;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if ((u8 *)((OtPrimitiveNode *)list)->tail != 0) {
        tail = (u8 *)((OtPrimitiveNode *)list)->tail;
    }
    if ((u8 *)((OtPrimitiveNode *)tail)->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    ((OtPrimitiveNode *)tail)->next = (OtPrimitiveNode *)node;
    if ((u8 *)((OtPrimitiveNode *)node)->tail != 0) {
        *(u8 **)&typedList->tail = (u8 *)((OtPrimitiveNode *)node)->tail;
    } else {
        *(u8 **)&typedList->tail = node;
    }
    return node;
}



/* The vertex buffer is a pointer, matching all source callers. The complete
 * 0x30-byte node and late list view preserve the existing 284 native bytes.
 * See docs/probe_archive/Map_shape_002b0b10_20260924.md. */
// Intent: Queue a draw-primitive node (command 0xB) with a primitive type, vertex buffer and vertex count [inferred]
// FUN_00461390
u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count)
{
    OtPrimitiveNode *node;
    OtPrimitiveNode *tail;
    OtPrimitiveNode *list;

    node = (OtPrimitiveNode *)D_008873F8[0](iGpffffba98, 0x41002);
    memset(node, 0, 0x30);
    if (node == 0) {
        kAssertFail(&iGpffffaf70, 0x13B);
    }
    node->command = 0xB;
    node->primitive = primitive;
    node->vertices = vertices;
    node->count = count;
    /* Interpret the queue links after constructing the primitive payload. */
    list = (OtPrimitiveNode *)inputList;
    tail = list;
    if (list == 0) {
        kAssertFail(&iGpffffaf70, 0xBE);
    }
    if (list->tail != 0) {
        tail = list->tail;
    }
    if (tail->tail != 0) {
        kAssertFail(&iGpffffaf70, 0xC2);
    }
    tail->next = node;
    if (node->tail != 0) {
        list->tail = node->tail;
    } else {
        list->tail = node;
    }
    return (u8 *)node;
}
