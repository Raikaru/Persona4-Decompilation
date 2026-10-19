/* Source unit: src/Battle/btlMain_001b5e60.c */
#include "include_asm.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_effect_internal.h"
#include "btl_unit_internal.h"
#include "btl_action_internal.h"

/* Packet 0x606 (0x10 bytes) and 0x607 (8 bytes), filled by their factories. */
typedef struct BtlUnitTintWork {
    struct BtlAction *action;
    u32 totalFrames;
    u32 currentFrame;
    u16 selector;
    u8 pad0E[2];
} BtlUnitTintWork;
typedef struct BtlUnitAlphaWork {
    u32 totalFrames;
    u32 currentFrame;
} BtlUnitAlphaWork;



extern u32 btlCountUnitRecords(void);
extern u32 btlSoundIsPlaybackActive(void);
extern void btlSoundResetBattleChannels(void);

typedef int (*code)();

BtlPacket* btlPacketAlloc(u32 type, u32 workSize);

extern u32 btlMainFieldColorFadePacketUpdate(void* work);
extern f32 fGpffff81f4; /* P4 gp -0x7e0c */

u32 btlMainUpdateCameraLerp(void* work);
typedef struct BtlMainColorWork BtlMainColorWork;
extern u32 btlMainUpdateColorWork(BtlMainColorWork* value); /* retail update target */
u32 btlMainUpdateFade(void* work);
typedef struct BtlMainLerpWork
{
    f32 value0;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 target0;
    f32 target1;
    f32 target2;
    f32 target3;
    u32 totalFrames;
    u32 currentFrame;
} BtlMainLerpWork;
typedef struct BtlMainColorFadeWork
{
    f32 value0;
    f32 value1;
    f32 value2;
    f32 value3;
    u32 totalFrames;
    u32 currentFrame;
} BtlMainColorFadeWork;

extern f32 fGpffffb458; /* target RGBA bytes begin four bytes later */
extern u8* iGpffffb3ac;

typedef struct BtlMainSlerpResult
{
    f32 current0;
    f32 current1;
    f32 current2;
    f32 current3;
    f32 next0;
    f32 next1;
    f32 next2;
    f32 next3;
    f32 angle;
    s32 mode;
} BtlMainSlerpResult;
u32 btlMainUpdateColorFade(void* work);
u32 btlMainUpdateUnitTint(void* work);
u32 btlMainUpdateUnitAlphaFade(void* work);

extern u8 *func_003bb4a0(u8 *spline, s32 index, f32 *position);

#include "rw_types_internal.h"

typedef struct RwV4d RwV4d;
struct RwV4d
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};
extern RwV4d* resrcMngGetColorValue(void);
extern RwV4d* resrcMngGetColorTarget(void);
extern void resrcMngApplyColorFactors(void* value);

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct BtlMainColorWork
{
    RwV4d target0;
    RwV4d current0;
    RwV4d target1;
    RwV4d current1;
    RwV4d target2;
    RwV4d current2;
    u32 totalFrames;
    u32 currentFrame;
    u16 flags;
    u16 padding;
};

typedef struct BtlMainMatrix
{
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
} BtlMainMatrix;

extern u_long128 D_00922C60[4];
extern f32 D_00922CA0[8];
extern s32 D_00922CC0[];
extern void mdlBlendTranslationRotation(f32* out, f32* first, f32* second, f32 weight);
extern f32 fGpffff80c0; /* P4 gp -0x7f40 */
extern f32 fGpffff80c8; /* P4 gp -0x7f38 */
extern f32 fGpffff81a4; /* P4 gp -0x7e5c */

extern f32 fGpffff8434; /* P4 gp -0x7bcc */

extern void btlMainEvalLinearPosition(u8* curve, f32* output, f32 value);
extern void btlMainEvalBezierPosition(u8* curve, f32* output, f32 value);
extern void func_003bb5b0(void* curve, s32 mode, f32 time, RwV3d* dst, void* aux);
extern void func_003dcc70(f32* first, f32* second, BtlMainSlerpResult* result);
extern f32 fGpffff83f8;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff8344;
extern f32 fGpffff843c;
extern f32 fGpffff8440;
extern void btlMainEvalSlerpRotation(u8* curve, f32* output, f32 value);
extern f32 fGpffff8438; /* P4 gp -0x7bc8 */



// FUN_001B5E60
/* Finish battle shutdown once both unit records and sound playback are drained, then clear the active
 * flag. */
u32 btlMainExitUpdate(void* work)
{
    BtlBattleState* btl;

    if (btlCountUnitRecords() == 0 && btlSoundIsPlaybackActive() == 0)
    {
        btlSoundResetBattleChannels();
        btl = (BtlBattleState*)iGpffffb3ac;
        btl->flags &= ~1;
    }

    return 0;
}



// FUN_001B7880
/* Create a field-color fade packet from two packed RGBA multipliers and a frame duration. */
BtlPacket* btlMainCreateColorLerpPacket(u32 startColor, u32 targetColor, u32 duration)
{
    float *color;
    BtlPacket *packet;
    union { u32 value; u8 bytes[4]; } packed;

    packet = btlPacketAlloc(0x600, 0x68);
    packet->updateFunc = btlMainFieldColorFadePacketUpdate;
    color = packet->workData;
    packed.value = startColor;
    color[0] = fGpffff81f4 * (float)packed.bytes[0];
    color[1] = fGpffff81f4 * (float)packed.bytes[1];
    color[2] = fGpffff81f4 * (float)packed.bytes[2];
    color[3] = fGpffff81f4 * (float)packed.bytes[3];
    packed.value = targetColor;
    color[4] = fGpffff81f4 * (float)packed.bytes[0];
    color[5] = fGpffff81f4 * (float)packed.bytes[1];
    color[6] = fGpffff81f4 * (float)packed.bytes[2];
    color[7] = fGpffff81f4 * (float)packed.bytes[3];
    ((BtlMainColorWork *)color)->totalFrames = duration;
    return packet;
}


/* measured: opt_propagation off preserves the retail grouped first-vector products. */
#pragma opt_propagation off
// FUN_001B7B30
/* Interpolate the saved scene color pair over the packet duration; return one when the endpoint is
 * installed. */
u32 btlMainUpdateCameraLerp(void* work)
{
    BtlMainLerpWork* lerpWork;
    u8* global;
    u32 flags;
    u32 totalFrames;
    u32 currentFrame;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    f32 firstX;
    f32 firstY;
    f32 firstZ;
    f32 firstW;
    f32 secondX;
    f32 secondY;
    f32 secondZ;
    f32 secondW;
    RwV4d result;

    lerpWork = (BtlMainLerpWork*)work;
    global = iGpffffb3ac;
    flags = ((BtlBattleState *)global)->flags;
    if ((flags & 2) == 0)
    {
        return 1;
    }
    if ((flags & 0x2000000) == 0)
    {
        return 1;
    }

    if (lerpWork->currentFrame == 0)
    {
        *(RwV4d*)&lerpWork->value0 = *resrcMngGetColorValue();
        *(RwV4d*)&lerpWork->target0 = *resrcMngGetColorTarget();
    }

    totalFrames = lerpWork->totalFrames;
    currentFrame = lerpWork->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;

        firstX = lerpWork->value0 * inverse;
        firstY = lerpWork->value1 * inverse;
        firstZ = lerpWork->value2 * inverse;
        firstW = lerpWork->value3 * inverse;
        global = iGpffffb3ac;
        secondX = ((BtlBattleState *)global)->scene.first.x * ratio;
        secondY = ((BtlBattleState *)global)->scene.first.y * ratio;
        secondZ = ((BtlBattleState *)global)->scene.first.z * ratio;
        secondW = ((BtlBattleState *)global)->scene.first.w;
        result.x = firstX + secondX;
        result.y = firstY + secondY;
        result.z = firstZ + secondZ;
        result.w = firstW + secondW * ratio;
        *resrcMngGetColorValue() = result;

        global = iGpffffb3ac;
        result.x = lerpWork->target0 * inverse + ((BtlBattleState *)global)->scene.second.x * ratio;
        result.y = lerpWork->target1 * inverse + ((BtlBattleState *)global)->scene.second.y * ratio;
        result.z = lerpWork->target2 * inverse + ((BtlBattleState *)global)->scene.second.z * ratio;
        result.w = lerpWork->target3 * inverse + ((BtlBattleState *)global)->scene.second.w * ratio;
        *resrcMngGetColorTarget() = result;

    }
    else
    {
        global = iGpffffb3ac;
        *resrcMngGetColorValue() = *(RwV4d *)&((BtlBattleState *)global)->scene.first;
        global = iGpffffb3ac;
        *resrcMngGetColorTarget() = *(RwV4d *)&((BtlBattleState *)global)->scene.second;
        return 1;
    }

    lerpWork->currentFrame++;
    return 0;
}
/* measured: restore propagation after btlMainUpdateCameraLerp. */
#pragma opt_propagation on
// FUN_001B7E20
/* Create the scene-color interpolation packet and store its unsigned frame duration. */
BtlPacket* btlCreateTimingPacket(u32 value)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x601, 0x28);
    packet->updateFunc = btlMainUpdateCameraLerp;
    ((BtlMainLerpWork *)packet->workData)->totalFrames = value;
    return packet;
}



