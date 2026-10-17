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
extern u16 datCalcMaxSp();
extern s32 datCalcGetSp();

extern u8 *scrGetAiState();

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 D_00724504;
extern s32 btlAICommandSelectCandidates();
extern u32 datCalcRandomBelow(u32 arg0);
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
extern u32 datCalcRandomBelow(u32 arg0);



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
extern s32 datCalcGetHp(s32 arg0);
extern s32 datCalcIsDead(s32 arg0, s32 arg1);
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001e; members 001e7400-001e8a80 */

static inline u16 p4_formation_get_opposing_genus(u32 unit)
{
    u32 side;
    if (*(u8 *)(*(s32 *)(unit + 0x30) + 0xA2) != 0)
        goto nonzero;
    side = 1;
    goto done;
nonzero:
    side = 0;
done:
    return side;
}
/* measured: object 264B vs window 272B, normalized_diff 10; remaining differences are register colouring. Committed at nd 10. */
// FUN_001E7400
s32 btlEffectScriptSelectSideUnit(void) {
    extern s32 btlSideSelectUnits();
    extern u32 datCalcRandomBelow(u32 arg0);
    extern s32 scrGetParamInt(s32 arg0);
    extern void scrSetReturnInt(s32 arg0);
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
            if (*(s32 *)(formation + 0x170) == candidates[index]) {
                break;
            }
            index++;
        }
        if (index == count) {
            selected = candidates[datCalcRandomBelow(count)];
        } else {
            selected = *(s32 *)(formation + 0x170);
        }
        scrSetReturnInt(*(s32 *)(selected + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

// FUN_001E7510
s32 btlEffectScriptSelectHighestLevelUnit(void) {
    extern s32 btlSideSelectUnits();
    extern s32 datCalcRandomBelow();
    extern s32 datCalcGetLevel();
    extern s64 scrGetParamInt();
    extern void scrSetReturnInt();
    extern u8 *scrGetAiState();
    u8 *var_19;
    s32 var_18;
    s32 temp_17;
    u8 *temp_16;
    u8 *temp_2;
    u8 *sp50[12];

    temp_16 = scrGetAiState();
    temp_17 = btlSideSelectUnits(temp_16, scrGetParamInt(0), 0x80000, 2, 1, &btlCond_MYHOJO, sp50) & 0xFFFF;
    if (temp_17 > 0) {
        var_19 = NULL;
        var_18 = 0;
        goto loop_test;
loop_body:
        temp_2 = (u8 *)&sp50[(u16)var_18];
        if ((datCalcGetLevel(*(s32 *)(*(u8 **)(*(u8 **)temp_2 + 0x30) + 0xA64)) & 0xFF) > 0) {
            var_19 = *(u8 **)temp_2;
        }
        var_18 = (var_18 + 1) & 0xFFFF;
loop_test:
        if ((var_18 & 0xFFFF) < temp_17)
            goto loop_body;
        if (var_19 == NULL)
            var_19 = sp50[datCalcRandomBelow(temp_17 & 0xFFFF)];
        scrSetReturnInt(*(s32 *)(var_19 + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

#pragma push
/* measured: btlEffectScriptPickRandomHighestOpposingUnit MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20b7 (p4flow AI.json AI_FUNCTION_00B7). */
// FUN_001E7640
s32 btlEffectScriptPickRandomHighestOpposingUnit(void)
{
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
    desired = p4_formation_get_opposing_genus((u32)unit);
    btlEffectCollectTargetUnits((u32)unit, &candidates, 2, 0, 0);
    highest = 0;
    selectedCount = 0;
    index = 0;
    desiredValue = desired;
    while (index < candidates.count) {
        candidate = candidates.entries[index];
        if (((*(u16 *)(candidate + 0x1A) & 1) != 0) &&
            ((*(u16 *)(candidate + 0x1A) & 8) != 0) &&
            (*(u8 *)(*(s32 *)(candidate + 0x30) + 0xA2) == desiredValue) &&
            (datCalcIsDead(*(s32 *)(*(s32 *)(candidate + 0x30) + 0xA64), 0) == 0)) {
            value = (u32)(datCalcGetLevel((u8 *)*(s32 *)(*(s32 *)(candidate + 0x30) + 0xA64)) & 0xFF);
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
        scrSetReturnInt(*(s32 *)(selected[value] + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

#pragma pop
/* AI script command 0x20d1 (p4flow AI.json AI_FUNCTION_00D1). */
// FUN_001E77F0
s32 btlEffectScriptPickHighestLevelHpUnit(void) {
    extern s32 datCalcGetLevel();
    u8 *temp_21;
    u32 temp_2;
    u8 *temp_20;
    u8 *var_19;
    u32 var_18;
    u32 temp_17;
    u32 var_16;
    u32 var_22;

    temp_21 = scrGetAiState();
    if (btlAICommandSelectCandidates(temp_21, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        if (*(u16 *)(temp_21 + 0x6A) == 1) {
            var_19 = *(u8 **)(temp_21 + 0x38);
        } else {
            var_19 = NULL;
            var_22 = 0;
            var_16 = 0;
            var_18 = 0;
            goto loop_test;
loop_body:
            temp_20 = *(u8 **)(temp_21 + var_18 * 4 + 0x38);
            temp_17 = datCalcGetLevel(*(s32 *)(*(u8 **)(temp_20 + 0x30) + 0xA64)) & 0xFF;
            if (temp_17 >= var_22) {
                temp_2 = datCalcGetHp(*(s32 *)(*(u8 **)(temp_20 + 0x30) + 0xA64)) & 0xFFFF;
                if (var_16 < temp_2) {
                    var_19 = temp_20;
                    var_16 = temp_2;
                }
                var_22 = temp_17;
            }
            var_18 += 1;
loop_test:
            if (var_18 < *(u16 *)(temp_21 + 0x6A))
                goto loop_body;
        }
        scrSetReturnInt(*(s32 *)(var_19 + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return -1;
}

/* AI script command 0x20d2 (p4flow AI.json AI_FUNCTION_00D2). */
// FUN_001E7950
s32 btlEffectScriptPickRandomNoBadStatusUnit(void) {
    extern s32 datCalcGetBadStatusNoDown();
    u8 *temp_19;
    s32 var_18;
    s32 var_17;
    u16 temp_4;
    u8 *temp_16;
    u8 *sp50[12];

    temp_19 = scrGetAiState();
    if (btlAICommandSelectCandidates(temp_19, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        var_17 = 0;
        var_18 = 0;
        goto loop_test;
loop_body:
        temp_16 = *(u8 **)(temp_19 + (u16)var_18 * 4 + 0x38);
        if (!(datCalcGetBadStatusNoDown(*(s32 *)(*(u8 **)(temp_16 + 0x30) + 0xA64)) & 0xFFEFFFFF)) {
            sp50[var_17 & 0xFFFF] = temp_16;
            var_17 = (var_17 + 1) & 0xFFFF;
        }
        var_18 = (var_18 + 1) & 0xFFFF;
loop_test:
        if ((var_18 & 0xFFFF) < (s32)*(u16 *)(temp_19 + 0x6A))
            goto loop_body;
        temp_4 = var_17 & 0xFFFF;
        if (temp_4 == 0) {
            scrSetReturnInt(-1);
        } else {
            scrSetReturnInt(*(s32 *)(sp50[datCalcRandomBelow(temp_4)] + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return -1;
}

/* SUPERSEDED, kept for history: "normalized_diff 1; the sole residual is the
   retail daddiu/addiu width at the count reset. Committed at nd 1." That width
   was believed unreachable. It is not - see the measured note below. */
/* measured: u16 var_17 reaches retail daddiu s1,zero,1; fused
   sp60[var_17++] produces addiu v0,s1,1 from the unmasked counter,
   avoiding reuse of the masked index. Object 364B/window 368B,
   normalized_diff 0. */
/* AI script command 0x20d3 (p4flow AI.json AI_FUNCTION_00D3). */
// FUN_001E7AB0
s32 btlEffectScriptPickRandomHighestLevelUnit(void) {
    extern s32 btlAICommandSelectCandidates();
    extern void btlAICommandNomalCheckNoGate();
    extern s32 datCalcRandomBelow();
    extern s32 datCalcGetLevel();
    extern s64 scrGetParamInt();
    extern void scrSetReturnInt();
    extern u8 *scrGetAiState();
    u8 *temp_20;
    u32 var_19;
    u32 var_18;
    u16 var_17;
    u8 *temp_16;
    u32 temp_3;
    u8 *sp60[12];
    u8 *var_2;

    temp_20 = scrGetAiState();
    if (btlAICommandSelectCandidates(temp_20, scrGetParamInt(0), 0, 0x2C, 1, &btlAICommandNomalCheckNoGate) == 1) {
        if (*(u16 *)(temp_20 + 0x6A) == 1) {
            var_2 = *(u8 **)(temp_20 + 0x38);
        } else {
            var_17 = 0;
            var_18 = 0;
            var_19 = 0;
            goto loop_test;
loop_body:
            temp_16 = *(u8 **)(temp_20 + var_19 * 4 + 0x38);
            temp_3 = (u32)(datCalcGetLevel(*(s32 *)(*(u8 **)(temp_16 + 0x30) + 0xA64)) & 0xFF);
            if (temp_3 >= var_18) {
                if (temp_3 == var_18) {
                    sp60[var_17++] = temp_16;
                } else {
                    var_18 = temp_3;
                    sp60[0] = temp_16;
                    var_17 = 1;
                }
            }
            var_19 += 1;
loop_test:
            if (var_19 < *(u16 *)(temp_20 + 0x6A))
                goto loop_body;
            var_2 = sp60[datCalcRandomBelow(var_17 & 0xFFFF)];
        }
        scrSetReturnInt(*(s32 *)(var_2 + 8) | 0x80000000);
    } else {
        scrSetReturnInt(-1);
    }
    return -1;
}

/* AI script command 0x20da (p4flow AI.json AI_FUNCTION_00DA). */
// FUN_001E7C20
s32 btlEffectScriptCountNoBadStatusUnits(void) {
    extern s32 btlAICommandSelectCandidates();
    extern s32 datCalcGetBadStatusNoDown();
    extern s64 scrGetParamInt();
    extern void scrSetReturnInt();
    extern u8 *scrGetAiState();
    u8 *temp_18;
    s32 var_17;
    s32 var_16;

    temp_18 = scrGetAiState();
    if (btlAICommandSelectCandidates(temp_18, scrGetParamInt(0), 0, 0x2C, 0, &btlCond_MYNOMAL) == 1) {
        var_16 = 0;
        var_17 = 0;
        goto loop_test;
loop_body:
        if (!(datCalcGetBadStatusNoDown(*(s32 *)(*(u8 **)(*(u8 **)(temp_18 + (u16)var_17 * 4 + 0x38) + 0x30) + 0xA64)) & 0xFFEFFFFF)) {
            var_16 = (var_16 + 1) & 0xFFFF;
        }
        var_17 = (var_17 + 1) & 0xFFFF;
loop_test:
        if ((var_17 & 0xFFFF) < (s32)*(u16 *)(temp_18 + 0x6A))
            goto loop_body;
        scrSetReturnInt(var_16 & 0xFFFF);
    } else {
        scrSetReturnInt(0);
    }
    return -1;
}

/* AI script command 0x20E5 (p4flow AI.json AI_FUNCTION_00E5). */
// FUN_001E7D30
s32 btlEffectScriptGetCurrentUnit(void) {
    u8 *temp;

    temp = scrGetAiState();
    scrSetReturnInt(*(s32 *)(temp + 8) | 0x80000000);
    return 1;
}

/* AI script command 0x20E6 (p4flow AI.json AI_FUNCTION_00E6). */
// FUN_001E7D70
s32 btlEffectScriptGetMaxHp(void) {
    scrSetReturnInt(datCalcMaxHp(*(s32 *)(*(u8 **)(btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}

/* AI script command 0x20E7 (p4flow AI.json AI_FUNCTION_00E7). */
// FUN_001E7DD0
s32 btlEffectScriptGetHp(void) {
    scrSetReturnInt(datCalcGetHp(*(s32 *)(*(u8 **)(btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}

/* AI script command 0x20E8 (p4flow AI.json AI_FUNCTION_00E8). */
// FUN_001E7E30
s32 btlEffectScriptGetSlotUnit(void) {
    u8 *temp;

    temp = btlActionGetQueueSecond();
    scrSetReturnInt(*(s32 *)(temp + 8) | 0x80000000);
    return 1;
}

/* AI script command 0x20E9 (p4flow AI.json AI_FUNCTION_00E9). */
// FUN_001E7E70
// measured: the status byte/halfword gates the signed-byte payload; the
// payload is read only when neither gate is active.
s32 btlEffectScriptGetStatusByte(void)
{
    u8 *base;
    u8 *payload;
    s32 value;

    base = *(u8 **)(btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF) + 0x30);
    if (*(u8 *)(base + 0xA2) == 0 && *(u16 *)(base + 0xA4) != 1) {
        payload = *(u8 **)(base + 0xA64);
        value = *(s8 *)(payload + 0x10);
    } else {
        value = -1;
    }
    scrSetReturnInt(value);
    return 1;
}

/* AI script command 0x20EE (p4flow AI.json AI_FUNCTION_00EE). */
// FUN_001E7EF0
s32 btlEffectScriptGetMaxSp(void) {
    scrSetReturnInt(datCalcMaxSp(*(s32 *)(*(u8 **)(btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}

/* AI script command 0x20EF (p4flow AI.json AI_FUNCTION_00EF). */
// FUN_001E7F50
s32 btlEffectScriptGetSp(void) {
    scrSetReturnInt(datCalcGetSp(*(s32 *)(*(u8 **)(btlActionFindById((u64) scrGetParamInt(0) & 0xFFFFFFF) + 0x30) + 0xA64)) & 0xFFFF);
    return 1;
}

/* AI script command 0x20F0 (p4flow AI.json AI_FUNCTION_00F0). */
// FUN_001E7FB0
s32 btlEffectScriptPickRandomCandidate(void) {
    u16 count;
    u8 *work;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2E, 0, &btlCond_MYHOJO) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            scrSetReturnInt(*(s32 *)(*(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38) + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f1 (p4flow AI.json AI_FUNCTION_00F1). */
// FUN_001E8090
s32 btlEffectScriptPickHansyaUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYHANSYA) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38);
            }
            scrSetReturnInt(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f2 (p4flow AI.json AI_FUNCTION_00F2). */
// FUN_001E8190
s32 btlEffectScriptPickKyusyuUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYKYUSYU) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38);
            }
            scrSetReturnInt(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f3 (p4flow AI.json AI_FUNCTION_00F3). */
// FUN_001E8290
s32 btlEffectScriptPickMukouUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYMUKOU) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38);
            }
            scrSetReturnInt(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x20f4 (p4flow AI.json AI_FUNCTION_00F4). */
// FUN_001E8390
s32 btlEffectScriptPickTaiseiUnit(void) {
    u8 *work;
    s64 flags;
    u16 count;
    u8 *result;

    work = scrGetAiState();
    flags = scrGetParamInt(0);
    if (btlAICommandSelectCandidates(work, flags, 0, 0x2E, 0, &btlCond_MYTAISEI) == 1) {
        count = *(u16 *)(work + 0x6A);
        if (count == 1) {
            scrSetReturnInt(*(s32 *)(*(u8 **)(work + 0x38) + 8) | 0x80000000);
        } else {
            if (flags & 2) {
                result = btlAICommandPickUnitByHpWeight(work);
            } else {
                result = *(u8 **)(p4_slot_001eb320((u32)datCalcRandomBelow(count) * 4, work) + 0x38);
            }
            scrSetReturnInt(*(s32 *)(result + 8) | 0x80000000);
        }
    } else {
        scrSetReturnInt(-1);
    }
    return 1;
}

/* AI script command 0x2080 (p4flow AI.json AI_FUNCTION_0080). */
// FUN_001E8490
s32 btlEffectScriptPickLowestHpWeakUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2E, 0, &btlCond_MYWEAK) == 1) {
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

/* AI script command 0x2081 (p4flow AI.json AI_FUNCTION_0081). */
// FUN_001E85C0
s32 btlEffectScriptPickLowestHpWeakFilteredUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2E, 0, &btlCond_MYWEAK) == 1) {
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

/* AI script command 0x2082 (p4flow AI.json AI_FUNCTION_0082). */
// FUN_001E86F0
s32 btlEffectScriptPickLowestHpWeakWideUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2F, 0, &btlCond_MYWEAK) == 1) {
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

/* AI script command 0x20f5 (p4flow AI.json AI_FUNCTION_00F5). */
// FUN_001E8820
s32 btlEffectScriptPickHighestHpWeakUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value >= min) {
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

/* AI script command 0x20f6 (p4flow AI.json AI_FUNCTION_00F6). */
// FUN_001E8950
s32 btlEffectScriptPickHighestHpWeakFilteredUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0x100000, 0x2E, 0, &btlCond_MYWEAK) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value >= min) {
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

/* AI script command 0x20f7 (p4flow AI.json AI_FUNCTION_00F7). */
// FUN_001E8A80
s32 btlEffectScriptPickHighestHpWeakWideUnit(void) {
    u32 value;
    u8 *work;
    u8 *selected;
    u8 *entry;
    u32 index;
    u32 min;

    work = scrGetAiState();
    if (btlAICommandSelectCandidates(work, scrGetParamInt(0), 0, 0x2F, 0, &btlCond_MYWEAK) == 1) {
        if (*(u16 *)(work + 0x6A) == 1) {
            selected = *(u8 **)(work + 0x38);
        } else {
            selected = NULL;
            min = 0;
            index = 0;
            while (index < *(u16 *)(work + 0x6A)) {
                entry = *(u8 **)(work + index * 4 + 0x38);
                value = datCalcGetHp(*(s32 *)(*(u8 **)(entry + 0x30) + 0xA64)) & 0xFFFF;
                if (value >= min) {
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

