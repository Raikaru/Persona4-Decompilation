#include "model_battle_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_cond_internal.h"
#include "datCalc_unit_internal.h"
#include "btl_formation_attach_internal.h"
#include "btl_unit_internal.h"
typedef struct BtlPacket BtlPacket;
static inline s32 p4_001d7f10_add(s32 left, s32 right)
{
    return left + right;
}

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern u32 iGpffffb3b8;

extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
extern s32 mdlComputeIndexedAttachMatrix();
extern void mdlUpdateModelMatrix(u8 *model);
extern void mdlPrepareItemSlots(u8 *model);
extern void RtQuatTransformVectors(f32 *output, f32 *input, s32 count, u8 *rotation);
extern u8 D_005DC7D0[];
extern u8 D_00794150[];
extern char D_005DC824[];
extern char D_00794AE0[];
extern char D_00794C00[];
extern void btlFormationVuTransform(f32 distance, f32 height, f32 *center, s32 *rotation, u8 *mode, u8 *position);
struct RwV3d;
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, struct RwV3d *outCenter,
                          f32 *outTop, f32 *outBottom, u32 options);
extern u8 *(*jtbl_008873E8[])(s32 size, s32 flags);
extern u8 D_00609498[];
extern f32 D_006094B0[];
extern f32 D_006094D0[];
extern u8 D_0060A0E0[];
extern u8 D_0060A0F0[];
extern void mdlEffectCopyCameraAim(u8 *output);
extern void func_003dc740(void *rotation, void *axis, f32 angle, s32 combine);


extern u8 D_008813B0[];
extern u8 D_00607E50[];
extern u8 D_00609558[];
extern u8 iGpffffa4db;
extern u8 iGpffffa4da;
extern u8 iGpffffa4d9;
extern u8 iGpffffa4d8;

typedef int (*code)();










extern f32 D_0060A100[];
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8110;

/* Source unit: src/promoted/code1_001d.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001d.c; members 001d44a0-001d4dc0 */

/* measured: opt_propagation off probe for btlCameraFindFormationForCounts loop masks. */
/* measured: close opt_propagation after btlCameraFindFormationForCounts probe. */
#pragma push
#pragma pop
/* Resolve a world-space attachment point, including camera-relative VU0 normalization.
 * The final word store clears the output vector padding lane. */
