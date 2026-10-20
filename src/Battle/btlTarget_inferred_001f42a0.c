#include "btl_sound_internal.h"
#include "h_cdvd_request_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"
/* Force the offset operand into the first addu slot. */

/* Force the base operand into the first addu slot. */

/* The step trigger occupies the first eight bytes of the playback block. */
typedef struct BtlActionStepCounter {
    u16 elapsed;
    u16 interval;
} BtlActionStepCounter;
typedef struct BtlActionStepState {
    BtlActionStepCounter counter;
    u16 pending;
    u16 unk06;
} BtlActionStepState;

/* Packet 0x800 has 0x18 bytes of work, populated by btlTargetCreateTargetPacket. */
typedef struct BtlTargetCallbackWork {
    s32 action;
    u16 command;
    u8 pad06[2];
    s32 argument;
    s32 extraArgument;
    s32 flags;
    s32 result;
} BtlTargetCallbackWork;

extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern u8 *iGpffffb3c4;
extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern s32 btlActionRunTargetCallback(s32 context, u16 argument, s32 option, s32 extra, s32 argumentMode);
extern void btlSoundCancelPlayback();
extern void btlActionStepMessagePhase();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);


extern s32 btlSideAverageBattleStat(s32 sideMask, s32 stat, s32 excludedStatus);

extern u32 datCalcRandomBelow();
extern u8 D_0060AB08[];
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern u8 D_00624B20[];
extern u8 D_00624B22[];
extern s32 btlCurrentUnitId(void);



extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];







extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f42a0-001f5ed0 */

extern s32 btlActionAnyTargetHitRowStatus(u8 *action);
extern s32 btlActionSameGenusTargetsHaveDelta(u8 *action);
extern s32 btlActionAnyTargetClearsDeathStatus(u8 *action);
extern s32 btlActionTargetsHaveDamageResult(u8 *action, s32 mode);
extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlTargetGroupStateMatches(u8 *context);
extern s32 btlSoundRequestPlayback(s16 channel, s32 playbackId);
extern void btlSoundCancelPlayback(void);
extern u32 datCalcIsLowHp(s32 unit);
extern u8 *btlActionFindByUnit(s32 unit);
#pragma push
#pragma pop
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: closes the invariant-hoist bracket for func_001f0af0. */
/* measured: loop-invariant probe for func_001f0c50's shared true value. */
/* measured: close opt_loop_invariants after func_001f0c50 probe. */
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: closes the invariant-hoist bracket for func_001f0d30. */
/* measured: opt_loop_invariants on preserves the nonzero-path constant and loop preheaders for func_001f0dd0. */
/* measured: close opt_loop_invariants after func_001f0dd0. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
/* measured: opt_loop_invariants on preserves target loop preheaders and state materialisation. */
/* measured: close opt_loop_invariants after btlTargetGroupStateMatches probe. */
#pragma push
/* measured: normalized result/record snapshots need invariant motion for the retail 0x310 frame. */
#pragma pop
/* measured: opt_propagation off keeps the iGpffffb3b8 base load ahead of the
   index arithmetic and the 0x70 field load in a temporary before its saved copy. */
/* measured: restore propagation for the rest of the unit. */
/* Return the current-actor message only for the selected action. */
/* Raw selected-action word comparison preserves the existing integer callback contract; the shared state stores a pointer. */
// FUN_001F42A0
s32 btlActionGetCurrentActorMsgCode(s32 context) {
    if (*(s32 *)(iGpffffb3ac + 0x170) != context) {
        return -1;
    }
    return 0x173;
}

/* Choose the default message, including the battle-flag/actor-id exception. */
/* Raw battle flags preserve the signed-word access of this callback; the shared field is unsigned. */
// FUN_001F42D0
s32 btlActionGetDefaultMsgCode(void) {
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) != 0) {
        if (btlCurrentUnitId() == 0x20B) {
            return 0x18B;
        }
    }
    return 0x165;
}

