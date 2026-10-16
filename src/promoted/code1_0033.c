#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "shd_misc_internal.h"
#include "fcl_combine_internal.h"
extern void (*jtbl_008873EC[])(void *);

// P4 retail reaches the battle-data object pointer at gp-0x4A68,
// i.e. absolute 0x007690f0 - 0x4a68 = 0x00764688, GP-relative.
extern int iGpffffb598;
extern u16 D_008C024E[];
extern s32 scrGetParamInt(s32 arg0);
extern s32 datGetFlag(s32 arg0);
extern void datSetFlag(s32 arg0, s32 arg1);
extern u32 fclGetMoney(void);



extern void sdkSpriteRelease(void *ptr);

typedef FclVec2 F2_0033;

/* Same four byte channels as the color constructor's output. */
typedef FclDrawColor Color_0033;

typedef struct {
    s32 sp30;
    s16 sp34;
    s16 pad36;
    s32 sp38;
    s32 sp3c;
} D9D0Locals;

extern void fclClearMoonFlagEntries(void);
extern void fclCombineApplyPackedResult(void);
extern void (*D_00887300[])(s32, s32);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void fclSpriteStartPosition(u8 *arg0, F2_0033 arg1, F2_0033 arg2,
                           u32 arg3, s32 arg4, s32 arg5);

extern void kwlnSetColorRgba(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
extern s8 iGpffffb59c;
extern u8 *kwlnTaskGetTaskByName(s8 *arg0);
extern s32 mtSceneResListPrepareAll(void);
extern void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
extern void calendarSetMode(s32 arg0);
extern u8 D_00644E80[];
extern u8 D_00644E98[];
extern u8 D_00644EB0[];
extern void chkmemAllocSiteTag(const void *arg0, s32 arg1);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern s32 sdkSpriteRequestLoad(void *arg0);
extern u8 D_0064A458[];
extern u8 D_0064A470[];
extern u8 D_0064A480[];
extern s32 fclBustupUpdate(u8 *arg0);
extern void func_0033e4b0(u8 *arg0);
extern s32 fclPackRgba(u8, u8, u8, u8);
extern f32 fclEaseInterpolate(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 fclAddClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s16 fclSubClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s32 func_0046a750(s32 arg0, s32 arg1);
extern s32 func_002859e0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00293ed0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00293fc0(s32 arg0);
extern s32 func_002940a0(s32 arg0, s32 *arg1, s32 *arg2,
                         s16 *arg3, s32 *arg4);
extern void fieldSceneLoad(s32 arg0, s32 arg1);
extern void func_00144e10(s32 arg0);
extern void func_00144ed0(s32 arg0);
extern s32 fieldSceneLoadStep(void);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern s32 kwlnTaskIsLinked(s32 arg0);
extern u8 *kwlnGetCamera(void);
extern void K_View_SetFov(u8 *arg0, f32 arg1);
extern f32 MT_Scene_GetCameraFov(void);
extern s32 MT_Scene_GetCameraResFirst(void);
extern void func_003e9cb0(s32 arg0, s32 arg1, s32 arg2);
extern s32 fadeStatus(void);
extern s32 fclCombineEventGateCreate(u8 *arg0, s32 arg1);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 D_007955C0[];
extern void PrimQueueBatchAlpha(void *, void *, f32, s32, s32, s32, s16, s16,
                         f32, f32, f32, void *);
extern u8 D_00794A80[];
extern u8 D_00794AB0[];
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s32 func_002be100(u8 arg0);
extern u16 cmmCommunityRecordValue(s32 arg0);
extern s8 nmMesWindowAcquire(void *arg0);
extern s32 nmMesWindowShowSlotRecord(s8 arg0, s32 arg1);
extern s32 func_00106600(s16 arg0);
extern s32 nmMesWindowSlotStatus(s8 arg0);
extern void nmMesWindowStepSlotRelease(s32 arg0);
extern void nmMesWindowDestroySlot(s8 arg0);
extern void wshopMaterialTalkCreate(u8 *arg0);
extern u8 D_00644ED0[];
extern u8 D_00645090[];
extern u8 D_00645240[];
extern u8 D_0064A000[];

// FUN_00331560
s32 func_00331560(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 4);
}

// FUN_00331580
s32 func_00331580(void)
{
    return *(s8 *)(*(int *)(iGpffffb598 + 0x38)) == 6;
}
// FUN_003315A0
void func_003315a0(void)
{
    *(s8 *)(*(int *)(iGpffffb598 + 0x38) + 0x45) = 1;
}

// FUN_003315C0
s32 func_003315c0(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 0x24);
}

