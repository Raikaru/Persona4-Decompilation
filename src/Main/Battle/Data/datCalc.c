#include "btl_equipment_count_internal.h"
#include "datCalc_internal.h"
#include "datCalc_unit_internal.h"
#include "datScript_internal.h"
#include "type.h"
#include "include_asm.h"
#include "datPersona_internal.h"
#include "dat_enemy_internal.h"
#include "g_data_entry_internal.h"
#include "member_access.h"
/* DatUnit's calculation state, pinned by the buff getters/setters and hit-result
 * writers below. The two packed tables each use eight bytes for indices 0..15;
 * indices 16..23 are represented by bits in buffFlags instead. */
typedef struct DatCalcUnitState
{
    u8 pad00[0x14];
    u32 buffFlags;          /* 0x14: active buffs and one-shot effects. */
    u32 consumedFlags;      /* 0x18: effects cleared after skill resolution. */
    u8 buffLevels[8];       /* 0x1C: signed nibbles, negative encoded plus 15. */
    u8 secondaryLevels[8];  /* 0x24: unsigned age counters. */
    s16 message;           /* 0x2C: survive/counter/evade message selector. */
    u8 pad2E[2];
} DatCalcUnitState;

/* Character and extended-enemy strides are pinned by their indexed readers. */
typedef struct DatCharacterTable
{
    u8 pad00[0x18];
    u8 skillValue;
    u8 pad19[0x131];
    u8 kind;
    u8 pad14B;
} DatCharacterTable;

typedef struct DatEnemyExtendedTable
{
    u8 pad00[0x18];
    u16 flags;
    u8 skillValue;
    u8 pad1B[0xCD];
} DatEnemyExtendedTable;

extern u32 RpRandom(void);
extern void kAssertFail(void *file, s32 line);
extern u8 D_00635938[];
extern u32 RpRandom(void);

extern void memset(void *, s32, s32);

/* Each percentage bank holds party/enemy rows indexed by signed level plus one. */
typedef struct DatBuffPercent
{
    u8 primary[2][3];
    u8 secondary[2][3];
} DatBuffPercent;

extern u32 datGetLevelTableFirstValue(s16 unitId);
extern s32 datCalcHasSkill(DatUnit *unit, s32 skillId);

extern s32 datScriptTargetIsNotEnemy(void);
extern f32 datScriptCalcFloat(u32 term, s32 parameter);
extern f32 D_00761260;
extern f32 fGpffff811c;
static inline f32 mul_f32_ordered(f32 left, f32 right)
{
    return left * right;
}
static inline f32 add_f32_ordered(f32 left, f32 right)
{
    return left + right;
}

extern s32 datItemCount(s16 itemId);

/* gp - 0x4C48 = 0x007690f0 - 0x4c48 = 0x007644a8 */
extern u8 *iGpffffb3b8;
/* gp - 0x4C40 = 0x007690f0 - 0x4c40 = 0x007644b0 */
extern u8 *iGpffffb3c0;

extern u8 *datEntryAt(s16 itemId);

/* Old-style declaration: the retail call site at datCalcIsFlaggedPersonaSkill passes arg0 raw (no 64-bit extension). */
u16 datCalcUnderlyingSkillId();

extern u16 datCalcMaxHpById(s16 unitId);
extern void datSetUnitHp(s16 unitId, s16 hp);
extern u16 datCalcMaxSpById(s16 unitId);
extern void datSetUnitSp(s16 unitId, s16 sp);
extern void datCalcClearBadStatusById(s16 unitId, u32 mask);

extern u8 *datPersonaGetSkillsByPcId(u16 pcId);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern s32 datPersonaGetLevel(s32 persona);
extern u32 datGetMoney(void);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern u8 *datUnitGetRecord(s32 unitId);
extern u8 datCalcGetBattleStat(DatUnit *unit, s32 statIndex);
/* Defined below in this file; used before its definition. */
extern u16 datCalcEnemyMoney(u8 *unit);
extern s16 datGetEquippedItemByUnit(s16 unitId, s16 slotIndex);
extern u16 datItemValue(s16 itemId);
extern u16 datItemElement(s16 itemId);
extern u32 datItemGrantedSkill(s16 itemId);

extern s32 datCalcGetAffinity(u8 *unit, s32 elementIndex);
extern s32 datCalcGetElementAffinity(u8 *unit, s32 elementIndex);
extern s32 datCalcInflictStatus(s32, DatUnit *, DatUnit *, s32);
extern s32 datCalcSkillAmount(s32, u8 *, u8 *, s32, s32, s32, s32, s32);
extern u32 datCalcStatusEffectResult(s32 skillId, DatUnit *source, DatUnit *target, s32 channel, s32 unusedOutcome, s32 options);
extern u32 datGetFlag(s32 bit);
extern s32 datPersonaGetStatById(s32, s32);
extern s64 datCalcAddBuffLevel(DatUnit *unit, s32 buffIndex, s64 delta);
/* datCalcSkillAllowedForMode passes a 5th arg (arg4) that datCalcSkillAppliesToTarget ignores. */
extern s32 datCalcSkillAppliesToTarget(u8 *, u8 *, s32, s32, s32);
extern s32 datScriptRunCalc(u32 calculationKind, u16 *sourceUnit, u16 *targetUnit, u16 commandId, s32 parameter);
extern u16 cmmCommunityForArcana(s64 arcanaValue);
extern u16 cmmCommunityRecordValue(s32 communityId);

extern u8 *iGpffffb3b4;

extern u8 *iGpffffb408;
extern f32 iGpffff8110;

extern s32 datPersonaLeadBoosted(s32 partyId);

extern u8 *iGpffffb3c4;
extern u8 *iGpffffb448;
extern u8 *iGpffffb44c;
extern u8 *iGpffffb3cc;

extern void datCalcSetBuffLevel(DatUnit *unit, u8 buffIndex, s32 level);
extern void datCalcSetSecondaryBuffLevel(DatUnit *unit, u8 buffIndex, s8 level);

extern u8 datCalcGetUnitStat(DatUnit *unit, s32 statIndex);
extern u8 datPersonaGetTotalStatById(u16 partyId, s32 statIndex);
extern s32 datEntryGetMiddleBandValue(s16 itemId);
extern s32 datEntryGetLastBandValue(s16 itemId);
extern u32 datCalcSkillCost(DatUnit *unit, s32 skillId);
extern s32 datCalcSkillElement(DatUnit *unit, u16 skillId);
extern s8 datCalcGetBuffLevel(DatUnit *unit, s32 buffIndex);
extern u16 datEntryGetPrimaryValue(s16 itemId);
extern u16 datEntryGetSecondaryValue(s16 itemId);
extern u8 datEntryGetPropertyByte(s16 itemId);
extern u16 datGetLevelTableSecondValue(s16 unitId);

static inline u32 PTDatCalcOffsetAdd(u32 offset, u32 base) { return offset + base; }


// Intent: uniform random value in 0..arg0-1 (RpRandom modulo); fatal when arg0 is zero.
// FUN_00231D70
u32 datCalcRandomBelow(u32 limit)
{
    if (limit == 0) {
        kAssertFail(D_00635938, 0x17);
    }
    return RpRandom() % limit;
}



// Intent: zeroes the 0x30-byte unit record arg0 and sets its id to arg1, with level 1 and HP/SP 1.
// FUN_00231DC0
void datCalcInitUnit(DatUnit *unit, s16 id)
{
    memset(unit, 0, sizeof(DatUnit));
    unit->id = id;
    unit->level = 1;
    unit->hp = 1;
    unit->sp = 1;
    unit->id2 = id;
    unit->aiTactic = 0;
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_00300410 (verified MATCH there). */


// Intent: level of unit arg0: its stored level for flag-4 units or id 1, otherwise its persona record's level; fatal when zero.
// FUN_00231E20
s32 datCalcGetLevel(DatUnit *unit)
{
    s32 level;

    if (unit->flags & 4 || unit->id == 1) {
        level = unit->level;
    } else {
        level = (s32)datPersonaGetRecord(unit->id);
        if (level == 0) {
            kAssertFail(D_00635938, 0x58);
        }
        level = datPersonaGetLevel(level) & 0xFF;
    }
    if ((s32)(u8)level <= 0) {
        kAssertFail(D_00635938, 0x5C);
    }
    return level;
}

// FUN_00231ED0
u16 datCalcGetHp(DatUnit *unit)
{
    return unit->hp;
}

// FUN_00231EE0
u16 datCalcGetSp(DatUnit *unit)
{
    return unit->sp;
}

// Intent: stores level arg1 in unit arg0, clamped to 99 unless flag 4.
// FUN_00231EF0
void datCalcSetLevel(DatUnit *unit, u8 level)
{
    if (level > 99 && !(unit->flags & 4))
    {
        level = 0x63;
    }
    unit->level = level;
}

/* Store HP, limiting party units to 999 while preserving enemy values. */
// FUN_00231F20
void datCalcSetHp(DatUnit *unit, u16 hp)
{
    if (hp > 999 && !(unit->flags & 4)) {
        hp = 999;
    }
    unit->hp = hp;
}

/* Store SP, limiting party units to 999 while preserving enemy values. */
// FUN_00231F50
void datCalcSetSp(DatUnit *unit, u16 sp)
{
    if (sp > 999 && !(unit->flags & 4)) {
        sp = 999;
    }
    unit->sp = sp;
}

/* MATCHED 2026-08-08: datCalcMaxHp is byte-exact (nd 0, object 784B /
   window 784B). A raw s32 temp with explicit masks at its uses, a named
   GP-base/index helper, #pragma opt_common_subs off, and
   #pragma opt_propagation off reproduce the retail saved-register lifetimes,
   table-address load order, and the slti $at clamp guard. */
// Intent: maximum HP of unit arg0 from its level and skill/equipment bonuses; capped at 999 unless flag 4.
// FUN_00231F80
/* measured: opt_common_subs/opt_propagation plus PTDatCalcOffsetAdd force retail index-first GP addressing; nested guard preserves slti $at branch form. */
#pragma opt_common_subs off
#pragma opt_propagation off
u16 datCalcMaxHp(DatUnit *unit)
{
    /* Enemy-row offsets +4/+6 are HP/SP within the 0x3C-byte stride; keep index-first GP addressing for the measured load-order requirement above. */
    s32 baseHp;
    s32 bonusHp;
    s32 maximumHp;
    u16 tableHp;
    u8 *base;

    bonusHp = 0;
    baseHp = unit->id;
    if ((unit->flags & 4) != 0) {
        if ((baseHp & 0xFFFF) >= 0x150) {
            kAssertFail(D_00635938, 0xBF);
        }
        base = iGpffffb3c4;
        tableHp = ((DatEnemyUnitInit *)((u8 *)PTDatCalcOffsetAdd((u32)((baseHp & 0xFFFF) * 0x3C), (u32)base)))->hp;
    } else {
        if ((baseHp & 0xFFFF) >= 0xB) {
            kAssertFail(D_00635938, 0xC2);
        }
        tableHp = (u16)datGetLevelTableFirstValue((s16)baseHp);
    }
    baseHp = tableHp & 0xFFFF;
    if (datCalcHasSkill(unit, 0x1F0) != 0) {
        bonusHp += (baseHp * 0xA) / 100;
    }
    if (datCalcHasSkill(unit, 0x1F1) != 0) {
        bonusHp += (baseHp * 0x14) / 100;
    }
    if (datCalcHasSkill(unit, 0x1F2) != 0) {
        bonusHp += (baseHp * 0x1E) / 100;
    }
    if (datCalcHasSkill(unit, 0x22D) != 0) {
        bonusHp += (baseHp * 0x32) / 100;
    }
    if (datCalcHasSkill(unit, 0x20C) != 0) {
        bonusHp += baseHp;
    }
    if (datCalcHasSkill(unit, 0x20D) != 0) {
        bonusHp -= (baseHp * 0x32) / 100;
    }
    bonusHp += (datCalcCountSlotsWithValue((u8 *)unit, 0x1A) & 0xFFFF) * 0xA;
    bonusHp += (datCalcCountSlotsWithValue((u8 *)unit, 0x1B) & 0xFFFF) * 0x14;
    bonusHp += (datCalcCountSlotsWithValue((u8 *)unit, 0x1C) & 0xFFFF) * 0x1E;
    bonusHp += (datCalcCountSlotsWithValue((u8 *)unit, 0x1D) & 0xFFFF) * 0x28;
    bonusHp += (datCalcCountSlotsWithValue((u8 *)unit, 0x1E) & 0xFFFF) * 0x32;
    maximumHp = baseHp + (bonusHp + ((datCalcCountSlotsWithValue((u8 *)unit, 0x5B) & 0xFFFF) * 0x64));
    if ((unit->flags & 4) == 0) {
        if (maximumHp > 0x3E7) {
            maximumHp = 0x3E7;
        }
    }
    return maximumHp & 0xFFFF;
}
/* measured: close opt_propagation scope after 00231f80. */
#pragma opt_propagation on
/* measured: close opt_common_subs scope after 00231f80. */
#pragma opt_common_subs on


/* MATCHED 2026-08-08: datCalcMaxSp is byte-exact (nd 0, object 784B /
   window 784B) using the same raw-s32/index-order/clamp template as
   datCalcMaxHp, with its stat offsets and percentage constants substituted. */
// Intent: maximum SP of unit arg0 from its level and SP bonuses; capped at 999 unless flag 4.
// FUN_00232290
/* measured: sibling of exact 00231f80 template; raw s32 temp, integer GP-base addition, and direct clamp spelling preserve retail. */
#pragma opt_common_subs off
#pragma opt_propagation off
u16 datCalcMaxSp(DatUnit *unit)
{
    /* Enemy-row offsets +4/+6 are HP/SP within the 0x3C-byte stride; keep index-first GP addressing for the measured load-order requirement above. */
    s32 baseSp;
    s32 bonusSp;
    s32 maximumSp;
    u16 tableSp;
    u8 *base;

    bonusSp = 0;
    baseSp = unit->id;
    if ((unit->flags & 4) != 0) {
        if ((baseSp & 0xFFFF) >= 0x150) {
            kAssertFail(D_00635938, 0xD9);
        }
        base = iGpffffb3c4;
        tableSp = ((DatEnemyUnitInit *)((u8 *)PTDatCalcOffsetAdd((u32)((baseSp & 0xFFFF) * 0x3C), (u32)base)))->sp;
    } else {
        if ((baseSp & 0xFFFF) >= 0xB) {
            kAssertFail(D_00635938, 0xDC);
        }
        tableSp = (u16)datGetLevelTableSecondValue((s16)baseSp);
    }
    baseSp = tableSp & 0xFFFF;
    if (datCalcHasSkill(unit, 0x1F3) != 0) {
        bonusSp += (baseSp * 0xA) / 100;
    }
    if (datCalcHasSkill(unit, 0x1F4) != 0) {
        bonusSp += (baseSp * 0x14) / 100;
    }
    if (datCalcHasSkill(unit, 0x1F5) != 0) {
        bonusSp += (baseSp * 0x1E) / 100;
    }
    if (datCalcHasSkill(unit, 0x22E) != 0) {
        bonusSp += (baseSp * 0x32) / 100;
    }
    if (datCalcHasSkill(unit, 0x20C) != 0) {
        bonusSp -= (baseSp * 0x32) / 100;
    }
    if (datCalcHasSkill(unit, 0x20D) != 0) {
        bonusSp += baseSp;
    }
    bonusSp += (datCalcCountSlotsWithValue((u8 *)unit, 0x1F) & 0xFFFF) * 0xA;
    bonusSp += (datCalcCountSlotsWithValue((u8 *)unit, 0x20) & 0xFFFF) * 0x14;
    bonusSp += (datCalcCountSlotsWithValue((u8 *)unit, 0x21) & 0xFFFF) * 0x1E;
    bonusSp += (datCalcCountSlotsWithValue((u8 *)unit, 0x22) & 0xFFFF) * 0x28;
    bonusSp += (datCalcCountSlotsWithValue((u8 *)unit, 0x23) & 0xFFFF) * 0x32;
    maximumSp = baseSp + (bonusSp + ((datCalcCountSlotsWithValue((u8 *)unit, 0x8A) & 0xFFFF) * 0x64));
    if ((unit->flags & 4) == 0) {
        if (maximumSp > 0x3E7) {
            maximumSp = 0x3E7;
        }
    }
    return maximumSp & 0xFFFF;
}
/* measured: close opt_propagation scope after 00232290. */
#pragma opt_propagation on
/* measured: close opt_common_subs scope after 00232290. */
#pragma opt_common_subs on
// Intent: adds hpDelta arg1 to unit arg0's HP, clamped to 0..max HP; returns the new HP.
// FUN_002325A0
s32 datCalcAddHp(DatUnit* unit, s32 hpDelta)
{
    s32 maxHp;
    s32 newHp;

    newHp = unit->hp + hpDelta;
    if (newHp < 0) {
        newHp = 0;
    }
    maxHp = datCalcMaxHp(unit) & 0xFFFF;
    if (maxHp < newHp) {
        newHp = maxHp;
    }
    unit->hp = (u16)newHp;
    return newHp & 0xFFFF;
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_00300480 (verified MATCH there). */

// Intent: adds spDelta arg1 to unit arg0's SP, clamped to 0..max SP; returns the new SP.
// FUN_00232610
s32 datCalcAddSp(DatUnit* unit, s32 spDelta)
{
    s32 maxSp;
    s32 newSp;

    newSp = unit->sp + spDelta;
    if (newSp < 0) {
        newSp = 0;
    }
    maxSp = datCalcMaxSp(unit) & 0xFFFF;
    if (maxSp < newSp) {
        newSp = maxSp;
    }
    unit->sp = (u16)newSp;
    return newSp & 0xFFFF;
}




/* Shared skill search, including the equipment fallback. */
static inline s32 PTDatCalcHasSkill(DatUnit *unit, s32 requestedSkill)
{
    /* Preserve the byte cursor; fields and measured MEMBER sites retain the retail load behavior. */
    s32 skill;
    s32 count;
    s32 index;
    u8 *base;
    s32 result;
    s32 limit;

    count = datCalcGetTableLength(unit) & 0xFFFF;
    base = datCalcSkillList(unit);
    index = 0;
    skill = requestedSkill & 0xFFFF;
    limit = count & 0xFFFF;
    while ((index & 0xFFFF) < limit) {
        if (skill == ((u16 *)base)[(u16)index]) {
            return 1;
        }
        index = (index + 1) & 0xFFFF;
    }
    if (!(*(u16 *)unit & 4)) {
        result = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)((DatUnit *)((u8 *)unit))->id, 2) & 0xFFFF);
        if (result >= 0) {
            if (skill == datItemGrantedSkill((s16)result)) {
                return 1;
            }
        }
    }
    return 0;
}

/* Replace nonzero ailment bits 0..19, and accumulate the independent high status bits. */
// FUN_00232680
u32 datCalcSetBadStatus(DatUnit *unit, u32 badStatus)
{
    u32 low;

    low = badStatus & 0x000fffff;
    if (low != 0) {
        unit->bad = (unit->bad & 0xfff00000) | low;
    }
    return unit->bad |= badStatus & 0xfff00000;
}

// FUN_002326C0
u32 datCalcGetBadStatusNoDown(DatUnit *unit)
{
    return unit->bad & 0x000fffff;
}

// FUN_002326E0
u32 datCalcGetBadStatus(DatUnit *unit)
{
    return unit->bad;
}

// FUN_002326F0
u32 datCalcClearBadStatus(DatUnit *unit, u32 badStatus)
{
    return unit->bad &= ~badStatus;
}

// FUN_00232710
u32 datCalcChkBadStatus(DatUnit *unit, u32 badStatus)
{
    return (unit->bad & badStatus) != 0;
}

// Intent: whether unit arg0 has skill arg1; wrapper over PTDatCalcHasSkill.
// FUN_00232730
s32 datCalcHasSkill(DatUnit *unit, s32 skillId)
{
    return PTDatCalcHasSkill(unit, skillId);
}

// Intent: true when unit arg0 lacks flag 4 and its id has a table entry (datItemCount > 0); [inferred].
// FUN_00232830
s32 datCalcIsStandardUnit(u16 *unitFlags, s64 itemId)
{
    if (*unitFlags & 4) {
        return 0;
    }
    return (datItemCount((s16)itemId) & 0xFF) > 0;
}




// Intent: count (0..2) of the two slots of record id arg0 whose value equals arg1.
// FUN_00232880
u16 datCalcCountIdSlotsWithValue(u16 characterId, u16 property)
{
    u16 count;
    s16 id;
    u16 val;

    if ((characterId & 0xFFFF) >= 0xB) {
        kAssertFail(D_00635938, 0x263);
    }
    count = 0;
    id = (s16)characterId;
    val = (u16)property;
    if ((datItemValue(datGetEquippedItemByUnit(id, 0)) & 0xFFFF) == val) {
        count++;
    }
    if ((datItemValue(datGetEquippedItemByUnit(id, 1)) & 0xFFFF) == val) {
        count++;
    }
    return count;
}

// Intent: count (0..2) of unit arg0's two slots whose value equals arg1.
// FUN_00232950
/* measured: propagation off preserves both per-record halfword increments.
 * The count is a word-valued query result; callers may test it without narrowing.
 * 58 instructions, zero relocation-masked differences for the whole owner. */
#pragma push
#pragma opt_propagation off
s32 datCalcCountSlotsWithValue(u8 *unit, s32 property)
{
    u32 count;
    s16 id;
    u16 id16;
    u16 val;

    if (((DatUnit *)unit)->flags & 4) {
        return 0;
    }
    id16 = ((DatUnit *)unit)->id;
    if (id16 >= 0xB) {
        kAssertFail(D_00635938, 0x263);
    }
    count = 0;
    id = (s16)id16;
    val = (u16)property;
    if (datItemValue(datGetEquippedItemByUnit(id, 0)) == val) {
        count = (u16)(count + 1);
    }
    if (datItemValue(datGetEquippedItemByUnit(id, 1)) == val) {
        count = (u16)(count + 1);
    }
    return count;
}
#pragma pop


// Intent: true when skill id arg0 (below 0x1B8) lacks flag bit 2 and has flag bit 1 set; [inferred].
// FUN_00232A40
s32 datCalcIsSkillAvailable(s32 skillId)
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    s32 id;
    u8 *base;

    id = skillId & 0xFFFF;
    if (id >= 0x1B8) {
        return 0;
    } else {
        base = iGpffffb3b8 + id * 0x28;
        if (base[0] & 2) {
            return 0;
        }
        return (base[1] & 1) != 0;
    }
}

// Intent: true for skill ids 0x301..0x3FF whose skill record has flag bit 2 set; [inferred].
// FUN_00232AA0
s32 datCalcIsFlaggedPersonaSkill(s32 skillId)
{
    u16 id16;

    if ((skillId & 0xFFFF) <= 0x300 || (skillId & 0xFFFF) >= 0x400) {
        return 0;
    } else {
        id16 = datCalcUnderlyingSkillId(skillId) & 0xFFFF;
        if (id16 == 0) {
            return 0;
        }
        if (id16 >= 0x1B8) {
            return 0;
        }
        return (iGpffffb3b8[id16 * 0x28 + 1] & 2) != 0;
    }
}

/* measured: daddiu return constants ARE reachable â€” u8 var_2 with
   `var_2 = 1;` / `var_2 = 0x63;` emits daddiu (s32 never does), the
   (s32)((u32)arg1 & 0xFFFF) guard gives bltz, and `temp_3 > 0x63` the
   slti-$at form; tail fully matches. Best nd 5: residual is the
   table-index load-sinking floor â€” retail lw's the iGpffffb3c4 base
   into $a0 BEFORE the *0x3C mul chain and masks the index last; mwcc
   b210 sinks the lw after the mul (index-first, base-first, base-local
   spellings all tried). */
