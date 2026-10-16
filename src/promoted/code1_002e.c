#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fr_font_internal.h"
extern void (*jtbl_008873EC[])(void *arg0);
typedef FclVec2 f2;
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} u4;
extern void fclSpriteStartPosition(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);
extern u8 *iGpffffb588;
extern u8 *iGpffffb590;
extern u8 *func_002e1db0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u32 datGetMoney(void);
extern s32 func_002e1230();
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern s32 func_0046a770(const void *arg0);
extern u8 D_0063FB50[];
extern u8 D_0063FAA0[];
extern u8 D_0063FB90[];
extern u8 D_0063FC80[];
extern u8 D_0063FC90[];
extern void *(*D_008873F4[])(size_t numObj, size_t sizeObj, u32 hint);
extern void chkmemAllocSiteTag(const void *arg0, u32 arg1);



extern void sdkSndFadeOutChannelFrames(s16 arg0, s32 arg1, s32 arg2);
extern s32 func_00106b20(s16 arg0);
extern s32 func_00106b50(s16 arg0);






s16 datGetDateIndex(void);
void calSplitDayOfYear(s64 arg0, s32 *arg1, s32 *arg2);

s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void datSetMoney(s32 arg0);
extern u8 D_0063F560[];



// FUN_002E04E0
u8 *func_002e04e0(u8 *arg0)
{
    return *(u8 **)(arg0 + 0x38);
}
// FUN_002E04F0
void func_002e04f0(u8 *arg0, u32 arg1, s8 arg2) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    if (arg2 == 0) {
        *(s16 *)(base + 4) |= (s16)((1 << (arg1 & 0xffff)) & 0xffff);
        return;
    }
    if (arg2 == 1) {
        *(s16 *)(base + 4) &= (s16)((1 << (arg1 & 0xffff)) ^ 0xffff);
        return;
    }
}
// FUN_002E0570
s8 func_002e0570(u8 *arg0, s32 arg1)
{
    s16 flags;

    flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 4);
    return (s8)((flags & ((1 << (arg1 & 0xFFFF)) & 0xFFFF)) >> (arg1 & 0xFFFF));
}



// FUN_002E05A0
s8 func_002e05a0(u8 *arg0) {
    s16 flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x4);
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

// FUN_002E0620
void func_002e0620(u8 *arg0, f2 p1, f2 p2, u32 arg3, u32 arg4, s16 arg5) {
    fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4, p1, p2, arg3, arg4, arg5);
}
// FUN_002E0660
void func_002e0660(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, s16 arg5)
{
    fclSpriteStartAlpha(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, (s16)arg5);
}



// FUN_002E0690
/* Parameter order taken from the caller at func_002d3ee0 in
   src/Event/Fcl/y_fclShopDraw.c: b210 emits argument setup in source order, and
   retail emits `mov.s $f13, $f12` between `lw $a0` and `move $a1`, which only
   happens when the two floats are arguments 2 and 3.  The EABI assigns integer
   and float arguments to their own register files, so this order compiles to
   the same object as the ints-first spelling (measured: identical bytes). */
void func_002e0690(u8 *arg0, f32 fparg0, f32 fparg1, u32 arg1, u32 arg2, s64 arg3)
{
    fclSpriteStartRevealScale(*(u8 **)(arg0 + 0x38) + 4, fparg0, fparg1, fparg0, fparg1, arg1, arg2, (s16)arg3);
}
// FUN_002E06D0
void func_002e06d0(u8 *arg0, f32 scale0, f32 scale1, f32 scale2, f32 scale3, u32 arg1, u32 arg2, s64 arg3)
{
    fclSpriteStartRevealScale(*(u8 **)(arg0 + 0x38) + 4, scale0, scale1, scale2, scale3, arg1, arg2, (s16)arg3);
}



