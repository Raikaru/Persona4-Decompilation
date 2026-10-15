#ifndef DATCALC_UNIT_INTERNAL_H
#define DATCALC_UNIT_INTERNAL_H

/* Temporary split: these two take the battle unit as u8 *, which disagrees with
 * the int-typed accessors in datCalc_internal.h. This header gets folded into
 * datCalc_internal.h once the accessor sweep unifies the signatures. */

#include "type.h"

/* Definitions in datCalc.c; both read the battle unit at retail offsets such as 0xA64. */
s32 datCalcHasBuffMask(u8 *arg0, s32 arg1);
u8 *func_0023e140(u8 *arg0);

#endif