/* measured: recipe-A re-test 2026-08-03. The bltz guard works unchanged
   (`(s32)((u32)arg1 & 0xFFFF)` keeps the single bare bltz; offsets 28-44
   byte-match). New finding: the table index needs TWO separate andi's in
   retail (one before the >=0x150/>=0xB error tests, one before the *0x3C
   mul chain); spelling the tests `(u16)temp_16` and the mul
   `(temp_16 & 0xFFFF)` defeats mwcc's mask CSE (a bare double `& 0xFFFF`
   collapses to one in-place `andi $s0`). Also fixed the wrong extern:
   datPersonaGetStatById is `s32 (s32, s32)` per datPersona.c (u16 param forced a
   bogus pre-call andi). Tail fully matches (daddiu 1/0x63, slti-$at form).
   Residual, best nd 9: the table-index load-sinking floor -- retail lw's
   the iGpffffb3c4 base into $a0 BEFORE the *0x3C mul chain and adds arg1's
   mask last; mwcc b210 sinks the lw after the mul (index-first, base-first,
   base-local, draft-tree spellings all tried). */
/* measured 2026-08-03 (re-test): nd 9 confirmed with the s32-temp_16
   combo (test `(u16)temp_16`, index `(temp_16 & 0xFFFF)`, arg1-index
   `(u16)arg1` keep the three andis separate; u16 temp_16 collapses the
   cast into the AND node and hoists one mask into s1, nd 72). Tail fully
   matches: bltz guard, daddiu 1/0x63, slti-$at form, datPersonaGetStatById call.
   Residual is the same load-sinking floor as func_0023e3e0's case 0:
   retail lw's the iGpffffb3c4 base into $a0 BEFORE the *0x3C andi-chain
   and masks arg1 last; mwcc b210 sinks the lw after the chain into $v0.
   Tried: inline, base-local (`u8 *base = iGpffffb3c4;`), elem-pointer
   local, chain-first/base-first addition order -- all nd 9. */
/* measured this pass: the load-sinking half IS the same defect func_0023e3e0
   solved, and `#pragma opt_propagation off` plus nested PTDatCalcOffsetAdd calls
   (offset-first for both the *0x3C chain and the arg1 mask) is the recipe that
   worked there. It could not be applied here because the recorded nd-9 body is
   not reconstructable from this note: a fresh reconstruction of the guards and
   tail lands at nd 68 (74 with the pragma), so the combo has not actually been
   tested against the good body. Whoever holds a body at nd 9 should try it --
   do NOT re-derive from scratch. */
/* measured: widened temp to s32 and cast each u16 use, keeping the unmasked
   source live while scratch andi values feed the guards/index; removed the
   named check and kept the direct bound comparison. normalized_diff 0,
   object 296B/304B. Committed at nd 0. */
// Intent: stat arg1 (0..4) of unit arg0 clamped to 1..99; fatal when arg1 >= 5.
// FUN_00232B40
u8 datCalcGetUnitStat(DatUnit *unit, s32 statIndex)
{
    /* Preserve index-first GP cursor construction; the fields follow the established table layouts. */
    s32 temp;
    u8 value;
    u32 index;
    u8 *base;

    if ((s32)(statIndex & 0xFFFF) < 0 || (s32)(statIndex & 0xFFFF) >= 5)
        kAssertFail(D_00635938, 0x2F0);
    temp = unit->id;
    if ((unit->flags & 4) != 0) {
        if ((u16)temp >= 0x150)
            kAssertFail(D_00635938, 0x2F7);
        base = (u8 *)iGpffffb3c4;
        index = (u32)(u16)temp * 0x3C;
        base = (u8 *)(index + (u32)base);
        base = (u8 *)(((u32)statIndex & 0xFFFF) + (u32)base);
        value = ((DatEnemyUnitInit *)(base))->stats[0];
    } else {
        if ((u16)temp >= 0xB)
            kAssertFail(D_00635938, 0x2FA);
        value = (u8)datPersonaGetStatById(temp, statIndex);
    }
    if ((s32)value > 0)
        goto clamp_value;
    value = 1;
    goto done_value;
clamp_value:
    if (value > 0x63)
        value = 0x63;
done_value:
    return value;
}

/* measured: archived candidate re-tested at nd 2; return-width and guard probes did not improve it. */
/* measured: the two clamp constants are `daddiu $v0,$zero,K` because the
   value is a u8 (narrow-unsigned rule) and the function returns u8, which
   keeps it in $v0; `v >>= 1` on the u8 avoids the extra re-mask a spelled-out
   `(u32)v >> 1` adds; `<= 0x63` before the goto gives the slti $at form. */
// Intent: battle stat arg1 (0..4) of unit arg0: from its table row for flag-4 units, else from its persona record; fatal when arg1 >= 5.
// FUN_00232C70
u8 datCalcGetBattleStat(DatUnit *unit, s32 statIndex)
{
    u8 value;
    s32 statValue;
    u8 halved;

    if (((s32)(statIndex & 0xFFFF) < 0) || ((statIndex & 0xFFFF) >= 5)) {
        kAssertFail(D_00635938, 0x313);
    }
    if ((unit->flags & 4) != 0) {
        value = (u32)datCalcGetUnitStat(unit, statIndex);
        value &= 0xFF;
    } else {
        if (unit->id >= 0xB) {
            kAssertFail(D_00635938, 0x31A);
        }
        value = (u32)datPersonaGetTotalStatById(unit->id, statIndex);
        value &= 0xFF;
    }
    halved = (unit->bad & 0x80) != 0;
    if (!halved) {
        goto no_shift;
    }
    value >>= 1;
no_shift:
    statValue = (u32)value & 0xFF;
    if (statValue > 0) {
        goto clamp_value;
    }
    value = 1;
    goto done_value;
clamp_value:
    if (statValue <= 0x63) {
        goto done_value;
    }
    value = 0x63;
done_value:
    return value;
}

// Intent: bitmask (bits 0..5) of skill ids 0x1F9..0x1FE that unit arg0 has; [inferred] meaning of the bits.
// FUN_00232D80
#pragma push
/* measured: 1304B/1312B, eight zero-tail bytes and 24 resolved relocations;
   loop-invariant hoisting preserves the retail six-search preheaders. */
#pragma opt_loop_invariants on
s32 datCalcGetSkillMask(DatUnit *unit)
{
    s32 result;
    result = 0;
    if (PTDatCalcHasSkill(unit, 0x1F9) != 0) {
        result |= 0x1;
    }
    if (PTDatCalcHasSkill(unit, 0x1FA) != 0) {
        result |= 0x2;
    }
    if (PTDatCalcHasSkill(unit, 0x1FB) != 0) {
        result |= 0x4;
    }
    if (PTDatCalcHasSkill(unit, 0x1FC) != 0) {
        result |= 0x8;
    }
    if (PTDatCalcHasSkill(unit, 0x1FD) != 0) {
        result |= 0x10;
    }
    if (PTDatCalcHasSkill(unit, 0x1FE) != 0) {
        result |= 0x20;
    }
    return result;
}
#pragma pop

// Intent: signed 4-bit buff level at index arg1 (0..23) of unit arg0; 0..4 follow DatPersonaStat (St/Ma/En/Ag/Lu), read as buff or debuff by datCalcHasBuffMask; [inferred].
// FUN_002332A0
s8 datCalcGetBuffLevel(DatUnit *unit, s32 buffIndex)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    s8 value;
    u8 index;
    u16 offset;

    if ((s32)(buffIndex & 0xff) >= 0x18) {
        kAssertFail(D_00635938, 0x40F);
    }
    index = buffIndex;
    offset = index >> 1;
    if (index & 1) {
        value = ((DatCalcUnitState *)(PTDatCalcOffsetAdd(offset, (u32)unit)))->buffLevels[0] >> 4;
    }
    else {
        value = ((DatCalcUnitState *)(PTDatCalcOffsetAdd(offset, (u32)unit)))->buffLevels[0] & 0xf;
    }
    if (7 < value) {
        value = (s8)(value - 0xf);
    }
    return value;
}

// Intent: stores signed 4-bit buff level arg2 (-7..7) for index arg1 (0..23); [inferred].
// FUN_00233370
void datCalcSetBuffLevel(DatUnit *unit, u8 buffIndex, s32 level)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    s32 index;
    s32 byteOffset;
    s8 signedLevel;
    s32 packedLevel;

    packedLevel = level;
    index = buffIndex & 0xFF;
    if (index >= 0x18) {
        kAssertFail(D_00635938, 0x441);
    }
    signedLevel = (s8)packedLevel;
    if (signedLevel > 7 || signedLevel < -7) {
        kAssertFail(D_00635938, 0x442);
    }
    byteOffset = (index >> 1) & 0xFFFF;
    if (signedLevel < 0) {
        packedLevel = (s8)(signedLevel + 0xF);
    }
    if (index & 1) {
        u8 *packedByte = (u8 *)((byteOffset & 0xFFFF) + (s32)unit);
        packedByte[0x1C] = (u8)((packedByte[0x1C] & 0xF) | (((s8)packedLevel & 0xF) << 4));
        return;
    }
    {
        u8 *packedByte = (u8 *)((byteOffset & 0xFFFF) + (s32)unit);
        packedByte[0x1C] = (u8)((packedByte[0x1C] & 0xF0) | ((s8)packedLevel & 0xF));
    }
}

// Intent: stores signed 4-bit buff level arg2 in the secondary nibble table for index arg1; [inferred].
// FUN_00233490
void datCalcSetSecondaryBuffLevel(DatUnit *unit, u8 buffIndex, s8 level)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    u8 *b;
    u16 idx;
    u8 old;

    if (buffIndex >= 0x18) {
        kAssertFail(D_00635938, 0x45E);
    }
    if (level < 0) {
        kAssertFail(D_00635938, 0x45F);
    }
    idx = ((s32)buffIndex >> 1) & 0xFFFF;
    b = (u8 *)unit;
    if (buffIndex & 1) {
        old = b[idx + 0x24];
        b[idx + 0x24] = (u8)((old & 0xF) | ((level & 0xF) << 4));
    } else {
        old = b[idx + 0x24];
        b[idx + 0x24] = (u8)((old & 0xF0) | (level & 0xF));
    }
}

/* measured: fully relocated 784B / 784B match, with no tail gap.
   Keep the standalone signed-byte promotion at the getter branch merge:
   it preserves retail scratch-register lifetimes before the signed decode. */
// Intent: adds signed delta arg2 to buff level arg1, clamped to -1..1, setting its flag bit when nonzero; returns the new level; [inferred].
// FUN_00233570
s64 datCalcAddBuffLevel(DatUnit *unit, s32 buffIndex, s64 delta)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    s32 index;
    u8 byteIndex;
    s32 halfIndex;
    u16 offset;
    s32 odd;
    s32 value;
    s32 current;
    s16 result;
    s8 packed;
    s8 checked;
    u8 *ptr;

    index = buffIndex & 0xff;
    if (index >= 24) {
        kAssertFail(D_00635938, 1142);
    }
    result = 0;
    if (index < 16) {
        if (index >= 24) {
            kAssertFail(D_00635938, 1039);
        }
        byteIndex = buffIndex;
        halfIndex = byteIndex >> 1;
        offset = halfIndex;
        odd = byteIndex & 1;
        if (odd) {
            value = (s8)(((DatCalcUnitState *)(PTDatCalcOffsetAdd(offset, (u32)unit)))->buffLevels[0] >> 4);
        } else {
            value = (s8)(((DatCalcUnitState *)(PTDatCalcOffsetAdd(offset, (u32)unit)))->buffLevels[0] & 15);
        }
        value = (s8)value;
        if (value > 7) {
            value = (s8)(value - 15);
        }
        current = (s8)value;
        if ((s8)delta == 0) {
            return (s8)current;
        }
        result = current + (s8)delta;
        if (result > 1) {
            result = 1;
        } else if (result < -1) {
            result = -1;
        }
        packed = result;
        if (index >= 24) {
            kAssertFail(D_00635938, 1089);
        }
        checked = packed;
        if (checked > 7 || checked < -7) {
            kAssertFail(D_00635938, 1090);
        }
        offset = halfIndex;
        if (checked < 0) {
            packed = (s8)(checked + 15);
        }
        if (odd) {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)unit);
            ptr[28] = (ptr[28] & 15) | ((packed & 15) << 4);
        } else {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)unit);
            ptr[28] = (ptr[28] & 240) | (packed & 15);
        }
        if (result == 0) {
            ((DatCalcUnitState *)unit)->buffFlags &= ~(1 << index);
        } else {
            ((DatCalcUnitState *)unit)->buffFlags |= 1 << index;
        }
        if (index >= 24) {
            kAssertFail(D_00635938, 1118);
        }
        offset = halfIndex;
        if (odd) {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)unit);
            ptr[36] &= 15;
        } else {
            ptr = (u8 *)PTDatCalcOffsetAdd(offset, (u32)unit);
            ptr[36] &= 240;
        }
    } else {
        ((DatCalcUnitState *)unit)->buffFlags |= 1 << index;
    }
    return (s8)result;
}

// Intent: clears buff level arg1 (0..23) and its flag bit in unit arg0; [inferred].
// FUN_00233880
void datCalcClearBuffLevel(DatUnit *unit, s32 buffIndex)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    s32 odd;
    s32 halfIndex;
    s32 index;
    s32 buffOffset;
    s32 secondaryOffset;
    u8 *ptr;

    index = buffIndex & 0xFF;
    if (index >= 0x18) {
        kAssertFail(D_00635938, 0x4A2);
    }
    if (index < 0x10) {
        if (index >= 0x18) {
            kAssertFail(D_00635938, 0x441);
        }
        halfIndex = index >> 1;
        buffOffset = halfIndex & 0xFFFF;
        odd = index & 1;
        if (odd != 0) {
            ptr = (u8 *)((buffOffset & 0xFFFF) + (s32)unit);
            ptr[0x1C] = (u8)(ptr[0x1C] & 0xF);
        } else {
            ptr = (u8 *)((buffOffset & 0xFFFF) + (s32)unit);
            ptr[0x1C] = (u8)(ptr[0x1C] & 0xF0);
        }
        if (index >= 0x18) {
            kAssertFail(D_00635938, 0x45E);
        }
        secondaryOffset = (u16)halfIndex;
        if (odd != 0) {
            ptr = (u8 *)((secondaryOffset & 0xFFFF) + (s32)unit);
            ptr[0x24] = (u8)(ptr[0x24] & 0xF);
        } else {
            ptr = (u8 *)((secondaryOffset & 0xFFFF) + (s32)unit);
            ptr[0x24] = (u8)(ptr[0x24] & 0xF0);
        }
    }
    ((DatCalcUnitState *)unit)->buffFlags = ((DatCalcUnitState *)unit)->buffFlags & ~(1 << index);
}

// Intent: clears all 24 buff levels of unit arg0 (flag word and both nibble tables); [inferred].
// FUN_002339D0
void datCalcClearAllBuffs(DatUnit *unit)
{
    u32 i;
    s32 i8;

    for (i = 0; i < 0x18; i++) {
        i8 = i & 0xFF;
        if (i8 >= 0x18) {
            kAssertFail(D_00635938, 0x4A2);
        }
        if (i8 < 0x10) {
            datCalcSetBuffLevel(unit, i, 0);
            datCalcSetSecondaryBuffLevel(unit, i, 0);
        }
        ((DatCalcUnitState *)unit)->buffFlags &= ~(1 << i8);
    }
}

// Intent: buff level (signed) for index arg1 below 16, or the flag bit for indices 16..23, of unit arg0.
// FUN_00233A90
s8 datCalcGetBuffStatus(DatUnit *unit, s32 buffIndex)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    s8 nibble;
    u8 result;
    u8 index;
    u16 offset;
    s32 statusIndex;

    statusIndex = buffIndex & 0xff;
    if (statusIndex >= 0x18) {
        kAssertFail(D_00635938, 0x4C1);
    }
    if (statusIndex < 0x10) {
        if (statusIndex >= 0x18) {
            kAssertFail(D_00635938, 0x40F);
        }
        index = buffIndex;
        offset = index >> 1;
        if (index & 1) {
            nibble = ((DatCalcUnitState *)(PTDatCalcOffsetAdd(offset, (u32)unit)))->buffLevels[0] >> 4;
        }
        else {
            nibble = ((DatCalcUnitState *)(PTDatCalcOffsetAdd(offset, (u32)unit)))->buffLevels[0] & 0xf;
        }
        if (7 < nibble) {
            nibble = (s8)(nibble - 0xf);
        }
        return nibble;
    }
    result = (((DatCalcUnitState *)unit)->buffFlags & 1 << statusIndex) != 0;
    return result;
}

/* Clears the word at byte offset 0x18 of the object block. */
// FUN_00233BB0
void datCalcClearField18(int object)
{
    /* The integer object transport is shared with callers; its consumed-flags word belongs to the calculation state. */
    ((DatCalcUnitState *)object)->consumedFlags = 0;
}

// Intent: multiplier for stat index arg1 on unit arg0: indices 0-4 read a buff level, 18-19 read a status bit; scaled by the enemy/party table, lead boost and the 0x40000/0x80000 flags; [inferred].
// FUN_00233BC0
/* The low-byte status index must be below 24. Retail diagnoses that
 * contract twice; all six executable callers pass constants 0..4.
 * Their third argument is an unused u16 skill ID; preserving that contract
 * avoids caller-side widening before the matching hit and damage routines. */
#pragma push
#pragma opt_propagation off
f32 datCalcBuffMultiplier(u8 *unit, s32 buffIndex, u16 unusedSkill)
{
    /* The percentage table uses signed status -1..1 and side-dependent three-byte rows; index-first GP addition preserves the documented retail load order. */
    s32 index;
    u8 active;
    s32 enemyFlag;
    u32 enemy;
    s16 enemyPredicate;
    f32 multiplier;
    f32 percentage;
    s32 value;
    u8 *table;
    s32 status;

    index = buffIndex & 0xFF;
    if (index >= 24) {
        kAssertFail(D_00635938, 1265);
    }
    if (index >= 24) {
        kAssertFail(D_00635938, 1217);
    }
    status = (s8)(index < 16 ? datCalcGetBuffLevel((DatUnit *)unit, buffIndex) :
        (s8)(active = (((DatCalcUnitState *)unit)->buffFlags & (1U << index)) != 0));
    if (status < -1 || status > 1) {
        kAssertFail(D_00635938, 1269);
    }
    enemyFlag = (((DatUnit *)unit)->flags & 4);
    enemyPredicate = enemyFlag != 0;
    enemy = (u16)enemyPredicate;
    multiplier = 1.0f;
    switch (index) {
    case 0:
        table = iGpffffb408;
        value = ((DatBuffPercent *)PTDatCalcOffsetAdd((u32)status,
            PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table)))->primary[0][1];
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        active = (((DatCalcUnitState *)unit)->buffFlags & 0x40000U) != 0;
        if ((s8)active > 0) {
            multiplier = multiplier * 2.5f;
        }
        if (enemyFlag == 0 && datPersonaLeadBoosted(((DatUnit *)unit)->id) != 0) {
            multiplier = multiplier * iGpffff8110;
        }
        break;
    case 1:
        table = iGpffffb408;
        value = ((DatBuffPercent *)PTDatCalcOffsetAdd((u32)status,
            PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table)))->primary[0][1];
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        active = (((DatCalcUnitState *)unit)->buffFlags & 0x80000U) != 0;
        if ((s8)active > 0) {
            multiplier = multiplier * 2.5f;
        }
        if (enemyFlag == 0 && datPersonaLeadBoosted(((DatUnit *)unit)->id) != 0) {
            multiplier = multiplier * iGpffff8110;
        }
        break;
    case 2:
        table = iGpffffb408; /* Interleaved side rows: bank center 7, indexed by minus signed status. */
        value = *(u8 *)(PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table) + 7U - (u32)status);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        if (enemyFlag == 0 && datPersonaLeadBoosted(((DatUnit *)unit)->id) != 0) {
            multiplier = multiplier * 0.75f;
        }
        break;
    case 3:
        table = iGpffffb408; /* Interleaved side rows: bank center 1, indexed by minus signed status. */
        value = *(u8 *)(PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table) + 1U - (u32)status);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        if (enemyFlag == 0 && datPersonaLeadBoosted(((DatUnit *)unit)->id) != 0) {
            multiplier = multiplier * 0.75f;
        }
        break;
    case 4:
        table = iGpffffb408;
        value = ((DatBuffPercent *)PTDatCalcOffsetAdd((u32)status,
            PTDatCalcOffsetAdd((enemy & 0xFFFF) * 3, (u32)table)))->secondary[0][1];
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        if (enemyFlag == 0 && datPersonaLeadBoosted(((DatUnit *)unit)->id) != 0) {
            multiplier = multiplier * iGpffff8110;
        }
        break;
    case 18:
        if (status > 0) {
            multiplier = 2.5f;
        }
        break;
    case 19:
        if (status > 0) {
            multiplier = 2.5f;
        }
        break;
    }
    return multiplier;
}

#pragma pop

/* measured: func_002340c0 matches retail's 1904-byte window (1900-byte
   emitted body plus the retail zero-padding tail). The 0x30000 branch uses
   goto-labelled shared return blocks, and each s64 flag normalization is
   explicitly re-booleanized after dsra32 to preserve retail's sltu sequence. */
