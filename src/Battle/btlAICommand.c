#include "member_access.h"
#include "scr_context_internal.h"
#include "btl_skill_target_internal.h"
#include "datCalc_unit_internal.h"
#include "datUnit_internal.h"
#include "type.h"
#include "include_asm.h"
#include "btl_cond_internal.h"
#include "btl_action_internal.h"
#include "btl_ai_internal.h"
#include "btl_effect_internal.h"
#include "kwln_task_internal.h"
#include "dat_skill_entry_internal.h"

/* Unit setting: retain explicit conditional branches throughout the AI command queries. */
#pragma opt_rebuildconditionals off

/* AI condition words pack an opcode in the high byte and a 24-bit argument.
 * Script handlers send the predicate value through scrSetReturnInt and retain
 * their original scheduler return status, including the query handlers returning -1. */

typedef s32 (*code)();


typedef struct DatUnit DatUnit;
extern u16 datCalcMaxHp(DatUnit *unit);


s32 btlAICommandNomalCheck(u8 *formation, s32 index, s32 enabled);

extern u64 datGetCollectionEntryBits();

extern s32 datCalcGetAffinity(u8 *unit, s32 elementIndex);

typedef void (*FormationCallback)(void);

extern s32 btlAICommandSelectCandidates();

extern u64 kwlnTaskIsLinked();

extern u8 *btlActionFindById();
extern s32 btlAICommandCollectCommandsOfType(u8 *action, u8 *target, s16 element, s32 costPreference);
extern u32 scrGetParamInt();
extern void scrSetReturnInt();
extern u8 *scrGetAiState();

extern s32 btlSideSelectUnits();
extern s32 datCalcSkillAmount(s32 skill, u8 *source, u8 *target, s32 count, s32 hit, s32 relation, s32 options, s32 channel);
extern void datCalcClearField18(u32 object);
extern s32 btlEffectSelectNearestEntry(u32 action, u8 *targets);
extern u32 btlFormationCurrentEntry(u8 *formation);
extern s32 datCalcSkillElement(u8 *unit, u16 skillId);
extern s32 datCalcElementBit(s16 element);
extern s8 datCalcGetBuffStatus(u8 *unit, s32 buffIndex);
extern u32 datCalcUnderlyingSkillId(s64 personaSkillId);
extern u32 *btlEffectFindUnitByIdAndStatus();
extern u32 datTestBitmapBit(u32 entryIndex, u32 bitIndex);
extern void btlFormationEntryCopySelected(u8 *destination, u8 *source);
extern u8 *D_0072449C;
extern void *D_00609850[];
extern u32 D_00609600[];
extern u32 btlActionGetQueueEntry(u16 index);
extern u32 datCalcClearBuffLevel(u32 unit, u32 buffIndex);
extern u32 datCalcRandomBelow(u32 limit);
extern u16 datCalcGetHp(s32 unit);
extern s32 datCalcGetElementAffinity(u8 *unit, s32 elementIndex);
extern void btlAICommandSetActionCode(u8 *action, u8 *work, u16 actionCode);

extern void *D_00609934[];
extern void *D_00609940[];
extern void *D_0060994C[];
extern void *D_00609A30[];
extern void *D_00609A3C[];
extern void *D_00609A48[];
extern void *D_00609A6C[];
extern void *D_00609A78[];
extern void *D_00609B74[];
extern void *D_00609B80[];
extern void *D_00609B8C[];
extern void *D_00609CE0[];
extern void *D_00609CE8[];
extern void *D_00609CF0[];
extern void *D_00609CF8[];
extern void *D_00609D18[];
extern void *D_00609D20[];
extern void *D_00609D70[];
extern void *D_00609D78[];
extern void *D_00609D80[];
extern void *D_00609DF0[];
extern void *D_00609E18[];
extern void btlEffectCollectTargetUnits(u8 *action, u8 *selection, u16 sideFlags, s32 filterFlags, u8 *statusMask);
extern s32 btlAICommandCollectSkillCandidates(u8 *action, u8 *target, s32 costPreference, s32 effectFilter);
extern s32 btlAICommandPickAiTarget(u8 *action, u32 value);
extern char D_006095E0[];
extern void kAssertFail(void *file, s32 line);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern s32 datCalcHasSkill(u8 *unit, s32 skillId);
extern s32 datCalcThresholdTrigger(u8 *unit, s32 skillId);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern void btlAiChooseUsableAttackSkill(u8 *action, u8 *command);
extern s32 datCalcDefaultSkillId(u8 *unit);
extern s32 datCalcPickSpecialItem(u8 *unit);
extern u32 datCalcGetLevel(u32 unit);
extern s32 datCalcIsDead(u32 unit, u32 hpDelta);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb42c;
extern u8 *iGpffffb3cc;
extern u8 iGpffffa2a8;
extern u8 *iGpffffb444;
extern void sprintf(u8 *a, u8 *b, u32 c, u8 d);
extern s32 scrFindPrcdIdxByName(u32 header, u8 *name);
extern s32 scrStartProcedureIndex(u8 *priority, u32 header, s32 procedureIndex);
extern void scrSetTaskProc(u32 task, u8 *proc);
extern u8 *kwlnTaskGetWork(u32 task);
extern s32 datPersonaNamePart1Alt(s32 unitId);
extern void itfMesWindowSetString(s32 handle, s32 slotIndex, u32 text);
extern void kwlnTaskAddChild(u8 *parent, u32 child);
extern u8 D_00609E20[];
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;
extern void btlTargetResetCommandRecord(u8 *record);

/* Check the actor's status and skill ownership before accepting an AI command. measured: a separate
 * unit alias keeps the retail reloads; typing datUnit at each access site changes four callers. */
static inline s32 btlCommandUsable(u8 *subject, u32 command) {
    BtlUnit *unit;
    s32 commandId;

    commandId = command & 0xFFFF;
    if (commandId >= 0x240) {
        kAssertFail(D_006095E0, 0x45F);
    }
    subject = (u8 *)((BtlAction *)subject)->unit;
    unit = (BtlUnit *)subject;
    if (commandId < 0x1B8) {
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)subject)->datUnit, 0x80008) != 0)
            return 0;
        if (datCalcHasSkill((u8 *)unit->datUnit, commandId) == 0)
            return 0;
        if (datCalcThresholdTrigger((u8 *)unit->datUnit, commandId) == 0)
            goto ret1;
        return 0;
    }
    if (datCalcHasSkill((u8 *)((BtlUnit *)subject)->datUnit, commandId) != 0)
        goto ret1;
    return 0;
ret1:
    return 1;
}

/* The shared helper preserves the command test used by inlined queries. */
// FUN_001DAF40
s32 btlCond_MYABLESKIL(u8 *action, u32 command) {
    return btlCommandUsable(action, command);
}

