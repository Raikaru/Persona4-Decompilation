#include "mt_scene_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit shdScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
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
extern s32 MT_Scene_CheckResSlot(u32 resourceId, u32 value);
extern s64 func_002bab80(void *arg0);
extern void strcpy(u8 *arg0, u8 *arg1);
extern void func_002bbd80(s8 arg0, s32 arg1, void *arg2);
extern s32 func_00248f20(s32 arg0, s32 arg1);
extern void kAssertFail(u8 *arg0, s32 arg1);
extern s32 func_002badc0(s8 arg0, s32 arg1);
extern s32 func_002bb680(s8 arg0);
extern void func_002bb420(s8 arg0);
extern s16 datCategoryRank(s16 arg0);
extern s16 datGetCategoryValueById(s16 arg0, s16 arg1);
extern void datSetCategoryValueById(s16 arg0, s16 arg1, s16 arg2);
extern s32 cmmRankStringAt(s16 arg0, s16 arg1);
extern void frFontExCopyString(char *src, char *dst, s32 maxlen);
extern void func_002bb550(s8 arg0);
extern void func_002bbcf0(s32 arg0);
extern s32 func_0025c790(u8 *task);
extern u32 kwlnTaskGetWork(void *task);
extern s32 func_0045af60(s16 index, s16 stream, s16 arg2, s16 arg3);
extern s32 func_0029d020(void);
extern s32 scrGetParamInt(s32 which);
extern void scrSetReturnInt(s32 arg0);

typedef struct {
    s32 state;
    s32 index;
    s32 value;
    s32 slot;
} ShdScriptWork;



/* Retail MATCH: 996/1008 bytes, 45 resolved relocations; twelve zero tail
   bytes. Promoted rank snapshots preserve the retail narrowing boundaries. */

// FUN_0025C790
s32 func_0025c790(u8 *task)
{
    u8 name[32];
    u8 old_name[32];
    u8 new_name[32];
    ShdScriptWork *work;
    s32 message;
    s32 old_rank;
    s32 increment;
    s32 index;
    s32 previous_rank;
    s32 value;
    s32 new_rank;

    work = (ShdScriptWork *)kwlnTaskGetWork(task);
    switch (work->state) {
    case 0:
        if (MT_Scene_GetRes(0x400) != 0)
            MT_Scene_CheckResSlot(0x400, 6);
        else
            MT_Scene_CheckResSlot(0xC01, 6);
        func_0045af60(0, 0, 4, 3);
        work->slot = (s8)func_002bab80(D_00636850);
        if (work->slot != -1) {
            strcpy(name, D_00636820[work->index]);
            func_002bbd80((s8)work->slot, 0, name);
            message = func_00248f20((s16)work->index, work->value);
            if (message < 0 || message > 2)
                kAssertFail(D_00636838, 0xD1);
            func_002badc0((s8)work->slot, message);
        } else {
            return -1;
        }
        work->state = 1;
        break;
    case 1:
        if (func_002bb680((s8)work->slot) == 0) {
            func_002bb420((s8)work->slot);
            old_rank = datCategoryRank((s16)work->index);
            increment = work->value;
            index = work->index;
            if (index >= 5)
                kAssertFail(D_00636838, 0x90);
            previous_rank = datCategoryRank((s16)index);
            value = (s32)((u32)increment + (u32)(s32)datGetCategoryValueById(1, (s16)index));
            if (value > 999)
                value = 999;
            datSetCategoryValueById(1, (s16)index, (s16)value);
            if (previous_rank != datCategoryRank((s16)index)) {
                new_rank = datCategoryRank((s16)work->index);
                func_0045af60(1, 0, 3, 0);
                strcpy(name, D_00636820[work->index]);
                func_002bbd80((s8)work->slot, 0, name);
                frFontExCopyString((char *)(u32)cmmRankStringAt((s16)work->index, (s16)old_rank), (char *)old_name, 32);
                frFontExCopyString((char *)(u32)cmmRankStringAt((s16)work->index, (s16)new_rank), (char *)new_name, 32);
                func_002bbd80((s8)work->slot, 1, old_name);
                func_002bbd80((s8)work->slot, 2, new_name);
                func_002badc0((s8)work->slot, 3);
                work->state = 2;
            } else {
                func_002bb550((s8)work->slot);
                return -1;
            }
        }
        break;
    case 2:
        if (func_002bb680((s8)work->slot) == 0) {
            func_002bb420((s8)work->slot);
            func_002bb550((s8)work->slot);
            return -1;
        }
        break;
    }
    if (work->slot >= 0)
        func_002bbcf0((s8)work->slot);
    return 0;
}
// FUN_0025CB80
void func_0025cb80(u8 *task)
{
    u32 work;

    work = kwlnTaskGetWork(task);
    DAT_008873ec_abs[0]((void *)work);
}

// FUN_0025CBC0
s32 func_0025cbc0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *mem;

    chkmemAllocSiteTag(D_00636838, 0x113);
    mem = D_008873F4[0](1, 0x10, 0x40000);
    *(s32 *)(mem + 4) = arg1;
    *(s32 *)(mem + 8) = arg2;
    *(s32 *)(mem + 0xC) = -1;
    return (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_00636A30), 0xF, 0, 0, func_0025c790, func_0025cb80, (u8 *)(mem));
}

// FUN_0025CC70
s32 func_0025cc70(void) {
    return kwlnTaskIsLinked(kwlnTaskGetTaskByName(D_00636A30)) != 0;
}

/* measured: explicit hit local and shared done label preserve retail's
   booleanisation and branch targets; object 280B/window 288B, nd 0. */
// FUN_0025CCB0
s32 func_0025ccb0(void) {
    u8 *buf;
    s32 a;
    s32 b;
    s32 hit;

    if (func_0029d020() == 0) {
        a = scrGetParamInt(0);
        b = scrGetParamInt(1);
        chkmemAllocSiteTag(D_00636838, 0x113);
        buf = D_008873F4[0](1, 0x10, 0x40000);
        *(s32 *)(buf + 4) = a;
        *(s32 *)(buf + 8) = b;
        *(s32 *)(buf + 0xC) = -1;
        (s32)kwlnTaskCreateChild((void *)(NULL), (const void *)(D_00636A30), 0xF, 0, 0, func_0025c790, func_0025cb80, (u8 *)(buf));
        goto done;
    }
    hit = kwlnTaskIsLinked(kwlnTaskGetTaskByName(D_00636A30)) != 0;
    if (hit != 0) {
        goto done;
    }
    scrSetReturnInt(0);
    return 1;
done:
    return 0;
}

