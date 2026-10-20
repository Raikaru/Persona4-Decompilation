#include "btl_target_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_equipment_count_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "btl_cond_internal.h"
extern void btlCameraLookAtQuat(void *out, const void *first,
                          const void *second, const void *config);
extern void *D_00609850[];


extern void memset(void *destination, s32 value, u32 size);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 iGpffffa9b0;
extern s32 *gEncountTbl;
extern s32 btlTargetCanControlDamagePhase(void);
extern void btlDamageEndPhase(s32 task);
extern s32 btlCurrentUnitId(void);
extern s32 D_00724504;
extern void btlTargetEndDamagePhase(void);
extern s32 btlTargetCanControlDamagePhase(void);
extern u32 datCalcRandomBelow(u32);


extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern f32 D_00761430;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff8060;
extern f32 D_00761438;


extern u32 datCalcRandomBelow(u32);


extern void btlAICommandSetActionCode(u8 *, u8 *, u16);
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
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;

extern s32 btlAiGetGlobal(void);
extern s32 btlAiSetGlobal(void);
extern s32 btlCurrentUnitId(void);
#pragma push
#pragma pop
/* measured: retail keeps the filter conditions as a separate branch chain. */
#pragma push
#pragma pop
/* measured: retail keeps the original conditional branch shape. */
#pragma push
#pragma pop
/* Clear the AI command work, then choose a command for the given status mode. The command comes
 * from a weighted random table, and the row is picked from the acting unit's state. */
// FUN_001EB4A0
/* Select a weighted status-dependent AI command and dispatch its packed target condition. Only the
 * low 20 bits of the forwarded unit-status word affect table selection. */
void btlAiSelectStatusCommand(u8 *action, u8 *command, u32 status) {
    BtlAction *statusAction = (BtlAction *)action;

    extern s32 datGetMoney();
    extern void btlAICommandSetActionCode(u8 *action, u8 *command, u16);
    extern s32 datCalcRandomBelow(u32 limit);
    extern void memset(void *action, s32 command, s32);
    extern void *D_006098BC[];
    extern void *D_00609934[];
    extern u8 D_00609E50[];
    extern u8 D_00609EF0[];
    extern u8 D_00609F90[];
    extern u8 D_0060A030[];
    extern u8 *iGpffffb3c4;
    extern u8 iGpffffa4d8;
    u8 *table;
    u32 actionWord;
    s32 threshold;
    u16 state;
    s32 index;
    s32 sum;
    s32 cumulative;
    s32 scanIndex;
    u64 mode;
    u8 *current;
    u8 *entry;
    u8 weight;
    u8 *row;
    u8 *unitData;
    u8 *unit;
    s32 (*callback)(u8 *, s64);

    ((BtlAiCommandWork *)command)->targetCount = 0;
    ((BtlAiCommandWork *)command)->command = 0;
    ((BtlAiCommandWork *)command)->skill = 0;
    ((BtlAiCommandWork *)command)->kind = 0;
    ((BtlAiCommandWork *)command)->unk50 = 0;
    ((BtlAiCommandWork *)command)->unk54 = 0;
    ((BtlAiCommandWork *)command)->unk58 = 0;
    memset(command + 0x3E, 0, 6);
    table = NULL;
    entry = NULL;
    mode = ((u64)status << 44) >> 44;
    switch (mode) {
    case 0x10:
        unit = (u8 *)(((BtlAction *)action)->unit);
        if (((BtlUnit *)unit)->genus == 1) {
            if ((((BtlSoundEnemyStatusRow *)iGpffffb3c4)[((BtlUnit *)unit)->charId ].flags & 0x2000) == 0 &&
                (((BtlAction *)action)->unk_1a & 0x4000) == 0) {
                state = 0;
            } else {
                state = 2;
            }
        } else if (datGetMoney() != 0) {
            state = 0;
        } else {
            state = 2;
        }
        if (((s32 (*)(u8 *, s32))D_006098BC[0])(action, 1) != 0)
            state++;
        if (statusAction->unit->genus == 0)
            table = D_00609E50;
        else
            table = D_00609EF0;
        break;
    case 4:
        unitData = (u8 *)(((BtlAction *)action)->unit);
        if (((BtlUnit *)unitData)->genus == 0 && ((BtlUnit *)unitData)->charId == 1) {
            state = 1;
        } else {
            state = (u16)(((s32 (*)(u8 *, s32))D_00609934[0])(action, 0) != 1);
        }
        table = D_00609F90;
        break;
    case 2:
        entry = (u8 *)&iGpffffa4d8 - 8;
        break;
    case 0x100:
        state = 0;
        table = D_0060A030;
        break;
    }
    if (table != NULL) {
        sum = 0;
        index = 0;
        row = table + (state & 0xFFFF) * 0x28;
        goto eb4a0_sum_test;
eb4a0_sum_body:
        sum = (sum + ((BtlAiWeightedCommand *)row)[(u16)index].weight) & 0xFFFF;
        index = (index + 1) & 0xFFFF;
eb4a0_sum_test:
        if ((index & 0xFFFF) < 5)
            goto eb4a0_sum_body;
        entry = NULL;
        threshold = (s32)(datCalcRandomBelow(sum & 0xFFFF) & 0xFFFF);
        cumulative = 0;
        for (scanIndex = 0; (scanIndex & 0xFFFF) < 5;
             scanIndex = (scanIndex + 1) & 0xFFFF) {
            current = row + ((u16)scanIndex * 8);
            weight = *(u8 *)current;
            cumulative = (cumulative + weight) & 0xFFFF;
            if (threshold <= cumulative && weight > 0) {
                entry = current;
                break;
            }
        }
    }
    btlAICommandSetActionCode(action, command, ((BtlAiWeightedCommand *)entry)->command);
    actionWord = ((BtlAiWeightedCommand *)entry)->targetCondition;
    callback = *(s32 (**)(u8 *, s64))((u8 *)D_00609CE0 +
                                      (((actionWord & 0xFF000000) >> 24) * 8));
    if (callback(action, (s64)((u64)actionWord << 40 >> 40)) == 0)
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
}

