#include "btl_equipment_count_internal.h"
#include "byte_address_internal.h"
#include "operand_order_internal.h"
#include "datCalc_internal.h"
#include "datCalc_unit_internal.h"
#include "datScript_internal.h"
#include "type.h"
#include "include_asm.h"
#include "datPersona_internal.h"
#include "dat_enemy_internal.h"
#include "g_data_entry_internal.h"
#include "member_access.h"

/* measured: retail's calculation helpers compile with loop invariants off, common subexpressions on
 * and propagation on. */
#pragma opt_loop_invariants off
#pragma opt_common_subs on
#pragma opt_propagation on

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


// Uniform random value in 0..limit-1; asserts when limit is zero.
// FUN_00231D70
u32 datCalcRandomBelow(u32 limit)
{
    if (limit == 0) {
        kAssertFail(D_00635938, 0x17);
    }
    return RpRandom() % limit;
}


// Zero the unit record and set its id, with level 1 and HP/SP 1.
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


/* Matches P3FES func_00300410. */


// Stored level for flag-4 units or id 1, otherwise the persona record's level; asserts when zero.
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

// Store the level, clamped to 99 unless flag 4 is set.
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

/* Maximum HP of a unit from its level and skill/equipment bonuses, capped at 999 unless flag 4 is
 * set. */
// FUN_00231F80
#pragma push
/* measured: with common-subexpression and propagation optimizations off, retail computes the array
 * index before adding the base address, and the nested guard keeps the retail compare-and-branch. */
#pragma opt_common_subs off
#pragma opt_propagation off
u16 datCalcMaxHp(DatUnit *unit)
{
    /* Enemy rows are 0x3C bytes; offsets +4/+6 hold HP/SP. */
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
        tableHp = ((DatEnemyUnitInit *)((u8 *)((u32)byteAddressAdd((u32)((baseHp & 0xFFFF) * 0x3C), (u8 *)((u32)base)))))->hp;
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


/* Maximum SP of the unit from its level and SP bonuses; capped at 999 unless flag 4 is set. */
// FUN_00232290
/* Same shape as datCalcMaxHp: a raw s32 temporary, integer base-address addition, and a direct
 * clamp. */
u16 datCalcMaxSp(DatUnit *unit)
{
    /* Enemy rows are 0x3C bytes; offsets +4/+6 hold HP/SP. */
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
        tableSp = ((DatEnemyUnitInit *)((u8 *)((u32)byteAddressAdd((u32)((baseSp & 0xFFFF) * 0x3C), (u8 *)((u32)base)))))->sp;
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
#pragma pop
// Adds hpDelta to the unit's HP, clamped to 0..max HP; returns the new HP.
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


/* Matches P3FES func_00300480. */

// Adds spDelta to the unit's SP, clamped to 0..max SP; returns the new SP.
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
/* Search learned skills and then the accessory-granted skill for a unit. */
static inline s32 datCalcHasRequestedSkill(DatUnit *unit, s32 requestedSkill)
{
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
    if (!(unit->flags & 4)) {
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

// Whether the unit has the skill; wrapper over datCalcHasRequestedSkill.
// FUN_00232730
s32 datCalcHasSkill(DatUnit *unit, s32 skillId)
{
    return datCalcHasRequestedSkill(unit, skillId);
}

// True when the unit lacks flag 4 and its id has a table entry (datItemCount > 0).
// FUN_00232830
s32 datCalcIsStandardUnit(u16 *unitFlags, s64 itemId)
{
    if (*unitFlags & 4) {
        return 0;
    }
    return (datItemCount((s16)itemId) & 0xFF) > 0;
}


// Counts (0..2) the two slots of record characterId whose value equals property.
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

// Counts (0..2) the unit's two slots whose value equals property.
// FUN_00232950
/* measured: propagation off keeps both per-record halfword increments; the count is returned as a
 * full word. */
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


// True when skill id (below 0x1B8) lacks flag bit 2 and has flag bit 1 set.
// FUN_00232A40
s32 datCalcIsSkillAvailable(s32 skillId)
{
    /* Skill rows are 0x28 bytes (DatSkillEntry); accessed by byte offset. */
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

// True for skill ids 0x301..0x3FF whose skill record has flag bit 2 set.
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

/* Returns stat statIndex (0..4) of the unit, clamped to 1..99; fatal error when statIndex >= 5. */
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

/* Return one of the unit's five battle stats, taken from its unit table row or its persona total.
 * Halve it when the unit has the 0x80 bad status and clamp the result to 1..99. */
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

// Bitmask (bits 0..5) of which skills 0x1F9..0x1FE the unit has.
// FUN_00232D80
#pragma push
/* measured: retail hoists loop invariants into the six skill-search preheaders. */
#pragma opt_loop_invariants on
s32 datCalcGetSkillMask(DatUnit *unit)
{
    s32 result;
    result = 0;
    if (datCalcHasRequestedSkill(unit, 0x1F9) != 0) {
        result |= 0x1;
    }
    if (datCalcHasRequestedSkill(unit, 0x1FA) != 0) {
        result |= 0x2;
    }
    if (datCalcHasRequestedSkill(unit, 0x1FB) != 0) {
        result |= 0x4;
    }
    if (datCalcHasRequestedSkill(unit, 0x1FC) != 0) {
        result |= 0x8;
    }
    if (datCalcHasRequestedSkill(unit, 0x1FD) != 0) {
        result |= 0x10;
    }
    if (datCalcHasRequestedSkill(unit, 0x1FE) != 0) {
        result |= 0x20;
    }
    return result;
}
#pragma pop

// Signed 4-bit buff level at buffIndex (0..23); indices 0..4 follow DatPersonaStat
// (St/Ma/En/Ag/Lu).
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
        value = ((DatCalcUnitState *)((offset + (u32)unit)))->buffLevels[0] >> 4;
    }
    else {
        value = ((DatCalcUnitState *)((offset + (u32)unit)))->buffLevels[0] & 0xf;
    }
    if (7 < value) {
        value = (s8)(value - 0xf);
    }
    return value;
}

// Stores signed 4-bit buff level (-7..7) for buffIndex (0..23).
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

// Stores signed 4-bit level in the secondary nibble table for buffIndex.
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

/* Adds the signed delta to the unit's buff level at buffIndex, clamps it to -1..1, sets the buff's
 * flag bit when the result is nonzero, and returns the new level. */
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
            value = (s8)(((DatCalcUnitState *)((offset + (u32)unit)))->buffLevels[0] >> 4);
        } else {
            value = (s8)(((DatCalcUnitState *)((offset + (u32)unit)))->buffLevels[0] & 15);
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
            ptr = (u8 *)(offset + (u32)unit);
            ptr[28] = (ptr[28] & 15) | ((packed & 15) << 4);
        } else {
            ptr = (u8 *)(offset + (u32)unit);
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
            ptr = (u8 *)(offset + (u32)unit);
            ptr[36] &= 15;
        } else {
            ptr = (u8 *)(offset + (u32)unit);
            ptr[36] &= 240;
        }
    } else {
        ((DatCalcUnitState *)unit)->buffFlags |= 1 << index;
    }
    return (s8)result;
}

