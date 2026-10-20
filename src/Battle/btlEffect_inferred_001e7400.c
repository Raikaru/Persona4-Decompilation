#include "btl_effect_internal.h"
#include "btl_action_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "byte_address_internal.h"
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
extern u8 *btlActionFindById();
extern void *D_00609850[];
extern s32 datCalcMaxHp();
extern s64 scrGetParamInt();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */

extern s32 datCalcGetHp();
extern u16 datCalcMaxSp();
extern s32 datCalcGetSp();

extern u8 *scrGetAiState();

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 limit);
extern u8 *btlAICommandPickUnitByHpWeight();
extern s32 btlSideSelectUnits();


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern u8 *btlActionGetQueueSecond(void);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001e7400-001e8a80 */

/* Return the opposite side selector for the action actor. */
static inline u16 btlEffectGetOpposingGenus(u32 unit)
{
    u32 side;
    if (((BtlAction *)unit)->unit->genus != 0)
        goto nonzero;
    side = 1;
    goto done;
nonzero:
    side = 0;
done:
    return side;
}
/* measured: object 264B vs window 272B, normalized_diff 10; remaining differences are register colouring. Committed at nd 10. */
/* Select a side-filtered candidate, preferring the current global selection when present; return its encoded action ID or -1. */
// FUN_001E7400
s32 btlEffectScriptSelectSideUnit(void) {
    extern s32 btlSideSelectUnits();
    extern u32 datCalcRandomBelow(u32 limit);
    extern s32 scrGetParamInt(s32 paramIdx);
    extern void scrSetReturnInt(s32 retVal);
    extern u8 *scrGetAiState(void);
    u8 *formation;
    u16 count;
    int selected;
    u32 unit;
    u32 selector;
    u16 index;
    int candidates[12];

    unit = (u32)scrGetAiState();
    selector = (u32)scrGetParamInt(0);
    count = btlSideSelectUnits(unit, selector, 0x80000, 1, 1,
                          &btlCond_MYHOJO, candidates);
    if (count > 0) {
        index = 0;
        formation = iGpffffb3ac;
        while (index < count) {
            if ((s32)((BtlBattleState *)(formation))->selectedAction == candidates[index]) {
                break;
            }
            index++;
        }
        if (index == count) {
            selected = candidates[datCalcRandomBelow(count)];
        } else {
            selected = (s32)((BtlBattleState *)(formation))->selectedAction;
        }
        scrSetReturnInt((s32)((BtlAction *)selected)->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* Scan side candidates for a nonzero level; retail keeps the last such entry, despite the older highest-level name. */
// FUN_001E7510
s32 btlEffectScriptSelectHighestLevelUnit(void) {
    extern s32 btlSideSelectUnits();
    extern s32 datCalcRandomBelow();
    extern s32 datCalcGetLevel();
    extern s64 scrGetParamInt();
    extern void scrSetReturnInt();
    extern u8 *scrGetAiState();
    u8 *selected;
    s32 index;
    s32 count;
    u8 *action;
    u8 *candidateSlot;
    u8 *candidates[12];

    action = scrGetAiState();
    count = btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 2, 1, &btlCond_MYHOJO, candidates) & 0xFFFF;
    if (count > 0) {
        selected = NULL;
        index = 0;
        goto loop_test;
loop_body:
        candidateSlot = (u8 *)&candidates[(u16)index];
        if ((datCalcGetLevel((s32)((BtlAction *)*(u8 **)candidateSlot)->unit->datUnit) & 0xFF) > 0) {
            selected = *(u8 **)candidateSlot;
        }
        index = (index + 1) & 0xFFFF;
loop_test:
        if ((index & 0xFFFF) < count)
            goto loop_body;
        if (selected == NULL)
            selected = candidates[datCalcRandomBelow(count & 0xFFFF)];
        scrSetReturnInt((s32)((BtlAction *)selected)->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

#pragma push
/* measured: btlEffectScriptPickRandomHighestOpposingUnit MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20b7 (p4flow AI.json AI_FUNCTION_00B7). */
/* Collect living opposing candidates at the highest level, then choose one uniformly and return its encoded ID. */
// FUN_001E7640
s32 btlEffectScriptPickRandomHighestOpposingUnit(void)
{
    BtlAction *candidateFields;
    extern s32 btlEffectCollectTargetUnits(u32, void *, s32, s32, s32);
    extern u8 *scrGetAiState(void);
    extern u32 datCalcRandomBelow(u32);
    extern s32 datCalcGetLevel(u8 *);
    extern s32 datCalcIsDead(s32, s32);
    extern void scrSetReturnInt(s32);
    struct {
        s32 entries[14];
        u16 count;
        u16 selected;
    } candidates;
    s32 selected[12];
    u8 *unit;
    u16 desired;
    u32 highest;
    u16 index;
    u16 selectedCount;
    s32 candidate;
    u32 value;
    u32 desiredValue;

    unit = scrGetAiState();
    desired = btlEffectGetOpposingGenus((u32)unit);
    btlEffectCollectTargetUnits((u32)unit, &candidates, 2, 0, 0);
    highest = 0;
    selectedCount = 0;
    index = 0;
    desiredValue = desired;
    while (index < candidates.count) {
        candidate = candidates.entries[index];
        candidateFields = (BtlAction *)candidate;
        if (((((BtlAction *)(candidate))->unk_1a & 1) != 0) &&
            ((((BtlAction *)(candidate))->unk_1a & 8) != 0) &&
            (((BtlUnit *)((s32)((BtlAction *)(candidate))->unit))->genus == desiredValue) &&
            (datCalcIsDead((s32)((BtlUnit *)((s32)((BtlAction *)(candidate))->unit))->datUnit, 0) == 0)) {
            value = (u32)(datCalcGetLevel((u8 *)(s32)((BtlUnit *)((s32)candidateFields->unit))->datUnit) & 0xFF);
            if (value == highest) {
                selected[selectedCount] = candidate;
                selectedCount++;
            } else if (highest < value) {
                highest = value;
                selected[0] = candidate;
                selectedCount = 1;
            }
        }
        index++;
    }
    if (selectedCount > 0) {
        value = datCalcRandomBelow(selectedCount);
        scrSetReturnInt((s32)((BtlAction *)(selected[value]))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

#pragma pop
/* AI script command 0x20d1 (p4flow AI.json AI_FUNCTION_00D1). */
/* Scan candidates by level and HP; retail keeps the HP bound across level increases rather than resetting it. */
// FUN_001E77F0
s32 btlEffectScriptPickHighestLevelHpUnit(void) {
    BtlAction *candidateFields;
    BtlAction *actionFields;
    extern s32 datCalcGetLevel();
    u8 *action;
    u32 hp;
    u8 *candidate;
    u8 *selected;
    u32 index;
    u32 level;
    u32 highestHp;
    u32 highestLevel;

    action = scrGetAiState();
    actionFields = (BtlAction *)action;
    if (btlAICommandSelectCandidates(action, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        if (((BtlAction *)(action))->unk_6a == 1) {
            selected = ((BtlAction *)(action))->targets[0];
        } else {
            selected = NULL;
            highestLevel = 0;
            highestHp = 0;
            index = 0;
            goto loop_test;
loop_body:
            candidate = ((BtlAction *)(action))->targets[index];
            candidateFields = (BtlAction *)candidate;
            level = datCalcGetLevel((s32)((BtlUnit *)((u8 *)((BtlAction *)(candidate))->unit))->datUnit) & 0xFF;
            if (level >= highestLevel) {
                hp = datCalcGetHp((s32)((BtlUnit *)((u8 *)candidateFields->unit))->datUnit) & 0xFFFF;
                if (highestHp < hp) {
                    selected = candidate;
                    highestHp = hp;
                }
                highestLevel = level;
            }
            index += 1;
loop_test:
            if (index < actionFields->unk_6a)
                goto loop_body;
        }
        scrSetReturnInt((s32)((BtlAction *)(selected))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return -1;
}

/* AI script command 0x20d2 (p4flow AI.json AI_FUNCTION_00D2). */
/* Gather candidates without non-down bad status and choose one uniformly; no candidates yields script return -1. */
// FUN_001E7950
s32 btlEffectScriptPickRandomNoBadStatusUnit(void) {
    extern s32 datCalcGetBadStatusNoDown();
    u8 *action;
    s32 index;
    s32 count;
    u16 candidateCount;
    u8 *candidate;
    u8 *candidates[12];

    action = scrGetAiState();
    if (btlAICommandSelectCandidates(action, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = 0;
        index = 0;
        goto loop_test;
loop_body:
        candidate = ((BtlAction *)(action))->targets[(u16)index];
        if (!(datCalcGetBadStatusNoDown((s32)((BtlUnit *)((u8 *)((BtlAction *)candidate)->unit))->datUnit) & 0xFFEFFFFF)) {
            candidates[count & 0xFFFF] = candidate;
            count = (count + 1) & 0xFFFF;
        }
        index = (index + 1) & 0xFFFF;
loop_test:
        if ((index & 0xFFFF) < (s32)((BtlAction *)action)->unk_6a)
            goto loop_body;
        candidateCount = count & 0xFFFF;
        if (candidateCount == 0) {
            scrSetReturnInt(-1);
        } else {
            scrSetReturnInt((s32)((BtlAction *)(candidates[datCalcRandomBelow(candidateCount)]))->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return -1;
}

/* SUPERSEDED, kept for history: "normalized_diff 1; the sole residual is the
   retail daddiu/addiu width at the count reset. Committed at nd 1." That width
   was believed unreachable. It is not - see the measured note below. */
/* measured: u16 count reaches retail daddiu s1,zero,1; fused
   candidates[count++] produces addiu v0,s1,1 from the unmasked counter,
   avoiding reuse of the masked index. Object 364B/window 368B,
   normalized_diff 0. */
/* AI script command 0x20d3 (p4flow AI.json AI_FUNCTION_00D3). */
/* Collect all candidates tied at the maximum level, then choose one uniformly and return its encoded action ID. */
// FUN_001E7AB0
s32 btlEffectScriptPickRandomHighestLevelUnit(void) {
    BtlAction *actionFields;
    extern s32 btlAICommandSelectCandidates();
    extern void btlAICommandNomalCheckNoGate();
    extern s32 datCalcRandomBelow();
    extern s32 datCalcGetLevel();
    extern s64 scrGetParamInt();
    extern void scrSetReturnInt();
    extern u8 *scrGetAiState();
    u8 *action;
    u32 index;
    u32 highestLevel;
    u16 count;
    u8 *candidate;
    u32 level;
    u8 *candidates[12];
    u8 *selected;

    action = scrGetAiState();
    actionFields = (BtlAction *)action;
    if (btlAICommandSelectCandidates(action, scrGetParamInt(0), 0, 0x2C, 1, &btlAICommandNomalCheckNoGate) == 1) {
        if (((BtlAction *)(action))->unk_6a == 1) {
            selected = ((BtlAction *)(action))->targets[0];
        } else {
            count = 0;
            highestLevel = 0;
            index = 0;
            goto loop_test;
loop_body:
            candidate = ((BtlAction *)(action))->targets[index];
            level = (u32)(datCalcGetLevel((s32)((BtlAction *)candidate)->unit->datUnit) & 0xFF);
            if (level >= highestLevel) {
                if (level == highestLevel) {
                    candidates[count++] = candidate;
                } else {
                    highestLevel = level;
                    candidates[0] = candidate;
                    count = 1;
                }
            }
            index += 1;
loop_test:
            if (index < actionFields->unk_6a)
                goto loop_body;
            selected = candidates[datCalcRandomBelow(count & 0xFFFF)];
        }
        scrSetReturnInt((s32)((BtlAction *)(selected))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return -1;
}

/* AI script command 0x20da (p4flow AI.json AI_FUNCTION_00DA). */
/* Count collected candidates without non-down bad status and return the sixteen-bit count to the script. */
// FUN_001E7C20
s32 btlEffectScriptCountNoBadStatusUnits(void) {
    extern s32 btlAICommandSelectCandidates();
    extern s32 datCalcGetBadStatusNoDown();
    extern s64 scrGetParamInt();
    extern void scrSetReturnInt();
    extern u8 *scrGetAiState();
    u8 *action;
    s32 index;
    s32 count;

    action = scrGetAiState();
    if (btlAICommandSelectCandidates(action, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        count = 0;
        index = 0;
        goto loop_test;
loop_body:
        if (!(datCalcGetBadStatusNoDown((s32)((BtlAction *)((BtlAction *)(action))->targets[(u16)index])->unit->datUnit) & 0xFFEFFFFF)) {
            count = (count + 1) & 0xFFFF;
        }
        index = (index + 1) & 0xFFFF;
loop_test:
        if ((index & 0xFFFF) < (s32)((BtlAction *)action)->unk_6a)
            goto loop_body;
        scrSetReturnInt(count & 0xFFFF);
    } else {
        scrSetReturnInt(0);
    }
    return -1;
}

/* AI script command 0x20E5 (p4flow AI.json AI_FUNCTION_00E5). */
/* Read the requested action or unit property and publish it as the AI script integer return value. */
// FUN_001E7D30
s32 btlEffectScriptGetCurrentUnit(void) {
    u8 *temp;

    temp = scrGetAiState();
    scrSetReturnInt((s32)((BtlAction *)temp)->id | 0x80000000);
    return 1;
}

/* AI script command 0x20E6 (p4flow AI.json AI_FUNCTION_00E6). */
/* Read the requested action or unit property and publish it as the AI script integer return value. */
// FUN_001E7D70
s32 btlEffectScriptGetMaxHp(void) {
    scrSetReturnInt(datCalcMaxHp((s32)((BtlAction *)btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF))->unit->datUnit) & 0xFFFF);
    return 1;
}

/* AI script command 0x20E7 (p4flow AI.json AI_FUNCTION_00E7). */
/* Read the requested action or unit property and publish it as the AI script integer return value. */
// FUN_001E7DD0
s32 btlEffectScriptGetHp(void) {
    scrSetReturnInt(datCalcGetHp((s32)((BtlAction *)btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF))->unit->datUnit) & 0xFFFF);
    return 1;
}

/* AI script command 0x20E8 (p4flow AI.json AI_FUNCTION_00E8). */
/* Read the requested action or unit property and publish it as the AI script integer return value. */
// FUN_001E7E30
s32 btlEffectScriptGetSlotUnit(void) {
    u8 *temp;

    temp = btlActionGetQueueSecond();
    scrSetReturnInt((s32)((BtlAction *)temp)->id | 0x80000000);
    return 1;
}

/* AI script command 0x20E9 (p4flow AI.json AI_FUNCTION_00E9). */
/* Read the requested action or unit property and publish it as the AI script integer return value. */
// FUN_001E7E70
// measured: the status byte/halfword gates the signed-byte payload; the
// payload is read only when neither gate is active.
s32 btlEffectScriptGetStatusByte(void)
{
    u8 *base;
    u8 *payload;
    s32 value;

    base = (u8 *)((BtlAction *)(btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF)))->unit;
    if (((BtlUnit *)(base))->genus == 0 && ((BtlUnit *)(base))->charId != 1) {
        payload = (u8 *)((BtlUnit *)(base))->datUnit;
        value = ((DatUnit *)(payload))->aiTactic;
    } else {
        value = -1;
    }
    scrSetReturnInt(value);
    return 1;
}

/* AI script command 0x20EE (p4flow AI.json AI_FUNCTION_00EE). */
/* Read the requested action or unit property and publish it as the AI script integer return value. */
// FUN_001E7EF0
s32 btlEffectScriptGetMaxSp(void) {
    scrSetReturnInt(datCalcMaxSp((s32)((BtlAction *)btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF))->unit->datUnit) & 0xFFFF);
    return 1;
}

/* AI script command 0x20EF (p4flow AI.json AI_FUNCTION_00EF). */
/* Read the requested action or unit property and publish it as the AI script integer return value. */
// FUN_001E7F50
s32 btlEffectScriptGetSp(void) {
    scrSetReturnInt(datCalcGetSp((s32)((BtlAction *)btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF))->unit->datUnit) & 0xFFFF);
    return 1;
}

/* AI script command 0x20F0 (p4flow AI.json AI_FUNCTION_00F0). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E7FB0
s32 btlEffectScriptPickRandomCandidate(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2E, 0, &btlCond_MYHOJO) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt((s32)((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            scrSetReturnInt((s32)((BtlAction *)(((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0]))->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f1 (p4flow AI.json AI_FUNCTION_00F1). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E8090
s32 btlEffectScriptPickHansyaUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYHANSYA) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt((s32)((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = ((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0];
            }
            scrSetReturnInt((s32)((BtlAction *)result)->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f2 (p4flow AI.json AI_FUNCTION_00F2). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E8190
s32 btlEffectScriptPickKyusyuUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYKYUSYU) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt((s32)((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = ((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0];
            }
            scrSetReturnInt((s32)((BtlAction *)result)->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f3 (p4flow AI.json AI_FUNCTION_00F3). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E8290
s32 btlEffectScriptPickMukouUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYMUKOU) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt((s32)((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = ((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0];
            }
            scrSetReturnInt((s32)((BtlAction *)result)->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f4 (p4flow AI.json AI_FUNCTION_00F4). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E8390
s32 btlEffectScriptPickTaiseiUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYTAISEI) == 1) {
        count = ((BtlAction *)work)->unk_6a;
        if (count == 1) {
            scrSetReturnInt((s32)((BtlAction *)(((BtlAction *)(work))->targets[0]))->id | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = ((BtlAction *)(byteAddressAdd((u32)datCalcRandomBelow(count) * 4, work)))->targets[0];
            }
            scrSetReturnInt((s32)((BtlAction *)result)->id | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2080 (p4flow AI.json AI_FUNCTION_0080). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E8490
s32 btlEffectScriptPickLowestHpWeakUnit(void) {
    BtlAction *workFields;
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    workFields = (BtlAction *)work;
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        if (((BtlAction *)(work))->unk_6a == 1) {
            selected = ((BtlAction *)(work))->targets[0];
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < workFields->unk_6a) {
                entry = ((BtlAction *)(work))->targets[index];
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)(selected))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2081 (p4flow AI.json AI_FUNCTION_0081). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E85C0
s32 btlEffectScriptPickLowestHpWeakFilteredUnit(void) {
    BtlAction *workFields;
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    workFields = (BtlAction *)work;
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        if (((BtlAction *)(work))->unk_6a == 1) {
            selected = ((BtlAction *)(work))->targets[0];
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < workFields->unk_6a) {
                entry = ((BtlAction *)(work))->targets[index];
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)(selected))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2082 (p4flow AI.json AI_FUNCTION_0082). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E86F0
s32 btlEffectScriptPickLowestHpWeakWideUnit(void) {
    BtlAction *workFields;
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    workFields = (BtlAction *)work;
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2F, 0, &btlCond_MYWEAK) == 1) {
        if (((BtlAction *)(work))->unk_6a == 1) {
            selected = ((BtlAction *)(work))->targets[0];
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < workFields->unk_6a) {
                entry = ((BtlAction *)(work))->targets[index];
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)(selected))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f5 (p4flow AI.json AI_FUNCTION_00F5). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E8820
s32 btlEffectScriptPickHighestHpWeakUnit(void) {
    BtlAction *workFields;
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    workFields = (BtlAction *)work;
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        if (((BtlAction *)(work))->unk_6a == 1) {
            selected = ((BtlAction *)(work))->targets[0];
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < workFields->unk_6a) {
                entry = ((BtlAction *)(work))->targets[index];
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value >= min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)(selected))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f6 (p4flow AI.json AI_FUNCTION_00F6). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E8950
s32 btlEffectScriptPickHighestHpWeakFilteredUnit(void) {
    BtlAction *workFields;
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    workFields = (BtlAction *)work;
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        if (((BtlAction *)(work))->unk_6a == 1) {
            selected = ((BtlAction *)(work))->targets[0];
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < workFields->unk_6a) {
                entry = ((BtlAction *)(work))->targets[index];
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value >= min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)(selected))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f7 (p4flow AI.json AI_FUNCTION_00F7). */
/* Select an AI candidate and return its encoded action ID (high bit set), or -1 when candidate collection fails. */
// FUN_001E8A80
s32 btlEffectScriptPickHighestHpWeakWideUnit(void) {
    BtlAction *workFields;
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    workFields = (BtlAction *)work;
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2F, 0, &btlCond_MYWEAK) == 1) {
        if (((BtlAction *)(work))->unk_6a == 1) {
            selected = ((BtlAction *)(work))->targets[0];
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < workFields->unk_6a) {
                entry = ((BtlAction *)(work))->targets[index];
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value >= min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)(selected))->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