/* measured: retain pair loads before stores and retail's written load order. */
#pragma push
#pragma opt_propagation off
// FUN_002E0700
void func_002e0700(u8 *arg0, s64 arg1, f32 fparg0, f32 fparg1,
                   s32 arg2, s32 arg3, s64 arg4)
{
    f2 pos;
    f2 out1;
    f2 out2;
    f2 draw1;
    f2 draw2;
    f32 out1_x;
    f32 out1_y;
    f32 out2_x;
    f32 out2_y;
    f32 pos_x;
    f32 pos_y;
    u8 *handle;
    u8 *temp;
    extern u8 *sdkSpriteNewNode(u32 arg0, u32 arg1);
    extern f32 sdkSpriteScaledHeight(u8 *arg0);
    u8 *base;
    extern void sdkSpriteFreeNode(void *node);
    temp = *(u8 **)(arg0 + 0x38);
    pos_x = *(f32 *)(temp + 0x2C);
    pos_y = *(f32 *)(temp + 0x30);
    pos.x = pos_x;
    pos.y = pos_y;
    if ((s8)arg4 == 1) {
        handle = sdkSpriteNewNode(*(u32 *)(temp + 0xF4), (s16)arg1);
        out1 = func_002b2970(pos.x,
                             pos.y - (sdkSpriteScaledHeight(handle) / 2.0f));
        out1_x = out1.x;
        out1_y = out1.y;
        draw1.x = out1_x;
        draw1.y = out1_y;
        arg3 = (s16)arg3;
        fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4, pos, draw1, 0, arg2,
                       arg3);
        sdkSpriteFreeNode(handle);
        fclSpriteStartAlpha(*(u8 **)(arg0 + 0x38) + 4, 0, 0xFF, 0, arg2, arg3);
    } else {
        handle = sdkSpriteNewNode(*(u32 *)(temp + 0xF4), (s16)arg1);
        out2 = func_002b2970(pos.x,
                             pos.y + (sdkSpriteScaledHeight(handle) / 2.0f));
        out2_x = out2.x;
        out2_y = out2.y;
        draw2.x = out2_x;
        draw2.y = out2_y;
        arg3 = (s16)arg3;
        fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4, pos, draw2, 0, arg2,
                       arg3);
        sdkSpriteFreeNode(handle);
        fclSpriteStartAlpha(*(u8 **)(arg0 + 0x38) + 4, 0xFF, 0, 0, 0,
                       (s16)((s32)arg3 + arg2));
    }
    base = *(u8 **)(arg0 + 0x38);
    fclSpriteStartRevealScale(base + 4, 1.0f, 1.0f, fparg0, fparg1, 0, arg2, arg3);
}
#pragma pop
// FUN_002E0940
void func_002e0940(u8 *arg0, f32 first, f32 second, u8 mode, s32 duration, s64 delay)
{
    fclSpriteStartTween(*(u8 **)(arg0 + 0x38) + 4, mode, duration, delay, first, second);
}



/* measured: replacing the two scalar result stores with a two-f32 aggregate
   copy preserves retail's grouped output loads and store-source registers. */

// FUN_002E0970
void func_002e0970(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s64 arg5)
{
    extern void fclSpriteStartColor(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s16 arg5);
    fclSpriteStartColor(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, arg5);
}

// FUN_002E09B0
void func_002e09b0(u8 *arg0, f32 fparg0, s16 arg1)
{
    u8 *temp = *(u8 **)(arg0 + 0x38);
    s16 flags = *(s16 *)(temp + 4);
    *(s16 *)(temp + 4) = flags | 0x80;
    *(s16 *)(temp + 0xF0) = 0;
    *(f32 *)(temp + 0xEC) = fparg0;
    *(s16 *)(temp + 0xF2) = arg1;
}
// FUN_002E09E0
void func_002e09e0(u8 *arg0, s32 arg1, f32 fparg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);
    f32 *entry = (f32 *)(D_0063F560 + *(s16 *)(work + 0xF8) * 8);
    f2 out;
    *(s16 *)(work + 4) |= 1;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 8) = fparg0;
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xFC) = arg1;
    work = *(u8 **)(arg0 + 0x38);
    out = func_002b2970(entry[0], entry[1]);
    *(f2 *)(work + 0x2C) = out;
}

