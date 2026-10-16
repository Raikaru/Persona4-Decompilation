#ifndef DATCALC_INTERNAL_H
#define DATCALC_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"

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
u32 datCalcGetTableLength(u8 *unused);
// Intent: maximum HP of unit arg0 from its level and skill/equipment bonuses; capped at 999 unless flag 4.
u16 datCalcMaxHp(DatUnit *unit);
// Intent: maximum SP of unit arg0 from its level and SP bonuses; capped at 999 unless flag 4.
u16 datCalcMaxSp(DatUnit *unit);
/* Returns 1 when the unit is flagged (flag 4) and its id's table entry has bit 0x80 set. */
s32 func_00243d80(DatUnit *unit);

#endif
