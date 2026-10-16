/* Original translation unit y_fclCombineEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
extern void sdkSndFadeOutChannelFrames();
extern void (*jtbl_008873EC[])(void *ptr);
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern u8 D_0064A400[];
extern u8 D_0064A420[];
extern u8 D_0064A440[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern s32 fclCombineEventTaskUpdate(u8 *task);
extern void fclCombineEventTaskDestroy(u8 *arg0);
extern s32 fclCombineEventGate(u8 *arg0);
extern s32 fclCombineEventSceneUpdate(u8 *arg0);
extern s32 func_00285b30(void);
extern void datSetFlag(s32 a, s32 b);
extern u16 D_008C024E[];
extern s32 func_00293ed0(s32 a, s32 b, s32 c, s32 d);
extern s32 func_00293fc0(s32 arg0);
extern s32 func_002940a0(s32 arg0, s32 *a, s32 *b, s32 *c, s32 *d);
extern void fieldSceneLoad(s32 a, s32 b);
extern void func_00144e10(s32 a);
extern void func_00144ed0(s32 a);
extern s32 fieldSceneLoadStep(void);
extern s32 func_002859e0(s32 a, s32 b, s32 c);
extern s32 kwlnTaskIsLinked(s32 handle);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern void fieldSceneUnload(void);


// FUN_0033DC90
void fclCombineEventTaskCreate(u8 *arg0, s8 arg1)
{
    u8 *work;

    chkmemAllocSiteTag(D_0064A400, 0xAF);
    work = D_008873F4[0](1, 0x14, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0064A420), 0xF, 0, 0, fclCombineEventTaskUpdate, fclCombineEventTaskDestroy, (u8 *)(work));
    work[0] = 0;
    *(s8 *)(work + 0x10) = arg1;
}


// Fcl combine event gate: returns -1 and sets the event's flag when a blocking flag or map range applies, else 0.
// FUN_0033DD40
s32 fclCombineEventGate(u8 *arg0)
{
    s32 *temp_16;

    temp_16 = *(s32 **)(arg0 + 0x38);
    if (func_00285b30() >= 4) {
        if ((func_00285b30() >= 0x11D) && (func_00285b30() < 0x12C)) {
            return 0;
        }
        if ((func_00285b30() >= 0x1A5) && (func_00285b30() < 0x1BD)) {
            return 0;
        }
        if (D_008C024E[0] & 0x800) {
            datSetFlag(*temp_16, 1);
            return -1;
        }
        if (D_008C024E[0] & 0x40) {
            datSetFlag(*temp_16, 1);
            return -1;
        }
    }
    return 0;
}


// Fcl combine event destroy: stops sound channel 2 and frees the task's work buffer.
// FUN_0033DE40
void fclCombineEventDestroy(u8 *arg0) {
    sdkSndFadeOutChannelFrames(2, 0, 0);
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}


// FUN_0033DE90
void fclCombineEventGateCreate(u8 *arg0, s32 arg1)
{
    u8 *work;

    chkmemAllocSiteTag(D_0064A400, 0x10A);
    work = D_008873F4[0](1, 4, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0064A440), 0xF, 0, 0, fclCombineEventGate, fclCombineEventDestroy, (u8 *)(work));
    *(s32 *)work = arg1;
}


// FUN_0033DF40
s32 fclCombineEventSceneUpdate(u8 *arg0)
{
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 temp_4_2;
    s8 temp_4;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = (s8)temp_16[0];
    switch (temp_4) {
    case 0:
        *(s32 *)(temp_16 + 0x10) = func_00293ed0(*(s32 *)(temp_16 + 4), *(s32 *)(temp_16 + 8), 0, 0);
        temp_16[0] = (s8)((s8)temp_16[0] + 1);
        /* fallthrough */
    case 1:
        if ((func_00293fc0(*(s32 *)(temp_16 + 0x10)) != 0) && (func_002940a0(*(s32 *)(temp_16 + 0x10), &sp2C, &sp28, &sp24, &sp20) == 1)) {
            if (*(s32 *)(temp_16 + 8) == 0xA) {
                fieldSceneLoad(sp2C, sp28);
            }
            func_00144e10((s16)sp24);
            func_00144ed0(3);
            temp_16[0] = (s8)((s8)temp_16[0] + 1);
        }
        goto out;
    case 2:
        if (fieldSceneLoadStep() != 0) {
            *(s32 *)(temp_16 + 0xC) = func_002859e0(*(s32 *)(temp_16 + 4), *(s32 *)(temp_16 + 8), 0);
            temp_16[0] = (s8)((s8)temp_16[0] + 1);
        case 3:
            if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0xC)) != 1) {
                temp_4_2 = *(s32 *)(temp_16 + 0x10);
                if (temp_4_2 != 0) {
                    kwlnTaskDestroyWithHierarchy(temp_4_2);
                }
                if (*(s32 *)(temp_16 + 8) == 0xA) {
                    fieldSceneUnload();
                }
                temp_16[0] = (s8)((s8)temp_16[0] + 1);
            }
        }
        goto out;
    case 4:
    case 5:
        temp_16[0] = (s8)(temp_4 + 1);
        goto out;
    case 6:
        return -1;
    default:
    out:
        return 0;
    }
}


// FUN_0033E0F0
void fclCombineEventSceneDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}


// FUN_0033E120
void fclCombineEventSceneCreate(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *work;

    chkmemAllocSiteTag(D_0064A400, 0x192);
    work = D_008873F4[0](1, 0x14, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0064A440), 0xF, 0, 0, fclCombineEventSceneUpdate, fclCombineEventSceneDestroy, (u8 *)(work));
    *(s32 *)(work + 4) = arg1;
    *(s32 *)(work + 8) = arg2;
    work[0] = 0;
}
