#include "btl_unit_packet_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
#include "btl_skill_internal.h"
#include "rw_types_internal.h"
typedef struct DatUnit DatUnit;

extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;


extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *iGpffffb3e0;
extern s32 iGpffffb430;
extern s32 iGpffffb434;
extern s32 iGpffffb438;
extern u8 D_005F6BF0[];
extern u8 D_005F66C0[];
extern u64 iGpffffa090;
extern u16 iGpffffa098;
extern s32 iGpffffb43c;
extern u8 D_005F65D0[];
extern u8 D_005F65B0[];
extern u8 D_005F65C0[];

extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern RwV3d D_0060A0D0;
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern RwV3d D_0060A100;
extern u8 *(*D_008873E8[])(s32 data, s32 value);


extern u8 iGpffffa4d8;
extern void btlEffectDestroyPlacementEntry(s32 placement);
extern void btlEffectFreeNodePool(s32 pool);
extern void btlUnitUnlinkAndFree(u8 *incomingUnit);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitReleaseModel(u8 *unit);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* measured: optimization_level 1, with the index and value locals declared before the loop, keeps
 * retail's initialisation order; -O2 reorders it. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: propagation is disabled so the alpha result stays in memory across the merge, as in
 * retail. */
#pragma push
#pragma pop
/* Retail reloads the 1/255 colour scale for every factor, and on the i == 2 && alpha < 0xFE path
 * reads mode uninitialised; the C does the same. */
#pragma push
#pragma pop
// FUN_0019D4E0
/* Release the model, child unit, placement entry and resource-node pool. */
void btlUnitReleaseAllResources(u8 *unit)
{
    u8 *node;
    s32 h;

    btlUnitReleaseModel(unit);
    node = (u8 *)((BtlUnit *)unit)->childUnit;
    if (node != NULL) {
        btlUnitUnlinkAndFree(node);
    }
    h = ((s32 *)unit)[641];
    if (h != 0) {
        btlEffectDestroyPlacementEntry(h);
        ((BtlUnitResources *)(unit + 0xA04))->placement = 0;
    }
    h = ((s32 *)unit)[642];
    if (h != 0) {
        btlEffectFreeNodePool(h);
        ((BtlUnitResources *)(unit + 0xA04))->nodePool = 0;
    }
}

