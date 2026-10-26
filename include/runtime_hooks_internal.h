#ifndef RUNTIME_HOOKS_INTERNAL_H
#define RUNTIME_HOOKS_INTERNAL_H

#include "type.h"

/* Retail 0043c008 returns zero without consuming the caller's context word. */
s32 func_0043c008(s32 unusedContext);

/* MPEG's range wrapper flushes globally and does not consume the supplied range. */
void func_0041e030(s32 unusedAddress, s32 unusedBytes);

#endif