// Intent: true when unit arg0 has a buff (>0) or debuff (<0) on any stat selected by mask arg1; [inferred].
// FUN_002340C0
s32 datCalcHasBuffMask(DatUnit *unit, s32 mask)
{
    s32 buffFlags;
    s64 active;

    if (mask == 0) {
        return 0;
    }
    if (mask & 1) {
        return datCalcGetBuffLevel(unit, 0) > 0;
    }
    if (mask & 2) {
        return datCalcGetBuffLevel(unit, 0) < 0;
    }
    if (mask & 4) {
        return datCalcGetBuffLevel(unit, 1) > 0;
    }
    if (mask & 8) {
        return datCalcGetBuffLevel(unit, 1) < 0;
    }
    if (mask & 0x10) {
        return datCalcGetBuffLevel(unit, 2) > 0;
    }
    if (mask & 0x20) {
        return datCalcGetBuffLevel(unit, 2) < 0;
    }
    if (mask & 0x40) {
        return datCalcGetBuffLevel(unit, 3) > 0;
    }
    if (mask & 0x80) {
        return datCalcGetBuffLevel(unit, 3) < 0;
    }
    if (mask & 0x100) {
        return datCalcGetBuffLevel(unit, 4) > 0;
    }
    if (mask & 0x200) {
        return datCalcGetBuffLevel(unit, 4) < 0;
    }
    if (mask & 0x400) {
        return (((s64)((((DatCalcUnitState *)unit)->buffFlags & 0x40000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (mask & 0x800) {
        return (((s64)((((DatCalcUnitState *)unit)->buffFlags & 0x80000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (mask & 0x4000) {
        return datCalcGetBuffLevel(unit, 5) != 0;
    }
    if (mask & 0x8000) {
        return datCalcGetBuffLevel(unit, 6) != 0;
    }
    if (mask == 0x30000) {
        goto case_30000;
    }
    if (mask & 0x10000) {
        return (((s64)((((DatCalcUnitState *)unit)->buffFlags & 0x10000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (mask & 0x20000) {
        return (((s64)((((DatCalcUnitState *)unit)->buffFlags & 0x20000) != 0) << 0x38) >> 0x38) != 0;
    }
    goto rest_30000;
case_30000:
    buffFlags = ((DatCalcUnitState *)unit)->buffFlags;
    active = (s64)((buffFlags & 0x10000) != 0);
    active = (s64)(active << 0x38) >> 0x38;
    active = active != 0;
    if (active == 0) {
        active = (s64)((buffFlags & 0x20000) != 0);
        active = (s64)(active << 0x38) >> 0x38;
        active = active != 0;
    }
    return active != 0;
rest_30000:
    if (mask & 0x40000) {
        return datCalcGetBuffLevel(unit, 8) != 0;
    }
    if (mask & 0x80000) {
        return datCalcGetBuffLevel(unit, 9) != 0;
    }
    if (mask & 0x100000) {
        return datCalcGetBuffLevel(unit, 0xA) != 0;
    }
    if (mask & 0x200000) {
        return datCalcGetBuffLevel(unit, 0xB) != 0;
    }
    if (mask & 0x400000) {
        return datCalcGetBuffLevel(unit, 7) != 0;
    }
    if (mask & 0x800000) {
        return (((s64)((((DatCalcUnitState *)unit)->buffFlags & 0x100000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (mask & 0x04000000) {
        return (((s64)((((DatCalcUnitState *)unit)->buffFlags & 0x800000) != 0) << 0x38) >> 0x38) != 0;
    }
    if (mask & 0x08000000) {
        return datCalcGetBuffLevel(unit, 0xC) != 0;
    }
    if (mask & 0x10000000) {
        return datCalcGetBuffLevel(unit, 0xD) != 0;
    }
    if (mask & 0x20000000) {
        return datCalcGetBuffLevel(unit, 0xE) != 0;
    }
    if (mask & 0x40000000) {
        return datCalcGetBuffLevel(unit, 0xF) != 0;
    }
    if (mask & 0x1000) {
        if (datCalcGetBuffLevel(unit, 0) <= 0) {
            if (datCalcGetBuffLevel(unit, 1) <= 0) {
                if (datCalcGetBuffLevel(unit, 2) <= 0) {
                    if (datCalcGetBuffLevel(unit, 3) <= 0) {
                        if (datCalcGetBuffLevel(unit, 4) > 0) {
                            goto return_zero_1000;
                        }
                        goto return_one_1000;
                    }
                    goto return_zero_1000;
                }
                goto return_zero_1000;
            }
            goto return_zero_1000;
        }
        goto return_zero_1000;
    }
    goto check_2000;
return_zero_1000:
    return 0;
return_one_1000:
    return 1;
check_2000:
    if (mask & 0x2000) {
        if (datCalcGetBuffLevel(unit, 0) >= 0) {
            if (datCalcGetBuffLevel(unit, 1) >= 0) {
                if (datCalcGetBuffLevel(unit, 2) >= 0) {
                    if (datCalcGetBuffLevel(unit, 3) >= 0) {
                        if (datCalcGetBuffLevel(unit, 4) < 0) {
                            goto return_zero_2000;
                        }
                        goto return_one_2000;
                    }
                    goto return_zero_2000;
                }
                goto return_zero_2000;
            }
            goto return_zero_2000;
        }
        goto return_zero_2000;
    }
    goto check_01000000;
return_zero_2000:
    return 0;
return_one_2000:
    return 1;
check_01000000:
    if (mask & 0x01000000) {
        return (((s64)((((DatCalcUnitState *)unit)->buffFlags & 0x10000) != 0) << 0x38) >> 0x38) == 0;
    }
    if (mask & 0x02000000) {
        return (((s64)((((DatCalcUnitState *)unit)->buffFlags & 0x20000) != 0) << 0x38) >> 0x38) == 0;
    }
    kAssertFail(D_00635938, 0x5DE);
    return 0;
}

// Intent: applies signed buff delta arg2 to the stats selected by mask arg1 (bit pairs for up and down on stats 0..4); [inferred].
// FUN_00234830
void datCalcApplyBuffMask(DatUnit *unit, s32 mask, s64 delta)
{
    if (mask != 0) {
        if (mask & 1) {
            datCalcAddBuffLevel(unit, 0, delta);
        }
        if (mask & 2) {
            datCalcAddBuffLevel(unit, 0, (s64)(s8)-(s8)delta);
        }
        if (mask & 4) {
            datCalcAddBuffLevel(unit, 1, delta);
        }
        if (mask & 8) {
            datCalcAddBuffLevel(unit, 1, (s64)(s8)-(s8)delta);
        }
        if (mask & 0x10) {
            datCalcAddBuffLevel(unit, 2, delta);
        }
        if (mask & 0x20) {
            datCalcAddBuffLevel(unit, 2, (s64)(s8)-(s8)delta);
        }
        if (mask & 0x40) {
            datCalcAddBuffLevel(unit, 3, delta);
        }
        if (mask & 0x80) {
            datCalcAddBuffLevel(unit, 3, (s64)(s8)-(s8)delta);
        }
        if (mask & 0x100) {
            datCalcAddBuffLevel(unit, 4, delta);
        }
        if (mask & 0x200) {
            datCalcAddBuffLevel(unit, 4, (s64)(s8)-(s8)delta);
        }
        if (mask & 0x400) {
            datCalcAddBuffLevel(unit, 0x12, delta);
        }
        if (mask & 0x800) {
            datCalcAddBuffLevel(unit, 0x13, delta);
        }
        if (mask & 0x1000) {
            if ((s8)datCalcGetBuffLevel(unit, 0) > 0) {
                datCalcSetBuffLevel(unit, 0, 0);
                datCalcSetSecondaryBuffLevel(unit, 0, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~1;
            }
            if ((s8)datCalcGetBuffLevel(unit, 1) > 0) {
                datCalcSetBuffLevel(unit, 1, 0);
                datCalcSetSecondaryBuffLevel(unit, 1, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~2;
            }
            if ((s8)datCalcGetBuffLevel(unit, 2) > 0) {
                datCalcSetBuffLevel(unit, 2, 0);
                datCalcSetSecondaryBuffLevel(unit, 2, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~4;
            }
            if ((s8)datCalcGetBuffLevel(unit, 3) > 0) {
                datCalcSetBuffLevel(unit, 3, 0);
                datCalcSetSecondaryBuffLevel(unit, 3, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~8;
            }
            if ((s8)datCalcGetBuffLevel(unit, 4) > 0) {
                datCalcSetBuffLevel(unit, 4, 0);
                datCalcSetSecondaryBuffLevel(unit, 4, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~0x10;
            }
        }
        if (mask & 0x2000) {
            if ((s8)datCalcGetBuffLevel(unit, 0) < 0) {
                datCalcSetBuffLevel(unit, 0, 0);
                datCalcSetSecondaryBuffLevel(unit, 0, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~1;
            }
            if ((s8)datCalcGetBuffLevel(unit, 1) < 0) {
                datCalcSetBuffLevel(unit, 1, 0);
                datCalcSetSecondaryBuffLevel(unit, 1, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~2;
            }
            if ((s8)datCalcGetBuffLevel(unit, 2) < 0) {
                datCalcSetBuffLevel(unit, 2, 0);
                datCalcSetSecondaryBuffLevel(unit, 2, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~4;
            }
            if ((s8)datCalcGetBuffLevel(unit, 3) < 0) {
                datCalcSetBuffLevel(unit, 3, 0);
                datCalcSetSecondaryBuffLevel(unit, 3, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~8;
            }
            if ((s8)datCalcGetBuffLevel(unit, 4) < 0) {
                datCalcSetBuffLevel(unit, 4, 0);
                datCalcSetSecondaryBuffLevel(unit, 4, 0);
                ((DatCalcUnitState *)unit)->buffFlags &= ~0x10;
            }
        }
        if (mask & 0x4000) {
            datCalcAddBuffLevel(unit, 5, delta);
        }
        if (mask & 0x8000) {
            datCalcAddBuffLevel(unit, 6, delta);
        }
        if (mask & 0x10000) {
            datCalcAddBuffLevel(unit, 0x10, delta);
        }
        if (mask & 0x20000) {
            datCalcAddBuffLevel(unit, 0x11, delta);
        }
        if (mask & 0x40000) {
            datCalcAddBuffLevel(unit, 8, delta);
        }
        if (mask & 0x80000) {
            datCalcAddBuffLevel(unit, 9, delta);
        }
        if (mask & 0x100000) {
            datCalcAddBuffLevel(unit, 0xA, delta);
        }
        if (mask & 0x200000) {
            datCalcAddBuffLevel(unit, 0xB, delta);
        }
        if (mask & 0x400000) {
            datCalcAddBuffLevel(unit, 7, delta);
        }
        if (mask & 0x800000) {
            datCalcAddBuffLevel(unit, 0x14, delta);
        }
        if (mask & 0x04000000) {
            datCalcAddBuffLevel(unit, 0x17, delta);
        }
        if (mask & 0x08000000) {
            datCalcAddBuffLevel(unit, 0xC, delta);
        }
        if (mask & 0x10000000) {
            datCalcAddBuffLevel(unit, 0xD, delta);
        }
        if (mask & 0x20000000) {
            datCalcAddBuffLevel(unit, 0xE, delta);
        }
        if (mask & 0x40000000) {
            datCalcAddBuffLevel(unit, 0xF, delta);
        }
        if (mask & 0x01000000) {
            ((DatCalcUnitState *)unit)->buffFlags &= 0xFFFEFFFF;
        }
        if (mask & 0x02000000) {
            ((DatCalcUnitState *)unit)->buffFlags &= 0xFFFDFFFF;
        }
    }
}

// Intent: clears the buff and secondary levels of each index flagged in the mask at +0x18 of unit arg0, then clears that mask.
// FUN_00235020
void datCalcClearFlaggedBuffs(u8 *unit)
{
    DatCalcUnitState *calcState = (DatCalcUnitState *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    u32 i;
    s32 i8;
    u32 mask;

    mask = ((DatCalcUnitState *)unit)->consumedFlags;
    if (mask != 0) {
        for (i = 0; i < 0x18; i++) {
            if (mask & (1 << i)) {
                i8 = i & 0xFF;
                if (i8 >= 0x18) {
                    kAssertFail(D_00635938, 0x4A2);
                }
                if (i8 < 0x10) {
                    datCalcSetBuffLevel((DatUnit *)unit, i, 0);
                    datCalcSetSecondaryBuffLevel((DatUnit *)unit, i, 0);
                }
                ((DatCalcUnitState *)unit)->buffFlags &= ~(1 << i8);
            }
        }
        calcState->consumedFlags = 0;
    }
}

static inline s8 P4CalcLevel(DatUnit *unit, u8 index)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    u16 offset;
    /* Preserve the signed-byte getter conversion at the branch merge. */
    s32 level;
    if ((s32)index >= 24)
        kAssertFail(D_00635938, 0x42A);
    offset = index >> 1;
    if (index & 1)
        level = (s8)(((DatCalcUnitState *)((u8 *)unit + offset))->secondaryLevels[0] >> 4);
    else
        level = (s8)(((DatCalcUnitState *)((u8 *)unit + offset))->secondaryLevels[0] & 15);
    return (s8)level;
}

static inline void P4CalcSetLevel(DatUnit *unit, u8 index, s8 level)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    u16 offset;
    u8 *ptr;
    if ((s32)index >= 24)
        kAssertFail(D_00635938, 0x45E);
    if (level < 0)
        kAssertFail(D_00635938, 0x45F);
    offset = index >> 1;
    if (index & 1) {
        ptr = (u8 *)unit + offset;
        ptr[0x24] = (ptr[0x24] & 15) | ((level & 15) << 4);
    } else {
        ptr = (u8 *)unit + offset;
        ptr[0x24] = (ptr[0x24] & 240) | (level & 15);
    }
}

/* measured: 524B/528B, only one zero-tail word. Signed-byte boundaries and
   per-branch setter addresses preserve the saved offset and retail merges. */
// Intent: raises the secondary level (cap 15) of every active buff in 0..15 by one; [inferred].
// FUN_00235110
void datCalcAdvanceSecondaryBuffs(DatUnit *unit)
{
    s32 checked;
    u32 index;
    s8 active;
    s8 level;
    for (index = 0; index < 16; index++) {
        checked = (u8)index;
        if (checked >= 24)
            kAssertFail(D_00635938, 0x4C1);
        if (checked < 16)
            active = datCalcGetBuffLevel(unit, index % 256U);
        else {
            u8 result = (((DatCalcUnitState *)unit)->buffFlags & (1U << checked)) != 0;
            active = result;
        }
        level = P4CalcLevel(unit, index);
        if (active != 0 && level < 15)
            P4CalcSetLevel(unit, index, level + 1);
    }
}

#pragma push
/* measured: b210 owner profile, 504B/512B, no differing emitted words;
   hoist the signed threshold comparison out of the loop. */
#pragma opt_loop_invariants on
// Intent: index of the first buff level in 0..15 that is active and at or above a threshold (3, doubled for flag-4 units with table bit 0x1000), else -1; [inferred].
// FUN_00235320
s64 datCalcFindStrongBuff(u8 *unit)
{
    DatUnit *unitRecord = (DatUnit *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    s32 checked;
    s8 threshold;
    u32 index;
    s8 active;
    s8 level;
    threshold = 3;
    if (*(u16 *)unit & 4) {
        if (((DatUnit *)unit)->id >= 0x150)
            kAssertFail(D_00635938, 0x6D8);
        if (((DatEnemyUnitInit *)(iGpffffb3c4 + unitRecord->id * 0x3C))->flags & 0x1000)
            threshold *= 2;
    }
    for (index = 0; index < 16; index++) {
        checked = (u8)index;
        if (checked >= 24)
            kAssertFail(D_00635938, 0x4C1);
        if (checked < 16)
            /* Keep the independently narrowed getter argument. */
            active = datCalcGetBuffLevel((DatUnit *)unit, index % 256U);
        else {
            u8 result = (((DatCalcUnitState *)unit)->buffFlags & (1 << checked)) != 0;
            active = result;
        }
        level = P4CalcLevel((DatUnit *)unit, index);
        if (active != 0 && level >= threshold)
            return (s8)index;
    }
    return -1;
}
#pragma pop
/* Equipment queries shared by damage, hit and critical calculations. */
static inline u16 DCHitEquipmentCount(u8 *unit, s32 property)
{
    /* Preserve the byte cursor; fields and measured MEMBER sites retain the retail load behavior. */
    if (*(u16 *)unit & 4) {
        return 0;
    }
    return datCalcCountIdSlotsWithValue(((DatUnit *)unit)->id, property);
}

static inline s32 DC411HasEquipmentProperty(u8 *unit, s32 property)
{
    /* Preserve the byte cursor; fields and measured MEMBER sites retain the retail load behavior. */
    u16 character;

    if (*(u16 *)unit & 4) {
        return 0;
    }
    character = ((DatUnit *)unit)->id;
    if ((s32)character >= 0xB) {
        kAssertFail(D_00635938, 0x23B);
    }
    if ((datItemValue(datGetEquippedItemByUnit((s16)character, 0)) & 0xFFFF) == property) {
        return 1;
    }
    if ((datItemValue(datGetEquippedItemByUnit((s16)character, 1)) & 0xFFFF) == property) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_loop_invariants on
static inline u16 DCDamageAccessoryProperty(DatUnit *unit)
{
    /* Preserve the byte cursor; fields and measured MEMBER sites retain the retail load behavior. */
    s16 character;
    if (*(u16 *)unit & 4) {
        return 0;
    }
    character = (s16)((DatUnit *)((u8 *)unit))->id;
    if (character >= 11) {
        kAssertFail(D_00635938, 0x291);
    }
    return datItemValue(datGetEquippedItemByUnit(character, 2)) & 0xFFFF;
}

static inline f32 DCDamageAccessoryFraction(DatUnit *unit)
{
    /* Preserve the byte cursor; fields and measured MEMBER sites retain the retail load behavior. */
    extern u16 datItemAccessoryPercent(s16 itemId);
    s16 character;
    s32 percent;
    if (*(u16 *)unit & 4) {
        return 0.0f;
    }
    character = (s16)((DatUnit *)((u8 *)unit))->id;
    if (character >= 11) {
        kAssertFail(D_00635938, 0x2A7);
    }
    percent = (s16)datItemAccessoryPercent(datGetEquippedItemByUnit(character, 2));
    if (percent < 0 || percent > 100) {
        kAssertFail(D_00635938, 0x2AB);
    }
    return (f32)percent / 100.0f;
}

static inline s32 DCDamageAddBonus(s32 base, s16 bonus)
{
    return base + bonus;
}

static inline u8 DCDamageSkillKind(u16 skill)
{
    u8 *table = iGpffffb3b8;
    return table[(u32)skill * 0x28 + 2];
}

/* measured: b210 emits all 12176 retail bytes, with all code
 * relocations resolved, and the 17-entry effect table at 00747bc0. The native
 * identifier-list formals keep the caller's promoted integer interface.
 * Unsigned channel dispatch preserves independent signed call conversions;
 * declaring result values after the work value preserves their lifetimes.
 * See docs/probe_archive/DC_worker2_20260920_damage_recovery.md. */
// Intent: signed amount of skill arg0 from actor arg1 on target arg2 for channel arg7 (1 HP, 2 SP): healing positive, damage negative, scaled by effect type, attack/defense, element and accessory bonuses; [inferred].
// FUN_00235520
s32 datCalcSkillAmount(skillId, source, target, hitCount, outcome, hitKind, options, channel)
u16 skillId;
u8 *source;
u8 *target;
u16 hitCount;
u16 outcome;
u16 hitKind;
s32 options;
u8 channel;
{
    DatUnit *sourceRecord = (DatUnit *)source;
    DatUnit *targetRecord = (DatUnit *)target;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    extern s32 datCalcElementBit(s16 element);
    extern f32 iGpffff8170;
    extern f32 fGpffff82c0;
    extern f32 fGpffff82c4;
    extern f32 fGpffff82c8;
    extern f32 fGpffff80bc;
    extern f32 fGpffff82cc;
    extern f32 fGpffff811c;
    extern f32 fGpffff809c;
    s32 checkedSkill;
    f32 attack;
    f32 defense;
    f32 status;
    f32 passive;
    f32 elemental;
    u16 current;
    u16 maximum;
    s32 fixed;
    s16 power;
    u16 effect;
    s16 bonus;
    s32 rawElement;
    s32 element;
    s32 elementMask;
    s32 offset;
    s32 work;
    s32 healing;
    s32 damage;
    u32 targetStatus;
    u8 *record;

    checkedSkill = (u16)skillId;
    if (checkedSkill < 0 || checkedSkill >= 0x240) {
        kAssertFail(D_00635938, 0x711);
    }
    if (checkedSkill >= 0x1B8) {
        kAssertFail(D_00635938, 0x712);
    }
    attack = 1.0f;
    defense = 1.0f;
    status = 1.0f;
    passive = 1.0f;
    healing = 0;
    damage = 0;
    current = 0;
    maximum = 0;
    fixed = 1;
    switch ((u32)channel) {
    case 1:
        record = (u8 *)PTDatCalcOffsetAdd(((u32)skillId % 0x10000U) * 0x28, (u32)iGpffffb3b8);
        power = ((DatSkillEntry *)record)->power;
        effect = ((DatSkillEntry *)record)->effectKind;
        bonus = 0;
        current = ((DatUnit *)target)->hp;
        maximum = datCalcMaxHp((DatUnit *)target);
        break;
    case 2:
        record = (u8 *)PTDatCalcOffsetAdd(((u32)skillId % 0x10000U) * 0x28, (u32)iGpffffb3b8);
        power = ((DatSkillEntry *)record)->spPower;
        effect = ((DatSkillEntry *)record)->spEffectKind;
        bonus = 0;
        current = ((DatUnit *)target)->sp;
        maximum = datCalcMaxSp((DatUnit *)target);
        break;
    default:
        kAssertFail(D_00635938, 0x731);
        break;
    }
    switch (effect) {
    case 0:
        break;
    case 5:
        healing = power + bonus;
        break;
    case 15:
        healing = power;
        if (healing == 0) {
            kAssertFail(D_00635938, 0x17);
        }
        healing = DCDamageAddBonus((s32)(RpRandom() % healing), bonus);
        break;
    case 9:
        healing = DCDamageAddBonus((s32)(current * power / 100), bonus);
        if (healing <= 0) {
            healing = 1;
        }
        break;
    case 11:
        healing = DCDamageAddBonus((s32)(maximum * power / 100), bonus);
        if (healing <= 0) {
            healing = 1;
        }
        break;
    case 2:
        switch (DCDamageSkillKind(skillId)) {
        case 1:
            /* Kind 1 is the PHYSICAL_DAMAGE handler, reused here for healing (dual use, see DatScriptCalcKind). */
            healing = datScriptRunCalc(DAT_SCRIPT_CALC_PHYSICAL_DAMAGE, (u16 *)source, (u16 *)target, skillId, channel);
            break;
        case 2:
            healing = datScriptRunCalc(DAT_SCRIPT_CALC_TERMS_13_AND_1A, (u16 *)source, (u16 *)target, skillId, channel);
            break;
        default:
            kAssertFail(D_00635938, 0x75E);
            break;
        }
        healing += bonus;
        if (healing <= 0) {
            healing = 1;
        }
        fixed = 0;
        break;
    case 7:
        healing = 50;
        healing += bonus;
        if (healing <= 0) {
            healing = 1;
        }
        fixed = 0;
        break;
    case 4:
    case 13:
        damage = power + bonus;
        if (effect == 13 && current < damage) {
            damage = current;
        }
        break;
    case 8:
        damage = DCDamageAddBonus((s32)(current * power / 100), bonus);
        if (damage <= 0 && power > 0) {
            damage = 1;
        }
        break;
    case 10:
        damage = DCDamageAddBonus((s32)(maximum * power / 100), bonus);
        if (damage <= 0 && power > 0) {
            damage = 1;
        }
        break;
    case 1:
    case 12:
    case 14:
        switch (DCDamageSkillKind(skillId)) {
        case 1:
            damage = datScriptRunCalc(DAT_SCRIPT_CALC_PHYSICAL_DAMAGE, (u16 *)source, (u16 *)target, skillId, channel);
            break;
        case 2:
            damage = datScriptRunCalc(DAT_SCRIPT_CALC_MAGIC_DAMAGE, (u16 *)source, (u16 *)target, skillId, channel);
            break;
        default:
            kAssertFail(D_00635938, 0x7A7);
            break;
        }
        damage += bonus;
        switch (effect) {
        case 12:
        case 13:
            if (current < damage) {
                damage = current;
            }
            break;
        }
        if (effect == 14 && hitCount > 1) {
            damage /= hitCount;
        }
        if (damage <= 0) {
            damage = 1;
        }
        fixed = 0;
        break;
    case 6:
        damage = 50;
        damage += bonus;
        if (damage <= 0) {
            damage = 1;
        }
        fixed = 0;
        break;
    case 3:
        if (power + bonus < current) {
            damage = current - (power + bonus);
        }
        break;
    case 16:
        damage = DCDamageAddBonus((s32)datScriptRunCalc(DAT_SCRIPT_CALC_PHYSICAL_DAMAGE_SCALED, (u16 *)source, (u16 *)target, skillId, channel), bonus);
        if (damage <= 0) {
            damage = 1;
        }
        fixed = 0;
        break;
    default:
        kAssertFail(D_00635938, 0x7DE);
        break;
    }
    if (fixed == 0 && damage > 0 && !(options & 1)) {
        rawElement = (s16)datCalcSkillElement((DatUnit *)source, skillId);
        elementMask = datCalcElementBit(rawElement);
        offset = ((u32)skillId % 0x10000U) * 0x28;
        switch (iGpffffb3b8[offset + 2]) {
        case 1:
            if (effect != 16) {
                attack = datCalcBuffMultiplier(source, 0, skillId);
            }
            defense = datCalcBuffMultiplier(target, 3, skillId);
            if (effect != 16) {
                ((DatCalcUnitState *)source)->consumedFlags |= 0x40000;
            }
            break;
        case 2:
            if (effect != 16) {
                attack = datCalcBuffMultiplier(source, 1, skillId);
            }
            defense = datCalcBuffMultiplier(target, 3, skillId);
            if (effect != 16) {
                ((DatCalcUnitState *)source)->consumedFlags |= 0x80000;
            }
            break;
        default:
            kAssertFail(D_00635938, 0x803);
            break;
        }
        element = (s16)rawElement;
        switch (element) {
        case 1:
            elemental = 1.0f;
            if ((DCDamageAccessoryProperty((DatUnit *)source) & 0xFFFF) == 0xBD) {
                elemental *= 1.0f + DCDamageAccessoryFraction((DatUnit *)source);
            }
            if (PTDatCalcHasSkill((DatUnit *)source, 0x1E7) || (DCHitEquipmentCount(source, 0x44) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (PTDatCalcHasSkill((DatUnit *)source, 0x1E8)) {
                elemental *= 1.5f;
            }
            if (elemental > 1.875f) {
                elemental = 1.875f;
            }
            passive *= elemental;
            if (datGetFlag(0x1435)) {
                if (datGetFlag(0x15C5)) {
                    passive *= 2.0f;
                } else {
                    passive *= fGpffff82c4;
                }
            }
            break;
        case 2:
            elemental = 1.0f;
            if ((DCDamageAccessoryProperty((DatUnit *)source) & 0xFFFF) == 0xBE) {
                elemental *= 1.0f + DCDamageAccessoryFraction((DatUnit *)source);
            }
            if (PTDatCalcHasSkill((DatUnit *)source, 0x1E9) || (DCHitEquipmentCount(source, 0x45) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (PTDatCalcHasSkill((DatUnit *)source, 0x1EA)) {
                elemental *= 1.5f;
            }
            if (elemental > 1.875f) {
                elemental = 1.875f;
            }
            passive *= elemental;
            if (datGetFlag(0x1435)) {
                if (datGetFlag(0x15C6)) {
                    passive *= 2.0f;
                } else {
                    passive *= fGpffff82c4;
                }
            }
            break;
        case 3:
            elemental = 1.0f;
            if ((DCDamageAccessoryProperty((DatUnit *)source) & 0xFFFF) == 0xC0) {
                elemental *= 1.0f + DCDamageAccessoryFraction((DatUnit *)source);
            }
            if (PTDatCalcHasSkill((DatUnit *)source, 0x1EB) || (DCHitEquipmentCount(source, 0x46) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (PTDatCalcHasSkill((DatUnit *)source, 0x1EC)) {
                elemental *= 1.5f;
            }
            if (elemental > 1.875f) {
                elemental = 1.875f;
            }
            passive *= elemental;
            if (datGetFlag(0x1435)) {
                if (datGetFlag(0x15C8)) {
                    passive *= 2.0f;
                } else {
                    passive *= fGpffff82c4;
                }
            }
            break;
        case 4:
            elemental = 1.0f;
            if ((DCDamageAccessoryProperty((DatUnit *)source) & 0xFFFF) == 0xBF) {
                elemental *= 1.0f + DCDamageAccessoryFraction((DatUnit *)source);
            }
            if (PTDatCalcHasSkill((DatUnit *)source, 0x1ED) || (DCHitEquipmentCount(source, 0x47) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (PTDatCalcHasSkill((DatUnit *)source, 0x1EE)) {
                elemental *= 1.5f;
            }
            if (elemental > 1.875f) {
                elemental = 1.875f;
            }
            passive *= elemental;
            if (datGetFlag(0x1435)) {
                if (datGetFlag(0x15C7)) {
                    passive *= 2.0f;
                } else {
                    passive *= fGpffff82c4;
                }
            }
            break;
        }
        if (PTDatCalcHasSkill((DatUnit *)target, 0x209)) {
            passive *= 0.5f;
        }
        if (datGetFlag(0x1011)) {
            if (*(u16 *)source & 4) {
                attack *= 1.5f;
            }
        } else if (datGetFlag(0x1010) && (*(u16 *)source & 4)) {
            attack *= iGpffff8170;
        }
        if (hitKind == 2) {
            if (!(*(u16 *)source & 4)) {
                attack *= fGpffff82c8;
            } else {
                attack *= fGpffff80bc;
            }
        }
        if (datCalcIsGuarding((u16 *)target)) {
            defense *= fGpffff82cc;
        }
        targetStatus = ((DatUnit *)target)->bad;
        if ((u8)((targetStatus & 0x100000) != 0)) {
            status *= 1.25f;
        }
        if ((elementMask & 2) && (u8)((((DatUnit *)source)->bad & 0x20) != 0)) {
            status *= 0.5f;
        }
        if ((u8)((((DatUnit *)source)->bad & 2) != 0)) {
            status *= 2.0f;
        }
        if ((u8)((targetStatus & 0x40) != 0)) {
            status *= 1.5f;
        } else if ((u8)((targetStatus & 2) != 0)) {
            status *= 2.0f;
        }
        if (*(u16 *)source & 4) {
            if (((DatUnit *)source)->id >= 0x150) {
                kAssertFail(D_00635938, 0x8C0);
            }
            if (((DatEnemyUnitInit *)(iGpffffb3c4 + sourceRecord->id * 0x3C))->flags & 0x20) {
                attack *= 0.75f;
            }
        }
        switch (iGpffffb3b8[offset + 0x24]) {
        case 3:
            if ((u8)((targetRecord->bad & 0x100000) != 0)) {
                attack *= 2.0f;
            }
            break;
        }
        if (!(*(u16 *)target & 4)) {
            switch (element) {
            case 0:
                if (DC411HasEquipmentProperty(target, 0x5F)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(target, 0x60)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(target, 0x61)) {
                    attack *= fGpffff809c;
                }
                break;
            }
            switch (element) {
            case 1:
            case 2:
            case 3:
            case 4:
                if (DC411HasEquipmentProperty(target, 0x6E)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(target, 0x6F)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(target, 0x70)) {
                    attack *= fGpffff809c;
                }
                break;
            }
            switch (element) {
            case 1:
                if ((DCDamageAccessoryProperty((DatUnit *)target) & 0xFFFF) == 0xC1) {
                    attack *= 1.0f - DCDamageAccessoryFraction((DatUnit *)target);
                }
                if (DC411HasEquipmentProperty(target, 0x62)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(target, 0x63)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(target, 0x64)) {
                    attack *= fGpffff809c;
                }
                break;
            case 2:
                if ((DCDamageAccessoryProperty((DatUnit *)target) & 0xFFFF) == 0xC2) {
                    attack *= 1.0f - DCDamageAccessoryFraction((DatUnit *)target);
                }
                if (DC411HasEquipmentProperty(target, 0x65)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(target, 0x66)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(target, 0x67)) {
                    attack *= fGpffff809c;
                }
                break;
            case 3:
                if ((DCDamageAccessoryProperty((DatUnit *)target) & 0xFFFF) == 0xC4) {
                    attack *= 1.0f - DCDamageAccessoryFraction((DatUnit *)target);
                }
                if (DC411HasEquipmentProperty(target, 0x6B)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(target, 0x6C)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(target, 0x6D)) {
                    attack *= fGpffff809c;
                }
                break;
            case 4:
                if ((DCDamageAccessoryProperty((DatUnit *)target) & 0xFFFF) == 0xC3) {
                    attack *= 1.0f - DCDamageAccessoryFraction((DatUnit *)target);
                }
                if (DC411HasEquipmentProperty(target, 0x68)) {
                    attack *= fGpffff82c0;
                }
                if (DC411HasEquipmentProperty(target, 0x69)) {
                    attack *= fGpffff811c;
                }
                if (DC411HasEquipmentProperty(target, 0x6A)) {
                    attack *= fGpffff809c;
                }
                break;
            }
        }
        work = (s32)(passive * (status * (defense * ((f32)damage * attack))));
        if (hitKind == 16) {
            damage = 500;
        } else {
            if (work > 31000) {
                work = 31000;
            } else if (work <= 0) {
                work = 1;
            }
            damage = (u32)(work * (RpRandom() % 11U + 95U)) / 100U;
        }
        if (damage <= 0) {
            damage = 1;
        }
    }
    if (fixed == 0 && healing > 0 && !(options & 1)) {
        if (PTDatCalcHasSkill((DatUnit *)source, 0x20E)) {
            passive *= 1.5f;
        }
        work = (s32)(passive * (status * (defense * ((f32)healing * attack))));
        if (work > 31000) {
            work = 31000;
        } else if (work <= 0) {
            work = 1;
        }
        healing = (u32)(work * (RpRandom() % 11U + 95U)) / 100U;
        if (healing <= 0) {
            healing = 1;
        }
    }
    if (outcome == 0x400 && damage > 0) {
        healing = damage;
        damage = 0;
    }
    switch (outcome) {
    case 0x100:
    case 2:
    case 4:
        healing = 0;
        damage = 0;
        break;
    }
    if (damage > 0) {
        healing = -damage;
    }
    return healing;
}
#pragma pop


// Intent: signed per-unit roll for kind-6 skill arg0 on unit arg1 (0 unless the table kind is 6): level and battle-stat base times a random 90-110% factor, positive on the monster side; the only caller stores it per slot; [inferred].
// FUN_002384B0
s32 datCalcSkillRoll(s32 skillId, DatUnit *unitArg, s32 targetAddress)
{
    /* measured: retail compiled this caller against the s32-returning
       prototype other units use (see datScript.c), so the u8 return of
       datCalcGetBattleStat is not re-masked here; a block-scope declaration
       reproduces that split inside the merged unit. */
    extern u32 datCalcGetBattleStat(DatUnit *unit, s32 statIndex);
    f32 randomizedAmount;
    f32 luckFloat;
    f32 leadLuckFloat;
    f32 rewardFloat;
    f32 randomFloat;
    f32 moneyFloat;
    f32 levelFloat;
    f32 leadLevelFloat;
    f32 moneyScale;
    f32 amount;
    s32 result;
    u32 money;
    s32 persona;
    u32 luck;
    s32 leadPersona;
    u32 leadLuck;
    u16 unusedValue;
    u16 characterId;
    u16 leadId;
    u32 randomOffset;
    u8 level;
    u8 leadLevel;
    u8 *leadUnit;

    if (iGpffffb3b8[(skillId & 0xFFFF) * 0x28 + 0x24] != 6) {
        return 0;
    }
    if (unitArg != (DatUnit *)targetAddress) {
        kAssertFail(D_00635938, 0x9F9);
    }
    if (!(((DatUnit *)unitArg)->flags & 4)) {
        money = datGetMoney();
        moneyFloat = (f32)money;
        moneyScale = moneyFloat / 20.0f;
        if ((((DatUnit *)unitArg)->flags & 4) || (characterId = ((DatUnit *)unitArg)->id, characterId == 1)) {
            level = ((DatUnit *)unitArg)->level;
        } else {
            persona = (s32)datPersonaGetRecord(characterId);
            if (persona == 0) {
                kAssertFail(D_00635938, 0x58);
            }
            level = datPersonaGetLevel(persona);
        }
        if ((level & 0xFF) <= 0) {
            kAssertFail(D_00635938, 0x5C);
        }
        levelFloat = (f32)level;
        amount = 4.0f + (levelFloat / 5.0f);
        luck = datCalcGetBattleStat(unitArg, PERSONA_STAT_LUC);
        luckFloat = (f32)luck;
        amount = moneyScale / (luckFloat / amount);
    } else {
        leadUnit = datUnitGetRecord(1);
        if ((((DatUnit *)leadUnit)->flags & 4) || (leadId = ((DatUnit *)leadUnit)->id, leadId == 1)) {
            leadLevel = ((DatUnit *)leadUnit)->level;
        } else {
            leadPersona = (s32)datPersonaGetRecord(leadId);
            if (leadPersona == 0) {
                kAssertFail(D_00635938, 0x58);
            }
            leadLevel = datPersonaGetLevel(leadPersona);
        }
        if ((leadLevel & 0xFF) <= 0) {
            kAssertFail(D_00635938, 0x5C);
        }
        leadLevelFloat = (f32)leadLevel;
        amount = 4.0f + (leadLevelFloat / 5.0f);
        leadLuck = datCalcGetBattleStat((DatUnit *)leadUnit, PERSONA_STAT_LUC);
        leadLuckFloat = (f32)leadLuck;
        amount = leadLuckFloat / amount;
        rewardFloat = (f32)datCalcEnemyMoney((u8 *)unitArg);
        amount = amount * rewardFloat;
    }
    randomOffset = RpRandom() % 21U;
    randomFloat = (f32)randomOffset;
    randomizedAmount = amount * (((100.0f + randomFloat) - 10.0f) / 100.0f);
    result = (s32)randomizedAmount;
    if (result == 0) {
        result = 1;
    }
    if (((DatUnit *)unitArg)->flags & 4) {
        return result;
    }
    return -result;
}

/* C89 promotes the u16 body parameter to the explicit s32 interface above.
 * Conversion belongs to this callee; the five dynamic callers pass the full
 * word. Unsigned table indexing keeps its mask distinct from validation.
 * measured: b210 -O2, 3728/3728 bytes, with both real u16 query consumers.
 * The bounded choices array and skill/equipment scans preserve P4 status bits. */
// Intent: status-infliction roll for skill arg0 from source arg1 on target arg2: picks the skill's status bits (one at random when the row mode is 3), gates them on the target, applies resistance and source-side bonuses unless options bit 1 is set, rolls the chance, and returns the landed bits (0 when resisted or missed; 0x80000 death may be cancelled by a survive flag); [inferred].
// FUN_00238940
#pragma push
#pragma opt_loop_invariants on
s32 datCalcInflictStatus(skillId, source, target, options)
u16 skillId;
DatUnit *source;
DatUnit *target;
s32 options;
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    u16 choices[24];
    s32 offset;
    u8 *entry;
    u8 mode;
    u8 kind;
    u32 statuses;
    s32 success;
    s32 index;
    s32 count;
    u32 choiceCount;
    s32 resistance;
    u32 percentage;
    f32 multiplier;
    f32 percent;
    f32 chance;
    s32 death;
    s32 rate;
    s32 element;
    u8 active;
    s16 message;
    extern s32 datCalcIsGuarding(u16 *unitFlags);
    extern s32 datCalcStatusElement(s32 skillId, s32 statusMask);

    if ((skillId & 0xFFFF) >= 0x240) {
        kAssertFail(D_00635938, 0xA30);
    }
    offset = (u32)(u16)skillId * 0x28;
    entry = (u8 *)((u32)offset + (u32)iGpffffb3b8);
    if (entry[0x24] == 13) {
        return 0x80000;
    }
    multiplier = 1.0f;
    success = 0;
    statuses = ((DatSkillEntry *)(entry))->statusMask & 0xFFFFFFU;
    if (entry[0x18] == 3) {
        count = 0;
        index = 0;
        while ((index & 0xFFFF) < 24) {
            if (statuses & (1U << (index & 0xFFFF))) {
                choices[count & 0xFFFF] = index;
                count = (count + 1) & 0xFFFF;
            }
            index = (index + 1) & 0xFFFF;
        }
        choiceCount = count & 0xFFFF;
        if (choiceCount == 0) {
            kAssertFail(D_00635938, 0x17);
        }
        statuses = 1U << choices[RpRandom() % choiceCount];
    }
    if (statuses != 0 &&
        ((entry = iGpffffb3b8, mode = *(u8 *)PTDatCalcOffsetAdd((u32)entry + 0x18U, (u32)offset), mode == 1) || mode == 3)) {
        switch (entry[offset + 0x24]) {
        case 14: {
            if ((u8)(((u8 *)target)[0xC] != 0)) {
                goto return_status_0;
            }
            goto return_zero_0;
return_status_0:
            return (s32)statuses;
return_zero_0:
            return 0;
        }
        default:
            break;
        }
        if (datCalcIsGuarding((u16 *)target)) {
            return 0;
        }
        kind = iGpffffb3b8[offset + 0x24];
        switch (kind) {
        case 1:
            if ((u8)((((DatUnit *)target)->bad & 4) != 0)) {
                return (s32)statuses;
            }
            break;
        case 7:
            if (((DatUnit *)target)->flags & 0x1000) {
                statuses = 0;
            }
            return (s32)statuses;
        case 8:
            switch (((DatUnit *)target)->flags & 0x1000) {
            case 0:
                statuses = 0;
                break;
            default:
                break;
            }
            return (s32)statuses;
        case 9:
            if ((u8)((((DatUnit *)target)->bad & 1) != 0)) {
                goto return_status_1;
            }
            goto return_zero_1;
return_status_1:
            return (s32)statuses;
return_zero_1:
            return 0;
        default:
            break;
        }
        resistance = datCalcGetAffinity((u8 *)target, (s16)datCalcStatusElement((s16)skillId, (s32)statuses));
        if (resistance & 0x27000000) {
            return 0;
        }
        if (statuses & 0x100000) {
            if ((u8)((((DatUnit *)target)->bad & 0x100000) != 0)) {
                return 0;
            }
            if (((DatUnit *)target)->flags & 8) {
                return 0;
            }
        }
        percentage = resistance & 0xFFFF;
        percent = (f32)percentage;
        multiplier = multiplier * (percent / 100.0f);
        if (!(options & 1)) {
            death = statuses & 0x80000;
            if (death == 0 && datCalcGetBuffLevel(target, 7) > 0) {
                multiplier *= 2.0f;
            }
            element = (s16)datCalcSkillElement(source, skillId);
            switch (element) {
            case 9:
                if (PTDatCalcHasSkill(source, 0x217)) multiplier *= 1.25f;
                break;
            case 8:
                if (PTDatCalcHasSkill(source, 0x216)) multiplier *= 1.25f;
                break;
            case 10:
                if (PTDatCalcHasSkill(source, 0x21A)) multiplier *= 1.25f;
                break;
            case 6:
                if (PTDatCalcHasSkill(source, 0x21F)) multiplier *= 1.25f;
                break;
            case 7:
                if (PTDatCalcHasSkill(source, 0x220)) multiplier *= 1.25f;
                break;
            case 13:
                if (PTDatCalcHasSkill(source, 0x218)) multiplier *= 1.25f;
                break;
            case 15:
                if (PTDatCalcHasSkill(source, 0x219)) multiplier *= 1.25f;
                break;
            case 11:
                if (PTDatCalcHasSkill(source, 0x21B)) multiplier *= 1.25f;
                break;
            case 14:
                if (PTDatCalcHasSkill(source, 0x21D)) multiplier *= 1.25f;
                break;
            }
            if (death == 0 && PTDatCalcHasSkill(source, 0x21E)) {
                multiplier *= 1.25f;
            }
        }
    }
    if (statuses == 0) {
        return 0;
    }
    if ((s32)iGpffffb3b8[offset + 0x19] >= 100) {
        success = 1;
    } else {
        chance = (f32)datScriptRunCalc(DAT_SCRIPT_CALC_RATIO_OF_PRODUCTS, (u16 *)(source), (u16 *)(target), skillId, (s32)statuses);
        chance = chance * multiplier;
        rate = (s32)chance;
        if (rate > 99) {
            rate = 99;
        } else if (rate < 0) {
            rate = 0;
        }
        if ((s32)(RpRandom() % 100U) < rate) {
            success = 1;
        }
    }
    if (success != 0 && (statuses & 0x80000) != 0 &&
        (s8)(active = (((DatCalcUnitState *)target)->buffFlags & 0x800000) != 0) > 0) {
        statuses &= ~0x80000U;
        if (((DatUnit *)target)->flags & 4) {
            message = 0x79;
        } else {
            message = 0x78;
        }
        ((DatCalcUnitState *)target)->message = message;
        ((DatCalcUnitState *)target)->consumedFlags |= 0x800000;
    }
    switch (success) {
    case 0:
        statuses = 0;
        break;
    default:
        break;
    }
    return (s32)statuses;
}
#pragma pop
// Intent: status-effect result for skill arg0 from actor arg1 on target arg2: 0x80000 for the special kind, a hit-formula result for ailment-type skills, else 0; [inferred].
// FUN_002397D0
u32 datCalcStatusEffectResult(s32 skillId, DatUnit *source, DatUnit *target, s32 channel, s32 unusedOutcome, s32 options)
{
    s16 characterId;
    s32 property;
    s32 equipmentProperty;
    u8 mode;
    u32 statuses;
    s32 off;
    u8 *skillEntry;

    if ((u16)skillId >= 0x1B8) {
        kAssertFail(D_00635938, 0xB1D);
    }
    off = (skillId & 0xFFFF) * 0x28;
    skillEntry = (u8 *)(off + (s32)iGpffffb3b8);
    if (skillEntry[0x24] == 0xD) {
        return 0x80000U;
    }
    if ((channel & 0xFFFF) != 1) {
        return 0U;
    }
    mode = skillEntry[0x18];
    if ((mode != 1) && (mode != 3)) {
        if ((datCalcUsesWeaponProperties(skillId) != 0) &&
            (((u64)((s64)((s32)((DatUnit *)target)->bad) << 0x2C) >> 0x2C) == 0)) {
            if (((DatUnit *)source)->flags & 4) {
                equipmentProperty = 0;
            } else {
                characterId = (s16)((DatUnit *)source)->id;
                if (characterId >= 0xB) {
                    kAssertFail(D_00635938, 0x291);
                }
                equipmentProperty = datItemValue(datGetEquippedItemByUnit(characterId, 0)) & 0xFFFF;
            }
            property = equipmentProperty & 0xFFFF;
            switch (property) {
            case 0x24:
                return datCalcInflictStatus(0x190, source, target, options);
            case 0x25:
                return datCalcInflictStatus(0x191, source, target, options);
            case 0x26:
                return datCalcInflictStatus(0x192, source, target, options);
            case 0x27:
                return datCalcInflictStatus(0x193, source, target, options);
            case 0x28:
                return datCalcInflictStatus(0x194, source, target, options);
            case 0x29:
                return datCalcInflictStatus(0x195, source, target, options);
            case 0x2A:
                return datCalcInflictStatus(0x196, source, target, options);
            case 0x2B:
                return datCalcInflictStatus(0x197, source, target, options);
            case 0x2C:
                return datCalcInflictStatus(0x198, source, target, options);
            case 0x2D:
                return datCalcInflictStatus(0x199, source, target, options);
            case 0x2E:
                return datCalcInflictStatus(0x19A, source, target, options);
            case 0x2F:
                return datCalcInflictStatus(0x19B, source, target, options);
            case 0x30:
                return datCalcInflictStatus(0x19C, source, target, options);
            case 0x31:
                return datCalcInflictStatus(0x19D, source, target, options);
            case 0x32:
                return datCalcInflictStatus(0x19E, source, target, options);
            case 0x33:
                return datCalcInflictStatus(0x19F, source, target, options);
            case 0x34:
                return datCalcInflictStatus(0x1A0, source, target, options);
            case 0x35:
                return datCalcInflictStatus(0x1A1, source, target, options);
            case 0x36:
                return datCalcInflictStatus(0x1A2, source, target, options);
            case 0x37:
                return datCalcInflictStatus(0x1A3, source, target, options);
            case 0x38:
                return datCalcInflictStatus(0x1A4, source, target, options);
            case 0x39:
                return datCalcInflictStatus(0x1A5, source, target, options);
            case 0x3A:
                return datCalcInflictStatus(0x1A6, source, target, options);
            case 0x3B:
                return datCalcInflictStatus(0x1A7, source, target, options);
            case 0x5C:
                return datCalcInflictStatus(0x1A8, source, target, options);
            case 0x5D:
                return datCalcInflictStatus(0x1A9, source, target, options);
            case 0x5E:
                return datCalcInflictStatus(0x1AA, source, target, options);
            }
            goto zero;
        }
zero:
        statuses = 0;
    } else {
        statuses = datCalcInflictStatus(skillId, source, target, options);
        if ((((u64)((s64)((s32)((DatUnit *)target)->bad) << 0x2C) >> 0x2C) != 0) && !(statuses & 0x180000)) {
            statuses = 0;
        }
    }
    return statuses;
}

// Intent: hit-formula result for skill arg0 when its table kind is 2 and its guard byte is 100 (a sure hit); 0 otherwise; [inferred].
// FUN_00239E40
s32 datCalcSureHitResult(s32 skillId, DatUnit *source, DatUnit *target, s32 channel, s32 unusedOutcome, s32 options)
{
    u8 *skillEntry;
    s32 off;

    if ((u16)skillId >= 0x1B8) {
        kAssertFail(D_00635938, 0xB94);
    }
    if ((channel & 0xFFFF) != 1) {
        return 0;
    }
    off = (skillId & 0xFFFF) * 0x28;
    skillEntry = (u8 *)(off + (s32)iGpffffb3b8);
    if (skillEntry[0x18] != 2) {
        return 0;
    }
    if ((s32)skillEntry[0x19] < 0x64) {
        kAssertFail(D_00635938, 0xB9F);
    }
    return datCalcInflictStatus(skillId, source, target, options);
}

// Intent: apply skill arg0 from actor arg1 to target arg2: HP and SP deltas (clamped to the unit's max), status bits into the unit word at +0xC, dead at 0 HP; returns 1 [inferred].
// FUN_00239F50
s32 datCalcApplySkillEffect(s32 skillId, u8 *source, u8 *target, s32 options)
{
    DatUnit *targetRecord = (DatUnit *)(target);
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    s32 hpDelta;
    u32 statuses;
    s32 result;

    if (source != NULL && target != NULL) {
        hpDelta = datCalcSkillAmount(skillId, source, target, 1, 1, 1, options, 1);
        options = datCalcSkillAmount(skillId, source, target, 1, 1, 1, options, 2);
        statuses = datCalcStatusEffectResult(skillId, (DatUnit *)source, (DatUnit *)target, 1, 1, 0);
        if ((u16)skillId >= 0x1B8) {
            kAssertFail(D_00635938, 0xB94);
        }
        if (iGpffffb3b8[(skillId & 0xFFFF) * 0x28 + 0x18] != 2) {
            result = 0;
        } else {
            if ((s32)iGpffffb3b8[(skillId & 0xFFFF) * 0x28 + 0x19] < 0x64) {
                kAssertFail(D_00635938, 0xB9F);
            }
            result = datCalcInflictStatus(skillId, (DatUnit *)source, (DatUnit *)target, 0);
        }
        if (hpDelta == 0 && options == 0 && statuses == 0 && result == 0) {
            return 0;
        }
        if ((((u64)statuses << 0x2C) >> 0x2C) != 0) {
            ((DatUnit *)target)->bad = (((DatUnit *)target)->bad & 0xFFF00000) | (statuses & 0xFFFFF);
        }
        ((DatUnit *)target)->bad |= statuses & 0xFFF00000;
        ((DatUnit *)target)->bad &= ~result;
        if (options != 0) {
            options = (u32)targetRecord->sp + (u32)options;
            if (options < 0) {
                options = 0;
            }
            result = datCalcMaxSp((DatUnit *)target) & 0xFFFF;
            if (result < options) {
                options = result;
            }
            ((DatUnit *)target)->sp = options;
        }
        if (hpDelta != 0) {
            options = ((DatUnit *)target)->hp + hpDelta;
            if (options < 0) {
                options = 0;
            }
            result = datCalcMaxHp((DatUnit *)target) & 0xFFFF;
            if (result < options) {
                options = result;
            }
            ((DatUnit *)target)->hp = options;
            if (((DatUnit *)target)->hp == 0) {
                ((DatUnit *)target)->bad = (((DatUnit *)target)->bad & 0xFFF00000) | 0x80000;
            }
        }
    }
    return 1;
}





// Intent: effect flag mask (1 HP, 2 SP, 4 status) for skill arg0 from actor arg1 on target arg2; 0 when the hit misses, 0xFFFF for a full effect; [inferred].
// FUN_0023A1E0
s32 datCalcSkillEffectFlags(s32 skillId, DatUnit *source, DatUnit *target, s32 options)
{
    s32 hpDelta;
    s32 spDelta;
    s32 statuses;
    s32 flags;
    s32 result;
    s32 status;
    s32 high;
    u32 hit;
    u16 currentSp;
    u16 currentHp;

    flags = 0;
    if (source != NULL && target != NULL) {
        hpDelta = datCalcSkillAmount(skillId, (u8 *)source, (u8 *)target, 1, 1, 1, options, 1);
        spDelta = datCalcSkillAmount(skillId, (u8 *)source, (u8 *)target, 1, 1, 1, options, 2);
        statuses = datCalcStatusEffectResult(skillId, source, target, 1, 1, 0);
        if ((u16)skillId >= 0x1B8) {
            kAssertFail(D_00635938, 0xB94);
        }
        if (iGpffffb3b8[(skillId & 0xFFFF) * 0x28 + 0x18] != 2) {
            result = 0;
        } else {
            if ((s32)iGpffffb3b8[(skillId & 0xFFFF) * 0x28 + 0x19] < 0x64) {
                kAssertFail(D_00635938, 0xB9F);
            }
            result = datCalcInflictStatus(skillId, source, target, 0);
        }
        ((DatCalcUnitState *)source)->consumedFlags = 0;
        ((DatCalcUnitState *)target)->consumedFlags = 0;
        status = (s32)((DatUnit *)target)->bad;
        high = ((status & 0x80000) != 0);
        if (hpDelta == 0 && spDelta == 0 && statuses == 0 && result == 0) {
            flags |= 0xFFFF;
        }
        if (result == 0) {
            goto check_status;
        }
        hit = ((status & result) != 0);
        if (hit != 0) {
            goto return_zero_status;
        }
        flags |= 4;
        goto check_result_high;
return_zero_status:
        return 0;
check_result_high:
        if ((result & 0x80000) == 0) {
            goto check_status;
        }
        if ((flags & 4) == 0) {
            goto check_status;
        }
        goto return_flags_status;
return_flags_status:
        return flags;
check_status:
        if (high == 0) {
            if (spDelta > 0) {
                currentSp = ((DatUnit *)target)->sp;
                if ((s32)(datCalcMaxSp(target) & 0xFFFF) > (s32)currentSp) {
                    goto return_zero_sp;
                }
                flags |= 2;
                goto check_hp;
return_zero_sp:
                return 0;
            }
check_hp:
            if (hpDelta > 0) {
                currentHp = ((DatUnit *)target)->hp;
                if ((s32)(datCalcMaxHp(target) & 0xFFFF) > (s32)currentHp) {
                    goto return_zero_hp;
                }
                flags |= 1;
                goto done;
return_zero_hp:
                return 0;
            }
            goto done;
        }
        return 0xFFFF;
    }
done:
    return flags;
}

// Intent: fills HP amount (*arg4), SP amount (*arg5) and infliction outcome (*arg6) for skill arg0 from source arg1 to target arg2, and clears their +0x18 fields; returns 0 if either unit is null; [inferred].
// FUN_0023A490
s32 datCalcSkillOutcome(s32 skillId, DatUnit *source, DatUnit *target, s32 options, s32 *hpAmount, s32 *spAmount, s32 *statusResult)
{
    s32 statuses;

    if (source != NULL && target != NULL) {
        if (hpAmount != NULL) {
            *hpAmount = datCalcSkillAmount(skillId, (u8 *)source, (u8 *)target, 1, 1, 1, options, 1);
        }
        if (spAmount != NULL) {
            *spAmount = datCalcSkillAmount(skillId, (u8 *)source, (u8 *)target, 1, 1, 1, options, 2);
        }
        if (statusResult != NULL) {
            if ((u16)skillId >= 0x1B8) {
                kAssertFail(D_00635938, 0xB94);
            }
            if (iGpffffb3b8[(skillId & 0xFFFF) * 0x28 + 0x18] != 2) {
                statuses = 0;
            } else {
                if ((s32)iGpffffb3b8[(skillId & 0xFFFF) * 0x28 + 0x19] < 0x64) {
                    kAssertFail(D_00635938, 0xB9F);
                }
                statuses = datCalcInflictStatus(skillId, source, target, 0);
            }
            *statusResult = statuses;
        }
        ((DatCalcUnitState *)source)->consumedFlags = 0;
        ((DatCalcUnitState *)target)->consumedFlags = 0;
        return 1;
    }
    return 0;
}

// Intent: skill-slot value from packed table entry arg1 (scaled x5 per byte, with fallback constants when the low half is zero); [inferred].
// FUN_0023A620
s32 datCalcSkillSlotValue(s32 unusedUnit, u16 packedValue)
{
    s32 packed = packedValue & 0xFFFF;
    s32 affinity = ((u32)(packed & 0xFF00) << 0x10) | ((packed & 0xFFFF00FF) * 5);
    if (!(affinity & 0xFFFF)) {
        if (affinity & 0x08000000) {
            affinity |= 0x7D;
        } else if (affinity & 0x27000000) {
            affinity |= 0x64;
        } else if (affinity & 0x10000000) {
            affinity |= 0x32;
        }
    }
    return affinity;
}
/* Base persona resistance and unit-type query. */
extern u8 *iGpffffb3c8;
extern u32 datPersonaGetSkillSlot(u16 partyId, s32 slotIndex);
extern s32 datCalcIsGuarding(u16 *unitFlags);

#pragma push
#pragma opt_loop_invariants on
// Intent: resistance and nullify flags of unit arg0 against status element arg1; callers test the 0x08000000 and 0x07000000 groups; [inferred].
// FUN_0023A6B0
s32 datCalcGetAffinity(u8 *unit, s32 elementIndex)
{
    DatUnit *unitRecord = (DatUnit *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    s32 element;
    s32 found;
    u32 affinity;
    u32 passiveFlags;
    s32 guarding;
    s32 clearResistance;
    s32 grantResistance;
    u16 raw;
    u32 high;
    u32 low;

    passiveFlags = 0;
    grantResistance = 0;
    clearResistance = 0;
    guarding = 0;
    element = (s16)elementIndex;
    switch (element) {
    case -1:
        return 0;
    case 0x10:
    case 0x11:
    case 0x12:
        return 100;
    }
    if (unit == 0) {
        kAssertFail(D_00635938, 0xCC1);
    }
    if (element >= 0x13 || element < 0) {
        kAssertFail(D_00635938, 0xCC2);
    }
    if ((*(u16 *)unit & 4) == 0) {
        affinity = datPersonaGetSkillSlot(((DatUnit *)unit)->id, (u16)elementIndex);
    } else {
        if (((DatUnit *)unit)->id2 >= 0x150) {
            kAssertFail(D_00635938, 0xCCD);
        }
        raw = ((u16 *)(iGpffffb3c8 + unitRecord->id2 * 0x20))[element];
        high = (u32)(raw & 0xFF00) << 16;
        low = (raw & 0xFFFF00FF) * 5;
        affinity = high | low;
        if ((affinity & 0xFFFF) == 0) {
            if ((affinity & 0x8000000) != 0) {
                affinity |= 0x7D;
            } else if ((affinity & 0x27000000) != 0) {
                affinity |= 100;
            } else if ((affinity & 0x10000000) != 0) {
                affinity |= 0x32;
            }
        }
    }
    if (datCalcIsGuarding((u16 *)unit) != 0) {
        guarding = 1;
    }
    switch (element) {
    case 0:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1B8);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1B9);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1BA);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1BB);
        if (found != 0) {
            passiveFlags |= 0x4000000;
        }
        break;
    }
    switch (element) {
    case 1:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1BC);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1BD);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1BE);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1BF);
        if (found != 0) {
            passiveFlags |= 0x4000000;
        }
        if (datCalcGetBuffLevel((DatUnit *)unit, 8) > 0) {
            clearResistance = 1;
        }
        if (datCalcGetBuffLevel((DatUnit *)unit, 0xC) > 0) {
            grantResistance = 1;
        }
        break;
    case 2:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C0);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C1);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C2);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C3);
        if (found != 0) {
            passiveFlags |= 0x4000000;
        }
        if (datCalcGetBuffLevel((DatUnit *)unit, 9) > 0) {
            clearResistance = 1;
        }
        if (datCalcGetBuffLevel((DatUnit *)unit, 0xD) > 0) {
            grantResistance = 1;
        }
        break;
    case 3:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C4);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C5);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C6);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C7);
        if (found != 0) {
            passiveFlags |= 0x4000000;
        }
        if (datCalcGetBuffLevel((DatUnit *)unit, 11) > 0) {
            clearResistance = 1;
        }
        if (datCalcGetBuffLevel((DatUnit *)unit, 0xE) > 0) {
            grantResistance = 1;
        }
        break;
    case 4:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C8);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1C9);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1CA);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1CB);
        if (found != 0) {
            passiveFlags |= 0x4000000;
        }
        if (datCalcGetBuffLevel((DatUnit *)unit, 10) > 0) {
            clearResistance = 1;
        }
        if (datCalcGetBuffLevel((DatUnit *)unit, 0xF) > 0) {
            grantResistance = 1;
        }
        break;
    case 6:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1CC);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1CD);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1CE);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        break;
    case 7:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1CF);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D0);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D1);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        break;
    case 9:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x225);
        if (found != 0) {
            goto acc_9_b;
        }
        found = DC411HasEquipmentProperty(unit, 0x4C);
        if (found == 0) {
            goto skp_9_b;
        }
acc_9_b:
        passiveFlags |= 0x10000000;
skp_9_b:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D7);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 8:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x226);
        if (found != 0) {
            goto acc_8_b;
        }
        found = DC411HasEquipmentProperty(unit, 0x4B);
        if (found == 0) {
            goto skp_8_b;
        }
acc_8_b:
        passiveFlags |= 0x10000000;
skp_8_b:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D2);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 10:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x227);
        if (found != 0) {
            goto acc_10_b;
        }
        found = DC411HasEquipmentProperty(unit, 0x4D);
        if (found == 0) {
            goto skp_10_b;
        }
acc_10_b:
        passiveFlags |= 0x10000000;
skp_10_b:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D5);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 13:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x228);
        if (found != 0) {
            goto acc_13_b;
        }
        found = DC411HasEquipmentProperty(unit, 0x50);
        if (found == 0) {
            goto skp_13_b;
        }
acc_13_b:
        passiveFlags |= 0x10000000;
skp_13_b:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D3);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 15:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x22C);
        if (found != 0) {
            goto acc_15_b;
        }
        found = DC411HasEquipmentProperty(unit, 0x52);
        if (found == 0) {
            goto skp_15_b;
        }
acc_15_b:
        passiveFlags |= 0x10000000;
skp_15_b:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D4);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 11:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x22A);
        if (found != 0) {
            goto acc_11_b;
        }
        found = DC411HasEquipmentProperty(unit, 0x4E);
        if (found == 0) {
            goto skp_11_b;
        }
acc_11_b:
        passiveFlags |= 0x10000000;
skp_11_b:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D6);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 14:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x229);
        if (found != 0) {
            goto acc_14_b;
        }
        found = DC411HasEquipmentProperty(unit, 0x51);
        if (found == 0) {
            goto skp_14_b;
        }
acc_14_b:
        passiveFlags |= 0x10000000;
skp_14_b:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D9);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 12:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x22B);
        if (found != 0) {
            goto acc_12_b;
        }
        found = DC411HasEquipmentProperty(unit, 0x4F);
        if (found == 0) {
            goto skp_12_b;
        }
