/* Source unit: src/Battle/btlEffect_001db100.c */
#include "btl_skill_target_internal.h"
#include "datCalc_unit_internal.h"
#include "datUnit_internal.h"
#include "type.h"
#include "include_asm.h"
#include "btl_cond_internal.h"
#include "btl_action_internal.h"
#include "btl_ai_internal.h"
#include "btl_effect_internal.h"

/* AI condition words pack an opcode in the high byte and a 24-bit argument.
 * Script handlers send the predicate value through scrSetReturnInt and retain
 * their original scheduler return status, including the query handlers returning -1. */

typedef s32 (*code)();




typedef struct DatUnit DatUnit;
extern u16 datCalcMaxHp(DatUnit *unit);


s32 btlAICommandNomalCheck(u8 *formation, s32 index, s32 enabled);

extern u64 datGetCollectionEntryBits();

extern s32 datCalcGetAffinity(u8 *arg0, s32 arg1);

typedef void (*FormationCallback)(void);

extern s32 btlAICommandSelectCandidates();

extern u64 kwlnTaskIsLinked();

extern u8 *btlActionFindById();
extern s32 btlAICommandCollectCommandsOfType(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3);
extern u32 scrGetParamInt();
extern void scrSetReturnInt();
extern u8 *scrGetAiState();

extern s32 btlSideSelectUnits();
extern s32 datCalcSkillAmount(s32 skill, u8 *source, u8 *target, s32 count, s32 hit, s32 relation, s32 options, s32 channel);
extern void datCalcClearField18(u32 arg0);
extern s32 btlEffectSelectNearestEntry(u32 arg0, u8 *arg1);
extern u32 btlFormationCurrentEntry(u8 *arg0);
extern s32 datCalcSkillElement(u8 *unit, u16 command);
extern s32 datCalcElementBit(s16 index);
extern s8 datCalcGetBuffStatus(u8 *unit, s32 status);
extern u32 datCalcUnderlyingSkillId(u32 arg0);
extern u32 *btlEffectFindUnitByIdAndStatus();
extern s32 func_001f9ce0(u8 *arg0, s32 arg1);
extern u32 datTestBitmapBit(u32 arg0, u32 arg1);
extern void btlFormationEntryCopySelected(u8 *arg0, u8 *arg1);
extern u8 *D_0072449C;
extern void *D_00609850[];
extern u32 D_00609600[];
extern u32 btlActionGetQueueEntry(u16 arg0);
extern u32 datCalcClearBuffLevel(u32 arg0, u32 arg1);
extern u32 datCalcRandomBelow(u32 arg0);
extern u16 datCalcGetHp(s32 unit);
extern s32 datCalcGetElementAffinity(u8 *unit, s32 index);
extern void btlAICommandSetActionCode(u8 *a, u8 *b, u16 c);

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
extern void btlEffectCollectTargetUnits(u8 *arg0, u8 *arg1, u16 arg2, s32 arg3, u8 *arg4);
extern s32 btlAICommandCollectSkillCandidates(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern s32 btlAICommandPickAiTarget(u8 *arg0, u32 arg1);
extern char D_006095E0[];
extern void kAssertFail(void *file, s32 line);
extern u32 datCalcChkBadStatus(s32 unit, u32 mask);
extern s32 datCalcHasSkill(u8 *unit, s32 command);
extern s32 datCalcThresholdTrigger(u8 *unit, s32 command);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern void func_001ebc00(u8 *a, u8 *b);
extern s32 datCalcDefaultSkillId(u8 *unit);
extern s32 datCalcPickSpecialItem(u8 *arg0);
extern u32 datCalcGetLevel(u32 arg0);
extern s32 datCalcIsDead(u32 arg0, u32 arg1);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb42c;
extern u8 *iGpffffb3cc;
extern u8 iGpffffa2a8;
extern u8 *iGpffffb444;
extern void sprintf(u8 *a, u8 *b, u32 c, u8 d);
extern s32 scrFindPrcdIdxByName(u32 a, u8 *b);
extern s32 scrStartProcedureIndex(u8 *a, u32 b, s32 c);
extern void scrSetTaskProc(u32 a, u8 *b);
extern u8 *kwlnTaskGetWork(u32 a);
extern s32 datPersonaNamePart1Alt(s32 a);
extern void itfMesWindowSetString(s32 a, s32 b, u32 c);
extern void kwlnTaskAddChild(u8 *a, u32 b);
extern u8 D_00609E20[];
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;
extern void func_001eb3b0(u8 *a);

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB040 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Shared by the exported callback and retail's inlined value query. */
/* The +0x30 action unit and +0xA64 data fields are proven; typed access
 * changed the inlined command-usability body (normalized diff 178). */
static inline s32 btlCommandUsable(u8 *subject, u32 command) {
    s32 commandId;

    commandId = command & 0xFFFF;
    if (commandId >= 0x240) {
        kAssertFail(D_006095E0, 0x45F);
    }
    subject = *(u8 **)(subject + 0x30);
    if (commandId < 0x1B8) {
        if (datCalcChkBadStatus((s32)*(u8 **)(subject + 0xA64), 0x80008) != 0)
            return 0;
        if (datCalcHasSkill(*(u8 **)(subject + 0xA64), commandId) == 0)
            return 0;
        if (datCalcThresholdTrigger(*(u8 **)(subject + 0xA64), commandId) == 0)
            goto ret1;
        return 0;
    }
    if (datCalcHasSkill(*(u8 **)(subject + 0xA64), commandId) != 0)
        goto ret1;
    return 0;
ret1:
    return 1;
}

/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 178). */
// FUN_001DAF40
s32 btlCond_MYABLESKIL(u8 *action, u32 command) {
    return btlCommandUsable(action, command);
}

/* Evaluate weakness on the opposite genus, excluding defeated units. */
// FUN_001DB040
void btlCond_ENWEAK_PAI(u8 *action, u32 value) {
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
    btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 6, (code *)&btlCond_MYWEAK);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB0A0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Evaluate weakness on the opposite genus, excluding defeated and down units. */
// FUN_001DB0A0
void btlCond_ENWEAK_ST_PAI(u8 *action, u32 value) {
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
    btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 6, (code *)&btlCond_MYWEAK);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB100 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Evaluate the alternate weakness predicate on the opposite genus. */
// FUN_001DB100
void btlCond_ENWEAK_DW_PAI(s32 action, u32 value)
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
  btlEffectFindUnitMatchingCallback(action, value, 1 << (shift & 0xffff) & 0xffff, 0x80000, 7,
                 (code *)&btlCond_MYWEAK);
  return;
}
#pragma opt_rebuildconditionals on



/* measured: shared usability inlining and explicit signed query guards give
   508B/512B, verify nd0; the remaining four bytes are zero tail padding.
   Keep the entry reload after the value query and the existing s32 input ABI. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 376). */
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

    unit = *(u8 **)(action + 0x30);
    queried = datCalcSkillElement(*(u8 **)(unit + 0xA64), 0);
    if (queried != value)
        goto scan;
    return 1;
scan:
    count = datCalcGetTableLength(*(DatUnit **)(unit + 0xA64));
    commands = (u16 *)datCalcSkillList(*(DatUnit **)(unit + 0xA64));
    index = 0;
    limit = count;
    while (index < limit) {
        entry = &commands[index];
        if (*entry != 0 && *entry < 0x1B8) {
            queried = datCalcSkillElement(*(u8 **)(unit + 0xA64), *entry);
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

/* Measured: 544/544 bytes, eight resolved relocations, no differing words.
 * Preserve the signed status result and the exactly-enabled status gate. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 417). */
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

    unit = *(u8 **)(formation + 0x30);
    if (*(u8 *)(unit + 0xA2) == 1 &&
        func_001f9ce0(formation, (s16)index) == 0) {
        u32 queryIndex = (u16)index;
        if (datTestBitmapBit(*(u16 *)(unit + 0xA4), queryIndex) == 0)
            return 1;
    }

    flags = datCalcElementBit((s16)index);
    if (enabled == 1 && !(flags & 0xE0001)) {
        if (flags & 2) {
            if (datCalcGetBuffStatus(*(u8 **)(unit + 0xA64), 0x10) > 0)
                return 0;
        } else if (!(flags & 0x40) &&
                   datCalcGetBuffStatus(*(u8 **)(unit + 0xA64), 0x11) > 0) {
            return 0;
        }
    }

    if (flags & 2) {
        if (*(u8 *)(unit + 0xA2) == 1) {
            if (*(u16 *)*(u8 **)(unit + 0xA64) & 0x100)
                return 0;
        } else {
            count = datCalcGetTableLength(*(DatUnit **)(unit + 0xA64));
            commands = (u16 *)datCalcSkillList(*(DatUnit **)(unit + 0xA64));
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
    return !(datCalcGetElementAffinity(*(u8 **)(unit + 0xA64), (s16)index) & 0x07000000);
}
#pragma opt_propagation on
#pragma opt_loop_invariants off
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
s32 btlAICommandNomalStatusCheck(u8 *action, s16 value) {
    return !(datCalcGetElementAffinity((u8 *)(((BtlAction *)action))->unit->datUnit, (s32)value) & 0x7000000);
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB620 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Evaluate normal-affinity targets on the opposite genus. */
// FUN_001DB620
void btlCond_ENNOMAL(u8 *action, u32 value) {
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
    btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0xA, (code *)&btlCond_MYNOMAL);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB680 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Evaluate normal-affinity targets, excluding defeated and down units. */
// FUN_001DB680
void btlCond_ENNOMAL_ST(u8 *action, u32 value) {
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
    btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0xA, (code *)&btlCond_MYNOMAL);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB6E0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Evaluate the alternate normal-affinity predicate on the opposite genus. */
// FUN_001DB6E0
void btlCond_ENNOMAL_DW(s32 action, u32 value)
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
  btlEffectFindUnitMatchingCallback(action, value, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0xb,
                 (code *)&btlCond_MYNOMAL);
  return;
}
#pragma opt_rebuildconditionals on



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
    return (((BtlAction *)action)->unit->datUnit->flags & DAT_UNIT_FLAG_DOWN) ? 0 : 1;
}



// FUN_001DB7B0
s32 btlCond_SLIP(u8 *action) {
    return (((BtlAction *)action)->unit->datUnit->flags & 0x10) ? 0 : 1;
}



/* Ported from P3FES btlEffect.c func_002c3300 (genus-match loop).
   func_002ffcc0->func_00231e20 (masked u8); iGpffffb6fc+0x14c->iGpffffb3ac+0x174;
   offsets 0xa2c->0xa64, 0x4a8->0x450. Pragma disables the shift-fold. */
#pragma opt_rebuildconditionals off
/* Find an active opposite-genus action whose level exceeds the caller by the requested amount. */
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
#pragma opt_rebuildconditionals on


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
void btlCond_FRTAISEI(u8 *action, u32 value) {
    btlEffectFindUnitMatchingCallback((s32)action, value, (1 << ((((BtlAction *)action))->unit->genus)) & 0xFFFF, 0x80000, 0, (code *)&btlCond_MYTAISEI);
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB990 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Evaluate affinity on units of the opposite genus. */
// FUN_001DB990
void btlCond_ENTAISEI(u8 *action, u32 value) {
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
    btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code *)&btlCond_MYTAISEI);
}

#pragma opt_rebuildconditionals on
/* measured: propagation off retains index preparation before the enemy load
   with the canonical u32 bitmap arguments; 156B/window 160B, normalized_diff 0. */
#pragma push
#pragma opt_propagation off
/* Check the enemy affinity bitmap and test whether the requested affinity is non-normal. */
// FUN_001DB9F0
s32 btlCond_MYNOTNOMAL(u8 *action, s16 value) {
    u8 *p = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)p)->genus == 1 && func_001f9ce0(action, value) == 0) {
        u32 index = (u16)value;
        if (datTestBitmapBit(((BtlUnit *)p)->charId, index) == 0)
            return 0;
    }
    return (datCalcGetElementAffinity((u8 *)((BtlUnit *)p)->datUnit, (s32)value) & 0x7000000) != 0;
}
#pragma pop

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DBA90 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Evaluate non-normal affinity on units of the opposite genus. */
// FUN_001DBA90
void btlCond_ENNOTNOMAL(u8 *action, u32 value) {
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
    btlEffectFindUnitMatchingCallback((s32)action, value, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0xA, (code *)&btlCond_MYNOTNOMAL);
}

#pragma opt_rebuildconditionals on
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