/* measured: opt_loop_invariants on hoists the unit-loop byte constants into the retail preheader registers. */
#pragma opt_loop_invariants on
// FUN_001B7E70
/* Snapshot scene colors and rotation, update unit light modes, then interpolate three color vectors.
 * Raw model mode bytes are SDK/model handle fields. */
u32 btlMainUpdateColorWork(BtlMainColorWork* work)
{
    u8* global;
    u8* unit;
    u32 globalFlags;
    u32 totalFrames;
    u32 currentFrame;
    u32 group;
    u_long128* matrixSrc;
    u_long128* matrixDst;
    s32 copyCount;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    f32 firstX;
    f32 firstY;
    f32 firstZ;
    f32 firstW;
    f32 secondX;
    f32 secondY;
    f32 secondZ;
    f32 secondW;
    f32 value;
    f32 otherValue;
    f32 productXW;
    f32 quatZ;
    f32 quatX;
    f32 quatY;
    f32 normalization;
    f32 scaledZ;
    f32 scaledY;
    f32 productXY;
    f32 scaledX;
    f32 productZX;
    f32 quatW;
    f32 productYZ;
    f32 productZZ;
    f32 productYY;
    f32 productXX;
    f32 productZW;
    f32 productYW;
    BtlMainMatrix matrix;
    RwV4d result;

    global = iGpffffb3ac;
    globalFlags = ((BtlBattleState *)global)->flags;
    if ((globalFlags & 2) == 0)
    {
        return 1;
    }
    if ((globalFlags & 0x2000000) == 0)
    {
        return 1;
    }

    if (work->currentFrame == 0)
    {
        work->target0.w = 1.0f;
        global = iGpffffb3ac;
        work->current0 = *(RwV4d *)&((BtlBattleState *)global)->colorFactors;
        work->current1 = *(RwV4d *)&((BtlBattleState *)global)->list4.first;
        work->current2 = *(RwV4d *)&((BtlBattleState *)global)->list4.second;

        *(RwV4d*)&D_00922CA0[0] = *(RwV4d *)&((BtlBattleState *)global)->scene.first;
        *(RwV4d*)&D_00922CA0[4] = *(RwV4d *)&((BtlBattleState *)global)->scene.second;

        quatY = ((BtlBattleState *)global)->scene.rotation.imag.y;
        quatX = ((BtlBattleState *)global)->scene.rotation.imag.x;
        quatZ = ((BtlBattleState *)global)->scene.rotation.imag.z;
        quatW = ((BtlBattleState *)global)->scene.rotation.real;
        normalization =
            2.0f / ((quatX * quatX) +
                    (quatY * quatY) +
                    (quatZ * quatZ) +
                    (quatW * quatW));
        scaledX = quatX * normalization;
        scaledY = quatY * normalization;
        scaledZ = quatZ * normalization;
        productXW = scaledX * quatW;
        productYW = scaledY * quatW;
        productZW = scaledZ * quatW;
        productXX = quatX * scaledX;
        productYY = quatY * scaledY;
        productZZ = quatZ * scaledZ;
        productYZ = quatY * scaledZ;
        productZX = quatZ * scaledX;
        productXY = quatX * scaledY;
        matrix.right.x = 1.0f - (productYY + productZZ);
        matrix.right.y = productXY + productZW;
        matrix.right.z = productZX - productYW;
        matrix.up.x = productXY - productZW;
        matrix.up.y = 1.0f - (productZZ + productXX);
        matrix.up.z = productYZ + productXW;
        matrix.at.x = productZX + productYW;
        matrix.at.y = productYZ - productXW;
        matrix.at.z = 1.0f - (productXX + productYY);
        matrix.pos.x = 0.0f;
        matrix.pos.y = 0.0f;
        matrix.pos.z = 0.0f;
        matrix.flags = 3;

        matrixSrc = (u_long128*)&matrix;
        matrixDst = D_00922C60;
        copyCount = 4;
        do
        {
            u_long128 matrixRow = *matrixSrc;
            matrixSrc++;
            copyCount--;
            *matrixDst = matrixRow;
            matrixDst++;
        }
        while (copyCount > 0);

        D_00922CC0[0] = 1;
        if ((work->flags & 4) == 0)
        {
            group = 0;
            while (group < 4)
            {
                unit = *(u8**)(iGpffffb3ac + group * 8 + 0x178);
                while (unit != 0)
                {
                    if ((((BtlUnit *)unit)->flags2 & 2) != 0)
                    {
                        if ((work->flags & 1) != 0)
                        {
                            (((BtlUnit *)unit)->layerHandle)[0x281] = 0;
                            (((BtlUnit *)unit)->layerHandle)[0x282] = 6;
                        }
                        else
                        {
                            (((BtlUnit *)unit)->layerHandle)[0x281] = 0x50;
                            (((BtlUnit *)unit)->layerHandle)[0x282] = 4;
                        }
                    }
                    unit = (u8 *)((BtlUnit *)unit)->nextUnit;
                }
                group++;
            }
        }
    }

    /* measured: opt_propagation off preserves the retail grouped interpolation products. */
#pragma opt_propagation off
    totalFrames = work->totalFrames;
    currentFrame = work->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;

        firstX = work->current0.x * inverse;
        firstY = work->current0.y * inverse;
        firstZ = work->current0.z * inverse;
        secondX = work->target0.x * ratio;
        secondY = work->target0.y * ratio;
        secondZ = work->target0.z;
        result.x = firstX + secondX;
        result.y = firstY + secondY;
        result.z = firstZ + secondZ * ratio;
        result.w = 1.0f;
        global = iGpffffb3ac;
        *(RwV4d *)&((BtlBattleState *)global)->colorFactors = result;
        resrcMngApplyColorFactors(&result);

        firstX = work->current1.x * inverse;
        firstY = work->current1.y * inverse;
        firstZ = work->current1.z * inverse;
        firstW = work->current1.w * inverse;
        secondX = work->target1.x * ratio;
        secondY = work->target1.y * ratio;
        secondZ = work->target1.z * ratio;
        secondW = work->target1.w;
        ((BtlBattleState *)iGpffffb3ac)->list4.first.x = firstX + secondX;
        ((BtlBattleState *)iGpffffb3ac)->list4.first.y = firstY + secondY;
        ((BtlBattleState *)iGpffffb3ac)->list4.first.z = firstZ + secondZ;
        ((BtlBattleState *)iGpffffb3ac)->list4.first.w = firstW + secondW * ratio;

        firstY = work->current2.y * inverse;
        firstZ = work->current2.z * inverse;
        firstW = work->current2.w * inverse;
        secondY = work->target2.y * ratio;
        secondZ = work->target2.z * ratio;
        secondW = work->target2.w * ratio;
        ((BtlBattleState *)iGpffffb3ac)->list4.second.x =
            work->current2.x * inverse + work->target2.x * ratio;
        ((BtlBattleState *)iGpffffb3ac)->list4.second.y = firstY + secondY;
        ((BtlBattleState *)iGpffffb3ac)->list4.second.z = firstZ + secondZ;
        ((BtlBattleState *)iGpffffb3ac)->list4.second.w = firstW + secondW;
    }
    else
    {
        resrcMngApplyColorFactors(work);
        global = iGpffffb3ac;
        *(RwV4d *)&((BtlBattleState *)global)->colorFactors = work->target0;
        *(RwV4d *)&((BtlBattleState *)global)->list4.first = work->target1;
        *(RwV4d *)&((BtlBattleState *)global)->list4.second = work->target2;
        return 1;
    }

    work->currentFrame++;
    return 0;
}
/* measured: restore loop-invariant extraction after btlMainUpdateColorWork. */
#pragma opt_loop_invariants off
/* measured: restore propagation after btlMainUpdateColorWork. */
#pragma opt_propagation on
// FUN_001B83F0
/* Unpack three RGBA colors into a color-work packet and record duration and mode flags. */
BtlPacket* btlMainCreateColorWorkPacket(s32 lightColor, s32 ambientColor, s32 fogColor, u32 duration, u16 flags)
{
    float *color;
    int packetAddress;
    union { u32 value; u8 bytes[4]; } packed;

    packetAddress = (int)btlPacketAlloc(0x602, 0x6c);
    *(code **)&((BtlPacket *)packetAddress)->updateFunc = (code *)btlMainUpdateColorWork;
    color = *(float **)&((BtlPacket *)packetAddress)->workData;

    packed.value = (u32)lightColor;
    color[0] = fGpffff81f4 * (float)packed.bytes[0];
    color[1] = fGpffff81f4 * (float)packed.bytes[1];
    color[2] = fGpffff81f4 * (float)packed.bytes[2];
    color[3] = fGpffff81f4 * (float)packed.bytes[3];

    packed.value = (u32)ambientColor;
    color[8] = fGpffff81f4 * (float)packed.bytes[0];
    color[9] = fGpffff81f4 * (float)packed.bytes[1];
    color[10] = fGpffff81f4 * (float)packed.bytes[2];
    color[0xb] = fGpffff81f4 * (float)packed.bytes[3];

    packed.value = (u32)fogColor;
    color[0x10] = fGpffff81f4 * (float)packed.bytes[0];
    color[0x11] = fGpffff81f4 * (float)packed.bytes[1];
    color[0x12] = fGpffff81f4 * (float)packed.bytes[2];
    color[0x13] = fGpffff81f4 * (float)packed.bytes[3];

    ((BtlMainColorWork *)color)->totalFrames = duration;
    ((BtlMainColorWork *)color)->flags = flags;
    return (BtlPacket*)packetAddress;
}



