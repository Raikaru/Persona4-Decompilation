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
extern void *memcpy(void *dst, const void *src, u32 size);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_0049Color;
extern Code1_0049Color iGpffffbb64;

static inline f32 code1_0049_mul(f32 left, f32 right) {
    return left * right;
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0049; members 004940d0-004941f0 */

#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: b210 -O2 needs independent value propagation and loop-invariant
 * constant materialization for the retail register and instruction schedule. */
#pragma push
#pragma pop
/* measured: probing opt_loop_invariants for the preheader -1 and loop branch. */
/* measured: closes opt_loop_invariants at its prior file baseline. */
/* measured: probing opt_propagation off for func_004940d0 load and branch order. */
/* measured: func_004940d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: probing opt_common_subs off for color byte reloads. */
/* measured: func_004940d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* Set the indexed ribbon and cap material colors, mapping fully opaque alpha to 254 temporarily. */
// FUN_004940D0
void mdlEffectSetRibbonMaterialColor(u8 *ribbons, u16 materialIndex, Code1_0049Color *color)
{
    u32 materialOffset;
    u32 max_1;
    u32 max_2;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;
    u8 *ribbonMaterial;
    u8 *opaqueRibbonMaterial;
    u8 *capModel;
    u8 *ribbonModel;
    u8 *capMaterial;
    u8 *opaqueCapMaterial;

    ribbonModel = (u8 *)((EffTrackRibbons *)ribbons)->ribbon;
    c3 = color->c3;
    max_1 = 0xFF;
    if (c3 != max_1) {
        materialOffset = (materialIndex & 0xFFFF) * 4;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        ribbonMaterial = *(u8 **)(((MdlEffectMultipartGeometry *)ribbonModel)->materials + materialOffset);
        c0 = color->c0;
        c1 = color->c1;
        c2 = color->c2;
        c3 = color->c3;
        ribbonMaterial[4] = c0;
        ribbonMaterial[5] = c1;
        ribbonMaterial[6] = c2;
        ribbonMaterial[7] = c3;
    } else {
        color->c3 = 0xFE;
        materialOffset = (materialIndex & 0xFFFF) * 4;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        opaqueRibbonMaterial = *(u8 **)(((MdlEffectMultipartGeometry *)ribbonModel)->materials + materialOffset);
        c0 = color->c0;
        c1 = color->c1;
        c2 = color->c2;
        c3 = color->c3;
        opaqueRibbonMaterial[4] = c0;
        opaqueRibbonMaterial[5] = c1;
        opaqueRibbonMaterial[6] = c2;
        opaqueRibbonMaterial[7] = c3;
        color->c3 = max_1;
    }
    capModel = (u8 *)((EffTrackRibbons *)ribbons)->cap;
    c3 = color->c3;
    max_2 = 0xFF;
    if (c3 != max_2) {
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        capMaterial = *(u8 **)(((MdlEffectMultipartGeometry *)capModel)->materials + materialOffset);
        c0 = color->c0;
        c1 = color->c1;
        c2 = color->c2;
        c3 = color->c3;
        capMaterial[4] = c0;
        capMaterial[5] = c1;
        capMaterial[6] = c2;
        capMaterial[7] = c3;
        return;
    }
    color->c3 = 0xFE;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    opaqueCapMaterial = *(u8 **)(((MdlEffectMultipartGeometry *)capModel)->materials + materialOffset);
    c0 = color->c0;
    c1 = color->c1;
    c2 = color->c2;
    c3 = color->c3;
    opaqueCapMaterial[4] = c0;
    opaqueCapMaterial[5] = c1;
    opaqueCapMaterial[6] = c2;
    opaqueCapMaterial[7] = c3;
    color->c3 = max_2;
}

/* measured: closing opt_common_subs after func_004940d0 probe. */
/* measured: func_004941f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
/* measured: closing opt_propagation after func_004940d0 probe. */
/* measured: func_004941f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
/* func_004941f0, MATCH 2026-10-07. Counts are unsigned after the signed-short
   loads; complete vector and packed-colour objects keep the VU transfers, and
   the colour unpacks use effectVuUnpackColor10V0. `opt_loop_invariants on`
   hoists the loop's vector addresses and 255.0f as retail does (measured:
   without it the body differs by 65 words). `opt_pulloutconstants off`
   stops IRO_CommonSubs from sharing the entry's 1.0f with the loop, so the
   loop preheader rematerialises it as retail does. The first unpack reads its
   word through a `const u32 *` local, which schedules the scale load after
   the address. */
#pragma push
/* measured: func_004941f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: func_004941f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_pulloutconstants off
/* Interpolate the ribbon colors, then repeat its first row and the cap colors. */
/* Interpolate four endpoint colors across each ribbon row and replicate the cap color row. */
// FUN_004941F0
void mdlEffectInterpolateRibbonColors(u8 *track, u32 *colors)
{
    extern u8 *func_003c22f0(u8 *geometry);
    extern f32 fGpffff8044;
    u32 firstWord;
    u32 secondWord;
    u32 thirdWord;
    u32 fourthWord;
    u32 firstPacked;
    u32 secondPacked;
    EffectVuVector first;
    EffectVuVector third;
    EffectVuVector second;
    EffectVuVector fourth;
    u8 *work;
    u32 rowCount;
    u32 vertexCount;
    u32 segmentCount;
    u8 *destination;
    u8 *firstRow;
    f32 fraction;
    f32 fractionStep;
    f32 scale;
    u32 index;
    u32 rowBytes;
    u32 rowIndex;
    u8 *geometry;
    u8 *cap;
    u8 *capColors;
    u8 *nextCapRow;
    u32 capRowIndex;

    work = (u8 *)((EffTrackRibbons *)track)->ribbon;
    RpGeometryLock(((RpAtomic *)((MdlEffectMultipartGeometry *)work)->model)->geometry, 8);
    rowCount = ((MdlEffectMultipartGeometry *)work)->partCount.signedValue;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    vertexCount = *(s16 *)(work + 8);
    segmentCount = vertexCount / 3U;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    destination = (u8 *)((RpGeometry *)(u8 *)((RpAtomic *)*(u8 **)(work + 0x10))->geometry)->colors;
    firstRow = destination;
    fractionStep = 1.0f / (f32)segmentCount;
    fraction = 0.0f;
    firstWord = colors[0];
    {
        const u32 *word = &firstWord;

        scale = fGpffff8044;
        effectVuUnpackColor10V0(word, scale);
    }
    effectVuStore10(&first);
    secondWord = colors[1];
    effectVuUnpackColor10V0(&secondWord, scale);
    effectVuStore10(&second);
    thirdWord = colors[2];
    effectVuUnpackColor10V0(&thirdWord, scale);
    effectVuStore10(&third);
    fourthWord = colors[3];
    effectVuUnpackColor10V0(&fourthWord, scale);
    effectVuStore10(&fourth);
    index = 0;
    while (index < segmentCount) {
        f32 inverse;
        effectVuLoad11(&first);
        effectVuLoad10(&third);
        effectVuScale10(fraction);
        inverse = 1.0f - fraction;
        effectVuScale11(inverse);
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
        {
            /* Binary32 255.0f converts normalized VU color lanes back to bytes. */
            u32 packed;
            __asm__ volatile(
                "qmtc2.ni %2, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2.ni %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, firstPacked\n"
                : "=&r"(packed), "=m"(firstPacked)
                : "r"(0x437F0000U)
                : "$vf2", "$vf10", "memory");
        }
        ((u32 *)destination)[1] = firstPacked;
        effectVuLoad11(&second);
        effectVuLoad10(&fourth);
        effectVuScale10(fraction);
        effectVuScale11(inverse);
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
        {
            /* Binary32 255.0f converts normalized VU color lanes back to bytes. */
            u32 packed;
            __asm__ volatile(
                "qmtc2.ni %2, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2.ni %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, secondPacked\n"
                : "=&r"(packed), "=m"(secondPacked)
                : "r"(0x437F0000U)
                : "$vf2", "$vf10", "memory");
        }
        *(u32 *)destination = secondPacked;
        ((Code1_0049Color *)destination)[2] = *(Code1_0049Color *)destination;
        fraction += fractionStep;
        destination += 12;
        index++;
    }
    rowIndex = 1;
    rowBytes = vertexCount * 4;
    while (rowIndex < rowCount) {
        memcpy(destination, firstRow, rowBytes);
        destination += rowBytes;
        rowIndex++;
    }
    geometry = (u8 *)((RpAtomic *)((MdlEffectMultipartGeometry *)work)->model)->geometry;
    func_003c22f0(geometry);
    if (*(u16 *)work & 4) {
        ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
    }
    cap = (u8 *)((EffTrackRibbons *)track)->cap;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    RpGeometryLock(((RpAtomic *)*(u8 **)(cap + 0x10))->geometry, 8);
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    capColors = (u8 *)((RpGeometry *)(u8 *)((RpAtomic *)*(u8 **)(cap + 0x10))->geometry)->colors;
    *(u32 *)capColors = colors[0];
    ((u32 *)capColors)[1] = colors[1];
    ((Code1_0049Color *)capColors)[2] = ((Code1_0049Color *)capColors)[1];
    ((Code1_0049Color *)capColors)[3] = ((Code1_0049Color *)capColors)[1];
    ((Code1_0049Color *)capColors)[4] = ((Code1_0049Color *)capColors)[1];
    ((Code1_0049Color *)capColors)[5] = ((Code1_0049Color *)capColors)[1];
    ((Code1_0049Color *)capColors)[6] = ((Code1_0049Color *)capColors)[1];
    ((Code1_0049Color *)capColors)[7] = ((Code1_0049Color *)capColors)[1];
    nextCapRow = capColors + 32;
    capRowIndex = 1;
    while (capRowIndex < rowCount) {
        memcpy(nextCapRow, capColors, 32);
        nextCapRow += 32;
        capRowIndex++;
    }
    geometry = (u8 *)((RpAtomic *)((MdlEffectMultipartGeometry *)cap)->model)->geometry;
    func_003c22f0(geometry);
    if (*(u16 *)cap & 4) {
        ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
    }
}
#pragma pop
