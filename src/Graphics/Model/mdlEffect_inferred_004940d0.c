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
// FUN_004940D0
void func_004940d0(u8 *arg0, u16 arg1, Code1_0049Color *arg2)
{
    u32 var_3;
    u32 max_1;
    u32 max_2;
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;
    u8 *temp_10;
    u8 *temp_10_2;
    u8 *temp_5;
    u8 *temp_7;
    u8 *temp_8;
    u8 *temp_8_2;

    temp_7 = *(u8 **)(arg0 + 0x10);
    c3 = arg2->c3;
    max_1 = 0xFF;
    if (c3 != max_1) {
        var_3 = (arg1 & 0xFFFF) * 4;
        temp_10 = *(u8 **)(*(u8 **)(temp_7 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_10[4] = c0;
        temp_10[5] = c1;
        temp_10[6] = c2;
        temp_10[7] = c3;
    } else {
        arg2->c3 = 0xFE;
        var_3 = (arg1 & 0xFFFF) * 4;
        temp_10_2 = *(u8 **)(*(u8 **)(temp_7 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_10_2[4] = c0;
        temp_10_2[5] = c1;
        temp_10_2[6] = c2;
        temp_10_2[7] = c3;
        arg2->c3 = max_1;
    }
    temp_5 = *(u8 **)(arg0 + 0x14);
    c3 = arg2->c3;
    max_2 = 0xFF;
    if (c3 != max_2) {
        temp_8 = *(u8 **)(*(u8 **)(temp_5 + 0x54) + var_3);
        c0 = arg2->c0;
        c1 = arg2->c1;
        c2 = arg2->c2;
        c3 = arg2->c3;
        temp_8[4] = c0;
        temp_8[5] = c1;
        temp_8[6] = c2;
        temp_8[7] = c3;
        return;
    }
    arg2->c3 = 0xFE;
    temp_8_2 = *(u8 **)(*(u8 **)(temp_5 + 0x54) + var_3);
    c0 = arg2->c0;
    c1 = arg2->c1;
    c2 = arg2->c2;
    c3 = arg2->c3;
    temp_8_2[4] = c0;
    temp_8_2[5] = c1;
    temp_8_2[6] = c2;
    temp_8_2[7] = c3;
    arg2->c3 = max_2;
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
// FUN_004941F0
void func_004941f0(u8 *track, u32 *colors)
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

    work = *(u8 **)(track + 0x10);
    RpGeometryLock(*(RpGeometry **)(*(u8 **)(work + 0x10) + 0x18), 8);
    rowCount = *(s16 *)(work + 0x48);
    vertexCount = *(s16 *)(work + 8);
    segmentCount = vertexCount / 3U;
    destination = *(u8 **)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x30);
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
        *(u32 *)(destination + 4) = firstPacked;
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
        *(Code1_0049Color *)(destination + 8) = *(Code1_0049Color *)destination;
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
    geometry = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(geometry);
    if (*(u16 *)work & 4) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
    cap = *(u8 **)(track + 0x14);
    RpGeometryLock(*(RpGeometry **)(*(u8 **)(cap + 0x10) + 0x18), 8);
    capColors = *(u8 **)(*(u8 **)(*(u8 **)(cap + 0x10) + 0x18) + 0x30);
    *(u32 *)capColors = colors[0];
    *(u32 *)(capColors + 4) = colors[1];
    *(Code1_0049Color *)(capColors + 8) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 12) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 16) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 20) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 24) = *(Code1_0049Color *)(capColors + 4);
    *(Code1_0049Color *)(capColors + 28) = *(Code1_0049Color *)(capColors + 4);
    nextCapRow = capColors + 32;
    capRowIndex = 1;
    while (capRowIndex < rowCount) {
        memcpy(nextCapRow, capColors, 32);
        nextCapRow += 32;
        capRowIndex++;
    }
    geometry = *(u8 **)(*(u8 **)(cap + 0x10) + 0x18);
    func_003c22f0(geometry);
    if (*(u16 *)cap & 4) {
        *(u16 *)(geometry + 0xC) |= 1;
    }
}

