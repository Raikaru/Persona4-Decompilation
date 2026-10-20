/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/btlAction.c; members 0021a7b0-0021dc50 */

#include "datCalc_unit_internal.h"
#include "operand_order_internal.h"
#include "list_item_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "datPersona_internal.h"
#include "btl_unit_internal.h"
#include "btl_ui_task_internal.h"
/* Adjacent BtlUnit gauge blocks at +0xA28/+0xA3C establish the 0x14 stride. */
typedef struct BtlGaugeTween
{
    f32 requestedFill;
    f32 fill;
    f32 startFill;
    f32 targetFill;
    s16 frame;
    u8 pad12[2];
} BtlGaugeTween;

typedef struct BtlGaugeReveal
{
    s32 frame;
    s32 active;
} BtlGaugeReveal;

typedef struct BtlFlourishState
{
    u16 flags;
    u16 unk02;
    u16 frame;
    u8 pad06[0xA];
    void *renderTask;
} BtlFlourishState;

typedef struct BtlAdvantageState
{
    u16 flags;
    u16 frame;
    u16 segments;
    u16 unk06;
    void *task;
} BtlAdvantageState;

/* btlShuffleCreate allocates/clears 0x94C bytes and fills these child handles. */
typedef struct BtlResultWork
{
    s32 flags;
    s32 phase;
    u8 parameters[0x58];
    s32 awardFlags;
    u8 awards[0x8D0];
    s32 file;
    s32 shuffleTask;
    s32 resultTask;
    s32 titleTask;
    s32 overlayTask;
    s32 summaryTask;
} BtlResultWork;
typedef struct KwlnTask KwlnTask;

