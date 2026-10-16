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
                          const void *second, const void *up);
extern u8 *btlActionFindById();
extern void *D_00609850[];
extern s32 datCalcMaxHp();
extern s64 scrGetParamInt();
/* The surrounding wrappers use the raw s64 ABI; this typed view preserves
   the 32-bit call result at this store site. */
static inline u8 *p4_slot_001eb320(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}
extern s32 datCalcGetHp();

extern s32 datCalcSkillElement(u8 *unit, u16 skill);
extern u32 datCalcGetTableLength(u8 *arg0);
extern s32 datCalcThresholdTrigger(u8 *unit, s32 skill);
extern s32 datCalcDefaultSkillId(u8 *unit);
extern s32 datCalcAilmentChance(u8 *arg0, s32 arg1);
extern u8 *func_0029d050();

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 arg0);
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


extern u32 datCalcRandomBelow(u32 arg0);



extern void btlAICommandSetActionCode(u8 *arg0, u8 *arg1, u16 arg2);
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
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 datCalcGetHp(s32 arg0);
extern s32 datCalcIsDead(s32 arg0, s32 arg1);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Source unit: src/promoted/code1_001e.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001e.c; members 001e8d80-001ea220 */

#pragma push
#pragma pop
/* AI script command 0x2090 (p4flow AI.json AI_FUNCTION_0090). */
// FUN_001E8D80
s32 btlEffectScriptGetSelfElement(void) {
    scrSetReturnInt((s16) datCalcSkillElement(*(u8 **)(*(u8 **)(func_0029d050() + 0x30) + 0xA64), 0U));
    return 1;
}

