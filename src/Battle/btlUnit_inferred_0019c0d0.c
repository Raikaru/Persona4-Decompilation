#include "member_access.h"
#include "model_battle_internal.h"
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


extern s32 scrStartProcedureChecked(s32 priority, s32 source, s32 size, s32 procedureIndex);
extern void mdlSetColor(void *model, s32 *color);
extern u8 iGpffffa4d8;
extern void btlUnitApplyModelState(u8 *unit, s32 mode);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern void btlUnitClearModelState(u8 *unit, s32 mode);
extern void btlUnitApplyModelState(u8 *unit, s32 mode);
extern void SceneDraw_SetResVisibleChecked(u16 resTypeId, u32 visible);


extern s32 iGpffffb444;
extern void btlUnitInitChild(u8 *unit, u16 characterId);

extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitUpdateLookAtTarget(u8 *unit);
extern void btlUnitHideModel();
extern void btlUnitShowModel(u8 *unit);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

extern void btlUnitUpdateMotionLayer(u8 *unit);
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
/* Multiply normalized RGBA channels and round each component back to a byte. */
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
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
/* Advance each unit, publish changed transform/color state, and refresh status-effect placement;
 * the flags byte is tested raw and the color is packed RGBA. */
// FUN_0019C0D0
void btlUnitUpdateAll(void)
{

    BtlUnit *typedEntry;
    extern u32 btlUnitUpdateFollowPath(u8 *context);
    extern void btlBossCopyPartnerMark(u8 *unit);
    extern void SceneDraw_SetResPersona(u16 resTypeId, u32 persona);
    extern void btlUnitUpdateModelLight(u8 *unit);
    extern void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp);
    extern void mdlScale(void *model, void *scale, s32 combineOp);
    extern void *mdlTranslateMatrix(void *matrix, void *translation, s32 combineOp);
    extern void mdlAdvanceModelFromFlags(void *model);
    extern s32 btlTargetRefreshRadiusNode(u8 *unit);
    extern u32 btlUnitIsModelVisible(u8 *unit);
    extern s32 btlEffectFlagToSlotIndex(s32 flag);
    extern s16 btlPacketGetValue(s32 placement);
    extern void btlEffectFlagToColor(s32 flag, u8 *color);
    /* Retail passes the sign-extended slot index without narrowing it again, so the callee is
     * declared to take an s32. */
    extern void btlPacketSetValue(u8 *packet, s32 value);
    extern void btlPacketSetTag(void *packet, u32 value);
    extern void btlEffectRefreshPlacementState(u8 *placement);
    u8 *entry;
    u32 i;
    s32 statusFlags;
    s32 effectSlot;

    for (i = 0; i < 4; i++) {
        entry = ((BtlBattleState *)D_0076449C)->unitLists[i * 2 + 1];
        typedEntry = (BtlUnit *)entry;
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
                        SceneDraw_SetResPersona(id, *(u8 *)&((BtlUnit *)entry)->unk_ac == 1);
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
                        typedEntry->cols[1].alpha = alpha - 0x20;
                    } else {
                        typedEntry->cols[1].alpha = minAlpha;
                    }
                    *(s32 *)&typedEntry->flags2 |= 4;
                } else {
                    s32 alpha = ((BtlUnit *)entry)->cols[1].alpha;

                    if (alpha < 0xFF) {
                        if (alpha < 0xDF) {
                            typedEntry->cols[1].alpha = alpha + 0x20;
                        } else {
                            typedEntry->cols[1].alpha = 0xFF;
                        }
                        *(s32 *)&typedEntry->flags2 |= 4;
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
                    *(s32 *)&typedEntry->flags2 |= 4;
                    typedEntry->unk_4c = typedEntry->unk_4c - 1;
                }
                if ((*(s32 *)&typedEntry->flags2 & 4) != 0) {
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
                    mdlScale(typedEntry->layerHandle, translation, 2);
                    translation[0] = ((BtlUnit *)entry)->pos.x + ((BtlUnit *)entry)->posOffset.x;
                    translation[1] = ((BtlUnit *)entry)->pos.y + ((BtlUnit *)entry)->posOffset.y;
                    translation[2] = ((BtlUnit *)entry)->pos.z + ((BtlUnit *)entry)->posOffset.z;
                    mdlTranslateMatrix(typedEntry->layerHandle, translation, 2);
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
                        s32 *skyTest = (s32 *)(typedEntry->layerHandle + 0xE8);

                        if (*skyTest != renderTest) {
                            u32 childIndex;

                            *skyTest = renderTest;
                        for (childIndex = 0; childIndex < 5; childIndex++) {
                            u8 *childModel = MEMBER(u8 *, (u32)typedEntry->layerHandle + childIndex * 12, Model, attachedWpns[0].wpnMdl);

                            if (childModel != NULL) {
                                ((MdlFileModel *)childModel)->skyTest = renderTest;
                            }
                        }
                        }
                    }
                    {
                        RwRGBA *colorPtr = &color;

                        ((BtlUnitColorTransition *)(entry + 0x40))->published = *colorPtr;
                        mdlSetColor(typedEntry->layerHandle, (s32 *)colorPtr);
                    }
                    btlTargetRefreshRadiusNode(entry);
                    *(s32 *)&typedEntry->flags2 &= ~4;
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
                            typedEntry->unk_4c = 8;
                            btlPacketSetValue((u8 *)((BtlUnitResources *)(entry + 0xA04))->placement, effectSlot);
                        }
                    }
                    btlPacketSetTag((u8 *)((BtlUnitResources *)(entry + 0xA04))->placement, *(u32 *)&((BtlUnit *)entry)->unk_4e);
                    btlEffectRefreshPlacementState((u8 *)((BtlUnitResources *)(entry + 0xA04))->placement);
                }
            }
            entry = (u8 *)((BtlUnit *)entry)->prevUnit;
            typedEntry = (BtlUnit *)entry;
        }
    }
}

#pragma pop
/* Refresh look-at targets for modeled units in all four genus lists. */
// FUN_0019CFB0
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

/* Request model visibility and synchronize the scene resource visibility when one exists. */
// FUN_0019D040
void btlUnitShowModel(u8 *unit) {
    BtlUnit *typedUnit = (BtlUnit *)unit;
    ((BtlUnit *)unit)->flags3 &= ~0x1000;
    btlUnitClearModelState(unit, 5);
    if (((BtlUnit *)unit)->sceneDrawId != 0) {
        SceneDraw_SetResVisibleChecked(((BtlUnit *)unit)->sceneDrawId, 1);
        *(s32 *)&typedUnit->flags3 &= ~2;
        return;
    }
    *(s32 *)&typedUnit->flags3 |= 2;
}

/* Hide both the model and its scene resource, clearing the queued visibility bit. The final clear
 * stays an s32 cast because retail does a word-wide store there. */
// FUN_0019D0C0
void btlUnitHideModel(u8 *unit) {
    BtlUnit *typedUnit = (BtlUnit *)unit;
    ((BtlUnit *)unit)->flags3 |= 0x1000;
    btlUnitClearModelState(unit, 5);
    if (((BtlUnit *)unit)->sceneDrawId != 0) {
        SceneDraw_SetResVisibleChecked(((BtlUnit *)unit)->sceneDrawId, 0);
    }
    *(s32 *)&typedUnit->flags3 &= ~2;
}

