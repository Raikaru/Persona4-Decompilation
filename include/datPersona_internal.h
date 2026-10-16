#ifndef DATPERSONA_INTERNAL_H
#define DATPERSONA_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"

/* Persona table, skill table, and stat accessors defined in datPersona.c.
 * func_0010b3b0 is intentionally not declared here: its one caller keeps an
 * old-style declaration so the s64 argument is passed as measured. */
// Intent: pointer to the static 0x11-byte table row of persona personaId; fatal at id >= 0x100.
u8 *datPersonaGetRow(u16 personaId);
// Intent: arcana byte (+2 of the 14-byte persona entry); callers match it against a target arcana.
u8 datPersonaGetArcana(u16 personaId);
// Intent: u16 id stored at +2 of a persona record.
u16 datPersonaRecordId(u32 arg0);
// Intent: u16 id at +2 of roster slot arg0; fatal when the slot is NULL.
u16 datPersonaRosterSlotId(s32 arg0);
// Intent: u16 id at +2 of the record for persona id arg0.
u16 datPersonaGetRecordId(u16 arg0);
// Intent: u8 at +4 of roster slot arg0, a ranking key; the largest value among same-type party members wins.
u8 datPersonaRosterSlotRank(s32 arg0);
// Intent: u16 flags word of roster slot arg0; fatal when the slot is NULL.
u16 datPersonaRosterSlotFlags(s32 arg0);
// Intent: writes the skill ids (arg1) and levels (arg2, optional) of persona record arg0's level-table entries it has not learned yet; returns the count.
s32 datPersonaCollectLearnableSkills(DatPersonaRecord *persona, void *arg1, void *arg2);
// Intent: passes skill slot arg1 of persona record arg0 to datCalcSkillSlotValue; fatal on bad id or slot.
void datPersonaRunSkillSlot(u8 *arg0, s32 arg1);
// Intent: skill-slot value of persona id arg0 at slot arg1, read through datCalcSkillSlotValue; fatal when out of range.
u32 datPersonaGetSkillSlot(u16 arg0, s32 arg1);
// Battle stat index for datPersonaGetStat, in in-game order St/Ma/En/Ag/Lu. Index 3 (AGI) is confirmed by turn-order callers in btlOrder_grouped; 0, 1, 2 and 4 are [inferred].
enum DatPersonaStat {
    PERSONA_STAT_STR,
    PERSONA_STAT_MAG,
    PERSONA_STAT_END,
    PERSONA_STAT_AGI,
    PERSONA_STAT_LUC
};
// Intent: battle stat (index 0..4, see DatPersonaStat) at +0x1C of a persona record; enemy records read the same index.
u8 datPersonaGetStat(DatPersonaRecord *arg0, s32 arg1);
// Intent: battle stat (index 0..4) of the record for persona id arg0; same layout as datPersonaGetStat.
s32 datPersonaGetStatById(s32 arg0, s32 arg1);
// Intent: battle stat arg1 of record arg0 plus two stat modifiers, capped at 99; fatal when arg1 >= 5.
u8 datPersonaGetBuffedStat(DatPersonaRecord *arg0, s32 arg1);
// Intent: battle stat arg1 of record arg0 plus two modifiers and the equipment bonus, clamped to 0..99.
u8 datPersonaGetTotalStat(DatPersonaRecord *arg0, s32 arg1);
// Intent: battle stat arg1 of the record for persona id arg0, plus modifiers and equipment, clamped to 0..99.
u8 datPersonaGetTotalStatById(u16 arg0, s32 arg1);
// Intent: signed per-stat bonus byte at +0x21 of a record for stat arg1; summed into the stat totals.
s8 datPersonaGetStatBonusA(DatPersonaRecord *arg0, s32 arg1);
// Intent: signed per-stat bonus byte at +0x26 of a record for stat arg1; summed into the stat totals.
s8 datPersonaGetStatBonusB(DatPersonaRecord *arg0, s32 arg1);
// Intent: equipment bonus for stat arg1 of record arg0, summed from the equipped items of its party slot.
s8 datPersonaGetEquipStatBonus(DatPersonaRecord *arg0, s32 arg1);
// Intent: adds delta arg2 to stat arg1 of record arg0, clamped to 0..99; returns the new value.
s32 datPersonaAddStat(u8 *arg0, s32 arg1, s32 arg2);
// Intent: adds delta arg2 to stat arg1 of the record for persona id arg0, clamped to 0..99.
s32 datPersonaAddStatById(u16 arg0, s32 arg1, s32 arg2);
// Intent: maps a persona id to its record; 1 is the selected roster slot, 2..10 index the party array.
DatPersonaRecord *datPersonaGetRecord(u16 arg0);
// Intent: skill list of persona record arg0, at +0xC of the record [inferred]
u16 *datPersonaGetSkills(DatPersonaRecord *persona);
// Intent: true when the lead (id 1) record has flag bit 4 set; datCalc scales damage and code1_0021 scales level when it is.
s32 datPersonaLeadBoosted(s32 arg0);
// Intent: index of the active roster slot whose id matches, or -1.
s32 datPersonaFindRosterSlotById(s32 arg0);
// Intent: index of the first inactive roster slot, or -1 when the roster is full.
s32 datPersonaFindFreeRosterSlot(void);
// Intent: true when roster slot arg0 has its active flag set.
s32 datPersonaRosterSlotActive(s16 arg0);
// Intent: roster record of the active slot matching the id, or NULL.
DatPersonaRecord *datPersonaFindRosterRecordById(s32 arg0);
// Intent: roster record at index arg0, or NULL when the slot is inactive.
DatPersonaRecord *datPersonaRosterSlot(s16 arg0);
// Intent: removes the active roster slot holding the id, if any.
s32 datPersonaRemoveRosterMemberById(s32 arg0);
// Intent: removes roster slot arg0, shifts later slots down, then reselects the lead.
s32 datPersonaRemoveRosterSlot(s32 arg0);
// Intent: adds persona id to the first free roster slot; fatal when the roster is full.
u8 *datPersonaAddRosterMember(u16 personaId);
// Intent: adds persona id to the first free roster slot, returning NULL when full.
u8 *datPersonaTryAddRosterMember(u16 personaId);
// Intent: copies a 0x30-byte record into the first free roster slot; returns 1 on success, 0 when full.
s32 datPersonaInsertRosterRecord(u8 *arg0);
// Intent: selects the active roster slot holding the id as lead; returns 0 when no slot matches.
s32 datPersonaSelectRosterMemberById(s32 arg0);
// Intent: persona id held in the lead slot's record (+2); callers treat it as the current lead persona.
u16 datPersonaLeadPersonaId(void);
// Intent: index of the lead roster slot; fatal when the lead slot is inactive.
s32 datPersonaGetLeadSlot(void);
// Intent: roster capacity (6, 8, 10 or 12) selected by the mode flags at D_0079B40C.
s32 datPersonaRosterCapacity(void);
// Intent: sets the roster mode flags (none, 1, 2 or 3 cumulative) that select the capacity.
void datPersonaSetRosterMode(s32 arg0);
// Intent: number of active roster slots within the current capacity.
u16 datPersonaCountValidMembers(void);
// Intent: clears the roster flag records.
void datPersonaClearRoster(void);
// Intent: removes the selected roster member by compacting the slots after it.
void datPersonaRemoveSelectedRosterMember(void);
// Intent: places persona arg1 into the first free slot of roster mode arg0 (mode 1 is the selection).
s32 datPersonaPlaceRosterMember(s32 arg0, u16 arg1);
// Intent: clears roster mode arg0; mode 1 resets the selection and the roster block, other modes clear one party block.
void datPersonaResetRosterMode(s16 arg0);
// Intent: true when persona record arg0 is in the fixed party id range 0xC0..0xD7 (fixed growth rows).
s32 datPersonaUsesFixedGrowth(DatPersonaRecord *arg0);
// Intent: previews stat, skill and level changes of persona arg0 at level arg2 into arg1 without modifying the persona.
void datPersonaPreviewLevelUp(u8 *arg0, u8 *arg1, s32 arg2);
// Intent: applies a level-up delta from arg1 to persona record arg0: level, stat deltas, and newly learned skills.
void datPersonaApplyLevelUp(u8 *arg0, u8 *arg1);
// Intent: total experience needed to reach level arg1 on persona arg0's growth curve; levels below 2 return 0.
u32 datPersonaGetExpForLevel(void *persona, u16 level);
// Intent: adds experience arg1 to persona record arg0 at +8; fatal when negative.
void datPersonaAddExp(DatPersonaRecord *arg0, s32 arg1);
// Intent: compacts the 8-slot skill list of persona record arg0 so non-empty skills come first.
void datPersonaCompactSkills(u8 *arg0);
// Intent: initializes roster record arg0 for persona id arg1 from its table row, at the table level, with fixed skills.
void datPersonaInitRecord(u8 *arg0, u16 arg1);
// Intent: stores skill arg1 in the first empty slot of record arg0; returns 1 on success, 0 when full.
s32 datPersonaAddSkill(u8 *arg0, u16 arg1);
// Intent: clears skill arg1 from record arg0 and compacts the list; returns 1 when found.
s32 datPersonaRemoveSkill(u8 *arg0, u32 arg1);
// Intent: replaces skill arg1 in record arg0 with arg2 when present; returns the slot index, or -1 when absent.
s32 datPersonaReplaceSkill(u8 *arg0, s16 arg1, u16 arg2);
// Intent: index of skill arg1 in the 8-slot list of record arg0, or -1 when absent.
s32 datPersonaFindSkillSlot(u8 *arg0, u16 arg1);
// Intent: number of non-empty skill slots in persona record arg0 (8 slots); 8 means full.
s32 datPersonaCountSkills(DatPersonaRecord *arg0);
// Intent: skill id in slot arg1 (0..7) of persona record arg0.
u16 datPersonaGetSkillAt(DatPersonaRecord *arg0, s16 arg1);
// Intent: stores source record arg2 (persona id arg1, its skills and stat bonuses) into the 0x30-byte record arg0; returns 1.
s32 datPersonaLoadRecord(u8 *arg0, u16 arg1, u8 *arg2);
// Intent: adds the fixed-table skills of a party persona record arg0 (ids 0xC0..0xD7) into its empty skill slots.
void datPersonaLearnFixedSkills(u8 *arg0);

#endif
