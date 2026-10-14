#ifndef DATCALC_INTERNAL_H
#define DATCALC_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"

/* Battle unit HP, SP, bad-status, and death accessors defined in datCalc.c. */
u16 datCalcGetHp(int unit);
u16 datCalcGetSp(int unit);
void datCalcSetHp(int unit, u16 hp);
void datCalcSetSp(int unit, u16 sp);
u32 datCalcSetBadStatus(int unit, u32 badStatus);
u32 datCalcGetBadStatusNoDown(int unit);
u32 datCalcGetBadStatus(int unit);
u32 datCalcClearBadStatus(int unit, u32 badStatus);
u32 datCalcChkBadStatus(int unit, u32 badStatus);
void func_00233bb0(int object);
u32 datCalcIsSpecialItem(u16 itemId);
u32 datCalcIsDead(int unit, s32 hpDelta);
u32 datCalcIsLowHp(int unit);
void datCalcInitializeCharacters(void);
void func_00243f20(u16 characterId);
u32 func_0023e130(u8 *unused);
u16 func_00231f80(DatUnit *unit);
u16 func_00232290(DatUnit *unit);

#endif