// FUN_001D44A0
void btlFormationVuTransform(f32 distance, f32 height, f32 *center, s32 *rotation, u8 *mode, u8 *position)
{
    struct Vec4 {
        f32 value[4];
    };
    f32 offset[4];
    f32 orientation[4];
    f32 vectorWork[4];
    f32 origin[4];
    f32 positionY;
    f32 negativeDistance;
    s32 positionMode;
    u8 heightMode;
    u8 positionKind;

    heightMode = ((BtlAttachMode *)mode)->heightMode;
    positionKind = ((BtlAttachMode *)mode)->positionMode;
    if (heightMode == 4) {
        positionMode = positionKind & 0xFF;
        if (positionMode == 8) {
            positionY = (((BtlAttachMode *)mode)->matrixIndex == 0) ? 2.0f : distance;
        } else {
            positionY = 2.0f;
        }
    } else {
        positionY = center[1] + height * D_006094B0[heightMode];
        positionMode = positionKind & 0xFF;
        if ((positionMode == 8) && (((BtlAttachMode *)mode)->matrixIndex != 0)) {
            positionY += distance;
        }
    }
    switch (positionMode) {
    case 8:
        ((BtlAttachV4 *)position)->x = center[0];
        ((BtlAttachV4 *)position)->y = positionY;
        ((BtlAttachV4 *)position)->z = center[2];
        break;
    case 9:
    case 10:
        mdlEffectCopyCameraAim((u8 *)origin);
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            :
            : "r"(origin)
            : "$vf10", "memory");
        if (distance < height) {
            height = height;
        } else {
            height = distance;
        }
        negativeDistance = -height;
        if (positionMode == 9) {
            origin[0] = center[0];
            origin[1] = center[1];
            origin[2] = center[2];
        } else {
            origin[0] = center[0];
            origin[1] = positionY;
            origin[2] = center[2];
        }
        __asm__ volatile(
            "lqc2 $vf11, 0(%0) \n"
            "vsub.xyzw $vf11, $vf11, $vf10 \n"
            :
            : "r"(origin)
            : "$vf10", "$vf11", "memory");
        if (positionMode == 10) {
            __asm__ volatile(
                "sqc2 $vf11, 0(%0) \n"
                :
                : "r"(vectorWork)
                : "$vf11", "memory");
            vectorWork[1] = 0.0f;
            __asm__ volatile(
                "lqc2 $vf11, 0(%0) \n"
                :
                : "r"(vectorWork)
                : "$vf11", "memory");
        }
        __asm__ volatile(
            "vmul.xyz $vf2, $vf11, $vf11 \n"
            "vmulax.w $ACC, $vf0, $vf2x \n"
            "vmadday.w $ACC, $vf0, $vf2y \n"
            "vmaddz.w $vf2, $vf0, $vf2z \n"
            "vrsqrt $Q, $vf0w, $vf2w \n"
            "vwaitq \n"
            "vmulq.xyz $vf11, $vf11, $Q \n"
            :
            :
            : "$vf2", "$vf11", "ACC", "Q", "memory");
        __asm__ volatile(
            "mfc1 $3, %0 \n"
            "nop \n"
            "qmtc2 $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(negativeDistance)
            : "$3", "$vf2", "$vf11", "memory");
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vadd.xyzw $vf10, $vf10, $vf11 \n"
            "sqc2 $vf10, 0(%1) \n"
            :
            : "r"(origin), "r"(position)
            : "$vf10", "$vf11", "memory");
        break;
    default:
        *(struct Vec4 *)orientation = *(struct Vec4 *)rotation;
        func_003dc740(orientation, D_0060A0E0, D_006094D0[positionKind], 2);
        RtQuatTransformVectors(offset, (f32 *)D_0060A0F0, 1, (u8 *)orientation);
        offset[0] = offset[0] * distance;
        offset[1] = offset[1] * distance;
        offset[2] = offset[2] * distance;
        ((BtlAttachV4 *)position)->x = center[0] + offset[0];
        ((BtlAttachV4 *)position)->y = positionY + offset[1];
        ((BtlAttachV4 *)position)->z = center[2] + offset[2];
        break;
    }
    *(s32 *)&((BtlAttachV4 *)position)->w = 0;
}

/* Scale and rotate the saved offset, then resolve the entry mode relative to the unit; matrixIndex
 * doubles as a distance override for this callback. */
// FUN_001D4780
void btlFormationTransformOffset(u8 *work, u8 *unit, u8 *attachment, f32 *position) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    s32 matrixIndex;
    f32 distance;
    f32 halfRadius;
    u8 *attachmentMode;

    attachmentMode = attachment + 8;
    matrixIndex = ((BtlAttachEntry *)attachment)->mode.matrixIndex;
    if (matrixIndex == 0) {
        distance = ((BtlAttachWork *)work)->height * ((BtlUnit *)unit)->scale;
    } else {
        distance = (f32)matrixIndex;
    }
    halfRadius = 0.5f * (((BtlAttachWork *)work)->radius * ((BtlUnit *)unit)->scale);
    frame.value60 = ((BtlAttachWork *)work)->scale.x * ((BtlAttachWork *)work)->size;
    frame.value64 = ((BtlAttachWork *)work)->scale.y * ((BtlAttachWork *)work)->size;
    frame.value68 = ((BtlAttachWork *)work)->scale.z * ((BtlAttachWork *)work)->size;
    RtQuatTransformVectors(&frame.value50, &frame.value60, 1, work + 0x40);
    frame.value70 = frame.value50 + ((BtlAttachWork *)work)->pos.x;
    frame.value74 = frame.value54 + ((BtlAttachWork *)work)->pos.y;
    frame.value78 = frame.value58 + ((BtlAttachWork *)work)->pos.z;
    btlFormationVuTransform(distance, halfRadius, &frame.value70, (s32 *)(work + 0x40), attachmentMode, (u8 *)position);
}

