#ifndef BTL_TARGET_STATE_PACKET_INTERNAL_H
#define BTL_TARGET_STATE_PACKET_INTERNAL_H

#include "type.h"

/* Creates packet 0x701 and returns it for submission or dependency setup.
 * The work area contains the action pointer followed by an unsigned flags byte:
 * bit 1 clears action byte 0x28; bit 0 increments it. With neither bit set, a
 * positive value is clamped to one and decremented.
 * Both byte-loaded and constant flags are passed by the retail callers. */
u8 *func_001f3870(u8 *action, u8 flags);

/* These are the types used by the generic packet dispatcher at +0x68,
 * +0x6c and +0x70; each callback receives the work-area pointer. */
typedef void (*BtlTargetStateHook)(u8 *work);
typedef u32 (*BtlTargetStateUpdate)(void *work);
void func_001f37b0(u8 *work);
u32 func_001f37d0(void *work);
void func_001f3850(u8 *work);

#endif
