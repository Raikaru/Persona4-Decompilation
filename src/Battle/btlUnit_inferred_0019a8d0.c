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
#include "btl_unit_internal.h"

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
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019a8d0-0019a960 */

/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
#pragma push
#pragma pop
/* measured: opt_propagation off is scoped to func_001990d0. */
/* measured: closes opt_propagation around func_001990d0. */
/* measured: opt_propagation off is scoped to func_001998e0. */
/* measured: closes opt_propagation around func_001998e0. */
/* Measured: the hit ordinal is s64 and motion is u16. Propagation off
   retains the entry mask and the late unsigned-halfword table index. */
#pragma push
#pragma pop
// FUN_0019A8D0
void btlUnitHoldPendingMotionSettle(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + 1;
}

/* Ported from P3FES btlUnitUpdate00284c90Packet: the packet's unit
   pointer is at offset 0 and its comparison field is at offset 0x9EC. */
// FUN_0019A8F0
u32 btlUnitMotionSettlePacketUpdate(void *work)
{
    u8 *unit;
    s16 current;

    unit = ((BtlUnitPacketReference *)work)->unit;
    switch (((BtlUnit *)unit)->genus) {
    case 0:
    case 1:
        if ((((BtlUnit *)unit)->flags2 & 2) != 0)
            current = ((BtlUnit *)unit)->currentMotion;
        else
            current = 0;
        return ((BtlUnit *)unit)->restMotion == current;
    }
    return 0;
}

// FUN_0019A960
void btlUnitReleasePendingMotionSettle(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}

