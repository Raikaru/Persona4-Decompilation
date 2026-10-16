/* Original translation unit datPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "datPersona_internal.h"
#include "datUnit_internal.h"
extern u8 D_00796E50[];

extern void kAssertFail(const void *file, u32 line);
extern void *memset(void *dest, s32 value, s32 size);
extern s32 datCalcSkillSlotValue(s32 arg0, u16 arg1);
extern char D_005E4318[];
extern s16 D_00797F88[];
extern s16 D_00797F8C[];
extern s16 D_0079819C[];
extern u8 D_007973A0[];
extern u8 D_00797F8E[];
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
static inline s32 datPersonaOrFlag(s32 flags, s32 mask)
{
    return flags | mask;
}

extern void memcpy(void *dst, void *src, u32 size);
extern void datPersonaResolveRecord(u8 *arg0);

extern void datPersonaResolveRecord(u8 *arg0);

extern s32 datPersonaSetLeadSlot(); /* old-style: target call preserves s64 argument */

extern u32 datCalcRandomBelow(u32 arg0);

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
u16 datPersonaRecordId(u32 arg0)
{
    return *(u16 *)(arg0 + 2);
}

// Intent: u16 id at +2 of roster slot arg0; fatal when the slot is NULL.
// FUN_00109300
u16 datPersonaRosterSlotId(s32 arg0)
{
    u16 *p = datPersonaRosterSlot(arg0);
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x3E);
    }
    return *(u16 *)((u8 *)p + 2);
}

// Intent: u16 id at +2 of the record for persona id arg0.
// FUN_00109360
u16 datPersonaGetRecordId(u16 arg0)
{
    return *(u16 *)((u8 *)datPersonaGetRecord(arg0) + 2);
}

// Intent: u8 at +4 of roster slot arg0, a ranking key; the largest value among same-type party members wins; fatal when NULL.
// FUN_001093A0
u8 datPersonaRosterSlotRank(s32 arg0)
{
    u16 *p = datPersonaRosterSlot(arg0);
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x5F);
    }
    return *(u8 *)((u8 *)p + 4);
}

// Intent: u16 flags word of roster slot arg0; fatal when the slot is NULL.
// FUN_00109470
u16 datPersonaRosterSlotFlags(s32 arg0)
{
    u16 *p = datPersonaRosterSlot(arg0);
    if (p == NULL) {
        kAssertFail(D_005E4318, 0xF1);
    }
    return *p;
}

/* The selected learning range uses independent output and traversal counts.
   Its length helper preserves that value across the known-skill query.
   Native b210 O2 with these scoped propagation/loop settings is exact
   684/688 bytes; see docs/probe_archive/Persona_skills_00109510_20260922.md. */
static inline s32 datPersonaSelectedCount(s32 first, s32 last)
{
    return (last + 1) - first;
}

