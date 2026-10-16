/* Source units: src/promoted/code1_001d.c (btlCond_MYHP..btlCond_ENALLHP) and
 * src/Battle/btlEffect.c (btlCond_FRLV_O..btlCond_MYID), merged in retail address order. */
#include "btl_skill_target_internal.h"
#include "type.h"
#include "include_asm.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"

typedef u8 bool;
typedef int (*code)();

static inline s32 p4_001da5f0_xor(s32 left, s32 right)
{
    return left ^ right;
}

extern s32 datCalcIsDead(u8 *arg0, s32 arg1);
extern s32 datCalcGetLevel(u8 *arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u16 datCalcGetHp(u8 *arg0);
extern u16 datCalcMaxHp(u8 *arg0);
extern u16 datCalcMaxSp(u8 *arg0);
extern s32 datCalcStatusResistance(u8 *arg0, s32 arg1);
extern s32 datCalcSkillElement(u8 *arg0, u16 arg1);
extern s32 func_0023df20(s32 arg0);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
// FUN_001D9740
s32 btlCond_MYHP(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 8);
    uVar2 = datCalcMaxHp(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return (u32)uVar1 * 100 <= (uVar2 & 0xFFFF) * arg1;
}

// FUN_001D97B0
s32 btlCondCheckMaxHp(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 8);
    uVar2 = datCalcMaxHp(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return !((u32)uVar1 * 100 < (uVar2 & 0xFFFF) * arg1);
}

// FUN_001D9820
s32 btlCond_MYMP(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 0xA);
    uVar2 = datCalcMaxSp(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return (u32)uVar1 * 100 <= (uVar2 & 0xFFFF) * arg1;
}

// FUN_001D9890
void btlCond_FRHP(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYHP);
}

// FUN_001D98E0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void btlCond_ENHP(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYHP);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001D9940
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void btlCond_ENHP_O(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCondCheckMaxHp);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001D99A0
s32 btlCond_MYLV_O(u8 *arg0, u32 arg1)
{
    return (u32)(datCalcGetLevel(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64)) & 0xFF) >= arg1;
}
// FUN_001D99E0
bool btlCond_FRLV_O(int param_1, u32 param_2)
{
  u32 uVar1 = 0;

  uVar1 = btlSideAverageLevel(1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff, 0x80000);
  return param_2 <= (uVar1 & 0xffff);
}


/* measured: opt_rebuildconditionals off is required for FUN_001D9A30. */
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001D9A30 (MATCH nd0 -> MISMATCH nd49) - measured W161. */

// FUN_001D9A30
bool btlCond_ENLV_O(int param_1, u32 param_2)
{
  u32 uVar1 = 0;
  u16 genus;
  u32 shift;
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
    goto nonzero;
  shift = 1;
  goto done;
nonzero:
  shift = 0;
done:
  genus = shift;
  uVar1 = btlSideAverageLevel(1 << genus & 0xffff, 0x80000);
  return param_2 <= (uVar1 & 0xffff);
}
/* measured: closes opt_rebuildconditionals for FUN_001D9A30. */
#pragma opt_rebuildconditionals on



// FUN_001D9AA0
bool btlCond_FRCNT(int param_1, u32 param_2)
{
  u32 uVar1 = 0;

  uVar1 = btlSideCountNotBad(1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff, 0x80000);
  return (uVar1 & 0xffff) <= param_2;
}


/* measured: opt_rebuildconditionals off is required for FUN_001D9AF0. */
#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001D9AF0 (MATCH nd0 -> MISMATCH nd49) - measured W161. */

// FUN_001D9AF0
bool btlCond_ENCNT(int param_1, u32 param_2)
{
  u32 uVar1 = 0;
  u16 genus;
  {
    u32 shift;
    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
      goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    genus = shift;
  }
  uVar1 = btlSideCountNotBad(1 << genus & 0xffff, 0x80000);
  return (uVar1 & 0xffff) <= param_2;
}
/* measured: closes opt_rebuildconditionals for FUN_001D9AF0. */
#pragma opt_rebuildconditionals on
// FUN_001D9B60
s32 btlCond_MYBAD(u8 *task, s32 mask) {
    return datCalcChkBadStatus(*(s32 *)(*(u8 **)(task + 0x30) + 0xA64), (u32)mask);
}
// FUN_001D9B90
void btlCond_FRBAD(u8 *arg0, u32 arg1)
{
    u32 mask;

    mask = (1 << *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) & 0xFFFF;
    if ((arg1 & 0x80000) != 0) {
        btlEffectFindUnitMatchingCallback((int)arg0, arg1, mask, 0, 0, btlCond_MYBAD);
    } else {
        btlEffectFindUnitMatchingCallback((int)arg0, arg1, mask, 0x80000, 0, btlCond_MYBAD);
    }
}

