#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit calendar.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "shd_misc_internal.h"
#include "kwln_task_internal.h"

/* Both calendar input tasks allocate exactly 0x10 bytes. */
typedef struct CalendarWork {
    s32 state;
    s32 drawEnabled;
    s32 dateIndex;
    s32 childTask;
} CalendarWork;
extern s32 kwlnTaskGetTaskByName();
extern u8 D_005E4FE8[];
extern u8 D_005E4FD8[];

extern s32 D_007242B4;
extern s32 D_007242B0;
extern s32 D_007242B8;
extern u8 D_005E4FF8[];
extern u8 D_005E5038[];
extern u8 D_005E5050[];
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void chkmemAllocSiteTag(u8 *file, s32 line);


extern s32 calendarStepTimeSlot(u8 *task);
extern void taskRecordDestroy(u8 *task);
extern s32 calendarTimeSlotChildNoop(u8 *unusedTask);
extern s32 calendarDraw(u8 *unusedTask);
extern s32 calGetMonthLength(s32 month);
extern void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut);
extern u8 datGetTimeSlot(void);
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern void fadeBeginTransition(s32 mode, s32 duration);
extern void datSetDateIndex(s32 date);
extern void sequenceRequest(s32 sequenceId, void *parameters, s32 parameterSize, s32 delay);
extern void calendarSyncFromDate(void);
extern s32 calendarTaskCreate(s32 a);
extern s32 kwlnTaskGetState(s32 task);
extern void datSetTimeSlot(s32 timeSlot);
extern s32 calGetWeekdayOfDay(s32 dateIndex);
extern s32 calGetWeekOfYear(s32 dateIndex);
extern s32 calDayOfYearFromMonthDay(s32 month, s32 day);
extern void PrimDrawFlatRectangle(void *colorData, void *rectangleData, f32 depth, s32 preserveState);
extern s32 iGpffff9c54;
extern const char *D_005E5010[];
extern u8 D_005E5028[];



/* Opens the calendar view and clears the mode flag D_007242B8. */
// FUN_001211B0
void calendarOpenFlagClear(void)
{
    CalendarWork *work;
    s32 handle;

    D_007242B8 = 0;
    chkmemAllocSiteTag(D_005E4FD8, 0x79);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work != NULL) {
        handle = (s32)kwlnTaskCreate((const void *)(D_005E4FE8), 0x100, 0, 0, calendarStepTimeSlot, taskRecordDestroy, (u8 *)(work));
        D_007242B0 = (s32)work;
        (s32)kwlnTaskCreateChild((void *)(handle), (const void *)(D_005E4FF8), 0x101, 0, 0, calendarTimeSlotChildNoop, 0, (u8 *)(NULL));
    }
}

/* Reports whether the calendar view task is open. */
// FUN_00121280
s32 calendarIsOpen(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005E4FE8) != 0);
}

/* Closes the calendar view task, asserting when it is not open. */
// FUN_001212B0
void calendarClose(void)
{
    s32 handle = kwlnTaskGetTaskByName(D_005E4FE8);

    if (handle == 0) {
        kAssertFail(D_005E4FD8, 0xA8);
    }
    kwlnTaskDestroyWithHierarchy(handle);
}