// Intent: writes the skill ids (arg1) and levels (arg2, optional) of persona record arg0's level-table entries it has not learned yet; returns the count.
// FUN_00109510
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
s32 datPersonaCollectLearnableSkills(u8 *persona, void *arg1, void *arg2)
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
    u8 *skills;

    if ((s32)*(u16 *)(persona + 2) >= 0x100)
    {
        kAssertFail(D_005E4318, 0x132);
    }
    if (datPersonaUsesFixedGrowth((DatPersonaRecord *)persona) != 0)
    {
        table = (u8 *)iGpffffb3e4 + (*(u16 *)(persona + 2) - 0xC0) * 0x26E + 4;
        maximum = 0x20;
        baseLevel = 0;
        lowerLevel = *(u8 *)(persona + 4);
        remainingLevels = 0x63 - lowerLevel;
    }
    else
    {
        u16 id = *(u16 *)(persona + 2);
        u8 *baseRecord;
        u32 recordAddress;
        table = iGpffffb3dc + id * 0x46 + 6;
        maximum = 0x10;
        baseRecord = iGpffffb3d4;
        recordAddress = id * 0xE;
        recordAddress += (u32)baseRecord;
        baseLevel = ((u8 *)recordAddress)[3];
        lowerLevel = *(u8 *)(persona + 4) - baseLevel;
        remainingLevels = 0x63 - *(u8 *)(persona + 4);
    }
    upperLevel = lowerLevel + remainingLevels;
    first = 0;
    foundFirst = 0;
    foundLast = 0;
    i = 0;
    while (i < maximum)
    {
        entry = table + i * 4;
        if (*(s8 *)(entry + 1) == 0)
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
    skills = persona + 0xC;
    known = datPersonaCountSkills(persona);
    count = 0;
    visit = 0;
    while (visit < span)
    {
        switch (*(s8 *)(table + 1))
        {
        case 1:
            skill = 0;
            while (skill < known)
            {
                if (*(u16 *)(table + 2) == *(u16 *)(skills + skill * 2))
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
                ((u16 *)arg1)[count] = *(u16 *)(table + 2);
                if (arg2 != NULL)
                {
                    ((u16 *)arg2)[count] = *(u8 *)table + baseLevel;
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
// FUN_001097C0
void datPersonaRunSkillSlot(u8 *arg0, s32 arg1)
{
    u8 *skillTable;

    if ((u16)*(u16 *)(arg0 + 2) >= 0x100) {
        kAssertFail(D_005E4318, 0x1B7);
    }
    if ((arg1 & 0xFFFF) >= 0x10) {
        kAssertFail(D_005E4318, 0x1B8);
    }
    skillTable = iGpffffb3d8 + (u16)*(u16 *)(arg0 + 2) * 0x20;
    datCalcSkillSlotValue(0, *(u16 *)(skillTable + (u16)arg1 * 2));
}

// Intent: skill-slot value of persona id arg0 at slot arg1, read through datCalcSkillSlotValue; fatal when out of range.
// FUN_00109870
u32 datPersonaGetSkillSlot(u16 arg0, s32 arg1)
{
    u8 *persona;

    persona = (u8 *)datPersonaGetRecord(arg0);
    if ((u16)*(u16 *)(persona + 2) >= 0x100) {
        kAssertFail(D_005E4318, 0x1B7);
    }
    if ((arg1 & 0xFFFF) >= 0x10) {
        kAssertFail(D_005E4318, 0x1B8);
    }
    return (u32)datCalcSkillSlotValue(0, *(u16 *)(iGpffffb3d8 + (u16)*(u16 *)(persona + 2) * 0x20 + (u16)arg1 * 2));
}

// Intent: battle stat (index 0..4, see DatPersonaStat in datPersona_internal.h) at +0x1C of a persona record.
// FUN_00109920
u8 datPersonaGetStat(DatPersonaRecord *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    return arg0->stats[(u16)arg1];
}

// Intent: battle stat (index 0..4) of the record for persona id arg0; same layout as datPersonaGetStat.
// FUN_00109980
/* Preserve the public word transport while interpreting the character as a halfword. */
s32 datPersonaGetStatById(arg0, arg1)
u16 arg0;
s32 arg1;
{
    u16 *p = datPersonaGetRecord(arg0);
    u8 *base = (u8 *)p;
    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    return base[(u16)arg1 + 0x1C];
}

// Intent: battle stat arg1 of record arg0 plus two stat modifiers, capped at 99; fatal when arg1 >= 5.
// FUN_001099F0
u8 datPersonaGetBuffedStat(DatPersonaRecord *arg0, s32 arg1)
{
    s16 a;
    s16 b;
    s8 c;
    s16 sum;
    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    a = (s16)arg0->stats[(u16)arg1];
    b = (s8)datPersonaGetStatBonusA(arg0, arg1);
    c = (s8)datPersonaGetStatBonusB(arg0, arg1);
    sum = (s16)(a + b + c);
    if (sum >= 0x63) {
        sum = 0x63;
    }
    return (u8)sum;
}

// Intent: battle stat arg1 of record arg0 plus two modifiers and the equipment bonus, clamped to 0..99.
// FUN_00109AD0
u8 datPersonaGetTotalStat(DatPersonaRecord *arg0, s32 arg1)
{
    s16 a;
    s16 b;
    s16 c;
    s8 d;
    s16 sum;

    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    a = (s16)arg0->stats[(u16)arg1];
    b = (s8)datPersonaGetStatBonusA(arg0, arg1);
    c = (s8)datPersonaGetStatBonusB(arg0, arg1);
    d = (s8)datPersonaGetEquipStatBonus(arg0, arg1);
    sum = (s16)(a + b + c + d);
    if (sum > 0x63) {
        sum = 0x63;
    } else if (sum < 0) {
        sum = 0;
    }
    return (u8)sum;
}

// Intent: battle stat arg1 of the record for persona id arg0, plus modifiers and equipment, clamped to 0..99.
// FUN_00109BF0
u8 datPersonaGetTotalStatById(u16 arg0, s32 arg1)
{
    s16 a;
    s16 b;
    s16 c;
    s8 d;
    s16 sum;
    DatPersonaRecord *p = (DatPersonaRecord *)datPersonaGetRecord(arg0);

    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x1DE);
    }
    a = (s16)p->stats[(u16)arg1];
    b = (s8)datPersonaGetStatBonusA(p, arg1);
    c = (s8)datPersonaGetStatBonusB(p, arg1);
    d = (s8)datPersonaGetEquipStatBonus(p, arg1);
    sum = (s16)(a + b + c + d);
    if (sum > 0x63) {
        sum = 0x63;
    } else if (sum < 0) {
        sum = 0;
    }
    return (u8)sum;
}

// Intent: signed per-stat bonus byte at +0x21 of a record for stat arg1; summed into the stat totals.
// FUN_00109D20
s8 datPersonaGetStatBonusA(DatPersonaRecord *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x268);
    }
    return arg0->statBonusA[(u16)arg1];
}

// Intent: signed per-stat bonus byte at +0x26 of a record for stat arg1; summed into the stat totals.
// FUN_00109DD0
s8 datPersonaGetStatBonusB(DatPersonaRecord *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x299);
    }
    return arg0->statBonusB[(u16)arg1];
}

extern u16 datCalcCountIdSlotsWithValue(u16 arg0, u16 arg1);
extern s16 D_00797578[];
extern u8 D_00796D90[];
extern u8 *iGpffffb1b0;

/* 2372/2384 bytes; 56 resolved relocations; 12 zero alignment bytes.
 * The real equipment-query inputs are unsigned halfwords. Keep each weighted
 * query independent and preserve the signed-byte result for the stat clamp. */
