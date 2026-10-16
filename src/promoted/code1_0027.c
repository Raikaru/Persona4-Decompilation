#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];

extern void poolFree(s32 arg0);
extern void itfMesListSetColor();
extern void itfMesListSetRangeFlag();

extern s32 frFontGetMode(void);
extern void func_002e0f20(void);
extern void frFontUpdateTextWork(u8 *arg0);
extern void frFontLayoutText(u8 *arg0, u8 *arg1);

extern s32 D_008815B0[];

extern void memset(void *arg0, s32 arg1, s32 arg2);
extern void MT_Scene_SetResMotionSlot(u32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
extern s32 itfMesWindowProcedureForKind(s32 arg0);
extern s32 cmmCommunityFindActiveSlotInGroup(s64 arg0);
extern u8 *cmmSlotNameRecord(s32 arg0);
extern s32 cmmCommunityGetCurrentId(void);
extern u8 *cmmNameRecord(s32 arg0);
static inline u32 add_retail_ptr(u32 offset, u32 base) {
    return offset + base;
}
extern s32 MT_Scene_CheckResSlot(u32 resourceId, u32 value);
extern s32 calGetDayWindowFlags(s32 arg0);
extern s64 func_002e0da0(s64 arg0, s32 arg1, s64 arg2);
extern void func_002e0f90(void);

extern u16 D_008817E8[];
extern u8 *frFontRasterFindEntry();
extern u8 *frFontRasterAllocEntry();
extern void itfMesFlushPendingCallback(s32 arg0);
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern u8 *D_008817EC[];
extern void itfMesWindowStepState(u8 *arg0);
extern void itfMesWindowAdvanceRow(u8 *arg0);
extern void itfMesWindowCommitSelection(u8 *arg0);
extern void itfMesWindowStepTransition(u8 *arg0);
extern void itfMesWindowQueueCallback(s32 arg0);
extern s32 func_0027bd40(s32 arg0);
extern s32 func_0027bda0(s32 arg0);
extern s32 func_0027be00(s32 arg0);
extern s16 datGetDateIndex(void);
extern void calSplitDayOfYear(s32 date, s32 *month, s32 *day);
extern s32 sprintf(void *arg0, const void *arg1, s32 arg2);
extern u8 iGpffffa738;
extern s32 calGetWeekOfYear(s32 arg0);
extern void frFontExCopyString(void *arg0, void *arg1, s32 arg2);
extern s8 D_0063BAB0[];
extern s32 cmmCommunityGetCurrentId(void);
extern void itfMesWindowFree(s32 arg0);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(u8 *arg0, u8 *arg1);




#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_rebuildconditionals off
#pragma opt_rebuildconditionals on



#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on




// FUN_002746C0
void func_002746c0(s32 arg0, s32 arg1)
{
    D_008815B0[arg0] = arg1;
}












#pragma opt_loop_invariants on
/* measured: opt_loop_invariants off */
#pragma opt_loop_invariants off


// FUN_0027B7C0
s32 func_0027b7c0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    *(s32 *)(itfMesWindowGetSubTable(arg0) + 0x14) = 0;
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0);
    }
    return 1;
}
// The itfMes op wrappers below stay unnamed: each sends one op number, and op meanings differ across window kinds (see ItfMesWindowOp).
// FUN_0027B830
s32 func_0027b830(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(arg0);
    *(s32 *)(base + 0x14) = 1;
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 1);
    }
    return 1;
}
// FUN_0027B8A0
s32 func_0027b8a0(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(arg0);
    *(s32 *)(base + 0x14) = 2;
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 2);
    }
    return 1;
}
// FUN_0027B910
s32 func_0027b910(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)itfMesWindowGetSubTable(arg0);
    *(s32 *)(base + 0x14) = 3;
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 3);
    }
    return 1;
}
// FUN_0027B980
s32 func_0027b980(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 4);
    }
    return 1;
}
// FUN_0027B9E0
s32 func_0027b9e0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 5);
    }
    return 1;
}
// FUN_0027BA40
s32 func_0027ba40(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 6);
    }
    return 1;
}
// FUN_0027BAA0
s32 func_0027baa0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 7);
    }
    return 1;
}
// Intent: Sends window op 8, which places the window's body and text lists for list node arg0 [inferred]
// FUN_0027BB00
s32 itfMesWindowSendLayoutLists(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, ITF_MES_WINDOW_OP_LAYOUT_LISTS);
    }
    return 1;
}
// FUN_0027BB60
s32 func_0027bb60(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 9);
    }
    return 1;
}
// FUN_0027BBC0
s32 func_0027bbc0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xA);
    }
    return 1;
}
// FUN_0027BC20
s32 func_0027bc20(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xB);
    }
    return 1;
}
// FUN_0027BC80
s32 func_0027bc80(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xC);
    }
    return 1;
}
// FUN_0027BCE0
s32 func_0027bce0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xD);
    }
    return 1;
}
// FUN_0027BD40
s32 func_0027bd40(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x10);
    }
    return 1;
}
// FUN_0027BDA0
s32 func_0027bda0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x11);
    }
    return 1;
}
// FUN_0027BE00
s32 func_0027be00(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    itfMesWindowGetSubTable(arg0);
    temp_2 = *(s32 (**)(s32, s32))itfMesWindowGetSubTable(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x12);
    }
    return 1;
}
// FUN_0027BEC0
s32 func_0027bec0(s32 handle)
{
    s32 temp_2;

    temp_2 = itfMesWindowGetFlags(handle);
    if (!(temp_2 & 0x80000) || ((temp_2 & 0x300) < 0x100)) {
        return 1;
    }
    return 0;
}
// Intent: Returns the window procedure registered for a kind [inferred]
// FUN_0027BF10
s32 itfMesWindowProcedureForKind(s32 arg0)
{
    return D_0063BF80[arg0];
}
/* The renderer receives a color snapshot and a rectangle value. The
 * rectangle literal retains its own temporary; clear cursors and counts
 * have separate lifetimes. Native b210: 2992/2992 bytes, no differences.
 * Evidence: build/first-party-finish-20260929/worker5/func_0027bf30. */
