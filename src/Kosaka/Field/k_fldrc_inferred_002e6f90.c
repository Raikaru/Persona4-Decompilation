#include "sdk_snd_internal.h"

#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "mdl_effect_internal.h"
#include "kwln_task_internal.h"
#include "fr_font_internal.h"
#include "fcl_object_internal.h"
#include "datPersona_internal.h"
extern void (*jtbl_008873EC[])(void *arg0);
extern u8 *iGpffffb590;
extern u8 D_0063FC80[];
extern u8 D_0063FC90[];
extern void *(*D_008873F4[])(size_t numObj, size_t sizeObj, u32 hint);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void sdkSndFadeOutChannelFrames(s16 channelIndex, s32 requestValue, s32 fadeFrames);
extern s32 datItemMoonGateFirst(s16 itemId);
extern s32 datItemMoonGateSecond(s16 itemId);
/* List indices are halfwords; the count follows the 48 ID slots. */
typedef struct FclItemIdList {
    s16 ids[0x30];
    s16 count;
} FclItemIdList;

/* shopSystemCreate allocates 0x18 bytes and drives the state byte. */
typedef struct ShopSystemWork {
    s8 state;
    u8 pad01[3];
    s32 shopTask;
    u8 unk08[0x10];
} ShopSystemWork;

/* Append an item ID only when it is absent from the 48-entry list. */
// FUN_002E6F90
#pragma push
/* measured: retail's pointer/index loop shape needs loop-invariant hoisting enabled. */
#pragma opt_loop_invariants on
s32 fclListAddUnique(u8 *list, s32 itemId) {
    s32 i = 0;
    s16 item = (s16)itemId;
    s16 count = ((FclItemIdList *)list)->count;

    while ((s16)i < count) {
        if (((FclItemIdList *)list)->ids[(s16)i] == item) {
            return 0;
        }
        i = (s16)(i + 1);
    }
    ((FclItemIdList *)list)->ids[count] = itemId;
    ((FclItemIdList *)list)->count = ((FclItemIdList *)list)->count + 1;
    return 1;
}
#pragma pop

#pragma push
/* measured: retail reloads the retained count while compacting the ID array. The function marks the
 * requested ID empty, compacts the remaining IDs and decrements the count. */
/* Remove every entry matching itemId from the ID list, shift the remaining IDs down to close the
 * gaps, and reduce the count by one. Always return 1. */
// FUN_002E7010
/* measured: retail's block lifetimes need loop-invariant hoisting enabled. */
#pragma opt_loop_invariants on
s32 fclListRemoveId(u8 *list, s16 itemId)
{
    FclItemIdList *itemList = (FclItemIdList *)list;
    u8 retainedCount;
    s16 clearIndex;
    s16 removeIndex;
    s16 removedId;
    s16 value;
    s16 readIndex;
    s16 retainedId;
    u8 writeIndex;
    s16 copyIndex;
    s16 emptyId;
    s16 retainedIds[0x30];

    retainedCount = 0;
    emptyId = -1;
    for (clearIndex = 0; clearIndex < 0x30; clearIndex++) {
        retainedIds[clearIndex] = emptyId;
    }
    emptyId = -1;
    for (removeIndex = 0, removedId = itemId; removeIndex < itemList->count; removeIndex++) {
        if (removedId == ((FclItemIdList *)list)->ids[removeIndex]) {
            ((FclItemIdList *)list)->ids[removeIndex] = emptyId;
        }
    }
    for (readIndex = 0; readIndex < itemList->count; readIndex++) {
        retainedId = ((FclItemIdList *)list)->ids[readIndex];
        if (retainedId != emptyId) {
            retainedIds[retainedCount++] = retainedId;
        }
    }
    writeIndex = 0;
    emptyId = -1;
    for (copyIndex = (s16)0; ((FclItemIdList *)list)->count > copyIndex; copyIndex++) {
        if (retainedIds[copyIndex] != emptyId) {
            ((FclItemIdList *)list)->ids[writeIndex++] = retainedIds[copyIndex];
        }
    }
    itemList->count = ((FclItemIdList *)list)->count - 1;
    return 1;
}
#pragma pop

// FUN_002E7190
void fclFreeWorkBlock(u8 *work) {
    jtbl_008873EC[0](work);
}

/* Unlock eligible moon-phase items and report whether any unlocked item exists. */
// FUN_002E71C0
s32 fclUnlockMoonPhaseItems(void)
{
    s16 item;
    s32 found;
    s16 itemCopy;

    found = 0;
    item = 0x300;
    goto loop_test;
loop_body:
    if (fclItemIsDateAvailable(item) == 1)
    {
        if ((clndGetMoonPhase(itemCopy) & 0xFF) == 0)
        {
            datSetStateTableEntry(item, (clndGetMoonPhase(item) & 0xFF) | 1);
            found = 1;
        }
        else if (((u8)clndGetMoonPhase(itemCopy)) & 1)
        {
            found = 1;
        }
    }
    item++;
loop_test:
    itemCopy = (s16)item;
    if (itemCopy < 0x3FF)
    {
        goto loop_body;
    }
    return (s8)found == 1;
}

