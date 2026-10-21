#include "member_access.h"
#include "btl_sound_internal.h"
#include "btl_effect_internal.h"
/* Merges the btlCond_MYHP..btlCond_ENALLHP and btlCond_FRLV_O..btlCond_MYID function groups in
 * retail address order. */
#include "btl_action_internal.h"
#include "btl_skill_target_internal.h"
#include "type.h"
#include "operand_order_internal.h"
#include "include_asm.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"

/* Unit settings: preserve condition branch structure throughout the battle predicates. */
#pragma opt_rebuildconditionals off

/* Encounter rule rows have a 0x18-byte stride; escape tests flag bit 0. */
typedef struct BtlEncounterRule {
    s32 flags;
    u8 pad04[0x14];
} BtlEncounterRule;

typedef u8 bool;
typedef int (*code)();


extern s32 datCalcIsDead(u8 *unit, s32 hpDelta);
extern s32 datCalcGetLevel(u8 *unit);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern u16 datCalcGetHp(u8 *unit);
extern u16 datCalcMaxHp(u8 *unit);
extern u16 datCalcMaxSp(u8 *unit);
extern s32 datCalcGetAffinity(u8 *unit, s32 elementIndex);
extern s32 datCalcSkillElement(u8 *unit, u16 skillId);
extern s32 func_0023df20(s32 input);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
/* Test current HP against a percentage of the corresponding maximum; equality satisfies the condition. */
// FUN_001D9740
s32 btlCond_MYHP(u8 *action, s32 conditionValue)
{
    u32 maxHp = 0;
    u32 currentHp = 0;

    currentHp = ((BtlAction *)action)->unit->datUnit->hp;
    maxHp = datCalcMaxHp((u8 *)((BtlAction *)action)->unit->datUnit);
    return (u32)currentHp * 100 <= (maxHp & 0xFFFF) * conditionValue;
}

/* Test current HP against a percentage of maximum HP, accepting equality on the high side. */
// FUN_001D97B0
s32 btlCondCheckMaxHp(u8 *action, s32 conditionValue)
{
    u32 maxHp = 0;
    u32 currentHp = 0;

    currentHp = ((BtlAction *)action)->unit->datUnit->hp;
    maxHp = datCalcMaxHp((u8 *)((BtlAction *)action)->unit->datUnit);
    return !((u32)currentHp * 100 < (maxHp & 0xFFFF) * conditionValue);
}

/* Test current SP against a percentage of the corresponding maximum; equality satisfies the condition. */
// FUN_001D9820
s32 btlCond_MYMP(u8 *action, s32 conditionValue)
{
    u32 maxSp = 0;
    u32 currentSp = 0;

    currentSp = ((BtlAction *)action)->unit->datUnit->sp;
    maxSp = datCalcMaxSp((u8 *)((BtlAction *)action)->unit->datUnit);
    return (u32)currentSp * 100 <= (maxSp & 0xFFFF) * conditionValue;
}

/* Run the corresponding per-unit condition over the allied side, excluding KO status. */
// FUN_001D9890
void btlCond_FRHP(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYHP);
}

/* Run the corresponding per-unit condition over the opposing side, excluding KO status. */
// FUN_001D98E0
/* opt_rebuildconditionals must be off for this wrapper, as for the same-shaped btlAICommand
 * func_001db990. */
void btlCond_ENHP(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYHP);
}

/* Run the corresponding per-unit condition over the opposing side, excluding KO status. */
// FUN_001D9940
/* measured: this wrapper needs opt_rebuildconditionals off, like the same-shaped btlAICommand
 * func_001db990; the goto form keeps the retail branch layout. */
void btlCond_ENHP_O(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCondCheckMaxHp);
}

/* Compare the acting unit level with the inclusive lower bound in conditionValue. */
// FUN_001D99A0
s32 btlCond_MYLV_O(u8 *action, u32 conditionValue)
{
    return (u32)(datCalcGetLevel((u8 *)((BtlAction *)action)->unit->datUnit) & 0xFF) >= conditionValue;
}
/* Compare the living allied side average level against the inclusive lower bound. */
// FUN_001D99E0
bool btlCond_FRLV_O(int action, u32 conditionValue)
{
  u32 averageLevel = 0;

  averageLevel = btlSideAverageLevel(1 << ((BtlAction *)action)->unit->genus & 0xffff, 0x80000);
  return conditionValue <= (averageLevel & 0xffff);
}


