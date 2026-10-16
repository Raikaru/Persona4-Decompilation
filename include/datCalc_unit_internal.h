#ifndef DATCALC_UNIT_INTERNAL_H
#define DATCALC_UNIT_INTERNAL_H

#include "type.h"
#include "datUnit_internal.h"

/* Definitions in datCalc.c; both read the battle unit at retail offsets such as 0xA64. */
s32 datCalcHasBuffMask(DatUnit *arg0, s32 arg1);
// Intent: pointer to the 8-entry skill-id list for a unit (see datCalcSkillList in datCalc.c); [inferred].
u8 *datCalcSkillList(DatUnit *arg0);

#endif
