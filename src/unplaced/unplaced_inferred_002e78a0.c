
/* Unit optimizer settings shared by the neighboring functions. */
#pragma opt_loop_invariants off

#include "list_item_internal.h"
#include "member_access.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "fcl_combine_internal.h"
#include "fcl_combine_row_internal.h"
#include "fr_font_internal.h"
#include "fcl_object_internal.h"
#include "datPersona_internal.h"
typedef struct FclCombineHeaderTasks { struct KwlnTask *tasks[2]; } FclCombineHeaderTasks;

extern void (*jtbl_008873EC[])(void *);
extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern u32 datGetMoney(void);
s16 datGetDateIndex(void);
void calSplitDayOfYear(s32, s32 *, s32 *);
s32 fclAddClamped(s32 , s32 , s32 , s32 , s32 );
void datSetMoney(s32 );
/* Split the current calendar date and return its month byte. */
// FUN_002E78A0
u8 fclCalendarMonth(void)
{
    s32 day;
    s32 month;

    calSplitDayOfYear(datGetDateIndex(), &month, &day);
    return month;
}

/* Retail returns the low day byte with lbu, defining the full result. */
// FUN_002E78E0
s32 fclCalendarDay(void)
{
    s32 day;
    s32 month;

    calSplitDayOfYear(datGetDateIndex(), &month, &day);
    return (u8)day;
}

/* Return the next month/day pair, wrapping the month when the current day reaches its month length. */
// FUN_002E7920
void fclCalGetNextDate(s32 *month, s32 *day)
{
    s32 calGetMonthLength(s32 month);
    s32 fclAddClamped(s32 month, s32 day, s32 , s32 , s8 );
    s32 *out0;
    u8 count;
    s32 *out1;
    s32 lengthDay;
    s32 lengthMonth;
    s32 currentDay;
    s32 currentMonth;
    s32 rolloverDay;
    s32 rolloverMonth;
    s32 resultDay;
    s32 resultMonth;
    s32 nextDay;
    s32 nextMonth;

    out0 = month;
    count = 0;
    out1 = day;

    calSplitDayOfYear(datGetDateIndex(), (s32 *)&currentMonth, (s32 *)&currentDay);
    count = *(u8 *)&currentDay;
    calSplitDayOfYear(datGetDateIndex(), (s32 *)&lengthMonth, (s32 *)&lengthDay);
    if (calGetMonthLength(*(u8 *)&lengthMonth) < (count + 1)) {
        calSplitDayOfYear(datGetDateIndex(), &rolloverMonth, &rolloverDay);
        *out0 = fclAddClamped(*(u8 *)&rolloverMonth, 1, 0xC, 1, 2);
        *out1 = 1;
        return;
    }
    calSplitDayOfYear(datGetDateIndex(), &resultMonth, &resultDay);
    *out0 = *(u8 *)&resultMonth;
    calSplitDayOfYear(datGetDateIndex(), &nextMonth, &nextDay);
    *out1 = *(u8 *)&nextDay + 1;
}

// FUN_002E7A60
u32 fclGetMoney(void)
{
    return datGetMoney();
}

// FUN_002E7A80
void fclAddMoney(s32 value)
{
    datSetMoney(fclAddClamped(value, 0, 0x98967F, 0, 1));
}

#define P4_002E7AC0_DRAW() \
    do { \
        if ((s16)fclSpriteFlagBit(((FclCombineRowSprite *)fclSpriteEntry(105))->flags, 0) == 1) { \
            frFontExDrawTextDeferredOutB(((FclCombineRowSprite *)fclSpriteEntry(105))->position.x + 52.0f, 41.0f, 88.0f, \
                          fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0, 1, \
                          (const char *)datPersonaNamePart1(1), 0, 0, D_00794E70, 24); \
        } \
    } while (0)

// Fcl combine menu update: runs the menu state machine (draws the text and returns a status).
// FUN_002E7AC0
s32 fclCombineMenuUpdate(u8 *task)
{
    void fclCombineMenuRoot(u8 *task);
    u8 *fclSpriteEntry(s16 index);
    s16 fclSpriteFlagBit(s16 task, s16 );
    s32 fclPackRgba(u8, u8, u8, u8);
    u32 datPersonaNamePart1(s16 unitId);
    
    void fclDrawSetFlag(u8 *task, s8 );
    void fclCombineMenuFusion(u8 *task);
    void fclCombineMenuFusionTriple(u8 *task);
    void fclCombineMenuMaterialPick(u8 *task);
    void fclCombineMenuPreview(u8 *task);
    void fclCombineMenuPriceInfo(u8 *task);
    void fclCombineMenuDetailPanels(u8 *task);
    void fclCombineMenuRosterFusion(u8 *task);
    void fclCombineMenuResult(u8 *task);
    void fclCombineMenuMaterialGrid(u8 *task);
    void fclCombineMenuOptionPick(u8 *task);
    void fclCombineMenuResultGrowth(u8 *task);
    void fclCombineMenuFinish(u8 *task);
    extern u8 D_00794E70[];
    u8 *work;
    u8 state;

    work = ((struct KwlnTask *)task)->work;
    state = (u8)((FclCombineWork *)work)->f0;
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
        fclCombineMenuRoot(task);
        break;
    default:
        break;
    }
    goto done;

