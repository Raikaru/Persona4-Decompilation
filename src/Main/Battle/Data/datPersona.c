/* Original translation unit datPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "operand_order_internal.h"
#include "type.h"
#include "datPersona_internal.h"
#include "datUnit_internal.h"
#include "member_access.h"

/* Unit settings: measured persona helpers use loop invariants off, propagation on and common subexpressions on. */
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on

/* Level-learning rows have a byte level, signed event kind and halfword skill.
 * Both fixed (32 rows) and ordinary (16 rows) growth tables use this stride. */
typedef struct DatPersonaLearnEvent
{
    u8 level;
    s8 kind;
    u16 skill;
} DatPersonaLearnEvent;

/* Cleared as 0x88 bytes by the preview, then consumed by ApplyLevelUp. */
typedef struct DatPersonaGrowthDelta
{
    u8 levelDelta;
    u8 pad01;
    u16 addedSkills[32];
    u16 removedSkills[32];
    u8 statGains[5];
    u8 pad87;
} DatPersonaGrowthDelta;
/* These symbols start at an interior field, not at the owning record header. */
typedef struct DatPartyAccessory {
    s16 item;
    u8 pad02[0x86];
} DatPartyAccessory;
typedef struct DatRosterId {
    u16 id;
    u8 pad02[0x2E];
} DatRosterId;
/* The 14-byte persona metadata row stores its starting level at byte three. */
typedef struct DatPersonaLevelRow {
    u8 pad00[3];
    u8 baseLevel;
    u8 pad04[0xA];
} DatPersonaLevelRow;
extern u8 D_00796E50[];

extern void kAssertFail(const void *file, u32 line);
extern void *memset(void *dest, s32 value, s32 size);
extern s32 datCalcSkillSlotValue(s32 unusedUnit, u16 packedValue);
extern char D_005E4318[];
extern s16 D_00797F88[];
extern s16 D_00797F8C[];
extern s16 D_0079819C[];
extern u8 D_007973A0[];
extern DatRosterId D_00797F8E[];
extern s32 D_0079B40C[];
extern u8 *DAT_007644c8;
extern u8 *DAT_007644c4;
extern u8 *DAT_00764530;
extern u8 *DAT_007644cc;
extern u8 *DAT_007644d4;
extern u8 *iGpffffb3d8; /* gp -0x4C28 */
extern u8 *iGpffffb3d4; /* gp -0x4C2C */
extern u8 *iGpffffb3dc; /* gp -0x4C24 */
extern u16 (*iGpffffb3e4)[311]; /* gp -0x4C1C */

extern void memcpy(void *dst, void *src, u32 size);
extern u8 *datPersonaResolveRecord(u8 *record);

extern s32 datPersonaSetLeadSlot(); /* old-style: target call preserves s64 argument */

extern u32 datCalcRandomBelow(u32 limit);

extern f32 fGpffff8218; /* gp -0x7DF8 */
extern f32 fGpffff821c; /* gp -0x7DF4 */
extern f32 fGpffff8150; /* gp -0x7EB0 */
extern f32 fGpffff8208;
extern f32 fGpffff820c;
extern s32 (*iGpffffb3e8)[98]; /* gp -0x4C18 */




// Intent: pointer to the static 0x11-byte table row of persona personaId; fatal at id >= 0x100.
// FUN_00109220
u8 *datPersonaGetRow(u16 personaId)
{
    if (!(personaId < 0x100)) {
        kAssertFail(D_005E4318, 0x18);
    }
    return DAT_00764530 + (u32)personaId * 0x11;
}
/* Read the persona-table arcana byte used by arcana comparisons; IDs outside the 256-row table assert. */
// FUN_00109280
/* measured: the u16 parameter is zero-extended separately for the range
   check and for the (u32) row offset, as retail does (two andi). A plain
   int row offset shares one entry mask. */
// Intent: arcana byte (+2 of the 14-byte persona entry); callers match it against a target arcana.
u8 datPersonaGetArcana(u16 personaId)
{
    u8 *table;

    if (!(personaId < 0x100)) {
        kAssertFail(D_005E4318, 0x26);
    }
    table = DAT_007644c4;
    return table[(u32)personaId * 0xE + 2];
}

// Intent: u16 id stored at +2 of a persona record.
// FUN_001092F0
u16 datPersonaRecordId(u32 recordAddress)
{
    return ((DatPersonaRecord *)recordAddress)->id;
}

// Intent: u16 id at +2 of roster slot arg0; fatal when the slot is NULL.
// FUN_00109300
u16 datPersonaRosterSlotId(s32 slotIndex)
{
    DatPersonaRecord *p = datPersonaRosterSlot(slotIndex);
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x3E);
    }
    return ((DatPersonaRecord *)p)->id;
}

// Intent: u16 id at +2 of the record for persona id arg0.
// FUN_00109360
u16 datPersonaGetRecordId(u16 partyId)
{
    return datPersonaGetRecord(partyId)->id;
}

// Intent: u8 at +4 of roster slot arg0, a ranking key; the largest value among same-type party members wins; fatal when NULL.
// FUN_001093A0
u8 datPersonaRosterSlotRank(s32 slotIndex)
{
    DatPersonaRecord *p = datPersonaRosterSlot(slotIndex);
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x5F);
    }
    return ((DatPersonaRecord *)p)->level;
}

// Intent: u16 flags word of roster slot arg0; fatal when the slot is NULL.
// FUN_00109470
u16 datPersonaRosterSlotFlags(s32 slotIndex)
{
    DatPersonaRecord *p = datPersonaRosterSlot(slotIndex);
    if (p == NULL) {
        kAssertFail(D_005E4318, 0xF1);
    }
    return *(u16 *)p;
}

/* The selected learning range uses independent output and traversal counts.
   Its length helper preserves that value across the known-skill query.
   Native b210 O2 with these scoped propagation/loop settings is exact
   684/688 bytes; see docs/probe_archive/Persona_skills_00109510_20260922.md. */
/* Compute the inclusive count between the first and last selected persona. */
/* measured: expansion allocates the span and loop indices to different saved registers. */
static inline s32 datPersonaSelectedCount(s32 first, s32 last)
{
    return (last + 1) - first;
}

// Intent: writes the skill ids (arg1) and levels (arg2, optional) of persona record arg0's level-table entries it has not learned yet; returns the count.
// FUN_00109510
#pragma push
/* measured: baseline propagation-on/loop-off differs by 116 words; isolated toggles give nd21/nd323; retain both. */
#pragma opt_propagation off
#pragma opt_loop_invariants on
s32 datPersonaCollectLearnableSkills(DatPersonaRecord *persona, void *outputSkills, void *outputLevels)
{
    u8 *table;
    s32 maximum;
    s32 baseLevel;
    s32 lowerLevel;
    s32 remainingLevels;
    s32 upperLevel;
    s32 first;
    s32 i;
    s32 foundFirst;
    s32 foundLast;
    s32 last;
    u8 *entry;
    s32 span;
    s32 known;
    s32 skill;
    s32 count;
    s32 visit;
    u16 *skills;

    if ((s32)persona->id >= 0x100)
    {
        kAssertFail(D_005E4318, 0x132);
    }
    if (datPersonaUsesFixedGrowth(persona) != 0)
    {
        table = (u8 *)iGpffffb3e4 + (persona->id - 0xC0) * 0x26E + 4;
        maximum = 0x20;
        baseLevel = 0;
        lowerLevel = persona->level;
        remainingLevels = 0x63 - lowerLevel;
    }
    else
    {
        u16 id = persona->id;
        u8 *baseRecord;
        u32 recordAddress;
        table = iGpffffb3dc + id * 0x46 + 6;
        maximum = 0x10;
        baseRecord = iGpffffb3d4;
        recordAddress = id * 0xE;
        recordAddress += (u32)baseRecord;
        baseLevel = ((u8 *)recordAddress)[3];
        lowerLevel = persona->level - baseLevel;
        remainingLevels = 0x63 - persona->level;
    }
    upperLevel = lowerLevel + remainingLevels;
    first = 0;
    foundFirst = 0;
    foundLast = 0;
    i = 0;
    while (i < maximum)
    {
        entry = table + i * 4;
        if (((DatPersonaLearnEvent *)entry)->kind == 0)
        {
            break;
        }
        if (lowerLevel < *(u8 *)entry)
        {
            if (foundFirst == 0)
            {
                foundFirst = 1;
                first = i;
                last = i;
            }
            if (*(u8 *)entry <= upperLevel)
            {
                foundLast = 1;
                last = i;
            }
        }
        i++;
    }
    if (foundLast != 0)
    {
        span = datPersonaSelectedCount(first, last);
    }
    else
    {
        span = 0;
    }
    table += first * 4;
    skills = persona->skills;
    known = datPersonaCountSkills(persona);
    count = 0;
    visit = 0;
    while (visit < span)
    {
        switch (((DatPersonaLearnEvent *)table)->kind)
        {
        case 1:
            skill = 0;
            while (skill < known)
            {
                if (((DatPersonaLearnEvent *)table)->skill == skills[skill])
                {
                    break;
                }
                skill++;
            }
            if (skill == known)
            {
                if (count >= 0x20)
                {
                    kAssertFail(D_005E4318, 0x17B);
                }
                ((u16 *)outputSkills)[count] = ((DatPersonaLearnEvent *)table)->skill;
                if (outputLevels != NULL)
                {
                    ((u16 *)outputLevels)[count] = *(u8 *)table + baseLevel;
                }
                count++;
            }
            break;
        default:
            break;
        }
        if (count == 0x20)
        {
            break;
        }
        visit++;
        table += 4;
    }
    return count & 0xFFFF;
}
#pragma pop