/* The five-vector work record matches the constructor's 0x5C allocation.
 * Both alpha contributions are weighted before their sum, preserving the
 * retail multiply-accumulate chain and the rounding constants' lifetimes. */
typedef struct BtlMainFadeWork
{
    RwV4d from0;
    RwV4d from1;
    RwV4d from2;
    RwV4d from3;
    RwV4d from4;
    u32 totalFrames;
    u32 currentFrame;
    u16 flags;
} BtlMainFadeWork;

static inline void btlMainColorToV4d(RwV4d *out, const BtlCameraPalette *color)
{
    out->x = color->red * (1.0f / 255.0f);
    out->y = color->green * (1.0f / 255.0f);
    out->z = color->blue * (1.0f / 255.0f);
    out->w = color->alpha * (1.0f / 255.0f);
}

/* Hoist the unit loop's color-conversion constants, as in retail. */
// FUN_001B87E0
#pragma push
#pragma opt_loop_invariants on
/* Fade scene and unit colors toward the current palette, switching model light modes at the midpoint.
 * Raw model-handle reloads are measured alias-sensitive; unit tint vectors retain their existing
 * aggregate type. */
u32 btlMainUpdateFade(void *workRaw)
{
    BtlMainFadeWork *work = (BtlMainFadeWork *)workRaw;
    u8 *global;
    f32 ratio;
    f32 inv;
    f32 firstX;
    f32 firstY;
    f32 firstZ;
    f32 firstW;
    f32 secondX;
    f32 secondY;
    f32 secondZ;
    f32 secondW;
    RwV4d tmp;
    RwV4d target;

    global = iGpffffb3ac;
    if ((((BtlBattleState *)global)->flags & 2) == 0) {
        return 1;
    }
    if ((((BtlBattleState *)global)->flags & 0x2000000) == 0) {
        return 1;
    }
    if (work->currentFrame == 0) {
        work->from0 = *(RwV4d *)&((BtlBattleState *)global)->colorFactors;
        work->from3 = *(RwV4d *)&((BtlBattleState *)global)->list4.first;
        work->from4 = *(RwV4d *)&((BtlBattleState *)global)->list4.second;
        work->from1 = *resrcMngGetColorValue();
        work->from2 = *resrcMngGetColorTarget();
        {
            u8 *unit;
            u32 group;

            for (group = 0; group < 4; group++) {
                for (unit = *(u8 **)(iGpffffb3ac + group * 8 + 0x178); unit != NULL;
                     unit = (u8 *)((BtlUnit *)unit)->nextUnit) {
                    *(BtlCameraPalette *)(unit + 0x38) = *(BtlCameraPalette *)(unit + 0x3c);
                    *(RwV4d *)(unit + 0x60) = *(RwV4d *)(unit + 0x70);
                }
            }
        }
    }
    if (work->currentFrame == work->totalFrames >> 1 && (work->flags & 4) == 0) {
        {
            u32 group;
            u8 *unit;

            for (group = 0; group < 4; group++) {
                for (unit = *(u8 **)(iGpffffb3ac + group * 8 + 0x178); unit != NULL;
                     unit = (u8 *)((BtlUnit *)unit)->nextUnit) {
                    if ((((BtlUnit *)unit)->flags2 & 2) != 0 &&
                        (*(*(u8 **)(unit + 0xa00) + 0x260) & 0x10) == 0) {
                        f32 *scale;

                        (*(u8 **)(unit + 0xa00))[0x281] = 0x70;
                        (*(u8 **)(unit + 0xa00))[0x282] = 6;
                        scale = (f32 *)(*(u8 **)(unit + 0xa00) + 0x274);
                        if (*scale > 1.0f) {
                            *scale = 1.0f;
                        }
                    }
                }
            }
        }
    }
    btlMainColorToV4d(&target, &D_007635C8);
    if (work->currentFrame < work->totalFrames) {
        ratio = (f32)work->currentFrame / (f32)work->totalFrames;
        inv = 1.0f - ratio;
        firstX = work->from0.x * inv;
        firstY = work->from0.y * inv;
        firstZ = work->from0.z * inv;
        secondX = target.x * ratio;
        secondY = target.y * ratio;
        secondZ = target.z;
        tmp.x = firstX + secondX;
        tmp.y = firstY + secondY;
        tmp.z = firstZ + secondZ * ratio;
        tmp.w = 1.0f;
        *(RwV4d *)&((BtlBattleState *)iGpffffb3ac)->colorFactors = tmp;
        resrcMngApplyColorFactors(&tmp);
        firstX = work->from1.x * inv;
        firstY = work->from1.y * inv;
        firstZ = work->from1.z * inv;
        firstW = work->from1.w * inv;
        secondX = ((BtlBattleState *)iGpffffb3ac)->scene.first.x * ratio;
        secondY = ((BtlBattleState *)iGpffffb3ac)->scene.first.y * ratio;
        secondZ = ((BtlBattleState *)iGpffffb3ac)->scene.first.z * ratio;
        secondW = ((BtlBattleState *)iGpffffb3ac)->scene.first.w;
        tmp.x = firstX + secondX;
        tmp.y = firstY + secondY;
        tmp.z = firstZ + secondZ;
        tmp.w = firstW + secondW * ratio;
        *resrcMngGetColorValue() = tmp;
        firstX = work->from2.x * inv;
        firstY = work->from2.y * inv;
        firstZ = work->from2.z * inv;
        firstW = work->from2.w * inv;
        secondX = ((BtlBattleState *)iGpffffb3ac)->scene.second.x * ratio;
        secondY = ((BtlBattleState *)iGpffffb3ac)->scene.second.y * ratio;
        secondZ = ((BtlBattleState *)iGpffffb3ac)->scene.second.z * ratio;
        secondW = ((BtlBattleState *)iGpffffb3ac)->scene.second.w;
        tmp.x = firstX + secondX;
        tmp.y = firstY + secondY;
        tmp.z = firstZ + secondZ;
        tmp.w = firstW + secondW * ratio;
        *resrcMngGetColorTarget() = tmp;
        firstX = work->from3.x * inv;
        firstY = work->from3.y * inv;
        firstZ = work->from3.z * inv;
        firstW = work->from3.w * inv;
        secondX = ((BtlBattleState *)iGpffffb3ac)->savedList4.first.x * ratio;
        secondY = ((BtlBattleState *)iGpffffb3ac)->savedList4.first.y * ratio;
        secondZ = ((BtlBattleState *)iGpffffb3ac)->savedList4.first.z * ratio;
        secondW = ((BtlBattleState *)iGpffffb3ac)->savedList4.first.w;
        ((BtlBattleState *)iGpffffb3ac)->list4.first.x = firstX + secondX;
        ((BtlBattleState *)iGpffffb3ac)->list4.first.y = firstY + secondY;
        ((BtlBattleState *)iGpffffb3ac)->list4.first.z = firstZ + secondZ;
        ((BtlBattleState *)iGpffffb3ac)->list4.first.w = firstW + secondW * ratio;
        firstX = work->from4.x * inv;
        firstY = work->from4.y * inv;
        firstZ = work->from4.z * inv;
        firstW = work->from4.w * inv;
        secondX = ((BtlBattleState *)iGpffffb3ac)->savedList4.second.x * ratio;
        secondY = ((BtlBattleState *)iGpffffb3ac)->savedList4.second.y * ratio;
        secondZ = ((BtlBattleState *)iGpffffb3ac)->savedList4.second.z * ratio;
        secondW = ((BtlBattleState *)iGpffffb3ac)->savedList4.second.w;
        ((BtlBattleState *)iGpffffb3ac)->list4.second.x = firstX + secondX;
        ((BtlBattleState *)iGpffffb3ac)->list4.second.y = firstY + secondY;
        ((BtlBattleState *)iGpffffb3ac)->list4.second.z = firstZ + secondZ;
        ((BtlBattleState *)iGpffffb3ac)->list4.second.w = firstW + secondW * ratio;
        if ((work->flags & 2) == 0) {
            f32 scale = 1.0f / 255.0f;

            {
                u32 group;
                u8 *unit;

                for (group = 0; group < 4; group++) {
                    for (unit = *(u8 **)(iGpffffb3ac + group * 8 + 0x178); unit != NULL;
                         unit = (u8 *)((BtlUnit *)unit)->nextUnit) {
                        firstX = scale * unit[0x38];
                        firstX *= inv;
                        firstY = scale * unit[0x39];
                        firstY *= inv;
                        firstZ = scale * unit[0x3a];
                        firstZ *= inv;
                        firstW = scale * unit[0x3b];
                        firstW *= inv;
                        secondX = target.x * ratio;
                        secondY = target.y * ratio;
                        secondZ = target.z * ratio;
                        secondW = target.w * ratio;
                        tmp.x = firstX + secondX;
                        tmp.y = firstY + secondY;
                        tmp.z = firstZ + secondZ;
                        tmp.w = firstW + secondW;
                        unit[0x3c] = (s32)(0.5f + 255.0f * tmp.x);
                        unit[0x3d] = (s32)(0.5f + 255.0f * tmp.y);
                        unit[0x3e] = (s32)(0.5f + 255.0f * tmp.z);
                        unit[0x3f] = (s32)(0.5f + 255.0f * tmp.w);
                        *(f32 *)(unit + 0x70) = *(f32 *)(unit + 0x60) * inv;
                        *(f32 *)(unit + 0x74) = *(f32 *)(unit + 0x64) * inv;
                        *(f32 *)(unit + 0x78) = *(f32 *)(unit + 0x68) * inv;
                        *(f32 *)(unit + 0x7c) = *(f32 *)(unit + 0x6c) * inv;
                    }
                }
            }
        }
    } else {
        resrcMngApplyColorFactors(&target);
        *(RwV4d *)&((BtlBattleState *)iGpffffb3ac)->colorFactors = target;
        *resrcMngGetColorValue() = *(RwV4d *)&((BtlBattleState *)iGpffffb3ac)->scene.first;
        *resrcMngGetColorTarget() = *(RwV4d *)&((BtlBattleState *)iGpffffb3ac)->scene.second;
        *(RwV4d *)&((BtlBattleState *)iGpffffb3ac)->list4.first = *(RwV4d *)&((BtlBattleState *)iGpffffb3ac)->savedList4.first;
        *(RwV4d *)&((BtlBattleState *)iGpffffb3ac)->list4.second = *(RwV4d *)&((BtlBattleState *)iGpffffb3ac)->savedList4.second;
        if ((work->flags & 2) == 0) {
            btlMainColorToV4d(&tmp, &iGpffffb45c);
            {
                u32 group;
                u8 *unit;

                for (group = 0; group < 4; group++) {
                    for (unit = *(u8 **)(iGpffffb3ac + group * 8 + 0x178); unit != NULL;
                         unit = (u8 *)((BtlUnit *)unit)->nextUnit) {
                        *(BtlCameraPalette *)(unit + 0x3c) = D_007635C8;
                        *(RwV4d *)(unit + 0x70) = tmp;
                    }
                }
            }
        }
        return 1;
    }
    work->currentFrame++;
    return 0;
}
#pragma pop
// FUN_001B9360
/* Create the palette fade packet with its frame duration and halfword mode flags. */
BtlPacket* btlMainCreateFadePacket(s32 arg, s16 mode)
{
    BtlPacket* packet;
    u8* work;

    packet = btlPacketAlloc(0x603, 0x5c);
    packet->updateFunc = btlMainUpdateFade;
    work = (u8*)packet->workData;
    ((BtlMainFadeWork *)work)->totalFrames = arg;
    ((BtlMainFadeWork *)work)->flags = mode;
    return packet;
}



