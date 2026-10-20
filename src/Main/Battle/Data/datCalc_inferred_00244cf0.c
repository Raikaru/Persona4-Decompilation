#include "include_asm.h"
#include "operand_order_internal.h"
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

// Compute physical damage with the STR/END formula, then scale it by the battle hit counter plus
// one and an extra factor.
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
    scaledTerm = operandOrderMultiply(damage, scaledTerm);
    powerTerm = sqrtf(scaledTerm);
    damage = 10.0f * powerTerm;
    damage *= datScriptCalcFloat(DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT, 0);
    damage *= datScriptCalcFloat(DAT_SCRIPT_TERM_LEVEL_FACTOR, 0);
    damage *= datScriptCalcFloat(0x1B, 0);
    powerTerm = damage * datScriptCalcFloat(0x21, 0);
    scaledTerm = powerTerm * fGpffff811c;
    datScriptSetResult(scaledTerm);
}

