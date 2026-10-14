#ifndef BTL_ACTION_INTERNAL_H
#define BTL_ACTION_INTERNAL_H

#include "type.h"
#include "btl_unit_internal.h"

/* Typed prefix of the retail BtlAction. Offsets through `unit` agree with the
   P4 battle TUs; later fields are named where code uses them as a role, and
   otherwise kept as unk_XX until evidence appears. */
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
    u16 flags;               /* 0x18 */
    u16 unk_1a;              /* 0x1A */
    u32 stateTimer;          /* 0x1C */
    u32 unk_20;              /* 0x20 */
    s32 idleWeaponAnimTimer; /* 0x24 */
    u8 unk_28;               /* 0x28 */
    u8 unk_29;               /* 0x29 */
    s32 unk_2c;              /* 0x2C */
    BtlUnit *unit;           /* 0x30 */
    u8 unk_34[0x04];         /* 0x34 */
    u8 unk_38[0x32];         /* 0x38. Target array, reached through the raw offset */
    u16 unk_6a;              /* 0x6A */
    u16 unk_6c;              /* 0x6C */
    u16 unk_6e;              /* 0x6E */
    u8 unk_70[0xD0 - 0x70];  /* 0x70 */
    u16 unk_d0;              /* 0xD0 */
    u16 unk_d2;              /* 0xD2 */
    u8 unk_d4[0xD8 - 0xD4];  /* 0xD4 */
    u8 unk_d8[0x41C - 0xD8]; /* 0xD8. Sub-struct passed by address (func_001f0a40) */
    s32 unk_41c;             /* 0x41C */
    s32 unk_420;             /* 0x420 */
    s32 unk_424;             /* 0x424 */
    s32 unk_428;             /* 0x428 */
    s32 unk_42c;             /* 0x42C */
    s16 unk_430;             /* 0x430 */
    u8 unk_432[0x02];        /* 0x432 */
    s32 unk_434;             /* 0x434 */
    u8 unk_438[0x04];        /* 0x438 */
    s16 unk_43c;             /* 0x43C */
    u8 unk_43e[0x02];        /* 0x43E */
    void *unk_440;           /* 0x440. Callback slot set beside state changes */
    u8 unk_444[0x0C];        /* 0x444 */
    BtlAction *next;         /* 0x450. Walked as the action list from D_0076449C+0x174 */
};

#endif