/* measured: retail code for btlCond_ENLV_O requires opt_rebuildconditionals off; the compiler
 * otherwise rebuilds its branch structure. */

/* Compare the living opposing side average level against the inclusive lower bound. */
// FUN_001D9A30
bool btlCond_ENLV_O(int action, u32 conditionValue)
{
  u32 averageLevel = 0;
  u16 genus;
  u32 shift;
  if (((BtlAction *)action)->unit->genus != 0)
    goto nonzero;
  shift = 1;
  goto done;
nonzero:
  shift = 0;
done:
  genus = shift;
  averageLevel = btlSideAverageLevel(1 << genus & 0xffff, 0x80000);
  return conditionValue <= (averageLevel & 0xffff);
}


/* Accept when the living allied unit count does not exceed conditionValue. */
// FUN_001D9AA0
bool btlCond_FRCNT(int action, u32 conditionValue)
{
  u32 unitCount = 0;

  unitCount = btlSideCountNotBad(1 << ((BtlAction *)action)->unit->genus & 0xffff, 0x80000);
  return (unitCount & 0xffff) <= conditionValue;
}


/* measured: this function needs opt_rebuildconditionals off; rebuilt conditionals change its branch
 * layout from retail. */

/* Accept when the living opposing unit count does not exceed conditionValue. */
// FUN_001D9AF0
bool btlCond_ENCNT(int action, u32 conditionValue)
{
  u32 unitCount = 0;
  u16 genus;
  {
    u32 shift;
    if (((BtlAction *)action)->unit->genus != 0)
      goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    genus = shift;
  }
  unitCount = btlSideCountNotBad(1 << genus & 0xffff, 0x80000);
  return (unitCount & 0xffff) <= conditionValue;
}
/* Test the acting unit against the supplied bad-status mask. */
// FUN_001D9B60
s32 btlCond_MYBAD(u8 *task, s32 mask) {
    return datCalcChkBadStatus((s32)((BtlUnit *)(u8 *)((BtlAction *)task)->unit)->datUnit, (u32)mask);
}
/* Search the allied side for the supplied status mask; a KO bit in the mask disables the separate KO exclusion. */
// FUN_001D9B90
void btlCond_FRBAD(u8 *action, u32 conditionValue)
{
    u32 mask;

    mask = (1 << (u8)((BtlAction *)action)->unit->genus) & 0xFFFF;
    if ((conditionValue & 0x80000) != 0) {
        btlEffectFindUnitMatchingCallback((int)action, conditionValue, mask, 0, 0, btlCond_MYBAD);
    } else {
        btlEffectFindUnitMatchingCallback((int)action, conditionValue, mask, 0x80000, 0, btlCond_MYBAD);
    }
}

/* Search the opposing side for the supplied status mask; a KO bit in the mask disables the separate
 * KO exclusion. */
// FUN_001D9C00
void btlCond_ENBAD(u8 *action, u32 conditionValue)
{
    u32 shift;
    u32 sideIndex;

    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero_1;
        shift = 1;
        goto done_1;
    nonzero_1:
        shift = 0;
    done_1:
        ;
    }
    sideIndex = shift & 0xFFFF;
    if ((conditionValue & 0x80000) != 0) {
        btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (sideIndex & 0xFFFF)) & 0xFFFF, 0, 0, btlCond_MYBAD);
    } else {
        btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (sideIndex & 0xFFFF)) & 0xFFFF, 0x80000, 0, btlCond_MYBAD);
    }
}
/* measured: opt_rebuildconditionals off forces the retail mode branch. Return true only when no
 * living opposing unit fails the supplied status-mask test. */
/* Return true only when every living unit on the opposing side has the bad status given by
 * conditionValue. */