/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
// FUN_001D9C00
#pragma opt_rebuildconditionals off
void btlCond_ENBAD(u8 *arg0, u32 arg1)
{
    u32 shift;
    u32 temp_3;

    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero_1;
        shift = 1;
        goto done_1;
    nonzero_1:
        shift = 0;
    done_1:
        ;
    }
    temp_3 = shift & 0xFFFF;
    if ((arg1 & 0x80000) != 0) {
        btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (temp_3 & 0xFFFF)) & 0xFFFF, 0, 0, btlCond_MYBAD);
    } else {
        btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (temp_3 & 0xFFFF)) & 0xFFFF, 0x80000, 0, btlCond_MYBAD);
    }
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001D9CA0
s32 btlCond_ENBAD_ALL(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 mode;
    s32 mask;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    mode = 1;
    goto done;
nonzero:
    mode = 0;
done:
    ;
    mask = (1 << (mode & 0xFFFF)) & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if ((mask & (1 << *(u8 *)(temp + 0xA2))) != 0 &&
                datCalcIsDead(*(u8 **)(temp + 0xA64), 0) == 0 &&
                datCalcChkBadStatus(*(s32 *)(temp + 0xA64), arg1) == 0) {
                break;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    if (unit != NULL)
        goto found;
    return 1;
found:
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001d9ca0. */
#pragma opt_rebuildconditionals on
// FUN_001D9DB0
s32 btlCond_FRID(u8 *arg0, s32 arg1)
{
    u16 flags;
    u8 *temp;
    u8 *unit;

    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        if (arg0 != unit) {
            flags = *(u16 *)(unit + 0x1A);
            if ((flags & 1) != 0 && (flags & 8) != 0) {
                temp = *(u8 **)(unit + 0x30);
                if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == *(u8 *)(temp + 0xA2) &&
                    datCalcChkBadStatus(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                    *(u16 *)(temp + 0xA4) == arg1) {
                    return 1;
                }
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001D9E80
s32 btlCond_ENID(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 value;
    s32 mode;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    value = 1;
    goto done;
nonzero:
    value = 0;
done:
    ;
    mode = value & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if (*(u8 *)(temp + 0xA2) == mode &&
                datCalcChkBadStatus(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                *(u16 *)(temp + 0xA4) == arg1) {
                return 1;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001d9e80. */
#pragma opt_rebuildconditionals on
// FUN_001D9F60
s32 btlCond_FRHOJO(u8 *arg0, s32 arg1)
{
    u16 flags;
    u8 *temp;
    u8 *unit;

    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        if (arg0 != unit) {
            flags = *(u16 *)(unit + 0x1A);
            if ((flags & 1) != 0 && (flags & 8) != 0) {
                temp = *(u8 **)(unit + 0x30);
                if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == *(u8 *)(temp + 0xA2) &&
                    datCalcChkBadStatus(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                    datCalcHasBuffMask(*(DatUnit **)(temp + 0xA64), arg1) != 0) {
                    return 1;
                }
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: opt_rebuildconditionals off forces the retail mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001DA040
s32 btlCond_ENHOJO(u8 *arg0, s32 arg1)
{
    u8 *unit;
    s32 value;
    s32 mode;
    u16 flags;
    u8 *temp;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
        goto nonzero;
    value = 1;
    goto done;
nonzero:
    value = 0;
done:
    ;
    mode = value & 0xFFFF;
    unit = *(u8 **)(iGpffffb3ac + 0x174);
    while (unit != NULL) {
        flags = *(u16 *)(unit + 0x1A);
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            temp = *(u8 **)(unit + 0x30);
            if (*(u8 *)(temp + 0xA2) == mode &&
                datCalcChkBadStatus(*(s32 *)(temp + 0xA64), 0x80000) == 0 &&
                datCalcHasBuffMask(*(DatUnit **)(temp + 0xA64), arg1) != 0) {
                return 1;
            }
        }
        unit = *(u8 **)(unit + 0x450);
    }
    return 0;
}
/* measured: restore opt_rebuildconditionals after func_001da040. */
#pragma opt_rebuildconditionals on
// FUN_001DA130
s32 btlCond_ESCAPE(u8 *arg0, s32 arg1) {
    s32 r;

    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180010) != 0) {
        r = 0;
    } else {
        r = (*(s32 *)(iGpffffb414 + *(u16 *)(*(u8 **)(D_0076449C + 0xC68) + 8) * 0x18) & 1) != 0;
    }
    return r;
}

// FUN_001DA1A0
s32 btlCond_SUMMON(void)
{
    return 0;
}

// FUN_001DA1B0
s32 btlCond_SENSEI(u8 *arg0)
{
    u8 genus;

    if (*(s32 *)(arg0 + 0x20) > 0)
        return 0;
    genus = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    switch (genus) {
    case 0:
        return *(u16 *)(iGpffffb3ac + 0x1A) == 1;
    case 1:
        return *(u16 *)(iGpffffb3ac + 0x1A) == 2;
    default:
        return 0;
    }
}

// FUN_001DA230
s32 btlCond_MYHANSYA(u8 *arg0, s16 arg1) {
    return (s32)((datCalcStatusResistance(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), (s32)arg1) & 0x02000000) != 0);
}



// FUN_001DA270
s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1) {
    return (s32)((datCalcStatusResistance(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), (s32)arg1) & 0x04000000) != 0);
}



// FUN_001DA2B0
s32 btlCond_MYMUKOU(u8 *arg0, s16 arg1) {
    return (s32)((datCalcStatusResistance(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), (s32)arg1) & 0x01000000) != 0);
}



// FUN_001DA2F0
s32 btlCond_MYWEAK(u8 *arg0, s16 arg1) {
    return (s32)((datCalcStatusResistance(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), (s32)arg1) & 0x08000000) != 0);
}



// FUN_001DA330
void btlCond_FRHANSYA(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYHANSYA);
}

// FUN_001DA380
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void btlCond_ENHANSYA(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYHANSYA);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on

// FUN_001DA3E0
void btlCond_FRKYUSYU(u8 *arg0, s32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << *(u8 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA2)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYKYUSYU);
}

// FUN_001DA430
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENKYUSYU(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYKYUSYU);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA490
void btlCond_FRMUKOU(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYMUKOU);
}
// FUN_001DA4E0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENMUKOU(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYMUKOU);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA540
void btlCond_FRWEAK(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYWEAK);
}
// FUN_001DA590
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENWEAK(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYWEAK);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA5F0
s32 btlCond_MYUSEATTR(u8 *arg0, s32 arg1)
{
    return p4_001da5f0_xor((s16)datCalcSkillElement(
        *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64),
        *(u16 *)(arg0 + 0x7E)), arg1) < 1U;
}
// FUN_001DA640
void btlCond_FRUSEATTR(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)btlCond_MYUSEATTR);
}
// FUN_001DA690
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENUSEATTR(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)btlCond_MYUSEATTR);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DA6F0
bool btlCond_MYUSESKIL(int param_1, int param_2)
{
    bool result;

    switch (*(u16*)(param_1 + 0x7c))
    {
    default:
        result = 0;
        break;
    case 1:
    case 2:
        result = *(u16*)(param_1 + 0x7e) == param_2;
        break;
    }
    return result;
}



