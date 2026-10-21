#include "member_access.h"
#include "btl_unit_movement_internal.h"
#include "mdl_file_internal.h"
#include "btl_effect_internal.h"
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

extern void memset(void *data, s32 value, s32 option);


extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern u8 *btlUnitCreate(s32 genus);


extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

extern void chkmemAllocSiteTag(void *file, s32 line);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern void mdlQueueModelForDraw(void *queue, void *model);
extern u8 D_00794150[];

/* measured: optimization_level 1, with the index and value locals declared before the loop, keeps
 * retail's loop initialisation order; -O2 reorders it. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Queue visible, nontransparent models unless their model flags suppress drawing. */
// FUN_0019D150
void btlUnitQueueAllModelsForDraw(void)
{
    u8 *model;
    u8 *node;
    u32 i;

    for (i = 0; i < 4; i++) {
        node = ((BtlBattleState *)iGpffffb3ac)->unitLists[i * 2 + 1];
        while (node != NULL) {
            if ((((BtlUnit *)node)->flags2 & 2) != 0 &&
                (((BtlUnit *)node)->flags3 & 2) != 0 &&
                ((BtlUnit *)node)->cols[0].alpha > 0) {
                model = ((BtlUnit *)node)->layerHandle;
                if ((((MdlFileModel *)model)->flags & 0x20) == 0) {
                    mdlQueueModelForDraw(D_00794150, model);
                }
            }
            node = (u8 *)((BtlUnit *)node)->prevUnit;
        }
    }
}

/* Allocate a 0xA70-byte unit, initialize movement/model state, and append it to its genus list. */
// FUN_0019D210
u8 *btlUnitCreate(s32 genus)
{
    BtlUnit *typedUnit;
    f32 movementRate;
    s32 battleAddress;
    s32 listOffset;
    u32 unitId;
    u8 *unit;
    u8 *tail;

    chkmemAllocSiteTag(D_005F6D10, 0x3A);
    unit = (u8 *)D_008873E8[0](0xA70, 0x40000);
    typedUnit = (BtlUnit *)unit;
    memset(unit, 0, 0xA70);
    ((BtlUnit *)unit)->genus = genus;
    if (iGpffffa0a8 >= 0x0FFFFFFFU) {
        iGpffffa0a8 = 1;
    }
    unitId = iGpffffa0a8;
    iGpffffa0a8 = unitId + 1;
    ((BtlUnit *)unit)->id = unitId;
    btlPacketResetUnit(unit);
    ((BtlUnit *)unit)->unk_8c = 150.0f;
    ((BtlUnit *)unit)->sphereRadius = 50.0f;
    ((BtlUnit *)unit)->sphereCenter.x = 0.0f;
    ((BtlUnit *)unit)->sphereCenter.y = 0.5f * ((BtlUnit *)unit)->unk_8c;
    ((BtlUnit *)unit)->sphereCenter.z = 0.0f;
    ((BtlUnitMovement *)(unit + 0xC4))->activity = 0;
    ((BtlUnitMovement *)(unit + 0xC4))->speed = 27.0f;
    if (typedUnit->genus == 0) {
        movementRate = 10.0f;
    } else {
        movementRate = 14.0f;
    }
    ((BtlUnitMovement *)(unit + 0xC4))->unk430 = 0.5f * movementRate;
    ((BtlUnit *)unit)->motionRate = 1.0f;
    /* Negative camera slots have no camera ownership to release. */
    ((BtlUnit *)unit)->cameraSlot = -1;
    ((BtlUnitResources *)(unit + 0xA04))->placement = btlEffectCreatePlacementEntry(unit);
    ((BtlUnitResources *)(unit + 0xA04))->nodePool = btlEffectAllocNodePool();
    ((BtlUnit *)unit)->prevUnit = NULL;
    listOffset = (genus & 0xFF) * 8;
    battleAddress = (s32)iGpffffb3ac;
    tail = *(u8 **)((u8 *)((s32 *)((s32)((s32 *)battleAddress) + (MEMBER_OFFSET(BtlBattleState, unitLists[0])))) + listOffset);
    if (tail != NULL) {
        ((BtlUnit *)tail)->prevUnit = (BtlUnit *) unit;
        ((BtlUnit *)unit)->nextUnit = (BtlUnit *)
            ((BtlBattleState *)((u8 *)((listOffset) + ((s32)iGpffffb3ac))))->unitLists[0];
    } else {
        ((BtlBattleState *)((u8 *)((listOffset) + (battleAddress))))->unitLists[1] = unit;
        ((BtlUnit *)unit)->nextUnit = NULL;
    }
    ((BtlBattleState *)((u8 *)((listOffset) + ((s32)iGpffffb3ac))))->unitLists[0] = unit;
    return unit;
}

