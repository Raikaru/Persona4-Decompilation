#include "mdl_effect_drawable_internal.h"
#include "btl_action_internal.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "particle_spawn_internal.h"
#include "effect_vu0_internal.h"
#include "sway_particle_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct EffRandState EffRandState;
extern s32 D_00713D58[];
extern s32 D_00713D5C[];
extern u8 D_00713E10[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_0049Color;
extern Code1_0049Color iGpffffbb64;


extern void mdlEffectSetRibbonMaterialColor(u8 *ribbons, u16 materialIndex, Code1_0049Color *color);
extern void mdlEffectInterpolateRibbonColors(u8 *track, u32 *colors);
/* Widen the ribbon index before selecting its retained count slot. measured: retail widens only the
 * count-slot index this way; vertex indices use plain casts. */
static inline u32 mdlEffectTrackIndex(u16 value)
{
    return value;
}
typedef struct TrackVertex
{
    f32 x, y, z;
} TrackVertex;
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: retail schedule needs value propagation off and loop-invariant constants hoisted. */
#pragma push
#pragma pop
/* func_004941f0: counts are unsigned after the signed-short loads, and colour unpacks use
 * effectVuUnpackColor10V0; the loop preheader rematerialises 1.0f as retail does. */
#pragma push
#pragma pop
#pragma push
/* measured: retail hoists loop invariants in this function. */
#pragma opt_loop_invariants on
/* Shift one track's center history, build the tapered ribbon, and rebuild its cap vertices from the
 * head tangent and side vector. */
// FUN_00494740
void mdlEffectAdvanceRibbon(u8 *track, u16 trackIndex, u8 *point, f32 width) {
    extern void mdlEffectAxisAngleBasisVU(f32 angle);
    extern u_long128 D_00713D00;
    extern f32 D_00713D10[4];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    extern f32 fGpffff8094;
    extern f32 fGpffff80bc;
    extern f32 fGpffff80c0;
    extern f32 fGpffff80c8;
    extern f32 fGpffff80cc;
    u_long128 headTangent;
    u_long128 headSide;
    u8 *followingCenter;
    u8 *previousCenter;
    s32 vertexCount;
    u16 shiftedVertex;
    s32 rowCount;
    u32 lastRow;
    u8 *countSlot;
    u32 activeRows;
    u8 *row;
    u8 *firstRow;
    f32 fraction;
    f32 fractionStep;
    f32 headWidth;
    f32 rotation;
    u16 rowIndex;
    u16 lastActiveRow;
    u8 *cap;
    f32 capLength;
    f32 capWidth;

    {
        u8 *t10 = (u8 *)((EffTrackRibbons *)track)->ribbon;
        vertexCount = ((MdlEffectMultipartGeometry *)t10)->vertexCount;
        {
            u8 *t1 = ((MdlEffectMultipartGeometry *)t10)->model;
            u8 *t2 = (u8 *)((RpAtomic *)t1)->geometry;
            u8 *t3 = (u8 *)((RpGeometry *)t2)->morphTarget;
            u8 *tab = (u8 *)((RpMorphTarget *)t3)->vertices;
            row = tab + (u32)vertexCount * ((u32)(u16)(trackIndex)) * 12;
        }
        previousCenter = row + (vertexCount - 5) * 12;
        followingCenter = row + (vertexCount - 2) * 12;
    }
    shiftedVertex = 3;
    goto shift_check;
shift_center:
    ((TrackVertex *)followingCenter)[0] = ((const TrackVertex *)previousCenter)[0];
    previousCenter -= 0x24;
    followingCenter -= 0x24;
    shiftedVertex += 3;
shift_check:
    if (shiftedVertex < vertexCount) {
        goto shift_center;
    }
    ((TrackVertex *)row)[1] = ((const TrackVertex *)point)[0];
    rowCount = (s32)vertexCount / 3 - 1;
    lastRow = (u16)rowCount;
    countSlot = ((EffTrackRibbons *)track)->counts + (mdlEffectTrackIndex(trackIndex) * 2);
    activeRows = *(u16 *)countSlot;
    if ((s32)activeRows <= (s32)lastRow) {
        u32 nv = activeRows + 1;
        activeRows = (u16)nv;
        *(u16 *)countSlot = (u16)nv;
    }
    firstRow = row;
    headWidth = 0.0f;
    __asm__ volatile("sqc2 $vf0, 0(%1)" : "=m"(headTangent) : "r"(&headTangent) : "memory");
    __asm__ volatile("sqc2 $vf0, 0(%1)" : "=m"(headSide) : "r"(&headSide) : "memory");
    rowIndex = 0;
    if ((s32)(u16)activeRows <= 1) {
        goto collapse_tail;
    }
    {
        fraction = (f32)(u32)activeRows / (f32)(u32)lastRow;
        fractionStep = fraction / (f32)(u32)activeRows;
        headWidth = width * fraction;
    }
    lastActiveRow = activeRows - 1;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D00), "m"(D_00713D00) : "$vf10", "memory");
    __asm__ volatile(
        "vmove.xyzw $vf24, $vf10 \n"
        : : : "$vf24", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(track), "m"(*(u_long128 *)track) : "$vf11", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf11 \n"
        "vaddy.x $vf2, $vf2, $vf2y \n"
        "vaddz.x $vf2, $vf2, $vf2z \n"
        : : : "$vf2", "memory");
    {
        f32 dot;
        __asm__ volatile(
            "qmfc2 %0, $vf2 \n"
            : "=r"(dot) : : "memory");
        rotation = fGpffff8094 * dot;
    }
    D_00713D10[0] = ((TrackVertex *)row)[1].x;
    D_00713D14[0] = ((TrackVertex *)row)[1].y;
    D_00713D18[0] = ((TrackVertex *)row)[1].z;
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
    D_00713D10[0] = ((TrackVertex *)row)[4].x;
    D_00713D14[0] = ((TrackVertex *)row)[4].y;
    D_00713D18[0] = ((TrackVertex *)row)[4].z;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf10", "memory");
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf12 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(headTangent) : "r"(&headTangent) : "memory");
    mdlEffectAxisAngleBasisVU(rotation);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf24 \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        : : : "$vf10", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(headSide) : "r"(&headSide) : "memory");
    {
            /* The unmodified inputs describe this row's width independently of
         * the retained cap width. Both are the same product at the head. */
        f32 rowWidth = width * fraction;
        __asm__ volatile("qmtc2 %0, $vf2" : : "r"(rowWidth) : "$vf2", "memory");
        __asm__ volatile(
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vadd.xyzw $vf12, $vf12, $vf10 \n"
            : : : "$vf10", "$vf12", "memory");
    }
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    *(f32 *)row = D_00713D10[0];
    ((TrackVertex *)row)[0].y = D_00713D14[0];
    ((TrackVertex *)row)[0].z = D_00713D18[0];
    __asm__ volatile(
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        : : : "$vf12", "memory");
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    ((TrackVertex *)row)[2].x = D_00713D10[0];
    ((TrackVertex *)row)[2].y = D_00713D14[0];
    ((TrackVertex *)row)[2].z = D_00713D18[0];
    fraction = fraction - fractionStep;
    row += 0x24;
    rowIndex++;
    goto ribbon_check;
