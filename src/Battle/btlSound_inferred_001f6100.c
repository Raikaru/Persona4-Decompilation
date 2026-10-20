#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"
#include "btl_sound_internal.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}

/* Force the base operand into the first addu slot. */
static inline u32 addBaseFirst(u32 base, u32 offset) {
    return base + offset;
}
static inline s32 promoteS16(s16 value) {
    return value;
}
static inline u32 addOffsetAfterBase(u32 base, u32 offset) {
    return offset + base;
}

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
extern s32 datCalcGetBadStatus(s32 unit);
extern u8 *iGpffffb3c4;
extern s32 datCalcGetHp(u8 *unit);
extern s32 datCalcGetSp(u8 *unit);
extern s32 datCalcMaxHp(u8 *unit);
extern u16 datCalcMaxSp(u8 *unit);
extern s32 datCalcGetBadStatusNoDown(u8 *unit);
extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void btlSoundCancelPlayback();
extern void btlActionStepMessagePhase();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *input, s32 value, s32 option);

extern void memset(void *destination, s32 value, u32 size);


extern u32 datCalcRandomBelow();
extern u8 D_0060AB08[];
extern void sdkSndPlayCue(s32 input, s32 value);
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
extern s32 btlSoundLoadPlaybackFile(u8 *work);
extern u8 D_00624B20[];
extern u8 D_00624B22[];

extern void H_Cdvd_Destroy(u8 *cdvd);
extern void fclMiscSetDoneFlag(void);

extern void fclMiscPruneGlobal(void);
extern void fclMiscStopAndClose(void);
extern s32 H_Cdvd_IsFileLoaded(u8 *cdvd);

extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];



extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);




extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

extern s32 btlTargetTestUnitFlag(s32 unitId, s32 bitIndex);



#pragma push
#pragma pop






/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f6100-001f73d0 */

