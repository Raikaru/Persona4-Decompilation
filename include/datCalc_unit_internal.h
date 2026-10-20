#ifndef DATCALC_UNIT_INTERNAL_H
#define DATCALC_UNIT_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"

/* Definitions in datCalc.c; both read the battle unit at retail offsets such as 0xA64. */
s32 datCalcHasBuffMask(DatUnit *unit, s32 mask);
// Intent: pointer to the 8-entry skill-id list for a unit (see datCalcSkillList in datCalc.c); [inferred].
u8 *datCalcSkillList(DatUnit *unit);

#endif
