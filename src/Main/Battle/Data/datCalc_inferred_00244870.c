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
extern f32 fGpffff811c;
/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* Source unit: src/promoted/code1_0024.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 00244870-00244870 */

// Intent: Compute a hit rate from attacker and defender AGI (200 + AGI ratio), scaled by the skill accuracy and a guard term when the target carries flag 4 [inferred]
// FUN_00244870
void datScriptCalcHitRate(void)
{
    extern f32 fGpffff824c;
    f32 agilityRatio;
    f32 accuracyTerm;
    f32 hitRate;
    f32 skillAccuracy;

    if (datScriptTargetIsNotEnemy() != 0) {
        accuracyTerm = (200.0f + datScriptCalcFloat(0xD, 3));
        hitRate = (200.0f + datScriptCalcFloat(0xE, 3));
        accuracyTerm = accuracyTerm / hitRate;
        hitRate = accuracyTerm * datScriptCalcFloat(0x11, 0);
    } else {
        accuracyTerm = (200.0f + datScriptCalcFloat(0xD, 3));
        hitRate = (200.0f + datScriptCalcFloat(0xE, 3));
        agilityRatio = accuracyTerm / hitRate;
        accuracyTerm = datScriptCalcFloat(0x1F, 0) / fGpffff824c;
        skillAccuracy = datScriptCalcFloat(0x11, 0) - accuracyTerm;
        if (skillAccuracy <= 0.0f)
            skillAccuracy = 1.0f;
        hitRate = agilityRatio * skillAccuracy;
    }
    datScriptSetResult(hitRate);
}