// Intent: passes skill slot arg1 of persona record arg0 to datCalcSkillSlotValue; fatal on bad id or slot.
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */
// FUN_001097C0

void datPersonaRunSkillSlot(u8 *persona, s32 slotIndex)
{
    DatPersonaRecord *personaRecord = (DatPersonaRecord *)(persona);
    u8 *skillTable;

    if ((u16)((DatPersonaRecord *)persona)->id >= 0x100) {
        kAssertFail(D_005E4318, 0x1B7);
    }
    if ((slotIndex & 0xFFFF) >= 0x10) {
        kAssertFail(D_005E4318, 0x1B8);
    }
    skillTable = iGpffffb3d8 + (u16)personaRecord->id * 0x20;
    datCalcSkillSlotValue(0, ((u16 *)skillTable)[(u16)slotIndex]);
}

// Intent: skill-slot value of persona id arg0 at slot arg1, read through datCalcSkillSlotValue; fatal when out of range.
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */
// FUN_00109870

u32 datPersonaGetSkillSlot(u16 partyId, s32 slotIndex)
{
    DatPersonaRecord *skillPersona;
    u8 *persona;

    persona = (u8 *)datPersonaGetRecord(partyId);
    skillPersona = (DatPersonaRecord *)persona;
    if ((u16)((DatPersonaRecord *)persona)->id >= 0x100) {
        kAssertFail(D_005E4318, 0x1B7);
    }
    if ((slotIndex & 0xFFFF) >= 0x10) {
        kAssertFail(D_005E4318, 0x1B8);
    }
    return (u32)datCalcSkillSlotValue(0, ((u16 *)(iGpffffb3d8 + (u16)skillPersona->id * 0x20))[(u16)slotIndex]);
}

// Intent: battle stat (index 0..4, see DatPersonaStat in datPersona_internal.h) at +0x1C of a persona record.
// FUN_00109920
u8 datPersonaGetStat(DatPersonaRecord *persona, s32 statIndex)
{
    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    return persona->stats[(u16)statIndex];
}

// Intent: battle stat (index 0..4) of the record for persona id arg0; same layout as datPersonaGetStat.
/* Preserve the public word transport while interpreting the character as a halfword. */
// FUN_00109980
s32 datPersonaGetStatById(partyId, statIndex)
u16 partyId;
s32 statIndex;
{
    DatPersonaRecord *p = datPersonaGetRecord(partyId);
    u8 *base = (u8 *)p;
    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    return base[(u16)statIndex + 0x1C];
}

// Intent: battle stat arg1 of record arg0 plus two stat modifiers, capped at 99; fatal when arg1 >= 5.
// FUN_001099F0
u8 datPersonaGetBuffedStat(DatPersonaRecord *persona, s32 statIndex)
{
    s16 baseStat;
    s16 bonusA;
    s8 bonusB;
    s16 sum;
    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    baseStat = (s16)persona->stats[(u16)statIndex];
    bonusA = (s8)datPersonaGetStatBonusA(persona, statIndex);
    bonusB = (s8)datPersonaGetStatBonusB(persona, statIndex);
    sum = (s16)(baseStat + bonusA + bonusB);
    if (sum >= 0x63) {
        sum = 0x63;
    }
    return (u8)sum;
}

// Intent: battle stat arg1 of record arg0 plus two modifiers and the equipment bonus, clamped to 0..99.
// FUN_00109AD0
u8 datPersonaGetTotalStat(DatPersonaRecord *persona, s32 statIndex)
{
    s16 baseStat;
    s16 bonusA;
    s16 bonusB;
    s8 equipmentBonus;
    s16 sum;

    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    baseStat = (s16)persona->stats[(u16)statIndex];
    bonusA = (s8)datPersonaGetStatBonusA(persona, statIndex);
    bonusB = (s8)datPersonaGetStatBonusB(persona, statIndex);
    equipmentBonus = (s8)datPersonaGetEquipStatBonus(persona, statIndex);
    sum = (s16)(baseStat + bonusA + bonusB + equipmentBonus);
    if (sum > 0x63) {
        sum = 0x63;
    } else if (sum < 0) {
        sum = 0;
    }
    return (u8)sum;
}

// Intent: battle stat arg1 of the record for persona id arg0, plus modifiers and equipment, clamped to 0..99.
// FUN_00109BF0
u8 datPersonaGetTotalStatById(u16 partyId, s32 statIndex)
{
    s16 baseStat;
    s16 bonusA;
    s16 bonusB;
    s8 equipmentBonus;
    s16 sum;
    DatPersonaRecord *p = (DatPersonaRecord *)datPersonaGetRecord(partyId);

    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    baseStat = (s16)p->stats[(u16)statIndex];
    bonusA = (s8)datPersonaGetStatBonusA(p, statIndex);
    bonusB = (s8)datPersonaGetStatBonusB(p, statIndex);
    equipmentBonus = (s8)datPersonaGetEquipStatBonus(p, statIndex);
    sum = (s16)(baseStat + bonusA + bonusB + equipmentBonus);
    if (sum > 0x63) {
        sum = 0x63;
    } else if (sum < 0) {
        sum = 0;
    }
    return (u8)sum;
}

// Intent: signed per-stat bonus byte at +0x21 of a record for stat arg1; summed into the stat totals.
// FUN_00109D20
s8 datPersonaGetStatBonusA(DatPersonaRecord *persona, s32 statIndex)
{
    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x268);
    }
    return persona->statBonusA[(u16)statIndex];
}

// Intent: signed per-stat bonus byte at +0x26 of a record for stat arg1; summed into the stat totals.
// FUN_00109DD0
s8 datPersonaGetStatBonusB(DatPersonaRecord *persona, s32 statIndex)
{
    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x299);
    }
    return persona->statBonusB[(u16)statIndex];
}

extern u16 datCalcCountIdSlotsWithValue(u16 characterId, u16 property);
extern s16 D_00797578[];
extern DatPartyAccessory D_00796D90[];
extern u8 *iGpffffb1b0;

/* 2372/2384 bytes; 56 resolved relocations; 12 zero alignment bytes.
 * The real equipment-query inputs are unsigned halfwords. Keep each weighted
 * query independent and preserve the signed-byte result for the stat clamp. */
