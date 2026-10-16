#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
extern s32 datScriptTargetIsNotEnemy(void);
extern f32 datScriptCalcFloat(s32 arg0, s32 arg1);
#include "datScript_internal.h"

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00635990[];
extern u8 D_006359A0[];
extern u8 D_006359B0[];
extern u8 D_006359C0[];

extern f32 D_00761260;
extern f32 fGpffff811c;
static inline f32 mul_f32_ordered(f32 left, f32 right)
{
    return left * right;
}
static inline f32 add_f32_ordered(f32 left, f32 right)
{
    return left + right;
}
/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* Source unit: src/promoted/code1_0024.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 00244110-00244540 */

// Intent: Compute physical damage from attacker STR, defender END, skill base power, status resistance and level factors; the flag-4 target split picks one of two formulas [inferred]
// FUN_00244110
void datScriptCalcPhysicalDamage(void)
{
    extern s32 datScriptCmdFlag2Set(void);
    extern f32 sqrtf(f32 arg0);
    extern f32 fGpffff82c0;
    extern f32 fGpffff824c;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    if (datScriptCmdFlag2Set() != 0) {
        if (datScriptTargetIsNotEnemy() != 0) {
            temp_f20 = datScriptCalcFloat(0xE, 2);
            temp_f20 += datScriptCalcFloat(0xE, 2);
            temp_f1 = datScriptCalcFloat(0x13, 0) / 2.0f;
            temp_f1 = mul_f32_ordered(30.0f, temp_f1);
            temp_f0 = 5.0f * temp_f20;
            temp_f20 = temp_f1 / temp_f0;
            temp_f0 = datScriptCalcFloat(0xD, 0) / 5.0f;
            temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
            temp_f1 = sqrtf(temp_f0);
            temp_f20 = 10.0f * temp_f1;
            temp_f20 *= datScriptCalcFloat(0xC, 0);
            temp_f20 *= datScriptCalcFloat(0x17, 0);
        } else {
            temp_f20 = datScriptCalcFloat(0x20, 0) / 4.0f;
            temp_f3 = 2.0f;
            temp_f0 = datScriptCalcFloat(0xE, 2);
            temp_f2 = temp_f20 / temp_f3;
            temp_f1 = temp_f2 + temp_f3 * temp_f0;
            temp_f0 = fGpffff811c * temp_f1;
            temp_f20 = temp_f0;
            temp_f1 = datScriptCalcFloat(0x13, 0);
            temp_f1 = mul_f32_ordered(30.0f, temp_f1);
            temp_f0 = mul_f32_ordered(5.0f, temp_f20);
            temp_f20 = temp_f1 / temp_f0;
            temp_f0 = datScriptCalcFloat(0xD, 0) / 5.0f;
            temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
            temp_f1 = sqrtf(temp_f0);
            temp_f20 = 10.0f * temp_f1;
            temp_f20 *= datScriptCalcFloat(0xC, 0);
            temp_f1 = temp_f20 * datScriptCalcFloat(0x17, 0);
            temp_f20 = fGpffff82c0 * temp_f1;
        }
    } else {
        if (datScriptTargetIsNotEnemy() != 0) {
            temp_f20 = datScriptCalcFloat(0xE, 2);
            temp_f20 += datScriptCalcFloat(0xE, 2);
            temp_f1 = datScriptCalcFloat(0x13, 0);
            temp_f1 = mul_f32_ordered(30.0f, temp_f1);
            temp_f0 = 5.0f * temp_f20;
            temp_f20 = temp_f1 / temp_f0;
            temp_f0 = datScriptCalcFloat(0xD, 0) / 5.0f;
            temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
            temp_f1 = sqrtf(temp_f0);
            temp_f20 = 10.0f * temp_f1;
            temp_f20 *= datScriptCalcFloat(0xC, 0);
            temp_f20 *= datScriptCalcFloat(0x17, 0);
        } else {
            temp_f20 = datScriptCalcFloat(0x20, 0) / 2.0f;
            temp_f3 = 2.0f;
            temp_f0 = datScriptCalcFloat(0xE, 2);
            temp_f2 = temp_f20 / temp_f3;
            temp_f1 = temp_f2 + temp_f3 * temp_f0;
            temp_f0 = fGpffff811c * temp_f1;
            temp_f20 = temp_f0;
            temp_f1 = datScriptCalcFloat(0x13, 0);
            temp_f1 = mul_f32_ordered(30.0f, temp_f1);
            temp_f0 = mul_f32_ordered(5.0f, temp_f20);
            temp_f20 = temp_f1 / temp_f0;
            temp_f0 = datScriptCalcFloat(0xD, 0) / 5.0f;
            temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
            temp_f1 = sqrtf(temp_f0);
            temp_f20 = 10.0f * temp_f1;
            temp_f1 = temp_f20 * datScriptCalcFloat(0x17, 0);
            temp_f20 = temp_f1 - 30.0f;
            if (temp_f20 <= 0.0f)
                temp_f20 = 1.0f;
            temp_f20 *= fGpffff824c;
            temp_f20 *= datScriptCalcFloat(0xC, 0);
        }
    }
    datScriptSetResult(temp_f20);
}