/* Choose the selected-action or enemy-side message, otherwise return -1. */
// FUN_001F4330
s32 btlActionGetSideMsgCode(u8 *context)
{
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == context) {
        return 0x99;
    }
    if (((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus == 1) {
        return 0x5D;
    }
    return -1;
}

/* Map party character ids to the message bank beginning at 0x68. */
// FUN_001F4380
s32 func_001f4380(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return 0x68;
    case 2:
        return 0x69;
    case 3:
        return 0x6A;
    case 4:
        return 0x6B;
    case 6:
        return 0x6C;
    case 7:
        return 0x6D;
    case 8:
        return 0x6E;
    default:
        return -1;
    }
}

/* Select a character message tier only while enemies remain. */
/* measured: the remaining action-unit reload changed MATCH when converted to the typed unit field. */
// FUN_001F4430
s32 btlActionGetCharacterLevelMsg(u8 *action, s32 tier) {
    s32 messageOffset;
    u16 characterId;

    if (((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->genus != 0) {
        return -1;
    }
    if (tier <= 0) {
        return -1;
    }
    if (!(func_001ef720(2, 0x80000) & 0xFFFF)) {
        return -1;
    }
    messageOffset = (5 - tier) * 7;
    characterId = ((BtlUnit *)*(u8 **)(action + 0x30))->charId;
    switch (characterId) {
    case 1:
        return messageOffset + 0xFD;
    case 2:
        return messageOffset + 0xFE;
    case 3:
        return messageOffset + 0xFF;
    case 4:
        return messageOffset + 0x100;
    case 6:
        return messageOffset + 0x101;
    case 7:
        return messageOffset + 0x102;
    case 8:
        return messageOffset + 0x103;
    default:
        return -1;
    }
}

/* Map party character ids to the message bank beginning at 0x3D. */
// FUN_001F4550
s32 func_001f4550(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return 0x3D;
    case 2:
        return 0x3E;
    case 3:
        return 0x3F;
    case 4:
        return 0x40;
    case 6:
        return 0x41;
    case 7:
        return 0x42;
    case 8:
        return 0x43;
    default:
        return -1;
    }
}

/* Map party character ids to the message bank beginning at 0x35. */
// FUN_001F4600
s32 func_001f4600(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return 0x35;
    case 2:
        return 0x36;
    case 3:
        return 0x37;
    case 4:
        return 0x38;
    case 6:
        return 0x39;
    case 7:
        return 0x3A;
    case 8:
        return 0x3B;
    default:
        return -1;
    }
}

/* Map party character ids to the message bank beginning at 0x14A. */
// FUN_001F46B0
s32 func_001f46b0(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return 0x14A;
    case 2:
        return 0x14B;
    case 3:
        return 0x14C;
    case 4:
        return 0x14D;
    case 6:
        return 0x14E;
    case 7:
        return 0x14F;
    case 8:
        return 0x150;
    default:
        return -1;
    }
}

/* Map party character ids to the message bank beginning at 0x143. */
// FUN_001F4760
s32 func_001f4760(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return 0x143;
    case 2:
        return 0x144;
    case 3:
        return 0x145;
    case 4:
        return 0x146;
    case 6:
        return 0x147;
    case 7:
        return 0x148;
    case 8:
        return 0x149;
    default:
        return -1;
    }
}