// FUN_002E0A60
void func_002e0a60(u8 *arg0, s32 arg1, f32 fparg0)
{
    u8 *work;
    u8 *entry;
    f2 out;

    work = *(u8 **)(arg0 + 0x38);
    entry = D_0063F560 + *(s16 *)(work + 0xF8) * 8;
    *(s16 *)(work + 4) |= 1;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 8) = fparg0;
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xFC) = arg1;
    work = *(u8 **)(arg0 + 0x38);
    out = func_002b2970(*(f32 *)entry, *(f32 *)(entry + 4));
    *(f2 *)(work + 0x2C) = out;
    work = *(u8 **)(arg0 + 0x38);
    *(u8 *)(work + 0x62) = 0xFF;
    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 0xA0) = 0x3F800000;
    *(s32 *)(work + 0x94) = 0x3F800000;
    work = *(u8 **)(arg0 + 0x38);
    *(s8 *)(work + 0xCF) = 0;
    *(s8 *)(work + 0xA7) = 0;
    *(s8 *)(work + 0x67) = 0;
    *(s8 *)(work + 0x3B) = 0;
}
// FUN_002E0B20
void func_002e0b20(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, u8 arg3,
                   s32 arg4, u8 *arg5)
{
    sdkSpriteDrawQueued(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF, (void *)(u32)func_0046a770(D_0063FB50), arg4, 0, 0, 0.0f, 1.0f, 1.0f, arg5);
}
// FUN_002E0BE0
void func_002e0be0(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, u8 arg3,
                   s32 arg4, u8 *arg5)
{
    sdkSpriteDrawQueued(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF, (void *)(u32)func_0046a770(D_0063FAA0), arg4, 0, 0, 0.0f, 1.0f, 1.0f, arg5);
}
// FUN_002E0CA0
void func_002e0ca0(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, u8 arg3,
                   s32 arg4, u8 *arg5)
{
    sdkSpriteDrawQueued(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF, (void *)(u32)func_0046a770(D_0063FB90), arg4, 0, 0, 0.0f, 1.0f, 1.0f, arg5);
}
// FUN_002E0D60
s32 func_002e0d60(void)
{
    u8 *temp = func_002e1db0(0x30, 0, 0, 0);
    iGpffffb588 = temp;
    return *(s32 *)(temp + 0x24);
}
// FUN_002E0DA0
s64 func_002e0da0(void)
{
    return (s64)(func_002e1230() != 0) << 0x30 >> 0x30;
}










/* measured: retail normalises the (s16) search value once in the loop
   preheader; plain -O2 re-narrows it inside the body (nd 69 at 132 bytes
   against a 128-byte window). With the hoist it is byte-exact. */
// FUN_002E6F90
#pragma opt_loop_invariants on
s32 func_002e6f90(u8 *arg0, s32 arg1) {
    s32 i = 0;
    s16 val = (s16)arg1;
    s16 n = *(s16 *)(arg0 + 0x60);

    while ((s16)i < n) {
        if (*(s16 *)(arg0 + (s16)i * 2) == val) {
            return 0;
        }
        i = (s16)(i + 1);
    }
    *(s16 *)(arg0 + n * 2) = arg1;
    *(s16 *)(arg0 + 0x60) = *(s16 *)(arg0 + 0x60) + 1;
    return 1;
}
/* measured: hoist (s16)arg1 normalization out of loop */
#pragma opt_loop_invariants off

/* measured: loop-invariant sentinel loads are hoisted to retail preheaders */
#pragma opt_loop_invariants on
// FUN_002E7010
s32 func_002e7010(u8 *arg0, s16 arg1)
{
    u8 v2;
    s16 i;
    s16 v4;
    s16 v5;
    s16 v7;
    s16 j;
    s16 v9;
    u8 v10;
    s16 k;
    s16 minus_one;
    s16 temp[0x30];

    v2 = 0;
    minus_one = -1;
    for (i = 0; i < 0x30; i++) {
        temp[i] = minus_one;
    }
    minus_one = -1;
    for (v4 = 0, v5 = arg1; v4 < *(s16 *)(arg0 + 0x60); v4++) {
        if (v5 == *(s16 *)(arg0 + v4 * 2)) {
            *(s16 *)(arg0 + v4 * 2) = minus_one;
        }
    }
    for (j = 0; j < *(s16 *)(arg0 + 0x60); j++) {
        v9 = *(s16 *)(arg0 + j * 2);
        if (v9 != minus_one) {
            temp[v2++] = v9;
        }
    }
    v10 = 0;
    minus_one = -1;
    for (k = (s16)0; *(s16 *)(arg0 + 0x60) > k; k++) {
        if (temp[k] != minus_one) {
            *(s16 *)(arg0 + v10++ * 2) = temp[k];
        }
    }
    *(s16 *)(arg0 + 0x60) = *(s16 *)(arg0 + 0x60) - 1;
    return 1;
}
/* measured: scoped loop-invariant optimization for func_002e7010 */
#pragma opt_loop_invariants off
// FUN_002E7190
void func_002e7190(u8 *arg0) {
    jtbl_008873EC[0](arg0);
}
// FUN_002E71C0
s32 func_002e71c0(void)
{
    s16 item;
    s32 found;
    s16 itemCopy;

    found = 0;
    item = 0x300;
    goto loop_test;
loop_body:
    if (func_002bdff0(item) == 1)
    {
        if ((clndGetMoonPhase(itemCopy) & 0xFF) == 0)
        {
            func_00110810(item, (clndGetMoonPhase(item) & 0xFF) | 1);
            found = 1;
        }
        else if (((u8)clndGetMoonPhase(itemCopy)) & 1)
        {
            found = 1;
        }
    }
    item++;
loop_test:
    itemCopy = (s16)item;
    if (itemCopy < 0x3FF)
    {
        goto loop_body;
    }
    return (s8)found == 1;
}
/* measured: corrected callee declarations; variadic call casts preserve retail's
   extra ignored arguments to the one-parameter routines. */
