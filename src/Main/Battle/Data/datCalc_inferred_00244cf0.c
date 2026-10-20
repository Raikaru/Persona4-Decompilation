#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
extern f32 datScriptCalcFloat(s32 term, s32 parameter);
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
/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* Source unit: src/promoted/code1_0024.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 00244cf0-00244cf0 */

// Intent: Compute physical damage with the STR/END formula, then scale it by the battle hit counter plus one and an extra factor [inferred]
// FUN_00244CF0
void datScriptCalcPhysicalDamageScaled(void)
{
    extern f32 sqrtf(f32);
    f32 damage;
    f32 scaledTerm;
    f32 powerTerm;

    damage = datScriptCalcFloat(0xE, 2);
    damage += datScriptCalcFloat(0xE, 2);
    scaledTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0);
    powerTerm = scaledTerm / 2.0f;
    scaledTerm = 30.0f * powerTerm;
    powerTerm = 5.0f * damage;
    damage = scaledTerm / powerTerm;
    scaledTerm = datScriptCalcFloat(0xD, 0);
    scaledTerm = scaledTerm / 5.0f;
    scaledTerm = mul_f32_ordered(damage, scaledTerm);
    powerTerm = sqrtf(scaledTerm);
    damage = 10.0f * powerTerm;
    damage *= datScriptCalcFloat(DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT, 0);
    damage *= datScriptCalcFloat(DAT_SCRIPT_TERM_LEVEL_FACTOR, 0);
    damage *= datScriptCalcFloat(0x1B, 0);
    powerTerm = damage * datScriptCalcFloat(0x21, 0);
    scaledTerm = powerTerm * fGpffff811c;
    datScriptSetResult(scaledTerm);
}