/* Choose a character/tier message, with optional thirty-percent special-bank rolls. */
/* measured: the remaining repeated action-unit loads changed MATCH when typed, including one-access substitutions. */
// FUN_001F4810
s32 btlActionPickMsgCodeByRoll(u8 *action, s32 flags, s32 tier) {
    s32 messageOffset;

    if (((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->genus != 0) {
        return -1;
    }
    if ((tier >= 6) || (tier <= 0)) {
        return -1;
    }
    if (tier == 1) {
        if ((flags & 2) && (datCalcRandomBelow(0x64) < 0x1E)) {
            s32 firstChoice;
            if (((BtlUnit *)*(u8 **)(action + 0x30))->genus != 0) {
                firstChoice = -1;
            } else {
                switch (((BtlUnit *)*(u8 **)(action + 0x30))->charId) {
                case 1:
                    firstChoice = 0x14A;
                    break;
                case 2:
                    firstChoice = 0x14B;
                    break;
                case 3:
                    firstChoice = 0x14C;
                    break;
                case 4:
                    firstChoice = 0x14D;
                    break;
                case 6:
                    firstChoice = 0x14E;
                    break;
                case 7:
                    firstChoice = 0x14F;
                    break;
                case 8:
                    firstChoice = 0x150;
                    break;
                default:
                    firstChoice = -1;
                    break;
                }
            }
            return firstChoice;
        }
        if ((flags & 4) && (datCalcRandomBelow(0x64) < 0x1E)) {
            s32 secondChoice;
            if (((BtlUnit *)*(u8 **)(action + 0x30))->genus != 0) {
                secondChoice = -1;
            } else {
                switch (((BtlUnit *)*(u8 **)(action + 0x30))->charId) {
                case 1:
                    secondChoice = 0x143;
                    break;
                case 2:
                    secondChoice = 0x144;
                    break;
                case 3:
                    secondChoice = 0x145;
                    break;
                case 4:
                    secondChoice = 0x146;
                    break;
                case 6:
                    secondChoice = 0x147;
                    break;
                case 7:
                    secondChoice = 0x148;
                    break;
                case 8:
                    secondChoice = 0x149;
                    break;
                default:
                    secondChoice = -1;
                    break;
                }
            }
            return secondChoice;
        }
    }
    messageOffset = (5 - tier) * 7;
    switch (((BtlUnit *)*(u8 **)(action + 0x30))->charId) {
    case 1:
        return messageOffset + 0x120;
    case 2:
        return messageOffset + 0x121;
    case 3:
        return messageOffset + 0x122;
    case 4:
        return messageOffset + 0x123;
    case 6:
        return messageOffset + 0x124;
    case 7:
        return messageOffset + 0x125;
    case 8:
        return messageOffset + 0x126;
    default:
        return -1;
    }
}

/* Map party character ids to the message bank beginning at 0x158. */
// FUN_001F4AD0
s32 func_001f4ad0(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return 0x158;
    case 2:
        return 0x159;
    case 3:
        return 0x15A;
    case 4:
        return 0x15B;
    case 6:
        return 0x15C;
    case 7:
        return 0x15D;
    case 8:
        return 0x15E;
    default:
        return -1;
    }
}

/* Map party character ids to the message bank beginning at 0x4D. */
// FUN_001F4B80
s32 func_001f4b80(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return 0x4D;
    case 2:
        return 0x4E;
    case 3:
        return 0x4F;
    case 4:
        return 0x50;
    case 6:
        return 0x51;
    case 7:
        return 0x52;
    case 8:
        return 0x53;
    default:
        return -1;
    }
}

/* Map party character ids to the message bank beginning at 0x2D. */
// FUN_001F4C30
s32 func_001f4c30(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return 0x2D;
    case 2:
        return 0x2E;
    case 3:
        return 0x2F;
    case 4:
        return 0x30;
    case 6:
        return 0x31;
    case 7:
        return 0x32;
    case 8:
        return 0x33;
    default:
        return -1;
    }
}