// FUN_001B93C0
/* Snapshot sky tint on the first frame and blend toward the packet color until its duration expires. */
u8 btlMainUpdateTintLerp(BtlMainLerpWork* work)
{
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    RwV4d results;
    u32 totalFrames;
    u32 currentFrame;
    u8* global;

    if (work->currentFrame == 0)
    {
        global = iGpffffb3ac;
        *(RwV4d*)&work->target0 = *(RwV4d *)&((BtlBattleState *)global)->skyColor;
    }

    totalFrames = work->totalFrames;
    currentFrame = work->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        results.x = work->target0 * inverse + work->value0 * ratio;
        results.y = work->target1 * inverse + work->value1 * ratio;
        results.z = work->target2 * inverse + work->value2 * ratio;
        results.w = work->target3 * inverse + work->value3 * ratio;
        global = iGpffffb3ac;
        *(RwV4d *)&((BtlBattleState *)global)->skyColor = results;
    }
    else
    {
        global = iGpffffb3ac;
        *(RwV4d *)&((BtlBattleState *)global)->skyColor = *(RwV4d*)&work->value0;
        return 1;
    }

    work->currentFrame++;
    return 0;
}
// FUN_001B9560
/* Create a sky-tint interpolation packet from packed RGBA and a frame duration. */
BtlPacket* btlMainCreateTintPacket(u32 targetColor, u32 duration)
{
    float *color;
    u32 packed;
    int packet;
    packet = (int)btlPacketAlloc(0x604, 0x28);
    *(code **)&((BtlPacket *)packet)->updateFunc = (code *)btlMainUpdateTintLerp;
    color = *(float **)&((BtlPacket *)packet)->workData;
    packed = targetColor;
    color[0] = fGpffff81f4 * (float)((u8*)&packed)[0];
    color[1] = fGpffff81f4 * (float)((u8*)&packed)[1];
    color[2] = fGpffff81f4 * (float)((u8*)&packed)[2];
    color[3] = fGpffff81f4 * (float)((u8*)&packed)[3];
    ((BtlMainLerpWork *)color)->totalFrames = duration;
    return (BtlPacket*)packet;
}