acc_12_b:
        passiveFlags |= 0x10000000;
skp_12_b:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1D8);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 0:
        break;
    case 5:
        break;
    }
    switch (element) {
    case 8:
    case 10:
    case 0xF:
    case 0xB:
    case 0xE:
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1DA);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    }
    if (element != 5) {
        found = PTDatCalcHasSkill((DatUnit *)unit, 0x1DB);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
    }
    if (guarding == 1 && (affinity & 0x8000000) != 0) {
        affinity = (affinity & 0xF7FF0000) | 100;
    }
    if (passiveFlags != 0) {
        if ((passiveFlags & 0x10000000) != 0 && (affinity & 0x7000000) == 0) {
            affinity = (((affinity & 0xF7FFFFFF) | 0x10000000) & 0xFFFF0000) | 0x32;
        }
        if ((passiveFlags & 0x1000000) != 0 && (affinity & 0x6000000) == 0) {
            affinity = (((affinity & 0xE7FFFFFF) | 0x1000000) & 0xFFFF0000) | 0x64;
        }
        if ((passiveFlags & 0x2000000) != 0 && (affinity & 0x4000000) == 0) {
            affinity = (((affinity & 0xE6FFFFFF) | 0x2000000) & 0xFFFF0000) | 0x64;
        }
        if ((passiveFlags & 0x4000000) != 0) {
            affinity = (((affinity & 0xE4FFFFFF) | 0x4000000) & 0xFFFF0000) | 0x64;
        }
    }
    if (clearResistance != 0 && (affinity & 0x17000000) != 0) {
        affinity = (affinity & 0xE8FF0000) | 100;
    }
    if (grantResistance != 0 && ((affinity & 0x8000000) != 0 || (affinity & 0xFF000000) == 0)) {
        affinity = (((affinity & 0xFFFFFF) | 0x10000000) & 0xFFFF0000) | 0x32;
    }
    return (s32)affinity;
}
#pragma pop

