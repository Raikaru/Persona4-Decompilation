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
extern u32 datGetFlag(s32);
extern void (*jtbl_008873EC[])(void *);
#include "Kosaka/k_fldFrame_internal.h"
#include "scene_event_internal.h"
/* Step record layout (stride 0x84): id +0, month/day/time +2/+4/+6,
 * calendar masks +8/+9/+A, phase condition +B, five required flag pairs +C,
 * twelve excluded flags +34, field/room +64/+66. The active location stores
 * two s32 values at +0/+4. The release handle is at work +0x14.
 * Typed rewrites below were measured and reverted where they changed codegen. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
// Intent: Release the handle at the work block's +0x14 through the hook table and clear it [inferred]
// FUN_0015D270
/* Measured: typed field access changed the retail instruction image; retain byte accesses at the documented work-layout offsets. */
void FldStepReleaseHandle(u8 *work)
{
    s32 handle;

    handle = *(s32 *)(work + 0x14);
    if (handle != 0) {
        (*jtbl_008873EC)((void *)handle);
        *(s32 *)(work + 0x14) = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
// Intent: Return the step record at the given count of empty records (id 0xFFFF) in the record table [inferred]
// FUN_0015D2C0
u16 *FldStepFindEmptySlot(u32 emptyIndex)
{
    u16 *record;
    u32 recordIndex;
    s32 emptyCount;
    u32 recordCount;
    u16 emptyId;

    record = (u16 *)D_00764384;
    emptyCount = 0;
    recordIndex = 0;
    recordCount = D_0076438C;
    emptyId = 0xFFFF;
    while (recordIndex < recordCount) {
        if (emptyCount != emptyIndex) {
            if (*record == emptyId) {
                emptyCount++;
            }
            recordIndex++;
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
/* Select the last step whose location, calendar masks and flag requirements pass; return NULL if none do. */
// FUN_0015D310
/* Measured: typed field access changed the retail instruction image; retain byte accesses at the documented work-layout offsets. */
u8 *fldStepFindEligibleRecord(u16 *records)
{
    extern s16 datGetDateIndex(void);
    extern s64 calGetDayEntryByPhase(s32 records, u32);
    extern u8 datGetTimeSlot(void);
    extern void calSplitDayOfYear(s32 date, s32 *month, s32 *day);
    extern s32 calGetWeekdayOfDay(s32 date);
    extern s32 calHasDayEntry(s32 date);
    extern u32 clndIsDateInRange(u32 firstMonth, u32 firstDay, u32 lastMonth, u32 lastDay);
    extern u32 datGetFlag(s32 bit);
    s32 month;
    s32 day;
    s32 excludedFlag;
    s32 requiredFlag;
    s32 pairedFlag;
    s32 endMonth;
    s32 hasRequirements;
    s32 firstPhaseParity;
    s32 secondPhaseParity;
    s64 firstPhase;
    s64 secondPhase;
    s32 firstDate;
    s32 secondDate;
    u16 *record;
    u32 startMonth;
    s32 endDay;
    s32 endTimeSlot;
    u32 recordCount;
    u32 excludedIndex;
    u32 requiredIndex;
    u32 reverseIndex;
    u8 phaseCondition;
    u8 *flagPair;
    u8 *fieldState;
    uintptr_t recordAddress;

    record = records;
    if (records == NULL) {
        return NULL;
    }
    recordCount = 0;
loop_3:
    if (*record != 0xFFFF) {
        recordCount += 1;
        record += 0x42;
        goto loop_3;
    }
    recordAddress = (uintptr_t)((u8 *)records + recordCount * 0x84) - 0x84;
    endMonth = 3;
    endDay = 0x1F;
    endTimeSlot = 0;
    calSplitDayOfYear((s16)datGetDateIndex(), &month, &day);
    reverseIndex = 0;
    goto loop_test;
loop_body:
        fieldState = iGpffff9db0;
        if ((*(s32 *)(fieldState + 0) == *(u16 *)(recordAddress + 0x64)) &&
            (*(s32 *)(fieldState + 4) == *(u16 *)(recordAddress + 0x66))) {
            startMonth = *(u16 *)(recordAddress + 2);
            if ((startMonth == endMonth) &&
                (*(u16 *)(recordAddress + 4) == endDay) &&
                (*(u16 *)(recordAddress + 6) == endTimeSlot)) {
                endMonth = 3;
                endDay = 0x1F;
                endTimeSlot = 0;
            }
            if (clndIsDateInRange(startMonth, *(u16 *)(recordAddress + 4),
                             endMonth, endDay) == 1) {
                if ((*(u16 *)(recordAddress + 2) == month) &&
                    (*(u16 *)(recordAddress + 4) == day) &&
                    ((datGetTimeSlot() & 0xFF) < endTimeSlot)) {
                    endMonth = *(u16 *)(recordAddress + 2);
                    endDay = *(u16 *)(recordAddress + 4);
                    endTimeSlot = *(u16 *)(recordAddress + 6);
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
                    phaseCondition = *(u8 *)(recordAddress + 0xB);
                    if (phaseCondition == 1) {
                        firstDate = (s16)datGetDateIndex();
                        firstPhase = (s64)(s8)calGetDayEntryByPhase(firstDate,
                                                     datGetTimeSlot() & 0xFF);
                        firstPhaseParity = (s32)firstPhase % 2;
                        if (firstPhaseParity != 0) {
                            goto block_50;
                        }
                        goto block_34;
                    }
                    if (phaseCondition == 2) {
                        secondDate = (s16)datGetDateIndex();
                        secondPhase = (s64)(s8)calGetDayEntryByPhase(secondDate,
                                                       datGetTimeSlot() & 0xFF);
                        secondPhaseParity = (s32)secondPhase % 2;
                        if (secondPhaseParity != 0) {
                            goto block_34;
                        }
                        goto block_50;
                    }
block_34:
                    for (excludedIndex = 0; excludedIndex < 0xC; excludedIndex++) {
                        excludedFlag = *(s32 *)(recordAddress + (excludedIndex * 4) + 0x34);
                        if ((excludedFlag != -1) &&
                            (datGetFlag(excludedFlag) == 1)) {
                            break;
                        }
                    }
                    if (excludedIndex >= 0xC) {
                        hasRequirements = 0;
                        for (requiredIndex = 0; requiredIndex < 5; requiredIndex++) {
                            flagPair = (u8 *)(recordAddress + (requiredIndex * 8));
                            requiredFlag = *(s32 *)(flagPair + 0xC);
                            if (requiredFlag == -1) {
                                continue;
                            }
                            hasRequirements = 1;
                            if (datGetFlag(requiredFlag) != 1) {
                                continue;
                            }
                            pairedFlag = *(s32 *)(flagPair + 0x10);
                            if (pairedFlag != -1) {
                                if (datGetFlag(pairedFlag) != 1) {
                                    continue;
                                }
                            }
                            break;
                        }
                        if ((requiredIndex >= 5) && (hasRequirements != 0)) {
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
                endMonth = *(u16 *)(recordAddress + 2);
                endDay = *(u16 *)(recordAddress + 4);
                endTimeSlot = *(u16 *)(recordAddress + 6);
                goto block_50;
            }
        } else {
block_50:
            reverseIndex += 1;
            recordAddress -= 0x84;
loop_test:
            if (reverseIndex < recordCount) {
                goto loop_body;
            }
        }
    if (reverseIndex >= recordCount) {
        recordAddress = 0;
    }
    return (u8 *)recordAddress;
}
#pragma pop