ribbon_row:
    D_00713D10[0] = ((TrackVertex *)row)[1].x;
    D_00713D14[0] = ((TrackVertex *)row)[1].y;
    D_00713D18[0] = ((TrackVertex *)row)[1].z;
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
    D_00713D10[0] = ((TrackVertex *)row)[4].x;
    D_00713D14[0] = ((TrackVertex *)row)[4].y;
    D_00713D18[0] = ((TrackVertex *)row)[4].z;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf10", "memory");
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf12 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    mdlEffectAxisAngleBasisVU(rotation);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf24 \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        : : : "$vf10", "ACC", "memory");
    {
        f32 t = width * fraction;
        __asm__ volatile("qmtc2 %0, $vf2" : : "r"(t) : "$vf2", "memory");
        __asm__ volatile(
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vadd.xyzw $vf12, $vf12, $vf10 \n"
            : : : "$vf10", "$vf12", "memory");
    }
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    {
        u8 *dst = row;
        *(f32 *)dst = D_00713D10[0];
        ((TrackVertex *)dst)[0].y = D_00713D14[0];
        ((TrackVertex *)dst)[0].z = D_00713D18[0];
    }
    __asm__ volatile(
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        "vsub.xyzw $vf12, $vf12, $vf10 \n"
        : : : "$vf12", "memory");
    __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
    ((TrackVertex *)row)[2].x = D_00713D10[0];
    ((TrackVertex *)row)[2].y = D_00713D14[0];
    ((TrackVertex *)row)[2].z = D_00713D18[0];
    fraction = fraction - fractionStep;
    row += 0x24;
    rowIndex++;
ribbon_check:
    if (rowIndex < lastActiveRow) {
        goto ribbon_row;
    }