/* Choose the character message bank according to the battle flag and current actor id. */
/* measured: the initial unit-pointer load must remain raw to preserve the verified branch/load sequence. */
// FUN_001F4CE0
s32 func_001f4ce0(u8 *action)
{
    u16 specialCharacterId;
    u16 characterId;
    u8 *unit;

    unit = *(u8 **)(action + 0x30);
    if (unit[0xA2] != 0) {
        return -1;
    }
    if ((((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x20000000) != 0) {
        if (btlCurrentUnitId() != 0x20B) {
            goto high_default_4ce0;
        }
        specialCharacterId = ((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->charId;
        switch (specialCharacterId) {
        case 2:
            return 0x18C;
        case 3:
            return 0x18D;
        case 4:
            return 0x18E;
        case 6:
            return 0x18F;
        case 7:
            return 0x190;
        case 8:
            return 0x18A;
        case 0:
        case 1:
        case 5:
        default:
            goto high_default_4ce0;
        }
    }
    goto low_switch_4ce0;
high_default_4ce0:
    return -1;
low_switch_4ce0:
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 2:
        return 0x26;
    case 3:
        return 0x27;
    case 4:
        return 0x28;
    case 6:
        return 0x29;
    case 7:
        return 0x2A;
    case 8:
        return 0x2B;
    case 0:
    case 1:
    case 5:
    default:
        return -1;
    }
}

/* Native b210 -O2 recovery: 1876 bytes plus 12 zero tail bytes.
   Each selected field has its own uintptr_t address, derived from that
   field's array base. The byte offset stays live across the previous-code
   check; the actor address is formed after recording the selected code.
   This preserves both addiu/LH-at-zero pairs and the signed actor guard.
   The owned nine-entry switch table resolves to retail at 0x00747500.
   See docs/probe_archive/BattleAction_20260922_resume.md. */
/* Collect party status/buff and enemy-count messages, then pick a non-repeated candidate. */
/* measured: remaining unit and playback snapshots changed MATCH under per-access typing; keep the raw loads around query callbacks. */
// FUN_001F4E50
s64 btlActionPickRandomStatusMsg(u8 *context) {
    struct ActionMessageChoice {
        s16 code;
        s16 actor;
    } choices[64];
    s16 selectedCode;
    u8 *unit;
    s32 choiceCount;
    s32 code8ACount;
    s32 enemyCount;
    u8 *battle;

    if (((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus != 0) {
        return -1;
    }
    choiceCount = 0;
    code8ACount = 0;
    battle = iGpffffb3ac;
    unit = ((BtlBattleState *)battle)->unitLists[0];
    while (unit != NULL) {
        if (datCalcIsDead((s32)((u8 *)((BtlUnit *)unit)->datUnit), 0) == 0) {
            u8 *unitWork = (u8 *)btlActionFindByUnit((s32)unit);
            if ((unitWork == NULL) || !(((BtlAction *)unitWork)->flags & 0x20)) {
                if (datCalcIsLowHp((s32)((void *)*(u8 **)(unit + 0xA64))) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x8A;
                    choice->actor = ((BtlUnit *)unit)->charId;
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                    code8ACount = (code8ACount + 1) & 0xFFFF;
                }
                if (((BtlUnit *)unit)->charId != 1) {
                    if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x10) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0x99;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x20) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0x9f;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x4) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xa5;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x2) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xab;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x1) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xb1;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x40) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xb7;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x80) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xbd;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x8) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xc3;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    }
                }
                if (datCalcHasBuffMask(*(DatUnit **)(unit + 0xA64), 0xA) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x6F;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
                if (datCalcHasBuffMask(*(DatUnit **)(unit + 0xA64), 0x80) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x76;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
                if (datCalcHasBuffMask(*(DatUnit **)(unit + 0xA64), 0x220) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x7D;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
            }
        }
        unit = (u8 *)((BtlUnit *)unit)->nextUnit;
    }
    {
        u8 *sourceUnit = *(u8 **)(context + 0x30);
        if (((BtlUnit *)sourceUnit)->charId == 1) {
            if (datCalcChkBadStatus((s32)((BtlUnit *)sourceUnit)->datUnit, 0x20) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x92;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x2) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x94;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x1) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x95;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x40) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x96;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x80) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x97;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x8) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x98;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            }
        }
    }
    if ((code8ACount & 0xFFFF) >= 2) {
        choices[choiceCount & 0xFFFF].code = 0x89;
        choices[choiceCount & 0xFFFF].actor = -1;
        choiceCount = (choiceCount + 1) & 0xFFFF;
    }
    enemyCount = func_001ef720(2, 0x80000) & 0xFFFF;
    {
        u8 *battleCounts = iGpffffb3ac;
        s16 *savedEnemyCount = (s16 *)(battleCounts + 0xA6C);
        if (((BtlSoundPlayback *)(battleCounts + 0xA44))->unk28 == enemyCount) {
            if ((enemyCount < 6) && (enemyCount > 0)) {
                choices[choiceCount & 0xFFFF].code = 0x89 - enemyCount;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            }
        } else {
            *savedEnemyCount = enemyCount;
        }
    }
    if ((choiceCount & 0xFFFF) <= 0) {
        return -1;
    }
    {
        u32 selectedOffset = (datCalcRandomBelow(choiceCount & 0xFFFF) & 0xFFFF) * 4;
        /* These are two field addresses within the same selected row. */
        uintptr_t codeAddress = (uintptr_t)((u8 *)choices + selectedOffset);
        s16 actorId;
        uintptr_t actorAddress;
        u8 *battleSelection;
        s32 *previousCode;
        selectedCode = *(s16 *)codeAddress;
        battleSelection = iGpffffb3ac;
        previousCode = (s32 *)(battleSelection + 0xA68);
        if (((BtlSoundPlayback *)(battleSelection + 0xA44))->unk24 == selectedCode) {
            return -1;
        }
        *previousCode = selectedCode;
        actorAddress = (uintptr_t)((u8 *)&choices[0].actor + selectedOffset);
        actorId = *(s16 *)actorAddress;
        if (actorId >= 0) {
            switch (actorId) {
            case 2:
                selectedCode = selectedCode + 1;
                break;
            case 3:
                selectedCode = selectedCode + 2;
                break;
            case 4:
                selectedCode = selectedCode + 3;
                break;
            case 6:
                selectedCode = selectedCode + 4;
                break;
            case 7:
                selectedCode = selectedCode + 5;
                break;
            case 8:
                selectedCode = selectedCode + 6;
                break;
            }
        }
    }
    return selectedCode;
}

