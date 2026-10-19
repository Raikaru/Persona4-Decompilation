#include "mt_scene_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit shdScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "scr_internal.h"
extern s32 kwlnTaskIsLinked();
extern s32 kwlnTaskGetTaskByName();
extern u8 D_00636A30[];

typedef void (*code)(void *);
extern code DAT_008873ec_abs[];
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 *D_00636820[];
extern u8 D_00636838[];
extern u8 D_00636850[];
typedef struct Resrc Resrc;
extern s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 value);
extern s64 nmMesWindowAcquire(void *arg0);
extern void strcpy(u8 *arg0, u8 *arg1);
extern void nmMesWindowSetSlotString(s8 arg0, s32 arg1, void *arg2);
extern s32 cmmDateTableRangeKind(s32 arg0, s32 arg1);
extern void kAssertFail(u8 *arg0, s32 arg1);
extern s32 nmMesWindowShowSlotRecord(s8 arg0, s32 arg1);
extern s32 nmMesWindowSlotStatus(s8 arg0);
extern void nmMesWindowRestartSlot(s8 arg0);
extern s16 datCategoryRank(s16 arg0);
extern s16 datGetCategoryValueById(s16 arg0, s16 arg1);
extern void datSetCategoryValueById(s16 arg0, s16 arg1, s16 arg2);
extern s32 cmmRankStringAt(s16 arg0, s16 arg1);
extern void frFontExCopyString(char *src, char *dst, s32 maxlen);
extern void nmMesWindowDestroySlot(s8 arg0);
extern void nmMesWindowStepSlotRelease(s32 arg0);
extern s32 shdScriptCategoryTaskUpdate(u8 *task);
extern u32 kwlnTaskGetWork(void *task);
extern s32 sdkSndStartStream(s16 index, s16 stream, s16 arg2, s16 arg3);

typedef struct {
    s32 state;
    s32 index;
    s32 value;
    s32 slot;
} ShdScriptWork;



/* Retail MATCH: 996/1008 bytes, 45 resolved relocations; twelve zero tail
   bytes. Promoted rank snapshots preserve the retail narrowing boundaries. */

/* Apply the category increment, then wait for its result/rank-up messages. */
// FUN_0025C790
s32 shdScriptCategoryTaskUpdate(u8 *task)
{
    u8 name[32];
    u8 oldName[32];
    u8 newName[32];
    ShdScriptWork *work;
    s32 message;
    s32 oldRank;
    s32 increment;
    s32 index;
    s32 previousRank;
    s32 value;
    s32 newRank;

    work = (ShdScriptWork *)kwlnTaskGetWork(task);
    switch (work->state) {
    case 0:
        if (MT_Scene_GetRes(0x400) != 0)
            MT_Scene_SpawnResIconTask(0x400, 6);
        else
            MT_Scene_SpawnResIconTask(0xC01, 6);
        sdkSndStartStream(0, 0, 4, 3);
        work->slot = (s8)nmMesWindowAcquire(D_00636850);
        if (work->slot != -1) {
            strcpy(name, D_00636820[work->index]);
            nmMesWindowSetSlotString((s8)work->slot, 0, name);
            message = cmmDateTableRangeKind((s16)work->index, work->value);
            if (message < 0 || message > 2)
                kAssertFail(D_00636838, 0xD1);
            nmMesWindowShowSlotRecord((s8)work->slot, message);
        } else {
            return -1;
        }
        work->state = 1;
        break;
    case 1:
        if (nmMesWindowSlotStatus((s8)work->slot) == 0) {
            nmMesWindowRestartSlot((s8)work->slot);
            oldRank = datCategoryRank((s16)work->index);
            increment = work->value;
            index = work->index;
            if (index >= 5)
                kAssertFail(D_00636838, 0x90);
            previousRank = datCategoryRank((s16)index);
            value = (s32)((u32)increment + (u32)(s32)datGetCategoryValueById(1, (s16)index));
            if (value > 999)
                value = 999;
            datSetCategoryValueById(1, (s16)index, (s16)value);
            if (previousRank != datCategoryRank((s16)index)) {
                newRank = datCategoryRank((s16)work->index);
                sdkSndStartStream(1, 0, 3, 0);
                strcpy(name, D_00636820[work->index]);
                nmMesWindowSetSlotString((s8)work->slot, 0, name);
                frFontExCopyString((char *)(u32)cmmRankStringAt((s16)work->index, (s16)oldRank), (char *)oldName, 32);
                frFontExCopyString((char *)(u32)cmmRankStringAt((s16)work->index, (s16)newRank), (char *)newName, 32);
                nmMesWindowSetSlotString((s8)work->slot, 1, oldName);
                nmMesWindowSetSlotString((s8)work->slot, 2, newName);
                nmMesWindowShowSlotRecord((s8)work->slot, 3);
                work->state = 2;
            } else {
                nmMesWindowDestroySlot((s8)work->slot);
                return -1;
            }
        }
        break;
    case 2:
        if (nmMesWindowSlotStatus((s8)work->slot) == 0) {
            nmMesWindowRestartSlot((s8)work->slot);
            nmMesWindowDestroySlot((s8)work->slot);
            return -1;
        }
        break;
    }
    if (work->slot >= 0)
        nmMesWindowStepSlotRelease((s8)work->slot);
    return 0;
}
// FUN_0025CB80
void shdScriptCategoryTaskDestroy(u8 *task)
{
    u32 work;

    work = kwlnTaskGetWork(task);
    DAT_008873ec_abs[0]((void *)work);
}