/* Use the indexed model attachment position when available, otherwise transform the saved unit offset. */
// FUN_001D48B0
void btlFormationOrientToUnit(u8 *work, u8 *unit, u8 *attachment, f32 *position) {
    struct Frame {
        f32 value30;
        f32 value34;
        f32 value38;
        f32 pad3C;
        f32 value40;
        f32 value44;
        f32 value48;
        f32 pad4C;
        f32 value50;
        f32 value54;
        f32 value58;
    } frame;
    u16 matrixIndex;
    u8 *attachmentMode;

    attachmentMode = attachment + 8;
    if ((((BtlUnit *)unit)->flags2 & 2) == 0) {
        btlUnitGetSphereWorldCenter(unit, &frame.value50);
    } else {
        matrixIndex = ((BtlAttachMode *)attachmentMode)->matrixIndex;
        if (mdlComputeIndexedAttachMatrix(((BtlUnit *)unit)->layerHandle, matrixIndex, &frame.value50) == 0) {
            frame.value40 = ((BtlAttachWork *)work)->scale.x * ((BtlAttachWork *)work)->size;
            frame.value44 = ((BtlAttachWork *)work)->scale.y * ((BtlAttachWork *)work)->size;
            frame.value48 = ((BtlAttachWork *)work)->scale.z * ((BtlAttachWork *)work)->size;
            RtQuatTransformVectors(&frame.value30, &frame.value40, 1, work + 0x40);
            frame.value50 = frame.value30 + ((BtlAttachWork *)work)->pos.x;
            frame.value54 = frame.value34 + ((BtlAttachWork *)work)->pos.y;
            frame.value58 = frame.value38 + ((BtlAttachWork *)work)->pos.z;
        }
    }
    position[0] = frame.value50;
    position[1] = frame.value54;
    position[2] = frame.value58;
}

/* Resolve a position on the alternate attached model, falling back to the unit model and saved offset.
 * The child model comes from the second weapon attachment slot. */
// FUN_001D49C0
void btlFormationApplyModelMatrix(u8 *work, u8 *unit, u8 *attachment, f32 *position) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    u8 *model;
    u8 *attachedModel;
    u8 *attachmentMode;

    attachmentMode = attachment + 8;
    if ((((BtlUnit *)unit)->flags2 & 2) == 0) {
        btlUnitGetSphereWorldCenter(unit, &frame.value70);
    } else {
        model = ((BtlUnit *)unit)->layerHandle;
        attachedModel = ((Model *)model)->attachedWpns[1].wpnMdl;
        if (attachedModel == NULL) {
            attachedModel = model;
        }
        mdlUpdateModelMatrix(attachedModel);
        mdlPrepareItemSlots(attachedModel);
        if (mdlComputeIndexedAttachMatrix(attachedModel, ((BtlAttachMode *)attachmentMode)->matrixIndex, &frame.value70) == 0) {
            frame.value60 = ((BtlAttachWork *)work)->scale.x * ((BtlAttachWork *)work)->size;
            frame.value64 = ((BtlAttachWork *)work)->scale.y * ((BtlAttachWork *)work)->size;
            frame.value68 = ((BtlAttachWork *)work)->scale.z * ((BtlAttachWork *)work)->size;
            RtQuatTransformVectors(&frame.value50, &frame.value60, 1, work + 0x40);
            frame.value70 = frame.value50 + ((BtlAttachWork *)work)->pos.x;
            frame.value74 = frame.value54 + ((BtlAttachWork *)work)->pos.y;
            frame.value78 = frame.value58 + ((BtlAttachWork *)work)->pos.z;
        }
    }
    position[0] = frame.value70;
    position[1] = frame.value74;
    position[2] = frame.value78;
}

