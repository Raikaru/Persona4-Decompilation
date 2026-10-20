#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
typedef signed __int128 s128;
typedef struct P4Vec4_001EC2B0 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 {
    P4Vec4_001EC2B0 quat;
} P4Vec4Holder_001EC2B0;
typedef struct P4RouteSlerp_001EF110 {
    P4Vec4_001EC2B0 first;
    P4Vec4_001EC2B0 second;
    f32 angle;
    s32 mode;
} P4RouteSlerp_001EF110;
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *config);
extern void *D_00609850[];
extern s64 scrGetParamInt();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
extern s32 scrGetParamIntS32(s32 index);
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
extern s32 datCalcGetHp();

extern u8 *scrGetAiState();

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 limit);
extern u8 *btlEffectFindUnitByIdAndStatus();
extern u8 *btlAICommandPickUnitByHpWeight();


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern u32 datCalcRandomBelow(u32 limit);



extern void *D_00609CE0[];
extern void *D_00609D20[];
extern f32 D_00881400[];
extern f32 D_00881404[];
extern f32 D_00881408[];
extern f32 D_00881420[];
extern f32 D_00881424[];
extern f32 D_00881428[];
extern f32 fGpffffb458;
extern u8 *iGpffffb3b8;
extern u8 D_00609E30[];
extern f32 D_008813F0[];
extern f32 D_008813F4[];
extern f32 D_008813F8[];
extern f32 D_00881410[];
extern f32 D_00881414[];
extern f32 D_00881418[];
extern f32 fGpffffb454;
extern u8 D_00609E40[];
extern s32 datCalcGetHp(s32 unit);
extern s32 datCalcIsDead(s32 unit, s32 hpDelta);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001e6d20-001e6ea0 */

/* AI script command 0x207b (p4flow AI.json AI_FUNCTION_007B). */
/* Resolve kind 0 or 1 to its fixed side/status search and publish the matching action ID; retail assumes a result. */
// FUN_001E6D20
s32 btlEffectScriptPickUnitByKind(void) {
    s32 first;
    s32 second;
    s32 kind;
    u8 *result;

    first = scrGetParamIntS32(0) & 0xFFFF;
    second = scrGetParamIntS32(1) & 0xFFFF;
    result = 0;
    kind = first & 0xFFFF;
    switch (kind) {
    case 0:
        result = btlEffectFindUnitByIdAndStatus(second, 1, 0);
        break;
    case 1:
        result = btlEffectFindUnitByIdAndStatus(second, 2, 0x80000);
        break;
    }
    scrSetReturnInt((s32)((BtlAction *)result)->id | 0x80000000);
    return 1;
}

/* AI script command 0x207c (p4flow AI.json AI_FUNCTION_007C). */
/* Find the lowest-current-HP living genus-1 action and publish its encoded ID; retail assumes one exists. */
// FUN_001E6DC0
s32 btlEffectScriptPickLowestHpLivingSide1Unit(void) {
    BtlAction *currentFields;
    u8 *current;
    u8 *best;
    u32 min;
    u16 flags;
    u8 *entry;
    u32 value;

    best = NULL;
    min = 0x0FFFFFFF;
    current = ((BtlBattleState *)(iGpffffb3ac))->actions;
    currentFields = (BtlAction *)current;
    while (current != NULL) {
        flags = ((BtlAction *)(current))->unk_1a;
        if ((flags & 1) && (flags & 8)) {
            entry = (u8 *)currentFields->unit;
            if (((BtlUnit *)(entry))->genus == 1 &&
                datCalcIsDead((s32)((BtlUnit *)(entry))->datUnit, 0) == 0) {
                value = datCalcGetHp((s32)((BtlAction *)current)->unit->datUnit) & 0xFFFF;
                if (value < min) {
                    best = current;
                    min = value;
                }
            }
        }
        current = (u8 *)((BtlAction *)(current))->next;
        currentFields = (BtlAction *)current;
    }
    scrSetReturnInt((s32)((BtlAction *)(best))->id | 0x80000000);
    return 1;
}

/* AI script command 0x207d (p4flow AI.json AI_FUNCTION_007D). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E6EA0
s32 btlEffectScriptPickWeakCandidateUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt((s32)((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = ((BtlAction *)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work)))->targets[0];
            }
            scrSetReturnInt((s32)((BtlAction *)result)->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

