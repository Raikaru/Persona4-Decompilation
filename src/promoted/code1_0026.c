#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;
extern s32 datGetFlag(s32 arg0);
extern s32 frFontCountRuns(u8 *arg0);
extern void MT_Scene_StopShake();

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern s32 func_0026db60(u8 *task);
extern void MT_Scene_EvalCubicBezier(f32 fparg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6);
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern void MT_Scene_GetDirectionYaw(f32 *arg0, f32 *arg1);
extern f32 RwV3dNormalize(f32 *arg0, f32 *arg1);
extern void func_0026dc30(u8 *task);
extern s32 func_0026dee0(u8 *task);
extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern void func_0026dd60(u8 *arg0);
extern void MT_Scene_UpdateShake(void);
extern void MT_Scene_UpdateResource(u8 *arg0);
extern void MT_Scene_UpdateCameraResource(u8 *arg0);
extern void func_004b11d0(void *arg0, s32 arg1);
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void qsort(u32 *arg0, s32 arg1, s32 arg2,
                           s32 (*arg3)(u8 **arg0, u8 **arg1));
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void *memcpy(void *arg0, const void *arg1, u32 arg2);
extern void memset(void *arg0, void *arg1, s32 arg2);
extern u8 D_0088152F[];
typedef struct { s32 value[19]; } Code1_00267800ShapeTable;
extern Code1_00267800ShapeTable D_00638FD0;
typedef union { f32 value[19]; u32 words[19]; } Code1_00267800ScaleTable;
extern Code1_00267800ScaleTable D_00639020;
extern f32 fGpffff8218;
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u8 pad18[0x18];
    s32 field18;
    s32 field1C;
    s32 field20;
} Code1_00263220State;
static inline f32 func_00263220_mul(f32 left, f32 right)
{
    return left * right;
}
extern void func_00267b20(f32 fparg0, f32 fparg1, f32 fparg2,
                          s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5,
                          f32 fparg3, f32 fparg4, f32 fparg5);
extern char iGpffffa6c4;
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
static inline u32 *func_0026e010_add_offset(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}
static inline u8 *func_0026f1e0_add(u8 *base, u32 index)
{
    return base + index;
}

extern u8 *kwlnTaskGetWork();
extern s32 kwlnTaskIsLinked();

extern s32 func_0025ef20(u8 *arg0);
extern u8 D_00637420[];

extern s32 datEntryGetFlags(s16 arg0);



extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00266cc0(s32 arg0, s32 arg1);