// FUN_001D9CA0
s32 btlCond_ENBAD_ALL(u8 *action, s32 conditionValue)
{
    BtlUnit *candidateUnit;
    u8 *unit;
    s32 mode;
    s32 mask;
    u16 flags;
    u8 *temp;

    if (((BtlUnit *)(*(u8 * *)&((BtlAction *)(action))->unit))->genus != 0)
        goto nonzero;
    mode = 1;
    goto done;
nonzero:
    mode = 0;
done:
    ;
    mask = (1 << (mode & 0xFFFF)) & 0xFFFF;
    unit = ((BtlBattleState *)(iGpffffb3ac))->actions;
    while (unit != NULL) {
        flags = ((BtlAction *)(unit))->unk_1a;
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 * *)&((BtlAction *)(unit))->unit;
            candidateUnit = (BtlUnit *)(temp);
            if ((mask & (1 << ((BtlUnit *)(temp))->genus)) != 0 &&
                datCalcIsDead(*(u8 * *)&((BtlUnit *)(temp))->datUnit, 0) == 0 &&
                datCalcChkBadStatus(*(s32 *)&candidateUnit->datUnit, conditionValue) == 0) {
                break;
            }
        }
        unit = *(u8 * *)&((BtlAction *)(unit))->next;
    }
    if (unit != NULL)
        goto found;
    return 1;
found:
    return 0;
}
/* Search active other allied actions for the requested character ID, excluding KO status. */
// FUN_001D9DB0
s32 btlCond_FRID(u8 *action, s32 conditionValue)
{
    u16 flags;
    u8 *temp;
    u8 *unit;

    unit = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (unit != NULL) {
        if (action != unit) {
            flags = ((BtlAction *)unit)->unk_1a;
            if ((flags & 1) != 0 && (flags & 8) != 0) {
                temp = (u8 *)((BtlAction *)unit)->unit;
                if ((u8)((BtlAction *)action)->unit->genus == (u8)((BtlUnit *)temp)->genus &&
                    datCalcChkBadStatus((s32)((BtlUnit *)temp)->datUnit, 0x80000) == 0 &&
                    (u16)((BtlUnit *)temp)->charId == conditionValue) {
                    return 1;
                }
            }
        }
        unit = (u8 *)((BtlAction *)unit)->next;
    }
    return 0;
}
/* measured: retail's branch on mode only comes out with opt_rebuildconditionals off. Searches
 * active opposing actions for the requested character ID, excluding KO status. */
/* Return true if an active opposing unit whose charId equals conditionValue exists and is not KO'd. */
// FUN_001D9E80
s32 btlCond_ENID(u8 *action, s32 conditionValue)
{
    u8 *unit;
    s32 value;
    s32 mode;
    u16 flags;
    u8 *temp;

    if ((u8)((BtlAction *)action)->unit->genus != 0)
        goto nonzero;
    value = 1;
    goto done;
nonzero:
    value = 0;
done:
    ;
    mode = value & 0xFFFF;
    unit = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (unit != NULL) {
        flags = ((BtlAction *)unit)->unk_1a;
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = (u8 *)((BtlAction *)unit)->unit;
            if ((u8)((BtlUnit *)temp)->genus == mode &&
                datCalcChkBadStatus((s32)((BtlUnit *)temp)->datUnit, 0x80000) == 0 &&
                (u16)((BtlUnit *)temp)->charId == conditionValue) {
                return 1;
            }
        }
        unit = (u8 *)((BtlAction *)unit)->next;
    }
    return 0;
}
/* Search active other allied actions for the requested buff mask, excluding KO status. */
// FUN_001D9F60
s32 btlCond_FRHOJO(u8 *action, s32 conditionValue)
{
    BtlUnit *candidateUnit;
    u16 flags;
    u8 *temp;
    u8 *unit;

    unit = ((BtlBattleState *)(iGpffffb3ac))->actions;
    while (unit != NULL) {
        if (action != unit) {
            flags = ((BtlAction *)(unit))->unk_1a;
            if ((flags & 1) != 0 && (flags & 8) != 0) {
                temp = *(u8 * *)&((BtlAction *)(unit))->unit;
                candidateUnit = (BtlUnit *)(temp);
                if (((BtlUnit *)(*(u8 * *)&((BtlAction *)(action))->unit))->genus == ((BtlUnit *)(temp))->genus &&
                    datCalcChkBadStatus(*(s32 *)&((BtlUnit *)(temp))->datUnit, 0x80000) == 0 &&
                    datCalcHasBuffMask(candidateUnit->datUnit, conditionValue) != 0) {
                    return 1;
                }
            }
        }
        unit = *(u8 * *)&((BtlAction *)(unit))->next;
    }
    return 0;
}
/* Search active opposing actions for the requested buff mask, excluding KO status. */
// FUN_001DA040
s32 btlCond_ENHOJO(u8 *action, s32 conditionValue)
{
    BtlUnit *candidateUnit;
    u8 *unit;
    s32 value;
    s32 mode;
    u16 flags;
    u8 *temp;

    if (((BtlUnit *)(*(u8 * *)&((BtlAction *)(action))->unit))->genus != 0)
        goto nonzero;
    value = 1;
    goto done;
nonzero:
    value = 0;
done:
    ;
    mode = value & 0xFFFF;
    unit = ((BtlBattleState *)(iGpffffb3ac))->actions;
    while (unit != NULL) {
        flags = ((BtlAction *)(unit))->unk_1a;
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 * *)&((BtlAction *)(unit))->unit;
            candidateUnit = (BtlUnit *)(temp);
            if (((BtlUnit *)(temp))->genus == mode &&
                datCalcChkBadStatus(*(s32 *)&((BtlUnit *)(temp))->datUnit, 0x80000) == 0 &&
                datCalcHasBuffMask(candidateUnit->datUnit, conditionValue) != 0) {
                return 1;
            }
        }
        unit = *(u8 * *)&((BtlAction *)(unit))->next;
    }
    return 0;
}
/* Reject escape-blocking statuses before consulting the encounter flags for the active group. */
// FUN_001DA130
s32 btlCond_ESCAPE(u8 *action, s32 conditionValue) {
    s32 r;

    if (datCalcChkBadStatus((s32)((BtlAction *)action)->unit->datUnit, 0x180010) != 0) {
        r = 0;
    } else {
        r = (((BtlEncounterRule *)iGpffffb414)[((BtlSoundEncounterRecord *)(*(u8 * *)&((BtlBattleState *)(D_0076449C))->encounterRecord))->trackRule].flags & 1) != 0;
    }
    return r;
}

