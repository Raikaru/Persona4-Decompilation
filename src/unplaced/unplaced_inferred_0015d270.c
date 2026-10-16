/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0015d270-0015d310 */

#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "type.h"
#include "field_light_internal.h"
#include "field_frame_internal.h"
#include "rw_types_internal.h"
extern s32 D_00764384;
extern u32 D_0076438C;
extern u8 *iGpffff9db0;
extern u32 datGetFlag(s32 arg0);
extern void (*jtbl_008873EC[])(void *);
#include "Kosaka/k_fldFrame_internal.h"
#include "scene_event_internal.h"
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
// Intent: Release the handle at the work block's +0x14 through the hook table and clear it [inferred]
// FUN_0015D270
void FldStepReleaseHandle(u8 *arg0)
{
    s32 h;

    h = *(s32 *)(arg0 + 0x14);
    if (h != 0) {
        (*jtbl_008873EC)((void *)h);
        *(s32 *)(arg0 + 0x14) = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
// Intent: Return the step record at the given count of empty records (id 0xFFFF) in the record table [inferred]
// FUN_0015D2C0
u16 *FldStepFindEmptySlot(u32 arg0)
{
    u16 *record;
    u32 i;
    s32 emptyCount;
    u32 recordCount;
    u16 emptyId;

    record = (u16 *)D_00764384;
    emptyCount = 0;
    i = 0;
    recordCount = D_0076438C;
    emptyId = 0xFFFF;
    while (i < recordCount) {
        if (emptyCount != arg0) {
            if (*record == emptyId) {
                emptyCount++;
            }
            i++;
            record = (u16 *)((u8 *)record + 0x84);
        } else {
            break;
        }
    }
    return record;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
// FUN_0015D310
u8 *func_0015d310(u16 *arg0)
{
    extern s16 datGetDateIndex(void);
    extern s64 calGetDayEntryByPhase(s32 arg0, u32 arg1);
    extern u8 datGetTimeSlot(void);
    extern void calSplitDayOfYear(s32 date, s32 *month, s32 *day);
    extern s32 calGetWeekdayOfDay(s32 date);
    extern s32 calHasDayEntry(s32 date);
    extern u32 clndIsDateInRange(u32 firstMonth, u32 firstDay, u32 lastMonth, u32 lastDay);
    extern u32 datGetFlag(s32 bit);
    s32 sp8C;
    s32 sp88;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 var_18;
    s32 var_19_2;
    s32 temp_3_2;
    s32 temp_3_3;
    s64 var_2;
    s64 var_2_2;
    s32 temp_22;
    s32 temp_22_2;
    u16 *var_5;
    u32 temp_4_2;
    s32 var_19;
    s32 var_20;
    u32 var_17;
    u32 var_18_2;
    u32 var_18_3;
    u32 var_21;
    u8 temp_3;
    u8 *temp_20;
    u8 *temp_4;
    uintptr_t recordAddress;

    var_5 = arg0;
    if (arg0 == NULL) {
        return NULL;
    }
    var_17 = 0;
loop_3:
    if (*var_5 != 0xFFFF) {
        var_17 += 1;
        var_5 += 0x42;
        goto loop_3;
    }
    recordAddress = (uintptr_t)((u8 *)arg0 + var_17 * 0x84) - 0x84;
    var_18 = 3;
    var_19 = 0x1F;
    var_20 = 0;
    calSplitDayOfYear((s16)datGetDateIndex(), &sp8C, &sp88);
    var_21 = 0;
    goto loop_test;
loop_body:
        temp_4 = iGpffff9db0;
        if ((*(s32 *)(temp_4 + 0) == *(u16 *)(recordAddress + 0x64)) &&
            (*(s32 *)(temp_4 + 4) == *(u16 *)(recordAddress + 0x66))) {
            temp_4_2 = *(u16 *)(recordAddress + 2);
            if ((temp_4_2 == var_18) &&
                (*(u16 *)(recordAddress + 4) == var_19) &&
                (*(u16 *)(recordAddress + 6) == var_20)) {
                var_18 = 3;
                var_19 = 0x1F;
                var_20 = 0;
            }
            if (clndIsDateInRange(temp_4_2, *(u16 *)(recordAddress + 4),
                             var_18, var_19) == 1) {
                if ((*(u16 *)(recordAddress + 2) == sp8C) &&
                    (*(u16 *)(recordAddress + 4) == sp88) &&
                    ((datGetTimeSlot() & 0xFF) < var_20)) {
                    var_18 = *(u16 *)(recordAddress + 2);
                    var_19 = *(u16 *)(recordAddress + 4);
                    var_20 = *(u16 *)(recordAddress + 6);
                    goto block_50;
                }
                if (((*(u8 *)(recordAddress + 8) == 0) ||
                     (*(u8 *)(recordAddress + 8) &
                      (1U << calHasDayEntry((s16)datGetDateIndex())))) &&
                    ((*(u8 *)(recordAddress + 9) == 0) ||
                     (*(u8 *)(recordAddress + 9) &
                      (1U << calGetWeekdayOfDay((s16)datGetDateIndex())))) &&
                    ((*(u8 *)(recordAddress + 0xA) == 0) ||
                     (*(u8 *)(recordAddress + 0xA) &
                      (1U << (datGetTimeSlot() & 0xFF))))) {
                    temp_3 = *(u8 *)(recordAddress + 0xB);
                    if (temp_3 == 1) {
                        temp_22 = (s16)datGetDateIndex();
                        var_2 = (s64)(s8)calGetDayEntryByPhase(temp_22,
                                                     datGetTimeSlot() & 0xFF);
                        temp_3_2 = (s32)var_2 % 2;
                        if (temp_3_2 != 0) {
                            goto block_50;
                        }
                        goto block_34;
                    }
                    if (temp_3 == 2) {
                        temp_22_2 = (s16)datGetDateIndex();
                        var_2_2 = (s64)(s8)calGetDayEntryByPhase(temp_22_2,
                                                       datGetTimeSlot() & 0xFF);
                        temp_3_3 = (s32)var_2_2 % 2;
                        if (temp_3_3 != 0) {
                            goto block_34;
                        }
                        goto block_50;
                    }
block_34:
                    for (var_18_2 = 0; var_18_2 < 0xC; var_18_2++) {
                        temp_4_3 = *(s32 *)(recordAddress + (var_18_2 * 4) + 0x34);
                        if ((temp_4_3 != -1) &&
                            (datGetFlag(temp_4_3) == 1)) {
                            break;
                        }
                    }
                    if (var_18_2 >= 0xC) {
                        var_19_2 = 0;
                        for (var_18_3 = 0; var_18_3 < 5; var_18_3++) {
                            temp_20 = (u8 *)(recordAddress + (var_18_3 * 8));
                            temp_4_4 = *(s32 *)(temp_20 + 0xC);
                            if (temp_4_4 == -1) {
                                continue;
                            }
                            var_19_2 = 1;
                            if (datGetFlag(temp_4_4) != 1) {
                                continue;
                            }
                            temp_4_5 = *(s32 *)(temp_20 + 0x10);
                            if (temp_4_5 != -1) {
                                if (datGetFlag(temp_4_5) != 1) {
                                    continue;
                                }
                            }
                            break;
                        }
                        if ((var_18_3 >= 5) && (var_19_2 != 0)) {
                            goto block_49;
                        }
                    } else {
                        goto block_49;
                    }
                } else {
                    goto block_50;
                }
            } else {
block_49:
                var_18 = *(u16 *)(recordAddress + 2);
                var_19 = *(u16 *)(recordAddress + 4);
                var_20 = *(u16 *)(recordAddress + 6);
                goto block_50;
            }
        } else {
block_50:
            var_21 += 1;
            recordAddress -= 0x84;
loop_test:
            if (var_21 < var_17) {
                goto loop_body;
            }
        }
    if (var_21 >= var_17) {
        recordAddress = 0;
    }
    return (u8 *)recordAddress;
}
#pragma pop