// Intent: equipment bonus for stat arg1 of record arg0, summed from the equipped items of its party slot.
/* D_00796D90 starts at the accessory halfword; the typed column retains its 0x88-byte stride. */
// FUN_00109E30
s8 datPersonaGetEquipStatBonus(DatPersonaRecord *persona, s32 statIndex)
{
    /* Equipment rows have a 0x44 stride; only the five signed stat bonuses are used here. */
    typedef struct DatEquipStatRow { u8 pad00[0x14]; s16 strength, endurance, magic, agility, luck; u8 pad1E[0x26]; } DatEquipStatRow;
    s16 bonus;
    u16 party;
    s16 equipped;
    u16 equipment;
    u16 stat = (u16)statIndex;
    if (stat >= 5) {
        kAssertFail(D_005E4318, 0x2CD);
    }
    bonus = 0;
    if (datPersonaUsesFixedGrowth(persona) != 0) {
        if (persona->id < 0xC0 || persona->id > 0xD7) {
            kAssertFail(D_005E4318, 0x2D4);
        }
        party = iGpffffb3e4[persona->id - 0xC0][0];
    } else {
        party = 1;
    }
    if ((u16)party >= 0xB) {
        kAssertFail(D_005E4318, 0x2D9);
    }
    if ((s16)party == 1) {
        equipped = D_00797578[0];
    } else {
        equipped = D_00796D90[(s16)party].item;
    }
    equipment = equipped;
    switch (stat) {
    case 0:
        bonus += ((DatEquipStatRow *)iGpffffb1b0)[(s16)equipment].strength;
        break;
    case 2:
        bonus += ((DatEquipStatRow *)iGpffffb1b0)[(s16)equipment].endurance;
        break;
    case 1:
        bonus += ((DatEquipStatRow *)iGpffffb1b0)[(s16)equipment].magic;
        break;
    case 3:
        bonus += ((DatEquipStatRow *)iGpffffb1b0)[(s16)equipment].agility;
        break;
    case 4:
        bonus += ((DatEquipStatRow *)iGpffffb1b0)[(s16)equipment].luck;
        break;
    }
    switch (stat) {
    case 0:
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 1) * 1);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 2) * 2);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 3) * 3);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 4) * 4);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 5) * 5);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 86) * 10);
        break;
    case 1:
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 11) * 1);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 12) * 2);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 13) * 3);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 14) * 4);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 15) * 5);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 88) * 10);
        break;
    case 2:
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 6) * 1);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 7) * 2);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 8) * 3);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 9) * 4);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 10) * 5);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 87) * 10);
        break;
    case 3:
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 16) * 1);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 17) * 2);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 18) * 3);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 19) * 4);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 20) * 5);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 89) * 10);
        break;
    case 4:
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 21) * 1);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 22) * 2);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 23) * 3);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 24) * 4);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 25) * 5);
        bonus += (s16)(datCalcCountIdSlotsWithValue(party, 90) * 10);
        break;
    }
    bonus += (s16)(datCalcCountIdSlotsWithValue(party, 63) * 1);
    bonus += (s16)(datCalcCountIdSlotsWithValue(party, 64) * 2);
    bonus += (s16)(datCalcCountIdSlotsWithValue(party, 65) * 3);
    bonus += (s16)(datCalcCountIdSlotsWithValue(party, 66) * 4);
    bonus += (s16)(datCalcCountIdSlotsWithValue(party, 67) * 5);
    bonus += (s16)(datCalcCountIdSlotsWithValue(party, 139) * 10);
    return (s8)bonus;
}

/* Ported from the Persona 3 FES tree (datPersona.c
   datPersonaAddToNaturalStat), which shares this source: two separate s16
   locals with a (s16)(u16) widening load, and the clamped total stored back
   through a pointer materialized once, is what keeps the s16 extension mwcc
   otherwise elides. Prior local spellings all floored at nd 25-28. */
// Intent: adds delta arg2 to stat arg1 of record arg0, clamped to 0..99; returns the new value.
// FUN_0010A780
s32 datPersonaAddStat(u8 *persona, s32 statIndex, s32 delta)
{
    u8 *stat;
    s16 naturalStat;
    s16 statTotal;

    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x36C);
    }

    stat = (u8 *)((u32)(u16)statIndex + (u32)persona) + 0x1C;
    naturalStat = (s16)(u16)*stat;
    statTotal = naturalStat + (s8)delta;
    if (statTotal > 0x63) {
        statTotal = 0x63;
    } else if (statTotal < 0) {
        statTotal = 0;
    }
    *stat = statTotal;
    return (u8)statTotal;
}
// Intent: adds delta arg2 to stat arg1 of the record for persona id arg0, clamped to 0..99.
// FUN_0010A840
s32 datPersonaAddStatById(u16 partyId, s32 statIndex, s32 statDelta) {
    u8 *base;
    u8 *stat;
    s16 old;
    s16 delta;
    s16 total;

    base = (u8 *)datPersonaGetRecord(partyId);
    if ((statIndex & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x36C);
    }
    stat = (u8 *)((u32)(u16)statIndex + (u32)base) + 0x1C;
    old = (s16)(u16)*stat;
    delta = (s8)statDelta;
    total = old + delta;
    if (total > 0x63) {
        total = 0x63;
    } else if (total < 0) {
        total = 0;
    }
    *stat = total;
    return (u8)total;
}

// Intent: maps a persona id to its record; 1 is the selected roster slot, 2..10 index the party array.
// FUN_0010A900
DatPersonaRecord *datPersonaGetRecord(u16 partyId)
{
    DatPersonaRecord *p;
    s32 v = partyId & 0xFFFF;

    if (v == 1) {
        p = datPersonaRosterSlot(D_00797F88[0]);
    } else {
        if (v >= 0xB) {
            kAssertFail(D_005E4318, 0x3A5);
        }
        p = &((DatPartySlot *)D_00796E50)[v - 2].personaRecord;
    }
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x3A9);
    }
    return p;
}

// Intent: true when the lead (id 1) record has flag bit 4 set; datCalc scales damage and code1_0021 scales level when it is.
// FUN_0010A9B0
s32 datPersonaLeadBoosted(s32 partyId)
{
    DatPersonaRecord *p;
    s32 v = partyId & 0xFFFF;

    if (v != 1) {
        return 0;
    }
    if (v == 1) {
        p = datPersonaRosterSlot(D_00797F88[0]);
    } else {
        if (v >= 0xB) {
            kAssertFail(D_005E4318, 0x3A5);
        }
        p = &((DatPartySlot *)D_00796E50)[v - 2].personaRecord;
    }
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x3A9);
    }
    return (*(u16 *)p & 4) != 0;
}

// Intent: index of the active roster slot whose id matches, or -1.
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */

// FUN_0010AA80

s32 datPersonaFindRosterSlotById(s32 personaId)
{
    s32 count = datPersonaRosterCapacity() & 0xFFFF;
    s32 i = 0;
    s32 id = (s16)personaId;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        /* measured: typed site/local/array forms change instructions; this existing member is exact. */
        if ((((DatPersonaRecord *)(base + off + 0xBEC))->flags & 1) != 0 && MEMBER(u16, base + 0xBEC + off, DatPersonaRecord, id) == id) {
            return (s16)i;
        }
    }
    return -1;
}

// Intent: index of the first inactive roster slot, or -1 when the roster is full.
// FUN_0010AB30
s32 datPersonaFindFreeRosterSlot(void)
{
    s32 i = 0;

    while ((u16)i < (u16)datPersonaRosterCapacity()) {
        if ((((DatPersonaRecord *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC))->flags & 1) == 0) {
            return (s16)i;
        }
        i = (i + 1) & 0xFFFF;
    }
    return -1;
}

// Intent: true when roster slot arg0 has its active flag set.
// FUN_0010ABD0
s32 datPersonaRosterSlotActive(s16 slotIndex)
{
    return (((DatPersonaRecord *)((u8 *)D_00797F8C + (s32)slotIndex * 0x30))->flags & 1) != 0;
}

// Intent: roster record of the active slot matching the id, or NULL.
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */

// FUN_0010AC10

DatPersonaRecord *datPersonaFindRosterRecordById(s32 personaId)
{
    s32 count = datPersonaRosterCapacity() & 0xFFFF;
    s32 i = 0;
    s16 found;
    s32 id = (s16)personaId;
    u8 *base = D_007973A0;
    s32 off;

    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((((DatPersonaRecord *)(base + 0xBEC + off))->flags & 1) != 0 &&
            /* measured: typed site/local/array forms change instructions; this existing member is exact. */
            MEMBER(u16, base + 0xBEC + off, DatPersonaRecord, id) == id) {
            found = (s16)i;
            goto done;
        }
    }
    found = -1;
done:
    if (found == -1) {
        return NULL;
    }
    return datPersonaRosterSlot(found);
}

// Intent: roster record at index arg0, or NULL when the slot is inactive.
// FUN_0010ACE0
DatPersonaRecord *datPersonaRosterSlot(s16 slotIndex)
{
    s32 v = (s32)slotIndex;

    if (v < 0 || v >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x3FE);
    }
    if ((((DatPersonaRecord *)((u8 *)D_00797F8C + v * 0x30))->flags & 1) == 0) {
        return NULL;
    }
    return (DatPersonaRecord *)((u8 *)D_007973A0 + v * 0x30 + 0xBEC);
}

// Intent: removes the active roster slot holding the id, if any.
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */

// FUN_0010AD80

s32 datPersonaRemoveRosterMemberById(s32 personaId)
{
    s32 count = datPersonaRosterCapacity() & 0xFFFF;
    s32 i = 0;
    s32 slotIndex;
    s32 id = (s16)personaId;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        /* measured: typed site/local/array forms change instructions; this existing member is exact. */
        if ((((DatPersonaRecord *)(base + 0xBEC + off))->flags & 1) != 0 && MEMBER(u16, base + 0xBEC + off, DatPersonaRecord, id) == id) {
            slotIndex = (s16)i;
            goto done;
        }
    }
    slotIndex = -1;
