#ifndef DATCALC_INTERNAL_H
#define DATCALC_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"
#include "dat_skill_entry_internal.h"


/* Affinity word from datCalcGetAffinity: the high bits are affinity kinds (null, repel,
   drain, weak, resist) and the low 16 bits are the damage percent. When those low bits
   are zero the percent defaults to 125 for weak, 50 for resist, and 100 for null, repel
   or drain (datCalcGetAffinity). */
enum DatAffinity
{
    AFF_NULL = 0x01000000,
    AFF_REPEL = 0x02000000,
    AFF_DRAIN = 0x04000000,
    AFF_WEAK = 0x08000000,
    AFF_RESIST = 0x10000000
};

/* Outcome codes from datCalcResolveSkillHit. Values other than 0x200 are [inferred]
   from the callers in btlTarget.c. */
enum DatResolveOutcome
{
    DAT_RESOLVE_HIT = 1,
    DAT_RESOLVE_MISS = 4,
    DAT_RESOLVE_NULL = 0x100,
    DAT_RESOLVE_REPEL = 0x200,
    DAT_RESOLVE_DRAIN = 0x400
};

/* Battle unit HP, SP, bad-status, and death accessors defined in datCalc.c.
 * The unit argument is the battle unit's DatUnit record; retail reads its fields. */
u16 datCalcGetHp(DatUnit *unit);
u16 datCalcGetSp(DatUnit *unit);
void datCalcSetHp(DatUnit *unit, u16 hp);
void datCalcSetSp(DatUnit *unit, u16 sp);
u32 datCalcSetBadStatus(DatUnit *unit, u32 badStatus);
u32 datCalcGetBadStatusNoDown(DatUnit *unit);
u32 datCalcGetBadStatus(DatUnit *unit);
u32 datCalcClearBadStatus(DatUnit *unit, u32 badStatus);
u32 datCalcChkBadStatus(DatUnit *unit, u32 badStatus);
/* Zeroes the unit record, sets its id, level 1, HP/SP 1 (datCalc.c). */
void datCalcInitUnit(DatUnit *unit, s16 id);
/* Level of the unit: its stored level for flag-4 units or id 1, otherwise its persona record's level. */
s32 datCalcGetLevel(DatUnit *unit);
/* Stores the level, clamped to 99 unless flag 4 (datCalc.c). */
void datCalcSetLevel(DatUnit *unit, u8 level);
/* Clears the word at byte offset 0x18 of an object block. */
void datCalcClearField18(int object);
u32 datCalcIsSpecialItem(u16 itemId);
u32 datCalcIsDead(DatUnit *unit, s32 hpDelta);
u32 datCalcIsLowHp(DatUnit *unit);
void datCalcInitializeCharacters(void);
// Intent: seeds the per-character tables for character id arg0; see datCalcInitializeCharacters.
void datCalcInitializeCharacter(u16 characterId);
/* Returns the fixed skill-table length (8) for a unit's table. */
u32 datCalcGetTableLength(DatUnit *unused);
// Intent: maximum HP of unit arg0 from its level and skill/equipment bonuses; capped at 999 unless flag 4.
u16 datCalcMaxHp(DatUnit *unit);
// Intent: maximum SP of unit arg0 from its level and SP bonuses; capped at 999 unless flag 4.
u16 datCalcMaxSp(DatUnit *unit);
/* Returns 1 when the unit is flagged (flag 4) and its id's table entry has bit 0x80 set. */
s32 datCalcEnemyHasExtendedFlag(DatUnit *unit);


/* Existing callers supply these inputs; unused inputs are retained explicitly. */
s32 datCalcSkillRoll(s32 skillId, DatUnit *unitArg, DatUnit *targetUnit, s32 unusedFlags);
s32 datCalcSkillAllowedForMode(DatUnit *source, DatUnit *target, s32 skillId, s32 channel, s32 mode, s32 unusedFlags);
s32 datCalcRollSupportSkillHit(u8 *source, u8 *target, s32 skillId, s32 outcome, s32 unusedMode, s32 unusedFlags);
s32 datCalcRollSkillChance(u8 *source, u8 *target, s32 skillIdArg, s32 channel, s32 outcome, s32 unusedFlags);

#endif
