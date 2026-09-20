#ifndef FCL_DRAW_TASK_H
#define FCL_DRAW_TASK_H

#include "fcl_draw_types.h"

/* The draw provider consumes the four bytes as a value, rather than a packed
 * integer. Member names agree with the provider's recovered color type. */
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} FclDrawColor;

/* Creators return the SDK task handle; the handle is stored in EE word fields. */
s32 func_002b5c90(s32 parent, FclVec2 position);
s32 func_0034ad70(s32 parent, u8 count, s16 order);
s32 func_0034b740(s32 parent);
s32 func_002b8150(s32 parent);
s32 func_002b9f90(s32 parent, s16 count, s32 resource);

#endif
