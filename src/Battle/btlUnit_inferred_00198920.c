#include "byte_address_internal.h"
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


extern s32 scrStartProcedureChecked(s32 priority, s32 source, s32 size, s32 procedureIndex);
extern void mdlSetLayerWeight(u8 *model, s32 layer, f32 speed);
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern s32 iGpffffb444;
extern void mdlSetLayerHandleFlag(void *model);
extern void mdlClearLayerHandleFlag(void *model);
extern void btlUnitInitChild(u8 *unit, u16 characterId);

extern void (*jtbl_008873EC[])(void *data);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];


extern s64 btlUnitGetMotionId(u8 *unit, u16 motion);

typedef struct MotionTableEntry {
    s16 followMotion;
    s16 ratePercent;
    s16 followFrame;
    s16 unknown6;
    s16 nextMotion;
} MotionTableEntry;
/* Classify motion options that require the alternate playback-mode flag. */
static inline u16 btlUnitMotionModeFlags(u16 option)
{
    switch (option) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        return 0;
    default:
        return 1;
    }
}
/* Resolve motion and playback rate, publish bounds, and configure follow-up animation state.
 * Separate typed unit aliases keep the mode, count, model and table reloads and the rate bit-
 * pattern store. */
// FUN_00198920
void btlUnitSetMotion(u8 *unit, s16 motion, u16 frame, f32 rate, u16 option)
{
    BtlUnit *unitFields = (BtlUnit *)unit;
    extern f32 iGpffff80d4;
    extern f32 iGpffff812c;
    extern u8 *btlUnitGetRecordPtr(u8 *unit, s32 motion);
    s32 motionIndex;
    u16 motionId;
    s32 modeFlags;
    s16 *bounds;
    MotionTableEntry *base;
    MotionTableEntry *table;

    ((BtlUnit *)unit)->motionOption = option;
    if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
        motionIndex = (u16)motion;
        ((BtlUnit *)unit)->currentMotion = motion;
        motionId = (u16)btlUnitGetMotionId(unit, motionIndex);
        if ((u16)motionId < ((BtlUnit *)unit)->motionCount) {
            table = (MotionTableEntry *)((BtlUnit *)unit)->motionRates;
            ((BtlUnit *)unit)->motionRate = rate * ((f32)table[motionId].ratePercent / 100.0f);
        } else {
            unitFields->motionRateBits = 0x3F800000;
        }
        option = option & 0xFFFF;
        modeFlags = btlUnitMotionModeFlags(option);
        if (rate < iGpffff80d4 || !(rate <= iGpffff812c)) {
            switch (motion) {
            case 4:
            case 12:
            case 8:
                modeFlags = (u16)(modeFlags | 0x60);
                break;
            default:
                break;
            }
        }
        if (((((BtlUnit *)unit)->unk_9d8 & 0x10) != 0) || ((s32)((BtlUnit *)unit)->datUnit != 0 && datCalcChkBadStatus((s32)((BtlUnit *)unit)->datUnit, 256) != 0)) {
            modeFlags = (u16)(modeFlags | 0x100);
        }
        if (motion == 19) {
            mdlClearLayerHandleFlag(((BtlUnit *)unit)->layerHandle);
        } else {
            mdlSetLayerHandleFlag(((BtlUnit *)unit)->layerHandle);
        }
        if ((unitFields->unk_9d8 & 0x20) != 0) {
            frame = 0;
        }
        if ((unitFields->unk_9d8 & 0x40) != 0) {
            motionId = 27;
        }
        mdlDispatchAnimIfPresent(unitFields->layerHandle, 0, (s32)(s16)motionId, frame, modeFlags);
        mdlSetLayerWeight(unitFields->layerHandle, 0, ((BtlUnit *)unit)->motionRate);
        bounds = (s16 *)btlUnitGetRecordPtr(unit, motionIndex);
        ((BtlUnit *)unit)->sphereCenter.x = (f32)bounds[0];
        ((BtlUnit *)unit)->sphereCenter.y = (f32)bounds[1];
        ((BtlUnit *)unit)->sphereCenter.z = (f32)bounds[2];
        ((BtlUnit *)unit)->unk_8c = (f32)(u16)bounds[3];
        ((BtlUnit *)unit)->sphereRadius = (f32)(u16)bounds[4];
        switch (motion) {
        case 8:
        case 16:
            if ((u16)motionId < unitFields->motionCount) {
                base = &((MotionTableEntry *)(u8 *)((BtlUnit *)unit)->motionRates)[(u16)motionId];
                if (base->followMotion >= 0 && base->followFrame > 0) {
                    unitFields->unk_9d8 = unitFields->unk_9d8 | 4;
                    ((BtlUnitFollowMotion *)(unit + 0x9E6))->motion = ((MotionTableEntry *)(u8 *)unitFields->motionRates)[(u16)motionId].followMotion;
                    ((BtlUnitFollowMotion *)(unit + 0x9E6))->frame = ((MotionTableEntry *)(s32)byteAddressAdd((u16)motionId * sizeof(MotionTableEntry), (u8 *)((s32)unitFields->motionRates)))->followFrame;
                }
            }
            break;
        default:
            unitFields->unk_9d8 = unitFields->unk_9d8 & 0xFFFB;
            break;
        }
        if (option == 0) {
            switch (motion) {
            case 2:
            case 8:
            case 12:
            case 9:
            case 11:
            case 22:
            case 23:
            case 20:
                ((BtlUnitRestMotion *)(unit + 0x9EC))->nextMotion = 0;
                break;
            case 4:
                ((BtlUnitRestMotion *)(unit + 0x9EC))->nextMotion = 0;
                break;
            default:
                if ((u16)motionId < unitFields->motionCount) {
                    table = (MotionTableEntry *)((BtlUnit *)unit)->motionRates;
                    ((BtlUnitRestMotion *)(unit + 0x9EC))->nextMotion = table[motionId].nextMotion;
                } else {
                    ((BtlUnitRestMotion *)(unit + 0x9EC))->nextMotion = 0;
                }
                break;
            }
        }
    }
}

