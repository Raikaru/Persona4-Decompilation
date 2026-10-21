#include "btl_effect_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern u32 iGpffffb3b8;

extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 input, s32 value);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();


extern s32 fadeBeginReturnTransition(s32 mode, s32 duration);

extern void *btlPacketAlloc();

extern s32 btlEffectSetFadeLevel(u16 *level);

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* measured: opt_propagation off keeps the btlCameraFindFormationForCounts loop masks computed the
 * way retail does. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation off is needed so the GP loads and stores stay in retail order. */
// FUN_001D7B30
s32 btlEffectSetFadeLevel(u16 *level) {
    fadeBeginReturnTransition(1, *level);
    return 1;
}

/* Create packet 0x30B with a halfword fade-level payload and the corresponding update callback. */
// FUN_001D7B60
BtlPacket *btlEffectCreateFadeLevelPacket(u16 level)
{
  int packetAddress = 0;

  packetAddress = (int)btlPacketAlloc(0x30B, 2);
  *(code *)&((BtlPacket *)packetAddress)->updateFunc = (code)btlEffectSetFadeLevel;
  **(u16 **)&((BtlPacket *)packetAddress)->workData = level;
  return (BtlPacket *)packetAddress;
}