// Intent: element bit (1 << (index+1)) for element index arg0 (0..0x12); callers mask it against the element and status sets; [inferred].
// FUN_0023D6E0
s32 datCalcElementBit(s16 element)
{
    if (element >= 0x13) {
        kAssertFail(D_00635938, 0xE47);
    }
    return 1 << (element + 1);
}




// Intent: element index that status bit arg1 counts as for skill arg0 (a skill of element 6 always gives 6); used for the resistance lookup; [inferred].
// FUN_0023D740
s32 datCalcStatusElement(s32 skillId, s32 statusMask)
{
    s32 element;

    if ((s16)skillId != -1) {
        element = (s16)datCalcSkillElement(NULL, skillId & 0xFFFF);
        if (element == 6) {
            return 6;
        }
    }
    switch (statusMask) {
    case 0x2:
        element = 0xB;
        break;
    case 0x4:
        element = 0xA;
        break;
    case 0x8:
        element = 0xF;
        break;
    case 0x10:
        element = 8;
        break;
    case 0x1:
        element = 0xC;
        break;
    case 0x20:
        element = 9;
        break;
    case 0x40:
        element = 0xD;
        break;
    case 0x80:
        element = 0xE;
        break;
    case 0x100:
        element = 5;
        break;
    case 0x80000:
        element = 7;
        break;
    case 0x100000:
        element = 5;
        break;
    default:
        kAssertFail(D_00635938, 0xE82);
        break;
    }
    return element;
}

// Intent: element index of skill arg1 on unit arg0: the monster row's byte, or the persona stat, or the skill-table byte for non-unit skills; callers pass it to datCalcElementBit; [inferred].
// FUN_0023D8E0
s32 datCalcSkillElement(DatUnit *unit, u16 skillId)
{
    s32 v;

    if (unit != 0 && (skillId & 0xFFFF) < 0x1B8 &&
        (((DatSkillEntry *)(iGpffffb3b8 + ((skillId & 0xFFFF)) * 0x28))->flags00 & 2)) {
        if (((DatUnit *)unit)->flags & 4) {
            v = iGpffffb3c4[((DatUnit *)unit)->id * 0x3C + 0x38];
        } else {
            v = (s16)datItemElement((s16)((u16)datGetEquippedItemByUnit((s16)((DatUnit *)unit)->id, 0) & 0xFFFF));
        }
    } else {
        v = (s8)iGpffffb3b4[(skillId & 0xFFFF) * 2];
    }
    return v;
}
/* measured: 992B / 992B, 24 resolved relocations, no instruction differences.
   The ordered optimizer scopes and materialized offsets/loop operands retain
   the fresh 16-bit masks and retail register ordering. The equipment guard
   tests a zero-extended value; percentage products wrap to 32 bits before
   signed division, while cost reduction remains an unsigned shift. */
// Intent: SP cost of skill arg1 for unit arg0, after equipment reduction and the cost limit; [inferred].
// FUN_0023D9B0
#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants on
#pragma opt_propagation off
u32 datCalcSkillCost(DatUnit *unit, s32 skillId)
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    s32 offset;
    u32 result;
    u16 count;
    u16 index;
    u16 maximum;
    u8 *table;
    s32 product;
    s32 equipment;
    s32 hit;
    s32 entry;
    s32 reduction;
    s32 limit;
    u32 field_offset;

    if ((s32)(u16)skillId >= 0x1B8) {
        kAssertFail(D_00635938, 0xEB4);
    }
    result = 0;
    offset = (u16)skillId * 0x28;
    switch (((DatSkillEntry *)(offset + (u32)iGpffffb3b8))->kind03) {
    case 1:
        if (unit->flags & 4) {
            if (unit->id >= 0x150) {
                kAssertFail(D_00635938, 0xEBE);
            }
            return 0;
        }
        maximum = datCalcMaxHp(unit);
        field_offset = (u16)skillId * 0x28;
        table = (u8 *)(field_offset + (u32)iGpffffb3b8);
        product = (s32)((u32)maximum * ((DatSkillEntry *)(table))->costPercent);
        result = product / 100 + ((DatSkillEntry *)(table))->costFlat;
        count = (u16)datCalcGetTableLength(unit);
        table = datCalcSkillList(unit);
        index = 0;
        limit = count;
        reduction = 0x20B;
        while (index < limit) {
            entry = ((u16 *)(table))[index];
            if (entry == reduction) {
                hit = 1;
                goto hp_reduction;
            }
            index++;
        }
        if ((unit->flags & 4) == 0) {
            equipment = (u16)datGetEquippedItemByUnit((s16)unit->id, 2);
            if (equipment >= 0) {
                if (datItemGrantedSkill((s16)equipment) == 0x20B) {
                    hit = 1;
                    goto hp_reduction;
                }
            }
        }
        hit = 0;
    hp_reduction:
        if (hit != 0) result >>= 1;
        if (result == 0) result = 1;
        break;
    case 2:
        if (unit->flags & 4) {
            if (unit->id >= 0x150) {
                kAssertFail(D_00635938, 0xED7);
            }
            if (((DatEnemyUnitInit *)(iGpffffb3c4 + unit->id * 0x3C))->flags & 2) {
                return 0;
            }
        }
        table = iGpffffb3b8;
        if ((((DatSkillEntry *)(table + offset))->flags00 & 0x10) == 0) {
            field_offset = (u16)skillId * 0x28;
            table = (u8 *)(field_offset + (u32)table);
            result = ((DatSkillEntry *)(table))->costPercent + ((DatSkillEntry *)(table))->costFlat;
        } else {
            maximum = datCalcMaxSp(unit);
            field_offset = (u16)skillId * 0x28;
            table = (u8 *)(field_offset + (u32)iGpffffb3b8);
            product = (s32)((u32)maximum * ((DatSkillEntry *)(table))->costPercent);
            result = product / 100 + ((DatSkillEntry *)(table))->costFlat;
        }
        if (result == 0) break;
        count = (u16)datCalcGetTableLength(unit);
        table = datCalcSkillList(unit);
        index = 0;
        limit = count;
        reduction = 0x20A;
        while (index < limit) {
            entry = ((u16 *)(table))[index];
            if (entry == reduction) {
                hit = 1;
                goto sp_reduction;
            }
            index++;
        }
        if ((unit->flags & 4) == 0) {
            equipment = (u16)datGetEquippedItemByUnit((s16)unit->id, 2);
            if (equipment >= 0) {
                if (datItemGrantedSkill((s16)equipment) == 0x20A) {
                    hit = 1;
                    goto sp_reduction;
                }
            }
        }
        hit = 0;
    sp_reduction:
        if (hit != 0) result >>= 1;
        if (result == 0) result = 1;
        break;
    }
    return result;
}
#pragma pop
// Intent: threshold kind byte of skill arg1 from the skill table (1 = HP, 2 = SP); [inferred].
// FUN_0023DD90
u16 datCalcThresholdKind(DatUnit *unusedUnit, s32 skillId)
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    DatSkillEntry *base = (DatSkillEntry *)iGpffffb3b8;
    return base[(skillId & 0xFFFF)].kind03;
}