/* This retail condition is an unconditional false result. */
// FUN_001DA1A0
s32 btlCond_SUMMON(void)
{
    return 0;
}

/* Test the initial-turn opening side; actions whose turn counter is positive cannot satisfy it. */
// FUN_001DA1B0
s32 btlCond_SENSEI(u8 *action)
{
    u8 genus;

    if ((s32)((BtlAction *)action)->unk_20 > 0)
        return 0;
    genus = (u8)((BtlAction *)action)->unit->genus;
    switch (genus) {
    case 0:
        return ((BtlBattleState *)iGpffffb3ac)->openingSide == 1;
    case 1:
        return ((BtlBattleState *)iGpffffb3ac)->openingSide == 2;
    default:
        return 0;
    }
}

/* Test the requested element affinity for reflection (0x02000000). */
// FUN_001DA230
s32 btlCond_MYHANSYA(u8 *action, s16 conditionValue) {
    return (s32)((datCalcGetAffinity((u8 *)((BtlAction *)action)->unit->datUnit, (s32)conditionValue) & 0x02000000) != 0);
}


/* Test the requested element affinity for absorption (0x04000000). */
// FUN_001DA270
s32 btlCond_MYKYUSYU(u8 *action, s16 conditionValue) {
    return (s32)((datCalcGetAffinity((u8 *)((BtlAction *)action)->unit->datUnit, (s32)conditionValue) & 0x04000000) != 0);
}


/* Test the requested element affinity for nullification (0x01000000). */
// FUN_001DA2B0
s32 btlCond_MYMUKOU(u8 *action, s16 conditionValue) {
    return (s32)((datCalcGetAffinity((u8 *)((BtlAction *)action)->unit->datUnit, (s32)conditionValue) & 0x01000000) != 0);
}


/* Test the requested element affinity for weakness (0x08000000). */
// FUN_001DA2F0
s32 btlCond_MYWEAK(u8 *action, s16 conditionValue) {
    return (s32)((datCalcGetAffinity((u8 *)((BtlAction *)action)->unit->datUnit, (s32)conditionValue) & 0x08000000) != 0);
}


/* Run the corresponding per-unit condition over the allied side, excluding KO status. */
// FUN_001DA330
void btlCond_FRHANSYA(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYHANSYA);
}

/* Run the corresponding per-unit condition over the opposing side, excluding KO status. */
// FUN_001DA380
/* Needs opt_rebuildconditionals off, the same as btlAICommand func_001db990. The goto form is used
 * because if/else and switch produce different code. */
