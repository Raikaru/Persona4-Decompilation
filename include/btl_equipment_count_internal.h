#ifndef BTL_EQUIPMENT_COUNT_INTERNAL_H
#define BTL_EQUIPMENT_COUNT_INTERNAL_H

#include "type.h"

/* Counts matching values in the two equipment records. The accumulator is
 * narrowed after each increment, then returned as a complete signed word.
 * 001b3138/3188/31d8 consume that word directly; numerical callers explicitly
 * narrow it before multiplication. The result is always in [0, 2]. */
// Intent: count (0..2) of the unit's two equipment slots whose value equals arg1; see the note above.
s32 datCalcCountSlotsWithValue(u8 *unit, s32 property);

#endif