extern u8 *iGpffffb3ac;
extern s32 iGpffffb470;
extern f32 D_008872F8[];
extern f32 fGpffff84a4;
extern BtlShuffleRenderStateSet D_00887300[];
extern u8 D_00628FA0[];
extern f32 D_007615B4;
extern f32 D_007615B8;
extern void (*D_00887314_abs[])(s32 arg0, void *arg1, s32 arg2, void *arg3, s32 arg4);
extern void btlUiSetRenderStates(void);
extern void memset(void *destination, s32 value, u32 size);
extern u32 kwlnTaskGetWork(void *task);
extern f32 cosf(f32 fparg0);
extern f32 sinf(f32 fparg0);
extern f32 fGpffff837c;
extern f32 fGpffff8378;
extern void H_Cdvd_Destroy(u8 *cdvd);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_006290C0[];
extern u8 D_006290D0[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void memcpy(void *dst, void *src, u32 size);
extern s32 btlShuffleTaskCreate(s32 parent, void *selection);
extern s32 btlResultSimpleCreateTask(s32 parentTask);
extern void PrimAppendNode(void *list, void *node);
extern void fadeBeginTransition(s32 mode, s32 duration);
extern s32 fadeStatus(void);
extern u8 D_00796340[];
extern s32 btlShuffleUpdateTask(u8 *sdkTaskBytes);
extern void (*jtbl_008873EC[])(void *);
extern void btlGaugeSetActive();
extern s32 btlShuffleTaskIsLoading(KwlnTask *task);
extern void btlShuffleTaskRequestCancel(s32);
extern void btlResultSimpleSetupEntries(s32);
extern void btlShuffleDrawSweep(s32 unusedTask, s32 *frameState);
extern void btlUiSetScale(void *work, f32 x, f32 y);
extern void btlGaugeDrawSegment(s32 task, u8 *gauge, f32 x, f32 y, f32 fill);
extern s32 datCalcMaxHp(s32 unit);
extern s32 datCalcIsDead(u8 *unit, s32 hpDelta);
extern f32 fGpffff8498;
extern s32 btlShuffleTickFrame(u8 *sdkTaskBytes);
extern void btlXpPrepareAwards(u8 *awards, u8 *reward);
extern void btlXpApplyAwards(u8 *awards, u8 *reward);
extern void btlXpAddRosterExp(u8 *awards);
extern void btlXpAddPartyExp(s32 awardsAddress);

union ColorWord {
    s32 word;
    f32 value;
    u8 bytes[4];
};

// Intent: draw a panel flourish with sky vertices and its fade. [inferred]
/* Packed halfword index pairs and RwCamera.nearPlane determine the sky packet geometry. */
// FUN_0021A7B0
void btlPanelDrawFlourish(u8 *task, u8 *state)
{
    PackedVec2f effectPosition;
    BtlShuffleSkyVertex vertices[6];
    BtlShuffleSkyVertex *vertex;
    u8 indexBytes[24];
    f32 visibility;
    f32 originX;
    f32 originY;
    f32 panelHeight;
    f32 screenDepth;
    f32 reciprocalDepth;
    f32 opacity;
    f32 firstScale;
    f32 secondScale;
    f32 bottomY;
    s32 *renderWork;
    s32 tick;
    s32 flags;
    extern void btlUiSetOrigin(u8 *work, f32 x, f32 y);

    renderWork = (s32 *)kwlnTaskGetWork(((BtlFlourishState *)state)->renderTask);
    if ((*renderWork & 1) == 0) {
        return;
    }
    flags = ((BtlFlourishState *)state)->flags;
    if (flags & 1) {
        if (!(flags & 2)) {
            ((BtlFlourishState *)state)->frame += 1;
            if (((BtlFlourishState *)state)->frame == 0x0E) {
                ((BtlFlourishState *)state)->flags |= 2;
            }
        }
        tick = ((BtlFlourishState *)state)->frame;
        btlUiSetRenderStates();
        {
            f32 depth = 0.0f;
            btlUiSetOrigin((u8 *)renderWork, depth, depth);
        }
        if (((BtlFlourishState *)state)->flags & 4) {
            originX = -10.0f;
            originY = 95.0f;
            panelHeight = 298.0f;
        } else {
            originX = -10.0f;
            originY = 95.0f;
            panelHeight = 181.0f;
        }
        if ((s32)tick < 5) {
            visibility = 0.0f;
        } else if ((s32)tick < 0x0E) {
            visibility = (f32)((s32)tick - 5) / 9.0f;
        } else {
            visibility = 1.0f;
        }
        if (!(visibility <= 0.0f)) {
            u8 *sourceIndices;
            u8 *outputIndices;
            s32 pairsLeft;
            s32 firstIndex;
            s32 secondIndex;
            screenDepth = D_008872F8[0];
            reciprocalDepth = 1.0f / ((RwCamera *)((u8 *)(u32)kwlnGetCamera()))->nearPlane;
            sourceIndices = D_00628FA0;
            outputIndices = indexBytes;
            pairsLeft = 6;
            do {
                firstIndex = *(s16 *)sourceIndices;
                secondIndex = ((s16 *)sourceIndices)[1];
                sourceIndices += 4;
                pairsLeft -= 1;
                *(s16 *)outputIndices = (s16)firstIndex;
                ((s16 *)outputIndices)[1] = (s16)secondIndex;
                outputIndices += 4;
            } while (pairsLeft > 0);
            /* Keep the first vertex cursor at the packet byte-address boundary. */
            vertex = (BtlShuffleSkyVertex *)(u8 *)&vertices[0];
            vertex->u.els.scrVertex.x = originX;
            vertex->u.els.scrVertex.y = originY;
            vertex->u.els.scrVertex.z = screenDepth;
            vertex->u.els.recipZ = reciprocalDepth;
            vertex->u.els.color.r = 0;
            vertex->u.els.color.g = 0;
            vertex->u.els.color.b = 0;
            opacity = 204.0f * visibility;
            vertex->u.els.color.a = (f32)(u8)opacity;
            vertex = &vertices[1];
            vertex->u.els.scrVertex.x = operandOrderAddFloat(originX, 241.0f);
            vertex->u.els.scrVertex.y = originY;
            vertex->u.els.scrVertex.z = screenDepth;
            vertex->u.els.recipZ = reciprocalDepth;
            vertex->u.els.color.r = 0;
            vertex->u.els.color.g = 0;
            vertex->u.els.color.b = 0;
            vertex->u.els.color.a = (f32)(u8)opacity;
            {
                vertex = &vertices[2];
                vertex->u.els.scrVertex.x = originX;
                vertex->u.els.scrVertex.y = bottomY = originY + panelHeight;
                vertex->u.els.scrVertex.z = screenDepth;
                vertex->u.els.recipZ = reciprocalDepth;
                vertex->u.els.color.r = 0;
                vertex->u.els.color.g = 0;
                vertex->u.els.color.b = 0;
                vertex->u.els.color.a = (f32)(u8)opacity;
            }
            {
                vertex = &vertices[3];
                vertex->u.els.scrVertex.x = operandOrderAddFloat(originX, 241.0f);
                vertex->u.els.scrVertex.y = bottomY;
                vertex->u.els.scrVertex.z = screenDepth;
                vertex->u.els.recipZ = reciprocalDepth;
                vertex->u.els.color.r = 0;
                vertex->u.els.color.g = 0;
                vertex->u.els.color.b = 0;
                vertex->u.els.color.a = (f32)(u8)opacity;
            }
            {
                f32 farX;
                vertex = &vertices[4];
                farX = operandOrderAddFloat(originX, (f32)0x15D);
                vertex->u.els.scrVertex.x = farX;
                vertex->u.els.scrVertex.y = originY;
                vertex->u.els.scrVertex.z = screenDepth;
                vertex->u.els.recipZ = reciprocalDepth;
                vertex->u.els.color.r = 0;
                vertex->u.els.color.g = 0;
                vertex->u.els.color.b = 0;
                vertex->u.els.color.a = 0;
                vertex = &vertices[5];
                vertex->u.els.scrVertex.x = farX;
                vertex->u.els.scrVertex.y = bottomY;
                vertex->u.els.scrVertex.z = screenDepth;
                vertex->u.els.recipZ = reciprocalDepth;
                vertex->u.els.color.r = 0;
                vertex->u.els.color.g = 0;
                vertex->u.els.color.b = 0;
                vertex->u.els.color.a = 0;
            }
            D_00887300[0](rwRENDERSTATETEXTURERASTER, 0);
            D_00887314_abs[0](3, vertices, 6, indexBytes, 12);
        }
        effectPosition.xy.x = 502.0f;
        effectPosition.xy.y = 215.0f;
        {
            if (tick < 0) {
                firstScale = 0.0f;
            } else if (tick < 0x0A) {
                firstScale = sinf(fGpffff84a4 * ((f32)tick / 10.0f));
            } else {
                firstScale = 1.0f;
            }
            {
                f32 depth = 0.0f;
                if (!(firstScale <= depth)) {
                    shdDrawRotatingQuad(effectPosition.xy, depth, 0xCC, D_007615B4 * firstScale, D_007615B8 * firstScale, 0);
                }
            }
        }
        {
            if (tick < 0) {
                secondScale = 0.0f;
            } else if (tick < 8) {
                secondScale = 1.0f - cosf(fGpffff84a4 * ((f32)tick / 8.0f));
            } else {
                secondScale = 1.0f;
            }
            {
                f32 depth = 0.0f;
                if (!(secondScale <= depth)) {
                    shdDrawRectOutline(effectPosition.xy, depth, 0x89FF1FFF, fGpffff84a4 * secondScale, 125.5f * secondScale, 16.0f, 1);
                }
            }
        }
    }
}

// Intent: initialise a gauge with its default range. [inferred]
// FUN_0021AE60
void btlGaugeInit(u8 *unusedTask, u8 *gauge)
{
    ((BtlGaugeTween *)gauge)->requestedFill = -1.0f;
    ((BtlGaugeTween *)gauge)->fill = 1.0f;
    ((BtlGaugeTween *)gauge)->frame = -1;
}

// Intent: clear a unit's gauge state. [inferred]
// FUN_0021AE80
void btlUnitGaugeClear(s32 unitAddress)
{
    btlGaugeSetActive(unitAddress + 0xA3C);
}

// Intent: draw a unit's gauge with its HP fraction and fill. [inferred]
/* Access-site fields and allocation-bound aliases retain the measured byte-pointer interface. */
// FUN_0021AEB0

void btlGaugeDrawUnit(s32 task, u8 *unit, f32 x, f32 y, s32 visible, f32 hpRatio)
{
    BtlUnit *battleUnit = (BtlUnit *)(unit);
    f32 minimumFill;
    f32 fill;
    u16 *unitData;
    u16 *checkedData;

    fill = hpRatio;
    if (visible != 0) {
        unitData = (u16 *)((BtlUnit *)(unit))->datUnit;
        if ((unitData != NULL) &&
            (datCalcIsDead((u8 *)unitData, 0) == 0)) {
            checkedData = (u16 *)battleUnit->datUnit;
            if ((*checkedData & 0x20) != 0) {
                if ((datCalcGetHp((s32)checkedData) & 0xFFFF) <= 1) {
                    goto callback;
                }
            }
            if (!(fill <= 0.0f)) {
                minimumFill = fGpffff8498;
                if (fill < minimumFill) {
                    fill = minimumFill;
                }
            }
        }
callback:
        btlGaugeDrawSegment(task, unit + 0xA3C, x, y, fill);
    }
}

// Intent: refresh the HP ratio of each party gauge. [inferred]
/* Access-site fields and allocation-bound aliases retain the measured byte-pointer interface. */
// FUN_0021AFA0

void btlGaugeRefreshAll(void)
{
    BtlUnit *gaugeUnit;
    u8 *p;
    u8 *work;
    u32 i;
s16 value0;
s16 value1;

    i = 0;
    goto outer_test;
outer_body:
    p = ((BtlBattleState *)(iGpffffb3ac))->unitLists[i * 2];
    goto loop_test;
loop_body:
    gaugeUnit = (BtlUnit *)p;
    if ((u8 *)((BtlUnit *)(p))->datUnit != NULL) {
        work = p + 0xA28;
        if (((BtlUnit *)(p))->hpGaugeMarker >= 0 &&
            ((BtlUnit *)(p))->hpGaugeMarker < 0xC) {
            value0 = (s16)datCalcGetHp((s32)((BtlUnit *)(p))->datUnit);
            value1 = (s16)datCalcMaxHp((s32)gaugeUnit->datUnit);
            ((BtlGaugeTween *)(work))->frame = -1;
            *(f32 *)work = -1.0f;
            ((BtlGaugeTween *)(work))->fill = (f32)value0 / (f32)value1;
        }
    }
    p = (u8 *)((BtlUnit *)(p))->nextUnit;
loop_test:
    if (p != NULL) {
        goto loop_body;
    }
    i++;
outer_test:
    if (i < 2U) {
        goto outer_body;
    }
}

// Intent: return a unit's HP as a fraction of its max HP. [inferred]
/* Access-site fields and allocation-bound aliases retain the measured byte-pointer interface. */
// FUN_0021B0A0

f32 btlGaugeHpRatio(u8 *unit)
{
    BtlUnit *battleUnit = (BtlUnit *)(unit);
    typedef struct DatUnit DatUnit;
    extern s32 datCalcGetHp(DatUnit *unit);
    extern s32 datCalcMaxHp(DatUnit *unit);
    f32 maxHpFloat;
    f32 hpFloat;
    u32 maxHp;
    u32 hp;

    if ((s32)((BtlUnit *)(unit))->datUnit == 0) {
        return 0.0f;
    }
    maxHp = (u32)datCalcMaxHp((DatUnit *)(s32)((BtlUnit *)(unit))->datUnit);
    maxHpFloat = (f32)maxHp;
    if (maxHpFloat == 0.0f) {
        return 0.0f;
    }
    hp = (u32)datCalcGetHp((DatUnit *)(s32)battleUnit->datUnit);
    hpFloat = (f32)hp;
    return hpFloat / maxHpFloat;
}

// Intent: initialise a gauge value and its counter. [inferred]
// FUN_0021B190
void btlGaugeInitValue(u8 *valueState, s32 value)
{
    memset(valueState, 0, 4);
    *(s32 *)valueState = value;
}
/* Gauge-component initialization hook called by btlUiTaskInit; retail deliberately leaves its state untouched. */
// FUN_0021B1E0
void btlGaugeInitNoop(void)
{
}

// Intent: step every unit's gauge animation toward its target. [inferred]
// FUN_0021B1F0
// measured: loop-invariant constant hoisting probe for func_0021b1f0.
/* measured: baseline off differs by 65 words; explicit frame-count/zero locals still differ (217 bytes); retain hoisting. */
#pragma opt_loop_invariants on
/* Head/tail pairs belong to BtlBattleState; the tween is the BtlUnit HP-gauge subobject. */
void btlGaugeStepAll(s32 unusedTask, s32 *taskPointer)
{
    f32 fraction;
    f32 startFill;
    s16 frame;
    u8 *unit;
    u32 listIndex;
    u8 *gauge;

    if ((*(s32 *)kwlnTaskGetWork((void *)*taskPointer) & 1) != 0) {
        listIndex = 0;
        while (listIndex < 2U) {
            unit = ((BtlBattleState *)(iGpffffb3ac))->unitLists[listIndex * 2];
            while (unit != NULL) {
                if (*(s32 *)&((BtlUnit *)unit)->datUnit != 0) {
                    gauge = unit + 0xA28;
                    fraction = ((BtlUnit *)(unit))->hpGauge.ratio;
                    if (!(fraction < 0.0f)) {
                        ((BtlGaugeTween *)gauge)->targetFill = fraction;
                        ((BtlGaugeTween *)gauge)->startFill = ((BtlGaugeTween *)gauge)->fill;
                        *(s32 *)gauge = (s32)0xBF800000;
                        ((BtlGaugeTween *)gauge)->frame = 0;
                    }
                    frame = ((BtlGaugeTween *)gauge)->frame;
                    if (frame >= 0 && frame < 0xD) {
                        if (frame < 0xC) {
                            startFill = ((BtlGaugeTween *)gauge)->startFill;
                            fraction = (f32)frame / 12.0f;
                            ((BtlGaugeTween *)gauge)->fill =
                                fraction * (((BtlGaugeTween *)gauge)->targetFill -
                                           startFill) +
                                (0.0f + startFill);
                        } else {
                            ((BtlGaugeTween *)gauge)->fill = ((BtlGaugeTween *)gauge)->targetFill;
                        }
                        ((BtlGaugeTween *)gauge)->frame =
                            ((BtlGaugeTween *)gauge)->frame + 1;
                    }
                }
                unit = *(u8 * *)&((BtlUnit *)unit)->nextUnit;
            }
            listIndex += 1;
        }
    }
}

#pragma opt_loop_invariants off
// Intent: set a gauge's active state. [inferred]
// FUN_0021B310
void btlGaugeSetActive(u8 *gauge, s32 active)
{
    if (active != 0) {
        ((BtlGaugeReveal *)gauge)->frame = 0;
    }
    ((BtlGaugeReveal *)gauge)->active = active;
}

/* object 452B; retail window 464B; normalized_diff 6; differing offsets 0x28, 0x30, 0xF8, 0x11C, 0x12C, 0x13C; best legal plain-C body; residual is saved FPU parameter-coloring and 12B tail padding. */
// Intent: draw one gauge segment with its scale and fill. [inferred]
// FUN_0021B330
void btlGaugeDrawSegment(s32 task, u8 *gauge, f32 x, f32 y, f32 fill)
{
    extern f32 fGpffff849c;
    u8 *context;
    s32 value;
    f32 amount;

    context = (u8 *)kwlnTaskGetWork((void *)task);
    if (((BtlGaugeReveal *)gauge)->active != 0) {
        value = *(s32 *)gauge;
        *(s32 *)gauge = value + 1;
        amount = (f32)(value + 1) / 4.0f;
        if (amount > 1.0f) {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (amount != 0.0f) {
        y = (1.0f - amount) * 5.5f + y + 0.0f;
        btlUiSetScale(context, 1.0f, amount);
        btlUiDrawSpriteFaded(context, 10, 0, x, y, 0x19, 0x19, 0x19, 0xFF);
        if (!(fill <= fGpffff849c)) {
            btlUiSetScale(context, fill, amount);
            btlUiDrawSpriteFaded(context, 10, 1,
                          (1.0f - fill) * 5.0f + x + 0.0f,
                          y, 0xFF, 0xFF, 0x51, 0xFF);
        }
        btlUiSetScale(context, 1.0f, 1.0f);
    }
}

// Intent: store a gauge quad's position, depth, colour and texture coordinates. [inferred]
// FUN_0021B500
static void btlGaugeSetStyle(u8 *vertex, f32 x, f32 y, f32 depth,
                   f32 u, f32 v, f32 reciprocalDepth, s32 packedColor)
{
    union {
        s32 word;
        u8 bytes[4];
    } color;

    color.word = packedColor;
    ((BtlShuffleSkyVertex *)vertex)->u.els.scrVertex.x = x;
    ((BtlShuffleSkyVertex *)vertex)->u.els.scrVertex.y = y;
    ((BtlShuffleSkyVertex *)vertex)->u.els.scrVertex.z = depth;
    ((BtlShuffleSkyVertex *)vertex)->u.els.color.r = (f32)(u32)color.bytes[0];
    ((BtlShuffleSkyVertex *)vertex)->u.els.color.g = (f32)(u32)color.bytes[1];
    ((BtlShuffleSkyVertex *)vertex)->u.els.color.b = (f32)(u32)color.bytes[2];
    ((BtlShuffleSkyVertex *)vertex)->u.els.color.a = (f32)(u32)color.bytes[3];
    ((BtlShuffleSkyVertex *)vertex)->u.els.u = u;
    ((BtlShuffleSkyVertex *)vertex)->u.els.v = v;
    ((BtlShuffleSkyVertex *)vertex)->u.els.recipZ = reciprocalDepth;
}

typedef struct {
    f32 x, y, z;
    f32 padding0;
    f32 u, v;
    f32 scale;
    f32 padding1;
    f32 color[4];
    u32 padding2[4];
} PanelQuad;

/* One four-vertex strip. The union preserves the packed RGBA bits through
 * the retail float-local spill; channel values are stored as floats.
 * Nine float formals precede the color union to preserve caller scheduling. */
// Intent: draw one textured four-vertex strip at a panel position. [inferred]
// FUN_0021B630
/* RwCamera.nearPlane supplies reciprocal depth for the four sky vertices. */
void btlPanelDrawQuad(f32 x, f32 y, f32 depth, f32 width,
                   f32 height, f32 u0, f32 v0, f32 u1,
                   f32 v1, union ColorWord packedColor)
{
    extern f32 D_008872F8[];
    extern s32 (*D_00887310[])(s32, void *, s32);
    extern s32 kwlnGetCamera(void);
    f32 color;
    PanelQuad quads[4];
    union {
        s32 word;
        f32 value;
        u8 bytes[4];
    } upperLeftColor, upperRightColor, lowerLeftColor, lowerRightColor;
    u8 *p;
    f32 zval;
    f32 scale;

    zval = D_008872F8[0] - depth;
    scale = 1.0f / ((RwCamera *)(kwlnGetCamera()))->nearPlane;
    u0 = u0 / 256.0f;
    v0 = v0 / 256.0f;
    u1 = u1 / 256.0f;
    v1 = v1 / 256.0f;
    color = packedColor.value;
    upperLeftColor.value = color;
    p = (u8 *)&quads[0];
    ((PanelQuad *)p)->x = x;
    ((PanelQuad *)p)->y = y;
    ((PanelQuad *)p)->z = zval;
    ((PanelQuad *)p)->color[0] = (f32)(u32)upperLeftColor.bytes[0];
    ((PanelQuad *)p)->color[1] = (f32)(u32)upperLeftColor.bytes[1];
    ((PanelQuad *)p)->color[2] = (f32)(u32)upperLeftColor.bytes[2];
    ((PanelQuad *)p)->color[3] = (f32)(u32)upperLeftColor.bytes[3];
    ((PanelQuad *)p)->u = u0;
    ((PanelQuad *)p)->v = v0;
    ((PanelQuad *)p)->scale = scale;
    upperRightColor.value = color;
    p = (u8 *)&quads[1];
    ((PanelQuad *)p)->x = x + width;
    ((PanelQuad *)p)->y = y;
    ((PanelQuad *)p)->z = zval;
    ((PanelQuad *)p)->color[0] = (f32)(u32)upperRightColor.bytes[0];
    ((PanelQuad *)p)->color[1] = (f32)(u32)upperRightColor.bytes[1];
    ((PanelQuad *)p)->color[2] = (f32)(u32)upperRightColor.bytes[2];
    ((PanelQuad *)p)->color[3] = (f32)(u32)upperRightColor.bytes[3];
    ((PanelQuad *)p)->u = u1;
    ((PanelQuad *)p)->v = v0;
    ((PanelQuad *)p)->scale = scale;
    lowerLeftColor.value = color;
    p = (u8 *)&quads[2];
    ((PanelQuad *)p)->x = x;
    ((PanelQuad *)p)->y = y + height;
    ((PanelQuad *)p)->z = zval;
    ((PanelQuad *)p)->color[0] = (f32)(u32)lowerLeftColor.bytes[0];
    ((PanelQuad *)p)->color[1] = (f32)(u32)lowerLeftColor.bytes[1];
    ((PanelQuad *)p)->color[2] = (f32)(u32)lowerLeftColor.bytes[2];
    ((PanelQuad *)p)->color[3] = (f32)(u32)lowerLeftColor.bytes[3];
    ((PanelQuad *)p)->u = u0;
    ((PanelQuad *)p)->v = v1;
    ((PanelQuad *)p)->scale = scale;
    lowerRightColor.value = color;
    p = (u8 *)&quads[3];
    ((PanelQuad *)p)->x = x + width;
    ((PanelQuad *)p)->y = y + height;
    ((PanelQuad *)p)->z = zval;
    ((PanelQuad *)p)->color[0] = (f32)(u32)lowerRightColor.bytes[0];
    ((PanelQuad *)p)->color[1] = (f32)(u32)lowerRightColor.bytes[1];
    ((PanelQuad *)p)->color[2] = (f32)(u32)lowerRightColor.bytes[2];
    ((PanelQuad *)p)->color[3] = (f32)(u32)lowerRightColor.bytes[3];
    ((PanelQuad *)p)->u = u1;
    ((PanelQuad *)p)->v = v1;
    ((PanelQuad *)p)->scale = scale;
    D_00887310[0](4, &quads[0], 4);
}

// Intent: draw the sky pulse effect for one frame index. [inferred]
// FUN_0021BBB0
void btlEffectDrawSkyPulse(s32 packedColor, u16 frame)
{
    extern BtlShuffleRenderStateSet D_00887300[];
    extern void RpSkyRenderStateSet(s32 packedColor, s32 frame);
    extern void effMiscDrawScreenColor(u8 *colors, s32 enabled);
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern f32 fGpffff84a4;
    extern f32 fGpffff84cc;
    union {
        f32 value;
        u8 bytes[4];
    } color;
    union {
        f32 f;
        s32 i;
    } color_value;
    union {
        f32 f;
        s32 i;
    } arg_color_copy;
    union {
        Vec2f v;
        struct {
            s32 low;
            s32 high;
        } raw;
    } coords;
    f32 scale;

    coords.raw.low = 0x43A00000;
    coords.raw.high = 0x43640000;
    D_00887300[0](rwRENDERSTATETEXTURERASTER, 0);
    frame = frame & 0xFFFF;
    if ((frame >= 0x21) && (frame < 0x30)) {
        color.bytes[0] = 0;
        color.bytes[1] = 0;
        color.bytes[2] = 0;
        scale = 400.0f *
                (1.0f - cosf(
                    fGpffff84a4 * ((f32)(frame - 0x21) / 15.0f)));
        mdlEffectEmitMaskedTagPair();
        RpSkyRenderStateSet(3, 0x31801);
        color.bytes[3] = 0;
        effMiscDrawScreenColor(color.bytes, 0);
        color.bytes[3] = 0xFF;
        color_value.f = color.value;
        shdDrawRadialFan(coords.v, 0.0f,
                      color_value.i, color_value.i,
                      scale, 0.0f, 0x24, fGpffff84cc, 1.0f, 0);
        mdlEffectEmitTagPair();
        RpSkyRenderStateSet(3, 0x37801);
    }
    if (frame >= 3) {
        if (frame < 0x21) {
            RpSkyRenderStateSet(2, 0x48);
            scale = 400.0f *
                    sinf(
                        fGpffff84a4 * ((f32)(frame - 3) / 30.0f));
            arg_color_copy.f = *(f32 *)&packedColor;
            shdDrawRadialFan(coords.v, 0.0f,
                          arg_color_copy.i, arg_color_copy.i,
                          scale, 0.0f, 0x24, fGpffff84cc, 1.0f, 0);
            RpSkyRenderStateSet(2, 0x44);
        } else if (frame < 0x30) {
            RpSkyRenderStateSet(2, 0x48);
            effMiscDrawScreenColor((u8 *)&packedColor, 0);
            RpSkyRenderStateSet(2, 0x44);
        }
    }
}

// Intent: initialise an effect block with its frame and its state. [inferred]
// FUN_0021BE10
void btlEffectInit(u8 *effect, s32 value)
{
    typedef struct BtlEffectState { s32 unk00; s16 state; u16 unk06; s32 value; } BtlEffectState;
    memset(effect, 0, 0xC);
    ((BtlEffectState *)effect)->value = value;
    ((BtlEffectState *)effect)->state = 1;
}

// FUN_0021BE60
s32 btlAdvantageGetRaster(void)
{
    return iGpffffb470;
}

/* Advantage-component initialization hook called by btlUiTaskInit; retail deliberately leaves its state untouched. */
// FUN_0021BE70
void btlAdvantageInitNoop(void)
{
}

/* Advantage-panel geometry uses complete tile, anchor and sky-vertex objects.
 * The final selector owns both random samples and returns the selected bits.
 * See docs/probe_archive/Battle_advantage_0021be80_20260922.md. */
/* Platform render-state domain from rw/sky2/rwcore.h. */
enum RpSkyRenderState {
    rpSKYRENDERSTATENARENDERSTATE = 0,
    rpSKYRENDERSTATEDITHER,
    rpSKYRENDERSTATEALPHA_1,
    rpSKYRENDERSTATEATEST_1,
    rpSKYRENDERSTATEFARFOGPLANE,
    rpSKYRENDERSTATEMAXMIPLEVELS,
    rpSKYRENDERSTATEFORCEENUMSIZEINT = 0x7FFFFFFF
};

typedef struct { f32 x, y, width, height, u, v; } BtlAdvantageTile;

extern BtlAdvantageTile D_00628FD0[];
typedef struct { Vec2f position[2]; } BtlAdvantageAnchors;

extern BtlAdvantageAnchors D_006290B0[];
extern u8 D_00629090[];
extern f32 fGpffff84cc;
extern f32 D_008872F8[];
extern BtlShuffleRenderPrimitive D_00887310[];
extern void kAssertFail(void *file, s32 line);
extern s32 kwlnGetCamera(void);
/* Draw the selected advantage tile using its stored position and texture rectangle. */
static inline void btlAdvantageTile(s32 index, union ColorWord color)
{
    BtlAdvantageTile *tile = &D_00628FD0[index];
    btlPanelDrawQuad(tile->x, tile->y, 0.0f, tile->width, tile->height,
        tile->u, tile->v, tile->u + tile->width, tile->v + tile->height, color);
}

/* Draw the mirrored advantage tile with signed horizontal and vertical scaling. */
static inline void btlAdvantageMirror(f32 horizontal, f32 vertical,
    union ColorWord color)
{
    BtlAdvantageTile *tile = &D_00628FD0[4];
    btlPanelDrawQuad(tile->x, tile->y, 0.0f,
        fGpffff84cc * (horizontal * tile->width), vertical * tile->height,
        tile->u + tile->width, tile->v + tile->height, tile->u, tile->v, color);
}

/* Draw the dark advantage background and its four mirrored decorations. */
static inline void btlAdvantageBackground(void)
{
    union ColorWord color;
    color.bytes[0] = 0x14;
    color.bytes[1] = 0x14;
    color.bytes[2] = 0x14;
    color.bytes[3] = 0xFF;
    btlAdvantageTile(0, color);
    btlAdvantageTile(1, color);
    btlAdvantageMirror(-1.0f, -1.0f, color);
    btlAdvantageMirror(1.0f, -1.0f, color);
    btlAdvantageMirror(-1.0f, 1.0f, color);
    btlAdvantageMirror(1.0f, 1.0f, color);
}

/* Draw one checked advantage segment using the corresponding mirrored anchor. */
static inline void btlAdvantageSegment(s32 index, union ColorWord color)
{
    BtlAdvantageAnchors anchors;
    s32 group, side, tileIndex, signX, signY;
    f32 x, y, width, height, u0, v0;
    f32 relativeX, relativeY, horizontalScale, verticalCenter;
    BtlAdvantageTile *tile;

    anchors = D_006290B0[0];
    if (index < 0 || index >= 12) {
        kAssertFail(D_00629090, 198);
    }
    group = index / 6;
    side = (index / 3 + group) & 1;
    if (index % 6 < 3) {
        tileIndex = index % 3;
    } else {
        tileIndex = ~(index % 3) + 3;
    }
    tile = &D_00628FD0[tileIndex + 5];
    signX = (side == 0) ? 1 : -1;
    signY = (group == 0) ? 1 : -1;
    height = tile->height;
    v0 = tile->v;
    width = tile->width;
    u0 = tile->u;
    relativeX = (anchors.position[side].x - (f32)319) + (f32)signX * tile->x;
    horizontalScale = 1.05f;
    x = (f32)319 - horizontalScale * relativeX;
    verticalCenter = 228.5f;
    relativeY = (anchors.position[group].y - verticalCenter) + (f32)signY * tile->y;
    y = verticalCenter - relativeY;
    btlPanelDrawQuad(x, y, 0.0f, horizontalScale * ((f32)-signX * width),
        (f32)-signY * height, u0, v0, u0 + width, v0 + height, color);
}

/* Build a textured screen quad and submit it as a triangle strip. */
static inline void btlAdvantageBuildQuad(f32 x, f32 y, f32 z,
    f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
    union ColorWord color)
{
    BtlShuffleSkyVertex vertices[4];
    s32 count = 0;
    f32 depth = D_008872F8[0] - z;
    /* Reciprocal depth uses the shared native camera near-plane field. */
    f32 reciprocalZ = 1.0f / ((RwCamera *)(kwlnGetCamera()))->nearPlane;
    u0 /= 256.0f;
    v0 /= 256.0f;
    u1 /= 256.0f;
    v1 /= 256.0f;
    btlGaugeSetStyle((u8 *)&vertices[count++], x, y, depth, u0, v0, reciprocalZ, color.word);
    btlGaugeSetStyle((u8 *)&vertices[count++], x + width, y, depth, u1, v0, reciprocalZ, color.word);
    btlGaugeSetStyle((u8 *)&vertices[count++], x, y + height, depth, u0, v1, reciprocalZ, color.word);
    btlGaugeSetStyle((u8 *)&vertices[count++], x + width, y + height, depth, u1, v1, reciprocalZ, color.word);
    if (count > 4) {
        kAssertFail(D_00629090, 122);
    }
    D_00887310[0](rwPRIMTYPETRISTRIP, vertices, count);
}

/* Advance the random stream once for the alternating pattern's phase and
   once for the selected segments. The caller owns the halfword result. */
/* Choose alternating segment eligibility and selection using successive random values. */
static inline u16 btlAdvantageChooseSegments(void)
{
    extern u32 RpRandom(void);
    s32 eligible = 0xAAAAA >>
        (s32)(2.0f * ((f32)RpRandom() / 2147483648.0f));
    u32 selected = RpRandom();
    return selected & eligible;
}

// Intent: draw the advantage panel's background, segments and random pattern. [inferred]
/* Access-site fields and allocation-bound aliases retain the measured byte-pointer interface. */
// FUN_0021BE80

void btlAdvantageDrawPanel(u8 *drawPayload, s32 workAddress, void *callback)
{
    BtlAdvantageState *advantageState;
    BtlAdvantageState *advantageWork;
    extern BtlShuffleRenderStateSet D_00887300[];
    extern u32 RpRandom(void);
    extern s32 RpSkyRenderStateSet(enum RpSkyRenderState state, void *value);
    union ColorWord color;
    u8 *work;
    s32 index;
    s32 bit;

    (void)drawPayload;
    (void)callback;
    work = (u8 *)(u32)workAddress;
    advantageWork = (BtlAdvantageState *)work;
    kwlnTaskGetWork(((BtlAdvantageState *)(work))->task);
    btlUiSetRenderStates();
    if (*(u16 *)work & 1) {
        if (((BtlAdvantageState *)(work))->frame < 48) {
            if (((BtlBattleState *)(iGpffffb3ac))->openingSide == 1) {
                if (((BtlAdvantageState *)(work))->frame == 4) {
                    sdkSndStartStream(1, 14, 2, 0);
                }
                color.bytes[0] = 0x2D;
                color.bytes[1] = 0x9F;
                color.bytes[2] = 0xFF;
                color.bytes[3] = 0xFF;
                btlEffectDrawSkyPulse(color.word, advantageWork->frame);
                D_00887300[0](rwRENDERSTATETEXTURERASTER, (void *)iGpffffb470);
                btlAdvantageBackground();
                RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void *)0x48);
                color.bytes[0] = 0x6B;
                color.bytes[1] = 0x9E;
                color.bytes[2] = 0xFF;
                color.bytes[3] = 0xFF;
                index = ((BtlAdvantageState *)(work))->segments;
                btlAdvantageSegment(index, color);
                btlAdvantageSegment(index + 6, color);
                index = (advantageWork->segments + 1) % 6;
                btlAdvantageSegment(index, color);
                btlAdvantageSegment(index + 6, color);
                RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void *)0x44);
                color.bytes[0] = 0x14;
                color.bytes[1] = 0x14;
                color.bytes[2] = 0x14;
                color.bytes[3] = 0xFF;
                {
                    BtlAdvantageTile *tile = &D_00628FD0[2];
                    btlAdvantageBuildQuad(tile->x, tile->y, 0.0f, tile->width, tile->height,
                        tile->u, tile->v, tile->u + tile->width, tile->v + tile->height, color);
                }
                advantageState = (BtlAdvantageState *)(work);
                if (++advantageWork->segments >= 6) {
                    advantageState->segments = 0;
                }

            } else {
                if (((BtlAdvantageState *)(work))->frame == 4) {
                    sdkSndStartStream(1, 14, 2, 1);
                }
                color.bytes[0] = 0xFF;
                color.bytes[1] = 0x24;
                color.bytes[2] = 0x23;
                color.bytes[3] = 0xFF;
                advantageState = (BtlAdvantageState *)(work);
                btlEffectDrawSkyPulse(color.word, advantageState->frame);
                D_00887300[0](rwRENDERSTATETEXTURERASTER, (void *)iGpffffb470);
                btlAdvantageBackground();
                RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void *)0x48);
                color.bytes[0] = 0xFF;
                color.bytes[1] = 0x27;
                color.bytes[2] = 0x27;
                color.bytes[3] = 0xFF;
                for (index = 0; index < 12; ++index) {
                    bit = 1 << index;
                    if (bit & 0xC61) {
                        if ((s32)(4.0f * ((f32)RpRandom() / 2147483648.0f)) == 0) {
                            btlAdvantageSegment(index, color);
                        }
                    }
                    if (((BtlAdvantageState *)(work))->segments & bit) {
                        btlAdvantageSegment(index, color);
                    }
                }
                RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void *)0x44);
                color.bytes[0] = 0x14;
                color.bytes[1] = 0x14;
                color.bytes[2] = 0x14;
                color.bytes[3] = 0xFF;
                {
                    BtlAdvantageTile *tile = &D_00628FD0[3];
                    btlAdvantageBuildQuad(tile->x, tile->y, 0.0f, tile->width, tile->height,
                        tile->u, tile->v, tile->u + tile->width, tile->v + tile->height, color);
                }
                advantageState = (BtlAdvantageState *)(work);
                if (advantageState->frame % 2 == 0) {
                    ((BtlAdvantageState *)(work))->segments = btlAdvantageChooseSegments();
                }
            }
            advantageState = (BtlAdvantageState *)(work);
            ++advantageState->frame;
        } else {
            *(u16 *)work &= (u16)~1;
        }
    }
}