// FUN_003315E0
s32 func_003315e0(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 0x28);
}

// FUN_00331600
s32 func_00331600(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 0x2C);
}

// FUN_00331620
s32 *func_00331620(void)
{
    return *(s32 **)(*(int *)(iGpffffb598 + 0x38) + 0x30);
}

// FUN_00331640
s8 func_00331640(void)
{
    return *(s8 *)(*(int *)(iGpffffb598 + 0x38) + 0x44);
}

// FUN_00331660
s32 func_00331660(void)
{
    return *(s32 *)(*(int *)(*(int *)(iGpffffb598 + 0x38) + 0x20) + 0x110);
}

// FUN_00331680
s32 func_00331680(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            func_001029a0(0x16, 0, 0, 2);
            calendarSetMode(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        iGpffffb59c += 1;
        break;
    case 6:
        if (kwlnTaskGetTaskByName((s8 *)D_00644E80) == 0) {
            calendarSetMode(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00331770
s32 func_00331770(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            func_001029a0(0x17, 0, 0, 2);
            calendarSetMode(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        iGpffffb59c += 1;
        break;
    case 6:
        if (kwlnTaskGetTaskByName((s8 *)D_00644E98) == 0) {
            calendarSetMode(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00331860
s32 func_00331860(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (mtSceneResListPrepareAll() != 0) {
            kwlnSetColorRgba(0, 0, 0, 0xFF);
            func_001029a0(0x18, 0, 0, 2);
            calendarSetMode(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        iGpffffb59c += 1;
        break;
    case 6:
        if (kwlnTaskGetTaskByName((s8 *)D_00644EB0) == 0) {
            calendarSetMode(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00331980
s32 func_00331980(void)
{
    return datGetFlag(scrGetParamInt(0)) != 0;
}
// FUN_003319C0
s32 func_003319c0(void) {
    s32 r;

    if ((D_008C024E[0] & 0x800) != 0) {
        datSetFlag(scrGetParamInt(0), 1);
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

#pragma push
/* measured: byte-exact (347/347 instructions, 0 differing words).  The level
   is compared directly as `level_value` in both scans; opt_loop_invariants
   hoists its sign extension out of the first scan into the register retail
   uses, which is what fixes the old $s2/$s3 exchange between `work` and the
   extended level.  Measured: 45 words comparing directly without the pragma;
   24 with a separate `s32 level` copy, with or without it. */
#pragma opt_loop_invariants on
// FUN_00331A20
s32 weaponShopTalkUpdate(u8 *arg0)
{
    s8 *work;
    s8 i;
    s8 j;
    s16 level_value;
    s16 min;
    s16 max;
    u8 *entry;
    u8 *e;

    work = *(s8 **)(arg0 + 0x38);
    level_value = (s16)(100 * (func_002be100(fclCalendarMonth()) & 0xFF) + (fclCalendarDay() & 0xFF));
    switch (*work) {
    case 0:
        if (datGetFlag(0x1C0) == 0) {
            work[1] = nmMesWindowAcquire(D_00645240);
            nmMesWindowShowSlotRecord(work[1], 0);
            (*work)++;
            datSetFlag(0x1C0, 1);
            return 0;
        }
        if ((cmmCommunityRecordValue(0x13) & 0xFFFF) == 6 || (cmmCommunityRecordValue(0x13) & 0xFFFF) == 7) {
            e = D_00645090 + ((cmmCommunityRecordValue(0x13) & 0xFFFF) - 6) * 0x10;
            if (datGetFlag(*(s32 *)(e + 12)) != 0 || *(s32 *)(e + 12) == 0) {
                work[1] = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)e);
                func_00106620(*(s16 *)(e + 2), ((func_00106600(*(s16 *)(e + 2)) & 0xFF) + 1) & 0xFF);
                datSetFlag(*(s32 *)(e + 4), 1);
                datSetFlag(*(s32 *)(e + 8), 0);
                (*work)++;
                return 0;
            }
        }
        i = 0;
        do {
            entry = D_00644ED0 + (i * 0x10);
            min = (s16)(entry[9] + 100 * (func_002be100(entry[8]) & 0xFF));
            max = (s16)(entry[11] + 100 * (func_002be100(entry[10]) & 0xFF));
            if (*(s16 *)entry != -1 && datGetFlag(*(s32 *)(entry + 12)) == 0 &&
                (datGetFlag(*(s32 *)(entry + 4)) != 0 || *(s32 *)(entry + 4) == 0) && !(min > level_value) &&
                !(max < level_value)) {
                work[1] = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)entry);
                datSetFlag(*(s32 *)(entry + 12), 1);
                (*work)++;
                return 0;
            }
            i++;
        } while (*(s16 *)entry != -1);
        if (datGetFlag(0x1324) != 0) {
            *work = 2;
            wshopMaterialTalkCreate(arg0);
            return 0;
        }
        j = 0;
        do {
            entry = D_00644ED0 + (j * 0x10);
            min = (s16)(entry[9] + 100 * (func_002be100(entry[8]) & 0xFF));
            max = (s16)(entry[11] + 100 * (func_002be100(entry[10]) & 0xFF));
            if (*(s16 *)entry != -1 && (datGetFlag(*(s32 *)(entry + 4)) != 0 || *(s32 *)(entry + 4) == 0) &&
                !(min > level_value) && !(max < level_value)) {
                work[1] = nmMesWindowAcquire(D_00645240);
                nmMesWindowShowSlotRecord(work[1], *(s16 *)entry);
                (*work)++;
                return 0;
            }
            j++;
        } while (*(s16 *)entry != -1);
        return -1;
    case 1:
        if (nmMesWindowSlotStatus(work[1]) != 0) {
            nmMesWindowStepSlotRelease(work[1]);
            break;
        }
        nmMesWindowDestroySlot(work[1]);
        return -1;
    case 2:
        if (kwlnTaskGetTaskByName((s8 *)D_0064A000) == 0) {
            return -1;
        }
        break;
    }
    return 0;
}
#pragma pop
// FUN_00331F90
void weaponShopTalkDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00332A80
void func_00332a80(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x7100D);
}
// FUN_00332B60
void func_00332b60(u8 *arg0, u8 *arg1)
{
    shdDrawNumberText(*(Vec2f *)(arg1 + 0x1E0), 1.0f, 0xFF, fclGetMoney());
}

// Identical to fclObjectGetWork (code1_002e.c).
// FUN_0033D310
u8 *fclBustupObjGetWork(u8 *arg0)
{
    return *(u8 **)(arg0 + 0x38);
}

// Identical to fclObjChangeFlagBit (code1_002e.c).
// FUN_0033D320
void fclBustupObjChangeFlagBit(u8 *arg0, s32 arg1, s8 arg2) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (arg2 == 0) {
        *(s16 *)(p + 4) |= (s16)((1 << arg1) & 0xFFFF);
    } else if (arg2 == 1) {
        *(s16 *)(p + 4) &= (s16)((1 << arg1) ^ 0xFFFF);
    }
}

// Identical to fclObjTestFlagBit (code1_002e.c).
// FUN_0033D390
s32 fclBustupObjTestFlagBit(u8 *arg0, s32 arg1)
{
    return (*(s16 *)(*(u8 **)(arg0 + 0x38) + 4) & ((1 << arg1) & 0xFFFF)) >> arg1;
}
// FUN_0033D3C0
void func_0033d3c0(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 8) = arg1;
}
// FUN_0033D3D0
void func_0033d3d0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xFC) = arg1;
}

// Identical to fclObjStartPosition (code1_002e.c).
// FUN_0033D3E0
void fclBustupObjStartPosition(u8 *arg0, F2_0033 p1, F2_0033 p2,
                   u32 arg3, u32 arg4, s16 arg5)
{
    fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4, p1, p2, arg3, arg4, arg5);
}
// FUN_0033D420
void func_0033d420(u8 *arg0, F2_0033 p1, F2_0033 p2,
                   u32 arg3, s8 arg4, u32 arg5, s16 arg6)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    fclSpriteStartPosition(p + 4, p1, p2, arg3, arg5, arg6);
    *(s8 *)(p + 0x3B) = arg4;
    *(s16 *)(*(u8 **)(arg0 + 0x38) + 4) |= 0x400;
    *(s16 *)(*(u8 **)(arg0 + 0x38) + 4) &= (s16)~2;
}
// Identical to fclObjStartAlpha (code1_002e.c).
// FUN_0033D4B0
void fclBustupObjStartAlpha(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, s64 arg5)
{
    fclSpriteStartAlpha(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, (s16)arg5);
}

// FUN_0033D4E0
void func_0033d4e0(u8 *arg0, f32 fparg0, f32 fparg1, u32 arg1, u32 arg2, s64 arg3)
{
    fclSpriteStartRevealScale(*(u8 **)(arg0 + 0x38) + 4, fparg0, fparg1, fparg0, fparg1, arg1, arg2, (s16)arg3);
}
// Identical to fclObjStartTween (code1_002e.c).
// FUN_0033D520
void func_0033d520(u8 *arg0, f32 fparg0, f32 fparg1, u8 arg1, s32 arg2, s64 arg3)
{
    fclSpriteStartTween(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, fparg0, fparg1);
}

// FUN_0033D550
/* measured: opt_propagation off preserves the per-call field loads and the
   argument materialisation order for fclSpriteStartRevealScale. */
#pragma opt_propagation off
void func_0033d550(u8 *arg0)
{
    s16 h;
    u8 b1;
    u8 b2;
    f32 f0;
    f32 f1;
    u8 *p;

    *(s16 *)(*(u8 **)(arg0 + 0x38) + 4) |= 1;

    fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4,
                  *(F2_0033 *)(*(u8 **)(arg0 + 0x38) + 0x2C),
                  *(F2_0033 *)(*(u8 **)(arg0 + 0x38) + 0x1C),
                  0,
                  *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x36),
                  0);

    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x5E);
    p = *(u8 **)(arg0 + 0x38) + 4;
    b1 = *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x62);
    b2 = *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x60);
    fclSpriteStartAlpha(p, b1, b2, 0, h, 0);

    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0xC8);
    p = *(u8 **)(arg0 + 0x38) + 4;
    f0 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0xC4);
    f1 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0xBC);
    fclSpriteStartTween(p, 0, h, 0, f0, f1);

    f1 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x8C);
    f0 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x94);
    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x88);
    p = *(u8 **)(arg0 + 0x38) + 4;
    fclSpriteStartRevealScale(p, f0, f1, f0, f1, 0, h, 0);
}
/* measured: restore opt_propagation for the rest of the translation unit. */
#pragma opt_propagation on
/*
 * measured: 924/928 bytes, eight resolved relocations, four zero alignment bytes.
 * The point-anchor dependency rebuilds both passes without retaining x + 4.
 * Keep the input-Y snapshot and the real color/point object lifetimes.
 */