// Intent: equipment bonus for stat arg1 of record arg0, summed from the equipped items of its party slot.
// FUN_00109E30
s8 datPersonaGetEquipStatBonus(DatPersonaRecord *arg0, s32 arg1)
{
    s16 bonus;
    u16 party;
    s16 equipped;
    u16 equipment;
    u16 stat = (u16)arg1;
    if (stat >= 5) {
        kAssertFail(D_005E4318, 0x2CD);
    }
    bonus = 0;
    if (datPersonaUsesFixedGrowth(arg0) != 0) {
        if (arg0->id < 0xC0 || arg0->id > 0xD7) {
            kAssertFail(D_005E4318, 0x2D4);
        }
        party = iGpffffb3e4[arg0->id - 0xC0][0];
    } else {
        party = 1;
    }
    if ((u16)party >= 0xB) {
        kAssertFail(D_005E4318, 0x2D9);
    }
    if ((s16)party == 1) {
        equipped = D_00797578[0];
    } else {
        equipped = *(s16 *)(D_00796D90 + (s16)party * 0x88);
    }
    equipment = equipped;
    switch (stat) {
    case 0:
        bonus += *(s16 *)(iGpffffb1b0 + (s16)equipment * 0x44 + 20);
        break;
    case 2:
        bonus += *(s16 *)(iGpffffb1b0 + (s16)equipment * 0x44 + 22);
        break;
    case 1:
        bonus += *(s16 *)(iGpffffb1b0 + (s16)equipment * 0x44 + 24);
        break;
    case 3:
        bonus += *(s16 *)(iGpffffb1b0 + (s16)equipment * 0x44 + 26);
        break;
    case 4:
        bonus += *(s16 *)(iGpffffb1b0 + (s16)equipment * 0x44 + 28);
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
s32 datPersonaAddStat(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *stat;
    s16 naturalStat;
    s16 statTotal;

    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x36C);
    }

    stat = (u8 *)((u32)(u16)arg1 + (u32)arg0) + 0x1C;
    naturalStat = (s16)(u16)*stat;
    statTotal = naturalStat + (s8)arg2;
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
s32 datPersonaAddStatById(u16 arg0, s32 arg1, s32 arg2) {
    u8 *base;
    u8 *stat;
    s16 old;
    s16 delta;
    s16 total;

    base = (u8 *)datPersonaGetRecord(arg0);
    if ((arg1 & 0xFFFF) >= 5) {
        kAssertFail(D_005E4318, 0x36C);
    }
    stat = (u8 *)((u32)(u16)arg1 + (u32)base) + 0x1C;
    old = (s16)(u16)*stat;
    delta = (s8)arg2;
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
u16 *datPersonaGetRecord(u16 arg0)
{
    u16 *p;
    s32 v = arg0 & 0xFFFF;

    if (v == 1) {
        p = datPersonaRosterSlot(D_00797F88[0]);
    } else {
        if (v >= 0xB) {
            kAssertFail(D_005E4318, 0x3A5);
        }
        p = (u16 *)(&((DatPartySlot *)D_00796E50)[v - 2].personaRecord);
    }
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x3A9);
    }
    return p;
}

// Intent: true when the lead (id 1) record has flag bit 4 set; datCalc scales damage and code1_0021 scales level when it is.
// FUN_0010A9B0
s32 datPersonaLeadBoosted(s32 arg0)
{
    u16 *p;
    s32 v = arg0 & 0xFFFF;

    if (v != 1) {
        return 0;
    }
    if (v == 1) {
        p = datPersonaRosterSlot(D_00797F88[0]);
    } else {
        if (v >= 0xB) {
            kAssertFail(D_005E4318, 0x3A5);
        }
        p = (u16 *)(&((DatPartySlot *)D_00796E50)[v - 2].personaRecord);
    }
    if (p == NULL) {
        kAssertFail(D_005E4318, 0x3A9);
    }
    return (*(u16 *)p & 4) != 0;
}

// Intent: index of the active roster slot whose id matches, or -1.
// FUN_0010AA80
s32 datPersonaFindRosterSlotById(s32 arg0)
{
    s32 count = datPersonaRosterCapacity() & 0xFFFF;
    s32 i = 0;
    s32 id = (s16)arg0;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 && *(u16 *)(base + 0xBEC + off + 2) == id) {
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
        if ((*(u16 *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC) & 1) == 0) {
            return (s16)i;
        }
        i = (i + 1) & 0xFFFF;
    }
    return -1;
}

// Intent: true when roster slot arg0 has its active flag set.
// FUN_0010ABD0
s32 datPersonaRosterSlotActive(s16 arg0)
{
    return (*(u16 *)((u8 *)D_00797F8C + (s32)arg0 * 0x30) & 1) != 0;
}

// Intent: roster record of the active slot matching the id, or NULL.
// FUN_0010AC10
u16 *datPersonaFindRosterRecordById(s32 arg0)
{
    s32 count = datPersonaRosterCapacity() & 0xFFFF;
    s32 i = 0;
    s16 found;
    s32 id = (s16)arg0;
    u8 *base = D_007973A0;
    s32 off;

    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 &&
            *(u16 *)(base + 0xBEC + off + 2) == id) {
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
u16 *datPersonaRosterSlot(s16 arg0)
{
    s32 v = (s32)arg0;

    if (v < 0 || v >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x3FE);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + v * 0x30) & 1) == 0) {
        return NULL;
    }
    return (u16 *)((u8 *)D_007973A0 + v * 0x30 + 0xBEC);
}

// Intent: removes the active roster slot holding the id, if any.
// FUN_0010AD80
s32 datPersonaRemoveRosterMemberById(s32 arg0)
{
    s32 count = datPersonaRosterCapacity() & 0xFFFF;
    s32 i = 0;
    s32 arg;
    s32 id = (s16)arg0;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 && *(u16 *)(base + 0xBEC + off + 2) == id) {
            arg = (s16)i;
            goto done;
        }
    }
    arg = -1;
done:
    return datPersonaRemoveRosterSlot(arg);
}