// Clears buff level buffIndex (0..23) and its flag bit.
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

// Clears all 24 buff levels (flag word and both nibble tables).
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

// Signed buff level for buffIndex below 16, or the flag bit for indices 16..23.
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
            nibble = ((DatCalcUnitState *)((offset + (u32)unit)))->buffLevels[0] >> 4;
        }
        else {
            nibble = ((DatCalcUnitState *)((offset + (u32)unit)))->buffLevels[0] & 0xf;
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

// Multiplier for stat buffIndex: 0-4 read a buff level, 18-19 a status bit; scaled by enemy/party
// table, lead boost and the 0x40000/0x80000 flags.
// FUN_00233BC0
/* The status index must be below 24; all six callers pass constants 0..4, and the third argument is
 * an unused u16 skill ID. */
#pragma push
/* measured: retail does not propagate copies through the status conditional. */
#pragma opt_propagation off
f32 datCalcBuffMultiplier(u8 *unit, s32 buffIndex, u16 unusedSkill)
{
    /* The percentage table uses signed status -1..1 and side-dependent three-byte rows; index is
     * added first to keep retail's load order. */
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
        value = ((DatBuffPercent *)((u32)status + ((u32)byteAddressAdd((enemy & 0xFFFF) * 3, (u8 *)((u32)table)))))->primary[0][1];
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
        value = ((DatBuffPercent *)((u32)status + ((u32)byteAddressAdd((enemy & 0xFFFF) * 3, (u8 *)((u32)table)))))->primary[0][1];
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
        value = *(u8 *)(((u32)byteAddressAdd((enemy & 0xFFFF) * 3, (u8 *)((u32)table))) + MEMBER_OFFSET(DatBuffPercent, secondary[0][1]) - (u32)status);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        if (enemyFlag == 0 && datPersonaLeadBoosted(((DatUnit *)unit)->id) != 0) {
            multiplier = multiplier * 0.75f;
        }
        break;
    case 3:
        table = iGpffffb408; /* Interleaved side rows: bank center 1, indexed by minus signed status. */
        value = *(u8 *)(((u32)byteAddressAdd((enemy & 0xFFFF) * 3, (u8 *)((u32)table))) + MEMBER_OFFSET(DatBuffPercent, primary[0][1]) - (u32)status);
        percentage = (f32)(u32)value;
        multiplier = percentage / 100.0f;
        if (enemyFlag == 0 && datPersonaLeadBoosted(((DatUnit *)unit)->id) != 0) {
            multiplier = multiplier * 0.75f;
        }
        break;
    case 4:
        table = iGpffffb408;
        value = ((DatBuffPercent *)((u32)status + ((u32)byteAddressAdd((enemy & 0xFFFF) * 3, (u8 *)((u32)table)))))->secondary[0][1];
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

/* Returns true when the unit has a buff (>0) or debuff (<0) on any stat selected by mask; each s64
 * flag is re-booleanized to match retail's comparison sequence. */
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

// Applies signed buff delta to stats selected by mask (bit pairs for up and down on stats 0..4).
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

// Clears the buff and secondary levels of each index flagged in consumedFlags, then clears that
// mask.
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

/* Read a signed secondary level from the indexed packed nibble. */
static inline s8 datCalcGetSecondaryLevel(DatUnit *unit, u8 index)
{
    /* Packed-byte addressing is intentional: getters/setters accept 24 indices, so indices 16..23 overlap the next state field rather than a separate bounded array. */
    u16 offset;
    /* Retail converts to a signed byte where the two branches merge. */
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

/* Update the indexed secondary-level nibble while retaining its neighbor. */
static inline void datCalcSetSecondaryLevel(DatUnit *unit, u8 index, s8 level)
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
        ((DatCalcUnitState *)ptr)->secondaryLevels[0] = (((DatCalcUnitState *)ptr)->secondaryLevels[0] & 15) | ((level & 15) << 4);
    } else {
        ptr = (u8 *)unit + offset;
        ((DatCalcUnitState *)ptr)->secondaryLevels[0] = (((DatCalcUnitState *)ptr)->secondaryLevels[0] & 240) | (level & 15);
    }
}

/* Raises the secondary level (capped at 15) of every active buff in slots 0..15 by one. */
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
        level = datCalcGetSecondaryLevel(unit, index);
        if (active != 0 && level < 15)
            datCalcSetSecondaryLevel(unit, index, level + 1);
    }
}