/* Evaluate weakness on the opposite genus, excluding defeated units. */
// FUN_001DB040
s32 btlCond_ENWEAK_PAI(u8 *action, u32 value) {
    u32 shift;
    {
        if ((((BtlAction *)action))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    return btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 6, (code *)&btlCond_MYWEAK);
}

/* Evaluate weakness on the opposite genus, excluding defeated and down units. */
// FUN_001DB0A0
s32 btlCond_ENWEAK_ST_PAI(u8 *action, u32 value) {
    u32 shift;
    {
        if ((((BtlAction *)action))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    return btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 6, (code *)&btlCond_MYWEAK);
}

/* Evaluate the alternate weakness predicate on the opposite genus. */
// FUN_001DB100
s32 btlCond_ENWEAK_DW_PAI(s32 action, u32 value)
{
  u32 shift;

  {
      if ((((BtlAction *)action))->unit->genus != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  return btlEffectFindUnitMatchingCallback(action, value, 1 << (shift & 0xffff) & 0xffff, 0x80000, 7,
                 (code *)&btlCond_MYWEAK);
}


/* Test whether the unit has a usable skill with the requested element; the entry is reloaded after
 * the value query. */
// FUN_001DB160
s32 btlCond_MYATTRSKIL(u8 *action, s32 value)
{
    u8 *unit;
    u16 count;
    u16 *commands;
    u16 index;
    s32 limit;
    u16 *entry;
    s16 queried;

    unit = MEMBER(u8 *, action, BtlAction, unit);
    queried = datCalcSkillElement((u8 *)((BtlUnit *)unit)->datUnit, 0);
    if (queried != value)
        goto scan;
    return 1;
scan:
    count = datCalcGetTableLength(MEMBER(DatUnit *, unit, BtlUnit, datUnit));
    commands = (u16 *)datCalcSkillList(MEMBER(DatUnit *, unit, BtlUnit, datUnit));
    index = 0;
    limit = count;
    while (index < limit) {
        entry = &commands[index];
        if (*entry != 0 && *entry < 0x1B8) {
            queried = datCalcSkillElement(MEMBER(u8 *, unit, BtlUnit, datUnit), *entry);
            if (queried != value)
                goto next;
            if (btlCommandUsable(action, *entry))
                return 1;
        }
next:
        ++index;
    }
    return 0;
}

/* Status result is signed and the status gate requires enabled to be exactly set. */
#pragma push
#pragma opt_loop_invariants on
/* measured: retail does not propagate the bitmap loads in this function. */
#pragma opt_propagation off
/* Reject blocked elements, status-gated attacks, and unusable physical commands. */
// FUN_001DB360
s32 btlAICommandNomalCheck(u8 *formation, s32 index, s32 enabled)
{
    u8 *unit;
    s32 flags;
    u16 count;
    u16 *commands;
    u16 i;
    s32 limit;
    u16 command;
    BtlUnit *statusUnit;

    unit = (u8 *)((BtlAction *)formation)->unit;
    statusUnit = (BtlUnit *)unit;
    if (((BtlUnit *)unit)->genus == 1 &&
        btlTargetAffinityKnowledgeBypassNoop(formation, (s16)index) == 0) {
        u32 queryIndex = (u16)index;
        if (datTestBitmapBit(((BtlUnit *)unit)->charId, queryIndex) == 0)
            return 1;
    }

    flags = datCalcElementBit((s16)index);
    if (enabled == 1 && !(flags & 0xE0001)) {
        if (flags & 2) {
            if (datCalcGetBuffStatus((u8 *)((BtlUnit *)unit)->datUnit, 0x10) > 0)
                return 0;
        } else if (!(flags & 0x40) &&
                   datCalcGetBuffStatus((u8 *)((BtlUnit *)unit)->datUnit, 0x11) > 0) {
            return 0;
        }
    }

    if (flags & 2) {
        if (statusUnit->genus == 1) {
            if (((BtlUnit *)unit)->datUnit->flags & 0x100)
                return 0;
        } else {
            count = datCalcGetTableLength(((BtlUnit *)unit)->datUnit);
            commands = (u16 *)datCalcSkillList(statusUnit->datUnit);
            i = 0;
            limit = count;
            while (i < limit) {
                command = commands[i];
                switch (command) {
                case 0x1F6:
                case 0x1F7:
                case 0x1F8:
                    return 0;
                }
                i++;
            }
        }
    }
    return !(datCalcGetElementAffinity((u8 *)((BtlUnit *)unit)->datUnit, (s16)index) & 0x07000000);
}
#pragma pop
// FUN_001DB580
s32 btlCond_MYNOMAL(u8 *formation, s32 index)
{
    return btlAICommandNomalCheck(formation, index, 1);
}


// FUN_001DB5B0
s32 btlAICommandNomalCheckNoGate(u8 *formation, s32 index)
{
    return btlAICommandNomalCheck(formation, index, 0);
}


// FUN_001DB5E0
s32 btlAICommandNomalStatusCheck(u8 *action, s64 value) {
    return !(datCalcGetElementAffinity((u8 *)(((BtlAction *)action))->unit->datUnit, (s32)(s16)value) & 0x7000000);
}

/* Evaluate normal-affinity targets on the opposite genus. */
// FUN_001DB620
s32 btlCond_ENNOMAL(u8 *action, u32 value) {
    u32 shift;
    {
        if ((((BtlAction *)action))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    return btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0xA, (code *)&btlCond_MYNOMAL);
}

/* Evaluate normal-affinity targets, excluding defeated and down units. */
// FUN_001DB680
s32 btlCond_ENNOMAL_ST(u8 *action, u32 value) {
    u32 shift;
    {
        if ((((BtlAction *)action))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    return btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0xA, (code *)&btlCond_MYNOMAL);
}

/* Evaluate the alternate normal-affinity predicate on the opposite genus. */
// FUN_001DB6E0
s32 btlCond_ENNOMAL_DW(s32 action, u32 value)
{
  u32 shift;

  {
      if ((((BtlAction *)action))->unit->genus != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  return btlEffectFindUnitMatchingCallback(action, value, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0xb,
                 (code *)&btlCond_MYNOMAL);
}


/* Test the analysis flag for enemy-genus units; other genera return false. */
// FUN_001DB740
u8 btlCond_ANALYZE(s32 action)
{
  long analysisFlag = 0;
  if ((((BtlAction *)action))->unit->genus != 1) {
    return 0;
  }
  analysisFlag = datGetCollectionEntryBits((((BtlAction *)action))->unit->charId);
  return analysisFlag != 0;
}


// FUN_001DB790
s32 btlCond_DOWN(u8 *action) {
    return !(((BtlAction *)action)->unit->datUnit->flags & DAT_UNIT_FLAG_DOWN);
}


// FUN_001DB7B0
s32 btlCond_SLIP(u8 *action) {
    return !(((BtlAction *)action)->unit->datUnit->flags & 0x10);
}


/* Matches P3FES func_002c3300. Finds an active opposite-genus action whose level exceeds the
 * caller's by the requested amount. */
// FUN_001DB7D0
u32 btlCond_ENOVERLV(s32 action, u32 value)
{
    u32 genusValue;

    if ((((BtlAction *)action))->unit->genus != 0) {
        goto nonzero_genus;
    }
    genusValue = 1;
    goto genus_done;
nonzero_genus:
    genusValue = 0;
genus_done:
    {
        u32 genus = (u16)genusValue;
        u32 current = (u8)datCalcGetLevel((u32)((BtlUnit *)(((BtlAction *)action)->unit))->datUnit);
        s32 unit = (s32)((BtlBattleState *)iGpffffb3ac)->actions;
        u32 candidate;
        u32 comparison;

        genus = (u16)genus;
        while (unit != 0) {
            if (((((BtlAction *)unit)->unk_1a & 1) != 0) &&
                ((((BtlAction *)unit)->unk_1a & 8) != 0) &&
                ((((BtlAction *)unit))->unit->genus == genus)) {
                candidate = (u8)datCalcGetLevel((u32)((BtlUnit *)(((BtlAction *)unit)->unit))->datUnit);
                comparison = candidate < current;
                if (comparison != 0) {
                    goto next_unit;
                }
                comparison = (candidate - current) < value;
                if (comparison != 0) {
                    goto next_unit;
                }
                return 1;
            }
next_unit:
            unit = (s32)((BtlAction *)unit)->next;
        }
    }
    return 0;
}


// FUN_001DB8D0
s32 btlCond_MYHOJO(u8 *action, s32 value) {
    return (s32)(datCalcHasBuffMask((((BtlAction *)action))->unit->datUnit, value) != 0);
}

// FUN_001DB900
s32 btlCond_MYTAISEI(u8 *action, s16 value) {
    return (s32)((datCalcGetAffinity((u8 *)(((BtlAction *)action))->unit->datUnit, (s32)value) & 0x10000000) != 0);
}


/* Evaluate affinity on units of the caller genus. */
// FUN_001DB940
s32 btlCond_FRTAISEI(u8 *action, u32 value) {
    return btlEffectFindUnitMatchingCallback((s32)action, value, (1 << ((((BtlAction *)action))->unit->genus)) & 0xFFFF, 0x80000, 0, (code *)&btlCond_MYTAISEI);
}

/* Evaluate affinity on units of the opposite genus. */
// FUN_001DB990
s32 btlCond_ENTAISEI(u8 *action, u32 value) {
    u32 shift;
    {
        if ((((BtlAction *)action))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    return btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code *)&btlCond_MYTAISEI);
}

/* measured: retail computes the bitmap index before the enemy load, which needs propagation off. */
#pragma push
/* measured: with propagation enabled the bitmap index preparation moves after the enemy load,
 * unlike retail. */
#pragma opt_propagation off
/* Check the enemy affinity bitmap and test whether the requested affinity is non-normal. */
// FUN_001DB9F0
s32 btlCond_MYNOTNOMAL(u8 *action, s16 value) {
    u8 *p = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)p)->genus == 1 && btlTargetAffinityKnowledgeBypassNoop(action, value) == 0) {
        u32 index = (u16)value;
        if (datTestBitmapBit(((BtlUnit *)p)->charId, index) == 0)
            return 0;
    }
    return (datCalcGetElementAffinity((u8 *)((BtlUnit *)p)->datUnit, (s32)value) & 0x7000000) != 0;
}
#pragma pop

/* Evaluate non-normal affinity on units of the opposite genus. */
// FUN_001DBA90
s32 btlCond_ENNOTNOMAL(u8 *action, u32 value) {
    u32 shift;
    {
        if ((((BtlAction *)action))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    return btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0xA, (code *)&btlCond_MYNOTNOMAL);
}

/* Translate four wall-selector bits into the corresponding buff-status mask. */
// FUN_001DBAF0
s32 btlCond_MYWALL(u8 *action, u32 value) {
    s32 mask = 0;
    if (value & 1)
        mask |= 0x8000000;
    if (value & 2)
        mask |= 0x10000000;
    if (value & 4)
        mask |= 0x20000000;
    if (value & 8)
        mask |= 0x40000000;
    if (mask == 0)
        return 0;
    return datCalcHasBuffMask((((BtlAction *)action))->unit->datUnit, mask) != 0;
}

// FUN_001DBB90
s32 btlAICommandAlwaysTrue(void) {
    return 1;
}

/* Filter the classified targets by status, affinity and predicate; copy all matches or choose one.
 * K&R definition because call sites pass differently-typed function pointers as the predicate. */
// FUN_001DBBA0
#pragma push
/* measured: retail evaluates the bitmap index argument before the charId load, which needs dead-
 * assignment elimination off and conditional rebuilding on. */
#pragma opt_dead_assignments off
#pragma opt_rebuildconditionals on
s32 btlAICommandSelectCandidates(action, queryValue, excludedStatus, selectionFlags, rejectedResult, predicate)
s32 action;
s32 queryValue;
s32 excludedStatus;
s32 selectionFlags;
s32 rejectedResult;
code predicate;
{
    s32 flags;
    s32 filterFlags;
    s32 requireDown;
    s32 requireKnownAffinity;
    s32 requireSkill;
    s32 excludeBuffs;
    u8 *candidateAction;
    u8 *candidateUnit;
    s32 selectedCount;
    s32 candidateIndex;
    u8 *selected[12];

    flags = selectionFlags & 0xFFFF;
    if ((flags & 0x20) != 0) {
        btlEffectCollectTargetUnits((u8 *)action, (u8 *)action + 0x98, 2, 0, 0);
    } else {
        u16 available;

        available = btlSkillClassifyTargets((u8 *)action, (u8 *)action + 0x98, ((BtlAction *)((u8 *)action))->unk_6e, 0);
        if (available != 0) {
            u16 copyIndex;
            u16 copyCount;

            copyIndex = 0;
            while ((copyCount = ((BtlAction *)((u8 *)action))->unk_d0), (u16)copyIndex < copyCount) {
                ((BtlAiCommandWork *)((BtlAction *)(u8 *)action)->unk_38)->targets[(copyIndex & 0xFFFF)] =
                    (u32)((BtlAction *)(u8 *)action)->parameters.candidates[(copyIndex & 0xFFFF)];
                copyIndex++;
            }
            ((BtlAction *)((u8 *)action))->unk_6a = copyCount;
            return 1;
        }
    }
    selectedCount = 0;
    candidateIndex = 0;
    filterFlags = (u16)selectionFlags;
    requireDown = filterFlags & 1;
    requireKnownAffinity = filterFlags & 2;
    requireSkill = filterFlags & 0x10;
    excludeBuffs = filterFlags & 0x40;
    for (; (u16)candidateIndex < ((BtlAction *)((u8 *)action))->unk_d0; candidateIndex = (candidateIndex + 1) & 0xFFFF) {
        candidateAction = ((BtlAction *)(u8 *)action)->parameters.candidates[(candidateIndex & 0xFFFF)];
        if ((((BtlAction *)candidateAction)->unk_1a & 1) == 0) {
            continue;
        }
        candidateUnit = (u8 *)((BtlAction *)candidateAction)->unit;
        if (filterFlags == 0) {
            goto testm4;
        }
        if (requireDown == 0) {
            goto testm2;
        }
        if (datCalcChkBadStatus((u32)((BtlUnit *)candidateUnit)->datUnit, 0x100000) == 0) {
            continue;
        }
    testm2:
        if (requireKnownAffinity == 0) {
            goto testm3;
        }
        if (((BtlUnit *)candidateUnit)->genus != 1 || btlTargetAffinityKnowledgeBypassNoop(candidateAction, (s16)queryValue) != 0) {
            goto testm3;
        }
        {
            u32 index = (u16)queryValue;
            if (datTestBitmapBit(((BtlUnit *)candidateUnit)->charId, index) == 0) {
                continue;
            }
        }
    testm3:
        if (requireSkill == 0) {
            goto testm4;
        }
        if (btlAICommandCollectSkillCandidates((u8 *)action, candidateAction, 0, 0) < 0) {
            continue;
        }
    testm4:
        if (excludeBuffs == 0) {
            if (datCalcChkBadStatus((u32)((BtlUnit *)candidateUnit)->datUnit, excludedStatus) != 0) {
                continue;
            } else {
                goto docallback;
            }
        }
        if (datCalcHasBuffMask(((BtlUnit *)candidateUnit)->datUnit, excludedStatus) != 0) {
            continue;
        }
    docallback:
        if (predicate(candidateAction, queryValue) != rejectedResult) {
            selected[(u16)selectedCount] = candidateAction;
            selectedCount = (selectedCount + 1) & 0xFFFF;
        }
    }
    {
        s32 count;

        count = selectedCount & 0xFFFF;
        if (count == 0) {
            if ((flags & 8) != 0) {
                return 0;
            }
            return btlAICommandPickAiTarget((u8 *)action, queryValue);
        }
        if ((flags & 4) == 0) {
            s32 pick;

            pick = 0;
            if (count > 1) {
                pick = datCalcRandomBelow(count) & 0xFFFF;
            }
            ((BtlAction *)(u8 *)action)->targets[0] = selected[pick & 0xFFFF];
            ((BtlAction *)((u8 *)action))->unk_6a = 1;
        } else {
            s32 selectedIndex;

            selectedIndex = 0;
            while ((u16)selectedIndex < count) {
                ((BtlAction *)(u8 *)action)->targets[(selectedIndex & 0xFFFF)] = selected[selectedIndex & 0xFFFF];
                selectedIndex = (selectedIndex + 1) & 0xFFFF;
            }
            ((BtlAction *)((u8 *)action))->unk_6a = selectedCount;
        }
        return 1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
/* measured: lifetime splitting is needed for retail's register allocation of the sort cursor. */
#pragma opt_lifetimes on
/* HP-ratio ranking row used by the weighted target picker. */
typedef struct SortEnt {
    u32 unit;
    f32 ratio;
} SortEnt;
/* Use uniform targeting unless eligible party targets can be ranked by HP ratio and weighted. */
// FUN_001DBF20
s32 btlAICommandPickAiTarget(u8 *action, u32 value) {
    extern u8 D_006095F0[];
    u16 classification;
    u16 copyIndex;
    u16 candidateCount;
    s32 chooseUniformly;
    s32 scanIndex;
    u8 targetKind;
    u16 candidateIndex;
    s32 sortCount;
    u8 *candidateEntry;
    u32 candidateAction;
    u32 maxHp;
    u32 currentHp;
    SortEnt rankedTargets[12];
    s32 swapped;
    f32 leftRatio;
    u32 leftAction;
    s32 totalWeight;
    u16 weightedIndex;
    u16 randomWeight;
    BtlAction *actionRecord = (BtlAction *)action;

    classification = btlSkillClassifyTargets(action, action + 0x98, ((BtlAction *)action)->unk_6e, 0);
    if (classification != 0) {
        copyIndex = 0;
        while ((candidateCount = ((BtlAction *)action)->unk_d0), (u16)copyIndex < candidateCount) {
            ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[(copyIndex & 0xFFFF)] = (u32)((BtlAction *)action)->parameters.candidates[(copyIndex & 0xFFFF)];
            copyIndex++;
        }
        ((BtlAction *)action)->unk_6a = candidateCount;
        return 1;
    }
    candidateCount = ((BtlAction *)action)->unk_d0;
    chooseUniformly = 1;
    if (candidateCount == 1) {
        ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[0] = (u32)((BtlAction *)action)->parameters.candidates[0];
        ((BtlAction *)action)->unk_6a = 1;
    } else {
        if (((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->genus == 1) {
            scanIndex = 0;
            while ((u16)scanIndex < candidateCount) {
                if (((BtlUnit *)((u8 *)((BtlAction *)((u32)((BtlAction *)action)->parameters.candidates[scanIndex & 0xFFFF]))->unit))->genus != 0) {
                    break;
                }
                scanIndex = (scanIndex + 1) & 0xFFFF;
            }
            if ((u16)scanIndex == candidateCount) {
                chooseUniformly = 0;
            }
        }
        targetKind = iGpffffb3b8[actionRecord->unk_6e * 40 + MEMBER_OFFSET(DatSkillEntry, effectKind)];
        if (targetKind == 0x10 || targetKind == 0x0E || targetKind == 0x0D || targetKind == 0x0C || targetKind == 0x0A || targetKind == 0x08 || targetKind == 0x04 || targetKind == 0x03 || targetKind == 0x01) {
        } else {
            chooseUniformly = 1;
        }
        if (chooseUniformly != 0 || candidateCount > 4) {
            ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[0] = ((u32 *)(action + 0x98))[(u16)datCalcRandomBelow(candidateCount)];
            ((BtlAction *)action)->unk_6a = 1;
        } else {
            candidateIndex = 0;
            sortCount = candidateCount & 0xFFFF;
            while (candidateIndex < sortCount) {
                candidateEntry = action + (candidateIndex & 0xFFFF) * 4 + 0x98;
                candidateAction = *(u32 *)candidateEntry;
                maxHp = datCalcMaxHp((DatUnit *)(u32)((BtlUnit *)((u32)((BtlAction *)candidateAction)->unit))->datUnit) & 0xFFFF;
                currentHp = datCalcGetHp((u32)((BtlUnit *)(MEMBER(u32, candidateAction, BtlAction, unit)))->datUnit) & 0xFFFF;
                rankedTargets[candidateIndex & 0xFFFF].unit = *(u32 *)candidateEntry;
                rankedTargets[candidateIndex & 0xFFFF].ratio = (f32)currentHp / (f32)maxHp;
                candidateIndex++;
            }
            do {
                swapped = 0;
                for (candidateIndex = 0; candidateIndex < (s32)sortCount - 1; candidateIndex++) {
                    if ((leftRatio = rankedTargets[candidateIndex].ratio) < rankedTargets[candidateIndex + 1].ratio) {
                        leftAction = rankedTargets[candidateIndex].unit;
                        rankedTargets[candidateIndex].unit = rankedTargets[candidateIndex + 1].unit;
                        rankedTargets[candidateIndex].ratio = rankedTargets[candidateIndex + 1].ratio;
                        rankedTargets[candidateIndex + 1].unit = leftAction;
                        rankedTargets[candidateIndex + 1].ratio = leftRatio;
                        swapped = 1;
                    }
                }
            } while (swapped != 0);
            randomWeight = datCalcRandomBelow(100);
            totalWeight = 0;
            weightedIndex = 0;
            while (weightedIndex < candidateCount) {
                totalWeight = (totalWeight + D_006095F0[4 * candidateCount - 4 + weightedIndex]) & 0xFFFF;
                if (totalWeight >= randomWeight) {
                    break;
                }
                weightedIndex++;
            }
            if (sortCount != weightedIndex) {
                ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[0] = rankedTargets[weightedIndex].unit;
                ((BtlAction *)action)->unk_6a = 1;
            } else {
                ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[0] = rankedTargets[datCalcRandomBelow(candidateCount)].unit;
                ((BtlAction *)action)->unk_6a = 1;
            }
        }
    }
    return 1;
}

#pragma pop
/* Matches P3FES func_002c3be0. Copies all classified targets or chooses the candidate with the
 * lowest current HP. */
// FUN_001DC380
u32 btlCond_HPMIN(u32 action)
{
    u32 unit;
    u16 available;

    unit = action;
    available = btlSkillClassifyTargets((u8 *)unit, (u8 *)(unit + 0x98), ((BtlAction *)unit)->unk_6e, 0);
    if (available != 0) {
        u16 index;
        u16 count;
        index = 0;
        while ((count = ((BtlAction *)unit)->unk_d0), (u16)index < count) {
            ((BtlAiCommandWork *)((BtlAction *)unit)->unk_38)->targets[(index & 0xffff)] =
                (u32)((BtlAction *)unit)->parameters.candidates[(index & 0xffff)];
            index++;
        }
        ((BtlAction *)unit)->unk_6a = count;
        return 1;
    }
    {
        u32 selected;
        u32 index;
        u32 lowest;
        u32 count;
        u32 candidate;
        u32 stat;
        selected = 0;
        lowest = 0xfffffff;
        index = 0;
        count = ((BtlAction *)unit)->unk_d0;
        while (index < count) {
            candidate = (u32)((BtlAction *)unit)->parameters.candidates[index];
            stat = ((DatUnit *)((s32)((BtlUnit *)((s32)((BtlAction *)candidate)->unit))->datUnit))->hp;
            if (stat < lowest) {
                selected = candidate;
                lowest = stat;
            }
            index++;
        }
        ((BtlAiCommandWork *)((BtlAction *)unit)->unk_38)->targets[0] = selected;
    }
    ((BtlAction *)unit)->unk_6a = 1;
    return 1;
}


/* Matches P3FES func_002c3ce0. Copies all classified targets or chooses the candidate with the
 * lowest level. */
// FUN_001DC480
u32 btlCond_LVMIN(u32 action)
{
    u16 result;
    u16 copyIndex;
    s32 unit;
    s32 selected;
    u16 index;
    u16 best;
    u16 score;
    u32 idx32;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), ((BtlAction *)action)->unk_6e, 0);
    if (result != 0) {
        for (copyIndex = 0; copyIndex < ((BtlAction *)action)->unk_d0; copyIndex++) {
            ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[copyIndex] = (u32)((BtlAction *)action)->parameters.candidates[copyIndex];
        }
        ((BtlAction *)action)->unk_6a = ((BtlAction *)action)->unk_d0;
        return 1;
    }
    selected = 0;
    best = 0xffff;
    for (index = 0; index < ((BtlAction *)action)->unk_d0; index++) {
        idx32 = index;
        idx32 = idx32 & 0xffff;
        unit = (s32)((BtlAction *)action)->parameters.candidates[idx32];
        score = (u8)datCalcGetLevel((u32)((BtlUnit *)((s32)((BtlAction *)unit)->unit))->datUnit);
        if (score < best) {
            selected = unit;
            best = score;
        }
    }
    ((s32 *)((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets)[0] = selected;
    ((BtlAction *)action)->unk_6a = 1;
    return 1;
}

// FUN_001DC5B0
s32 btlCond_MPMAX(void) {
    return 0;
}

// FUN_001DC5C0
s32 btlAICommandPickMyBad(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, btlCond_MYBAD);
}

// FUN_001DC600
s32 btlAICommandPickNotMyBad(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 1, btlCond_MYBAD);
}

// FUN_001DC640
s32 btlAICommandPickMyId(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, btlCond_MYID);
}

/* Matches P3FES func_002c3f00 (btlAI target-select loop); the index extern returns u32 so the call
 * result is not re-masked. Chooses another active same-genus action, falling back to the caller
 * when none qualifies. */
// FUN_001DC6A0
u32 btlCond_MYAI(s32 action)
{
    s32 candidateAction;
    u16 candidateCount;
    s32 candidates[12];

    candidateCount = 0;
    for (candidateAction = (s32)((BtlBattleState *)iGpffffb3ac)->actions; candidateAction != 0; candidateAction = (s32)((BtlAction *)candidateAction)->next) {
        if ((((action != candidateAction) && ((((BtlAction *)candidateAction)->unk_1a & 1) != 0)) &&
            ((((BtlAction *)candidateAction)->unk_1a & 8) != 0)) &&
           (((((BtlAction *)action))->unit->genus == (((BtlAction *)candidateAction))->unit->genus &&
            (datCalcChkBadStatus((u32)((BtlUnit *)(((BtlAction *)candidateAction)->unit))->datUnit, 0x80000) == 0))
           )) {
            candidates[candidateCount] = candidateAction;
            candidateCount++;
        }
    }
    if (candidateCount == 0) {
        ((s32 *)((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets)[0] = action;
        ((BtlAction *)action)->unk_6a = 1;
        return 1;
    }
    else {
        ((s32 *)((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets)[0] = candidates[datCalcRandomBelow(candidateCount)];
        ((BtlAction *)action)->unk_6a = 1;
        return 1;
    }
}


// FUN_001DC7A0
s32 btlAICommandPickMyHansya(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, btlCond_MYHANSYA);
}

// FUN_001DC7E0
s32 btlAICommandPickMyKyusyu(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, btlCond_MYKYUSYU);
}

// FUN_001DC820
s32 btlAICommandPickMyMukou(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, btlCond_MYMUKOU);
}

// FUN_001DC860
s32 btlAICommandPickMyWeak(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, btlCond_MYWEAK);
}

// FUN_001DC8A0
s32 btlAICommandPickNotMyHansya(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 1, btlCond_MYHANSYA);
}

// FUN_001DC8E0
s32 btlAICommandPickNotMyKyusyu(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 1, btlCond_MYKYUSYU);
}

// FUN_001DC920
s32 btlAICommandPickNotMyMukou(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 1, btlCond_MYMUKOU);
}

// FUN_001DC960
s32 btlAICommandPickNotMyWeak(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 1, btlCond_MYWEAK);
}

/* Copy classified reverse targets or choose one candidate uniformly. Matches P3FES func_002c4200. */
// FUN_001DC9A0
u32 btlCond_AI_REV(u32 action)
{
    u16 result;
    u16 index;
    u32 address;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), ((BtlAction *)action)->unk_6e, 1);
    if (result != 0) {
        for (index = 0; index < ((BtlAction *)action)->unk_d0; index++) {
            ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[index] = (u32)((BtlAction *)action)->parameters.candidates[index];
        }
        ((BtlAction *)action)->unk_6a = ((BtlAction *)action)->unk_d0;
        return 1;
    }
    index = datCalcRandomBelow(((BtlAction *)action)->unk_d0);
    address = (index & 0xffff) * 4;
    ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[0] = (u32)((BtlAction *)(address + action))->parameters.candidates[0];
    ((BtlAction *)action)->unk_6a = 1;
    return 1;
}

/* Use the nearest candidate when available, otherwise use the normal AI target picker; the copy
 * loop is written like FUN_001DC9A0's. */
// FUN_001DCA60
s32 btlCond_APPOINT(u8 *action, u32 value)
{
    u16 result;
    u16 index;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), ((BtlAction *)action)->unk_6e, 0);
    if (result != 0) {
        for (index = 0; index < ((BtlAction *)action)->unk_d0; index++) {
            ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[index] = (u32)((BtlAction *)action)->parameters.candidates[index];
        }
        ((BtlAction *)action)->unk_6a = ((BtlAction *)action)->unk_d0;
        return 1;
    }
    if (btlEffectSelectNearestEntry(0, (u8 *)(action + 0x98)) == 0) {
        return btlAICommandPickAiTarget(action, value);
    }
    ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[0] = btlFormationCurrentEntry((u8 *)(action + 0x98));
    ((BtlAction *)action)->unk_6a = 1;
    return 1;
}

