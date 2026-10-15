#include "list_item_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"

#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
#include "btl_action_internal.h"
typedef struct BtlPacket BtlPacket;
typedef struct BtlTarget BtlTarget;

/* 001f14f0 writes 0x20-byte hit records at action+0xF0. The guarded
   controllers also construct this same provider-sized result payload. */
typedef struct LargeBattleHitResult {
    s32 hpDelta, spDelta;
    u32 addedStatus, removedStatus;
    u32 field10;
    s32 field14;
    s16 hpTransfer, spTransfer;
    s8 motion;
    u8 field1d;
    u16 flags;
} LargeBattleHitResult;

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *func_001f5f70(u32 action, u16 kind, u32 a, u32 b, u32 c);
static inline u8 *actionTargetPacketBytes(u8 *action, u16 kind, u32 a, u32 b, u32 c)
{
    return (u8 *)func_001f5f70((u32)action, kind, a, b, c);
}
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
static inline void actionSetDelayBytes(u8 *action, s32 state, s32 delay)
{
    btlActionSetStateWithDelay((BtlAction *)action, (u16)state, (u16)delay);
}
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
static inline u8 *actionRotatePacketBytes(u8 *unit, void *rot, s32 flags)
{
    return (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, (const RwV3d *)rot, (u32)flags);
}
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
static inline u8 *actionRecoveryPacketBytes(BtlUnit *unit)
{
    return (u8 *)btlUnitCreateMotionSettlePacket(unit);
}
extern BtlPacket *func_00202400(s32 unit, s32 message);
static inline void *actionMessagePacketBytes(s32 unit, s32 message)
{
    return func_00202400(unit, message);
}
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

static inline s32 func_001a_add_offset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 func_001a_fix_var(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}




extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;

extern u8 *iGpffffb3b8;
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *target, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
extern f32 fGpffff811c;
s32 func_001d94d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));

extern f32 D_0076144C;

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001a0660-001a0660 */

/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: close loop-invariant probe for 001A0140. */
// FUN_001A0660
void func_001a0660(void)
{
}