// Intent: start a shuffle task and mark it ready. [inferred]
/* The owning battle UI task stores the advantage ready flag and frame counter in this component. */
// FUN_0021D440
void btlShuffleStart(s32 task)
{
    u8 *p;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlAdvantageState *)(((BtlUiTaskWork *)(p))->advantage))->frame = 0;
    ((BtlAdvantageState *)(((BtlUiTaskWork *)(p))->advantage))->flags = ((BtlAdvantageState *)(((BtlUiTaskWork *)(p))->advantage))->flags | 1;
}

// Intent: report whether the shuffle task is not ready. [inferred]
/* Read the advantage ready flag written by btlShuffleStart in the owning battle UI task. */
// FUN_0021D470
s32 btlShuffleIsIdle(s32 task)
{
    s32 flag;

    flag = (((BtlAdvantageState *)(((BtlUiTaskWork *)((u8 *)kwlnTaskGetWork((void *)task)))->advantage))->flags & 1) != 0;
    return flag ^ 1;
}

// Intent: advance the shuffle task state machine. [inferred]
/* Access-site fields and allocation-bound aliases retain the measured byte-pointer interface. */
// FUN_0021D4A0

s32 btlShuffleUpdateTask(u8 *sdkTaskBytes)
{
    BtlResultWork *resultState;
    BtlResultWork *resultWork;
    s32 task = (s32)sdkTaskBytes;
    extern s32 btlShuffleTaskIsCancelRequested(s32 task);
    extern s32 btlShuffleTaskIsCancelRequestedFor(KwlnTask *task);
    extern void btlShuffleTaskSetBusy(s32 task);
    extern void btlXpPrepareAwards(u8 *awards, u8 *reward);
    extern s32 btlResultSimpleSetDoneFlag(s32 task);
    extern s32 btlShuffleTaskIsBusy(s32 task);
    extern void btlShuffleTaskResetPhase(s32 task);
    extern s32 btlResultSimpleIsDone(s32 task);
    extern void btlResultSimpleOnConfirm(s32 task);
    extern s32 btlLogoTitleCreate(s32 parent);
    extern s32 btlResultOverlayCreate(s32 parent);
    extern s32 btlResultSummaryCreate(s32 parent);
    extern s32 btlLogoTitleIsReady(KwlnTask *task);
    extern void btlLogoTitleAdvance(KwlnTask *task);
    extern s32 btlResultOverlayIsReady(KwlnTask *task);
    extern void btlResultOverlayStart(KwlnTask *task);
    extern s32 btlResultSummaryIsReady(KwlnTask *task);
    extern void btlResultSummaryStart(KwlnTask *task);
    extern s32 btlShuffleFindTask(void);
    extern s32 btlLogoTaskExists(void);
    extern s32 btlLogoTitleExists(void);
    extern s32 btlResultOverlayExists(void);
    extern s32 btlResultSummaryExists(void);
    u8 *work;
    s32 flags;
    s32 ready;

    work = (u8 *)kwlnTaskGetWork((void *)task);
    resultWork = (BtlResultWork *)work;
    switch (((BtlResultWork *)(work))->phase) {
    case 1:
        resultWork->phase = 2;
        break;
    case 2:
        flags = *(s32 *)work;
        if ((flags & 1) == 0 || (flags & 4) == 0) {
            if ((flags & 2) != 0) {
                ready = 1;
                if ((((BtlResultWork *)(work))->awardFlags & 1) != 0 &&
                    btlShuffleTaskIsCancelRequested(((BtlResultWork *)(work))->shuffleTask) != 0) {
                    ready = 0;
                }
                if (btlShuffleTaskIsCancelRequestedFor((KwlnTask *)((BtlResultWork *)(work))->resultTask) != 0) {
                    ready = 0;
                }
                if (ready != 0) {
                    flags = *(s32 *)work;
                    flags &= ~2;
                    *(s32 *)work = flags;
                    flags |= 4;
                    *(s32 *)work = flags;
                }
            }
            break;
        }
    case 3:
        flags = ((BtlResultWork *)(work))->awardFlags;
        if ((flags & 1) != 0) {
            btlShuffleTaskSetBusy(((BtlResultWork *)(work))->shuffleTask);
            resultWork->phase = 4;
        } else {
            btlXpPrepareAwards(work + 0x60, work + 8);
            btlResultSimpleSetDoneFlag(((BtlResultWork *)(work))->resultTask);
            resultWork->phase = 5;
        }
        break;
    case 4:
        if (btlShuffleTaskIsBusy(((BtlResultWork *)(work))->shuffleTask) == 0) {
            btlShuffleTaskResetPhase(resultWork->shuffleTask);
            resultWork->shuffleTask = 0;
            btlXpPrepareAwards(work + 0x60, work + 8);
            btlResultSimpleSetDoneFlag(((BtlResultWork *)(work))->resultTask);
            resultWork->phase = 5;
        }
        break;
    case 5:
        if (btlResultSimpleIsDone(((BtlResultWork *)(work))->resultTask) == 0) {
            btlResultSimpleOnConfirm(resultWork->resultTask);
            resultWork->resultTask = 0;
            flags = ((BtlResultWork *)(work))->awardFlags;
            if ((flags & 2) != 0) {
                btlXpApplyAwards(work + 0x60, work + 8);
                ((BtlResultWork *)(work))->titleTask = btlLogoTitleCreate(task);
                resultWork->phase = 6;
            } else if ((flags & 8) != 0) {
                btlXpApplyAwards(work + 0x60, work + 8);
                ((BtlResultWork *)(work))->overlayTask = btlResultOverlayCreate(task);
                resultWork->phase = 7;
            } else if ((flags & 0x10) != 0) {
                btlXpApplyAwards(work + 0x60, work + 8);
                btlXpAddRosterExp(work + 0x60);
                ((BtlResultWork *)(work))->summaryTask = btlResultSummaryCreate(task);
                resultWork->phase = 8;
            } else {
                btlXpApplyAwards(work + 0x60, work + 8);
                btlXpAddRosterExp(work + 0x60);
                btlXpAddPartyExp((s32)(work + 0x60));
                resultWork->phase = 9;
            }
        }
        break;
    case 6:
        if (btlLogoTitleIsReady((KwlnTask *)((BtlResultWork *)(work))->titleTask) == 0) {
            btlLogoTitleAdvance((KwlnTask *)resultWork->titleTask);
            resultWork->titleTask = 0;
            flags = ((BtlResultWork *)(work))->awardFlags;
            if ((flags & 8) != 0) {
                ((BtlResultWork *)(work))->overlayTask = btlResultOverlayCreate(task);
                resultWork->phase = 7;
            } else if ((flags & 0x10) != 0) {
                btlXpAddRosterExp(work + 0x60);
                ((BtlResultWork *)(work))->summaryTask = btlResultSummaryCreate(task);
                resultWork->phase = 8;
            } else {
                btlXpAddRosterExp(work + 0x60);
                btlXpAddPartyExp((s32)(work + 0x60));
                resultWork->phase = 9;
            }
        }
        break;
    case 7:
        if (btlResultOverlayIsReady((KwlnTask *)((BtlResultWork *)(work))->overlayTask) == 0) {
            btlResultOverlayStart((KwlnTask *)resultWork->overlayTask);
            resultWork->overlayTask = 0;
            flags = ((BtlResultWork *)(work))->awardFlags;
            if ((flags & 0x10) != 0) {
                ((BtlResultWork *)(work))->summaryTask = btlResultSummaryCreate(task);
                resultWork->phase = 8;
            } else {
            btlXpAddPartyExp((s32)(work + 0x60));
                resultWork->phase = 9;
            }
        }
        break;
    case 8:
        if (btlResultSummaryIsReady((KwlnTask *)((BtlResultWork *)(work))->summaryTask) == 0) {
            btlResultSummaryStart((KwlnTask *)resultWork->summaryTask);
            resultWork->summaryTask = 0;
            resultWork->phase = 9;
        }
        break;
    case 9:
        resultState = (BtlResultWork *)(work);
        if (btlShuffleFindTask() == 0 &&
            btlLogoTaskExists() == 0 &&
            btlLogoTitleExists() == 0 &&
            btlResultOverlayExists() == 0 &&
            btlResultSummaryExists() == 0) {
            resultState->phase = 0;
        }
        break;
    }
    return 0;
}