/* MATCH.  `opt_dead_assignments off` is the whole difference: with it the
   two remaining words - retail evaluating the second argument of
   datTestBitmapBit(*(u16 *)(temp16 + 0xA4), index) first, `andi $a1, $s4,
   0xffff` before `lhu $a0, 0xa4($s0)` - come out in retail's order.  Found by
   a pairwise sweep; the pragma is not in the usual four and had never been
   measured anywhere in this tree.  `opt_strength_reduction off` alone is
   neutral at 2, the pair is also 0, so the single pragma is what is kept.
   The two source levers that got it from unmeasurable to 2 stay load-bearing:
   the definition must be K&R, because every call site below passes a
   differently-typed function pointer to `code arg5` and a prototyped form
   fails the whole translation unit under -DNON_MATCHING; and the group test
   is `count > 1` rather than `count >= 2`, which puts the compare in $at
   where retail has it.  Measured and rejected on the last two words before
   the pragma was found: inlining `(u16)arg1` at the call, a two-definition
   pin on `index`, hoisting the halfword load into a named local, spelling the
   mask `arg1 & 0xFFFF`, and all four of `schedule on` (199),
   `opt_loop_invariants on` (147), `opt_common_subs off` (193) and
   `opt_propagation off` (191). */
/* Filter the classified targets by status, affinity and predicate; copy all matches or choose one. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 6). */
// FUN_001DBBA0
#pragma opt_dead_assignments off
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

        available = btlSkillClassifyTargets((u8 *)action, (u8 *)action + 0x98, *(u16 *)((u8 *)action + 0x6E), 0);
        if (available != 0) {
            u16 copyIndex;
            u16 copyCount;

            copyIndex = 0;
            while ((copyCount = *(u16 *)((u8 *)action + 0xD0)), (u16)copyIndex < copyCount) {
                *(u32 *)((u8 *)action + (copyIndex & 0xFFFF) * 4 + 0x38) =
                    *(u32 *)((u8 *)action + (copyIndex & 0xFFFF) * 4 + 0x98);
                copyIndex++;
            }
            *(u16 *)((u8 *)action + 0x6A) = copyCount;
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
    for (; (u16)candidateIndex < *(u16 *)((u8 *)action + 0xD0); candidateIndex = (candidateIndex + 1) & 0xFFFF) {
        candidateAction = *(u8 **)((u8 *)action + (candidateIndex & 0xFFFF) * 4 + 0x98);
        if ((*(u16 *)(candidateAction + 0x1A) & 1) == 0) {
            continue;
        }
        candidateUnit = *(u8 **)(candidateAction + 0x30);
        if (filterFlags == 0) {
            goto testm4;
        }
        if (requireDown == 0) {
            goto testm2;
        }
        if (datCalcChkBadStatus(*(u32 *)(candidateUnit + 0xA64), 0x100000) == 0) {
            continue;
        }
    testm2:
        if (requireKnownAffinity == 0) {
            goto testm3;
        }
        if (*(u8 *)(candidateUnit + 0xA2) != 1 || func_001f9ce0(candidateAction, (s16)queryValue) != 0) {
            goto testm3;
        }
        {
            u32 index = (u16)queryValue;
            if (datTestBitmapBit(*(u16 *)(candidateUnit + 0xA4), index) == 0) {
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
            if (datCalcChkBadStatus(*(u32 *)(candidateUnit + 0xA64), excludedStatus) != 0) {
                continue;
            } else {
                goto docallback;
            }
        }
        if (datCalcHasBuffMask(*(DatUnit **)(candidateUnit + 0xA64), excludedStatus) != 0) {
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
            *(u8 **)((u8 *)action + 0x38) = selected[pick & 0xFFFF];
            *(u16 *)((u8 *)action + 0x6A) = 1;
        } else {
            s32 selectedIndex;

            selectedIndex = 0;
            while ((u16)selectedIndex < count) {
                *(u8 **)((u8 *)action + (selectedIndex & 0xFFFF) * 4 + 0x38) = selected[selectedIndex & 0xFFFF];
                selectedIndex = (selectedIndex + 1) & 0xFFFF;
            }
            *(u16 *)((u8 *)action + 0x6A) = selectedCount;
        }
        return 1;
    }
}
#pragma opt_dead_assignments on

/* measured 2026-09-28: 1116 bytes plus four retail zero bytes, nine resolved
   relocations. The unit/ratio records keep integer and float copies separate;
   u32 HP values preserve retail's unsigned float conversions. The masked s32
   count and total, and the total-before-index declarations, retain the other
   scan lifetimes. Loop-invariant optimization hoists the sort bound and 1.
   Lifetime optimization separates the two uses of n: the completed target
   scan and the subsequent sort. Reusing that cursor closes the last seven
   register differences without adding an operation. */
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
/* HP-ratio ranking row used by the weighted target picker. */
typedef struct SortEnt {
    u32 unit;
    f32 ratio;
} SortEnt;
/* Use uniform targeting unless eligible party targets can be ranked by HP ratio and weighted. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 815). */
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

    classification = btlSkillClassifyTargets(action, action + 0x98, *(u16 *)(action + 0x6E), 0);
    if (classification != 0) {
        copyIndex = 0;
        while ((candidateCount = *(u16 *)(action + 0xD0)), (u16)copyIndex < candidateCount) {
            *(u32 *)(action + (copyIndex & 0xFFFF) * 4 + 0x38) = *(u32 *)(action + (copyIndex & 0xFFFF) * 4 + 0x98);
            copyIndex++;
        }
        *(u16 *)(action + 0x6A) = candidateCount;
        return 1;
    }
    candidateCount = *(u16 *)(action + 0xD0);
    chooseUniformly = 1;
    if (candidateCount == 1) {
        *(u32 *)(action + 0x38) = *(u32 *)(action + 0x98);
        *(u16 *)(action + 0x6A) = 1;
    } else {
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 1) {
            scanIndex = 0;
            while ((u16)scanIndex < candidateCount) {
                if (*(u8 *)(*(u8 **)(*(u32 *)(action + (scanIndex & 0xFFFF) * 4 + 0x98) + 0x30) + 0xA2) != 0) {
                    break;
                }
                scanIndex = (scanIndex + 1) & 0xFFFF;
            }
            if ((u16)scanIndex == candidateCount) {
                chooseUniformly = 0;
            }
        }
        targetKind = *(iGpffffb3b8 + *(u16 *)(action + 0x6E) * 40 + 17);
        if (targetKind == 0x10 || targetKind == 0x0E || targetKind == 0x0D || targetKind == 0x0C || targetKind == 0x0A || targetKind == 0x08 || targetKind == 0x04 || targetKind == 0x03 || targetKind == 0x01) {
        } else {
            chooseUniformly = 1;
        }
        if (chooseUniformly != 0 || candidateCount > 4) {
            *(u32 *)(action + 0x38) = ((u32 *)(action + 0x98))[(u16)datCalcRandomBelow(candidateCount)];
            *(u16 *)(action + 0x6A) = 1;
        } else {
            candidateIndex = 0;
            sortCount = candidateCount & 0xFFFF;
            while (candidateIndex < sortCount) {
                candidateEntry = action + (candidateIndex & 0xFFFF) * 4 + 0x98;
                candidateAction = *(u32 *)candidateEntry;
                maxHp = datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(candidateAction + 0x30) + 0xA64)) & 0xFFFF;
                currentHp = datCalcGetHp(*(u32 *)(*(u32 *)(candidateAction + 0x30) + 0xA64)) & 0xFFFF;
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
                *(u32 *)(action + 0x38) = rankedTargets[weightedIndex].unit;
                *(u16 *)(action + 0x6A) = 1;
            } else {
                *(u32 *)(action + 0x38) = rankedTargets[datCalcRandomBelow(candidateCount)].unit;
                *(u16 *)(action + 0x6A) = 1;
            }
        }
    }
    return 1;
}

#pragma opt_loop_invariants off
#pragma pop
/* Ported from P3FES btlEffect.c func_002c3be0 (copy-all / min-stat select).
   func_002bff60_u16->func_001d7f10; offsets 0x88->0x98, 0xc0->0xd0, 0xa2c->0xa64;
   lowest init 0xfffffff. */
/* Copy all classified targets or choose the candidate with the lowest current HP. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 4). */
// FUN_001DC380
u32 btlCond_HPMIN(u32 action)
{
    u32 unit;
    u16 available;

    unit = action;
    available = btlSkillClassifyTargets((u8 *)unit, (u8 *)(unit + 0x98), *(u16 *)(unit + 0x6e), 0);
    if (available != 0) {
        u16 index;
        u16 count;
        index = 0;
        while ((count = *(u16 *)(unit + 0xd0)), (u16)index < count) {
            *(u32 *)(unit + (index & 0xffff) * 4 + 0x38) =
                *(u32 *)(unit + (index & 0xffff) * 4 + 0x98);
            index++;
        }
        *(u16 *)(unit + 0x6a) = count;
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
        count = *(u16 *)(unit + 0xd0);
        while (index < count) {
            candidate = *(u32 *)(unit + index * 4 + 0x98);
            stat = *(u16 *)(*(s32 *)(*(s32 *)(candidate + 0x30) + 0xa64) + 8);
            if (stat < lowest) {
                selected = candidate;
                lowest = stat;
            }
            index++;
        }
        *(u32 *)(unit + 0x38) = selected;
    }
    *(u16 *)(unit + 0x6a) = 1;
    return 1;
}


/* Ported from P3FES btlEffect.c func_002c3ce0 (target-choose min-score loop).
   func_002bff60_u16->func_001d7f10, func_002ffcc0->func_00231e20 (score masked
   (u8)); offsets 0x88->0x98, 0xc0->0xd0, 0xa2c->0xa64. */
/* Copy all classified targets or choose the candidate with the lowest level. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 4). */
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

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), *(u16 *)(action + 0x6e), 0);
    if (result != 0) {
        for (copyIndex = 0; copyIndex < *(u16 *)(action + 0xd0); copyIndex++) {
            *(u32 *)(action + copyIndex * 4 + 0x38) = *(u32 *)(action + copyIndex * 4 + 0x98);
        }
        *(u16 *)(action + 0x6a) = *(u16 *)(action + 0xd0);
        return 1;
    }
    selected = 0;
    best = 0xffff;
    for (index = 0; index < *(u16 *)(action + 0xd0); index++) {
        idx32 = index;
        idx32 = idx32 & 0xffff;
        unit = *(s32 *)(action + idx32 * 4 + 0x98);
        score = (u8)datCalcGetLevel(*(u32 *)(*(s32 *)(unit + 0x30) + 0xa64));
        if (score < best) {
            selected = unit;
            best = score;
        }
    }
    *(s32 *)(action + 0x38) = selected;
    *(u16 *)(action + 0x6a) = 1;
    return 1;
}

// FUN_001DC5B0
s32 btlCond_MPMAX(void) {
    return 0;
}

// FUN_001DC5C0
void btlAICommandPickMyBad(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, btlCond_MYBAD);
}

// FUN_001DC600
void btlAICommandPickNotMyBad(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 1, btlCond_MYBAD);
}

// FUN_001DC640
void btlAICommandPickMyId(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, btlCond_MYID);
}

/* measured: entire loop body and tail compile with mwcc b210's temp registers
   rotated one slot off retail ($v1/$a0/$a1 where retail uses $v0/$v1/$a0),
   starting from the gp load (lw $v1,($gp) vs lw $v0,-0x4c54($gp)) and cascading
   through lhu/andi, the 0x30-chain, the arr store (andi $a0.. vs $v0..), the
   (u16)i test (andi $v1 vs $a0) and the else path (extra move $a0,$s0 + andi on
   the u16 return). Control flow, frame, saved regs, call shapes all match.
   Tried: decl-order swaps, fl/np locals, inline exprs, g = iGpffffb3ac local,
   for/while, node-chain compare order, t = (u16)i local, arr[14]/arr[16] —
   all nd 40-56. $v0/$v1-coloring floor. */
/* Ported from P3FES btlEffect.c func_002c3f00 (btlAI target-select loop).
   iGpffffb6fc+0x14c -> iGpffffb3ac+0x174; func_00300580 -> func_00232710;
   func_002ffbc0 -> func_00231d70 (extern switched u16->u32 so the index
   call doesn't re-mask the return); field 0xa2c -> 0xa64, 0x4a8 -> 0x450. */
/* Choose another active same-genus action, falling back to the caller when none qualifies. */
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
void btlAICommandPickMyHansya(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, btlCond_MYHANSYA);
}