/* Allocate the category-increment task; a negative slot means no window yet. */
// FUN_0025CBC0
s32 shdScriptCategoryTaskCreate(u8 *parentTask, s32 categoryIndex, s32 increment)
{
    u8 *mem;

    chkmemAllocSiteTag(D_00636838, 0x113);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    ((ShdScriptWork *)mem)->index = categoryIndex;
    ((ShdScriptWork *)mem)->value = increment;
    ((ShdScriptWork *)mem)->slot = -1;
    return (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_00636A30), 0xF, 0, 0, shdScriptCategoryTaskUpdate, shdScriptCategoryTaskDestroy, (u8 *)(mem));
}

// FUN_0025CC70
s32 shdScriptIsCategoryTaskActive(void) {
    return kwlnTaskIsLinked(kwlnTaskGetTaskByName(D_00636A30)) != 0;
}

/* Script command: start once, then suspend until the category task ends. */
/* measured: explicit hit local and shared done label preserve retail's
   booleanisation and branch targets; object 280B/window 288B, nd 0. */
// FUN_0025CCB0
s32 shdScriptCommandIncrementCategory(void) {
    u8 *buf;
    s32 categoryIndex;
    s32 increment;
    s32 taskActive;

    if (scrGetCmdTimer() == 0) {
        categoryIndex = scrGetParamInt(0);
        increment = scrGetParamInt(1);
        chkmemAllocSiteTag(D_00636838, 0x113);
        buf = D_008873F4[0](1, 0x10, 0x40000);
        ((ShdScriptWork *)buf)->index = categoryIndex;
        ((ShdScriptWork *)buf)->value = increment;
        ((ShdScriptWork *)buf)->slot = -1;
        (s32)kwlnTaskCreateChild((void *)(NULL), (const void *)(D_00636A30), 0xF, 0, 0, shdScriptCategoryTaskUpdate, shdScriptCategoryTaskDestroy, (u8 *)(buf));
        goto done;
    }
    taskActive = kwlnTaskIsLinked(kwlnTaskGetTaskByName(D_00636A30)) != 0;
    if (taskActive != 0) {
        goto done;
    }
    scrSetReturnInt(0);
    return 1;
done:
    return 0;
}