// FUN_002E72C0
s32 func_002e72c0(u8 *arg0)
{
    void fieldSceneLoad(s32 arg0, s32 arg1);
    s32 func_00122520(s32 arg0, s32 arg1);
    s32 func_00122640(s32 arg0, s32 arg1);
    s32 func_00122720(void);
    s32 fieldSceneLoadStep(void);
    void fieldSceneUnload(void);
    s32 MT_Scene_GetCameraResFirst(void);
    f32 MT_Scene_GetCameraFov(void);
    s32 func_0015f660(void);
    s32 func_0033be40(u8 *arg0);
    u8 *func_003e9cb0(u8 *arg0, ...);
    s32 kwlnTaskGetTaskByName(s8 *arg0);
    u8 *func_00457120(void);
    void K_View_SetFov(void *arg0, f32 arg1);
    s32 sdkSndPlayCue(s16 arg0, ...);
    extern s8 D_0063FC68[];
    s8 state;
    u8 *work;
    u8 *view;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s8 *)work;
    switch (state) {
    case 1:
        fieldSceneLoad(8, 6);
        *(s8 *)work = 2;
        /* fallthrough */
    case 2:
        if ((fieldSceneLoadStep() != 0) && (func_0015f660() != 0)) {
            view = func_00457120();
            K_View_SetFov(view, MT_Scene_GetCameraFov());
            view = func_00457120();
            func_003e9cb0(*(u8 **)(view + 4), MT_Scene_GetCameraResFirst(), 0);
            *(s8 *)work = 3;
            sdkSndPlayCue((s16)0x15, 1);
        }
        goto block_24;
    case 3:
        func_00122640(1, 0);
        *(s8 *)work = 4;
        /* fallthrough */
    case 4:
        if (func_00122720() != 0) {
            if (*(s32 *)(work + 4) != 0) {
                *(s32 *)(work + 4) = 0;
            }
            *(s32 *)(work + 4) = func_0033be40(arg0);
            *(s8 *)work = 0x22;
        }
        goto block_24;
    case 5:
        func_00122520(1, 0);
        *(s8 *)work = 6;
        /* fallthrough */
    case 6:
        if (func_00122720() != 0) {
            fieldSceneUnload();
            *(s8 *)work = 0x23;
        }
        goto block_24;
    case 34:
        if (kwlnTaskGetTaskByName(D_0063FC68) == 0) {
            fieldSceneUnload();
            *(s8 *)work = 0x23;
        }
        goto block_24;
    case 35:
        return -1;
    default:
block_24:
        return 0;
    }
}
// FUN_002E74E0
void func_002e74e0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002E7510
s32 func_002e7510(s32 arg0)
{
    s32 result;
    u8 *work;
    s32 i;

    chkmemAllocSiteTag(D_0063FC80, 0x11A);
    work = D_008873F4[0](1, 0x18, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)((void *)(arg0)), (const void *)((char *)D_0063FC90), 0xF, 0, 0, func_002e72c0, func_002e74e0, (u8 *)(work));
    iGpffffb590 = NULL;
    iGpffffb590 = (u8 *)func_002b5c90(result, func_002b2970(0, 0));
    func_002b5db0(iGpffffb590, func_002b2970(0, 0), func_002b29e0(640.0f, 448.0f));
    func_002b5e30(iGpffffb590, func_002b2a60(0, 0, 0, 0xFF));
    *work = 1;
    sdkSndFadeOutChannelFrames(3, 0, 0x1E);

    for (i = 0; i < 0x2FF; i++) {
        if (((func_00106b20((s16)i) & 0xFFF00) >> 8) == 0 &&
            ((func_00106b50((s16)i) & 0xFFF00) >> 8) == 0) {
            func_00110810(i, (clndGetMoonPhase(i) & 0xFF) | 4);
        } else if ((func_00106b20((s16)i) & 0xFF) == 0 &&
                   (func_00106b50((s16)i) & 0xFF) == 0) {
            func_00110810(i, (clndGetMoonPhase(i) & 0xFF) | 4);
        }
    }
    for (i = 0x300; i < 0x3FF; i++) {
        if ((func_002be100((u8)func_00106ac0((s16)i)) & 0xFF) <
            (func_002be100(4) & 0xFF)) {
            func_00110810(i, (clndGetMoonPhase(i) & 0xFF) | 4);
        } else if ((func_002be100((u8)func_00106ac0((s16)i)) & 0xFF) ==
                   (func_002be100(4) & 0xFF) &&
                   (s8)func_00106af0((s16)i) < 2) {
            func_00110810(i, (clndGetMoonPhase(i) & 0xFF) | 4);
        }
    }
    return result;
}
// FUN_002E78A0
u8 func_002e78a0(void)
{
    s32 sp1C;
    s32 sp18;

    calSplitDayOfYear(datGetDateIndex(), &sp18, &sp1C);
    return sp18;
}