/* measured: opt_common_subs off preserves the retail per-component scale reloads. */
#pragma opt_common_subs off
// FUN_001B96E0
/* Fade the current sky tint to the live default RGBA value and report completion after the endpoint
 * write. */
u32 btlMainUpdateColorFade(void* work)
{
    BtlMainColorFadeWork* colorWork;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    RwV4d results;
    RwV4d target;
    u32 totalFrames;
    u32 currentFrame;
    u8* global;

    colorWork = (BtlMainColorFadeWork*)work;
    if (colorWork->currentFrame == 0)
    {
        global = iGpffffb3ac;
        *(RwV4d*)&colorWork->value0 = *(RwV4d *)&((BtlBattleState *)global)->skyColor;
    }

    target.x = fGpffff81f4 * (f32)((u8*)&fGpffffb458)[4];
    target.y = fGpffff81f4 * (f32)((u8*)&fGpffffb458)[5];
    target.z = fGpffff81f4 * (f32)((u8*)&fGpffffb458)[6];
    target.w = fGpffff81f4 * (f32)((u8*)&fGpffffb458)[7];
    totalFrames = colorWork->totalFrames;
    currentFrame = colorWork->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        results.x = colorWork->value0 * inverse + target.x * ratio;
        results.y = colorWork->value1 * inverse + target.y * ratio;
        results.z = colorWork->value2 * inverse + target.z * ratio;
        results.w = colorWork->value3 * inverse + target.w * ratio;
        global = iGpffffb3ac;
        *(RwV4d *)&((BtlBattleState *)global)->skyColor = results;
    }
    else
    {
        global = iGpffffb3ac;
        *(RwV4d *)&((BtlBattleState *)global)->skyColor = target;
        return 1;
    }

    colorWork->currentFrame++;
    return 0;
}
/* measured: restore common-subexpression optimization after btlMainUpdateColorFade. */
#pragma opt_common_subs on
// FUN_001B99A0
/* Create a timed sky-tint fade back to the current default color. */
BtlPacket* btlMainCreateColorFadePacket(s32 arg)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x605, 0x18);
    packet->updateFunc = btlMainUpdateColorFade;
    ((BtlMainColorFadeWork *)packet->workData)->totalFrames = arg;
    return packet;
}



typedef struct BtlUnit BtlUnit;
extern void btlUnitSetColor(BtlUnit* unit, RwRGBA col);
/* Measured: all 1008 bytes and five relocations match.
 * Keep the word selector and row base separate: the base load precedes
 * index arithmetic. Work counters and list links remain callback reloads. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs on
extern u8 *iGpffffb3b8;
extern s32 btlActionHasNoTargetClass(u32 arg0);
// FUN_001B99F0
/* Fade unrelated unit groups while preserving the acting unit and selected target groups. Raw target-
 * list storage is opaque in BtlAction; raw counter increments retain measured callback reloads. */
u32 btlMainUpdateUnitTint(void *work)
{
    u8 *tintWork;
    u8 *unit;
    s32 result;
    s32 i;
    u8 *node;
    u8 *primary;
    u32 total;
    u32 current;
    s32 selector;
    u8 *tableBase;
    u16 mask1;
    s32 mask2;
    s32 j;
    s32 k;
    s32 bit;
    u8 fade;
    f32 curF;
    f32 totF;
    f32 ratio;
    f32 inv;
    f32 scaled;
    RwRGBA col;

    result = 1;
    tintWork = (u8 *)work;
    unit = (u8 *)((BtlUnitTintWork *)tintWork)->action;
    selector = ((BtlUnitTintWork *)tintWork)->selector;
    if ((((BtlBattleState *)iGpffffb3ac)->battleFlags & 8) != 0)
    {
        return 1;
    }
    tableBase = iGpffffb3b8 + 0x11;
    if (*(u8 *)(tableBase + (selector & 0xFFFF) * 0x28) == 0x10)
    {
        return 1;
    }
    if (((s32)*(u16 *)(unit + 0x6a) < 2) && (*(u8 *)(*(u8 **)(unit + 0x30) + 0xa2) != 0))
    {
        return 1;
    }
    if (btlActionHasNoTargetClass((u32)unit) != 0)
    {
        mask1 = ((1 << *(u8 *)(*(u8 **)(unit + 0x30) + 0xa2)) & 0xFFFF);
        mask2 = 0;
    }
    else
    {
        s32 maskIndex;
        mask1 = 3;
        mask2 = 0;
        maskIndex = 0;
        while ((maskIndex & 0xFFFF) < (s32)*(u16 *)(unit + 0x6a))
        {
            mask2 = ((mask2 | ((1 << *(u8 *)(*(u8 **)(*(u8 **)(unit + ((u16)maskIndex * 4) + 0x38) + 0x30) + 0xa2)) & 0xFFFF)) & 0xFFFF);
            maskIndex = (maskIndex + 1) & 0xFFFF;
        }
    }
    if (*(u8 *)(*(u8 **)(unit + 0x30) + 0xa2) == 0)
    {
        j = 1;
        k = 0;
        while ((k & 0xFFFF) < (s32)*(u16 *)(unit + 0x6a))
        {
            if (*(u8 *)(*(u8 **)(*(u8 **)(unit + ((u16)k * 4) + 0x38) + 0x30) + 0xa2) != 0)
            {
                j = 0;
                break;
            }
            k = (k + 1) & 0xFFFF;
        }
        if (j != 0)
        {
            return 1;
        }
    }
    total = ((BtlUnitTintWork *)tintWork)->totalFrames;
    current = ((BtlUnitTintWork *)tintWork)->currentFrame;
    if (current < total)
    {
        curF = (f32)current;
        totF = (f32)total;
        ratio = curF / totF;
        inv = 1.0f - ratio;
        scaled = 255.0f * inv;
        fade = (u8)scaled;
        result = 0;
    }
    else
    {
        fade = 0;
    }
    i = 0;
    mask1 = mask1 & 0xFFFF;
    mask2 = mask2 & 0xFFFF;
    while ((i & 0xFFFF) < 2)
    {
        node = *(u8 **)(iGpffffb3ac + ((u16)i) * 8 + 0x178);
        while (node != 0)
        {
            if (((BtlUnit *)node)->sceneDrawId != 0)
            {
                bit = ((1 << ((BtlUnit *)node)->genus) & 0xFFFF);
                if (((mask1 & bit) != 0) && ((((BtlUnit *)node)->flags3 & 1) == 0))
                {
                    col.red = *(u8 *)(node + 0x30);
                    col.green = *(u8 *)(node + 0x31);
                    col.blue = *(u8 *)(node + 0x32);
                    primary = *(u8 **)(unit + 0x30);
                    if ((node != primary) && ((mask2 & bit) == 0))
                    {
                        col.alpha = fade;
                    }
                    else
                    {
                        col.alpha = 0xff;
                    }
                    btlUnitSetColor((BtlUnit *)node, col);
                }
            }
            node = (u8 *)((BtlUnit *)node)->nextUnit;
        }
        i = (i + 1) & 0xFFFF;
    }
    *(u32 *)(tintWork + 8) = *(u32 *)(tintWork + 8) + 1;
    return result;
}
#pragma pop
// FUN_001B9DE0
/* Create an action-associated unit-tint packet with selector, duration and zero elapsed frames. */
BtlPacket* btlMainCreateUnitTintPacket(struct BtlAction *action, u32 selector, u32 duration)
{
    BtlPacket* packet;
    u8* work;

    packet = btlPacketAlloc(0x606, 0x10);
    packet->updateFunc = btlMainUpdateUnitTint;
    work = (u8*)packet->workData;
    ((BtlUnitTintWork *)work)->action = action;
    ((BtlUnitTintWork *)work)->totalFrames = duration;
    ((BtlUnitTintWork *)work)->selector = (u16)selector;
    ((BtlUnitTintWork *)work)->currentFrame = 0;
    return packet;
}



