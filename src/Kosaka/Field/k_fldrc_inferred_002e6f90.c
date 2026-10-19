/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Kosaka/Field/k_fldrc.c; members 002e6f90-002e7510 */

#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fr_font_internal.h"
#include "fcl_object_internal.h"
#include "datPersona_internal.h"
extern void (*jtbl_008873EC[])(void *arg0);
extern u8 *iGpffffb590;
extern u8 D_0063FC80[];
extern u8 D_0063FC90[];
extern void *(*D_008873F4[])(size_t numObj, size_t sizeObj, u32 hint);
extern void chkmemAllocSiteTag(const void *arg0, u32 arg1);
extern void sdkSndFadeOutChannelFrames(s16 arg0, s32 arg1, s32 arg2);
extern s32 datItemMoonGateFirst(s16 arg0);
extern s32 datItemMoonGateSecond(s16 arg0);
// FUN_002E6F90
#pragma opt_loop_invariants on
s32 fclListAddUnique(u8 *arg0, s32 arg1) {
    s32 i = 0;
    s16 val = (s16)arg1;
    s16 n = *(s16 *)(arg0 + 0x60);

    while ((s16)i < n) {
        if (*(s16 *)(arg0 + (s16)i * 2) == val) {
            return 0;
        }
        i = (s16)(i + 1);
    }
    *(s16 *)(arg0 + n * 2) = arg1;
    *(s16 *)(arg0 + 0x60) = *(s16 *)(arg0 + 0x60) + 1;
    return 1;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_002E7010
s32 fclListRemoveId(u8 *arg0, s16 arg1)
{
    u8 v2;
    s16 i;
    s16 v4;
    s16 v5;
    s16 v7;
    s16 j;
    s16 v9;
    u8 v10;
    s16 k;
    s16 minus_one;
    s16 temp[0x30];

    v2 = 0;
    minus_one = -1;
    for (i = 0; i < 0x30; i++) {
        temp[i] = minus_one;
    }
    minus_one = -1;
    for (v4 = 0, v5 = arg1; v4 < *(s16 *)(arg0 + 0x60); v4++) {
        if (v5 == *(s16 *)(arg0 + v4 * 2)) {
            *(s16 *)(arg0 + v4 * 2) = minus_one;
        }
    }
    for (j = 0; j < *(s16 *)(arg0 + 0x60); j++) {
        v9 = *(s16 *)(arg0 + j * 2);
        if (v9 != minus_one) {
            temp[v2++] = v9;
        }
    }
    v10 = 0;
    minus_one = -1;
    for (k = (s16)0; *(s16 *)(arg0 + 0x60) > k; k++) {
        if (temp[k] != minus_one) {
            *(s16 *)(arg0 + v10++ * 2) = temp[k];
        }
    }
    *(s16 *)(arg0 + 0x60) = *(s16 *)(arg0 + 0x60) - 1;
    return 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_002E7190
void fclFreeWorkBlock(u8 *arg0) {
    jtbl_008873EC[0](arg0);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_002E72C0
s32 shopSystemUpdate(u8 *arg0)
{
    void fieldSceneLoad(s32 arg0, s32 arg1);
    s32 fadeBeginTransition(s32 arg0, s32 arg1);
    s32 fadeBeginReturnTransition(s32 arg0, s32 arg1);
    s32 fadeStatus(void);
    s32 fieldSceneLoadStep(void);
    void fieldSceneUnload(void);
    s32 MT_Scene_GetCameraResFirst(void);
    f32 MT_Scene_GetCameraFov(void);
    s32 mtSceneResListPrepareAll(void);
    s32 fclItemShopCreate(u8 *arg0);
    u8 *func_003e9cb0(u8 *arg0, ...);
    s32 kwlnTaskGetTaskByName(s8 *arg0);
    u8 *kwlnGetCamera(void);
    void K_View_SetFov(void *arg0, f32 arg1);
    s32 sdkSndPlayCue(s16 arg0, ...);
    extern s8 D_0063FC68[];
    s8 state;
    u8 *work;
    u8 *view;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s8 *)work;
    switch (state) {
    case 1:
        fieldSceneLoad(8, 6);
        *(s8 *)work = 2;
        /* fallthrough */
    case 2:
        if ((fieldSceneLoadStep() != 0) && (mtSceneResListPrepareAll() != 0)) {
            view = kwlnGetCamera();
            K_View_SetFov(view, MT_Scene_GetCameraFov());
            view = kwlnGetCamera();
            func_003e9cb0(*(u8 **)(view + 4), MT_Scene_GetCameraResFirst(), 0);
            *(s8 *)work = 3;
            sdkSndPlayCue((s16)0x15, 1);
        }
        goto block_24;
    case 3:
        fadeBeginReturnTransition(1, 0);
        *(s8 *)work = 4;
        /* fallthrough */
    case 4:
        if (fadeStatus() != 0) {
            if (*(s32 *)(work + 4) != 0) {
                *(s32 *)(work + 4) = 0;
            }
            *(s32 *)(work + 4) = fclItemShopCreate(arg0);
            *(s8 *)work = 0x22;
        }
        goto block_24;
    case 5:
        fadeBeginTransition(1, 0);
        *(s8 *)work = 6;
        /* fallthrough */
    case 6:
        if (fadeStatus() != 0) {
            fieldSceneUnload();
            *(s8 *)work = 0x23;
        }
        goto block_24;
    case 34:
        if (kwlnTaskGetTaskByName(D_0063FC68) == 0) {
            fieldSceneUnload();
            *(s8 *)work = 0x23;
        }
        goto block_24;
    case 35:
        return -1;
    default:
block_24:
        return 0;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_002E74E0
void shopSystemDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_002E7510
s32 shopSystemCreate(s32 arg0)
{
    s32 result;
    u8 *work;
    s32 i;

    chkmemAllocSiteTag(D_0063FC80, 0x11A);
    work = D_008873F4[0](1, 0x18, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)((void *)(arg0)), (const void *)((char *)D_0063FC90), 0xF, 0, 0, shopSystemUpdate, shopSystemDestroy, (u8 *)(work));
    iGpffffb590 = NULL;
    iGpffffb590 = (u8 *)fclSpriteSpawnChild(result, fclMakeVec2(0, 0));
    fclSpriteSetPositionBounds(iGpffffb590, fclMakeVec2(0, 0), fclMakeBoundsPacket(640.0f, 448.0f));
    fclSpriteSetCornerColors(iGpffffb590, fclMakeDrawColor(0, 0, 0, 0xFF));
    *work = 1;
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
#pragma pop
