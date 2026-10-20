/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00260510-00264d10 */

#include "include_asm.h"
#include "member_access.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "primitive_queue_internal.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern s32 datGetFlag(s32 );
extern void qsort(u32 *, s32 , s32 ,
                           s32 (*)(u8 **, u8 **));
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u32 state;
    union { s32 word; u8 *pointer; } spritePack;
    s32 queue;
    s32 fromDay;
    s32 toDay;
    s32 childTask;
    s32 day;
    s32 scroll;
    s32 frame;
} CalendarDayChange;

typedef struct CalendarGlyphContext {
    s16 offsetX, offsetY;
    f32 depthOffset, scaleX, scaleY;
    u8 *font;
} CalendarGlyphContext;

typedef struct SdlSchedulerWork {
    u8 pad00[8];
    s32 flags;
} SdlSchedulerWork;

extern char iGpffffa6c4;
extern s32 (*D_00887300[])(RwRenderState state, void *value);
typedef struct { s32 a, b, c, d; } Quad4;

typedef void (*CalendarGlyphCallback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);

extern u8 *kwlnTaskGetWork();
extern s32 kwlnTaskIsLinked();
extern s32 sdkSpritePackCreate(u8 *);
extern u8 D_00637420[];
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(u8 *, u8 *);
extern void sdkSpritePackDestroy(void *);
extern void (*jtbl_008873EC[])(void *);
extern void calSplitDayOfYear(s32 , s32 *, s32 *);
extern s32 shdSpriteEnsureLoaded(u8 *);
extern char D_00637348[];
extern s32 kwlnTaskGetTaskByName(void *);
extern void kwlnTaskDestroyWithHierarchy(s32 );
extern void calDrawDayStripCallback(s32 , u8 *);
extern s32 cldDayChangeStartStateTask(s32 , s32 , s32 );
extern s32 cldDayChangeRequest(u32 , s32 );
extern void cldDayChangeMarkDone(u8 *);
extern s32 cldDayChangeIsDone(s32 );
extern void datSetFlag(s32 , s32 );
extern void calQueueDayStripDraw(s32 , s32 );
extern s32 calGetPackedDayEntry(s32 , s32 );
extern s32 func_0043c6a0(s32 );
extern f32 sinf(f32 );
extern void calDrawDateCell(s32 , s32 , f32 , u8 , s32 , s32 , f32 , f32 , s32 , s32 , s32 , s32 );
extern void calDrawWeather(s32 , s32 , f32 , u8 ,
                           s32 , s32 , f32 , f32 ,
                           s32 , s32 , s32 ,
                           s32 );
extern s32 sprintf(char *dst, const char *fmt, ...);
extern s32 calGetWeekdayOfDay(s32 );
extern s32 calHasDayEntry(s32 );
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void mdlEffectEmitMaskedTagPair(void);
extern void PrimDrawFlatRectangle(void *, void *, f32 , s32 );
extern void mdlEffectEmitTagPair(void);
extern s32 shdSpriteEntryWidth(s32 , s32 , u8 *);
extern void shdSpriteDrawUniformNumber(f32, f32, f32, s32, u8, const char *, s32, s16, s16, CalendarGlyphCallback, u8 *);
// Intent: Sets the enable flag on the sdlScheduler task when it exists [inferred]
// FUN_00260510
void sdlSchedulerEnable(void)
{
    s32 task;
    u8 *work;

    task = kwlnTaskGetTaskByName(D_00637348);
    if (task != 0) {
        work = kwlnTaskGetWork(task);
        ((SdlSchedulerWork *)work)->flags |= 1;
    }
}

// Intent: Destroys the sdlScheduler task when it exists [inferred]
// FUN_00260560
void sdlSchedulerDestroy(void)
{
    s32 task;

    task = kwlnTaskGetTaskByName(D_00637348);
    if (task != 0) {
        kwlnTaskDestroyWithHierarchy(task);
    }
}

// Intent: Draws one character of a day number as a glyph (callback for the shdSpriteDrawUniformNumber text drawer; skips newline codes) [inferred]
// FUN_002605A0
void calDrawDayNumberGlyph(f32 x, f32 y, f32 depth, s32 color, u8 alpha, s8 * text, s32 index, s32 length, u8 * context)
{
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    s8 character;

    character = text[index];
    if (character != 0xA) {
        shdSpriteDrawNowEx(x, y, depth, color, alpha, 0, character, ((CalendarGlyphContext *)context)->font, 1, ((CalendarGlyphContext *)context)->offsetX, ((CalendarGlyphContext *)context)->offsetY, ((CalendarGlyphContext *)context)->depthOffset, ((CalendarGlyphContext *)context)->scaleX, ((CalendarGlyphContext *)context)->scaleY);
    }
}

typedef struct { u32 w[48]; } CalendarTrailTable;