#pragma push
/* measured: retail hoists the signed threshold comparison out of the buff scan loop. */
#pragma opt_loop_invariants on
// Returns the index of the first active buff in 0..15 at or above a threshold (3, doubled for
// flag-4 units with table bit 0x1000), else -1.
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
        level = datCalcGetSecondaryLevel((DatUnit *)unit, index);
        if (active != 0 && level >= threshold)
            return (s8)index;
    }
    return -1;
}
/* Equipment queries shared by damage, hit and critical calculations. */
/* Count matching equipment properties for party units; enemy units contribute none. */
static inline u16 datCalcCountEquipmentProperty(u8 *unit, s32 property)
{
    if (((DatUnit *)unit)->flags & 4) {
        return 0;
    }
    return datCalcCountIdSlotsWithValue(((DatUnit *)unit)->id, property);
}

/* Test the two equipment slots for a party-unit item property. */
static inline s32 datCalcHasEquipmentProperty(u8 *unit, s32 property)
{
    u16 character;

    if (((DatUnit *)unit)->flags & 4) {
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

/* measured: kept as a separate inline helper because retail code generation for datCalcSkillAmount
 * depends on this hoisting shape. Read a party unit accessory property; enemy units have no
 * accessory. */
static inline u16 datCalcAccessoryProperty(DatUnit *unit)
{
    s16 character;
    if (unit->flags & 4) {
        return 0;
    }
    character = (s16)((DatUnit *)((u8 *)unit))->id;
    if (character >= 11) {
        kAssertFail(D_00635938, 0x291);
    }
    return datItemValue(datGetEquippedItemByUnit(character, 2)) & 0xFFFF;
}

/* Convert a checked party accessory percentage into a fractional multiplier. */
static inline f32 datCalcAccessoryFraction(DatUnit *unit)
{
    extern u16 datItemAccessoryPercent(s16 itemId);
    s16 character;
    s32 percent;
    if (unit->flags & 4) {
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


/* Signed amount of skill skillId from source on target for channel (1 HP, 2 SP): healing positive,
 * damage negative, scaled by effect type, attack/defense, element and accessory bonuses. K&R
 * formals keep the caller's promoted integer interface. */
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
        record = (u8 *)((u32)byteAddressAdd(((u32)skillId % 0x10000U) * 0x28, (u8 *)((u32)iGpffffb3b8)));
        power = ((DatSkillEntry *)record)->power;
        effect = ((DatSkillEntry *)record)->effectKind;
        bonus = 0;
        current = ((DatUnit *)target)->hp;
        maximum = datCalcMaxHp((DatUnit *)target);
        break;
    case 2:
        record = (u8 *)((u32)byteAddressAdd(((u32)skillId % 0x10000U) * 0x28, (u8 *)((u32)iGpffffb3b8)));
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
        healing = operandOrderAdd((s32)(RpRandom() % healing), (s16)bonus);
        break;
    case 9:
        healing = operandOrderAdd((s32)(current * power / 100), (s16)bonus);
        if (healing <= 0) {
            healing = 1;
        }
        break;
    case 11:
        healing = operandOrderAdd((s32)(maximum * power / 100), (s16)bonus);
        if (healing <= 0) {
            healing = 1;
        }
        break;
    case 2:
/* Read the damage class from the skill table. */
        switch ((iGpffffb3b8[(u32)(u16)skillId * sizeof(DatSkillEntry) + MEMBER_OFFSET(DatSkillEntry, damageClass)])) {
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
        damage = operandOrderAdd((s32)(current * power / 100), (s16)bonus);
        if (damage <= 0 && power > 0) {
            damage = 1;
        }
        break;
    case 10:
        damage = operandOrderAdd((s32)(maximum * power / 100), (s16)bonus);
        if (damage <= 0 && power > 0) {
            damage = 1;
        }
        break;
    case 1:
    case 12:
    case 14:
        switch ((iGpffffb3b8[(u32)(u16)skillId * sizeof(DatSkillEntry) + MEMBER_OFFSET(DatSkillEntry, damageClass)])) {
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
        damage = operandOrderAdd((s32)datScriptRunCalc(DAT_SCRIPT_CALC_PHYSICAL_DAMAGE_SCALED, (u16 *)source, (u16 *)target, skillId, channel), (s16)bonus);
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
            if ((datCalcAccessoryProperty((DatUnit *)source) & 0xFFFF) == 0xBD) {
                elemental *= 1.0f + datCalcAccessoryFraction((DatUnit *)source);
            }
            if (datCalcHasRequestedSkill((DatUnit *)source, 0x1E7) || (datCalcCountEquipmentProperty(source, 0x44) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (datCalcHasRequestedSkill((DatUnit *)source, 0x1E8)) {
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
            if ((datCalcAccessoryProperty((DatUnit *)source) & 0xFFFF) == 0xBE) {
                elemental *= 1.0f + datCalcAccessoryFraction((DatUnit *)source);
            }
            if (datCalcHasRequestedSkill((DatUnit *)source, 0x1E9) || (datCalcCountEquipmentProperty(source, 0x45) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (datCalcHasRequestedSkill((DatUnit *)source, 0x1EA)) {
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
            if ((datCalcAccessoryProperty((DatUnit *)source) & 0xFFFF) == 0xC0) {
                elemental *= 1.0f + datCalcAccessoryFraction((DatUnit *)source);
            }
            if (datCalcHasRequestedSkill((DatUnit *)source, 0x1EB) || (datCalcCountEquipmentProperty(source, 0x46) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (datCalcHasRequestedSkill((DatUnit *)source, 0x1EC)) {
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
            if ((datCalcAccessoryProperty((DatUnit *)source) & 0xFFFF) == 0xBF) {
                elemental *= 1.0f + datCalcAccessoryFraction((DatUnit *)source);
            }
            if (datCalcHasRequestedSkill((DatUnit *)source, 0x1ED) || (datCalcCountEquipmentProperty(source, 0x47) & 0xFFFF)) {
                elemental *= 1.25f;
            }
            if (datCalcHasRequestedSkill((DatUnit *)source, 0x1EE)) {
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
        if (datCalcHasRequestedSkill((DatUnit *)target, 0x209)) {
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
                if (datCalcHasEquipmentProperty(target, 0x5F)) {
                    attack *= fGpffff82c0;
                }
                if (datCalcHasEquipmentProperty(target, 0x60)) {
                    attack *= fGpffff811c;
                }
                if (datCalcHasEquipmentProperty(target, 0x61)) {
                    attack *= fGpffff809c;
                }
                break;
            }
            switch (element) {
            case 1:
            case 2:
            case 3:
            case 4:
                if (datCalcHasEquipmentProperty(target, 0x6E)) {
                    attack *= fGpffff82c0;
                }
                if (datCalcHasEquipmentProperty(target, 0x6F)) {
                    attack *= fGpffff811c;
                }
                if (datCalcHasEquipmentProperty(target, 0x70)) {
                    attack *= fGpffff809c;
                }
                break;
            }
            switch (element) {
            case 1:
                if ((datCalcAccessoryProperty((DatUnit *)target) & 0xFFFF) == 0xC1) {
                    attack *= 1.0f - datCalcAccessoryFraction((DatUnit *)target);
                }
                if (datCalcHasEquipmentProperty(target, 0x62)) {
                    attack *= fGpffff82c0;
                }
                if (datCalcHasEquipmentProperty(target, 0x63)) {
                    attack *= fGpffff811c;
                }
                if (datCalcHasEquipmentProperty(target, 0x64)) {
                    attack *= fGpffff809c;
                }
                break;
            case 2:
                if ((datCalcAccessoryProperty((DatUnit *)target) & 0xFFFF) == 0xC2) {
                    attack *= 1.0f - datCalcAccessoryFraction((DatUnit *)target);
                }
                if (datCalcHasEquipmentProperty(target, 0x65)) {
                    attack *= fGpffff82c0;
                }
                if (datCalcHasEquipmentProperty(target, 0x66)) {
                    attack *= fGpffff811c;
                }
                if (datCalcHasEquipmentProperty(target, 0x67)) {
                    attack *= fGpffff809c;
                }
                break;
            case 3:
                if ((datCalcAccessoryProperty((DatUnit *)target) & 0xFFFF) == 0xC4) {
                    attack *= 1.0f - datCalcAccessoryFraction((DatUnit *)target);
                }
                if (datCalcHasEquipmentProperty(target, 0x6B)) {
                    attack *= fGpffff82c0;
                }
                if (datCalcHasEquipmentProperty(target, 0x6C)) {
                    attack *= fGpffff811c;
                }
                if (datCalcHasEquipmentProperty(target, 0x6D)) {
                    attack *= fGpffff809c;
                }
                break;
            case 4:
                if ((datCalcAccessoryProperty((DatUnit *)target) & 0xFFFF) == 0xC3) {
                    attack *= 1.0f - datCalcAccessoryFraction((DatUnit *)target);
                }
                if (datCalcHasEquipmentProperty(target, 0x68)) {
                    attack *= fGpffff82c0;
                }
                if (datCalcHasEquipmentProperty(target, 0x69)) {
                    attack *= fGpffff811c;
                }
                if (datCalcHasEquipmentProperty(target, 0x6A)) {
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
        if (datCalcHasRequestedSkill((DatUnit *)source, 0x20E)) {
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


// Signed per-unit roll for a kind-6 skill (else 0): level and battle-stat base times a random
// 90-110% factor, positive on the monster side.
// FUN_002384B0
s32 datCalcSkillRoll(s32 skillId, DatUnit *unitArg, s32 targetAddress)
{
    /* measured: retail compiled this caller against the s32-returning prototype used elsewhere, so
     * the u8 return of datCalcGetBattleStat is not re-masked. */
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

/* The u16 skillId is promoted to s32 under C89 old-style parameters, and the callee does the
 * narrowing. The five dynamic callers pass the full word. */
// FUN_00238940
#pragma push
/* measured: retail hoists loop invariants in this function. */
#pragma opt_loop_invariants on
s32 datCalcInflictStatus(skillId, source, target, options)
u16 skillId;
DatUnit *source;
DatUnit *target;
s32 options;
{
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
        ((entry = iGpffffb3b8, mode = *(u8 *)((u32)entry + MEMBER_OFFSET(DatSkillEntry, mode18) + (u32)offset), mode == 1) || mode == 3)) {
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
                if (datCalcHasRequestedSkill(source, 0x217)) multiplier *= 1.25f;
                break;
            case 8:
                if (datCalcHasRequestedSkill(source, 0x216)) multiplier *= 1.25f;
                break;
            case 10:
                if (datCalcHasRequestedSkill(source, 0x21A)) multiplier *= 1.25f;
                break;
            case 6:
                if (datCalcHasRequestedSkill(source, 0x21F)) multiplier *= 1.25f;
                break;
            case 7:
                if (datCalcHasRequestedSkill(source, 0x220)) multiplier *= 1.25f;
                break;
            case 13:
                if (datCalcHasRequestedSkill(source, 0x218)) multiplier *= 1.25f;
                break;
            case 15:
                if (datCalcHasRequestedSkill(source, 0x219)) multiplier *= 1.25f;
                break;
            case 11:
                if (datCalcHasRequestedSkill(source, 0x21B)) multiplier *= 1.25f;
                break;
            case 14:
                if (datCalcHasRequestedSkill(source, 0x21D)) multiplier *= 1.25f;
                break;
            }
            if (death == 0 && datCalcHasRequestedSkill(source, 0x21E)) {
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
// Status-effect result of a skill: 0x80000 for the special kind, a hit-formula result for ailment-
// type skills, else 0.
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

// Hit-formula result when the skill's table kind is 2 and its guard byte is 100 (a sure hit); 0
// otherwise.
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

// Applies a skill to the target: HP and SP deltas clamped to max, status bits into the unit status
// word, dead at 0 HP; returns 1.
// FUN_00239F50
s32 datCalcApplySkillEffect(s32 skillId, u8 *source, u8 *target, s32 options)
{
    DatUnit *targetRecord = (DatUnit *)(target);
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


// Effect flag mask (1 HP, 2 SP, 4 status) for a skill on a target; 0 when the hit misses, 0xFFFF
// for a full effect.
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

// Fills the HP amount, SP amount and infliction outcome for a skill and clears their +0x18 fields;
// returns 0 if either unit is null.
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

// Skill-slot value from a packed table entry, scaled x5 per byte, with fallback constants when the
// low half is zero.
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
/* measured: retail hoists loop invariants in this function. */
#pragma opt_loop_invariants on
// Resistance and nullify flags of a unit against a status element; callers test the 0x08000000 and
// 0x07000000 groups.
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
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1B8);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1B9);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1BA);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1BB);
        if (found != 0) {
            passiveFlags |= 0x4000000;
        }
        break;
    }
    switch (element) {
    case 1:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1BC);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1BD);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1BE);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1BF);
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
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C0);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C1);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C2);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C3);
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
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C4);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C5);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C6);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C7);
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
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C8);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1C9);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1CA);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1CB);
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
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1CC);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1CD);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1CE);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        break;
    case 7:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1CF);
        if (found != 0) {
            passiveFlags |= 0x10000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D0);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D1);
        if (found != 0) {
            passiveFlags |= 0x2000000;
        }
        break;
    case 9:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x225);
        if (found != 0) {
            goto acc_9_b;
        }
        found = datCalcHasEquipmentProperty(unit, 0x4C);
        if (found == 0) {
            goto skp_9_b;
        }
