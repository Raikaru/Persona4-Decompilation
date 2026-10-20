#include "include_asm.h"
#include "sdk_task_registration.h"
/* Source unit: src/cldScheduler.c */
#include "type.h"
#include "h_cdvd_internal.h"

extern void chkmemAllocSiteTag(void *procedureTask, s32 id);
extern void kAssertFail(const void *file, u32 line);
extern void *memset(void *dest, s32 value, s32 size);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern char D_006372B0[];
extern u32 D_008814F0[3];
extern s32 D_0076457C;

typedef struct SdlSched
{
    s32 state;   /* 0x00 */
    s32 procedureTask;    /* 0x04 */
    s32 flags;    /* 0x08 */
} SdlSched;

extern s16 datGetDateIndex(void);
extern u8 datGetTimeSlot(void);
extern void calSplitDayOfYear(s32 date, s32 *month, s32 *loadedMonth);
extern void sequenceRequest(s32 id, void *data, s32 size, s32 sameMonth);
extern void cmmTickReverseProgress(void);
extern s32 scrStartProcedureIndex(s32 kind, u8 *script, s32 index);
extern s32 scrFindPrcdIdxByName(s32 scriptOrSize, void *fileData);
extern void memcpy(void *, void *, u32);
extern s32 sprintf(char *buf, char *fmt, ...);
extern s32 kwlnTaskIsLinked(void *task);
extern u32 kwlnTaskGetWork(void *task);
extern u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 kind);
extern char D_006372C0[];
extern char D_00637310[];
extern char D_00637320[];
extern s32 D_007637A0;
extern char D_007637A8[6];
extern s32 D_00764578;
extern s32 D_00764574;
typedef struct KwlnTask KwlnTask;
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);

extern char D_00637348[];
extern s32 cldSchedulerTaskUpdate(u8 *task);
extern void cldSchedulerTaskDestroy(u8 *task);



/* Allocate the monthly schedule script buffer and reset the scheduler work. */
// FUN_0025FF90
void cldSchedulerInit(void)
{
    if (D_0076457C != 0)
    {
        kAssertFail(D_006372B0, 0x3E);
    }
    chkmemAllocSiteTag(D_006372B0, 0x3F);
    D_0076457C = (s32)D_008873F4[0](1, 0x20000, 0x40000);
    memset(&D_008814F0[0], 0, 0xC);
}



/* The six eight-byte period labels generate the retail paired-byte copy.
 * Keep propagation off here to retain the post-copy byte conversion. */
