#include "operand_order_internal.h"
#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
#include "kwln_task_internal.h"

/* Entry links and value slots are shared by the setters and list traversal. */
typedef struct SdkLboxEntry {
    s32 id;                         /* 0x000 */
    s32 kind;                       /* 0x004 */
    u8 pad008[0x200];
    s32 referenceValue;             /* 0x208 */
    f32 floatValue;                 /* 0x20c */
    s32 minimum;                    /* 0x210 */
    s32 maximum;                    /* 0x214 */
    u8 pad218[0x10];
    u8 *next;                       /* 0x228 */
} SdkLboxEntry;

typedef struct SdkLboxWork {
    u8 pad000[0x134];
    s32 cursor;                     /* 0x134 */
    s32 scroll;                     /* 0x138 */
    u8 pad13C[4];
    s32 count;                      /* 0x140 */
    u8 *head;                       /* 0x144 */
    s32 unk148;
} SdkLboxWork;
extern MdlNameCallback iGpffffbb2c;
extern MdlTypeCallback iGpffffbb30;
extern MdlNameCallback iGpffffbb34;
extern MdlSetupCallback iGpffffbb38;
extern void (*iGpffffbb3c)();
extern void sdkLboxClear(u8 *task);
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffbb28;
struct RuntimeWork;
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];

extern u8 *sdkLboxFindEntry(u8 *task, s32 key);
extern void sdkLboxRecalcLayout(u8 *task);


extern void sdkListStateSetCount(u8 *state, s32 value);
extern s32 sdkListStateGetCount(u8 *state);
extern s32 sdkListStateGetScroll(u8 *state);
extern s32 sdkListStateGetCursor(u8 *state);
/* measured: retail adds the cursor before the scroll in sdkLboxGetSelectedId, so
 * operandOrderAddReversed keeps that operand order. */


/* Selects reference-value mode and resets the entry's integer range. */
// FUN_00470C10
void sdkLboxSetRefValue(u8 *task, s32 entryId, s32 value)
{
    u8 *node;

    node = sdkLboxFindEntry(task, entryId);
    if (node != NULL) {
        ((SdkLboxEntry *)node)->kind = 2;
        ((SdkLboxEntry *)node)->referenceValue = value;
        ((SdkLboxEntry *)node)->minimum = 0;
        ((SdkLboxEntry *)node)->maximum = 1;
        sdkLboxRecalcLayout(task);
    }
}

/* Selects float-value mode and supplies the entry's range endpoints. */
// FUN_00470C80
void sdkLboxSetFloatRange(u8 *task, s32 entryId, s32 value, s32 minimum, s32 maximum)
{
    u8 *node;

    node = sdkLboxFindEntry(task, entryId);
    if (node != NULL) {
        ((SdkLboxEntry *)node)->kind = 4;
        ((SdkLboxEntry *)node)->floatValue = (f32)value;
        ((SdkLboxEntry *)node)->minimum = minimum;
        ((SdkLboxEntry *)node)->maximum = maximum;
        sdkLboxRecalcLayout(task);
    }
}

/* Finds an entry by ID; -1 is the caller's no-selection sentinel. */
// FUN_00470D10
u8 *sdkLboxFindEntry(u8 *task, s32 key)
{
    u8 *node;

    node = ((SdkLboxWork *)((KwlnTask *)task)->work)->head;
    if (key == -1) {
        return NULL;
    }
    if (node == NULL) {
        return NULL;
    }
    goto compare;
advance:
    node = ((SdkLboxEntry *)node)->next;
    if (node == NULL) {
        return NULL;
    }
compare:
    if (((SdkLboxEntry *)node)->id != key) {
        goto advance;
    }
    return node;
}

/* Frees all entries, then refreshes the cached list-state selection fields. */
// FUN_00470D70
void sdkLboxClear(u8 *task)
{
    u8 *work;
    u8 *node;
    SdkLboxWork *listWork;

    work = ((KwlnTask *)task)->work;
    listWork = (SdkLboxWork *)work;
    node = ((SdkLboxWork *)work)->head;
    while (node != NULL) {
        u8 *next;

        next = ((SdkLboxEntry *)node)->next;
        jtbl_008873EC[0](node);
        node = next;
    }
    listWork->head = NULL;
    ((SdkLboxWork *)work)->unk148 = 0;
    ((SdkLboxWork *)work)->count = 0;
    ((SdkLboxWork *)work)->cursor = 0;
    ((SdkLboxWork *)work)->scroll = 0;
    /* The embedded sdkListState extent is unknown; pass its proven +0x164 start. */
    sdkListStateSetCount(work + 0x164, 0);
    listWork->count = sdkListStateGetCount(work + 0x164);
    listWork->scroll = sdkListStateGetScroll(work + 0x164);
    listWork->cursor = sdkListStateGetCursor(work + 0x164);
}

/* Returns the entry ID at scroll + cursor, or -1 beyond the list count. */
// FUN_00470E20
s32 sdkLboxGetSelectedId(u8 *task)
{
    s32 target;
    s32 index;
    u8 *work;
    u8 *node;

    work = ((KwlnTask *)task)->work;
    node = ((SdkLboxWork *)work)->head;
    target = ((SdkLboxWork *)work)->scroll;
    target = operandOrderAddReversed(target, ((SdkLboxWork *)work)->cursor);
    if (target >= ((SdkLboxWork *)work)->count) {
        return -1;
    }
    index = 0;
    while (index < target) {
        node = ((SdkLboxEntry *)node)->next;
        index += 1;
    }
    return ((SdkLboxEntry *)node)->id;
}