// Intent: release a shuffle task and its load handle. [inferred]
// FUN_0021D920
void btlShuffleDestroyTask(u8 *sdkTaskBytes)
{
    s32 task = (s32)sdkTaskBytes;
    u8 *p;
    s32 value;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    value = ((BtlResultWork *)p)->file;
    if (value != 0) {
        H_Cdvd_Destroy((u8 *)value);
    }
    jtbl_008873EC[0](p);
}

// Intent: create a shuffle task with its child task and state. [inferred]
// FUN_0021D980
s32 btlShuffleCreate(s32 parentTask, u16 *parameters)
{
    u8 *work;
    s32 result;

    chkmemAllocSiteTag(&D_006290D0, 0x3A);
    work = (u8 *)jtbl_008873E8[0](0x94C, 0x40000);
    memset(work, 0, 0x94C);
    result = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(&D_006290C0), 0xF, 0, 0, btlShuffleUpdateTask, btlShuffleDestroyTask, (u8 *)(work));
    memcpy(work + 8, parameters, 0x58);
    if ((*parameters & 1) != 0) {
        ((BtlResultWork *)work)->awardFlags |= 1;
    }
    ((BtlResultWork *)work)->phase = 1;
    if ((((BtlResultWork *)work)->awardFlags & 1) != 0) {
        ((BtlResultWork *)work)->shuffleTask = btlShuffleTaskCreate(result, work + 0x48);
    }
    ((BtlResultWork *)work)->resultTask = btlResultSimpleCreateTask(result);
    return result;
}

