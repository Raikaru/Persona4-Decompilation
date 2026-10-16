#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
s32 kwlnTaskGetTaskByName(void *arg0);
extern u32 kwlnTaskGetWork(void *task);
extern void func_0025f230(s32 arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 D_006367C0[];
extern void func_0045aeb0(s32 arg0, const char *arg1);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 func_00250ad0(s32 *arg0, u8 *arg1);
extern u16 *datPersonaGetRecord(u16 arg0);
extern s32 datPersonaLoadRecord(u8 *arg0, u16 arg1, u8 *arg2);
extern void memcpy(void *arg0, void *arg1, s32 arg2);
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern u32 datGetMoney(void);
extern void datSetMoney(s32 arg0);
extern s32 func_00120e20(s32 arg0, s32 arg1);
extern s32 func_00120ee0(s32 arg0);
extern void func_00120f00(s32 arg0);
extern void func_00120f40(s32 arg0, s64 arg1);
extern s32 iGpffffb480;

s16 func_001060b0(void);
void func_001104d0(s64 arg0, s32 *arg1, s32 *arg2);
void scrSetReturnInt(s32 arg0);
s32 func_00110580(s64 arg0);

s32 scrGetParamInt(s32 arg0);
s16 func_00110600(s32 arg0, s32 arg1);
void func_00106300(s64 arg0);
void func_00106310(s32 arg0);
void func_00106320(s32 arg0);
s32 func_001106f0(s64 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 MT_Scene_CheckResSlot(u32 resourceId, u32 value);
u8 datPersonaGetTotalStatById(u16 arg0, s32 arg1);

s32 func_0029d020(void);
void func_001227d0(void);
s32 func_001227f0(void);

s32 datGetTimeSlot(void);
s8 func_00110960(s16 arg0, s32 arg1);
float scrGetParamFloat(s32 arg0);
s16 datCategoryRankProgress(s16 arg0, float arg1);
s16 datCategoryRank(s16 arg0);
s32 datPersonaAddStatById(u16 arg0, s32 arg1, s32 arg2);
void func_00106620(s16 arg0, s32 arg1);
s16 datGetPartyId(s32 arg0);
void datSetPartyId(s32 arg0, s32 arg1);
s16 func_00106cd0(s16 arg0, s16 arg1);
void func_00106d40(s16 arg0, s16 arg1, s16 arg2);
s32 kwlnTaskIsLinked(s32 arg0);
void func_00120f20(s32 arg0);
s32 mcIconTaskCreate(u8 *parent, s32 mode);
s32 func_002aa3f0(void);
extern s32 func_00481450(void);
extern void func_00481440(s32 arg0);
extern void sdkSpriteDraw(u8 *arg0, s32 arg1);
extern void sdkSpriteFreeNode(void *arg0);
extern u8 *sdkSpriteNewNode(u32 arg0, u32 arg1);
extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void sdkSpriteDrawAndFreeFlag1(s32 arg0, u8 *arg1);
extern void sdkSpriteDrawAndFreeFlag0(s32 arg0, u8 *arg1);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
extern s64 cmmCommunityArcana(s32 arg0);
extern s32 func_0025ef20(u8 *arg0);
extern s32 func_0025f110(s32 arg0);
extern s32 func_0035adc0(s32 arg0, s64 arg1, s32 arg2);
extern s32 func_0035af60(s32 arg0);
extern s32 func_00251f00(s32 arg0, s32 *arg1);
extern void func_00251fc0(s32 arg0, s32 arg1);
extern void func_00252050(s32 arg0, s32 arg1, s32 arg2);
extern void func_002519b0(s32 *arg0);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern f32 cosf(f32 arg0);
extern f32 sinf(f32 arg0);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void func_0045dfd0(void *arg0, void *arg1, f32 farg0,
                           s32 arg2, s32 arg3, s32 arg4);
extern void func_0045ee00(s32 arg0, s32 arg1, void *arg2, s32 arg3,
                           f32 farg0, f32 farg1, s32 arg4);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}













// Intent: Script command: returns the current time slot (datGetTimeSlot) as the script return value [inferred]
// FUN_0025C420
s32 scrGetTimeSlot(void) {
    scrSetReturnInt(datGetTimeSlot() & 0xFF);
    return 1;
}






















#pragma opt_propagation off
#pragma opt_propagation on







/* measured: explicit else placement reproduces retail's out-of-line return-one
   block. Object 120B/window 128B; normalized_diff 0, with the remaining eight
   bytes being retail zero padding. */




// Intent: Draws a sprite node at unit scale with no size offset (wrapper of sdkSpriteDrawNow) [inferred]
// FUN_0025E9E0
void sdkSpriteDrawNowUnscaled(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4) {
    sdkSpriteDrawNow(farg0, farg1, farg2, arg0, arg1, arg2, arg3, arg4, 0, 0, 0.0f, 1.0f, 1.0f);
}
/* measured: plain `(u16)(4096.0f * farg4)` and `(u16)(4096.0f * farg5)` casts reproduce both compiler-generated float-to-unsigned conversion paths; MATCH object 484B/window 496B. Each retail site begins `lui 0x4580; mtc1; mul.s; lui 0x4F00; mtc1; c.ole.s`, then uses low `cvt.w.s; mfc1; andi` or high `sub.s; cvt.w.s; mfc1; lui 0x8000; or; andi` before `sh`. The `or` is after `mfc1`, and the 4096.0f `mul.s` is genuine scaling. */
// Intent: Creates a sprite node at a position with alpha, colour, texture and scale, and draws it when both scales are nonzero [inferred]
// FUN_0025EA20
s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5) {
    u8 *temp_2;

    temp_2 = sdkSpriteNewNode((u32)arg3, arg2);
    *(f32 *)(temp_2 + 8) = farg0;
    *(f32 *)(temp_2 + 0xC) = farg1;
    *(f32 *)(temp_2 + 0x24) = farg2;
    *(s8 *)(temp_2 + 0x11) = (s8)(0xFF - arg1);
    *(s8 *)(temp_2 + 0x28) = (s8)((u32)arg0 >> 0x10);
    *(s8 *)(temp_2 + 0x29) = (s8)((u32)arg0 >> 8);
    *(u8 *)(temp_2 + 0x2A) = (u8)arg0;
    *(s16 *)(temp_2 + 0x1C) = (s16)arg5;
    *(s16 *)(temp_2 + 0x1E) = (s16)arg6;
    *(f32 *)(temp_2 + 0x18) = farg3;
    *(u16 *)(temp_2 + 0x20) = (u16)(4096.0f * farg4);
    *(u16 *)(temp_2 + 0x22) = (u16)(4096.0f * farg5);
    if ((*(u16 *)(temp_2 + 0x20) != 0) &&
        (*(u16 *)(temp_2 + 0x22) != 0)) {
        sdkSpriteDraw(temp_2, arg4);
    }
    sdkSpriteFreeNode(temp_2);
    return 0;
}
/* measured: plain `(u16)(4096.0f * farg4)` and `(u16)(4096.0f * farg5)` casts reproduce both compiler-generated float-to-unsigned conversion paths; MATCH object 588B/window 592B. Each retail site begins `lui 0x4580; mtc1; mul.s; lui 0x4F00; mtc1; c.ole.s`, then uses low `cvt.w.s; mfc1; andi` or high `sub.s; cvt.w.s; mfc1; lui 0x8000; or; andi` before `sh`. The `or` is after `mfc1`, and the 4096.0f `mul.s` is genuine scaling. */
// Intent: Creates a sprite node like sdkSpriteDrawNow but queues its draw as a task callback; arg4 == 1 selects the flag-1 callback [inferred]
// FUN_0025ECD0
s32 sdkSpriteDrawQueued(f32 farg0, f32 farg1, f32 farg2,
                  s32 arg0, u8 arg1, s32 arg2, void *arg3,
                  s32 arg4, s16 arg5, s16 arg6,
                  f32 farg3, f32 farg4, f32 farg5, void *arg7) {
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = func_00460990();
    temp_2 = sdkSpriteNewNode((u32)arg3, arg2);
    *(f32 *)(temp_2 + 8) = farg0;
    *(f32 *)(temp_2 + 0xC) = farg1;
    *(f32 *)(temp_2 + 0x24) = farg2;
    *(s8 *)(temp_2 + 0x11) = (s8)(0xFF - arg1);
    *(s8 *)(temp_2 + 0x28) = (s8)((u32)arg0 >> 0x10);
    *(s8 *)(temp_2 + 0x29) = (s8)((u32)arg0 >> 8);
    *(u8 *)(temp_2 + 0x2A) = arg0;
    *(s16 *)(temp_2 + 0x1C) = arg5;
    *(s16 *)(temp_2 + 0x1E) = arg6;
    *(f32 *)(temp_2 + 0x18) = farg3;
    *(u16 *)(temp_2 + 0x20) = (u16)(4096.0f * farg4);
    *(u16 *)(temp_2 + 0x22) = (u16)(4096.0f * farg5);
    if (*(u16 *)(temp_2 + 0x20) == 0) {
        goto cleanup;
    }
    if (*(u16 *)(temp_2 + 0x22) == 0) {
        goto cleanup;
    }
    if (arg4 != 1) {
        goto callback_2;
    }
    *(void **)(temp_16 + 8) = (void *)sdkSpriteDrawAndFreeFlag1;
    *(u8 **)(temp_16 + 0x10) = temp_2;
    goto callback_call;
callback_2:
    *(void **)(temp_16 + 8) = (void *)sdkSpriteDrawAndFreeFlag0;
    *(u8 **)(temp_16 + 0x10) = temp_2;
callback_call:
    func_00460ac0(arg7, temp_16);
    goto done;
cleanup:
    sdkSpriteFreeNode(temp_2);
done:
    return 0;
}
// Intent: Queued draw callback: draws the sprite node with flag 1, then frees it [inferred]
// FUN_0025EC10
void sdkSpriteDrawAndFreeFlag1(s32 arg0, u8 *arg1) {
    sdkSpriteDraw(arg1, 1);
    sdkSpriteFreeNode(arg1);
}
// Intent: Queued draw callback: draws the sprite node with flag 0, then frees it [inferred]
// FUN_0025EC50
void sdkSpriteDrawAndFreeFlag0(s32 arg0, u8 *arg1) {
    sdkSpriteDraw(arg1, 0);
    sdkSpriteFreeNode(arg1);
}
// Intent: Queued unit-scale sprite draw (wrapper of sdkSpriteDrawQueued) [inferred]
// FUN_0025EC90
void sdkSpriteDrawQueuedUnscaled(f32 farg0, f32 farg1, f32 farg2,
                   s32 arg0, u8 arg1, s32 arg2, void *arg3, s32 arg4, void *arg5) {
    sdkSpriteDrawQueued(farg0, farg1, farg2, arg0, arg1, arg2, arg3, arg4,
                  0, 0, 0.0f, 1.0f, 1.0f, arg5);
}
// Intent: Task update for a blur filter task: advances the direct or copied blur filter and syncs it [inferred]
// FUN_0025F960
s32 effBlurFilterTaskUpdate(u8 *task) {
    s32 var_17;
    s32 *p;
    s32 temp_3;

    p = (s32 *)kwlnTaskGetWork(task);
    if (p[4] != 0) {
        var_17 = func_00481450();
        func_00481440(p[4]);
    }
    temp_3 = p[0];
    switch (temp_3) {
    case 0:
        effBlurFilterDirectAdvanceAndSync((u8 *)p[1]);
        p[2] = p[2] + 1;
        break;
    case 1:
        effBlurFilterCopiedAdvanceAndSync((u8 *)p[1]);
        p[2] = p[2] + 1;
        break;
    }
    if (p[4] != 0) {
        func_00481440(var_17);
    }
    return 0;
}
// Intent: Task destroy for a blur filter task: destroys the direct or copied blur filter, then frees the work block [inferred]
// FUN_0025FA30
void effBlurFilterTaskDestroy(u8 *task)
{
    s32 *temp_2;
    s32 temp_3;

    temp_2 = (s32 *)kwlnTaskGetWork(task);
    temp_3 = temp_2[0];
    switch (temp_3) {
    case 0:
        effBlurFilterDirectDestroy((void *)temp_2[1]);
        break;
    case 1:
        effBlurFilterCopiedDestroy((void *)temp_2[1]);
        break;
    }
    jtbl_008873EC[0](temp_2);
}
// FUN_0025FF60
s32 func_0025ff60(s32 task)
{
    s32 *p;
    p = (s32 *)kwlnTaskGetWork((void *)(u32)task);
    return p[0];
}