done:
    return datPersonaRemoveRosterSlot(slotIndex);
}

// Intent: removes roster slot arg0, shifts later slots down, then reselects the lead.
/* The shifted roster cursor still points at the game-state base; +0xBEC/+0xBEE address the DatPersonaRecord flags/id, not a second object type. */
// FUN_0010AE30
s32 datPersonaRemoveRosterSlot(s32 slotIndex)
{
    s16 i;
    s32 id;
    s16 selected;
    s32 selected32;
    s32 count;
    s64 found;
    s32 j;
    u8 *entry;
    u8 *base;

    id = (s16)slotIndex;
    if (id < 0 || id >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x417);
    }
    if ((((DatPersonaRecord *)((u8 *)D_00797F8C + id * 0x30))->flags & 1) == 0) {
        return 0;
    }
    selected = datPersonaLeadPersonaId();
    for (i = (s16)slotIndex; (s32)i < 0xB; i++) {
        memcpy((u8 *)D_007973A0 + (s32)i * 0x30 + 0xBEC,
                      (u8 *)D_007973A0 + ((s32)i + 1) * 0x30 + 0xBEC,
                      0x30);
    }
    memset(D_0079819C, 0, 0x30);
    count = datPersonaRosterCapacity() & 0xFFFF;
    j = 0;
    selected32 = selected;
    base = (u8 *)D_007973A0;
    for (; (u16)j < count; j = (u16)(j + 1)) {
        entry = base + (j & 0xFFFF) * 0x30;
        if ((((DatPersonaRecord *)(entry + 0xBEC))->flags & 1) != 0 &&
            ((DatPersonaRecord *)(entry + 0xBEC))->id == selected32) {
            found = (s16)j;
            goto done;
        }
    }
    found = -1;
done:
    if ((s16)found != -1) {
        datPersonaSetLeadSlot(found);
    }
    return 1;
}

// Intent: adds persona id to the first free roster slot; fatal when the roster is full.
// FUN_0010B010
u8 *datPersonaAddRosterMember(u16 personaId)
{
    u8 *p = datPersonaTryAddRosterMember(personaId);
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x43A);
    }
    return p;
}

// Intent: adds persona id to the first free roster slot, returning NULL when full.
// FUN_0010B060
u8 *datPersonaTryAddRosterMember(u16 personaId)
{
    s32 i = 0;
    s16 found;
    u8 *entry;

    while ((u16)i < (u16)datPersonaRosterCapacity()) {
        if ((((DatPersonaRecord *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC))->flags & 1) == 0) {
            found = (s16)i;
            goto done;
        }
        i = (i + 1) & 0xFFFF;
    }
    found = -1;
done:
    if (found == -1) {
        return NULL;
    }
    entry = (u8 *)D_007973A0 + found * 0x30 + 0xBEC;
    datPersonaInitRecord(entry, personaId);
    ((DatPersonaRecord *)((u8 *)D_00797F8C + found * 0x30))->flags &= 0xC;
    ((DatPersonaRecord *)((u8 *)D_00797F8C + found * 0x30))->flags |= 1;
    datPersonaResolveRecord(entry);
    return entry;
}

// Intent: copies a 0x30-byte record into the first free roster slot; returns 1 on success, 0 when full.
// FUN_0010B190
s32 datPersonaInsertRosterRecord(u8 *persona)
{
    s32 i;
    s16 found;
    u8 *entry;

    if (persona == NULL) {
        kAssertFail(D_005E4318, 0x464);
    }
    if (((DatPersonaRecord *)persona)->id == 0 || ((DatPersonaRecord *)persona)->id >= 0x100) {
        kAssertFail(D_005E4318, 0x465);
    }
    i = 0;
    while ((u16)i < (u16)datPersonaRosterCapacity()) {
        if ((((DatPersonaRecord *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC))->flags & 1) == 0) {
            found = (s16)i;
            goto done;
        }
        i = (i + 1) & 0xFFFF;
    }
    found = -1;
done:
    if (found == -1) {
        return 0;
    }
    entry = (u8 *)D_007973A0 + found * 0x30 + 0xBEC;
    memcpy(entry, persona, 0x30);
    ((DatPersonaRecord *)((u8 *)D_00797F8C + found * 0x30))->flags &= 0xC;
    ((DatPersonaRecord *)((u8 *)D_00797F8C + found * 0x30))->flags |= 1;
    datPersonaResolveRecord(entry);
    return 1;
}

// Intent: selects the active roster slot holding the id as lead; returns 0 when no slot matches.
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */

// FUN_0010B300

s32 datPersonaSelectRosterMemberById(s32 personaId)
{
    s32 count = datPersonaRosterCapacity() & 0xFFFF;
    s32 i = 0;
    s32 slotIndex;
    s32 id = (s16)personaId;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        /* measured: typed site/local/array forms change instructions; this existing member is exact. */
        if ((((DatPersonaRecord *)(base + 0xBEC + off))->flags & 1) != 0 && MEMBER(u16, base + 0xBEC + off, DatPersonaRecord, id) == id) {
            slotIndex = (s16)i;
            goto done;
        }
    }
    slotIndex = -1;
done:
    return datPersonaSetLeadSlot(slotIndex);
}

// Intent: makes roster slot arg0 the lead when it is active; returns 0 otherwise.
// FUN_0010B3B0
s32 datPersonaSetLeadSlot(s32 slotIndex)
{
    s32 idx = (s16)slotIndex;
    if (idx < 0 || idx >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x47E);
    }
    if ((((DatPersonaRecord *)((u8 *)D_00797F8C + idx * 0x30))->flags & 1) == 0) {
        return 0;
    }
    D_00797F88[0] = (s16)slotIndex;
    return 1;
}

// Intent: persona id held in the lead slot's record (+2); callers treat it as the current lead persona.
/* D_00797F8E starts at the roster ID halfword, two bytes beyond the separate flag alias. */
// FUN_0010B460
u16 datPersonaLeadPersonaId(void)
{
    s32 v = D_00797F88[0];
    s32 off;

    if (v < 0 || v >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x491);
    }
    off = v * 0x30;
    if ((((DatPersonaRecord *)((u8 *)D_00797F8C + off))->flags & 1) == 0) {
        kAssertFail(D_005E4318, 0x492);
    }
    return D_00797F8E[v].id;
}

// Intent: index of the lead roster slot; fatal when the lead slot is inactive.
// FUN_0010B510
s32 datPersonaGetLeadSlot(void)
{
    s32 v = D_00797F88[0];

    if (v < 0 || v >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x49C);
    }
    if ((((DatPersonaRecord *)((u8 *)D_00797F8C + v * 0x30))->flags & 1) == 0) {
        kAssertFail(D_005E4318, 0x49D);
    }
    return v;
}

// Intent: roster capacity (6, 8, 10 or 12) selected by the mode flags at D_0079B40C.
// FUN_0010B5B0
s32 datPersonaRosterCapacity(void)
{
    s32 v = D_0079B40C[0];
    if (v & 4) {
        return 0xC;
    }
    if (v & 2) {
        return 0xA;
    }
    if (v & 1) {
        return 8;
    }
    return 6;
}

#pragma push
/* measured: nested static inline OR helper preserves retail's intermediate
   ori sequence for modes 2 and 3; helper is required for exact b610 codegen. */
/* measured: opt_propagation off preserves the three retail mask/and steps. */
/* measured: baseline differs by 43 words; reloading the stored mode flags leaves nd110; retain propagation off. */
#pragma opt_propagation off
// Intent: sets the roster mode flags (none, 1, 2 or 3 cumulative) that select the capacity.
// FUN_0010B610
void datPersonaSetRosterMode(s32 rosterMode)
{
    s32 flags;
    s32 mode;

    flags = D_0079B40C[0];
    flags &= ~1;
    flags &= ~2;
    flags &= ~4;
    D_0079B40C[0] = flags;
    mode = rosterMode & 0xFFFF;
    switch (mode) {
    case 0:
        break;
    case 1:
        D_0079B40C[0] = flags | 1;
        break;
    case 2:
        D_0079B40C[0] = (operandOrderOr(flags, 1) | 2);
        break;
    case 3:
        D_0079B40C[0] = (operandOrderOr(operandOrderOr(flags, 1), 2) | 4);
        break;
    default:
        kAssertFail(D_005E4318, 0x4CD);
        break;
    }
}
/* measured: restore the unit propagation setting after the b610 bracket. */
#pragma pop
#pragma push
/* measured: sibling P3 valid-count shape closes this 0xD0 window with
   opt_loop_invariants; the explicit bracket is required for the hoisted base. */