case_01:
    P4_002E7AC0_DRAW();
    fclDrawSetFlag(((FclCombineWork *)work)->f148, 0);
    ((FclCombineWork *)work)->fusionCount = 2;
    fclCombineMenuFusion(task);
    goto done;
case_02:
    P4_002E7AC0_DRAW();
    fclDrawSetFlag(((FclCombineWork *)work)->f148, 0);
    ((FclCombineWork *)work)->fusionCount = 3;
    fclCombineMenuFusionTriple(task);
    goto done;
case_03:
    P4_002E7AC0_DRAW();
    ((FclCombineWork *)work)->fusionCount = 4;
    fclDrawSetFlag(((FclCombineWork *)work)->f148, 0);
    fclCombineMenuMaterialPick(task);
    goto done;
case_04:
    P4_002E7AC0_DRAW();
    ((FclCombineWork *)work)->fusionCount = 5;
    fclDrawSetFlag(((FclCombineWork *)work)->f148, 0);
    fclCombineMenuMaterialPick(task);
    goto done;
case_05:
    P4_002E7AC0_DRAW();
    ((FclCombineWork *)work)->fusionCount = 6;
    fclDrawSetFlag(((FclCombineWork *)work)->f148, 0);
    fclCombineMenuMaterialPick(task);
    goto done;
case_06:
    P4_002E7AC0_DRAW();
    ((FclCombineWork *)work)->fusionCount = 7;
    fclDrawSetFlag(((FclCombineWork *)work)->f148, 0);
    fclCombineMenuPreview(task);
    goto done;
case_07:
    fclCombineMenuDetailPanels(task);
    goto done;
case_08:
    P4_002E7AC0_DRAW();
    fclCombineMenuRosterFusion(task);
    goto done;
case_10:
    fclDrawSetFlag(((FclCombineWork *)work)->f148, 1);
    fclCombineMenuPriceInfo(task);
    goto done;
case_0c:
    fclCombineMenuResultGrowth(task);
    goto done;
case_09:
    fclCombineMenuMaterialGrid(task);
    goto done;
case_0a:
    fclCombineMenuOptionPick(task);
    goto done;
case_0d:
    fclCombineMenuResult(task);
    goto done;
case_0e:
    fclCombineMenuFinish(task);
    goto done;
return_minus_one:
    return -1;
done:
    return 0;
}

#undef P4_002E7AC0_DRAW

// Fcl combine menu destroy: releases the slot entries and the slot draw tasks.
// FUN_002E82B0
void fclCombineMenuDestroy(u8 *task)
{
    /* measured: the remaining header-task and combine-task accesses stay untyped because typed
     * fields change how retail schedules the loop index and reloads. */
    s8 yListSlotRelease(s8 list);
    s32 kwlnTaskDestroyWithHierarchy(struct KwlnTask *task);
    s16 i;
    s64 j;
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    i = 0;
    while (i < 15) {
        yListSlotRelease((s8)i);
        i++;
    }
    i = 0;
    goto loop_7_test;
loop_7_body:
    if ((s32)((FclCombineRowWork *)work)->gridRowTasks[(s16)j] != 0) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)((FclCombineRowWork *)work)->gridRowTasks[(s16)j]);
    }
    i++;
loop_7_test:
    j = (s16)i;
    if ((s16)j < (u16)datPersonaRosterCapacity()) {
        goto loop_7_body;
    }
    i = 0;
    while (i < 2) {
        if (MEMBER(s32, work + (i * 4), FclCombineWork, f184) != 0) {
            kwlnTaskDestroyWithHierarchy(((FclCombineHeaderTasks *)(work + 0x184))->tasks[i]);
        }
        i++;
    }
    if ((s32)((FclCombineWork *)work)->unk24C != 0) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)((FclCombineWork *)work)->unk24C);
    }
    if ((s32)((FclCombineWork *)work)->unk250 != 0) {
        kwlnTaskDestroyWithHierarchy((struct KwlnTask *)((FclCombineWork *)work)->unk250);
    }
    jtbl_008873EC[0](MEMBER(u8 *, task, KwlnTask, work));
}
