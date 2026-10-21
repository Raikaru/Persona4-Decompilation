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

extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 command, u32 argument, u32 extraArgument, u32 flags);
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
extern BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];


extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;

extern u8 *iGpffffb3b8;
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u16 flags);
extern f32 fGpffff811c;
s32 btlEffectFindUnitMatchingCallback(u8 *action, s32 conditionValue, s32 sideMask, s32 statusMask, s32 filterFlags,
                  s32 (*predicate)(u8 *arg0, s64 arg1));

extern f32 D_0076144C;

// FUN_001A0650
void btlActionNonUpdate(void)
{
}