// FUN_0033D630
f32 func_0033d630(F2_0033 pos, s16 angleStep, f32 angleOffset, u8 alpha, s8 highlight)
{
    Color_0033 baseColor;
    Color_0033 highlightColor;
    F2_0033 points[5];
    Color_0033 colors[5];
    f32 rotation;
    f32 originX;
    f32 originY;
    f32 result;
    f32 inputY = pos.y;

    rotation = (f32)-(s16)angleStep - angleOffset;

    originX = 113.0f + pos.x;
    points[0].x = points[4].x = originX;

    originY = 113.0f + inputY;
    points[0].y = points[4].y = originY;

    points[1].x = 4.0f + points[0].x;
    points[1].y = 338.0f;

    points[2].x = 26.0f + points[1].x;
    points[2].y = -400.0f;

    points[3].x = originX - 26.0f;
    points[3].y = -400.0f;

    baseColor = fclMakeDrawColor(0x7E, 0, 8, alpha);
    colors[0] = colors[1] = colors[2] = colors[3] = colors[4] = baseColor;

    PrimQueueBatchAlpha(colors, points, 70.0f, 5, 4, 1, 0, 0, rotation, 1.0f, 1.0f, D_00794AB0);

    if ((s8)highlight == 1) {
        points[0].x = points[4].x = originX;
        points[0].y = points[4].y = originY;

        points[1].x = 4.0f + points[0].x;
        points[1].y = 338.0f;

        points[2].x = 7.0f + (26.0f + points[1].x);
        points[2].y = -400.0f;

        points[3].x = (originX - 26.0f) - 7.0f;
        points[3].y = -400.0f;

        highlightColor = fclMakeDrawColor(0xFF, 0xFF, 0xFF, alpha);
        colors[0] = colors[1] = colors[2] = colors[3] = colors[4] = highlightColor;

        PrimQueueBatchAlpha(colors, points, 69.0f, 5, 4, 1, 0, 0, 5.0f + rotation, 1.0f, 1.0f, D_00794A80);
    }

    result = (f32)angleStep + angleOffset;
    if (result >= 360.0f) {
        result -= 360.0f;
    }
    return result;
}
// FUN_0033D9D0
 s32 fclCombineEventTaskUpdate(u8 *arg0)
 {
     D9D0Locals locals;
     s32 taskHandle;
     s8 state;
     u8 *work;
     u8 *view;
     u8 *viewRec;

     work = *(u8 **)(arg0 + 0x38);
     state = *(s8 *)work;
     switch (state) {
     case 0:
         *(s32 *)(work + 4) = func_00293ed0(
             0x5A, *(s8 *)(work + 0x10) + 1, 0, 0);
         *(s8 *)work = *(s8 *)work + 1;
     default:
         goto out;
     case 1:
         if ((func_00293fc0(*(s32 *)(work + 4)) != 0) &&
             (func_002940a0(*(s32 *)(work + 4), &locals.sp3c,
                            &locals.sp38, &locals.sp34, &locals.sp30) == 1)) {
             fieldSceneLoad(locals.sp3c, locals.sp38);
             func_00144e10(locals.sp34);
             func_00144ed0(3);
             *(s8 *)work = *(s8 *)work + 1;
         }
         goto out;
     case 2:
         if (fieldSceneLoadStep() != 0) {
             *(s32 *)(work + 8) = func_002859e0(
                 0x5A, *(s8 *)(work + 0x10) + 1, 0);
             *(s32 *)(work + 0xC) = fclCombineEventGateCreate(arg0, 0x58);
             *(s8 *)work = *(s8 *)work + 1;
         }
         goto out;
     case 3:
         if (kwlnTaskIsLinked(*(s32 *)(work + 8)) != 1) {
             taskHandle = *(s32 *)(work + 4);
             if (taskHandle != 0) {
                 kwlnTaskDestroyWithHierarchy(taskHandle);
             }
             *(s8 *)work = *(s8 *)work + 1;
         }
         goto out;
     case 4:
     case 5:
         *(s8 *)work = (s8)(state + 1);
         goto out;
     case 6:
         fieldSceneLoad(8, 3);
         func_00144e10(1);
         *(s8 *)work = *(s8 *)work + 1;
         goto out;
     case 7:
         if (fieldSceneLoadStep() == 0) {
             goto out;
         }
         if (mtSceneResListPrepareAll() == 0) {
             goto out;
         }
         view = kwlnGetCamera();
         K_View_SetFov(view, MT_Scene_GetCameraFov());
         viewRec = kwlnGetCamera();
         func_003e9cb0(*(s32 *)(viewRec + 4), MT_Scene_GetCameraResFirst(), 0);
         func_00122640(1, 0xA);
         *(s8 *)work = *(s8 *)work + 1;
     case 8:
         if (fadeStatus() != 0) {
             return -1;
         }
         goto out;
     out:
         return 0;
     }
 }