// FUN_001DA730
void btlCond_FRUSESKIL(int param_1, u32 param_2)
{
    btlEffectFindUnitMatchingCallback(param_1, param_2, 1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff, 0x80000, 0, (code *)&btlCond_MYUSESKIL);
}
/* measured: opt_rebuildconditionals off is required for the retail branch shape. */
#pragma opt_rebuildconditionals off
// FUN_001DA780
void btlCond_ENUSESKIL(int param_1, u32 param_2)
{
    u32 shift;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    btlEffectFindUnitMatchingCallback(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code *)&btlCond_MYUSESKIL);
}
/* measured: closes the function-local conditional rebuild setting. */
#pragma opt_rebuildconditionals on
// FUN_001DA7E0
u32 btlCond_MYGROUP(int param_1)
{
  u16 result;

  result = btlSkillClassifyTargets((u8 *)param_1, 0, *(u16 *)(param_1 + 0x7e), 0);
  switch (result) {
  case 1:
  case 2:
    return 1;
  default:
    return 0;
  }
}



// FUN_001DA840
void btlCond_FRGROUP(int param_1, u32 param_2)
{
    btlEffectFindUnitMatchingCallback(param_1, param_2, 1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff, 0x80000, 0, (code *)&btlCond_MYGROUP);
}
/* measured: opt_rebuildconditionals off is required for the retail branch shape. */
#pragma opt_rebuildconditionals off
// FUN_001DA890
void btlCond_ENGROUP(int param_1, u32 param_2)
{
    u32 shift;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
        goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    btlEffectFindUnitMatchingCallback(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0, (code *)&btlCond_MYGROUP);
}
/* measured: closes the function-local conditional rebuild setting. */
#pragma opt_rebuildconditionals on
// FUN_001DA8F0
bool btlCond_TURN(int param_1, u32 param_2)
{
    return param_2 >= *(u32*)(param_1 + 0x20);
}