// FUN_001B9E50
/* Raise drawable unit alpha to the current fade threshold, respecting the battle transition guard. Raw
 * elapsed-counter increments retain measured callback reloads. */
u32 btlMainUpdateUnitAlphaFade(void* work)
{
    RwRGBA color;
    f32 scaledAlpha;
    f32 totalFloat;
    f32 currentFloat;
    BtlUnit *unit;
    s32 index;
    s32 result;
    s32 compareThreshold;
    u8 threshold;
    u32 current;
    u32 total;
    u8 *fadeWork;

    fadeWork = (u8 *)work;
    if (((((BtlBattleState *)iGpffffb3ac)->flags & 0x400000) != 0) &&
        ((((BtlBattleState *)iGpffffb3ac)->actionEndFlags & 0x10) != 0))
    {
        return 1;
    }

    result = 1;
    total = ((BtlUnitAlphaWork *)fadeWork)->totalFrames;
    current = ((BtlUnitAlphaWork *)fadeWork)->currentFrame;
    if (current < total)
    {
        currentFloat = (f32)(u32)current;
        totalFloat = (f32)(u32)total;
        scaledAlpha = 255.0f * (currentFloat / totalFloat);
        threshold = (u8)scaledAlpha;
        result = 0;
    }
    else
    {
        threshold = 0xFF;
    }

    index = 0;
    compareThreshold = threshold & 0xFF;
    while ((index & 0xFFFF) < 2)
    {
        unit = *(BtlUnit **)(iGpffffb3ac + (((u16)index) * 8) + 0x178);
        while (unit != NULL)
        {
            if ((((BtlUnit *)(u8 *)unit)->sceneDrawId != 0) &&
                ((((BtlUnit *)(u8 *)unit)->flags3 & 1) == 0))
            {
                color = *(RwRGBA *)((u8 *)unit + 0x30);
                if ((s32)color.alpha < compareThreshold)
                {
                    color.alpha = threshold;
                    btlUnitSetColor(unit, color);
                }
            }
            unit = (BtlUnit *)((BtlUnit *)(u8 *)unit)->nextUnit;
        }
        index = (index + 1) & 0xFFFF;
    }

    *(u32 *)(fadeWork + 4) = *(u32 *)(fadeWork + 4) + 1;
    return result;
}
// FUN_001BA090
/* Create the unit-alpha fade packet with an unsigned elapsed counter initialized by allocation. */
BtlPacket* btlMainCreateColorSetPacket(s32 arg)
{
    BtlPacket* packet;

    packet = btlPacketAlloc(0x607, 8);
    packet->updateFunc = btlMainUpdateUnitAlphaFade;
    *(s32*)packet->workData = arg;
    return packet;
}



// FUN_001BA9E0
/* Append an optional position/quaternion to the four-key ring and mirror position into the spline.
 * Measured: direct curveKeys addressing changes MATCH; retain integer-address copies and raw ring
 * writes. */
u32 btlMainCurveAppendKeyframe(u16 *curve, f32 *position, f32 *rotation)
{
    u16 index;
    u32 address;
    f32 *entry;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    if (((BtlCamera *)curve)->keyCount >= 4)
    {
        return 0;
    }
    index = ((BtlCamera *)curve)->keyWriteIndex;
    if (position != ((void*)0))
    {
        address = (u32)index * 0x1c;
        address = address + (u32)curve;
        entry = (f32*)(address + 4);
        value2 = position[0];
        value3 = position[1];
        value1 = position[2];
        entry[0] = value2;
        entry[1] = value3;
        entry[2] = value1;
        if ((*curve & 1) == 0)
        {
            func_003bb4a0(*(u8 **)(curve + 0x4c), index, position);
        }
    }
    if (rotation != ((void*)0))
    {
        address = (u32)index * 0x1c;
        address = address + (u32)curve;
        entry = (f32*)(address + 0x10);
        value2 = rotation[0];
        value3 = rotation[1];
        value4 = rotation[2];
        value1 = rotation[3];
        entry[0] = value2;
        entry[1] = value3;
        entry[2] = value4;
        entry[3] = value1;
    }
    index++;
    if (index >= 4)
    {
        index = 0;
    }
    curve[0x3c] = index;
    curve[0x3b]++;
    return 1;
}



// FUN_001BAB00
/* Reset curve mode, ring counters and time, then seed the first position/quaternion. Raw ring writes
 * preserve callback-visible reloads and the existing integer-address copy shape. */
void btlMainCurveReset(u16 *curve, f32 *pose)
{
    u16 index;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    *curve = 0;
    curve[0x3a] = 0;
    curve[0x3b] = 0;
    curve[0x3c] = 0;
    *(u32*)((u8*)curve + 0x80) = 0;
    *(u32*)((u8*)curve + 0x7c) = 0;
    if (((BtlCamera *)curve)->keyCount < 4)
    {
        index = ((BtlCamera *)curve)->keyWriteIndex;
        if (pose != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address = address + (u32)curve;
            entry = (f32*)(address + 4);
            value2 = pose[0];
            value3 = pose[1];
            value1 = pose[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index, pose);
            }
        }
        source = pose + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address = address + (u32)curve;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        curve[0x3c] = index;
        curve[0x3b]++;
    }
}



// FUN_001BAC20
/* Seed four keys from two endpoint poses and their one-third/two-third interpolants. Measured: typed
 * count reloads change MATCH; keep raw ring writes and callback-visible count checks. */
void btlMainCurveSetPoses(u16 *curve, f32 *firstPose, f32 *lastPose, u16 mode)
{
    u16 index;
    u16 index0;
    u16 index1;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    f32 work[7];

    *curve = mode;
    curve[0x3a] = 0;
    curve[0x3b] = 0;
    curve[0x3c] = 0;
    *(u32*)((u8*)curve + 0x80) = 0;
    *(u32*)((u8*)curve + 0x7c) = 0;
    if (curve[0x3b] < 4)
    {
        index0 = ((BtlCamera *)curve)->keyWriteIndex;
        if (firstPose != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 4);
            value2 = firstPose[0];
            value3 = firstPose[1];
            value1 = firstPose[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index0, firstPose);
            }
        }
        source = firstPose + 3;
        if (source != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index0++;
        if (index0 >= 4)
        {
            index0 = 0;
        }
        curve[0x3c] = index0;
        curve[0x3b]++;
    }

    mdlBlendTranslationRotation(work, firstPose, lastPose, fGpffff80c0);
    if (curve[0x3b] < 4)
    {
        index1 = ((BtlCamera *)curve)->keyWriteIndex;
        if (work != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index1, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index1++;
        if (index1 >= 4)
        {
            index1 = 0;
        }
        curve[0x3c] = index1;
        curve[0x3b]++;
    }

    mdlBlendTranslationRotation(work, firstPose, lastPose, fGpffff80c8);
    if (curve[0x3b] < 4)
    {
        index = ((BtlCamera *)curve)->keyWriteIndex;
        if (work != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        curve[0x3c] = index;
        curve[0x3b]++;
    }

    if (curve[0x3b] < 4)
    {
        index = ((BtlCamera *)curve)->keyWriteIndex;
        if (lastPose != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 4);
            value2 = lastPose[0];
            value3 = lastPose[1];
            value1 = lastPose[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index, lastPose);
            }
        }
        source = lastPose + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        curve[0x3c] = index;
        curve[0x3b]++;
    }
}



/* Three poses form four keys: first, two-thirds toward the middle,
   one-third toward the last, then last. Curve writes precede quaternion
   reloads, including when an input aliases spline storage.
   Measured: 984/992B, eight resolved relocations, eight zero-tail bytes. */
// FUN_001BAFF0
/* Seed four keys from three poses, interpolating the interior pair around the middle pose. Measured:
 * typed count reloads change MATCH; keep raw ring writes and callback-visible count checks. */