/* Select an ailment message for the selected action while its pending kind is 0xB. */
/* measured: these DatUnit-pointer reloads must remain raw after the first status query; typing either changed MATCH. */
// FUN_001F55B0
s32 btlActionGetPendingMsgCode(u8 *context)
{
    u8 *work;

    if (((BtlBattleState *)iGpffffb3ac)->selectedAction != context) {
        return -1;
    }
    work = (u8 *)((BtlAction *)context)->unit;
    switch (((BtlAction *)context)->unk_6c) {
    case 0xB:
        if (datCalcChkBadStatus((s32)((BtlUnit *)work)->datUnit, 0x10) != 0) {
            return 0x91;
        }
        if (datCalcChkBadStatus(*(s32 *)(work + 0xA64), 4) != 0) {
            return 0x93;
        }
        if (datCalcChkBadStatus(*(s32 *)(work + 0xA64), 2) != 0) {
            return 0x94;
        }
        break;
    default:
        break;
    }
    return -1;
}

/* Map an encounter slot from one through five to its message code. */
/* The encounter record is opaque here; only its halfword slot selector at +2 is established. */
// FUN_001F5680
/* The `return -1` and `return v + 0x11` blocks are reached by goto so they
   land in retail's order; writing both as plain returns emits them the other
   way round. */
s32 btlActionGetSlotMsgCode(void) {
    u8 *p;
    s32 v;

    p = *(u8 **)(iGpffffb3ac + 0xC68);
    if (p == NULL) {
        return -1;
    }
    v = *(u16 *)(p + 2);
    if (v < 6) {
        if (v != 0) {
            goto add;
        }
    }
    return -1;
add:
    return v + 0x11;
}