/* Retail returns the low day byte with lbu, defining the full result. */
// FUN_002E78E0
s32 func_002e78e0(void)
{
    s32 sp1C;
    s32 sp18;

    calSplitDayOfYear(datGetDateIndex(), &sp18, &sp1C);
    return (u8)sp1C;
}



// FUN_002E7920
void func_002e7920(s32 *arg0, s32 *arg1)
{
    s32 calGetMonthLength(s32 arg0);
    s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
    s32 *out0;
    u8 count;
    s32 *out1;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;

    out0 = arg0;
    count = 0;
    out1 = arg1;

    calSplitDayOfYear(datGetDateIndex(), (s32 *)&sp60, (s32 *)&sp64);
    count = *(u8 *)&sp64;
    calSplitDayOfYear(datGetDateIndex(), (s32 *)&sp68, (s32 *)&sp6C);
    if (calGetMonthLength(*(u8 *)&sp68) < (count + 1)) {
        calSplitDayOfYear(datGetDateIndex(), &sp58, &sp5C);
        *out0 = func_002b2cb0(*(u8 *)&sp58, 1, 0xC, 1, 2);
        *out1 = 1;
        return;
    }
    calSplitDayOfYear(datGetDateIndex(), &sp50, &sp54);
    *out0 = *(u8 *)&sp50;
    calSplitDayOfYear(datGetDateIndex(), &sp48, &sp4C);
    *out1 = *(u8 *)&sp4C + 1;
}
// FUN_002E7A60
u32 func_002e7a60(void)
{
    return datGetMoney();
}

// FUN_002E7A80
void func_002e7a80(s32 arg0)
{
    datSetMoney(func_002b2cb0(arg0, 0, 0x98967F, 0, 1));
}

#define P4_002E7AC0_DRAW() \
    do { \
        if ((s16)fclSpriteFlagBit(*(s16 *)(fclSpriteEntry(105) + 0x10), 0) == 1) { \
            frFontExDrawTextDeferredOutB(*(f32 *)(fclSpriteEntry(105) + 0x38) + 52.0f, 41.0f, 88.0f, \
                          func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF), 0, 1, \
                          (const char *)func_0010d6d0(1), 0, 0, D_00794E70, 24); \
        } \
    } while (0)