void btlMainCurveSetThreePoses(u16 *curve, f32 *firstPose, f32 *middlePose, f32 *lastPose, u16 mode)
{
    u16 index;
    u16 index0;
    u16 index1;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    f32 work[7];

    *curve = mode;
    curve[0x3a] = 0;
    curve[0x3b] = 0;
    curve[0x3c] = 0;
    *(u32*)((u8*)curve + 0x80) = 0;
    *(u32*)((u8*)curve + 0x7c) = 0;
    if (curve[0x3b] < 4)
    {
        index0 = ((BtlCamera *)curve)->keyWriteIndex;
        if (firstPose != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 4);
            value2 = firstPose[0];
            value3 = firstPose[1];
            value1 = firstPose[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index0, firstPose);
            }
        }
        source = firstPose + 3;
        if (source != ((void*)0))
        {
            address = (u32)index0 * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index0++;
        if (index0 >= 4)
        {
            index0 = 0;
        }
        curve[0x3c] = index0;
        curve[0x3b]++;
    }

    mdlBlendTranslationRotation(work, firstPose, middlePose, fGpffff80c8);
    if (curve[0x3b] < 4)
    {
        index1 = ((BtlCamera *)curve)->keyWriteIndex;
        if (work != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index1, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index1 * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index1++;
        if (index1 >= 4)
        {
            index1 = 0;
        }
        curve[0x3c] = index1;
        curve[0x3b]++;
    }

    mdlBlendTranslationRotation(work, middlePose, lastPose, fGpffff81a4);
    if (curve[0x3b] < 4)
    {
        index = ((BtlCamera *)curve)->keyWriteIndex;
        if (work != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 4);
            *(RwV3d*)entry = *(RwV3d*)work;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index, work);
            }
        }
        if (work + 3 != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 0x10);
            *(RwV4d*)entry = *(RwV4d*)(work + 3);
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        curve[0x3c] = index;
        curve[0x3b]++;
    }

    if (curve[0x3b] < 4)
    {
        index = ((BtlCamera *)curve)->keyWriteIndex;
        if (lastPose != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 4);
            value2 = lastPose[0];
            value3 = lastPose[1];
            value1 = lastPose[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*curve & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8*)curve + 0x98), index, lastPose);
            }
        }
        source = lastPose + 3;
        if (source != ((void*)0))
        {
            address = (u32)index * 0x1c;
            address += (u32)curve;
            entry = (f32*)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        curve[0x3c] = index;
        curve[0x3b]++;
    }
}
/* Exact: 948B/960B, four resolved spline calls and twelve zero-tail bytes.
   Keep each append's count/index reloads and callback-visible copy order. */
// FUN_001BB3D0
/* Reset the curve and copy four explicit position/quaternion poses in order. Raw ring storage retains
 * the established callback-visible copy order and byte-address traversal. */
void btlMainCurveSetFourPoses(void *camera, void *first, void *second,
                   void *third, void *fourth, u16 mode)
{
    u16 *state = (u16 *)camera;
    u16 index;
    u32 address;
    f32 *entry;
    f32 *source;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;

    state[0] = mode;
    state[0x3A] = 0;
    state[0x3B] = 0;
    state[0x3C] = 0;
    *(u32 *)((u8 *)camera + 0x80) = 0;
    *(u32 *)((u8 *)camera + 0x7C) = 0;
    if (state[0x3B] < 4)
    {
        index = state[0x3C];
        if (first != NULL)
        {
            address = (u32)index * 0x1C;
            address = address + (u32)state;
            entry = (f32 *)(address + 4);
            value2 = ((f32 *)first)[0];
            value3 = ((f32 *)first)[1];
            value1 = ((f32 *)first)[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*state & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8 *)state + 0x98), index, first);
            }
        }
        source = (f32 *)((u8 *)first + 0xC);
        if (source != NULL)
        {
            address = (u32)index * 0x1C;
            address = address + (u32)state;
            entry = (f32 *)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        state[0x3C] = index;
        state[0x3B]++;
    }
    if (state[0x3B] < 4)
    {
        index = state[0x3C];
        if (second != NULL)
        {
            address = (u32)index * 0x1C;
            address = address + (u32)state;
            entry = (f32 *)(address + 4);
            value2 = ((f32 *)second)[0];
            value3 = ((f32 *)second)[1];
            value1 = ((f32 *)second)[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*state & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8 *)state + 0x98), index, second);
            }
        }
        source = (f32 *)((u8 *)second + 0xC);
        if (source != NULL)
        {
            address = (u32)index * 0x1C;
            address = address + (u32)state;
            entry = (f32 *)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        state[0x3C] = index;
        state[0x3B]++;
    }
    if (state[0x3B] < 4)
    {
        index = state[0x3C];
        if (third != NULL)
        {
            address = (u32)index * 0x1C;
            address = address + (u32)state;
            entry = (f32 *)(address + 4);
            value2 = ((f32 *)third)[0];
            value3 = ((f32 *)third)[1];
            value1 = ((f32 *)third)[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*state & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8 *)state + 0x98), index, third);
            }
        }
        source = (f32 *)((u8 *)third + 0xC);
        if (source != NULL)
        {
            address = (u32)index * 0x1C;
            address = address + (u32)state;
            entry = (f32 *)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        state[0x3C] = index;
        state[0x3B]++;
    }
    if (state[0x3B] < 4)
    {
        index = state[0x3C];
        if (fourth != NULL)
        {
            address = (u32)index * 0x1C;
            address = address + (u32)state;
            entry = (f32 *)(address + 4);
            value2 = ((f32 *)fourth)[0];
            value3 = ((f32 *)fourth)[1];
            value1 = ((f32 *)fourth)[2];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value1;
            if ((*state & 1) == 0)
            {
                func_003bb4a0(*(u8 **)((u8 *)state + 0x98), index, fourth);
            }
        }
        source = (f32 *)((u8 *)fourth + 0xC);
        if (source != NULL)
        {
            address = (u32)index * 0x1C;
            address = address + (u32)state;
            entry = (f32 *)(address + 0x10);
            value2 = source[0];
            value3 = source[1];
            value4 = source[2];
            value1 = source[3];
            entry[0] = value2;
            entry[1] = value3;
            entry[2] = value4;
            entry[3] = value1;
        }
        index++;
        if (index >= 4)
        {
            index = 0;
        }
        state[0x3C] = index;
        state[0x3B]++;
    }
}
extern RwV3d D_00881430;
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
/* Exact: 296B/304B, six resolved relocations and eight zero-tail bytes.
   Scoped loop extraction hoists positive zero; the coefficient pointer
   retains retail's stack-address materialization with propagation off. */
// FUN_001BB790
/* Evaluate cubic Bezier position weights across the four-key ring. Raw coordinate loads retain the
 * integer-address traversal of the canonical 0x1C-byte pose records. */
void btlMainEvalBezierPosition(u8 *curveWork, f32 *position, f32 time)
{
    f32 weights[4];
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 coefficient;
    u16 i;
    s32 index;
    u8 *p;
    f32 *weight;

    f3 = 1.0f - time;
    f1 = f3 * f3;
    weights[0] = f3 * f1;
    f0 = time * f1;
    f2 = 3.0f;
    weights[1] = f2 * f0;
    f1 = time * time;
    f0 = f3 * f1;
    weights[2] = f2 * f0;
    weights[3] = time * f1;
    index = ((BtlCamera *)curveWork)->keyReadIndex;
    *(RwV3d *)position = D_00881430;
    i = 0;
    while (i < 4) {
        weight = &weights[i];
        coefficient = *weight;
        p = curveWork + (u16)index * 0x1C;
        f4 = *(f32 *)(p + 8) * coefficient;
        f3 = *(f32 *)(p + 0xC) * coefficient;
        position[0] = (position[0] + 0.0f) + *(f32 *)(p + 4) * coefficient;
        position[1] += f4;
        position[2] += f3;
        index = (u16)(index + 1);
        if (index >= 4) {
            index = 0;
        }
        i++;
    }
}
#pragma pop
// FUN_001BB8C0
/* Select adjacent ring keys from time and linearly interpolate their positions. Raw coordinate loads
 * retain the integer-address traversal of the canonical 0x1C-byte pose records. */