acc_9_b:
        passiveFlags |= 0x10000000;
skp_9_b:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D7);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 8:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x226);
        if (found != 0) {
            goto acc_8_b;
        }
        found = datCalcHasEquipmentProperty(unit, 0x4B);
        if (found == 0) {
            goto skp_8_b;
        }
acc_8_b:
        passiveFlags |= 0x10000000;
skp_8_b:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D2);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 10:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x227);
        if (found != 0) {
            goto acc_10_b;
        }
        found = datCalcHasEquipmentProperty(unit, 0x4D);
        if (found == 0) {
            goto skp_10_b;
        }
acc_10_b:
        passiveFlags |= 0x10000000;
skp_10_b:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D5);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 13:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x228);
        if (found != 0) {
            goto acc_13_b;
        }
        found = datCalcHasEquipmentProperty(unit, 0x50);
        if (found == 0) {
            goto skp_13_b;
        }
acc_13_b:
        passiveFlags |= 0x10000000;
skp_13_b:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D3);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 15:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x22C);
        if (found != 0) {
            goto acc_15_b;
        }
        found = datCalcHasEquipmentProperty(unit, 0x52);
        if (found == 0) {
            goto skp_15_b;
        }
acc_15_b:
        passiveFlags |= 0x10000000;
skp_15_b:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D4);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 11:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x22A);
        if (found != 0) {
            goto acc_11_b;
        }
        found = datCalcHasEquipmentProperty(unit, 0x4E);
        if (found == 0) {
            goto skp_11_b;
        }