#pragma opt_propagation off
/* Load the current month, run its date/time procedure, then await completion. */
// FUN_00260020
s32 cldSchedulerTaskUpdate(u8 *task)
{
    s32 month;
    s32 monthDay;
    s32 procedureMonth;
    s32 procedureDay;
    char path[0x100];
    char procedureName[0x20];
    SdlSched *sched;
    s32 sameMonth;
    s32 loaded;
    s32 loadedMonth;
    s32 fileData;
    s32 scriptOrSize;
    s32 procedureIndex;
    s32 procedureTask;

    sched = (SdlSched *)kwlnTaskGetWork(task);
    month = 0;
    monthDay = 0;
    calSplitDayOfYear((s16)datGetDateIndex(), &month, &monthDay);
    switch (sched->state)
    {
    case 0:
        loadedMonth = month;
        sameMonth = 1;
        if (D_007637A0 != -1 && D_007637A0 == loadedMonth)
        {
            sameMonth = 1;
        }
        else
        {
            sameMonth = 0;
        }
        if (sameMonth == 0)
        {
            if (D_00764578 != 0)
            {
                kAssertFail(D_006372B0, 0x54);
            }
            D_007637A0 = loadedMonth;
            sprintf(path, D_006372C0, loadedMonth);
            func_00440b68(D_007637A8, D_006372B0, 0x57);
            D_00764578 = (s32)H_Cdvd_AcquireDirectory((u8 *)path, 0);
            sched->state = 1;
        }
        else
        {
            s32 period;
            sched->state = 2;
            procedureMonth = 0;
            procedureDay = 0;
            calSplitDayOfYear((s16)datGetDateIndex(), &procedureMonth, &procedureDay);
            period = datGetTimeSlot() & 0xFF;
            {
                char labels[6][8] = { "AM_A", "AM_B", "PM_A", "PM_B", "PM_C", "PM_D" };
                sprintf(procedureName, D_00637310, procedureMonth, procedureDay, labels[period & 0xFF]);
            }
            if (D_007637A0 == -1)
            {
                scriptOrSize = 0;
            }
            else
            {
                scriptOrSize = D_0076457C;
                scriptOrSize = (scriptOrSize != 0) ? scriptOrSize : 0;
            }
            if (scriptOrSize == 0)
            {
                kAssertFail(D_006372B0, 0x82);
            }
            procedureIndex = scrFindPrcdIdxByName(scriptOrSize, procedureName);
            if (procedureIndex == -1)
            {
                func_00440b68(D_00637320, procedureName);
                procedureTask = 0;
            }
            else
            {
                procedureTask = scrStartProcedureIndex(0xF, (u8 *)scriptOrSize, procedureIndex);
            }
            sched->procedureTask = procedureTask;
            if (procedureTask == 0)
            {
                kAssertFail(D_006372B0, 0xA4);
            }
        }
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded((HCdvd *)D_00764578) != 0)
        {
            scriptOrSize = (s32)((HCdvd *)D_00764578)->fileSize;
            fileData = (s32)((HCdvd *)D_00764578)->fileMemory;
            if (scriptOrSize > 0x20000)
            {
                kAssertFail(D_006372B0, 0x49);
            }
            if (D_0076457C == 0)
            {
                kAssertFail(D_006372B0, 0x4A);
            }
            memset((void *)D_0076457C, 0, 0x20000);
            memcpy((void *)D_0076457C, (void *)fileData, (u32)scriptOrSize);
            H_Cdvd_Destroy((HCdvd *)D_00764578);
            D_00764578 = 0;
            loaded = 1;
        }
        else
        {
            loaded = 0;
        }
        if (loaded)
        {
            sched->state = 0;
        }
        break;
    case 2:
        sched->state = 3;
        if (D_00764574 != (s16)datGetDateIndex())
        {
            cmmTickReverseProgress();
        }
        D_00764574 = (s16)datGetDateIndex();
        /* fallthrough */
    case 3:
        if (kwlnTaskIsLinked((void *)sched->procedureTask) == 0)
        {
            sched->procedureTask = 0;
            sched->state = 4;
        }
        break;
    case 4:
        if ((sched->flags & 1) != 1)
        {
            sequenceRequest(0x19, 0, 0, 0);
        }
        return -1;
    default:
        break;
    }
    return 0;
}
#pragma opt_propagation on



// FUN_00260440
void cldSchedulerTaskDestroy(u8 *unusedTask)
{
}



/* Replace the live scheduler task using the shared three-word work block. */
// FUN_00260450
/* Preserve argument materialization order with the task API's word handles. */
#pragma opt_propagation off
void cldSchedulerStart(void)
{
    u32 *base = D_008814F0;

    if (D_008814F0[1] != 0 && kwlnTaskIsLinked((void *)base[1]) != 0)
    {
        kwlnTaskDestroyWithHierarchy((KwlnTask *)base[1]);
        base[1] = 0;
    }
    memset(base, 0, 0xC);
    if (base == 0)
    {
        kAssertFail(D_006372B0, 0xD8);
    }
    {
        const void *name = D_00637348;
        s32 priority = 0x100;
        s32 startDelay = 0;
        s32 closeDelay = 0;
        SdkTaskUpdate update = cldSchedulerTaskUpdate;
        SdkTaskDestroy close = cldSchedulerTaskDestroy;
        kwlnTaskCreate((const void *)(name), priority, startDelay, closeDelay, update, close, (u8 *)((s32)base));
    }
}
#pragma opt_propagation on