void btlCond_ENHANSYA(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYHANSYA);
}

/* Run the corresponding per-unit condition over the allied side, excluding KO status. */
// FUN_001DA3E0
void btlCond_FRKYUSYU(u8 *action, s32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (u8)((BtlUnit *)(u8 *)(u8 *)((BtlAction *)(u8 *)action)->unit)->genus) & 0xFFFF, 0x80000, 0, (code)btlCond_MYKYUSYU);
}

/* Run the corresponding per-unit condition over the opposing side, excluding KO status. */
// FUN_001DA430
/* Same branch shape as func_001da380; this wrapper needs opt_rebuildconditionals off. */
void btlCond_ENKYUSYU(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYKYUSYU);
}
/* Run the corresponding per-unit condition over the allied side, excluding KO status. */
// FUN_001DA490
void btlCond_FRMUKOU(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYMUKOU);
}
/* Run the corresponding per-unit condition over the opposing side, excluding KO status. */
// FUN_001DA4E0
/* Same branch shape as func_001da380; the goto form keeps retail's branch layout, and this wrapper
 * needs opt_rebuildconditionals off. */
void btlCond_ENMUKOU(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYMUKOU);
}
/* Run the corresponding per-unit condition over the allied side, excluding KO status. */
// FUN_001DA540
void btlCond_FRWEAK(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYWEAK);
}
/* Run the corresponding per-unit condition over the opposing side, excluding KO status. */
// FUN_001DA590
/* measured: this wrapper needs opt_rebuildconditionals off to keep the same branch shape as
 * func_001da380. */
void btlCond_ENWEAK(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYWEAK);
}
/* Compare the selected skill element with conditionValue; the XOR expression implements equality. */
// FUN_001DA5F0
s32 btlCond_MYUSEATTR(u8 *action, s32 conditionValue)
{
    return operandOrderXor((s16)datCalcSkillElement(
        (u8 *)((BtlAction *)action)->unit->datUnit,
        ((BtlAction *)(action))->parameters.skill), conditionValue) < 1U;
}
/* Run the corresponding per-unit condition over the allied side, excluding KO status. */
// FUN_001DA640
void btlCond_FRUSEATTR(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYUSEATTR);
}
/* Run the corresponding per-unit condition over the opposing side, excluding KO status. */
// FUN_001DA690
/* Uses the same goto branch shape as func_001da380, and needs opt_rebuildconditionals off. */
void btlCond_ENUSEATTR(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYUSEATTR);
}
/* Accept the requested skill ID only for command kinds 1 and 2. */
// FUN_001DA6F0
bool btlCond_MYUSESKIL(int action, int conditionValue)
{
    bool result;

    switch (((BtlAction *)(action))->parameters.commandKind)
    {
    default:
        result = 0;
        break;
    case 1:
    case 2:
        result = ((BtlAction *)(action))->parameters.skill == conditionValue;
        break;
    }
    return result;
}


/* Run the corresponding per-unit condition over the allied side, excluding KO status. */
// FUN_001DA730
void btlCond_FRUSESKIL(int action, u32 conditionValue)
{
    btlEffectFindUnitMatchingCallback(action, conditionValue, 1 << ((BtlAction *)action)->unit->genus & 0xffff, 0x80000, 0, (code *)&btlCond_MYUSESKIL);
}
/* measured: retail's branch shape needs opt_rebuildconditionals off. Runs the per-unit condition
 * over the opposing side, excluding KO status. */
/* Check the opposing side's non-KO units for one that passes the btlCond_MYUSESKIL skill-use test. */
// FUN_001DA780
void btlCond_ENUSESKIL(int action, u32 conditionValue)
{
    u32 shift;

    if (((BtlAction *)action)->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    btlEffectFindUnitMatchingCallback(action, conditionValue, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code *)&btlCond_MYUSESKIL);
}
/* Accept target classifications 1 and 2 for the action's selected skill. */
// FUN_001DA7E0
u32 btlCond_MYGROUP(int action)
{
  u16 result;

  result = btlSkillClassifyTargets((u8 *)action, 0, ((BtlAction *)(action))->parameters.skill, 0);
  switch (result) {
  case 1:
  case 2:
    return 1;
  default:
    return 0;
  }
}


