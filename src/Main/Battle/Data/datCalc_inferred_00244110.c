#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
extern s32 datScriptTargetIsNotEnemy(void);
extern f32 datScriptCalcFloat(s32 term, s32 parameter);
#include "datScript_internal.h"

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00635990[];
extern u8 D_006359A0[];
extern u8 D_006359B0[];
extern u8 D_006359C0[];

extern f32 D_00761260;
/* fGpffff811c: scale on the attacker-side term when the target is an enemy [inferred]. */
extern f32 fGpffff811c;
static inline f32 mul_f32_ordered(f32 left, f32 right)
{
    return left * right;
}
/* Two scripted damage formulas, datScriptCalcPhysicalDamage and datScriptCalcMagicDamage,
   driven by datScriptCalcFloat selectors and the fGpffff* float constants (documented beside
   their externs). Each is a separate retail function with its own C body. */

/* Source unit: src/promoted/code1_0024.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 00244110-00244540 */

// Intent: Compute physical damage from attacker STR, defender END, skill base power, status resistance and level factors; the flag-4 target split picks one of two formulas [inferred]
// FUN_00244110
void datScriptCalcPhysicalDamage(void)
{
    extern s32 datScriptCmdFlag2Set(void);
    extern f32 sqrtf(f32);
    /* fGpffff82c0: multiplier on the flag-2 branch of the enemy-target physical formula [inferred]. */
    extern f32 fGpffff82c0;
    /* fGpffff824c: scale on the clamped result, after the 30-point offset (datScriptCalcPhysicalDamage) [inferred]. */
    extern f32 fGpffff824c;
    f32 damageTerm;
    f32 scaledTerm;
    f32 powerTerm;
    f32 levelTerm;
    f32 divisor;

    if (datScriptCmdFlag2Set() != 0) {
        if (datScriptTargetIsNotEnemy() != 0) {
            damageTerm = datScriptCalcFloat(0xE, 2);
            damageTerm += datScriptCalcFloat(0xE, 2);
            powerTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0) / 2.0f;
            powerTerm = mul_f32_ordered(30.0f, powerTerm);
            scaledTerm = 5.0f * damageTerm;
            damageTerm = powerTerm / scaledTerm;
            scaledTerm = datScriptCalcFloat(0xD, 0) / 5.0f;
            scaledTerm = mul_f32_ordered(damageTerm, scaledTerm);
            powerTerm = sqrtf(scaledTerm);
            damageTerm = 10.0f * powerTerm;
            damageTerm *= datScriptCalcFloat(DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT, 0);
            damageTerm *= datScriptCalcFloat(DAT_SCRIPT_TERM_LEVEL_FACTOR, 0);
        } else {
            damageTerm = datScriptCalcFloat(0x20, 0) / 4.0f;
            divisor = 2.0f;
            scaledTerm = datScriptCalcFloat(0xE, 2);
            levelTerm = damageTerm / divisor;
            powerTerm = levelTerm + divisor * scaledTerm;
            scaledTerm = fGpffff811c * powerTerm;
            damageTerm = scaledTerm;
            powerTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0);
            powerTerm = mul_f32_ordered(30.0f, powerTerm);
            scaledTerm = mul_f32_ordered(5.0f, damageTerm);
            damageTerm = powerTerm / scaledTerm;
            scaledTerm = datScriptCalcFloat(0xD, 0) / 5.0f;
            scaledTerm = mul_f32_ordered(damageTerm, scaledTerm);
            powerTerm = sqrtf(scaledTerm);
            damageTerm = 10.0f * powerTerm;
            damageTerm *= datScriptCalcFloat(DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT, 0);
            powerTerm = damageTerm * datScriptCalcFloat(DAT_SCRIPT_TERM_LEVEL_FACTOR, 0);
            damageTerm = fGpffff82c0 * powerTerm;
        }
    } else {
        if (datScriptTargetIsNotEnemy() != 0) {
            damageTerm = datScriptCalcFloat(0xE, 2);
            damageTerm += datScriptCalcFloat(0xE, 2);
            powerTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0);
            powerTerm = mul_f32_ordered(30.0f, powerTerm);
            scaledTerm = 5.0f * damageTerm;
            damageTerm = powerTerm / scaledTerm;
            scaledTerm = datScriptCalcFloat(0xD, 0) / 5.0f;
            scaledTerm = mul_f32_ordered(damageTerm, scaledTerm);
            powerTerm = sqrtf(scaledTerm);
            damageTerm = 10.0f * powerTerm;
            damageTerm *= datScriptCalcFloat(DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT, 0);
            damageTerm *= datScriptCalcFloat(DAT_SCRIPT_TERM_LEVEL_FACTOR, 0);
        } else {
            damageTerm = datScriptCalcFloat(0x20, 0) / 2.0f;
            divisor = 2.0f;
            scaledTerm = datScriptCalcFloat(0xE, 2);
            levelTerm = damageTerm / divisor;
            powerTerm = levelTerm + divisor * scaledTerm;
            scaledTerm = fGpffff811c * powerTerm;
            damageTerm = scaledTerm;
            powerTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0);
            powerTerm = mul_f32_ordered(30.0f, powerTerm);
            scaledTerm = mul_f32_ordered(5.0f, damageTerm);
            damageTerm = powerTerm / scaledTerm;
            scaledTerm = datScriptCalcFloat(0xD, 0) / 5.0f;
            scaledTerm = mul_f32_ordered(damageTerm, scaledTerm);
            powerTerm = sqrtf(scaledTerm);
            damageTerm = 10.0f * powerTerm;
            powerTerm = damageTerm * datScriptCalcFloat(DAT_SCRIPT_TERM_LEVEL_FACTOR, 0);
            damageTerm = powerTerm - 30.0f;
            if (damageTerm <= 0.0f)
                damageTerm = 1.0f;
            damageTerm *= fGpffff824c;
            damageTerm *= datScriptCalcFloat(DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT, 0);
        }
    }
    datScriptSetResult(damageTerm);
}

