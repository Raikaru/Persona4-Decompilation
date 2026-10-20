#ifndef SDK_OT_STATE_API_H
#define SDK_OT_STATE_API_H

#include "type.h"

/* The ordering-table constructors return the queued 0x30-byte node. Callers
 * may discard it; both providers use the same list and state-word interface. */
u8 *PrimQueueStateSet(u8 *list, s32 stateId, s32 stateValue);
u8 *PrimQueueStateSetAlt(u8 *list, s32 stateId, s32 stateValue);

#endif