/* measured: baseline differs by 17 words; cached typed roster base reduces nd35 to nd10 but changes addressing; retain hoisting. */
#pragma opt_loop_invariants on
// Intent: number of active roster slots within the current capacity.
// FUN_0010B6F0
u16 datPersonaCountValidMembers(void)
{
    u16 validCount;
    u32 modeFlags;
    u16 maxPersonaCount;
    s32 personaCount;
    u16 personaIdx;
    u8 valid;

    validCount = 0;
    modeFlags = D_0079B40C[0];
    if (modeFlags & 4) {
        maxPersonaCount = 0xC;
    } else if (modeFlags & 2) {
        maxPersonaCount = 0xA;
    } else if (modeFlags & 1) {
        maxPersonaCount = 8;
    } else {
        maxPersonaCount = 6;
    }
    personaIdx = 0;
    personaCount = (u16)maxPersonaCount;
    for (; personaIdx < personaCount; personaIdx++) {
        valid = (((DatPersonaRecord *)((u8 *)D_007973A0 + (s16)personaIdx * 0x30 + 0xBEC))->flags & 1) != 0;
        if (valid) {
            validCount++;
        }
    }
    return validCount;
}
/* measured: restore the unit settings after the one-function optimization bracket. */
#pragma pop
// Intent: clears the roster flag records.
// FUN_0010B7C0
void datPersonaClearRoster(void)
{
    memset((void *)D_00797F8C, 0, 0x240);
}

/* measured: retail loads the count-select constants with daddiu (the
   b5b0-return form) inside the ||; mwcc b210 emits addiu for ternary/local
   forms and hoists the D_0079B40C load. Tried ternary/u16/s64 arms and
   assignment forms; nd 104-106. Same daddiu-local floor as datPersonaCountValidMembers. */
// Intent: removes the selected roster member by compacting the slots after it.
// FUN_0010B7F0
void datPersonaRemoveSelectedRosterMember(void)
{
    u8 selectedRecord[0x30];
    s32 selected;
    s64 index;
    u16 maxPersonaCount;
    s32 personaCount;
    s32 selectedOffset;
    s16 i;

    index = D_00797F88[0];
    selected = D_00797F88[0];
    if (index >= 0) {
        if (D_0079B40C[0] & 4) {
            maxPersonaCount = 0xC;
        } else if (D_0079B40C[0] & 2) {
            maxPersonaCount = 0xA;
        } else if (D_0079B40C[0] & 1) {
            maxPersonaCount = 8;
        } else {
            maxPersonaCount = 6;
        }
        personaCount = (u16)maxPersonaCount;
        if (index < personaCount) {
            goto valid_index;
        }
    }
    kAssertFail(D_005E4318, 0x50B);
valid_index:
    selectedOffset = (s32)selected * 0x30;
    if ((((DatPersonaRecord *)((u8 *)D_00797F8C + selectedOffset))->flags & 1) == 0) {
        kAssertFail(D_005E4318, 0x50C);
    }
    if (index != 0) {
        memcpy(selectedRecord, (u8 *)D_007973A0 + selectedOffset + 0xBEC, 0x30);
        i = (s16)index;
        while (i > 0) {
            memcpy((u8 *)D_007973A0 + i * 0x30 + 0xBEC,
                          (u8 *)D_007973A0 + (i - 1) * 0x30 + 0xBEC,
                          0x30);
            i--;
        }
        memcpy((void *)D_00797F8C, selectedRecord, 0x30);
        D_00797F88[0] = 0;
    }
}
/* 1008/1008 bytes; forty-five fully resolved relocations, no alignment tail.
 * Preserve the promoted search bound and signed persona-ID comparison.
 * Initialization and diagnostics can change the capacity flags: reload them
 * at each subsequent validation, as the retail body does. */
// Intent: places persona arg1 into the first free slot of roster mode arg0 (mode 1 is the selection).
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */

// FUN_0010B9A0

s32 datPersonaPlaceRosterMember(s32 partyId, u16 personaId)
{
    s32 v = partyId & 0xFFFF;
    u8 *p;
    s16 empty;
    s32 emptyOff;
    u16 maxPersonaCount;
    s32 personaCount;
    s32 i;
    s16 found;
    s32 id;
    u8 *base;
    s32 off;
    s32 cur;
    s32 curOff;

    if (v == 1) {
        empty = datPersonaFindFreeRosterSlot();
        if (empty == -1) {
            p = NULL;
        } else {
            emptyOff = empty * 0x30;
            p = (u8 *)D_007973A0 + emptyOff + 0xBEC;
            datPersonaInitRecord(p, personaId);
            ((DatPersonaRecord *)((u8 *)D_00797F8C + emptyOff))->flags &= 0xC;
            ((DatPersonaRecord *)((u8 *)D_00797F8C + emptyOff))->flags |= 1;
            datPersonaResolveRecord(p);
        }
        if (p == NULL) {
            kAssertFail(D_005E4318, 0x43A);
        }
        if (D_0079B40C[0] & 4) {
            maxPersonaCount = 0xC;
        } else if (D_0079B40C[0] & 2) {
            maxPersonaCount = 0xA;
        } else if (D_0079B40C[0] & 1) {
            maxPersonaCount = 8;
        } else {
            maxPersonaCount = 6;
        }
        i = 0;
        id = (s16)personaId;
        personaCount = (u16)maxPersonaCount;
        base = (u8 *)D_007973A0;
        for (; (u16)i < personaCount; i = (u16)(i + 1)) {
            off = (i & 0xFFFF) * 0x30;
            /* measured: typed site/local/array forms change instructions; this existing member is exact. */
            if ((((DatPersonaRecord *)(base + 0xBEC + off))->flags & 1) != 0 && MEMBER(u16, base + 0xBEC + off, DatPersonaRecord, id) == id) {
                found = (s16)i;
                goto search_done;
            }
        }
        found = -1;
search_done:
        if (found >= 0) {
            if (D_0079B40C[0] & 4) {
                maxPersonaCount = 0xC;
            } else if (D_0079B40C[0] & 2) {
                maxPersonaCount = 0xA;
            } else if (D_0079B40C[0] & 1) {
                maxPersonaCount = 8;
            } else {
                maxPersonaCount = 6;
            }
            personaCount = (u16)maxPersonaCount;
            if (found < personaCount) {
                goto pass52D;
            }
        }
        kAssertFail(D_005E4318, 0x52D);
pass52D:
        if (found >= 0) {
            if (D_0079B40C[0] & 4) {
                maxPersonaCount = 0xC;
            } else if (D_0079B40C[0] & 2) {
                maxPersonaCount = 0xA;
            } else if (D_0079B40C[0] & 1) {
                maxPersonaCount = 8;
            } else {
                maxPersonaCount = 6;
            }
            personaCount = (u16)maxPersonaCount;
            if (found < personaCount) {
                goto pass47E;
            }
        }
        kAssertFail(D_005E4318, 0x47E);
pass47E:
        if ((((DatPersonaRecord *)((u8 *)D_00797F8C + found * 0x30))->flags & 1) != 0) {
            D_00797F88[0] = found;
        }
    } else {
        if (v == 1) {
            cur = D_00797F88[0];
            if (cur < 0 || cur >= (u16)datPersonaRosterCapacity()) {
                kAssertFail(D_005E4318, 0x3FE);
            }
            curOff = cur * 0x30;
            p = ((((DatPersonaRecord *)((u8 *)D_00797F8C + curOff))->flags & 1) != 0) ? (u8 *)D_007973A0 + curOff + 0xBEC : NULL;
        } else {
            if (v >= 0xB) {
                kAssertFail(D_005E4318, 0x3A5);
            }
            p = (u8 *)&((DatPartySlot *)D_00796E50)[v - 2].personaRecord;
        }
        if (p == NULL) {
            kAssertFail(D_005E4318, 0x3A9);
        }
        datPersonaInitRecord(p, personaId);
        *(u16 *)p = 1;
    }
    return 1;
}

// Intent: clears roster mode arg0; mode 1 resets the selection and the roster block, other modes clear one party block.
// FUN_0010BD90
void datPersonaResetRosterMode(s16 partyId)
{
    s32 v = (s32)partyId;

    if (v == 1) {
        D_00797F88[0] = -1;
        memset((void *)D_00797F8C, 0, 0x240);
    } else {
        memset((void *)&((DatPartySlot *)D_00796E50)[v - 2].personaRecord, 0, sizeof(DatPersonaRecord));
    }
}

