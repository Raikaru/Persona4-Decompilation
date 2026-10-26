#ifndef RFMAI_INTERNAL_H
#define RFMAI_INTERNAL_H

#include "type.h"

/* 004f5860 discards each input's upper 32 bits before joining high:low.
 * The result is a complete signed 64-bit bit pattern, not host C long. */
s64 RFMAI_CnvU32plusU32toS64(u32 high, u32 low);
void RFMAI_CnvS64toU32plusU32(u64 value, u32 *high, u32 *low);

#endif
