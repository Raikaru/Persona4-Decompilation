/* Source unit: src/Battle/btlEffect_001db100.c */
#include "btl_skill_target_internal.h"
#include "datCalc_unit_internal.h"
#include "datUnit_internal.h"
#include "type.h"
#include "include_asm.h"
#include "btl_cond_internal.h"

typedef u8 bool;
typedef int (*code)();

typedef struct DatUnit DatUnit;
extern u16 datCalcMaxHp(DatUnit *unit);


s32 btlAICommandNomalCheck(u8 *formation, s32 index, s32 enabled);

extern u64 func_0010f460();

extern s32 datCalcStatusResistance(u8 *arg0, s32 arg1);

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
extern u32 func_001d8bc0(u8 *arg0);
extern s32 datCalcSkillElement(u8 *unit, u16 command);
extern s32 datCalcElementBit(s16 index);
extern s8 datCalcGetBuffStatus(u8 *unit, s32 status);
extern u32 datCalcGetTableLength(u8 *unit);
extern u32 datCalcUnderlyingSkillId(u32 arg0);
extern u32 *btlEffectFindUnitByIdAndStatus();
extern s32 func_001f9ce0(u8 *arg0, s32 arg1);
extern u32 datTestBitmapBit(u32 arg0, u32 arg1);
extern void func_001d8bf0(u8 *arg0, u8 *arg1);
extern u8 *D_0072449C;
extern void *D_00609850[];
extern u32 D_00609600[];
extern u32 btlActionGetQueueEntry(u16 arg0);
extern u32 datCalcClearBuffLevel(u32 arg0, u32 arg1);
extern u32 datCalcRandomBelow(u32 arg0);
extern u16 datCalcGetHp(s32 unit);
extern s32 datCalcAilmentChance(u8 *unit, s32 index);
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
extern s32 func_0029da90(u8 *a, u32 b, s32 c);
extern void func_0029dfe0(u32 a, u8 *b);
extern u8 *kwlnTaskGetWork(u32 a);
extern s32 func_0010d740(s32 a);
extern void itfMesWindowSetString(s32 a, s32 b, u32 c);
extern void kwlnTaskAddChild(u8 *a, u32 b);
extern u8 D_00609E20[];
extern u8 *iGpffffb428;
extern u8 *iGpffffb42c;
extern void func_001eb3b0(u8 *a);

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB040 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* Shared by the exported callback and retail's inlined value query. */
static inline s32 btlCommandUsable(u8 *p, u32 arg1) {
    s32 a;

    a = arg1 & 0xFFFF;
    if (a >= 0x240) {
        kAssertFail(D_006095E0, 0x45F);
    }
    p = *(u8 **)(p + 0x30);
    if (a < 0x1B8) {
        if (datCalcChkBadStatus((s32)*(u8 **)(p + 0xA64), 0x80008) != 0)
            return 0;
        if (datCalcHasSkill(*(u8 **)(p + 0xA64), a) == 0)
            return 0;
        if (datCalcThresholdTrigger(*(u8 **)(p + 0xA64), a) == 0)
            goto ret1;
        return 0;
    }
    if (datCalcHasSkill(*(u8 **)(p + 0xA64), a) != 0)
        goto ret1;
    return 0;
ret1:
    return 1;
}

// FUN_001DAF40
s32 btlCond_MYABLESKIL(u8 *p, u32 arg1) {
    return btlCommandUsable(p, arg1);
}

// FUN_001DB040
void btlCond_ENWEAK_PAI(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 6, (code *)&btlCond_MYWEAK);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB0A0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB0A0
void btlCond_ENWEAK_ST_PAI(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 6, (code *)&btlCond_MYWEAK);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB100 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB100
void btlCond_ENWEAK_DW_PAI(int param_1, u32 param_2)
{
  u32 shift;

  {
      if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  btlEffectFindUnitMatchingCallback(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 7,
                 (code *)&btlCond_MYWEAK);
  return;
}
#pragma opt_rebuildconditionals on



/* measured: shared usability inlining and explicit signed query guards give
   508B/512B, verify nd0; the remaining four bytes are zero tail padding.
   Keep the entry reload after the value query and the existing s32 input ABI. */
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
    count = datCalcGetTableLength(*(u8 **)(unit + 0xA64));
    commands = (u16 *)datCalcSkillList(*(u8 **)(unit + 0xA64));
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
            count = datCalcGetTableLength(*(u8 **)(unit + 0xA64));
            commands = (u16 *)datCalcSkillList(*(u8 **)(unit + 0xA64));
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
    return !(datCalcAilmentChance(*(u8 **)(unit + 0xA64), (s16)index) & 0x07000000);
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
s32 btlAICommandNomalStatusCheck(u8 *arg0, s16 arg1) {
    return !(datCalcAilmentChance(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), (s32)arg1) & 0x7000000);
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB620 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB620
void btlCond_ENNOMAL(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0xA, (code *)&btlCond_MYNOMAL);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB680 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB680
void btlCond_ENNOMAL_ST(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0xA, (code *)&btlCond_MYNOMAL);
}

#pragma opt_rebuildconditionals on
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB6E0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB6E0
void btlCond_ENNOMAL_DW(int param_1, u32 param_2)
{
  u32 shift;

  {
      if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  btlEffectFindUnitMatchingCallback(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0xb,
                 (code *)&btlCond_MYNOMAL);
  return;
}
#pragma opt_rebuildconditionals on



// FUN_001DB740
bool btlCond_ANALYZE(int param_1)
{
  long lVar2 = 0;
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 1) {
    return 0;
  }
  lVar2 = func_0010f460(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4));
  return lVar2 != 0;
}



// FUN_001DB790
s32 btlCond_DOWN(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & DAT_UNIT_FLAG_DOWN) ? 0 : 1;
}



// FUN_001DB7B0
s32 btlCond_SLIP(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 0x10) ? 0 : 1;
}



/* Ported from P3FES btlEffect.c func_002c3300 (genus-match loop).
   func_002ffcc0->func_00231e20 (masked u8); iGpffffb6fc+0x14c->iGpffffb3ac+0x174;
   offsets 0xa2c->0xa64, 0x4a8->0x450. Pragma disables the shift-fold. */
#pragma opt_rebuildconditionals off
// FUN_001DB7D0
u32 btlCond_ENOVERLV(int param_1, u32 param_2)
{
    u32 genusValue;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        goto nonzero_genus;
    }
    genusValue = 1;
    goto genus_done;
nonzero_genus:
    genusValue = 0;
genus_done:
    {
        u32 genus = (u16)genusValue;
        u32 current = (u8)datCalcGetLevel(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa64));
        int unit = *(int *)(iGpffffb3ac + 0x174);
        u32 candidate;
        u32 comparison;

        genus = (u16)genus;
        while (unit != 0) {
            if (((*(u16 *)(unit + 0x1a) & 1) != 0) &&
                ((*(u16 *)(unit + 0x1a) & 8) != 0) &&
                (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) == genus)) {
                candidate = (u8)datCalcGetLevel(*(u32 *)(*(int *)(unit + 0x30) + 0xa64));
                comparison = candidate < current;
                if (comparison != 0) {
                    goto next_unit;
                }
                comparison = (candidate - current) < param_2;
                if (comparison != 0) {
                    goto next_unit;
                }
                return 1;
            }
next_unit:
            unit = *(int *)(unit + 0x450);
        }
    }
    return 0;
}
#pragma opt_rebuildconditionals on


// FUN_001DB8D0
s32 btlCond_MYHOJO(u8 *arg0, s32 arg1) {
    return (s32)(datCalcHasBuffMask(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), arg1) != 0);
}

// FUN_001DB900
s32 btlCond_MYTAISEI(u8 *arg0, s16 arg1) {
    return (s32)((datCalcStatusResistance(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), (s32)arg1) & 0x10000000) != 0);
}



// FUN_001DB940
void btlCond_FRTAISEI(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code *)&btlCond_MYTAISEI);
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB990 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB990
void btlCond_ENTAISEI(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code *)&btlCond_MYTAISEI);
}

#pragma opt_rebuildconditionals on
/* measured: propagation off retains index preparation before the enemy load
   with the canonical u32 bitmap arguments; 156B/window 160B, normalized_diff 0. */
#pragma push
#pragma opt_propagation off
// FUN_001DB9F0
s32 btlCond_MYNOTNOMAL(u8 *arg0, s16 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(p + 0xA2) == 1 && func_001f9ce0(arg0, arg1) == 0) {
        u32 index = (u16)arg1;
        if (datTestBitmapBit(*(u16 *)(p + 0xA4), index) == 0)
            return 0;
    }
    return (datCalcAilmentChance(*(u8 **)(p + 0xA64), (s32)arg1) & 0x7000000) != 0;
}
#pragma pop

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DBA90 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DBA90
void btlCond_ENNOTNOMAL(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0xA, (code *)&btlCond_MYNOTNOMAL);
}