// Intent: removes roster slot arg0, shifts later slots down, then reselects the lead.
// FUN_0010AE30
s32 datPersonaRemoveRosterSlot(s32 arg0)
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

    id = (s16)arg0;
    if (id < 0 || id >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x417);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + id * 0x30) & 1) == 0) {
        return 0;
    }
    selected = datPersonaLeadPersonaId();
    for (i = (s16)arg0; (s32)i < 0xB; i++) {
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
        if ((*(u16 *)(entry + 0xBEC) & 1) != 0 &&
            *(u16 *)(entry + 0xBEE) == selected32) {
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
        if ((*(u16 *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC) & 1) == 0) {
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
    *(u16 *)((u8 *)D_00797F8C + found * 0x30) &= 0xC;
    *(u16 *)((u8 *)D_00797F8C + found * 0x30) |= 1;
    datPersonaResolveRecord(entry);
    return entry;
}

// Intent: copies a 0x30-byte record into the first free roster slot; returns 1 on success, 0 when full.
// FUN_0010B190
s32 datPersonaInsertRosterRecord(u8 *arg0)
{
    s32 i;
    s16 found;
    u8 *entry;

    if (arg0 == NULL) {
        kAssertFail(D_005E4318, 0x464);
    }
    if (*(u16 *)(arg0 + 2) == 0 || *(u16 *)(arg0 + 2) >= 0x100) {
        kAssertFail(D_005E4318, 0x465);
    }
    i = 0;
    while ((u16)i < (u16)datPersonaRosterCapacity()) {
        if ((*(u16 *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC) & 1) == 0) {
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
    memcpy(entry, arg0, 0x30);
    *(u16 *)((u8 *)D_00797F8C + found * 0x30) &= 0xC;
    *(u16 *)((u8 *)D_00797F8C + found * 0x30) |= 1;
    datPersonaResolveRecord(entry);
    return 1;
}

// Intent: selects the active roster slot holding the id as lead; returns 0 when no slot matches.
// FUN_0010B300
s32 datPersonaSelectRosterMemberById(s32 arg0)
{
    s32 count = datPersonaRosterCapacity() & 0xFFFF;
    s32 i = 0;
    s32 arg;
    s32 id = (s16)arg0;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 && *(u16 *)(base + 0xBEC + off + 2) == id) {
            arg = (s16)i;
            goto done;
        }
    }
    arg = -1;
done:
    return datPersonaSetLeadSlot(arg);
}

// Intent: makes roster slot arg0 the lead when it is active; returns 0 otherwise.
// FUN_0010B3B0
s32 datPersonaSetLeadSlot(s32 arg0)
{
    s32 idx = (s16)arg0;
    if (idx < 0 || idx >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x47E);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + idx * 0x30) & 1) == 0) {
        return 0;
    }
    D_00797F88[0] = (s16)arg0;
    return 1;
}

// Intent: persona id held in the lead slot's record (+2); callers treat it as the current lead persona.
// FUN_0010B460
u16 datPersonaLeadPersonaId(void)
{
    s32 v = D_00797F88[0];
    s32 off;

    if (v < 0 || v >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x491);
    }
    off = v * 0x30;
    if ((*(u16 *)((u8 *)D_00797F8C + off) & 1) == 0) {
        kAssertFail(D_005E4318, 0x492);
    }
    return *(u16 *)((u8 *)D_00797F8E + off);
}

// Intent: index of the lead roster slot; fatal when the lead slot is inactive.
// FUN_0010B510
s32 datPersonaGetLeadSlot(void)
{
    s32 v = D_00797F88[0];

    if (v < 0 || v >= (u16)datPersonaRosterCapacity()) {
        kAssertFail(D_005E4318, 0x49C);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + v * 0x30) & 1) == 0) {
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

/* measured: nested static inline OR helper preserves retail's intermediate
   ori sequence for modes 2 and 3; helper is required for exact b610 codegen. */
/* measured: opt_propagation off preserves the three retail mask/and steps. */
#pragma opt_propagation off
// Intent: sets the roster mode flags (none, 1, 2 or 3 cumulative) that select the capacity.
// FUN_0010B610
void datPersonaSetRosterMode(s32 arg0)
{
    s32 flags;
    s32 mode;

    flags = D_0079B40C[0];
    flags &= ~1;
    flags &= ~2;
    flags &= ~4;
    D_0079B40C[0] = flags;
    mode = arg0 & 0xFFFF;
    switch (mode) {
    case 0:
        break;
    case 1:
        D_0079B40C[0] = flags | 1;
        break;
    case 2:
        D_0079B40C[0] = datPersonaOrFlag(datPersonaOrFlag(flags, 1), 2);
        break;
    case 3:
        D_0079B40C[0] = datPersonaOrFlag(datPersonaOrFlag(datPersonaOrFlag(flags, 1), 2), 4);
        break;
    default:
        kAssertFail(D_005E4318, 0x4CD);
        break;
    }
}
/* measured: explicit opposite pragma closes the b610 propagation bracket. */
#pragma opt_propagation on
/* measured: sibling P3 valid-count shape closes this 0xD0 window with
   opt_loop_invariants; the explicit bracket is required for the hoisted base. */
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
        valid = (*(u16 *)((u8 *)D_007973A0 + (s16)personaIdx * 0x30 + 0xBEC) & 1) != 0;
        if (valid) {
            validCount++;
        }
    }
    return validCount;
}
/* measured: explicit opposite pragma closes the one-function optimization bracket. */
#pragma opt_loop_invariants off
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
    u8 sp30[0x30];
    s32 selected;
    s64 index;
    u16 maxPersonaCount;
    s32 personaCount;
    s32 temp_off;
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
    temp_off = (s32)selected * 0x30;
    if ((*(u16 *)((u8 *)D_00797F8C + temp_off) & 1) == 0) {
        kAssertFail(D_005E4318, 0x50C);
    }
    if (index != 0) {
        memcpy(sp30, (u8 *)D_007973A0 + temp_off + 0xBEC, 0x30);
        i = (s16)index;
        while (i > 0) {
            memcpy((u8 *)D_007973A0 + i * 0x30 + 0xBEC,
                          (u8 *)D_007973A0 + (i - 1) * 0x30 + 0xBEC,
                          0x30);
            i--;
        }
        memcpy((void *)D_00797F8C, sp30, 0x30);
        D_00797F88[0] = 0;
    }
}
/* 1008/1008 bytes; forty-five fully resolved relocations, no alignment tail.
 * Preserve the promoted search bound and signed persona-ID comparison.
 * Initialization and diagnostics can change the capacity flags: reload them
 * at each subsequent validation, as the retail body does. */