// Intent: true when persona record arg0 is in the fixed party id range 0xC0..0xD7 (fixed growth rows).

// FUN_0010BE20
s32 datPersonaUsesFixedGrowth(DatPersonaRecord *persona)
{
    u16 v = persona->id;

    if (v >= 0xC0 && v < 0xD8) {
        return 1;
    }
    return 0;
}

/* Preview level, stat and skill changes without changing the persona.
 * Ordinary personas attempt three weighted stat gains per level; party
 * personas use fixed growth rows. Only stats below 99 can grow. Skill
 * additions/removals cover the newly reached level range.
 * Native b210 O2: 1856/1856 bytes, 34 resolved relocations, no tail.
 */
#pragma push
/* measured: baseline differs by 179 words; explicit growth-table preheader gives nd1087; retain hoisting. */
#pragma opt_loop_invariants on
/* Test whether the persona identifier belongs to the party-persona interval. */
static inline s32 datPersonaGrowthIsParty(u8 *persona)
{
    /* Same DatPersonaRecord +2 access retained by the matching level-preview caller. */
    /* measured: typed site/local/array forms change instructions; this existing member is exact. */
    s32 id = MEMBER(u16, persona, DatPersonaRecord, id);
    if (id >= 0xC0 && id < 0xD8) {
        return 1;
    }
    return 0;
}

/* Search the known halfword skills, retaining the truncated index on return. */
static inline s32 datPersonaGrowthFindSkill(u16 skill, u8 *skills, s32 known)
{
    s32 index;
    /* The skill-list byte cursor preserves the preview's halfword index truncation. */
    for (index = 0; (index & 0xFFFF) < known; index = (index + 1) & 0xFFFF) {
        if (skill == ((u16 *)skills)[(u16)index]) { break; }
    }
    return index & 0xFFFF;
}


// Intent: previews stat, skill and level changes of persona arg0 at level arg2 into arg1 without modifying the persona.
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */

// FUN_0010BE60

void datPersonaPreviewLevelUp(u8 *persona, u8 *delta, s32 addedExp)
{
    DatPersonaLearnEvent *learningEvent;
    DatPersonaRecord *personaRecord = (DatPersonaRecord *)(persona);
    u16 stat[5];
    s32 pid;
    s32 statIndex;
    u8 *statBytes;
    u16 *statValue;
    u16 level;
    u32 expsum;
    s32 pidoff;
    s32 roll;
    s32 weight;
    s32 total;
    s32 sumIndex;
    s32 partyIndex;
    s32 statScan;
    s32 choice;
    u8 *table;
    u8 *gain;
    u16 statBase;
    u16 bonusIndex;
    u16 *checkedIndex;
    u8 *entry;
    u8 *skills;
    s32 known;
    s32 limit;
    s32 oldLevel;
    s32 newLevel;
    s32 first;
    s32 found;
    s32 span;
    s32 last;
    s32 count;
    s32 rangeCurrent;
    s32 rangeIndex;
    s32 search;
    s32 added;
    s32 removed;
    s32 collectIndex;
    u8 *event;

    pid = ((DatPersonaRecord *)persona)->id;
    if (pid == 0 || pid >= 0x100) {
        kAssertFail(D_005E4318, 0x56D);
    }
    memset(delta, 0, 0x88);
    for (statIndex = 0; (statIndex & 0xFFFF) < 5; statIndex = (statIndex + 1) & 0xFFFF) {
        if ((statIndex & 0xFFFF) >= 5) {
            kAssertFail(D_005E4318, 0x1DE);
        }
        statBytes = persona + (u16)statIndex;
        statValue = &stat[(u16)statIndex];
        *statValue = statBytes[0x1C];
        if ((u16)statIndex >= 5) {
            kAssertFail(D_005E4318, 0x268);
        }
        /* The next accessor checks this unsigned halfword lvalue. */
        checkedIndex = &bonusIndex;
        *checkedIndex = statIndex;
        *statValue += ((DatPersonaRecord *)statBytes)->statBonusA[0];
        if (*checkedIndex >= 5) {
            kAssertFail(D_005E4318, 0x299);
        }
        *statValue += ((DatPersonaRecord *)statBytes)->statBonusB[0];
    }
    level = persona[4] + 1;
    expsum = (u32)((DatPersonaRecord *)persona)->exp + (u32)addedExp;
    pidoff = (pid & 0xFFFF) * 0x46;
    while (datPersonaGetExpForLevel(persona, level) <= expsum && level <= 99) {
        if (!datPersonaGrowthIsParty(persona)) {
            for (roll = 0; (roll & 0xFFFF) < 3; roll = (roll + 1) & 0xFFFF) {
                total = 0;
                sumIndex = 0;
                table = (u8 *)((u32)pidoff + (u32)iGpffffb3dc);
                while ((sumIndex & 0xFFFF) < 5) {
                    if ((s32)(delta[(sumIndex & 0xFFFF) + 0x82] + stat[(u16)sumIndex]) < 99) {
                        total = (total + table[sumIndex & 0xFFFF]) & 0xFFFF;
                    }
                    sumIndex = (sumIndex + 1) & 0xFFFF;
                }
                if ((total & 0xFFFF) > 0) {
                    choice = (datCalcRandomBelow(total & 0xFFFF) + 1) & 0xFFFF;
                    weight = 0;
                    statScan = 0;
                    table = (u8 *)((u32)pidoff + (u32)iGpffffb3dc);
                    while ((statScan & 0xFFFF) < 5) {
                        gain = delta + (statScan & 0xFFFF) + 0x82;
                        if ((s32)(*gain + stat[(u16)statScan]) < 99) {
                            weight = (weight + table[statScan & 0xFFFF]) & 0xFFFF;
                            if (choice <= weight) {
                                *gain += 1;
                                break;
                            }
                        }
                        statScan = (statScan + 1) & 0xFFFF;
                    }
                }
            }
        } else {
            /* measured: typed site/local/array forms change instructions; this existing member is exact. */
            if (MEMBER(u16, persona, DatPersonaRecord, id) < 0xC0 || MEMBER(u16, persona, DatPersonaRecord, id) > 0xD7) {
                kAssertFail(D_005E4318, 0x59F);
            }
            table = (u8 *)iGpffffb3e4 + (personaRecord->id - 0xC0) * 0x26E;
            if (level >= 2) {
                partyIndex = 0;
                table += (u16)level * 5;
                while ((partyIndex & 0xFFFF) < 5) {
                    statValue = &stat[(u16)partyIndex];
                    statBase = *statValue;
                    gain = delta + (partyIndex & 0xFFFF) + 0x82;
                    if ((s32)(*gain + statBase) < 99) {
                        delta[(partyIndex & 0xFFFF) + 0x82] += table[(partyIndex & 0xFFFF) + 0x7A];
                        if ((s32)operandOrderAdd(delta[(partyIndex & 0xFFFF) + 0x82], statBase) > 99) {
                            *gain = 99 - statBase;
                        }
                    }
                    partyIndex = (partyIndex + 1) & 0xFFFF;
                }
            }
        }
        level++;
        delta[0] += 1;
    }
    if (datPersonaGrowthIsParty(persona)) {
        /* measured: typed site/local/array forms change instructions; this existing member is exact. */
        entry = (u8 *)iGpffffb3e4 + (MEMBER(u16, persona, DatPersonaRecord, id) - 0xC0) * 0x26E + 4;
        limit = 32;
        oldLevel = persona[4];
    } else {
        /* measured: typed site/local/array forms change instructions; this existing member is exact. */
        pid = (u16)MEMBER(s16, persona, DatPersonaRecord, id);
        entry = (u8 *)iGpffffb3dc + pid * 0x46 + 6;
        limit = 16;
        /* measured: typed base-level fields change nine bytes; plain byte-table indexing retains MATCH. */
        oldLevel = persona[4] - (iGpffffb3d4[(u32)(u16)pid * sizeof(DatPersonaLevelRow) + MEMBER_OFFSET(DatPersonaLevelRow, baseLevel)]);
    }
    newLevel = oldLevel + delta[0];
    first = 0;
    found = 0;
    span = 0;
    for (rangeIndex = 0; (rangeCurrent = rangeIndex & 0xFFFF) < limit; rangeIndex = (rangeIndex + 1) & 0xFFFF) {
        event = entry + (u16)rangeIndex * 4;
        if (((DatPersonaLearnEvent *)event)->kind == 0) {
            break;
        }
        if (oldLevel < event[0]) {
            if (!found) {
                found = 1;
                first = (u16)rangeIndex;
                last = (u16)rangeIndex;
            }
            if (event[0] <= newLevel) {
                span = 1;
                last = rangeCurrent;
            }
        }
    }
    if (span) {
        count = (last + 1) - first;
    } else {
        count = 0;
    }
    entry += first * 4;
    skills = persona + 0xC;
    known = datPersonaCountSkills((DatPersonaRecord *)persona);
    added = 0;
    removed = 0;
    collectIndex = 0;
    while ((collectIndex & 0xFFFF) < count) {
        learningEvent = (DatPersonaLearnEvent *)entry;
        switch (((DatPersonaLearnEvent *)entry)->kind) {
        case 1:

            if (learningEvent->skill != 0) {

                search = datPersonaGrowthFindSkill(learningEvent->skill, skills, known);
                if (search == known) {
                    if ((added & 0xFFFF) >= 32) {
                        kAssertFail(D_005E4318, 0x604);
                    }
                    ((DatPersonaGrowthDelta *)delta)->addedSkills[(u16)added] = ((DatPersonaLearnEvent *)entry)->skill;
                    added = (added + 1) & 0xFFFF;
                }
            }
            break;
        case 2:
            if (((DatPersonaLearnEvent *)entry)->skill != 0) {
                search = datPersonaGrowthFindSkill(((DatPersonaLearnEvent *)entry)->skill, skills, known);
                if (search != known) {
                    if ((removed & 0xFFFF) >= 32) {
                        kAssertFail(D_005E4318, 0x614);
                    }

                    ((DatPersonaGrowthDelta *)delta)->removedSkills[(u16)removed] = learningEvent->skill;
                    removed = (removed + 1) & 0xFFFF;
                }
            }
            break;
        case 3:
        case 4:
            break;
        default:
            kAssertFail(D_005E4318, 0x61F);
            break;
        }
        collectIndex = (collectIndex + 1) & 0xFFFF;
        entry += 4;
    }
}
#pragma pop
// Intent: applies a level-up delta from arg1 to persona record arg0: level, stat deltas, and newly learned skills.
// FUN_0010C5A0
void datPersonaApplyLevelUp(u8 *persona, u8 *delta)
{
    s32 i;
    s32 j;
    s32 k;

    if (((DatPersonaRecord *)persona)->id == 0 || ((DatPersonaRecord *)persona)->id >= 0x100) {
        kAssertFail(D_005E4318, 0x62E);
    }
    ((DatPersonaRecord *)persona)->level += ((DatPersonaGrowthDelta *)delta)->levelDelta;
    i = 0;
    while ((u16)i < 5) {
        *((u8 *)&((DatPersonaRecord *)persona)->stats[(u16)i]) += ((DatPersonaGrowthDelta *)delta)->statGains[(u16)i];
        i = (i + 1) & 0xFFFF;
    }
    j = 0;
    while ((u16)j < 0x20) {
        if (((DatPersonaGrowthDelta *)delta)->removedSkills[(j & 0xFFFF)] != 0) {
            datPersonaRemoveSkill(persona, ((DatPersonaGrowthDelta *)delta)->removedSkills[(j & 0xFFFF)]);
        }
        j = (j + 1) & 0xFFFF;
    }
    k = 0;
    while ((u16)k < 0x20) {
        if (((DatPersonaGrowthDelta *)delta)->addedSkills[(k & 0xFFFF)] != 0) {
            datPersonaAddSkill(persona, ((DatPersonaGrowthDelta *)delta)->addedSkills[(k & 0xFFFF)]);
        }
        k = (k + 1) & 0xFFFF;
    }
}

