#ifndef K_SCENEDRAW_STATE_H
#define K_SCENEDRAW_STATE_H

#include "type.h"

/* Current scene prefix: band predicates consume the low halfwords at 0/4;
 * FldState_SetEventViewMode writes the word at 0x18. */
typedef struct FldMapState {
    u16 fieldId;
    u8 pad02[2];
    u16 roomId;
    u8 pad06[0x12];
    s32 eventViewMode;
} FldMapState;

#endif