// Intent: places persona arg1 into the first free slot of roster mode arg0 (mode 1 is the selection).
// FUN_0010B9A0
s32 datPersonaPlaceRosterMember(s32 arg0, u16 arg1)
{
    s32 v = arg0 & 0xFFFF;
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
            datPersonaInitRecord(p, arg1);
            *(u16 *)((u8 *)D_00797F8C + emptyOff) &= 0xC;
            *(u16 *)((u8 *)D_00797F8C + emptyOff) |= 1;
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
        id = (s16)arg1;
        personaCount = (u16)maxPersonaCount;
        base = (u8 *)D_007973A0;
        for (; (u16)i < personaCount; i = (u16)(i + 1)) {
            off = (i & 0xFFFF) * 0x30;
            if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 && *(u16 *)(base + 0xBEC + off + 2) == id) {
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
        if ((*(u16 *)((u8 *)D_00797F8C + found * 0x30) & 1) != 0) {
            D_00797F88[0] = found;
        }
    } else {
        if (v == 1) {
            cur = D_00797F88[0];
            if (cur < 0 || cur >= (u16)datPersonaRosterCapacity()) {
                kAssertFail(D_005E4318, 0x3FE);
            }
            curOff = cur * 0x30;
            p = ((*(u16 *)((u8 *)D_00797F8C + curOff) & 1) != 0) ? (u8 *)D_007973A0 + curOff + 0xBEC : NULL;
        } else {
            if (v >= 0xB) {
                kAssertFail(D_005E4318, 0x3A5);
            }
            p = (u8 *)&((DatPartySlot *)D_00796E50)[v - 2].personaRecord;
        }
        if (p == NULL) {
            kAssertFail(D_005E4318, 0x3A9);
        }
        datPersonaInitRecord(p, arg1);
        *(u16 *)p = 1;
    }
    return 1;
}

// Intent: clears roster mode arg0; mode 1 resets the selection and the roster block, other modes clear one party block.
// FUN_0010BD90
void datPersonaResetRosterMode(s16 arg0)
{
    s32 v = (s32)arg0;

    if (v == 1) {
        D_00797F88[0] = -1;
        memset((void *)D_00797F8C, 0, 0x240);
    } else {
        memset((void *)&((DatPartySlot *)D_00796E50)[v - 2].personaRecord, 0, sizeof(DatPersonaRecord));
    }
}

