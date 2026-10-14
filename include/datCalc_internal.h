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
/* Clears the word at byte offset 0x18 of an object block. */
void datCalcClearField18(int object);
u32 datCalcIsSpecialItem(u16 itemId);
u32 datCalcIsDead(DatUnit *unit, s32 hpDelta);
u32 datCalcIsLowHp(DatUnit *unit);
void datCalcInitializeCharacters(void);
void func_00243f20(u16 characterId);
/* Returns the fixed skill-table length (8) for a unit's table. */
u32 datCalcGetTableLength(u8 *unused);
u16 func_00231f80(DatUnit *unit);
u16 func_00232290(DatUnit *unit);
/* Returns 1 when the unit is flagged (flag 4) and its id's table entry has bit 0x80 set. */
s32 func_00243d80(DatUnit *unit);

#endif