collapse_tail:
    ((TrackVertex *)row)[0] = ((const TrackVertex *)row)[1];
    ((TrackVertex *)row)[2] = ((const TrackVertex *)row)[1];
    {
        u8 *nxt = row + 0x24;
        goto tail_check;
tail_row:
        ((TrackVertex *)nxt)[0] = ((const TrackVertex *)row)[0];
        ((TrackVertex *)nxt)[1] = ((const TrackVertex *)row)[1];
        ((TrackVertex *)nxt)[2] = ((const TrackVertex *)row)[2];
        nxt += 0x24;
        rowIndex++;
tail_check:
        if (rowIndex < (s32)(u16)lastRow) {
            goto tail_row;
        }
        {
            u8 *t = (u8 *)((EffTrackRibbons *)track)->cap;
            u32 c2 = ((MdlEffectMultipartGeometry *)t)->vertexCount;
            u8 *t1 = ((MdlEffectMultipartGeometry *)t)->model;
            u8 *t2 = (u8 *)((RpAtomic *)t1)->geometry;
            u8 *t3 = (u8 *)((RpGeometry *)t2)->morphTarget;
            u8 *tab2 = (u8 *)((RpMorphTarget *)t3)->vertices;
            cap = tab2 + (u32)c2 * ((u32)(u16)(trackIndex)) * 12;
            *(TrackVertex *)cap = ((const TrackVertex *)firstRow)[1];
            ((TrackVertex *)cap)[1] = ((const TrackVertex *)firstRow)[0];
            ((TrackVertex *)cap)[7] = ((const TrackVertex *)firstRow)[2];
        }
        {
            f32 wide;
            f32 inner;
            f32 blendWide;
            f32 blendInner;
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&headTangent), "m"(headTangent) : "$vf11", "memory");
            __asm__ volatile("vsub.xyz $vf11, $vf0, $vf11" : : : "$vf11", "memory");
            capLength = 2.0f * headWidth;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capLength) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "memory");
            }
            D_00713D10[0] = ((TrackVertex *)firstRow)[1].x;
            D_00713D14[0] = ((TrackVertex *)firstRow)[1].y;
            D_00713D18[0] = ((TrackVertex *)firstRow)[1].z;
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&D_00713D10), "m"(D_00713D10) : "$vf12", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            wide = fGpffff80bc * headWidth;
            capWidth = wide;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capWidth) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "memory");
            }
            {
                blendWide = fGpffff80c0;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendWide) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            ((TrackVertex *)cap)[2].x = D_00713D10[0];
            ((TrackVertex *)cap)[2].y = D_00713D14[0];
            ((TrackVertex *)cap)[2].z = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            inner = 1.7f * headWidth;
            capWidth = inner;
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(capWidth) : "$vf2", "memory");
                __asm__ volatile("vmulx.xyzw $vf10, $vf10, $vf2x" : : : "$vf10", "memory");
            }
            {
                blendInner = fGpffff80c8;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendInner) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            ((TrackVertex *)cap)[3].x = D_00713D10[0];
            ((TrackVertex *)cap)[3].y = D_00713D14[0];
            ((TrackVertex *)cap)[3].z = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(wide) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vsub.xyz $vf10, $vf0, $vf10 \n"
                    : : : "$vf10", "memory");
            }
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendWide) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            ((TrackVertex *)cap)[6].x = D_00713D10[0];
            ((TrackVertex *)cap)[6].y = D_00713D14[0];
            ((TrackVertex *)cap)[6].z = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&headSide), "m"(headSide) : "$vf10", "memory");
            {
                f32 t2 = inner;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(t2) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vsub.xyz $vf10, $vf0, $vf10 \n"
                    : : : "$vf10", "memory");
            }
            {
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(blendInner) : "$vf2", "memory");
                __asm__ volatile(
                    "vsubx.w $vf3, $vf0, $vf2x \n"
                    "vmulax.xyzw $ACC, $vf11, $vf2x \n"
                    "vmaddw.xyzw $vf10, $vf10, $vf3w \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : : : "$vf3", "$vf10", "ACC", "memory");
            }
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            ((TrackVertex *)cap)[5].x = D_00713D10[0];
            ((TrackVertex *)cap)[5].y = D_00713D14[0];
            ((TrackVertex *)cap)[5].z = D_00713D18[0];
            {
                f32 endpoint = fGpffff80cc;
                __asm__ volatile("qmtc2 %0, $vf2" : : "r"(endpoint) : "$vf2", "memory");
                __asm__ volatile(
                    "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                    "vadd.xyzw $vf11, $vf11, $vf12 \n"
                    : : : "$vf11", "memory");
            }
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(D_00713D10) : "r"(&D_00713D10) : "memory");
            ((TrackVertex *)cap)[4].x = D_00713D10[0];
            ((TrackVertex *)cap)[4].y = D_00713D14[0];
            ((TrackVertex *)cap)[4].z = D_00713D18[0];
        }
    }
}
#pragma pop