// Intent: true when persona record arg0 is in the fixed party id range 0xC0..0xD7 (fixed growth rows).
// FUN_0010BE20
s32 datPersonaUsesFixedGrowth(DatPersonaRecord *arg0)
{
    u16 v = arg0->id;

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
#pragma opt_loop_invariants on
static inline s32 DPGrowthIsParty(u8 *persona)
{
    s32 id = *(u16 *)(persona + 2);
    if (id >= 0xC0 && id < 0xD8) {
        return 1;
    }
    return 0;
}

static inline u8 DPGrowthBaseLevel(u16 id)
{
    u8 *table = iGpffffb3d4;
    return table[(u32)id * 14 + 3];
}

static inline u32 DPGrowthOffset(u32 offset, u32 base)
{
    return offset + base;
}

static inline s32 DPGrowthFindSkill(u16 skill, u8 *skills, s32 known)
{
    s32 index;
    for (index = 0; (index & 0xFFFF) < known; index = (index + 1) & 0xFFFF) {
        if (skill == *(u16 *)(skills + (u16)index * 2)) { break; }
    }
    return index & 0xFFFF;
}

static inline s32 DPGrowthAddStat(s32 gain, s32 base) { return gain + base; }

// Intent: previews stat, skill and level changes of persona arg0 at level arg2 into arg1 without modifying the persona.
// FUN_0010BE60
void datPersonaPreviewLevelUp(u8 *arg0, u8 *arg1, s32 arg2)
{
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

    pid = *(u16 *)(arg0 + 2);
    if (pid == 0 || pid >= 0x100) {
        kAssertFail(D_005E4318, 0x56D);
    }
    memset(arg1, 0, 0x88);
    for (statIndex = 0; (statIndex & 0xFFFF) < 5; statIndex = (statIndex + 1) & 0xFFFF) {
        if ((statIndex & 0xFFFF) >= 5) {
            kAssertFail(D_005E4318, 0x1DE);
        }
        statBytes = arg0 + (u16)statIndex;
        statValue = &stat[(u16)statIndex];
        *statValue = statBytes[0x1C];
        if ((u16)statIndex >= 5) {
            kAssertFail(D_005E4318, 0x268);
        }
        /* The next accessor checks this unsigned halfword lvalue. */
        checkedIndex = &bonusIndex;
        *checkedIndex = statIndex;
        *statValue += *(s8 *)(statBytes + 0x21);
        if (*checkedIndex >= 5) {
            kAssertFail(D_005E4318, 0x299);
        }
        *statValue += *(s8 *)(statBytes + 0x26);
    }
    level = arg0[4] + 1;
    expsum = *(u32 *)(arg0 + 8) + (u32)arg2;
    pidoff = (pid & 0xFFFF) * 0x46;
    while (datPersonaGetExpForLevel(arg0, level) <= expsum && level <= 99) {
        if (!DPGrowthIsParty(arg0)) {
            for (roll = 0; (roll & 0xFFFF) < 3; roll = (roll + 1) & 0xFFFF) {
                total = 0;
                sumIndex = 0;
                table = (u8 *)DPGrowthOffset((u32)pidoff, (u32)iGpffffb3dc);
                while ((sumIndex & 0xFFFF) < 5) {
                    if ((s32)(arg1[(sumIndex & 0xFFFF) + 0x82] + stat[(u16)sumIndex]) < 99) {
                        total = (total + table[sumIndex & 0xFFFF]) & 0xFFFF;
                    }
                    sumIndex = (sumIndex + 1) & 0xFFFF;
                }
                if ((total & 0xFFFF) > 0) {
                    choice = (datCalcRandomBelow(total & 0xFFFF) + 1) & 0xFFFF;
                    weight = 0;
                    statScan = 0;
                    table = (u8 *)DPGrowthOffset((u32)pidoff, (u32)iGpffffb3dc);
                    while ((statScan & 0xFFFF) < 5) {
                        gain = arg1 + (statScan & 0xFFFF) + 0x82;
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
            if (*(u16 *)(arg0 + 2) < 0xC0 || *(u16 *)(arg0 + 2) > 0xD7) {
                kAssertFail(D_005E4318, 0x59F);
            }
            table = (u8 *)iGpffffb3e4 + (*(u16 *)(arg0 + 2) - 0xC0) * 0x26E;
            if (level >= 2) {
                partyIndex = 0;
                table += (u16)level * 5;
                while ((partyIndex & 0xFFFF) < 5) {
                    statValue = &stat[(u16)partyIndex];
                    statBase = *statValue;
                    gain = arg1 + (partyIndex & 0xFFFF) + 0x82;
                    if ((s32)(*gain + statBase) < 99) {
                        arg1[(partyIndex & 0xFFFF) + 0x82] += table[(partyIndex & 0xFFFF) + 0x7A];
                        if ((s32)DPGrowthAddStat(arg1[(partyIndex & 0xFFFF) + 0x82], statBase) > 99) {
                            *gain = 99 - statBase;
                        }
                    }
                    partyIndex = (partyIndex + 1) & 0xFFFF;
                }
            }
        }
        level++;
        arg1[0] += 1;
    }
    if (DPGrowthIsParty(arg0)) {
        entry = (u8 *)iGpffffb3e4 + (*(u16 *)(arg0 + 2) - 0xC0) * 0x26E + 4;
        limit = 32;
        oldLevel = arg0[4];
    } else {
        pid = (u16)*(s16 *)(arg0 + 2);
        entry = (u8 *)iGpffffb3dc + pid * 0x46 + 6;
        limit = 16;
        oldLevel = arg0[4] - DPGrowthBaseLevel(pid);
    }
    newLevel = oldLevel + arg1[0];
    first = 0;
    found = 0;
    span = 0;
    for (rangeIndex = 0; (rangeCurrent = rangeIndex & 0xFFFF) < limit; rangeIndex = (rangeIndex + 1) & 0xFFFF) {
        event = entry + (u16)rangeIndex * 4;
        if (*(s8 *)(event + 1) == 0) {
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
    skills = arg0 + 0xC;
    known = datPersonaCountSkills(arg0);
    added = 0;
    removed = 0;
    collectIndex = 0;
    while ((collectIndex & 0xFFFF) < count) {
        switch (*(s8 *)(entry + 1)) {
        case 1:
            if (*(u16 *)(entry + 2) != 0) {
                search = DPGrowthFindSkill(*(u16 *)(entry + 2), skills, known);
                if (search == known) {
                    if ((added & 0xFFFF) >= 32) {
                        kAssertFail(D_005E4318, 0x604);
                    }
                    *(u16 *)(arg1 + (u16)added * 2 + 2) = *(u16 *)(entry + 2);
                    added = (added + 1) & 0xFFFF;
                }
            }
            break;
        case 2:
            if (*(u16 *)(entry + 2) != 0) {
                search = DPGrowthFindSkill(*(u16 *)(entry + 2), skills, known);
                if (search != known) {
                    if ((removed & 0xFFFF) >= 32) {
                        kAssertFail(D_005E4318, 0x614);
                    }
                    *(u16 *)(arg1 + (u16)removed * 2 + 0x42) = *(u16 *)(entry + 2);
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
void datPersonaApplyLevelUp(u8 *arg0, u8 *arg1)
{
    s32 i;
    s32 j;
    s32 k;

    if (*(u16 *)(arg0 + 2) == 0 || *(u16 *)(arg0 + 2) >= 0x100) {
        kAssertFail(D_005E4318, 0x62E);
    }
    *(u8 *)(arg0 + 4) += *(u8 *)(arg1 + 0);
    i = 0;
    while ((u16)i < 5) {
        *(u8 *)(arg0 + 0x1C + (u16)i) += *(u8 *)(arg1 + 0x82 + (u16)i);
        i = (i + 1) & 0xFFFF;
    }
    j = 0;
    while ((u16)j < 0x20) {
        if (*(u16 *)(arg1 + (j & 0xFFFF) * 2 + 0x42) != 0) {
            datPersonaRemoveSkill(arg0, *(u16 *)(arg1 + (j & 0xFFFF) * 2 + 0x42));
        }
        j = (j + 1) & 0xFFFF;
    }
    k = 0;
    while ((u16)k < 0x20) {
        if (*(u16 *)(arg1 + (k & 0xFFFF) * 2 + 0x2) != 0) {
            datPersonaAddSkill(arg0, *(u16 *)(arg1 + (k & 0xFFFF) * 2 + 0x2));
        }
        k = (k + 1) & 0xFFFF;
    }
}

/* 556/560 bytes; fifteen resolved relocations; four zero alignment bytes.
 * Typed party records and experience curves retain retail address ordering. */
// Intent: total experience needed to reach level arg1 on persona arg0's growth curve; levels below 2 return 0.
// FUN_0010C750
u32 datPersonaGetExpForLevel(void *persona, u16 level)
{
    u8 *work = persona;
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

        if ((*(u16 *)(work + 2) >= 0xC0) &&
            (*(u16 *)(work + 2) < 0xD8)) {
            partyPersona = 1;
        } else {
            partyPersona = 0;
        }
        if (partyPersona == 0) {
            if (*(u16 *)(work + 2) >= 0x100) {
                kAssertFail(D_005E4318, 0x673);
            }
            levelF = (f32)level;
            baseOffset = (s32)*(u16 *)(work + 2) * 0xE;
            baseLevelF = (f32)(u32)iGpffffb3d4[baseOffset + 3];
            prod = fGpffff8150 * levelF;
            result = (s32)((0.0f + 10.0f) +
                           ((fGpffff820c + 0.0f - fGpffff8208 * baseLevelF) *
                            (prod * levelF * levelF)));
        } else {
            if ((*(u16 *)(work + 2) < 0xC0) ||
                (*(u16 *)(work + 2) > 0xD7)) {
                kAssertFail(D_005E4318, 0x67B);
            }
            curveId = iGpffffb3e4[*(u16 *)(work + 2) - 0xC0][0];
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
void datPersonaAddExp(DatPersonaRecord *arg0, s32 arg1)
{
    if (arg1 < 0) {
        kAssertFail(D_005E4318, 0x689);
    }
    arg0->exp += arg1;
}

/* measured: ported the matching P3 FES skill-compaction structure, with
   the loop-invariant pragma required to retain retail's maxSkills preheader;
   normalized_diff 0, object_size 232/240. */
// FUN_0010C9E0
#pragma opt_loop_invariants on
// Intent: compacts the 8-slot skill list of persona record arg0 so non-empty skills come first.
void datPersonaCompactSkills(u8 *arg0)
{
    u8 *persona_p;
    s32 skillIdx;
    s32 nextSkillIdx;
    s32 maxSkills;

    persona_p = arg0;
    if (persona_p == NULL) {
        kAssertFail(D_005E4318, 0x69D);
    }
    maxSkills = 8;
    skillIdx = 0;
    nextSkillIdx = 0;
    while (skillIdx < maxSkills) {
        if (*(u16 *)(persona_p + skillIdx * 2 + 0xC) == 0) {
            nextSkillIdx = skillIdx + 1;
            while (nextSkillIdx < maxSkills) {
                if (*(u16 *)(persona_p + nextSkillIdx * 2 + 0xC) != 0) {
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
                *(u16 *)(persona_p + skillIdx * 2 + 0xC) = *(u16 *)(persona_p + nextSkillIdx * 2 + 0xC);
            } else {
                *(u16 *)(persona_p + skillIdx * 2 + 0xC) = 0;
            }
        }
        skillIdx++;
        nextSkillIdx++;
    }
}
/* measured: closing pragma balances the required loop-invariant setting; nd 0. */
#pragma opt_loop_invariants off

/* The halfword persona contract retains both retail masks when common
 * subexpression folding is disabled for this initializer. */
#pragma opt_common_subs off
// Intent: initializes roster record arg0 for persona id arg1 from its table row, at the table level, with fixed skills.
// FUN_0010CAD0
void datPersonaInitRecord(u8 *arg0, u16 arg1)
{
    s32 id;
    s32 offset;
    u8 buf[0x88];

    if (arg0 == NULL) {
        kAssertFail(D_005E4318, 0x6C2);
    }
    id = arg1 & 0xFFFF;
    if (id == 0 || id >= 0x100) {
        kAssertFail(D_005E4318, 0x6C3);
    }
    id = (u16)arg1;
    offset = id * 0xE;
    {
        u8 *entry;

        entry = iGpffffb3d4 + offset;
        *(u16 *)(arg0 + 2) = (u16)arg1;
        *(u8 *)(arg0 + 4) = entry[3];
        *(u8 *)(arg0 + 5) = entry[9];
        *(s32 *)(arg0 + 8) = datPersonaGetExpForLevel(arg0, entry[3]);
    }
    *(s32 *)(arg0 + 0x2C) = 0;
    memcpy(arg0 + 0x1C, iGpffffb3d4 + offset + 4, 5);
    memset(arg0 + 0x21, 0, 5);
    memset(arg0 + 0x26, 0, 5);
    memset(arg0 + 0xC, 0, 0x10);
    datPersonaPreviewLevelUp(arg0, buf, 0);
    datPersonaApplyLevelUp(arg0, buf);
    datPersonaLearnFixedSkills(arg0);
}

#pragma opt_common_subs on
// Intent: stores skill arg1 in the first empty slot of record arg0; returns 1 on success, 0 when full.
// FUN_0010CC20
s32 datPersonaAddSkill(u8 *arg0, u16 arg1)
{
    s32 i;

    if (arg0 == NULL || (arg1 & 0xFFFF) == 0) {
        kAssertFail(D_005E4318, 0x6E0);
    }
    i = 0;
    while (i < 8) {
        if (*(u16 *)(arg0 + i * 2 + 0xC) == 0) {
            *(u16 *)(arg0 + i * 2 + 0xC) = (u16)arg1;
            return 1;
        }
        i++;
    }
    return 0;
}

// Intent: clears skill arg1 from record arg0 and compacts the list; returns 1 when found.
// FUN_0010CCC0
s32 datPersonaRemoveSkill(u8 *arg0, u32 arg1)
{
    s32 i;
    s32 key;
    u16 v2;

    if (arg0 == NULL || (arg1 & 0xFFFF) == 0) {
        kAssertFail(D_005E4318, 0x6EE);
    }
    i = 0;
    key = arg1 & 0xFFFF;
    while (i < 8) {
        v2 = *(u16 *)(arg0 + i * 2 + 0xC);
        if (v2 == key) {
            *(u16 *)(arg0 + i * 2 + 0xC) = 0;
            datPersonaCompactSkills(arg0);
            return 1;
        }
        i++;
    }
    return 0;
}

// Intent: replaces skill arg1 in record arg0 with arg2 when present; returns the slot index, or -1 when absent.
// FUN_0010CD70
s32 datPersonaReplaceSkill(u8 *arg0, s16 arg1, u16 arg2)
{
    if (arg0 == NULL || (s16)arg1 == 0 || (arg2 & 0xFFFF) == 0) {
        kAssertFail(D_005E4318, 0x6FE);
    }
    {
        s32 r = datPersonaFindSkillSlot(arg0, (u16)arg1);
        if (r != -1) {
            s32 off = r * 2;
            *(u16 *)(off + (s32)arg0 + 0xC) = (u16)arg2;
        }
        return r;
    }
}

// Intent: index of skill arg1 in the 8-slot list of record arg0, or -1 when absent.
// FUN_0010CE10
s32 datPersonaFindSkillSlot(u8 *arg0, u16 arg1)
{
    s32 i;
    u32 key;

    if (arg0 == NULL || (arg1 & 0xFFFF) == 0) {
        kAssertFail(D_005E4318, 0x70A);
    }
    i = 0;
    key = arg1 & 0xFFFF;
    while (i < 8) {
        u16 v = *(u16 *)(arg0 + i * 2 + 0xC);
        if (v == key) {
            return i;
        }
        i++;
    }
    return -1;
}

// Intent: number of non-empty skill slots in persona record arg0 (8 slots); 8 means full.
// FUN_0010CEB0
s32 datPersonaCountSkills(u8 *arg0)
{
    s32 count = 0;
    s32 i;

    if (arg0 == NULL) {
        kAssertFail(D_005E4318, 0x717);
    }
    i = 0;
    while (i < 8) {
        if (*(u16 *)(arg0 + i * 2 + 0xC) != 0) {
            count++;
        }
        i++;
    }
    return count;
}

// Intent: skill id in slot arg1 (0..7) of persona record arg0.
// FUN_0010CF40
u16 datPersonaGetSkillAt(DatPersonaRecord *arg0, s16 arg1)
{
    s32 index = arg1;

    if (index >= 8) {
        kAssertFail(D_005E4318, 0x723);
    }
    return arg0->skills[index];
}
// Intent: stores source record arg2 (persona id arg1, its skills and stat bonuses) into the 0x30-byte record arg0; returns 1.
// FUN_0010CFA0
s32 datPersonaLoadRecord(u8 *arg0, u16 arg1, u8 *arg2)
{
    s32 i;
    s32 i2;
    s32 v;
    s32 *sp2;
    s32 *dp2;
    s32 t0;
    s32 t1;
    s32 n;
    u8 *src;
    u8 *dst;
    u8 entry[0x30];
    u8 buf[0x90];

    if (arg0 == NULL) {
        kAssertFail(D_005E4318, 0x7AF);
    }
    if (arg2 == NULL) {
        kAssertFail(D_005E4318, 0x7B0);
    }
    v = *(s32 *)(arg2 + 8);
    datPersonaInitRecord(entry, arg1);
    datPersonaPreviewLevelUp(entry, buf, v);
    datPersonaApplyLevelUp(entry, buf);
    if (v < 0) {
        kAssertFail(D_005E4318, 0x689);
    }
    *(s32 *)(entry + 8) += v;
    src = arg2 + 0xC;
    dst = entry + 0xC;
    for (i = 0; i < 8; i++) {
        *(u16 *)(dst + i * 2) = *(u16 *)(src + i * 2);
    }
    if (entry == NULL || arg2 == NULL) {
        kAssertFail(D_005E4318, 0x778);
    }
    for (i2 = 0; i2 < 5; i2++) {
        *(u8 *)(entry + 0x21 + i2) = *(u8 *)(arg2 + 0x21 + i2);
        *(u8 *)(entry + 0x26 + i2) = *(u8 *)(arg2 + 0x26 + i2);
    }
    sp2 = (s32 *)entry;
    dp2 = (s32 *)arg0;
    n = 6;
    do {
        t0 = sp2[0];
        t1 = sp2[1];
        sp2 += 2;
        n--;
        dp2[0] = t0;
        dp2[1] = t1;
        dp2 += 2;
    } while (n > 0);
    return 1;
}

// Intent: adds the fixed-table skills of a party persona record arg0 (ids 0xC0..0xD7) into its empty skill slots.
// FUN_0010D150
void datPersonaLearnFixedSkills(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 b;
    u16 n;
    u8 *entry;
    u16 id = *(u16 *)(arg0 + 2);

    if (id >= 0xC0 && id < 0xD8) {
        b = 1;
    } else {
        b = 0;
    }
    if (b) {
        entry = (u8 *)iGpffffb3e4 + (id - 0xC0) * 0x26E + 4;
        for (i = 0; i < 0x20; i++) {
            if (*(u8 *)(entry + i * 4) == 0 && *(s8 *)(entry + i * 4 + 1) == 1) {
                n = *(u16 *)(entry + i * 4 + 2);
                if (arg0 == NULL || (n & 0xFFFF) == 0) {
                    kAssertFail(D_005E4318, 0x6E0);
                }
                for (j = 0; j < 8; j++) {
                    if (*(u16 *)(arg0 + j * 2 + 0xC) == 0) {
                        *(u16 *)(arg0 + j * 2 + 0xC) = n;
                        break;
                    }
                }
            }
        }
    } else {
        entry = (u8 *)iGpffffb3dc + (id & 0xFFFF) * 0x46 + 6;
        for (i = 0; i < 0x10; i++) {
            if (*(u8 *)(entry + i * 4) == 0 && *(s8 *)(entry + i * 4 + 1) == 1) {
                n = *(u16 *)(entry + i * 4 + 2);
                if (arg0 == NULL || (n & 0xFFFF) == 0) {
                    kAssertFail(D_005E4318, 0x6E0);
                }
                for (j = 0; j < 8; j++) {
                    if (*(u16 *)(arg0 + j * 2 + 0xC) == 0) {
                        *(u16 *)(arg0 + j * 2 + 0xC) = n;
                        break;
                    }
                }
            }
        }
    }
}