/* Run the corresponding per-unit condition over the allied side, excluding KO status. */
// FUN_001DA840
void btlCond_FRGROUP(int action, u32 conditionValue)
{
    btlEffectFindUnitMatchingCallback(action, conditionValue, 1 << ((BtlAction *)action)->unit->genus & 0xffff, 0x80000, 0, (code *)&btlCond_MYGROUP);
}
/* Runs the per-unit condition over the opposing side, excluding KO status; retail's branch shape
 * needs opt_rebuildconditionals off. */
// FUN_001DA890
void btlCond_ENGROUP(int action, u32 conditionValue)
{
    u32 shift;

    if (((BtlAction *)action)->unit->genus != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    btlEffectFindUnitMatchingCallback(action, conditionValue, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code *)&btlCond_MYGROUP);
}
/* Test the action turn counter against an inclusive upper bound. */
// FUN_001DA8F0
bool btlCond_TURN(int action, u32 conditionValue)
{
    return conditionValue >= ((BtlAction *)action)->unk_20;
}


/* Test the action turn counter against an inclusive lower bound. */
// FUN_001DA910
bool btlCond_TURN_O(int action, u32 conditionValue)
{
    return conditionValue <= ((BtlAction *)action)->unk_20;
}
/* Matches P3FES func_002c2510 (btlEffect.c). Scans the unit's nonzero skills below 0x1B8 for one
 * accepted by the recovery-skill predicate. */
// FUN_001DA930
s32 btlCond_MYHREC(u8 *action)
{
    s32 data;
    s32 count;
    u16 *skills;
    u16 index;

    data = *(s32 *)&((BtlAction *)(action))->unit;
    count = (u16)datCalcGetTableLength(((BtlUnit *)(data))->datUnit);
    skills = (u16 *)datCalcSkillList(MEMBER(DatUnit *, data, BtlUnit, datUnit));
    index = 0;
    count = (u16)count;
    while (index < count) {
        u16 skillId = skills[index];

        if (skillId != 0 && skillId < 0x1B8 && func_0023df20(skillId) != 0)
            return 1;
        index++;
    }
    return 0;
}
/* Run the corresponding per-unit condition over the allied side, excluding KO and down status. */
// FUN_001DAA00
void btlCond_FRHANSYA_ST(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x180000, 0, (code)btlCond_MYHANSYA);
}
/* Run the corresponding per-unit condition over the opposing side, excluding KO and down status. */
// FUN_001DAA50
/* Same branch shape as func_001da380; this wrapper needs opt_rebuildconditionals off. */
void btlCond_ENHANSYA_ST(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYHANSYA);
}
/* Run the corresponding per-unit condition over the allied side, excluding KO and down status. */
// FUN_001DAAB0
void btlCond_FRKYUSYU_ST(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x180000, 0, (code)btlCond_MYKYUSYU);
}
/* Run the corresponding per-unit condition over the opposing side, excluding KO and down status. */
// FUN_001DAB00
/* Needs opt_rebuildconditionals off; same branch shape as func_001da380. */
void btlCond_ENKYUSYU_ST(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYKYUSYU);
}
/* Run the corresponding per-unit condition over the allied side, excluding KO and down status. */
// FUN_001DAB60
void btlCond_FRMUKOU_ST(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x180000, 0, (code)btlCond_MYMUKOU);
}
/* Run the corresponding per-unit condition over the opposing side, excluding KO and down status. */
// FUN_001DABB0
/* Uses the same goto branch shape as func_001da380; the if/else and switch forms produce different
 * code. */
