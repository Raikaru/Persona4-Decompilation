#ifndef BTL_UNIT_MOVEMENT_INTERNAL_H
#define BTL_UNIT_MOVEMENT_INTERNAL_H

#include "btl_target_internal.h"
#include "rw_types_internal.h"

/* Embedded at BtlUnit+0xC4. Move/rotate packet setup and btlUnitCreate agree
 * on the targets, speed, route storage and later initialization words. */
typedef struct BtlUnitMovement {
    s32 flags;                  /* unit+0xC4 */
    u16 activity;               /* unit+0xC8 */
    u8 pad06[2];
    f32 speed;                  /* unit+0xCC: move packet stores 27 * requested speed */
    RwV3d rotationTarget;        /* unit+0xD0 */
    RwV3d destination;           /* unit+0xDC */
    f32 stoppingDistance;       /* unit+0xE8 */
    BtlTargetRoute route;       /* unit+0xEC */
    f32 unk430;                 /* unit+0x4F4: initialized to 5 or 7 by genus */
    u8 pad434[0x0C];
    s32 unk440;                 /* unit+0x504: cleared when starting rotation */
} BtlUnitMovement;

#endif