/* Input task update: cancel, confirm, and date/month cursor moves. */
// FUN_00121310
s32 calendarInputUpdate(u8 *task)
{
    s32 month;
    s32 day;
    CalendarWork *work;
    s32 state;
    s32 dateIndex;

    work = (CalendarWork *)((KwlnTask *)task)->work;
    state = work->state;
    switch (state) {
    case 0:
        work->dateIndex = 0;
        work->drawEnabled = 1;
        work->state = 1;
        break;
    case 1:
        if (D_008C0276[0] & 0x40) {
            fadeBeginTransition(1, 1);
            datSetDateIndex((s16)work->dateIndex);
            sequenceRequest(0x1A, NULL, 0, 0);
            return -1;
        }
        if (D_008C0276[0] & 0x800) {
            datSetDateIndex((s16)work->dateIndex);
            calendarSyncFromDate();
            work->childTask = calendarTaskCreate((s32)task);
            work->state = 4;
        } else if (D_008C027A[0] & 0x1000) {
            dateIndex = work->dateIndex;
            if (dateIndex < 7) {
                work->dateIndex = 0;
            } else {
                work->dateIndex = dateIndex - 7;
            }
        } else if (D_008C027A[0] & 0x4000) {
            dateIndex = work->dateIndex;
            if (dateIndex > 0x165) {
                work->dateIndex = 0x16C;
            } else {
                work->dateIndex = dateIndex + 7;
            }
        } else if (D_008C027A[0] & 0x8000) {
            dateIndex = work->dateIndex;
            if (dateIndex != 0) {
                work->dateIndex = dateIndex - 1;
            }
        } else if (D_008C027A[0] & 0x2000) {
            dateIndex = work->dateIndex;
            if (dateIndex != 0x16C) {
                work->dateIndex = dateIndex + 1;
            }
        } else if (D_008C027A[0] & 0x4) {
            if ((datGetTimeSlot() & 0xFF) == 0) {
                datSetTimeSlot(5);
            } else {
                datSetTimeSlot(((datGetTimeSlot() & 0xFF) - 1) & 0xFF);
            }
        } else if (D_008C027A[0] & 0x8) {
            if ((datGetTimeSlot() & 0xFF) == 5) {
                datSetTimeSlot(0);
            } else {
                datSetTimeSlot(((datGetTimeSlot() & 0xFF) + 1) & 0xFF);
            }
        } else if (D_008C027A[0] & 0x1) {
            calSplitDayOfYear(work->dateIndex, &month, &day);
            if (month != 4) {
                work->dateIndex = work->dateIndex - (calGetMonthLength(month) - 1);
            }
        } else if (D_008C027A[0] & 0x2) {
            calSplitDayOfYear(work->dateIndex, &month, &day);
            if (month != 3) {
                work->dateIndex = work->dateIndex + calGetMonthLength(month);
            }
        }
        break;
    case 4:
        if (kwlnTaskGetState(work->childTask) == 3) {
            work->state = 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
/* Input task release: clears the shared draw work pointer and frees the work block. */
// FUN_00121660
void calendarInputRelease(u8 *task)
{
    void *work = ((KwlnTask *)task)->work;
    D_007242B4 = 0;
    jtbl_008873EC[0](work);
}

/* Draw task update: draws the calendar grid and day numbers for the current date. */
/* Measured: 688 bytes and 17 resolved relocations. Packed positions retain
 * both coordinate components; the formatter consumes a genuine vararg list.
 * Keep the loop bound live and reuse the selected row offset across queries. */
// FUN_00121690
s32 calendarDraw(u8 *unusedTask)
{
    s32 month, day;
    u8 color[4];
    PackedVec2f pos;
    s32 dim[4];
    s32 current, index;
    s32 offset;
    s32 weekday;
    CalendarWork *work;

    work = (CalendarWork *)D_007242B4;
    if (work == NULL) return 0;
    if (work->drawEnabled == 0) return 0;
    color[0] = 0x40; color[1] = 0x40; color[2] = 0x40; color[3] = 0xff;
    dim[0] = 100; dim[1] = 100; dim[2] = 250; dim[3] = 100;
    PrimDrawFlatRectangle(color, dim, 0.0f, 1);
    calSplitDayOfYear(work->dateIndex, &month, &day);
    weekday = calGetWeekdayOfDay(calDayOfYearFromMonthDay(month, 1));
    current = calGetWeekdayOfDay(work->dateIndex);
    if (current >= weekday) offset = 0; else offset = 12;
    offset = offset + (calGetWeekOfYear(work->dateIndex) - 1) * 12;
    color[0] = 0x40; color[1] = 0x80; color[2] = 0x80; color[3] = 0xff;
    dim[0] = current * 36 + 100; dim[1] = offset + 124; dim[2] = 36; dim[3] = 12;
    PrimDrawFlatRectangle(color, dim, 0.0f, 1);
    pos.xy.x = 100.0f; pos.xy.y = 100.0f;
    sdkDbprtPrint(pos, 0.0f, D_005E5028, month, D_005E5010[datGetTimeSlot()]);
    pos.xy.x = 0.0f + 100.0f + 36.0f * (f32)weekday;
    pos.xy.y = 124.0f;
    index = 0;
    while (index < calGetMonthLength(month)) {
        sdkDbprtPrint(pos, 0.0f, &iGpffff9c54, index + 1);
        weekday++;
        if (weekday > 6) {
            weekday = 0;
            pos.xy.x -= 252.0f; pos.xy.y += 12.0f;
        }
        pos.xy.x += 36.0f;
        index++;
    }
    return 0;
}

/* Creates the input and draw tasks over one work block; returns the input task handle. */
// FUN_00121940
s32 calendarStart(void)
{
    s32 handle;
    CalendarWork *work;

    chkmemAllocSiteTag(D_005E4FD8, 0x164);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work == NULL) {
        return 0;
    }
    handle = (s32)kwlnTaskCreate((const void *)(D_005E5038), 0x100, 0, 0, calendarInputUpdate, calendarInputRelease, (u8 *)(work));
    D_007242B4 = (s32)work;
    (s32)kwlnTaskCreateChild((void *)(handle), (const void *)(D_005E5050), 0x101, 0, 0, calendarDraw, 0, (u8 *)(NULL));
    return handle;
}

/* Opens the calendar view and sets the mode flag D_007242B8 to 1. */
// FUN_00121A20
void calendarOpenFlagSet(void)
{
    CalendarWork *work;
    s32 handle;

    D_007242B8 = 1;
    chkmemAllocSiteTag(D_005E4FD8, 0x79);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work != NULL) {
        handle = (s32)kwlnTaskCreate((const void *)(D_005E4FE8), 0x100, 0, 0, calendarStepTimeSlot, taskRecordDestroy, (u8 *)(work));
        D_007242B0 = (s32)work;
        (s32)kwlnTaskCreateChild((void *)(handle), (const void *)(D_005E4FF8), 0x101, 0, 0, calendarTimeSlotChildNoop, 0, (u8 *)(NULL));
    }
}