void btlMainEvalLinearPosition(u8* curve, f32* position, f32 time)
{
    u16 currentIndex;
    u16 nextIndex;
    u32 currentAddress;
    u32 nextAddress;
    f32 currentX;
    f32 currentY;
    f32 currentZ;
    f32 nextX;
    f32 nextY;
    f32 nextZ;
    f32 blend;
    f32 period;
    currentIndex = ((BtlCamera *)curve)->keyReadIndex;
    period = fGpffff8434;
    while (time >= period)
    {
        currentIndex++;
        time -= period;
    }
    time /= period;
    if (currentIndex >= 4)
    {
        currentIndex &= 3;
    }
    nextIndex = currentIndex + 1;
    if (nextIndex >= 4)
    {
        nextIndex &= 3;
    }
    blend = 1.0f - time;
    currentAddress = (u32)currentIndex * 0x1c;
    currentAddress = currentAddress + (u32)curve;
    currentY = *(f32*)(currentAddress + 8);
    currentY = currentY * blend;
    currentZ = *(f32*)(currentAddress + 0xc);
    currentZ = currentZ * blend;
    nextAddress = (u32)nextIndex * 0x1c;
    nextAddress = nextAddress + (u32)curve;
    nextY = *(f32*)(nextAddress + 8);
    nextY = nextY * time;
    nextZ = *(f32*)(nextAddress + 0xc);
    nextZ = nextZ * time;
    currentX = *(f32*)(currentAddress + 4);
    nextX = *(f32*)(nextAddress + 4);
    position[0] = currentX * blend + nextX * time;
    position[1] = currentY + nextY;
    position[2] = currentZ + nextZ;
}



// FUN_001BB9B0
/* Select neighboring ring quaternions and blend them using the prepared spherical/linear mode and sine
 * approximation. */
void btlMainEvalSlerpRotation(u8* curve, f32* rotation, f32 time)
{
    u16 index;
    u16 nextIndex;
    u8* currentAddress;
    u8* nextAddress;
    f32 period;
    f32 blend;
    f32 inverse;
    f32 f0;
    f32 f1;
    f32 f3;
    f32 f4;
    BtlMainSlerpResult result;

    blend = time;
    index = ((BtlCamera *)curve)->keyReadIndex;
    period = fGpffff8434;
    while (blend >= period)
    {
        index++;
        blend -= period;
    }
    blend = blend / period;

    if (index >= 4)
        index &= 3;
    nextIndex = (u16)((index + 1) & 0xffff);
    if (nextIndex >= 4)
        nextIndex &= 3;

    nextAddress = curve + ((u32)nextIndex * 0x1c) + 0x10;
    currentAddress = curve + ((u32)index * 0x1c) + 0x10;
    func_003dcc70((f32*)currentAddress, (f32*)nextAddress, &result);

    if (blend <= 0.0f)
    {
        *(RwV4d*)rotation = *(RwV4d*)currentAddress;
        return;
    }
    if (1.0f <= blend)
    {
        *(RwV4d*)rotation = *(RwV4d*)nextAddress;
        return;
    }

    inverse = 1.0f - blend;
    if (result.mode == 0)
    {
        f4 = inverse * result.angle;
        f3 = f4 * f4;
        f0 = fGpffff83f8 * f3 + fGpffff8054;
        f0 = f3 * f0 + fGpffff8058;
        f0 = f3 * f0 + fGpffff8344;
        f0 = f3 * f0 + fGpffff843c;
        f1 = f3 * f0 + fGpffff8440;
        f0 = f3 * f4;
        inverse = f0 * f1 + f4;

        f4 = blend * result.angle;
        f3 = f4 * f4;
        f1 = fGpffff83f8 * f3 + fGpffff8054;
        f1 = f3 * f1 + fGpffff8058;
        f1 = f3 * f1 + fGpffff8344;
        f1 = f3 * f1 + fGpffff843c;
        f0 = f3 * f1 + fGpffff8440;
        f1 = f3 * f4;
        blend = f1 * f0 + f4;
    }

    rotation[0] = result.current0 * inverse;
    rotation[1] = result.current1 * inverse;
    rotation[2] = result.current2 * inverse;
    rotation[0] = result.next0 * blend + rotation[0];
    rotation[1] = result.next1 * blend + rotation[1];
    rotation[2] = result.next2 * blend + rotation[2];
    rotation[3] = result.current3 * inverse + result.next3 * blend;
}
// FUN_001BBC40
/* Sample the available keys with a single pose, linear interpolation, Bezier, or spline position and
 * quaternion interpolation. Raw spline and pose copies retain their original pointer/copy shape. */
u32 btlCameraSampleKeyframes(u8* curveWork, f32* position, f32* rotation)
{
    void* curve;
    u16 frame;
    u16 index;
    u8* entry;
    frame = ((BtlCamera *)curveWork)->keyCount;
    if (0 < frame)
    {
        goto has_frame;
    }
    return 0;
has_frame:
    if (frame < 2)
    {
        index = ((BtlCamera *)curveWork)->keyReadIndex;
        entry = (u8 *)((u32)index * 0x1c);
        entry += (u32)curveWork;
        *(RwV3d *)position = *(RwV3d *)(entry + 4);
        index = ((BtlCamera *)curveWork)->keyReadIndex;
        entry = (u8 *)((u32)index * 0x1c);
        entry += (u32)curveWork;
        *(RwV4d *)rotation = *(RwV4d *)(entry + 0x10);
        return 0;
    }
    if (frame < 4)
    {
        btlMainEvalLinearPosition(curveWork, position, *(f32*)(curveWork + 0x7c));
    }
    else if ((((BtlCamera *)curveWork)->curveFlags & 1) != 0)
    {
        btlMainEvalBezierPosition(curveWork, position, *(f32*)(curveWork + 0x7c));
    }
    else
    {
        curve = *(void* *)(curveWork + 0x98);
        func_003bb5b0((void*)curve, 0xa,
                     *(f32*)(curveWork + 0x7c),
                     (RwV3d *)position, ((void*)0));
    }
    btlMainEvalSlerpRotation(curveWork, rotation, *(f32*)(curveWork + 0x7c));
    return 1;
}



// FUN_001BBD80
/* Advance time, consume complete key intervals, and wrap the read index in the four-key ring. Raw ring
 * writes preserve the measured load/store alias behavior. */
u32 btlCameraAdvanceKeyframes(u8* curveWork, f32 deltaTime)
{
    u16 frame;
    u16 counter;
    u32 result;
    f32 value;
    frame = ((BtlCamera *)curveWork)->keyCount;
    if (frame < 2)
    {
        *(u32*)(curveWork + 0x7c) = 0;
        return 0;
    }
    value = *(f32*)(curveWork + 0x7c) + deltaTime;
    if (frame < 3)
    {
        if (!(value < fGpffff8434))
        {
            value = 0.0f;
            *(u16 *)(curveWork + 0x76) = frame - 1;
            *(u16 *)(curveWork + 0x74) = ((BtlCamera *)curveWork)->keyReadIndex + 1;
        }
    }
    else if (frame < 4)
    {
        if (!(value < fGpffff80c8))
        {
            value = 0.0f;
            *(u16 *)(curveWork + 0x76) = frame - 2;
            *(u16 *)(curveWork + 0x74) = ((BtlCamera *)curveWork)->keyReadIndex + 2;
        }
    }
    else if (!(value < fGpffff8438))
    {
        value = value - 1.0f;
        *(u16 *)(curveWork + 0x76) = frame - 3;
        *(u16 *)(curveWork + 0x74) = ((BtlCamera *)curveWork)->keyReadIndex + 3;
    }
    counter = ((BtlCamera *)curveWork)->keyReadIndex;
    if (counter >= 4)
    {
        *(u16 *)(curveWork + 0x74) = counter & 3;
    }
    *(f32*)(curveWork + 0x7c) = value;
    result = 1;
    return result;
}



// FUN_001BBEF0
/* Convert seconds to the camera frame-duration convention and select the eased transition mode. Raw
 * bit-pattern writes preserve the float storage interpretation. */
void btlCameraSetDuration(u8* work, f32 value)
{
    *(f32*)(work + 0x84) = (value * 2.0f * 60.0f) / 2.0f;
    *(u32*)(work + 0x94) = 0x3f000000;
    *(u16*)work = *(u16*)work & 0xfff5;
    *(u16*)work = *(u16*)work | 4;
}
