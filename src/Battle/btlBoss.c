#include "member_access.h"
/* Measured alias-sensitive fields use MEMBER; typed access-site, local-pointer
 * and applicable array forms are recorded in FullBattle2.culprits.tsv. */
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "btl_unit_internal.h"
#include "datCalc_internal.h"
/* Source unit: src/Battle/btlBoss_0022fb90.c */
#include "btl_skill_target_internal.h"
#include "type.h"
#include "btl_unit_internal.h"
#include "include_asm.h"

/* UNIT_GENUS_EC = 1 (include/Main/Battle/Data/datUnit.h in P3). */
enum { UNIT_GENUS_EC = 1 };

extern u8* DAT_0076449c;


BtlPacket* btlPacketAlloc(u32 packetType, u32 workSize);
u32 btlBossLoadPakInit(void* work);
u32 btlBossLoadPakUpdate(void* work);
extern s32 btlActionHasNoTargetClass();
extern s32 btlActionSkillReachesTargets();
extern s32 btlCurrentUnitId();
extern s32 btlActionGetQueueFront();
extern void btlActionQueueMoveToBack(s32);
extern void btlActionQueueSortKeepingKind(s32);
extern void memset(void *, s32, s32);
extern u8 *iGpffffb414;
void btlFormationAllocEncounterSlots(void);
void func_00440b68();
void sprintf();
extern u8* H_Cdvd_AcquireDirectory(u8* path, s32 flags);
s32 H_Cdvd_IsFileLoaded(u8* cdvd);
extern char iGpffffa5e8;
extern char D_00635620[];
extern char D_00635638[];
extern char D_00635650[];
extern char D_00635668[];



/* Full-word zero/one predicate, shared with formation placement.
 * Both provider and caller retain their original native code. */