extern void func_0025f230(void *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern void kAssertFail(void *arg0, s32 arg1);
extern s32 func_00266ba0(u8 *arg0);
extern s32 func_0045a8d0(s32 arg0, s32 arg1);
extern s32 func_004598e0(s32 arg0);
extern void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_0025f110(u8 *arg0);
extern u8 D_00638F90[];
extern void func_002674b0(s32 arg0, u8 *arg1);
extern char D_00637348[];
extern s32 kwlnTaskGetTaskByName(void *arg0);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern void func_00263cb0(s32 arg0, u8 *arg1);
extern void frFontSetStateBits(u32 param_1, int param_2);
extern s32 cldDayChangeStartStateTask(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00266a40(u32 arg0, s32 arg1);
extern void func_00266a90(u8 *arg0);
extern s32 func_00266ae0(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern s32 cmmCommunityGetCurrentId(void);
extern void cmmCommunitySetReversed(s32 arg0);
extern void cmmCommunityClearReversed(s32 arg0);
extern s32 cmmCommunityAddScaledPoints(s32 arg0, u32 arg1);
extern void func_00264cb0(s32 arg0, s32 arg1);
extern s32 func_00110c50(s32 arg0, s32 arg1);
extern s32 func_0043c6a0(s32 arg0);
extern f32 sinf(f32 fparg0);
extern void func_00262de0(s32 arg0, s32 arg1, f32 fparg0, u8 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0);
extern void func_00261560(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern u32 frFontGetMode(void);
extern void frFontLayoutText(u8 *text, u8 *context);
extern u32 datGetItemNameId(s16 id);
extern s64 func_0010d660(s32 arg0);
extern s64 func_0010d6d0(s32 arg0);
extern s32 sprintf(char *dst, const char *fmt, ...);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0045aeb0(s16 arg0, const char *arg1);
extern s32 D_008815B0[];
extern void frFontUpdateTextWork(u8 *arg0);
extern void frFontLayoutSlotText(s32 arg0, u8 *arg1);
extern u8 iGpffffa734;
extern f32 RwV3dLength(f32 *arg0);
extern u8 *func_003e9700(s32 arg0);
extern u8 *func_00457120(void);
extern void func_004b1470(s32 arg0, f32 *arg1);

extern s32 func_00110580(s32 arg0);
extern s32 func_00110d30(s32 arg0);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void func_00489f80(void);
extern void func_0045d6e0(void *arg0, void *arg1, f32 arg2, s32 arg3);
extern void func_0048a000(void);
extern s32 func_0025f2c0(s32 arg0, s32 arg1, u8 *arg2);
extern void func_0025f620(f32, f32, f32, s32, u8, const char *, s32, s16, s16, Code1_0026Callback, u8 *);
extern s32 func_0026e360(s64 arg0);
// Intent: Sets the enable flag on the sdlScheduler task when it exists [inferred]
// FUN_00260510
void sdlSchedulerEnable(void)
{
    s32 temp_2;
    u8 *temp_2_2;

    temp_2 = kwlnTaskGetTaskByName(D_00637348);
    if (temp_2 != 0) {
        temp_2_2 = kwlnTaskGetWork(temp_2);
        *(s32 *)(temp_2_2 + 8) |= 1;
    }
}
// Intent: Destroys the sdlScheduler task when it exists [inferred]
// FUN_00260560
void sdlSchedulerDestroy(void)
{
    s32 temp_2;

    temp_2 = kwlnTaskGetTaskByName(D_00637348);
    if (temp_2 != 0) {
        kwlnTaskDestroyWithHierarchy(temp_2);
    }
}
/* measured: declaring func_0025f430's halfword parameters as s16 reproduces
   retail's zero/pointer/constant/halfword setup order; object 88B, retail
   window 96B with zero tail, normalized_diff 0. */
// FUN_002605A0
void func_002605a0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, u8 arg1, s8 * arg2, s32 arg3, s32 arg4, u8 * arg5)
{
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    s8 temp_7;

    temp_7 = *(s8 *)(arg2 + arg3);
    if (temp_7 != 0xA) {
        func_0025f430(fparg0, fparg1, fparg2, arg0, arg1, 0, temp_7, *(u8 **)(arg5 + 0x10), 1, *(s16 *)(arg5 + 0), *(s16 *)(arg5 + 2), *(f32 *)(arg5 + 4), *(f32 *)(arg5 + 8), *(f32 *)(arg5 + 0xC));
    }
}

/* Three trail-segment layouts (arg4 0/1/2). The 0xC0-byte point tables are
 * struct copies; each loop's i = 0 precedes the invariant scale products,
 * which opt_loop_invariants hoists while the (s16) conversion of the second
 * product stays in the loop as in retail. The closing call's position
 * arguments are computed before its D_007612C4 products. func_0025f430's
 * colour parameter is declared u32 here (H011): retail converts arg2 for each
 * call and keeps the per-case colour copies in $fp/$s7. */
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
typedef struct { u32 w[48]; } TrailTable_00260600;

// FUN_00260600
void func_00260600(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, u8 arg3, s32 arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6)
{
    extern s32 func_0025f430(f32, f32, f32, u32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    extern f32 cosf(f32);
    extern f32 sinf(f32);
    extern u8 D_00637440[];
    extern u8 D_00637500[];
    extern f32 fGpffff811c;
    extern f32 iGpffff81d0;
    extern f32 D_007612C4;
    f32 tbl0[12][4];
    f32 tbl1[12][4];
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
    *(TrailTable_00260600 *)tbl0 = *(TrailTable_00260600 *)D_00637440;
    *(TrailTable_00260600 *)tbl1 = *(TrailTable_00260600 *)D_00637500;
    switch (arg4) {
    case 0:
        biasA = (int)((float)arg0 - 14.0f * fparg1);
        biasB = (int)((float)arg1 - 16.0f * fparg2);
        i = 0;
        halfThird = 0.5f * fparg2;
        halfFiveThird = 0.5f * (5.0f * fparg2);
        for (; i < 0xC; i++) {
            f32 *p = tbl0[i];

            entry2 = p[2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosS = 18.0f * cosf(angle);
            sinS = 18.0f * -sinf(angle);
            fx = cosS + (47.0f + p[0]);
            fy = sinS + (52.0f + p[1]);
            entry3 = p[3];
            func_0025f430((float)biasA + fx * fparg1, (float)biasB + fy * fparg2, fparg0, arg2, arg3, 0x13, 0, (u8 *)arg5, arg6,
                          (s16)(int)(0.5f * (fparg1 * (22.0f * entry3))), (s16)halfFiveThird,
                          entry2 - 180.0f, 0.5f * (fparg1 * entry3), halfThird);
        }
        func_0025f430((float)biasA + 34.0f * fparg1, (float)biasB + 36.0f * fparg2, fparg0, arg2, arg3, 5, 0, (u8 *)arg5, arg6, 0, 0, 0.0f, fparg1, fparg2);
        break;
    case 1:
        biasA = (int)((float)arg0 - 41.0f * fparg1);
        biasB = (int)((float)arg1 - 29.0f * fparg2);
        i = 0;
        halfThird = fGpffff811c * fparg2;
        halfFiveThird = fGpffff811c * (5.0f * fparg2);
        for (; i < 0xC; i++) {
            f32 *p = tbl1[i];

            entry2 = p[2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosS = 13.0f * cosf(angle);
            sinS = 13.0f * -sinf(angle);
            fx = cosS + (57.0f + p[0]);
            fy = sinS + (48.0f + p[1]);
            entry3 = p[3];
            func_0025f430((float)biasA + fx * fparg1, (float)biasB + fy * fparg2, fparg0, arg2, arg3, 0x13, 0, (u8 *)arg5, arg6,
                          (s16)(int)(0.5f * (fparg1 * (22.0f * entry3))), (s16)halfFiveThird,
                          entry2 - 180.0f, 0.5f * (fparg1 * entry3), halfThird);
        }
        fx = (float)biasA + 52.0f * fparg1;
        fy = (float)biasB + 38.0f * fparg2;
        func_0025f430(fx, fy, fparg0, arg2, arg3, 5, 0, (u8 *)arg5, arg6, 0, 0, 0.0f, D_007612C4 * fparg1, D_007612C4 * fparg2);
        break;
    case 2:
        biasA = (int)((float)arg0 - 12.0f * fparg1);
        biasB = (int)((float)arg1 + fparg2);
        i = 0;
        halfThird = fGpffff811c * fparg2;
        halfFiveThird = fGpffff811c * (5.0f * fparg2);
        for (; i < 0xC; i++) {
            f32 *p = tbl1[i];

            entry2 = p[2];
            angle = iGpffff81d0 * (90.0f - entry2);
            cosS = 13.0f * cosf(angle);
            sinS = 13.0f * -sinf(angle);
            fx = cosS + (57.0f + p[0]);
            fy = sinS + (48.0f + p[1]);
            entry3 = p[3];
            func_0025f430((float)biasA + fx * fparg1, (float)biasB + fy * fparg2, fparg0, arg2, arg3, 0x13, 0, (u8 *)arg5, arg6,
                          (s16)(int)(0.5f * (fparg1 * (22.0f * entry3))), (s16)halfFiveThird,
                          entry2 - 180.0f, 0.5f * (fparg1 * entry3), halfThird);
        }
        fx = (float)biasA + 52.0f * fparg1;
        fy = (float)biasB + 38.0f * fparg2;
        func_0025f430(fx, fy, fparg0, arg2, arg3, 5, 0, (u8 *)arg5, arg6, 0, 0, 0.0f, D_007612C4 * fparg1, D_007612C4 * fparg2);
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
extern void func_00260600(s32 x, s32 y, f32 depth, s32 color, u8 alpha, s32 variant, f32 scaleX, f32 scaleY, s32 font, s32 arg6);
#pragma push
#pragma opt_propagation off
// FUN_00260E60
void func_00260e60(s32 x, s32 y, f32 depth, u8 alpha, s32 kind, s32 variant, s32 highlight, f32 scaleX, f32 scaleY, s32 font, s32 setupStates)
{
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
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
            func_00260600(x, y, depth, color, alpha, variant, scaleX, scaleY, font, 0);
            break;
        case 1:
            func_00260600(x, y, depth, color, alpha, variant, scaleX, scaleY, font, 0);
            break;
        case 2:
            func_00260600(x, y, depth, color, alpha, variant, scaleX, scaleY, font, 0);
            break;
        }
        break;
    case 1:
        if (highlight != 0) {
            color = 0x4C85EF;
        }
        switch (variant) {
        case 0:
            func_0025f430((f32)x, (f32)y, depth, color, alpha, 8, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            break;
        case 1:
            posX = ((f32)x + 0.0f) - 3.0f * scaleX;
            posY = (f32)(y - 4);
            func_0025f430(posX, posY, depth, color, alpha, 7, 0, (u8 *)font, 0, 0, 0, 0.0f, 0.707f * scaleX, 0.707f * scaleY);
            break;
        case 2:
            posX = ((f32)x + 0.0f) + 23.0f * scaleX;
            posY = (f32)(y + 27);
            func_0025f430(posX, posY, depth, color, alpha, 7, 0, (u8 *)font, 0, 0, 0, 0.0f, 0.707f * scaleX, 0.707f * scaleY);
            break;
        }
        break;
    case 2:
        if (highlight != 0) {
            color = 0x949494;
        }
        switch (variant) {
        case 0:
            func_0025f430((f32)x, (f32)y, depth, color, alpha, 6, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            break;
        case 1:
            func_0025f430((f32)x, (f32)y, depth, color, alpha, 6, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            break;
        case 2:
            func_0025f430((f32)(x - 5), (f32)(y + 25), depth, color, alpha, 6, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
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
            func_0025f430((f32)x, (f32)y, depth, color, alpha, 10, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
            for (i = 0; i < 30; i++) {
                spot = &sparkle.offset[i];
                func_0025f430((f32)(x - 10 + spot->x), (f32)(y - 12 + spot->y), depth, color, alpha, 9, 0, (u8 *)font, 0, 0, 0, 0.0f, scaleX, scaleY);
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
// FUN_00261560
#pragma push
#pragma opt_lifetimes on
void func_00261560(s32 x, s32 y, f32 depth, u8 opacity, s32 weather, s32 highlight, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipWidth, s32 font, s32 forcedHighlight)
{
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
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
    extern void func_0045d6e0(void *, void *, f32, s32);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
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
        func_00489f80();
        func_0045d6e0(&sameBackdropColor, &sameBackdropBounds, 10.0f, 0);
        func_0048a000();
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
        func_00489f80();
        func_0045d6e0(&sameViewportColor, &sameViewportBounds, 1.0f, 0);
        func_0048a000();
        (*(void (**)(u32, u32))renderStates)(6, 1);
        (*(void (**)(u32, u32))renderStates)(7, 2);
        RpSkyRenderStateSet(3, (void *)(0x7000D));
        func_0025f430((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 3, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        func_0025f430((f32)x + (9.0f * scaleX), (f32) (y + 4), 10.0f, backgroundColor, opacity, 0xD, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        if (!(scaleX < 1.0f)) {
            func_0025f430(((float)x + 70.0f * scaleX), (f32) y, 10.0f, backgroundColor, opacity, 0xE, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        } else {
            func_0025f430(((float)x + 69.0f * scaleX), (f32) y, 10.0f, backgroundColor, opacity, 0xE, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
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
        func_00489f80();
        func_0045d6e0(&sameOverlayColor, &sameOverlayBounds, 5.0f, 0);
        func_0048a000();
        (*(void (**)(u32, u32))renderStates)(6, 0);
        (*(void (**)(u32, u32))renderStates)(7, 2);
        RpSkyRenderStateSet(3, (void *)(0x7000D));
        func_00489f80();
        func_0025f430((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 3, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        func_0025f430((f32)x + (9.0f * scaleX), (f32) (y + 4), 10.0f, backgroundColor, opacity, 0xD, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        if (!(scaleX < 1.0f)) {
            func_0025f430(((float)x + 70.0f * scaleX), (f32) y, 10.0f, backgroundColor, opacity, 0xE, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        } else {
            func_0025f430(((float)x + 69.0f * scaleX), (f32) y, 10.0f, backgroundColor, opacity, 0xE, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
        }
        func_0048a000();
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
        func_00489f80();
        func_0045d6e0(&sameFinishColor, &sameFinishBounds, 1.0f, 0);
        func_0048a000();
        if (forcedHighlight != 0) {
            func_00260e60(x, y, 10.0f, opacity, currentWeather, 0, forcedHighlight, scaleX, scaleY, font, 1);
            return;
        }
        func_00260e60(x, y, 10.0f, opacity, currentWeather, 0, fallbackHighlight, scaleX, scaleY, font, 1);
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
    func_00489f80();
    func_0045d6e0(&currentBackdropColor, &currentBackdropBounds, 10.0f, 0);
    func_0048a000();
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
    func_00489f80();
    func_0045d6e0(&currentViewportColor, &currentViewportBounds, 1.0f, 0);
    func_0048a000();
    (*(void (**)(u32, u32))renderStates)(6, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    RpSkyRenderStateSet(3, (void *)(0x3000D));
    func_0025f430((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 0xF, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
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
    func_00489f80();
    func_0045d6e0(&currentOverlayColor, &currentOverlayBounds, 5.0f, 0);
    func_0048a000();
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    RpSkyRenderStateSet(3, (void *)(0x7000D));
    func_00489f80();
    func_0025f430((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 0xF, 0, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
    func_0048a000();
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
    func_00489f80();
    func_0045d6e0(&currentFinishColor, &currentFinishBounds, 1.0f, 0);
    func_0048a000();
    if (forcedHighlight != 0) {
        func_00260e60(x, y, 10.0f, opacity, currentWeather, 1, forcedHighlight, scaleX, scaleY, font, 1);
    } else {
        func_00260e60(x, y, 10.0f, opacity, currentWeather, 1, fallbackHighlight, scaleX, scaleY, font, 1);
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
    func_00489f80();
    func_0045d6e0(&previousBackdropColor, &previousBackdropBounds, 10.0f, 0);
    func_0048a000();
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
    func_00489f80();
    func_0045d6e0(&previousViewportColor, &previousViewportBounds, 1.0f, 0);
    func_0048a000();
    (*(void (**)(u32, u32))renderStates)(6, 1);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    RpSkyRenderStateSet(3, (void *)(0x3000D));
    func_0025f430((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 3, 1, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
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
    func_00489f80();
    func_0045d6e0(&previousOverlayColor, &previousOverlayBounds, 5.0f, 0);
    func_0048a000();
    (*(void (**)(u32, u32))renderStates)(6, 0);
    (*(void (**)(u32, u32))renderStates)(7, 2);
    RpSkyRenderStateSet(3, (void *)(0x7000D));
    func_00489f80();
    func_0025f430((f32) x, (f32) y, 10.0f, backgroundColor, opacity, 3, 1, (u8 *)(font), 0, 0.0f, 0.0f, 0.0f, scaleX, scaleY);
    func_0048a000();
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
    func_00489f80();
    func_0045d6e0(&previousFinishColor, &previousFinishBounds, 1.0f, 0);
    func_0048a000();
    if (forcedHighlight != 0) {
        func_00260e60(x, y, 10.0f, opacity, (oldWeather & 0xF), 2, forcedHighlight, scaleX, scaleY, font, 1);
        return;
    }
    func_00260e60(x, y, 10.0f, opacity, (oldWeather & 0xF), 2, fallbackHighlight, scaleX, scaleY, font, 1);
}
#pragma pop
#pragma opt_propagation off
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
// FUN_00262DE0
void func_00262de0(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 enabled, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite)
{
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    struct CalendarGlyphContext {
        s16 offsetX, offsetY;
        f32 depthOffset, scaleX, scaleY;
        u8 *font;
    };
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

    func_001104d0(date, &month, &day);
    weekday = func_00110580(date);
    color = enabled ? 0 : 0x686868;
    if (enabled) {
        if (weekday == 0 || func_00110d30(date) != 0) color = 0x860113;
        else if (weekday == 6) color = 0x35081;
    } else {
        if (weekday == 0 || func_00110d30(date) != 0) color = 0x885C62;
        else if (weekday == 6) color = 0x4D626F;
    }
    if (forceWhite == 1 && (weekday == 6 || weekday == 0 || func_00110d30(date) != 0))
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
    func_00489f80();
    func_0045d6e0(&depthValue, &clip, depth, 0);
    func_0048a000();
    glyphWidth = func_0025f2c0(1, 0, (u8 *)fontWord);
    drawDepth = 1.0f + depth;
    func_0025f430(((f32)x + 0.0f) + ((f32)glyphWidth / 2.0f) * (1.0f - scaleX), (f32)y, drawDepth, color, alpha, 1, weekday, (u8 *)fontWord, 1, 0, 0, 0.0f, scaleX, scaleY);
    sprintf(number, &iGpffffa6c4, day);
    glyphContext.offsetX = 0;
    glyphContext.offsetY = 0;
    glyphContext.depthOffset = 0.0f;
    glyphContext.scaleX = scaleX;
    glyphContext.scaleY = scaleY;
    glyphContext.font = (u8 *)fontWord;
    func_0025f620((f32)(x + 20), ((f32)y + 0.0f) + 19.0f * scaleY, drawDepth,
                  color, alpha, number, 2, 31, 0, func_002605a0, (u8 *)&glyphContext);
}
#pragma opt_propagation on
// FUN_00263220
/* measured: optimization-level probe for 00263220 register colouring */
#pragma optimization_level 1
s32 func_00263220(Code1_00263220State *arg0, s32 arg1, s32 arg2)
{
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_2;
    s32 temp_17;
    s32 temp_3;
    s32 var_16;

    temp_17 = arg0->field20 + 1;
    arg0->field20 = temp_17;
    temp_3 = arg2 - arg1;
    if (temp_3 == 1) {
        temp_f0 = sinf((fGpffff84a4 * (f32)temp_17) /
                                15.0f);
        temp_f1 = temp_f0 * (f32)(arg2 - arg1);
        temp_f0 = (f32)arg1;
        temp_f0 = temp_f0 + temp_f1;
        temp_2 = (s32)temp_f0;
        arg0->field18 = temp_2;
        arg0->field1C =
            (s32)(94.0f * (temp_f1 - (f32)(temp_2 - arg1)));
        if (temp_17 >= 0xF) {
            arg0->field18 = arg2;
            arg0->field1C = 0;
            return 1;
        }
            goto block_8;
        }
    if (arg1 < arg2) {
        var_16 = temp_3 * 3;
    } else {
        var_16 = (arg1 - arg2) * 3;
    }
    temp_f1_2 =
        (1.0f + sinf(fGpffff8574 +
                               (fGpffff82fc * (f32)temp_17) /
                               (f32)var_16)) /
        2.0f;
    temp_f1_2 = temp_f1_2 * (f32)(arg2 - arg1);
    temp_f0_2 = (f32)arg1;
    temp_f0_2 = temp_f0_2 + temp_f1_2;
    temp_2 = (s32)temp_f0_2;
    arg0->field18 = temp_2;
    arg0->field1C =
        (s32)(94.0f * (temp_f1_2 - (f32)(temp_2 - arg1)));
    if (temp_17 >= var_16) {
        arg0->field18 = arg2;
        arg0->field1C = 0;
        return 1;
    }
block_8:
    return 0;
}
/* measured: closes optimization-level probe for 00263220 */
#pragma optimization_level 2
// FUN_00263460
s32 func_00263460(u8 *sdkTaskBytes)
{
    s32 arg0 = (s32)sdkTaskBytes;
    s32 sp3C;
    s32 sp38;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    u8 *temp_2;

    temp_2 = kwlnTaskGetWork();
    func_001104d0(*(s32 *)(temp_2 + 0xC), &sp3C, &sp38);
    switch (*(u32 *)temp_2) {
    case 0:
        *(s32 *)(temp_2 + 4) = func_0025ef20(D_00637420);
        *(u32 *)temp_2 = 1;
        goto block_25;
    case 1:
        if (func_0025f110((u8 *)*(s32 *)(temp_2 + 4)) != 0) {
            *(u32 *)temp_2 = 2;
            *(s32 *)(temp_2 + 0x14) =
                cldDayChangeStartStateTask(arg0, *(s32 *)(temp_2 + 4),
                              *(s32 *)(temp_2 + 8));
            if (datGetFlag(0x1471) != 0) {
                func_00106390(0x1471, 0);
                return -1;
            }
        }
        goto block_25;
    case 2:
        *(u32 *)temp_2 = 3;
        *(s32 *)(temp_2 + 0x20) = 0;
        *(s32 *)(temp_2 + 0x18) = *(s32 *)(temp_2 + 0xC);
        func_00266a40(*(s32 *)(temp_2 + 0x14), sp3C);
        /* fall through */
    case 3:
        temp_2_3 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_3;
        if (temp_2_3 > 0xA) {
            *(u32 *)temp_2 = 4;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 8:
        temp_2_4 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_4;
        if (temp_2_4 > 0x1E) {
            func_00266a90((u8 *)*(s32 *)(temp_2 + 0x14));
            *(u32 *)temp_2 = 0xA;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 4:
        temp_2_5 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_5;
        if (temp_2_5 > 5) {
            *(u32 *)temp_2 = 5;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 9:
        temp_2_6 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_6;
        if (temp_2_6 > 0xA) {
            *(u32 *)temp_2 = 8;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 5:
        if (func_00263220((Code1_00263220State *)temp_2, *(s32 *)(temp_2 + 0xC),
                          *(s32 *)(temp_2 + 0x10)) != 0) {
            *(u32 *)temp_2 = 6;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        func_001104d0(*(s32 *)(temp_2 + 0x18), &sp3C, &sp38);
        func_00266a40(*(s32 *)(temp_2 + 0x14), sp3C);
        goto block_25;
    case 7:
        temp_2_7 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_7;
        if (temp_2_7 > 0xA) {
            *(u32 *)temp_2 = 9;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 6:
        temp_2_8 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_8;
        if (temp_2_8 > 5) {
            *(u32 *)temp_2 = 7;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 10:
        func_00266a90((u8 *)*(s32 *)(temp_2 + 0x14));
        /* fall through */
    case 11:
        if (func_00266ae0(*(s32 *)(temp_2 + 0x14)) != 0) {
            return -1;
        }
    default:
        goto block_25;
    }
block_25:
    func_00264cb0(arg0, *(s32 *)(temp_2 + 8));
    return 0;
}
/* The scrolling state supplies a fractional-day offset of at most 94 pixels.
 * Blend the weather glyphs on either side of the day boundary; the selected
 * columns are redrawn with their own clip intervals. Opacity is a byte in
 * this function and in both calendar drawing helpers. */
// FUN_00263730
/* measured: opt_loop_invariants on hoists (u8)opacity into the sq/lq spill retail has (269 -> 253 words on the shape before the statement-ordered font word; off it stays inside the fade block). */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
void func_00263730(s32 x, s32 y, f32 depth, u8 opacity, s32 date, s32 crossfade, u8 *work)
{
    s32 column;
    s32 oldWeather;
    s32 weather;
    u8 oldOpacity;
    u8 newOpacity;
    s32 oldFont;
    s32 newFont;
    s32 rowFont;
    s32 selectedFont;

    for (column = 0; column < 8; column++) {
        if (date - 1 + column < 0) {
            continue;
        }
        if (crossfade != 0 && (oldWeather = (u16)func_00110c50(date - 1 + column, date)) != (u16)func_00110c50(date - 1 + column, date + 1)) {
            oldOpacity = (u8)(255.0f - (f32)(func_0043c6a0(x) * (u8)opacity) / 94.0f);
            func_00262de0(x + column * 0x5E + 15, y + 245, depth, oldOpacity, date - 1 + column, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(work + 4), 0);
            oldFont = *(s32 *)(work + 4);
            weather = (u16)func_00110c50(date - 1 + column, date);
            func_00261560(x + column * 0x5E, y + 295, depth, oldOpacity, weather, 0, 1.0f, 1.0f, 0x58, 0x5A, oldFont, 0);
            newOpacity = (u8)((f32)(func_0043c6a0(x) * (u8)opacity) / 94.0f);
            func_00262de0(x + column * 0x5E + 15, y + 245, depth, newOpacity, date - 1 + column, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(work + 4), 0);
            newFont = *(s32 *)(work + 4);
            weather = (u16)func_00110c50(date - 1 + column, date + 1);
            func_00261560(x + column * 0x5E, y + 295, depth, newOpacity, weather, 0, 1.0f, 1.0f, 0x58, 0x5A, newFont, 0);
        } else {
            func_00262de0(x + column * 0x5E + 15, y + 245, depth, opacity, date - 1 + column, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(work + 4), 0);
            rowFont = *(s32 *)(work + 4);
            weather = (u16)func_00110c50(date - 1 + column, date);
            func_00261560(x + column * 0x5E, y + 295, depth, opacity, weather, 0, 1.0f, 1.0f, 0x58, 0x5A, rowFont, 0);
        }
        if (column == 1) {
            func_00262de0(x + column * 0x5E + 15, y + 245, depth, opacity, date - 1 + column, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(work + 4), 0);
            selectedFont = *(s32 *)(work + 4);
            weather = (u16)func_00110c50(date - 1 + column, date);
            func_00261560(x + column * 0x5E, y + 295, depth, opacity, weather, 1, 1.0f, 1.0f, 0, 0x58, selectedFont, 0);
        } else if (column == 2) {
            func_00262de0(x + column * 0x5E + 15, y + 245, depth, opacity, date - 1 + column, 1, 1.0f, 1.0f, 0xB2, 0x5E, *(s32 *)(work + 4), 0);
            selectedFont = *(s32 *)(work + 4);
            weather = (u16)func_00110c50(date - 1 + column, date);
            func_00261560(x + column * 0x5E, y + 295, depth, opacity, weather, 1, 1.0f, 1.0f, 0xB2, 0x5E, selectedFont, 0);
        }
    }
}
#pragma pop
/* measured 00263cb0: object 3232B vs retail 4084B; retail 1021 vs object 808 instrs (-20.9%, gate needs 990-1052); differing words 914 reloc-masked, fnalign 695 edits +2 reloc-only. Archive 262 lines compiles after truthful s128 typedef+aligned(16) and (s32,u8*) per prologue daddu $4,$5 + callee deref; Ghidra/IDA 2-arg agree. Frame retail 0xF0; JAL retail 61 vs object ~39. */
/* shortfall: VU lq 0xC0->0xD0/0xA0->0xB0 + float adda/madd chains + scheduling across 8 switch arms; excluded folded switch (jump table intact), omitted-call as sole cause, unsigned/narrow bloat (signed, per-field). Production stays ASM. */
/* round2 2026-09-18 (scratch /var/tmp/cold263cb0b/NOTE_263cb0_round2.md): pragma round 13 variants best opt_common_subs off 909 (-5; 831 instrs/733 edits, size/edit cost, not bankable), rest tie/regress (schedule 920, prop 929, dead 928, peephole 912, L0 951/L1 920/L3-4 917); subscript N/A (no P[i]; stride i*0x5E hoisted both sides per retail 0x1640F4-104, inline probe ties 914); 7r: 2 accumulator sites both sides (mul.s 4=4, ?? 9v8, prime colour only; mtc1 95->40 is missing calls + lwc1/sd const builds, not spelling). BLOCKER: candidate lacks entire case 7 (Ghidra/IDA agree; retail .L00264238-4474; ~14-15 JAL of the jal 61->46 delta + ~200 of 213 missing instrs); prior shortfall line incomplete on this point (JAL recount 46, not ~39). Production stays ASM. */
/* banked 2026-09-18 B2: emitted 1028 vs retail 1021 (+0.7%, gate 991-1052), 915wd reloc-masked, fnalign 1091 edits +2 reloc-only, jal 63 vs 61. Restored missing case 7 (retail 0x164850-0x164B5C; loop skips 1 and 4, const-0xFF color, quotient staging in temp_f21 across calls); shared else48 via default-label goto (retail .L00264C10 shared by case 5 and 7; also fixes case-5-else arg4 0 to 1); call-idiom fix fparg0 0.0f and arg5 0 at 8 case-8 sites per retail f12 0 and the in-file 00263730 idiom; temp_20 s64 to s32 per retail addu. Baseline was archive262 at 914wd 695ed 808in. Recipe log: /var/tmp/cold263cb0b/NOTE_263cb0_round2.md. */
/* 2026-09-18 opcode census: 915 -> 908.  The census showed `sd +42`, which
   is not a wide local - it is fourteen stack arguments stored 64 bits wide
   because `func_0025f430` had no visible prototype here.  Every other caller
   in this file declares it at block scope; this body did not, so the
   arguments went through the default promotion.  Declaring
   `extern s32 func_0025f430(s32, s32, s32, s32, u8 *, s32, s32, s32, f32,
   f32, f32, f32, f32, f32)` - the signature `src/Event/Fcl/shdSprite.c`
   defines - is worth seven words.  Adding prototypes for `func_00263730`
   and `func_0025f2c0` alongside does not compile; their block-scope
   declarations elsewhere in this file disagree, which is its own finding. */
/* 2026-09-19 hole/lump (fnalign without --quiet, opclass.py handoff 7t): before retail 1021 vs object 1000
   (inside 991-1052), fnalign 1014 edits +2 reloc-only, score 908wd (obj 4000B/window 4096B),
   pure hole delete retail[185:218] (33) vs pure lump insert retail[478:478] object[729:850] (121, ~4x hole).
   Lump makeup before: sd 5, dsll32 2, lui 7, move 20, mtc1 6, mov.s 3, jal 9, addiu 28;
   hole wants mtc1 5, mov.s 3, jal 2. Opclass before 38: mtc1 -22, lui +10, move +10,
   addiu -9, mov.s -7, dsll32 +6, sw -6, sd +6. Characterised as sign/zero-extension cascade
   from a too-wide local (f32 args promoted to f64: sd/dsll32/lui where retail wants mtc1/mov.s/sw),
   not a switch chain, table-arithmetic, or struct copy. Fix: block-scope extern s32 func_0025f3f0
   (s32x6+f32x3) per src/Event/Fcl/shdSprite.c and extern void func_00263730(s32x5+u8*+f32) with u8*
   (not u32*) to match call sites without casts; prior note on non-compiling prototypes was file-scope,
   block-scope here does not conflict. After: same 1021 vs 1000, 999 edits +2 (-15), score 908 unchanged,
   hole gone (no delete >=20), lump still 121 but dsll32 0, sd 5->3, mtc1 6->11, mov.s 3->5;
   opclass 13: lui +10, addiu -9, sw -6, mtc1 -3 (dsll32/sd/mov.s gone). Case-7 recovery untouched. */
/* 2026-09-19 reg-alloc collapse (Main handoff: lui+10/addiu-9/sw-6 address fold + mtc1-3 check).
   Before (prototype fix banked): retail 1021 vs object 1000, 999 edits +2, score 908, opclass 13
   (lui +10, addiu -9, sw -6, mtc1 -3), hole gone, pure lump 121 at retail[478:478] object[729:850].
   Relocs in 729:850 are only R_MIPS_26 (jal: 2x110C50, 2x25f3f0/263730, loop 262de0/261560 tails);
   no HI16/LO16/GPREL16 there, so the lump's 7 lui are float consts, not global addresses.
   Overall lui+10 is D_00887300 base rebuild (object lui $v0,0 + lw per site x14 vs retail
   lui $s1,0x88 + addiu hoisted + lw per site); writing D_00887300[0] for (*D_00887300) ties
   (999/908 unchanged), so no preamble of the ((u32)SYM & 0xFFFF0000)-with-negative-offset kind here.
   Root cause of the pure 121/33 pair was a swapped saved-reg pair: object kept temp_2 in $s1
   (move $s1,$v0; lw $s0,0x18($s1)) where retail keeps it in $s0, throwing every later anchor
   (277 vs 398 + 121 + 398 vs 1). Fix: declare u8 *temp_2 + s32 temp_3 first (after externs),
   choosing $s0 (now move $s0,$v0; lw $s1,0x18($s0), matching retail). After: same 1021 vs 1000
   (inside 991-1052), 297 edits +2 (-702), score 905 (-3), opclass 13 unchanged (opcodes same,
   regs fixed), no delete/insert >=20 (largest delete 10 at 205:215, largest inserts 5-6).
   missing_prototypes.py is clean for this body (all calls declared), so mtc1 -3 is not an
   undeclared call but const/scheduling residue. Case-7 recovery untouched. */
/* measured 00263cb0 (owner, 2026-09-19): fnalign **297 -> 260 edits**, count
   1000 -> 1000 against retail 1021, by putting the switch arms in the order the
   JUMP TABLE uses rather than ascending case order.  The layout is read out of the
   retail ELF - the `sltiu` bound gives the entry count, each 4-byte entry gives an
   arm address, and sorting the case values by arm address is the order retail
   emitted them in; entries sharing the most common address are the default.
   Ascending order is what a lowered if-CHAIN wants.  A jump table already encodes
   its own order and the source has to agree with it.  Swept over every first-party
   floor with a table: 20 were already in layout order, 5 improved (274, 88, 50, 37
   and 7 edits) and 13 got worse, so it is measured per function like every other
   spelling. */
/* The switch arms are in retail's jump-table order. Locals whose live ranges
 * are disjoint share one variable (temp_18_2/temp_3, temp_17_10/temp_16_2,
 * temp_19_2/temp_17_3, fadeAlpha/temp_17_9, temp_22/temp_17), as retail's
 * register reuse across the cases shows. In case 7's day loop the date is
 * `temp_20` and the `* 0x5E` column is `var_2`, both dead outside that loop:
 * retail's register numbering follows which variable each value lives in, and
 * these give the $s3/$s4/$s5 order of the product, date and font word. The
 * render-state table goes through a u32 local, both fade rectangles are
 * {x,y,w,h} structs copied into the 16-byte argument, the case-5 and case-7
 * fallback tails are separate copies, and `temp_3_2 > 1` gives the slti $at
 * form. opt_lifetimes on is measured (102 -> 85 edits without the other levers). */
#pragma push
#pragma opt_lifetimes on
// FUN_00263CB0
void func_00263cb0(s32 arg0, u8 *arg1)
{
    typedef signed __int128 s128;
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    extern s32 func_0025f3f0(f32, f32, f32, s32, u8, s32, s32, u8 *, s32);
    extern void func_00263730(s32, s32, f32, u8, s32, s32, u8 *);
    u8 *temp_2;
    s32 temp_3;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    typedef struct { s32 x, y, w, h; } FadeRect;
    s128 spD0;
    FadeRect rectC __attribute__((aligned(16)));
    s128 spB0;
    FadeRect rectA __attribute__((aligned(16)));
    f32 *var_3;
    f32 *var_3_3;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f13;
    s32 var_21;
    f32 temp_f20;
    f32 temp_f21;
    u8 *var_3_2;
    u8 *var_3_4;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_17_8;
    s32 temp_17_9;
    s32 temp_18;
    s32 temp_18_3;
    f32 temp_f13_2;
    s32 temp_18_5;
    s32 temp_18_6;
    s32 temp_18_7;
    s32 temp_21;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 var_17;
    s32 var_18;
    s32 temp_18_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 temp_20;
    s64 temp_20_2;

    temp_2 = kwlnTaskGetWork(arg1);
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 3:
        temp_17 = *(s32 *)(temp_2 + 0x18);
        temp_2_2 = *(s32 *)(temp_2 + 0x20);
        if (temp_2_2 < 5) {
            temp_f20 = sinf(fGpffff84a4 * ((f32)temp_2_2 / 5.0f));
            temp_f0 = (f32)func_0025f2c0(2, 0, *(u8 **)(temp_2 + 4)) / 2.0f;
            temp_f13 = 1.0f - temp_f20;
            temp_f13_2 = 88.0f + temp_f0 * temp_f13;
            func_0025f430(temp_f13_2, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1, 0, 0, 0.0f, temp_f20, 1.0f);
        } else {
            func_0025f430(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
        }
        temp_3_2 = *(s32 *)(temp_2 + 0x20);
        if (temp_3_2 > 1) {
            temp_f0 = 255.0f * ((f32)(temp_3_2 - 1) / 9.0f);
            temp_21 = (s32)temp_f0;
            func_00263730(0, 0, 0.0f, temp_21 & 0xFF, temp_17, 0,
                          temp_2);
        }
        break;
    case 4:
    case 9:
        temp_17_2 = *(s32 *)(temp_2 + 0x18);
        func_0025f430(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
        func_00263730(0, 0, 0.0f, 0xFF, temp_17_2, 0, temp_2);
        break;
    case 6:
        temp_17_5 = *(s32 *)(temp_2 + 0xC);
        if (*(s32 *)(temp_2 + 0x10) - temp_17_5 == 1) {
            func_0025f430(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            func_00263730(-0x5E, 0, 0.0f, 0xFF, temp_17_5, 0, temp_2);
        } else {
            temp_17_6 = *(s32 *)(temp_2 + 0x18);
            temp_18_3 = -*(s32 *)(temp_2 + 0x1C);
            func_0025f430(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            func_00263730(temp_18_3, 0, 0.0f, 0xFF, temp_17_6, 0, temp_2);
        }
        break;
    case 8:
        temp_3 = *(s32 *)(temp_2 + 0x18);
        temp_3_3 = *(s32 *)(temp_2 + 0x20);
        if (temp_3_3 < 0xA) {
            temp_f0 = (f32)temp_3_3 / 10.0f;
            temp_21 = (s32)(255.0f * (1.0f - temp_f0));
            func_0025f3f0(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1);
            var_21 = 0;
            while (var_21 < 7) {
                temp_20 = temp_3 - 1 + var_21;
                if ((temp_20 >= 0) && (var_21 != 1)) {
                    func_00262de0(var_21 * 0x5E + 0xF, 0xF5, 0.0f, temp_21, (s32)temp_20, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(temp_2 + 4), 0);
                    temp_17 = *(s32 *)(temp_2 + 4);
                    func_00261560(var_21 * 0x5E, 0x127, 0.0f, temp_21, func_00110c50((s32)temp_20, temp_3) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, temp_17, 0);
                }
                var_21 += 1;
            }
            func_00262de0(0x6D, 0xF5, 0.0f, 0xFF, temp_3, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
            temp_16_2 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, 0.0f, 0xFF, func_00110c50(temp_3, temp_3) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, temp_16_2, 0);
        } else if (temp_3_3 < 0x19) {
            func_0025f3f0(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1);
            var_3 = &spE8;
            var_2 = 4;
            if (var_3 != NULL) {
                do {
                    *(u8 *)var_3 = 0;
                    var_3 = (f32 *)((u8 *)var_3 + 1);
                    var_2 -= 1;
                } while (var_2 != 0);
            }
            spEC = spE8;
            var_3_2 = (u8 *)&rectC;
            var_2_2 = 0x10;
            if (var_3_2 != NULL) {
                do {
                    *var_3_2 = 0;
                    var_3_2 += 1;
                    var_2_2 -= 1;
                } while (var_2_2 != 0);
            }
            rectC.x = 0;
            rectC.y = 0;
            rectC.w = 0x280;
            rectC.h = 0x1E0;
            spD0 = *(s128 *)&rectC;
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
            func_00489f80();
            func_0045d6e0(&spEC, &spD0, 10.0f, 0);
            func_0048a000();
            func_00262de0(0x6D, 0xF5, 0.0f, 0xFF, temp_3, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
            temp_16_2 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, 0.0f, 0xFF, func_00110c50(temp_3, temp_3) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, temp_16_2, 0);
        } else if (temp_3_3 < 0x1E) {
            temp_f20 = (f32)(temp_3_3 - 0x19) / 5.0f;
            temp_f0_2 = 1.0f - temp_f20;
            temp_17_9 = (s32)(255.0f * temp_f0_2);
            temp_f0 = (f32)func_0025f2c0(2, 0, *(u8 **)(temp_2 + 4)) / 2.0f;
            temp_f13 = 88.0f + temp_f0 * temp_f20;
            func_0025f430(temp_f13, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1, 0, 0, 0.0f, temp_f0_2, 1.0f);
            var_3_3 = &spE0;
            var_2_3 = 4;
            if (var_3_3 != NULL) {
                do {
                    *(u8 *)var_3_3 = 0;
                    var_3_3 = (f32 *)((u8 *)var_3_3 + 1);
                    var_2_3 -= 1;
                } while (var_2_3 != 0);
            }
            spE4 = spE0;
            var_3_4 = (u8 *)&rectA;
            var_2_4 = 0x10;
            if (var_3_4 != NULL) {
                do {
                    *var_3_4 = 0;
                    var_3_4 += 1;
                    var_2_4 -= 1;
                } while (var_2_4 != 0);
            }
            rectA.x = 0;
            rectA.y = 0;
            rectA.w = 0x280;
            rectA.h = 0x1E0;
            spB0 = *(s128 *)&rectA;
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
            func_00489f80();
            func_0045d6e0(&spE4, &spB0, 10.0f, 0);
            func_0048a000();
            func_00262de0(0x6D, 0xF5, 0.0f, temp_17_9, temp_3, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
            temp_16 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, 0.0f, temp_17_9, func_00110c50(temp_3, temp_3) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, temp_16, 0);
        }
        break;
    case 5:
        temp_17_3 = *(s32 *)(temp_2 + 0xC);
        temp_3_4 = *(s32 *)(temp_2 + 0x10);
        if (temp_3_4 - temp_17_3 == 1) {
            if (*(s32 *)(temp_2 + 0x18) == temp_3_4) {
                var_18 = -0x5E;
            } else {
                var_18 = -*(s32 *)(temp_2 + 0x1C);
            }
            func_0025f3f0(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1);
            func_00263730(var_18, 0, 0.0f, 0xFF, temp_17_3, 0, temp_2);
        } else {
            temp_16_2 = *(s32 *)(temp_2 + 0x18);
            temp_18_3 = -*(s32 *)(temp_2 + 0x1C);
            func_0025f3f0(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1);
            func_00263730(temp_18_3, 0, 0.0f, 0xFF, temp_16_2, 1, temp_2);
        }
        break;
    case 7:
        temp_17_7 = *(s32 *)(temp_2 + 0x10);
        if (temp_17_7 - *(s32 *)(temp_2 + 0xC) == 1) {
            temp_18_4 = func_00110c50(temp_17_7 + 3, temp_17_7) & 0xFFFF;
            temp_18_5 = func_00110c50(temp_17_7 + 3, temp_17_7 + 1) & 0xFFFF;
            if (temp_18_4 == temp_18_5) {
                temp_17_8 = *(s32 *)(temp_2 + 0x18);
                func_0025f3f0(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1);
                func_00263730(0, 0, 0.0f, 0xFF, temp_17_8, 0, temp_2);
            } else {
                temp_17_9 = *(s32 *)(temp_2 + 0xC);
                func_0025f3f0(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1);
                temp_17_3 = 0;
                while (temp_17_3 < 7) {
                    if ((temp_17_3 != 1) && (temp_17_3 != 4)) {
                        temp_20 = temp_17_9 + temp_17_3;
                        var_2 = temp_17_3 * 0x5E;
                        func_00262de0(var_2 + 0xF, 0xF5, 0.0f, 0xFF, temp_20, 0, 1.0f, 1.0f, 0x58, 0x5A, *(s32 *)(temp_2 + 4), 0);
                        temp_17 = *(s32 *)(temp_2 + 4);
                        func_00261560(var_2, 0x127, 0.0f, 0xFF, func_00110c50(temp_20, temp_17_9) & 0xFFFF, 0, 1.0f, 1.0f, 0x58, 0x5A, temp_17, 0);
                    }
                    temp_17_3 += 1;
                }
                func_00262de0(0x6D, 0xF5, 0.0f, 0xFF, temp_17_9 + 1, 1, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
                temp_16 = *(s32 *)(temp_2 + 4);
                func_00261560(0x5E, 0x127, 0.0f, 0xFF, func_00110c50(temp_17_9 + 1, temp_17_9) & 0xFFFF, 1, 1.0f, 1.0f, 0, 0x58, temp_16, 0);
                temp_3_2 = *(s32 *)(temp_2 + 0x20);
                if (temp_3_2 < 5) {
                    temp_f21 = (f32)temp_3_2 / 5.0f;
                    func_00262de0(0x187, 0xF5, 0.0f, 0xFF, temp_17_9 + 4, 0, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
                    temp_18_6 = *(s32 *)(temp_2 + 4);
                    func_00261560(0x178, 0x127, 0.0f, 0xFF, func_00110c50(temp_17_9 + 4, temp_17_9) & 0xFFFF, 0, 1.0f - temp_f21, 1.0f, 0, 0x58, temp_18_6, 0);
                } else {
                    temp_f21 = ((f32)temp_3_2 - 5.0f) / 5.0f;
                    func_00262de0(0x187, 0xF5, 0.0f, 0xFF, temp_17_9 + 4, 0, 1.0f, 1.0f, 0, 0x58, *(s32 *)(temp_2 + 4), 0);
                    temp_18_7 = *(s32 *)(temp_2 + 4);
                    func_00261560(0x178, 0x127, 0.0f, 0xFF, func_00110c50(temp_17_9 + 4, temp_17_9 + 1) & 0xFFFF, 0, temp_f21, 1.0f, 0, 0x58, temp_18_7, 0);
                }
            }
        } else {
            temp_16_2 = *(s32 *)(temp_2 + 0x18);
            temp_18_3 = -*(s32 *)(temp_2 + 0x1C);
            func_0025f3f0(88.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1);
            func_00263730(temp_18_3, 0, 0.0f, 0xFF, temp_16_2, 1, temp_2);
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
// FUN_00264CB0
void func_00264cb0(s32 arg0, s32 arg1)
{
    u8 *temp_2;

    temp_2 = func_00460990();
    *(void (**)(s32, u8 *))(temp_2 + 8) = func_00263cb0;
    *(s32 *)(temp_2 + 0x10) = arg0;
    func_00460ac0((u8 *)arg1, temp_2);
}
// FUN_00264D10
void func_00264d10(u8 *unusedTask)
{
    s32 temp_4;
    u8 *temp_2;

    temp_2 = kwlnTaskGetWork();
    if (kwlnTaskIsLinked((u8 *)*(s32 *)(temp_2 + 0x14)) != 0) {
        kwlnTaskDestroyWithHierarchy(*(s32 *)(temp_2 + 0x14));
    }
    temp_4 = *(s32 *)(temp_2 + 4);
    if (temp_4 != 0) {
        func_0025f230((void *)temp_4);
    }
    (*jtbl_008873EC)(temp_2);
}









static inline f32 func_0026_div_140(f32 value)
{
    return value / 140.0f;
}
#pragma optimization_level 1
/* measured: closes the optimization_level bracket (nd 0). */
#pragma optimization_level 2

/* Copy complete table objects; renderer callbacks may change the item index. */
#pragma optimization_level 1
static inline f32 func_00267800_threshold(void)
{
    return fGpffff8218;
}
static inline s32 *func_00267800_shape_at(s32 *values, s32 index)
{
    return values + index;
}
#pragma optimization_level 2
#pragma opt_common_subs off
#pragma opt_common_subs reset
#pragma optimization_level 2
/* Contour outline renderer: complete contour tables, clip and color values;
   source points are reloaded across renderer callbacks. The closing pass
   copies the outline pointer into its own cursor, which keeps that pointer
   in its retail saved register. */
typedef struct { const PrimPoint *value[19]; } ContourSourceTable;
static inline const PrimPoint *const *contourOutlinePoints(const PrimPoint *const *sources, s32 shape)
{
    return sources + shape * 2 + 1;
}

typedef struct { s32 value[19]; } ContourCountTable;

typedef struct { u32 value[4]; } ContourChannels;
static inline u32 contourChannelValue(const ContourChannels *color, s32 component)
{
    return color->value[component];
}

static inline PrimPoint *contourPointAt(PrimPoint *points, s32 index)
{
    return points + index;
}

static inline u8 *contourColorAt(u8 *colors, s32 index)
{
    return colors + index * 4;
}

static inline const s32 *contourOutlineCount(const s32 *words, s32 shape)
{
    return words + shape * 2 + 1;
}

#pragma opt_propagation off
#pragma opt_propagation on



#pragma push
#pragma opt_loop_invariants on
#pragma pop
#pragma optimization_level 1
#pragma opt_propagation off
#pragma opt_propagation on
#pragma optimization_level 2

#pragma opt_propagation off
#pragma opt_propagation on


#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop
#pragma optimization_level 0
#pragma optimization_level 2
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma pop
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop
// FUN_0026FBA0
s32 func_0026fba0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)sp20, (const char *)&iGpffffa734, func_0010d660(1));
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    return 0;
}
// FUN_0026FC20
s32 func_0026fc20(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)sp20, (const char *)&iGpffffa734, func_0010d6d0(1));
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    return 0;
}
// FUN_0026FCA0
s32 func_0026fca0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x23];

    if (frFontGetMode() != 0) {
        return 0;
    }
    sprintf((char *)sp20, (const char *)&iGpffffa734, func_0010d6d0(1));
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    sp20[0] = -0x7D;
    sp20[1] = -0xA;
    sp20[2] = 0;
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    sprintf((char *)sp20, (const char *)&iGpffffa734, func_0010d660(1));
    frFontUpdateTextWork(arg1);
    frFontLayoutText((u8 *)sp20, arg1);
    return 0;
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern s32 func_0026fff0(s32 arg0, u8 *arg1);
#pragma pop
#pragma opt_common_subs off
#pragma opt_propagation off
/* measured: closing opt_propagation off for func_0026fff0. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026fff0. */
#pragma opt_common_subs on
