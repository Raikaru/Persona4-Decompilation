#ifndef BTL_UNIT_LOOK_INTERNAL_H
#define BTL_UNIT_LOOK_INTERNAL_H

#include "btl_action_internal.h"
#include "btl_effect_internal.h"

/* Packet 0x11A allocates eight bytes and stores the unit and side mask. */
typedef struct BtlUnitLookSideWork {
    u8 *unit;
    u16 flags; /* bit 0 party, bit 1 enemies; neither selects unit */
    u8 pad06[2];
} BtlUnitLookSideWork;

/* The range callback reads a unit, a world target and a group flag. */
typedef struct BtlUnitLookPointWork {
    u8 *unit;
    RwV3d point;
    u16 flags; /* bit 0 applies to every active party unit */
    u8 pad12[2];
} BtlUnitLookPointWork;

#endif
