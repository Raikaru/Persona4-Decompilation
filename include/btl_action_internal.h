#ifndef BTL_ACTION_INTERNAL_H
#define BTL_ACTION_INTERNAL_H

#include "type.h"
#include "btl_unit_internal.h"
#include "btl_hit_result_internal.h"

/* Typed prefix of the retail BtlAction. Offsets through `unit` agree with the
   P4 battle TUs; later fields are named where code uses them as a role, and
   otherwise kept as unk_XX until evidence appears. */
/* Target block at BtlAction+0xD8, 0x44 bytes. Offsets are from the action;
 * the rows are the hit records, counted by hitRowCount (u8, 0xD9). The row
 * capacity is 25 (0xF0 + 25*0x20 = 0x410, inside the 0x41C end). */
typedef struct BtlActionTargetBlock
{
    u8 unk_d8;
    u8 hitRowCount;               /* 0xD9 */
    u8 unk_da[0xDE - 0xDA];
    u16 targetFlags;              /* 0xDE. Tested with mask 6 */
    s32 reactionFlag;             /* 0xE0. Nonzero marks a reacting target */
    s32 specialHitFlag;           /* 0xE4. Nonzero marks a special hit */
    u8 unk_e8[0xF0 - 0xE8];
    LargeBattleHitResult hitRows[25]; /* 0xF0 */
    u8 unk_410[0x41C - 0x410];
} BtlActionTargetBlock;

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
    BtlActionTargetBlock targetBlock; /* 0xD8. Target hit rows; see BtlActionTargetBlock */
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
    u8 unk_444[8];           /* 0x444 */
    BtlAction *previous;     /* 0x44C. Paired with next by create/unlink */
    BtlAction *next;         /* 0x450. Walked as the action list from D_0076449C+0x174 */
};
/* BtlAction.flags (+0x18). Bit 0 is the callback-pending bit (btlActionSetCallbackPending).
   btlTargetApplyHpSpChange sets the HIT/DOWN bits from the target-state work word
   (+0x2A, the packet's targetFlags) and the target status word (BTL_STATUS_DOWN). */
#define BTL_ACTION_FLAG_CALLBACK_PENDING 0x1
#define BTL_ACTION_FLAG_HIT_WEAK 0x800
#define BTL_ACTION_FLAG_HIT_CRITICAL 0x1000
#define BTL_ACTION_FLAG_DOWN 0x2000

/* Hit result values from datCalcHitResult (sub, action +0xDE); the bits are packed
   into targetFlags. 2 = critical (datCalcSkillAmount applies its attack multiplier when
   sub == 2), 4 = weakness hit (datCalcHitResult returns 4 when the affinity has
   AFF_WEAK), 1 = plain hit. */
#define BTL_HIT_RESULT_CRITICAL 0x2
#define BTL_HIT_RESULT_WEAK 0x4

/* Retail action state table at 0x005F6E20, indexed by BtlAction.currState:
 * 38 entries from NON (0) through TEST (37), decoded from SLUS_217.82. Each
 * entry is {init, update, name} at 12 bytes. Handlers are named
 * btlAction<StateName><Init|Update>. */
typedef void (*BtlActionStateFn)(BtlAction *action);
typedef struct BtlActionState
{
    BtlActionStateFn init;
    BtlActionStateFn update;
    const char *name;
} BtlActionState;
extern BtlActionState D_005f6e20[];

#endif