// FUN_001DCB50
s32 btlAICommandPickMyDown(u8 *formation, u32 unusedQuery)
{
    return btlAICommandSelectCandidates((s32)formation, BTL_STATUS_DOWN, 0, 0, 0, btlCond_MYBAD);
}


// FUN_001DCB90
s32 btlAICommandPickNotMyDown(u8 *formation, u32 unusedQuery)
{
    return btlAICommandSelectCandidates((s32)formation, BTL_STATUS_DOWN, 0, 0, 1, btlCond_MYBAD);
}


// FUN_001DCBD0
s32 btlAICommandPickMyHansyaExcludingDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 1048576, 0, 0, btlCond_MYHANSYA);
}

// FUN_001DCC10
s32 btlAICommandPickMyKyusyuExcludingDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 1048576, 0, 0, btlCond_MYKYUSYU);
}

// FUN_001DCC50
s32 btlAICommandPickMyMukouExcludingDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 1048576, 0, 0, btlCond_MYMUKOU);
}

// FUN_001DCC90
s32 btlAICommandPickMyWeakExcludingDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 1048576, 0, 0, btlCond_MYWEAK);
}

// FUN_001DCCD0
s32 btlAICommandPickNotMyHansyaExcludingDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 1048576, 0, 1, btlCond_MYHANSYA);
}

// FUN_001DCD10
s32 btlAICommandPickNotMyKyusyuExcludingDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 1048576, 0, 1, btlCond_MYKYUSYU);
}

// FUN_001DCD50
s32 btlAICommandPickNotMyMukouExcludingDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 1048576, 0, 1, btlCond_MYMUKOU);
}

// FUN_001DCD90
s32 btlAICommandPickNotMyWeakExcludingDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 1048576, 0, 1, btlCond_MYWEAK);
}

// FUN_001DCDD0
s32 btlAICommandPickMyHansyaRequireDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 1, 0, btlCond_MYHANSYA);
}

// FUN_001DCE10
s32 btlAICommandPickMyKyusyuRequireDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 1, 0, btlCond_MYKYUSYU);
}

// FUN_001DCE50
s32 btlAICommandPickMyMukouRequireDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 1, 0, btlCond_MYMUKOU);
}

// FUN_001DCE90
s32 btlAICommandPickMyWeakRequireDown(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 1, 0, btlCond_MYWEAK);
}

// FUN_001DCED0
s32 btlAICommandPickNotMyId(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 1, btlCond_MYID);
}

/* Copies all classified targets or picks one candidate uniformly at random. Matches P3FES
 * func_002c4760; the random slot offset is kept in bytes. */
// FUN_001DCF10
u32 btlCond_RND(u32 action)
{
    u16 result;
    u16 index;
    u32 address;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), ((BtlAction *)action)->unk_6e, 0);
    if (result != 0) {
        for (index = 0; index < ((BtlAction *)action)->unk_d0; index++) {
            ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[index] = (u32)((BtlAction *)action)->parameters.candidates[index];
        }
        ((BtlAction *)action)->unk_6a = ((BtlAction *)action)->unk_d0;
        return 1;
    }
    index = datCalcRandomBelow(((BtlAction *)action)->unk_d0);
    address = (index & 0xffff) * 4;
    ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[0] = (u32)((BtlAction *)(address + action))->parameters.candidates[0];
    ((BtlAction *)action)->unk_6a = 1;
    return 1;
}


// FUN_001DCFD0
s32 btlAICommandPickMyHojo(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, (FormationCallback)btlCond_MYHOJO);
}

// FUN_001DD010
s32 btlAICommandPickNotMyHojo(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 1, (FormationCallback)btlCond_MYHOJO);
}

// FUN_001DD050
s32 btlAICommandPickMyNotNomal(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, btlCond_MYNOTNOMAL);
}

// FUN_001DD090
s32 btlAICommandPickMyNomal(u8 *formation, u32 flags) {
    return btlAICommandSelectCandidates((s32)formation, flags, 0, 0, 0, (FormationCallback)btlCond_MYNOMAL);
}

/* Copy all classified targets or choose the candidate with the highest current HP. The max-score
 * search uses a while loop so the best, bestScore, j, count initialisation order follows retail. */
// FUN_001DD0D0
u32 btlCond_HPMAX(u32 action)
{
    u16 result;
    u16 index;
    u32 best;
    u32 j;
    u32 bestScore;
    u32 count;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), ((BtlAction *)action)->unk_6e, 0);
    if (result != 0) {
        for (index = 0; index < ((BtlAction *)action)->unk_d0; index++) {
            ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[index] = (u32)((BtlAction *)action)->parameters.candidates[index];
        }
        ((BtlAction *)action)->unk_6a = ((BtlAction *)action)->unk_d0;
        return 1;
    }
    best = 0;
    bestScore = 0;
    j = 0;
    count = ((BtlAction *)action)->unk_d0;
    while (j < count) {
        u8 *ptr = (u8 *)(u32)((BtlAction *)action)->parameters.candidates[j];
        u32 score = ((DatUnit *)((u32)((BtlUnit *)((u32)((BtlAction *)ptr)->unit))->datUnit))->hp;
        if (bestScore < score) {
            best = (u32)ptr;
            bestScore = score;
        }
        j++;
    }
    ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->targets[0] = best;
    ((BtlAction *)action)->unk_6a = 1;
    return 1;
}
/* Skill-table byte +8 remains unnamed; it is unknown04[4] in the shared 0x28-byte row. Select a
 * usable command by predicted remaining target HP and the requested cost class. */
#pragma push
/* measured: retail rebuilds the conditionals in the predicted-HP selection body. */
#pragma opt_rebuildconditionals on
// FUN_001DD1C0
s32 btlAICommandPickSkillTargetByHp(u8 *action, u8 *target, u16 *commands, u16 count, u32 requestedCostClass) {
    u32 targetHp;
    s32 bestRemainingHp;
    s32 bestCommand;
    s32 commandIndex;
    u32 costClass;
    s32 commandCount;
    u16 *commandEntry;
    u16 commandId;
    u8 costKind;
    s32 hpDelta;
    s32 remainingHp;
    BtlAction *targetRecord = (BtlAction *)target;

    targetHp = datCalcGetHp((u32)((BtlUnit *)((u32)((BtlAction *)target)->unit))->datUnit) & 0xFFFF;
    bestCommand = -1;
    bestRemainingHp = 0xFFFFFF;
    commandIndex = 0;
    costClass = requestedCostClass & 0xFFFF;
    commandCount = count & 0xFFFF;
    while ((commandIndex & 0xFFFF) < commandCount) {
        commandEntry = commands + (u16)commandIndex;
        commandId = *(u16 *)commandEntry;
        if (commandId == 0)
            costKind = 0;
        else
            costKind = ((DatSkillEntry *)iGpffffb3b8)[commandId].unknown04[4];
        if ((costClass != 0 || (costKind & 0xFF) == 1) && (costClass != 1 || (costKind & 0xFF) == 0)) {
            hpDelta = datCalcSkillAmount(commandId, (u8 *)((BtlUnit *)(u32)((BtlAction *)action)->unit)->datUnit, (u8 *)targetRecord->unit->datUnit, 1, 1, 1, 0, 1);
            remainingHp = targetHp + hpDelta;
            if (remainingHp > 0 && bestRemainingHp > 0) {
                if (remainingHp < bestRemainingHp) {
                    bestCommand = *(u16 *)commandEntry;
                    bestRemainingHp = remainingHp;
                }
                goto next;
            }
            if (remainingHp <= 0 && (bestRemainingHp > 0 || bestRemainingHp < remainingHp)) {
                bestCommand = *(u16 *)commandEntry;
                bestRemainingHp = remainingHp;
            }
        }
    next:
        commandIndex = (commandIndex + 1) & 0xFFFF;
    }
    datCalcClearField18((u32)((BtlUnit *)((u32)((BtlAction *)action)->unit))->datUnit);
    datCalcClearField18((u32)targetRecord->unit->datUnit);
    return bestCommand;
}
#pragma pop
/* Skill-table byte +8 remains unnamed; it is unknown04[4] in the shared 0x28-byte row. Choose the
 * command whose predicted target HP is closest to its maximum. */
