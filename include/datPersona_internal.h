#ifndef DATPERSONA_INTERNAL_H
#define DATPERSONA_INTERNAL_H

#include "type.h"

/* Persona table, skill table, and stat accessors defined in datPersona.c.
 * func_0010b3b0 is intentionally not declared here: its one caller keeps an
 * old-style declaration so the s64 argument is passed as measured. */
u8 *func_00109220(u16 personaId);
u8 func_00109280(u16 personaId);
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
s32 func_00109510(u8 *persona, void *arg1, void *arg2);
void func_001097c0(u8 *arg0, s32 arg1);
u32 func_00109870(u16 arg0, s32 arg1);
// Battle stat index for datPersonaGetStat, in in-game order St/Ma/En/Ag/Lu. Index 3 (AGI) is confirmed by turn-order callers in btlOrder_grouped; 0, 1, 2 and 4 are [inferred].
enum DatPersonaStat {
    PERSONA_STAT_STR,
    PERSONA_STAT_MAG,
    PERSONA_STAT_END,
    PERSONA_STAT_AGI,
    PERSONA_STAT_LUC
};
// Intent: battle stat (index 0..4, see DatPersonaStat) at +0x1C of a persona record; enemy records read the same index.
u8 datPersonaGetStat(u8 *arg0, s32 arg1);
// Intent: battle stat (index 0..4) of the record for persona id arg0; same layout as datPersonaGetStat.
s32 datPersonaGetStatById(s32 arg0, s32 arg1);
u8 func_001099f0(u8 *arg0, s32 arg1);
u8 func_00109ad0(u8 *arg0, s32 arg1);
u8 func_00109bf0(u16 arg0, s32 arg1);
s8 func_00109d20(u8 *arg0, s32 arg1);
s8 func_00109dd0(u8 *arg0, s32 arg1);
s8 func_00109e30(u8 *arg0, s32 arg1);
s32 func_0010a780(u8 *arg0, s32 arg1, s32 arg2);
s32 func_0010a840(u16 arg0, s32 arg1, s32 arg2);
// Intent: maps a persona id to its record; 1 is the selected roster slot, 2..10 index the party array.
u16 *datPersonaGetRecord(u16 arg0);
// Intent: true when the lead (id 1) record has flag bit 4 set; datCalc scales damage and code1_0021 scales level when it is.
s32 datPersonaLeadBoosted(s32 arg0);
// Intent: index of the active roster slot whose id matches, or -1.
s32 datPersonaFindRosterSlotById(s32 arg0);
// Intent: index of the first inactive roster slot, or -1 when the roster is full.
s32 datPersonaFindFreeRosterSlot(void);
// Intent: true when roster slot arg0 has its active flag set.
s32 datPersonaRosterSlotActive(s16 arg0);
// Intent: roster record of the active slot matching the id, or NULL.
u16 *datPersonaFindRosterRecordById(s32 arg0);
// Intent: roster record at index arg0, or NULL when the slot is inactive.
u16 *datPersonaRosterSlot(s16 arg0);
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
void func_0010b7f0(void);
s32 func_0010b9a0(s32 arg0, u16 arg1);
void func_0010bd90(s16 arg0);
s32 func_0010be20(u8 *arg0);
void func_0010be60(u8 *arg0, u8 *arg1, s32 arg2);
void func_0010c5a0(u8 *arg0, u8 *arg1);
u32 func_0010c750(void *persona, u16 level);
void func_0010c980(u8 *arg0, s32 arg1);
void func_0010c9e0(u8 *arg0);
void func_0010cad0(u8 *arg0, u16 arg1);
s32 func_0010cc20(u8 *arg0, u16 arg1);
s32 func_0010ccc0(u8 *arg0, u32 arg1);
s32 func_0010cd70(u8 *arg0, s16 arg1, u16 arg2);
s32 func_0010ce10(u8 *arg0, u16 arg1);
s32 func_0010ceb0(u8 *arg0);
u16 func_0010cf40(u8 *arg0, s16 arg1);
s32 func_0010cfa0(u8 *arg0, u16 arg1, u8 *arg2);
void func_0010d150(u8 *arg0);

#endif