#pragma opt_rebuildconditionals on
// FUN_001DBAF0
s32 btlCond_MYWALL(u8 *arg0, u32 arg1) {
    s32 mask = 0;
    if (arg1 & 1)
        mask |= 0x8000000;
    if (arg1 & 2)
        mask |= 0x10000000;
    if (arg1 & 4)
        mask |= 0x20000000;
    if (arg1 & 8)
        mask |= 0x40000000;
    if (mask == 0)
        return 0;
    return datCalcHasBuffMask(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), mask) != 0;
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
// FUN_001DBBA0
#pragma opt_dead_assignments off
s32 btlAICommandSelectCandidates(arg0, arg1, arg2, arg3, arg4, arg5)
s32 arg0;
s32 arg1;
s32 arg2;
s32 arg3;
s32 arg4;
code arg5;
{
    s32 f23;
    s32 f17;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 m4;
    u8 *temp19;
    u8 *temp16;
    s32 c18;
    s32 i22;
    u8 *selected[12];

    f23 = arg3 & 0xFFFF;
    if ((f23 & 0x20) != 0) {
        btlEffectCollectTargetUnits((u8 *)arg0, (u8 *)arg0 + 0x98, 2, 0, 0);
    } else {
        u16 available;

        available = btlSkillClassifyTargets((u8 *)arg0, (u8 *)arg0 + 0x98, *(u16 *)((u8 *)arg0 + 0x6E), 0);
        if (available != 0) {
            u16 eindex;
            u16 ecount;

            eindex = 0;
            while ((ecount = *(u16 *)((u8 *)arg0 + 0xD0)), (u16)eindex < ecount) {
                *(u32 *)((u8 *)arg0 + (eindex & 0xFFFF) * 4 + 0x38) =
                    *(u32 *)((u8 *)arg0 + (eindex & 0xFFFF) * 4 + 0x98);
                eindex++;
            }
            *(u16 *)((u8 *)arg0 + 0x6A) = ecount;
            return 1;
        }
    }
    c18 = 0;
    i22 = 0;
    f17 = (u16)arg3;
    m1 = f17 & 1;
    m2 = f17 & 2;
    m3 = f17 & 0x10;
    m4 = f17 & 0x40;
    for (; (u16)i22 < *(u16 *)((u8 *)arg0 + 0xD0); i22 = (i22 + 1) & 0xFFFF) {
        temp19 = *(u8 **)((u8 *)arg0 + (i22 & 0xFFFF) * 4 + 0x98);
        if ((*(u16 *)(temp19 + 0x1A) & 1) == 0) {
            continue;
        }
        temp16 = *(u8 **)(temp19 + 0x30);
        if (f17 == 0) {
            goto testm4;
        }
        if (m1 == 0) {
            goto testm2;
        }
        if (datCalcChkBadStatus(*(u32 *)(temp16 + 0xA64), 0x100000) == 0) {
            continue;
        }
    testm2:
        if (m2 == 0) {
            goto testm3;
        }
        if (*(u8 *)(temp16 + 0xA2) != 1 || func_001f9ce0(temp19, (s16)arg1) != 0) {
            goto testm3;
        }
        {
            u32 index = (u16)arg1;
            if (datTestBitmapBit(*(u16 *)(temp16 + 0xA4), index) == 0) {
                continue;
            }
        }
    testm3:
        if (m3 == 0) {
            goto testm4;
        }
        if (btlAICommandCollectSkillCandidates((u8 *)arg0, temp19, 0, 0) < 0) {
            continue;
        }
    testm4:
        if (m4 == 0) {
            if (datCalcChkBadStatus(*(u32 *)(temp16 + 0xA64), arg2) != 0) {
                continue;
            } else {
                goto docallback;
            }
        }
        if (datCalcHasBuffMask(*(u8 **)(temp16 + 0xA64), arg2) != 0) {
            continue;
        }
    docallback:
        if (arg5(temp19, arg1) != arg4) {
            selected[(u16)c18] = temp19;
            c18 = (c18 + 1) & 0xFFFF;
        }
    }
    {
        s32 count;

        count = c18 & 0xFFFF;
        if (count == 0) {
            if ((f23 & 8) != 0) {
                return 0;
            }
            return btlAICommandPickAiTarget((u8 *)arg0, arg1);
        }
        if ((f23 & 4) == 0) {
            s32 pick;

            pick = 0;
            if (count > 1) {
                pick = datCalcRandomBelow(count) & 0xFFFF;
            }
            *(u8 **)((u8 *)arg0 + 0x38) = selected[pick & 0xFFFF];
            *(u16 *)((u8 *)arg0 + 0x6A) = 1;
        } else {
            s32 k;

            k = 0;
            while ((u16)k < count) {
                *(u8 **)((u8 *)arg0 + (k & 0xFFFF) * 4 + 0x38) = selected[k & 0xFFFF];
                k = (k + 1) & 0xFFFF;
            }
            *(u16 *)((u8 *)arg0 + 0x6A) = c18;
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
typedef struct SortEnt {
    u32 unit;
    f32 ratio;
} SortEnt;
// FUN_001DBF20
s32 btlAICommandPickAiTarget(u8 *arg0, u32 arg1) {
    extern u8 D_006095F0[];
    u16 available;
    u16 i;
    u16 v7;
    s32 v8;
    s32 j;
    u8 g;
    u16 n;
    s32 c18;
    u8 *e;
    u32 w;
    u32 f15;
    u32 f16;
    SortEnt stab[12];
    s32 swapped;
    f32 r0;
    u32 t0;
    s32 tot;
    u16 m;
    u16 rnd;

    available = btlSkillClassifyTargets(arg0, arg0 + 0x98, *(u16 *)(arg0 + 0x6E), 0);
    if (available != 0) {
        i = 0;
        while ((v7 = *(u16 *)(arg0 + 0xD0)), (u16)i < v7) {
            *(u32 *)(arg0 + (i & 0xFFFF) * 4 + 0x38) = *(u32 *)(arg0 + (i & 0xFFFF) * 4 + 0x98);
            i++;
        }
        *(u16 *)(arg0 + 0x6A) = v7;
        return 1;
    }
    v7 = *(u16 *)(arg0 + 0xD0);
    v8 = 1;
    if (v7 == 1) {
        *(u32 *)(arg0 + 0x38) = *(u32 *)(arg0 + 0x98);
        *(u16 *)(arg0 + 0x6A) = 1;
    } else {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1) {
            j = 0;
            while ((u16)j < v7) {
                if (*(u8 *)(*(u8 **)(*(u32 *)(arg0 + (j & 0xFFFF) * 4 + 0x98) + 0x30) + 0xA2) != 0) {
                    break;
                }
                j = (j + 1) & 0xFFFF;
            }
            if ((u16)j == v7) {
                v8 = 0;
            }
        }
        g = *(iGpffffb3b8 + *(u16 *)(arg0 + 0x6E) * 40 + 17);
        if (g == 0x10 || g == 0x0E || g == 0x0D || g == 0x0C || g == 0x0A || g == 0x08 || g == 0x04 || g == 0x03 || g == 0x01) {
        } else {
            v8 = 1;
        }
        if (v8 != 0 || v7 > 4) {
            *(u32 *)(arg0 + 0x38) = ((u32 *)(arg0 + 0x98))[(u16)datCalcRandomBelow(v7)];
            *(u16 *)(arg0 + 0x6A) = 1;
        } else {
            n = 0;
            c18 = v7 & 0xFFFF;
            while (n < c18) {
                e = arg0 + (n & 0xFFFF) * 4 + 0x98;
                w = *(u32 *)e;
                f15 = datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(w + 0x30) + 0xA64)) & 0xFFFF;
                f16 = datCalcGetHp(*(u32 *)(*(u32 *)(w + 0x30) + 0xA64)) & 0xFFFF;
                stab[n & 0xFFFF].unit = *(u32 *)e;
                stab[n & 0xFFFF].ratio = (f32)f16 / (f32)f15;
                n++;
            }
            do {
                swapped = 0;
                for (n = 0; n < (s32)c18 - 1; n++) {
                    if ((r0 = stab[n].ratio) < stab[n + 1].ratio) {
                        t0 = stab[n].unit;
                        stab[n].unit = stab[n + 1].unit;
                        stab[n].ratio = stab[n + 1].ratio;
                        stab[n + 1].unit = t0;
                        stab[n + 1].ratio = r0;
                        swapped = 1;
                    }
                }
            } while (swapped != 0);
            rnd = datCalcRandomBelow(100);
            tot = 0;
            m = 0;
            while (m < v7) {
                tot = (tot + D_006095F0[4 * v7 - 4 + m]) & 0xFFFF;
                if (tot >= rnd) {
                    break;
                }
                m++;
            }
            if (c18 != m) {
                *(u32 *)(arg0 + 0x38) = stab[m].unit;
                *(u16 *)(arg0 + 0x6A) = 1;
            } else {
                *(u32 *)(arg0 + 0x38) = stab[datCalcRandomBelow(v7)].unit;
                *(u16 *)(arg0 + 0x6A) = 1;
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
// FUN_001DC380
u32 btlCond_HPMIN(u32 param_1)
{
    u32 unit;
    u16 available;

    unit = param_1;
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
            stat = *(u16 *)(*(int *)(*(int *)(candidate + 0x30) + 0xa64) + 8);
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
// FUN_001DC480
u32 btlCond_LVMIN(u32 param_1)
{
    u16 result;
    u16 copyIndex;
    int unit;
    int selected;
    u16 index;
    u16 best;
    u16 score;
    u32 idx32;

    result = btlSkillClassifyTargets((u8 *)param_1, (u8 *)(param_1 + 0x98), *(u16 *)(param_1 + 0x6e), 0);
    if (result != 0) {
        for (copyIndex = 0; copyIndex < *(u16 *)(param_1 + 0xd0); copyIndex++) {
            *(u32 *)(param_1 + copyIndex * 4 + 0x38) = *(u32 *)(param_1 + copyIndex * 4 + 0x98);
        }
        *(u16 *)(param_1 + 0x6a) = *(u16 *)(param_1 + 0xd0);
        return 1;
    }
    selected = 0;
    best = 0xffff;
    for (index = 0; index < *(u16 *)(param_1 + 0xd0); index++) {
        idx32 = index;
        idx32 = idx32 & 0xffff;
        unit = *(int *)(param_1 + idx32 * 4 + 0x98);
        score = (u8)datCalcGetLevel(*(u32 *)(*(int *)(unit + 0x30) + 0xa64));
        if (score < best) {
            selected = unit;
            best = score;
        }
    }
    *(int *)(param_1 + 0x38) = selected;
    *(u16 *)(param_1 + 0x6a) = 1;
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
// FUN_001DC6A0
u32 btlCond_MYAI(int param_1)
{
    int iVar1;
    u16 uVar3;
    int aiStack_30[12];

    uVar3 = 0;
    for (iVar1 = *(int *)(iGpffffb3ac + 0x174); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x450)) {
        if ((((param_1 != iVar1) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)) &&
            ((*(u16 *)(iVar1 + 0x1a) & 8) != 0)) &&
           ((*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) == *(u8 *)(*(int *)(iVar1 + 0x30) + 0xa2) &&
            (datCalcChkBadStatus(*(u32 *)(*(int *)(iVar1 + 0x30) + 0xa64), 0x80000) == 0))
           )) {
            aiStack_30[uVar3] = iVar1;
            uVar3++;
        }
    }
    if (uVar3 == 0) {
        *(int *)(param_1 + 0x38) = param_1;
        *(u16 *)(param_1 + 0x6a) = 1;
        return 1;
    }
    else {
        *(int *)(param_1 + 0x38) = aiStack_30[datCalcRandomBelow(uVar3)];
        *(u16 *)(param_1 + 0x6a) = 1;
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
// FUN_001DC9A0
u32 btlCond_AI_REV(u32 param_1)
{
    u16 result;
    u16 index;
    u32 address;

    result = btlSkillClassifyTargets((u8 *)param_1, (u8 *)(param_1 + 0x98), *(u16 *)(param_1 + 0x6e), 1);
    if (result != 0) {
        for (index = 0; index < *(u16 *)(param_1 + 0xd0); index++) {
            *(u32 *)(param_1 + index * 4 + 0x38) = *(u32 *)(param_1 + index * 4 + 0x98);
        }
        *(u16 *)(param_1 + 0x6a) = *(u16 *)(param_1 + 0xd0);
        return 1;
    }
    index = datCalcRandomBelow(*(u16 *)(param_1 + 0xd0));
    address = (index & 0xffff) * 4;
    *(u32 *)(param_1 + 0x38) = *(u32 *)(address + param_1 + 0x98);
    *(u16 *)(param_1 + 0x6a) = 1;
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
// FUN_001DCA60
s32 btlCond_APPOINT(u8 *param_1, u32 param_2)
{
    u16 result;
    u16 index;

    result = btlSkillClassifyTargets((u8 *)param_1, (u8 *)(param_1 + 0x98), *(u16 *)(param_1 + 0x6e), 0);
    if (result != 0) {
        for (index = 0; index < *(u16 *)(param_1 + 0xd0); index++) {
            *(u32 *)(param_1 + index * 4 + 0x38) = *(u32 *)(param_1 + index * 4 + 0x98);
        }
        *(u16 *)(param_1 + 0x6a) = *(u16 *)(param_1 + 0xd0);
        return 1;
    }
    if (btlEffectSelectNearestEntry(0, (u8 *)(param_1 + 0x98)) == 0) {
        return btlAICommandPickAiTarget(param_1, param_2);
    }
    *(u32 *)(param_1 + 0x38) = func_001d8bc0((u8 *)(param_1 + 0x98));
    *(u16 *)(param_1 + 0x6a) = 1;
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
// FUN_001DCF10
u32 btlCond_RND(u32 param_1)
{
    u16 result;
    u16 index;
    u32 address;

    result = btlSkillClassifyTargets((u8 *)param_1, (u8 *)(param_1 + 0x98), *(u16 *)(param_1 + 0x6e), 0);
    if (result != 0) {
        for (index = 0; index < *(u16 *)(param_1 + 0xd0); index++) {
            *(u32 *)(param_1 + index * 4 + 0x38) = *(u32 *)(param_1 + index * 4 + 0x98);
        }
        *(u16 *)(param_1 + 0x6a) = *(u16 *)(param_1 + 0xd0);
        return 1;
    }
    index = datCalcRandomBelow(*(u16 *)(param_1 + 0xd0));
    address = (index & 0xffff) * 4;
    *(u32 *)(param_1 + 0x38) = *(u32 *)(address + param_1 + 0x98);
    *(u16 *)(param_1 + 0x6a) = 1;
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
// FUN_001DD0D0
u32 btlCond_HPMAX(u32 param_1)
{
    u16 result;
    u16 index;
    u32 best;
    u32 j;
    u32 bestScore;
    u32 count;

    result = btlSkillClassifyTargets((u8 *)param_1, (u8 *)(param_1 + 0x98), *(u16 *)(param_1 + 0x6e), 0);
    if (result != 0) {
        for (index = 0; index < *(u16 *)(param_1 + 0xd0); index++) {
            *(u32 *)(param_1 + index * 4 + 0x38) = *(u32 *)(param_1 + index * 4 + 0x98);
        }
        *(u16 *)(param_1 + 0x6a) = *(u16 *)(param_1 + 0xd0);
        return 1;
    }
    best = 0;
    bestScore = 0;
    j = 0;
    count = *(u16 *)(param_1 + 0xd0);
    while (j < count) {
        u8 *ptr = (u8 *)*(u32 *)(param_1 + j * 4 + 0x98);
        u32 score = *(u16 *)(*(u32 *)(*(u32 *)(ptr + 0x30) + 0xA64) + 0x8);
        if (bestScore < score) {
            best = (u32)ptr;
            bestScore = score;
        }
        j++;
    }
    *(u32 *)(param_1 + 0x38) = best;
    *(u16 *)(param_1 + 0x6a) = 1;
    return 1;
}
// FUN_001DD1C0
s32 btlAICommandPickSkillTargetByHp(u8 *p, u8 *q, u16 *t, u16 u, u32 v) {
    u32 s;
    s32 bd;
    s32 best;
    s32 i;
    u32 v2;
    s32 u2;
    u16 *e;
    u16 w;
    u8 b;
    s32 d;
    s32 d2;

    s = datCalcGetHp(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64)) & 0xFFFF;
    best = -1;
    bd = 0xFFFFFF;
    i = 0;
    v2 = v & 0xFFFF;
    u2 = u & 0xFFFF;
    while ((i & 0xFFFF) < u2) {
        e = t + (u16)i;
        w = *(u16 *)e;
        if (w == 0)
            b = 0;
        else
            b = *(u8 *)(iGpffffb3b8 + w * 40 + 8);
        if ((v2 != 0 || (b & 0xFF) == 1) && (v2 != 1 || (b & 0xFF) == 0)) {
            d = datCalcSkillAmount(w, (u8 *)*(u32 *)(*(u32 *)(p + 0x30) + 0xA64), (u8 *)*(u32 *)(*(u32 *)(q + 0x30) + 0xA64), 1, 1, 1, 0, 1);
            d2 = s + d;
            if (d2 > 0 && bd > 0) {
                if (d2 < bd) {
                    best = *(u16 *)e;
                    bd = d2;
                }
                goto next;
            }
            if (d2 <= 0 && (bd > 0 || bd < d2)) {
                best = *(u16 *)e;
                bd = d2;
            }
        }
    next:
        i = (i + 1) & 0xFFFF;
    }
    datCalcClearField18(*(u32 *)(*(u32 *)(p + 0x30) + 0xA64));
    datCalcClearField18(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64));
    return best;
}
// FUN_001DD3A0
s32 btlAICommandPickSkillTargetNearMaxHp(u8 *p, u8 *q, u16 *t, u16 u, s32 v) {
    u32 s1;
    u32 s2;
    s32 bd;
    s32 best;
    s32 i;
    u32 v2;
    s32 u2;
    u16 *e;
    u16 w;
    u8 b;
    s32 d;

    s1 = datCalcGetHp(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64)) & 0xFFFF;
    s2 = datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(q + 0x30) + 0xA64)) & 0xFFFF;
    best = -1;
    bd = 0xFFFFFF;
    i = 0;
    v2 = v & 0xFFFF;
    u2 = u & 0xFFFF;
    while ((i & 0xFFFF) < u2) {
        e = t + (u16)i;
        w = *(u16 *)e;
        if (w != 0 && w < 0x1B8) {
            b = *(u8 *)(iGpffffb3b8 + w * 40 + 8);
            if ((v2 != 0 || (b & 0xFF) == 1) && (v2 != 1 || (b & 0xFF) == 0)) {
                d = func_0043c6a0(s2 - (s1 + datCalcSkillAmount(w, (u8 *)*(u32 *)(*(u32 *)(p + 0x30) + 0xA64), (u8 *)*(u32 *)(*(u32 *)(q + 0x30) + 0xA64), 1, 1, 1, 0, 1)));
                if (d < bd) {
                    best = *(u16 *)e;
                    bd = d;
                }
            }
        }
        i = (i + 1) & 0xFFFF;
    }
    datCalcClearField18(*(u32 *)(*(u32 *)(p + 0x30) + 0xA64));
    datCalcClearField18(*(u32 *)(*(u32 *)(q + 0x30) + 0xA64));
    return best;
}
/* Recovered: retail's shape is a scoped `opt_propagation off` translation
   unit region, which is why the object keeps folds this build would remove
   (the first tally increment stays `addiu $v0,$s2,1; andi $s2,$v0,0xffff`
   after the tally is zeroed, and `ok = 1` is still tested by `beqz $v0`).
   Four source shapes carry the rest: the loop bound is a separate `s32`
   copy of the u16 limit (retail keeps the u16 in $s1 and spills the int
   copy to 0xB0, masking once instead of once per iteration), `idx = 0`
   precedes that copy, both legs of the command test assign `ok = 0` and
   jump to a single shared `ok = 1`, and the dispatch is a `switch` whose
   cases `break` to one `return r` - the trampoline at 0x1dd8d4 - with the
   `return -1` left as the function's last statement.  With the limit mask
   written `(u16)call()` (propagation-off lowers `call() & 0xFFFF` as
   ori/and) this is byte-exact. */
// FUN_001DD570
#pragma push
#pragma opt_propagation off
s32 btlAICommandCollectSkillCandidates(u8 *p, u8 *q, s32 arg2, s32 arg3)
{
    u8 *unit0;
    s16 cur0;
    u16 buf[8];
    u16 idx;
    u16 n;
    u16 *table;
    u16 limit;
    s32 count;
    u16 *e;
    u16 v;
    s16 cur;
    s32 flags;
    u16 cmd;
    u8 *unitP;
    s32 ok;
    s32 r;

    n = 0;
    unit0 = *(u8 **)(p + 0x30);
    cur0 = (s16)datCalcSkillElement(*(u8 **)(unit0 + 0xA64), 0);
    if (btlAICommandNomalCheck(q, cur0, 1) != 0) {
        buf[0] = 0;
        n++;
    }
    limit = (u16)datCalcGetTableLength(*(u8 **)(unit0 + 0xA64));
    table = (u16 *)datCalcSkillList(*(u8 **)(unit0 + 0xA64));
    idx = 0;
    count = limit;
    while (idx < count) {
        e = table + idx;
        v = *e;
        if (v != 0 && v < 0x1B8) {
            cur = (s16)datCalcSkillElement(*(u8 **)(unit0 + 0xA64), v);
            flags = datCalcElementBit(cur);
            if (arg3 == 0) {
                if ((flags & 0x7E) == 0)
                    goto next;
            } else if (arg3 == 1) {
                if ((flags & 0x7E) == 0 || (flags & 2) != 0)
                    goto next;
            } else if (arg3 == 2) {
                if ((flags & 2) == 0)
                    goto next;
            }
            cmd = *e;
            if (cmd >= 0x240)
                kAssertFail(D_006095E0, 0x45F);
            unitP = *(u8 **)(p + 0x30);
            if (cmd < 0x1B8) {
                if (datCalcChkBadStatus(*(u32 *)(unitP + 0xA64), 0x80008) != 0) {
                    ok = 0;
                    goto have_ok;
                }
                if (datCalcHasSkill(*(u8 **)(unitP + 0xA64), cmd) == 0) {
                    ok = 0;
                    goto have_ok;
                }
                if (datCalcThresholdTrigger(*(u8 **)(unitP + 0xA64), cmd) != 0) {
                    ok = 0;
                    goto have_ok;
                }
            } else {
                if (datCalcHasSkill(*(u8 **)(unitP + 0xA64), cmd) == 0) {
                    ok = 0;
                    goto have_ok;
                }
            }
            ok = 1;
have_ok:
            if (ok == 0)
                goto next;
            if (btlAICommandNomalCheck(q, cur, 1) != 0) {
                buf[n] = *e;
                n++;
            }
        }
next:
        idx++;
    }
    if (n > 0) {
        switch (arg2) {
        case 0:
            r = btlAICommandPickSkillTargetByHp(p, q, buf, n, 0);
            if (r < 0)
                r = btlAICommandPickSkillTargetByHp(p, q, buf, n, 1);
            break;
        case 1:
            r = btlAICommandPickSkillTargetByHp(p, q, buf, n, 1);
            if (r < 0)
                r = btlAICommandPickSkillTargetByHp(p, q, buf, n, 0);
            break;
        default:
            r = btlAICommandPickSkillTargetByHp(p, q, buf, n, 0xFFFF);
            break;
        }
        return r;
    }
    return -1;
}
#pragma pop
/* Measured with b210: the scoped scan aggregates preserve iterator lifetimes
   through scalarization. The status scan keeps a native index with explicit
   halfword boundaries; both scans reload entries after the usability calls.
   Allocator capture traced the former selector/count exchange to the healing
   scan's command/index coloring, rather than their declaration order. */
// FUN_001DD920
s32 btlAICommandCollectRecoveryCommands(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3)
{
    u8 *unit;
    u16 count;
    u16 *commands;
    u16 table[8];
    u16 n;
    s16 result;
    u16 cmd;
    u32 hp;
    u32 max;
    s32 cur;
    s32 r;

    result = -1;
    n = 0;
    unit = *(u8 **)(arg0 + 0x30);
    count = datCalcGetTableLength(*(u8 **)(unit + 0xA64));
    commands = (u16 *)datCalcSkillList(*(u8 **)(unit + 0xA64));
    if (datCalcIsDead(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64), 0) != 0) {
        result = 0;
    } else {
        hp = *(u16 *)(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64) + 8);
        max = (u16)datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64));
        if (hp * 100 <= max * 60) {
            result = 1;
        } else {
            if (datCalcChkBadStatus(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64), 0xC) != 0) {
                result = 2;
            } else {
                cur = datCalcGetHp(*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64)) & 0xFFFF;
                if (cur < (s32)(datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(arg1 + 0x30) + 0xA64)) & 0xFFFF))
                    result = 1;
            }
        }
    }
    switch (result) {
    case 0: {
        u16 i;
        u16 *entry;
        s32 limit;

        i = 0;
        limit = count;
        while (i < limit) {
            entry = commands + i;
            cmd = *entry;
            if (cmd != 0 && cmd < 0x1B8) {
                switch (cmd) {
                case 0xD1: case 0xD2:
                    if (btlCommandUsable(arg0, cmd)) {
                        table[n] = *entry;
                        n++;
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
        scan.limit = count;
        while (scan.i < scan.limit) {
            scan.entry = commands + scan.i;
            cmd = *scan.entry;
            if (cmd != 0 && cmd < 0x1B8) {
                switch (cmd) {
                case 0xC0: case 0xC1: case 0xC2: case 0xC3:
                case 0xC4: case 0xC5: case 0xC6:
                    if (btlCommandUsable(arg0, cmd)) {
                        table[n] = *scan.entry;
                        n++;
                    }
                    break;
                }
            }
            scan.i++;
        }
        if (n > 0) {
            switch (arg3) {
            case 0:
                r = btlAICommandPickSkillTargetNearMaxHp(arg0, arg1, table, n, 0);
                if (r < 0)
                    r = btlAICommandPickSkillTargetNearMaxHp(arg0, arg1, table, n, 1);
                break;
            case 1:
                r = btlAICommandPickSkillTargetNearMaxHp(arg0, arg1, table, n, 1);
                if (r < 0)
                    r = btlAICommandPickSkillTargetNearMaxHp(arg0, arg1, table, n, 0);
                break;
            default:
                r = btlAICommandPickSkillTargetNearMaxHp(arg0, arg1, table, n, 0xFFFF);
                break;
            }
            return r;
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
        scan.limit = count;
        while ((u16)scan.i < scan.limit) {
            scan.entry = commands + (u16)scan.i;
            cmd = *scan.entry;
            if (cmd != 0 && cmd < 0x1B8) {
                switch (cmd) {
                case 0xC7: case 0xC8:
                    if (btlCommandUsable(arg0, cmd)) {
                        table[n] = *scan.entry;
                        n++;
                    }
                    break;
                }
            }
            scan.i = (u16)(scan.i + 1);
        }
        break;
    }
    }
    if (n > 0)
        return table[datCalcRandomBelow(n)];
    return -1;
}
/* measured: matched by declaring func_001dd1c0's count parameter u16, so
   the u16 tally passes raw ($a3 = $s2) instead of reusing a promoted
   copy; the guard and the table index keep their own andi temps, which
   is retail's shape. The callee is unaffected (still exact). */
// FUN_001DE000
#pragma push
#pragma opt_propagation off
s32 btlAICommandCollectCommandsOfType(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3)
{
    extern s32 btlAICommandCollectRecoveryCommands(u8 *arg0, u8 *arg1, s16 arg2, s32 arg3);
    u8 *unit;
    s16 queried;
    s16 q;
    u16 count;
    s32 limit;
    u16 *commands;
    u16 j;
    u16 n;
    u16 *entry;
    u16 cmd;
    u16 table[8];
    s32 r;

    if (arg2 == 0x10)
        return btlAICommandCollectRecoveryCommands(arg0, arg1, arg2, arg3);

    n = 0;
    unit = *(u8 **)(arg0 + 0x30);
    queried = datCalcSkillElement(*(u8 **)(unit + 0xA64), 0);
    if (queried == arg2 && btlAICommandNomalCheck(arg1, queried, 1) != 0) {
        table[0] = 0;
        n++;
    }
    count = datCalcGetTableLength(*(u8 **)(unit + 0xA64));
    commands = (u16 *)datCalcSkillList(*(u8 **)(unit + 0xA64));
    j = 0;
    limit = count;
    for (; j < limit; j++) {
        entry = commands + j;
        if (*entry == 0 || *entry >= 0x1B8)
            goto next;
        queried = datCalcSkillElement(*(u8 **)(unit + 0xA64), *entry);
        if (queried != arg2)
            goto next;
        cmd = *entry;
        if (btlCommandUsable(arg0, cmd) == 0)
            goto next;
        q = queried;
        if (btlAICommandNomalCheck(arg1, q, 1) == 0)
            goto next;
        table[n] = *entry;
        n++;
    next:
        ;
    }
    if (n > 0) {
        switch (arg3) {
        case 0:
            r = btlAICommandPickSkillTargetByHp(arg0, arg1, table, n, 0);
            if (r < 0)
                r = btlAICommandPickSkillTargetByHp(arg0, arg1, table, n, 1);
            break;
        case 1:
            r = btlAICommandPickSkillTargetByHp(arg0, arg1, table, n, 1);
            if (r < 0)
                r = btlAICommandPickSkillTargetByHp(arg0, arg1, table, n, 0);
            break;
        default:
            r = btlAICommandPickSkillTargetByHp(arg0, arg1, table, n, 0xFFFF);
            break;
        }
    } else {
        return -1;
    }
    return r;
}
#pragma pop
#pragma push
/* measured: opt_loop_invariants on is required for the retail-sized frame and
   bubble-sort register coloring; the COP1 chain is ordinary C arithmetic and
   D_00609600 is a real, placeable linker symbol. */
#pragma opt_loop_invariants on
// FUN_001DE370
u32 btlAICommandPickUnitByHpWeight(u8 *arg0)
{
    u32 i;
    u32 random;
    u32 cumulative;
    s16 scores[16];
    u32 selectionIndex;
    u32 total;

    if (*(u16 *)(arg0 + 0xD0) == 1)
        return *(u32 *)(arg0 + 0x98);

    total = 0;
    i = 0;
    while (i < *(u16 *)(arg0 + 0xD0)) {
        u8 *unit;
        s16 *score;
        u32 max;
        u32 current;
        f32 scoreFloat;
        f32 bonus;

        total += D_00609600[i];
        unit = *(u8 **)(arg0 + i * 4 + 0x98);
        score = scores + i;
        *score = 0;
        max = datCalcMaxHp((DatUnit *)*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64)) & 0xFFFF;
        current = datCalcGetHp(*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64)) & 0xFFFF;
        *score += (s16)(100.0f - 100.0f * ((f32)current / (f32)max));
        switch (datCalcGetBadStatusNoDown(*(u32 *)(*(u32 *)(unit + 0x30) + 0xA64))) {
        case 0x40:
            bonus = 50.0f;
            scoreFloat = (f32)*score;
            *score = (s16)(scoreFloat + bonus);
            break;
        default:
            break;
        }
        i++;
    }
    {
        u32 bubbleIndex;
        s16 *sortScore;
        s32 swapped;
        u32 one;
        one = 1;
        do {
        swapped = 0;
        for (bubbleIndex = 0; bubbleIndex < *(u16 *)(arg0 + 0xD0) - 1; bubbleIndex++) {
            s32 left;
            s32 right;
            s16 *nextScore;

            sortScore = scores + bubbleIndex;
            nextScore = sortScore + 1;
            right = *nextScore;
            left = *sortScore;
            if (left < right) {
                u8 *entry;
                u32 temp;

                entry = arg0 + bubbleIndex * 4;
                temp = *(u32 *)(entry + 0x98);
                *(u32 *)(entry + 0x98) = *(u32 *)(entry + 0x9C);
                *(u32 *)(entry + 0x9C) = temp;
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
    for (; selectionIndex < *(u16 *)(arg0 + 0xD0); selectionIndex++) {
        cumulative += D_00609600[selectionIndex];
        if (random < cumulative)
            return *(u32 *)((u8 *)(selectionIndex * 4) + (u32)arg0 + 0x98);
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
// FUN_001DE640
void btlAICommandSetActionCode(u8 *p, u8 *q, u16 v)
{
    u16 t;

    if ((v & 0xF000) == 0x8000)
        t = v;
    else
        t = v & 0xF000;
    switch (t & 0xFFFF) {
    case 0x8000:
        *(u16 *)(q + 0x34) = 1;
        *(u16 *)(q + 0x36) = datCalcDefaultSkillId(*(u8 **)(*(u8 **)(p + 0x30) + 0xA64)) & 0xFFFF;
        break;
    case 0x1000:
        *(u16 *)(q + 0x34) = 9;
        *(u16 *)(q + 0x36) = 0x111;
        *(u16 *)(q + 0x3E) = v & 0xFFFF0FFF;
        break;
    case 0x2000:
        *(u16 *)(p + 0xEC) = v & 0xFFFF0FFF;
    case 0x8002:
        *(u16 *)(q + 0x34) = 0x7;
        break;
    case 0x8007:
        *(u16 *)(q + 0x34) = 0x8;
        break;
    case 0x8005:
        break;
    case 0x8006:
        *(u16 *)(q + 0x34) = 0xB;
        break;
    case 0x8001:
        *(u16 *)(q + 0x34) = 0x6;
        break;
    case 0x8008:
        *(u16 *)(q + 0x34) = 0xC;
        break;
    case 0x8009:
        func_001ebc00(p, q);
        break;
    case 0x8004:
        v = (u16)(datCalcPickSpecialItem(*(u8 **)(*(u8 **)(p + 0x30) + 0xA64)) & 0xFFFF);
    default:
        *(u16 *)(q + 0x34) = 2;
        *(u16 *)(q + 0x36) = v;
        break;
    }
}
// FUN_001DE800
u8 btlAICommandPickTableAction(u8 *p) {
    u8 *base;
    u8 *row;
    s32 k;
    s32 j;
    u32 w;
    u32 e;
    u32 a2;
    s32 x;
    u32 arr[3];

    base = iGpffffb3d0 + (*(u16 *)(*(u32 *)(p + 0x30) + 0xA4)) * 164;
    k = 0;
    while ((u16)k < 2) {
        row = base + (k & 0xFFFF) * 20 + 4;
        j = 0;
        while ((u16)j < 3) {
            w = *(s32 *)(row + (j & 0xFFFF) * 4);
            e = (w & 0xFF000000) >> 24;
            a2 = w & 0xFFFFFF;
            if (e == 0)
                x = 0;
            else
                x = ((s32 (*)(u8 *, u32))D_00609850[e * 3])(p, a2);
            arr[j & 0xFFFF] = x;
            j = (j + 1) & 0xFFFF;
        }
        if (arr[0] && arr[1] && arr[2] && *(u8 *)(row + 0xC) != 8)
            return *(u8 *)(row + 0xC);
        if (arr[0] && arr[1] && *(u8 *)(row + 0xD) != 8)
            return *(u8 *)(row + 0xD);
        if (arr[0] && arr[2] && *(u8 *)(row + 0xE) != 8)
            return *(u8 *)(row + 0xE);
        if (arr[1] && arr[2] && *(u8 *)(row + 0xF) != 8)
            return *(u8 *)(row + 0xF);
        if (arr[0] && *(u8 *)(row + 0x10) != 8)
            return *(u8 *)(row + 0x10);
        if (arr[1] && *(u8 *)(row + 0x11) != 8)
            return *(u8 *)(row + 0x11);
        if (arr[2] && *(u8 *)(row + 0x12) != 8)
            return *(u8 *)(row + 0x12);
        if (*(u8 *)(row + 0x13) != 8)
            return *(u8 *)(row + 0x13);
        k = (k + 1) & 0xFFFF;
    }
    return 0;
}

/* Measured: 288B/288B, nd 0. Separate loop locals preserve register
   lifetimes; random-first comparison selects retail's $at branch.
   The random helper takes the summed weights, not the record pointer. */
// FUN_001DEA90
u8 *func_001dea90(u8 *p, u32 index)
{
    u8 *node;
    u8 *entry;
    u32 i;
    u32 sum;
    u32 total;
    u32 j;
    s32 random;
    s32 weight;

    node = iGpffffb3d0 + *(u16 *)(*(u32 *)(p + 0x30) + 0xA4) * 164;
    sum = 0;
    i = 0;
    node += (index & 0xffff) * 40;
    while ((u16)i < 5) {
        sum = (sum + *(u8 *)(node + (i & 0xffff) * 8 + 0x2c)) & 0xffff;
        i = (i + 1) & 0xffff;
    }
    if ((sum & 0xffff) == 0)
        return &iGpffffa2a8;
    random = datCalcRandomBelow(sum & 0xffff) & 0xffff;
    total = 0;
    j = 0;
    while ((u16)j < 5) {
        entry = node + (j & 0xffff) * 8;
        weight = entry[0x2c];
        total = (total + weight) & 0xffff;
        if (random <= (s32)total && weight > 0)
            return entry + 0x2c;
        j = (j + 1) & 0xffff;
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
// FUN_001DEBB0
s32 btlAICommandSpawnActionProc(u8 *p, u8 *q, u32 v, u32 w)
{
    u8 buf[32];
    u32 c;
    u32 t;
    u32 d;
    u32 v2;

    if (*(u8 *)(*(u32 *)(p + 0x30) + 0xA2) == 0) {
        c = *(u8 *)(*(u32 *)(*(u32 *)(p + 0x30) + 0xA64) + 0x10);
        sprintf(buf, D_00609E20, w, c);
        c = scrFindPrcdIdxByName(v, buf);
    } else {
        c = w;
    }
    t = func_0029da90((u8 *)(*(u32 *)(*(u32 *)(iGpffffb3ac + 0xDC8) + 0x20) - 1), v, c);
    func_0029dfe0(t, p);
    v2 = (u32)kwlnTaskGetWork(t);
    if (*(s32 *)(v2 + 0x130) >= 0) {
        switch (*(u8 *)(*(u32 *)(p + 0x30) + 0xA2)) {
        case 0:
            d = (u32)func_0010d740(*(s16 *)(*(u32 *)(p + 0x30) + 0xA4));
            break;
        case 1:
            d = (u32)iGpffffb444 + (*(u16 *)(*(u32 *)(p + 0x30) + 0xA4)) * 21;
            break;
        }
        itfMesWindowSetString(*(s32 *)(v2 + 0x130), 0, d);
    }
    kwlnTaskAddChild((u8 *)(*(u32 *)(iGpffffb3ac + 0xDC8)), t);
    *(u32 *)(q + 0x4C) = t;
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
   func_002c6e30->func_001dea90, func_002c6a00->func_001de640, PTR_FUN_006975e0->D_00609CE0;
   DAT_007ce41c->iGpffffb3d0 (integer-domain address forces the early base load),
   DAT_007ce4cc->iGpffffb3cc, DAT_007ce4d0->iGpffffb42c. func_001de800 declared
   locally as u32 to keep the &0xFFFF mask from folding to 0xff. */
// FUN_001DED30
void btlAICommandSetUnitAction(int param_1, int param_2)
{
    u8 type;
    u16 baseActionId;
    u16 actionId;
    int entry;
    u32 actionWord;
    u32 data;
    u32 result;

    baseActionId = *(u16 *)(*(int *)(param_1 + 0x30) + 0xa4);
    func_001eb3b0((u8 *)param_2);
    type = *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2);
    switch (type) {
    case 0:
        actionId = baseActionId;
        data = (u32)iGpffffb428;
        break;
    case 1:
        {
            u8 *table;
            u32 off;

            /* measured: the integer-domain address spelling forces the early base load (retail lw $a0,-0x4c30($gp) first), ported from donor func_002c70d0 */
            table = *(u8 **)((u32)&iGpffffb3d0);
            off = ((u32)baseActionId * 0x28 + (u32)baseActionId) * 4;
            table = (u8 *)(off) + (int)table;
            actionId = *(u16 *)(table + 2);
            data = (u32)iGpffffb42c;
        }
        break;
    }
    if (actionId > 0) {
        btlAICommandSpawnActionProc((u8 *)param_1, (u8 *)param_2, data, actionId);
        *(u8 *)(param_2 + 0x30) = 1;
    }
    else {
        extern u32 btlAICommandPickTableAction(u8 *);
        actionId = btlAICommandPickTableAction((u8 *)param_1) & 0xFFFF;
        entry = (int)func_001dea90((u8 *)param_1, actionId);
        btlAICommandSetActionCode((u8 *)param_1, (u8 *)param_2, *(u16 *)(entry + 2));
        actionWord = *(u32 *)(entry + 4);
        result = ((s32 (*)(u8 *, u32))D_00609CE0[((actionWord & 0xff000000) >> 0x18) * 2])((u8 *)param_1, actionWord & 0xffffff);
        if (result == 0) {
            ((s32 (*)(u8 *, u32))D_00609CE0[0])((u8 *)param_1, 0);
        }
    }
}


// FUN_001DEEE0
u32 btlAICommandTryReleaseProc(int param_1)
{
  u32 uVar1 = 0;
  long lVar2 = 0;

  if (*(u8 *)(param_1 + 0x30) == 0) {
    uVar1 = 1;
  }
  else if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 1;
  }
  else {
    lVar2 = kwlnTaskIsLinked(*(int *)(param_1 + 0x4c));
    if (lVar2 == 0) {
      *(u8 *)(param_1 + 0x30) = 0;
      *(u32 *)(param_1 + 0x4c) = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* AI script command 0x203d (p4flow AI.json AI_FUNCTION_003D). */
// FUN_001DEF60
u32 btlAICommandScriptSetDefaultAction(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *pVar1 = (char *)scrGetAiState();

  btlAICommandSetActionCode(pVar1, pVar1 + 0x38, 0x8000);
  return 1;
}



/* AI script command 0x203e (p4flow AI.json AI_FUNCTION_003E). */
// FUN_001DEFA0
s32 btlAICommandScriptSetActionParam(void) {
    u8 *p = scrGetAiState();
    s32 r = scrGetParamInt(0);
    if (r == 0)
        btlAICommandSetActionCode(p, p + 0x38, 0x8000);
    else if (r > 0)
        btlAICommandSetActionCode(p, p + 0x38, (u16)r);
    else
        btlAICommandSetActionCode(p, p + 0x38, 0x8002);
    return 1;
}

/* AI script command 0x2068 (p4flow AI.json AI_FUNCTION_0068). */
// FUN_001DF040
s32 btlAICommandScriptSetSkillAction(void) {
    u8 *p = scrGetAiState();
    s32 r = scrGetParamInt(0);
    if (r >= 0) {
        *(u16 *)(p + 0x6C) = 3;
        *(u16 *)(p + 0x70) = r;
        *(u16 *)(p + 0x6E) = datCalcUnderlyingSkillId((u16)r);
    } else {
        btlAICommandSetActionCode(p, p + 0x38, 0x8002);
    }
    return 1;
}

/* AI script command 0x203f (p4flow AI.json AI_FUNCTION_003F). */
// FUN_001DF0C0
u32 btlAICommandScriptSetAction8001(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)scrGetAiState();
  btlAICommandSetActionCode(pVar1, pVar1 + 0x38, 0x8001);
  return 1;
}



/* AI script command 0x2040 (p4flow AI.json AI_FUNCTION_0040). */
// FUN_001DF100
u32 btlAICommandScriptSetAction8002(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)scrGetAiState();
  btlAICommandSetActionCode(pVar1, pVar1 + 0x38, 0x8002);
  return 1;
}



/* AI script command 0x20d5 (p4flow AI.json AI_FUNCTION_00D5). */
// FUN_001DF140
s32 btlAICommandScriptSetActionSubword(void) {
    u8 *p = scrGetAiState();
    *(u16 *)(p + 0xEC) = scrGetParamInt(0);
    btlAICommandSetActionCode(p, p + 0x38, 0x8002);
    return 1;
}

/* AI script command 0x2041 (p4flow AI.json AI_FUNCTION_0041). */
// FUN_001DF1A0
s32 btlAICommandScriptSetAiPlan(void) {
    u8 *p = scrGetAiState();
    *(u16 *)(p + 0x6C) = 9;
    *(u16 *)(p + 0x6E) = 0x111;
    *(u16 *)(p + 0x76) = scrGetParamInt(0);
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2059 (p4flow AI.json AI_FUNCTION_0059). */
// FUN_001DF230
s32 btlAICommandScriptSetAiPlanWithArg(void) {
    u8 *p = scrGetAiState();
    *(u16 *)(p + 0x6C) = 9;
    *(u16 *)(p + 0x6E) = 0x111;
    *(u16 *)(p + 0x76) = scrGetParamInt(0);
    *(u16 *)(p + 0x78) = scrGetParamInt(1);
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2048 (p4flow AI.json AI_FUNCTION_0048). */
// FUN_001DF2D0
u32 btlAICommandScriptSetAction8007(void)
{
  extern u8 *scrGetAiState(void);
  extern void btlAICommandSetActionCode(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)scrGetAiState();
  btlAICommandSetActionCode(pVar1, pVar1 + 0x38, 0x8007);
  return 1;
}



/* AI script command 0x2000 (p4flow AI.json AI_FUNCTION_0000). */
// FUN_001DF310
s32 btlAICommandScriptQueryMyHp(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2001 (p4flow AI.json AI_FUNCTION_0001). */
// FUN_001DF3C0
s32 btlAICommandScriptQueryMyMp(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x2000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2002 (p4flow AI.json AI_FUNCTION_0002). */
// FUN_001DF470
s32 btlAICommandScriptQueryFrHp(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x3000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2003 (p4flow AI.json AI_FUNCTION_0003). */
// FUN_001DF520
s32 btlAICommandScriptQueryEnHp(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x4000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2004 (p4flow AI.json AI_FUNCTION_0004). */
// FUN_001DF5D0
s32 btlAICommandScriptQueryEnHpO(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x5000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2005 (p4flow AI.json AI_FUNCTION_0005). */
// FUN_001DF680
s32 btlAICommandScriptQueryMyLvO(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x6000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2006 (p4flow AI.json AI_FUNCTION_0006). */
// FUN_001DF730
s32 btlAICommandScriptQueryFrLvO(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x7000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2007 (p4flow AI.json AI_FUNCTION_0007). */
// FUN_001DF7E0
s32 btlAICommandScriptQueryEnLvO(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x8000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2008 (p4flow AI.json AI_FUNCTION_0008). */
// FUN_001DF890
s32 btlAICommandScriptQueryFrCnt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x9000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2009 (p4flow AI.json AI_FUNCTION_0009). */
// FUN_001DF940
s32 btlAICommandScriptQueryEnCnt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xA000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x200a (p4flow AI.json AI_FUNCTION_000A). */
// FUN_001DF9F0
s32 btlAICommandScriptQueryMyBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xB000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x200b (p4flow AI.json AI_FUNCTION_000B). */
// FUN_001DFAA0
s32 btlAICommandScriptQueryFrBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xC000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x200c (p4flow AI.json AI_FUNCTION_000C). */
// FUN_001DFB50
s32 btlAICommandScriptQueryEnBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xD000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x200d (p4flow AI.json AI_FUNCTION_000D). */
// FUN_001DFC00
s32 btlAICommandScriptQueryEnBadAll(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xE000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x200e (p4flow AI.json AI_FUNCTION_000E). */
// FUN_001DFCB0
s32 btlAICommandScriptQueryFrId(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xF000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x200f (p4flow AI.json AI_FUNCTION_000F). */
// FUN_001DFD60
s32 btlAICommandScriptQueryEnId(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x10000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2010 (p4flow AI.json AI_FUNCTION_0010). */
// FUN_001DFE10
s32 btlAICommandScriptQueryFrHojo(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x11000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2011 (p4flow AI.json AI_FUNCTION_0011). */
// FUN_001DFEC0
s32 btlAICommandScriptQueryEnHojo(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x12000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
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
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x16000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2016 (p4flow AI.json AI_FUNCTION_0016). */
// FUN_001E0110
s32 btlAICommandScriptQueryMyKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x17000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2017 (p4flow AI.json AI_FUNCTION_0017). */
// FUN_001E01C0
s32 btlAICommandScriptQueryMyMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x18000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2018 (p4flow AI.json AI_FUNCTION_0018). */
// FUN_001E0270
s32 btlAICommandScriptQueryMyWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x19000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2019 (p4flow AI.json AI_FUNCTION_0019). */
// FUN_001E0320
s32 btlAICommandScriptQueryFrHansya(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1A000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x201a (p4flow AI.json AI_FUNCTION_001A). */
// FUN_001E03D0
s32 btlAICommandScriptQueryEnHansya(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1B000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x201b (p4flow AI.json AI_FUNCTION_001B). */
// FUN_001E0480
s32 btlAICommandScriptQueryFrKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1C000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x201c (p4flow AI.json AI_FUNCTION_001C). */
// FUN_001E0530
s32 btlAICommandScriptQueryEnKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1D000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x201d (p4flow AI.json AI_FUNCTION_001D). */
// FUN_001E05E0
s32 btlAICommandScriptQueryFrMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1E000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x201e (p4flow AI.json AI_FUNCTION_001E). */
// FUN_001E0690
s32 btlAICommandScriptQueryEnMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1F000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x201f (p4flow AI.json AI_FUNCTION_001F). */
// FUN_001E0740
s32 btlAICommandScriptQueryFrWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x20000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2020 (p4flow AI.json AI_FUNCTION_0020). */
// FUN_001E07F0
s32 btlAICommandScriptQueryEnWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x21000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2021 (p4flow AI.json AI_FUNCTION_0021). */
// FUN_001E08A0
s32 btlAICommandScriptQueryMyUseAttr(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x22000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2022 (p4flow AI.json AI_FUNCTION_0022). */
// FUN_001E0950
s32 btlAICommandScriptQueryFrUseAttr(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x23000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2023 (p4flow AI.json AI_FUNCTION_0023). */
// FUN_001E0A00
s32 btlAICommandScriptQueryEnUseAttr(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x24000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2024 (p4flow AI.json AI_FUNCTION_0024). */
// FUN_001E0AB0
s32 btlAICommandScriptQueryMyUseSkil(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x25000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2025 (p4flow AI.json AI_FUNCTION_0025). */
// FUN_001E0B60
s32 btlAICommandScriptQueryFrUseSkil(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x26000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2026 (p4flow AI.json AI_FUNCTION_0026). */
// FUN_001E0C10
s32 btlAICommandScriptQueryEnUseSkil(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x27000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
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
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x2B000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x202b (p4flow AI.json AI_FUNCTION_002B). */
// FUN_001E0E60
s32 btlAICommandScriptQueryTurnO(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x2C000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
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
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x2F000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2052 (p4flow AI.json AI_FUNCTION_0052). */
// FUN_001E1060
s32 btlAICommandScriptQueryEnHansyaSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x30000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2053 (p4flow AI.json AI_FUNCTION_0053). */
// FUN_001E1110
s32 btlAICommandScriptQueryFrKyusyuSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x31000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2054 (p4flow AI.json AI_FUNCTION_0054). */
// FUN_001E11C0
s32 btlAICommandScriptQueryEnKyusyuSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x32000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2055 (p4flow AI.json AI_FUNCTION_0055). */
// FUN_001E1270
s32 btlAICommandScriptQueryFrMukouSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x33000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2056 (p4flow AI.json AI_FUNCTION_0056). */
// FUN_001E1320
s32 btlAICommandScriptQueryEnMukouSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x34000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2057 (p4flow AI.json AI_FUNCTION_0057). */
// FUN_001E13D0
s32 btlAICommandScriptQueryFrWeakSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x35000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2058 (p4flow AI.json AI_FUNCTION_0058). */
// FUN_001E1480
s32 btlAICommandScriptQueryEnWeakSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x36000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    int result;
    int dispatchResult;

    argument = scrGetParamInt(1);
    unit = scrGetAiState();
    sideMask = 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff;
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
    u8 *p = scrGetAiState();
    u32 *r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2))) & 0xFFFF, 0x80000);
    s32 x;
    if (r != 0)
        x = datCalcHasBuffMask(*(u8 **)(*(u8 **)((u8 *)r + 0x30) + 0xA64), scrGetParamInt(1));
    else
        x = 0;
    scrSetReturnInt(x != 0);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    u8 *p = scrGetAiState();
    u32 *r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2))) & 0xFFFF, 0x80000);
    s32 x;
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609A30[0])((u8 *)r, 0);
    else
        x = 0;
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2066 (p4flow AI.json AI_FUNCTION_0066). */
// FUN_001E2030
s32 btlAICommandSideIdQueryMyHrec(void) {
    u8 *p = scrGetAiState();
    u32 *r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2))) & 0xFFFF, 0x80000);
    s32 x;
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609A6C[0])((u8 *)r, 0);
    else
        x = 0;
    scrSetReturnInt(x != 0);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    int result;
    int dispatchResult;

    argument = scrGetParamInt(1);
    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
// FUN_001E2550
s32 btlAICommandSideIdQueryAllBadStatus(void) {
    u32 v;
    u32 m2;
    u32 c02;
    u32 m;
    u32 c0;
    u8 *node;
    s32 n;
    s32 k;
    u8 *np;
    u32 flag;

    m = (1 << (*(u8 *)(*(u32 *)(scrGetAiState() + 0x30) + 0xA2))) & 0xFFFF;
    c0 = scrGetParamInt(0) & 0xFFFF;
    v = scrGetParamInt(1);
    n = 0;
    k = 0;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    m2 = m & 0xFFFF;
    c02 = c0 & 0xFFFF;
    while (node != 0) {
        if ((*(u16 *)(node + 0x1A) & 1) && (*(u16 *)(node + 0x1A) & 8)) {
            np = *(u8 **)(node + 0x30);
            if ((m2 & (1 << (*(u8 *)(np + 0xA2)))) != 0) {
                if (*(u16 *)(np + 0xA4) == c02) {
                    if (datCalcIsDead(*(u32 *)(np + 0xA64), 0) == 0) {
                        n = (n + 1) & 0xFFFF;
                        if (datCalcChkBadStatus(*(u32 *)(np + 0xA64), v) != 0) {
                            k = (k + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        node = *(u8 **)(node + 0x450);
    }
    flag = 0;
    if ((n & 0xFFFF) > 0 && (n & 0xFFFF) == (k & 0xFFFF))
        flag = 1;
    scrSetReturnInt(flag != 0);
    return 1;
}

/* measured: byte-exact at nd 0. Reusing the c0 local for the node payload
   and m for the post-call c02 value gives retail's saved-register live
   ranges; #pragma opt_rebuildconditionals off preserves the branchy shift
   sequence and its 392-byte object (retail window 400 bytes). */
/* AI script command 0x210d (p4flow AI.json AI_FUNCTION_010D). */
// FUN_001E26C0
/* measured: retains the branch-rebuild setting required for the byte-exact body. */
#pragma opt_rebuildconditionals off
s32 btlAICommandOppSideIdQueryAllBadStatus(void)
{
    u32 shift;
    u32 v;
    u32 m2;
    u32 m;
    u8 *c0;
    u8 *node;
    s32 n;
    s32 k;
    u32 flag;

    if (*(u8 *)(*(u8 **)(scrGetAiState() + 0x30) + 0xa2) != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    m = (1 << (shift & 0xffff)) & 0xffff;
    c0 = (u8 *)(scrGetParamInt(0) & 0xffff);
    v = scrGetParamInt(1);
    n = 0;
    k = 0;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    m2 = m & 0xffff;
    m = (u32)c0 & 0xffff;
    while (node != 0) {
        if ((*(u16 *)(node + 0x1a) & 1) && (*(u16 *)(node + 0x1a) & 8)) {
            c0 = *(u8 **)(node + 0x30);
            if ((m2 & (1 << (*(u8 *)(c0 + 0xa2)))) != 0) {
                if (*(u16 *)(c0 + 0xa4) == m) {
                    if (datCalcIsDead(*(u32 *)(c0 + 0xa64), 0) == 0) {
                        n = (n + 1) & 0xffff;
                        if (datCalcChkBadStatus(*(u32 *)(c0 + 0xa64), v) != 0)
                            k = (k + 1) & 0xffff;
                    }
                }
            }
        }
        node = *(u8 **)(node + 0x450);
    }
    flag = 0;
    if ((n & 0xffff) > 0 && (n & 0xffff) == (k & 0xffff))
        flag = 1;
    scrSetReturnInt(flag != 0);
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
    u32 *r;
    s32 x;
    {
        if (*(u8 *)(*(u8 **)((u8 *)scrGetAiState() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (r != 0)
        x = datCalcHasBuffMask(*(u8 **)(*(u8 **)((u8 *)r + 0x30) + 0xA64), scrGetParamInt(1));
    else
        x = 0;
    scrSetReturnInt(x != 0);
    return 1;
}
#pragma opt_rebuildconditionals on

/* AI script command 0x2111 (p4flow AI.json AI_FUNCTION_0111). */
// FUN_001E2910
s32 btlAICommandSideIdQueryAllHasBuff(void) {
    u32 v;
    u32 m2;
    u32 c02;
    u32 m;
    u32 c0;
    u8 *node;
    s32 n;
    s32 k;
    u8 *np;
    u32 flag;

    m = (1 << (*(u8 *)(*(u32 *)(scrGetAiState() + 0x30) + 0xA2))) & 0xFFFF;
    c0 = scrGetParamInt(0) & 0xFFFF;
    v = scrGetParamInt(1);
    n = 0;
    k = 0;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    m2 = m & 0xFFFF;
    c02 = c0 & 0xFFFF;
    while (node != 0) {
        if ((*(u16 *)(node + 0x1A) & 1) && (*(u16 *)(node + 0x1A) & 8)) {
            np = *(u8 **)(node + 0x30);
            if ((m2 & (1 << (*(u8 *)(np + 0xA2)))) != 0) {
                if (*(u16 *)(np + 0xA4) == c02) {
                    if (datCalcIsDead(*(u32 *)(np + 0xA64), 0) == 0) {
                        n = (n + 1) & 0xFFFF;
                        if (datCalcHasBuffMask(*(u8 **)(np + 0xA64), v) != 0) {
                            k = (k + 1) & 0xFFFF;
                        }
                    }
                }
            }
        }
        node = *(u8 **)(node + 0x450);
    }
    flag = 0;
    if ((n & 0xFFFF) > 0 && (n & 0xFFFF) == (k & 0xFFFF))
        flag = 1;
    scrSetReturnInt(flag != 0);
    return 1;
}

/* measured: byte-exact sibling of FUN_001E26C0; reusing c0 for the node
   payload and m for c02 with conditional rebuilds disabled gives nd 0. */
/* AI script command 0x2110 (p4flow AI.json AI_FUNCTION_0110). */
// FUN_001E2A80
#pragma opt_rebuildconditionals off
s32 btlAICommandOppSideIdQueryAllHasBuff(void)
{
    u32 shift;
    u32 v;
    u32 m2;
    u32 m;
    u8 *c0;
    u8 *node;
    s32 n;
    s32 k;
    u32 flag;

    if (*(u8 *)(*(u8 **)(scrGetAiState() + 0x30) + 0xa2) != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    m = (1 << (shift & 0xffff)) & 0xffff;
    c0 = (u8 *)(scrGetParamInt(0) & 0xffff);
    v = scrGetParamInt(1);
    n = 0;
    k = 0;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    m2 = m & 0xffff;
    m = (u32)c0 & 0xffff;
    while (node != 0) {
        if ((*(u16 *)(node + 0x1a) & 1) && (*(u16 *)(node + 0x1a) & 8)) {
            c0 = *(u8 **)(node + 0x30);
            if ((m2 & (1 << (*(u8 *)(c0 + 0xa2)))) != 0) {
                if (*(u16 *)(c0 + 0xa4) == m) {
                    if (datCalcIsDead(*(u32 *)(c0 + 0xa64), 0) == 0) {
                        n = (n + 1) & 0xffff;
                        if (datCalcHasBuffMask(*(u8 **)(c0 + 0xa64), v) != 0)
                            k = (k + 1) & 0xffff;
                    }
                }
            }
        }
        node = *(u8 **)(node + 0x450);
    }
    flag = 0;
    if ((n & 0xffff) > 0 && (n & 0xffff) == (k & 0xffff))
        flag = 1;
    scrSetReturnInt(flag != 0);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
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
    u32 *r;
    s32 x;
    {
        if (*(u8 *)(*(u8 **)((u8 *)scrGetAiState() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609A30[0])((u8 *)r, 0);
    else
        x = 0;
    scrSetReturnInt(x != 0);
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
    u32 *r;
    s32 x;
    {
        if (*(u8 *)(*(u8 **)((u8 *)scrGetAiState() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609A6C[0])((u8 *)r, 0);
    else
        x = 0;
    scrSetReturnInt(x != 0);
    return 1;
}
#pragma opt_rebuildconditionals on

/* AI script command 0x2069 (p4flow AI.json AI_FUNCTION_0069). */
// FUN_001E33D0
s32 btlAICommandScriptUnitIsIdOnSide(void) {
    u8 *p = scrGetAiState();
    u32 a = scrGetParamInt(0) & 0xFFFF;
    u32 b = scrGetParamInt(1) & 0xFFFF;
    u32 flag = 1;
    switch (a & 0xFFFF) {
    case 0:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 0)
            flag = 0;
        break;
    case 1:
        if (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2) != 1)
            flag = 0;
        break;
    default:
        break;
    }
    if (flag == 1 && *(u16 *)(*(u8 **)(p + 0x30) + 0xA4) != (b & 0xFFFF))
        flag = 0;
    scrSetReturnInt(flag != 0);
    return 1;
}

/* AI script command 0x206a (p4flow AI.json AI_FUNCTION_006A). */
// FUN_001E34B0
s32 btlAICommandScriptQueryFrAllHp(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x38000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x206b (p4flow AI.json AI_FUNCTION_006B). */
// FUN_001E3560
s32 btlAICommandScriptQueryEnAllHp(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x39000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x206c (p4flow AI.json AI_FUNCTION_006C). */
// FUN_001E3610
s32 btlAICommandScriptQueryMyAbleSkil(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x3A000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x206d (p4flow AI.json AI_FUNCTION_006D). */
// FUN_001E36C0
s32 btlAICommandScriptQueryEnWeakPai(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x3B000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x206e (p4flow AI.json AI_FUNCTION_006E). */
// FUN_001E3770
s32 btlAICommandScriptQueryEnWeakStPai(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x3C000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x206f (p4flow AI.json AI_FUNCTION_006F). */
// FUN_001E3820
s32 btlAICommandScriptQueryEnWeakDwPai(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x3D000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2070 (p4flow AI.json AI_FUNCTION_0070). */
// FUN_001E38D0
s32 btlAICommandScriptQueryMyAttrSkil(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x3E000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2071 (p4flow AI.json AI_FUNCTION_0071). */
// FUN_001E3980
s32 btlAICommandScriptQueryMyNomal(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x3F000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2072 (p4flow AI.json AI_FUNCTION_0072). */
// FUN_001E3A30
s32 btlAICommandScriptQueryEnNomal(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x40000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2073 (p4flow AI.json AI_FUNCTION_0073). */
// FUN_001E3AE0
s32 btlAICommandScriptQueryEnNomalSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x41000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2074 (p4flow AI.json AI_FUNCTION_0074). */
// FUN_001E3B90
s32 btlAICommandScriptQueryEnNomalDw(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x42000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
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
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x46000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
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
    int result;
    int dispatchResult;

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
s32 func_001e3f10(void) {
    u32 a = scrGetParamInt(0) & 0xFFFF;
    u32 b = scrGetParamInt(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = btlEffectFindUnitByIdAndStatus(b, 1, 0x80000);
        break;
    case 1:
        r = btlEffectFindUnitByIdAndStatus(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = (*(u16 *)((u8 *)r + 0x18) & 0x1800) != 0;
    else
        x = 0;
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x20d6 (p4flow AI.json AI_FUNCTION_00D6). */
// FUN_001E3FD0
s32 func_001e3fd0(void) {
    u32 a = scrGetParamInt(0) & 0xFFFF;
    u32 b = scrGetParamInt(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = btlEffectFindUnitByIdAndStatus(b, 1, 0x80000);
        break;
    case 1:
        r = btlEffectFindUnitByIdAndStatus(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = (*(u16 *)((u8 *)r + 0x18) & 0x1000) != 0;
    else
        x = 0;
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x20d7 (p4flow AI.json AI_FUNCTION_00D7). */
// FUN_001E4090
s32 func_001e4090(void) {
    u32 a = scrGetParamInt(0) & 0xFFFF;
    u32 b = scrGetParamInt(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = btlEffectFindUnitByIdAndStatus(b, 1, 0x80000);
        break;
    case 1:
        r = btlEffectFindUnitByIdAndStatus(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = (*(u16 *)((u8 *)r + 0x18) & 0x800) != 0;
    else
        x = 0;
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x20d8 (p4flow AI.json AI_FUNCTION_00D8). */
// FUN_001E4150
s32 func_001e4150(void) {
    u32 a = scrGetParamInt(0) & 0xFFFF;
    u32 b = scrGetParamInt(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = btlEffectFindUnitByIdAndStatus(b, 1, 0x80000);
        break;
    case 1:
        r = btlEffectFindUnitByIdAndStatus(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = (*(u16 *)((u8 *)r + 0x18) & 0x2000) != 0;
    else
        x = 0;
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x20c9 (p4flow AI.json AI_FUNCTION_00C9). */
// FUN_001E4210
s32 btlAICommandSideSwitchQueryAnalyze(void) {
    u32 a = scrGetParamInt(0) & 0xFFFF;
    u32 b = scrGetParamInt(1) & 0xFFFF;
    u32 *r = 0;
    s32 x;
    switch (a & 0xFFFF) {
    case 0:
        r = btlEffectFindUnitByIdAndStatus(b, 1, 0x80000);
        break;
    case 1:
        r = btlEffectFindUnitByIdAndStatus(b, 2, 0x80000);
        break;
    default:
        break;
    }
    if (r != 0)
        x = ((s32 (*)(u8 *, s32))D_00609B74[0])((u8 *)r, 0);
    else
        x = 0;
    scrSetReturnInt(x != 0);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    u8 *p = scrGetAiState();
    scrSetReturnInt(datCalcHasBuffMask(*(u8 **)(*(u8 **)(p + 0x30) + 0xA64), scrGetParamInt(0)) != 0);
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
    int result;
    int dispatchResult;

    unit = scrGetAiState();
    id = scrGetParamInt(0) & 0xFFFF;
    context = (u8 *)btlEffectFindUnitByIdAndStatus(id, 1 << *(u8 *)(*(int *)(unit + 0x30) + 0xa2) & 0xffff, 0x80000);
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
    u8 *p = scrGetAiState();
    u32 flag = 0;
    u16 i;
    for (i = 1; i < 0xC; i++) {
        u32 r = btlActionGetQueueEntry(i);
        if (r == 0)
            break;
        if (r == *(u32 *)(D_0072449C + 0x170))
            break;
        if (r == (u32)p) {
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
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x48000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x20ec (p4flow AI.json AI_FUNCTION_00EC). */
// FUN_001E46B0
s32 btlAICommandScriptQueryFrTaisei(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x49000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x20ed (p4flow AI.json AI_FUNCTION_00ED). */
// FUN_001E4760
s32 btlAICommandScriptQueryEnTaisei(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x4A000000;
    u8 *p = scrGetAiState();
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = v & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x202c (p4flow AI.json AI_FUNCTION_002C). */
// FUN_001E4810
s32 btlAICommandScriptRunAi(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x202d (p4flow AI.json AI_FUNCTION_002D). */
// FUN_001E4880
s32 btlAICommandAiUnlessHpMin(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CE8[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x202e (p4flow AI.json AI_FUNCTION_002E). */
// FUN_001E48F0
s32 btlAICommandAiUnlessLvMin(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CF0[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x202f (p4flow AI.json AI_FUNCTION_002F). */
// FUN_001E4960
s32 btlAICommandAiUnlessMpMax(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609CF8[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2030 (p4flow AI.json AI_FUNCTION_0030). */
// FUN_001E49D0
s32 btlAICommandCondQueryBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x4000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2031 (p4flow AI.json AI_FUNCTION_0031). */
// FUN_001E4A80
s32 btlAICommandCondQueryNotBad(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x5000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x210c (p4flow AI.json AI_FUNCTION_010C). */
// FUN_001E4B30
s32 btlAICommandScriptPickMyIdFromArgs(void) {
    u32 a = scrGetParamInt(0);
    u32 b = scrGetParamInt(1);
    btlAICommandSelectCandidates(scrGetAiState(), a, b, 0, 0, btlCond_MYID);
    return 1;
}

/* AI script command 0x2032 (p4flow AI.json AI_FUNCTION_0032). */
// FUN_001E4BB0
s32 btlAICommandCondQueryId(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x6000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2033 (p4flow AI.json AI_FUNCTION_0033). */
// FUN_001E4C60
s32 btlAICommandAiUnlessMine(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D18[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2034 (p4flow AI.json AI_FUNCTION_0034). */
// FUN_001E4CD0
s32 btlAICommandAiUnlessMyAi(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D20[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2035 (p4flow AI.json AI_FUNCTION_0035). */
// FUN_001E4D40
s32 btlAICommandCondQueryHansya(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x9000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2036 (p4flow AI.json AI_FUNCTION_0036). */
// FUN_001E4DF0
s32 btlAICommandCondQueryKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xA000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2037 (p4flow AI.json AI_FUNCTION_0037). */
// FUN_001E4EA0
s32 btlAICommandCondQueryMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xB000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2038 (p4flow AI.json AI_FUNCTION_0038). */
// FUN_001E4F50
s32 btlAICommandCondQueryWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xC000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2039 (p4flow AI.json AI_FUNCTION_0039). */
// FUN_001E5000
s32 btlAICommandCondQueryNotHansya(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xD000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x203a (p4flow AI.json AI_FUNCTION_003A). */
// FUN_001E50B0
s32 btlAICommandCondQueryNotKyusyu(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xE000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x203b (p4flow AI.json AI_FUNCTION_003B). */
// FUN_001E5160
s32 btlAICommandCondQueryNotMukou(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0xF000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x203c (p4flow AI.json AI_FUNCTION_003C). */
// FUN_001E5210
s32 btlAICommandCondQueryNotWeak(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x10000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2043 (p4flow AI.json AI_FUNCTION_0043). */
// FUN_001E52C0
s32 btlAICommandAiUnlessAppoint(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D70[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2044 (p4flow AI.json AI_FUNCTION_0044). */
// FUN_001E5330
s32 btlAICommandAiUnlessDown(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D78[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2045 (p4flow AI.json AI_FUNCTION_0045). */
// FUN_001E53A0
s32 btlAICommandAiUnlessStand(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609D80[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2049 (p4flow AI.json AI_FUNCTION_0049). */
// FUN_001E5410
s32 btlAICommandCondQueryHansyaSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x15000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x204a (p4flow AI.json AI_FUNCTION_004A). */
// FUN_001E54C0
s32 btlAICommandCondQueryKyusyuSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x16000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x204b (p4flow AI.json AI_FUNCTION_004B). */
// FUN_001E5570
s32 btlAICommandCondQueryMukouSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x17000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x204c (p4flow AI.json AI_FUNCTION_004C). */
// FUN_001E5620
s32 btlAICommandCondQueryWeakSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x18000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x204d (p4flow AI.json AI_FUNCTION_004D). */
// FUN_001E56D0
s32 btlAICommandCondQueryNotHansyaSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x19000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x204e (p4flow AI.json AI_FUNCTION_004E). */
// FUN_001E5780
s32 btlAICommandCondQueryNotKyusyuSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1A000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x204f (p4flow AI.json AI_FUNCTION_004F). */
// FUN_001E5830
s32 btlAICommandCondQueryNotMukouSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1B000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2050 (p4flow AI.json AI_FUNCTION_0050). */
// FUN_001E58E0
s32 btlAICommandCondQueryNotWeakSt(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x1C000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2067 (p4flow AI.json AI_FUNCTION_0067). */
// FUN_001E5990
s32 btlAICommandScriptAppointCurrent(void) {
    u8 *p = scrGetAiState();
    u32 q = *(u32 *)(D_0072449C + 0x170);
    if (q != 0) {
        func_001d8bf0(p + 0x98, (u8 *)q + 0x98);
        if (!((s32 (*)(u8 *, s32))D_00609D70[0])(p, 0))
            ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    }
    return 1;
}

/* AI script command 0x2098 (p4flow AI.json AI_FUNCTION_0098). */
// FUN_001E5A20
s32 btlAICommandCondQueryNotId(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x21000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x209a (p4flow AI.json AI_FUNCTION_009A). */
// FUN_001E5AD0
s32 btlAICommandAiUnlessRnd(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609DF0[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x20c6 (p4flow AI.json AI_FUNCTION_00C6). */
// FUN_001E5B40
s32 btlAICommandCondQueryHojo(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x23000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x20c7 (p4flow AI.json AI_FUNCTION_00C7). */
// FUN_001E5BF0
s32 btlAICommandCondQueryNotHojo(void) {
    u32 v = (scrGetParamInt(0) & 0xFFFFFF) | 0x24000000;
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, u32))D_00609CE0[(((v & 0xFF000000) >> 24) * 2)])(p, v & 0xFFFFFF))
        ((s32 (*)(u8 *, u32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x210f (p4flow AI.json AI_FUNCTION_010F). */
// FUN_001E5CA0
s32 btlAICommandScriptPickMyIdFiltered(void) {
    u32 a = scrGetParamInt(0);
    u32 b = scrGetParamInt(1);
    btlAICommandSelectCandidates(scrGetAiState(), a, b, 0x40, 0, btlCond_MYID);
    return 1;
}

/* AI script command 0x2112 (p4flow AI.json AI_FUNCTION_0112). */
// FUN_001E5D20
s32 btlAICommandAiUnlessHpMax(void) {
    u8 *p = scrGetAiState();
    if (!((s32 (*)(u8 *, s32))D_00609E18[0])(p, 0))
        ((s32 (*)(u8 *, s32))D_00609CE0[0])(p, 0);
    return 1;
}

/* AI script command 0x2091 (p4flow AI.json AI_FUNCTION_0091). */
// FUN_001E5D90
s32 btlAICommandScriptSetId2ClearBuffs(void) {
    u8 *p = scrGetAiState();
    u32 a = scrGetParamInt(0) & 0xFFFF;
    u32 q;
    datCalcClearBuffLevel(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), 8);
    datCalcClearBuffLevel(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), 9);
    datCalcClearBuffLevel(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), 0xA);
    datCalcClearBuffLevel(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), 0xB);
    q = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
    *(u16 *)(q + 4) = a;
    return 1;
}

/* AI script command 0x2095 (p4flow AI.json AI_FUNCTION_0095). */
// FUN_001E5E40
s32 btlAICommandScriptSetDownFlag(void) {
    u8 *p = scrGetAiState();
    if ((scrGetParamInt(0) & 0xFFFF) == 0) {
        u32 f = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
        *(u16 *)f |= 8;
    } else {
        u32 f = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
        *(u16 *)f &= 0xFFF7;
    }
    return 1;
}

/* AI script command 0x2096 (p4flow AI.json AI_FUNCTION_0096). */
// FUN_001E5EC0
s32 btlAICommandScriptSetSlipFlag(void) {
    u8 *p = scrGetAiState();
    if ((scrGetParamInt(0) & 0xFFFF) == 0) {
        u32 f = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
        *(u16 *)f |= 0x10;
    } else {
        u32 f = *(u32 *)(*(u8 **)(p + 0x30) + 0xA64);
        *(u16 *)f &= 0xFFEF;
    }
    return 1;
}

/* AI script command 0x20db (p4flow AI.json AI_FUNCTION_00DB). */
// FUN_001E5F40
s32 btlAICommandScriptSetCommandOverride(void) {
    u8 *p = scrGetAiState();
    *(u16 *)(p + 0x80) = scrGetParamInt(0);
    *(u8 *)(p + 0x82) = scrGetParamInt(1);
    return 1;
}

/* AI script command 0x2099 (p4flow AI.json AI_FUNCTION_0099). */
// FUN_001E5F90
s32 btlAICommandScriptGetSelfId2(void) {
    u32 a = *(u32 *)(*(u8 **)((u8 *)scrGetAiState() + 0x30) + 0xA64);
    scrSetReturnInt(*(u16 *)(a + 4));
    return 1;
}

/* AI script command 0x20ab (p4flow AI.json AI_FUNCTION_00AB). */
// FUN_001E5FD0
s32 func_001e5fd0(void) {
    u8 *p = scrGetAiState();
    u32 *r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << (*(u8 *)(*(u8 **)(p + 0x30) + 0xA2))) & 0xFFFF, 0x80000);
    scrSetReturnInt(r != 0 ? *(u32 *)((u8 *)r + 0x20) : 0);
    return 1;
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001E6050 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* AI script command 0x20ac (p4flow AI.json AI_FUNCTION_00AC). */
// FUN_001E6050
s32 func_001e6050(void) {
    u32 shift;
    u32 *r;
    {
        if (*(u8 *)(*(u8 **)((u8 *)scrGetAiState() + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    r = btlEffectFindUnitByIdAndStatus(scrGetParamInt(0) & 0xFFFF, (1 << shift) & 0xffff, 0x80000);
    scrSetReturnInt(r != 0 ? *(u32 *)((u8 *)r + 0x20) : 0);
    return 1;
}
#pragma opt_rebuildconditionals on

/* AI script command 0x20b0 (p4flow AI.json AI_FUNCTION_00B0). */
// FUN_001E60F0
s32 btlAICommandScriptCountOwnHojo(void) {
    u8 *p = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(p, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20b1 (p4flow AI.json AI_FUNCTION_00B1). */
// FUN_001E6160
s32 btlAICommandScriptCountOwnNotHojo(void) {
    u8 *p = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(p, scrGetParamInt(0), 0x80000, 1, 1, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20b2 (p4flow AI.json AI_FUNCTION_00B2). */
// FUN_001E61D0
s32 btlAICommandScriptCountOwnBad(void) {
    u8 *p = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(p, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYBAD, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20ea (p4flow AI.json AI_FUNCTION_00EA). */
// FUN_001E6240
s32 btlAICommandScriptCountOppBad(void) {
    u8 *p = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(p, scrGetParamInt(0), 0x80000, 2, 0, &btlCond_MYBAD, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20b3 (p4flow AI.json AI_FUNCTION_00B3). */
// FUN_001E62B0
s32 btlAICommandScriptCountOppHojo(void) {
    u8 *p = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(p, scrGetParamInt(0), 0x80000, 2, 0, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20b4 (p4flow AI.json AI_FUNCTION_00B4). */
// FUN_001E6320
s32 btlAICommandScriptCountOppNotHojo(void) {
    u8 *p = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(p, scrGetParamInt(0), 0x80000, 2, 1, &btlCond_MYHOJO, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20cd (p4flow AI.json AI_FUNCTION_00CD). */
// FUN_001E6390
s32 btlAICommandScriptCountOwnHp(void) {
    u8 *p = scrGetAiState();
    scrSetReturnInt(btlSideSelectUnits(p, scrGetParamInt(0), 0x80000, 1, 0, &btlCond_MYHP, 0) & 0xFFFF);
    return 1;
}

/* AI script command 0x20ce (p4flow AI.json AI_FUNCTION_00CE). */
// FUN_001E6400
s32 btlAICommandScriptAverageOwnLevel(void) {
    scrSetReturnInt(btlSideAverageLevel((1 << (*(u8 *)(*(u8 **)((u8 *)scrGetAiState() + 0x30) + 0xA2))) & 0xFFFF, 0x80000) & 0xFFFF);
    return -1;
}

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001E6450 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

/* AI script command 0x20cf (p4flow AI.json AI_FUNCTION_00CF). */
// FUN_001E6450
s32 btlAICommandScriptAverageOppLevel(void) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)((u8 *)scrGetAiState() + 0x30) + 0xA2) != 0)
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
    u8 *p = scrGetAiState();
    short r = (short)scrGetParamInt(0);
    scrSetReturnInt((s16)datCalcSkillElement(*(u8 **)(*(u8 **)(p + 0x30) + 0xA64), (u16)r));
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
    scrSetReturnInt(datCalcGetHp(*(u32 *)(*(u8 **)((u8 *)scrGetAiState() + 0x30) + 0xA64)) & 0xFFFF);
    return -1;
}

/* AI script command 0x2075 (p4flow AI.json AI_FUNCTION_0075). */
// FUN_001E65F0
s32 btlAICommandIdScriptQueryMyHp(void) {
    u32 a = scrGetParamInt(0);
    u32 b = scrGetParamInt(1);
    u8 *p = btlActionFindById(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x1000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x1000000) & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x2076 (p4flow AI.json AI_FUNCTION_0076). */
// FUN_001E66C0
s32 btlAICommandIdScriptQueryHasBuff(void) {
    u32 a = scrGetParamInt(0);
    u32 b = scrGetParamInt(1);
    u8 t = datCalcHasBuffMask(*(u8 **)(*(u8 **)((u8 *)btlActionFindById(a & 0xFFFFFFF) + 0x30) + 0xA64), b) != 0;
    scrSetReturnInt(t != 0);
    return 1;
}

/* AI script command 0x2077 (p4flow AI.json AI_FUNCTION_0077). */
// FUN_001E6740
s32 btlAICommandScriptWouldBeKilled(void) {
    u8 *p = scrGetAiState();
    u8 *q = btlActionFindById(scrGetParamInt(0) & 0xFFFFFFF);
    s32 x = datCalcSkillAmount(0, (u8 *)*(u32 *)(*(u8 **)(p + 0x30) + 0xA64), (u8 *)*(u32 *)(*(u8 **)(q + 0x30) + 0xA64), 1, 1, 1, 0, 1);
    s32 off;
    s32 sum;
    datCalcClearField18(*(u32 *)(*(u8 **)(p + 0x30) + 0xA64));
    datCalcClearField18(*(u32 *)(*(u8 **)(q + 0x30) + 0xA64));
    off = (s32)(datCalcGetHp(*(u32 *)(*(u8 **)(q + 0x30) + 0xA64)) & 0xFFFF);
    sum = off + x;
    scrSetReturnInt(sum <= 0);
    return 1;
}

/* AI script command 0x2078 (p4flow AI.json AI_FUNCTION_0078). */
// FUN_001E6820
s32 btlAICommandScriptHasCommandOfType(void) {
    u32 temp_16;
    u32 temp_17;
    u8 *temp_18;

    temp_18 = (u8 *)(scrGetAiState());
    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    scrSetReturnInt(~btlAICommandCollectCommandsOfType(temp_18, btlActionFindById(temp_17 & 0xFFFFFFF), (s16) temp_16, 0) != 0);
    return 1;
}



/* AI script command 0x2079 (p4flow AI.json AI_FUNCTION_0079). */
// FUN_001E68C0
s32 btlAICommandScriptLookupOnlyFalse(void) {
    u32 temp_16;

    scrGetAiState();
    temp_16 = scrGetParamInt(0);
    scrGetParamInt(1);
    btlActionFindById(temp_16 & 0xFFFFFFF);
    scrSetReturnInt(0U);
    return 1;
}



/* AI script command 0x209c (p4flow AI.json AI_FUNCTION_009C). */
// FUN_001E6930
s32 btlAICommandIdScriptQueryMyNomal(void) {
    u32 a = scrGetParamInt(0);
    u32 b = scrGetParamInt(1);
    u8 *p = btlActionFindById(a & 0xFFFFFFF);
    u32 v = (b & 0xFFFFFF) | 0x3F000000;
    u32 cmd = (v & 0xFF000000) >> 24;
    u32 arg = (b | 0x3F000000) & 0xFFFFFF;
    s32 x;
    if (cmd == 0)
        x = 0;
    else
        x = ((s32 (*)(u8 *, u32))D_00609850[cmd * 3])(p, arg);
    scrSetReturnInt(x != 0);
    return 1;
}

/* AI script command 0x20e3 (p4flow AI.json AI_FUNCTION_00E3). */
// FUN_001E6A00
s32 btlAICommandIdScriptQueryOnSideZero(void) {
    scrSetReturnInt(*(u8 *)(*(u8 **)(btlActionFindById(scrGetParamInt(0) & 0xFFFFFFF) + 0x30) + 0xA2) == 0);
    return 1;
}
/* AI script command 0x20e4 (p4flow AI.json AI_FUNCTION_00E4). */
// FUN_001E6A50
s32 btlAICommandIdScriptQueryCanUseCommand(void) {
    s32 r0 = scrGetParamInt(0);
    s32 r1 = scrGetParamInt(1);
    u8 *q = btlActionFindById(r0 & 0xFFFFFFF);
    s32 idx = r1 & 0xFFFF;
    s32 x;
    if (idx >= 0x240)
        kAssertFail(D_006095E0, 0x45F);
    q = *(u8 **)(q + 0x30);
    if (idx < 0x1B8) {
        if (datCalcChkBadStatus((s32)*(u8 **)(q + 0xA64), 0x80008) != 0)
            x = 0;
        else if (datCalcHasSkill(*(u8 **)(q + 0xA64), idx) == 0)
            x = 0;
        else if (datCalcThresholdTrigger(*(u8 **)(q + 0xA64), idx) != 0)
            x = 0;
        else
            goto one;
    } else if (datCalcHasSkill(*(u8 **)(q + 0xA64), idx) != 0)
        goto one;
    else
        x = 0;
    goto done;
one:
    x = 1;
done:
    scrSetReturnInt(x != 0);
    return 1;
}