// Intent: threshold trigger for skill arg1 on unit arg0: 0 for none, 4 when unit flag 8 is set, 1 when the HP threshold is crossed, 2 for the SP threshold; [inferred].
// FUN_0023DDC0
s32 datCalcThresholdTrigger(DatUnit *unit, s32 skillId)
{
    s32 trigger;
    s32 idx;
    u32 v;

    trigger = 0;
    if ((u16)skillId >= 0x240) {
        kAssertFail(D_00635938, 0xF1A);
    }
    idx = (skillId & 0xFFFF) * 0x28;
    if (iGpffffb3b8[idx + 0x11] == 0x10) {
        return 0;
    }
    if ((s32)(((s32)((DatUnit *)unit)->bad & 8) != 0) != 0) {
        return 4;
    }
    v = datCalcSkillCost(unit, skillId);
    switch (iGpffffb3b8[idx + 3]) {
    case 1:
        if (!(iGpffffb3b8[idx] & 1)) {
            if (((DatUnit *)unit)->hp > v) {
            } else {
                trigger = 1;
            }
        } else {
            if (((DatUnit *)unit)->hp < v) {
                trigger = 1;
            }
        }
        break;
    case 2:
        if (((DatUnit *)unit)->sp < v) {
            trigger = 2;
        }
        break;
    }
    return trigger;
}
/* Recognize the six special skill IDs accepted by the special-item picker; all other IDs return zero. */
// FUN_0023DF20
u32 datCalcIsSpecialItem(u16 itemId)
{
    u32 result;

    switch (itemId) {
    case 0xc0:
    case 0xc1:
    case 0xc2:
    case 0xc3:
    case 0xc4:
    case 0xc5:
        result = 1;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

/* Whether this skill takes its element/properties from the acting unit's weapon. */
// FUN_0023DF70
s32 datCalcUsesWeaponProperties(s32 skillId)
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    u8 *base;

    if ((skillId & 0xFFFF) >= 0x1B8) {
        kAssertFail(D_00635938, 0xF5E);
    }
    base = iGpffffb3b8 + (u16)skillId * 0x28;
    return (base[0] & 2) != 0;
}

// Intent: default skill id for unit arg0. A stub in retail: it always returns 0, so callers use 0 as "no skill"; [inferred].
// FUN_0023DFE0
s32 datCalcDefaultSkillId(DatUnit *unit)
{
    return 0;
}

// Intent: random special-item skill (0xC0-0xC5) from unit arg0's skill list; 0 when the list has none; [inferred].
// FUN_0023DFF0
#pragma push
/* measured: 320B/320B, nd 0. Unsigned remainders preserve distinct masks
   through CSE; hoisting and selected-before-index match retail registers. */
#pragma opt_loop_invariants on
#pragma opt_common_subs on
s32 datCalcPickSpecialItem(DatUnit *unit)
{
    u16 choices[16];
    s32 count;
    u16 *table;
    u32 selected;
    s32 index;
    s32 valid;
    u16 value;
    u32 n;

    count = datCalcGetTableLength(unit) & 0xFFFF;
    table = (u16 *)datCalcSkillList(unit);
    selected = 0;
    index = 0;
    while ((index & 0xFFFF) < (s32)((u32)count % 0x10000U) &&
           (u32)(selected & 0xFFFF) < 16U) {
        value = table[(u32)index % 0x10000U];
        switch (value) {
        case 0xC0: case 0xC1: case 0xC2: case 0xC3: case 0xC4: case 0xC5:
            valid = 1;
            break;
        default:
            valid = 0;
            break;
        }
        if (valid) {
            choices[(u32)selected % 0x10000U] = value;
            selected = (selected + 1) & 0xFFFF;
        }
        index = (index + 1) & 0xFFFF;
    }
    n = (u32)selected % 0x10000U;
    if (n == 0)
        return 0;
    if (n == 0)
        kAssertFail(D_00635938, 0x17);
    return choices[RpRandom() % n];
}
#pragma pop


/* Retail callers pass the unit pointer even though the count is constant. */
/* Returns the fixed skill-table length (8) used by every unit's table. */
// FUN_0023E130
u32 datCalcGetTableLength(DatUnit *unused)
{
    return 8;
}

// Intent: pointer to the 8-entry skill-id list for unit arg0 (persona skills by pc id, or the monster row's slots); [inferred].
// FUN_0023E140
u8 *datCalcSkillList(DatUnit *unit)
{
    DatUnit *skillUnit = unit;
    /* Preserve index-first GP cursor construction; the fields follow the established table layouts. */
    u8 *unitBytes = (u8 *)unit;

    if (!(*(u16 *)unitBytes & 4)) {
        if (((DatUnit *)unitBytes)->id >= 0xB) {
            kAssertFail(D_00635938, 0xFA5);
        }
        return datPersonaGetSkillsByPcId(skillUnit->id);
    }
    if (((DatUnit *)unitBytes)->id >= 0x150) {
        kAssertFail(D_00635938, 0xFA8);
    }
    return iGpffffb3c4 + skillUnit->id * 0x3C + 0xE;
}

/* Party-character table kind byte; support-hit checks reject kinds 3 and 5. */
// FUN_0023E1F0
u8 datCalcGetCharacterTableKind(DatUnit *unit)
{
    /* Preserve index-first GP cursor construction; the fields follow the established table layouts. */
    DatCharacterTable *base;
    if (unit->flags & 4) {
        return 0;
    }
    if (unit->id >= 0xB) {
        kAssertFail(D_00635938, 0xFBB);
    }
    base = (DatCharacterTable *)iGpffffb3c0;
    return base[unit->id].kind;
}




// Intent: first persona id of unit arg0 (0 for flag-4 units); [inferred].
// FUN_0023E270
u16 datCalcPrimaryPersonaId(DatUnit *unit)
{
    if (unit->flags & 4) {
        return 0;
    }
    if (unit->id >= 0xB) {
        kAssertFail(D_00635938, 0xFCE);
    }
    return (u16)datGetEquippedItemByUnit((s16)unit->id, 0) & 0xFFFF;
}

// Intent: base skill value for unit arg0 at slot arg1 (flag-4 units from the monster row +0x1A; others from the persona row +0x18 when arg1 has bits 6, else 1); the roll in datCalcRollSkillValue adds to it; [inferred].
// FUN_0023E2F0
s32 datCalcSkillValueBase(u8 *unit, s32 slotFlags)
{
    DatUnit *unitRecord = (DatUnit *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    u8 *b;
    u16 v;
    s32 idx;

    if (*(u16 *)unit & 4) {
        if (((DatUnit *)unit)->id >= 0x150) {
            kAssertFail(D_00635938, 0xFE2);
        }
        idx = unitRecord->id * 0xE8;
        b = (u8 *)iGpffffb3cc;
        return b[idx + 0x1A];
    }
    if (((DatUnit *)unit)->id >= 0xB) {
        kAssertFail(D_00635938, 0xFE6);
    }
    v = (u16)slotFlags;
    if (v & 6) {
        idx = unitRecord->id * 0x14C;
        b = (u8 *)iGpffffb3c0;
        return b[idx + 0x18];
    }
    return 1;
}

/* MATCHED 2026-08-03 (wave 14): the goto-form shared zero block + array
   spelling for the lbu case + `#pragma opt_propagation off` + the index-first
   PTDatCalcOffsetAdd helper on the case-0 lhu path together reproduced
   retail's early iGpffffb3c4 base load. Was a documented load-sinking floor
   (nd 7); now matches byte-for-byte. */
/* Query one of three weapon properties, substituting enemy-row values for enemies. */
// FUN_0023E3E0
/* measured: opt_propagation off + index-first inline helper force the
   single-use iGpffffb3c4 base lw before the *0x3C chain (peer-verified). */
#pragma opt_propagation off
u16 datCalcGetWeaponProperty(u16 *unitWords, s32 propertyKind)
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    u16 ret;
    if (unitWords[0] & 0x4) {
        u16 field0 = unitWords[1];
        if (field0 >= 0x150) {
            kAssertFail(D_00635938, 0x1002);
        }
        switch (propertyKind & 0xFF) {
        case 0:
            return ((DatEnemyUnitInit *)(PTDatCalcOffsetAdd((field0 & 0xFFFF) * 0x3C, (u32)iGpffffb3c4)))->weaponPower;
        case 1:
            return iGpffffb3c4[(field0 & 0xFFFF) * 0x3C + 0x39];
        case 2:
            return ((DatSkillEntry *)(iGpffffb3b8))->critRate;
        default:
            kAssertFail(D_00635938, 0x100D);
            goto zero;
        }
    }
    else {
        u16 field1;
        u32 r;
        field1 = unitWords[1];
        if (field1 >= 0xB) {
            kAssertFail(D_00635938, 0x1011);
        }
        r = (u16)datGetEquippedItemByUnit((s16)field1, 0) & 0xFFFF;
        switch (propertyKind & 0xFF) {
        case 0:
            return datEntryGetPrimaryValue((s16)r);
        case 1:
            return datEntryGetSecondaryValue((s16)r);
        case 2:
            return datEntryGetPropertyByte((s16)r) & 0xFF;
        default:
            kAssertFail(D_00635938, 0x101C);
            goto zero;
        }
    }
zero:
    return 0;
}
/* measured: close opt_propagation scope after func_0023e3e0. */
#pragma opt_propagation on
/* Query either armor property; enemy units use ten for both selectors. */

// FUN_0023E5B0
s32 datCalcGetArmorProperty(DatUnit *unit, s32 propertyKindArg)
{
    s32 propertyKind;
    u16 id;
    s32 v;

    if (((DatUnit *)unit)->flags & 4) {
        propertyKind = propertyKindArg & 0xFF;
        switch (propertyKind) {
        case 0:
            return 0xA;
        case 1:
            return 0xA;
        default:
            kAssertFail(D_00635938, 0x1039);
            goto ret0;
        }
    } else {
        id = ((DatUnit *)unit)->id;
        if ((s32)id >= 0xB) {
            kAssertFail(D_00635938, 0x103D);
        }
        v = (u16)datGetEquippedItemByUnit((s16)id, 1) & 0xFFFF;
        propertyKind = propertyKindArg & 0xFF;
        switch (propertyKind) {
        case 0:
            return datEntryGetLastBandValue((s16)v);
        case 1:
            return datEntryGetMiddleBandValue((s16)v);
        default:
            kAssertFail(D_00635938, 0x1046);
            goto ret0;
        }
    }
ret0:
    return 0;
}

/* Fixed eight-slot skill search shared by hit and critical checks. */
#pragma push
#pragma opt_loop_invariants on
static inline u8 *DC411SkillTable(u8 *unit)
{
    /* Preserve the byte cursor; fields and measured MEMBER sites retain the retail load behavior. */
    if (!(*(u16 *)unit & 4)) {
        if (((DatUnit *)unit)->id >= 0xB) {
            kAssertFail(D_00635938, 0xFA5);
        }
        /* measured: typed site/local/array forms change instructions; this existing member is exact. */
        return datPersonaGetSkillsByPcId(MEMBER(u16, unit, DatUnit, id));
    }
    /* measured: typed site/local/array forms change instructions; this existing member is exact. */
    if (MEMBER(u16, unit, DatUnit, id) >= 0x150) {
        kAssertFail(D_00635938, 0xFA8);
    }
    /* measured: typed site/local/array forms change instructions; this existing member is exact. */
    return iGpffffb3c4 + MEMBER(u16, unit, DatUnit, id) * 0x3C + 0xE;
}

static inline s32 DC411HasFixedSkill(u8 *unit, s32 requestedSkill)
{
    /* Preserve the byte cursor; fields and measured MEMBER sites retain the retail load behavior. */
    s32 skill;
    s32 index;
    u8 *table;
    s32 equipment;

    table = DC411SkillTable(unit);
    index = 0;
    skill = requestedSkill & 0xFFFF;
    while ((index & 0xFFFF) < 8) {
        if (skill == ((u16 *)(table))[(u16)index]) {
            return 1;
        }
        index = (index + 1) & 0xFFFF;
    }
    if (!(*(u16 *)unit & 4)) {
        equipment = (u32)(u16)datGetEquippedItemByUnit((s16)((DatUnit *)(unit))->id, 2);
        if (equipment >= 0) {
            if (skill == datItemGrantedSkill((s16)equipment)) {
                return 1;
            }
        }
    }
    return 0;
}

/* C89 promotes the u16 skill formal to the existing s32 call interface.
 * Native byte/halfword conversions retain the retail flag and element checks.
 * Cases 1 and 14 share an early result exit; counter and evade causes share
 * one lifetime. measured: 10920 code bytes plus 8 zero alignment bytes.
 * See docs/probe_archive/DC_worker2_20260920_hit_recovery.md. */
s32 datCalcResolveSkillHit(u8 *, u8 *, s32, s32);
// Intent: outcome code of skill arg2 from source arg0 to target arg1 (0x200 means reflected, re-resolved against the source); [inferred].
// FUN_0023E6F0
s32 datCalcResolveSkillHit(source, target, skillId, options)
u8 *source;
u8 *target;
u16 skillId;
s32 options;
{
    DatUnit *targetRecord = (DatUnit *)target;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    extern f32 iGpffff8170;
    extern f32 fGpffff80cc;
    s32 result;
    s32 checkedSkill;
    s32 skill;
    s32 offset;
    u16 targetFlags;
    u8 active;
    u16 enemyElement;
    s32 element;
    s32 elementMask;
    s32 counterRate;
    s32 rawElement;
    s32 resistance;
    f32 defenseRate;
    f32 attackRate;
    f32 evadeMultiplier;
    f32 hitMultiplier;
    s32 equipmentBonus;
    s16 evadeCause;
    s32 baseRate;

    checkedSkill = skillId & 0xFFFF;
    if (checkedSkill >= 0x1B8) {
        kAssertFail(D_00635938, 0x105E);
    }
    targetFlags = *(u16 *)target;
    if (((*(u16 *)source & 4) != (targetFlags & 4)) &&
        (s8)(active = (((DatCalcUnitState *)source)->buffFlags & 0x100000) != 0) > 0) {
        ((DatCalcUnitState *)target)->message = 0xB2;
        return 4;
    }
    skill = (u32)skillId % 0x10000U;
    offset = skill * 0x28;
    switch (iGpffffb3b8[offset + 0x24]) {
    case 1:
        if ((u8)((((DatUnit *)target)->bad & 4) != 0)) {
            result = 1;
            goto finish;
        } else {
            return 4;
        }
    case 7:
        return (targetFlags & 0x1000) ? 4 : 1;
    case 8:
        return (targetFlags & 0x1000) ? 1 : 4;
    case 9:
        if (datCalcIsGuarding((u16 *)target) != 0) {
            return 0x100;
        }
        break;
    case 12:
        if (datCalcGetElementAffinity(target, 6) & 0x08000000) {
            return 1;
        }
        return (datCalcGetElementAffinity(target, 7) & 0x08000000) ? 1 : 4;
    case 14:
        if ((u8)(((u8 *)&((DatUnit *)target)->bad)[0] != 0)) {
            result = 1;
            goto finish;
        } else {
            return 4;
        }
    }
    if (source != NULL && checkedSkill < 0x1B8 &&
        (iGpffffb3b8[offset] & 2)) {
        if (*(u16 *)source & 4) {
            enemyElement = ((DatEnemyUnitInit *)PTDatCalcOffsetAdd(
                ((DatUnit *)source)->id * 0x3C, (u32)iGpffffb3c4))->weaponElement;
            rawElement = (s16)enemyElement;
        } else {
            rawElement = (s16)datItemElement(
                (s16)(u16)datGetEquippedItemByUnit((s16)((DatUnit *)(source))->id, 0));
        }
    } else {
        rawElement = ((s8 *)iGpffffb3b4)[(skill * 2)];
    }
    element = (s16)rawElement;
    if (element >= 0x13) {
        kAssertFail(D_00635938, 0xE47);
    }
    elementMask = 1 << (element + 1);
    if (!(elementMask & 0xE0001)) {
        if (elementMask & 2) {
            if ((s8)(active = (((DatCalcUnitState *)target)->buffFlags & 0x10000) != 0) > 0) {
                ((DatCalcUnitState *)target)->consumedFlags |= 0x10000;
                return 0x200;
            }
            if (!(options & 2) && !(iGpffffb3b8[offset] & 0x40)) {
                counterRate = 0;
                if (DC411HasFixedSkill(target, 0x1F8) ||
                    (DCHitEquipmentCount(target, 0x4A) & 0xFFFF)) {
                    counterRate = 20;
                    evadeCause = 0x11F8;
                } else {
                    if (DC411HasFixedSkill(target, 0x1F7) ||
                        (DCHitEquipmentCount(target, 0x49) & 0xFFFF)) {
                        counterRate = 15;
                        evadeCause = 0x11F7;
                    } else {
                        if (DC411HasFixedSkill(target, 0x1F6) ||
                            (DCHitEquipmentCount(target, 0x48) & 0xFFFF)) {
                            counterRate = 10;
                            evadeCause = 0x11F6;
                        }
                    }
                }
                counterRate = (s16)counterRate;
                if (counterRate != 0 &&
                    (s32)(RpRandom() % 100U) < counterRate) {
                    ((DatCalcUnitState *)target)->message = evadeCause;
                    return 0x200;
                }
            }
        } else if (!(elementMask & 0x40) &&
            (s8)(active = (((DatCalcUnitState *)target)->buffFlags & 0x20000) != 0) > 0) {
            ((DatCalcUnitState *)target)->consumedFlags |= 0x20000;
            return 0x200;
        }
        resistance = datCalcGetElementAffinity(target, rawElement);
        if (resistance & 0x02000000) {
            return 0x200;
        }
        if (resistance & 0x04000000) {
            return 0x400;
        }
        if (resistance & 0x01000000) {
            return 0x100;
        }
    }
    if (iGpffffb3b8[offset + 0xE] == 0) {
        return 4;
    }
    if ((u8)((((DatUnit *)target)->bad & 0x100000) != 0)) {
        return 1;
    }
    if (datCalcIsGuarding((u16 *)target) != 0) {
        return 1;
    }
    if (iGpffffb3b8[offset + 0xE] >= 100) {
        return 1;
    }
    if (*(u16 *)target & 0x40) {
        return 1;
    }
    switch (targetRecord->bad & 0xFFFFF) {
    case 1:
        return 1;
    }
    attackRate = datCalcBuffMultiplier(source, 4, skillId);
    defenseRate = datCalcBuffMultiplier(target, 2, skillId);
    evadeMultiplier = 1.0f;
    hitMultiplier = 1.0f;
    equipmentBonus = 0;
    evadeCause = 0;
    if (!(options & 2)) {
        switch (element) {
        case 0:
            if (DC411HasFixedSkill(target, 0x1DD)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11DD;
            } else if (DC411HasFixedSkill(target, 0x1DC)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11DC;
            }
            break;
        case 1:
            if (DC411HasFixedSkill(target, 0x1DF)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11DF;
            } else if (DC411HasFixedSkill(target, 0x1DE)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11DE;
            }
            break;
        case 2:
            if (DC411HasFixedSkill(target, 0x1E1)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E1;
            } else if (DC411HasFixedSkill(target, 0x1E0)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E0;
            }
            break;
        case 4:
            if (DC411HasFixedSkill(target, 0x1E3)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E3;
            } else if (DC411HasFixedSkill(target, 0x1E2)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E2;
            }
            break;
        case 3:
            if (DC411HasFixedSkill(target, 0x1E5)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E5;
            } else if (DC411HasFixedSkill(target, 0x1E4)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E4;
            }
            break;
        }
        if (evadeMultiplier == 1.0f && (elementMask & 0x3C)) {
            if (DC411HasFixedSkill(target, 0x1E6)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E6;
            }
        }
        if (DC411HasFixedSkill(target, 0x209)) {
            return 1;
        }
        if (DC411HasFixedSkill(target, 0x208)) {
            evadeMultiplier *= 0.5f;
        }
    }
    baseRate = datScriptRunCalc(DAT_SCRIPT_CALC_HIT_RATE, (u16 *)source, (u16 *)target, skillId, 0);
    if (!(*(u16 *)target & 4)) {
        switch (element) {
        case 0:
            if (DC411HasEquipmentProperty(target, 0x74)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(target, 0x75)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(target, 0x76)) {
                equipmentBonus += 20;
            }
            break;
        }
        switch (element) {
        case 1: case 2: case 3: case 4:
            if (DC411HasEquipmentProperty(target, 0x83)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(target, 0x84)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(target, 0x85)) {
                equipmentBonus += 20;
            }
            break;
        }
        switch (element) {
        case 1:
            if (DC411HasEquipmentProperty(target, 0x77)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(target, 0x78)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(target, 0x79)) {
                equipmentBonus += 20;
            }
            break;
        case 2:
            if (DC411HasEquipmentProperty(target, 0x7A)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(target, 0x7B)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(target, 0x7C)) {
                equipmentBonus += 20;
            }
            break;
        case 3:
            if (DC411HasEquipmentProperty(target, 0x80)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(target, 0x81)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(target, 0x82)) {
                equipmentBonus += 20;
            }
            break;
        case 4:
            if (DC411HasEquipmentProperty(target, 0x7D)) {
                equipmentBonus += 10;
            }
            if (DC411HasEquipmentProperty(target, 0x7E)) {
                equipmentBonus += 15;
            }
            if (DC411HasEquipmentProperty(target, 0x7F)) {
                equipmentBonus += 20;
            }
            break;
        }
    }
    baseRate = (s32)(evadeMultiplier * (hitMultiplier *
        (defenseRate * ((f32)baseRate * attackRate)))) - equipmentBonus;
    if (baseRate > 99) {
        baseRate = 99;
    } else if (baseRate < 50) {
        baseRate = 50;
    }
    if ((s32)(RpRandom() % 100U) >= baseRate) {
        ((DatCalcUnitState *)target)->message = evadeCause;
        return 4;
    }
    return 1;
finish:
    return result;
}
#pragma pop


/* measured 002411a0: configured b210 emits 2588/2592B with all 70 relocations
 * resolved exactly and four retail zero tail bytes. Declaring idx after lvl
 * restores the initial index/element register assignment. The repeated searches,
 * native conversions and conversion-before-bonus order preserve retail behavior.
 * opt_loop_invariants on scopes the searches; opt_common_subs on scopes the main
 * body. All 79 siblings and allocated data are unchanged.
 * The fifth argument is passed by btlTargetResolveSelectedSkill and unused by retail.
 * See docs/probe_archive/DC_worker3_20260920_recoveries.md. */
#pragma push
#pragma opt_loop_invariants on

/* The skill is interpreted as u16 inside this C89 definition; its promoted
 * s32 interface preserves the existing callers. measured: 2588/2592 bytes
 * with func_00244f60's real u16 skill parameter; the suffix is zero alignment. */
s32 datCalcHitResult(u8 *, u8 *, s32, s32, s32);
// Intent: skill result for attacker arg0 on target arg1: 2 for a critical (roll under the crit rate; sub == 2 in datCalcSkillAmount), 4 when the affinity is weak (AFF_WEAK), 1 otherwise; [inferred].
// FUN_002411A0
#pragma opt_common_subs on
s32 datCalcHitResult(source, target, skillId, outcome, unusedMode)
u8 *source;
u8 *target;
u16 skillId;
s32 outcome;
s32 unusedMode;
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    s32 tmp22;
    s32 lvl;
    s32 idx;
    s32 bits;
    u16 element;
    u16 enemyElement;
    s32 res;
    s32 base;
    s32 thresh;
    f32 f20;
    u8 *entry;
    u16 id16;
    s32 bonus;
    s32 scaled;
    s32 total;

    tmp22 = skillId & 0xFFFF;
    if (tmp22 >= 0x1B8) {
        kAssertFail(D_00635938, 0x122E);
    }
    switch (outcome & 0xFFFF) {
    case 0x200:
    case 0x400:
    case 0x100:
    case 2:
    case 4:
        return 1;
    }
    if ((source != 0) && (tmp22 < 0x1B8) && ((iGpffffb3b8[(idx = (u32)skillId % 0x10000U) * 0x28] & 2) != 0)) {
        if ((((DatUnit *)source)->flags & 4) != 0) {
            id16 = ((DatUnit *)source)->id;
            enemyElement = iGpffffb3c4[id16 * 0x3C + 0x38];
            lvl = (s16)enemyElement;
        } else {
            element = datGetEquippedItemByUnit((s16)((DatUnit *)source)->id, 0);
            lvl = (s16)datItemElement((s16)element);
        }
    } else {
        idx = (u32)skillId % 0x10000U;
        lvl = ((s8 *)iGpffffb3b4)[(idx * 2)];
    }
    bits = (s16)lvl;
    if (bits >= 0x13) {
        kAssertFail(D_00635938, 0xE47);
    }
    bits = 1U << (bits + 1);
    if ((bits & 0xE0001) != 0) {
        return 1;
    }
    res = datCalcGetElementAffinity(target, lvl);
    if (((bits & 2) == 0) && (((bits & 0x40) == 0) || (iGpffffb3b8[idx * 0x28 + 2] != 1))) {
        if (res & 0x08000000) {
            return 4;
        }
        return 1;
    }
    idx *= 0x28;
    entry = iGpffffb3b8;
    if (entry[idx + 0x25] == 0) {
        return (res & 0x08000000) != 0 ? 4 : 1;
    }
    if ((((DatUnit *)target)->flags & 0x80) != 0) {
        return (res & 0x08000000) != 0 ? 4 : 1;
    }
    if ((((DatUnit *)source)->flags & 4) == (((DatUnit *)target)->flags & 4)) {
        return (res & 0x08000000) != 0 ? 4 : 1;
    }
    if ((res & 0x08000000) != 0) {
        return 4;
    }
    if (datCalcIsGuarding((u16 *)target) != 0) {
        return 1;
    }
    base = 0;
    thresh = 0;
    f20 = 1.0f;
    entry = iGpffffb3b8;
    if (entry[idx + 0x25] == 0x64) {
        base = 0x64;
        thresh = 0x64;
    }
    switch (entry[idx + 2]) {
    case 1:
        if (base == 0) {
            base = datScriptRunCalc(DAT_SCRIPT_CALC_SCALED_RATIO, (u16 *)(source), (u16 *)(target), skillId, 0);
        }
        if (DC411HasFixedSkill(target, 0x206)) {
            f20 = f20 * 0.5f;
        }
        if (DC411HasFixedSkill(source, 0x207)) {
            f20 = f20 * 2.0f;
        }
        scaled = (s32)((f32)base * f20);
        bonus = 0;
        if (tmp22 >= 0x1B8) {
            kAssertFail(D_00635938, 0xF5E);
        }
        if ((u8)((((DatSkillEntry *)(iGpffffb3b8 + idx))->flags00 & 2) != 0)) {
            if (DC411HasEquipmentProperty(source, 0x3C)) {
                bonus += 5;
            }
            if (DC411HasEquipmentProperty(source, 0x3D)) {
                bonus += 10;
            }
            if (DC411HasEquipmentProperty(source, 0x3E)) {
                bonus += 15;
            }
        }
        if (datCalcGetBuffLevel((DatUnit *)source, 5) > 0) {
            bonus += 7;
        }
        if (datCalcGetBuffLevel((DatUnit *)source, 6) > 0) {
            bonus += 15;
        }
        total = scaled + bonus;
        if (total > 0x64) {
            total = 0x64;
        } else if (total < 0) {
            total = 0;
        }
        if ((s32)(RpRandom() % 100) < thresh) {
            return 2;
        }
        if ((s32)(RpRandom() % 100) < 0) {
            return 2;
        }
        if ((s32)(RpRandom() % 100) < total) {
            return 2;
        }
        break;
    case 2:
        break;
    default:
        kAssertFail(D_00635938, 0x12EF);
        break;
    }
    return 1;
}
#pragma pop

