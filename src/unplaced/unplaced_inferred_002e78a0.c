/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 002e78a0-002e82b0 */

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
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern u32 datGetMoney(void);
s16 datGetDateIndex(void);
void calSplitDayOfYear(s64 arg0, s32 *arg1, s32 *arg2);
s32 fclAddClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void datSetMoney(s32 arg0);
#pragma push
#pragma opt_loop_invariants off
// FUN_002E78A0
u8 fclCalendarMonth(void)
{
    s32 sp1C;
    s32 sp18;

    calSplitDayOfYear(datGetDateIndex(), &sp18, &sp1C);
    return sp18;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
/* Retail returns the low day byte with lbu, defining the full result. */
// FUN_002E78E0
s32 fclCalendarDay(void)
{
    s32 sp1C;
    s32 sp18;

    calSplitDayOfYear(datGetDateIndex(), &sp18, &sp1C);
    return (u8)sp1C;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_002E7920
void fclCalGetNextDate(s32 *arg0, s32 *arg1)
{
    s32 calGetMonthLength(s32 arg0);
    s32 fclAddClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
    s32 *out0;
    u8 count;
    s32 *out1;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;

    out0 = arg0;
    count = 0;
    out1 = arg1;

    calSplitDayOfYear(datGetDateIndex(), (s32 *)&sp60, (s32 *)&sp64);
    count = *(u8 *)&sp64;
    calSplitDayOfYear(datGetDateIndex(), (s32 *)&sp68, (s32 *)&sp6C);
    if (calGetMonthLength(*(u8 *)&sp68) < (count + 1)) {
        calSplitDayOfYear(datGetDateIndex(), &sp58, &sp5C);
        *out0 = fclAddClamped(*(u8 *)&sp58, 1, 0xC, 1, 2);
        *out1 = 1;
        return;
    }
    calSplitDayOfYear(datGetDateIndex(), &sp50, &sp54);
    *out0 = *(u8 *)&sp50;
    calSplitDayOfYear(datGetDateIndex(), &sp48, &sp4C);
    *out1 = *(u8 *)&sp4C + 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_002E7A60
u32 fclGetMoney(void)
{
    return datGetMoney();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_002E7A80
void fclAddMoney(s32 arg0)
{
    datSetMoney(fclAddClamped(arg0, 0, 0x98967F, 0, 1));
}
#pragma pop

#define P4_002E7AC0_DRAW() \
    do { \
        if ((s16)fclSpriteFlagBit(*(s16 *)(fclSpriteEntry(105) + 0x10), 0) == 1) { \
            frFontExDrawTextDeferredOutB(*(f32 *)(fclSpriteEntry(105) + 0x38) + 52.0f, 41.0f, 88.0f, \
                          fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0, 1, \
                          (const char *)datPersonaNamePart1(1), 0, 0, D_00794E70, 24); \
        } \
    } while (0)

#pragma push
#pragma opt_loop_invariants off
// Fcl combine menu update: runs the menu state machine (draws the text and returns a status).
// FUN_002E7AC0
s32 fclCombineMenuUpdate(u8 *arg0)
{
    void fclCombineMenuRoot(u8 *arg0);
    u8 *fclSpriteEntry(s16 arg0);
    s16 fclSpriteFlagBit(s16 arg0, s16 arg1);
    s32 fclPackRgba(u8, u8, u8, u8);
    u32 datPersonaNamePart1(s16 arg0);
    
    void fclDrawSetFlag(u8 *arg0, s8 arg1);
    void fclCombineMenuFusion(u8 *arg0);
    void fclCombineMenuFusionTriple(u8 *arg0);
    void fclCombineMenuMaterialPick(u8 *arg0);
    void fclCombineMenuPreview(u8 *arg0);
    void fclCombineMenuPriceInfo(u8 *arg0);
    void fclCombineMenuDetailPanels(u8 *arg0);
    void fclCombineMenuRosterFusion(u8 *arg0);
    void fclCombineMenuResult(u8 *arg0);
    void fclCombineMenuMaterialGrid(u8 *arg0);
    void fclCombineMenuOptionPick(u8 *arg0);
    void fclCombineMenuResultGrowth(u8 *arg0);
    void fclCombineMenuFinish(u8 *arg0);
    extern u8 D_00794E70[];
    u8 *work;
    u8 state;

    work = *(u8 **)(arg0 + 0x38);
    state = *(u8 *)work;
    if (state == 0xD8) {
        goto done;
    }
    if (state == 0x0B) {
        goto return_minus_one;
    }
    if (state == 0x0E) {
        goto case_0e;
    }
    if (state == 0x0D) {
        goto case_0d;
    }
    if (state == 0x0A) {
        goto case_0a;
    }
    if (state == 0x09) {
        goto case_09;
    }
    if (state == 0x0C) {
        goto case_0c;
    }
    if (state == 0x10) {
        goto case_10;
    }
    if (state == 0x0F) {
        goto case_10;
    }
    if (state == 0x08) {
        goto case_08;
    }
    if (state == 0x07) {
        goto case_07;
    }
    if (state == 0x06) {
        goto case_06;
    }
    if (state == 0x05) {
        goto case_05;
    }
    if (state == 0x04) {
        goto case_04;
    }
    if (state == 0x03) {
        goto case_03;
    }
    if (state == 0x02) {
        goto case_02;
    }
    if (state == 0x01) {
        goto case_01;
    }
    switch (state) {
    case 0:
        fclCombineMenuRoot(arg0);
        break;
    default:
        break;
    }
    goto done;

case_01:
    P4_002E7AC0_DRAW();
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    *(s8 *)(work + 0x1A) = 2;
    fclCombineMenuFusion(arg0);
    goto done;
case_02:
    P4_002E7AC0_DRAW();
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    *(s8 *)(work + 0x1A) = 3;
    fclCombineMenuFusionTriple(arg0);
    goto done;
case_03:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 4;
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    fclCombineMenuMaterialPick(arg0);
    goto done;
case_04:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 5;
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    fclCombineMenuMaterialPick(arg0);
    goto done;
case_05:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 6;
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    fclCombineMenuMaterialPick(arg0);
    goto done;
case_06:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 7;
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    fclCombineMenuPreview(arg0);
    goto done;
case_07:
    fclCombineMenuDetailPanels(arg0);
    goto done;
case_08:
    P4_002E7AC0_DRAW();
    fclCombineMenuRosterFusion(arg0);
    goto done;
case_10:
    fclDrawSetFlag(*(u8 **)(work + 0x148), 1);
    fclCombineMenuPriceInfo(arg0);
    goto done;
case_0c:
    fclCombineMenuResultGrowth(arg0);
    goto done;
case_09:
    fclCombineMenuMaterialGrid(arg0);
    goto done;
case_0a:
    fclCombineMenuOptionPick(arg0);
    goto done;
case_0d:
    fclCombineMenuResult(arg0);
    goto done;
case_0e:
    fclCombineMenuFinish(arg0);
    goto done;
return_minus_one:
    return -1;
done:
    return 0;
}
#pragma pop

#undef P4_002E7AC0_DRAW

#pragma push
#pragma opt_loop_invariants off
// Fcl combine menu destroy: releases the slot entries and the slot draw tasks.
// FUN_002E82B0
void fclCombineMenuDestroy(u8 *arg0)
{
    s8 yListSlotRelease(s8 arg0);
    s32 kwlnTaskDestroyWithHierarchy(struct KwlnTask *arg0);
    s16 i;
    s64 j;
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    i = 0;
    while (i < 15) {
        yListSlotRelease((s8)i);
        i++;
    }
    i = 0;
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(work + ((s16)j * 4) + 0x154) != 0) {
        kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(work + ((s16)j * 4) + 0x154));
    }
    i++;
loop_7_test:
    j = (s16)i;
    if ((s16)j < (u16)datPersonaRosterCapacity()) {
        goto loop_7_body;
    }
    i = 0;
    while (i < 2) {
        if (*(s32 *)(work + (i * 4) + 0x184) != 0) {
            kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(work + (i * 4) + 0x184));
        }
        i++;
    }
    if (*(s32 *)(work + 0x24C) != 0) {
        kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(work + 0x24C));
    }
    if (*(s32 *)(work + 0x250) != 0) {
        kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(work + 0x250));
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop
