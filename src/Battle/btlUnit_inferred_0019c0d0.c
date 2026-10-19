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
extern s32 scrStartProcedureChecked(s32 data, s32 value, s32 option, s32 rate);
static inline void btlUnitStartProcedureOrdered(s32 option, s32 data, s32 value, s32 rate)
{
    scrStartProcedureChecked(data, value, option, rate);
}
extern void mdlSetColor(void *data, s32 *value);
extern u8 iGpffffa4d8;
extern void btlUnitApplyModelState(u8 *data, s32 value);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern void btlUnitClearModelState(u8 *data, s32 value);
extern void btlUnitApplyModelState(u8 *data, s32 value);
extern void SceneDraw_SetResVisibleChecked(u16 data, u32 value);




extern s32 iGpffffb444;
extern void btlUnitInitChild(u8 *data, u16 value);

static inline void btlUnitInitChildOrdered(u16 value, u8 *data)
{
    btlUnitInitChild(data, value);
}
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitUpdateLookAtTarget(u8 *data);
extern void btlUnitHideModel();
extern void btlUnitShowModel(u8 *data);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019c0d0-0019d0c0 */

extern void btlUnitUpdateMotionLayer(u8 *data);
typedef struct {
    f32 right[3];
    s32 flags;
    f32 up[3];
    s32 pad1;
    f32 at[3];
    s32 pad2;
    f32 pos[3];
    s32 pad3;
} BtlUnitMatrix;
static inline void btlUnitMultiplyColor(RwRGBA *dst, const u8 *src)
{
    f32 scale;
    f32 bias;
    f32 g = (0.003921569f * (f32)(u32)dst->green) * (0.003921569f * (f32)(u32)src[1]);
    f32 b = (0.003921569f * (f32)(u32)dst->blue) * (0.003921569f * (f32)(u32)src[2]);
    f32 a = (0.003921569f * (f32)(u32)dst->alpha) * (0.003921569f * (f32)(u32)src[3]);
    f32 r = (0.003921569f * (f32)(u32)dst->red) * (0.003921569f * (f32)(u32)src[0]);

    scale = 255.0f;
    bias = 0.5f;
    dst->red = (s32)(scale * r + bias);
    dst->green = (s32)(scale * g + bias);
    dst->blue = (s32)(scale * b + bias);
    dst->alpha = (s32)(scale * a + bias);
}
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Measured: 1164 instruction bytes in the 1168-byte window, three resolved
 * relocations and a four-byte zero tail. This callback uses the packet creator's
 * u32 (void *) contract. Modes 1..4 initialize every timing value; the retail
 * constructor callers use modes 3 or 4. The packet is 20 bytes.
 * Disabling propagation locally retains the alpha result's memory/merge
 * lifetime. Publication remains the actual four-byte color-by-value operation. */
#pragma push
#pragma pop
/* Retail reloads the 1/255 colour scale (0x3B808081, written here as a
 * literal) for every factor; with default optimisation b210 does the same.
 * `v41` and `chk` are function-scope locals so they keep retail's saved
 * registers. On the `i == 2 && alpha < 0xFE` path retail compares 0xE8
 * against the `mode` left from an earlier entry (0x0019CDE0); the C reads
 * `mode` uninitialised there in the same way. */
#pragma push
// FUN_0019C0D0
/* measured: remaining color/flags/model sites lose MATCH when typed; +0xAC is byte-tested and +0x4E is packed RGBA. */
/* Advance each unit, publish changed transform/color state, and refresh status-effect placement. */
void btlUnitUpdateAll(void)
{
    extern u32 btlUnitUpdateFollowPath(u8 *unit);
    extern void btlBossCopyPartnerMark(u8 *unit);
    extern void SceneDraw_SetResPersona(u16 unit, u32 value);
    extern void btlUnitUpdateModelLight(u8 *unit);
    extern void mdlApplyModelMatrix(void *unit, void *value, s32 option);
    extern void mdlScale(void *unit, void *value, s32 option);
    extern void *mdlTranslateMatrix(void *unit, void *value, s32 option);
    extern void mdlAdvanceModelFromFlags(void *unit);
    extern s32 btlTargetRefreshRadiusNode(u8 *unit);
    extern u32 btlUnitIsModelVisible(u8 *unit);
    extern s32 btlEffectFlagToSlotIndex(s32 unit);
    extern s16 btlPacketGetValue(s32 unit);
    extern void btlEffectFlagToColor(s32 unit, u8 *value);
    /* Retail passes the sign-extended word from (s16)btlEffectFlagToSlotIndex() in $a1
     * without narrowing; the s16 definition's prototype adds a re-extension. */
    extern void btlPacketSetValue(u8 *unit, s32 value);
    extern void btlPacketSetTag(void *unit, u32 value);
    extern void btlEffectRefreshPlacementState(u8 *unit);
    u8 *entry;
    u32 i;
    s32 statusFlags;
    s32 effectSlot;

    for (i = 0; i < 4; i++) {
        entry = ((BtlBattleState *)D_0076449C)->unitLists[i * 2 + 1];
        while (entry != NULL) {
            btlUnitUpdateFollowPath(entry);
            btlUnitUpdateMotionLayer(entry);
            switch (i) {
            case 1:
                btlBossCopyPartnerMark(entry);
                break;
            case 2:
                if ((((BtlUnit *)entry)->flags2 & 2) != 0) {
                    u16 id;

                    if ((id = ((BtlUnit *)entry)->sceneDrawId) != 0) {
                        SceneDraw_SetResPersona(id, *(u8 *)(entry + 0xAC) == 1);
                    }
                }
                break;
            }
            if ((((BtlUnit *)entry)->flags2 & 2) != 0) {
                s32 unitFlags;
                s32 blendTicks;

                btlUnitUpdateModelLight(entry);
                unitFlags = *(u16 *)entry;
                if ((unitFlags & 3) != 0 && (unitFlags & 4) == 0) {
                    u8 minAlpha;
                    s32 alpha;

                    if ((unitFlags & 8) != 0) {
                        minAlpha = 0x58;
                    } else {
                        minAlpha = 0;
                    }
                    alpha = ((BtlUnit *)entry)->cols[1].alpha;
                    if (minAlpha + 0x20 < alpha) {
                        *(u8 *)(entry + 0x37) = alpha - 0x20;
                    } else {
                        *(u8 *)(entry + 0x37) = minAlpha;
                    }
                    *(s32 *)(entry + 0x98) |= 4;
                } else {
                    s32 alpha = ((BtlUnit *)entry)->cols[1].alpha;

                    if (alpha < 0xFF) {
                        if (alpha < 0xDF) {
                            *(u8 *)(entry + 0x37) = alpha + 0x20;
                        } else {
                            *(u8 *)(entry + 0x37) = 0xFF;
                        }
                        *(s32 *)(entry + 0x98) |= 4;
                    }
                }
                blendTicks = ((BtlUnit *)entry)->unk_4c;
                if (blendTicks > 0) {
                    f32 blendFactor = (f32)(u32)blendTicks / 8.0f;
                    u32 b;

                    b = ((BtlUnitColorTransition *)(entry + 0x40))->target.red;
                    ((BtlUnit *)entry)->cols[4].red = b + (u32)(blendFactor * (f32)(s32)(((BtlUnitColorTransition *)(entry + 0x40))->start.red - b));
                    b = ((BtlUnitColorTransition *)(entry + 0x40))->target.green;
                    ((BtlUnit *)entry)->cols[4].green = b + (u32)(blendFactor * (f32)(s32)(((BtlUnitColorTransition *)(entry + 0x40))->start.green - b));
                    b = ((BtlUnitColorTransition *)(entry + 0x40))->target.blue;
                    ((BtlUnit *)entry)->cols[4].blue = b + (u32)(blendFactor * (f32)(s32)(((BtlUnitColorTransition *)(entry + 0x40))->start.blue - b));
                    *(s32 *)(entry + 0x98) |= 4;
                    *(u16 *)(entry + 0x4C) = *(u16 *)(entry + 0x4C) - 1;
                }
                if ((*(s32 *)(entry + 0x98) & 4) != 0) {
                    BtlUnitMatrix matrix;
                    f32 translation[3];
                    RwRGBA color;
                    s32 renderTest;
                    u8 *modelWork;
                    f32 x = ((BtlUnit *)entry)->rot.imag.x;
                    f32 y = ((BtlUnit *)entry)->rot.imag.y;
                    f32 z = ((BtlUnit *)entry)->rot.imag.z;
                    f32 w = ((BtlUnit *)entry)->rot.real;
                    f32 xx = x * x;
                    f32 yy = y * y;
                    f32 zz = z * z;
                    f32 yz = y * z;
                    f32 zx = z * x;
                    f32 xy = x * y;
                    f32 wx = w * x;
                    f32 wy = w * y;
                    f32 wz = w * z;
                    f32 two = 2.0f;
                    f32 one = 1.0f;

                    matrix.right[0] = one - two * (yy + zz);
                    matrix.right[1] = two * (xy + wz);
                    matrix.right[2] = two * (zx - wy);
                    matrix.up[0] = two * (xy - wz);
                    matrix.up[1] = one - two * (xx + zz);
                    matrix.up[2] = two * (yz + wx);
                    matrix.at[0] = two * (zx + wy);
                    matrix.at[1] = two * (yz - wx);
                    matrix.at[2] = one - two * (xx + yy);
                    matrix.pos[0] = 0.0f;
                    matrix.pos[1] = 0.0f;
                    matrix.pos[2] = 0.0f;
                    matrix.flags = 3;
                    mdlApplyModelMatrix(((BtlUnit *)entry)->layerHandle, &matrix, 0);
                    translation[0] = translation[1] = translation[2] = ((BtlUnit *)entry)->scale;
                    mdlScale(*(u8 **)(entry + 0xA00), translation, 2);
                    translation[0] = ((BtlUnit *)entry)->pos.x + ((BtlUnit *)entry)->posOffset.x;
                    translation[1] = ((BtlUnit *)entry)->pos.y + ((BtlUnit *)entry)->posOffset.y;
                    translation[2] = ((BtlUnit *)entry)->pos.z + ((BtlUnit *)entry)->posOffset.z;
                    mdlTranslateMatrix(*(u8 **)(entry + 0xA00), translation, 2);
                    color = ((BtlUnit *)entry)->cols[0];
                    btlUnitMultiplyColor(&color, entry + 0x34);
                    btlUnitMultiplyColor(&color, entry + 0x3C);
                    btlUnitMultiplyColor(&color, entry + 0x40);
                    if (color.alpha >= 0xFE) {
                        color.alpha = 0xFF;
                        renderTest = 0x737FB;
                        btlUnitClearModelState(entry, 2);
                        btlUnitClearModelState(entry, 5);
                    } else if (i != 2) {
                        renderTest = 0x737FB;
                        btlUnitApplyModelState(entry, 2);
                        btlUnitApplyModelState(entry, 5);
                    }
                    {
                        s32 *skyTest = (s32 *)(*(u8 **)(entry + 0xA00) + 0xE8);

                        if (*skyTest != renderTest) {
                            u32 childIndex;

                            *skyTest = renderTest;
                        for (childIndex = 0; childIndex < 5; childIndex++) {
                            /* The shared model layout does not expose these 12-byte child slots at +0x290. */
                            u8 *childModel = *(u8 **)((u32)*(u8 **)(entry + 0xA00) + childIndex * 12 + 0x290);

                            if (childModel != NULL) {
                                ((MdlFileModel *)childModel)->skyTest = renderTest;
                            }
                        }
                        }
                    }
                    {
                        RwRGBA *colorPtr = &color;

                        ((BtlUnitColorTransition *)(entry + 0x40))->published = *colorPtr;
                        mdlSetColor(*(u8 **)(entry + 0xA00), (s32 *)colorPtr);
                    }
                    btlTargetRefreshRadiusNode(entry);
                    *(s32 *)(entry + 0x98) &= ~4;
                }
                {
                    u8 *model = ((BtlUnit *)entry)->layerHandle;

                    if ((((MdlFileModel *)model)->flags & 4) != 0) {
                        mdlAdvanceModelFromFlags(model);
                    }
                }
                if (((BtlUnitResources *)(entry + 0xA04))->placement != 0 && btlUnitIsModelVisible(entry) != 0) {
                    u8 *dataUnit = (u8 *)((BtlUnit *)entry)->datUnit;

                    if (dataUnit != NULL) {
                        statusFlags = ((DatUnit *)dataUnit)->bad & 0xFFFFF;
                        effectSlot = (s16)btlEffectFlagToSlotIndex(statusFlags);

                        if (effectSlot != (s16)btlPacketGetValue(((BtlUnitResources *)(entry + 0xA04))->placement)) {
                            btlEffectFlagToColor(statusFlags, entry + 0x48);
                            ((BtlUnitColorTransition *)(entry + 0x40))->start = ((BtlUnitColorTransition *)(entry + 0x40))->current;
                            *(u16 *)(entry + 0x4C) = 8;
                            btlPacketSetValue((u8 *)((BtlUnitResources *)(entry + 0xA04))->placement, effectSlot);
                        }
                    }
                    btlPacketSetTag((u8 *)((BtlUnitResources *)(entry + 0xA04))->placement, *(u32 *)(entry + 0x4E));
                    btlEffectRefreshPlacementState((u8 *)((BtlUnitResources *)(entry + 0xA04))->placement);
                }
            }
            entry = (u8 *)((BtlUnit *)entry)->prevUnit;
        }
    }
}

#pragma pop
// FUN_0019CFB0
/* Refresh look-at targets for modeled units in all four genus lists. */
void btlUnitUpdateAllLookAtTargets(void) {
    u32 i;
    u8 *entry;

    i = 0;
    goto loop_7;
loop_5:
    entry = ((BtlBattleState *)D_0076449C)->unitLists[i * 2 + 1];
    goto loop_check;
loop_body:
    if (((BtlUnit *)entry)->flags2 & 2) {
        btlUnitUpdateLookAtTarget(entry);
    }
    entry = (u8 *)((BtlUnit *)entry)->prevUnit;
loop_check:
    if (entry != NULL) {
        goto loop_body;
    }
    i += 1;
loop_7:
    if (i < 4U) {
        goto loop_5;
    }
}

// FUN_0019D040
/* measured: typing either remaining visibility-bit update changes MATCH to MISMATCH. */
/* Request model visibility and synchronize the scene resource visibility when one exists. */
void btlUnitShowModel(u8 *unit) {
    ((BtlUnit *)unit)->flags3 &= ~0x1000;
    btlUnitClearModelState(unit, 5);
    if (((BtlUnit *)unit)->sceneDrawId != 0) {
        SceneDraw_SetResVisibleChecked(((BtlUnit *)unit)->sceneDrawId, 1);
        *(s32 *)(unit + 0x9C) &= ~2;
        return;
    }
    *(s32 *)(unit + 0x9C) |= 2;
}

// FUN_0019D0C0
/* measured: typing the final visibility-bit clear changes MATCH to MISMATCH. */
/* Hide both the model and its scene resource, clearing the queued visibility bit. */
void btlUnitHideModel(u8 *unit) {
    ((BtlUnit *)unit)->flags3 |= 0x1000;
    btlUnitClearModelState(unit, 5);
    if (((BtlUnit *)unit)->sceneDrawId != 0) {
        SceneDraw_SetResVisibleChecked(((BtlUnit *)unit)->sceneDrawId, 0);
    }
    *(s32 *)(unit + 0x9C) &= ~2;
}

