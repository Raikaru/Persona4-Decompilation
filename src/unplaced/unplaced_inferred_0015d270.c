/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0015d270-0015d310 */

/* Unit optimizer settings shared by all field-step functions. */
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_rebuildconditionals on

#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "type.h"
#include "member_access.h"
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
typedef struct { u8 pad0[0x14]; s32 handle; } FldStepWork;
typedef struct { s32 field, room; } FldStepLocation;
typedef struct { s32 required, paired; } FldStepFlagPair;
typedef struct {
    u16 id, month, day, time;
    u8 dayMask, weekdayMask, timeMask, phase;
    FldStepFlagPair requirements[5];
    s32 excluded[12];
    u16 field, room;
    u8 pad68[0x1C];
} FldStepRecord;

/* Step record layout (stride 0x84): id +0, month/day/time +2/+4/+6,
 * calendar masks +8/+9/+A, phase condition +B, five required flag pairs +C,
 * twelve excluded flags +34, field/room +64/+66. The active location stores
 * two s32 values at +0/+4. The release handle is at work +0x14.
 * Typed record cursors preserve the reverse traversal and calendar cutoffs. */
// Intent: Release the handle at the work block's +0x14 through the hook table and clear it [inferred]
// FUN_0015D270
/* Keep the original byte cursor alongside typed object access for retail alias behavior. */
void FldStepReleaseHandle(u8 *work)
{
    FldStepWork *stepWork = (FldStepWork *)work;
    s32 handle;

    handle = ((FldStepWork *)(work))->handle;
    if (handle != 0) {
        (*jtbl_008873EC)((void *)handle);
        stepWork->handle = 0;
    }
}

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

/* Select the last step whose location, calendar masks and flag requirements pass; return NULL if none do. */
// FUN_0015D310
/* Keep the original byte cursor alongside typed object access for retail alias behavior. */
u8 *fldStepFindEligibleRecord(u16 *records)
{
    FldStepRecord *stepRecord;
    extern s16 datGetDateIndex(void);
    extern s64 calGetDayEntryByPhase(s32 records, u32);
    extern u8 datGetTimeSlot(void);
    extern void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut);
    extern s32 calGetWeekdayOfDay(s32 dateIndex);
    extern s32 calHasDayEntry(s32 day);
    extern u32 clndIsDateInRange(u32 startMonth, u32 startDay, u32 endMonth, u32 endDay);
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
        stepRecord = (FldStepRecord *)recordAddress;
        fieldState = iGpffff9db0;
        if ((((FldStepLocation *)(fieldState))->field == ((FldStepRecord *)(recordAddress))->field) &&
            (((FldStepLocation *)(fieldState))->room == ((FldStepRecord *)(recordAddress))->room)) {
            startMonth = ((FldStepRecord *)(recordAddress))->month;
            if ((startMonth == endMonth) &&
                (((FldStepRecord *)(recordAddress))->day == endDay) &&
                (((FldStepRecord *)(recordAddress))->time == endTimeSlot)) {
                endMonth = 3;
                endDay = 0x1F;
                endTimeSlot = 0;
            }
            if (clndIsDateInRange(startMonth, ((FldStepRecord *)(recordAddress))->day,
                             endMonth, endDay) == 1) {
                if ((stepRecord->month == month) &&
                    (stepRecord->day == day) &&
                    ((datGetTimeSlot() & 0xFF) < endTimeSlot)) {
                    endMonth = stepRecord->month;
                    endDay = stepRecord->day;
                    endTimeSlot = ((FldStepRecord *)(recordAddress))->time;
                    goto block_50;
                }
                if (((((FldStepRecord *)(recordAddress))->dayMask == 0) ||
                     (stepRecord->dayMask &
                      (1U << calHasDayEntry((s16)datGetDateIndex())))) &&
                    ((((FldStepRecord *)(recordAddress))->weekdayMask == 0) ||
                     (stepRecord->weekdayMask &
                      (1U << calGetWeekdayOfDay((s16)datGetDateIndex())))) &&
                    ((((FldStepRecord *)(recordAddress))->timeMask == 0) ||
                     (stepRecord->timeMask &
                      (1U << (datGetTimeSlot() & 0xFF))))) {
                    phaseCondition = ((FldStepRecord *)(recordAddress))->phase;
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
                        excludedFlag = ((FldStepRecord *)(recordAddress + (excludedIndex * 4)))->excluded[0];
                        if ((excludedFlag != -1) &&
                            (datGetFlag(excludedFlag) == 1)) {
                            break;
                        }
                    }
                    if (excludedIndex >= 0xC) {
                        hasRequirements = 0;
                        for (requiredIndex = 0; requiredIndex < 5; requiredIndex++) {
                            flagPair = (u8 *)(recordAddress + (requiredIndex * 8));
                            requiredFlag = ((FldStepRecord *)(flagPair))->requirements[0].required;
                            if (requiredFlag == -1) {
                                continue;
                            }
                            hasRequirements = 1;
                            if (datGetFlag(requiredFlag) != 1) {
                                continue;
                            }
                            pairedFlag = ((FldStepRecord *)(flagPair))->requirements[0].paired;
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
                endMonth = stepRecord->month;
                endDay = stepRecord->day;
                endTimeSlot = ((FldStepRecord *)(recordAddress))->time;
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