/* Gate a target-message callback against playback state and encounter flags, then request playback. */
/* measured: remaining playback-state reloads changed MATCH when typed. Encounter-rule and relative-message directory payloads remain opaque. */
// FUN_001F56D0
s32 btlActionRunTargetCallback(s32 context, u16 argument, s32 option, s32 extra, s32 argumentMode) {
    s32 flags;
    s32 mode;
    s32 index;
    s32 value;
    s32 (*callback)(s32, s32, s32, s32);
    s32 result;
    u8 *table;

    extern s32 (*D_0060AB20[])(s32, s32, s32, s32);
    extern s32 btlSoundRequestPlayback(u16, s32);

    flags = *(s32 *)(iGpffffb3ac + 0xC);
    if ((flags & 0x1000000) == 0) {
        return 1;
    }
    if (((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->phase != 0) {
        return 0;
    }
    mode = argumentMode & 6;
    if ((mode == 0) && ((*(u16 *)(iGpffffb3ac + 0xA4E) & 1) != 0)) {
        return 1;
    }
    table = iGpffffb414 + (*(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8) * 0x18);
    if ((*(s32 *)table & 0x400) != 0) {
        return 1;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xA4E) & 1) != 0) {
        index = argument & 0xFFFF;
        if (*(s16 *)(iGpffffb3ac + 0xA5C) == index) {
            return 1;
        }
        if (*(s16 *)(iGpffffb3ac + 0xA64) == index) {
            return 1;
        }
    }
    callback = D_0060AB20[argument & 0xFFFF];
    if (callback == NULL) {
        return 1;
    }
    value = callback(context, option, extra, 0);
    if (value < 0) {
        return 1;
    }
    if ((*(s32 *)table & 0x1000) != 0) {
        u8 *pool;
        u8 *entries;
        s32 slot;
        pool = *(u8 **)(iGpffffb3ac + 0xA54);
        slot = value & 0xFFFF;
        entries = (u8 *)((HCdvdRequest *)pool)->data;
        if (*(u8 *)(entries + slot * 0xC) != 0) {
            return 1;
        }
    }
    if ((argumentMode & 2) != 0) {
        btlSoundCancelPlayback();
        ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->unk2A = 2;
    } else {
        ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->unk2A = 0;
    }
    result = btlSoundRequestPlayback(argument, value);
    return result;
}

