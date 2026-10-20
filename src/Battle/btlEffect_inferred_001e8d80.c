#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "btl_ai_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
typedef struct BtlPacket BtlPacket;
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *up);
extern u8 *btlActionFindById();
extern void *D_00609850[];
extern s32 datCalcMaxHp();
extern s64 scrGetParamInt();
extern s32 datCalcGetHp();

extern s32 datCalcSkillElement(u8 *unit, u16 skill);
extern s32 datCalcThresholdTrigger(u8 *unit, s32 skill);
extern s32 datCalcDefaultSkillId(u8 *unit);
extern s32 datCalcGetElementAffinity(u8 *unit, s32 elementIndex);
extern u8 *scrGetAiState();

extern u8 *iGpffffb3ac; /* active battle state */
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 limit);
extern u8 *btlEffectFindUnitByKey();
extern s32 btlAICommandCollectSkillCandidates();
extern s32 btlSideSelectUnits();
extern s32 btlAICommandAlwaysTrue(void);


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



extern void btlAICommandSetActionCode(u8 *action, u8 *work, u16 actionCode);
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
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern s32 datCalcGetHp(s32 unit);
extern s32 datCalcIsDead(s32 unit, s32 hpDelta);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001e8d80-001ea220 */

#pragma push
#pragma pop
/* AI script command 0x2090 (p4flow AI.json AI_FUNCTION_0090). */
// FUN_001E8D80
/* Return the acting unit's default skill element to the AI script. */
s32 btlEffectScriptGetSelfElement(void) {
    scrSetReturnInt((s16) datCalcSkillElement((u8 *)((BtlAction *)scrGetAiState())->unit->datUnit, 0U));
    return 1;
}