/* measured: 4 attempts, best nd 58. Nearly everything now matches: the
   u32-typed flag1 gives retail's sltu booleanization, `(s32)(u16)arg2`
   defeats the mask CSE (raw arg2 stays in $s2, temp_6 in $a2),
   `(u32)temp_4 + temp_5` defeats the commutative cross-block CSE so the
   &2 check re-adds $a0+$a1 as retail, the entry reads are one addu into
   $v1, the 1 constant lands in $a3, and the return-1 tail (addiu $v1,1
   before addiu $v0,1, sllv, 0xE0001 mask) matches. Residual: the three
   path values each need ONE dsll32/dsra32-by-16 pair in retail (lbu+pair,
   jal+pair, lb with the pair only at the merge). `(s16)` casts fold into
   the merge's (s16) extension (no path pairs); the s64-shift spelling
   `(s32)((s64)x << 0x30) >> 0x30` keeps the path pairs but adds a
   dsll32/dsra32-by-0 truncation pair per path (6 extra words, nd 58). The
   merge itself ((s16)var_2_2 into $s0) matches.
   Wave 14 re-test: fresh reconstruction with the note's spellings (u32
   flag1, (s32)(u16)arg2, (s16) v) gave nd 83 (obj 504B vs window 544B,
   frame 0x50 vs 0x60 â€” 4 rst saved vs 5, branch targets shifted); the
   exact hand-adapted body was not recovered. The 5th arg (arg4) is passed
   by datCalcSkillAllowedForMode but unused in the body (prologue never saves it).
   s16-extension-pair floor, corroborated. */
// Intent: true unless the target's level bit for skill arg2 is in 0xE0001 (null, absorb or reflect); other early exits return false; [inferred].
// FUN_00241BC0
#pragma push
/* measured: opt_propagation off keeps arg2 raw in $s2 and the masked u16 in $s0;
   per-use u16 casts for other masks avoid the 0xffff constant cache. */
#pragma opt_propagation off
s32 datCalcSkillAppliesToTarget(source, target, skillId, channel, unusedMode)
u8 *source;
u8 *target;
s32 skillId;
s32 channel;
s32 unusedMode;
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    u16 idx;
    u32 offset;
    u8 *base;
    u8 *entry;
    u32 flag1;
    s16 value;

    idx = (u16)skillId;
    if (idx >= 0x1B8) {
        kAssertFail(D_00635938, 0x1305);
    }
    flag1 = ((DatUnit *)target)->bad;
    if (((u32)((flag1 & 0x100000) != 0) != 0)) {
        return 0;
    }
    if ((u16)channel != 1) {
        return 0;
    }
    if ((((DatUnit *)target)->flags & 8)) {
        return 0;
    }
    offset = (u32)(u16)skillId * 0x28;
    base = iGpffffb3b8;
    entry = (u8 *)(offset + (u32)base);
    if (entry[0x11] == 0 && (entry[0x18] != 1 || ((((DatSkillEntry *)(entry))->statusMask & 0x80000) == 0))) {
        return 0;
    }
    if (source != 0 && idx < 0x1B8 && ((((DatSkillEntry *)(base + offset))->flags00 & 2))) {
        if ((((DatUnit *)source)->flags & 4)) {
            s32 partyOffset;
            u8 *partyPtr;

            partyOffset = (s32)(((DatUnit *)source)->id * 0x3C);
            partyPtr = (u8 *)(partyOffset + (s32)iGpffffb3c4);
            value = (s16)partyPtr[0x38];
        } else {
            value = (s16)datItemElement((s16)((u16)datGetEquippedItemByUnit((s16)((DatUnit *)source)->id, 0) & 0xFFFF));
        }
    } else {
        value = ((s8 *)iGpffffb3b4)[((u32)(u16)skillId * 2)];
    }
    if (value >= 0x13) {
        kAssertFail(D_00635938, 0xE47);
    }
    if (((1 << (value + 1)) & 0xE0001) == 0) {
        goto one;
    }
    return 0;
one:
    return 1;
}
#pragma pop
// Intent: true when datCalcSkillAppliesToTarget holds and the skill's category is 9 or 10, or mode arg4 is 2 or 4; [inferred].
// FUN_00241DE0
s32 datCalcSkillAllowedForMode(DatUnit *source, DatUnit *target, s32 skillId, s32 channel, s32 mode)
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    u8 *entry;
    u32 offset;
    if (!((skillId & 0xFFFF) < 0x1B8)) {
        kAssertFail(D_00635938, 0x1333);
    }
    if (datCalcSkillAppliesToTarget((u8 *)source, (u8 *)target, skillId, channel, mode) == 0) {
        return 0;
    }
    entry = (u8 *)iGpffffb3b8;
    offset = (u16)skillId * 0x28;
    entry = (u8 *)((u32)offset + (u32)entry);
    switch (((DatSkillEntry *)(entry))->kind24) {
    case 9:
    case 10:
        return 1;
    }
    if ((mode & 0xFFFF) == 2 || (mode & 0xFFFF) == 4) {
        return 1;
    }
    return 0;
}

// Intent: rolls a support-skill hit for arg0 on arg1 from a chance set by passive flags 0x71, 0x72 and 0x73 (5, 50, 32 or 0); [inferred].
// FUN_00241F00
s32 datCalcRollSupportSkillHit(u8 *source, u8 *target, s32 skillId, s32 outcome)
{
    DatUnit *sourceRecord = (DatUnit *)source;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    u16 sourceFlags;
    u8 tactic;
    s32 tacticValue;
    s32 hitResult;
    s32 baseChance;
    u16 chance;
    s32 unusedValue;
    s32 hasHighChance;
    s32 hasMediumChance;
    s32 hasNoChance;
    u16 characterId;

    if ((u16)skillId >= 0x1B8) {
        kAssertFail(D_00635938, 0x1360);
    }
    if (!(((DatSkillEntry *)(iGpffffb3b8 + ((skillId & 0xFFFF)) * 0x28))->flags00 & 2)) {
        return 0;
    }
    if ((s32)(((s32)((DatUnit *)(target))->bad & 0x100000) != 0) != 0) {
        return 0;
    }
    sourceFlags = *(u16 *)source;
    if (sourceFlags & 0x10) {
        return 0;
    }
    if (!(sourceFlags & 4)) {
        if (((DatUnit *)source)->id >= 0xB) {
            kAssertFail(D_00635938, 0x1371);
        }
        if (*(u16 *)source & 4) {
            tactic = 0;
        } else {
            if (sourceRecord->id >= 0xB) {
                kAssertFail(D_00635938, 0xFBB);
            }
            tactic = iGpffffb3c0[sourceRecord->id * 0x14C + 0x14A];
        }
        tacticValue = tactic & 0xFF;
        if (tacticValue == 3 || tacticValue == 5) {
            return 0;
        }
    }
    hitResult = outcome & 0xFFFF;
    if (hitResult != 4 && hitResult != 2) {
        return 0;
    }
    if (*(u16 *)source & 4) {
        baseChance = 0x64;
    } else {
        baseChance = 5;
    }
    chance = baseChance & 0xFFFF;
    if (*(u16 *)source & 4) {
        hasHighChance = 0;
    } else {
        characterId = ((DatUnit *)source)->id;
        if ((s32)characterId >= 0xB) {
            kAssertFail(D_00635938, 0x23B);
        }
        if ((datItemValue(datGetEquippedItemByUnit((s16)characterId, 0)) & 0xFFFF) == 0x71) {
            hasHighChance = 1;
        } else if ((datItemValue(datGetEquippedItemByUnit((s16)characterId, 1)) & 0xFFFF) == 0x71) {
            hasHighChance = 1;
        } else {
            hasHighChance = 0;
        }
    }
    if (hasHighChance != 0) {
        chance = 0x50;
    }
    if (*(u16 *)source & 4) {
        hasMediumChance = 0;
    } else {
        characterId = ((DatUnit *)source)->id;
        if ((s32)characterId >= 0xB) {
            kAssertFail(D_00635938, 0x23B);
        }
        if ((datItemValue(datGetEquippedItemByUnit((s16)characterId, 0)) & 0xFFFF) == 0x72) {
            hasMediumChance = 1;
        } else if ((datItemValue(datGetEquippedItemByUnit((s16)characterId, 1)) & 0xFFFF) == 0x72) {
            hasMediumChance = 1;
        } else {
            hasMediumChance = 0;
        }
    }
    if (hasMediumChance != 0) {
        chance = 0x32;
    }
    if (*(u16 *)source & 4) {
        hasNoChance = 0;
    } else {
        characterId = ((DatUnit *)source)->id;
        if ((s32)characterId >= 0xB) {
            kAssertFail(D_00635938, 0x23B);
        }
        if ((datItemValue(datGetEquippedItemByUnit((s16)characterId, 0)) & 0xFFFF) == 0x73) {
            hasNoChance = 1;
        } else if ((datItemValue(datGetEquippedItemByUnit((s16)characterId, 1)) & 0xFFFF) == 0x73) {
            hasNoChance = 1;
        } else {
            hasNoChance = 0;
        }
    }
    if (hasNoChance != 0) {
        chance = 0;
    }
    if ((s32)(RpRandom() % 100) < (s32)(chance & 0xFFFF)) {
        return 1;
    }
    return 0;
}

// Intent: rolls a skill's success for target arg1 from the skill's chance byte (raised for flagged units and for skill 0x21C); [inferred].
// FUN_00242360
/* measured: loop-invariant 0x21C compare constant must be hoisted into
   the preheader (retail addiu $a0,$zero,0x21c before the loop's initial
   branch); mwcc b210 rematerialises it in the body without the pragma. */
#pragma opt_loop_invariants on
s32 datCalcRollSkillChance(u8 *source, u8 *target, s32 skillIdArg, s32 channel, s32 outcome)
{
    DatUnit *sourceRecord = (DatUnit *)source;
    DatUnit *targetRecord = (DatUnit *)(target);
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    f32 scaledChance;
    f32 boostedChance;
    f32 baseChanceFloat;
    f32 chanceFloat;
    f32 resistanceScale;
    s32 skillId;
    s32 chanceValue;
    u32 queryValue;
    s32 hitResult;
    s32 hasChanceBoost;
    s32 unusedValue;
    s32 unusedResult;
    s32 skillIndex;
    s32 affinity;
    u32 flag1;
    u32 flag2;
    u32 flag3;
    u8 *skills;
    u16 chance;

    flag1 = ((s32)((DatUnit *)(target))->bad & 1) != 0;
    if (flag1) {
        return 0;
    }
    if ((channel & 0xFFFF) != 1) {
        return 0;
    }
    skillId = skillIdArg & 0xFFFF;
    if (skillId >= 0x1B8) {
        kAssertFail(D_00635938, 0x13B6);
    }
    affinity = datCalcGetAffinity(target, 0xC);
    if (affinity & 0x27000000) {
        return 0;
    }
    chance = 0;
    flag2 = ((s32)targetRecord->bad & 0x100000) != 0;
    if (flag2) {
        if (skillId >= 0x1B8) {
            kAssertFail(D_00635938, 0xF5E);
        }
        flag3 = (iGpffffb3b8[(u16)skillIdArg * 0x28] & 2) != 0;
        if (flag3) {
            chance = 0x32;
        }
        hitResult = outcome & 0xFFFF;
        if (hitResult == 2 || hitResult == 4) {
            chance = 0x64;
        }
    } else {
        chance = iGpffffb3b8[(u16)skillIdArg * 0x28 + 0x26];
        if ((s32)chance > 0) {
            queryValue = affinity & 0xFFFF;
            resistanceScale = (f32)queryValue;
            resistanceScale = resistanceScale / 100.0f;
            baseChanceFloat = (f32)chance;
            scaledChance = baseChanceFloat * resistanceScale;
            chance = (u16)scaledChance;
            if (!(*(u16 *)source & 4)) {
                if (((DatUnit *)source)->id >= 0xB) {
                    kAssertFail(D_00635938, 0xFA5);
                }
                skills = datPersonaGetSkillsByPcId(sourceRecord->id);
            } else {
                if (((DatUnit *)source)->id >= 0x150) {
                    kAssertFail(D_00635938, 0xFA8);
                }
                skills = sourceRecord->id * 0x3C + iGpffffb3c4 + 0xE;
            }
            skillIndex = 0;
            while ((skillIndex & 0xFFFF) < 8) {
                if (((u16 *)(skills))[(u16)skillIndex] == 0x21C) {
                    hasChanceBoost = 1;
                    goto done;
                }
                skillIndex = (skillIndex + 1) & 0xFFFF;
            }
            if (!(*(u16 *)source & 4) && (queryValue = (u16)datGetEquippedItemByUnit((s16)sourceRecord->id, 2) & 0xFFFF, (s32)queryValue >= 0) &&
                (datItemGrantedSkill((s16)queryValue) == 0x21C)) {
                hasChanceBoost = 1;
            } else {
                hasChanceBoost = 0;
            }
done:
            if (hasChanceBoost != 0) {
                chanceFloat = (f32)chance;
                boostedChance = 1.25f * chanceFloat;
                chance = (u16)boostedChance;
            }
        }
    }
    chanceValue = chance & 0xFFFF;
    if (chanceValue == 0) {
        return 0;
    }
    if (chanceValue >= 0x64 || (s32)(RpRandom() % 100U & 0xFFFF) < chanceValue) {
        return 1;
    }
    return 0;
}
/* Closes the measured opt_loop_invariants scope opened for datCalcRollSkillChance above.
   It must stay scoped: leaving it on regresses the neighbouring functions. */
#pragma opt_loop_invariants off

// Intent: chance (0..100) that an ailment of level arg1 lands on unit arg0: 0 for level -1 or bit 0, 100 for bits 0xE0000, else the skill-table result; [inferred].
// FUN_00242800
s32 datCalcGetElementAffinity(u8 *unit, s32 elementIndex)
{
    s16 id;
    s32 x;

    id = (s16)elementIndex;
    if (id == -1) {
        return 0;
    }
    if (id >= 0x13) {
        kAssertFail(D_00635938, 0x13FD);
    }
    if (id >= 0x13) {
        kAssertFail(D_00635938, 0xE47);
    }
    x = 1 << (id + 1);
    if (x & 1) {
        return 0;
    }
    if (x & 0xE0000) {
        return 0x64;
    }
    return datCalcGetAffinity(unit, elementIndex);
}
/* Test the KO status or whether current HP plus the proposed delta would be nonpositive. */
// FUN_002428F0
u32 datCalcIsDead(DatUnit *unit, s32 hpDelta)
{
    if (unit->bad & 0x80000 ? 1 : 0) {
        return 1;
    }
    return (unit->hp + hpDelta) <= 0;
}
/* Report HP below 26 percent of the computed maximum, using integer percentage division. */
// FUN_00242930
u32 datCalcIsLowHp(DatUnit *unit)
{
    u16 hp;

    hp = unit->hp;
    return ((hp * 100) / datCalcMaxHp(unit)) < 26;
}

/* measured: fndiff 1 word (reloc-masked), fnalign 2 edits (plus 43 reloc-only), obj 813 instrs / retail 813 instrs (window 3264B, 12B under, 0.4% inside 3% gate). Baseline 172 edits / 750 words at 812/812; all-fresh counters 172->68 edits; loopinv 68->20; head temp_16 reuse 20->14; s16 value 14->3 edits / 558->2 words; tail (u16) mask 2->1 word / 3->2 edits. Free pragmas: loopinv 752, unroll/sched tie 750, commonsubs 578 words but 207 edits (rejected for edits). Subscript P[i] neutral 172; reuse temp_16 alone 246 edits (rejected). Decl swaps tie 172; fresh-first 159. All 8 skill-search loops match (while+goto-done, (u16)var_5 masks, fresh counters per loop, loopinv hoist); 0x231/0x232 early returns, 0x20/0x800/0x400 guards, 6/7 dispatch with 0x340/0x3C-0x38 checks, 0x211/0x221 + 0x212/0x222 with 50% random, 0x210/0x20F tail and 47cb0/107ac0 >=9 all in retail shape. Remaining: single addu $v0,$v1,$v0 vs $v0,$v0,$v1 orientation (commutative, source-invariant across both orders, floor) + lw addend masked as reloc-only. Supersedes prior nd-170 layout floor. */
/* MATCHED 2026-09-19.  The single differing word at 0x00242CEC - retail
   `addu $v0, $v1, $v0` against b210's `addu $v0, $v0, $v1` - was not a compiler floor.
   Routing the monster-attribute load through the file's existing `PTDatCalcOffsetAdd`
   helper fixes the operand order: the parameter boundary forces the offset to be the
   first addend, which is what retail emits.  Ten spellings had been measured without
   the helper and all tied at one differing word, which is what produced the incorrect
   floor claim in the earlier note.  The three sibling sites in this function already
   used the helper; this was the one that did not. */
// Intent: effective skill id for unit arg0 given base skill arg1: a replacement id found in the unit's slots (0x20F-0x231 families, some by random roll), or -1 when none applies; [inferred].
// FUN_00242990
#pragma opt_loop_invariants on
s32 datCalcResolveSkillId(DatUnit *unit, s32 baseSkill)
{
    /* Skill-row byte addressing retains the measured offset/load order; DatSkillEntry documents the proven 0x28-byte layout (see datCalc_internal.h). */
    s32 skillId;
    s32 equipment;
    s32 found;
    u8 *skills;
    s32 priorityIndex;
    s32 secondaryPriorityIndex;
    s32 lightChanceIndex;
    s32 lightIndex;
    s32 darkChanceIndex;
    s32 darkIndex;
    s32 firstFallbackIndex;
    s32 lastFallbackIndex;
    s16 value;
    s32 tmp;
    s32 replacementSkill;

    replacementSkill = -1;
    skillId = baseSkill & 0xFFFF;
    if ((skillId < 0x1B8) && (iGpffffb3b8[skillId * 0x28 + 0x24] == 0xD)) {
        return -1;
    }
    if (!(unit->flags & 4)) {
        if (unit->id >= 0xB) {
            kAssertFail(D_00635938, 0xFA5);
        }
        skills = datPersonaGetSkillsByPcId(unit->id);
    } else {
        if (unit->id >= 0x150) {
            kAssertFail(D_00635938, 0xFA8);
        }
        skills = unit->id * 0x3C + iGpffffb3c4 + 0xE;
    }
    priorityIndex = 0;
    while ((priorityIndex & 0xFFFF) < 8) {
        if (((u16 *)(skills))[(u16)priorityIndex] == 0x231) {
            found = 1;
            goto done1;
        }
        priorityIndex = (priorityIndex + 1) & 0xFFFF;
    }
    if (!(unit->flags & 4)) {
        equipment = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)unit->id, 2) & 0xFFFF);
        if (equipment >= 0) {
            if (datItemGrantedSkill((s16)equipment) == 0x231) {
                found = 1;
                goto done1;
            }
        }
    }
    found = 0;
done1:
    if (found != 0) {
        return 0x231;
    }
    if (!(unit->flags & 4)) {
        if (unit->id >= 0xB) {
            kAssertFail(D_00635938, 0xFA5);
        }
        skills = datPersonaGetSkillsByPcId(unit->id);
    } else {
        if (unit->id >= 0x150) {
            kAssertFail(D_00635938, 0xFA8);
        }
        skills = unit->id * 0x3C + iGpffffb3c4 + 0xE;
    }
    secondaryPriorityIndex = 0;
    while ((secondaryPriorityIndex & 0xFFFF) < 8) {
        if (((u16 *)(skills))[(u16)secondaryPriorityIndex] == 0x232) {
            found = 1;
            goto done2;
        }
        secondaryPriorityIndex = (secondaryPriorityIndex + 1) & 0xFFFF;
    }
    if (!(unit->flags & 4)) {
        equipment = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)unit->id, 2) & 0xFFFF);
        if (equipment >= 0) {
            if (datItemGrantedSkill((s16)equipment) == 0x232) {
                found = 1;
                goto done2;
            }
        }
    }
    found = 0;
done2:
    if (found != 0) {
        return 0x232;
    }
    if (unit->flags & 0x20) {
        return 0;
    }
    if ((unit != 0) && (skillId < 0x1B8) && ((iGpffffb3b8[(u16)baseSkill * 0x28] & 2) != 0)) {
        if (unit->flags & 4) {
            value = ((DatEnemyUnitInit *)((u8 *)PTDatCalcOffsetAdd(unit->id * 0x3C, (u32)iGpffffb3c4)))->weaponElement;
        } else {
            value = (s16)datItemElement((s16)((u16)datGetEquippedItemByUnit((s16)unit->id, 0) & 0xFFFF));
        }
    } else {
        value = ((s8 *)iGpffffb3b4)[((u32)(u16)baseSkill * 2)];
    }
    if ((s16)value == 6) {
        if (unit->flags & 4) {
            tmp = 0;
        } else {
            tmp = (datItemCount(0x340) & 0xFF) > 0;
        }
        if (tmp != 0) {
            replacementSkill = 0x154;
        }
        if (!(unit->flags & 4)) {
            if (unit->id >= 0xB) {
                kAssertFail(D_00635938, 0xFA5);
            }
            skills = datPersonaGetSkillsByPcId(unit->id);
        } else {
            if (unit->id >= 0x150) {
                kAssertFail(D_00635938, 0xFA8);
            }
            skills = unit->id * 0x3C + iGpffffb3c4 + 0xE;
        }
        lightChanceIndex = 0;
        while ((lightChanceIndex & 0xFFFF) < 8) {
            if (((u16 *)(skills))[(u16)lightChanceIndex] == 0x211) {
                found = 1;
                goto done3;
            }
            lightChanceIndex = (lightChanceIndex + 1) & 0xFFFF;
        }
        if (!(unit->flags & 4)) {
            equipment = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)unit->id, 2) & 0xFFFF);
            if (equipment >= 0) {
                if (datItemGrantedSkill((s16)equipment) == 0x211) {
                    found = 1;
                    goto done3;
                }
            }
        }
        found = 0;