void btlCond_ENMUKOU_ST(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYMUKOU);
}
/* Run the corresponding per-unit condition over the allied side, excluding KO and down status. */
// FUN_001DAC10
void btlCond_FRWEAK_ST(u8 *action, u32 conditionValue) {
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << ((u8)((BtlAction *)action)->unit->genus)) & 0xFFFF, 0x180000, 0, (code)btlCond_MYWEAK);
}
/* Run the corresponding per-unit condition over the opposing side, excluding KO and down status. */
// FUN_001DAC60
void btlCond_ENWEAK_ST(u8 *action, u32 conditionValue) {
    u32 shift;
    {
        if ((u8)((BtlAction *)action)->unit->genus != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)action, conditionValue, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYWEAK);
}
/* Compare the acting unit character ID with conditionValue. */
// FUN_001DACC0
bool btlCond_MYID(int action, int conditionValue)
{
    return ((BtlUnit *)((s32)((BtlAction *)action)->unit))->charId == conditionValue;
}
/* Sum living allied HP and maximum HP, then compare the totals against the supplied percentage. */
// FUN_001DACE0
s32 btlCond_FRALLHP(u8 *action, s32 conditionValue)
{
    BtlUnit *sideUnit;
    extern u16 datCalcGetHp(u8 *unit);
    u8 *currentAction;
    u8 *unitWork;
    u16 actionFlags;
    s32 totalHp;
    s32 totalMaxHp;
    s32 sideMask;
    s32 limit;

    limit = conditionValue;
    sideMask = (1 << (((BtlUnit *)(*(u8 * *)&((BtlAction *)(action))->unit))->genus)) & 0xFFFF;
    totalHp = 0;
    totalMaxHp = 0;
    currentAction = ((BtlBattleState *)(iGpffffb3ac))->actions;
    goto loop_test;
loop_body:
    actionFlags = ((BtlAction *)(currentAction))->unk_1a;
    if ((actionFlags & 1) != 0 && (actionFlags & 8) != 0) {
        unitWork = *(u8 * *)&((BtlAction *)(currentAction))->unit;
        sideUnit = (BtlUnit *)(unitWork);
        if ((sideMask & (1 << ((BtlUnit *)(unitWork))->genus)) != 0 &&
            datCalcIsDead(*(u8 * *)&((BtlUnit *)(unitWork))->datUnit, 0) == 0) {
            totalHp += datCalcGetHp(*(u8 * *)&sideUnit->datUnit) & 0xFFFF;
            totalMaxHp += datCalcMaxHp(*(u8 * *)&sideUnit->datUnit) & 0xFFFF;
        }
    }
    currentAction = *(u8 * *)&((BtlAction *)(currentAction))->next;
loop_test:
    if (currentAction != NULL)
        goto loop_body;
    return (u32)(totalHp * 0x64) <= (u32)(totalMaxHp * limit);
}
/* The mode branch needs opt_rebuildconditionals off. Sum living opposing HP and maximum HP, then
 * compare the totals against the supplied percentage. */
// FUN_001DAE00
s32 btlCond_ENALLHP(u8 *action, s32 conditionValue)
{
    BtlUnit *sideUnit;
    extern u16 datCalcGetHp(u8 *unit);
    u8 *currentAction;
    u8 *unitWork;
    u16 actionFlags;
    s32 totalHp;
    s32 totalMaxHp;
    s32 sideMask;
    s32 limit;

    limit = conditionValue;
    {
        if (((BtlUnit *)(*(u8 * *)&((BtlAction *)(action))->unit))->genus != 0)
            goto nonzero;
        sideMask = 1;
        goto done;
    nonzero:
        sideMask = 0;
    done:
        ;
    }
    sideMask = (1 << (sideMask & 0xFFFF)) & 0xFFFF;
    totalHp = 0;
    totalMaxHp = 0;
    currentAction = ((BtlBattleState *)(iGpffffb3ac))->actions;
    goto loop_test;
loop_body:
    actionFlags = ((BtlAction *)(currentAction))->unk_1a;
    if ((actionFlags & 1) != 0 && (actionFlags & 8) != 0) {
        unitWork = *(u8 * *)&((BtlAction *)(currentAction))->unit;
        sideUnit = (BtlUnit *)(unitWork);
        if ((sideMask & (1 << ((BtlUnit *)(unitWork))->genus)) != 0 &&
            datCalcIsDead(*(u8 * *)&((BtlUnit *)(unitWork))->datUnit, 0) == 0) {
            totalHp += datCalcGetHp(*(u8 * *)&sideUnit->datUnit) & 0xFFFF;
            totalMaxHp += datCalcMaxHp(*(u8 * *)&sideUnit->datUnit) & 0xFFFF;
        }
    }
    currentAction = *(u8 * *)&((BtlAction *)(currentAction))->next;
loop_test:
    if (currentAction != NULL)
        goto loop_body;
    return (u32)(totalHp * 0x64) <= (u32)(totalMaxHp * limit);
}