// Fcl combine menu update: runs the menu state machine (draws the text and returns a status).
// FUN_002E7AC0
s32 fclCombineMenuUpdate(u8 *arg0)
{
    void fclCombineMenuRoot(u8 *arg0);
    u8 *fclSpriteEntry(s16 arg0);
    s16 fclSpriteFlagBit(s16 arg0, s16 arg1);
    s32 func_002b2a30(u8, u8, u8, u8);
    u32 func_0010d6d0(s16 arg0);
    
    void fclDrawSetFlag(u8 *arg0, s8 arg1);
    void fclCombineMenuFusion(u8 *arg0);
    void fclCombineMenuFusionTriple(u8 *arg0);
    void fclCombineMenuMaterialPick(u8 *arg0);
    void fclCombineMenuPreview(u8 *arg0);
    void fclCombineMenuPriceInfo(u8 *arg0);
    void fclCombineMenuDetailPanels(u8 *arg0);
    void fclCombineMenuRosterFusion(u8 *arg0);
    void fclCombineMenuResult(u8 *arg0);
    void fclCombineMenuMaterialGrid(u8 *arg0);
    void fclCombineMenuOptionPick(u8 *arg0);
    void fclCombineMenuResultGrowth(u8 *arg0);
    void fclCombineMenuFinish(u8 *arg0);
    extern u8 D_00794E70[];
    u8 *work;
    u8 state;

    work = *(u8 **)(arg0 + 0x38);
    state = *(u8 *)work;
    if (state == 0xD8) {
        goto done;
    }
    if (state == 0x0B) {
        goto return_minus_one;
    }
    if (state == 0x0E) {
        goto case_0e;
    }
    if (state == 0x0D) {
        goto case_0d;
    }
    if (state == 0x0A) {
        goto case_0a;
    }
    if (state == 0x09) {
        goto case_09;
    }
    if (state == 0x0C) {
        goto case_0c;
    }
    if (state == 0x10) {
        goto case_10;
    }
    if (state == 0x0F) {
        goto case_10;
    }
    if (state == 0x08) {
        goto case_08;
    }
    if (state == 0x07) {
        goto case_07;
    }
    if (state == 0x06) {
        goto case_06;
    }
    if (state == 0x05) {
        goto case_05;
    }
    if (state == 0x04) {
        goto case_04;
    }
    if (state == 0x03) {
        goto case_03;
    }
    if (state == 0x02) {
        goto case_02;
    }
    if (state == 0x01) {
        goto case_01;
    }
    switch (state) {
    case 0:
        fclCombineMenuRoot(arg0);
        break;
    default:
        break;
    }
    goto done;

case_01:
    P4_002E7AC0_DRAW();
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    *(s8 *)(work + 0x1A) = 2;
    fclCombineMenuFusion(arg0);
    goto done;
case_02:
    P4_002E7AC0_DRAW();
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    *(s8 *)(work + 0x1A) = 3;
    fclCombineMenuFusionTriple(arg0);
    goto done;
case_03:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 4;
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    fclCombineMenuMaterialPick(arg0);
    goto done;
case_04:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 5;
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    fclCombineMenuMaterialPick(arg0);
    goto done;
case_05:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 6;
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    fclCombineMenuMaterialPick(arg0);
    goto done;
case_06:
    P4_002E7AC0_DRAW();
    *(s8 *)(work + 0x1A) = 7;
    fclDrawSetFlag(*(u8 **)(work + 0x148), 0);
    fclCombineMenuPreview(arg0);
    goto done;
case_07:
    fclCombineMenuDetailPanels(arg0);
    goto done;
case_08:
    P4_002E7AC0_DRAW();
    fclCombineMenuRosterFusion(arg0);
    goto done;
case_10:
    fclDrawSetFlag(*(u8 **)(work + 0x148), 1);
    fclCombineMenuPriceInfo(arg0);
    goto done;
case_0c:
    fclCombineMenuResultGrowth(arg0);
    goto done;
case_09:
    fclCombineMenuMaterialGrid(arg0);
    goto done;
case_0a:
    fclCombineMenuOptionPick(arg0);
    goto done;
case_0d:
    fclCombineMenuResult(arg0);
    goto done;
case_0e:
    fclCombineMenuFinish(arg0);
    goto done;
return_minus_one:
    return -1;
done:
    return 0;
}
#undef P4_002E7AC0_DRAW
// Fcl combine menu destroy: releases the slot entries and the slot draw tasks.
// FUN_002E82B0
void fclCombineMenuDestroy(u8 *arg0)
{
    s32 datPersonaRosterCapacity(void);
    s8 yListSlotRelease(s8 arg0);
    s32 kwlnTaskDestroyWithHierarchy(struct KwlnTask *arg0);
    s16 i;
    s64 j;
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    i = 0;
    while (i < 15) {
        yListSlotRelease((s8)i);
        i++;
    }
    i = 0;
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(work + ((s16)j * 4) + 0x154) != 0) {
        kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(work + ((s16)j * 4) + 0x154));
    }
    i++;
loop_7_test:
    j = (s16)i;
    if ((s16)j < (u16)datPersonaRosterCapacity()) {
        goto loop_7_body;
    }
    i = 0;
    while (i < 2) {
        if (*(s32 *)(work + (i * 4) + 0x184) != 0) {
            kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(work + (i * 4) + 0x184));
        }
        i++;
    }
    if (*(s32 *)(work + 0x24C) != 0) {
        kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(work + 0x24C));
    }
    if (*(s32 *)(work + 0x250) != 0) {
        kwlnTaskDestroyWithHierarchy(*(struct KwlnTask **)(work + 0x250));
    }
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