/* AI script command 0x209b (p4flow AI.json AI_FUNCTION_009B). */
// FUN_001E8DD0
/* Pick the living genus-0 action with least HP; scripts receive its tagged action id. */
s32 btlEffectScriptPickLowestHpLivingSide0Unit(void) {
    u8 *current;
    u8 *best;
    u32 min;
    u16 flags;
    u8 *entry;
    u32 value;

    best = NULL;
    min = 0x0FFFFFFF;
    current = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (current != NULL) {
        flags = ((BtlAction *)current)->unk_1a;
        if ((flags & 1) && (flags & 8)) {
            entry = (u8 *)((BtlAction *)current)->unit;
            if (((BtlUnit *)entry)->genus == 0 &&
                datCalcIsDead((s32)((BtlUnit *)entry)->datUnit, 0) == 0) {
                /* measured: repeating typed action->unit across the call hoists +30 (232 vs 224 bytes). */
                value = datCalcGetHp((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit) & 0xFFFF;
                if (value < min) {
                    best = current;
                    min = value;
                }
            }
        }
        current = (u8 *)((BtlAction *)current)->next;
    }
    scrSetReturnInt((s32)((BtlAction *)best)->id | 0x80000000);
    return 1;
}

/* AI script command 0x2083 (p4flow AI.json AI_FUNCTION_0083). */
// FUN_001E8EB0
/* Pick the least-HP action among normal candidates, or return -1 when none qualify. */
s32 btlEffectScriptPickLowestHpNormalUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        if (((BtlAction *)work)->unk_6a == 1) {
            selected = ((u8 **)((BtlAiCommandWork *)((BtlAction *)work)->unk_38)->targets)[0];
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            /* measured: typing both count reads hoists +6A (312 vs 304 bytes). */
            while (index < *(u16 *)(work + 0x6A)) {
                /* measured: a typed indexed target reverses the addu operands. */
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)selected)->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2084 (p4flow AI.json AI_FUNCTION_0084). */
// FUN_001E8FE0
/* Pick the least-HP normal candidate with the extra 0x100000 selection filter. */
s32 btlEffectScriptPickLowestHpNormalFilteredUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        if (((BtlAction *)work)->unk_6a == 1) {
            selected = ((u8 **)((BtlAiCommandWork *)((BtlAction *)work)->unk_38)->targets)[0];
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            /* measured: repeated typed count reads hoist +6A into a saved register. */
            while (index < *(u16 *)(work + 0x6A)) {
                /* Preserve the work-first addu operands used for this indexed target. */
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)selected)->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2085 (p4flow AI.json AI_FUNCTION_0085). */
// FUN_001E9110
/* Pick the least-HP normal candidate using selector 0x2D instead of 0x2C. */
s32 btlEffectScriptPickLowestHpNormalAltUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2D, 0, &btlCond_MYNOMAL) == 1) {
        if (((BtlAction *)work)->unk_6a == 1) {
            selected = ((u8 **)((BtlAiCommandWork *)((BtlAction *)work)->unk_38)->targets)[0];
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            /* measured: repeated typed count reads hoist +6A into a saved register. */
            while (index < *(u16 *)(work + 0x6A)) {
                /* Preserve the work-first addu operands used for this indexed target. */
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp((s32)((BtlAction *)entry)->unit->datUnit) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt((s32)((BtlAction *)selected)->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2089 (p4flow AI.json AI_FUNCTION_0089). */
// FUN_001E9240
/* Reuse a genus-1 target when available, otherwise randomly choose a living one. */
s32 btlEffectScriptPickRandomSide1Unit(void) {
    u8 *selected;
    u8 *data;
    u8 *entry;
    u16 flags;
    u8 *current;
    s32 count;
    u8 *stack[12];

    selected = btlEffectFindUnitByKey(scrGetAiState() + 0x98);
    if (selected == NULL || ((BtlAction *)selected)->unit->genus != 1) {
        count = 0;
        current = ((BtlBattleState *)iGpffffb3ac)->actions;
        while (current != NULL) {
            flags = ((BtlAction *)current)->unk_1a;
            if ((flags & 1) && (flags & 8)) {
                entry = (u8 *)((BtlAction *)current)->unit;
                if (((BtlUnit *)entry)->genus == 1) {
                    data = (u8 *)((BtlUnit *)entry)->datUnit;
                    if (data == NULL || datCalcIsDead((s32)data, 0) == 0) {
                        stack[count & 0xFFFF] = current;
                        count = (count + 1) & 0xFFFF;
                    }
                }
            }
            current = (u8 *)((BtlAction *)current)->next;
        }
        selected = stack[datCalcRandomBelow(count & 0xFFFF)];
    }
    scrSetReturnInt((s32)((BtlAction *)selected)->id | 0x80000000);
    return 1;
}

/* AI script command 0x208a (p4flow AI.json AI_FUNCTION_008A). */
// FUN_001E9350
/* Find a usable skill element whose target affinity includes mask 0x08000000. */
s32 btlEffectScriptFindAilmentSkillElement(void) {
    u64 command;
    u16 skill;
    u32 index;
    u8 *result;
    u8 *entry;
    u32 count;
    u8 *base;
    u8 *work;
    s32 element;

    work = scrGetAiState();
    command = scrGetParamInt(0);
    result = btlActionFindById((u64)(command << 0x24) >> 0x24);
    entry = (u8 *)((BtlAction *)work)->unit;
    element = (s16)datCalcSkillElement((u8 *)((BtlUnit *)entry)->datUnit, 0);
    if (datCalcGetElementAffinity((u8 *)((BtlAction *)result)->unit->datUnit, element) & 0x08000000) {
        scrSetReturnInt((s16)element);
        return 1;
    }
    /* measured: repeated typed datUnit/action-unit fields hoist addresses across calls (412 vs 400 bytes). */
    count = datCalcGetTableLength(*(DatUnit **)(entry + 0xA64)) & 0xFFFF;
    base = datCalcSkillList(*(DatUnit **)(entry + 0xA64));
    index = 0;
    while (index < count) {
        skill = ((u16 *)base)[index];
        if (skill != 0 && skill < 0x1B8) {
            element = (s16)datCalcSkillElement(*(u8 **)(entry + 0xA64), skill);
            if (datCalcGetElementAffinity((u8 *)((BtlUnit *)*(u8 **)(result + 0x30))->datUnit, element) & 0x08000000) {
                scrSetReturnInt((s16)element);
                return 1;
            }
        }
        index++;
    }
    scrSetReturnInt(-1);
    return 1;
}

/* AI script command 0x208b (p4flow AI.json AI_FUNCTION_008B). */
// FUN_001E94E0
/* Resolve the selected action's key, falling back to a random living genus-1 action. */
s32 btlEffectScriptPickRandomSide1OtherUnit(void) {
    u8 *selected;
    u8 *data;
    u8 *entry;
    u16 flags;
    u8 *current;
    s32 count;
    u8 *stack[12];

    scrGetAiState();
    selected = btlEffectFindUnitByKey(((BtlBattleState *)iGpffffb3ac)->selectedAction + 0x98);
    if (selected == NULL || ((BtlAction *)selected)->unit->genus != 1) {
        count = 0;
        current = ((BtlBattleState *)iGpffffb3ac)->actions;
        while (current != NULL) {
            flags = ((BtlAction *)current)->unk_1a;
            if ((flags & 1) && (flags & 8)) {
                entry = (u8 *)((BtlAction *)current)->unit;
                if (((BtlUnit *)entry)->genus == 1) {
                    data = (u8 *)((BtlUnit *)entry)->datUnit;
                    if (data == NULL || datCalcIsDead((s32)data, 0) == 0) {
                        stack[count & 0xFFFF] = current;
                        count = (count + 1) & 0xFFFF;
                    }
                }
            }
            current = (u8 *)((BtlAction *)current)->next;
        }
        selected = stack[datCalcRandomBelow(count & 0xFFFF)];
    }
    scrSetReturnInt((s32)((BtlAction *)selected)->id | 0x80000000);
    return 1;
}

/* AI script command 0x208c (p4flow AI.json AI_FUNCTION_008C). */
// FUN_001E9600
/* Prefer the least-HP skill-eligible genus-1 target, falling back to least HP. */
s32 btlEffectScriptPickLowestHpSkillEligibleUnit(void) {
    u8 *work;
    u8 *current;
    u8 *bestFallback;
    u8 *bestEligible;
    u32 minimumFallbackHp;
    u32 minimumEligibleHp;
    u16 flags;
    u8 *entry;
    u32 value;

    work = scrGetAiState();
    bestFallback = NULL;
    minimumFallbackHp = 0x0FFFFFFF;
    bestEligible = NULL;
    minimumEligibleHp = 0x0FFFFFFF;
    current = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (current != NULL) {
        flags = ((BtlAction *)current)->unk_1a;
        if ((flags & 1) && (flags & 8)) {
            entry = (u8 *)((BtlAction *)current)->unit;
            if (((BtlUnit *)entry)->genus == 1 &&
                datCalcIsDead((s32)((BtlUnit *)entry)->datUnit, 0) == 0) {
                /* measured: typing both datUnit loads changes saved-register allocation. */
                value = datCalcGetHp(*(s32 *)(entry + 0xA64)) & 0xFFFF;
                if (value < minimumEligibleHp &&
                    btlAICommandCollectSkillCandidates(work, current, 0, 0) >= 0) {
                    bestEligible = current;
                    minimumEligibleHp = value;
                }
                if (value < minimumFallbackHp) {
                    bestFallback = current;
                    minimumFallbackHp = value;
                }
            }
        }
        current = (u8 *)((BtlAction *)current)->next;
    }
    if (bestEligible != NULL) {
        scrSetReturnInt((s32)((BtlAction *)bestEligible)->id | 0x80000000);
    } else {
        scrSetReturnInt((s32)((BtlAction *)bestFallback)->id | 0x80000000);
    }
    return 1;
}

/* AI script command 0x209d (p4flow AI.json AI_FUNCTION_009D). */
// FUN_001E9770
/* Pick least HP within the script's minimum HP, maximum percentage and status mask. */
s32 btlEffectScriptPickLowestHpInRangeUnit(void) {
    extern s32 scrGetParamInt(s32 paramIdx);
    extern void scrSetReturnInt(s32 retVal);
    extern s32 datCalcIsDead(s32 unit, s32 hpDelta);
    extern s32 datCalcGetHp(s32 unit);
    extern s32 datCalcMaxHp(s32 unit);
    u32 storedHp;
    u32 maximumHp;
    s32 maximumPercent;
    s32 minimumHp;
    u8 *current;
    u8 *best;
    u32 hp;
    u32 bestHp;
    s32 statusMask;
    u16 flags;
    u8 *unitData;
    s32 allowDead;
    minimumHp = scrGetParamInt(0);
    maximumPercent = scrGetParamInt(1);
    statusMask = scrGetParamInt(2);
    best = NULL;
    bestHp = 0x0FFFFFFF;
    current = ((BtlBattleState *)iGpffffb3ac)->actions;
    allowDead = statusMask & 0x80000;
    goto loop_test;
loop_body:
    flags = ((BtlAction *)current)->unk_1a;
    if ((flags & 1) == 0)
        goto loop_next;
    if ((flags & 8) == 0)
        goto loop_next;
    if (((BtlAction *)current)->unit->genus != 0)
        goto loop_next;
    /* measured: repeated typed action->unit loads change allocation across the HP/status calls. */
    if ((allowDead == 0) &&
        (datCalcIsDead((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit, 0) != 0))
        goto loop_next;
    hp = datCalcGetHp((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit) & 0xFFFF;
    if ((u32)minimumHp > hp)
        goto loop_next;
    unitData = (u8 *)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit;
    storedHp = ((DatUnit *)unitData)->hp;
    maximumHp = (u32)(datCalcMaxHp((s32)unitData) & 0xFFFF);
    if ((u32)storedHp * 0x64 > maximumHp * (u32)maximumPercent)
        goto loop_next;
    if ((statusMask != 0) &&
        (datCalcChkBadStatus((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit, statusMask) == 0))
        goto loop_next;
    if (hp >= bestHp)
        goto loop_next;
    best = current;
    bestHp = hp;
loop_next:
    current = (u8 *)((BtlAction *)current)->next;
loop_test:
    if (current != NULL)
        goto loop_body;
    if (best != NULL) {
        scrSetReturnInt((s32)((BtlAction *)best)->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* Rank usable skills by the best single target or the accumulated target score.
 * The producer's 0x40-byte target record includes selected@0x3A and flags@0x3C.
 * Register/spill notes (verified MATCH): skill and element are s32 (retail passes
 * skill unnarrowed and re-sign-extends element); func_0023d8e0 and func_001d7f10
 * are declared here with s32 skill parameters, as retail passes $s2 without a
 * mask. Retail spills skillStore, singleTargetElement, groupElement, skillIndex and bestCost; the
 * declaration order (bestTargetId before skillIndex, element before skill, skillStore
 * after singleTargetElement/groupElement) reproduces that spill set and slot order. */
/* AI script command 0x20fa (p4flow AI.json AI_FUNCTION_00FA). */
// FUN_001E9950
s32 btlEffectScriptChooseBestSkill(void) {
    extern s32 scrGetParamInt(s32 paramIdx);
    extern void scrSetReturnInt(s32 retVal);
    extern s32 datCalcElementBit(s16 element);
    extern s32 datCalcSkillElement(u8 *unit, s32 skillId);
    extern u16 btlSkillClassifyTargets(u8 *action, u8 *targets, s32 skill, u32 reverseGroups);
    extern s32 datCalcUsesWeaponProperties(s32 skillId);
    extern u32 datCalcSkillCost(u8 *unit, s32 skillId);
    extern u16 datCalcThresholdKind(u8 *unusedUnit, s32 skillId);
    extern s32 btlAICommandNomalCheck(u8 *formation, s32 index, s32 enabled);
    extern s32 datCalcSkillAmount(s32, u8 *, u8 *, s32, s32, s32, s32, s32);
    extern u8 *btlActionFindById(s32 id);
    extern s32 btlAICommandPickAiTarget(u8 *action, u32 value);
    u8 *work;
    u8 *unit;
    s32 bestSkill;
    s32 bestTarget;
    s32 bestCost;
    f32 skillScore;
    f32 bestScore;
    f32 targetScore;
    u16 *table;
    s32 mode;
    s32 skillLimit;
    s32 bestTargetId;
    u16 skillIndex;
    s32 skillCount;
    s32 element;
    s32 skill;
    s32 groupElement;
    s32 singleTargetElement;
    s32 skillStore;
    u16 targetKind;
    s32 singleTargetIndex;
    s32 groupTargetIndex;
    u8 *singleTarget;
    u8 *groupTarget;
    s32 amount;
    s32 hp;
    s32 maxHp;
    s32 healing;
    s32 cost;
    BtlTargetSelection targets;
    work = scrGetAiState();
    mode = scrGetParamInt(0);
    unit = (u8 *)((BtlAction *)work)->unit;
    bestTarget = 0;
    bestSkill = -1;
    bestCost = 0x3E7;
    bestScore = -1.0f;
    skillLimit = ((datCalcGetTableLength(((BtlUnit *)unit)->datUnit) & 0xFFFF) + 1) & 0xFFFF;
    /* measured: repeated typed datUnit/action-unit loads hoist addresses (1512 vs 1488 bytes). */
    table = (u16 *)datCalcSkillList(*(DatUnit **)(unit + 0xA64));
    skillIndex = 0;
    skillCount = skillLimit & 0xFFFF;
    goto outer_test;
outer_body:
    if (skillIndex == 0) {
        skill = (u16)(datCalcDefaultSkillId(*(u8 **)(unit + 0xA64)) & 0xFFFF);
    } else {
        /* measured: table[skillIndex - 1] changes the halfword address instruction. */
        skill = *(u16 *)((u8 *)table + skillIndex * 2 - 2);
        if (skill == 0) {
            goto outer_next;
        }
    }
    skillStore = skill & 0xFFFF;
    if (skillStore >= 0x1B8) {
        goto outer_next;
    }
    element = (s16)datCalcSkillElement(*(u8 **)(unit + 0xA64), skill);
    if ((datCalcElementBit(element) & 0x7E) == 0) {
        goto outer_next;
    }
    if (!(s16)element) {
        if (mode == 1) {
            goto outer_next;
        }
    } else {
        if (mode == 2) {
            goto outer_next;
        }
    }
    if (datCalcUsesWeaponProperties(skill) == 0) {
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x80008) != 0) {
            goto outer_next;
        }
        if (datCalcThresholdTrigger(*(u8 **)(unit + 0xA64), skill) != 0) {
            goto outer_next;
        }
    }
    targetKind = btlSkillClassifyTargets(work, (u8 *)&targets, skill, 0);
    bestTargetId = 0;
    if (targetKind == 0) {
        skillScore = 0.0f;
        singleTargetIndex = 0;
        singleTargetElement = (s16)element;
        for (; (singleTargetIndex & 0xFFFF) < (s32)(targets.count & 0xFFFF); singleTargetIndex = (singleTargetIndex + 1) & 0xFFFF) {
            singleTarget = targets.entries[(u16)singleTargetIndex];
            if (btlAICommandNomalCheck(singleTarget, singleTargetElement, 1) != 0) {
                amount = datCalcSkillAmount(skill, *(u8 **)(unit + 0xA64), (u8 *)((BtlAction *)singleTarget)->unit->datUnit, 1, 1, 1, 0, 1);
                hp = datCalcGetHp((s32)((BtlUnit *)*(u8 **)(singleTarget + 0x30))->datUnit) & 0xFFFF;
                maxHp = datCalcMaxHp((s32)((BtlUnit *)*(u8 **)(singleTarget + 0x30))->datUnit) & 0xFFFF;
                healing = (s32)(0u - (u32)amount);
                if (hp < healing) {
                    targetScore = (f32)hp / (f32)maxHp;
                    targetScore = 1.0f + targetScore;
                } else {
                    targetScore = (f32)healing / (f32)maxHp;
                }
                if (skillScore < targetScore) {
                    bestTargetId = (s32)((BtlAction *)singleTarget)->id;
                    skillScore = targetScore;
                }
            }
        }
    } else {
        skillScore = 0.0f;
        groupTargetIndex = 0;
        groupElement = (s16)element;
        for (; ((s32)groupTargetIndex & 0xFFFF) < (s32)(targets.count & 0xFFFF); groupTargetIndex = ((s32)groupTargetIndex + 1) & 0xFFFF) {
            groupTarget = targets.entries[(groupTargetIndex & 0xFFFF)];
            if (btlAICommandNomalCheck(groupTarget, groupElement, 1) == 0) {
                if ((datCalcGetElementAffinity((u8 *)((BtlAction *)groupTarget)->unit->datUnit, element) & 0x1000000) == 0) {
                    skillScore = 0.0f;
                    goto scored;
                }
            } else {
                amount = datCalcSkillAmount(skill, *(u8 **)(unit + 0xA64), (u8 *)((BtlUnit *)*(u8 **)(groupTarget + 0x30))->datUnit, 1, 1, 1, 0, 1);
                hp = datCalcGetHp((s32)((BtlUnit *)*(u8 **)(groupTarget + 0x30))->datUnit) & 0xFFFF;
                maxHp = datCalcMaxHp((s32)((BtlUnit *)*(u8 **)(groupTarget + 0x30))->datUnit) & 0xFFFF;
                healing = (s32)(0u - (u32)amount);
                if (hp < healing) {
                    skillScore += (f32)hp / (f32)maxHp;
                    skillScore = 1.0f + skillScore;
                } else {
                    skillScore += (f32)healing / (f32)maxHp;
                }
            }
        }
    }
scored:
    if (bestScore <= skillScore) {
        if (bestScore == skillScore) {
            if ((datCalcThresholdKind(*(u8 **)(unit + 0xA64), skill) & 0xFFFF) == 2) {
                cost = datCalcSkillCost(*(u8 **)(unit + 0xA64), skill);
                if (cost < bestCost) {
                    bestSkill = skillStore;
                    bestTarget = bestTargetId;
                    bestScore = skillScore;
                    bestCost = cost;
                }
            }
        } else {
            bestSkill = skillStore;
            bestTarget = bestTargetId;
            bestScore = skillScore;
        }
    }
    goto outer_next;
outer_next:
    skillIndex++;
outer_test:
    if (skillIndex < skillCount) {
        goto outer_body;
    }
    if (bestSkill != -1) {
        if (bestSkill == 0) {
            btlAICommandSetActionCode(work, work + 0x38, 0x8000);
        } else {
            btlAICommandSetActionCode(work, work + 0x38, bestSkill & 0xFFFF);
        }
        if (bestTarget != 0) {
            ((u8 **)((BtlAiCommandWork *)((BtlAction *)work)->unk_38)->targets)[0] = btlActionFindById(bestTarget);
            ((BtlAction *)work)->unk_6a = 1;
        } else {
            btlAICommandPickAiTarget(work, 0);
        }
    }
    scrSetReturnInt(bestSkill);
    return 1;
}

/* AI script command 0x2100 (p4flow AI.json AI_FUNCTION_0100). */
// FUN_001E9F20
/* Pick the living genus-1 target with matching status bits and greatest HP. */
s32 btlEffectScriptPickHighestHpBadStatusUnit(void) {
    extern s32 scrGetParamInt(s32 paramIdx);
    extern s32 datCalcGetHp(s32 unit);
    extern s32 datCalcIsDead(s32 unit, s32 hpDelta);
    extern void scrSetReturnInt(s32 retVal);
    u16 flags;
    u32 value;
    u8 *current;
    u8 *best;
    u32 bestHp;
    s32 statusMask;

    statusMask = scrGetParamInt(0);
    best = NULL;
    bestHp = 0;
    current = ((BtlBattleState *)iGpffffb3ac)->actions;
    /* measured: repeated typed action->unit loads hoist +30 across status/HP calls. */
    while (current != NULL) {
        flags = ((BtlAction *)current)->unk_1a;
        if ((flags & 1) && (flags & 8)) {
            if ((((BtlAction *)current)->unit->genus == 1) &&
                (datCalcChkBadStatus((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit, statusMask) != 0) &&
                (datCalcIsDead((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit, 0) == 0)) {
                value = (u32)(datCalcGetHp((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit) & 0xFFFF);
                if (bestHp < value) {
                    best = current;
                    bestHp = value;
                }
            }
        }
        current = (u8 *)((BtlAction *)current)->next;
    }
    if (best != NULL) {
        scrSetReturnInt((s32)((BtlAction *)best)->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2101 (p4flow AI.json AI_FUNCTION_0101). */
// FUN_001EA050
/* Pick the living genus-1 target with matching status bits and least HP. */
s32 btlEffectScriptPickLowestHpBadStatusUnit(void) {
    extern s32 scrGetParamInt(s32 paramIdx);
    extern s32 datCalcGetHp(s32 unit);
    extern s32 datCalcIsDead(s32 unit, s32 hpDelta);
    extern void scrSetReturnInt(s32 retVal);
    u16 flags;
    u32 value;
    u8 *current;
    u8 *best;
    u32 bestHp;
    s32 statusMask;

    statusMask = scrGetParamInt(0);
    best = NULL;
    bestHp = 0x0FFFFFFF;
    current = ((BtlBattleState *)iGpffffb3ac)->actions;
    /* measured: repeated typed action->unit loads hoist +30 across status/HP calls. */
    while (current != NULL) {
        flags = ((BtlAction *)current)->unk_1a;
        if ((flags & 1) && (flags & 8)) {
            if ((((BtlAction *)current)->unit->genus == 1) &&
                (datCalcChkBadStatus((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit, statusMask) != 0) &&
                (datCalcIsDead((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit, 0) == 0)) {
                value = (u32)(datCalcGetHp((s32)((BtlUnit *)*(u8 **)(current + 0x30))->datUnit) & 0xFFFF);
                if (value < bestHp) {
                    best = current;
                    bestHp = value;
                }
            }
        }
        current = (u8 *)((BtlAction *)current)->next;
    }
    if (best != NULL) {
        scrSetReturnInt((s32)((BtlAction *)best)->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2102 (p4flow AI.json AI_FUNCTION_0102). */
// FUN_001EA180
/* Return a random action from the side selector, or -1 for an empty selection. */
s32 btlEffectScriptPickRandomSideUnit(void) {
    u8 *candidates[12];
    s32 candidateCount;

    candidateCount = (s32)(btlSideSelectUnits(scrGetAiState(), 0, 0x80000, 2, 0, &btlAICommandAlwaysTrue, &candidates) & 0xFFFF);
    if (candidateCount > 0) {
        scrSetReturnInt((s32)((BtlAction *)candidates[datCalcRandomBelow(candidateCount)])->id | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2104 (p4flow AI.json AI_FUNCTION_0104). */
// FUN_001EA220
/* Set command kind 9 and its script arguments, then run the command handler fallback. */
s32 btlEffectScriptSetActionParams(void) {
    u8 *work;

    work = scrGetAiState();
    ((BtlAction *)work)->unk_6e = scrGetParamInt(0);
    ((BtlAction *)work)->unk_6c = 9;
    ((BtlAiCommandWork *)((BtlAction *)work)->unk_38)->plan = scrGetParamInt(1);
    /* measured: typing both plan stores hoists the command subobject (+38) into s0. */
    *(s16 *)(work + 0x78) = scrGetParamInt(2);
    /* The adjacent final argument is in BtlAiCommandWork.pad42; retain the same cursor shape. */
    *(s16 *)(work + 0x7A) = scrGetParamInt(3);
    if (((s32 (*)(u8 *, s32))D_00609D20[0])(work, 0) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(work, 0);
    return 1;
}