done3:
        if ((found != 0) && ((s32)(RpRandom() % 100U) < 0x32)) {
            replacementSkill = 0x211;
        }
        if (!(unit->flags & 4)) {
            if (unit->id >= 0xB) {
                kAssertFail(D_00635938, 0xFA5);
            }
            skills = datPersonaGetSkillsByPcId(unit->id);
        } else {
            if (unit->id >= 0x150) {
                kAssertFail(D_00635938, 0xFA8);
            }
            skills = unit->id * 0x3C + iGpffffb3c4 + 0xE;
        }
        lightIndex = 0;
        while ((lightIndex & 0xFFFF) < 8) {
            if (((u16 *)(skills))[(u16)lightIndex] == 0x221) {
                found = 1;
                goto done4;
            }
            lightIndex = (lightIndex + 1) & 0xFFFF;
        }
        if (!(unit->flags & 4)) {
            equipment = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)unit->id, 2) & 0xFFFF);
            if (equipment >= 0) {
                if (datItemGrantedSkill((s16)equipment) == 0x221) {
                    found = 1;
                    goto done4;
                }
            }
        }
        found = 0;
done4:
        if (found != 0) {
            replacementSkill = 0x221;
        }
    } else if ((s16)value == 7) {
        if (unit->flags & 4) {
            tmp = 0;
        } else {
            tmp = (datItemCount(0x340) & 0xFF) > 0;
        }
        if (tmp != 0) {
            replacementSkill = 0x154;
        }
        if (!(unit->flags & 4)) {
            if (unit->id >= 0xB) {
                kAssertFail(D_00635938, 0xFA5);
            }
            skills = datPersonaGetSkillsByPcId(unit->id);
        } else {
            if (unit->id >= 0x150) {
                kAssertFail(D_00635938, 0xFA8);
            }
            skills = unit->id * 0x3C + iGpffffb3c4 + 0xE;
        }
        darkChanceIndex = 0;
        while ((darkChanceIndex & 0xFFFF) < 8) {
            if (((u16 *)(skills))[(u16)darkChanceIndex] == 0x212) {
                found = 1;
                goto done5;
            }
            darkChanceIndex = (darkChanceIndex + 1) & 0xFFFF;
        }
        if (!(unit->flags & 4)) {
            equipment = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)unit->id, 2) & 0xFFFF);
            if (equipment >= 0) {
                if (datItemGrantedSkill((s16)equipment) == 0x212) {
                    found = 1;
                    goto done5;
                }
            }
        }
        found = 0;
done5:
        if ((found != 0) && ((s32)(RpRandom() % 100U) < 0x32)) {
            replacementSkill = 0x212;
        }
        if (!(unit->flags & 4)) {
            if (unit->id >= 0xB) {
                kAssertFail(D_00635938, 0xFA5);
            }
            skills = datPersonaGetSkillsByPcId(unit->id);
        } else {
            if (unit->id >= 0x150) {
                kAssertFail(D_00635938, 0xFA8);
            }
            skills = unit->id * 0x3C + iGpffffb3c4 + 0xE;
        }
        darkIndex = 0;
        while ((darkIndex & 0xFFFF) < 8) {
            if (((u16 *)(skills))[(u16)darkIndex] == 0x222) {
                found = 1;
                goto done6;
            }
            darkIndex = (darkIndex + 1) & 0xFFFF;
        }
        if (!(unit->flags & 4)) {
            equipment = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)unit->id, 2) & 0xFFFF);
            if (equipment >= 0) {
                if (datItemGrantedSkill((s16)equipment) == 0x222) {
                    found = 1;
                    goto done6;
                }
            }
        }
        found = 0;
done6:
        if (found != 0) {
            replacementSkill = 0x222;
        }
    }
    if ((s16)replacementSkill != -1) {
        goto tail;
    }
    if (!(unit->flags & 0x800)) {
        if (!(unit->flags & 4)) {
            if (unit->id >= 0xB) {
                kAssertFail(D_00635938, 0xFA5);
            }
            skills = datPersonaGetSkillsByPcId(unit->id);
        } else {
            if (unit->id >= 0x150) {
                kAssertFail(D_00635938, 0xFA8);
            }
            skills = unit->id * 0x3C + iGpffffb3c4 + 0xE;
        }
        firstFallbackIndex = 0;
        while ((firstFallbackIndex & 0xFFFF) < 8) {
            if (((u16 *)(skills))[(u16)firstFallbackIndex] == 0x210) {
                found = 1;
                goto done7;
            }
            firstFallbackIndex = (firstFallbackIndex + 1) & 0xFFFF;
        }
        if (!(unit->flags & 4)) {
            equipment = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)unit->id, 2) & 0xFFFF);
            if (equipment >= 0) {
                if (datItemGrantedSkill((s16)equipment) == 0x210) {
                    found = 1;
                    goto done7;
                }
            }
        }
        found = 0;
done7:
        if (found != 0) {
            replacementSkill = 0x210;
            goto tail;
        }
    }
    if (unit->flags & 0x400) {
        goto tail;
    }
    if (!(unit->flags & 4)) {
        if (unit->id >= 0xB) {
            kAssertFail(D_00635938, 0xFA5);
        }
        skills = datPersonaGetSkillsByPcId(unit->id);
    } else {
        if (unit->id >= 0x150) {
            kAssertFail(D_00635938, 0xFA8);
        }
        skills = unit->id * 0x3C + iGpffffb3c4 + 0xE;
    }
    lastFallbackIndex = 0;
    while ((lastFallbackIndex & 0xFFFF) < 8) {
        if (((u16 *)(skills))[(u16)lastFallbackIndex] == 0x20F) {
            found = 1;
            goto done8;
        }
        lastFallbackIndex = (lastFallbackIndex + 1) & 0xFFFF;
    }
    if (!(unit->flags & 4)) {
        equipment = (s32)((u32)(u16)datGetEquippedItemByUnit((s16)unit->id, 2) & 0xFFFF);
        if (equipment >= 0) {
            if (datItemGrantedSkill((s16)equipment) == 0x20F) {
                found = 1;
                goto done8;
            }
        }
    }
    found = 0;
done8:
    if (found != 0) {
        replacementSkill = 0x20F;
    }
tail:
    if (((s16)replacementSkill == -1) && (!(unit->flags & 4)) && (unit->id != 1) && (!(unit->flags & 0x400))) {
        if ((s32)(cmmCommunityRecordValue((u16)(cmmCommunityForArcana((s16)unit->id) & 0xFFFF)) & 0xFFFF) >= 9) {
            replacementSkill = 0x20F;
        }
    }
    return replacementSkill;
}
#pragma opt_loop_invariants off

// Intent: skill value for unit arg0 at slot arg2: a table base plus a random roll within the row's range; [inferred].
// FUN_00243650
u8 datCalcRollSkillValue(u8 *unit, s32 skillId, s32 slotFlags)
{
    DatUnit *unitRecord = (DatUnit *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    s32 value;
    s32 maximumValue;
    s32 rowOffset;
    s32 tableAddress;
    u32 range;
    u8 minimum;
    u8 maximum;
    u8 baseValue;
    u8 *skillEntry;

    if ((u16)skillId >= 0x1B8) {
        kAssertFail(D_00635938, 0x14C5);
    }
    skillEntry = iGpffffb3b8 + (skillId & 0xFFFF) * 0x28;
    if (*(u8 *)skillEntry & 2) {
        value = (s32)(*(u16 *)unit & 4);
        if (value == 0) {
            if (value != 0) {
                if (((DatUnit *)unit)->id >= 0x150) {
                    kAssertFail(D_00635938, 0xFE2);
                }
                rowOffset = unitRecord->id * 0xE8;
                tableAddress = (s32)iGpffffb3cc;
                baseValue = ((DatEnemyExtendedTable *)(rowOffset + tableAddress))->skillValue;
            } else {
                if (((DatUnit *)unit)->id >= 0xB) {
                    kAssertFail(D_00635938, 0xFE6);
                }
                if ((u16)slotFlags & 6) {
                    rowOffset = unitRecord->id * 0x14C;
                    tableAddress = (s32)iGpffffb3c0;
                    baseValue = ((DatCharacterTable *)(rowOffset + tableAddress))->skillValue;
                } else {
                    baseValue = 1;
                }
            }
            return baseValue;
        }
        return 1;
    }
    minimum = ((DatSkillEntry *)(skillEntry))->unknown0F[0];
    maximum = ((DatSkillEntry *)(skillEntry))->unknown0F[1];
    if ((s32)minimum <= 0 || (maximum & 0xFF) <= 0) {
        kAssertFail(D_00635938, 0x14D3);
    }
    maximumValue = maximum & 0xFF;
    if ((s32)minimum >= maximumValue) {
        return minimum;
    }
    range = (maximumValue - minimum) + 1;
    if (range == 0) {
        kAssertFail(D_00635938, 0x17);
    }
    value = minimum & 0xFF;
    return (u8)(value + RpRandom() % range);
}

// Intent: pointer to the 0x13-byte record for id arg0 (below 0x240) in the id table; [inferred].
// FUN_00243840
u8 *datCalcGetIdRecord(s32 skillId)
{
    if ((skillId & 0xFFFF) >= 0x240) {
        kAssertFail(D_00635938, 0x14E4);
    }
    return iGpffffb448 + (u16)skillId * 0x13;
}

// Intent: pointer to the 0x15-byte slot record for index arg0 (0..0x1F) in the slot table; [inferred].
// FUN_002438B0
u8 *datCalcGetSlotRecord(s32 slotIndex)
{
    if ((slotIndex & 0xFF) >= 0x20) {
        kAssertFail(D_00635938, 0x14F2);
    }
    return iGpffffb44c + (u8)slotIndex * 0x15;
}

// Intent: underlying skill id for persona-skill id arg0 (the record from datEntryAt at +0x24, read by datCalcIsFlaggedPersonaSkill); [inferred].
// FUN_00243920
u16 datCalcUnderlyingSkillId(s64 personaSkillId)
{
    /* This query reads only the low halfword of GDataEntry.grantedSkill. */
    return ((u16 *)&((GDataEntry *)((u8 *)datEntryAt((s16)personaSkillId)))->grantedSkill)[0];
}


/* Ported from P3FES src/Main/Battle/Data/datCalc.c FUN_0030c490 (verified MATCH there). */


// Intent: experience reward of the enemy unit arg0 (monster row field +0x1E), added to the battle reward total; [inferred].
// FUN_00243950
u16 datCalcEnemyExp(u8 *unit)
{
    DatUnit *unitRecord = (DatUnit *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    if (((DatUnit *)unit)->id >= 0x150) {
        kAssertFail(D_00635938, 0x1515);
    }
    return ((DatEnemyUnitInit *)(iGpffffb3c4 + unitRecord->id * 0x3C))->exp;
}

/* Enemy reward halfword used as the base of the kind-six money roll. */
// FUN_002439C0
u16 datCalcEnemyMoney(u8 *unit)
{
    DatUnit *unitRecord = (DatUnit *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    if (((DatUnit *)unit)->id >= 0x150) {
        kAssertFail(D_00635938, 0x152A);
    }
    return ((DatEnemyUnitInit *)(iGpffffb3c4 + unitRecord->id * 0x3C))->money;
}

/* Measured: 688/688 bytes and 16 fully resolved relocations.
 * Loop guards mask promoted counters independently of narrowed indexing;
 * the weighted random choice retains its unsigned-halfword boundary. */
// Intent: picks a skill id for a unit: first a flagged entry at +0x34 (chance from +0x36), else a weighted choice over the four slots (weight +0x24); *arg1 is 1 when the flagged entry was taken; [inferred].

// FUN_00243A30
u16 datCalcPickWeightedSkill(u8 *unit, s32 *usedFlaggedSkill)
{
    DatEnemyUnitInit *enemyEntry;
    DatUnit *unitRecord = (DatUnit *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    u8 *entry;
    u16 result;
    s32 total;
    s32 count;
    s32 second_total;
    s32 i;
    u16 value;
    u8 *slot;
    u16 *field;

    if (!(*(u16 *)unit & 4)) {
        kAssertFail(D_00635938, 0x153F);
    }
    if (((DatUnit *)unit)->id >= 0x150) {
        kAssertFail(D_00635938, 0x1540);
    }
    entry = iGpffffb3c4 + unitRecord->id * 0x3C;
    enemyEntry = (DatEnemyUnitInit *)entry;
    result = 0;
    if (usedFlaggedSkill != 0) {
        *usedFlaggedSkill = 0;
    }
    if (((DatEnemyUnitInit *)(entry))->specialSkill != 0) {
        value = ((DatEnemyUnitInit *)(entry))->specialFlag;
        if (value != 0 && datGetFlag(value) != 0 &&
            (s32)((RpRandom() % 100U) & 0xFF) < (s32)((DatEnemyUnitInit *)(entry))->specialChance) {

            result = enemyEntry->specialSkill;
            if (usedFlaggedSkill != 0) {
                *usedFlaggedSkill = 1;
            }
        }
    }
    if (result == 0) {
        total = 0;
        i = 0;
        while ((i & 0xFFFF) < 4) {
            slot = entry + (u16)i * 4;
            value = ((DatEnemyUnitInit *)(slot))->choices[0].skill;
            if (value != 0 &&
                (value < 0x400 || value >= 0x500 ||
                 datGetFlag(0x600 - value) == 0)) {
                total = (total + ((DatEnemyUnitInit *)(slot))->choices[0].weight) & 0xFFFF;
            }
            i = (i + 1) & 0xFFFF;
        }
        count = total & 0xFFFF;
        if (count > 0 &&
            (s32)((RpRandom() % 200U) & 0xFFFF) < count) {
            if (count == 0) {
                kAssertFail(D_00635938, 0x17);
            }
            total = (u16)(RpRandom() % (u32)count);
            second_total = 0;
            i = 0;
            while ((i & 0xFFFF) < 4) {
                slot = entry + (u16)i * 4;
                field = (u16 *)(slot + 0x22);
                value = *field;
                if (value != 0 &&
                    (value < 0x400 || value >= 0x500 ||
                     datGetFlag(0x600 - value) == 0)) {
                    second_total =
                        (second_total + ((DatEnemyUnitInit *)(slot))->choices[0].weight) & 0xFFFF;
                    if (total < second_total) {
                        result = *field;
                        goto done;
                    }
                }
                i = (i + 1) & 0xFFFF;
            }
        }
    }
done:
    return result;
}

/* Test enemy-row flag 4; its gameplay meaning is not established here. */
// FUN_00243CE0
s32 datCalcEnemyHasTableFlag(u8 *unit)
{
    DatUnit *unitRecord = (DatUnit *)unit;
    /* Byte-pointer transport is retained; the field expressions name the established unit and table layouts. */
    if (!(*(u16 *)unit & 4)) {
        return 0;
    }
    if (((DatUnit *)unit)->id >= 0x150) {
        kAssertFail(D_00635938, 0x15C5);
    }
    if (((DatEnemyUnitInit *)(iGpffffb3c4 + unitRecord->id * 0x3C))->flags & 4) {
        return 1;
    }
    return 0;
}

/* Test flag 0x80 at +0x18 of the enemy's extended 0xE8-byte table row. */
// FUN_00243D80
s32 datCalcEnemyHasExtendedFlag(DatUnit *unit)
{
    /* Preserve index-first GP cursor construction; the fields follow the established table layouts. */
    s16 *b;

    if (!(unit->flags & 4)) {
        return 0;
    }
    if (unit->id >= 0x150) {
        kAssertFail(D_00635938, 0x15D2);
    }
    b = (s16 *)iGpffffb3cc;
    if (b[unit->id * 0x74 + 0xC] & 0x80) {
        return 1;
    }
    return 0;
}

// Intent: nonzero when the unit word arg0 has the status-blocked bit (0x200) set; a blocked target takes no status from datCalcInflictStatus; [inferred].
// FUN_00243E30
s32 datCalcIsGuarding(u16 *unitFlags)
{
    return (s32)((*unitFlags & 0x200) != 0);
}

// Intent: set the status-blocked bit (0x200) of unit word arg0; [inferred].
// FUN_00243E50
void datCalcSetStatusBlocked(u16 *unitFlags)
{
    *unitFlags |= 0x200;
}

// Intent: clear the status-blocked bit (0x200) of unit word arg0; [inferred].
// FUN_00243E70
void datCalcClearStatusBlocked(u16 *unitFlags)
{
    *unitFlags &= 0xFDFF;
}

// Intent: class of unit arg0: 4 for the main character (id 1), else the record byte at +0x10; callers compare against 4; [inferred].
// FUN_00243E90
s32 datCalcUnitClass(DatUnit *unit)
{
    if (((DatUnit *)unit)->id == 1) {
        return 4;
    }
    return ((DatUnit *)unit)->aiTactic;
}

// Intent: store class byte arg1 in the unit record at +0x10; [inferred].
// FUN_00243EC0
void datCalcSetUnitClass(DatUnit *unit, s8 tactic)
{
    ((u8 *)unit)[0x10] = (u8)tactic;
}

/* Initialize the ten playable-character records using their configured HP/SP maxima. */
// FUN_00243ED0
void datCalcInitializeCharacters(void)
{
    u16 characterId;

    for (characterId = 1; characterId < 0xb; characterId++) {
        datCalcInitializeCharacter(characterId);
    }
}

// Intent: seeds the per-character tables for character id arg0 (defaults from datCalcMaxHpById and datCalcMaxSpById, then datCalcClearBadStatusById reset to -1).
// FUN_00243F20
void datCalcInitializeCharacter(u16 characterId)
{
    s16 id;
    s16 value;

    id = (s16)characterId;
    value = (s16)datCalcMaxHpById(id);
    datSetUnitHp(id, value);
    value = (s16)datCalcMaxSpById(id);
    datSetUnitSp(id, value);
    datCalcClearBadStatusById(id, -1);
}

/* measured: full body matches byte-for-byte (nd 0, no fndiff ! rows) but
   verify.py reports SIZE_MISMATCH: the window (368B, per
   tools/slus21782_functions.json) extends to 0x244110 and contains the
   unmarked nullsub at 0x244100 (jr $ra; nop; nop; nop), so the retail
   tail beyond my 352B object is nonzero. Fixed 2026-08-03: the src
   marker for the stub below IS a window boundary (per the
   p3-window-nullsub-discovery Case A procedure), so splitting the
   nullsub out in this file shrinks the window to 352B and this MATCHes. */
// Intent: returns 0 when skill arg0's type field for slot arg1 (1: +0x11, 2: +0x14) is one of the blocked types, else 1; [inferred].
// FUN_00243FA0
s32 datCalcSkillTypeAllowed(s32 skillIdArg, s32 channelArg)
{
    u16 effectKind;
    s32 skillId;
    s32 channel;
    s32 allowed;
    u32 checkedKind;

    skillId = skillIdArg & 0xFFFF;
    if ((s32)((u32)skillIdArg & 0xFFFF) < 0 || skillId >= 0x240) {
        kAssertFail(D_00635938, 0x165A);
    }
    if (skillId >= 0x1B8) {
        kAssertFail(D_00635938, 0x165B);
    }
    channel = channelArg & 0xFF;
    switch (channel) {
    case 1:
        effectKind = iGpffffb3b8[(u16)skillIdArg * 0x28 + 0x11];
        break;
    case 2:
        effectKind = iGpffffb3b8[(u16)skillIdArg * 0x28 + 0x14];
        break;
    default:
        kAssertFail(D_00635938, 0x1666);
        break;
    }
    allowed = 1;
    checkedKind = (u16)effectKind & 0xFFFF;
    switch (checkedKind) {
    case 0:
    case 3:
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
    case 13:
    case 15:
        break;
    case 1:
    case 2:
    case 6:
    case 7:
    case 12:
    case 14:
    case 16:
        allowed = 0;
        break;
    default:
        kAssertFail(D_00635938, 0x1682);
        break;
    }
    return allowed;
}
// FUN_00244100
void datCalcNoOperation(void)
{
}
/* Publish skill-power plus term 0x1A; scale the extra term only for an enemy source. */
// FUN_002447C0

void datCalcFormulaTerms13And1A(void)
{
    f32 result;
    f32 extraTerm;

    if (datScriptTargetIsNotEnemy() != 0) {
        result = datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0);
        result += datScriptCalcFloat(0x1A, 0);
    } else {
        extraTerm = datScriptCalcFloat(0x1A, 0);
        result = D_00761260 * extraTerm + datScriptCalcFloat(DAT_SCRIPT_TERM_SKILL_POWER, 0);
    }
    datScriptSetResult(result);
}
/* Publish the base critical-rate term times the source/target luck ratio, with enemy-source scaling. */
// FUN_002449C0

void datCalcFormulaScaledRatio(void)
{
    f32 ratio;
    f32 result;

    if (datScriptTargetIsNotEnemy() != 0) {
        ratio = (50.0f + datScriptCalcFloat(0xD, 4)) /
                   (50.0f + datScriptCalcFloat(0xE, 4));
        result = datScriptCalcFloat(0x14, 0);
        result *= ratio;
    } else {
        ratio = (50.0f + datScriptCalcFloat(0xD, 4)) /
                   (50.0f + datScriptCalcFloat(0xE, 4));
        result = fGpffff811c * mul_f32_ordered(datScriptCalcFloat(0x14, 0), ratio);
    }
    datScriptSetResult(result);
}
/* Publish term 0x15 after the source-side predicate runs its required nonnull assertion. */
// FUN_00244AD0

void datCalcFormulaPassCalc15(void)
{
    datScriptTargetIsNotEnemy();
    datScriptSetResult(datScriptCalcFloat(0x15, 0));
}
/* Publish the weighted agility and luck ratios plus five times the encounter escape count. */
// FUN_00244B10

void datCalcFormulaWeightedRatio(void)
{
    f32 firstRatio;
    f32 result;

    result = 100.0f + datScriptCalcFloat(0xD, 3);
    firstRatio = result / (100.0f + datScriptCalcFloat(0xE, 3));
    result = 100.0f + datScriptCalcFloat(0xD, 4);
    result = 75.0f * (firstRatio * (result / (100.0f + datScriptCalcFloat(0xE, 4))));
    result += 5.0f * datScriptCalcFloat(0x22, 0);
    datScriptSetResult(result);
}
/* Publish the source-luck ratio over the level/status divisor; nonpositive divisors produce one. */
// FUN_00244C10

void datCalcFormulaInverseRatio(void)
{
    f32 result;

    result = 3.0f * (datScriptCalcFloat(1, 0) - 1.0f) + 2.0f;
    result *= datScriptCalcFloat(0x10, 0);
    if (result > 0.0f) {
        result = 50.0f * (datScriptCalcFloat(0xD, 4) / result);
    } else {
        result = 1.0f;
    }
    datScriptSetResult(result);
}
/* Publish the status chance and affinity product times the source/target luck ratio, scaling enemy sources. */
// FUN_00244E20

void datCalcFormulaRatioOfProducts(void)
{
    f32 numerator;
    f32 result;
    f32 quotient;

    if (datScriptTargetIsNotEnemy() != 0) {
        numerator = datScriptCalcFloat(0x12, 0);
        numerator *= datScriptCalcFloat(0x10, 0);
        result = datScriptCalcFloat(0xD, 4);
        result = add_f32_ordered(100.0f, result);
        numerator *= result;
        result = datScriptCalcFloat(0xE, 4);
        result = add_f32_ordered(100.0f, result);
        result = numerator / result;
    } else {
        numerator = datScriptCalcFloat(0x12, 0);
        numerator *= datScriptCalcFloat(0x10, 0);
        result = datScriptCalcFloat(0xD, 4);
        result = add_f32_ordered(100.0f, result);
        numerator *= result;
        result = add_f32_ordered(100.0f, datScriptCalcFloat(0xE, 4));
        quotient = numerator / result;
        result = fGpffff811c * quotient;
    }
    datScriptSetResult(result);
}