// FUN_001DD3A0
s32 btlAICommandPickSkillTargetNearMaxHp(u8 *action, u8 *target, u16 *commands, u16 count, s32 requestedCostClass) {
    u32 targetHp;
    u32 maxHp;
    s32 bestDistance;
    s32 bestCommand;
    s32 commandIndex;
    u32 costClass;
    s32 commandCount;
    u16 *commandEntry;
    u16 commandId;
    u8 costKind;
    s32 distance;
    BtlAction *targetRecord = (BtlAction *)target;

    targetHp = datCalcGetHp((u32)((BtlUnit *)((u32)((BtlAction *)target)->unit))->datUnit) & 0xFFFF;
    maxHp = datCalcMaxHp(targetRecord->unit->datUnit) & 0xFFFF;
    bestCommand = -1;
    bestDistance = 0xFFFFFF;
    commandIndex = 0;
    costClass = requestedCostClass & 0xFFFF;
    commandCount = count & 0xFFFF;
    while ((commandIndex & 0xFFFF) < commandCount) {
        commandEntry = commands + (u16)commandIndex;
        commandId = *(u16 *)commandEntry;
        if (commandId != 0 && commandId < 0x1B8) {
            costKind = ((DatSkillEntry *)iGpffffb3b8)[commandId].unknown04[4];
            if ((costClass != 0 || (costKind & 0xFF) == 1) && (costClass != 1 || (costKind & 0xFF) == 0)) {
                distance = func_0043c6a0(maxHp - (targetHp + datCalcSkillAmount(commandId, (u8 *)((BtlUnit *)(u32)((BtlAction *)action)->unit)->datUnit, (u8 *)targetRecord->unit->datUnit, 1, 1, 1, 0, 1)));
                if (distance < bestDistance) {
                    bestCommand = *(u16 *)commandEntry;
                    bestDistance = distance;
                }
            }
        }
        commandIndex = (commandIndex + 1) & 0xFFFF;
    }
    datCalcClearField18((u32)((BtlUnit *)((u32)((BtlAction *)action)->unit))->datUnit);
    datCalcClearField18((u32)targetRecord->unit->datUnit);
    return bestCommand;
}
/* Collect usable commands effective on the target and choose by predicted HP outcome. */
// FUN_001DD570
s32 btlAICommandCollectSkillCandidates(u8 *action, u8 *target, s32 costPreference, s32 effectFilter)
{
    u8 *sourceUnit;
    s16 defaultElement;
    u16 candidates[8];
    u16 commandIndex;
    u16 candidateCount;
    u16 *commands;
    u16 commandCount;
    s32 scanCount;
    u16 *entry;
    u16 listCommand;
    s16 commandElement;
    s32 elementFlags;
    u16 command;
    u8 *usabilityUnit;
    s32 usable;
    s32 selectedCommand;
    BtlAction *actionRecord = (BtlAction *)action;
    BtlUnit *commandUnit;

    candidateCount = 0;
    sourceUnit = (u8 *)((BtlAction *)action)->unit;
    defaultElement = (s16)datCalcSkillElement((u8 *)((BtlUnit *)sourceUnit)->datUnit, 0);
    if (btlAICommandNomalCheck(target, defaultElement, 1) != 0) {
        candidates[0] = 0;
        candidateCount++;
    }
    commandCount = (u16)datCalcGetTableLength(MEMBER(DatUnit *, sourceUnit, BtlUnit, datUnit));
    commands = (u16 *)datCalcSkillList(MEMBER(DatUnit *, sourceUnit, BtlUnit, datUnit));
    commandIndex = 0;
    scanCount = commandCount;
    while (commandIndex < scanCount) {
        entry = commands + commandIndex;
        listCommand = *entry;
        if (listCommand != 0 && listCommand < 0x1B8) {
            commandElement = (s16)datCalcSkillElement(MEMBER(u8 *, sourceUnit, BtlUnit, datUnit), listCommand);
            elementFlags = datCalcElementBit(commandElement);
            if (effectFilter == 0) {
                if ((elementFlags & 0x7E) == 0)
                    goto next;
            } else if (effectFilter == 1) {
                if ((elementFlags & 0x7E) == 0 || (elementFlags & 2) != 0)
                    goto next;
            } else if (effectFilter == 2) {
                if ((elementFlags & 2) == 0)
                    goto next;
            }
            command = *entry;
            if (command >= 0x240)
                kAssertFail(D_006095E0, 0x45F);
            usabilityUnit = (u8 *)actionRecord->unit;
            commandUnit = (BtlUnit *)usabilityUnit;
            if (command < 0x1B8) {
                if (datCalcChkBadStatus((u32)((BtlUnit *)usabilityUnit)->datUnit, 0x80008) != 0) {
                    usable = 0;
                    goto have_ok;
                }
                if (datCalcHasSkill((u8 *)commandUnit->datUnit, command) == 0) {
                    usable = 0;
                    goto have_ok;
                }
                if (datCalcThresholdTrigger((u8 *)commandUnit->datUnit, command) != 0) {
                    usable = 0;
                    goto have_ok;
                }
            } else {
                if (datCalcHasSkill((u8 *)((BtlUnit *)usabilityUnit)->datUnit, command) == 0) {
                    usable = 0;
                    goto have_ok;
                }
            }
            usable = 1;
have_ok:
            if (usable == 0)
                goto next;
            if (btlAICommandNomalCheck(target, commandElement, 1) != 0) {
                candidates[candidateCount] = *entry;
                candidateCount++;
            }
        }
next:
        commandIndex++;
    }
    if (candidateCount > 0) {
        switch (costPreference) {
        case 0:
            selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 0);
            if (selectedCommand < 0)
                selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 1);
            break;
        case 1:
            selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 1);
            if (selectedCommand < 0)
                selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 0);
            break;
        default:
            selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 0xFFFF);
            break;
        }
        return selectedCommand;
    }
    return -1;
}
/* Collect revive, healing or status-cure commands according to the target condition. */
// FUN_001DD920
s32 btlAICommandCollectRecoveryCommands(u8 *action, u8 *target, s16 unusedElement, s32 costPreference)
{
    u8 *unit;
    u16 commandCount;
    u16 *commands;
    u16 candidates[8];
    u16 candidateCount;
    s16 recoveryKind;
    u16 command;
    u32 targetHp;
    u32 maxHp;
    s32 currentHp;
    s32 selectedCommand;
    BtlAction *targetRecord = (BtlAction *)target;

    recoveryKind = -1;
    candidateCount = 0;
    unit = MEMBER(u8 *, action, BtlAction, unit);
    commandCount = datCalcGetTableLength(((BtlUnit *)unit)->datUnit);
    commands = (u16 *)datCalcSkillList(MEMBER(DatUnit *, unit, BtlUnit, datUnit));
    if (datCalcIsDead((u32)((BtlUnit *)((u32)((BtlAction *)target)->unit))->datUnit, 0) != 0) {
        recoveryKind = 0;
    } else {
        targetHp = ((DatUnit *)((u32)((BtlUnit *)((u32)((BtlAction *)target)->unit))->datUnit))->hp;
        maxHp = (u16)datCalcMaxHp((DatUnit *)(u32)((BtlUnit *)((u32)((BtlAction *)target)->unit))->datUnit);
        if (targetHp * 100 <= maxHp * 60) {
            recoveryKind = 1;
        } else {
            if (datCalcChkBadStatus((u32)targetRecord->unit->datUnit, 0xC) != 0) {
                recoveryKind = 2;
            } else {
                currentHp = datCalcGetHp((u32)targetRecord->unit->datUnit) & 0xFFFF;
                if (currentHp < (s32)(datCalcMaxHp(targetRecord->unit->datUnit) & 0xFFFF))
                    recoveryKind = 1;
            }
        }
    }
    switch (recoveryKind) {
    case 0: {
        u16 i;
        u16 *entry;
        s32 limit;

        i = 0;
        limit = commandCount;
        while (i < limit) {
            entry = commands + i;
            command = *entry;
            if (command != 0 && command < 0x1B8) {
                switch (command) {
                case 0xD1: case 0xD2:
                    if (btlCommandUsable(action, command)) {
                        candidates[candidateCount] = *entry;
                        candidateCount++;
                    }
                    break;
                }
            }
            i++;
        }
        break;
    }
    case 1: {
        struct {
            u16 i;
            u16 *entry;
            s32 limit;
        } scan;

        scan.i = 0;
        scan.limit = commandCount;
        while (scan.i < scan.limit) {
            scan.entry = commands + scan.i;
            command = *scan.entry;
            if (command != 0 && command < 0x1B8) {
                switch (command) {
                case 0xC0: case 0xC1: case 0xC2: case 0xC3:
                case 0xC4: case 0xC5: case 0xC6:
                    if (btlCommandUsable(action, command)) {
                        candidates[candidateCount] = *scan.entry;
                        candidateCount++;
                    }
                    break;
                }
            }
            scan.i++;
        }
        if (candidateCount > 0) {
            switch (costPreference) {
            case 0:
                selectedCommand = btlAICommandPickSkillTargetNearMaxHp(action, target, candidates, candidateCount, 0);
                if (selectedCommand < 0)
                    selectedCommand = btlAICommandPickSkillTargetNearMaxHp(action, target, candidates, candidateCount, 1);
                break;
            case 1:
                selectedCommand = btlAICommandPickSkillTargetNearMaxHp(action, target, candidates, candidateCount, 1);
                if (selectedCommand < 0)
                    selectedCommand = btlAICommandPickSkillTargetNearMaxHp(action, target, candidates, candidateCount, 0);
                break;
            default:
                selectedCommand = btlAICommandPickSkillTargetNearMaxHp(action, target, candidates, candidateCount, 0xFFFF);
                break;
            }
            return selectedCommand;
        }
        break;
    }
    case 2: {
        struct {
            s32 i;
            u16 *entry;
            s32 limit;
        } scan;

        scan.i = 0;
        scan.limit = commandCount;
        while ((u16)scan.i < scan.limit) {
            scan.entry = commands + (u16)scan.i;
            command = *scan.entry;
            if (command != 0 && command < 0x1B8) {
                switch (command) {
                case 0xC7: case 0xC8:
                    if (btlCommandUsable(action, command)) {
                        candidates[candidateCount] = *scan.entry;
                        candidateCount++;
                    }
                    break;
                }
            }
            scan.i = (u16)(scan.i + 1);
        }
        break;
    }
    }
    if (candidateCount > 0)
        return candidates[datCalcRandomBelow(candidateCount)];
    return -1;
}
/* Collect usable commands of the requested element and choose by predicted HP outcome. */
// FUN_001DE000
#pragma push
/* measured: retail compiles the command collector with propagation disabled. */
#pragma opt_propagation off
s32 btlAICommandCollectCommandsOfType(u8 *action, u8 *target, s16 element, s32 costPreference)
{
    extern s32 btlAICommandCollectRecoveryCommands(u8 *action, u8 *target, s16 unusedElement, s32 costPreference);
    u8 *unit;
    s16 queried;
    s16 targetElement;
    u16 commandCount;
    s32 scanCount;
    u16 *commands;
    u16 commandIndex;
    u16 candidateCount;
    u16 *entry;
    u16 command;
    u16 candidates[8];
    s32 selectedCommand;

    if (element == 0x10)
        return btlAICommandCollectRecoveryCommands(action, target, element, costPreference);

    candidateCount = 0;
    unit = (u8 *)((BtlAction *)action)->unit;
    queried = datCalcSkillElement((u8 *)((BtlUnit *)unit)->datUnit, 0);
    if (queried == element && btlAICommandNomalCheck(target, queried, 1) != 0) {
        candidates[0] = 0;
        candidateCount++;
    }
    commandCount = datCalcGetTableLength(MEMBER(DatUnit *, unit, BtlUnit, datUnit));
    commands = (u16 *)datCalcSkillList(MEMBER(DatUnit *, unit, BtlUnit, datUnit));
    commandIndex = 0;
    scanCount = commandCount;
    for (; commandIndex < scanCount; commandIndex++) {
        entry = commands + commandIndex;
        if (*entry == 0 || *entry >= 0x1B8)
            goto next;
        queried = datCalcSkillElement(MEMBER(u8 *, unit, BtlUnit, datUnit), *entry);
        if (queried != element)
            goto next;
        command = *entry;
        if (btlCommandUsable(action, command) == 0)
            goto next;
        targetElement = queried;
        if (btlAICommandNomalCheck(target, targetElement, 1) == 0)
            goto next;
        candidates[candidateCount] = *entry;
        candidateCount++;
    next:
        ;
    }
    if (candidateCount > 0) {
        switch (costPreference) {
        case 0:
            selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 0);
            if (selectedCommand < 0)
                selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 1);
            break;
        case 1:
            selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 1);
            if (selectedCommand < 0)
                selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 0);
            break;
        default:
            selectedCommand = btlAICommandPickSkillTargetByHp(action, target, candidates, candidateCount, 0xFFFF);
            break;
        }
    } else {
        return -1;
    }
    return selectedCommand;
}
#pragma pop
#pragma push
/* measured: retail hoists loop invariants in the HP-weight picker. */
#pragma opt_loop_invariants on
/* measured: retail's stack frame and bubble-sort loop require loop-invariant hoisting enabled.
 * Ranks candidates by missing HP and status bonus, then picks from the ranked weight table. */
// FUN_001DE370
u32 btlAICommandPickUnitByHpWeight(u8 *action)
{
    u32 candidateIndex;
    u32 random;
    u32 cumulative;
    s16 scores[16];
    u32 selectionIndex;
    u32 total;
    BtlAction *actionRecord = (BtlAction *)action;
    BtlAction *candidateRecord;

    if (((BtlAction *)action)->unk_d0 == 1)
        return (u32)((BtlAction *)action)->parameters.candidates[0];

    total = 0;
    candidateIndex = 0;
    while (candidateIndex < actionRecord->unk_d0) {
        u8 *unit;
        s16 *score;
        u32 maxHp;
        u32 currentHp;
        f32 scoreFloat;
        f32 bonus;

        total += D_00609600[candidateIndex];
        unit = ((BtlAction *)action)->parameters.candidates[candidateIndex];
        candidateRecord = (BtlAction *)unit;
        score = scores + candidateIndex;
        *score = 0;
        maxHp = datCalcMaxHp((DatUnit *)(u32)((BtlUnit *)((u32)((BtlAction *)unit)->unit))->datUnit) & 0xFFFF;
        currentHp = datCalcGetHp((u32)candidateRecord->unit->datUnit) & 0xFFFF;
        *score += (s16)(100.0f - 100.0f * ((f32)currentHp / (f32)maxHp));
        switch (datCalcGetBadStatusNoDown((u32)candidateRecord->unit->datUnit)) {
        case 0x40:
            bonus = 50.0f;
            scoreFloat = (f32)*score;
            *score = (s16)(scoreFloat + bonus);
            break;
        default:
            break;
        }
        candidateIndex++;
    }
    {
        u32 bubbleIndex;
        s16 *sortScore;
        s32 swapped;
        u32 one;
        one = 1;
        do {
        swapped = 0;
        for (bubbleIndex = 0; bubbleIndex < actionRecord->unk_d0 - 1; bubbleIndex++) {
            s32 left;
            s32 right;
            s16 *nextScore;

            sortScore = scores + bubbleIndex;
            nextScore = sortScore + 1;
            right = *nextScore;
            left = *sortScore;
            if (left < right) {
                u8 *entry;
                u32 swappedAction;

                entry = action + bubbleIndex * 4;
                swappedAction = (u32)((BtlAction *)entry)->parameters.candidates[0];
                ((BtlAction *)entry)->parameters.candidates[0] = ((BtlAction *)entry)->parameters.candidates[1];
                ((BtlAction *)entry)->parameters.candidates[1] = (u8 *)swappedAction;
                *sortScore = right;
                *nextScore = left;
                swapped = one;
            }
        }
        } while (swapped != 0);
    }
    cumulative = 0;
    random = datCalcRandomBelow(total);
    selectionIndex = 0;
    for (; selectionIndex < actionRecord->unk_d0; selectionIndex++) {
        cumulative += D_00609600[selectionIndex];
        if (random < cumulative)
            return (u32)((BtlAction *)((u8 *)(selectionIndex * 4) + (u32)action))->parameters.candidates[0];
    }
    return 0;
}
#pragma pop
/* measured: switch cases are declared in reverse of retail's test order because the compiler tests
 * linear-chain case labels in reverse. Decode the packed action code into command-work kind, skill
 * and plan fields. */
#pragma push
/* measured: retail rebuilds the conditionals in the action-code decoder. */
#pragma opt_rebuildconditionals on
// FUN_001DE640
void btlAICommandSetActionCode(u8 *action, u8 *work, u16 actionCode)
{
    u16 kindCode;

    if ((actionCode & 0xF000) == 0x8000)
        kindCode = actionCode;
    else
        kindCode = actionCode & 0xF000;
    switch (kindCode & 0xFFFF) {
    case 0x8000:
        ((BtlAiCommandWork *)work)->kind = 1;
        ((BtlAiCommandWork *)work)->command = datCalcDefaultSkillId((u8 *)(((BtlAction *)action))->unit->datUnit) & 0xFFFF;
        break;
    case 0x1000:
        ((BtlAiCommandWork *)work)->kind = 9;
        ((BtlAiCommandWork *)work)->command = 0x111;
        ((BtlAiCommandWork *)work)->plan = actionCode & 0xFFFF0FFF;
        break;
    case 0x2000:
        ((u16 *)((BtlAction *)action)->targetBlock.unk_e8)[2] = actionCode & 0xFFFF0FFF;
    case 0x8002:
        ((BtlAiCommandWork *)work)->kind = 0x7;
        break;
    case 0x8007:
        ((BtlAiCommandWork *)work)->kind = 0x8;
        break;
    case 0x8005:
        break;
    case 0x8006:
        ((BtlAiCommandWork *)work)->kind = 0xB;
        break;
    case 0x8001:
        ((BtlAiCommandWork *)work)->kind = 0x6;
        break;
    case 0x8008:
        ((BtlAiCommandWork *)work)->kind = 0xC;
        break;
    case 0x8009:
        btlAiChooseUsableAttackSkill(action, work);
        break;
    case 0x8004:
        actionCode = (u16)(datCalcPickSpecialItem((u8 *)(((BtlAction *)action))->unit->datUnit) & 0xFFFF);
    default:
        ((BtlAiCommandWork *)work)->kind = 2;
        ((BtlAiCommandWork *)work)->command = actionCode;
        break;
    }
}
#pragma pop
/* Evaluate two rows of three conditions and return the first eligible action selector. */
// FUN_001DE800
u8 btlAICommandPickTableAction(u8 *action) {
    BtlAiRecord *base;
    BtlAiConditionRow *row;
    s32 rowIndex;
    s32 conditionIndex;
    u32 packedCondition;
    u32 conditionKind;
    u32 conditionValue;
    s32 conditionResult;
    u32 conditionResults[3];

    base = &((BtlAiRecord *)iGpffffb3d0)[((BtlUnit *)(u32)((BtlAction *)action)->unit)->charId];
    rowIndex = 0;
    while ((u16)rowIndex < 2) {
        row = &base->conditionRows[rowIndex & 0xFFFF];
        conditionIndex = 0;
        while ((u16)conditionIndex < 3) {
            packedCondition = (s32)row->conditions[conditionIndex & 0xFFFF];
            conditionKind = (packedCondition & 0xFF000000) >> 24;
            conditionValue = packedCondition & 0xFFFFFF;
            if (conditionKind == 0)
                conditionResult = 0;
            else
                conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
            conditionResults[conditionIndex & 0xFFFF] = conditionResult;
            conditionIndex = (conditionIndex + 1) & 0xFFFF;
        }
        if (conditionResults[0] && conditionResults[1] && conditionResults[2] && row->actions[0] != 8)
            return row->actions[0];
        if (conditionResults[0] && conditionResults[1] && row->actions[1] != 8)
            return row->actions[1];
        if (conditionResults[0] && conditionResults[2] && row->actions[2] != 8)
            return row->actions[2];
        if (conditionResults[1] && conditionResults[2] && row->actions[3] != 8)
            return row->actions[3];
        if (conditionResults[0] && row->actions[4] != 8)
            return row->actions[4];
        if (conditionResults[1] && row->actions[5] != 8)
            return row->actions[5];
        if (conditionResults[2] && row->actions[6] != 8)
            return row->actions[6];
        if (row->actions[7] != 8)
            return row->actions[7];
        rowIndex = (rowIndex + 1) & 0xFFFF;
    }
    return 0;
}

/* Choose a positive-weight command from the selected five-entry AI table; the random helper takes
 * the summed weights, not the record pointer. */
// FUN_001DEA90
u8 *btlAISelectWeightedEntry(u8 *action, u32 index)
{
    u8 *node;
    u8 *entry;
    u32 entryIndex;
    u32 weightSum;
    u32 cumulativeWeight;
    u32 candidateIndex;
    s32 randomWeight;
    s32 weight;

    node = iGpffffb3d0 + ((BtlUnit *)(u32)((BtlAction *)action)->unit)->charId * 164;
    weightSum = 0;
    entryIndex = 0;
    node += (index & 0xffff) * 40;
    while ((u16)entryIndex < 5) {
        weightSum = (weightSum + ((BtlAiWeightedCommand *)(node + (entryIndex & 0xffff) * 8 + 0x2c))->weight) & 0xffff;
        entryIndex = (entryIndex + 1) & 0xffff;
    }
    if ((weightSum & 0xffff) == 0)
        return &iGpffffa2a8;
    randomWeight = datCalcRandomBelow(weightSum & 0xffff) & 0xffff;
    cumulativeWeight = 0;
    candidateIndex = 0;
    while ((u16)candidateIndex < 5) {
        entry = node + (candidateIndex & 0xffff) * 8;
        weight = entry[0x2c];
        cumulativeWeight = (cumulativeWeight + weight) & 0xffff;
        if (randomWeight <= (s32)cumulativeWeight && weight > 0)
            return entry + 0x2c;
        candidateIndex = (candidateIndex + 1) & 0xffff;
    }
    return 0;
}
/* Starts the action procedure with priority from KwlnTask's field minus one, sets its message name,
 * and attaches it to the battle task. */
