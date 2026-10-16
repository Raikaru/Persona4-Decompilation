#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 00244cf0-00244cf0 */

// Intent: Compute physical damage with the STR/END formula, then scale it by the battle hit counter plus one and an extra factor [inferred]
// FUN_00244CF0
void datScriptCalcPhysicalDamageScaled(void)
{
    extern f32 sqrtf(f32 arg0);
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f1;

    temp_f20 = datScriptCalcFloat(0xE, 2);
    temp_f20 += datScriptCalcFloat(0xE, 2);
    temp_f0 = datScriptCalcFloat(0x13, 0);
    temp_f1 = temp_f0 / 2.0f;
    temp_f0 = 30.0f * temp_f1;
    temp_f1 = 5.0f * temp_f20;
    temp_f20 = temp_f0 / temp_f1;
    temp_f0 = datScriptCalcFloat(0xD, 0);
    temp_f0 = temp_f0 / 5.0f;
    temp_f0 = mul_f32_ordered(temp_f20, temp_f0);
    temp_f1 = sqrtf(temp_f0);
    temp_f20 = 10.0f * temp_f1;
    temp_f20 *= datScriptCalcFloat(0xC, 0);
    temp_f20 *= datScriptCalcFloat(0x17, 0);
    temp_f20 *= datScriptCalcFloat(0x1B, 0);
    temp_f1 = temp_f20 * datScriptCalcFloat(0x21, 0);
    temp_f0 = temp_f1 * fGpffff811c;
    datScriptSetResult(temp_f0);
}

