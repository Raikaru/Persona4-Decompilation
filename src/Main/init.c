/* Whole-file translation unit: src/Main/init.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"
#include "sdk_task_registration.h"

extern void func_00440b68(...);
extern void memcpy(void *dest, const void *src, u32 size);
extern void *func_00454a60(const char *path, s32 flags);
extern void H_Cdvd_Destroy(void *handle);
extern s32 H_Cdvd_IsFileLoaded(void *handle);

extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void datEntryTableUseBuiltin(void);
extern s32 calendarStartTasks(s32);
extern void loadingSpinnerRequestShow(void);
extern void loadingSpinnerRequestHide(void);
extern s32 kwlnTaskGetState(s32);
extern s32 hsndSlotIsStarting();
extern void func_001029a0(s32, s32, s32, s32);
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
s32 initDataReadStep(u8 *arg0)
{
    u8 *temp_16;
    s32 temp_3;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)temp_16;
    switch (temp_3) {
    case 0:
        func_00440b68(&D_00762CB8, &D_00762CC0, 0x1FA);
        *(u8 **)(temp_16 + 4) = func_00454a60(D_005E46A0, 0);
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded(*(u8 **)(temp_16 + 4)) == 1) {
            temp_2 = *(u8 **)(temp_16 + 4);
            memcpy(&D_0079BF00, *(u8 **)(temp_2 + 0x110), *(s32 *)(temp_2 + 0x118));
            H_Cdvd_Destroy(*(u8 **)(temp_16 + 4));
            *(u8 **)(temp_16 + 4) = NULL;
            datEntryTableUseBuiltin();
            return -1;
        }
        break;
    }
    return 0;
}

/* Destroy callback of the init-data read task: releases the pending read handle. */
// FUN_001118A0
void initDataReadDestroy(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        H_Cdvd_Destroy(temp_4);
        *(u8 **)(temp_16 + 4) = NULL;
    }
    jtbl_008873EC[0](temp_16);
}

/* Starts the init-data read task that loads the boot tables. */
// FUN_001118F0
s32 initDataReadStart(void)
{
    s32 temp_2;
    s32 var_2;

    chkmemAllocSiteTag(&D_00762CC0, 0x21E);
    temp_2 = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    var_2 = (s32)kwlnTaskCreate((const void *)(D_005E46C0), 0x100, 0, 0, initDataReadStep, initDataReadDestroy, (u8 *)(temp_2));
    return var_2 == 0 ? 0 : var_2;
}

/* Boot chain step task: runs its three step callbacks in turn, then ends the chain. */
// FUN_00111990
s32 initBootChainStep(u8 *arg0)
{
    typedef s32 (*StepCallback)(void);
    StepCallback callbacks[8];
    u32 *var_7;
    u32 *var_6;
    s32 var_5;
    s32 temp_3_2;
    s32 temp_3;
    s32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_7 = (u32 *)D_005E46D0;
    var_6 = (u32 *)callbacks;
    var_5 = 3;
    do {
        temp_3 = var_7[0];
        temp_2 = var_7[1];
        var_7 += 2;
        var_5 -= 1;
        var_6[0] = temp_3;
        var_6[1] = temp_2;
        var_6 += 2;
    } while (var_5 > 0);
    temp_3_2 = *(s32 *)temp_16;
    switch (temp_3_2) {
    case 0:
        if ((hsndSlotIsStarting(0, var_5, var_6, var_7) != 0) && (hsndSlotIsStarting(1) != 0)) {
            *(s32 *)(temp_16 + 4) = 0;
            *(s32 *)temp_16 = 1;
            loadingSpinnerRequestShow();
        }
        break;
    case 1:
        if (callbacks[*(s32 *)(temp_16 + 4)] == NULL) {
            loadingSpinnerRequestHide();
            calendarStartTasks(0);
            return -1;
        }
        *(s32 *)(temp_16 + 8) = (s32)callbacks[*(s32 *)(temp_16 + 4)]();
        *(s32 *)temp_16 = 2;
        break;
    case 2:
        if (kwlnTaskGetState(*(s32 *)(temp_16 + 8)) == 3) {
            *(s32 *)(temp_16 + 4) += 1;
            *(s32 *)temp_16 = 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

/* Destroy callback of the boot chain: calls the destroy table, then requests sequence 27. */
// FUN_00111AE0
void initBootChainDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
    datInitDefaultGameState();
    func_001029a0(0x1B, 0, 0, 5);
}

/* Starts the boot chain task, which runs the init-data read and the step callbacks. */
// FUN_00111B30
s32 initBootChainStart(void)
{
    s32 temp_2;

    chkmemAllocSiteTag(&D_00762CC0, 0x288);
    temp_2 = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    return (s32)kwlnTaskCreate((const void *)(D_005E46E8), 0x100, 0, 0, initBootChainStep, initBootChainDestroy, (u8 *)(temp_2));
}
