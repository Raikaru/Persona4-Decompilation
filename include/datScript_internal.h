#ifndef DATSCRIPT_INTERNAL_H
#define DATSCRIPT_INTERNAL_H

#include "type.h"

/* Formula kinds for datScriptRunCalc: the index into D_00635950 (arg0 < 0xB).
   Kind 0 (func_00244100) is unnamed and omitted. Kind 1 is named for its handler (physical damage) but datCalc.c also uses it for healing. */
typedef enum DatScriptCalcKind {
    DAT_SCRIPT_CALC_PHYSICAL_DAMAGE = 1,         /* datScriptCalcPhysicalDamage */
    DAT_SCRIPT_CALC_MAGIC_DAMAGE = 2,            /* datScriptCalcMagicDamage */
    DAT_SCRIPT_CALC_TERMS_13_AND_1A = 3,         /* datCalcFormulaTerms13And1A */
    DAT_SCRIPT_CALC_HIT_RATE = 4,                /* datScriptCalcHitRate */
    DAT_SCRIPT_CALC_SCALED_RATIO = 5,            /* datCalcFormulaScaledRatio */
    DAT_SCRIPT_CALC_PASS_CALC_15 = 6,            /* datCalcFormulaPassCalc15 */
    DAT_SCRIPT_CALC_WEIGHTED_RATIO = 7,          /* datCalcFormulaWeightedRatio */
    DAT_SCRIPT_CALC_INVERSE_RATIO = 8,           /* datCalcFormulaInverseRatio */
    DAT_SCRIPT_CALC_PHYSICAL_DAMAGE_SCALED = 9,  /* datScriptCalcPhysicalDamageScaled */
    DAT_SCRIPT_CALC_RATIO_OF_PRODUCTS = 10       /* datCalcFormulaRatioOfProducts */
} DatScriptCalcKind;

/* Term selectors for datScriptCalcFloat(arg0, arg1). A separate space from
   DatScriptCalcKind: selector 1 is unit 1's level, not physical damage. Only
   selectors read by a named caller are listed; the rest of 1..34 are unnamed. */
typedef enum DatScriptTermKind {
    DAT_SCRIPT_TERM_TARGET_AFFINITY_PCT = 0xC,   /* case 12: element resistance of unit 2, percent */
    DAT_SCRIPT_TERM_SKILL_POWER = 0x13,          /* case 19: skill base power (arg1 selects the variant) */
    DAT_SCRIPT_TERM_LEVEL_FACTOR = 0x17,         /* case 23: level-difference factor */
    DAT_SCRIPT_TERM_MAGIC_TIER_BONUS = 0x19      /* case 25: tier bonus from stat/10 [inferred: magic formula] */
} DatScriptTermKind;

/* Script command dispatch table: datScriptRunCalc calls D_00635950[kind] (0xB entries, kind 0 = func_00244100). */
extern void (*D_00635950[11])(void);

/* Marks the current script calculation as having a result and stores that value. */
void datScriptSetResult(s32 value);

#endif