/* AI script command 0x209b (p4flow AI.json AI_FUNCTION_009B). */
// FUN_001E8DD0
s32 btlEffectScriptPickLowestHpLivingSide0Unit(void) {
    u8 *current;
    u8 *best;
    u32 min;
    u16 flags;
    u8 *entry;
    u32 value;

    best = NULL;
    min = 0x0FFFFFFF;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            entry = *(u8 **)(current + 0x30);
            if (*(u8 *)(entry + 0xA2) == 0 &&
                datCalcIsDead(*(s32 *)(entry + 0xA64), 0) == 0) {
                value = datCalcGetHp(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    best = current;
                    min = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    scrSetReturnInt(*(s32 *)(best + 8) | 0x80000000);
    return 1;
}

/* AI script command 0x2083 (p4flow AI.json AI_FUNCTION_0083). */
// FUN_001E8EB0
s32 btlEffectScriptPickLowestHpNormalUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2084 (p4flow AI.json AI_FUNCTION_0084). */
// FUN_001E8FE0
s32 btlEffectScriptPickLowestHpNormalFilteredUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2085 (p4flow AI.json AI_FUNCTION_0085). */
// FUN_001E9110
s32 btlEffectScriptPickLowestHpNormalAltUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = func_0029d050();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2D, 0, &btlCond_MYNOMAL) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0x0FFFFFFF;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value < min) {
                    selected = entry;
                    min = value;
                }
                index++;
            }
        }
        scrSetReturnInt(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2089 (p4flow AI.json AI_FUNCTION_0089). */
// FUN_001E9240
s32 btlEffectScriptPickRandomSide1Unit(void) {
    u8 *selected;
    u8 *data;
    u8 *entry;
    u16 flags;
    u8 *current;
    s32 count;
    u8 *stack[12];

    selected = btlEffectFindUnitByKey(func_0029d050() + 0x98);
    if (selected == NULL || *(u8 *)(*(u8 **)(selected + 0x30) + 0xA2) != 1) {
        count = 0;
        current = *(u8 **)(iGpffffb3ac + 0x174);
        while (current != NULL) {
            flags = *(u16 *)(current + 0x1A);
            if ((flags & 1) && (flags & 8)) {
                entry = *(u8 **)(current + 0x30);
                if (*(u8 *)(entry + 0xA2) == 1) {
                    data = *(u8 **)(entry + 0xA64);
                    if (data == NULL || datCalcIsDead((s32)data, 0) == 0) {
                        stack[count & 0xFFFF] = current;
                        count = (count + 1) & 0xFFFF;
                    }
                }
            }
            current = *(u8 **)(current + 0x450);
        }
        selected = stack[datCalcRandomBelow(count & 0xFFFF)];
    }
    scrSetReturnInt(*(s32 *)(selected + 8) | 0x80000000);
    return 1;
}

/* AI script command 0x208a (p4flow AI.json AI_FUNCTION_008A). */
// FUN_001E9350
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

    work = func_0029d050();
    command = scrGetParamInt(0);
    result = btlActionFindById((u64)(command << 0x24) >> 0x24);
    entry = *(u8 **)(work + 0x30);
    element = (s16)datCalcSkillElement(*(u8 **)(entry + 0xA64), 0);
    if (datCalcAilmentChance(*(u8 **)(*(u8 **)(result + 0x30) + 0xA64), element) & 0x08000000) {
        scrSetReturnInt((s16)element);
        return 1;
    }
    count = datCalcGetTableLength(*(u8 **)(entry + 0xA64)) & 0xFFFF;
    base = datCalcSkillList(*(u8 **)(entry + 0xA64));
    index = 0;
    while (index < count) {
        skill = *(u16 *)(base + index * 2);
        if (skill != 0 && skill < 0x1B8) {
            element = (s16)datCalcSkillElement(*(u8 **)(entry + 0xA64), skill);
            if (datCalcAilmentChance(*(u8 **)(*(u8 **)(result + 0x30) + 0xA64), element) & 0x08000000) {
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
s32 btlEffectScriptPickRandomSide1OtherUnit(void) {
    u8 *selected;
    u8 *data;
    u8 *entry;
    u16 flags;
    u8 *current;
    s32 count;
    u8 *stack[12];

    func_0029d050();
    selected = btlEffectFindUnitByKey(*(u8 **)(iGpffffb3ac + 0x170) + 0x98);
    if (selected == NULL || *(u8 *)(*(u8 **)(selected + 0x30) + 0xA2) != 1) {
        count = 0;
        current = *(u8 **)(iGpffffb3ac + 0x174);
        while (current != NULL) {
            flags = *(u16 *)(current + 0x1A);
            if ((flags & 1) && (flags & 8)) {
                entry = *(u8 **)(current + 0x30);
                if (*(u8 *)(entry + 0xA2) == 1) {
                    data = *(u8 **)(entry + 0xA64);
                    if (data == NULL || datCalcIsDead((s32)data, 0) == 0) {
                        stack[count & 0xFFFF] = current;
                        count = (count + 1) & 0xFFFF;
                    }
                }
            }
            current = *(u8 **)(current + 0x450);
        }
        selected = stack[datCalcRandomBelow(count & 0xFFFF)];
    }
    scrSetReturnInt(*(s32 *)(selected + 8) | 0x80000000);
    return 1;
}

/* AI script command 0x208c (p4flow AI.json AI_FUNCTION_008C). */
// FUN_001E9600
s32 btlEffectScriptPickLowestHpSkillEligibleUnit(void) {
    u8 *work;
    u8 *current;
    u8 *best_fallback;
    u8 *best_eligible;
    u32 min_fallback;
    u32 min_eligible;
    u16 flags;
    u8 *entry;
    u32 value;

    work = func_0029d050();
    best_fallback = NULL;
    min_fallback = 0x0FFFFFFF;
    best_eligible = NULL;
    min_eligible = 0x0FFFFFFF;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            entry = *(u8 **)(current + 0x30);
            if (*(u8 *)(entry + 0xA2) == 1 &&
                datCalcIsDead(*(s32 *)(entry + 0xA64), 0) == 0) {
                value = datCalcGetHp(*(s32 *)(entry + 0xA64)) & 0xFFFF;
                if (value < min_eligible &&
                    btlAICommandCollectSkillCandidates(work, current, 0, 0) >= 0) {
                    best_eligible = current;
                    min_eligible = value;
                }
                if (value < min_fallback) {
                    best_fallback = current;
                    min_fallback = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    if (best_eligible != NULL) {
        scrSetReturnInt(*(s32 *)(best_eligible + 8) | 0x80000000);
    } else {
        scrSetReturnInt(*(s32 *)(best_fallback + 8) | 0x80000000);
    }
    return 1;
}

/* AI script command 0x209d (p4flow AI.json AI_FUNCTION_009D). */
// FUN_001E9770
s32 btlEffectScriptPickLowestHpInRangeUnit(void) {
    extern s32 scrGetParamInt(s32 arg0);
    extern void scrSetReturnInt(s32 arg0);
    extern s32 datCalcIsDead(s32 arg0, s32 arg1);
    extern s32 datCalcGetHp(s32 arg0);
    extern s32 datCalcMaxHp(s32 arg0);
    u32 temp_16;
    u32 temp_2;
    s32 temp_30;
    s32 temp_23;
    u8 *var_21;
    u8 *var_20;
    u32 temp_19;
    u32 var_18;
    s32 temp_17;
    u16 temp_3;
    u8 *temp_4;
    s32 temp_22;
    temp_23 = scrGetParamInt(0);
    temp_30 = scrGetParamInt(1);
    temp_17 = scrGetParamInt(2);
    var_20 = NULL;
    var_18 = 0x0FFFFFFF;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    temp_22 = temp_17 & 0x80000;
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) == 0)
        goto loop_next;
    if ((temp_3 & 8) == 0)
        goto loop_next;
    if (*(u8 *)(*(u8 **)(var_21 + 0x30) + 0xA2) != 0)
        goto loop_next;
    if ((temp_22 == 0) &&
        (datCalcIsDead(*(s32 *)(*(u8 **)(var_21 + 0x30) + 0xA64), 0) != 0))
        goto loop_next;
    temp_19 = datCalcGetHp(*(s32 *)(*(u8 **)(var_21 + 0x30) + 0xA64)) & 0xFFFF;
    if ((u32)temp_23 > temp_19)
        goto loop_next;
    temp_4 = *(u8 **)(*(u8 **)(var_21 + 0x30) + 0xA64);
    temp_16 = *(u16 *)(temp_4 + 8);
    temp_2 = (u32)(datCalcMaxHp((s32)temp_4) & 0xFFFF);
    if ((u32)temp_16 * 0x64 > temp_2 * (u32)temp_30)
        goto loop_next;
    if ((temp_17 != 0) &&
        (datCalcChkBadStatus(*(s32 *)(*(u8 **)(var_21 + 0x30) + 0xA64), temp_17) == 0))
        goto loop_next;
    if (temp_19 >= var_18)
        goto loop_next;
    var_20 = var_21;
    var_18 = temp_19;
loop_next:
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    if (var_20 != NULL) {
        scrSetReturnInt(*(s32 *)(var_20 + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* Rank usable skills by the best single target or the accumulated target score.
 * The producer's 0x40-byte target record includes selected@0x3A and flags@0x3C.
 * Register/spill notes (verified MATCH): skill and kind are s32 (retail passes
 * skill unnarrowed and re-sign-extends kind); func_0023d8e0 and func_001d7f10
 * are declared here with s32 skill parameters, as retail passes $s2 without a
 * mask. Retail spills skillStore, paramA, paramB, outer and bestCost; the
 * declaration order (innerBest before outer, kind before skill, skillStore
 * after paramA/paramB) reproduces that spill set and slot order. */
/* AI script command 0x20fa (p4flow AI.json AI_FUNCTION_00FA). */
// FUN_001E9950
s32 btlEffectScriptChooseBestSkill(void) {
    extern s32 scrGetParamInt(s32 arg0);
    extern void scrSetReturnInt(s32 arg0);
    extern s32 datCalcElementBit(s16 arg0);
    extern s32 datCalcSkillElement(u8 *arg0, s32 arg1);
    extern u16 btlSkillClassifyTargets(u8 *action, u8 *targets, s32 skill, u32 reverseGroups);
    extern s32 func_0023df70(s32 arg0);
    extern u32 datCalcSkillCost(u8 *arg0, s32 arg1);
    extern u16 datCalcThresholdKind(u8 *arg0, s32 arg1);
    extern s32 btlAICommandNomalCheck(u8 *arg0, s32 arg1, s32 arg2);
    extern s32 datCalcSkillAmount(s32, u8 *, u8 *, s32, s32, s32, s32, s32);
    extern u8 *btlActionFindById(s32 arg0);
    extern s32 btlAICommandPickAiTarget(u8 *arg0, u32 arg1);
    u8 *work;
    u8 *unit;
    s32 bestSkill;
    s32 bestTarget;
    s32 bestCost;
    f32 curScore;
    f32 bestScore;
    f32 cur;
    u16 *table;
    s32 mode;
    s32 outerLimit;
    s32 innerBest;
    u16 outer;
    s32 outerCount;
    s32 kind;
    s32 skill;
    s32 paramB;
    s32 paramA;
    s32 skillStore;
    u16 targetKind;
    s32 idxA;
    s32 idxB;
    u8 *entryA;
    u8 *entryB;
    s32 dmg;
    s32 hp;
    s32 maxHp;
    s32 neg;
    s32 cost;
    struct {
        u8 *entries[14];
        u16 count;
        u16 selected;
        u8 flags;
    } tgt;
    work = func_0029d050();
    mode = scrGetParamInt(0);
    unit = *(u8 **)(work + 0x30);
    bestTarget = 0;
    bestSkill = -1;
    bestCost = 0x3E7;
    bestScore = -1.0f;
    outerLimit = ((datCalcGetTableLength(*(u8 **)(unit + 0xA64)) & 0xFFFF) + 1) & 0xFFFF;
    table = (u16 *)datCalcSkillList(*(u8 **)(unit + 0xA64));
    outer = 0;
    outerCount = outerLimit & 0xFFFF;
    goto outer_test;
outer_body:
    if (outer == 0) {
        skill = (u16)(datCalcDefaultSkillId(*(u8 **)(unit + 0xA64)) & 0xFFFF);
    } else {
        skill = *(u16 *)((u8 *)table + outer * 2 - 2);
        if (skill == 0) {
            goto outer_next;
        }
    }
    skillStore = skill & 0xFFFF;
    if (skillStore >= 0x1B8) {
        goto outer_next;
    }
    kind = (s16)datCalcSkillElement(*(u8 **)(unit + 0xA64), skill);
    if ((datCalcElementBit(kind) & 0x7E) == 0) {
        goto outer_next;
    }
    if (!(s16)kind) {
        if (mode == 1) {
            goto outer_next;
        }
    } else {
        if (mode == 2) {
            goto outer_next;
        }
    }
    if (func_0023df70(skill) == 0) {
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x80008) != 0) {
            goto outer_next;
        }
        if (datCalcThresholdTrigger(*(u8 **)(unit + 0xA64), skill) != 0) {
            goto outer_next;
        }
    }
    targetKind = btlSkillClassifyTargets(work, (u8 *)&tgt, skill, 0);
    innerBest = 0;
    if (targetKind == 0) {
        curScore = 0.0f;
        idxA = 0;
        paramA = (s16)kind;
        for (; (idxA & 0xFFFF) < (s32)(tgt.count & 0xFFFF); idxA = (idxA + 1) & 0xFFFF) {
            entryA = tgt.entries[(u16)idxA];
            if (btlAICommandNomalCheck(entryA, paramA, 1) != 0) {
                dmg = datCalcSkillAmount(skill, *(u8 **)(unit + 0xA64), *(u8 **)(*(u8 **)(entryA + 0x30) + 0xA64), 1, 1, 1, 0, 1);
                hp = datCalcGetHp(*(s32 *)(*(u8 **)(entryA + 0x30) + 0xA64)) & 0xFFFF;
                maxHp = datCalcMaxHp(*(s32 *)(*(u8 **)(entryA + 0x30) + 0xA64)) & 0xFFFF;
                neg = (s32)(0u - (u32)dmg);
                if (hp < neg) {
                    cur = (f32)hp / (f32)maxHp;
                    cur = 1.0f + cur;
                } else {
                    cur = (f32)neg / (f32)maxHp;
                }
                if (curScore < cur) {
                    innerBest = *(s32 *)(entryA + 8);
                    curScore = cur;
                }
            }
        }
    } else {
        curScore = 0.0f;
        idxB = 0;
        paramB = (s16)kind;
        for (; ((s32)idxB & 0xFFFF) < (s32)(tgt.count & 0xFFFF); idxB = ((s32)idxB + 1) & 0xFFFF) {
            entryB = tgt.entries[(idxB & 0xFFFF)];
            if (btlAICommandNomalCheck(entryB, paramB, 1) == 0) {
                if ((datCalcAilmentChance(*(u8 **)(*(u8 **)(entryB + 0x30) + 0xA64), kind) & 0x1000000) == 0) {
                    curScore = 0.0f;
                    goto scored;
                }
            } else {
                dmg = datCalcSkillAmount(skill, *(u8 **)(unit + 0xA64), *(u8 **)(*(u8 **)(entryB + 0x30) + 0xA64), 1, 1, 1, 0, 1);
                hp = datCalcGetHp(*(s32 *)(*(u8 **)(entryB + 0x30) + 0xA64)) & 0xFFFF;
                maxHp = datCalcMaxHp(*(s32 *)(*(u8 **)(entryB + 0x30) + 0xA64)) & 0xFFFF;
                neg = (s32)(0u - (u32)dmg);
                if (hp < neg) {
                    curScore += (f32)hp / (f32)maxHp;
                    curScore = 1.0f + curScore;
                } else {
                    curScore += (f32)neg / (f32)maxHp;
                }
            }
        }
    }
scored:
    if (bestScore <= curScore) {
        if (bestScore == curScore) {
            if ((datCalcThresholdKind(*(u8 **)(unit + 0xA64), skill) & 0xFFFF) == 2) {
                cost = datCalcSkillCost(*(u8 **)(unit + 0xA64), skill);
                if (cost < bestCost) {
                    bestSkill = skillStore;
                    bestTarget = innerBest;
                    bestScore = curScore;
                    bestCost = cost;
                }
            }
        } else {
            bestSkill = skillStore;
            bestTarget = innerBest;
            bestScore = curScore;
        }
    }
    goto outer_next;
outer_next:
    outer++;
outer_test:
    if (outer < outerCount) {
        goto outer_body;
    }
    if (bestSkill != -1) {
        if (bestSkill == 0) {
            btlAICommandSetActionCode(work, work + 0x38, 0x8000);
        } else {
            btlAICommandSetActionCode(work, work + 0x38, bestSkill & 0xFFFF);
        }
        if (bestTarget != 0) {
            *(u8 **)(work + 0x38) = btlActionFindById(bestTarget);
            *(u16 *)(work + 0x6A) = 1;
        } else {
            btlAICommandPickAiTarget(work, 0);
        }
    }
    scrSetReturnInt(bestSkill);
    return 1;
}

/* AI script command 0x2100 (p4flow AI.json AI_FUNCTION_0100). */
// FUN_001E9F20
s32 btlEffectScriptPickHighestHpBadStatusUnit(void) {
    extern s32 scrGetParamInt(s32 arg0);
    extern s32 datCalcGetHp(s32 arg0);
    extern s32 datCalcIsDead(s32 arg0, s32 arg1);
    extern void scrSetReturnInt(s32 arg0);
    u16 flags;
    u32 value;
    u8 *current;
    u8 *best;
    u32 best_value;
    s32 random;

    random = scrGetParamInt(0);
    best = NULL;
    best_value = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            if ((*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) == 1) &&
                (datCalcChkBadStatus(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64), random) != 0) &&
                (datCalcIsDead(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64), 0) == 0)) {
                value = (u32)(datCalcGetHp(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64)) & 0xFFFF);
                if (best_value < value) {
                    best = current;
                    best_value = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    if (best != NULL) {
        scrSetReturnInt(*(s32 *)(best + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2101 (p4flow AI.json AI_FUNCTION_0101). */
// FUN_001EA050
s32 btlEffectScriptPickLowestHpBadStatusUnit(void) {
    extern s32 scrGetParamInt(s32 arg0);
    extern s32 datCalcGetHp(s32 arg0);
    extern s32 datCalcIsDead(s32 arg0, s32 arg1);
    extern void scrSetReturnInt(s32 arg0);
    u16 flags;
    u32 value;
    u8 *current;
    u8 *best;
    u32 best_value;
    s32 random;

    random = scrGetParamInt(0);
    best = NULL;
    best_value = 0x0FFFFFFF;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    while (current != NULL) {
        flags = *(u16 *)(current + 0x1A);
        if ((flags & 1) && (flags & 8)) {
            if ((*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) == 1) &&
                (datCalcChkBadStatus(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64), random) != 0) &&
                (datCalcIsDead(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64), 0) == 0)) {
                value = (u32)(datCalcGetHp(*(s32 *)(*(u8 **)(current + 0x30) + 0xA64)) & 0xFFFF);
                if (value < best_value) {
                    best = current;
                    best_value = value;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    if (best != NULL) {
        scrSetReturnInt(*(s32 *)(best + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2102 (p4flow AI.json AI_FUNCTION_0102). */
// FUN_001EA180
s32 btlEffectScriptPickRandomSideUnit(void) {
    u8 *sp10[12];
    s32 temp_4;

    temp_4 = (s32)(btlSideSelectUnits(func_0029d050(), 0, 0x80000, 2, 0, &btlAICommandAlwaysTrue, &sp10) & 0xFFFF);
    if (temp_4 > 0) {
        scrSetReturnInt(*(s32 *)(sp10[datCalcRandomBelow(temp_4)] + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2104 (p4flow AI.json AI_FUNCTION_0104). */
// FUN_001EA220
s32 btlEffectScriptSetActionParams(void) {
    u8 *temp_16;

    temp_16 = func_0029d050();
    *(s16 *)(temp_16 + 0x6E) = scrGetParamInt(0);
    *(s16 *)(temp_16 + 0x6C) = 9;
    *(s16 *)(temp_16 + 0x76) = scrGetParamInt(1);
    *(s16 *)(temp_16 + 0x78) = scrGetParamInt(2);
    *(s16 *)(temp_16 + 0x7A) = scrGetParamInt(3);
    if (((s32 (*)(u8 *, s32))D_00609D20[0])(temp_16, 0) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(temp_16, 0);
    return 1;
}

