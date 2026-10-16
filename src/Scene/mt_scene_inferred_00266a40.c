#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void qsort(u32 *arg0, s32 arg1, s32 arg2,
                           s32 (*arg3)(u8 **arg0, u8 **arg1));
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void *memcpy(void *arg0, const void *arg1, u32 arg2);
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
static inline f32 mtSceneMulF32(f32 left, f32 right)
{
    return left * right;
}
extern void PrimDrawContour(f32 fparg0, f32 fparg1, f32 fparg2,
                          s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5,
                          f32 fparg3, f32 fparg4, f32 fparg5);
extern char iGpffffa6c4;
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
static inline u32 *rbRingNextNode(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}
static inline u8 *mtSceneBytePairAt(u8 *base, u32 index)
{
    return base + index;
}

extern u8 *kwlnTaskGetWork();
extern s32 kwlnTaskIsLinked();

extern s32 sdkSpritePackCreate(u8 *arg0);
extern u8 D_00637420[];




extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(u8 *arg0, u8 *arg1);
extern void cldTimeChangeDraw(s32 arg0, s32 arg1);

extern void sdkSpritePackDestroy(void *arg0);
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern void kAssertFail(void *arg0, s32 arg1);
extern s32 cldTimeChangeUpdate(u8 *arg0);
extern s32 sdkSndFadeOutChannel(s32 arg0, s32 arg1);
extern s32 sdkSndStopChannel(s32 arg0);
extern void calSplitDayOfYear(s32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_0025f110(u8 *arg0);
extern u8 D_00638F90[];
extern void cldTimeChangeQueueDraw(s32 arg0, u8 *arg1);
extern char D_00637348[];
extern s32 cldDayChangeRequest(u32 arg0, s32 arg1);
extern void cldDayChangeMarkDone(u8 *arg0);
extern s32 cldDayChangeIsDone(s32 arg0);
extern f32 sinf(f32 fparg0);
extern void calDrawWeather(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern u8 iGpffffa734;

extern s32 calHasDayEntry(s32 arg0);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void mdlEffectEmitMaskedTagPair(void);
extern void PrimDrawFlatRectangle(void *arg0, void *arg1, f32 arg2, s32 arg3);
extern void mdlEffectEmitTagPair(void);
extern s32 func_0025f2c0(s32 arg0, s32 arg1, u8 *arg2);

/* Source unit: src/promoted/code1_0026.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0026.c; members 00266a40-00267b20 */

extern f32 D_007612C4;
static inline f32 func_0026_div_140(f32 value)
{
    return value / 140.0f;
}
static inline f32 mtSceneThresholdValue(void)
{
    return fGpffff8218;
}
static inline s32 *mtSceneShapeValueAt(s32 *values, s32 index)
{
    return values + index;
}
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
/* Three trail-segment layouts (arg4 0/1/2). The 0xC0-byte point tables are
 * struct copies; each loop's i = 0 precedes the invariant scale products,
 * which opt_loop_invariants hoists while the (s16) conversion of the second
 * product stays in the loop as in retail. The closing call's position
 * arguments are computed before its D_007612C4 products. func_0025f430's
 * colour parameter is declared u32 here (H011): retail converts arg2 for each
 * call and keeps the per-case colour copies in $fp/$s7. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: optimization-level probe for 00263220 register colouring */
/* measured: closes optimization-level probe for 00263220 */
/* measured: opt_loop_invariants on hoists (u8)opacity into the sq/lq spill retail has (269 -> 253 words on the shape before the statement-ordered font word; off it stays inside the fade block). */
#pragma push
#pragma pop
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
#pragma pop
// FUN_00266A40
s32 cldDayChangeRequest(u32 unk, s32 arg1) {
    u8 *temp_2 = kwlnTaskGetWork();

    if (*(s32 *)(temp_2 + 0x10) != arg1) {
        *(s32 *)(temp_2 + 4) |= 1;
        *(s32 *)(temp_2 + 0x14) = arg1;
    }
    return 0;
}

// FUN_00266A90
void cldDayChangeMarkDone(u8 *arg0) {
    u8 *p;

    if (kwlnTaskIsLinked(arg0) != 0) {
        p = kwlnTaskGetWork(arg0);
        *(s32 *)(p + 4) |= 2;
    }
}

// FUN_00266AE0
s32 cldDayChangeIsDone(s32 arg0)
{
    u8 *temp_2;
    s32 temp_4;

    if (kwlnTaskIsLinked() != 0) {
        temp_2 = kwlnTaskGetWork(arg0);
        temp_4 = *(s32 *)(temp_2 + 4);
        if ((temp_4 & 1) && !(temp_4 & 4)) {
            return 0;
        }
        if (*(s32 *)temp_2 == 1) {
            return 1;
        }
        return 0;
    }
    return 1;
}

// FUN_00266B70
void mtSceneBuildSpriteTable(void) {
    sdkSpritePackCreate(D_00637420);
}

// FUN_00266BA0
s32 cldTimeChangeUpdate(u8 *arg0)
{
    s32 sp3C;
    s32 sp38;
    u8 *work;
    s32 temp;
    s32 state;

    work = kwlnTaskGetWork();
    calSplitDayOfYear(*(s32 *)(work + 0xC), &sp3C, &sp38);
    state = *(s32 *)(work + 0);
    switch (state) {
    case 0:
        *(s32 *)(work + 4) = sdkSpritePackCreate(D_00638F90);
        *(s32 *)(work + 0) = 1;
        break;
    case 1:
        if (func_0025f110((u8 *)*(s32 *)(work + 4)) != 0) {
            *(s32 *)(work + 0) = 2;
            *(s32 *)(work + 0x14) = 0;
        }
        break;
    case 2:
        temp = *(s32 *)(work + 0x14) + 1;
        *(s32 *)(work + 0x14) = temp;
        if (temp >= 0x3C) {
            *(s32 *)(work + 0) = 3;
        }
        break;
    case 3:
    case 4:
        return -1;
    default:
        break;
    }
    cldTimeChangeQueueDraw((s32)arg0, (u8 *)*(s32 *)(work + 8));
    return 0;
}

// FUN_00266CC0
void cldTimeChangeDraw(s32 arg0, s32 arg1)
{
    extern s32 func_0025f430(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    extern f32 sinf(f32);
    extern s16 datGetDateIndex(void);
    s32 first;
    s32 second;
    u8 *work;
    s32 t;
    s32 alpha;

    work = kwlnTaskGetWork(arg1);
    first = *(s32 *)(work + 0xC);
    second = *(s32 *)(work + 0x10);
    if (calHasDayEntry(datGetDateIndex()) != 0) {
        if (*(s32 *)(work + 0xC) == 3) {
            first = 6;
        }
        if (*(s32 *)(work + 0x10) == 3) {
            second = 6;
        }
    }
    switch (*(s32 *)work) {
    case 2:
        t = *(s32 *)(work + 0x14);
        if (t < 15) {
            f32 s = sinf((fGpffff84a4 * (f32)t) / 15.0f);

            func_0025f430(200.0f * (1.0f - s), 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, s, 1.0f);
            t = *(s32 *)(work + 0x14);
            if (t > 10) {
                alpha = (u8)(255.0f * ((f32)(t - 10) / 5.0f));
                func_0025f430(0.0f, 0.0f, 0.0f, 0, alpha, first + 1, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
        } else if (t < 20) {
            func_0025f430(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            func_0025f430(0.0f, 0.0f, 0.0f, 0, 0xFF, first + 1, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
        } else if (t < 25) {
            f32 s = sinf((fGpffff84a4 * (f32)(t - 20)) / 5.0f);
            s32 w = func_0025f2c0(0, 0, *(u8 **)(work + 4));
            f32 r = 1.0f - s;

            func_0025f430(((f32)w / 2.0f) * s, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, r, 1.0f);
            w = func_0025f2c0(first + 1, 0, *(u8 **)(work + 4));
            func_0025f430(((f32)w / 2.0f) * s, 0.0f, 0.0f, 0, 0xFF, first + 1, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, r, 1.0f);
        } else if (t < 30) {
            f32 r;
            s32 w;
            f32 s;

            s = 1.0f - sinf((fGpffff84a4 * (f32)(t - 25)) / 5.0f);
            w = func_0025f2c0(0, 0, *(u8 **)(work + 4));
            r = 1.0f - s;

            func_0025f430(((f32)w / 2.0f) * s, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, r, 1.0f);
            w = func_0025f2c0(second + 1, 0, *(u8 **)(work + 4));
            func_0025f430(((f32)w / 2.0f) * s, 0.0f, 0.0f, 0, 0xFF, second + 1, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, r, 1.0f);
        } else if (t < 40) {
            func_0025f430(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            func_0025f430(0.0f, 0.0f, 0.0f, 0, 0xFF, second + 1, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
        } else if (t < 60) {
            f32 s = sinf((fGpffff84a4 * (f32)(t - 40)) / 20.0f);
            f32 r = 1.0f - s;

            alpha = (u8)(255.0f * r);
            func_0025f430(-200.0f * s, 0.0f, 0.0f, 0xFFFFFF, alpha, 0, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, r, 1.0f);
            t = *(s32 *)(work + 0x14);
            if (t < 45) {
                r = (f32)(t - 40) / 5.0f;
                alpha = (u8)(255.0f * (1.0f - r));
                func_0025f430(0.0f, 0.0f, 0.0f, 0, alpha, second + 1, 0, *(u8 **)(work + 4), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
        }
        break;
    }
}

// FUN_002674B0
void cldTimeChangeQueueDraw(s32 arg0, u8 *arg1) {
    u8 *p;

    p = PrimAllocQueueNode();
    *(void **)(p + 0x8) = (void *)cldTimeChangeDraw;
    *(s32 *)(p + 0x10) = arg0;
    PrimAppendNode(arg1, p);
}

// FUN_00267510
void mtSceneSpriteTableTaskDestroy(u8 *arg0) {
    u8 *p;
    s32 v;

    p = kwlnTaskGetWork();
    v = *(s32 *)(p + 4);
    if (v != 0) {
        sdkSpritePackDestroy((void *)v);
    }
    jtbl_008873EC[0](p);
}

// Intent: Creates the cldTimeChange child task with its work block (cldTimeChange.c alloc site) [inferred]
// FUN_00267570
s32 cldTimeChangeCreate(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *work;
    s32 result;

    if (arg3 == 0) {
        kAssertFail(D_00638FA0, 0xF2);
    }
    chkmemAllocSiteTag(D_00638FA0, 0xF3);
    work = D_008873F4[0](1, 0x18, 0x40000);
    *(s32 *)(work + 0) = 0;
    *(s32 *)(work + 8) = arg3;
    *(s32 *)(work + 0xC) = arg1;
    *(s32 *)(work + 0x10) = arg2;
    result = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_00638FB0), 0xF, 0, 0, cldTimeChangeUpdate, mtSceneSpriteTableTaskDestroy, (u8 *)((s32)work));
    sdkSndFadeOutChannel(3, 0);
    sdkSndStopChannel(0xA);
    return result;
}

// FUN_00267670
void cldShapeListDraw(u8 **arg0)
{
    u8 *base;
    u8 *var_18;
    u8 *temp_17;
    f32 old;
    f32 result;
    u8 *temp_4;
    f32 temp_f12;
    extern void func_002e2240(void *arg0, void *arg1, void *arg2);
    extern f32 D_00761514;
    extern f32 D_00761658;
    extern f32 D_0076165C;
    extern f32 D_00761260;
    extern s32 cldShapeDraw(u8 **arg0, u8 *arg1);
    extern f32 MT_Scene_CubicBezier(f32 arg0, f32 arg1, f32 arg2, f32 arg3,
                              f32 arg4);

    base = (u8 *)arg0;
    *(s32 *)(base + 0xC) = 0xFF;
    var_18 = *(u8 **)(*(u8 **)base + 8);
    goto loop_test;
loop_body:
    temp_17 = *(u8 **)(var_18 + 0xC);
    if (cldShapeDraw(arg0, *(u8 **)(var_18 + 0x14)) != 0) {
        temp_4 = *(u8 **)base;
        func_002e2240(temp_4, temp_4 + 4, var_18);
    }
    var_18 = temp_17;
loop_test:
    if (var_18 != NULL) {
        goto loop_body;
    }
    if ((*(f32 *)(base + 4) > 0.0f) ||
        (*(u16 *)(*(u8 **)base + 0x10) != 0)) {
        *(f32 *)(base + 4) += 1.0f;
        if (*(f32 *)(base + 8) == 0.0f) {
            *(f32 *)(base + 8) = D_00761514;
            return;
        }
        temp_f12 = func_0026_div_140(*(f32 *)(base + 4));
        result = MT_Scene_CubicBezier(D_00761658, D_00761658,
                               D_0076165C, D_00761260, temp_f12);
        old = *(f32 *)(base + 8);
        *(f32 *)(base + 8) = result * old + old;
    }
}

/* measured: optimization_level 1 and the right-associated first two terms produce the retail FPU chain; exact match nd 0 (obj 88B/window 96B). */
/* measured: opens optimization_level 1 to preserve retail's FPU term and accumulator order (nd 0). */
// FUN_002677A0
f32 MT_Scene_CubicBezier(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 u;
    f32 k;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    u = 1.0f - t;
    k = 3.0f * u;
    a = t * (t * t);
    b = t * (k * t);
    c = u * (u * u);
    d = t * (k * u);
    return p0 * c + p1 * d + p2 * b + p3 * a;
}

/* measured: closes the optimization_level bracket (nd 0). */
/* Copy complete table objects; renderer callbacks may change the item index. */
/* measured: cldShapeDraw MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_00267800
s32 cldShapeDraw(u8 **arg0, u8 *arg1)
{
    f32 position[4];
    Code1_00267800ShapeTable shapes;
    Code1_00267800ScaleTable scales;
    s32 alpha;
    s32 shape;
    f32 scale;
    f32 threshold;
    f32 renderScale;
    s32 *shapeSrc;
    s32 *shapeDst;
    u32 *scaleSrc;
    u32 *scaleDst;
    s32 count;

    memcpy(position, arg1 + 0x28, sizeof(position));
    position[2] += -136.0f + (150.0f * *(f32 *)((u8 *)arg0 + 4)) / 120.0f;
    position[0] += 288.0f;
    position[1] += 222.0f;
    shapeSrc = D_00638FD0.value;
    shapeDst = shapes.value;
    count = 19;
    do {
        s32 value = *shapeSrc++;
        count--;
        *shapeDst++ = value;
    } while (count > 0);
    scaleSrc = D_00639020.words;
    scaleDst = scales.words;
    count = 19;
    do {
        u32 value = *scaleSrc++;
        count--;
        *scaleDst++ = value;
    } while (count > 0);
    alpha = 0xFF;
    scale = *(f32 *)((u8 *)arg0 + 8) * scales.value[*(s32 *)(arg1 + 4)];
    position[3] = scale;
    if (scale < (threshold = fGpffff8218)) {
        alpha = (s32)((255.0f * scale) / threshold);
    }
    alpha = (s32)((f32)alpha * ((f32)*(s32 *)((u8 *)arg0 + 0xC) / 255.0f));
    shape = *mtSceneShapeValueAt(shapes.value, *(s32 *)(arg1 + 4));
    if (shape != 9) {
        if (!(scale <= mtSceneThresholdValue())) {
            renderScale = position[3];
            PrimDrawContour(position[0], position[1], 0.0f, 0x76BF48, alpha, 1, shape, 0, 0,
                           4.0f + position[2], renderScale, renderScale);
            renderScale = position[3];
            PrimDrawContour(position[0], position[1], 0.0f, 0x4883BF, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                           2.0f + position[2], renderScale, renderScale);
            renderScale = position[3];
            PrimDrawContour(position[0], position[1], 0.0f, 0xBF4848, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                           position[2] - 2.0f, renderScale, renderScale);
        }
        renderScale = position[3];
        PrimDrawContour(position[0], position[1], 0.0f, 0x292929, alpha, 1, shapes.value[*(s32 *)(arg1 + 4)], 0, 0,
                           position[2], renderScale, renderScale);
    }
    if (!(position[3] < 7.0f)) {
        return 1;
    }
    return 0;
}

/* measured: PrimDrawContour MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_00267B20
/* measured: PrimDrawContour MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void PrimDrawContour(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   f32 fparg3, f32 fparg4, f32 fparg5)
{
    typedef signed __int128 ContourPacket;
    typedef union {
        struct { s32 x, y, width, height; } fields;
        ContourPacket packet;
    } ContourClip;
    typedef union {
        struct { u8 red, green, blue, alpha; } bytes;
        f32 transfer;
    } ContourColor;
    extern const ContourCountTable D_0063A9E0;
    extern const ContourSourceTable D_0063AA30;
    extern void shdDisableBlendFlag(void);
    ContourColor backdrop;
    ContourColor backdropScratch;
    PrimPoint points[257];
    u8 colors[256 * 4];
    ContourCountTable counts;
    ContourSourceTable sources;
    ContourClip clip;
    ContourClip clipScratch;
    ContourChannels channels;
    s32 i9;
    s32 iA;
    s32 iB;
    s32 iC;
    s32 count9;
    s32 countA;
    s32 countB;
    const PrimPoint *ptr9;
    const PrimPoint *ptrA;
    const PrimPoint *ptrB;
    const PrimPoint *ptrC;
    u8 b0_9;
    u8 b1_9;
    u8 b2_9;
    u8 b3_9;
    u8 *p;
    s32 m;
    s32 (**tbl)(RwRenderState, void *);
    u32 combined;
    combined = ((u32)arg0 << 8) | (u32)arg1;
    {
        const s32 *src = D_0063A9E0.value;
        s32 *dst = counts.value;
        s32 remaining = 19;
        do {
            s32 value = *src;
            src++;
            remaining--;
            *dst = value;
            dst++;
        } while (remaining > 0);
    }
    {
        const PrimPoint *const *src = D_0063AA30.value;
        const PrimPoint * *dst = sources.value;
        s32 remaining = 19;
        do {
            const PrimPoint * value = *src;
            src++;
            remaining--;
            *dst = value;
            dst++;
        } while (remaining > 0);
    }
    if (!(fparg4 < 7.0f) || !(fparg5 < 7.0f)) {
        return;
    }
    if (arg3 == 9) {
        count9 = counts.value[arg3 * 2];
        ptr9 = sources.value[arg3 * 2];
        i9 = 0;
        b0_9 = (combined >> 24) & 0xFF;
        b1_9 = (combined >> 16) & 0xFF;
        b2_9 = (combined >> 8) & 0xFF;
        b3_9 = combined & 0xFF;
        while (i9 < count9) {
            const f32 *src9 = ptr9[i9].v;
            f32 *dst9 = &points[i9].v[0];
            u8 *col9;
            dst9[0] = (fparg0 + src9[0]) - ptr9[0].v[0];
            dst9[1] = (fparg1 + src9[1]) - ptr9[0].v[1];
            col9 = &colors[i9 * 4];
            col9[0] = b0_9;
            col9[1] = b1_9;
            col9[2] = b2_9;
            col9[3] = b3_9;
            i9++;
        }
        shdEnableBlendFlag();
        PrimDrawTransformed(colors, points, fparg2, count9, 5, 1, arg4, arg5, fparg3, fparg4, fparg5);
        shdDisableBlendFlag();
        return;
    }
    p = (u8 *)&backdropScratch.transfer;
    m = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            m--;
        } while (m != 0);
    }
    backdrop.transfer = backdropScratch.transfer;
    p = (u8 *)&clipScratch.packet;
    m = 0x10;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            m--;
        } while (m != 0);
    }
    clipScratch.fields.x = 0;
    clipScratch.fields.y = 0;
    clipScratch.fields.width = 0x280;
    clipScratch.fields.height = 0x1E0;
    clip.packet = clipScratch.packet;
    tbl = D_00887300;
    tbl[0]((RwRenderState)(0xE), (void *)(0));
    tbl[0]((RwRenderState)(0xC), (void *)(1));
    tbl[0]((RwRenderState)(7), (void *)(2));
    tbl[0]((RwRenderState)(9), (void *)(2));
    tbl[0]((RwRenderState)(0x14), (void *)(1));
    tbl[0]((RwRenderState)(6), (void *)(0));
    tbl[0]((RwRenderState)(8), (void *)(1));
    RpSkyRenderStateSet(3, (void *)(0x31003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&backdrop.transfer, &clip.packet, 10.0f, 0);
    mdlEffectEmitTagPair();
    countA = *contourOutlineCount(counts.value, arg3);
    ptrA = *contourOutlinePoints(sources.value, arg3);
    iA = 0;
    channels.value[0] = (combined >> 24) & 0xFF;
    channels.value[1] = (combined >> 16) & 0xFF;
    channels.value[2] = (combined >> 8) & 0xFF;
    channels.value[3] = combined & 0xFF;
    while (iA < countA) {
        const f32 *srcA = ptrA[iA].v;
        f32 *dstA = &points[iA].v[0];
        u8 *colA;
        dstA[0] = (fparg0 + srcA[0]) - ptrA[0].v[0];
        dstA[1] = (fparg1 + srcA[1]) - ptrA[0].v[1];
        colA = &colors[iA * 4];
        colA[0] = contourChannelValue(&channels, 0);
        colA[1] = contourChannelValue(&channels, 1);
        colA[2] = (u8)contourChannelValue(&channels, 2);
        colA[3] = contourChannelValue(&channels, 3);
        iA++;
    }
    shdEnableBlendFlag();
    tbl = D_00887300;
    tbl[0]((RwRenderState)(6), (void *)(0));
    tbl[0]((RwRenderState)(8), (void *)(1));
    RpSkyRenderStateSet(3, (void *)(0x30003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawTransformed(colors, points, fparg2, countA, 5, 0, arg4, arg5, fparg3, fparg4, fparg5);
    mdlEffectEmitTagPair();
    shdDisableBlendFlag();
    countB = counts.value[arg3 * 2];
    ptrB = sources.value[arg3 * 2];
    iB = 0;
    while (iB < countB) {
        const f32 *srcB = ptrB[iB].v;
        f32 *dstB = &points[iB].v[0];
        u8 *colB;
        dstB[0] = (fparg0 + srcB[0]) - ptrB[0].v[0];
        dstB[1] = (fparg1 + srcB[1]) - ptrB[0].v[1];
        colB = &colors[iB * 4];
        colB[0] = contourChannelValue(&channels, 0);
        colB[1] = contourChannelValue(&channels, 1);
        colB[2] = (u8)contourChannelValue(&channels, 2);
        colB[3] = contourChannelValue(&channels, 3);
        iB++;
    }
    if (arg1 == 0xFF) {
        shdEnableBlendFlag();
    }
    PrimDrawTransformed(colors, points, 1.0f + fparg2, countB, 5, 1, arg4, arg5, fparg3, fparg4, fparg5);
    if (arg1 == 0xFF) {
        shdDisableBlendFlag();
    }
    /* The closing pass walks the outline through its own cursor. */
    ptrC = ptrA;
    iC = 1;
    while (iC < countA) {
        const f32 *srcC = ptrC[iC].v;
        PrimPoint *dstC = contourPointAt(points, iC);
        u8 *colC;
        dstC[-1].v[0] = (fparg0 + srcC[0]) - ptrC[0].v[0];
        dstC[-1].v[1] = (fparg1 + srcC[1]) - ptrC[0].v[1];
        colC = contourColorAt(colors, iC);
        colC[-4] = contourChannelValue(&channels, 0);
        colC[-3] = contourChannelValue(&channels, 1);
        colC[-2] = (u8)contourChannelValue(&channels, 2);
        colC[-1] = contourChannelValue(&channels, 3);
        iC++;
    }
    if (arg1 == 0xFF) {
        shdEnableBlendFlag();
    }
    {
        s32 v0;
        s32 v1;
        v0 = (s32)(s16)(s32)(fparg0 + ((f32)arg4 - points[0].v[0]));
        v1 = (s32)(s16)(s32)(fparg1 + ((f32)arg5 - points[0].v[1]));
        PrimDrawTransformed(colors, points, fparg2, countA - 1, 4, 1, v0, v1, fparg3, fparg4, fparg5);
    }
    if (arg1 == 0xFF) {
        shdDisableBlendFlag();
    }
}