/* Resolve a position on the first weapon attachment, falling back to the unit model and saved offset. */
// FUN_001D4B00
void btlFormationApplyModelMatrixAlt(u8 *work, u8 *unit, u8 *attachment, f32 *position) {
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 pad5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6C;
        f32 value70;
        f32 value74;
        f32 value78;
    } frame;
    u8 *model;
    u8 *attachedModel;
    u8 *attachmentMode;

    attachmentMode = attachment + 8;
    if ((((BtlUnit *)unit)->flags2 & 2) == 0) {
        btlUnitGetSphereWorldCenter(unit, &frame.value70);
    } else {
        model = ((BtlUnit *)unit)->layerHandle;
        attachedModel = ((Model *)model)->attachedWpns[0].wpnMdl;
        if (attachedModel == NULL) {
            attachedModel = model;
        }
        mdlUpdateModelMatrix(attachedModel);
        mdlPrepareItemSlots(attachedModel);
        if (mdlComputeIndexedAttachMatrix(attachedModel, ((BtlAttachMode *)attachmentMode)->matrixIndex, &frame.value70) == 0) {
            frame.value60 = ((BtlAttachWork *)work)->scale.x * ((BtlAttachWork *)work)->size;
            frame.value64 = ((BtlAttachWork *)work)->scale.y * ((BtlAttachWork *)work)->size;
            frame.value68 = ((BtlAttachWork *)work)->scale.z * ((BtlAttachWork *)work)->size;
            RtQuatTransformVectors(&frame.value50, &frame.value60, 1, work + 0x40);
            frame.value70 = frame.value50 + ((BtlAttachWork *)work)->pos.x;
            frame.value74 = frame.value54 + ((BtlAttachWork *)work)->pos.y;
            frame.value78 = frame.value58 + ((BtlAttachWork *)work)->pos.z;
        }
    }
    position[0] = frame.value70;
    position[1] = frame.value74;
    position[2] = frame.value78;
}

/* Build an attachment point around bounds of both battle sides; a nonzero entry distance overrides the
 * group radius. */
// FUN_001D4C40
void btlFormationOffsetTransformA(u8 *work, u8 *unit, u8 *attachment, f32 *position) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 temp;
    u8 *attachmentMode;

    attachmentMode = attachment + 8;
    base = btlUnitGetGroupBounds(3, 0, &frame.center, &frame.value4C, 0, 0);
    temp = ((BtlAttachMode *)attachmentMode)->matrixIndex;
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    btlFormationVuTransform(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, attachmentMode, (u8 *)position);
}

/* Build an attachment point around the unit side bounds, using the entry distance override when
 * present. */
// FUN_001D4CF0
void btlFormationOffsetTransformB(u8 *work, u8 *unit, u8 *attachment, f32 *position) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 mode;
    s32 temp;
    u8 *attachmentMode;

    if (((BtlUnit *)unit)->genus == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    attachmentMode = attachment + 8;
    base = btlUnitGetGroupBounds(mode & 0xFFFF, 0, &frame.center, &frame.value4C, 0, 0);
    temp = ((BtlAttachMode *)attachmentMode)->matrixIndex;
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    btlFormationVuTransform(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, attachmentMode, (u8 *)position);
}

/* Build an attachment point around the opposing side bounds, using the entry distance override when
 * present. */
// FUN_001D4DC0
void btlFormationOffsetTransformC(u8 *work, u8 *unit, u8 *attachment, f32 *position) {
    struct Frame {
        s32 zero0;
        s32 zero1;
        s32 zero2;
        s32 one;
        RwV3d center;
        f32 value4C;
    } frame;
    f32 base;
    f32 value;
    s32 mode;
    s32 temp;
    u8 *attachmentMode;

    if (((BtlUnit *)unit)->genus == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    attachmentMode = attachment + 8;
    base = btlUnitGetGroupBounds(mode & 0xFFFF, 0, &frame.center, &frame.value4C, 0, 0);
    temp = ((BtlAttachMode *)attachmentMode)->matrixIndex;
    if (temp == 0) {
        value = base;
    } else {
        value = (f32)temp;
    }
    frame.one = 0x3F800000;
    frame.zero0 = 0;
    frame.zero1 = 0;
    frame.zero2 = 0;
    btlFormationVuTransform(value, 0.5f * frame.value4C, (f32 *)&frame.center, &frame.zero0, attachmentMode, (u8 *)position);
}

