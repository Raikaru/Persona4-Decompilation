#ifndef BTL_ACTION_INTERNAL_H
#define BTL_ACTION_INTERNAL_H

#include "type.h"
#include "btl_unit_internal.h"

/* Typed prefix of the retail BtlAction. Fields past `unit` are reached
   through raw offsets by callers. */
typedef struct BtlAction BtlAction;
struct BtlAction
{
    u64 uid;                 /* 0x00 */
    u32 id;                  /* 0x08 */
    u16 currState;           /* 0x0C */
    u16 pendingState;        /* 0x0E */
    u16 oldState;            /* 0x10 */
    u16 pendingStateTimer;   /* 0x12 */
    u16 state;               /* 0x14 */
    s16 unk_16;              /* 0x16 */
    u16 unk_18;              /* 0x18 */
    u16 unk_1a;              /* 0x1A */
    u32 stateTimer;          /* 0x1C */
    u32 unk_20;              /* 0x20 */
    s32 idleWeaponAnimTimer; /* 0x24 */
    u8 unk_28;               /* 0x28 */
    s32 unk_2c;              /* 0x2C */
    BtlUnit *unit;           /* 0x30 */
};

#endif