/* 556/560 bytes; fifteen resolved relocations; four zero alignment bytes.
 * Typed party records and experience curves retain retail address ordering. */
// Intent: total experience needed to reach level arg1 on persona arg0's growth curve; levels below 2 return 0.
/* Retain byte-pointer interfaces while naming fields through the proven record layouts. */

// FUN_0010C750

u32 datPersonaGetExpForLevel(void *persona, u16 level)
{
    DatPersonaRecord *work = persona;
    u32 partyPersona;
    s32 baseOffset;
    f32 levelF;
    f32 baseLevelF;
    f32 prod;
    u16 curveId;
    s32 result;

    if ((level & 0xFFFF) < 2) {
        result = 0;
    } else {
        if ((level & 0xFFFF) > 99) {
            level = 0x63;
        }


        if ((work->id >= 0xC0) &&
            (work->id < 0xD8)) {
            partyPersona = 1;
        } else {
            partyPersona = 0;
        }
        if (partyPersona == 0) {

            if (work->id >= 0x100) {
                kAssertFail(D_005E4318, 0x673);
            }
            levelF = (f32)level;
            baseOffset = (s32)work->id * 0xE;
            baseLevelF = (f32)(u32)iGpffffb3d4[baseOffset + 3];
            prod = fGpffff8150 * levelF;
            result = (s32)((0.0f + 10.0f) +
                           ((fGpffff820c + 0.0f - fGpffff8208 * baseLevelF) *
                            (prod * levelF * levelF)));
        } else {

            if ((work->id < 0xC0) ||

                (work->id > 0xD7)) {
                kAssertFail(D_005E4318, 0x67B);
            }
            curveId = iGpffffb3e4[work->id - 0xC0][0];
            if ((curveId <= 1) || (curveId >= 0xB)) {
                kAssertFail(D_005E4318, 0x67D);
            }
            result = iGpffffb3e8[curveId - 2][(level & 0xFFFF) - 2];
        }
    }
    return (u32)result;
}

// Intent: adds experience arg1 to persona record arg0 at +8; fatal when negative.
// FUN_0010C980
void datPersonaAddExp(DatPersonaRecord *persona, s32 addedExp)
{
    if (addedExp < 0) {
        kAssertFail(D_005E4318, 0x689);
    }
    persona->exp += addedExp;
}

#pragma push
/* measured: ported the matching P3 FES skill-compaction structure, with
   the loop-invariant pragma required to retain retail's maxSkills preheader;
   normalized_diff 0, object_size 232/240. */
// FUN_0010C9E0
/* measured: baseline differs by 33 words; a cached skills pointer leaves nd67; retain hoisting. */
#pragma opt_loop_invariants on
// Intent: compacts the 8-slot skill list of persona record arg0 so non-empty skills come first.
void datPersonaCompactSkills(u8 *persona)
{
    u8 *record;
    s32 skillIdx;
    s32 nextSkillIdx;
    s32 maxSkills;

    record = persona;
    if (record == NULL) {
        kAssertFail(D_005E4318, 0x69D);
    }
    maxSkills = 8;
    skillIdx = 0;
    nextSkillIdx = 0;
    while (skillIdx < maxSkills) {
        if (((DatPersonaRecord *)record)->skills[skillIdx] == 0) {
            nextSkillIdx = skillIdx + 1;
            while (nextSkillIdx < maxSkills) {
                if (((DatPersonaRecord *)record)->skills[nextSkillIdx] != 0) {
                    break;
                }
                nextSkillIdx++;
            }
            if (nextSkillIdx == maxSkills) {
                return;
            }
        }
        if (skillIdx != nextSkillIdx) {
            if (nextSkillIdx < maxSkills) {
                ((DatPersonaRecord *)record)->skills[skillIdx] = ((DatPersonaRecord *)record)->skills[nextSkillIdx];
            } else {
                ((DatPersonaRecord *)record)->skills[skillIdx] = 0;
            }
        }
        skillIdx++;
        nextSkillIdx++;
    }
}
/* measured: closing pragma balances the required loop-invariant setting; nd 0. */
#pragma pop

#pragma push
/* The halfword persona contract retains both retail masks when common
 * subexpression folding is disabled for this initializer. */
/* measured: baseline differs by 52 words; typed level-row array access leaves nd133; retain common-subexpression setting. */
#pragma opt_common_subs off
// Intent: initializes roster record arg0 for persona id arg1 from its table row, at the table level, with fixed skills.
// FUN_0010CAD0
void datPersonaInitRecord(u8 *persona, u16 personaId)
{
    s32 id;
    s32 offset;
    u8 buf[0x88];

    if (persona == NULL) {
        kAssertFail(D_005E4318, 0x6C2);
    }
    id = personaId & 0xFFFF;
    if (id == 0 || id >= 0x100) {
        kAssertFail(D_005E4318, 0x6C3);
    }
    id = (u16)personaId;
    offset = id * 0xE;
    {
        u8 *entry;

        entry = iGpffffb3d4 + offset;
        ((DatPersonaRecord *)persona)->id = (u16)personaId;
        ((DatPersonaRecord *)persona)->level = entry[3];
        ((DatPersonaRecord *)persona)->unknown05 = entry[9];
        ((DatPersonaRecord *)persona)->exp = datPersonaGetExpForLevel(persona, entry[3]);
    }
    ((DatPersonaRecord *)persona)->unknown2C = 0;
    memcpy(persona + 0x1C, iGpffffb3d4 + offset + 4, 5);
    memset(persona + 0x21, 0, 5);
    memset(persona + 0x26, 0, 5);
    memset(persona + 0xC, 0, 0x10);
    datPersonaPreviewLevelUp(persona, buf, 0);
    datPersonaApplyLevelUp(persona, buf);
    datPersonaLearnFixedSkills(persona);
}