// FUN_0033DC60
void fclCombineEventTaskDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0033E1E0
s32 fclBustupUpdate(u8 *arg0)
{
    u8 *p;
    s16 value;

    p = *(u8 **)(arg0 + 0x38);
    switch (*(s8 *)p) {
    case 0:
        if (func_0046a750(*(s32 *)(p + 4), 3) == 0) {
            return 0;
        }
        *(s8 *)p = 1;
        break;
    case 1:
        break;
    default:
        break;
    case 2:
        if (*(s16 *)(p + 0x24) > *(s16 *)(p + 0x26)) {
            goto update;
        }
        *(s8 *)p = 3;
        if (*(f32 *)(p + 0x1C) >= 640.0f) {
            *(s8 *)p = 1;
            return 0;
        }
    update:
        *(f32 *)(p + 0x1C) = fclEaseInterpolate(
            *(s8 *)(p + 0x2A), *(f32 *)(p + 0x0C), *(f32 *)(p + 0x14),
            (f32)*(s16 *)(p + 0x26), (f32)*(s16 *)(p + 0x24));
        *(f32 *)(p + 0x20) = fclEaseInterpolate(
            *(s8 *)(p + 0x2A), *(f32 *)(p + 0x10), *(f32 *)(p + 0x18),
            (f32)*(s16 *)(p + 0x26), (f32)*(s16 *)(p + 0x24));
        value = *(s16 *)(p + 0x28);
        if (value > 0) {
            *(s16 *)(p + 0x28) = fclSubClamped(value, 1, 0, 0, 1);
        } else {
            *(s16 *)(p + 0x26) = fclAddClamped(
                *(s16 *)(p + 0x26), 1, *(s16 *)(p + 0x24), 0, 1);
        }
        func_0033e4b0(arg0);
        break;
    case 3:
        func_0033e4b0(arg0);
        break;
    }
    return 0;
}
// FUN_0033E3A0
void fclBustupDestroy(u8 *arg0)
{
    sdkSpriteRelease((void *)*(u8 **)(*(u8 **)(arg0 + 0x38) + 4));
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0033E3F0
s32 func_0033e3f0(u8 *arg0)
{
    s32 result;
    u8 *work;

    chkmemAllocSiteTag(D_0064A458, 0x85);
    work = D_008873F4[0](1, 0x2C, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0064A470), 0xF, 0, 0, fclBustupUpdate, fclBustupDestroy, (u8 *)(work));
    work[0] = 0;
    *(s32 *)(work + 4) = sdkSpriteRequestLoad(D_0064A480);
    return result;
}
// FUN_0033E4B0
void func_0033e4b0(u8 *arg0)
{
    u8 *work;
    s32 color;
    f32 x;
    f32 y;

    work = *(u8 **)(arg0 + 0x38);
    color = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
    x = *(f32 *)(work + 0x1C);
    y = *(f32 *)(work + 0x20);
    sdkSpriteDrawQueued(x, y, 104.0f, color, 0xFF, 1, *(void **)(work + 4),
                  1, 0, 0, 0.0f, 1.0f, 1.0f, D_007955C0);
}
// FUN_0033E540
void func_0033e540(u8 *arg0, F2_0033 arg1, F2_0033 arg2, s16 arg3, s16 arg4)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(F2_0033 *)(work + 0x1C) = arg1;
    *(F2_0033 *)(work + 0x0C) = *(F2_0033 *)(work + 0x1C);
    *(F2_0033 *)(work + 0x14) = arg2;
    *(s16 *)(work + 0x24) = arg3;
    *(s16 *)(work + 0x26) = 0;
    *(s16 *)(work + 0x28) = arg4;
    *(s8 *)work = 2;
}
// FUN_0033E5A0
s32 func_0033e5a0(u8 *arg0)
{
    return *(s8 *)(*(u8 **)(arg0 + 0x38)) != 0;
}