// Intent: Compute magic damage from attacker MAG, defender END and skill base power, with the same level and resistance factors as the physical formula [inferred]
// FUN_00244540
void datScriptCalcMagicDamage(void)
{
    extern f32 sqrtf(f32);
    /* fGpffff824c: scale on the clamped result, after the 30-point offset (datScriptCalcMagicDamage) [inferred]. */
    extern f32 fGpffff824c;
    f32 damageTerm;
    f32 baseDamage;
    f32 scaledTerm;
    f32 powerTerm;
    f32 combinedTerm;
    f32 divisor;

    if (datScriptTargetIsNotEnemy() != 0) {
        damageTerm = datScriptCalcFloat(0xE, 2);
        damageTerm += datScriptCalcFloat(0xE, 2);
        powerTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0);
        powerTerm = mul_f32_ordered(30.0f, powerTerm);
        scaledTerm = 5.0f * damageTerm;
        damageTerm = powerTerm / scaledTerm;
        scaledTerm = datScriptCalcFloat(0xD, 1) / 5.0f;
        scaledTerm = mul_f32_ordered(damageTerm, scaledTerm);
        powerTerm = sqrtf(scaledTerm);
        baseDamage = 10.0f * powerTerm;
        baseDamage *= datScriptCalcFloat(DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT, 0);
        damageTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_LEVEL_FACTOR, 0);
        scaledTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_MAGIC_TIER_BONUS, 0);
        damageTerm = scaledTerm + baseDamage * damageTerm;
    } else {
        damageTerm = datScriptCalcFloat(0x20, 0) / 2.0f;
        divisor = 2.0f;
        scaledTerm = datScriptCalcFloat(0xE, 2);
        combinedTerm = damageTerm / divisor;
        powerTerm = combinedTerm + divisor * scaledTerm;
        scaledTerm = fGpffff811c * powerTerm;
        damageTerm = scaledTerm;
        powerTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0);
        powerTerm = mul_f32_ordered(30.0f, powerTerm);
        scaledTerm = mul_f32_ordered(5.0f, damageTerm);
        damageTerm = powerTerm / scaledTerm;
        scaledTerm = datScriptCalcFloat(0xD, 1) / 5.0f;
        scaledTerm = mul_f32_ordered(damageTerm, scaledTerm);
        powerTerm = sqrtf(scaledTerm);
        baseDamage = 10.0f * powerTerm;
        damageTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_LEVEL_FACTOR, 0);
        scaledTerm = datScriptCalcFloat(DAT_SCRIPT_TERM_MAGIC_TIER_BONUS, 0);
        combinedTerm = scaledTerm + baseDamage * damageTerm;
        scaledTerm = 30.0f;
        damageTerm = combinedTerm - scaledTerm;
        if (damageTerm <= 0.0f)
            damageTerm = 1.0f;
        damageTerm *= 2.0f;
        damageTerm *= datScriptCalcFloat(DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT, 0);
    }
    datScriptSetResult(damageTerm);
}

