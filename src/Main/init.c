/* Whole-file translation unit: src/Main/init.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"
#include "sdk_task_registration.h"
#include "kwln_task_internal.h"
#include "h_cdvd_internal.h"

/* Both boot tasks allocate 0x0C bytes; only the read task's tail is unknown. */
typedef struct InitDataReadWork
{
    s32 state;
    void *file;
    u32 unk08;
} InitDataReadWork;

typedef struct InitBootChainWork
{
    s32 state;
    s32 stepIndex;
    s32 childTask;
} InitBootChainWork;

extern void memcpy(void *dest, const void *src, u32 size);
extern void *H_Cdvd_AcquireDirectory(const char *path, s32 flags);

extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void datEntryTableUseBuiltin(void);
extern s32 calendarStartTasks(s32);
extern void loadingSpinnerRequestShow(void);
extern void loadingSpinnerRequestHide(void);
extern s32 kwlnTaskGetState(s32);
extern s32 hsndSlotIsStarting();
extern void sequenceRequest(s32, s32, s32, s32);
extern void datInitDefaultGameState(void);
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern char D_00762CB8;
extern char D_00762CC0;
extern char D_005E46A0[];
extern char D_005E46C0[];
extern char D_005E46D0[];
extern char D_005E46E8[];
extern u8 D_0079BF00[];

/* Init-data read step: loads init/itemtbl.bin once the file is ready, then unloads the handle. */
// FUN_001117C0
/* Typed read-work fields add saved-register/address temporaries under b210;
 * retain byte accesses to InitDataReadWork and HCdvd (+0x110/+0x118) for MATCH. */
s32 initDataReadStep(u8 *task)
{
    u8 *work;
    s32 state;
    u8 *file;

    work = ((KwlnTask *)task)->work;
    state = *(s32 *)work;
    switch (state) {
    case 0:
        func_00440b68(&D_00762CB8, &D_00762CC0, 0x1FA);
        *(u8 **)(work + 4) = H_Cdvd_AcquireDirectory(D_005E46A0, 0);
        *(s32 *)work += 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded((HCdvd *)*(u8 **)(work + 4)) == 1) {
            file = *(u8 **)(work + 4);
            memcpy(&D_0079BF00, *(u8 **)(file + 0x110), *(s32 *)(file + 0x118));
            H_Cdvd_Destroy((HCdvd *)*(u8 **)(work + 4));
            *(u8 **)(work + 4) = NULL;
            datEntryTableUseBuiltin();
            return -1;
        }
        break;
    }
    return 0;
}

/* Destroy callback of the init-data read task: releases the pending read handle. */
// FUN_001118A0
/* Typed read-work fields add saved-register/address temporaries under b210;
 * retain byte accesses to InitDataReadWork and HCdvd (+0x110/+0x118) for MATCH. */
void initDataReadDestroy(u8 *task)
{
    u8 *work;
    u8 *file;

    work = ((KwlnTask *)task)->work;
    file = *(u8 **)(work + 4);
    if (file != NULL) {
        H_Cdvd_Destroy((HCdvd *)file);
        *(u8 **)(work + 4) = NULL;
    }
    jtbl_008873EC[0](work);
}

/* Starts the init-data read task that loads the boot tables. */
// FUN_001118F0
s32 initDataReadStart(void)
{
    s32 work;
    s32 task;

    chkmemAllocSiteTag(&D_00762CC0, 0x21E);
    work = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (work == 0) {
        return 0;
    }
    task = (s32)kwlnTaskCreate((const void *)(D_005E46C0), 0x100, 0, 0, initDataReadStep, initDataReadDestroy, (u8 *)(work));
    return task == 0 ? 0 : task;
}

/* Boot chain step task: runs its three step callbacks in turn, then ends the chain. */
// FUN_00111990
s32 initBootChainStep(u8 *task)
{
    typedef s32 (*StepCallback)(void);
    StepCallback callbacks[8];
    u32 *sourceCallbacks;
    u32 *copiedCallbacks;
    s32 pairsRemaining;
    s32 state;
    s32 firstCallback;
    s32 secondCallback;
    u8 *work;

    work = ((KwlnTask *)task)->work;
    sourceCallbacks = (u32 *)D_005E46D0;
    copiedCallbacks = (u32 *)callbacks;
    pairsRemaining = 3;
    do {
        firstCallback = sourceCallbacks[0];
        secondCallback = sourceCallbacks[1];
        sourceCallbacks += 2;
        pairsRemaining -= 1;
        copiedCallbacks[0] = firstCallback;
        copiedCallbacks[1] = secondCallback;
        copiedCallbacks += 2;
    } while (pairsRemaining > 0);
    state = ((InitBootChainWork *)work)->state;
    switch (state) {
    case 0:
        if ((hsndSlotIsStarting(0, pairsRemaining, copiedCallbacks, sourceCallbacks) != 0) && (hsndSlotIsStarting(1) != 0)) {
            ((InitBootChainWork *)work)->stepIndex = 0;
            ((InitBootChainWork *)work)->state = 1;
            loadingSpinnerRequestShow();
        }
        break;
    case 1:
        if (callbacks[((InitBootChainWork *)work)->stepIndex] == NULL) {
            loadingSpinnerRequestHide();
            calendarStartTasks(0);
            return -1;
        }
        ((InitBootChainWork *)work)->childTask = (s32)callbacks[((InitBootChainWork *)work)->stepIndex]();
        ((InitBootChainWork *)work)->state = 2;
        break;
    case 2:
        if (kwlnTaskGetState(((InitBootChainWork *)work)->childTask) == 3) {
            ((InitBootChainWork *)work)->stepIndex += 1;
            ((InitBootChainWork *)work)->state = 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

/* Destroy callback of the boot chain: calls the destroy table, then requests sequence 27. */
// FUN_00111AE0
void initBootChainDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
    datInitDefaultGameState();
    sequenceRequest(0x1B, 0, 0, 5);
}

/* Starts the boot chain task, which runs the init-data read and the step callbacks. */
// FUN_00111B30
s32 initBootChainStart(void)
{
    s32 work;

    chkmemAllocSiteTag(&D_00762CC0, 0x288);
    work = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (work == 0) {
        return 0;
    }
    return (s32)kwlnTaskCreate((const void *)(D_005E46E8), 0x100, 0, 0, initBootChainStep, initBootChainDestroy, (u8 *)(work));
}