// FUN_001DC7E0
void btlAICommandPickMyKyusyu(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, btlCond_MYKYUSYU);
}

// FUN_001DC820
void btlAICommandPickMyMukou(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, btlCond_MYMUKOU);
}

// FUN_001DC860
void btlAICommandPickMyWeak(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, btlCond_MYWEAK);
}

// FUN_001DC8A0
void btlAICommandPickNotMyHansya(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 1, btlCond_MYHANSYA);
}

// FUN_001DC8E0
void btlAICommandPickNotMyKyusyu(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 1, btlCond_MYKYUSYU);
}

// FUN_001DC920
void btlAICommandPickNotMyMukou(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 1, btlCond_MYMUKOU);
}

// FUN_001DC960
void btlAICommandPickNotMyWeak(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 1, btlCond_MYWEAK);
}

/* measured: retail hoists the loop-test count load before the (u16)i mask
   (lhu $v1,0xd0($s0); andi $v0,$a0,0xffff) while mwcc b210 emits the mask
   first under every operand order tried, and the else-path address addu comes
   out base-first (addu $v0,$s0,$v0 vs retail addu $v0,$v0,$s0) no matter how
   the scaled offset is named. nd 5 = those 3 words + reloc accounting; the
   loop-body mask, increment, branch shape and everything else are
   byte-identical with the (u16)i + while((count=load)>i)... spelling
   (attempt 1; swapped compare order regressed to nd 8). Load-sinking floor,
   same family as FUN_001DCA60. */
/* Ported from P3FES btlEffect.c func_002c4200 (copy-all / random-select).
   func_002bff60_u16->func_001d7f10 (4th arg 1), func_002ffbc0_u16->func_00231d70;
   offsets 0x88->0x98, 0xc0->0xd0. */
/* The random slot offset stays in bytes: MWCC operand order for this materialized offset is matching-sensitive. */
/* Copy classified reverse targets or choose one candidate uniformly. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 2). */
// FUN_001DC9A0
u32 btlCond_AI_REV(u32 action)
{
    u16 result;
    u16 index;
    u32 address;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), *(u16 *)(action + 0x6e), 1);
    if (result != 0) {
        for (index = 0; index < *(u16 *)(action + 0xd0); index++) {
            *(u32 *)(action + index * 4 + 0x38) = *(u32 *)(action + index * 4 + 0x98);
        }
        *(u16 *)(action + 0x6a) = *(u16 *)(action + 0xd0);
        return 1;
    }
    index = datCalcRandomBelow(*(u16 *)(action + 0xd0));
    address = (index & 0xffff) * 4;
    *(u32 *)(action + 0x38) = *(u32 *)(address + action + 0x98);
    *(u16 *)(action + 0x6a) = 1;
    return 1;
}

/* measured: same 2-word loop-body mask floor as FUN_001DCF10/FUN_001DC9A0 —
   retail zero-extends the u16 counter into scratch $v0 (andi $v0,$a0,0xffff;
   sll $v0,$v0,2), mwcc b210 masks in place (andi $a0,$a0,0xffff; sll $v0,$a0,2);
   everything else in the function is byte-identical (nd 5 = those 2 words +
   reloc accounting). Tried (u32)/(s32)/explicit-mask index spellings: nd >= 5. */
/* measured: MATCH. Copy loop spelled exactly like FUN_001DC9A0 (u16 index,
   for loop, sh count). Else branch: retail keeps func_001dbf20 INLINE and
   puts the store block OUT OF LINE (forward bnez) — lever 1, flip the
   branch: if (btlEffectSelectNearestEntry(...) == 0) { return func_001dbf20(...); } then
   the store block falls through. The opposite spelling (store block in the
   if with return 1, func_001dbf20 as trailing return) emits the mirror
   layout at nd 36. */
/* Use the nearest candidate when available, otherwise use the normal AI target picker. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 2). */
// FUN_001DCA60
s32 btlCond_APPOINT(u8 *action, u32 value)
{
    u16 result;
    u16 index;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), *(u16 *)(action + 0x6e), 0);
    if (result != 0) {
        for (index = 0; index < *(u16 *)(action + 0xd0); index++) {
            *(u32 *)(action + index * 4 + 0x38) = *(u32 *)(action + index * 4 + 0x98);
        }
        *(u16 *)(action + 0x6a) = *(u16 *)(action + 0xd0);
        return 1;
    }
    if (btlEffectSelectNearestEntry(0, (u8 *)(action + 0x98)) == 0) {
        return btlAICommandPickAiTarget(action, value);
    }
    *(u32 *)(action + 0x38) = btlFormationCurrentEntry((u8 *)(action + 0x98));
    *(u16 *)(action + 0x6a) = 1;
    return 1;
}

// FUN_001DCB50
void btlAICommandPickMyDown(u64 formation)
{
    btlAICommandSelectCandidates(formation, BTL_STATUS_DOWN, 0, 0, 0, btlCond_MYBAD);
}



// FUN_001DCB90
void btlAICommandPickNotMyDown(u64 formation)
{
    btlAICommandSelectCandidates(formation, BTL_STATUS_DOWN, 0, 0, 1, btlCond_MYBAD);
}



// FUN_001DCBD0
void btlAICommandPickMyHansyaExcludingDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 1048576, 0, 0, btlCond_MYHANSYA);
}

// FUN_001DCC10
void btlAICommandPickMyKyusyuExcludingDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 1048576, 0, 0, btlCond_MYKYUSYU);
}

// FUN_001DCC50
void btlAICommandPickMyMukouExcludingDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 1048576, 0, 0, btlCond_MYMUKOU);
}

// FUN_001DCC90
void btlAICommandPickMyWeakExcludingDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 1048576, 0, 0, btlCond_MYWEAK);
}

// FUN_001DCCD0
void btlAICommandPickNotMyHansyaExcludingDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 1048576, 0, 1, btlCond_MYHANSYA);
}

// FUN_001DCD10
void btlAICommandPickNotMyKyusyuExcludingDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 1048576, 0, 1, btlCond_MYKYUSYU);
}

// FUN_001DCD50
void btlAICommandPickNotMyMukouExcludingDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 1048576, 0, 1, btlCond_MYMUKOU);
}

// FUN_001DCD90
void btlAICommandPickNotMyWeakExcludingDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 1048576, 0, 1, btlCond_MYWEAK);
}

// FUN_001DCDD0
void btlAICommandPickMyHansyaRequireDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 1, 0, btlCond_MYHANSYA);
}

// FUN_001DCE10
void btlAICommandPickMyKyusyuRequireDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 1, 0, btlCond_MYKYUSYU);
}

// FUN_001DCE50
void btlAICommandPickMyMukouRequireDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 1, 0, btlCond_MYMUKOU);
}

// FUN_001DCE90
void btlAICommandPickMyWeakRequireDown(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 1, 0, btlCond_MYWEAK);
}

// FUN_001DCED0
void btlAICommandPickNotMyId(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 1, btlCond_MYID);
}

/* Ported from P3FES btlEffect.c func_002c4760 (copy-all / random-select).
   func_002bff60_u16->func_001d7f10 (4th arg 0), func_002ffbc0_u16->func_00231d70;
   offsets 0x88->0x98, 0xc0->0xd0. */
/* The random slot offset stays in bytes: MWCC operand order for this materialized offset is matching-sensitive. */
/* Copy classified targets or choose one candidate uniformly. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 2). */
// FUN_001DCF10
u32 btlCond_RND(u32 action)
{
    u16 result;
    u16 index;
    u32 address;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), *(u16 *)(action + 0x6e), 0);
    if (result != 0) {
        for (index = 0; index < *(u16 *)(action + 0xd0); index++) {
            *(u32 *)(action + index * 4 + 0x38) = *(u32 *)(action + index * 4 + 0x98);
        }
        *(u16 *)(action + 0x6a) = *(u16 *)(action + 0xd0);
        return 1;
    }
    index = datCalcRandomBelow(*(u16 *)(action + 0xd0));
    address = (index & 0xffff) * 4;
    *(u32 *)(action + 0x38) = *(u32 *)(address + action + 0x98);
    *(u16 *)(action + 0x6a) = 1;
    return 1;
}


// FUN_001DCFD0
void btlAICommandPickMyHojo(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, (FormationCallback)btlCond_MYHOJO);
}

// FUN_001DD010
void btlAICommandPickNotMyHojo(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 1, (FormationCallback)btlCond_MYHOJO);
}

// FUN_001DD050
void btlAICommandPickMyNotNomal(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, btlCond_MYNOTNOMAL);
}

// FUN_001DD090
void btlAICommandPickMyNomal(u64 formation, u32 flags) {
    btlAICommandSelectCandidates(formation, flags, 0, 0, 0, (FormationCallback)btlCond_MYNOMAL);
}

/* measured: MATCH. Copy loop spelled exactly like FUN_001DC9A0 (u16 index).
   Second (max-score search) loop needs the WHILE form (not for) with
   statement order best=0, bestScore=0, j=0, count=load — the for-loop spelling
   emits the count load before j=0 in the preheader (nd 8); the while form
   preserves source order and reproduces retail's best,bestScore,j,count
   preheader exactly. bestScore u32 (sltu). */
/* Copy all classified targets or choose the candidate with the highest current HP. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 4). */
// FUN_001DD0D0
u32 btlCond_HPMAX(u32 action)
{
    u16 result;
    u16 index;
    u32 best;
    u32 j;
    u32 bestScore;
    u32 count;

    result = btlSkillClassifyTargets((u8 *)action, (u8 *)(action + 0x98), *(u16 *)(action + 0x6e), 0);
    if (result != 0) {
        for (index = 0; index < *(u16 *)(action + 0xd0); index++) {
            *(u32 *)(action + index * 4 + 0x38) = *(u32 *)(action + index * 4 + 0x98);
        }
        *(u16 *)(action + 0x6a) = *(u16 *)(action + 0xd0);
        return 1;
    }
    best = 0;
    bestScore = 0;
    j = 0;
    count = *(u16 *)(action + 0xd0);
    while (j < count) {
        u8 *ptr = (u8 *)*(u32 *)(action + j * 4 + 0x98);
        u32 score = *(u16 *)(*(u32 *)(*(u32 *)(ptr + 0x30) + 0xA64) + 0x8);
        if (bestScore < score) {
            best = (u32)ptr;
            bestScore = score;
        }
        j++;
    }
    *(u32 *)(action + 0x38) = best;
    *(u16 *)(action + 0x6a) = 1;
    return 1;
}
/* Skill-table byte +8 is not yet named in DatSkillEntry; retain the observed 0x28-byte row access. */
/* Select a usable command by predicted remaining target HP and the requested cost class. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 21). */
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

    targetHp = datCalcGetHp(*(u32 *)(*(u32 *)(target + 0x30) + 0xA64)) & 0xFFFF;
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
            costKind = *(u8 *)(iGpffffb3b8 + commandId * 40 + 8);
        if ((costClass != 0 || (costKind & 0xFF) == 1) && (costClass != 1 || (costKind & 0xFF) == 0)) {
            hpDelta = datCalcSkillAmount(commandId, (u8 *)*(u32 *)(*(u32 *)(action + 0x30) + 0xA64), (u8 *)*(u32 *)(*(u32 *)(target + 0x30) + 0xA64), 1, 1, 1, 0, 1);
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
    datCalcClearField18(*(u32 *)(*(u32 *)(action + 0x30) + 0xA64));
    datCalcClearField18(*(u32 *)(*(u32 *)(target + 0x30) + 0xA64));
    return bestCommand;
}
/* Skill-table byte +8 is not yet named in DatSkillEntry; retain the observed 0x28-byte row access. */
/* Choose the command whose predicted target HP is closest to its maximum. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 35). */
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

    targetHp = datCalcGetHp(*(u32 *)(*(u32 *)(target + 0x30) + 0xA64)) & 0xFFFF;
    maxHp = datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(target + 0x30) + 0xA64)) & 0xFFFF;
    bestCommand = -1;
    bestDistance = 0xFFFFFF;
    commandIndex = 0;
    costClass = requestedCostClass & 0xFFFF;
    commandCount = count & 0xFFFF;
    while ((commandIndex & 0xFFFF) < commandCount) {
        commandEntry = commands + (u16)commandIndex;
        commandId = *(u16 *)commandEntry;
        if (commandId != 0 && commandId < 0x1B8) {
            costKind = *(u8 *)(iGpffffb3b8 + commandId * 40 + 8);
            if ((costClass != 0 || (costKind & 0xFF) == 1) && (costClass != 1 || (costKind & 0xFF) == 0)) {
                distance = func_0043c6a0(maxHp - (targetHp + datCalcSkillAmount(commandId, (u8 *)*(u32 *)(*(u32 *)(action + 0x30) + 0xA64), (u8 *)*(u32 *)(*(u32 *)(target + 0x30) + 0xA64), 1, 1, 1, 0, 1)));
                if (distance < bestDistance) {
                    bestCommand = *(u16 *)commandEntry;
                    bestDistance = distance;
                }
            }
        }
        commandIndex = (commandIndex + 1) & 0xFFFF;
    }
    datCalcClearField18(*(u32 *)(*(u32 *)(action + 0x30) + 0xA64));
    datCalcClearField18(*(u32 *)(*(u32 *)(target + 0x30) + 0xA64));
    return bestCommand;
}
/* Recovered: retail's shape is a scoped `opt_propagation off` translation
   unit region, which is why the object keeps folds this build would remove
   (the first tally increment stays `addiu $v0,$s2,1; andi $s2,$v0,0xffff`
   after the tally is zeroed, and `ok = 1` is still tested by `beqz $v0`).
   Four source shapes carry the rest: the loop bound is a separate `s32`
   copy of the u16 limit (retail keeps the u16 in $s1 and spills the s32
   copy to 0xB0, masking once instead of once per iteration), `idx = 0`
   precedes that copy, both legs of the command test assign `ok = 0` and
   jump to a single shared `ok = 1`, and the dispatch is a `switch` whose
   cases `break` to one `return r` - the trampoline at 0x1dd8d4 - with the
   `return -1` left as the function's last statement.  With the limit mask
   written `(u16)call()` (propagation-off lowers `call() & 0xFFFF` as
   ori/and) this is byte-exact. */