acc_11_b:
        passiveFlags |= 0x10000000;
skp_11_b:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D6);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 14:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x229);
        if (found != 0) {
            goto acc_14_b;
        }
        found = datCalcHasEquipmentProperty(unit, 0x51);
        if (found == 0) {
            goto skp_14_b;
        }
acc_14_b:
        passiveFlags |= 0x10000000;
skp_14_b:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D9);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    case 12:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x22B);
        if (found != 0) {
            goto acc_12_b;
        }
        found = datCalcHasEquipmentProperty(unit, 0x4F);
        if (found == 0) {
            goto skp_12_b;
        }
acc_12_b:
        passiveFlags |= 0x10000000;
skp_12_b:
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1D8);
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
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1DA);
        if (found != 0) {
            passiveFlags |= 0x1000000;
        }
        break;
    }
    if (element != 5) {
        found = datCalcHasRequestedSkill((DatUnit *)unit, 0x1DB);
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

// Returns the element bit (1 << (element+1)) for element index 0..0x12; callers mask it against
// element and status sets.
// FUN_0023D6E0
s32 datCalcElementBit(s16 element)
{
    if (element >= 0x13) {
        kAssertFail(D_00635938, 0xE47);
    }
    return 1 << (element + 1);
}


// Element index that a status bit counts as for a skill (element-6 skills always give 6); used for
// the resistance lookup.
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

// Element index of a skill on a unit: the monster row byte, the persona stat, or the skill-table
// byte for non-unit skills.
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
/* SP cost of a skill for a unit after equipment reduction and the cost limit; percentage products
 * wrap to 32 bits before signed division. */
// FUN_0023D9B0
#pragma push
/* measured: retail code needs CSE and propagation off with loop hoisting on; for-loop forms do not
 * reproduce it. */
#pragma opt_common_subs off
#pragma opt_loop_invariants on
#pragma opt_propagation off
u32 datCalcSkillCost(DatUnit *unit, s32 skillId)
{
    /* Skill rows are addressed as bytes to keep retail load order; see DatSkillEntry for the
     * 0x28-byte layout. */
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
// Threshold kind byte of a skill from the skill table (1 = HP, 2 = SP).
// FUN_0023DD90
u16 datCalcThresholdKind(DatUnit *unusedUnit, s32 skillId)
{
    DatSkillEntry *base = (DatSkillEntry *)iGpffffb3b8;
    return base[(skillId & 0xFFFF)].kind03;
}


// Threshold trigger for a skill on a unit: 0 none, 4 when unit flag 8 is set, 1 for HP threshold
// crossed, 2 for SP threshold.
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
    u8 *base;

    if ((skillId & 0xFFFF) >= 0x1B8) {
        kAssertFail(D_00635938, 0xF5E);
    }
    base = iGpffffb3b8 + (u16)skillId * 0x28;
    return (base[0] & 2) != 0;
}

// Default skill id for a unit; a stub in retail that always returns 0, which callers treat as "no
// skill".
// FUN_0023DFE0
s32 datCalcDefaultSkillId(DatUnit *unit)
{
    return 0;
}

// Picks a random special-item skill (0xC0-0xC5) from the unit's skill list; returns 0 when there is
// none.
// FUN_0023DFF0
#pragma push
/* measured: retail hoists loop-invariant values out of the special-item scan loop. */
#pragma opt_loop_invariants on
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

// Pointer to the unit's 8-entry skill-id list (persona skills by pc id, or the monster row's
// slots).
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


// First persona id of the unit (0 for flag-4 units).
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

// Base skill value for a unit and slot: monster row for flag-4 units, else persona row when slot
// bit 6 is set, else 1; datCalcRollSkillValue adds to it.
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

/* Query one of three weapon properties, substituting enemy-row values for enemies. */
// FUN_0023E3E0
#pragma push
/* measured: propagation is off so retail loads the enemy-table base once before the 0x3C-stride row
 * indexing. */
#pragma opt_propagation off
u16 datCalcGetWeaponProperty(u16 *unitWords, s32 propertyKind)
{
    u16 ret;
    if (unitWords[0] & 0x4) {
        u16 field0 = unitWords[1];
        if (field0 >= 0x150) {
            kAssertFail(D_00635938, 0x1002);
        }
        switch (propertyKind & 0xFF) {
        case 0:
            return ((DatEnemyUnitInit *)(((u32)byteAddressAdd((field0 & 0xFFFF) * 0x3C, (u8 *)((u32)iGpffffb3c4)))))->weaponPower;
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
#pragma pop
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
/* measured: retail hoists loop invariants in the shared skill search. */
#pragma opt_loop_invariants on
/* Select the party persona or enemy initialization skill table. */
static inline u8 *datCalcFixedSkillTable(u8 *unit)
{
    if (!(((DatUnit *)unit)->flags & 4)) {
        if (((DatUnit *)unit)->id >= 0xB) {
            kAssertFail(D_00635938, 0xFA5);
        }
        return datPersonaGetSkillsByPcId(MEMBER(u16, unit, DatUnit, id));
    }
    if (MEMBER(u16, unit, DatUnit, id) >= 0x150) {
        kAssertFail(D_00635938, 0xFA8);
    }
    return (u8 *)((DatEnemyUnitInit *)iGpffffb3c4)[MEMBER(u16, unit, DatUnit, id)].skills;
}

/* Search eight fixed skills and then the party accessory-granted skill. */
static inline s32 datCalcHasFixedSkill(u8 *unit, s32 requestedSkill)
{
    s32 skill;
    s32 index;
    u8 *table;
    s32 equipment;

    table = datCalcFixedSkillTable(unit);
    index = 0;
    skill = requestedSkill & 0xFFFF;
    while ((index & 0xFFFF) < 8) {
        if (skill == ((u16 *)(table))[(u16)index]) {
            return 1;
        }
        index = (index + 1) & 0xFFFF;
    }
    if (!(((DatUnit *)unit)->flags & 4)) {
        equipment = (u32)(u16)datGetEquippedItemByUnit((s16)((DatUnit *)(unit))->id, 2);
        if (equipment >= 0) {
            if (skill == datItemGrantedSkill((s16)equipment)) {
                return 1;
            }
        }
    }
    return 0;
}

/* Old-style definition promotes the u16 skill parameter to the s32 call interface; cases 1 and 14
 * share an early result exit. */
s32 datCalcResolveSkillHit(u8 *, u8 *, s32, s32);
// Outcome code of the skill from source on target; 0x200 means reflected and is re-resolved against
// the source.
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
            enemyElement = ((DatEnemyUnitInit *)((u32)byteAddressAdd(((DatUnit *)source)->id * 0x3C, (u8 *)((u32)iGpffffb3c4))))->weaponElement;
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
                if (datCalcHasFixedSkill(target, 0x1F8) ||
                    (datCalcCountEquipmentProperty(target, 0x4A) & 0xFFFF)) {
                    counterRate = 20;
                    evadeCause = 0x11F8;
                } else {
                    if (datCalcHasFixedSkill(target, 0x1F7) ||
                        (datCalcCountEquipmentProperty(target, 0x49) & 0xFFFF)) {
                        counterRate = 15;
                        evadeCause = 0x11F7;
                    } else {
                        if (datCalcHasFixedSkill(target, 0x1F6) ||
                            (datCalcCountEquipmentProperty(target, 0x48) & 0xFFFF)) {
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
            if (datCalcHasFixedSkill(target, 0x1DD)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11DD;
            } else if (datCalcHasFixedSkill(target, 0x1DC)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11DC;
            }
            break;
        case 1:
            if (datCalcHasFixedSkill(target, 0x1DF)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11DF;
            } else if (datCalcHasFixedSkill(target, 0x1DE)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11DE;
            }
            break;
        case 2:
            if (datCalcHasFixedSkill(target, 0x1E1)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E1;
            } else if (datCalcHasFixedSkill(target, 0x1E0)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E0;
            }
            break;
        case 4:
            if (datCalcHasFixedSkill(target, 0x1E3)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E3;
            } else if (datCalcHasFixedSkill(target, 0x1E2)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E2;
            }
            break;
        case 3:
            if (datCalcHasFixedSkill(target, 0x1E5)) {
                evadeMultiplier *= iGpffff8170;
                evadeCause = 0x11E5;
            } else if (datCalcHasFixedSkill(target, 0x1E4)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E4;
            }
            break;
        }
        if (evadeMultiplier == 1.0f && (elementMask & 0x3C)) {
            if (datCalcHasFixedSkill(target, 0x1E6)) {
                evadeMultiplier *= fGpffff80cc;
                evadeCause = 0x11E6;
            }
        }
        if (datCalcHasFixedSkill(target, 0x209)) {
            return 1;
        }
        if (datCalcHasFixedSkill(target, 0x208)) {
            evadeMultiplier *= 0.5f;
        }
    }
    baseRate = datScriptRunCalc(DAT_SCRIPT_CALC_HIT_RATE, (u16 *)source, (u16 *)target, skillId, 0);
    if (!(*(u16 *)target & 4)) {
        switch (element) {
        case 0:
            if (datCalcHasEquipmentProperty(target, 0x74)) {
                equipmentBonus += 10;
            }
            if (datCalcHasEquipmentProperty(target, 0x75)) {
                equipmentBonus += 15;
            }
            if (datCalcHasEquipmentProperty(target, 0x76)) {
                equipmentBonus += 20;
            }
            break;
        }
        switch (element) {
        case 1: case 2: case 3: case 4:
            if (datCalcHasEquipmentProperty(target, 0x83)) {
                equipmentBonus += 10;
            }
            if (datCalcHasEquipmentProperty(target, 0x84)) {
                equipmentBonus += 15;
            }
            if (datCalcHasEquipmentProperty(target, 0x85)) {
                equipmentBonus += 20;
            }
            break;
        }
        switch (element) {
        case 1:
            if (datCalcHasEquipmentProperty(target, 0x77)) {
                equipmentBonus += 10;
            }
            if (datCalcHasEquipmentProperty(target, 0x78)) {
                equipmentBonus += 15;
            }
            if (datCalcHasEquipmentProperty(target, 0x79)) {
                equipmentBonus += 20;
            }
            break;
        case 2:
            if (datCalcHasEquipmentProperty(target, 0x7A)) {
                equipmentBonus += 10;
            }
            if (datCalcHasEquipmentProperty(target, 0x7B)) {
                equipmentBonus += 15;
            }
            if (datCalcHasEquipmentProperty(target, 0x7C)) {
                equipmentBonus += 20;
            }
            break;
        case 3:
            if (datCalcHasEquipmentProperty(target, 0x80)) {
                equipmentBonus += 10;
            }
            if (datCalcHasEquipmentProperty(target, 0x81)) {
                equipmentBonus += 15;
            }
            if (datCalcHasEquipmentProperty(target, 0x82)) {
                equipmentBonus += 20;
            }
            break;
        case 4:
            if (datCalcHasEquipmentProperty(target, 0x7D)) {
                equipmentBonus += 10;
            }
            if (datCalcHasEquipmentProperty(target, 0x7E)) {
                equipmentBonus += 15;
            }
            if (datCalcHasEquipmentProperty(target, 0x7F)) {
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


/* measured: declaring idx after lvl, repeating the searches, and converting before the bonus follow
 * retail; opt_loop_invariants scopes the searches. The fifth argument is unused by retail. */

/* The skill is treated as u16 inside this C89 definition, and the promoted s32 interface keeps
 * existing callers working. */
s32 datCalcHitResult(u8 *, u8 *, s32, s32, s32);
// Skill result for attacker on target: 2 for a critical, 4 when the affinity is weak (AFF_WEAK), 1
// otherwise.
// FUN_002411A0
s32 datCalcHitResult(source, target, skillId, outcome, unusedMode)
u8 *source;
u8 *target;
u16 skillId;
s32 outcome;
s32 unusedMode;
{
    /* Skill rows are addressed by byte offset; DatSkillEntry in datCalc_internal.h documents the
     * 0x28-byte layout. */
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
        if (datCalcHasFixedSkill(target, 0x206)) {
            f20 = f20 * 0.5f;
        }
        if (datCalcHasFixedSkill(source, 0x207)) {
            f20 = f20 * 2.0f;
        }
        scaled = (s32)((f32)base * f20);
        bonus = 0;
        if (tmp22 >= 0x1B8) {
            kAssertFail(D_00635938, 0xF5E);
        }
        if ((u8)((((DatSkillEntry *)(iGpffffb3b8 + idx))->flags00 & 2) != 0)) {
            if (datCalcHasEquipmentProperty(source, 0x3C)) {
                bonus += 5;
            }
            if (datCalcHasEquipmentProperty(source, 0x3D)) {
                bonus += 10;
            }
            if (datCalcHasEquipmentProperty(source, 0x3E)) {
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

/* Returns true unless the target's level bit for the skill is in 0xE0001 (null, absorb or reflect);
 * other early exits return false. The fifth argument is passed by datCalcSkillAllowedForMode but
 * unused. */
// FUN_00241BC0
s32 datCalcSkillAppliesToTarget(source, target, skillId, channel, unusedMode)
u8 *source;
u8 *target;
s32 skillId;
s32 channel;
s32 unusedMode;
{
    /* Skill rows are addressed by byte offset; DatSkillEntry in datCalc_internal.h documents the
     * 0x28-byte layout. */
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
// True when datCalcSkillAppliesToTarget holds and the skill's category is 9 or 10, or mode is 2 or
// 4.
// FUN_00241DE0
s32 datCalcSkillAllowedForMode(DatUnit *source, DatUnit *target, s32 skillId, s32 channel, s32 mode)
{
    /* Skill rows are addressed by byte offset; DatSkillEntry in datCalc_internal.h documents the
     * 0x28-byte layout. */
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

// Rolls a support-skill hit for source on target, with a chance set by passive flags 0x71, 0x72 and
// 0x73 (5, 50, 32 or 0).
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

// Rolls a skill's success on the target from the skill's chance byte, raised for flagged units and
// for skill 0x21C.
// FUN_00242360
#pragma push
/* measured: retail loads the loop-invariant compare constant once before the loop instead of
 * rebuilding it in the body. */
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
#pragma pop

// Chance (0..100) that an ailment of this level lands on the unit: 0 for level -1 or bit 0, 100 for
// bits 0xE0000, else the skill-table result.
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

/* Returns the effective skill id for a unit given a base skill: a replacement id found in the
 * unit's slots (0x20F-0x231 families, some by random roll), or -1 when none applies. */
// FUN_00242990
#pragma push
/* measured: retail hoists loop-invariant values out of the skill-search loops. */
#pragma opt_loop_invariants on
s32 datCalcResolveSkillId(DatUnit *unit, s32 baseSkill)
{
    /* Skill rows are addressed by byte offset; DatSkillEntry in datCalc_internal.h documents the
     * 0x28-byte layout. */
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
            value = ((DatEnemyUnitInit *)((u8 *)((u32)byteAddressAdd(unit->id * 0x3C, (u8 *)((u32)iGpffffb3c4)))))->weaponElement;
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
#pragma pop

// Skill value for the unit at a slot: a table base plus a random roll within the row's range.
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

// Pointer to the 0x13-byte record for an id below 0x240 in the id table.
// FUN_00243840
u8 *datCalcGetIdRecord(s32 skillId)
{
    if ((skillId & 0xFFFF) >= 0x240) {
        kAssertFail(D_00635938, 0x14E4);
    }
    return iGpffffb448 + (u16)skillId * 0x13;
}

// Pointer to the 0x15-byte slot record for index 0..0x1F in the slot table.
// FUN_002438B0
u8 *datCalcGetSlotRecord(s32 slotIndex)
{
    if ((slotIndex & 0xFF) >= 0x20) {
        kAssertFail(D_00635938, 0x14F2);
    }
    return iGpffffb44c + (u8)slotIndex * 0x15;
}

// Underlying skill id for a persona-skill id, taken from the entry's grantedSkill field.
// FUN_00243920
u16 datCalcUnderlyingSkillId(s64 personaSkillId)
{
    /* This query reads only the low halfword of GDataEntry.grantedSkill. */
    return ((u16 *)&((GDataEntry *)((u8 *)datEntryAt((s16)personaSkillId)))->grantedSkill)[0];
}


/* Matches P3FES func_0030c490. */


// Experience reward of the enemy unit, taken from its monster row and added to the battle reward
// total.
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

/* Picks a skill id for a unit: first a flagged entry (chance from its rate field), else a weighted
 * choice over the four slots; *usedFlaggedSkill is 1 when the flagged entry was taken. */

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

// Nonzero when the unit word has the status-blocked bit (0x200) set; a blocked target takes no
// status from datCalcInflictStatus.
// FUN_00243E30
s32 datCalcIsGuarding(u16 *unitFlags)
{
    return (s32)((*unitFlags & 0x200) != 0);
}

// Set the status-blocked bit (0x200) of the unit word.
// FUN_00243E50
void datCalcSetStatusBlocked(u16 *unitFlags)
{
    *unitFlags |= 0x200;
}

// Clear the status-blocked bit (0x200) of the unit word.
// FUN_00243E70
void datCalcClearStatusBlocked(u16 *unitFlags)
{
    *unitFlags &= 0xFDFF;
}

// Class of the unit: 4 for the main character (id 1), else its aiTactic byte; callers compare
// against 4.
// FUN_00243E90
s32 datCalcUnitClass(DatUnit *unit)
{
    if (((DatUnit *)unit)->id == 1) {
        return 4;
    }
    return ((DatUnit *)unit)->aiTactic;
}

// Store the class byte in the unit record's aiTactic field.
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

// Seeds the per-character tables for a character id with max HP and SP, then clears bad status with
// -1.
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

/* Returns 0 when the skill's type field for the given channel (1 or 2) is one of the blocked types,
 * else 1. */
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
void datCalcFormulaNoop(void)
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
        result = fGpffff811c * operandOrderMultiply(datScriptCalcFloat(0x14, 0), ratio);
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
        result = operandOrderAddFloat(100.0f, result);
        numerator *= result;
        result = datScriptCalcFloat(0xE, 4);
        result = operandOrderAddFloat(100.0f, result);
        result = numerator / result;
    } else {
        numerator = datScriptCalcFloat(0x12, 0);
        numerator *= datScriptCalcFloat(0x10, 0);
        result = datScriptCalcFloat(0xD, 4);
        result = operandOrderAddFloat(100.0f, result);
        numerator *= result;
        result = (100.0f + datScriptCalcFloat(0xE, 4));
        quotient = numerator / result;
        result = fGpffff811c * quotient;
    }
    datScriptSetResult(result);
}