// FUN_0022FB90
s32 btlBossUnitsSameGenus(BtlUnit* first, BtlUnit* second)
{
    if ((((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
    {
        return 0;
    }
    if (first->genus == UNIT_GENUS_EC)
    {
        return 0;
    }
    if (first == second)
    {
        return 0;
    }
    return first->genus == second->genus;
}



/* Reject a distinct same-side target only for a non-enemy actor outside status 0x100; return one when unrestricted. */
// FUN_0022FC00
s32 btlBossTargetBlocked(u8* action)
{
    u8 genus;
    BtlUnit* targetUnit;
    DatUnit* unitData;
    BtlUnit* unit;

    if ((*(s32 *)&((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
    {
        return 1;
    }
    if (btlActionHasNoTargetClass() == 0)
    {
        return 1;
    }
    unit = ((BtlAction *)action)->unit;
    targetUnit = ((BtlAction *)*(u8 * *)&((BtlAction *)action)->unk_38[0])->unit;
    genus = unit->genus;
    if (genus == 1)
    {
        return 1;
    }
    if (unit == targetUnit)
    {
        return 1;
    }
    if (genus != targetUnit->genus)
    {
        return 1;
    }
    unitData = unit->datUnit;
    if ((unitData != NULL) && (datCalcChkBadStatus(unitData, 0x100) != 0))
    {
        return 1;
    }
    return 0;
}
/* Return zero only for two enemy units during a boss encounter; all other pairs are accepted. */
// FUN_0022FCE0
u32 btlBossFlagPairOk(s32 first, s32 second)
{
    u8 value;

    if ((((BtlBattleState *)DAT_0076449c)->flags & 0x200000) != 0)
    {
        value = ((BtlUnit *)first)->genus;
        if (value == 1 && value == ((BtlUnit *)second)->genus)
        {
            return 0;
        }
    }

    return 1;
}





/* Report unrestricted actions outside enabled boss enemy actions; otherwise invert the skill target-reach predicate. */
// FUN_0022FD30
s32 btlBossActionBlocked(u8* action)
{
    if ((*(s32 *)&((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
    {
        return 1;
    }
    if ((((BtlAction *)action)->unk_1a & 1) == 0)
    {
        return 1;
    }
    if (((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->genus != 1)
    {
        return 1;
    }
    return !((u32)btlActionSkillReachesTargets());
}
// FUN_0022FDC0
/* Rebuild the boss action queue with flag-dependent weights, optionally rotating a living preferred action to the front. */
void btlBossCollectTargets(u8 *preferredAction)
{
    /* Typed action/unit/packet fields changed MWCC codegen (436B trial); retain the proven byte offsets for MATCH. */
    s32 *encounterFlags;
    s32 frontAction;
    s32 battleFlags;
    u16 actionFlags;
    u8 **queueSlot;
    u8 *battle;
    u8 *previousAction;
    u8 *action;

    battleFlags = *(s32 *)&((BtlBattleState *)(DAT_0076449c))->flags;
    if ((battleFlags & 0x200000) != 0)
    {
        encounterFlags = (s32 *)(iGpffffb414 +
                          (btlCurrentUnitId(battleFlags) * 0x18));
        memset(DAT_0076449c + 0x29C, 0, 0x30);
        battle = DAT_0076449c;
        queueSlot = (u8 **)(battle + 0x29C);
        action = *(u8 * *)&((BtlBattleState *)(battle))->actions;
loop_2:
        previousAction = *(u8 * *)&((BtlAction *)(action))->next;
        if (previousAction != NULL)
        {
            action = previousAction;
            goto loop_2;
        }
loop_4:
        if (((*(u16 *)&((BtlAction *)(action))->unk_1a & 1) != 0) ^ 1)
            goto loop_4_next;
        if (datCalcIsDead((*(BtlUnit * *)&((BtlAction *)(action))->unit)->datUnit, 0) != 0)
            goto loop_4_next;
        {
            *queueSlot = action;
            queueSlot += 1;
            actionFlags = MEMBER(u16, action, BtlAction, unk_1a);
            if ((actionFlags & 0x2000) != 0)
            {
                queueSlot[0] = action;
                queueSlot[1] = action;
                queueSlot[2] = action;
                queueSlot[3] = action;
                queueSlot += 4;
            }
            else if ((actionFlags & 0x100) != 0)
            {
                queueSlot[0] = action;
                queueSlot += 1;
            }
        }
loop_4_next:
        action = *(u8 * *)&((BtlAction *)(action))->previous;
        switch ((u32)action)
        {
        case 0:
            goto loop_4_done;
        default:
            goto loop_4;
        }
loop_4_done:
        if ((*encounterFlags & 0x10) != 0)
            btlActionQueueSortKeepingKind(1);
        if ((preferredAction != NULL) &&
            (datCalcIsDead((*(BtlUnit * *)&((BtlAction *)(preferredAction))->unit)->datUnit, 0) == 0))
        {
loop_16:
            frontAction = btlActionGetQueueFront();
            if ((frontAction != 0) && ((u8 *)frontAction != preferredAction))
            {
                btlActionQueueMoveToBack(frontAction);
                goto loop_16;
            }
        }
    }
}
/* measured: optimization_level 1 preserves retail's lhu/move halfword
   argument materialization; object 168B, retail window 176B. */
#pragma optimization_level 1
// FUN_0022FF70
/* Classify a non-enemy action in boss mode and accept only target classes one and two. */
s32 btlBossSkillResultBlocked(u8 *action)
{
    s32 skillId;
    s32 targetClass;
    s32 result;

    if ((*(s32 *)&((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
    {
        result = 0;
        goto done;
    }
    if (((BtlUnit *)*(u8 * *)&((BtlAction *)action)->unit)->genus == 1)
    {
        result = 0;
        goto done;
    }
    skillId = ((BtlAction *)action)->unk_6e;
    targetClass = (s32)(btlSkillClassifyTargets(action, NULL, skillId, 0) & 0xFFFF);
    switch (targetClass)
    {
    case 1:
    case 2:
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
done:
    return result;
}
#pragma optimization_level 2
/* measured: literal-return switch reproduces the retail branch after the zero assignment. */
// FUN_00230020
/* Exclude the listed skill IDs for enemy actions in boss mode. */
s32 btlBossSkillAllowed(u8 *action)
{
    u16 skillId;

    if ((*(s32 *)&((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
        return 1;
    if (((BtlUnit *)*(u8 * *)&((BtlAction *)action)->unit)->genus == 1)
    {
        skillId = ((BtlAction *)action)->unk_6e;
        switch (skillId)
        {
        case 0x172:
        case 0x173:
        case 0x174:
        case 0x175:
        case 0x176:
        case 0x177:
        case 0x160:
        case 0x17A:
        case 0x186:
        case 0x18B:
            return 0;
        default:
            return 1;
        }
    }
    return 1;
}
// FUN_002300F0
/* Replace enemy unit 0x111 with genus two and unit 0x110 while boss mode is active. */
u32 btlBossRemapSkillPair(u8 *unit, u16 *genus, u16 *unitId)
{
    if ((((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
        return 0;
    if (unit[0xa2] != 1)
        return 0;
    if (((BtlUnit *)unit)->charId != 0x111)
        return 0;
    *genus = unit[0xa2] + 1;
    *unitId = 0x110;
    return 1;
}
/* measured probe: opt_loop_invariants on for btlBossCopyPartnerMark */
#pragma opt_loop_invariants on
// FUN_00230170
/* For unit 0x106, inherit the marked flag and color byte from partner unit 0x10F. */
void btlBossCopyPartnerMark(u8 *unit)
{
    u8 *battle;
    u8 *partner;
    u16 target = 0x10f;

    battle = DAT_0076449c;
    if ((*(s32 *)&((BtlBattleState *)battle)->flags & 0x200000) &&
        (((BtlUnit *)unit)->charId == 0x106) &&
        ((*(s32 *)&((BtlUnit *)unit)->flags3 & 8) == 0))
    {
        partner = ((BtlBattleState *)battle)->unitLists[2];
        goto loop_cond;
loop_body:
        if (((BtlUnit *)partner)->charId == target)
            goto loop_done;
        partner = *(u8 * *)&((BtlUnit *)partner)->nextUnit;
loop_cond:
        if (partner != NULL)
            goto loop_body;
loop_done:
        if ((partner != NULL) && ((((BtlUnit *)partner)->flags & 2) != 0))
        {
            ((BtlUnit *)unit)->flags = ((BtlUnit *)unit)->flags | 2;
            ((BtlUnit *)unit)->cols[1].alpha = ((BtlUnit *)partner)->cols[1].alpha;
        }
    }
}

#pragma opt_loop_invariants off
/* Select encounters that use the special boss-opening action path; unlisted encounter IDs return zero. */
// FUN_00230210
s32 btlBossIsAllowedAction(void)
{
    s32 encounterId;

    if ((*(s32 *)&((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
        return 0;
    encounterId = btlCurrentUnitId();
    switch (encounterId)
    {
    case 0x200:
        return 1;
    case 0x201:
        return 1;
    case 0x202:
        return 1;
    case 0x203:
        return 1;
    case 0x204:
        return 1;
    case 0x205:
        return 1;
    case 0x206:
        return 0;
    case 0x207:
        return 1;
    case 0x208:
        return 1;
    case 0x209:
        return 1;
    case 0x20a:
        return 1;
    case 0x20b:
    case 0x215:
        return 1;
    case 0x20c:
        return 0;
    case 0x20d:
        return 1;
    case 0x214:
        return 0;
    default:
        return 0;
    }
}
/* Clear the pending formation cue for the enumerated boss unit IDs; leave other units and ordinary encounters unchanged. */
// FUN_00230340
void btlBossResetPendingCue(u8 *action)
{
    u8 *unit;
    u8 *battle;
    u16 unitId;

    battle = DAT_0076449c;
    if ((*(s32 *)&((BtlBattleState *)battle)->flags & 0x200000) != 0)
    {
        unit = *(u8 * *)&((BtlAction *)action)->unit;
        if (((BtlUnit *)unit)->genus == 1)
        {
            unitId = ((BtlUnit *)unit)->charId;
            switch (unitId)
            {
            case 0x102:
            case 0x104:
            case 0x105:
            case 0x106:
            case 0x107:
            case 0x10b:
            case 0x112:
                ((BtlBattleState *)battle)->pendingBossCue = -1;
                break;
            default:
                break;
            }
        }
    }
}
/* Format the current encounter resource path and acquire its directory into the battle boss-resource handle. */
// FUN_002303E0
u32 btlBossLoadPakInit(void* work)
{
    u8 buf[0x80];

    sprintf(buf, D_00635620, btlCurrentUnitId());
    func_00440b68(&iGpffffa5e8, D_00635638, 0x997);
    ((BtlBattleState *)DAT_0076449c)->bossPakHandle = (u32)H_Cdvd_AcquireDirectory(buf, 1);
}



/* Wait for the boss resource directory, then allocate encounter slots; a missing handle completes immediately. */
// FUN_00230450
u32 btlBossLoadPakUpdate(void* work)
{
    u32 handle;

    handle = ((BtlBattleState *)DAT_0076449c)->bossPakHandle;
    if (handle == 0)
    {
        return 1;
    }
    if (H_Cdvd_IsFileLoaded((u8*)handle) != 0)
    {
        btlFormationAllocEncounterSlots();
        return 1;
    }
    return 0;
}

/* Create the boss-resource loading packet with asynchronous initialization and completion callbacks, clearing flag bit zero. */
// FUN_002304B0
BtlPacket* btlBossCreateLoadPakPacket(void)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0xe00, 0);
    packet->flags &= ~(1 << 0);
    packet->initFunc = btlBossLoadPakInit;
    packet->updateFunc = btlBossLoadPakUpdate;

    return packet;
}



typedef struct BtlBossEndBgmWork {
    u32 encountId; // 0x00
    u32 loaded;    // 0x04
} BtlBossEndBgmWork;

/* Acquire the encounter end-BGM directory on the first step, then report completion after its load finishes. */
// FUN_00230500
u32 btlBossLoadEndBgmStep(BtlBossEndBgmWork* work)
{
    u8 buf[0x80];

    if (work->loaded == 0)
    {
        sprintf(buf, D_00635650, D_00635668, work->encountId);
        func_00440b68(&iGpffffa5e8, D_00635638, 0x9C6);
        ((BtlBattleState *)DAT_0076449c)->bossEndBgmHandle = (u32)H_Cdvd_AcquireDirectory(buf, 0);
        work->loaded = 1;
        goto done;
    }
    if (H_Cdvd_IsFileLoaded((u8*)((BtlBattleState *)DAT_0076449c)->bossEndBgmHandle) != 0)
    {
        return 1;
    }
done:
    return 0;
}
