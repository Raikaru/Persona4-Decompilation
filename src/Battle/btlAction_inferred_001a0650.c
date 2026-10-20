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

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 kind, u32 a, u32 b, u32 c);
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
extern BtlPacket *btlPacketCreateEffectCounter(s32 unit, s32 message);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];





extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;

extern u8 *iGpffffb3b8;
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *target, u16 flags);
extern f32 fGpffff811c;
s32 btlEffectFindUnitMatchingCallback(u8 *action, s32 conditionValue, s32 sideMask, s32 statusMask, s32 filterFlags,
                  s32 (*predicate)(u8 *arg0, s64 arg1));

extern f32 D_0076144C;

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001a0650-001a0650 */

/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: close loop-invariant probe for 001A0140. */
/* Empty state-table callback; this state needs no work in this phase. */
// FUN_001A0650
void btlActionNonUpdate(void)
{
}