// FUN_001EB7F0
/* Leave damage phase when battle flag 0x1000 is set and restore stream playback. */
void btlTargetEndDamagePhase(void) {
    s32 flags;
    u8 *battle;
    u8 *flagAddress;

    battle = iGpffffb3ac;
    flagAddress = battle + 0xC;
    flags = (s32)(((BtlBattleState *)battle)->flags);
    if (flags & 0x1000) {
        *(s32 *)flagAddress = flags & ~0x1000;
        btlDamageEndPhase(((BtlBattleState *)iGpffffb3ac)->uiTask);
        sdkSndStartStream(1, 0xF, 2, 0x13);
    }
}

/* Allow damage-phase controls unless battle flag 0x80 or encounter 0x215 forbids them. */
// FUN_001EB860
s32 btlTargetCanControlDamagePhase(void) {
    u8 *battle;
    s32 result;

    battle = iGpffffb3ac;
    if ((s32)(((BtlBattleState *)battle)->flags) & 0x80) {
        result = 0;
        goto done;
    }
    if (((BtlBattleState *)battle)->encounterRecord != 0) {
        if (btlCurrentUnitId() == 0x215) {
            result = 0;
            goto done;
        }
    }
    result = 1;
done:
    return result;
}

// FUN_001EB8D0
/* Toggle damage phase from input bits 0x10/0x20 when the battle permits it. */
void btlTargetUpdateDamagePhaseInput(void) {
    extern void btlDamageBeginPhase(s32 task);
    extern void btlDamageEndPhase(s32 task);
    extern u16 D_008C024E[];
    s32 flags;
    s32 phaseActive;
    s32 enabled;
    u8 *battle;
    u8 *initialBattle;
    u8 *flagAddress;

    initialBattle = iGpffffb3ac;
    if ((s32)(((BtlBattleState *)initialBattle)->flags) & 0x80) {
        enabled = 0;
    } else if ((((BtlBattleState *)initialBattle)->encounterRecord != 0) &&
               (btlCurrentUnitId() == 0x215)) {
        enabled = 0;
    } else {
        enabled = 1;
    }
    if ((enabled != 0) &&
        (battle = iGpffffb3ac,
         flagAddress = battle + 0xC,
         flags = (s32)(((BtlBattleState *)battle)->flags),
         ((flags & 0x2000) != 0))) {
        phaseActive = flags & 0x1000;
        if (phaseActive != 0) {
            if (((D_008C024E[0] & 0x10) || (D_008C024E[0] & 0x20)) &&
                (phaseActive != 0)) {
                *(s32 *)flagAddress = *(s32 *)flagAddress & ~0x1000;
                btlDamageEndPhase(((BtlBattleState *)iGpffffb3ac)->uiTask);
                sdkSndStartStream(1, 0xF, 2, 0x13);
            }
        } else if ((D_008C024E[0] & 0x10) && (phaseActive == 0)) {
            *(s32 *)flagAddress = flags | 0x1000;
            btlDamageBeginPhase(((BtlBattleState *)iGpffffb3ac)->uiTask);
            sdkSndStartStream(1, 0xF, 2, 0x12);
        }
    }
}