// FUN_001DEBB0
s32 btlAICommandSpawnActionProc(u8 *action, u8 *work, u32 scriptData, u32 procedureId)
{
    u8 procedureName[32];
    u32 procedureValue;
    u32 procedureTask;
    u32 speakerName;
    u32 procedureWork;
    BtlAction *actionRecord = (BtlAction *)action;
    ScrContext *procedureContext;
    /* ScrContext supplies the message-window manager for the procedure. */
    if (((BtlUnit *)((u32)((BtlAction *)action)->unit))->genus == 0) {
        procedureValue = (u8)((DatUnit *)((u32)((BtlUnit *)((u32)((BtlAction *)action)->unit))->datUnit))->aiTactic;
        sprintf(procedureName, D_00609E20, procedureId, procedureValue);
        procedureValue = scrFindPrcdIdxByName(scriptData, procedureName);
    } else {
        procedureValue = procedureId;
    }
    procedureTask = scrStartProcedureIndex((u8 *)((u32)((struct KwlnTask *)((u32)((BtlBattleState *)(iGpffffb3ac))->cutinTaskParent))->unk20Value - 1), scriptData, procedureValue);
    scrSetTaskProc(procedureTask, action);
    procedureWork = (u32)kwlnTaskGetWork(procedureTask);
    procedureContext = (ScrContext *)procedureWork;
    if (((ScrContext *)procedureWork)->messageManager >= 0) {
        switch (actionRecord->unit->genus) {
        case 0:
            speakerName = (u32)datPersonaNamePart1Alt((s16)actionRecord->unit->charId);
            break;
        case 1:
            speakerName = (u32)iGpffffb444 + actionRecord->unit->charId * 21;
            break;
        }
        itfMesWindowSetString(procedureContext->messageManager, 0, speakerName);
    }
    kwlnTaskAddChild((u8 *)((u32)((BtlBattleState *)(iGpffffb3ac))->cutinTaskParent), procedureTask);
    ((BtlAiCommandWork *)work)->procedureTask = procedureTask;
    return 1;
}
/* Matches P3FES func_002c70d0 (action dispatch, switch type 0/1). func_001de800 is declared locally
 * as u32 so the &0xFFFF mask does not fold to 0xff. Use an explicit AI procedure when present,
 * otherwise decode a weighted table command. */
// FUN_001DED30
void btlAICommandSetUnitAction(s32 action, s32 work)
{
    u8 genus;
    u16 baseActionId;
    u16 actionId;
    s32 weightedCommand;
    u32 packedCondition;
    u32 scriptData;
    u32 conditionResult;

    baseActionId = ((BtlUnit *)((s32)((BtlAction *)action)->unit))->charId;
    btlTargetResetCommandRecord((u8 *)work);
    genus = ((BtlUnit *)(MEMBER(s32, action, BtlAction, unit)))->genus;
    switch (genus) {
    case 0:
        actionId = baseActionId;
        scriptData = (u32)iGpffffb428;
        break;
    case 1:
        {
            u8 *aiRecord;
            u32 recordOffset;

            /* measured: the integer-domain address spelling makes retail's early load of the AI
             * record base reproduce. */
            aiRecord = ((u8 **)((u32)&iGpffffb3d0))[0];
            recordOffset = ((u32)baseActionId * 0x28 + (u32)baseActionId) * 4;
            aiRecord = (u8 *)(recordOffset) + (s32)aiRecord;
            actionId = ((BtlAiRecord *)aiRecord)->procedure;
            scriptData = (u32)iGpffffb42c;
        }
        break;
    }
    if (actionId > 0) {
        btlAICommandSpawnActionProc((u8 *)action, (u8 *)work, scriptData, actionId);
        ((BtlAiCommandWork *)work)->procedureActive = 1;
    }
    else {
        extern u32 btlAICommandPickTableAction(u8 *);
        actionId = btlAICommandPickTableAction((u8 *)action) & 0xFFFF;
        weightedCommand = (s32)btlAISelectWeightedEntry((u8 *)action, actionId);
        btlAICommandSetActionCode((u8 *)action, (u8 *)work, ((BtlAiWeightedCommand *)weightedCommand)->command);
        packedCondition = ((BtlAiWeightedCommand *)weightedCommand)->targetCondition;
        conditionResult = ((s32 (*)(u8 *, u32))D_00609CE0[((packedCondition & 0xff000000) >> 0x18) * 2])((u8 *)action, packedCondition & 0xffffff);
        if (conditionResult == 0) {
            ((s32 (*)(u8 *, u32))D_00609CE0[0])((u8 *)action, 0);
        }
    }
}


/* Clear the procedure-active flag and task handle after the task is no longer linked. */
// FUN_001DEEE0
u32 btlAICommandTryReleaseProc(s32 work)
{
  u32 released = 0;
  long taskLinked = 0;
  BtlAiCommandWork *commandWork = (BtlAiCommandWork *)work;

  if (((BtlAiCommandWork *)work)->procedureActive == 0) {
    released = 1;
  }
  else if ((s32)((BtlAiCommandWork *)work)->procedureTask == 0) {
    released = 1;
  }
  else {
    taskLinked = kwlnTaskIsLinked((s32)((BtlAiCommandWork *)work)->procedureTask);
    if (taskLinked == 0) {
      commandWork->procedureActive = 0;
      commandWork->procedureTask = 0;
      released = 1;
    }
    else {
      released = 0;
    }
  }
  return released;
}


/* Set the current AI state's action to the default action code 0x8000. Always returns 1. */
// FUN_001DEF60
u32 btlAICommandScriptSetDefaultAction(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *action = (char *)scrGetAiState();

  btlAICommandSetActionCode(action, action + 0x38, 0x8000);
  return 1;
}


/* Set the AI action code from the first script parameter. Zero picks the default 0x8000, a negative
 * value picks 0x8002, and a positive value is used as-is. */
// FUN_001DEFA0
s32 btlAICommandScriptSetActionParam(void) {
    u8 *action = scrGetAiState();
    s32 actionCode = scrGetParamInt(0);
    if (actionCode == 0)
        btlAICommandSetActionCode(action, action + 0x38, 0x8000);
    else if (actionCode > 0)
        btlAICommandSetActionCode(action, action + 0x38, (u16)actionCode);
    else
        btlAICommandSetActionCode(action, action + 0x38, 0x8002);
    return 1;
}

/* Make the AI action use the skill given by the first script parameter and record its underlying
 * skill ID. A negative ID sets action code 0x8002 instead. */
// FUN_001DF040
s32 btlAICommandScriptSetSkillAction(void) {
    u8 *action = scrGetAiState();
    s32 skillId = scrGetParamInt(0);
    if (skillId >= 0) {
        ((BtlAction *)action)->unk_6c = 3;
        ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->skill = skillId;
        ((BtlAction *)action)->unk_6e = datCalcUnderlyingSkillId((u16)skillId);
    } else {
        btlAICommandSetActionCode(action, action + 0x38, 0x8002);
    }
    return 1;
}

/* AI script command: set the current AI state's action code to 0x8001. */
// FUN_001DF0C0
u32 btlAICommandScriptSetAction8001(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *action = 0;

  action = (char *)scrGetAiState();
  btlAICommandSetActionCode(action, action + 0x38, 0x8001);
  return 1;
}


/* AI script command: set the current AI state's action code to 0x8002. */
// FUN_001DF100
u32 btlAICommandScriptSetAction8002(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *action = 0;

  action = (char *)scrGetAiState();
  btlAICommandSetActionCode(action, action + 0x38, 0x8002);
  return 1;
}


/* AI script command: store the integer parameter as a subword in the action's target block, then
 * set the action code to 0x8002. */
// FUN_001DF140
s32 btlAICommandScriptSetActionSubword(void) {
    u8 *action = scrGetAiState();
    ((u16 *)((BtlAction *)action)->targetBlock.unk_e8)[2] = scrGetParamInt(0);
    btlAICommandSetActionCode(action, action + 0x38, 0x8002);
    return 1;
}

/* AI script command: set the AI command work's plan from the integer parameter and mark the action
 * type. Then run the first plan handler and fall back to the second if the first fails. */