#pragma pop
// Intent: stores skill arg1 in the first empty slot of record arg0; returns 1 on success, 0 when full.
// FUN_0010CC20
s32 datPersonaAddSkill(u8 *persona, u16 skillId)
{
    s32 i;

    if (persona == NULL || (skillId & 0xFFFF) == 0) {
        kAssertFail(D_005E4318, 0x6E0);
    }
    i = 0;
    while (i < 8) {
        if (((DatPersonaRecord *)persona)->skills[i] == 0) {
            ((DatPersonaRecord *)persona)->skills[i] = (u16)skillId;
            return 1;
        }
        i++;
    }
    return 0;
}

// Intent: clears skill arg1 from record arg0 and compacts the list; returns 1 when found.
// FUN_0010CCC0
s32 datPersonaRemoveSkill(u8 *persona, u32 skillId)
{
    s32 i;
    s32 key;
    u16 v2;

    if (persona == NULL || (skillId & 0xFFFF) == 0) {
        kAssertFail(D_005E4318, 0x6EE);
    }
    i = 0;
    key = skillId & 0xFFFF;
    while (i < 8) {
        v2 = ((DatPersonaRecord *)persona)->skills[i];
        if (v2 == key) {
            ((DatPersonaRecord *)persona)->skills[i] = 0;
            datPersonaCompactSkills(persona);
            return 1;
        }
        i++;
    }
    return 0;
}

// Intent: replaces skill arg1 in record arg0 with arg2 when present; returns the slot index, or -1 when absent.
/* The slot lookup supplies a byte offset into the DatPersonaRecord skills at +0x0C; retain the explicit offset local used for the final store. */
// FUN_0010CD70
s32 datPersonaReplaceSkill(u8 *persona, s16 oldSkill, u16 newSkill)
{
    if (persona == NULL || (s16)oldSkill == 0 || (newSkill & 0xFFFF) == 0) {
        kAssertFail(D_005E4318, 0x6FE);
    }
    {
        s32 r = datPersonaFindSkillSlot(persona, (u16)oldSkill);
        if (r != -1) {
            s32 off = r * 2;
            ((DatPersonaRecord *)(off + (s32)persona))->skills[0] = (u16)newSkill;
        }
        return r;
    }
}

// Intent: index of skill arg1 in the 8-slot list of record arg0, or -1 when absent.
// FUN_0010CE10
s32 datPersonaFindSkillSlot(u8 *persona, u16 skillId)
{
    s32 i;
    u32 key;

    if (persona == NULL || (skillId & 0xFFFF) == 0) {
        kAssertFail(D_005E4318, 0x70A);
    }
    i = 0;
    key = skillId & 0xFFFF;
    while (i < 8) {
        u16 v = ((DatPersonaRecord *)persona)->skills[i];
        if (v == key) {
            return i;
        }
        i++;
    }
    return -1;
}

// Intent: number of non-empty skill slots in persona record arg0 (8 slots); 8 means full.
// FUN_0010CEB0
s32 datPersonaCountSkills(DatPersonaRecord *persona)
{
    s32 count = 0;
    s32 i;

    if (persona == NULL) {
        kAssertFail(D_005E4318, 0x717);
    }
    i = 0;
    while (i < 8) {
        if (((DatPersonaRecord *)persona)->skills[i] != 0) {
            count++;
        }
        i++;
    }
    return count;
}

// Intent: skill id in slot arg1 (0..7) of persona record arg0.
// FUN_0010CF40
u16 datPersonaGetSkillAt(DatPersonaRecord *persona, s16 slotIndex)
{
    s32 index = slotIndex;

    if (index >= 8) {
        kAssertFail(D_005E4318, 0x723);
    }
    return persona->skills[index];
}
// Intent: stores source record arg2 (persona id arg1, its skills and stat bonuses) into the 0x30-byte record arg0; returns 1.
// FUN_0010CFA0
s32 datPersonaLoadRecord(u8 *destination, u16 personaId, u8 *source)
{
    s32 i;
    s32 i2;
    s32 v;
    s32 *sourceWords;
    s32 *destinationWords;
    s32 firstWord;
    s32 secondWord;
    s32 pairsRemaining;
    u8 *src;
    u8 *dst;
    u8 entry[0x30];
    u8 buf[0x90];

    if (destination == NULL) {
        kAssertFail(D_005E4318, 0x7AF);
    }
    if (source == NULL) {
        kAssertFail(D_005E4318, 0x7B0);
    }
    v = ((DatPersonaRecord *)source)->exp;
    datPersonaInitRecord(entry, personaId);
    datPersonaPreviewLevelUp(entry, buf, v);
    datPersonaApplyLevelUp(entry, buf);
    if (v < 0) {
        kAssertFail(D_005E4318, 0x689);
    }
    ((DatPersonaRecord *)entry)->exp += v;
    src = source + 0xC;
    dst = entry + 0xC;
    for (i = 0; i < 8; i++) {
        ((u16 *)dst)[i] = ((u16 *)src)[i];
    }
    if (entry == NULL || source == NULL) {
        kAssertFail(D_005E4318, 0x778);
    }
    for (i2 = 0; i2 < 5; i2++) {
        *((u8 *)&((DatPersonaRecord *)entry)->statBonusA[i2]) = *((u8 *)&((DatPersonaRecord *)source)->statBonusA[i2]);
        *((u8 *)&((DatPersonaRecord *)entry)->statBonusB[i2]) = *((u8 *)&((DatPersonaRecord *)source)->statBonusB[i2]);
    }
    sourceWords = (s32 *)entry;
    destinationWords = (s32 *)destination;
    pairsRemaining = 6;
    do {
        firstWord = sourceWords[0];
        secondWord = sourceWords[1];
        sourceWords += 2;
        pairsRemaining--;
        destinationWords[0] = firstWord;
        destinationWords[1] = secondWord;
        destinationWords += 2;
    } while (pairsRemaining > 0);
    return 1;
}

// Intent: adds the fixed-table skills of a party persona record arg0 (ids 0xC0..0xD7) into its empty skill slots.
// FUN_0010D150
void datPersonaLearnFixedSkills(u8 *persona)
{
    s32 i;
    s32 j;
    s32 b;
    u16 n;
    u8 *entry;
    u16 id = ((DatPersonaRecord *)persona)->id;

    if (id >= 0xC0 && id < 0xD8) {
        b = 1;
    } else {
        b = 0;
    }
    if (b) {
        entry = (u8 *)iGpffffb3e4 + (id - 0xC0) * 0x26E + 4;
        for (i = 0; i < 0x20; i++) {
            if (((DatPersonaLearnEvent *)entry)[i].level == 0 && ((DatPersonaLearnEvent *)entry)[i].kind == 1) {
                n = ((DatPersonaLearnEvent *)entry)[i].skill;
                if (persona == NULL || (n & 0xFFFF) == 0) {
                    kAssertFail(D_005E4318, 0x6E0);
                }
                for (j = 0; j < 8; j++) {
                    if (((DatPersonaRecord *)persona)->skills[j] == 0) {
                        ((DatPersonaRecord *)persona)->skills[j] = n;
                        break;
                    }
                }
            }
        }
    } else {
        entry = (u8 *)iGpffffb3dc + (id & 0xFFFF) * 0x46 + 6;
        for (i = 0; i < 0x10; i++) {
            if (((DatPersonaLearnEvent *)entry)[i].level == 0 && ((DatPersonaLearnEvent *)entry)[i].kind == 1) {
                n = ((DatPersonaLearnEvent *)entry)[i].skill;
                if (persona == NULL || (n & 0xFFFF) == 0) {
                    kAssertFail(D_005E4318, 0x6E0);
                }
                for (j = 0; j < 8; j++) {
                    if (((DatPersonaRecord *)persona)->skills[j] == 0) {
                        ((DatPersonaRecord *)persona)->skills[j] = n;
                        break;
                    }
                }
            }
        }
    }
}