/* Collect usable commands effective on the target and choose by predicted HP outcome. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 627). */
// FUN_001DD570
#pragma push
#pragma opt_propagation off
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

    candidateCount = 0;
    sourceUnit = *(u8 **)(action + 0x30);
    defaultElement = (s16)datCalcSkillElement(*(u8 **)(sourceUnit + 0xA64), 0);
    if (btlAICommandNomalCheck(target, defaultElement, 1) != 0) {
        candidates[0] = 0;
        candidateCount++;
    }
    commandCount = (u16)datCalcGetTableLength(*(DatUnit **)(sourceUnit + 0xA64));
    commands = (u16 *)datCalcSkillList(*(DatUnit **)(sourceUnit + 0xA64));
    commandIndex = 0;
    scanCount = commandCount;
    while (commandIndex < scanCount) {
        entry = commands + commandIndex;
        listCommand = *entry;
        if (listCommand != 0 && listCommand < 0x1B8) {
            commandElement = (s16)datCalcSkillElement(*(u8 **)(sourceUnit + 0xA64), listCommand);
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
            usabilityUnit = *(u8 **)(action + 0x30);
            if (command < 0x1B8) {
                if (datCalcChkBadStatus(*(u32 *)(usabilityUnit + 0xA64), 0x80008) != 0) {
                    usable = 0;
                    goto have_ok;
                }
                if (datCalcHasSkill(*(u8 **)(usabilityUnit + 0xA64), command) == 0) {
                    usable = 0;
                    goto have_ok;
                }
                if (datCalcThresholdTrigger(*(u8 **)(usabilityUnit + 0xA64), command) != 0) {
                    usable = 0;
                    goto have_ok;
                }
            } else {
                if (datCalcHasSkill(*(u8 **)(usabilityUnit + 0xA64), command) == 0) {
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
#pragma pop
/* Measured with b210: the scoped scan aggregates preserve iterator lifetimes
   through scalarization. The status scan keeps a native index with explicit
   halfword boundaries; both scans reload entries after the usability calls.
   Allocator capture traced the former selector/count exchange to the healing
   scan's command/index coloring, rather than their declaration order. */
/* Collect revive, healing or status-cure commands according to the target condition. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 1175). */
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

    recoveryKind = -1;
    candidateCount = 0;
    unit = *(u8 **)(action + 0x30);
    commandCount = datCalcGetTableLength(*(DatUnit **)(unit + 0xA64));
    commands = (u16 *)datCalcSkillList(*(DatUnit **)(unit + 0xA64));
    if (datCalcIsDead(*(u32 *)(*(u32 *)(target + 0x30) + 0xA64), 0) != 0) {
        recoveryKind = 0;
    } else {
        targetHp = *(u16 *)(*(u32 *)(*(u32 *)(target + 0x30) + 0xA64) + 8);
        maxHp = (u16)datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(target + 0x30) + 0xA64));
        if (targetHp * 100 <= maxHp * 60) {
            recoveryKind = 1;
        } else {
            if (datCalcChkBadStatus(*(u32 *)(*(u32 *)(target + 0x30) + 0xA64), 0xC) != 0) {
                recoveryKind = 2;
            } else {
                currentHp = datCalcGetHp(*(u32 *)(*(u32 *)(target + 0x30) + 0xA64)) & 0xFFFF;
                if (currentHp < (s32)(datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(target + 0x30) + 0xA64)) & 0xFFFF))
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
/* measured: matched by declaring func_001dd1c0's count parameter u16, so
   the u16 tally passes raw ($a3 = $s2) instead of reusing a promoted
   copy; the guard and the table index keep their own andi temps, which
   is retail's shape. The callee is unaffected (still exact). */
/* Collect usable commands of the requested element and choose by predicted HP outcome. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 600). */
// FUN_001DE000
#pragma push
#pragma opt_propagation off
s32 btlAICommandCollectCommandsOfType(u8 *action, u8 *target, s16 element, s32 costPreference)
{
    extern s32 btlAICommandCollectRecoveryCommands(u8 *action, u8 *target, s16 element, s32 costPreference);
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
    unit = *(u8 **)(action + 0x30);
    queried = datCalcSkillElement(*(u8 **)(unit + 0xA64), 0);
    if (queried == element && btlAICommandNomalCheck(target, queried, 1) != 0) {
        candidates[0] = 0;
        candidateCount++;
    }
    commandCount = datCalcGetTableLength(*(DatUnit **)(unit + 0xA64));
    commands = (u16 *)datCalcSkillList(*(DatUnit **)(unit + 0xA64));
    commandIndex = 0;
    scanCount = commandCount;
    for (; commandIndex < scanCount; commandIndex++) {
        entry = commands + commandIndex;
        if (*entry == 0 || *entry >= 0x1B8)
            goto next;
        queried = datCalcSkillElement(*(u8 **)(unit + 0xA64), *entry);
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
/* measured: opt_loop_invariants on is required for the retail-sized frame and
   bubble-sort register coloring; the COP1 chain is ordinary C arithmetic and
   D_00609600 is a real, placeable linker symbol. */
#pragma opt_loop_invariants on
/* Rank candidates by missing HP and status bonus, then choose from the ranked weight table. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 558). */
// FUN_001DE370
u32 btlAICommandPickUnitByHpWeight(u8 *action)
{
    u32 candidateIndex;
    u32 random;
    u32 cumulative;
    s16 scores[16];
    u32 selectionIndex;
    u32 total;

    if (*(u16 *)(action + 0xD0) == 1)
        return *(u32 *)(action + 0x98);

    total = 0;
    candidateIndex = 0;
    while (candidateIndex < *(u16 *)(action + 0xD0)) {
        u8 *unit;
        s16 *score;
        u32 maxHp;
        u32 currentHp;
        f32 scoreFloat;
        f32 bonus;

        total += D_00609600[candidateIndex];
        unit = *(u8 **)(action + candidateIndex * 4 + 0x98);
        score = scores + candidateIndex;
        *score = 0;
        maxHp = datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64)) & 0xFFFF;
        currentHp = datCalcGetHp(*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64)) & 0xFFFF;
        *score += (s16)(100.0f - 100.0f * ((f32)currentHp / (f32)maxHp));
        switch (datCalcGetBadStatusNoDown(*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64))) {
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
        for (bubbleIndex = 0; bubbleIndex < *(u16 *)(action + 0xD0) - 1; bubbleIndex++) {
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
                swappedAction = *(u32 *)(entry + 0x98);
                *(u32 *)(entry + 0x98) = *(u32 *)(entry + 0x9C);
                *(u32 *)(entry + 0x9C) = swappedAction;
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
    for (; selectionIndex < *(u16 *)(action + 0xD0); selectionIndex++) {
        cumulative += D_00609600[selectionIndex];
        if (random < cumulative)
            return *(u32 *)((u8 *)(selectionIndex * 4) + (u32)action + 0x98);
    }
    return 0;
}
#pragma pop
/* measured: MATCH. The "coloring floor" was actually a switch-linear-chain
   declaration-order issue: MWCC tests linear-chain case labels in the REVERSE
   of their C declaration order, so the cases must be declared in the reverse
   of retail's test order, i.e. 0x8000, 0x1000, 0x2000, 0x8002, 0x8007, 0x8005,
   0x8006, 0x8001, 0x8008, 0x8009, 0x8004, default. Case 0x2000 falls through
   into case 0x8002 (separate p+0xEC store then shared q+0x34=7 body); case
   0x8004 falls through into default (v = datCalcPickSpecialItem(...)&0xFFFF then the
   shared q+0x34=2/q+0x36=v body, reusing the v parameter in $a2 exactly as
   retail). if/else t = v / v & 0xF000, then switch(t & 0xFFFF). */
/* Decode the packed action code into command-work kind, skill and plan fields. */
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
        func_001ebc00(action, work);
        break;
    case 0x8004:
        actionCode = (u16)(datCalcPickSpecialItem((u8 *)(((BtlAction *)action))->unit->datUnit) & 0xFFFF);
    default:
        ((BtlAiCommandWork *)work)->kind = 2;
        ((BtlAiCommandWork *)work)->command = actionCode;
        break;
    }
}
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

/* Measured: 288B/288B, nd 0. Separate loop locals preserve register
   lifetimes; random-first comparison selects retail's $at branch.
   The random helper takes the summed weights, not the record pointer. */
/* The 0x2C header and precomputed 0x28-byte table offset are retained to preserve the weighted-scan address order. */
/* Choose a positive-weight command from the selected five-entry AI table. */
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
        weightSum = (weightSum + *(u8 *)(node + (entryIndex & 0xffff) * 8 + 0x2c)) & 0xffff;
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
/* measured: MATCH. Two keys the earlier floor notes missed: (1) c is
   REASSIGNED from func_0029de20's return in the type==0 branch
   (`c = func_0029de20(v, buf);`), so c stays in scratch $v0 at the merge
   point instead of needing a saved register — this is what makes retail's
   lbu-into-$v0 + move-$a3 shape reproducible; (2) the `if (m >= 0)` guard
   on the 0x130 load must be SIGNED (s32) or b210 eliminates it as `u32>=0`
   always-true. t declared before d (reverse decl order -> d=$19/t=$20),
   buf[32], case 0/1 switch, iGpffffb444 + x*21 chain. */
/* The scheduler task prefix remains opaque here; +0x20 supplies the procedure priority, decremented by one. */
/* Start the action procedure, set its message name and attach it to the battle task. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 231). */
// FUN_001DEBB0
s32 btlAICommandSpawnActionProc(u8 *action, u8 *work, u32 scriptData, u32 procedureId)
{
    u8 procedureName[32];
    u32 procedureValue;
    u32 procedureTask;
    u32 speakerName;
    u32 procedureWork;

    if (*(u8 *)(*(u32 *)(action + 0x30) + 0xA2) == 0) {
        procedureValue = *(u8 *)(*(u32 *)(*(u32 *)(action + 0x30) + 0xA64) + 0x10);
        sprintf(procedureName, D_00609E20, procedureId, procedureValue);
        procedureValue = scrFindPrcdIdxByName(scriptData, procedureName);
    } else {
        procedureValue = procedureId;
    }
    procedureTask = scrStartProcedureIndex((u8 *)(*(u32 *)(*(u32 *)(iGpffffb3ac + 0xDC8) + 0x20) - 1), scriptData, procedureValue);
    scrSetTaskProc(procedureTask, action);
    procedureWork = (u32)kwlnTaskGetWork(procedureTask);
    if (*(s32 *)(procedureWork + 0x130) >= 0) {
        switch (*(u8 *)(*(u32 *)(action + 0x30) + 0xA2)) {
        case 0:
            speakerName = (u32)datPersonaNamePart1Alt(*(s16 *)(*(u32 *)(action + 0x30) + 0xA4));
            break;
        case 1:
            speakerName = (u32)iGpffffb444 + (*(u16 *)(*(u32 *)(action + 0x30) + 0xA4)) * 21;
            break;
        }
        itfMesWindowSetString(*(s32 *)(procedureWork + 0x130), 0, speakerName);
    }
    kwlnTaskAddChild((u8 *)(*(u32 *)(iGpffffb3ac + 0xDC8)), procedureTask);
    *(u32 *)(work + 0x4C) = procedureTask;
    return 1;
}
/* measured: three 1-2 word scheduler residuals. (1) case 1's chain: retail
   loads iGpffffb3d0 FIRST (lw $a0,-0x4c30) then computes (a4&0xFFFF)*164 and
   addu $v0,$v0,$a0, while mwcc b210 sinks the global load after the chain and
   emits addu $v0,$v0,$v1 (base-first); (2) the v2 > 0 test's u16 mask lands in
   $v0 instead of retail's $a3; (3) func_001de640's args materialize lhu-before-
   moves instead of moves-then-lhu. Tried chain-first/global-first spellings and
   a g = iGpffffb3d0 local inside the case — all identical 16. Load-sinking +
   $v0/$v1-coloring floor. */
/* Ported from P3FES btlEffect.c func_002c70d0 (action dispatch, switch type 0/1).
   func_002d15a0->func_001eb3b0, func_002c6f50->func_001debb0, func_002c6ba0->func_001de800,
   func_002c6e30->btlAISelectWeightedEntry, func_002c6a00->func_001de640, PTR_FUN_006975e0->D_00609CE0;
   DAT_007ce41c->iGpffffb3d0 (integer-domain address forces the early base load),
   DAT_007ce4cc->iGpffffb3cc, DAT_007ce4d0->iGpffffb42c. func_001de800 declared
   locally as u32 to keep the &0xFFFF mask from folding to 0xff. */
/* Use an explicit AI procedure when present, otherwise decode a weighted table command. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 262). */
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

    baseActionId = *(u16 *)(*(s32 *)(action + 0x30) + 0xa4);
    func_001eb3b0((u8 *)work);
    genus = *(u8 *)(*(s32 *)(action + 0x30) + 0xa2);
    switch (genus) {
    case 0:
        actionId = baseActionId;
        scriptData = (u32)iGpffffb428;
        break;
    case 1:
        {
            u8 *aiRecord;
            u32 recordOffset;

            /* measured: the integer-domain address spelling forces the early base load (retail lw $a0,-0x4c30($gp) first), ported from donor func_002c70d0 */
            aiRecord = *(u8 **)((u32)&iGpffffb3d0);
            recordOffset = ((u32)baseActionId * 0x28 + (u32)baseActionId) * 4;
            aiRecord = (u8 *)(recordOffset) + (s32)aiRecord;
            actionId = *(u16 *)(aiRecord + 2);
            scriptData = (u32)iGpffffb42c;
        }
        break;
    }
    if (actionId > 0) {
        btlAICommandSpawnActionProc((u8 *)action, (u8 *)work, scriptData, actionId);
        *(u8 *)(work + 0x30) = 1;
    }
    else {
        extern u32 btlAICommandPickTableAction(u8 *);
        actionId = btlAICommandPickTableAction((u8 *)action) & 0xFFFF;
        weightedCommand = (s32)btlAISelectWeightedEntry((u8 *)action, actionId);
        btlAICommandSetActionCode((u8 *)action, (u8 *)work, *(u16 *)(weightedCommand + 2));
        packedCondition = *(u32 *)(weightedCommand + 4);
        conditionResult = ((s32 (*)(u8 *, u32))D_00609CE0[((packedCondition & 0xff000000) >> 0x18) * 2])((u8 *)action, packedCondition & 0xffffff);
        if (conditionResult == 0) {
            ((s32 (*)(u8 *, u32))D_00609CE0[0])((u8 *)action, 0);
        }
    }
}


/* Clear the procedure-active flag and task handle after the task is no longer linked. */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 86). */
// FUN_001DEEE0
u32 btlAICommandTryReleaseProc(s32 work)
{
  u32 released = 0;
  long taskLinked = 0;

  if (*(u8 *)(work + 0x30) == 0) {
    released = 1;
  }
  else if (*(s32 *)(work + 0x4c) == 0) {
    released = 1;
  }
  else {
    taskLinked = kwlnTaskIsLinked(*(s32 *)(work + 0x4c));
    if (taskLinked == 0) {
      *(u8 *)(work + 0x30) = 0;
      *(u32 *)(work + 0x4c) = 0;
      released = 1;
    }
    else {
      released = 0;
    }
  }
  return released;
}



