#include "btl_unit_packet_internal.h"
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

extern void (*D_00887300[])(s32 data, s32 value);
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

extern s32 datCalcIsDead(u8 *unit, s32 hpDelta);
extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
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


/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *btlUnitAddRecordOffset(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 btlUnitAddOffsetToBase(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *btlUnitOffsetWordTable(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 btlUnitAddBaseToOffset(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 btlUnitOne(void)
{
    return 1;
}
static inline s64 btlUnitExtendSignedHalfword(s16 value)
{
    return value;
}
static inline s32 btlUnitMotionTableAddress(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 btlUnitAddProgress(f32 left, f32 right)
{
    return left + right;
}
static inline void btlUnitStoreListEndpoint(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    /* offset selects a genus-list endpoint; retain byte addressing for the retail operand-order helper. */
    *(u8 **)(address + offset) = stored;
}

static inline void btlUnitSetMotionOrdered(s16 value, u8 *data, u16 option, f32 rate, u16 flags)
{
    btlUnitSetMotion(data, value, option, rate, flags);
}
static inline void btlUnitStartProcedureOrdered(s32 option, s32 data, s32 value, s32 rate)
{
    scrStartProcedureChecked(data, value, option, rate);
}
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;
extern s32 datCalcIsLowHp(u8 *unit);
extern s32 datCalcIsGuarding(s32 unitFlags);

static inline void btlUnitInitChildOrdered(u16 value, u8 *data)
{
    btlUnitInitChild(data, value);
}
extern void (*jtbl_008873EC[])(void *data);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 00198dd0-00198dd0 */

/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
/* Recovered.  Two shapes closed it: the availability flag is an if/else
   (`if (r == 1) flag = 0; else flag = 1;`) rather than `flag = 1` with a
   conditional clear - retail reuses the materialised 1 as both the flag
   value and the comparison constant, and keeps the unreachable clear the
   else arm leaves behind - and the kind test is a `switch` with `case 0:
   case 1:` falling into one body, which emits retail's three-branch chain
   (beq 1, beqz, b default) instead of the inverted two-branch form an
   `||` condition produces.  The case labels are written 0 then 1 because
   the compare chain is emitted in reverse label order. */
/* measured: a distinct typed unit alias retains the model/data-unit reloads that moved instructions at the measured call sites. */
/* Choose the rest motion from status/HP/guard/death state; replace playback only when already at rest. */
// FUN_00198DD0
#pragma push
void btlUnitUpdateStatusMotion(u8 *unit, u16 frame)
{
    BtlUnit *unitFields = (BtlUnit *)unit;
    s16 restMotion;
    s64 value;
    u16 motionOption;
    u16 nextMotion;
    s32 atRest;
    s32 available;
    s32 keyEmpty;
    s16 motionId;
    extern s32 mdlIsLayerKeyEmpty(u8 *model, u32 layer, s16 animation);
    extern s32 datCalcChkBadStatus();

    restMotion = 0;
    if (datCalcIsLowHp((u8 *)((BtlUnit *)unit)->datUnit) != 0) {
        if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
            motionId = (s16)(btlUnitGetMotionId(unit, 0x12) & 0xFFFF);
            if (mdlLayerHasAnimation(((BtlUnit *)unit)->layerHandle, 0, motionId) == 0) {
                available = 0;
            } else {
                keyEmpty = mdlIsLayerKeyEmpty(unitFields->layerHandle, 0, motionId);
                if (keyEmpty == 1) {
                    available = 0;
                } else {
                    available = 1;
                }
            }
        } else {
            available = 0;
        }
        if (available != 0) {
            restMotion = 0x12;
        }
    }
    if (datCalcChkBadStatus((s32)unitFields->datUnit, 0xFFFFF) != 0) {
        restMotion = 3;
    }
    if (datCalcChkBadStatus((s32)unitFields->datUnit, 0x100000) != 0) {
        restMotion = 0xA;
    }
    if (datCalcIsGuarding((s32)unitFields->datUnit) != 0) {
        restMotion = 0x18;
    }
    if (datCalcChkBadStatus((s32)unitFields->datUnit, 0x100) != 0) {
        restMotion = 0;
    }
    if ((datCalcIsDead((u8 *)unitFields->datUnit, 0) != 0) && ((((BtlUnit *)unit)->flags3 & 0x20) != 0)) {
        if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
            motionId = (s16)(btlUnitGetMotionId(unit, 0x13) & 0xFFFF);
            if (mdlLayerHasAnimation(((BtlUnit *)unit)->layerHandle, 0, motionId) == 0) {
                available = 0;
            } else {
                keyEmpty = mdlIsLayerKeyEmpty(unitFields->layerHandle, 0, motionId);
                if (keyEmpty == 1) {
                    available = 0;
                } else {
                    available = 1;
                }
            }
        } else {
            available = 0;
        }
        if (available != 0) {
            restMotion = 0x13;
        }
    }
    value = (s64)restMotion;
    if (value != 0x13) {
        motionOption = 1;
        nextMotion = *(u16 *)&((BtlUnitRestMotion *)(unit + 0x9EC))->nextMotion;
    } else {
        motionOption = 2;
        nextMotion = 0;
    }
    {
        u8 kind;
        s16 currentMotion;

        kind = ((BtlUnit *)unit)->genus;
        switch (kind) {
        case 0:
        case 1:
            if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
                currentMotion = ((BtlUnit *)unit)->currentMotion;
            } else {
                currentMotion = 0;
            }
            atRest = (s32)(((BtlUnit *)unit)->restMotion == (s16)currentMotion);
            break;
        default:
            atRest = 0;
            break;
        }
    }
    if ((atRest != 0) && ((s64)(((BtlUnit *)unit)->restMotion) != value)) {
        btlUnitSetMotion(unit, restMotion, frame, 1.0f, motionOption);
    }
    ((BtlUnit *)unit)->restMotion = restMotion;
    *(u16 *)&((BtlUnitRestMotion *)(unit + 0x9EC))->nextMotion = nextMotion;
    ((BtlUnit *)unit)->restRate = 1.0f;
    ((BtlUnit *)unit)->restOption = motionOption;
}


#pragma pop