// Intent: Draws the calendar screen: month and day text, tile backdrop and sky render states (msgCal resources) [inferred]
// FUN_0027BF30
void calDrawScreen(u8 *unusedTask, u8 *arg1)
{
    typedef struct {
        s32 x;
        s32 y;
        s32 w;
        s32 h;
    } CalendarRectangle;
    typedef union { u8 rgba[4]; f32 value; } CalendarColor;
    extern s32 msgCalResourceGet(s32 arg0);
    extern f32 sinf(f32 arg0);
    extern void PrimDrawFlatRectangle(u8 *arg0, f32 *arg1, f32 fparg0, s32 arg2);
    extern u8 *resourceFindByName(char *arg0);
    extern s32 (*D_00887300[])(s32 state, void *value);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void *arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
    extern void kAssertFail(void *arg0, s32 arg1);
    extern s32 calGetWeekdayOfDay(s32 arg0);
    extern s32 calHasDayEntry(s32 arg0);
    extern s32 calGetPackedDayEntry(s32 arg0, s32 arg1);
    extern void calDrawDateCell(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 enabled, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite);
    extern void calDrawWeather(s32 arg0, s32 arg1, f32 fparg0, u8 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0);
    extern char D_0063BFB0[];
    extern u8 D_007482F0[];
    s32 month;
    s32 day;
    CalendarColor depthColor;
    CalendarColor color;
    CalendarRectangle rect;
    s32 appear[6];
    f32 alpha;
    f32 x;
    f32 y;
    f32 rot;
    f32 fade;
    f32 t;
    u8 *font;
    s32 py;
    s32 mode;
    s32 date;
    s32 px;
    s32 today;
    s32 tile;
    s32 rgb;
    s32 week;
    s32 phase;
    s32 frame;
    s32 i;
    s32 (**table)(s32, void *);
    s32 lineRgb;
    u8 *handle;

    switch (*(s32 *)(arg1 + 4)) {
    case 4:
        handle = (u8 *)msgCalResourceGet(0);
        if (handle == NULL) {
            break;
        }
        t = sinf(1.5707964f * (f32)*(s32 *)(arg1 + 0x10) / 20.0f);
        {
            u8 *colorCursor;
            s32 colorRemaining;
            colorCursor = color.rgba;
            colorRemaining = 4;
            if (colorCursor != NULL) {
                do {
                    *colorCursor = 0;
                    colorCursor++;
                    colorRemaining--;
                } while (colorRemaining != 0);
            }
        }
        fade = 1.0f - t;
        alpha = 76.5f * fade;
        color.rgba[3] = alpha;
        depthColor = color;
        {
            rect = (CalendarRectangle){0, 0, 640, 480};

            PrimDrawFlatRectangle((u8 *)&depthColor, (f32 *)&rect, 10.0f, 1);
        }
        phase = *(s32 *)(arg1 + 0x10) % 4;
        table = (s32 (**)(s32, void *))(u32)D_00887300;
        table[0](6, (void *)1);
        table[0](8, (void *)1);
        RpSkyRenderStateSet(3, (void *)0x7000D);
        RpSkyRenderStateSet(2, (void *)0x48);
        for (tile = 0; tile < 24; tile++) {
            x = (tile % 6) * 126;
            y = (tile / 6) * 126;
            sdkSpriteDrawNow(x, y, 10.0f, 0xFFFFFF, alpha, phase, resourceFindByName(D_0063BFB0), 0, 0, 0, 0.0f, 1.0f, 1.0f);
            phase = (phase + 1) % 4;
        }
        frame = (f32)*(s32 *)(arg1 + 0x10) + *(f32 *)(arg1 + 8);
        if ((f32)frame > 120.0f) {
            frame = (f32)frame - 120.0f;
        }
        rot = (f32)frame / 120.0f;
        if (handle == NULL) {
            kAssertFail(D_007482F0, 0x59);
        }
        sdkSpriteDrawNow(-59.0f, -103.0f, 10.0f, 0xFFFFFF, 255.0f * fade, 2, **(void ***)(handle + 8), 1, 0x80, 0x80, 360.0f * rot, 1.0f, 1.0f);
        frame = *(s32 *)(arg1 + 0x10);
        if (frame < 4) {
            fade = sinf(1.5707964f * (f32)frame / 4.0f);
            if (handle == NULL) {
                kAssertFail(D_007482F0, 0x59);
            }
            rot = 1.0f - fade;
            sdkSpriteDrawNow(165.0f, 244.0f + 95.0f * fade, 0.0f, 0, 0xCC, 1, **(void ***)(handle + 8), 1, 0, 0, 0.0f, 1.0f, rot);
            func_00366380(0xB0, 271 + 64.0f * fade, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, 0.3f + 0.3f * rot);
        } else if (frame < 11) {
            t = (f32)(frame - 4) / 6.0f;
            func_00366380(176.0f * (1.0f - t), 0x14F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f + t, 0.3f - 0.2f * t);
        }
        font = (u8 *)msgCalResourceGet(1);
        {
            u8 *appearCursor;
            s32 appearRemaining;
            appearCursor = (u8 *)appear;
            appearRemaining = sizeof(appear);
            if (appearCursor != NULL) {
                do {
                    *appearCursor = 0;
                    appearCursor++;
                    appearRemaining--;
                } while (appearRemaining != 0);
            }
        }
        today = (s16)datGetDateIndex();
        for (i = 0; i < 6; i++) {
            s32 step;

            if (*(s32 *)(arg1 + 0x10) >= appear[i]) {
                step = *(s32 *)(arg1 + 0x10) - appear[i];
                if (step >= 5) {
                    step = 5;
                }
            } else {
                step = 0;
            }
            fade = 1.0f - sinf(1.5707964f * (f32)step / 5.0f);
            date = today + i + 1;
            week = calGetWeekdayOfDay(date);
            if (week == 0 || calHasDayEntry(date) != 0) {
                rgb = 0xFFE92C;
                mode = 3;
            } else if (week == 6) {
                rgb = 0xFFE92C;
                mode = 2;
            } else {
                rgb = 0xFFE92C;
                mode = 1;
            }
            calSplitDayOfYear(date, &month, &day);
            if (day == 1) {
                if (handle == NULL) {
                    kAssertFail(D_007482F0, 0x59);
                }
                sdkSpriteDrawNow(i * 0x53 + 0x4B, 69.0f, 0.0f, rgb, 255.0f * fade, month + 4, **(void ***)(handle + 8), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
            rot = 1.0f - fade;
            t = 64.0f * rot;
            py = 113.0f + t;
            px = i * 0x53;
            func_00366380(px + 0x5C, py, 0.0f, 0x50, 0x7F, rgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, fade);
            calDrawDateCell(px + 0x6B, py, 0.0f, 0xFF, today + i + 1, 1, 1.0f, fade, 0, 0, (s32)font, 0);
            py = 163.0f - 5.0f * rot;
            calDrawWeather(px + 0x5D, py, 0.0f, 0xFF, calGetPackedDayEntry(today + i + 1, today) & 0xFFFF, 1, 1.0f, fade * fade, 0, 0, (s32)font, mode);
        }
        week = calGetWeekdayOfDay(today + 3);
        if (week == 0 || calHasDayEntry(today + 3) != 0) {
            lineRgb = 0xFFE92C;
        } else if (week == 6) {
            lineRgb = 0xFFE92C;
        } else {
            lineRgb = 0xFFE92C;
        }
        frame = *(s32 *)(arg1 + 0x10);
        if (frame >= 2) {
            if (frame < 0) {
                t = sinf(1.5707964f * (f32)(frame - 1) / 4.0f);
                func_00366380(0x12C, 145.0f + 24.0f * t, 0.0f, 0x50, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 0.5f - 0.2f * t);
            } else if (frame < 8) {
                t = (f32)(frame - 2) / 5.0f;
                func_00366380(300.0f * (1.0f - t), 0xA9, 0.0f, 80.0f + 640.0f * t, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 0.3f - 0.2f * t);
            }
        }
        break;
    }
}