extern s32 btlActionHasNoTargetClass(u32 action);
struct EffRandState;
static inline s32 battleMessageBand(s32 value, s32 band)
{
    return value + band;
}
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Clear playback requests and restore the inactive handle, channel and ID sentinels. */
// FUN_001F6100
void btlSoundResetPlaybackState(void)
{
    memset(iGpffffb3ac + 0xA44, 0, 0x2C);
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->handle = 0;
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->currentId = -1;
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->currentChannel = -1;
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->pendingId = -1;
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->pendingChannel = -1;
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->unk24 = -1;
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->unk28 = -1;
    *(s16 *)&((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->phase = 0;
    *(s16 *)&((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->flags = 0;
    *(s16 *)&((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->channel = 8;
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->unk2A = 0;
}

// FUN_001F6190
void btlSoundStepMessagePhase(void)
{
    btlActionStepMessagePhase();
}

/* Release the playback handle and clear both the loaded and active flags. */
// FUN_001F61B0
void btlSoundStopAndReleaseHandle(void)
{
    u8 *battle;
    u8 *handle;

    handle = *(u8 **)&((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->handle;
    if (handle != NULL) {
        H_Cdvd_Destroy(handle);
        *(u8 **)&((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->handle = NULL;
        battle = iGpffffb3ac;
        *(s32 *)&((BtlBattleState *)battle)->flags = *(s32 *)&((BtlBattleState *)battle)->flags & 0xFEFFFFFF;
    }
    battle = iGpffffb3ac;
    ((BtlSoundPlayback *)(battle + 0xA44))->flags = ((BtlSoundPlayback *)(battle + 0xA44))->flags & 0xFFFE;
    fclMiscSetDoneFlag();
}

/* Queue a playback ID unless it is already the active or pending request. */
// FUN_001F6220
s32 btlSoundRequestPlayback(s16 channel, s32 playbackId)
{
    u8 *battle;

    battle = iGpffffb3ac;
    if ((((BtlSoundPlayback *)(battle + 0xA44))->flags & 1) != 0) {
        if (((BtlSoundPlayback *)(battle + 0xA44))->currentId == playbackId) {
            return 1;
        }
        if (((BtlSoundPlayback *)(battle + 0xA44))->pendingId == playbackId) {
            return 1;
        }
    }
    ((BtlSoundPlayback *)(battle + 0xA44))->pendingChannel = channel;
    ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->pendingId = playbackId;
    *(s16 *)&((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->phase = 1;
    return 1;
}

// FUN_001F6290
s32 btlSoundIsPlaybackActive(void) {
    return (s32)((((BtlSoundPlayback *)((u8 *)iGpffffb3ac + 0xA44))->flags & 1) != 0);
}

/* Close playback UI state and clear the outstanding playback request. */
// FUN_001F62B0
void btlSoundCancelPlayback(void) {
    u8 *battle;

    fclMiscPruneGlobal();
    fclMiscStopAndClose();
    *(s16 *)&((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->phase = 0;
    battle = iGpffffb3ac;
    ((BtlSoundPlayback *)(battle + 0xA44))->flags &= 0xFFFE;
}

/* Choose an affinity-specific voice from the supported elements and relative level band. */
// FUN_001F62F0
s32 btlSoundPickResistVoice(u8 *unit)
{
    extern s32 datCalcGetLevel(u8 *unit);
    extern s32 datCalcGetAffinity(u8 *unit, s32 elementIndex);
    extern u32 effMiscRand(struct EffRandState *state);
    s32 code;
    s32 base;
    s32 random;
    u16 mode;
    u16 count;
    s16 i;
    s32 flags;
    s32 offset;
    u16 values[8];

    base = datGetFlag(0x38) != 0 ? 0xFA : 0xC8;
    random = func_001ef4d0(2, 0x80000) & 0xFFFF;
    flags = datCalcGetLevel(
        (u8 *)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit->datUnit) &
        0xFF;
    if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) != 0) {
        mode = 0;
    } else if ((random - flags) >= 4) {
        mode = 0;
    } else if ((flags - random) >= 4) {
        mode = 2;
    } else {
        mode = 1;
    }
    count = 0;
    i = 0;
    offset = mode * 0x1E;
    for (; i < 7; i++) {
        switch (i) {
        case 0:
            code = 0;
            break;
        case 1:
            code = 1;
            break;
        case 2:
            code = 2;
            break;
        case 3:
            code = 4;
            break;
        case 4:
            code = 3;
            break;
        case 5:
            code = 6;
            break;
        case 6:
            code = 7;
            break;
        default:
            break;
        }
        if ((((BtlUnit *)unit)->genus != 1) ||
            ((flags = (u16)code, btlTargetTestUnitFlag(((BtlUnit *)unit)->charId, flags)) != 0)) {
            flags = datCalcGetAffinity(*(u8 **)&((BtlUnit *)unit)->datUnit, code);
            if ((flags & 0x08000000) != 0) {
                values[count++] =
                    (u16)(battleMessageBand(base + (i * 2), offset) + 2 +
                          (effMiscRand(NULL) & 1));
            } else if ((flags & 0x07000000) != 0) {
                values[count++] =
                    (u16)(battleMessageBand(base + (i * 2), offset) + 2 +
                          (effMiscRand(NULL) & 1) + 0xE);
            }
        }
    }
    if (count > 0) {
        return values[datCalcRandomBelow(count)];
    }
    return base + (effMiscRand(NULL) & 1) + offset;
}

/* Load the requested playback bank, then enable its channel and loaded flag. */
// FUN_001F65D0
s32 btlSoundLoadPlaybackFile(u8 *work)
{
    extern void fclMiscOrStateFlags(u32 flags);
    extern void func_00440b68();
    extern s32 H_Cdvd_AcquireDirectory();
    extern u8 iGpffffa4e8;
    extern u8 iGpffffa4e0;
    extern u8 D_0060ABE8[];
    u16 phase;
    u16 channel;
    u8 *battle;

    /* measured: typing this phase load grows the loader from 320 to 328 bytes; its phase stores remain typed. */
    phase = MEMBER(u16, work, BtlSoundLoadWork, phase);
    switch (phase) {
    case 0:
        if (((BtlSoundLoadWork *)work)->bank == 0) {
            channel = 8;
        } else {
            channel = 5;
        }
        ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->channel = channel;
    case 1:
        func_00440b68(&iGpffffa4e8, D_0060ABE8, 0x713);
        ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->handle =
            H_Cdvd_AcquireDirectory(
                ((u8 **)&iGpffffa4e0)[((BtlSoundLoadWork *)work)->bank],
                0);
        ((BtlSoundLoadWork *)work)->phase = 2;
        goto block_14;
    case 2:
        if (H_Cdvd_IsFileLoaded(*(u8 **)&((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->handle) != 0) {
    case 3:
            fclMiscOrStateFlags(
                (1 << ((BtlSoundPlayback *)(iGpffffb3ac + 0xA44))->channel) | 1);
            ((BtlSoundLoadWork *)work)->phase = 4;
    case 4:
            battle = iGpffffb3ac;
            *(s32 *)&((BtlBattleState *)battle)->flags =
                *(s32 *)&((BtlBattleState *)battle)->flags | 0x01000000;
            return 1;
        }
        goto block_14;
    block_14:
    default:
        return 0;
    }
}

/* Create the bank-loading packet with an initial phase of zero. */
// FUN_001F6710
u8 *btlSoundCreateLoadPlaybackPacket(s32 bank) {
    u8 *p;
    u8 *q;

    p = (u8 *)btlPacketAlloc(0x803, 8);
    ((BtlPacket *)p)->flags &= 0xFE;
    *(void **)&((BtlPacket *)p)->updateFunc = (void *)btlSoundLoadPlaybackFile;
    q = *(u8 **)&((BtlPacket *)p)->workData;
    *(s16 *)&((BtlSoundLoadWork *)q)->bank = (s16)bank;
    *(s16 *)&((BtlSoundLoadWork *)q)->phase = 0;
    return p;
}

/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
/* measured: btlSoundRollStatusCure MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Roll the special status-cure chance and track the first eligible failed cure. */
// FUN_001F6770
s32 btlSoundRollStatusCure(u8 *action)
{
    extern u32 datCalcRandomBelow(s32 limit);
    extern s32 datCalcHasSkill(u8 *unit, s32 skillId);
    u16 chance;
    u8 *status;
    u32 mask;
    u32 one;
    u32 i;

    status = *(u8 **)&((BtlUnit *)*(u8 **)&((BtlAction *)action)->unit)->datUnit;
    if (datCalcChkBadStatus((s32)status, 0x100000) != 0) {
        return 1;
    }
    if (datCalcChkBadStatus((s32)status, 0x1001DF) == 0) {
        return 0;
    }
    chance = 100;
    mask = 0;
    switch (datCalcGetBadStatusNoDown(status)) {
    case 4:
        chance = 70;
        mask = 4;
        break;
    default:
        break;
    }
    chance &= 0xFFFF;
    if (chance == 100) {
        return 1;
    }
    chance = datCalcRandomBelow(100) < chance;
    if (chance == 0 && datCalcHasSkill(status, 0x230) != 0) {
        one = 1;
        i = 0;
        while (i < 0x18U) {
            if ((mask & (one << i)) != 0) {
                if (((BtlSoundStatusTurns *)(action + 0x3F6))->turns[i] > 0) {
                    return 1;
                }
                ((BtlSoundStatusTurns *)(action + 0x3F6))->turns[i] += 1;
                break;
            }
            i++;
        }
    }
    return chance;
}

/* measured: close opt_loop_invariants after btlSoundRollStatusCure. */
/* measured: btlSoundSelectCureableStatuses MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants off
/* Report whether this action can receive the tested status group. */
// FUN_001F68E0
s32 btlSoundCanReceiveStatus(u8 *action)
{
    u8 *unit;
    s32 status;

    unit = *(u8 **)&((BtlAction *)action)->unit;
    status = *(s32 *)&((BtlUnit *)unit)->datUnit;
    if ((((BtlAction *)action)->flags & 4) != 0) {
        return 0;
    }
    return (datCalcChkBadStatus(status, 0x60) != 0);
}

#pragma push
/* measured: btlSoundSelectCureableStatuses MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Build the status-cure mask from per-status probabilities, counters and passive skills. */
// FUN_001F6930
s32 btlSoundSelectCureableStatuses(u8 *action)
{
    BtlUnit *unitState;
    extern s32 datCalcHasSkill(s32 unit, s32 skillId);
    extern s32 func_00244f60(u32 action, u16 *value, u16 *option, u16 extra, s32 flags);
    s32 cureMask;
    u32 statusIndex;
    s32 chance;
    s32 requiredTurns;
    s32 countedStatus;
    u8 *unit;
    s32 statusBit;
    s32 statuses;
    u16 *fearData;
    u16 *panicData;
    u16 *rageData;
    u16 *exhaustionData;
    u16 *silenceData;
    u16 *poisonData;
    s32 hasTurnThreshold;

    unit = *(u8 **)&((BtlAction *)action)->unit;
    unitState = (BtlUnit *)unit;
    /* measured: typing this DatUnit reload changes allocation across the status/skill calls. */
    statuses = datCalcGetBadStatus(*(s32 *)&unitState->datUnit);
    cureMask = 0;
    statusIndex = 0;
    goto loop_31_test;
loop_31_body:
    countedStatus = 1;
    statusBit = 1 << statusIndex;
    if (statuses & statusBit) {
        switch (statusBit) {
        case 0x10:
            fearData = *(u16 **)&((BtlUnit *)unit)->datUnit;
            chance = func_00244f60(8, fearData, fearData, 0xFFFF, 0x10);
            requiredTurns = 3;
            hasTurnThreshold = countedStatus;
            break;
        case 0x4:
            panicData = *(u16 **)&((BtlUnit *)unit)->datUnit;
            chance = func_00244f60(8, panicData, panicData, 0xFFFF, 4);
            requiredTurns = 3;
            hasTurnThreshold = countedStatus;
            break;
        case 0x2:
            rageData = *(u16 **)&((BtlUnit *)unit)->datUnit;
            chance = func_00244f60(8, rageData, rageData, 0xFFFF, 2);
            requiredTurns = 3;
            hasTurnThreshold = countedStatus;
            break;
        case 0x40:
            exhaustionData = *(u16 **)&((BtlUnit *)unit)->datUnit;
            chance = func_00244f60(8, exhaustionData, exhaustionData, 0xFFFF, 0x40);
            requiredTurns = 3;
            hasTurnThreshold = countedStatus;
            break;
        case 0x80:
            silenceData = *(u16 **)&((BtlUnit *)unit)->datUnit;
            chance = func_00244f60(8, silenceData, silenceData, 0xFFFF, 0x80);
            requiredTurns = 6;
            hasTurnThreshold = countedStatus;
            break;
        case 8:
            poisonData = *(u16 **)&((BtlUnit *)unit)->datUnit;
            chance = func_00244f60(8, poisonData, poisonData, 0xFFFF, 8);
            requiredTurns = 6;
            hasTurnThreshold = countedStatus;
            break;
        default:
            chance = 0;
            requiredTurns = 0;
            hasTurnThreshold = 0;
            break;
        }
        if ((hasTurnThreshold == 1) && (requiredTurns != 0)) {
            if (datCalcHasSkill(*(s32 *)&unitState->datUnit, 0x22F) != 0) {
                requiredTurns = requiredTurns >> 1;
                if (requiredTurns <= 0) {
                    requiredTurns = 1;
                }
            }
            if (datCalcHasSkill(*(s32 *)&((BtlUnit *)unit)->datUnit, 0x230) != 0) {
                requiredTurns = 1;
            }
        }
        if (countedStatus == 1) {
            /* measured: typed counter indexing changes the retained address operand order; the other counter handlers are typed. */
            if (MEMBER(u8, action + statusIndex, BtlAction, targetBlock.recovery.statusTurns[0]) <= 1) {
                goto loop_31_increment;
            }
        }
        if ((MEMBER(u8, action + statusIndex, BtlAction, targetBlock.recovery.statusTurns[0]) >= requiredTurns) && (requiredTurns != 0)) {
            cureMask |= statusBit;
        } else if ((s32)datCalcRandomBelow(0x64) < chance) {
            cureMask |= statusBit;
        }
    }
loop_31_increment:
    statusIndex += 1;
loop_31_test:
    if (statusIndex < 0x18U) {
        goto loop_31_body;
    }
    return cureMask;
}

#pragma pop
/* Test whether the first status counter has reached two turns. */
// FUN_001F6BF0
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
/* measured: btlSoundIsStatusCounterHigh MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 btlSoundIsStatusCounterHigh(u8 *action) {
    s32 i;
    s32 one;

    i = 0;
    one = 1;
    while ((u32)i < 0x18) {
        if ((one << i) == one) {
            return ((BtlSoundStatusTurns *)(action + 0x3F6))->turns[i] >= 2;
        }
        i++;
    }
    return 1;
}

/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
/* Clear counters for statuses present in the old mask but absent from the unit. */
// FUN_001F6C40
void btlSoundClearStatusCounters(u8 *action, s32 previousStatuses)
{
    s32 statuses;
    s32 statusBit;
    u32 statusIndex;

    if (previousStatuses != 0) {
        statuses = datCalcGetBadStatus(*(s32 *)&((BtlUnit *)*(u8 **)&((BtlAction *)action)->unit)->datUnit);
        statusIndex = 0;
        goto loop_test_6;
loop_6:
        statusBit = 1 << statusIndex;
        if ((previousStatuses & statusBit) && !(statuses & statusBit)) {
            /* measured: typed counter indexing changes the retained address operand order; the other counter handlers are typed. */
            ((BtlAction *)action)->targetBlock.recovery.statusTurns[statusIndex] = 0;
        }
        statusIndex += 1;
loop_test_6:
        if (statusIndex < 0x18U) {
            goto loop_6;
        }
    }
}

/* Saturating-increment the turn counters of active statuses. */
// FUN_001F6CD0
void btlSoundBumpStatusCounters(u8 *action)
{
    s32 statuses;
    u32 statusIndex;
    u8 turns;
    u8 *statusBase;
    u8 *counter;

    statuses = datCalcGetBadStatus(*(s32 *)&((BtlUnit *)*(u8 **)&((BtlAction *)action)->unit)->datUnit);
    statusIndex = 0;
    goto loop_test_5;
loop_5:
    if ((statuses & (1 << statusIndex)) != 0) {
        statusBase = action + statusIndex;
        counter = statusBase + 0x3F6;
        turns = ((BtlSoundStatusTurns *)(action + 0x3F6))->turns[statusIndex];
        if ((s32)turns < 0xFF) {
            *counter = (u8)(turns + 1);
        }
    }
    statusIndex += 1;
loop_test_5:
    if (statusIndex < 0x18U) {
        goto loop_5;
    }
}

/* Compute the status-driven HP or SP delta, preserving the nonlethal HP limit. */
// FUN_001F6D60
s16 btlSoundCalcStatusHpSpDelta(u8 *action)
{
    u8 *data;
    s16 delta;
    s32 maxSp;
    s32 status;
    s32 maxHp;
    s32 currentSp;
    u16 enemyFlags;

    data = *(u8 **)&((BtlUnit *)*(u8 **)&((BtlAction *)action)->unit)->datUnit;
    delta = 0;
    status = datCalcGetBadStatusNoDown(data);
    switch (status) {
    case 0x20:
        maxHp = datCalcMaxHp(data) & 0xFFFF;
        if ((*(u16 *)data & 4) == 0) {
            delta = -((maxHp & 0xFFFF) * 0x64) / 1000;
        } else {
            enemyFlags = ((BtlSoundEnemyStatusRow *)(iGpffffb3c4 + ((DatUnit *)data)->id * 0x3C))->flags;
            if ((enemyFlags & 0x400) != 0) {
                delta = -0x32;
            } else if ((enemyFlags & 0x800) != 0) {
                delta = -0x64;
            } else {
                delta = -((maxHp & 0xFFFF) * 0x64) / 1000;
            }
            if (delta > 0x3E7) {
                delta = 0x3E7;
            }
            }
        if (datCalcIsDead((s32)(data), delta) != 0) {
            delta = -((datCalcGetHp(data) & 0xFFFF) - 1);
        }
        break;
    case 0x40:
        maxSp = datCalcMaxSp(data) & 0xFFFF;
        currentSp = datCalcGetSp(data) & 0xFFFF;
        delta = -((maxSp & 0xFFFF) * 0x64) / 1000;
        if (currentSp < delta) {
            delta = currentSp;
        }
        break;
    default:
        break;
    }
    return delta;
}

/* measured: opt_rebuildconditionals off probe for btlSoundPickStatusTalkVoiceA final branch. */
/* measured: btlSoundPickStatusTalkVoiceA MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* Choose a status/action-specific voice and adjust its pair for non-player units. */
// FUN_001F6F60
s32 btlSoundPickStatusTalkVoiceA(u8 *action)
{
    u8 *unit;
    s32 voice;
    s32 adjustedVoice;
    s32 status;
    u16 actionKind;
    u16 alternateActionKind;

    if ((((BtlAction *)action)->unk_1a & 1) == 0) {
        return -1;
    }
    unit = *(u8 **)&((BtlAction *)action)->unit;
    voice = -1;
    status = datCalcGetBadStatusNoDown(*(u8 **)&((BtlUnit *)unit)->datUnit);
    switch (status) {
    case 2:
        if ((((BtlAction *)action)->unk_28 == 0) &&
            (((BtlAction *)action)->unk_29 == 0)) {
            voice = 0xC;
        }
        break;
    case 4:
        actionKind = ((BtlAction *)action)->unk_6c;
        switch (actionKind) {
        case 6:
        case 12:
            voice = 8;
            break;
        case 7:
        case 8:
        case 11:
            voice = 0xA;
            break;
        default:
            break;
        }
        break;
    case 8:
        break;
    case 0x10:
        switch (((BtlAction *)action)->unk_6c) {
        case 1:
            voice = 4;
            break;
        default:
            voice = 6;
            break;
        }
        break;
    case 0x100:
        alternateActionKind = ((BtlAction *)action)->unk_6c;
        switch (alternateActionKind) {
        case 2:
        case 1:
            voice = 0xAA;
            break;
        case 7:
        case 8:
        case 11:
            voice = 0xAB;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    if (voice < 0) {
        return -1;
    }
    {
        if (((BtlUnit *)unit)->genus != 0)
            goto increment_6f60;
        adjustedVoice = voice;
        goto done_6f60;
    increment_6f60:
        adjustedVoice = voice + 1;
    done_6f60:
        ;
    }
    voice = adjustedVoice;
    return voice;
}

/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceA probe. */
/* measured: opt_rebuildconditionals off preserves btlSoundPickStatusTalkVoiceB's positive flag branch. */
/* Choose the alternate status voice, returning minus one when no voice applies. */
// FUN_001F7140
s32 btlSoundPickStatusTalkVoiceB(u8 *action)
{
    u8 *unit;
    s32 voice;
    s32 adjustedVoice;
    s32 status;

    if ((((BtlAction *)action)->unk_1a & 1) == 0) {
        return -1;
    }
    unit = *(u8 **)&((BtlAction *)action)->unit;
    voice = -1;
    status = datCalcGetBadStatusNoDown(*(u8 **)&((BtlUnit *)unit)->datUnit);
    switch (status) {
    case 2:
        voice = 0x2E;
        break;
    case 4:
        voice = 0x2C;
        break;
    case 8:
        voice = 0x34;
        break;
    case 0x10:
        voice = 0x2A;
        break;
    case 0x40:
        voice = 0x30;
        break;
    case 0x80:
        voice = 0x32;
        break;
    default:
        break;
    }
    if (voice < 0) {
        return -1;
    }
    {
        if (((BtlUnit *)unit)->genus != 0)
            goto increment_7140;
        adjustedVoice = voice;
        goto done_7140;
    increment_7140:
        adjustedVoice = voice + 1;
    done_7140:
        ;
    }
    voice = adjustedVoice;
    return voice;
}

/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceB. */
/* Initialize all sixteen cue-cache rows and the rotating channel sentinel. */
// FUN_001F7260
void btlSoundResetSlotQueue(void)
{
    s32 offset;
    s32 empty;
    u16 i;
    u8 state;

    *(s16 *)&((BtlSoundQueue *)(iGpffffb3ac + 0xAC8))->channel = 5;
    empty = -1;
    ((BtlSoundQueue *)(iGpffffb3ac + 0xAC8))->frame = empty;
    i = 0;
    state = 3;
    for (; i < 0x10; i++) {
        offset = (u32)i * 6;
        ((BtlSoundQueue *)(iGpffffb3ac + offset + 0xAC8))->channels[0].cue = empty;
        ((BtlSoundQueue *)(iGpffffb3ac + offset + 0xAC8))->channels[0].variant = empty;
        ((BtlSoundQueue *)(iGpffffb3ac + offset + 0xAC8))->channels[0].frame = state;
    }
}

// measured: required for exact retail loop codegen in btlSoundResetSlotQueue.
/* measured: optimization_level 1 required for exact btlSoundAdvanceSlotQueue codegen. */
/* measured: btlSoundAdvanceSlotQueue MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* measured: opt_loop_invariants off baseline for btlSoundAdvanceSlotQueue. */
/* Age the rotating queue and expire cached channel selectors after three ticks. */
// FUN_001F72E0
void btlSoundAdvanceSlotQueue(void)
{
    s32 slotIndex;
    u8 *battle;
    u8 *slotBase;
    s32 slotOffset;
    s32 frameAddress;
    s32 empty;
    s32 slotFrame;

    {
        u8 *queueBase;
        u8 *queueFrame;
        s32 elapsed;

        queueBase = iGpffffb3ac;
        queueFrame = queueBase + 0xACA;
        elapsed = *(s8 *)queueFrame;
        if (elapsed >= 0) {
            elapsed = elapsed + 1;
            *(s8 *)queueFrame = (s8)elapsed;
            if ((s8)elapsed >= 3) {
                ((BtlSoundQueue *)(iGpffffb3ac + 0xAC8))->frame = -1;
            }
        }
    }
    slotIndex = 0;
    empty = -1;
    goto loop_test_8;
loop_8:
    battle = iGpffffb3ac;
    frameAddress = slotIndex & 0xFFFF;
    slotOffset = frameAddress * 6;
    slotBase = battle + slotOffset;
    frameAddress = (s32)(slotBase + 0xAD0);
    slotFrame = ((BtlSoundQueue *)(slotBase + 0xAC8))->channels[0].frame;
    if (slotFrame >= 0) {
        slotFrame = slotFrame + 1;
        *(s8 *)frameAddress = (s8)slotFrame;
        if ((s8)slotFrame >= 3) {
            ((BtlSoundQueue *)(iGpffffb3ac + slotOffset + 0xAC8))->channels[0].cue = empty;
            ((BtlSoundQueue *)(iGpffffb3ac + slotOffset + 0xAC8))->channels[0].variant = empty;
            ((BtlSoundQueue *)(iGpffffb3ac + slotOffset + 0xAC8))->channels[0].frame = empty;
        }
    }
    slotIndex = (slotIndex + 1) & 0xFFFF;
loop_test_8:
    if ((slotIndex & 0xFFFF) < 0x10) {
        goto loop_8;
    }
}

/* measured: restore optimization_level 2 after btlSoundAdvanceSlotQueue. */
/* measured: btlSoundPlayRetailSelectTrack MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* Reserved sound teardown hook called while releasing the battle runtime. */
// FUN_001F73C0
void btlSoundReleaseNoop(void)
{
}

/* Retail selectors 4/5/6 request tracks 5/6/4. Preserve block order:
 * the eleven resolved jump-table entries at 0x00747550 must also match. */
// FUN_001F73D0
void btlSoundPlayRetailSelectTrack(void)
{
    u16 selector;
    u8 *battle;

    battle = iGpffffb3ac;
    if (*(s32 *)&((BtlBattleState *)battle)->flags & 0x40) {
        /* measured: typed counter indexing changes the retained address operand order; the other counter handlers are typed. */
        selector = ((BtlSoundEncounterRecord *)*(u8 **)&((BtlBattleState *)battle)->encounterRecord)->trackRule;
        selector = ((BtlSoundTrackRule *)iGpffffb414)[selector].selector;
        switch (selector) {
        case 2:
            sdkSndPlayCue(2, 1);
            break;
        case 3:
            sdkSndPlayCue(3, 1);
            break;
        case 6:
            sdkSndPlayCue(4, 1);
            break;
        case 4:
            sdkSndPlayCue(5, 1);
            break;
        case 5:
            sdkSndPlayCue(6, 1);
            break;
        case 7:
            sdkSndPlayCue(0x29, 1);
            break;
        case 8:
            sdkSndPlayCue(0x30, 1);
            break;
        case 9:
            sdkSndPlayCue(0x2F, 1);
            break;
        case 10:
            sdkSndPlayCue(0x2D, 1);
            break;
        default:
            sdkSndPlayCue(1, 1);
            break;
        }
    }
}