/* Advance the delayed message request, select a record, and remember its callback/channel. */
/* The message directory retains twelve-byte relative-offset rows; its resource payload is outside the playback-state layout. */
// FUN_001F58D0
void btlActionStepMessagePhase(void)
{
    s16 delay;
    u8 *phaseAddress;
    u8 *delayAddress;
    u8 *messageRecord;
    u8 *messageTable;
    u16 phase;
    u8 *messageState;
    u8 *codeState;
    u8 *actorState;
    u8 *flagState;
    u8 *idleState;
    u8 *battle;

    battle = iGpffffb3ac;
    phaseAddress = battle + 0xA50;
    phase = *(u16 *)phaseAddress;
    switch (phase) {
    case 0:
        goto done;
    case 1:
        goto case1;
    case 2:
        goto case2;
    default:
        goto done;
    }
case1:
    delayAddress = battle + 0xA6E;
    delay = *(s16 *)delayAddress;
    if (delay > 0) {
        *(s16 *)delayAddress = (s16)(delay - 1);
        goto done;
    }
    *(u16 *)phaseAddress = 2;
case2:
    messageState = iGpffffb3ac;
    messageTable = *(u8 **)(((BtlSoundPlayback *)(messageState + 0xA44))->handle + 0x110);
    messageRecord = messageTable + ((s32 *)(messageTable + 4))[*(u16 *)(messageState + 0xA60) * 3];
    fclMiscSetStatusCode(messageRecord, phaseAddress, battle);
    fclMiscAddRecord(((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->channel,
                  datCalcRandomBelow(itfMesRecordCount(messageRecord)), 0, 0);
    codeState = iGpffffb3ac;
    ((BtlSoundPlayback *)(codeState + 0xA44))->currentId = ((BtlSoundPlayback *)(codeState + 0xA44))->pendingId;
    actorState = iGpffffb3ac;
    ((BtlSoundPlayback *)(actorState + 0xA44))->currentChannel = ((BtlSoundPlayback *)(actorState + 0xA44))->pendingChannel;
    flagState = iGpffffb3ac;
    ((BtlSoundPlayback *)(flagState + 0xA44))->flags =
        (u16)(((BtlSoundPlayback *)(flagState + 0xA44))->flags | 1);
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->phase = 0;
done:
    if (fclMiscGetRecordCount() == 0) {
        idleState = iGpffffb3ac;
        ((BtlSoundPlayback *)(idleState + 0xA44))->flags =
            (u16)(((BtlSoundPlayback *)(idleState + 0xA44))->flags & 0xFFFE);
    }
}

/* Advance pending step counters and enqueue the trigger action when its threshold is reached. */
/* measured: remaining counter/action reloads changed MATCH with typed substitutions; preserve their callback-crossing byte-pointer shape. */
// FUN_001F5A00
void btlActionCheckStepTrigger(s32 context)
{
    extern s32 btlActionGetQueueFront(void);
    extern s32 btlActionGetActive(void);
    extern s32 btlActionActiveListPush(s32 action);
    s32 i;
    s32 result;
    u8 *current;
    u8 *global;

    result = 0;
    i = 0;
    while (((i & 0xFFFF) <= 0) && (result == 0)) {
        if ((((BtlActionStepState *)(iGpffffb3ac + 0xA44))->pending &
             ((1 << (i & 0xFFFF)) & 0xFFFF)) != 0) {
            switch (((1 << (i & 0xFFFF)) & 0xFFFF)) {
            case 1:
                current = (u8 *)btlActionGetQueueFront();
                if ((current != NULL) &&
                    ((((BtlAction *)current)->unk_1a & 1) != 0) &&
                    (context != 0) &&
                    (((BtlUnit *)(u8 *)((BtlAction *)current)->unit)->genus == 0)) {
                    ((BtlActionStepCounter *)(iGpffffb3ac + ((i & 0xFFFF) * 4) + 0xA44))->elapsed =
                        (u16)(((BtlActionStepCounter *)(iGpffffb3ac +
                                       ((i & 0xFFFF) * 4) + 0xA44))->elapsed + 1);
                    if ((context != 0) &&
                        (*(u16 *)(iGpffffb3ac +
                                  ((i & 0xFFFF) * 4) + 0xA46) >= 4) &&
                        (((BtlActionStepCounter *)(iGpffffb3ac +
                                  ((i & 0xFFFF) * 4) + 0xA44))->elapsed ==
                         (((BtlActionStepCounter *)(iGpffffb3ac +
                                   ((i & 0xFFFF) * 4) + 0xA44))->interval >> 1))) {
                        btlActionRunTargetCallback(
                            (s32)((BtlBattleState *)iGpffffb3ac)->selectedAction, 4, 0, 0, 4);
                    } else {
                        global = iGpffffb3ac;
                        if ((((BtlActionStepCounter *)(global +
                                      ((i & 0xFFFF) * 4) + 0xA44))->elapsed >=
                             ((BtlActionStepCounter *)(global +
                                      ((i & 0xFFFF) * 4) + 0xA44))->interval) &&
                            (datCalcChkBadStatus(
                                 *(s32 *)(*(u8 **)(((BtlBattleState *)global)->selectedAction +
                                                   0x30) + 0xA64),
                                 0x180010) == 0) &&
                            (btlActionGetActive() == 0)) {
                            *(u16 *)(((BtlBattleState *)iGpffffb3ac)->selectedAction + 0x16) =
                                0x1C;
                            btlActionActiveListPush(
                                (s32)((BtlBattleState *)iGpffffb3ac)->selectedAction);
                            result = 1;
                            ((BtlActionStepState *)(iGpffffb3ac + 0xA44))->pending =
                                (u16)(((BtlActionStepState *)(iGpffffb3ac + 0xA44))->pending &
                                      0xFFFE);
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
        i = (i + 1) & 0xFFFF;
    }
}

/* measured: 708/720B MATCH; the remaining 12 bytes are zero tail padding.
   Paired group statistics stay in FPRs and preserve the retail operation
   tree and unsigned conversions without additional storage. */
/* Roll and clamp a group-stat ratio, then derive the step-trigger interval from it. */
// FUN_001F5BD0
#pragma push
/* measured: btlActionRollGroupRatio MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void btlActionRollGroupRatio(s32 context)
{
    u32 mask;
    unsigned int random_value;
    struct { f32 stat3; f32 stat4; } group1, group2;
    f32 random_ratio;
    f32 ratio;
    u16 result;

    mask = ((1 << (u16)context) & 0xFFFF);
    ((BtlActionStepState *)(iGpffffb3ac + 0xA44))->pending =
        (u16)(((BtlActionStepState *)(iGpffffb3ac + 0xA44))->pending | mask);
    switch ((u16)context) {
    case 0:
        goto body;
    default:
        goto done;
    }
body:
    group1.stat3 = (f32)(u32)btlSideAverageBattleStat(1, 3, 0x80000);
    group2.stat3 = (f32)(u32)btlSideAverageBattleStat(2, 3, 0x80000);
    group1.stat4 = (f32)(u32)btlSideAverageBattleStat(1, 4, 0x80000);
    group2.stat4 = (f32)(u32)btlSideAverageBattleStat(2, 4, 0x80000);

    random_value = datCalcRandomBelow(0xF) + 5;
    random_ratio = (f32)random_value;
    random_ratio /= 10.0f;
    ratio = random_ratio * (30.0f * ((group1.stat3 / group2.stat3) * (group1.stat4 / group2.stat4)));
    if (ratio > 50.0f) {
        ratio = 50.0f;
    } else if (ratio < 10.0f) {
        ratio = 10.0f;
    }
    {
        s32 offset;
        u8 *p;
        offset = (u16)context * 4;
        p = (u8 *)(offset + (s32)iGpffffb3ac);
        ((BtlActionStepCounter *)(p + 0xA44))->elapsed = 0;
        result = (u16)(100.0f / ratio);
        offset = (u16)context * 4;
        p = (u8 *)(offset + (s32)iGpffffb3ac);
        ((BtlActionStepCounter *)(p + 0xA44))->interval = result;
    }
done:
    ;
}

#pragma pop
/* Test whether the requested step-trigger bit is pending. */
// FUN_001F5EA0
s32 btlActionIsPendingBit(s32 context) {
    return (s32)((((BtlActionStepState *)((u8 *)iGpffffb3ac + 0xA44))->pending & (1 << (context & 0xFFFF))) != 0);
}

/* Cache target callback dispatch and optionally wait until its message playback has finished. */
/* measured: the two remaining cached-result accesses changed MATCH when replaced with typed work fields. */
// FUN_001F5ED0
s32 btlActionCachedDispatch(u8 *context)
{
    s32 result;
    u8 *global;

    if (((BtlTargetCallbackWork *)context)->result == 0) {
        *(s32 *)(context + 0x14) = btlActionRunTargetCallback(
            ((BtlTargetCallbackWork *)context)->action,
            ((BtlTargetCallbackWork *)context)->command,
            ((BtlTargetCallbackWork *)context)->argument,
            ((BtlTargetCallbackWork *)context)->extraArgument,
            ((BtlTargetCallbackWork *)context)->flags);
    }
    result = *(s32 *)(context + 0x14);
    if ((result == 1) && (((BtlTargetCallbackWork *)context)->flags & 1) != 0) {
        global = iGpffffb3ac;
        if (((((BtlSoundPlayback *)(global + 0xA44))->flags & 1) != 0) ||
            (((BtlSoundPlayback *)(global + 0xA44))->phase != 0)) {
            result = 0;
        }
    }
    return result;
}