// Intent: cancel a shuffle task and its children. [inferred]
// FUN_0021DAB0
void btlShuffleCancel(s32 task)
{
    u8 *p;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    if ((((BtlResultWork *)p)->awardFlags & 1) != 0) {
        btlShuffleTaskRequestCancel(((BtlResultWork *)p)->shuffleTask);
    }
    btlResultSimpleSetupEntries(((BtlResultWork *)p)->resultTask);
    *(s32 *)p |= 2;
}

// Intent: report whether a shuffle task was canceled. [inferred]
// FUN_0021DB10
s32 btlShuffleIsCanceled(s32 task)
{
    return (*(s32 *)kwlnTaskGetWork((void *)task) & 2) != 0;
}

// Intent: report whether a shuffle task still has an active child. [inferred]
// FUN_0021DB40
s32 btlShuffleIsBusy(s32 task)
{
    u8 *p;
    s32 temp;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    if (((BtlResultWork *)p)->shuffleTask != 0) {
        return 0;
    }
    temp = ((BtlResultWork *)p)->resultTask;
    if (temp != 0) {
        return btlShuffleTaskIsLoading((KwlnTask *)temp);
    }
    return 0;
}

// Intent: advance a shuffle task's frame counter and return -1 when done. [inferred]
// FUN_0021DBA0
s32 btlShuffleTickFrame(u8 *sdkTaskBytes)
{
    typedef struct BtlSweepWork { s32 frame; s32 next; s32 previous; } BtlSweepWork;
    s32 task = (s32)sdkTaskBytes;
    u8 *p;
    s32 value;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlSweepWork *)p)->next = 0;
    ((BtlSweepWork *)p)->previous = 0;
    PrimAppendNode(&D_00796340, p + 4);
    value = ((BtlSweepWork *)p)->frame + 1;
    ((BtlSweepWork *)p)->frame = value;
    if (value == 0xC) {
        fadeBeginTransition(1, 1);
        goto exit;
    }
    if (value <= 0xC) {
        goto exit;
    }
    if (fadeStatus() != 0) {
        return -1;
    }
exit:
    return 0;
}

// Intent: draw the shuffle sweep quad for the current frame. [inferred]
// FUN_0021DC50
void btlShuffleDrawSweep(s32 unusedTask, s32 *frameState)
{
    f32 progress;
    f32 directionY;
    f32 travelY;
    Vec2f position;
    f32 unusedValue;

    btlUiSetRenderStates();
    progress = (f32)frameState[0] / 12.0f;
    if (!(progress <= 1.0f)) {
        progress = 1.0f;
    }
    position.x = 0.0f;
    position.y = -500.0f;
    position.x = position.x + progress * (800.0f * sinf(fGpffff837c));
    directionY = cosf(fGpffff837c);
    travelY = 800.0f * directionY;
    position.y = position.y + progress * travelY;
    shdDrawRotatedRect(position, 0.0f, 0xFF,
                  1500.0f, 1000.0f, fGpffff8378, 0);
}
