#include "message_window_internal.h"
#include "shd_sprite_pack.h"
/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/itfMsgProcedure_Window.c); members 0027bec0-0027bf30 */

#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_snd_internal.h"
extern s32 D_0063BF80[];
extern s32 itfMesWindowProcedureForKind(s32 kind);
extern s16 datGetDateIndex(void);
extern void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut);
#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Allow drawing unless bit 19 gates the window during its transition phase (bits 8-9). */
// FUN_0027BEC0
s32 itfMsgWindowCanDraw(s32 handle)
{
    s32 flags;

    flags = itfMesWindowGetFlags(handle);
    if (!(flags & 0x80000) || ((flags & 0x300) < 0x100)) {
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
// Intent: Returns the window procedure registered for a kind [inferred]
// FUN_0027BF10
s32 itfMesWindowProcedureForKind(s32 kind)
{
    return D_0063BF80[kind];
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* The renderer receives a color snapshot and a rectangle value. The
 * rectangle literal retains its own temporary; clear cursors and counts
 * have separate lifetimes. Native b210: 2992/2992 bytes, no differences.
 * Evidence: build/first-party-finish-20260929/worker5/func_0027bf30. */
// Intent: Draws the calendar screen: month and day text, tile backdrop and sky render states (msgCal resources) [inferred]
// FUN_0027BF30
void calDrawScreen(u8 *unusedTask, MsgProcWindowEntry *entry)
{
    typedef struct {
        s32 x;
        s32 y;
        s32 w;
        s32 h;
    } CalendarRectangle;
    typedef union { u8 rgba[4]; f32 value; } CalendarColor;
    extern s32 msgCalResourceGet(s32 index);
    extern f32 sinf(f32);
    extern void PrimDrawFlatRectangle(u8 *colorData, f32 *rectangleData, f32 depth, s32 preserveState);
    extern u8 *resourceFindByName(char *name);
    extern s32 (*D_00887300[])(s32 state, void *value);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern s32 sdkSpriteDrawNow(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void *pack, s32 setStates, s16 pivotX, s16 pivotY, f32 angle, f32 scaleX, f32 scaleY);
    extern void kAssertFail(void *file, s32 line);
    extern s32 calGetWeekdayOfDay(s32 dateIndex);
    extern s32 calHasDayEntry(s32 day);
    extern s32 calGetPackedDayEntry(s32 day, s32 referenceDay);
    extern void calDrawDateCell(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 enabled, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite);
    extern void calDrawWeather(s32 x, s32 y, f32 depth, u8 opacity, s32 weather, s32 highlight, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipWidth, s32 font, s32 forcedHighlight);
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
    ShdSpritePack *handle;

    switch (entry->kind) {
    case 4:
        handle = (ShdSpritePack *)msgCalResourceGet(0);
        if (handle == NULL) {
            break;
        }
        t = sinf(1.5707964f * (f32)entry->elapsed / 20.0f);
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
        phase = entry->elapsed % 4;
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
        frame = (f32)entry->elapsed + entry->frameOffset;
        if ((f32)frame > 120.0f) {
            frame = (f32)frame - 120.0f;
        }
        rot = (f32)frame / 120.0f;
        if (handle == NULL) {
            kAssertFail(D_007482F0, 0x59);
        }
        sdkSpriteDrawNow(-59.0f, -103.0f, 10.0f, 0xFFFFFF, 255.0f * fade, 2, handle->sprites[0], 1, 0x80, 0x80, 360.0f * rot, 1.0f, 1.0f);
        frame = entry->elapsed;
        if (frame < 4) {
            fade = sinf(1.5707964f * (f32)frame / 4.0f);
            if (handle == NULL) {
                kAssertFail(D_007482F0, 0x59);
            }
            rot = 1.0f - fade;
            sdkSpriteDrawNow(165.0f, 244.0f + 95.0f * fade, 0.0f, 0, 0xCC, 1, handle->sprites[0], 1, 0, 0, 0.0f, 1.0f, rot);
            sflDataDrawNarrowRoundedFrame(0xB0, 271 + 64.0f * fade, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f, 0.3f + 0.3f * rot);
        } else if (frame < 11) {
            t = (f32)(frame - 4) / 6.0f;
            sflDataDrawNarrowRoundedFrame(176.0f * (1.0f - t), 0x14F, 0.0f, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 1.0f + t, 0.3f - 0.2f * t);
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

            if (entry->elapsed >= appear[i]) {
                step = entry->elapsed - appear[i];
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
                sdkSpriteDrawNow(i * 0x53 + 0x4B, 69.0f, 0.0f, rgb, 255.0f * fade, month + 4, handle->sprites[0], 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
            rot = 1.0f - fade;
            t = 64.0f * rot;
            py = 113.0f + t;
            px = i * 0x53;
            sflDataDrawNarrowRoundedFrame(px + 0x5C, py, 0.0f, 0x50, 0x7F, rgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, fade);
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
        frame = entry->elapsed;
        if (frame >= 2) {
            if (frame < 0) {
                t = sinf(1.5707964f * (f32)(frame - 1) / 4.0f);
                sflDataDrawNarrowRoundedFrame(0x12C, 145.0f + 24.0f * t, 0.0f, 0x50, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 0.5f - 0.2f * t);
            } else if (frame < 8) {
                t = (f32)(frame - 2) / 5.0f;
                sflDataDrawNarrowRoundedFrame(300.0f * (1.0f - t), 0xA9, 0.0f, 80.0f + 640.0f * t, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 0.3f - 0.2f * t);
            }
        }
        break;
    }
}
#pragma pop