// Intent: Draws a highlight trail around a weather icon in one of three layouts (variant 0/1/2) [inferred]
// FUN_00260600
/* measured: baseline differs by 1432 bytes; retaining lifetimes leaves 1420, explicit float origins leave 1605. */
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
void calDrawHighlightTrail(s32 x, s32 y, f32 depth, s32 color, u8 alpha, s32 variant, f32 scaleX, f32 scaleY, s32 font, s32 setupStates)
{
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, u32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    extern f32 cosf(f32);
    extern f32 sinf(f32);
    extern u8 D_00637440[];
    extern u8 D_00637500[];
    extern f32 fGpffff811c;
    extern f32 iGpffff81d0;
    extern f32 D_007612C4;
    f32 smallTrail[12][4];
    f32 wideTrail[12][4];
    s32 biasA;
    f32 cosS;
    s32 biasB;
    f32 halfThird;
    f32 halfFiveThird;
    u32 i;
    f32 entry3;
    f32 angle;
    f32 entry2;
    f32 sinS;
    f32 fx;
    f32 fy;
    *(CalendarTrailTable *)smallTrail = *(CalendarTrailTable *)D_00637440;
    *(CalendarTrailTable *)wideTrail = *(CalendarTrailTable *)D_00637500;
    switch (variant) {
    case 0:
        biasA = (int)((float)x - 14.0f * scaleX);
        biasB = (int)((float)y - 16.0f * scaleY);
        i = 0;
        halfThird = 0.5f * scaleY;
        halfFiveThird = 0.5f * (5.0f * scaleY);
        for (; i < 0xC; i++) {
            f32 *p = smallTrail[i];

            entry2 = p[2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosS = 18.0f * cosf(angle);
            sinS = 18.0f * -sinf(angle);
            fx = cosS + (47.0f + p[0]);
            fy = sinS + (52.0f + p[1]);
            entry3 = p[3];
            shdSpriteDrawNowEx((float)biasA + fx * scaleX, (float)biasB + fy * scaleY, depth, color, alpha, 0x13, 0, (u8 *)font, setupStates,
                          (s16)(int)(0.5f * (scaleX * (22.0f * entry3))), (s16)halfFiveThird,
                          entry2 - 180.0f, 0.5f * (scaleX * entry3), halfThird);
        }
        shdSpriteDrawNowEx((float)biasA + 34.0f * scaleX, (float)biasB + 36.0f * scaleY, depth, color, alpha, 5, 0, (u8 *)font, setupStates, 0, 0, 0.0f, scaleX, scaleY);
        break;
    case 1:
        biasA = (int)((float)x - 41.0f * scaleX);
        biasB = (int)((float)y - 29.0f * scaleY);
        i = 0;
        halfThird = fGpffff811c * scaleY;
        halfFiveThird = fGpffff811c * (5.0f * scaleY);
        for (; i < 0xC; i++) {
            f32 *p = wideTrail[i];

            entry2 = p[2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosS = 13.0f * cosf(angle);
            sinS = 13.0f * -sinf(angle);
            fx = cosS + (57.0f + p[0]);
            fy = sinS + (48.0f + p[1]);
            entry3 = p[3];
            shdSpriteDrawNowEx((float)biasA + fx * scaleX, (float)biasB + fy * scaleY, depth, color, alpha, 0x13, 0, (u8 *)font, setupStates,
                          (s16)(int)(0.5f * (scaleX * (22.0f * entry3))), (s16)halfFiveThird,
                          entry2 - 180.0f, 0.5f * (scaleX * entry3), halfThird);
        }
        fx = (float)biasA + 52.0f * scaleX;
        fy = (float)biasB + 38.0f * scaleY;
        shdSpriteDrawNowEx(fx, fy, depth, color, alpha, 5, 0, (u8 *)font, setupStates, 0, 0, 0.0f, D_007612C4 * scaleX, D_007612C4 * scaleY);
        break;
    case 2:
        biasA = (int)((float)x - 12.0f * scaleX);
        biasB = (int)((float)y + scaleY);
        i = 0;
        halfThird = fGpffff811c * scaleY;
        halfFiveThird = fGpffff811c * (5.0f * scaleY);
        for (; i < 0xC; i++) {
            f32 *p = wideTrail[i];

            entry2 = p[2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosS = 13.0f * cosf(angle);
            sinS = 13.0f * -sinf(angle);
            fx = cosS + (57.0f + p[0]);
            fy = sinS + (48.0f + p[1]);
            entry3 = p[3];
            shdSpriteDrawNowEx((float)biasA + fx * scaleX, (float)biasB + fy * scaleY, depth, color, alpha, 0x13, 0, (u8 *)font, setupStates,
                          (s16)(int)(0.5f * (scaleX * (22.0f * entry3))), (s16)halfFiveThird,
                          entry2 - 180.0f, 0.5f * (scaleX * entry3), halfThird);
        }
        fx = (float)biasA + 52.0f * scaleX;
        fy = (float)biasB + 38.0f * scaleY;
        shdSpriteDrawNowEx(fx, fy, depth, color, alpha, 5, 0, (u8 *)font, setupStates, 0, 0, 0.0f, D_007612C4 * scaleX, D_007612C4 * scaleY);
        break;
    }
}
#pragma pop

extern f32 D_007612C4;
typedef struct {
    s32 x, y;
} CalendarSparkle;

typedef struct {
    CalendarSparkle offset[30];
} CalendarSparkleTable;

extern CalendarSparkle D_006375C0[30];
extern void calDrawHighlightTrail(s32 x, s32 y, f32 depth, s32 color, u8 alpha, s32 variant, f32 scaleX, f32 scaleY, s32 font, s32 );
// Intent: Draws the weather highlight (sparkle table, colour by highlight kind) for a calendar cell [inferred]
// FUN_00260E60
/* measured: baseline and direct render-state table calls both differ by 1307 bytes. */
#pragma push
#pragma opt_propagation off
void calDrawWeatherHighlight(s32 x, s32 y, f32 depth, u8 alpha, s32 kind, s32 variant, s32 highlight, f32 scaleX, f32 scaleY, s32 font, s32 setupStates)
{
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    CalendarSparkleTable sparkle;
    CalendarSparkle *spot;
    s32 (**states)(RwRenderState state, void *value);
    s32 color;
    f32 posX;
    f32 posY;
    u32 i;

    color = 0x919191;
    switch (highlight) {
    case 1:
        color = 0xFFF000;
        break;
    case 2:
        color = 0x52BDFF;
        break;
    case 3:
        color = 0xFF296B;
        break;
    }
    if (setupStates != 0) {
        states = D_00887300;
        states[0]((RwRenderState)(20), (void *)(1));
        states[0]((RwRenderState)(6), (void *)(1));
        states[0]((RwRenderState)(7), (void *)(2));
        states[0]((RwRenderState)(8), (void *)(1));
        states[0]((RwRenderState)(9), (void *)(2));
        states[0]((RwRenderState)(12), (void *)(1));
        states[0]((RwRenderState)(2), (void *)(4));
        states[0]((RwRenderState)(14), (void *)(0));
        RpSkyRenderStateSet(3, (void *)(0x7000D));
        RpSkyRenderStateSet(2, (void *)(0x44));
    }
    switch (kind) {
    case 0:
        if (highlight != 0) {
            color = 0xFF9000;
        }
        switch (variant) {
        case 0:
            calDrawHighlightTrail(x, y, depth, color, alpha, variant, scaleX, scaleY, font, 0);
            break;
        case 1:
            calDrawHighlightTrail(x, y, depth, color, alpha, variant, scaleX, scaleY, font, 0);
            break;
        case 2:
            calDrawHighlightTrail(x, y, depth, color, alpha, variant, scaleX, scaleY, font, 0);
            break;
        }
        break;
    case 1:
        if (highlight != 0) {
            color = 0x4C85EF;
        }
        switch (variant) {
        case 0:
            shdSpriteDrawNowEx((f32)x, (f32)y, depth, color, alpha, 8, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            break;
        case 1:
            posX = ((f32)x + 0.0f) - 3.0f * scaleX;
            posY = (f32)(y - 4);
            shdSpriteDrawNowEx(posX, posY, depth, color, alpha, 7, 0, (u8 *)font, 0, 0, 0, 0.0f, 0.707f * scaleX, 0.707f * scaleY);
            break;
        case 2:
            posX = ((f32)x + 0.0f) + 23.0f * scaleX;
            posY = (f32)(y + 27);
            shdSpriteDrawNowEx(posX, posY, depth, color, alpha, 7, 0, (u8 *)font, 0, 0, 0, 0.0f, 0.707f * scaleX, 0.707f * scaleY);
            break;
        }
        break;
    case 2:
        if (highlight != 0) {
            color = 0x949494;
        }
        switch (variant) {
        case 0:
            shdSpriteDrawNowEx((f32)x, (f32)y, depth, color, alpha, 6, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            break;
        case 1:
            shdSpriteDrawNowEx((f32)x, (f32)y, depth, color, alpha, 6, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            break;
        case 2:
            shdSpriteDrawNowEx((f32)(x - 5), (f32)(y + 25), depth, color, alpha, 6, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            break;
        }
        break;
    case 3:
        break;
    case 4:
        if (highlight != 0) {
            color = 0xFFFFFF;
        }
        switch (variant) {
        case 0:
            sparkle = *(CalendarSparkleTable *)D_006375C0;
            shdSpriteDrawNowEx((f32)x, (f32)y, depth, color, alpha, 10, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            for (i = 0; i < 30; i++) {
                spot = &sparkle.offset[i];
                shdSpriteDrawNowEx((f32)(x - 10 + spot->x), (f32)(y - 12 + spot->y), depth, color, alpha, 9, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            }
            break;
        case 1:
            break;
        case 2:
            break;
        }
        break;
    }
}
#pragma pop

/* Render the current weather and its transition using complete clip/color records. */
// Intent: Renders the weather icon for a calendar day, cross-fading old and new weather during a transition [inferred]
// FUN_00261560
#pragma push
#pragma opt_lifetimes on
void calDrawWeather(s32 x, s32 y, f32 depth, u8 opacity, s32 weather, s32 highlight, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipWidth, s32 font, s32 forcedHighlight)
{
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    typedef signed __int128 s128;
    typedef union {
        struct { s32 x, y, width, height; } fields;
        s128 packet;
    } WeatherClip;
    typedef struct { u8 red, green, blue, alpha; } WeatherColor;
    extern s128 D_00637430;
    extern s32 (*D_00887300[])(RwRenderState state, void *value);
    u8 *renderStates;
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void PrimDrawFlatRectangle(void *, void *, f32, s32);
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    WeatherColor sameBackdropColor;
    WeatherColor sameBackdropColorScratch;
    WeatherColor sameViewportColor;
    WeatherColor sameViewportColorScratch;
    WeatherColor sameOverlayColor;
    WeatherColor sameOverlayColorScratch;
    WeatherColor sameFinishColor;
    WeatherColor sameFinishColorScratch;
    WeatherColor currentBackdropColor;
    WeatherColor currentBackdropColorScratch;
    WeatherColor currentViewportColor;
    WeatherColor currentViewportColorScratch;
    WeatherColor currentOverlayColor;
    WeatherColor currentOverlayColorScratch;
    WeatherColor currentFinishColor;
    WeatherColor currentFinishColorScratch;
    WeatherColor previousBackdropColor;
    WeatherColor previousBackdropColorScratch;
    WeatherColor previousViewportColor;
    WeatherColor previousViewportColorScratch;
    WeatherColor previousOverlayColor;
    WeatherColor previousOverlayColorScratch;
    WeatherColor previousFinishColor;
    WeatherColor previousFinishColorScratch;
    WeatherClip sameBackdropBounds;
    WeatherClip sameBackdropBoundsScratch;
    WeatherClip sameViewportBounds;
    WeatherClip sameViewportBoundsScratch;
    WeatherClip sameOverlayBounds;
    WeatherClip sameOverlayBoundsScratch;
    WeatherClip sameFinishBounds;
    WeatherClip sameFinishBoundsScratch;
    WeatherClip currentBackdropBounds;
    WeatherClip currentBackdropBoundsScratch;
    WeatherClip currentViewportBounds;
    WeatherClip currentViewportBoundsScratch;
    WeatherClip currentOverlayBounds;
    WeatherClip currentOverlayBoundsScratch;
    WeatherClip currentFinishBounds;
    WeatherClip currentFinishBoundsScratch;
    WeatherClip previousBackdropBounds;
    WeatherClip previousBackdropBoundsScratch;
    WeatherClip previousViewportBounds;
    WeatherClip previousViewportBoundsScratch;
    WeatherClip previousOverlayBounds;
    WeatherClip previousOverlayBoundsScratch;
    WeatherClip previousFinishBounds;
    WeatherClip previousFinishBoundsScratch;
    s32 fallbackHighlight;
    s32 oldWeather;
    u8 *cursor;
    s32 previousWeather;
    s32 currentWeather;
    s32 backgroundColor;
    s32 remaining;

    fallbackHighlight = highlight;
    backgroundColor = 0x242424;
    if (highlight != 0) {
        backgroundColor = 0;
    }
    currentWeather = weather & 0xF;
    previousWeather = weather >> 4;
    oldWeather = previousWeather;
    if (previousWeather == currentWeather) {
        x = (s32)((float)x + 47.0f * (1.0f - scaleX));
        cursor = (u8 *)(&sameBackdropColorScratch);
        remaining = 4;
        if (cursor != NULL) {
            do {
                *cursor = 0;
                cursor += 1;
            } while (--remaining != 0);
        }
        sameBackdropColor = sameBackdropColorScratch;
        sameBackdropBoundsScratch.packet = D_00637430;
        sameBackdropBoundsScratch.fields.x = x - 0x40;
        sameBackdropBoundsScratch.fields.y = y - 0x40;
        sameBackdropBounds = sameBackdropBoundsScratch;
        renderStates = (u8 *)D_00887300;
        (*(void (**)(u32, u32))renderStates)(0xE, 0);
        (*(void (**)(u32, u32))renderStates)(0xC, 1);
        (*(void (**)(u32, u32))renderStates)(7, 2);
        (*(void (**)(u32, u32))renderStates)(9, 1);
        (*(void (**)(u32, u32))renderStates)(0x14, 1);
        (*(void (**)(u32, u32))renderStates)(6, 0);
        (*(void (**)(u32, u32))renderStates)(8, 1);
        RpSkyRenderStateSet(3, (void *)(0x71003));
        RpSkyRenderStateSet(2, (void *)(0x44));
        mdlEffectEmitMaskedTagPair();
        PrimDrawFlatRectangle(&sameBackdropColor, &sameBackdropBounds, 10.0f, 0);
        mdlEffectEmitTagPair();
        cursor = (u8 *)(&sameViewportColorScratch);
        remaining = 4;
        if (cursor != NULL) {
            do {
                *cursor = 0;
                cursor += 1;
            } while (--remaining != 0);
        }
        sameViewportColor = sameViewportColorScratch;
        cursor = (u8 *)(&sameViewportBoundsScratch);
        remaining = 0x10;
        if (cursor != NULL) {
            do {
                *cursor = 0;
                cursor += 1;
            } while (--remaining != 0);
        }
        sameViewportBoundsScratch.fields.x = clipLeft;
        sameViewportBoundsScratch.fields.y = 0;
        sameViewportBoundsScratch.fields.width = clipWidth;
        sameViewportBoundsScratch.fields.height = 0x1E0;
        sameViewportBounds = sameViewportBoundsScratch;
        (*(void (**)(u32, u32))renderStates)(0xE, 0);
        (*(void (**)(u32, u32))renderStates)(0xC, 1);
        (*(void (**)(u32, u32))renderStates)(7, 2);
        (*(void (**)(u32, u32))renderStates)(9, 1);
        (*(void (**)(u32, u32))renderStates)(0x14, 1);
        (*(void (**)(u32, u32))renderStates)(6, 0);
        (*(void (**)(u32, u32))renderStates)(8, 1);
        RpSkyRenderStateSet(3, (void *)(0x31003));
        RpSkyRenderStateSet(2, (void *)(0x44));
        mdlEffectEmitMaskedTagPair();
        PrimDrawFlatRectangle(&sameViewportColor, &sameViewportBounds, 1.0f, 0);
        mdlEffectEmitTagPair();
        (*(void (**)(u32, u32))renderStates)(6, 1);
        (*(void (**)(u32, u32))renderStates)(7, 2);
        RpSkyRenderStateSet(3, (void *)(0x7000D));
        shdSpriteDrawNowEx((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 3, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        shdSpriteDrawNowEx((f32)x + (9.0f * scaleX), (f32) (y + 4), 10.0f, backgroundColor, opacity, 0xD, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        if (!(scaleX < 1.0f)) {
            shdSpriteDrawNowEx(((float)x + 70.0f * scaleX), (f32) y, 10.0f, backgroundColor, opacity, 0xE, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        } else {
            shdSpriteDrawNowEx(((float)x + 69.0f * scaleX), (f32) y, 10.0f, backgroundColor, opacity, 0xE, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        }
        cursor = (u8 *)(&sameOverlayColorScratch);
        remaining = 4;
        if (cursor != NULL) {
            do {
                *cursor = 0;
                cursor += 1;
            } while (--remaining != 0);
        }
        sameOverlayColor = sameOverlayColorScratch;
        sameOverlayBoundsScratch.packet = D_00637430;
        sameOverlayBoundsScratch.fields.x = x - 0x40;
        sameOverlayBoundsScratch.fields.y = y - 0x40;
        sameOverlayBounds = sameOverlayBoundsScratch;
        renderStates = (u8 *)D_00887300;
        (*(void (**)(u32, u32))renderStates)(0xE, 0);
        (*(void (**)(u32, u32))renderStates)(0xC, 1);
        (*(void (**)(u32, u32))renderStates)(7, 2);
        (*(void (**)(u32, u32))renderStates)(9, 1);
        (*(void (**)(u32, u32))renderStates)(0x14, 1);
        (*(void (**)(u32, u32))renderStates)(6, 0);
        (*(void (**)(u32, u32))renderStates)(8, 1);
        RpSkyRenderStateSet(3, (void *)(0x71003));
        RpSkyRenderStateSet(2, (void *)(0x44));
        mdlEffectEmitMaskedTagPair();
        PrimDrawFlatRectangle(&sameOverlayColor, &sameOverlayBounds, 5.0f, 0);
        mdlEffectEmitTagPair();
        (*(void (**)(u32, u32))renderStates)(6, 0);
        (*(void (**)(u32, u32))renderStates)(7, 2);
        RpSkyRenderStateSet(3, (void *)(0x7000D));
        mdlEffectEmitMaskedTagPair();
        shdSpriteDrawNowEx((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 3, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        shdSpriteDrawNowEx((f32)x + (9.0f * scaleX), (f32) (y + 4), 10.0f, backgroundColor, opacity, 0xD, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        if (!(scaleX < 1.0f)) {
            shdSpriteDrawNowEx(((float)x + 70.0f * scaleX), (f32) y, 10.0f, backgroundColor, opacity, 0xE, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        } else {
            shdSpriteDrawNowEx(((float)x + 69.0f * scaleX), (f32) y, 10.0f, backgroundColor, opacity, 0xE, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        }
        mdlEffectEmitTagPair();
        cursor = (u8 *)(&sameFinishColorScratch);
        remaining = 4;
        if (cursor != NULL) {
            do {
                *cursor = 0;
                cursor += 1;
            } while (--remaining != 0);
        }
        sameFinishColor = sameFinishColorScratch;
        cursor = (u8 *)(&sameFinishBoundsScratch);
        remaining = 0x10;
        if (cursor != NULL) {
            do {
                *cursor = 0;
                cursor += 1;
            } while (--remaining != 0);
        }
        sameFinishBoundsScratch.fields.x = clipLeft;
        sameFinishBoundsScratch.fields.y = 0;
        sameFinishBoundsScratch.fields.width = clipWidth;
        sameFinishBoundsScratch.fields.height = 0x1E0;
        sameFinishBounds = sameFinishBoundsScratch;
        renderStates = (u8 *)D_00887300;
        (*(void (**)(u32, u32))renderStates)(0xE, 0);
        (*(void (**)(u32, u32))renderStates)(0xC, 1);
        (*(void (**)(u32, u32))renderStates)(7, 2);
        (*(void (**)(u32, u32))renderStates)(9, 1);
        (*(void (**)(u32, u32))renderStates)(0x14, 1);
        (*(void (**)(u32, u32))renderStates)(6, 0);
        (*(void (**)(u32, u32))renderStates)(8, 1);
        RpSkyRenderStateSet(3, (void *)(0x31003));
        RpSkyRenderStateSet(2, (void *)(0x44));
        mdlEffectEmitMaskedTagPair();
        PrimDrawFlatRectangle(&sameFinishColor, &sameFinishBounds, 1.0f, 0);
        mdlEffectEmitTagPair();
        if (forcedHighlight != 0) {
            calDrawWeatherHighlight(x, y, 10.0f, opacity, currentWeather, 0, forcedHighlight, scaleX, scaleY, font, 1);
            return;
        }
        calDrawWeatherHighlight(x, y, 10.0f, opacity, currentWeather, 0, fallbackHighlight, scaleX, scaleY, font, 1);
        return;
    }
    (void)depth;
    x = (s32)((float)x + 47.0f * (1.0f - scaleX));
    cursor = (u8 *)(&currentBackdropColorScratch);
    remaining = 4;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    currentBackdropColor = currentBackdropColorScratch;
    currentBackdropBoundsScratch.packet = D_00637430;
    currentBackdropBoundsScratch.fields.x = x - 0x40;
    currentBackdropBoundsScratch.fields.y = y - 0x40;
    currentBackdropBounds = currentBackdropBoundsScratch;
    renderStates = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderStates)(0xE, 0);
    (*(void (**)(u32, u32))renderStates)(0xC, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    (*(void (**)(u32, u32))renderStates)(9, 1);
    (*(void (**)(u32, u32))renderStates)(0x14, 1);
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(8, 1);
    RpSkyRenderStateSet(3, (void *)(0x71003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&currentBackdropColor, &currentBackdropBounds, 10.0f, 0);
    mdlEffectEmitTagPair();
    cursor = (u8 *)(&currentViewportColorScratch);
    remaining = 4;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    currentViewportColor = currentViewportColorScratch;
    cursor = (u8 *)(&currentViewportBoundsScratch);
    remaining = 0x10;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    currentViewportBoundsScratch.fields.x = clipLeft;
    currentViewportBoundsScratch.fields.y = 0;
    currentViewportBoundsScratch.fields.width = clipWidth;
    currentViewportBoundsScratch.fields.height = 0x1E0;
    currentViewportBounds = currentViewportBoundsScratch;
    (*(void (**)(u32, u32))renderStates)(0xE, 0);
    (*(void (**)(u32, u32))renderStates)(0xC, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    (*(void (**)(u32, u32))renderStates)(9, 1);
    (*(void (**)(u32, u32))renderStates)(0x14, 1);
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(8, 1);
    RpSkyRenderStateSet(3, (void *)(0x31003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&currentViewportColor, &currentViewportBounds, 1.0f, 0);
    mdlEffectEmitTagPair();
    (*(void (**)(u32, u32))renderStates)(6, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    RpSkyRenderStateSet(3, (void *)(0x3000D));
    shdSpriteDrawNowEx((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 0xF, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
    cursor = (u8 *)(&currentOverlayColorScratch);
    remaining = 4;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    currentOverlayColor = currentOverlayColorScratch;
    currentOverlayBoundsScratch.packet = D_00637430;
    currentOverlayBoundsScratch.fields.x = x - 0x40;
    currentOverlayBoundsScratch.fields.y = y - 0x40;
    currentOverlayBounds = currentOverlayBoundsScratch;
    (*(void (**)(u32, u32))renderStates)(0xE, 0);
    (*(void (**)(u32, u32))renderStates)(0xC, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    (*(void (**)(u32, u32))renderStates)(9, 1);
    (*(void (**)(u32, u32))renderStates)(0x14, 1);
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(8, 1);
    RpSkyRenderStateSet(3, (void *)(0x71003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&currentOverlayColor, &currentOverlayBounds, 5.0f, 0);
    mdlEffectEmitTagPair();
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    RpSkyRenderStateSet(3, (void *)(0x7000D));
    mdlEffectEmitMaskedTagPair();
    shdSpriteDrawNowEx((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 0xF, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
    mdlEffectEmitTagPair();
    cursor = (u8 *)(&currentFinishColorScratch);
    remaining = 4;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    currentFinishColor = currentFinishColorScratch;
    cursor = (u8 *)(&currentFinishBoundsScratch);
    remaining = 0x10;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    currentFinishBoundsScratch.fields.x = clipLeft;
    currentFinishBoundsScratch.fields.y = 0;
    currentFinishBoundsScratch.fields.width = clipWidth;
    currentFinishBoundsScratch.fields.height = 0x1E0;
    currentFinishBounds = currentFinishBoundsScratch;
    (*(void (**)(u32, u32))renderStates)(0xE, 0);
    (*(void (**)(u32, u32))renderStates)(0xC, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    (*(void (**)(u32, u32))renderStates)(9, 1);
    (*(void (**)(u32, u32))renderStates)(0x14, 1);
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(8, 1);
    RpSkyRenderStateSet(3, (void *)(0x31003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&currentFinishColor, &currentFinishBounds, 1.0f, 0);
    mdlEffectEmitTagPair();
    if (forcedHighlight != 0) {
        calDrawWeatherHighlight(x, y, 10.0f, opacity, currentWeather, 1, forcedHighlight, scaleX, scaleY, font, 1);
    } else {
        calDrawWeatherHighlight(x, y, 10.0f, opacity, currentWeather, 1, fallbackHighlight, scaleX, scaleY, font, 1);
    }
    cursor = (u8 *)(&previousBackdropColorScratch);
    remaining = 4;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    previousBackdropColor = previousBackdropColorScratch;
    previousBackdropBoundsScratch.packet = D_00637430;
    previousBackdropBoundsScratch.fields.x = x - 0x40;
    previousBackdropBoundsScratch.fields.y = y - 0x40;
    previousBackdropBounds = previousBackdropBoundsScratch;
    renderStates = (u8 *)D_00887300;
    (*(void (**)(u32, u32))renderStates)(0xE, 0);
    (*(void (**)(u32, u32))renderStates)(0xC, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    (*(void (**)(u32, u32))renderStates)(9, 1);
    (*(void (**)(u32, u32))renderStates)(0x14, 1);
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(8, 1);
    RpSkyRenderStateSet(3, (void *)(0x71003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&previousBackdropColor, &previousBackdropBounds, 10.0f, 0);
    mdlEffectEmitTagPair();
    cursor = (u8 *)(&previousViewportColorScratch);
    remaining = 4;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    previousViewportColor = previousViewportColorScratch;
    cursor = (u8 *)(&previousViewportBoundsScratch);
    remaining = 0x10;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    previousViewportBoundsScratch.fields.x = clipLeft;
    previousViewportBoundsScratch.fields.y = 0;
    previousViewportBoundsScratch.fields.width = clipWidth;
    previousViewportBoundsScratch.fields.height = 0x1E0;
    previousViewportBounds = previousViewportBoundsScratch;
    (*(void (**)(u32, u32))renderStates)(0xE, 0);
    (*(void (**)(u32, u32))renderStates)(0xC, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    (*(void (**)(u32, u32))renderStates)(9, 1);
    (*(void (**)(u32, u32))renderStates)(0x14, 1);
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(8, 1);
    RpSkyRenderStateSet(3, (void *)(0x31003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&previousViewportColor, &previousViewportBounds, 1.0f, 0);
    mdlEffectEmitTagPair();
    (*(void (**)(u32, u32))renderStates)(6, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    RpSkyRenderStateSet(3, (void *)(0x3000D));
    shdSpriteDrawNowEx((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 3, 1, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
    cursor = (u8 *)(&previousOverlayColorScratch);
    remaining = 4;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    previousOverlayColor = previousOverlayColorScratch;
    previousOverlayBoundsScratch.packet = D_00637430;
    previousOverlayBoundsScratch.fields.x = x - 0x40;
    previousOverlayBoundsScratch.fields.y = y - 0x40;
    previousOverlayBounds = previousOverlayBoundsScratch;
    (*(void (**)(u32, u32))renderStates)(0xE, 0);
    (*(void (**)(u32, u32))renderStates)(0xC, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    (*(void (**)(u32, u32))renderStates)(9, 1);
    (*(void (**)(u32, u32))renderStates)(0x14, 1);
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(8, 1);
    RpSkyRenderStateSet(3, (void *)(0x71003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&previousOverlayColor, &previousOverlayBounds, 5.0f, 0);
    mdlEffectEmitTagPair();
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    RpSkyRenderStateSet(3, (void *)(0x7000D));
    mdlEffectEmitMaskedTagPair();
    shdSpriteDrawNowEx((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 3, 1, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
    mdlEffectEmitTagPair();
    cursor = (u8 *)(&previousFinishColorScratch);
    remaining = 4;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    previousFinishColor = previousFinishColorScratch;
    cursor = (u8 *)(&previousFinishBoundsScratch);
    remaining = 0x10;
    if (cursor != NULL) {
        do {
            *cursor = 0;
            cursor += 1;
        } while (--remaining != 0);
    }
    previousFinishBoundsScratch.fields.x = clipLeft;
    previousFinishBoundsScratch.fields.y = 0;
    previousFinishBoundsScratch.fields.width = clipWidth;
    previousFinishBoundsScratch.fields.height = 0x1E0;
    previousFinishBounds = previousFinishBoundsScratch;
    (*(void (**)(u32, u32))renderStates)(0xE, 0);
    (*(void (**)(u32, u32))renderStates)(0xC, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    (*(void (**)(u32, u32))renderStates)(9, 1);
    (*(void (**)(u32, u32))renderStates)(0x14, 1);
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(8, 1);
    RpSkyRenderStateSet(3, (void *)(0x31003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&previousFinishColor, &previousFinishBounds, 1.0f, 0);
    mdlEffectEmitTagPair();
    if (forcedHighlight != 0) {
        calDrawWeatherHighlight(x, y, 10.0f, opacity, (oldWeather & 0xF), 2, forcedHighlight, scaleX, scaleY, font, 1);
        return;
    }
    calDrawWeatherHighlight(x, y, 10.0f, opacity, (oldWeather & 0xF), 2, fallbackHighlight, scaleX, scaleY, font, 1);
}

/* Clear a positive byte count when the destination pointer is non-null. */
static inline void calendarZeroBytes(void *memory, s32 count)
{
    u8 *cursor;
    s32 remaining;
    cursor = memory;
    remaining = count;
    if (cursor != NULL) {
        do {
            *cursor++ = 0;
            remaining--;
        } while (remaining != 0);
    }
}

// Intent: Draws one calendar date cell: day number, weekday colour, opacity and clip state [inferred]
// FUN_00262DE0
/* measured: baseline and direct render-state table calls both differ by 425 bytes. */
#pragma push
#pragma opt_propagation off
void calDrawDateCell(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 enabled, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite)
{
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    char number[4];
    s32 month;
    s32 day;
    struct CalendarColor { u8 r, g, b, a; } depthValue;
    struct CalendarColor depthScratch;
    Quad4 clip;
    Quad4 clipScratch;
    struct CalendarGlyphContext glyphContext;
    s32 weekday;
    s32 color;
    s32 glyphWidth;
    f32 drawDepth;
    s32 (**states)(RwRenderState state, void *value);

    calSplitDayOfYear(date, &month, &day);
    weekday = calGetWeekdayOfDay(date);
    color = enabled ? 0 : 0x686868;
    if (enabled) {
        if (weekday == 0 || calHasDayEntry(date) != 0) color = 0x860113;
        else if (weekday == 6) color = 0x35081;
    } else {
        if (weekday == 0 || calHasDayEntry(date) != 0) color = 0x885C62;
        else if (weekday == 6) color = 0x4D626F;
    }
    if (forceWhite == 1 && (weekday == 6 || weekday == 0 || calHasDayEntry(date) != 0))
        color = 0xFFFFFF;

    calendarZeroBytes(&depthScratch, sizeof(depthScratch));
    depthValue = depthScratch;
    calendarZeroBytes(&clipScratch, sizeof(clipScratch));
    clipScratch.a = clipLeft;
    clipScratch.b = 0;
    clipScratch.c = clipRight;
    clipScratch.d = 480;
    clip = clipScratch;
    states = D_00887300;
    states[0]((RwRenderState)(14), (void *)(0));
    states[0]((RwRenderState)(12), (void *)(1));
    states[0]((RwRenderState)(7), (void *)(2));
    states[0]((RwRenderState)(9), (void *)(1));
    states[0]((RwRenderState)(20), (void *)(1));
    states[0]((RwRenderState)(6), (void *)(0));
    states[0]((RwRenderState)(8), (void *)(1));
    RpSkyRenderStateSet(3, (void *)(0x31003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&depthValue, &clip, depth, 0);
    mdlEffectEmitTagPair();
    glyphWidth = shdSpriteEntryWidth(1, 0, (u8 *)fontWord);
    drawDepth = 1.0f + depth;
    shdSpriteDrawNowEx(((f32)x + 0.0f) + ((f32)glyphWidth / 2.0f) * (1.0f - scaleX), (f32)y, drawDepth, color, alpha, 1, weekday, (u8 *)fontWord, 1, 0, 0, 0.0f, scaleX, scaleY);
    sprintf(number, &iGpffffa6c4, day);
    glyphContext.offsetX = 0;
    glyphContext.offsetY = 0;
    glyphContext.depthOffset = 0.0f;
    glyphContext.scaleX = scaleX;
    glyphContext.scaleY = scaleY;
    glyphContext.font = (u8 *)fontWord;
    shdSpriteDrawUniformNumber((f32)(x + 20), ((f32)y + 0.0f) + 19.0f * scaleY, drawDepth,
                  color, alpha, number, 2, 31, 0, calDrawDayNumberGlyph, (u8 *)&glyphContext);
}
#pragma pop

#pragma push
// Intent: Advances a day-scroll step over 15 frames with a sine ease and returns 1 when finished [inferred]
// FUN_00263220
/* measured: optimization-level probe for 00263220 register colouring */
#pragma optimization_level 1
s32 calDayScrollStep(CalendarDayChange *work, s32 fromDay, s32 toDay)
{
    f32 position;
    f32 easedPosition;
    f32 delta;
    f32 easedDelta;
    s32 day;
    s32 frame;
    s32 distance;
    s32 duration;

    frame = work->frame + 1;
    work->frame = frame;
    distance = toDay - fromDay;
    if (distance == 1) {
        position = sinf((fGpffff84a4 * (f32)frame) /
                                15.0f);
        delta = position * (f32)(toDay - fromDay);
        position = (f32)fromDay;
        position = position + delta;
        day = (s32)position;
        work->day = day;
        work->scroll =
            (s32)(94.0f * (delta - (f32)(day - fromDay)));
        if (frame >= 0xF) {
            work->day = toDay;
            work->scroll = 0;
            return 1;
        }
            goto block_8;
        }
    if (fromDay < toDay) {
        duration = distance * 3;
    } else {
        duration = (fromDay - toDay) * 3;
    }
    easedDelta =
        (1.0f + sinf(fGpffff8574 +
                               (fGpffff82fc * (f32)frame) /
                               (f32)duration)) /
        2.0f;
    easedDelta = easedDelta * (f32)(toDay - fromDay);
    easedPosition = (f32)fromDay;
    easedPosition = easedPosition + easedDelta;
    day = (s32)easedPosition;
    work->day = day;
    work->scroll =
        (s32)(94.0f * (easedDelta - (f32)(day - fromDay)));
    if (frame >= duration) {
        work->day = toDay;
        work->scroll = 0;
        return 1;
    }
block_8:
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Intent: Day-change task update: loads the day-change resource, then drives the day-change state task [inferred]
// FUN_00263460
s32 cldDayChangeTaskUpdate(u8 *sdkTaskBytes)
{
    /* measured: remaining CalendarDayChange byte accesses preserve b210 load/address scheduling; individual field substitutions lose MATCH. */
    s32 taskAddress = (s32)sdkTaskBytes;
    s32 month;
    s32 day;
    s32 introFrame;
    s32 outroFrame;
    s32 pauseFrame;
    s32 settleFrame;
    s32 weatherFrame;
    s32 holdFrame;
    u8 *work;

    work = kwlnTaskGetWork();
    calSplitDayOfYear(((CalendarDayChange *)work)->fromDay, &month, &day);
    switch (((CalendarDayChange *)work)->state) {
    case 0:
        ((CalendarDayChange *)work)->spritePack.word = sdkSpritePackCreate(D_00637420);
        ((CalendarDayChange *)work)->state = 1;
        goto block_25;
    case 1:
        if (shdSpriteEnsureLoaded((u8 *)((CalendarDayChange *)work)->spritePack.word) != 0) {
            ((CalendarDayChange *)work)->state = 2;
            ((CalendarDayChange *)work)->childTask =
                cldDayChangeStartStateTask(taskAddress, MEMBER(s32, work, CalendarDayChange, spritePack.word),
                              ((CalendarDayChange *)work)->queue);
            if (datGetFlag(0x1471) != 0) {
                datSetFlag(0x1471, 0);
                return -1;
            }
        }
        goto block_25;
    case 2:
        ((CalendarDayChange *)work)->state = 3;
        ((CalendarDayChange *)work)->frame = 0;
        ((CalendarDayChange *)work)->day = MEMBER(s32, work, CalendarDayChange, fromDay);
        cldDayChangeRequest(((CalendarDayChange *)work)->childTask, month);
        /* fall through */
    case 3:
        introFrame = ((CalendarDayChange *)work)->frame + 1;
        ((CalendarDayChange *)work)->frame = introFrame;
        if (introFrame > 0xA) {
            ((CalendarDayChange *)work)->state = 4;
            MEMBER(s32, work, CalendarDayChange, frame) = 0;
        }
        goto block_25;
    case 8:
        outroFrame = ((CalendarDayChange *)work)->frame + 1;
        ((CalendarDayChange *)work)->frame = outroFrame;
        if (outroFrame > 0x1E) {
            cldDayChangeMarkDone((u8 *)((CalendarDayChange *)work)->childTask);
            ((CalendarDayChange *)work)->state = 0xA;
            MEMBER(s32, work, CalendarDayChange, frame) = 0;
        }
        goto block_25;
    case 4:
        pauseFrame = ((CalendarDayChange *)work)->frame + 1;
        ((CalendarDayChange *)work)->frame = pauseFrame;
        if (pauseFrame > 5) {
            ((CalendarDayChange *)work)->state = 5;
            MEMBER(s32, work, CalendarDayChange, frame) = 0;
        }
        goto block_25;
    case 9:
        settleFrame = ((CalendarDayChange *)work)->frame + 1;
        ((CalendarDayChange *)work)->frame = settleFrame;
        if (settleFrame > 0xA) {
            ((CalendarDayChange *)work)->state = 8;
            MEMBER(s32, work, CalendarDayChange, frame) = 0;
        }
        goto block_25;
    case 5:
        if (calDayScrollStep((CalendarDayChange *)work, MEMBER(s32, work, CalendarDayChange, fromDay),
                          ((CalendarDayChange *)work)->toDay) != 0) {
            ((CalendarDayChange *)work)->state = 6;
            ((CalendarDayChange *)work)->frame = 0;
        }
        calSplitDayOfYear(((CalendarDayChange *)work)->day, &month, &day);
        cldDayChangeRequest(((CalendarDayChange *)work)->childTask, month);
        goto block_25;
    case 7:
        weatherFrame = ((CalendarDayChange *)work)->frame + 1;
        ((CalendarDayChange *)work)->frame = weatherFrame;
        if (weatherFrame > 0xA) {
            ((CalendarDayChange *)work)->state = 9;
            MEMBER(s32, work, CalendarDayChange, frame) = 0;
        }
        goto block_25;
    case 6:
        holdFrame = ((CalendarDayChange *)work)->frame + 1;
        ((CalendarDayChange *)work)->frame = holdFrame;
        if (holdFrame > 5) {
            ((CalendarDayChange *)work)->state = 7;
            MEMBER(s32, work, CalendarDayChange, frame) = 0;
        }
        goto block_25;
    case 10:
        cldDayChangeMarkDone((u8 *)((CalendarDayChange *)work)->childTask);
        /* fall through */
    case 11:
        if (cldDayChangeIsDone(((CalendarDayChange *)work)->childTask) != 0) {
            return -1;
        }
    default:
        goto block_25;
    }
block_25:
    calQueueDayStripDraw(taskAddress, ((CalendarDayChange *)work)->queue);
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_lifetimes on
/* The scrolling state supplies a fractional-day offset of at most 94 pixels.
 * Blend the weather glyphs on either side of the day boundary; the selected
 * columns are redrawn with their own clip intervals. Opacity is a byte in
 * this function and in both calendar drawing helpers. */
// Intent: Draws the day strip with a crossfade between two weather columns at the fractional scroll offset [inferred]
// FUN_00263730
/* Widen opacity once after initializing the column; both crossfade calculations share this value. */
void calDrawDayStrip(s32 x, s32 y, f32 depth, u8 opacity, s32 date, s32 crossfade, u8 *work)
{
    /* measured: remaining CalendarDayChange byte accesses preserve b210 load/address scheduling; individual field substitutions lose MATCH. */
    s32 column;
    s32 oldWeather;
    s32 weather;
    u8 oldOpacity;
    u8 newOpacity;
    s32 oldFont;
    s32 newFont;
    s32 rowFont;
    s32 selectedFont;
    s32 alpha;

    column = 0;
    alpha = opacity;
    for (; column < 8; column++) {
        if (date - 1 + column < 0) {
            continue;
        }
        if (crossfade != 0 && (oldWeather = (u16)calGetPackedDayEntry(date - 1 + column, date)) != (u16)calGetPackedDayEntry(date - 1 + column, date + 1)) {
            oldOpacity = (u8)(255.0f - (f32)(func_0043c6a0(x) * alpha) / 94.0f);
            calDrawDateCell(x + column * 0x5E + 15, y + 245, depth, oldOpacity, date - 1 + column, 0, 1.0f, 1.0f, 0x58, 0x5A, ((CalendarDayChange *)work)->spritePack.word, 0);
            oldFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
            weather = (u16)calGetPackedDayEntry(date - 1 + column, date);
            calDrawWeather(x + column * 0x5E, y + 295, depth, oldOpacity, weather, 0, 1.0f, 1.0f, 0x58, 0x5A, oldFont, 0);
            newOpacity = (u8)((f32)(func_0043c6a0(x) * alpha) / 94.0f);
            calDrawDateCell(x + column * 0x5E + 15, y + 245, depth, newOpacity, date - 1 + column, 0, 1.0f, 1.0f, 0x58, 0x5A, MEMBER(s32, work, CalendarDayChange, spritePack.word), 0);
            newFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
            weather = (u16)calGetPackedDayEntry(date - 1 + column, date + 1);
            calDrawWeather(x + column * 0x5E, y + 295, depth, newOpacity, weather, 0, 1.0f, 1.0f, 0x58, 0x5A, newFont, 0);
        } else {
            calDrawDateCell(x + column * 0x5E + 15, y + 245, depth, opacity, date - 1 + column, 0, 1.0f, 1.0f, 0x58, 0x5A, ((CalendarDayChange *)work)->spritePack.word, 0);
            rowFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
            weather = (u16)calGetPackedDayEntry(date - 1 + column, date);
            calDrawWeather(x + column * 0x5E, y + 295, depth, opacity, weather, 0, 1.0f, 1.0f, 0x58, 0x5A, rowFont, 0);
        }
        if (column == 1) {
            calDrawDateCell(x + column * 0x5E + 15, y + 245, depth, opacity, date - 1 + column, 1, 1.0f, 1.0f, 0, 0x58, MEMBER(s32, work, CalendarDayChange, spritePack.word), 0);
            selectedFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
            weather = (u16)calGetPackedDayEntry(date - 1 + column, date);
            calDrawWeather(x + column * 0x5E, y + 295, depth, opacity, weather, 1, 1.0f, 1.0f, 0, 0x58, selectedFont, 0);
        } else if (column == 2) {
            calDrawDateCell(x + column * 0x5E + 15, y + 245, depth, opacity, date - 1 + column, 1, 1.0f, 1.0f, 0xB2, 0x5E, MEMBER(s32, work, CalendarDayChange, spritePack.word), 0);
            selectedFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
            weather = (u16)calGetPackedDayEntry(date - 1 + column, date);
            calDrawWeather(x + column * 0x5E, y + 295, depth, opacity, weather, 1, 1.0f, 1.0f, 0xB2, 0x5E, selectedFont, 0);
        }
    }
}

#pragma push
#pragma optimization_level 2
/* measured: removing lifetimes changes 97 bytes in the draw callback. */
#pragma opt_lifetimes on
// Intent: Queued draw callback for the day strip: draws fade rectangles and the strip columns [inferred]
// FUN_00263CB0
void calDrawDayStripCallback(s32 queue, u8 *task)
{
    /* measured: remaining CalendarDayChange byte accesses preserve b210 load/address scheduling; individual field substitutions lose MATCH. */
    typedef signed __int128 s128;
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    extern s32 shdSpriteDrawNow(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
    extern void calDrawDayStrip(s32, s32, f32, u8, s32, s32, u8 *);
    u8 *work;
    s32 state;
    f32 fadeColor;
    f32 fadeScratch;
    f32 exitColor;
    f32 exitScratch;
    typedef struct { s32 x, y, w, h; } FadeRect;
    s128 fadeBounds;
    FadeRect rectC __attribute__((aligned(16)));
    s128 exitBounds;
    FadeRect rectA __attribute__((aligned(16)));
    f32 *fadeCursor;
    f32 *exitCursor;
    f32 value;
    f32 remainingScale;
    f32 drawX;
    s32 column;
    f32 progress;
    f32 weatherProgress;
    u8 *boundsCursor;
    u8 *exitBoundsCursor;
    s32 font;
    s32 selectedFont;
    s32 day;
    s32 heldDay;
    s32 sourceDay;
    s32 unusedDay;
    s32 initialDay;
    s32 scrolledDay;
    s32 targetDay;
    s32 finalDay;
    s32 displayDay;
    s32 unusedValue;
    s32 scrollX;
    f32 iconX;
    s32 nextWeather;
    s32 firstFont;
    s32 secondFont;
    s32 opacity;
    s32 introFrame;
    s32 unusedFrame;
    s32 frame;
    s32 outroFrame;
    s32 destinationDay;
    s32 unusedIndex;
    s32 offsetX;
    s32 oldWeather;
    s32 byteCount;
    s32 boundsBytes;
    s32 exitBytes;
    s32 exitBoundsBytes;
    s32 cellDay;
    s64 unusedWideDay;

    work = kwlnTaskGetWork(task);
    state = ((CalendarDayChange *)(work))->state;
    switch (state) {
    case 3:
        day = ((CalendarDayChange *)work)->day;
        introFrame = ((CalendarDayChange *)work)->frame;
        if (introFrame < 5) {
            progress = sinf(fGpffff84a4 * ((f32)introFrame / 5.0f));
            value = (f32)shdSpriteEntryWidth(2, 0, ((CalendarDayChange *)work)->spritePack.pointer) / 2.0f;
            drawX = 1.0f - progress;
            iconX = 88.0f + value * drawX;
            shdSpriteDrawNowEx(iconX, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, MEMBER(u8 *, work, CalendarDayChange, spritePack.pointer), 1, 0, 0, 0.0f, progress, 1.0f);
        } else {
            shdSpriteDrawNowEx(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, ((CalendarDayChange *)work)->spritePack.pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f);
        }
        frame = MEMBER(s32, work, CalendarDayChange, frame);
        if (frame > 1) {
            value = 255.0f * ((f32)(frame - 1) / 9.0f);
            opacity = (s32)value;
            calDrawDayStrip(0, 0, 0.0f, opacity & 0xFF, day, 0,
                          work);
        }
        break;
    case 4:
    case 9:
        heldDay = ((CalendarDayChange *)work)->day;
        shdSpriteDrawNowEx(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, ((CalendarDayChange *)work)->spritePack.pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f);
        calDrawDayStrip(0, 0, 0.0f, 0xFF, heldDay, 0, work);
        break;
    case 6:
        initialDay = ((CalendarDayChange *)work)->fromDay;
        if (((CalendarDayChange *)work)->toDay - initialDay == 1) {
            shdSpriteDrawNowEx(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, ((CalendarDayChange *)work)->spritePack.pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f);
            calDrawDayStrip(-0x5E, 0, 0.0f, 0xFF, initialDay, 0, work);
        } else {
            scrolledDay = ((CalendarDayChange *)work)->day;
            scrollX = -((CalendarDayChange *)work)->scroll;
            shdSpriteDrawNowEx(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, ((CalendarDayChange *)work)->spritePack.pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f);
            calDrawDayStrip(scrollX, 0, 0.0f, 0xFF, scrolledDay, 0, work);
        }
        break;
    case 8:
        state = ((CalendarDayChange *)work)->day;
        outroFrame = ((CalendarDayChange *)work)->frame;
        if (outroFrame < 0xA) {
            value = (f32)outroFrame / 10.0f;
            opacity = (s32)(255.0f * (1.0f - value));
            shdSpriteDrawNow(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, MEMBER(u8 *, work, CalendarDayChange, spritePack.pointer), 1);
            column = 0;
            while (column < 7) {
                cellDay = state - 1 + column;
                if ((cellDay >= 0) && (column != 1)) {
                    calDrawDateCell(column * 0x5E + 0xF, 0xF5, 0.0f, opacity, (s32)cellDay, 0, 1.0f, 1.0f, 0x58, 0x5A, ((CalendarDayChange *)work)->spritePack.word, 0);
                    day = MEMBER(s32, work, CalendarDayChange, spritePack.word);
                    calDrawWeather(column * 0x5E, 0x127, 0.0f, opacity, calGetPackedDayEntry((s32)cellDay, state) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, day, 0);
                }
                column += 1;
            }
            calDrawDateCell(0x6D, 0xF5, 0.0f, 0xFF, state, 1, 1.0f, 1.0f, 0, 0x58, ((CalendarDayChange *)work)->spritePack.word, 0);
            selectedFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
            calDrawWeather(0x5E, 0x127, 0.0f, 0xFF, calGetPackedDayEntry(state, state) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, selectedFont, 0);
        } else if (outroFrame < 0x19) {
            shdSpriteDrawNow(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, MEMBER(u8 *, work, CalendarDayChange, spritePack.pointer), 1);
            fadeCursor = &fadeScratch;
            byteCount = 4;
            if (fadeCursor != NULL) {
                do {
                    *(u8 *)fadeCursor = 0;
                    fadeCursor = (f32 *)((u8 *)fadeCursor + 1);
                    byteCount -= 1;
                } while (byteCount != 0);
            }
            fadeColor = fadeScratch;
            boundsCursor = (u8 *)&rectC;
            boundsBytes = 0x10;
            if (boundsCursor != NULL) {
                do {
                    *boundsCursor = 0;
                    boundsCursor += 1;
                    boundsBytes -= 1;
                } while (boundsBytes != 0);
            }
            rectC.x = 0;
            rectC.y = 0;
            rectC.w = 0x280;
            rectC.h = 0x1E0;
            fadeBounds = *(s128 *)&rectC;
            {
                u32 table = (u32)D_00887300;

                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(0xE), (void *)(0));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(0xC), (void *)(1));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(7), (void *)(2));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(9), (void *)(1));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(0x14), (void *)(1));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(6), (void *)(0));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(8), (void *)(1));
            }
            RpSkyRenderStateSet(3, (void *)(0x31003));
            RpSkyRenderStateSet(2, (void *)(0x44));
            mdlEffectEmitMaskedTagPair();
            PrimDrawFlatRectangle(&fadeColor, &fadeBounds, 10.0f, 0);
            mdlEffectEmitTagPair();
            calDrawDateCell(0x6D, 0xF5, 0.0f, 0xFF, state, 1, 1.0f, 1.0f, 0, 0x58, ((CalendarDayChange *)work)->spritePack.word, 0);
            selectedFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
            calDrawWeather(0x5E, 0x127, 0.0f, 0xFF, calGetPackedDayEntry(state, state) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, selectedFont, 0);
        } else if (outroFrame < 0x1E) {
            progress = (f32)(outroFrame - 0x19) / 5.0f;
            remainingScale = 1.0f - progress;
            displayDay = (s32)(255.0f * remainingScale);
            value = (f32)shdSpriteEntryWidth(2, 0, MEMBER(u8 *, work, CalendarDayChange, spritePack.pointer)) / 2.0f;
            drawX = 88.0f + value * progress;
            shdSpriteDrawNowEx(drawX, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, MEMBER(u8 *, work, CalendarDayChange, spritePack.pointer), 1, 0, 0, 0.0f, remainingScale, 1.0f);
            exitCursor = &exitScratch;
            exitBytes = 4;
            if (exitCursor != NULL) {
                do {
                    *(u8 *)exitCursor = 0;
                    exitCursor = (f32 *)((u8 *)exitCursor + 1);
                    exitBytes -= 1;
                } while (exitBytes != 0);
            }
            exitColor = exitScratch;
            exitBoundsCursor = (u8 *)&rectA;
            exitBoundsBytes = 0x10;
            if (exitBoundsCursor != NULL) {
                do {
                    *exitBoundsCursor = 0;
                    exitBoundsCursor += 1;
                    exitBoundsBytes -= 1;
                } while (exitBoundsBytes != 0);
            }
            rectA.x = 0;
            rectA.y = 0;
            rectA.w = 0x280;
            rectA.h = 0x1E0;
            exitBounds = *(s128 *)&rectA;
            {
                u32 table = (u32)D_00887300;

                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(0xE), (void *)(0));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(0xC), (void *)(1));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(7), (void *)(2));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(9), (void *)(1));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(0x14), (void *)(1));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(6), (void *)(0));
                (*(s32 (**)(RwRenderState, void *))table)((RwRenderState)(8), (void *)(1));
            }
            RpSkyRenderStateSet(3, (void *)(0x31003));
            RpSkyRenderStateSet(2, (void *)(0x44));
            mdlEffectEmitMaskedTagPair();
            PrimDrawFlatRectangle(&exitColor, &exitBounds, 10.0f, 0);
            mdlEffectEmitTagPair();
            calDrawDateCell(0x6D, 0xF5, 0.0f, displayDay, state, 1, 1.0f, 1.0f, 0, 0x58, ((CalendarDayChange *)work)->spritePack.word, 0);
            font = MEMBER(s32, work, CalendarDayChange, spritePack.word);
            calDrawWeather(0x5E, 0x127, 0.0f, displayDay, calGetPackedDayEntry(state, state) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, font, 0);
        }
        break;
    case 5:
        sourceDay = ((CalendarDayChange *)work)->fromDay;
        destinationDay = ((CalendarDayChange *)work)->toDay;
        if (destinationDay - sourceDay == 1) {
            if (((CalendarDayChange *)work)->day == destinationDay) {
                offsetX = -0x5E;
            } else {
                offsetX = -((CalendarDayChange *)work)->scroll;
            }
            shdSpriteDrawNow(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, ((CalendarDayChange *)work)->spritePack.pointer, 1);
            calDrawDayStrip(offsetX, 0, 0.0f, 0xFF, sourceDay, 0, work);
        } else {
            selectedFont = ((CalendarDayChange *)work)->day;
            scrollX = -((CalendarDayChange *)work)->scroll;
            shdSpriteDrawNow(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, ((CalendarDayChange *)work)->spritePack.pointer, 1);
            calDrawDayStrip(scrollX, 0, 0.0f, 0xFF, selectedFont, 1, work);
        }
        break;
    case 7:
        targetDay = ((CalendarDayChange *)work)->toDay;
        if (targetDay - ((CalendarDayChange *)work)->fromDay == 1) {
            oldWeather = calGetPackedDayEntry(targetDay + 3, targetDay) & 0xFFFF;
            nextWeather = calGetPackedDayEntry(targetDay + 3, targetDay + 1) & 0xFFFF;
            if (oldWeather == nextWeather) {
                finalDay = ((CalendarDayChange *)work)->day;
                shdSpriteDrawNow(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, ((CalendarDayChange *)work)->spritePack.pointer, 1);
                calDrawDayStrip(0, 0, 0.0f, 0xFF, finalDay, 0, work);
            } else {
                displayDay = MEMBER(s32, work, CalendarDayChange, fromDay);
                shdSpriteDrawNow(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, MEMBER(u8 *, work, CalendarDayChange, spritePack.pointer), 1);
                sourceDay = 0;
                while (sourceDay < 7) {
                    if ((sourceDay != 1) && (sourceDay != 4)) {
                        cellDay = displayDay + sourceDay;
                        byteCount = sourceDay * 0x5E;
                        calDrawDateCell(byteCount + 0xF, 0xF5, 0.0f, 0xFF, cellDay, 0, 1.0f, 1.0f, 0x58, 0x5A, ((CalendarDayChange *)work)->spritePack.word, 0);
                        day = MEMBER(s32, work, CalendarDayChange, spritePack.word);
                        calDrawWeather(byteCount, 0x127, 0.0f, 0xFF, calGetPackedDayEntry(cellDay, displayDay) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, day, 0);
                    }
                    sourceDay += 1;
                }
                calDrawDateCell(0x6D, 0xF5, 0.0f, 0xFF, displayDay + 1, 1, 1.0f, 1.0f, 0, 0x58, ((CalendarDayChange *)work)->spritePack.word, 0);
                font = MEMBER(s32, work, CalendarDayChange, spritePack.word);
                calDrawWeather(0x5E, 0x127, 0.0f, 0xFF, calGetPackedDayEntry(displayDay + 1, displayDay) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, font, 0);
                frame = ((CalendarDayChange *)work)->frame;
                if (frame < 5) {
                    weatherProgress = (f32)frame / 5.0f;
                    calDrawDateCell(0x187, 0xF5, 0.0f, 0xFF, displayDay + 4, 0, 1.0f, 1.0f, 0, 0x58, MEMBER(s32, work, CalendarDayChange, spritePack.word), 0);
                    firstFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
                    calDrawWeather(0x178, 0x127, 0.0f, 0xFF, calGetPackedDayEntry(displayDay + 4, displayDay) & 0xFFFF, 0, 1.0f - weatherProgress, 1.0f, 0, 0x58, firstFont, 0);
                } else {
                    weatherProgress = ((f32)frame - 5.0f) / 5.0f;
                    calDrawDateCell(0x187, 0xF5, 0.0f, 0xFF, displayDay + 4, 0, 1.0f, 1.0f, 0, 0x58, MEMBER(s32, work, CalendarDayChange, spritePack.word), 0);
                    secondFont = MEMBER(s32, work, CalendarDayChange, spritePack.word);
                    calDrawWeather(0x178, 0x127, 0.0f, 0xFF, calGetPackedDayEntry(displayDay + 4, displayDay + 1) & 0xFFFF, 0, weatherProgress, 1.0f, 0, 0x58, secondFont, 0);
                }
            }
        } else {
            selectedFont = ((CalendarDayChange *)work)->day;
            scrollX = -((CalendarDayChange *)work)->scroll;
            shdSpriteDrawNow(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, ((CalendarDayChange *)work)->spritePack.pointer, 1);
            calDrawDayStrip(scrollX, 0, 0.0f, 0xFF, selectedFont, 1, work);
        }
        break;
    case 0:
    case 1:
    case 2:
        break;
    default:
        break;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Intent: Queues a day-strip draw task with the strip callback and its state argument [inferred]
// FUN_00264CB0
void calQueueDayStripDraw(s32 task, s32 queue)
{
    u8 *node;

    node = PrimAllocQueueNode();
    ((PrimQueueNode *)node)->callback = (void *)calDrawDayStripCallback;
    ((PrimQueueNode *)node)->argument.handle = task;
    PrimAppendNode((u8 *)queue, node);
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Intent: Day-change task destroy: destroys the child task hierarchy, frees the day-change resource and releases the task work block [inferred]
// FUN_00264D10
void cldDayChangeStopTask(u8 *unusedTask)
{
    /* measured: remaining CalendarDayChange byte accesses preserve b210 load/address scheduling; individual field substitutions lose MATCH. */
    s32 spritePack;
    u8 *work;

    work = kwlnTaskGetWork();
    if (kwlnTaskIsLinked((u8 *)((CalendarDayChange *)work)->childTask) != 0) {
        kwlnTaskDestroyWithHierarchy(MEMBER(s32, work, CalendarDayChange, childTask));
    }
    spritePack = ((CalendarDayChange *)work)->spritePack.word;
    if (spritePack != 0) {
        sdkSpritePackDestroy((void *)spritePack);
    }
    (*jtbl_008873EC)(work);
}
#pragma pop
#pragma pop
#pragma pop
