#ifndef RUNTIME_FLOAT_INTERNAL_H
#define RUNTIME_FLOAT_INTERNAL_H

#include "type.h"

/* 0044dcd8 returns the IEEE binary64 representation in the complete v0 word. */
u64 fptodp(f32 value);

#endif