// FUN_001DF1A0
s32 btlAICommandScriptSetAiPlan(void) {
    u8 *action = scrGetAiState();
    ((BtlAction *)action)->unk_6c = 9;
    ((BtlAction *)action)->unk_6e = 0x111;
    ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->plan = scrGetParamInt(0);
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Set the AI action to plan 9/0x111 with the two script parameters as summon IDs, then run the plan
 * handler and fall back to the default handler if it fails. Always returns 1. */
// FUN_001DF230
s32 btlAICommandScriptSetAiPlanWithArg(void) {
    u8 *action = scrGetAiState();
    ((BtlAction *)action)->unk_6c = 9;
    ((BtlAction *)action)->unk_6e = 0x111;
    ((BtlAction *)action)->parameters.summonIds[0] = scrGetParamInt(0);
    ((BtlAction *)action)->parameters.summonIds[1] = scrGetParamInt(1);
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: set the current AI state's action code to 0x8007. */
// FUN_001DF2D0
u32 btlAICommandScriptSetAction8007(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *action = 0;

  action = (char *)scrGetAiState();
  btlAICommandSetActionCode(action, action + 0x38, 0x8007);
  return 1;
}


/* Evaluate the acting unit's own-HP condition using the script's threshold parameter and return
 * whether it holds to the script. */
// FUN_001DF310
s32 btlAICommandScriptQueryMyHp(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x1000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the acting unit's own-MP condition using the script's threshold parameter and return
 * whether it holds to the script. */
// FUN_001DF3C0
s32 btlAICommandScriptQueryMyMp(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x2000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate an ally-HP condition using the script's threshold parameter and return whether it holds
 * to the script. */
// FUN_001DF470
s32 btlAICommandScriptQueryFrHp(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x3000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate an enemy-HP condition using the script's threshold parameter and return whether it holds
 * to the script. */
// FUN_001DF520
s32 btlAICommandScriptQueryEnHp(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x4000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the alternate enemy-HP condition using the script's threshold parameter and return
 * whether it holds to the script. */
// FUN_001DF5D0
s32 btlAICommandScriptQueryEnHpO(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x5000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: evaluate condition kind 6 (own level check) against the script parameter for
 * the current AI state and return whether it holds. */
// FUN_001DF680
s32 btlAICommandScriptQueryMyLvO(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x6000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: evaluate condition kind 7 (ally level check) against the script parameter for
 * the current AI state and return whether it holds. */
// FUN_001DF730
s32 btlAICommandScriptQueryFrLvO(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x7000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: evaluate condition kind 8 (enemy level check) against the script parameter for
 * the current AI state and return whether it holds. */
// FUN_001DF7E0
s32 btlAICommandScriptQueryEnLvO(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x8000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: evaluate condition kind 9 (ally count check) against the script parameter for
 * the current AI state and return whether it holds. */
// FUN_001DF890
s32 btlAICommandScriptQueryFrCnt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x9000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: evaluate condition kind 10 (enemy count check) against the script parameter
 * for the current AI state and return whether it holds. */
// FUN_001DF940
s32 btlAICommandScriptQueryEnCnt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0xA000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the AI's own-bad-status condition (kind 0xB) on the script parameter and return whether
 * it holds. */
// FUN_001DF9F0
s32 btlAICommandScriptQueryMyBad(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0xB000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the ally-bad-status condition (kind 0xC) on the script parameter and return whether it
 * holds. */
// FUN_001DFAA0
s32 btlAICommandScriptQueryFrBad(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0xC000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the enemy-bad-status condition (kind 0xD) on the script parameter and return whether it
 * holds. */
// FUN_001DFB50
s32 btlAICommandScriptQueryEnBad(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0xD000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the all-enemies-bad-status condition (kind 0xE) on the script parameter and return
 * whether it holds. */
// FUN_001DFC00
s32 btlAICommandScriptQueryEnBadAll(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0xE000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the ally-ID condition (kind 0xF) on the script parameter and return whether it holds. */
// FUN_001DFCB0
s32 btlAICommandScriptQueryFrId(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0xF000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the enemy-ID condition check on the script's integer parameter for the current AI state, and
 * return true or false to the script. */
// FUN_001DFD60
s32 btlAICommandScriptQueryEnId(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x10000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the ally support-effect (hojo) condition check on the script's integer parameter for the
 * current AI state, and return true or false to the script. */
// FUN_001DFE10
s32 btlAICommandScriptQueryFrHojo(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x11000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the enemy support-effect (hojo) condition check on the script's integer parameter for the
 * current AI state, and return true or false to the script. */
// FUN_001DFEC0
s32 btlAICommandScriptQueryEnHojo(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x12000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

// FUN_001DFF70
s32 btlAICommandScriptQueryEscape(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609934[0])(scrGetAiState(), 0) != 0);
    return 1;
}

// FUN_001DFFC0
s32 btlAICommandScriptQuerySummon(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609940[0])(scrGetAiState(), 0) != 0);
    return 1;
}

// FUN_001E0010
s32 btlAICommandScriptQuerySensei(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_0060994C[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* Run the self reflect (hansya) condition check on the script's integer parameter for the current
 * AI state, and return true or false to the script. */
// FUN_001E0060
s32 btlAICommandScriptQueryMyHansya(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x16000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the self absorb (kyusyu) condition check on the script's integer parameter for the current AI
 * state, and return true or false to the script. */
// FUN_001E0110
s32 btlAICommandScriptQueryMyKyusyu(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x17000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether the acting unit nullifies the element given by the script
 * parameter, and return the result as a boolean. */
// FUN_001E01C0
s32 btlAICommandScriptQueryMyMukou(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x18000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether the acting unit is weak to the element given by the script
 * parameter, and return the result as a boolean. */
// FUN_001E0270
s32 btlAICommandScriptQueryMyWeak(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x19000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether an ally reflects the element given by the script parameter, and
 * return the result as a boolean. */
// FUN_001E0320
s32 btlAICommandScriptQueryFrHansya(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x1A000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether an enemy reflects the element given by the script parameter, and
 * return the result as a boolean. */
// FUN_001E03D0
s32 btlAICommandScriptQueryEnHansya(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x1B000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether an ally absorbs the element given by the script parameter, and
 * return the result as a boolean. */
// FUN_001E0480
s32 btlAICommandScriptQueryFrKyusyu(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x1C000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the enemy-absorbs (kyusyu) AI condition against the first script parameter and return
 * whether it holds to the script. */
// FUN_001E0530
s32 btlAICommandScriptQueryEnKyusyu(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x1D000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the ally-nullifies (mukou) AI condition against the first script parameter and return
 * whether it holds to the script. */
// FUN_001E05E0
s32 btlAICommandScriptQueryFrMukou(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x1E000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the enemy-nullifies (mukou) AI condition against the first script parameter and return
 * whether it holds to the script. */
// FUN_001E0690
s32 btlAICommandScriptQueryEnMukou(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x1F000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the ally-weakness AI condition against the first script parameter and return whether it
 * holds to the script. */
// FUN_001E0740
s32 btlAICommandScriptQueryFrWeak(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x20000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the enemy-weakness AI condition against the first script parameter and return whether it
 * holds to the script. */
// FUN_001E07F0
s32 btlAICommandScriptQueryEnWeak(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x21000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether this unit has used an attack of the given attribute, by running
 * the condition-table check, and return the result to the script. */
// FUN_001E08A0
s32 btlAICommandScriptQueryMyUseAttr(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x22000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether an ally has used an attack of the given attribute, by running the
 * condition-table check, and return the result to the script. */
// FUN_001E0950
s32 btlAICommandScriptQueryFrUseAttr(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x23000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether an enemy has used an attack of the given attribute, by running
 * the condition-table check, and return the result to the script. */
// FUN_001E0A00
s32 btlAICommandScriptQueryEnUseAttr(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x24000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether this unit has used the given skill, by running the condition-
 * table check, and return the result to the script. */
// FUN_001E0AB0
s32 btlAICommandScriptQueryMyUseSkil(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x25000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether an ally has used the given skill, by running the condition-table
 * check, and return the result to the script. */
// FUN_001E0B60
s32 btlAICommandScriptQueryFrUseSkil(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x26000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether an enemy has used the skill given by the script parameter, and
 * return the result as a boolean. */
// FUN_001E0C10
s32 btlAICommandScriptQueryEnUseSkil(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x27000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

// FUN_001E0CC0
s32 btlAICommandScriptQueryMyGroup(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A30[0])(scrGetAiState(), 0) != 0);
    return 1;
}

// FUN_001E0D10
s32 btlAICommandScriptQueryFrGroup(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A3C[0])(scrGetAiState(), 0) != 0);
    return 1;
}

// FUN_001E0D60
s32 btlAICommandScriptQueryEnGroup(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A48[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command: run the turn-count condition on the script parameter for the current AI state,
 * and return the result as a boolean. */
// FUN_001E0DB0
s32 btlAICommandScriptQueryTurn(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x2B000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: run the alternate turn condition on the script parameter for the current AI
 * state, and return the result as a boolean. */
// FUN_001E0E60
s32 btlAICommandScriptQueryTurnO(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x2C000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

// FUN_001E0F10
s32 btlAICommandScriptQueryMyHrec(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A6C[0])(scrGetAiState(), 0) != 0);
    return 1;
}

// FUN_001E0F60
s32 btlAICommandScriptQueryMore(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A78[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command: test whether an ally has the reflect status given by the script parameter, and
 * return the result as a boolean. */
// FUN_001E0FB0
s32 btlAICommandScriptQueryFrHansyaSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x2F000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: test whether an enemy has the reflect status given by the script parameter,
 * and return the result as a boolean. */
// FUN_001E1060
s32 btlAICommandScriptQueryEnHansyaSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x30000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition check for allies that absorb the given element (Kyusyu), using the script
 * parameter. Return the true/false result to the script. */
// FUN_001E1110
s32 btlAICommandScriptQueryFrKyusyuSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x31000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition check for enemies that absorb the given element (Kyusyu), using the script
 * parameter. Return the true/false result to the script. */
// FUN_001E11C0
s32 btlAICommandScriptQueryEnKyusyuSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x32000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition check for allies that nullify the given element (Mukou), using the script
 * parameter. Return the true/false result to the script. */
// FUN_001E1270
s32 btlAICommandScriptQueryFrMukouSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x33000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition check for enemies that nullify the given element (Mukou), using the script
 * parameter. Return the true/false result to the script. */
// FUN_001E1320
s32 btlAICommandScriptQueryEnMukouSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x34000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition check for allies weak to the given element, using the script parameter.
 * Return the true/false result to the script. */
// FUN_001E13D0
s32 btlAICommandScriptQueryFrWeakSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x35000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the enemy-weak-status condition for the given parameter through the AI condition table
 * and return whether it holds. */
// FUN_001E1480
s32 btlAICommandScriptQueryEnWeakSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x36000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Find the unit with the given ID on the caller's side and set the script return value to whether
 * its HP satisfies the condition in parameter 1. */
// FUN_001E1530
u32 btlAICommandSideIdQueryMyHp(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x01000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Find the unit with the given ID on the caller's side and set the script return value to whether
 * its MP satisfies the condition in parameter 1. */
// FUN_001E1620
u32 btlAICommandSideIdQueryMyMp(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x02000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Find the unit with the given ID on the caller's side and set the script return value to whether
 * it passes the type-6 (level) check in parameter 1. */
// FUN_001E1710
u32 btlAICommandSideIdQueryMyLvO(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x06000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002c9ba0. */
/* Find the unit with the given ID on the caller's side and set the script return value to whether
 * it has the bad status given in parameter 1. If parameter 1 has bit 0x80000 set, the unit lookup
 * skips the status filter. */
// FUN_001E1800
u32 btlAICommandSideIdQueryMyBad(void)
{
    u16 id;
    u8 *unit;
    u32 argument;
    u32 sideMask;
    u8 *context;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    argument = scrGetParamInt(1);
    unit = scrGetAiState();
    sideMask = 1 << (((BtlAction *)unit))->unit->genus & 0xffff;
    if ((argument & 0x80000) != 0) {
        id = scrGetParamInt(0);
        context = (u8 *)btlEffectFindUnitByIdAndStatus(id, sideMask, 0);
    } else {
        id = scrGetParamInt(0);
        context = (u8 *)btlEffectFindUnitByIdAndStatus(id, sideMask, 0x80000);
    }
    if (context != 0) {
        dispatchType = (((argument & 0xffffff) | 0x0b000000) & 0xff000000) >> 24;
        payload = (argument | 0x0b000000) & 0xffffff;
        if (dispatchType == 0)
            dispatchResult = 0;
        else
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}

/* Find the unit with the given ID on the acting unit's own side and return whether it has any of
 * the buffs in the given mask. */
// FUN_001E1940
s32 btlAICommandSideIdQueryHasBuff(void) {
    u8 *action = scrGetAiState();
    u32 *targetAction = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << ((((BtlAction *)action))->unit->genus)) & 0xFFFF, 0x80000);
    s32 queryResult;
    if (targetAction != 0)
        queryResult = datCalcHasBuffMask((((BtlAction *)(targetAction)))->unit->datUnit, scrGetParamInt(1));
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* AI command: find the unit with the given id on the caller's side and return whether it reflects
 * (hansya) the attribute given in param 1. */
// FUN_001E19F0
u32 btlAICommandSideIdQueryMyHansya(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x16000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* AI command: find the unit with the given id on the caller's side and return whether it absorbs
 * (kyusyu) the attribute given in param 1. */
// FUN_001E1AE0
u32 btlAICommandSideIdQueryMyKyusyu(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x17000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* AI command: find the unit with the given id on the caller's side and return whether it nullifies
 * (mukou) the attribute given in param 1. */
// FUN_001E1BD0
u32 btlAICommandSideIdQueryMyMukou(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x18000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* AI command: find the unit with the given id on the caller's side and return whether it is weak to
 * the attribute given in param 1. */
// FUN_001E1CC0
u32 btlAICommandSideIdQueryMyWeak(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x19000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* AI command: find the unit with the given id on the caller's side and return whether it can use
 * the attribute given in param 1. */
// FUN_001E1DB0
u32 btlAICommandSideIdQueryMyUseAttr(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x22000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Find the unit with the given id on the caller's own side and return whether it passes the use-
 * skill condition check named by the second parameter. */
// FUN_001E1EA0
u32 btlAICommandSideIdQueryMyUseSkil(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x25000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Find the unit with the given ID on the acting unit's own side and return the result of the my-
 * group condition check on it. */
// FUN_001E1F90
s32 btlAICommandSideIdQueryMyGroup(void) {
    u8 *action = scrGetAiState();
    u32 *targetAction = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << ((((BtlAction *)action))->unit->genus)) & 0xFFFF, 0x80000);
    s32 queryResult;
    if (targetAction != 0)
        queryResult = ((s32 (*)(u8 *, s32))D_00609A30[0])((u8 *)targetAction, 0);
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* Find the unit with the given ID on the acting unit's own side and return the result of the my-
 * hrec condition check on it. */
// FUN_001E2030
s32 btlAICommandSideIdQueryMyHrec(void) {
    u8 *action = scrGetAiState();
    u32 *targetAction = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << ((((BtlAction *)action))->unit->genus)) & 0xFFFF, 0x80000);
    s32 queryResult;
    if (targetAction != 0)
        queryResult = ((s32 (*)(u8 *, s32))D_00609A6C[0])((u8 *)targetAction, 0);
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* Matches P3FES func_002ca480. */
/* Find the unit with the given id on the side opposite the caller and return whether its HP passes
 * the condition named by the second parameter. */
// FUN_001E20D0
u32 btlAICommandOppSideIdQueryMyHp(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x01000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002ca590; uses selector tag 0x02000000. */
// FUN_001E21E0
u32 btlAICommandOppSideIdQueryMyMp(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x02000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002ca6a0; same mapping as FUN_001E20D0. */
// FUN_001E22F0
u32 btlAICommandOppSideIdQueryMyLvO(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x06000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002ca7b0; dispatches on the argument side mask with selector tag 0x0b000000. */
// FUN_001E2400
u32 btlAICommandOppSideIdQueryMyBad(void)
{
    u16 id;
    u8 *unit;
    u32 argument;
    u32 sideMask;
    u32 shift;
    u8 *context;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    argument = scrGetParamInt(1);
    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    sideMask = 1 << shift & 0xffff;
    if ((argument & 0x80000) != 0) {
        id = scrGetParamInt(0);
        context = (u8 *)btlEffectFindUnitByIdAndStatus(id, sideMask, 0);
    } else {
        id = scrGetParamInt(0);
        context = (u8 *)btlEffectFindUnitByIdAndStatus(id, sideMask, 0x80000);
    }
    if (context != 0) {
        dispatchType = (((argument & 0xffffff) | 0x0b000000) & 0xff000000) >> 24;
        payload = (argument | 0x0b000000) & 0xffffff;
        if (dispatchType == 0)
            dispatchResult = 0;
        else
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Returns true only when every living matching ally has the requested status. */
// FUN_001E2550
s32 btlAICommandSideIdQueryAllBadStatus(void) {
    u32 statusMask;
    u32 sideMask;
    u32 unitId;
    u32 selector;
    u32 unitValue;
    u8 *candidateAction;
    s32 livingCount;
    s32 matchingCount;
    u8 *unit;
    u32 allMatch;
    BtlUnit *matchingUnit;

    selector = (1 << (((BtlUnit *)((u32)((BtlAction *)(scrGetAiState()))->unit))->genus)) & 0xFFFF;
    unitValue = scrGetParamInt(0) & 0xFFFF;
    statusMask = scrGetParamInt(1);
    livingCount = 0;
    matchingCount = 0;
    candidateAction = (u8 *)((BtlBattleState *)(iGpffffb3ac))->actions;
    sideMask = selector & 0xFFFF;
    unitId = unitValue & 0xFFFF;
    while (candidateAction != 0) {
        if ((((BtlAction *)candidateAction)->unk_1a & 1) && (((BtlAction *)candidateAction)->unk_1a & 8)) {
            unit = (u8 *)((BtlAction *)candidateAction)->unit;
            matchingUnit = (BtlUnit *)unit;
            if ((sideMask & (1 << (((BtlUnit *)unit)->genus))) != 0) {
                if (((BtlUnit *)unit)->charId == unitId) {
                    if (datCalcIsDead((u32)((BtlUnit *)unit)->datUnit, 0) == 0) {
                        livingCount = (livingCount + 1) & 0xFFFF;
                        if (datCalcChkBadStatus((u32)matchingUnit->datUnit, statusMask) != 0) {
                            matchingCount = (matchingCount + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        candidateAction = (u8 *)((BtlAction *)candidateAction)->next;
    }
    allMatch = 0;
    if ((livingCount & 0xFFFF) > 0 && (livingCount & 0xFFFF) == (matchingCount & 0xFFFF))
        allMatch = 1;
    scrSetReturnInt(allMatch != 0);
    return 1;
}

/* Requires the requested status on every living matching unit of the opposite side. */
// FUN_001E26C0
/* measured: retail keeps the shift selection as branches, so conditional rebuilding stays off. */
s32 btlAICommandOppSideIdQueryAllBadStatus(void)
{
    u32 shift;
    u32 statusMask;
    u32 sideMask;
    u32 selector;
    u8 *unitValue;
    u8 *candidateAction;
    s32 livingCount;
    s32 matchingCount;
    u32 allMatch;
    BtlUnit *matchingUnit;

    if (((BtlUnit *)((u8 *)((BtlAction *)(scrGetAiState()))->unit))->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    selector = (1 << (shift & 0xffff)) & 0xffff;
    unitValue = (u8 *)(scrGetParamInt(0) & 0xffff);
    statusMask = scrGetParamInt(1);
    livingCount = 0;
    matchingCount = 0;
    candidateAction = (u8 *)((BtlBattleState *)(iGpffffb3ac))->actions;
    sideMask = selector & 0xffff;
    selector = (u32)unitValue & 0xffff;
    while (candidateAction != 0) {
        if ((((BtlAction *)candidateAction)->unk_1a & 1) && (((BtlAction *)candidateAction)->unk_1a & 8)) {
            unitValue = (u8 *)((BtlAction *)candidateAction)->unit;
            matchingUnit = (BtlUnit *)unitValue;
            if ((sideMask & (1 << (((BtlUnit *)unitValue)->genus))) != 0) {
                if (((BtlUnit *)unitValue)->charId == selector) {
                    if (datCalcIsDead((u32)((BtlUnit *)unitValue)->datUnit, 0) == 0) {
                        livingCount = (livingCount + 1) & 0xffff;
                        if (datCalcChkBadStatus((u32)matchingUnit->datUnit, statusMask) != 0)
                            matchingCount = (matchingCount + 1) & 0xffff;
                    }
                }
            }
        }
        candidateAction = (u8 *)((BtlAction *)candidateAction)->next;
    }
    allMatch = 0;
    if ((livingCount & 0xffff) > 0 && (livingCount & 0xffff) == (matchingCount & 0xffff))
        allMatch = 1;
    scrSetReturnInt(allMatch != 0);
    return 1;
}

/* Find the unit with the given ID on the side opposing the acting unit and return whether it has
 * any of the buffs in the given mask. */
// FUN_001E2850
s32 btlAICommandOppSideIdQueryHasBuff(void) {
    u32 shift;
    u32 *targetAction;
    s32 queryResult;
    {
        if ((((BtlAction *)(scrGetAiState())))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    targetAction = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (targetAction != 0)
        queryResult = datCalcHasBuffMask((((BtlAction *)(targetAction)))->unit->datUnit, scrGetParamInt(1));
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* Requires a matching buff on every living ally with the requested unit id. */
// FUN_001E2910
s32 btlAICommandSideIdQueryAllHasBuff(void) {
    u32 statusMask;
    u32 sideMask;
    u32 unitId;
    u32 selector;
    u32 unitValue;
    u8 *candidateAction;
    s32 livingCount;
    s32 matchingCount;
    u8 *unit;
    u32 allMatch;
    BtlUnit *matchingUnit;

    selector = (1 << (((BtlUnit *)((u32)((BtlAction *)(scrGetAiState()))->unit))->genus)) & 0xFFFF;
    unitValue = scrGetParamInt(0) & 0xFFFF;
    statusMask = scrGetParamInt(1);
    livingCount = 0;
    matchingCount = 0;
    candidateAction = (u8 *)((BtlBattleState *)(iGpffffb3ac))->actions;
    sideMask = selector & 0xFFFF;
    unitId = unitValue & 0xFFFF;
    while (candidateAction != 0) {
        if ((((BtlAction *)candidateAction)->unk_1a & 1) && (((BtlAction *)candidateAction)->unk_1a & 8)) {
            unit = (u8 *)((BtlAction *)candidateAction)->unit;
            matchingUnit = (BtlUnit *)unit;
            if ((sideMask & (1 << (((BtlUnit *)unit)->genus))) != 0) {
                if (((BtlUnit *)unit)->charId == unitId) {
                    if (datCalcIsDead((u32)((BtlUnit *)unit)->datUnit, 0) == 0) {
                        livingCount = (livingCount + 1) & 0xFFFF;
                        if (datCalcHasBuffMask(matchingUnit->datUnit, statusMask) != 0) {
                            matchingCount = (matchingCount + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        candidateAction = (u8 *)((BtlAction *)candidateAction)->next;
    }
    allMatch = 0;
    if ((livingCount & 0xFFFF) > 0 && (livingCount & 0xFFFF) == (matchingCount & 0xFFFF))
        allMatch = 1;
    scrSetReturnInt(allMatch != 0);
    return 1;
}

/* Requires a matching buff on every living opponent with the requested unit id. Sibling of
 * FUN_001E26C0. */
// FUN_001E2A80
s32 btlAICommandOppSideIdQueryAllHasBuff(void)
{
    u32 shift;
    u32 statusMask;
    u32 sideMask;
    u32 selector;
    u8 *unitValue;
    u8 *candidateAction;
    s32 livingCount;
    s32 matchingCount;
    u32 allMatch;
    BtlUnit *matchingUnit;

    if (((BtlUnit *)((u8 *)((BtlAction *)(scrGetAiState()))->unit))->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    selector = (1 << (shift & 0xffff)) & 0xffff;
    unitValue = (u8 *)(scrGetParamInt(0) & 0xffff);
    statusMask = scrGetParamInt(1);
    livingCount = 0;
    matchingCount = 0;
    candidateAction = (u8 *)((BtlBattleState *)(iGpffffb3ac))->actions;
    sideMask = selector & 0xffff;
    selector = (u32)unitValue & 0xffff;
    while (candidateAction != 0) {
        if ((((BtlAction *)candidateAction)->unk_1a & 1) && (((BtlAction *)candidateAction)->unk_1a & 8)) {
            unitValue = (u8 *)((BtlAction *)candidateAction)->unit;
            matchingUnit = (BtlUnit *)unitValue;
            if ((sideMask & (1 << (((BtlUnit *)unitValue)->genus))) != 0) {
                if (((BtlUnit *)unitValue)->charId == selector) {
                    if (datCalcIsDead((u32)((BtlUnit *)unitValue)->datUnit, 0) == 0) {
                        livingCount = (livingCount + 1) & 0xffff;
                        if (datCalcHasBuffMask(matchingUnit->datUnit, statusMask) != 0)
                            matchingCount = (matchingCount + 1) & 0xffff;
                    }
                }
            }
        }
        candidateAction = (u8 *)((BtlAction *)candidateAction)->next;
    }
    allMatch = 0;
    if ((livingCount & 0xffff) > 0 && (livingCount & 0xffff) == (matchingCount & 0xffff))
        allMatch = 1;
    scrSetReturnInt(allMatch != 0);
    return 1;
}

/* Matches P3FES func_002ca9d0. */
/* Find the unit with the given id on the side opposite the caller and return whether it passes the
 * reflect (hansya) condition named by the second parameter. */
// FUN_001E2C10
u32 btlAICommandOppSideIdQueryMyHansya(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x16000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002caae0; selector tag 0x17000000. */
// FUN_001E2D20
u32 btlAICommandOppSideIdQueryMyKyusyu(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x17000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002cabf0; selector tag 0x18000000. */
// FUN_001E2E30
u32 btlAICommandOppSideIdQueryMyMukou(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x18000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002cad00; selector tag 0x19000000. */
// FUN_001E2F40
u32 btlAICommandOppSideIdQueryMyWeak(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x19000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002cae10; selector tag 0x22000000. */
// FUN_001E3050
u32 btlAICommandOppSideIdQueryMyUseAttr(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x22000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Matches P3FES func_002caf20; selector tag 0x25000000. */
// FUN_001E3160
u32 btlAICommandOppSideIdQueryMyUseSkil(void)
{
    u8 *unit;
    u16 id;
    u32 shift;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    if ((((BtlAction *)unit))->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << shift & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x25000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* AI script command: find the opposing-side unit with the ID given in param 0 and return whether
 * its group query holds against the acting unit. */
// FUN_001E3270

// FUNC_001E3270
s32 btlAICommandOppSideIdQueryMyGroup(void) {
    u32 shift;
    u32 *targetAction;
    s32 queryResult;
    {
        if ((((BtlAction *)(scrGetAiState())))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    targetAction = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (targetAction != 0)
        queryResult = ((s32 (*)(u8 *, s32))D_00609A30[0])((u8 *)targetAction, 0);
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* AI script command: find the opposing-side unit with the ID given in param 0 and return whether
 * its hit-record query holds against the acting unit. */
// FUN_001E3320

// FUNC_001E3320
s32 btlAICommandOppSideIdQueryMyHrec(void) {
    u32 shift;
    u32 *targetAction;
    s32 queryResult;
    {
        if ((((BtlAction *)(scrGetAiState())))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    targetAction = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (targetAction != 0)
        queryResult = ((s32 (*)(u8 *, s32))D_00609A6C[0])((u8 *)targetAction, 0);
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* AI script command: return whether the acting unit is on the side given in param 0 and has the
 * character ID given in param 1. */
// FUN_001E33D0
s32 btlAICommandScriptUnitIsIdOnSide(void) {
    u8 *action = scrGetAiState();
    u32 a = scrGetParamInt(0) & 0xFFFF;
    u32 unitId = scrGetParamInt(1) & 0xFFFF;
    u32 matches = 1;
    switch (a & 0xFFFF) {
    case 0:
        if ((((BtlAction *)action))->unit->genus != 0)
            matches = 0;
        break;
    case 1:
        if ((((BtlAction *)action))->unit->genus != 1)
            matches = 0;
        break;
    default:
        break;
    }
    if (matches == 1 && (((BtlAction *)action))->unit->charId != (unitId & 0xFFFF))
        matches = 0;
    scrSetReturnInt(matches != 0);
    return 1;
}

/* AI script command: evaluate the friendly-side all-HP condition with the value from param 0 and
 * return the result as a boolean. */
// FUN_001E34B0
s32 btlAICommandScriptQueryFrAllHp(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x38000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* AI script command: evaluate the enemy-side all-HP condition with the value from param 0 and
 * return the result as a boolean. */
// FUN_001E3560
s32 btlAICommandScriptQueryEnAllHp(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x39000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition that checks whether the acting unit has a usable skill matching the script
 * parameter, and return 1 or 0 to the script. */
// FUN_001E3610
s32 btlAICommandScriptQueryMyAbleSkil(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x3A000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition that checks for an enemy weakness matching the script parameter, and return
 * 1 or 0 to the script. */
// FUN_001E36C0
s32 btlAICommandScriptQueryEnWeakPai(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x3B000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition that checks for an enemy weakness to a status effect matching the script
 * parameter, and return 1 or 0 to the script. */
// FUN_001E3770
s32 btlAICommandScriptQueryEnWeakStPai(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x3C000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition that checks for an enemy weakness to a debuff matching the script parameter,
 * and return 1 or 0 to the script. */
// FUN_001E3820
s32 btlAICommandScriptQueryEnWeakDwPai(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x3D000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the AI condition that checks whether the acting unit has a skill of the element given by the
 * script parameter, and return 1 or 0 to the script. */
// FUN_001E38D0
s32 btlAICommandScriptQueryMyAttrSkil(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x3E000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the AI's "my normal" condition against the script parameter and return whether it holds
 * to the script. */
// FUN_001E3980
s32 btlAICommandScriptQueryMyNomal(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x3F000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the AI's "enemy normal" condition against the script parameter and return whether it
 * holds to the script. */
// FUN_001E3A30
s32 btlAICommandScriptQueryEnNomal(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x40000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the AI's "enemy normal status" condition against the script parameter and return whether
 * it holds to the script. */
// FUN_001E3AE0
s32 btlAICommandScriptQueryEnNomalSt(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x41000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the AI's "enemy normal down" condition against the script parameter and return whether
 * it holds to the script. */
// FUN_001E3B90
s32 btlAICommandScriptQueryEnNomalDw(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x42000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

// FUN_001E3C40
s32 btlAICommandScriptQueryAnalyze(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609B74[0])(scrGetAiState(), 0) != 0);
    return 1;
}

// FUN_001E3C90
s32 btlAICommandScriptQueryDown(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609B80[0])(scrGetAiState(), 0) != 0);
    return 1;
}

// FUN_001E3CE0
s32 btlAICommandScriptQuerySlip(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609B8C[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* Evaluate the AI's "enemy over level" condition against the script parameter and return whether it
 * holds to the script. */
// FUN_001E3D30
s32 btlAICommandScriptQueryEnOverlv(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x46000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Matches P3FES func_002cbba0; id is u32 masked to 0xFFFF because btlEffectFindUnitByIdAndStatus
 * takes s32. */
// FUN_001E3DE0
u32 btlAICommandSideSwitchIdQueryMyWeak(void)
{
    u8 *context;
    u16 side;
    u32 id;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    side = scrGetParamInt(0);
    id = scrGetParamInt(1) & 0xFFFF;
    context = 0;
    switch (side) {
    case 0:
        context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1, 0x80000);
        break;
    case 1:
        context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 2, 0x80000);
        break;
    }
    if (context != 0) {
        selector = (scrGetParamInt(2) & 0xffffff) | 0x19000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}

/* AI script command: look up the unit by side and ID and return whether its action is flagged as a
 * critical or weakness hit. */
// FUN_001E3F10
s32 btlScriptIsSideUnitHitFlagged(void) {
    u32 side = scrGetParamInt(0) & 0xFFFF;
    u32 unitId = scrGetParamInt(1) & 0xFFFF;
    u32 *targetAction = 0;
    s32 queryResult;
    switch (side & 0xFFFF) {
    case 0:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 1, 0x80000);
        break;
    case 1:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 2, 0x80000);
        break;
    default:
        break;
    }
    if (targetAction != 0)
        queryResult = (((BtlAction *)(targetAction))->flags & (BTL_ACTION_FLAG_HIT_CRITICAL | BTL_ACTION_FLAG_HIT_WEAK)) != 0;
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* AI script command: look up the unit by side and ID and return whether its action is flagged as a
 * critical hit. */
// FUN_001E3FD0
s32 btlScriptIsSideUnitCriticalFlagged(void) {
    u32 side = scrGetParamInt(0) & 0xFFFF;
    u32 unitId = scrGetParamInt(1) & 0xFFFF;
    u32 *targetAction = 0;
    s32 queryResult;
    switch (side & 0xFFFF) {
    case 0:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 1, 0x80000);
        break;
    case 1:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 2, 0x80000);
        break;
    default:
        break;
    }
    if (targetAction != 0)
        queryResult = (((BtlAction *)(targetAction))->flags & BTL_ACTION_FLAG_HIT_CRITICAL) != 0;
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* AI script command: look up the unit by side and ID and return whether its action is flagged as a
 * weakness hit. */
// FUN_001E4090
s32 btlScriptIsSideUnitWeakFlagged(void) {
    u32 side = scrGetParamInt(0) & 0xFFFF;
    u32 unitId = scrGetParamInt(1) & 0xFFFF;
    u32 *targetAction = 0;
    s32 queryResult;
    switch (side & 0xFFFF) {
    case 0:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 1, 0x80000);
        break;
    case 1:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 2, 0x80000);
        break;
    default:
        break;
    }
    if (targetAction != 0)
        queryResult = (((BtlAction *)(targetAction))->flags & BTL_ACTION_FLAG_HIT_WEAK) != 0;
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* AI script command: look up the unit by side and ID and return whether its action is flagged as
 * knocked down. */
// FUN_001E4150
s32 btlScriptIsSideUnitDownFlagged(void) {
    u32 side = scrGetParamInt(0) & 0xFFFF;
    u32 unitId = scrGetParamInt(1) & 0xFFFF;
    u32 *targetAction = 0;
    s32 queryResult;
    switch (side & 0xFFFF) {
    case 0:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 1, 0x80000);
        break;
    case 1:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 2, 0x80000);
        break;
    default:
        break;
    }
    if (targetAction != 0)
        queryResult = (((BtlAction *)(targetAction))->flags & BTL_ACTION_FLAG_DOWN) != 0;
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* AI script command: look up the unit by side and ID, run the first query handler in D_00609B74 on
 * it, and return whether that handler gave a nonzero result. */
// FUN_001E4210
s32 btlAICommandSideSwitchQueryAnalyze(void) {
    u32 side = scrGetParamInt(0) & 0xFFFF;
    u32 unitId = scrGetParamInt(1) & 0xFFFF;
    u32 *targetAction = 0;
    s32 queryResult;
    switch (side & 0xFFFF) {
    case 0:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 1, 0x80000);
        break;
    case 1:
        targetAction = btlEffectFindUnitByIdAndStatus(unitId, 2, 0x80000);
        break;
    default:
        break;
    }
    if (targetAction != 0)
        queryResult = ((s32 (*)(u8 *, s32))D_00609B74[0])((u8 *)targetAction, 0);
    else
        queryResult = 0;
    scrSetReturnInt(queryResult != 0);
    return 1;
}

/* Find the unit with the given id on the caller's own side and return whether it can use the skill
 * named by the second parameter. */
// FUN_001E42E0
u32 btlAICommandSideIdQueryMyAbleSkil(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x3a000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Return through the script whether the acting unit has any of the buffs in the mask given by the
 * first parameter. */
// FUN_001E43D0
s32 btlAICommandScriptSelfHasBuff(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(datCalcHasBuffMask((((BtlAction *)action))->unit->datUnit, scrGetParamInt(0)) != 0);
    return 1;
}

/* Find the unit with the given id on the caller's own side and return whether it has a skill of the
 * attribute named by the second parameter. */
// FUN_001E4430
u32 btlAICommandSideIdQueryMyAttrSkil(void)
{
    u8 *unit;
    u16 id;
    u8 *context;
    u32 selector;
    u32 dispatchType;
    u32 payload;
    s32 result;
    s32 dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << (((BtlAction *)unit))->unit->genus & 0xffff, 0x80000);
    if (context != 0) {
        selector = (scrGetParamInt(1) & 0xffffff) | 0x3e000000;
        dispatchType = (selector & 0xff000000) >> 24;
        payload = selector & 0xffffff;
        if (dispatchType == 0) {
            dispatchResult = 0;
        } else {
            dispatchResult = ((s32 (*)(u8 *, u32))D_00609850[dispatchType * 3])(context, payload);
        }
        result = dispatchResult;
    } else {
        result = 0;
    }
    scrSetReturnInt(result != 0);
    return 1;
}


/* Return through the script whether the current AI action is in the action queue ahead of the
 * battle's selected action. */
// FUN_001E4520
s32 btlAICommandScriptIsSelfListed(void) {
    u8 *action = scrGetAiState();
    u32 flag = 0;
    u16 i;
    for (i = 1; i < 0xC; i++) {
        u32 r = btlActionGetQueueEntry(i);
        if (r == 0)
            break;
        if (r == (u32)((BtlBattleState *)D_0072449C)->selectedAction)
            break;
        if (r == (u32)action) {
            flag = 1;
            break;
        }
    }
    scrSetReturnInt(flag != 0);
    return 1;
}

// FUN_001E45D0
s32 btlAICommandScriptAlwaysFalse(void) {
    scrSetReturnInt(0);
    return 1;
}

/* Evaluate the self-affinity (taisei) condition from the first parameter through the condition
 * handler table and return the result through the script as a boolean. */
// FUN_001E4600
s32 btlAICommandScriptQueryMyTaisei(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x48000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the ally-affinity (taisei) condition from the first parameter through the condition
 * handler table and return the result through the script as a boolean. */
// FUN_001E46B0
s32 btlAICommandScriptQueryFrTaisei(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x49000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Evaluate the enemy-affinity (taisei) condition from the first parameter through the condition
 * handler table and return the result through the script as a boolean. */
// FUN_001E4760
s32 btlAICommandScriptQueryEnTaisei(void) {
    u32 packedCondition = (scrGetParamInt(0) & 0xFFFFFF) | 0x4A000000;
    u8 *action = scrGetAiState();
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = packedCondition & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Run the default AI target routine on the current AI state, retrying it once if the first call
 * fails. Always returns 1. */
// FUN_001E4810
s32 btlAICommandScriptRunAi(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Try the lowest-HP targeting routine on the current AI state and fall back to the default AI
 * routine if it fails. */
// FUN_001E4880
s32 btlAICommandAiUnlessHpMin(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CE8[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Try the lowest-level targeting routine on the current AI state and fall back to the default AI
 * routine if it fails. */
// FUN_001E48F0
s32 btlAICommandAiUnlessLvMin(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CF0[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Try the highest-MP targeting routine on the current AI state and fall back to the default AI
 * routine if it fails. */
// FUN_001E4960
s32 btlAICommandAiUnlessMpMax(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CF8[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Build a bad-status condition query from the script parameter and dispatch it through the AI
 * routine table, falling back to the default AI routine if the query fails. */
// FUN_001E49D0
s32 btlAICommandCondQueryBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x4000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Run the AI condition handler of type 5 with the script argument against the current AI state, and
 * fall back to the default handler if it fails. */
// FUN_001E4A80
s32 btlAICommandCondQueryNotBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x5000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Select target candidates for the current AI state with the MYID condition, using the unit id and
 * excluded status taken from the script arguments. */
// FUN_001E4B30
s32 btlAICommandScriptPickMyIdFromArgs(void) {
    u32 unitId = scrGetParamInt(0);
    u32 excludedStatus = scrGetParamInt(1);
    btlAICommandSelectCandidates(scrGetAiState(), unitId, excludedStatus, 0, 0, btlCond_MYID);
    return 1;
}

/* Run the AI condition handler of type 6 (id query) with the script argument against the current AI
 * state, and fall back to the default handler if it fails. */
// FUN_001E4BB0
s32 btlAICommandCondQueryId(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x6000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Run the "mine" AI condition handler on the current AI state, and fall back to the default handler
 * if it fails. */
// FUN_001E4C60
s32 btlAICommandAiUnlessMine(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D18[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Run the "my AI" condition handler on the current AI state, and fall back to the default handler
 * if it fails. */
// FUN_001E4CD0
s32 btlAICommandAiUnlessMyAi(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: tag the script's element parameter with condition type 9 (repels) and pass it
 * to the matching handler in the condition table, so the AI state targets units that reflect that
 * element. If the handler fails, fall back to the default handler. */
// FUN_001E4D40
s32 btlAICommandCondQueryHansya(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x9000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: tag the script's element parameter with condition type 10 (absorbs) and pass
 * it to the matching handler in the condition table, so the AI state targets units that absorb that
 * element. If the handler fails, fall back to the default handler. */
// FUN_001E4DF0
s32 btlAICommandCondQueryKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xA000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: tag the script's element parameter with condition type 11 (nullifies) and pass
 * it to the matching handler in the condition table, so the AI state targets units that block that
 * element. If the handler fails, fall back to the default handler. */
// FUN_001E4EA0
s32 btlAICommandCondQueryMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xB000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: tag the script's element parameter with condition type 12 (weak) and pass it
 * to the matching handler in the condition table, so the AI state targets units weak to that
 * element. If the handler fails, fall back to the default handler. */
// FUN_001E4F50
s32 btlAICommandCondQueryWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xC000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: tag the script's element parameter with condition type 13 (does not repel) and
 * pass it to the matching handler in the condition table, so the AI state targets units that don't
 * reflect that element. If the handler fails, fall back to the default handler. */
// FUN_001E5000
s32 btlAICommandCondQueryNotHansya(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xD000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Narrow the AI target set to units that do not absorb (kyusyu) the script's affinity parameter,
 * and clear the set if none match. */
// FUN_001E50B0
s32 btlAICommandCondQueryNotKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xE000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Narrow the AI target set to units that do not nullify (mukou) the script's affinity parameter,
 * and clear the set if none match. */
// FUN_001E5160
s32 btlAICommandCondQueryNotMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xF000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Narrow the AI target set to units that are not weak to the script's affinity parameter, and clear
 * the set if none match. */
// FUN_001E5210
s32 btlAICommandCondQueryNotWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x10000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Run the appointed-target AI condition on the current AI state, and clear the target set if it
 * fails. */
// FUN_001E52C0
s32 btlAICommandAiUnlessAppoint(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D70[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Run the downed-target AI condition on the current AI state, and clear the target set if it fails. */
// FUN_001E5330
s32 btlAICommandAiUnlessDown(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D78[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: run the first condition handler in D_00609D80 on the AI state and fall back to
 * the default handler if it fails. Always returns 1. */
// FUN_001E53A0
s32 btlAICommandAiUnlessStand(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D80[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: run condition query 0x15 (reflect status) with the script's integer parameter
 * and fall back to the default handler if the query fails. Always returns 1. */
// FUN_001E5410
s32 btlAICommandCondQueryHansyaSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x15000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: run condition query 0x16 (absorb status) with the script's integer parameter
 * and fall back to the default handler if the query fails. Always returns 1. */
// FUN_001E54C0
s32 btlAICommandCondQueryKyusyuSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x16000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: run condition query 0x17 (nullify status) with the script's integer parameter
 * and fall back to the default handler if the query fails. Always returns 1. */
// FUN_001E5570
s32 btlAICommandCondQueryMukouSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x17000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command: run condition query 0x18 (weakness status) with the script's integer parameter
 * and fall back to the default handler if the query fails. Always returns 1. */
// FUN_001E5620
s32 btlAICommandCondQueryWeakSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x18000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Narrow the AI target query to units whose status does not reflect (hansya) the element given by
 * the script parameter, resetting the query if none match. Always returns 1. */
// FUN_001E56D0
s32 btlAICommandCondQueryNotHansyaSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x19000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Narrow the AI target query to units whose status does not absorb (kyusyu) the element given by
 * the script parameter, resetting the query if none match. Always returns 1. */
// FUN_001E5780
s32 btlAICommandCondQueryNotKyusyuSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1A000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Narrow the AI target query to units whose status does not nullify (mukou) the element given by
 * the script parameter, resetting the query if none match. Always returns 1. */
// FUN_001E5830
s32 btlAICommandCondQueryNotMukouSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1B000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Narrow the AI target query to units whose status is not weak to the element given by the script
 * parameter, resetting the query if none match. Always returns 1. */
// FUN_001E58E0
s32 btlAICommandCondQueryNotWeakSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1C000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Copy the battle's currently selected action's formation entry into the AI state and apply it as
 * the target, resetting the query if that fails. Always returns 1. */
// FUN_001E5990
s32 btlAICommandScriptAppointCurrent(void) {
    u8 *action = scrGetAiState();
    u32 q = (u32)((BtlBattleState *)D_0072449C)->selectedAction;
    if (q != 0) {
        btlFormationEntryCopySelected(action + 0x98, (u8 *)q + 0x98);
        if (!((s32 (*)(u8 *, s32))D_00609D70[0])(action, 0))
            ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    }
    return 1;
}

/* Run the AI target-filter condition 0x21 ("not ID") with the script's parameter on the current AI
 * state, falling back to the default filter if it fails. */
// FUN_001E5A20
s32 btlAICommandCondQueryNotId(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x21000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Run the random-chance AI filter on the current AI state, falling back to the default filter if it
 * fails. */
// FUN_001E5AD0
s32 btlAICommandAiUnlessRnd(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609DF0[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Run the AI target-filter condition 0x23 (support/buff "hojo") with the script's parameter on the
 * current AI state, falling back to the default filter if it fails. */
// FUN_001E5B40
s32 btlAICommandCondQueryHojo(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x23000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Run the AI target-filter condition 0x24 (lacking support/buff "hojo") with the script's parameter
 * on the current AI state, falling back to the default filter if it fails. */
// FUN_001E5BF0
s32 btlAICommandCondQueryNotHojo(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x24000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Select AI candidates that match the given unit ID using btlCond_MYID, excluding units that have
 * the buffs named in the second script parameter. */
// FUN_001E5CA0
s32 btlAICommandScriptPickMyIdFiltered(void) {
    u32 unitId = scrGetParamInt(0);
    u32 excludedBuffs = scrGetParamInt(1);
    btlAICommandSelectCandidates(scrGetAiState(), unitId, excludedBuffs, 0x40, 0, btlCond_MYID);
    return 1;
}

/* AI script command: run the acting unit's action through the second handler table entry unless the
 * first handler's check (HP at max) passes. Always returns 1. */
// FUN_001E5D20
s32 btlAICommandAiUnlessHpMax(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609E18[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* Clears four buff levels before replacing the acting unit's secondary id. */
// FUN_001E5D90
s32 btlAICommandScriptSetId2ClearBuffs(void) {
    u8 *action = scrGetAiState();
    u32 secondaryId = scrGetParamInt(0) & 0xFFFF;
    u32 data;
    BtlAction *actionRecord = (BtlAction *)action;
    datCalcClearBuffLevel((u32)((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->datUnit, 8);
    datCalcClearBuffLevel((u32)actionRecord->unit->datUnit, 9);
    datCalcClearBuffLevel((u32)actionRecord->unit->datUnit, 0xA);
    datCalcClearBuffLevel((u32)actionRecord->unit->datUnit, 0xB);
    data = (u32)actionRecord->unit->datUnit;
    ((DatUnit *)(data))->id2 = secondaryId;
    return 1;
}

// FUN_001E5E40
s32 btlAICommandScriptSetDownFlag(void) {
    u8 *action = scrGetAiState();
    if ((scrGetParamInt(0) & 0xFFFF) == 0) {
        u32 dataAddress = (u32)((BtlUnit *)(((BtlAction *)action)->unit))->datUnit;
        *(u16 *)dataAddress |= 8;
    } else {
        u32 dataAddress = (u32)((BtlUnit *)(((BtlAction *)action)->unit))->datUnit;
        *(u16 *)dataAddress &= 0xFFF7;
    }
    return 1;
}

// FUN_001E5EC0
s32 btlAICommandScriptSetSlipFlag(void) {
    u8 *action = scrGetAiState();
    if ((scrGetParamInt(0) & 0xFFFF) == 0) {
        u32 dataAddress = (u32)((BtlUnit *)(((BtlAction *)action)->unit))->datUnit;
        *(u16 *)dataAddress |= 0x10;
    } else {
        u32 dataAddress = (u32)((BtlUnit *)(((BtlAction *)action)->unit))->datUnit;
        *(u16 *)dataAddress &= 0xFFEF;
    }
    return 1;
}

// FUN_001E5F40
s32 btlAICommandScriptSetCommandOverride(void) {
    u8 *action = scrGetAiState();
    ((BtlAiCommandWork *)((BtlAction *)action)->unk_38)->overrideCommand = scrGetParamInt(0);
    ((BtlAiCommandWork *)(action + 0x38))->overrideEnabled = scrGetParamInt(1);
    return 1;
}

/* AI script command: return the id2 field of the acting unit's DatUnit to the script. */
// FUN_001E5F90
s32 btlAICommandScriptGetSelfId2(void) {
    u32 data = (u32)((BtlUnit *)(((BtlAction *)(scrGetAiState()))->unit))->datUnit;
    scrSetReturnInt(((DatUnit *)data)->id2);
    return 1;
}

/* AI script command: find a unit with the given id on the acting unit's own side and return its
 * unk_20 value, or 0 if none is found. */
// FUN_001E5FD0
s32 btlScriptGetSameSideUnitValue(void) {
    u8 *action = scrGetAiState();
    u32 *r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << ((((BtlAction *)action))->unit->genus)) & 0xFFFF, 0x80000);
    scrSetReturnInt(r != 0 ? ((BtlAction *)r)->unk_20 : 0);
    return 1;
}

/* AI script command: find a unit with the given id on the side opposite the acting unit and return
 * its unk_20 value, or 0 if none is found. */
// FUN_001E6050
s32 btlScriptGetOppositeSideUnitValue(void) {
    u32 shift;
    u32 *r;
    {
        if ((((BtlAction *)(scrGetAiState())))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    scrSetReturnInt(r != 0 ? ((BtlAction *)r)->unk_20 : 0);
    return 1;
}

/* AI script command: count the units on the acting unit's side that match the btlCond_MYHOJO
 * condition for the given parameter and return the count. */
// FUN_001E60F0
s32 btlAICommandScriptCountOwnHojo(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command: count the units on the AI's own side that do not match btlCond_MYHOJO (no buff
 * active) and return the count to the script. */
// FUN_001E6160
s32 btlAICommandScriptCountOwnNotHojo(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 1, 1, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command: count the units on the AI's own side that match btlCond_MYBAD (an ailment
 * active) and return the count to the script. */
// FUN_001E61D0
s32 btlAICommandScriptCountOwnBad(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYBAD, 0) & 0xFFFF);
    return 1;
}

/* AI script command: count the units on the opposing side that match btlCond_MYBAD (an ailment
 * active) and return the count to the script. */
// FUN_001E6240
s32 btlAICommandScriptCountOppBad(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 2, 0, &btlCond_MYBAD, 0) & 0xFFFF);
    return 1;
}

/* AI script command: count the units on the opposing side that match btlCond_MYHOJO (a buff active)
 * and return the count to the script. */
// FUN_001E62B0
s32 btlAICommandScriptCountOppHojo(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 2, 0, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command: count the units on the opposing side that do not match btlCond_MYHOJO (no buff
 * active) and return the count to the script. */
// FUN_001E6320
s32 btlAICommandScriptCountOppNotHojo(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 2, 1, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command: count the units on the acting side that pass the own-HP condition given by
 * parameter 0, and return the count to the script. */
// FUN_001E6390
s32 btlAICommandScriptCountOwnHp(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYHP, 0) & 0xFFFF);
    return 1;
}

// FUN_001E6400
s32 btlAICommandScriptAverageOwnLevel(void) {
    scrSetReturnInt(btlSideAverageLevel((1 << ((((BtlAction *)(scrGetAiState())))->unit->genus)) & 0xFFFF, 0x80000) & 0xFFFF);
    return -1;
}

/* AI script command: return the average level of the side opposing the acting unit, where the
 * opposing side is picked from the unit's genus. */
// FUN_001E6450
s32 btlAICommandScriptAverageOppLevel(void) {
    u32 shift;
    {
        if ((((BtlAction *)(scrGetAiState())))->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    scrSetReturnInt(btlSideAverageLevel((1 << (shift & 0xffff)) & 0xffff, 0x80000) & 0xFFFF);
    return -1;
}

/* AI script command: return the element row of the skill given in parameter 0, as calculated for
 * the acting unit. */
// FUN_001E64C0
s32 btlAICommandScriptGetCommandRow(void) {
    u8 *action = scrGetAiState();
    short commandId = (short)scrGetParamInt(0);
    scrSetReturnInt((s16)datCalcSkillElement((u8 *)(((BtlAction *)action))->unit->datUnit, (u16)commandId));
    return -1;
}

/* AI script command: return how many units on the player side are not in a bad state. */
// FUN_001E6530
s32 btlAICommandScriptCountOwnAlive(void) {
    scrGetAiState();
    scrSetReturnInt(btlSideCountNotBad(1, 0) & 0xFFFF);
    return 1;
}

/* AI script command: return how many units on the enemy side are not in a bad state. */
// FUN_001E6570
s32 btlAICommandScriptCountOppAlive(void) {
    scrGetAiState();
    scrSetReturnInt(btlSideCountNotBad(2, 0) & 0xFFFF);
    return -1;
}

// FUN_001E65B0
s32 btlAICommandScriptGetSelfHp(void) {
    scrSetReturnInt(datCalcGetHp((u32)((BtlUnit *)(((BtlAction *)(scrGetAiState()))->unit))->datUnit) & 0xFFFF);
    return -1;
}

/* Script command: look up the action for the given ID and run the HP condition check (kind 1)
 * against the query value, returning whether it holds. */
// FUN_001E65F0
s32 btlAICommandIdScriptQueryMyHp(void) {
    u32 actionId = scrGetParamInt(0);
    u32 queryValue = scrGetParamInt(1);
    u8 *action = btlActionFindById(actionId & 0xFFFFFFF);
    u32 packedCondition = (queryValue & 0xFFFFFF) | 0x1000000;
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = (queryValue | 0x1000000) & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

/* Script command: return whether the unit of the action with the given ID has any buff in the given
 * mask. */
// FUN_001E66C0
s32 btlAICommandIdScriptQueryHasBuff(void) {
    u32 actionId = scrGetParamInt(0);
    u32 queryValue = scrGetParamInt(1);
    u8 hasBuff = datCalcHasBuffMask((((BtlAction *)(btlActionFindById(actionId & 0xFFFFFFF))))->unit->datUnit, queryValue) != 0;
    scrSetReturnInt(hasBuff != 0);
    return 1;
}

/* Predicts whether the default attack kills the selected action's unit. */
// FUN_001E6740
s32 btlAICommandScriptWouldBeKilled(void) {
    u8 *action = scrGetAiState();
    u8 *target = btlActionFindById(scrGetParamInt(0) & 0xFFFFFFF);
    s32 hpDelta = datCalcSkillAmount(0, (u8 *)((BtlAction *)action)->unit->datUnit, (u8 *)((BtlAction *)target)->unit->datUnit, 1, 1, 1, 0, 1);
    s32 currentHp;
    s32 remainingHp;
    datCalcClearField18((u32)((BtlUnit *)(MEMBER(u8 *, action, BtlAction, unit)))->datUnit);
    datCalcClearField18((u32)((BtlUnit *)(MEMBER(u8 *, target, BtlAction, unit)))->datUnit);
    currentHp = (s32)(datCalcGetHp((u32)((BtlUnit *)(MEMBER(u8 *, target, BtlAction, unit)))->datUnit) & 0xFFFF);
    remainingHp = currentHp + hpDelta;
    scrSetReturnInt(remainingHp <= 0);
    return 1;
}

/* Script command: return whether the AI state has a command of the given element type usable
 * against the action with the given ID. */
// FUN_001E6820
s32 btlAICommandScriptHasCommandOfType(void) {
    u32 element;
    u32 targetId;
    u8 *action;

    action = (u8 *)(scrGetAiState());
    targetId = scrGetParamInt(0);
    element = scrGetParamInt(1);
    scrSetReturnInt(~btlAICommandCollectCommandsOfType(action, btlActionFindById(targetId & 0xFFFFFFF), (s16) element, 0) != 0);
    return 1;
}


/* Script command: read both parameters and look up the action by ID, then always return false. */
// FUN_001E68C0
s32 btlAICommandScriptLookupOnlyFalse(void) {
    u32 actionId;

    scrGetAiState();
    actionId = scrGetParamInt(0);
    scrGetParamInt(1);
    btlActionFindById(actionId & 0xFFFFFFF);
    scrSetReturnInt(0U);
    return 1;
}


/* Script command: look up the action for the given ID and run the normal-status condition check
 * (kind 0x3F) against the query value, returning whether it holds. */
// FUN_001E6930
s32 btlAICommandIdScriptQueryMyNomal(void) {
    u32 actionId = scrGetParamInt(0);
    u32 queryValue = scrGetParamInt(1);
    u8 *action = btlActionFindById(actionId & 0xFFFFFFF);
    u32 packedCondition = (queryValue & 0xFFFFFF) | 0x3F000000;
    u32 conditionKind = (packedCondition & 0xFF000000) >> 24;
    u32 conditionValue = (queryValue | 0x3F000000) & 0xFFFFFF;
    s32 conditionResult;
    if (conditionKind == 0)
        conditionResult = 0;
    else
        conditionResult = ((s32 (*)(u8 *, u32))D_00609850[conditionKind * 3])(action, conditionValue);
    scrSetReturnInt(conditionResult != 0);
    return 1;
}

// FUN_001E6A00
s32 btlAICommandIdScriptQueryOnSideZero(void) {
    scrSetReturnInt((((BtlAction *)btlActionFindById(scrGetParamInt(0) & 0xFFFFFFF)))->unit->genus == 0);
    return 1;
}
/* Reports whether the selected unit can use the supplied command id. */
// FUN_001E6A50
s32 btlAICommandIdScriptQueryCanUseCommand(void) {
    s32 actionId = scrGetParamInt(0);
    s32 commandId = scrGetParamInt(1);
    u8 *subject = btlActionFindById(actionId & 0xFFFFFFF);
    s32 command = commandId & 0xFFFF;
    s32 usable;
    BtlUnit *subjectUnit;
    if (command >= 0x240)
        kAssertFail(D_006095E0, 0x45F);
    subject = (u8 *)((BtlAction *)subject)->unit;
    subjectUnit = (BtlUnit *)subject;
    if (command < 0x1B8) {
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)subject)->datUnit, 0x80008) != 0)
            usable = 0;
        else if (datCalcHasSkill((u8 *)subjectUnit->datUnit, command) == 0)
            usable = 0;
        else if (datCalcThresholdTrigger((u8 *)subjectUnit->datUnit, command) != 0)
            usable = 0;
        else
            goto one;
    } else if (datCalcHasSkill((u8 *)((BtlUnit *)subject)->datUnit, command) != 0)
        goto one;
    else
        usable = 0;
    goto done;
one:
    usable = 1;
done:
    scrSetReturnInt(usable != 0);
    return 1;
}
