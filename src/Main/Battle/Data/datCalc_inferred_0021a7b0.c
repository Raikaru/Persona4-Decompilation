/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/btlAction.c; members 0021a7b0-0021dc50 */

#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "datPersona_internal.h"
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
extern void H_Cdvd_Destroy(u8 *arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_006290C0[];
extern u8 D_006290D0[];
extern void chkmemAllocSiteTag(const void *arg0, s32 arg1);
extern void memcpy(void *dst, void *src, u32 size);
extern s32 btlShuffleTaskCreate(s32 arg0, void *arg1);
extern s32 btlResultSimpleCreateTask(s32 arg0);
extern void PrimAppendNode(void *arg0, void *arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 fadeStatus(void);
extern u8 D_00796340[];
extern s32 btlShuffleUpdateTask(u8 *task);
extern void (*jtbl_008873EC[])(void *);
extern void btlGaugeSetActive();
extern s32 btlShuffleTaskIsLoading(KwlnTask *task);
extern void btlShuffleTaskRequestCancel(s32 arg0);
extern void btlResultSimpleSetupEntries(s32 arg0);
extern void btlShuffleDrawSweep(s32 arg0, s32 *arg1);
extern void btlUiSetScale(void *arg0, f32 arg1, f32 arg2);
extern void btlGaugeDrawSegment(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2);
extern s32 datCalcMaxHp(s32 arg0);
extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern f32 fGpffff8498;
extern s32 btlShuffleTickFrame(u8 *task);
extern void btlXpPrepareAwards(u8 *arg0, u8 *arg1);
extern void btlXpApplyAwards(u8 *arg0, u8 *arg1);
extern void btlXpAddRosterExp(u8 *arg0);
extern void btlXpAddPartyExp(s32 arg0);
static inline f32 ws14_add(f32 left, f32 right)
{
    return left + right;
}

union ColorWord {
    s32 word;
    f32 value;
    u8 bytes[4];
};

// Intent: draw a panel flourish with sky vertices and its fade. [inferred]
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
    extern void btlUiSetOrigin(u8 *task, f32 fparg0, f32 fparg1);

    renderWork = (s32 *)kwlnTaskGetWork(*(void **)(state + 0x10));
    if ((*renderWork & 1) == 0) {
        return;
    }
    flags = *(u16 *)(state + 0);
    if (flags & 1) {
        if (!(flags & 2)) {
            *(u16 *)(state + 4) += 1;
            if (*(u16 *)(state + 4) == 0x0E) {
                *(u16 *)(state + 0) |= 2;
            }
        }
        tick = *(u16 *)(state + 4);
        btlUiSetRenderStates();
        {
            f32 depth = 0.0f;
            btlUiSetOrigin((u8 *)renderWork, depth, depth);
        }
        if (*(u16 *)(state + 0) & 4) {
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
            reciprocalDepth = 1.0f / *(f32 *)((u8 *)(u32)kwlnGetCamera() + 0x80);
            sourceIndices = D_00628FA0;
            outputIndices = indexBytes;
            pairsLeft = 6;
            do {
                firstIndex = *(s16 *)sourceIndices;
                secondIndex = *(s16 *)(sourceIndices + 2);
                sourceIndices += 4;
                pairsLeft -= 1;
                *(s16 *)outputIndices = (s16)firstIndex;
                *(s16 *)(outputIndices + 2) = (s16)secondIndex;
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
            vertex->u.els.scrVertex.x = ws14_add(originX, 241.0f);
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
                vertex->u.els.scrVertex.x = ws14_add(originX, 241.0f);
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
                farX = ws14_add(originX, (f32)0x15D);
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
void btlGaugeInit(u8 *arg0, u8 *arg1)
{
    *(f32 *)(arg1 + 0) = -1.0f;
    *(f32 *)(arg1 + 4) = 1.0f;
    *(s16 *)(arg1 + 0x10) = -1;
}

// Intent: clear a unit's gauge state. [inferred]
// FUN_0021AE80
void btlUnitGaugeClear(s32 arg0)
{
    btlGaugeSetActive(arg0 + 0xA3C);
}

// Intent: draw a unit's gauge with its HP fraction and fill. [inferred]
// FUN_0021AEB0
void btlGaugeDrawUnit(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, s32 arg2, f32 fparg2)
{
    f32 temp_f0;
    f32 var_f20;
    u16 *temp_4;
    u16 *temp_4_2;

    var_f20 = fparg2;
    if (arg2 != 0) {
        temp_4 = *(u16 **)(arg1 + 0xA64);
        if ((temp_4 != NULL) &&
            (datCalcIsDead((u8 *)temp_4, 0) == 0)) {
            temp_4_2 = *(u16 **)(arg1 + 0xA64);
            if ((*temp_4_2 & 0x20) != 0) {
                if ((datCalcGetHp((s32)temp_4_2) & 0xFFFF) <= 1) {
                    goto callback;
                }
            }
            if (!(var_f20 <= 0.0f)) {
                temp_f0 = fGpffff8498;
                if (var_f20 < temp_f0) {
                    var_f20 = temp_f0;
                }
            }
        }
callback:
        btlGaugeDrawSegment(arg0, arg1 + 0xA3C, fparg0, fparg1, var_f20);
    }
}

// Intent: refresh the HP ratio of each party gauge. [inferred]
// FUN_0021AFA0
void btlGaugeRefreshAll(void)
{
    u8 *p;
    u8 *work;
    u32 i;
s16 value0;
s16 value1;

    i = 0;
    goto outer_test;
outer_body:
    p = *(u8 **)(iGpffffb3ac + (i * 8) + 0x178);
    goto loop_test;
loop_body:
    if (*(u8 **)(p + 0xA64) != NULL) {
        work = p + 0xA28;
        if (*(s16 *)(p + 0xA38) >= 0 &&
            *(s16 *)(p + 0xA38) < 0xC) {
            value0 = (s16)datCalcGetHp(*(s32 *)(p + 0xA64));
            value1 = (s16)datCalcMaxHp(*(s32 *)(p + 0xA64));
            *(s16 *)(work + 0x10) = -1;
            *(f32 *)work = -1.0f;
            *(f32 *)(work + 4) = (f32)value0 / (f32)value1;
        }
    }
    p = *(u8 **)(p + 0xA6C);
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
// FUN_0021B0A0
f32 btlGaugeHpRatio(u8 *arg0)
{
    typedef struct DatUnit DatUnit;
    extern s32 datCalcGetHp(DatUnit *arg0);
    extern s32 datCalcMaxHp(DatUnit *arg0);
    f32 var_f20;
    f32 var_f0;
    u32 temp_2;
    u32 temp_2_2;

    if (*(s32 *)(arg0 + 0xA64) == 0) {
        return 0.0f;
    }
    temp_2 = (u32)datCalcMaxHp((DatUnit *)*(s32 *)(arg0 + 0xA64));
    var_f20 = (f32)temp_2;
    if (var_f20 == 0.0f) {
        return 0.0f;
    }
    temp_2_2 = (u32)datCalcGetHp((DatUnit *)*(s32 *)(arg0 + 0xA64));
    var_f0 = (f32)temp_2_2;
    return var_f0 / var_f20;
}

// Intent: initialise a gauge value and its counter. [inferred]
// FUN_0021B190
void btlGaugeInitValue(u8 *arg0, s32 arg1)
{
    memset(arg0, 0, 4);
    *(s32 *)arg0 = arg1;
}

// FUN_0021B1E0
void func_0021b1e0(void)
{
}

// Intent: step every unit's gauge animation toward its target. [inferred]
// FUN_0021B1F0
// measured: loop-invariant constant hoisting probe for func_0021b1f0.
#pragma opt_loop_invariants on
void btlGaugeStepAll(s32 arg0, s32 *arg1)
{
    f32 temp_f0;
    f32 temp_f3;
    s16 temp_3;
    u8 *var_7;
    u32 var_6;
    u8 *temp_5;

    if ((*(s32 *)kwlnTaskGetWork((void *)*arg1) & 1) != 0) {
        var_6 = 0;
        while (var_6 < 2U) {
            var_7 = *(u8 **)(iGpffffb3ac + var_6 * 8 + 0x178);
            while (var_7 != NULL) {
                if (*(s32 *)(var_7 + 0xA64) != 0) {
                    temp_5 = var_7 + 0xA28;
                    temp_f0 = *(f32 *)(var_7 + 0xA28);
                    if (!(temp_f0 < 0.0f)) {
                        *(f32 *)(temp_5 + 0xC) = temp_f0;
                        *(f32 *)(temp_5 + 8) = *(f32 *)(temp_5 + 4);
                        *(s32 *)temp_5 = (s32)0xBF800000;
                        *(s16 *)(temp_5 + 0x10) = 0;
                    }
                    temp_3 = *(s16 *)(temp_5 + 0x10);
                    if (temp_3 >= 0 && temp_3 < 0xD) {
                        if (temp_3 < 0xC) {
                            temp_f3 = *(f32 *)(temp_5 + 8);
                            temp_f0 = (f32)temp_3 / 12.0f;
                            *(f32 *)(temp_5 + 4) =
                                temp_f0 * (*(f32 *)(temp_5 + 0xC) -
                                           temp_f3) +
                                (0.0f + temp_f3);
                        } else {
                            *(f32 *)(temp_5 + 4) = *(f32 *)(temp_5 + 0xC);
                        }
                        *(s16 *)(temp_5 + 0x10) =
                            *(s16 *)(temp_5 + 0x10) + 1;
                    }
                }
                var_7 = *(u8 **)(var_7 + 0xA6C);
            }
            var_6 += 1;
        }
    }
}

#pragma push
#pragma opt_loop_invariants off
// Intent: set a gauge's active state. [inferred]
// FUN_0021B310
void btlGaugeSetActive(u8 *arg0, s32 arg1)
{
    if (arg1 != 0) {
        *(s32 *)(arg0 + 0) = 0;
    }
    *(s32 *)(arg0 + 4) = arg1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
/* object 452B; retail window 464B; normalized_diff 6; differing offsets 0x28, 0x30, 0xF8, 0x11C, 0x12C, 0x13C; best legal plain-C body; residual is saved FPU parameter-coloring and 12B tail padding. */
// Intent: draw one gauge segment with its scale and fill. [inferred]
// FUN_0021B330
void btlGaugeDrawSegment(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2)
{
    extern f32 fGpffff849c;
    u8 *context;
    s32 value;
    f32 amount;

    context = (u8 *)kwlnTaskGetWork((void *)arg0);
    if (*(s32 *)(arg1 + 4) != 0) {
        value = *(s32 *)arg1;
        *(s32 *)arg1 = value + 1;
        amount = (f32)(value + 1) / 4.0f;
        if (amount > 1.0f) {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (amount != 0.0f) {
        fparg1 = (1.0f - amount) * 5.5f + fparg1 + 0.0f;
        btlUiSetScale(context, 1.0f, amount);
        btlUiDrawSpriteFaded(context, 10, 0, fparg0, fparg1, 0x19, 0x19, 0x19, 0xFF);
        if (!(fparg2 <= fGpffff849c)) {
            btlUiSetScale(context, fparg2, amount);
            btlUiDrawSpriteFaded(context, 10, 1,
                          (1.0f - fparg2) * 5.0f + fparg0 + 0.0f,
                          fparg1, 0xFF, 0xFF, 0x51, 0xFF);
        }
        btlUiSetScale(context, 1.0f, 1.0f);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: store a gauge quad's position, depth, colour and texture coordinates. [inferred]
// FUN_0021B500
static void btlGaugeSetStyle(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                   f32 fparg3, f32 fparg4, f32 fparg5, s32 arg1)
{
    union {
        s32 word;
        u8 bytes[4];
    } spC;

    spC.word = arg1;
    *(f32 *)(arg0 + 0) = fparg0;
    *(f32 *)(arg0 + 4) = fparg1;
    *(f32 *)(arg0 + 8) = fparg2;
    *(f32 *)(arg0 + 0x20) = (f32)(u32)spC.bytes[0];
    *(f32 *)(arg0 + 0x24) = (f32)(u32)spC.bytes[1];
    *(f32 *)(arg0 + 0x28) = (f32)(u32)spC.bytes[2];
    *(f32 *)(arg0 + 0x2C) = (f32)(u32)spC.bytes[3];
    *(f32 *)(arg0 + 0x10) = fparg3;
    *(f32 *)(arg0 + 0x14) = fparg4;
    *(f32 *)(arg0 + 0x18) = fparg5;
}
#pragma pop

typedef struct {
    f32 x, y, z;
    f32 padding0;
    f32 u, v;
    f32 scale;
    f32 padding1;
    f32 color[4];
    u32 padding2[4];
} PanelQuad;

#pragma push
#pragma opt_loop_invariants off
/* One four-vertex strip. The union preserves the packed RGBA bits through
 * the retail float-local spill; channel values are stored as floats.
 * Nine float formals precede the color union to preserve caller scheduling. */
// Intent: draw one textured four-vertex strip at a panel position. [inferred]
// FUN_0021B630
void btlPanelDrawQuad(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7,
                   f32 fparg8, union ColorWord arg0)
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
    } spC, sp8, sp4, sp0;
    u8 *p;
    f32 zval;
    f32 scale;

    zval = D_008872F8[0] - fparg2;
    scale = 1.0f / *(f32 *)(kwlnGetCamera() + 0x80);
    fparg5 = fparg5 / 256.0f;
    fparg6 = fparg6 / 256.0f;
    fparg7 = fparg7 / 256.0f;
    fparg8 = fparg8 / 256.0f;
    color = arg0.value;
    spC.value = color;
    p = (u8 *)&quads[0];
    *(f32 *)(p + 0) = fparg0;
    *(f32 *)(p + 4) = fparg1;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x20) = (f32)(u32)spC.bytes[0];
    *(f32 *)(p + 0x24) = (f32)(u32)spC.bytes[1];
    *(f32 *)(p + 0x28) = (f32)(u32)spC.bytes[2];
    *(f32 *)(p + 0x2C) = (f32)(u32)spC.bytes[3];
    *(f32 *)(p + 0x10) = fparg5;
    *(f32 *)(p + 0x14) = fparg6;
    *(f32 *)(p + 0x18) = scale;
    sp8.value = color;
    p = (u8 *)&quads[1];
    *(f32 *)(p + 0) = fparg0 + fparg3;
    *(f32 *)(p + 4) = fparg1;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x20) = (f32)(u32)sp8.bytes[0];
    *(f32 *)(p + 0x24) = (f32)(u32)sp8.bytes[1];
    *(f32 *)(p + 0x28) = (f32)(u32)sp8.bytes[2];
    *(f32 *)(p + 0x2C) = (f32)(u32)sp8.bytes[3];
    *(f32 *)(p + 0x10) = fparg7;
    *(f32 *)(p + 0x14) = fparg6;
    *(f32 *)(p + 0x18) = scale;
    sp4.value = color;
    p = (u8 *)&quads[2];
    *(f32 *)(p + 0) = fparg0;
    *(f32 *)(p + 4) = fparg1 + fparg4;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x20) = (f32)(u32)sp4.bytes[0];
    *(f32 *)(p + 0x24) = (f32)(u32)sp4.bytes[1];
    *(f32 *)(p + 0x28) = (f32)(u32)sp4.bytes[2];
    *(f32 *)(p + 0x2C) = (f32)(u32)sp4.bytes[3];
    *(f32 *)(p + 0x10) = fparg5;
    *(f32 *)(p + 0x14) = fparg8;
    *(f32 *)(p + 0x18) = scale;
    sp0.value = color;
    p = (u8 *)&quads[3];
    *(f32 *)(p + 0) = fparg0 + fparg3;
    *(f32 *)(p + 4) = fparg1 + fparg4;
    *(f32 *)(p + 8) = zval;
    *(f32 *)(p + 0x20) = (f32)(u32)sp0.bytes[0];
    *(f32 *)(p + 0x24) = (f32)(u32)sp0.bytes[1];
    *(f32 *)(p + 0x28) = (f32)(u32)sp0.bytes[2];
    *(f32 *)(p + 0x2C) = (f32)(u32)sp0.bytes[3];
    *(f32 *)(p + 0x10) = fparg7;
    *(f32 *)(p + 0x14) = fparg8;
    *(f32 *)(p + 0x18) = scale;
    D_00887310[0](4, &quads[0], 4);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: draw the sky pulse effect for one frame index. [inferred]
// FUN_0021BBB0
void btlEffectDrawSkyPulse(s32 arg0, u16 arg1)
{
    extern BtlShuffleRenderStateSet D_00887300[];
    extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern void effMiscDrawScreenColor(u8 *arg0, s32 arg1);
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
    arg1 = arg1 & 0xFFFF;
    if ((arg1 >= 0x21) && (arg1 < 0x30)) {
        color.bytes[0] = 0;
        color.bytes[1] = 0;
        color.bytes[2] = 0;
        scale = 400.0f *
                (1.0f - cosf(
                    fGpffff84a4 * ((f32)(arg1 - 0x21) / 15.0f)));
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
    if (arg1 >= 3) {
        if (arg1 < 0x21) {
            RpSkyRenderStateSet(2, 0x48);
            scale = 400.0f *
                    sinf(
                        fGpffff84a4 * ((f32)(arg1 - 3) / 30.0f));
            arg_color_copy.f = *(f32 *)&arg0;
            shdDrawRadialFan(coords.v, 0.0f,
                          arg_color_copy.i, arg_color_copy.i,
                          scale, 0.0f, 0x24, fGpffff84cc, 1.0f, 0);
            RpSkyRenderStateSet(2, 0x44);
        } else if (arg1 < 0x30) {
            RpSkyRenderStateSet(2, 0x48);
            effMiscDrawScreenColor((u8 *)&arg0, 0);
            RpSkyRenderStateSet(2, 0x44);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: initialise an effect block with its frame and its state. [inferred]
// FUN_0021BE10
void btlEffectInit(u8 *arg0, s32 arg1)
{
    memset(arg0, 0, 0xC);
    *(s32 *)(arg0 + 8) = arg1;
    *(s16 *)(arg0 + 4) = 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_0021BE60
s32 func_0021be60(void)
{
    return iGpffffb470;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_0021BE70
void func_0021be70(void)
{
}
#pragma pop

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
static inline void btlAdvantageTile(s32 index, union ColorWord color)
{
    BtlAdvantageTile *tile = &D_00628FD0[index];
    btlPanelDrawQuad(tile->x, tile->y, 0.0f, tile->width, tile->height,
        tile->u, tile->v, tile->u + tile->width, tile->v + tile->height, color);
}

static inline void btlAdvantageMirror(f32 horizontal, f32 vertical,
    union ColorWord color)
{
    BtlAdvantageTile *tile = &D_00628FD0[4];
    btlPanelDrawQuad(tile->x, tile->y, 0.0f,
        fGpffff84cc * (horizontal * tile->width), vertical * tile->height,
        tile->u + tile->width, tile->v + tile->height, tile->u, tile->v, color);
}

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

static inline void btlAdvantageBuildQuad(f32 x, f32 y, f32 z,
    f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
    union ColorWord color)
{
    BtlShuffleSkyVertex vertices[4];
    s32 count = 0;
    f32 depth = D_008872F8[0] - z;
    f32 reciprocalZ = 1.0f / *(f32 *)(kwlnGetCamera() + 0x80);
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
static inline u16 btlAdvantageChooseSegments(void)
{
    extern u32 RpRandom(void);
    s32 eligible = 0xAAAAA >>
        (s32)(2.0f * ((f32)RpRandom() / 2147483648.0f));
    u32 selected = RpRandom();
    return selected & eligible;
}

#pragma push
#pragma opt_loop_invariants off
// Intent: draw the advantage panel's background, segments and random pattern. [inferred]
// FUN_0021BE80
void btlAdvantageDrawPanel(u8 *drawPayload, s32 workAddress, void *callback)
{
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
    kwlnTaskGetWork(*(void **)(work + 8));
    btlUiSetRenderStates();
    if (*(u16 *)work & 1) {
        if (*(u16 *)(work + 2) < 48) {
            if (*(u16 *)(iGpffffb3ac + 0x1A) == 1) {
                if (*(u16 *)(work + 2) == 4) {
                    sdkSndStartStream(1, 14, 2, 0);
                }
                color.bytes[0] = 0x2D;
                color.bytes[1] = 0x9F;
                color.bytes[2] = 0xFF;
                color.bytes[3] = 0xFF;
                btlEffectDrawSkyPulse(color.word, *(u16 *)(work + 2));
                D_00887300[0](rwRENDERSTATETEXTURERASTER, (void *)iGpffffb470);
                btlAdvantageBackground();
                RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void *)0x48);
                color.bytes[0] = 0x6B;
                color.bytes[1] = 0x9E;
                color.bytes[2] = 0xFF;
                color.bytes[3] = 0xFF;
                index = *(u16 *)(work + 4);
                btlAdvantageSegment(index, color);
                btlAdvantageSegment(index + 6, color);
                index = (*(u16 *)(work + 4) + 1) % 6;
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
                if (++*(u16 *)(work + 4) >= 6) {
                    *(u16 *)(work + 4) = 0;
                }

            } else {
                if (*(u16 *)(work + 2) == 4) {
                    sdkSndStartStream(1, 14, 2, 1);
                }
                color.bytes[0] = 0xFF;
                color.bytes[1] = 0x24;
                color.bytes[2] = 0x23;
                color.bytes[3] = 0xFF;
                btlEffectDrawSkyPulse(color.word, *(u16 *)(work + 2));
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
                    if (*(u16 *)(work + 4) & bit) {
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
                if (*(u16 *)(work + 2) % 2 == 0) {
                    *(u16 *)(work + 4) = btlAdvantageChooseSegments();
                }
            }
            ++*(u16 *)(work + 2);
        } else {
            *(u16 *)work &= (u16)~1;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: start a shuffle task and mark it ready. [inferred]
// FUN_0021D440
void btlShuffleStart(s32 task)
{
    u8 *p;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    *(s16 *)(p + 0x9E6) = 0;
    *(u16 *)(p + 0x9E4) = *(u16 *)(p + 0x9E4) | 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: report whether the shuffle task is not ready. [inferred]
// FUN_0021D470
s32 btlShuffleIsIdle(s32 task)
{
    s32 flag;

    flag = (*(u16 *)((u8 *)kwlnTaskGetWork((void *)task) + 0x9E4) & 1) != 0;
    return flag ^ 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: advance the shuffle task state machine. [inferred]
// FUN_0021D4A0
s32 btlShuffleUpdateTask(u8 *sdkTaskBytes)
{
    s32 arg0 = (s32)sdkTaskBytes;
    extern s32 btlShuffleTaskIsCancelRequested(s32 arg0);
    extern s32 btlShuffleTaskIsCancelRequestedFor(KwlnTask *task);
    extern void btlShuffleTaskSetBusy(s32 arg0);
    extern void btlXpPrepareAwards(u8 *arg0, u8 *arg1);
    extern s32 btlResultSimpleSetDoneFlag(s32 arg0);
    extern s32 btlShuffleTaskIsBusy(s32 arg0);
    extern void btlShuffleTaskResetPhase(s32 arg0);
    extern s32 btlResultSimpleIsDone(s32 arg0);
    extern void btlResultSimpleOnConfirm(s32 arg0);
    extern s32 btlLogoTitleCreate(s32 arg0);
    extern s32 btlResultOverlayCreate(s32 arg0);
    extern s32 btlResultSummaryCreate(s32 arg0);
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

    work = (u8 *)kwlnTaskGetWork((void *)arg0);
    switch (*(s32 *)(work + 4)) {
    case 1:
        *(s32 *)(work + 4) = 2;
        break;
    case 2:
        flags = *(s32 *)work;
        if ((flags & 1) == 0 || (flags & 4) == 0) {
            if ((flags & 2) != 0) {
                ready = 1;
                if ((*(s32 *)(work + 0x60) & 1) != 0 &&
                    btlShuffleTaskIsCancelRequested(*(s32 *)(work + 0x938)) != 0) {
                    ready = 0;
                }
                if (btlShuffleTaskIsCancelRequestedFor(*(KwlnTask **)(work + 0x93C)) != 0) {
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
        flags = *(s32 *)(work + 0x60);
        if ((flags & 1) != 0) {
            btlShuffleTaskSetBusy(*(s32 *)(work + 0x938));
            *(s32 *)(work + 4) = 4;
        } else {
            btlXpPrepareAwards(work + 0x60, work + 8);
            btlResultSimpleSetDoneFlag(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 4) = 5;
        }
        break;
    case 4:
        if (btlShuffleTaskIsBusy(*(s32 *)(work + 0x938)) == 0) {
            btlShuffleTaskResetPhase(*(s32 *)(work + 0x938));
            *(s32 *)(work + 0x938) = 0;
            btlXpPrepareAwards(work + 0x60, work + 8);
            btlResultSimpleSetDoneFlag(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 4) = 5;
        }
        break;
    case 5:
        if (btlResultSimpleIsDone(*(s32 *)(work + 0x93C)) == 0) {
            btlResultSimpleOnConfirm(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 0x93C) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 2) != 0) {
                btlXpApplyAwards(work + 0x60, work + 8);
                *(s32 *)(work + 0x940) = btlLogoTitleCreate(arg0);
                *(s32 *)(work + 4) = 6;
            } else if ((flags & 8) != 0) {
                btlXpApplyAwards(work + 0x60, work + 8);
                *(s32 *)(work + 0x944) = btlResultOverlayCreate(arg0);
                *(s32 *)(work + 4) = 7;
            } else if ((flags & 0x10) != 0) {
                btlXpApplyAwards(work + 0x60, work + 8);
                btlXpAddRosterExp(work + 0x60);
                *(s32 *)(work + 0x948) = btlResultSummaryCreate(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
                btlXpApplyAwards(work + 0x60, work + 8);
                btlXpAddRosterExp(work + 0x60);
                btlXpAddPartyExp((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 6:
        if (btlLogoTitleIsReady(*(KwlnTask **)(work + 0x940)) == 0) {
            btlLogoTitleAdvance(*(KwlnTask **)(work + 0x940));
            *(s32 *)(work + 0x940) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 8) != 0) {
                *(s32 *)(work + 0x944) = btlResultOverlayCreate(arg0);
                *(s32 *)(work + 4) = 7;
            } else if ((flags & 0x10) != 0) {
                btlXpAddRosterExp(work + 0x60);
                *(s32 *)(work + 0x948) = btlResultSummaryCreate(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
                btlXpAddRosterExp(work + 0x60);
                btlXpAddPartyExp((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 7:
        if (btlResultOverlayIsReady(*(KwlnTask **)(work + 0x944)) == 0) {
            btlResultOverlayStart(*(KwlnTask **)(work + 0x944));
            *(s32 *)(work + 0x944) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 0x10) != 0) {
                *(s32 *)(work + 0x948) = btlResultSummaryCreate(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
            btlXpAddPartyExp((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 8:
        if (btlResultSummaryIsReady(*(KwlnTask **)(work + 0x948)) == 0) {
            btlResultSummaryStart(*(KwlnTask **)(work + 0x948));
            *(s32 *)(work + 0x948) = 0;
            *(s32 *)(work + 4) = 9;
        }
        break;
    case 9:
        if (btlShuffleFindTask() == 0 &&
            btlLogoTaskExists() == 0 &&
            btlLogoTitleExists() == 0 &&
            btlResultOverlayExists() == 0 &&
            btlResultSummaryExists() == 0) {
            *(s32 *)(work + 4) = 0;
        }
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: release a shuffle task and its load handle. [inferred]
// FUN_0021D920
void btlShuffleDestroyTask(u8 *sdkTaskBytes)
{
    s32 task = (s32)sdkTaskBytes;
    u8 *p;
    s32 value;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    value = *(s32 *)(p + 0x934);
    if (value != 0) {
        H_Cdvd_Destroy((u8 *)value);
    }
    jtbl_008873EC[0](p);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: create a shuffle task with its child task and state. [inferred]
// FUN_0021D980
s32 btlShuffleCreate(s32 arg0, u16 *arg1)
{
    u8 *work;
    s32 result;

    chkmemAllocSiteTag(&D_006290D0, 0x3A);
    work = (u8 *)jtbl_008873E8[0](0x94C, 0x40000);
    memset(work, 0, 0x94C);
    result = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_006290C0), 0xF, 0, 0, btlShuffleUpdateTask, btlShuffleDestroyTask, (u8 *)(work));
    memcpy(work + 8, arg1, 0x58);
    if ((*arg1 & 1) != 0) {
        *(s32 *)(work + 0x60) |= 1;
    }
    *(s32 *)(work + 4) = 1;
    if ((*(s32 *)(work + 0x60) & 1) != 0) {
        *(s32 *)(work + 0x938) = btlShuffleTaskCreate(result, work + 0x48);
    }
    *(s32 *)(work + 0x93C) = btlResultSimpleCreateTask(result);
    return result;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: cancel a shuffle task and its children. [inferred]
// FUN_0021DAB0
void btlShuffleCancel(s32 task)
{
    u8 *p;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    if ((*(s32 *)(p + 0x60) & 1) != 0) {
        btlShuffleTaskRequestCancel(*(s32 *)(p + 0x938));
    }
    btlResultSimpleSetupEntries(*(s32 *)(p + 0x93C));
    *(s32 *)p |= 2;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: report whether a shuffle task was canceled. [inferred]
// FUN_0021DB10
s32 btlShuffleIsCanceled(s32 task)
{
    return (*(s32 *)kwlnTaskGetWork((void *)task) & 2) != 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: report whether a shuffle task still has an active child. [inferred]
// FUN_0021DB40
s32 btlShuffleIsBusy(s32 task)
{
    u8 *p;
    s32 temp;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    if (*(s32 *)(p + 0x938) != 0) {
        return 0;
    }
    temp = *(s32 *)(p + 0x93C);
    if (temp != 0) {
        return btlShuffleTaskIsLoading((KwlnTask *)temp);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: advance a shuffle task's frame counter and return -1 when done. [inferred]
// FUN_0021DBA0
s32 btlShuffleTickFrame(u8 *sdkTaskBytes)
{
    s32 task = (s32)sdkTaskBytes;
    u8 *p;
    s32 value;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    *(s32 *)(p + 4) = 0;
    *(s32 *)(p + 8) = 0;
    PrimAppendNode(&D_00796340, p + 4);
    value = *(s32 *)p + 1;
    *(s32 *)p = value;
    if (value == 0xC) {
        func_00122520(1, 1);
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Intent: draw the shuffle sweep quad for the current frame. [inferred]
// FUN_0021DC50
void btlShuffleDrawSweep(s32 arg0, s32 *arg1)
{
    f32 var_f20;
    f32 temp_f0;
    f32 temp_f1;
    Vec2f sp38;
    f32 var_f1;

    btlUiSetRenderStates();
    var_f20 = (f32)*(s32 *)(arg1 + 0) / 12.0f;
    if (!(var_f20 <= 1.0f)) {
        var_f20 = 1.0f;
    }
    sp38.x = 0.0f;
    sp38.y = -500.0f;
    sp38.x = sp38.x + var_f20 * (800.0f * sinf(fGpffff837c));
    temp_f0 = cosf(fGpffff837c);
    temp_f1 = 800.0f * temp_f0;
    sp38.y = sp38.y + var_f20 * temp_f1;
    shdDrawRotatedRect(sp38, 0.0f, 0xFF,
                  1500.0f, 1000.0f, fGpffff8378, 0);
}
#pragma pop
