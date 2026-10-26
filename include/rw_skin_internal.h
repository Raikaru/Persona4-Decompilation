#ifndef RW_SKIN_INTERNAL_H
#define RW_SKIN_INTERNAL_H

#include "type.h"

/* The skin plugin opener supplies its flags; this retail hook returns one
 * without consuming them. Keep the caller's existing argument evaluation. */
s32 func_003b8d20(s32 unusedFlags);

#endif