/* Drive shop scene loading, fades, shop task creation and eventual scene unloading. */
// FUN_002E72C0
s32 shopSystemUpdate(u8 *task)
{
    ShopSystemWork *shopWork;
    void fieldSceneLoad(s32 fieldId, s32 roomId);
    s32 fadeBeginTransition(s32 mode, s32 duration);
    s32 fadeBeginReturnTransition(s32 mode, s32 duration);
    s32 fadeStatus(void);
    s32 fieldSceneLoadStep(void);
    void fieldSceneUnload(void);
    s32 MT_Scene_GetCameraResFirst(void);
    f32 MT_Scene_GetCameraFov(void);
    s32 mtSceneResListPrepareAll(void);
    s32 fclItemShopCreate(u8 *shopTask);
    u8 *func_003e9cb0(u8 *task, ...);
    s32 kwlnTaskGetTaskByName(s8 *name);
    u8 *kwlnGetCamera(void);
    void K_View_SetFov(void *camera, f32 fov);
    extern s8 D_0063FC68[];
    s8 state;
    u8 *work;
    u8 *view;

    work = ((KwlnTask *)task)->work;

    shopWork = (ShopSystemWork *)work;
    state = ((ShopSystemWork *)work)->state;
    switch (state) {
    case 1:
        fieldSceneLoad(8, 6);
        ((ShopSystemWork *)work)->state = 2;
        /* fallthrough */
    case 2:
        if ((fieldSceneLoadStep() != 0) && (mtSceneResListPrepareAll() != 0)) {
            view = kwlnGetCamera();
            K_View_SetFov(view, MT_Scene_GetCameraFov());
            view = kwlnGetCamera();
            func_003e9cb0(((MdlEffectCamera *)view)->frame, MT_Scene_GetCameraResFirst(), 0);
            ((ShopSystemWork *)work)->state = 3;
            sdkSndPlayCue((s16)0x15, 1);
        }
        goto block_24;
    case 3:
        fadeBeginReturnTransition(1, 0);
        ((ShopSystemWork *)work)->state = 4;
        /* fallthrough */
    case 4:
        if (fadeStatus() != 0) {
            if (((ShopSystemWork *)work)->shopTask != 0) {
                shopWork->shopTask = 0;
            }
            shopWork->shopTask = fclItemShopCreate(task);
            ((ShopSystemWork *)work)->state = 0x22;
        }
        goto block_24;
    case 5:
        fadeBeginTransition(1, 0);
        ((ShopSystemWork *)work)->state = 6;
        /* fallthrough */
    case 6:
        if (fadeStatus() != 0) {
            fieldSceneUnload();
            ((ShopSystemWork *)work)->state = 0x23;
        }
        goto block_24;
    case 34:
        if (kwlnTaskGetTaskByName(D_0063FC68) == 0) {
            fieldSceneUnload();
            ((ShopSystemWork *)work)->state = 0x23;
        }
        goto block_24;
    case 35:
        return -1;
    default:
block_24:
        return 0;
    }
}

// FUN_002E74E0
void shopSystemDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Create the shop controller and black background, then initialize item availability flags. */
// FUN_002E7510
s32 shopSystemCreate(s32 parent)
{
    s32 result;
    u8 *work;
    s32 i;

    chkmemAllocSiteTag(D_0063FC80, 0x11A);
    work = D_008873F4[0](1, 0x18, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)((void *)(parent)), (const void *)((char *)D_0063FC90), 0xF, 0, 0, shopSystemUpdate, shopSystemDestroy, (u8 *)(work));
    iGpffffb590 = NULL;
    iGpffffb590 = (u8 *)fclSpriteSpawnChild(result, fclMakeVec2(0, 0));
    fclSpriteSetPositionBounds(iGpffffb590, fclMakeVec2(0, 0), fclMakeBoundsPacket(640.0f, 448.0f));
    fclSpriteSetCornerColors(iGpffffb590, fclMakeDrawColor(0, 0, 0, 0xFF));
    ((ShopSystemWork *)work)->state = 1;
    sdkSndFadeOutChannelFrames(3, 0, 0x1E);

    for (i = 0; i < 0x2FF; i++) {
        if (((datItemMoonGateFirst((s16)i) & 0xFFF00) >> 8) == 0 &&
            ((datItemMoonGateSecond((s16)i) & 0xFFF00) >> 8) == 0) {
            datSetStateTableEntry(i, (clndGetMoonPhase(i) & 0xFF) | 4);
        } else if ((datItemMoonGateFirst((s16)i) & 0xFF) == 0 &&
                   (datItemMoonGateSecond((s16)i) & 0xFF) == 0) {
            datSetStateTableEntry(i, (clndGetMoonPhase(i) & 0xFF) | 4);
        }
    }
    for (i = 0x300; i < 0x3FF; i++) {
        if ((fclCalendarMonthOrder((u8)datItemAvailableMonth((s16)i)) & 0xFF) <
            (fclCalendarMonthOrder(4) & 0xFF)) {
            datSetStateTableEntry(i, (clndGetMoonPhase(i) & 0xFF) | 4);
        } else if ((fclCalendarMonthOrder((u8)datItemAvailableMonth((s16)i)) & 0xFF) ==
                   (fclCalendarMonthOrder(4) & 0xFF) &&
                   (s8)datItemAvailableDay((s16)i) < 2) {
            datSetStateTableEntry(i, (clndGetMoonPhase(i) & 0xFF) | 4);
        }
    }
    return result;
}