/* AI script command 0x203d (p4flow AI.json AI_FUNCTION_003D). */
// FUN_001DEF60
u32 btlAICommandScriptSetDefaultAction(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *action = (char *)scrGetAiState();

  btlAICommandSetActionCode(action, action + 0x38, 0x8000);
  return 1;
}



/* AI script command 0x203e (p4flow AI.json AI_FUNCTION_003E). */
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

/* AI script command 0x2068 (p4flow AI.json AI_FUNCTION_0068). */
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

/* AI script command 0x203f (p4flow AI.json AI_FUNCTION_003F). */
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



/* AI script command 0x2040 (p4flow AI.json AI_FUNCTION_0040). */
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



/* AI script command 0x20d5 (p4flow AI.json AI_FUNCTION_00D5). */
// FUN_001DF140
s32 btlAICommandScriptSetActionSubword(void) {
    u8 *action = scrGetAiState();
    ((u16 *)((BtlAction *)action)->targetBlock.unk_e8)[2] = scrGetParamInt(0);
    btlAICommandSetActionCode(action, action + 0x38, 0x8002);
    return 1;
}

/* AI script command 0x2041 (p4flow AI.json AI_FUNCTION_0041). */
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

/* AI script command 0x2059 (p4flow AI.json AI_FUNCTION_0059). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 113). */
// FUN_001DF230
s32 btlAICommandScriptSetAiPlanWithArg(void) {
    u8 *action = scrGetAiState();
    *(u16 *)(action + 0x6C) = 9;
    *(u16 *)(action + 0x6E) = 0x111;
    *(u16 *)(action + 0x76) = scrGetParamInt(0);
    *(u16 *)(action + 0x78) = scrGetParamInt(1);
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2048 (p4flow AI.json AI_FUNCTION_0048). */
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



/* AI script command 0x2000 (p4flow AI.json AI_FUNCTION_0000). */
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

/* AI script command 0x2001 (p4flow AI.json AI_FUNCTION_0001). */
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

/* AI script command 0x2002 (p4flow AI.json AI_FUNCTION_0002). */
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

/* AI script command 0x2003 (p4flow AI.json AI_FUNCTION_0003). */
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

/* AI script command 0x2004 (p4flow AI.json AI_FUNCTION_0004). */
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

/* AI script command 0x2005 (p4flow AI.json AI_FUNCTION_0005). */
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

/* AI script command 0x2006 (p4flow AI.json AI_FUNCTION_0006). */
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

/* AI script command 0x2007 (p4flow AI.json AI_FUNCTION_0007). */
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

/* AI script command 0x2008 (p4flow AI.json AI_FUNCTION_0008). */
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

/* AI script command 0x2009 (p4flow AI.json AI_FUNCTION_0009). */
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

/* AI script command 0x200a (p4flow AI.json AI_FUNCTION_000A). */
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

/* AI script command 0x200b (p4flow AI.json AI_FUNCTION_000B). */
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

/* AI script command 0x200c (p4flow AI.json AI_FUNCTION_000C). */
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

/* AI script command 0x200d (p4flow AI.json AI_FUNCTION_000D). */
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

/* AI script command 0x200e (p4flow AI.json AI_FUNCTION_000E). */
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

/* AI script command 0x200f (p4flow AI.json AI_FUNCTION_000F). */
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

/* AI script command 0x2010 (p4flow AI.json AI_FUNCTION_0010). */
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

/* AI script command 0x2011 (p4flow AI.json AI_FUNCTION_0011). */
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

/* AI script command 0x2012 (p4flow AI.json AI_FUNCTION_0012). */
// FUN_001DFF70
s32 btlAICommandScriptQueryEscape(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609934[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2013 (p4flow AI.json AI_FUNCTION_0013). */
// FUN_001DFFC0
s32 btlAICommandScriptQuerySummon(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609940[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2014 (p4flow AI.json AI_FUNCTION_0014). */
// FUN_001E0010
s32 btlAICommandScriptQuerySensei(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_0060994C[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2015 (p4flow AI.json AI_FUNCTION_0015). */
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

/* AI script command 0x2016 (p4flow AI.json AI_FUNCTION_0016). */
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

/* AI script command 0x2017 (p4flow AI.json AI_FUNCTION_0017). */
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

/* AI script command 0x2018 (p4flow AI.json AI_FUNCTION_0018). */
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

/* AI script command 0x2019 (p4flow AI.json AI_FUNCTION_0019). */
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

/* AI script command 0x201a (p4flow AI.json AI_FUNCTION_001A). */
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

/* AI script command 0x201b (p4flow AI.json AI_FUNCTION_001B). */
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

/* AI script command 0x201c (p4flow AI.json AI_FUNCTION_001C). */
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

/* AI script command 0x201d (p4flow AI.json AI_FUNCTION_001D). */
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

/* AI script command 0x201e (p4flow AI.json AI_FUNCTION_001E). */
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

/* AI script command 0x201f (p4flow AI.json AI_FUNCTION_001F). */
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

/* AI script command 0x2020 (p4flow AI.json AI_FUNCTION_0020). */
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

/* AI script command 0x2021 (p4flow AI.json AI_FUNCTION_0021). */
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

/* AI script command 0x2022 (p4flow AI.json AI_FUNCTION_0022). */
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

/* AI script command 0x2023 (p4flow AI.json AI_FUNCTION_0023). */
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

/* AI script command 0x2024 (p4flow AI.json AI_FUNCTION_0024). */
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

/* AI script command 0x2025 (p4flow AI.json AI_FUNCTION_0025). */
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

/* AI script command 0x2026 (p4flow AI.json AI_FUNCTION_0026). */
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

/* AI script command 0x2027 (p4flow AI.json AI_FUNCTION_0027). */
// FUN_001E0CC0
s32 btlAICommandScriptQueryMyGroup(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A30[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2028 (p4flow AI.json AI_FUNCTION_0028). */
// FUN_001E0D10
s32 btlAICommandScriptQueryFrGroup(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A3C[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2029 (p4flow AI.json AI_FUNCTION_0029). */
// FUN_001E0D60
s32 btlAICommandScriptQueryEnGroup(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A48[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x202a (p4flow AI.json AI_FUNCTION_002A). */
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

/* AI script command 0x202b (p4flow AI.json AI_FUNCTION_002B). */
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

/* AI script command 0x2046 (p4flow AI.json AI_FUNCTION_0046). */
// FUN_001E0F10
s32 btlAICommandScriptQueryMyHrec(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A6C[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2047 (p4flow AI.json AI_FUNCTION_0047). */
// FUN_001E0F60
s32 btlAICommandScriptQueryMore(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609A78[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2051 (p4flow AI.json AI_FUNCTION_0051). */
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

/* AI script command 0x2052 (p4flow AI.json AI_FUNCTION_0052). */
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

/* AI script command 0x2053 (p4flow AI.json AI_FUNCTION_0053). */
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

/* AI script command 0x2054 (p4flow AI.json AI_FUNCTION_0054). */
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

/* AI script command 0x2055 (p4flow AI.json AI_FUNCTION_0055). */
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

/* AI script command 0x2056 (p4flow AI.json AI_FUNCTION_0056). */
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

/* AI script command 0x2057 (p4flow AI.json AI_FUNCTION_0057). */
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

/* AI script command 0x2058 (p4flow AI.json AI_FUNCTION_0058). */
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

/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x205a (p4flow AI.json AI_FUNCTION_005A). */
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


/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x205b (p4flow AI.json AI_FUNCTION_005B). */
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


/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x205c (p4flow AI.json AI_FUNCTION_005C). */
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


/* Ported from P3FES btlEffect.c func_002c9ba0 (argument sideMask dispatch,
   selector tag 0x0b000000, inline shift). func_0035ed20->scrGetParamInt,
   func_0035f160->func_0029d050, func_002c0e30->btlEffectFindUnitByIdAndStatus,
   func_0035f060->scrSetReturnInt, gFormationDispatchTable->D_00609850. */
/* AI script command 0x205d (p4flow AI.json AI_FUNCTION_005D). */
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

/* AI script command 0x205e (p4flow AI.json AI_FUNCTION_005E). */
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

/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x205f (p4flow AI.json AI_FUNCTION_005F). */
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


/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x2060 (p4flow AI.json AI_FUNCTION_0060). */
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


/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x2061 (p4flow AI.json AI_FUNCTION_0061). */
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


/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x2062 (p4flow AI.json AI_FUNCTION_0062). */
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


/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x2063 (p4flow AI.json AI_FUNCTION_0063). */
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


/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x2064 (p4flow AI.json AI_FUNCTION_0064). */
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


/* AI script command 0x2065 (p4flow AI.json AI_FUNCTION_0065). */
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

/* AI script command 0x2066 (p4flow AI.json AI_FUNCTION_0066). */
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

/* measured: mwcc b210 folds f = (a == 0) into an xor/sltiu booleanize no matter
   the spelling (if/else, ternary, inline in the shift, f = 0 first, switch,
   goto) while retail keeps a branchy set (bnez $v0,L; addiu $v0,1; b; L: move
   $v0,0), which then shifts the whole dispatch tail by 4 words; same fold floor
   as FUN_001DB7D0. The rest (9280 arg order, dsll32/dsrl32 24-bit masks, the
   e*3 table call) all compile correctly when f is the only difference. */
/* Ported from P3FES btlEffect.c func_002ca480 (dispatch handler, 8-alt clone
   family). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850; selector tag 0x01000000. */
#pragma opt_rebuildconditionals off
/* AI script command 0x209e (p4flow AI.json AI_FUNCTION_009E). */
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
#pragma opt_rebuildconditionals on


/* measured: re-verified this wave — the goto-form body compiles the whole
   function byte-identically except the inner-else branch: retail b 0x1e22b4
   (branch-to-branch through the outer tail jump) vs mwcc b210 b 0x1e22c0
   (threaded straight to the join). Tried this wave: double-goto both-paths
   into the merge label (nd 4), explicit goto out2 closing the r!=0 block
   (nd 4), label inside the block (nd 4), #pragma opt_propagation off
   (nd 62), opt_common_subs off (nd 4), schedule off (nd 4). Still nd 4 =
   1 word + 3 reloc words; same wall as the previous wave. Branch-to-branch
   sharing floor (corroborated in mdlManager/datCalc). */
/* Ported from P3FES btlEffect.c func_002ca590 (dispatch handler, 8-alt clone
   family, selector tag 0x02000000). Same mapping as FUN_001E20D0. */
#pragma opt_rebuildconditionals off
/* AI script command 0x209f (p4flow AI.json AI_FUNCTION_009F). */
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
#pragma opt_rebuildconditionals on



/* measured: branchy shift set reproduces with the goto form under
   #pragma opt_rebuildconditionals off; only residual is 1 word — retail's
   x=0 path jumps to the call-path tail jump (branch-to-branch) while mwcc
   b210 peepholes it straight to the merge. nd 4 = that word + reloc words;
   same wall as FUN_001E21E0; switch(cond) dispatch form re-lays-out the
   whole tail (nd 30) so if/else is the closer shape. */
/* measured: re-verified this wave — same recipe body as FUN_001E21E0 (goto
   shift set + pragma off); the sole residual is again the threaded branch:
   retail b 0x1e23c4 (branch-to-branch) vs mwcc b210 b 0x1e23d0. nd 4 = 1
   word + 3 reloc words. Branch-to-branch sharing floor. */
/* Ported from P3FES btlEffect.c func_002ca6a0 (dispatch handler, 8-alt clone
   family, selector tag 0x06000000). Same mapping as FUN_001E20D0. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20a0 (p4flow AI.json AI_FUNCTION_00A0). */
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
#pragma opt_rebuildconditionals on



/* Ported from P3FES btlEffect.c func_002ca7b0 (argument sideMask dispatch,
   selector tag 0x0b000000). func_0035ed20->scrGetParamInt, func_0035f160->func_0029d050,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. Pragma for branchy shift set. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20a1 (p4flow AI.json AI_FUNCTION_00A1). */
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
#pragma opt_rebuildconditionals on



/* AI script command 0x210e (p4flow AI.json AI_FUNCTION_010E). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 134). */
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

    selector = (1 << (*(u8 *)(*(u32 *)(scrGetAiState() + 0x30) + 0xA2))) & 0xFFFF;
    unitValue = scrGetParamInt(0) & 0xFFFF;
    statusMask = scrGetParamInt(1);
    livingCount = 0;
    matchingCount = 0;
    candidateAction = *(u8 **)(iGpffffb3ac + 0x174);
    sideMask = selector & 0xFFFF;
    unitId = unitValue & 0xFFFF;
    while (candidateAction != 0) {
        if ((*(u16 *)(candidateAction + 0x1A) & 1) && (*(u16 *)(candidateAction + 0x1A) & 8)) {
            unit = *(u8 **)(candidateAction + 0x30);
            if ((sideMask & (1 << (*(u8 *)(unit + 0xA2)))) != 0) {
                if (*(u16 *)(unit + 0xA4) == unitId) {
                    if (datCalcIsDead(*(u32 *)(unit + 0xA64), 0) == 0) {
                        livingCount = (livingCount + 1) & 0xFFFF;
                        if (datCalcChkBadStatus(*(u32 *)(unit + 0xA64), statusMask) != 0) {
                            matchingCount = (matchingCount + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        candidateAction = *(u8 **)(candidateAction + 0x450);
    }
    allMatch = 0;
    if ((livingCount & 0xFFFF) > 0 && (livingCount & 0xFFFF) == (matchingCount & 0xFFFF))
        allMatch = 1;
    scrSetReturnInt(allMatch != 0);
    return 1;
}

/* measured: byte-exact at nd 0. Reusing the c0 local for the node payload
   and m for the post-call c02 value gives retail's saved-register live
   ranges; #pragma opt_rebuildconditionals off preserves the branchy shift
   sequence and its 392-byte object (retail window 400 bytes). */
/* AI script command 0x210d (p4flow AI.json AI_FUNCTION_010D). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 134). */
// FUN_001E26C0
/* measured: retains the branch-rebuild setting required for the byte-exact body. */
#pragma opt_rebuildconditionals off
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

    if (*(u8 *)(*(u8 **)(scrGetAiState() + 0x30) + 0xa2) != 0)
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
    candidateAction = *(u8 **)(iGpffffb3ac + 0x174);
    sideMask = selector & 0xffff;
    selector = (u32)unitValue & 0xffff;
    while (candidateAction != 0) {
        if ((*(u16 *)(candidateAction + 0x1a) & 1) && (*(u16 *)(candidateAction + 0x1a) & 8)) {
            unitValue = *(u8 **)(candidateAction + 0x30);
            if ((sideMask & (1 << (*(u8 *)(unitValue + 0xa2)))) != 0) {
                if (*(u16 *)(unitValue + 0xa4) == selector) {
                    if (datCalcIsDead(*(u32 *)(unitValue + 0xa64), 0) == 0) {
                        livingCount = (livingCount + 1) & 0xffff;
                        if (datCalcChkBadStatus(*(u32 *)(unitValue + 0xa64), statusMask) != 0)
                            matchingCount = (matchingCount + 1) & 0xffff;
                    }
                }
            }
        }
        candidateAction = *(u8 **)(candidateAction + 0x450);
    }
    allMatch = 0;
    if ((livingCount & 0xffff) > 0 && (livingCount & 0xffff) == (matchingCount & 0xffff))
        allMatch = 1;
    scrSetReturnInt(allMatch != 0);
    return 1;
}
/* measured: closes the conditional-rebuild scope for FUN_001E26C0. */
#pragma opt_rebuildconditionals on

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001E2850 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* AI script command 0x20a2 (p4flow AI.json AI_FUNCTION_00A2). */
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
#pragma opt_rebuildconditionals on

/* AI script command 0x2111 (p4flow AI.json AI_FUNCTION_0111). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 134). */
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

    selector = (1 << (*(u8 *)(*(u32 *)(scrGetAiState() + 0x30) + 0xA2))) & 0xFFFF;
    unitValue = scrGetParamInt(0) & 0xFFFF;
    statusMask = scrGetParamInt(1);
    livingCount = 0;
    matchingCount = 0;
    candidateAction = *(u8 **)(iGpffffb3ac + 0x174);
    sideMask = selector & 0xFFFF;
    unitId = unitValue & 0xFFFF;
    while (candidateAction != 0) {
        if ((*(u16 *)(candidateAction + 0x1A) & 1) && (*(u16 *)(candidateAction + 0x1A) & 8)) {
            unit = *(u8 **)(candidateAction + 0x30);
            if ((sideMask & (1 << (*(u8 *)(unit + 0xA2)))) != 0) {
                if (*(u16 *)(unit + 0xA4) == unitId) {
                    if (datCalcIsDead(*(u32 *)(unit + 0xA64), 0) == 0) {
                        livingCount = (livingCount + 1) & 0xFFFF;
                        if (datCalcHasBuffMask(*(DatUnit **)(unit + 0xA64), statusMask) != 0) {
                            matchingCount = (matchingCount + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        candidateAction = *(u8 **)(candidateAction + 0x450);
    }
    allMatch = 0;
    if ((livingCount & 0xFFFF) > 0 && (livingCount & 0xFFFF) == (matchingCount & 0xFFFF))
        allMatch = 1;
    scrSetReturnInt(allMatch != 0);
    return 1;
}

/* measured: byte-exact sibling of FUN_001E26C0; reusing c0 for the node
   payload and m for c02 with conditional rebuilds disabled gives nd 0. */
/* AI script command 0x2110 (p4flow AI.json AI_FUNCTION_0110). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 134). */
// FUN_001E2A80
#pragma opt_rebuildconditionals off
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

    if (*(u8 *)(*(u8 **)(scrGetAiState() + 0x30) + 0xa2) != 0)
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
    candidateAction = *(u8 **)(iGpffffb3ac + 0x174);
    sideMask = selector & 0xffff;
    selector = (u32)unitValue & 0xffff;
    while (candidateAction != 0) {
        if ((*(u16 *)(candidateAction + 0x1a) & 1) && (*(u16 *)(candidateAction + 0x1a) & 8)) {
            unitValue = *(u8 **)(candidateAction + 0x30);
            if ((sideMask & (1 << (*(u8 *)(unitValue + 0xa2)))) != 0) {
                if (*(u16 *)(unitValue + 0xa4) == selector) {
                    if (datCalcIsDead(*(u32 *)(unitValue + 0xa64), 0) == 0) {
                        livingCount = (livingCount + 1) & 0xffff;
                        if (datCalcHasBuffMask(*(DatUnit **)(unitValue + 0xa64), statusMask) != 0)
                            matchingCount = (matchingCount + 1) & 0xffff;
                    }
                }
            }
        }
        candidateAction = *(u8 **)(candidateAction + 0x450);
    }
    allMatch = 0;
    if ((livingCount & 0xffff) > 0 && (livingCount & 0xffff) == (matchingCount & 0xffff))
        allMatch = 1;
    scrSetReturnInt(allMatch != 0);
    return 1;
}
/* measured: closes the conditional-rebuild scope for the byte-exact body. */
#pragma opt_rebuildconditionals on

/* measured: branchy shift set reproduces with the goto form under
   #pragma opt_rebuildconditionals off; only residual is 1 word — retail's
   x=0 path jumps to the call-path tail jump (branch-to-branch) while mwcc
   b210 peepholes it straight to the merge. nd 4 = that word + reloc words;
   same wall as FUN_001E21E0. */
/* Ported from P3FES btlEffect.c func_002ca9d0 (dispatch handler, 8-alt clone
   family, selector tag 0x16000000). Same mapping as FUN_001E20D0. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20a3 (p4flow AI.json AI_FUNCTION_00A3). */
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
#pragma opt_rebuildconditionals on



/* measured: branchy shift set reproduces with the goto form under
   #pragma opt_rebuildconditionals off; only residual is 1 word — retail's
   x=0 path jumps to the call-path tail jump (branch-to-branch) while mwcc
   b210 peepholes it straight to the merge. nd 4 = that word + reloc words;
   same wall as FUN_001E21E0. */
/* measured: re-verified this wave — same recipe body as FUN_001E21E0 (goto
   shift set + pragma off, const 0x17000000); sole residual is the threaded
   branch: retail b to the call-path tail jump (branch-to-branch) vs mwcc b210
   straight to the join. nd 4 = 1 word + 3 reloc words. Branch-to-branch
   sharing floor, same as FUN_001E21E0. */
/* Ported from P3FES btlEffect.c func_002caae0 (dispatch handler, 8-alt clone
   family, selector tag 0x17000000). Same mapping as FUN_001E20D0. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20a4 (p4flow AI.json AI_FUNCTION_00A4). */
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
#pragma opt_rebuildconditionals on



/* measured: branchy shift set reproduces with the goto form under
   #pragma opt_rebuildconditionals off; only residual is 1 word — retail's
   x=0 path jumps to the call-path tail jump (branch-to-branch) while mwcc
   b210 peepholes it straight to the merge. nd 4 = that word + reloc words;
   same wall as FUN_001E21E0. */
/* measured: re-verified this wave — same recipe body as FUN_001E21E0 (goto
   shift set + pragma off, const 0x18000000); sole residual is the threaded
   branch: retail b to the call-path tail jump (branch-to-branch) vs mwcc b210
   straight to the join. nd 4 = 1 word + 3 reloc words. Branch-to-branch
   sharing floor, same as FUN_001E21E0. */
/* Ported from P3FES btlEffect.c func_002cabf0 (dispatch handler, 8-alt clone
   family, selector tag 0x18000000). Same mapping as FUN_001E20D0. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20a5 (p4flow AI.json AI_FUNCTION_00A5). */
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
#pragma opt_rebuildconditionals on



/* measured: branchy shift set reproduces with the goto form under
   #pragma opt_rebuildconditionals off; only residual is 1 word — retail's
   x=0 path jumps to the call-path tail jump (branch-to-branch) while mwcc
   b210 peepholes it straight to the merge. nd 4 = that word + reloc words;
   same wall as FUN_001E21E0. */
/* measured: re-verified this wave — same recipe body as FUN_001E21E0 (goto
   shift set + pragma off, const 0x19000000); sole residual is the threaded
   branch: retail b to the call-path tail jump (branch-to-branch) vs mwcc b210
   straight to the join. nd 4 = 1 word + 3 reloc words. Branch-to-branch
   sharing floor, same as FUN_001E21E0. */
/* Ported from P3FES btlEffect.c func_002cad00 (dispatch handler, 8-alt clone
   family, selector tag 0x19000000). Same mapping as FUN_001E20D0. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20a6 (p4flow AI.json AI_FUNCTION_00A6). */
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
#pragma opt_rebuildconditionals on



/* measured: branchy shift set reproduces with the goto form under
   #pragma opt_rebuildconditionals off; only residual is 1 word — retail's
   x=0 path jumps to the call-path tail jump (branch-to-branch) while mwcc
   b210 peepholes it straight to the merge. nd 4 = that word + reloc words;
   same wall as FUN_001E21E0. */
/* measured: re-verified this wave — same recipe body as FUN_001E21E0 (goto
   shift set + pragma off, const 0x22000000); sole residual is the threaded
   branch: retail b to the call-path tail jump (branch-to-branch) vs mwcc b210
   straight to the join. nd 4 = 1 word + 3 reloc words. Branch-to-branch
   sharing floor, same as FUN_001E21E0. */
/* Ported from P3FES btlEffect.c func_002cae10 (dispatch handler, 8-alt clone
   family, selector tag 0x22000000). Same mapping as FUN_001E20D0. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20a7 (p4flow AI.json AI_FUNCTION_00A7). */
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
#pragma opt_rebuildconditionals on



/* measured: branchy shift set reproduces with the goto form under
   #pragma opt_rebuildconditionals off; only residual is 1 word — retail's
   x=0 path jumps to the call-path tail jump (branch-to-branch) while mwcc
   b210 peepholes it straight to the merge. nd 4 = that word + reloc words;
   same wall as FUN_001E21E0. */
/* measured: re-verified this wave — same recipe body as FUN_001E21E0 (goto
   shift set + pragma off, const 0x25000000); sole residual is the threaded
   branch: retail b to the call-path tail jump (branch-to-branch) vs mwcc b210
   straight to the join. nd 4 = 1 word + 3 reloc words. Branch-to-branch
   sharing floor, same as FUN_001E21E0. */
/* Ported from P3FES btlEffect.c func_002caf20 (dispatch handler, 8-alt clone
   family, selector tag 0x25000000). Same mapping as FUN_001E20D0. */
#pragma opt_rebuildconditionals off
/* AI script command 0x20a8 (p4flow AI.json AI_FUNCTION_00A8). */
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
#pragma opt_rebuildconditionals on



/* AI script command 0x20a9 (p4flow AI.json AI_FUNCTION_00A9). */
// FUN_001E3270
#pragma opt_rebuildconditionals off
/* Removing this loses FUNC_001E3270 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

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
#pragma opt_rebuildconditionals on

/* AI script command 0x20aa (p4flow AI.json AI_FUNCTION_00AA). */
// FUN_001E3320
#pragma opt_rebuildconditionals off
/* Removing this loses FUNC_001E3320 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

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
#pragma opt_rebuildconditionals on

/* AI script command 0x2069 (p4flow AI.json AI_FUNCTION_0069). */
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

/* AI script command 0x206a (p4flow AI.json AI_FUNCTION_006A). */
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

/* AI script command 0x206b (p4flow AI.json AI_FUNCTION_006B). */
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

/* AI script command 0x206c (p4flow AI.json AI_FUNCTION_006C). */
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

/* AI script command 0x206d (p4flow AI.json AI_FUNCTION_006D). */
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

/* AI script command 0x206e (p4flow AI.json AI_FUNCTION_006E). */
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

/* AI script command 0x206f (p4flow AI.json AI_FUNCTION_006F). */
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

/* AI script command 0x2070 (p4flow AI.json AI_FUNCTION_0070). */
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

/* AI script command 0x2071 (p4flow AI.json AI_FUNCTION_0071). */
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

/* AI script command 0x2072 (p4flow AI.json AI_FUNCTION_0072). */
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

/* AI script command 0x2073 (p4flow AI.json AI_FUNCTION_0073). */
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

/* AI script command 0x2074 (p4flow AI.json AI_FUNCTION_0074). */
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

/* AI script command 0x2092 (p4flow AI.json AI_FUNCTION_0092). */
// FUN_001E3C40
s32 btlAICommandScriptQueryAnalyze(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609B74[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2093 (p4flow AI.json AI_FUNCTION_0093). */
// FUN_001E3C90
s32 btlAICommandScriptQueryDown(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609B80[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x2094 (p4flow AI.json AI_FUNCTION_0094). */
// FUN_001E3CE0
s32 btlAICommandScriptQuerySlip(void) {
    scrSetReturnInt(((s32 (*)(u8 *, s32))D_00609B8C[0])(scrGetAiState(), 0) != 0);
    return 1;
}

/* AI script command 0x20af (p4flow AI.json AI_FUNCTION_00AF). */
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

/* Ported from P3FES btlEffect.c func_002cbba0 (side-switch dispatch, selector
   tag 0x19000000). func_0035ed20->scrGetParamInt, func_002c0e30->btlEffectFindUnitByIdAndStatus,
   func_0035f060->scrSetReturnInt, gFormationDispatchTable->D_00609850. id is u32
   (masked & 0xFFFF) because btlEffectFindUnitByIdAndStatus takes s32. switch cases ascending 0/1. */
/* AI script command 0x20b9 (p4flow AI.json AI_FUNCTION_00B9). */
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

/* AI script command 0x20ba (p4flow AI.json AI_FUNCTION_00BA). */
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

/* AI script command 0x20d6 (p4flow AI.json AI_FUNCTION_00D6). */
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

/* AI script command 0x20d7 (p4flow AI.json AI_FUNCTION_00D7). */
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

/* AI script command 0x20d8 (p4flow AI.json AI_FUNCTION_00D8). */
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

/* AI script command 0x20c9 (p4flow AI.json AI_FUNCTION_00C9). */
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

/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x20cb (p4flow AI.json AI_FUNCTION_00CB). */
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


/* AI script command 0x20cc (p4flow AI.json AI_FUNCTION_00CC). */
// FUN_001E43D0
s32 btlAICommandScriptSelfHasBuff(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(datCalcHasBuffMask((((BtlAction *)action))->unit->datUnit, scrGetParamInt(0)) != 0);
    return 1;
}

/* Ported from P3FES btlEffect.c dispatch handler (10-alt clone family, inline
   shift). func_0035f160->func_0029d050, func_0035ed20->scrGetParamInt,
   func_002c0e30->btlEffectFindUnitByIdAndStatus, func_0035f060->scrSetReturnInt,
   gFormationDispatchTable->D_00609850. No pragma needed (inline shift). */
/* AI script command 0x20d4 (p4flow AI.json AI_FUNCTION_00D4). */
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


/* AI script command 0x20d9 (p4flow AI.json AI_FUNCTION_00D9). */
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

/* AI script command 0x20e0 (p4flow AI.json AI_FUNCTION_00E0). */
// FUN_001E45D0
s32 btlAICommandScriptAlwaysFalse(void) {
    scrSetReturnInt(0);
    return 1;
}

/* AI script command 0x20eb (p4flow AI.json AI_FUNCTION_00EB). */
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

/* AI script command 0x20ec (p4flow AI.json AI_FUNCTION_00EC). */
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

/* AI script command 0x20ed (p4flow AI.json AI_FUNCTION_00ED). */
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

/* AI script command 0x202c (p4flow AI.json AI_FUNCTION_002C). */
// FUN_001E4810
s32 btlAICommandScriptRunAi(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x202d (p4flow AI.json AI_FUNCTION_002D). */
// FUN_001E4880
s32 btlAICommandAiUnlessHpMin(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CE8[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x202e (p4flow AI.json AI_FUNCTION_002E). */
// FUN_001E48F0
s32 btlAICommandAiUnlessLvMin(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CF0[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x202f (p4flow AI.json AI_FUNCTION_002F). */
// FUN_001E4960
s32 btlAICommandAiUnlessMpMax(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CF8[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2030 (p4flow AI.json AI_FUNCTION_0030). */
// FUN_001E49D0
s32 btlAICommandCondQueryBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x4000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2031 (p4flow AI.json AI_FUNCTION_0031). */
// FUN_001E4A80
s32 btlAICommandCondQueryNotBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x5000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x210c (p4flow AI.json AI_FUNCTION_010C). */
// FUN_001E4B30
s32 btlAICommandScriptPickMyIdFromArgs(void) {
    u32 unitId = scrGetParamInt(0);
    u32 excludedStatus = scrGetParamInt(1);
    btlAICommandSelectCandidates(scrGetAiState(), unitId, excludedStatus, 0, 0, btlCond_MYID);
    return 1;
}

/* AI script command 0x2032 (p4flow AI.json AI_FUNCTION_0032). */
// FUN_001E4BB0
s32 btlAICommandCondQueryId(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x6000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2033 (p4flow AI.json AI_FUNCTION_0033). */
// FUN_001E4C60
s32 btlAICommandAiUnlessMine(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D18[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2034 (p4flow AI.json AI_FUNCTION_0034). */
// FUN_001E4CD0
s32 btlAICommandAiUnlessMyAi(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2035 (p4flow AI.json AI_FUNCTION_0035). */
// FUN_001E4D40
s32 btlAICommandCondQueryHansya(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x9000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2036 (p4flow AI.json AI_FUNCTION_0036). */
// FUN_001E4DF0
s32 btlAICommandCondQueryKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xA000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2037 (p4flow AI.json AI_FUNCTION_0037). */
// FUN_001E4EA0
s32 btlAICommandCondQueryMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xB000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2038 (p4flow AI.json AI_FUNCTION_0038). */
// FUN_001E4F50
s32 btlAICommandCondQueryWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xC000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2039 (p4flow AI.json AI_FUNCTION_0039). */
// FUN_001E5000
s32 btlAICommandCondQueryNotHansya(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xD000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x203a (p4flow AI.json AI_FUNCTION_003A). */
// FUN_001E50B0
s32 btlAICommandCondQueryNotKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xE000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x203b (p4flow AI.json AI_FUNCTION_003B). */
// FUN_001E5160
s32 btlAICommandCondQueryNotMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xF000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x203c (p4flow AI.json AI_FUNCTION_003C). */
// FUN_001E5210
s32 btlAICommandCondQueryNotWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x10000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2043 (p4flow AI.json AI_FUNCTION_0043). */
// FUN_001E52C0
s32 btlAICommandAiUnlessAppoint(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D70[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2044 (p4flow AI.json AI_FUNCTION_0044). */
// FUN_001E5330
s32 btlAICommandAiUnlessDown(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D78[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2045 (p4flow AI.json AI_FUNCTION_0045). */
// FUN_001E53A0
s32 btlAICommandAiUnlessStand(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D80[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2049 (p4flow AI.json AI_FUNCTION_0049). */
// FUN_001E5410
s32 btlAICommandCondQueryHansyaSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x15000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x204a (p4flow AI.json AI_FUNCTION_004A). */
// FUN_001E54C0
s32 btlAICommandCondQueryKyusyuSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x16000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x204b (p4flow AI.json AI_FUNCTION_004B). */
// FUN_001E5570
s32 btlAICommandCondQueryMukouSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x17000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x204c (p4flow AI.json AI_FUNCTION_004C). */
// FUN_001E5620
s32 btlAICommandCondQueryWeakSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x18000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x204d (p4flow AI.json AI_FUNCTION_004D). */
// FUN_001E56D0
s32 btlAICommandCondQueryNotHansyaSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x19000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x204e (p4flow AI.json AI_FUNCTION_004E). */
// FUN_001E5780
s32 btlAICommandCondQueryNotKyusyuSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1A000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x204f (p4flow AI.json AI_FUNCTION_004F). */
// FUN_001E5830
s32 btlAICommandCondQueryNotMukouSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1B000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2050 (p4flow AI.json AI_FUNCTION_0050). */
// FUN_001E58E0
s32 btlAICommandCondQueryNotWeakSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1C000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2067 (p4flow AI.json AI_FUNCTION_0067). */
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

/* AI script command 0x2098 (p4flow AI.json AI_FUNCTION_0098). */
// FUN_001E5A20
s32 btlAICommandCondQueryNotId(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x21000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x209a (p4flow AI.json AI_FUNCTION_009A). */
// FUN_001E5AD0
s32 btlAICommandAiUnlessRnd(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609DF0[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x20c6 (p4flow AI.json AI_FUNCTION_00C6). */
// FUN_001E5B40
s32 btlAICommandCondQueryHojo(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x23000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x20c7 (p4flow AI.json AI_FUNCTION_00C7). */
// FUN_001E5BF0
s32 btlAICommandCondQueryNotHojo(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x24000000;
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(action, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x210f (p4flow AI.json AI_FUNCTION_010F). */
// FUN_001E5CA0
s32 btlAICommandScriptPickMyIdFiltered(void) {
    u32 unitId = scrGetParamInt(0);
    u32 excludedBuffs = scrGetParamInt(1);
    btlAICommandSelectCandidates(scrGetAiState(), unitId, excludedBuffs, 0x40, 0, btlCond_MYID);
    return 1;
}

/* AI script command 0x2112 (p4flow AI.json AI_FUNCTION_0112). */
// FUN_001E5D20
s32 btlAICommandAiUnlessHpMax(void) {
    u8 *action = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609E18[0])(action, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(action, 0);
    return 1;
}

/* AI script command 0x2091 (p4flow AI.json AI_FUNCTION_0091). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 117). */
// FUN_001E5D90
s32 btlAICommandScriptSetId2ClearBuffs(void) {
    u8 *action = scrGetAiState();
    u32 secondaryId = scrGetParamInt(0) & 0xFFFF;
    u32 data;
    datCalcClearBuffLevel(*(u32 *)(*(u8 **)(action + 0x30) + 0xA64), 8);
    datCalcClearBuffLevel(*(u32 *)(*(u8 **)(action + 0x30) + 0xA64), 9);
    datCalcClearBuffLevel(*(u32 *)(*(u8 **)(action + 0x30) + 0xA64), 0xA);
    datCalcClearBuffLevel(*(u32 *)(*(u8 **)(action + 0x30) + 0xA64), 0xB);
    data = *(u32 *)(*(u8 **)(action + 0x30) + 0xA64);
    *(u16 *)(data + 4) = secondaryId;
    return 1;
}

/* AI script command 0x2095 (p4flow AI.json AI_FUNCTION_0095). */
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

/* AI script command 0x2096 (p4flow AI.json AI_FUNCTION_0096). */
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

/* AI script command 0x20db (p4flow AI.json AI_FUNCTION_00DB). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 6). */
// FUN_001E5F40
s32 btlAICommandScriptSetCommandOverride(void) {
    u8 *action = scrGetAiState();
    *(u16 *)(action + 0x80) = scrGetParamInt(0);
    *(u8 *)(action + 0x82) = scrGetParamInt(1);
    return 1;
}

/* AI script command 0x2099 (p4flow AI.json AI_FUNCTION_0099). */
// FUN_001E5F90
s32 btlAICommandScriptGetSelfId2(void) {
    u32 data = (u32)((BtlUnit *)(((BtlAction *)(scrGetAiState()))->unit))->datUnit;
    scrSetReturnInt(((DatUnit *)data)->id2);
    return 1;
}

/* AI script command 0x20ab (p4flow AI.json AI_FUNCTION_00AB). */
// FUN_001E5FD0
s32 btlScriptGetSameSideUnitValue(void) {
    u8 *action = scrGetAiState();
    u32 *r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << ((((BtlAction *)action))->unit->genus)) & 0xFFFF, 0x80000);
    scrSetReturnInt(r != 0 ? ((BtlAction *)r)->unk_20 : 0);
    return 1;
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001E6050 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* AI script command 0x20ac (p4flow AI.json AI_FUNCTION_00AC). */
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
#pragma opt_rebuildconditionals on

/* AI script command 0x20b0 (p4flow AI.json AI_FUNCTION_00B0). */
// FUN_001E60F0
s32 btlAICommandScriptCountOwnHojo(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20b1 (p4flow AI.json AI_FUNCTION_00B1). */
// FUN_001E6160
s32 btlAICommandScriptCountOwnNotHojo(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 1, 1, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20b2 (p4flow AI.json AI_FUNCTION_00B2). */
// FUN_001E61D0
s32 btlAICommandScriptCountOwnBad(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYBAD, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20ea (p4flow AI.json AI_FUNCTION_00EA). */
// FUN_001E6240
s32 btlAICommandScriptCountOppBad(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 2, 0, &btlCond_MYBAD, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20b3 (p4flow AI.json AI_FUNCTION_00B3). */
// FUN_001E62B0
s32 btlAICommandScriptCountOppHojo(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 2, 0, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20b4 (p4flow AI.json AI_FUNCTION_00B4). */
// FUN_001E6320
s32 btlAICommandScriptCountOppNotHojo(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 2, 1, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20cd (p4flow AI.json AI_FUNCTION_00CD). */
// FUN_001E6390
s32 btlAICommandScriptCountOwnHp(void) {
    u8 *action = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(action, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYHP, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20ce (p4flow AI.json AI_FUNCTION_00CE). */
// FUN_001E6400
s32 btlAICommandScriptAverageOwnLevel(void) {
    scrSetReturnInt(btlSideAverageLevel((1 << ((((BtlAction *)(scrGetAiState())))->unit->genus)) & 0xFFFF, 0x80000) & 0xFFFF);
    return -1;
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001E6450 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* AI script command 0x20cf (p4flow AI.json AI_FUNCTION_00CF). */
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
#pragma opt_rebuildconditionals on

/* AI script command 0x20d0 (p4flow AI.json AI_FUNCTION_00D0). */
// FUN_001E64C0
s32 btlAICommandScriptGetCommandRow(void) {
    u8 *action = scrGetAiState();
    short commandId = (short)scrGetParamInt(0);
    scrSetReturnInt((s16)datCalcSkillElement((u8 *)(((BtlAction *)action))->unit->datUnit, (u16)commandId));
    return -1;
}

/* AI script command 0x20e1 (p4flow AI.json AI_FUNCTION_00E1). */
// FUN_001E6530
s32 btlAICommandScriptCountOwnAlive(void) {
    scrGetAiState();
    scrSetReturnInt(btlSideCountNotBad(1, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20e2 (p4flow AI.json AI_FUNCTION_00E2). */
// FUN_001E6570
s32 btlAICommandScriptCountOppAlive(void) {
    scrGetAiState();
    scrSetReturnInt(btlSideCountNotBad(2, 0) & 0xFFFF);
    return -1;
}

/* AI script command 0x2113 (p4flow AI.json AI_FUNCTION_0113). */
// FUN_001E65B0
s32 btlAICommandScriptGetSelfHp(void) {
    scrSetReturnInt(datCalcGetHp((u32)((BtlUnit *)(((BtlAction *)(scrGetAiState()))->unit))->datUnit) & 0xFFFF);
    return -1;
}

/* AI script command 0x2075 (p4flow AI.json AI_FUNCTION_0075). */
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

/* AI script command 0x2076 (p4flow AI.json AI_FUNCTION_0076). */
// FUN_001E66C0
s32 btlAICommandIdScriptQueryHasBuff(void) {
    u32 actionId = scrGetParamInt(0);
    u32 queryValue = scrGetParamInt(1);
    u8 hasBuff = datCalcHasBuffMask((((BtlAction *)(btlActionFindById(actionId & 0xFFFFFFF))))->unit->datUnit, queryValue) != 0;
    scrSetReturnInt(hasBuff != 0);
    return 1;
}

/* AI script command 0x2077 (p4flow AI.json AI_FUNCTION_0077). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 111). */
// FUN_001E6740
s32 btlAICommandScriptWouldBeKilled(void) {
    u8 *action = scrGetAiState();
    u8 *target = btlActionFindById(scrGetParamInt(0) & 0xFFFFFFF);
    s32 hpDelta = datCalcSkillAmount(0, (u8 *)*(u32 *)(*(u8 **)(action + 0x30) + 0xA64), (u8 *)*(u32 *)(*(u8 **)(target + 0x30) + 0xA64), 1, 1, 1, 0, 1);
    s32 currentHp;
    s32 remainingHp;
    datCalcClearField18(*(u32 *)(*(u8 **)(action + 0x30) + 0xA64));
    datCalcClearField18(*(u32 *)(*(u8 **)(target + 0x30) + 0xA64));
    currentHp = (s32)(datCalcGetHp(*(u32 *)(*(u8 **)(target + 0x30) + 0xA64)) & 0xFFFF);
    remainingHp = currentHp + hpDelta;
    scrSetReturnInt(remainingHp <= 0);
    return 1;
}

/* AI script command 0x2078 (p4flow AI.json AI_FUNCTION_0078). */
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



/* AI script command 0x2079 (p4flow AI.json AI_FUNCTION_0079). */
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



/* AI script command 0x209c (p4flow AI.json AI_FUNCTION_009C). */
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

/* AI script command 0x20e3 (p4flow AI.json AI_FUNCTION_00E3). */
// FUN_001E6A00
s32 btlAICommandIdScriptQueryOnSideZero(void) {
    scrSetReturnInt((((BtlAction *)btlActionFindById(scrGetParamInt(0) & 0xFFFFFFF)))->unit->genus == 0);
    return 1;
}
/* AI script command 0x20e4 (p4flow AI.json AI_FUNCTION_00E4). */
/* Proven action/unit and selection layouts remain byte-addressed here: the
 * shared-member rewrite changed MWCC codegen (measured normalized diff 218). */
// FUN_001E6A50
s32 btlAICommandIdScriptQueryCanUseCommand(void) {
    s32 actionId = scrGetParamInt(0);
    s32 commandId = scrGetParamInt(1);
    u8 *subject = btlActionFindById(actionId & 0xFFFFFFF);
    s32 command = commandId & 0xFFFF;
    s32 usable;
    if (command >= 0x240)
        kAssertFail(D_006095E0, 0x45F);
    subject = *(u8 **)(subject + 0x30);
    if (command < 0x1B8) {
        if (datCalcChkBadStatus((s32)*(u8 **)(subject + 0xA64), 0x80008) != 0)
            usable = 0;
        else if (datCalcHasSkill(*(u8 **)(subject + 0xA64), command) == 0)
            usable = 0;
        else if (datCalcThresholdTrigger(*(u8 **)(subject + 0xA64), command) != 0)
            usable = 0;
        else
            goto one;
    } else if (datCalcHasSkill(*(u8 **)(subject + 0xA64), command) != 0)
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