// FUN_001DA910
bool btlCond_TURN_O(int param_1, u32 param_2)
{
    return param_2 <= *(u32*)(param_1 + 0x20);
}
/* Twin port from P3 Battle/btlEffect.c func_002c2510; P4 constants and callees recovered from retail asm. */
// FUN_001DA930
s32 btlCond_MYHREC(u8 *arg0)
{
    s32 data;
    s32 count;
    u16 *skills;
    u16 index;

    data = *(s32 *)(arg0 + 0x30);
    count = (u16)datCalcGetTableLength(*(DatUnit **)(data + 0xA64));
    skills = (u16 *)datCalcSkillList(*(DatUnit **)(data + 0xA64));
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
// FUN_001DAA00
void btlCond_FRHANSYA_ST(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)btlCond_MYHANSYA);
}
// FUN_001DAA50
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENHANSYA_ST(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYHANSYA);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAAB0
void btlCond_FRKYUSYU_ST(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)btlCond_MYKYUSYU);
}
// FUN_001DAB00
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENKYUSYU_ST(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYKYUSYU);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAB60
void btlCond_FRMUKOU_ST(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)btlCond_MYMUKOU);
}
// FUN_001DABB0
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENMUKOU_ST(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYMUKOU);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DAC10
void btlCond_FRWEAK_ST(u8 *arg0, u32 arg1) {
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x180000, 0, (code)btlCond_MYWEAK);
}
// FUN_001DAC60
/* Opening state measured: opt_rebuildconditionals off is required for this wrapper. */
#pragma opt_rebuildconditionals off
/* Same branch shape as func_001da380; pragma measured on this wrapper. */
void btlCond_ENWEAK_ST(u8 *arg0, u32 arg1) {
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
    btlEffectFindUnitMatchingCallback((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x180000, 0, (code)btlCond_MYWEAK);
}
/* Closing state measured: restore opt_rebuildconditionals on after this wrapper. */
#pragma opt_rebuildconditionals on
// FUN_001DACC0
bool btlCond_MYID(int param_1, int param_2)
{
    return *(u16*)(*(s32*)(param_1 + 0x30) + 0xa4) == param_2;
}
// FUN_001DACE0
s32 btlCond_FRALLHP(u8 *arg0, s32 arg1)
{
    extern u16 datCalcGetHp(u8 *arg0);
    u8 *var_21;
    u8 *temp_17;
    u16 temp_3;
    s32 var_20;
    s32 var_19;
    s32 temp_18;
    s32 limit;

    limit = arg1;
    temp_18 = (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF;
    var_20 = 0;
    var_19 = 0;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) != 0 && (temp_3 & 8) != 0) {
        temp_17 = *(u8 **)(var_21 + 0x30);
        if ((temp_18 & (1 << *(u8 *)(temp_17 + 0xA2))) != 0 &&
            datCalcIsDead(*(u8 **)(temp_17 + 0xA64), 0) == 0) {
            var_20 += datCalcGetHp(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
            var_19 += datCalcMaxHp(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
        }
    }
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    return (u32)(var_20 * 0x64) <= (u32)(var_19 * limit);
}
/* Opening state measured: opt_rebuildconditionals off is required for this mode branch. */
#pragma opt_rebuildconditionals off
// FUN_001DAE00
s32 btlCond_ENALLHP(u8 *arg0, s32 arg1)
{
    extern u16 datCalcGetHp(u8 *arg0);
    u8 *var_21;
    u8 *temp_17;
    u16 temp_3;
    s32 var_20;
    s32 var_19;
    s32 temp_18;
    s32 limit;

    limit = arg1;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        temp_18 = 1;
        goto done;
    nonzero:
        temp_18 = 0;
    done:
        ;
    }
    temp_18 = (1 << (temp_18 & 0xFFFF)) & 0xFFFF;
    var_20 = 0;
    var_19 = 0;
    var_21 = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_test;
loop_body:
    temp_3 = *(u16 *)(var_21 + 0x1A);
    if ((temp_3 & 1) != 0 && (temp_3 & 8) != 0) {
        temp_17 = *(u8 **)(var_21 + 0x30);
        if ((temp_18 & (1 << *(u8 *)(temp_17 + 0xA2))) != 0 &&
            datCalcIsDead(*(u8 **)(temp_17 + 0xA64), 0) == 0) {
            var_20 += datCalcGetHp(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
            var_19 += datCalcMaxHp(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF;
        }
    }
    var_21 = *(u8 **)(var_21 + 0x450);
loop_test:
    if (var_21 != NULL)
        goto loop_body;
    return (u32)(var_20 * 0x64) <= (u32)(var_19 * limit);
}
/* Closing state measured: restore opt_rebuildconditionals on after this function. */
#pragma opt_rebuildconditionals on