// Intent: Compute magic damage from attacker MAG, defender END and skill base power, with the same level and resistance factors as the physical formula [inferred]
// FUN_00244540
void datScriptCalcMagicDamage(void)
{
    extern f32 sqrtf(f32 arg0);
    extern f32 fGpffff824c;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    if (datScriptTargetIsNotEnemy() != 0) {
        temp_f20 = datScriptCalcFloat(0xE, 2);
        temp_f20 += datScriptCalcFloat(0xE, 2);
        temp_f1 = datScriptCalcFloat(0x13, 0);
        temp_f1 = mul_f32_ordered(30.0f, temp_f1);
        temp_f0 = 5.0f * temp_f20;
        temp_f20 = temp_f1 / temp_f0;
        temp_f0 = datScriptCalcFloat(0xD, 1) / 5.0f;
        temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
        temp_f1 = sqrtf(temp_f0);
        temp_f21 = 10.0f * temp_f1;
        temp_f21 *= datScriptCalcFloat(0xC, 0);
        temp_f20 = datScriptCalcFloat(0x17, 0);
        temp_f0 = datScriptCalcFloat(0x19, 0);
        temp_f20 = temp_f0 + temp_f21 * temp_f20;
    } else {
        temp_f20 = datScriptCalcFloat(0x20, 0) / 2.0f;
        temp_f3 = 2.0f;
        temp_f0 = datScriptCalcFloat(0xE, 2);
        temp_f2 = temp_f20 / temp_f3;
        temp_f1 = temp_f2 + temp_f3 * temp_f0;
        temp_f0 = fGpffff811c * temp_f1;
        temp_f20 = temp_f0;
        temp_f1 = datScriptCalcFloat(0x13, 0);
        temp_f1 = mul_f32_ordered(30.0f, temp_f1);
        temp_f0 = mul_f32_ordered(5.0f, temp_f20);
        temp_f20 = temp_f1 / temp_f0;
        temp_f0 = datScriptCalcFloat(0xD, 1) / 5.0f;
        temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
        temp_f1 = sqrtf(temp_f0);
        temp_f21 = 10.0f * temp_f1;
        temp_f20 = datScriptCalcFloat(0x17, 0);
        temp_f0 = datScriptCalcFloat(0x19, 0);
        temp_f2 = temp_f0 + temp_f21 * temp_f20;
        temp_f0 = 30.0f;
        temp_f20 = temp_f2 - temp_f0;
        if (temp_f20 <= 0.0f)
            temp_f20 = 1.0f;
        temp_f20 *= 2.0f;
        temp_f20 *= datScriptCalcFloat(0xC, 0);
    }
    datScriptSetResult(temp_f20);
}

