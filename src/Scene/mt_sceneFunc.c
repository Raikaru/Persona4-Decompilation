#include "operand_order_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Source unit: src/Scene/mt_sceneFunc.c (functions consolidated from the retired src/mt_scene/mt_scene_00268bd0.c) */
#include "type.h"
#include "member_access.h"
#include "effect_update_internal.h"
#include "scene_event_internal.h"
#include "scene_resource_internal.h"
#include "scene_task_internal.h"
#include "kwln_view_internal.h"

/* Unit settings: measured scene helpers use loop invariants off and propagation on. */
#pragma opt_loop_invariants off
#pragma opt_propagation on




// lint: allow H011 -- measured: u16 prototype regresses MT_Scene_BeginResMoveToward (andi on wide id args); retail declared this old-style
extern void *MT_Scene_GetRes();
u32 MT_Scene_GetSegmentHeading(float* start, float* end, float* directionOutput, float* headingOutput);

extern u32 MT_Scene_BeginResPathAnim(ResrcHeader* resource, u32 pathWords, float speed, u32 loop);
extern u32 MT_Scene_SetResColorParam(u32 resourceAddress, u8 alpha, u32 duration, u32 enableBlend);

extern u32 MT_Scene_SetResMotionRecord(u32 *resource, u32 layer, u32 animation, u32 frame,
                         u32 flags, u32 blend, float speed);
extern u32 MT_Scene_SetResActive(void* resource, s32 enabled);
extern s32 MT_Scene_SetResShadowCaster(u8 *resource, s32 enabled);

extern u8 *MT_Scene_GetResListHead(s32 resourceType);

extern void MT_Scene_WrapAngles(float *angles);

// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbb90 (verified MATCH
// there). 006a2f48 -> D_0063b1a0, 006a2f50 -> D_0063b1a8, 004c69f0 ->
// func_003e40b0, 00530da0 -> func_0044dcd8, 0052e9a0 -> func_0044b8d8,
// 005318a0 -> func_0044e7d8, 007caf18 -> fGpffff8428 (gp 0x007690f0 - 0x7bd8).

typedef struct SceneVecBits
{
    u64 xy;
    float z;
} __attribute__((packed)) SceneVecBits;

extern SceneVecBits D_0063b1a0[];
extern float D_0063b1a8[];
extern SceneVecBits D_0063B120[];
extern f32 D_0063B128[];
extern SceneVecBits D_0063B130[];
extern f32 D_0063B138[];
extern SceneVecBits D_0063B140[];
extern f32 D_0063B148[];
extern SceneVecBits D_0063B150[];
extern f32 D_0063B158[];
extern float RwV3dNormalize(float *dst, const float *src);
extern u32 fptodp(float param_1);
extern u32 func_0044b8d8(u32 value);
extern float dptofp(u32 value);
extern float fGpffff8428;

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbc90 (verified MATCH there). */

#include "rw_types_internal.h"

// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbd40 (verified MATCH
// there). 003bbc90 -> MT_Scene_EvalCubicBezier.

extern void MT_Scene_EvalCubicBezier(float t, float *x, float *y, float *z, float *outX, float *outY, float *outZ);
extern f32 RwV3dLength(const RwV3d *vector);

// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bc0e0 (verified MATCH
// there). 007cb0b8 -> D_007614c0, 003bbfd0 -> MT_Scene_GetCurveSegmentLength.

extern f32 D_007614c0;
extern float MT_Scene_GetCurveSegmentLength(float firstTime, float secondTime, float *controlX, float *controlY, float *controlZ, float *firstPoint, float *secondPoint);

// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bcc80 (verified MATCH
// there). 007ce658 -> D_00764580, 003500e0 -> mdlEffectSeqStop.

extern u16 D_00764580;
extern u32 D_00764584;
extern u32 D_00764588;
extern u32 D_0076458C;
extern void mdlEffectSeqStop(void);

extern void MT_Scene_WrapObjectAngles(s32 object);
extern float MT_Scene_GetCurveLength(char *path);
extern s32 mtSceneIconSpawnTask(u16 resourceId, s32 iconIndex);
extern s32 FldShadow_SetCasterFlag(s32, s32, s32);
extern void memset(void *dst, s32 value, s32 size);
extern f32 RwV3dNormalize();
extern s64 D_0063B110;
extern f32 D_0063B118;
extern u8 D_0063B110_abs[];
extern f32 fGpffff8048;
extern void RwMatrixRotate(void *dst, void *src, f32 angle, s32 mode);
extern u8 *func_003e4320(void *dst, void *src, void *mat);
extern s32 RwMatrixUpdate(void *);
extern s32 K_FldFrame_IsPointInTriangle();
extern s32 mdlIsLayerKeyEmpty(u32 model, u16 layer, s16 animation);
extern void mdlSetLayerWeight(u32 model, u16 layer, f32 speed);
extern void mdlSetLayerTime(u32 model, u16 layer, f32 frameValue);
extern void *mdlGetColor();
extern void mdlEffectGetPackedColor(void *object, s32 *color);
extern void chkmemAllocSiteTag(const void *file, u32 line);

extern void kAssertFail(const void *file, u32 line);
extern void func_00440b68(const void *msg, u32 value);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u32 *jtbl_008873E8[];
extern s32 K_View_SetFov(void *camera, f32 fov);
extern u8 *kwlnGetCamera(void);
extern u8 *func_003e0f80(void);
extern void RwMatrixTranslate(void *dst, void *src, s32 mode);
extern u32 MT_Scene_GetShakeOffset(float *offset);
extern void func_003e9df0(void *);
extern void func_003e9cb0(void *frame, void *transform, s32 combine);
extern void func_003e0f40(void *);
extern void MT_Scene_OffsetPointByRotation(f32 *input, f32 distance, f32 pitch, f32 yaw, f32 roll, f32 *result);
extern u8 *resrcMngGetTableEntry(u32 curveKind);
extern f32 cosf(f32);
extern f32 func_0044b938(f32 value);
extern f32 func_0044b950(f32 left, f32 right);
extern u8 *PTR_DAT_00762ea0;
extern u32 D_005F08B0[];
extern u8 D_0063B090[];
extern u8 D_0063B0A0[];
extern u8 D_0063B0D0[];
extern u8 D_0063B080[];
extern u8 D_0063B088[];
extern u8 D_0063B0F0[];
extern u8 D_0063B0F8[];
extern u8 D_0063B100[];
extern u8 D_0063B108[];
extern s64 D_0063B0B8[];
extern f32 D_0063B0C0[];
extern s32 MT_Scene_IconTaskUpdate(u8 *task);
extern void MT_Scene_IconTaskDestroy(u8 *task);
extern u8 D_0063B160_abs[];
extern u8 D_0063B170_abs[];
extern u8 D_0063B180_abs[];
extern u8 D_0063B190_abs[];
extern void MT_Scene_GetResAnchor(float *out, void *resource, f32 scale);

/* Defer effect destruction by two update frames using an eight-byte owned work block. */
// FUN_00268B20
void MT_Scene_SpawnIconTask(u32 effectHandle)
{
    u8 *work;

    chkmemAllocSiteTag(D_0063B090, 0x31);
    work = D_008873F4[0](1, 8, 0x40000);
    if ((s32)kwlnTaskCreateChild((void *)(0), (const void *)((char *)D_0063B0A0), 0, 1, 1, MT_Scene_IconTaskUpdate, MT_Scene_IconTaskDestroy, (u8 *)(work)) != 0) {
        *(u32 *)&((SceneIconWork *)work)->remainingFrames = 2;
        *(u32 *)&((SceneIconWork *)work)->value.handle = effectHandle;
    }
}

/* Set bit 3 only when enabled equals one; clear it for every other value. */
// FUN_00268BD0
u32 MT_Scene_SetResEnabled(ResrcHeader* resource, s32 enabled)
{
    if (resource == NULL)
    {
        return 0;
    }

    if (enabled == 1)
    {
        resource->flags |= 8;
    }
    else
    {
        resource->flags &= ~8;
    }

    return 1;
}



/* Resolve a resource id and update the bit-3 transition-pause flag. */
// FUN_00268C20
u32 MT_Scene_SetResEnabledById(u32 resTypeId, s32 enabled)
{
    ResrcHeader* res;

    res = MT_Scene_GetRes(resTypeId);
    if (res == NULL)
    {
        return 0;
    }
    else if (res == NULL)
    {
        return 0;
    }
    else
    {
        if (enabled == 1)
        {
            res->flags |= 8;
        }
        else
        {
            res->flags &= ~8;
        }

        return 1;
    }
}



/* Return whether a non-NULL resource has its bit-3 flag set. */
// FUN_00268CB0
u8 MT_Scene_IsResEnabled(ResrcHeader* resource)
{
    if (resource == NULL)
    {
        return 0;
    }

    return (resource->flags & 8) != 0;
}



/* measured: volatile casts on the D_0063B0B8/D_0063B0C0 global loads and the
   source-local stores force mwcc b210 to batch both loads before both stores
   (retail: lui+ld, lui+lwc1, sd, swc1) and to emit the exact FPU
   mul.s/adda.s/madd.s dot chain with the zero term in $f5; the plain form
   emits load-store-load-store. Same pattern as the matched P3FES port
   FUN_0026C860. */
// FUN_00268CE0
u32 MT_Scene_GetSegmentHeading(f32 *start, f32 *end, f32 *directionOutput, f32 *headingOutput)
{
    u32 angleBits;
    f32 heading;
    u64 sourceXy;
    f32 sourceZ;
    f32 dif[3];
    f32 direction[4];
    SceneVecBits source;

    sourceXy = ((volatile SceneVecBits *)D_0063B0B8)->xy;
    sourceZ = *(volatile f32 *)D_0063B0C0;
    *(volatile u64 *)&source.xy = sourceXy;
    *(volatile f32 *)&source.z = sourceZ;
    dif[0] = end[0] - start[0];
    dif[1] = end[1] - start[1];
    dif[2] = end[2] - start[2];
    heading = RwV3dNormalize(direction, dif);
    if (heading == 0.0f) {
        return 0;
    }
    direction[1] = 0.0f;
    angleBits = fptodp(direction[0] * ((f32 *)&source.xy)[0] +
                          direction[1] * ((f32 *)&source.xy)[1] +
                          direction[2] * source.z);
    angleBits = func_0044b8d8(angleBits);
    heading = fGpffff8428 * dptofp(angleBits);
    if (direction[0] < 0.0f) {
        heading = heading * -1.0f;
    }
    *headingOutput = heading;
    *(RwV3d *)directionOutput = *(RwV3d *)dif;
    return 1;
}

// FUN_00268E30
u32 MT_Scene_GetSegmentHeadingAngle(f32* start, f32* end, f32* headingOutput)
{
    f32 direction[4];

    return MT_Scene_GetSegmentHeading(start, end, direction, headingOutput);
}



/* Start constant-speed movement from the current position to the requested endpoint. */
// FUN_00268E60
s32 MT_Scene_BeginResMoveToward(u32 resourceId, u8 *destination, f32 speed) {
    s32 flags;
    u8 *resource = (u8*)MT_Scene_GetRes(resourceId);

    if (resource == NULL) {
        return 0;
    }
    if (resource == NULL) {
        return 0;
    }
    flags = *(s32 *)&((ResrcHeader *)resource)->flags | 1;
    *(s32 *)&((ResrcHeader *)resource)->flags = flags;
    *(s32 *)&((ResrcHeader *)resource)->flags = flags & ~0x40;
    *(SVec3 *)&((ResrcHeader *)resource)->moveStart = *(SVec3 *)&((ResrcHeader *)resource)->position;
    *(SVec3 *)&((ResrcHeader *)resource)->moveEnd = *(SVec3 *)destination;
    ((ResrcHeader *)resource)->moveSpeed = speed;
    *(s8 *)&((ResrcHeader *)resource)->moveKind = 0;
    return 1;
}



/* Start timed movement; mode 1 uses the frame counters and the selected easing curve. */
// FUN_00268F20
s32 MT_Scene_BeginResTimedMove(u32 resourceId, SVec3 *destination, u32 duration, s8 easing)
{
    s32 result;
    u8 *resource = MT_Scene_GetRes(resourceId);

    if (resource == NULL) return 0;
    if (resource == NULL) {
        result = 0;
    } else {
        ((ResrcHeader *)resource)->flags |= 1;
        ((ResrcHeader *)resource)->flags &= ~0x40;
        ((ResrcHeader *)resource)->flags &= ~0x10;
        *(SVec3 *)&((ResrcHeader *)resource)->moveStart = *(SVec3 *)&((ResrcHeader *)resource)->position;
        *(SVec3 *)&((ResrcHeader *)resource)->moveEnd = *(SVec3 *)destination;
        ((ResrcHeader *)resource)->moveDuration.frame = duration;
        result = 1;
        ((ResrcHeader *)resource)->moveKind = result;
        ((ResrcHeader *)resource)->moveEase = easing;
        ((ResrcHeader *)resource)->moveElapsed.frame = 0;
    }
    return result;
}

/* Replace movement/rotation with an eased orbit between two centers and angle/distance pairs. */
// FUN_00269000
s32 MT_Scene_SetResCurveParams(u8 *resource, u8 *startCenter, u8 *endCenter, f32 startYaw, f32 endYaw,
                  f32 startPitch, f32 endPitch, f32 startDistance, f32 endDistance, s32 duration,
                  s8 easing) {
    s32 orbitFlags;
    s32 moveFlags;
    s32 rotationFlags;

    if (resource == NULL) {
        return 0;
    }
    orbitFlags = *(s32 *)&((ResrcHeader *)resource)->flags | 0x10;
    *(s32 *)&((ResrcHeader *)resource)->flags = orbitFlags;
    moveFlags = orbitFlags & ~1;
    *(s32 *)&((ResrcHeader *)resource)->flags = moveFlags;
    rotationFlags = moveFlags & ~4;
    *(s32 *)&((ResrcHeader *)resource)->flags = rotationFlags;
    *(s32 *)&((ResrcHeader *)resource)->flags = rotationFlags & ~0x40;
    *(SVec3 *)&((ResrcHeader *)resource)->orbitStart = *(SVec3 *)startCenter;
    *(SVec3 *)&((ResrcHeader *)resource)->orbitEnd = *(SVec3 *)endCenter;
    ((ResrcHeader *)resource)->yawStart = startYaw;
    ((ResrcHeader *)resource)->yawEnd = endYaw;
    ((ResrcHeader *)resource)->pitchStart = startPitch;
    ((ResrcHeader *)resource)->pitchEnd = endPitch;
    ((ResrcHeader *)resource)->distanceStart = startDistance;
    ((ResrcHeader *)resource)->distanceEnd = endDistance;
    *(s32 *)&((ResrcHeader *)resource)->orbitDuration = duration;
    *(s8 *)&((ResrcHeader *)resource)->orbitEase = easing;
    *(s32 *)&((ResrcHeader *)resource)->orbitElapsed = 0;
    return 1;
}


// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003b89f0 (verified MATCH
// there). 003b5d10 -> func_00145270, 003b88c0 -> MT_Scene_BeginResPathAnim.


// FUN_002690B0
s32 MT_Scene_SetResCurveParamsById(u32 resourceId, u8 *startCenter, u8 *endCenter, f32 startYaw, f32 endYaw,
                  f32 startPitch, f32 endPitch, f32 startDistance, f32 endDistance, s32 duration,
                  s8 easing)
{
    u8 *resource = MT_Scene_GetRes(resourceId);
    s32 result;

    if (resource != NULL) {
        result = MT_Scene_SetResCurveParams(resource, startCenter, endCenter, startYaw, endYaw, startPitch, endPitch, startDistance, endDistance, duration, easing);
    } else {
        result = 0;
    }
    return result;
}

/* Copy the 0x130-byte path, cache its sampled length and optionally wrap elapsed distance. */
/* measured: three path-pointer accesses require MEMBER: access-site, typed-local and array forms grow the body to 328 bytes (320-byte window). */
// FUN_00269190
u32 MT_Scene_BeginResPathAnim(ResrcHeader *resource, u32 pathWords, f32 speed, u32 loop)
{
    u32 firstWord;
    u32 secondWord;
    u32 *outputWords;
    s32 resourceAddress;
    s32 remainingPairs;

    if (resource == 0) return 0;
    resourceAddress = (s32)resource;
    firstWord = resource->flags;
    firstWord = firstWord | 1;
    resource->flags = firstWord;
    firstWord = firstWord & 0xFFFFFFBF;
    resource->flags = firstWord;
    if (loop == 1) {
        resource->flags = resource->flags | 0x40;
    }
    *(f32 *)&((ResrcHeader *)resourceAddress)->moveSpeed = speed;
    *(u8 *)&((ResrcHeader *)resourceAddress)->moveKind = 2;
    *(u32 *)&((ResrcHeader *)resourceAddress)->moveElapsed.frame = 0;
    if (*(u32 *)&((ResrcHeader *)resourceAddress)->path == 0) {
        chkmemAllocSiteTag(D_0063B090, 0x269);
        secondWord = (u32)((u32(*)(u32, u32))jtbl_008873E8[0])(0x130, 0x40000);
        MEMBER(u32, resourceAddress, ResrcHeader, path) = secondWord;
        if (secondWord == 0) {
            kAssertFail(D_0063B090, 0x26A);
        }
    }
    outputWords = MEMBER(u32 *, resourceAddress, ResrcHeader, path);
    remainingPairs = 0x26;
    do {
        firstWord = *(u32 *)pathWords;
        secondWord = *((u32 *)pathWords + 1);
        pathWords = (u32)((u32 *)pathWords + 2);
        remainingPairs--;
        *outputWords = firstWord;
        outputWords[1] = secondWord;
        outputWords += 2;
    } while (0 < remainingPairs);
    {
        f32 length;
        length = MT_Scene_GetCurveLength((char *)MEMBER(u32, resourceAddress, ResrcHeader, path));
        *(f32 *)&((ResrcHeader *)resourceAddress)->moveDuration.distance = length;
        func_00440b68(D_0063B0D0, fptodp(length));
    }
    return 1;
}


/* Resolve the packed resource id and start its copied path animation; return zero when absent. */
// FUN_002692D0
u32 MT_Scene_BeginResPathAnimById(u32 resourceId, u32 pathWords, f32 speed, u32 loop)
{
    u32 resourceAddress;
    u32 result;

    resourceAddress = (u32)MT_Scene_GetRes(resourceId);
    if (resourceAddress != 0)
    {
        result = MT_Scene_BeginResPathAnim((ResrcHeader*)resourceAddress, pathWords, speed, loop);
    }
    else
    {
        result = 0;
    }
    return result;
}



/* Snapshot the current rotation and normalize both endpoints before starting the timer. */
// FUN_00269340
s32 MT_Scene_BeginResRotation(u32 resourceId, SVec3 *angles, u32 duration, u8 easing)
{
    SVec3 values;
    u8 *resource = MT_Scene_GetRes(resourceId);

    if (resource == NULL) return 0;
    values = *angles;
    if (resource == NULL) return 0;
    MT_Scene_WrapObjectAngles((s32)resource);
    MT_Scene_WrapAngles((f32 *)&values);
    ((ResrcHeader *)resource)->flags |= 4;
    *(SVec3 *)&((ResrcHeader *)resource)->rotationStart = *(SVec3 *)&((ResrcHeader *)resource)->rotation;
    *(SVec3 *)&((ResrcHeader *)resource)->rotationEnd = values;
    ((ResrcHeader *)resource)->unknown80 = 0;
    ((ResrcHeader *)resource)->rotationEase = easing;
    ((ResrcHeader *)resource)->rotationDuration = duration;
    ((ResrcHeader *)resource)->rotationElapsed = 0;
    return 1;
}

/* Snapshot scale endpoints and start a linear scale transition. */
// FUN_00269440
s32 MT_Scene_BeginResScale(u32 resourceId, u8 *scale, s32 duration) {
    u8 *resource = (u8*)MT_Scene_GetRes(resourceId);

    if (resource == NULL) {
        return 0;
    }
    if (resource == NULL) {
        return 0;
    }
    *(s32 *)&((ResrcHeader *)resource)->flags |= 0x8000;
    *(SVec3 *)&((ResrcHeader *)resource)->scaleUpdate.start = *(SVec3 *)&((ResrcHeader *)resource)->scale;
    *(SVec3 *)&((ResrcHeader *)resource)->scaleUpdate.end = *(SVec3 *)scale;
    *(s32 *)&((ResrcHeader *)resource)->scaleUpdate.duration = duration;
    *(s32 *)&((ResrcHeader *)resource)->scaleUpdate.elapsed = 0;
    return 1;
}


// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003b8e10 (verified MATCH
// there). 003b5d10 -> func_00145270, 003b8ce0 -> MT_Scene_SetResColorParam.


/* Start an alpha transition on NPC models or effects, preserving the current alpha. */
// FUN_002694F0
u32 MT_Scene_SetResColorParam(u32 resourceAddress, u8 alpha, u32 duration, u32 enableBlend)
{
    u8 colorBytes[8];
    u8 startAlpha;

    if (resourceAddress == 0) return 0;
    switch (((s32)(*(u16 *)resourceAddress & 0xFFC00)) >> 10) {
    case 3:
    {
        u8 *colorCursor = mdlGetColor(*(u32 *)&((ResrcRecord *)resourceAddress)->modelHandle164);
        u8 b0 = *colorCursor++;
        u8 b1 = *colorCursor++;
        u8 b2 = *colorCursor++;
        u8 b3 = *colorCursor++;

        colorBytes[4] = b0;
        colorBytes[5] = b1;
        colorBytes[6] = b2;
        colorBytes[7] = b3;
        startAlpha = colorBytes[7];
        if (enableBlend == 1) {
            *(u8 *)&((ResrcHeader *)resourceAddress)->alphaBlend = 1;
        } else {
            *(u8 *)&((ResrcHeader *)resourceAddress)->alphaBlend = 0;
        }
        break;
    }
    case 6:
        mdlEffectGetPackedColor(((ResrcRecord *)resourceAddress)->slotHandle[1], (s32 *)colorBytes);
        startAlpha = colorBytes[3];
        break;
    default:
        return 0;
    }
    ((ResrcHeader *)resourceAddress)->flags |= 0x4000;
    ((ResrcHeader *)resourceAddress)->alphaStart = startAlpha;
    ((ResrcHeader *)resourceAddress)->alphaEnd = alpha;
    ((ResrcHeader *)resourceAddress)->alphaDuration = duration;
    ((ResrcHeader *)resourceAddress)->alphaElapsed = 0;
    return 1;
}

/* Resolve the resource id before starting its alpha transition; return zero when absent. */
// FUN_00269620
u32 MT_Scene_SetResColorParamById(u32 resourceId, u8 alpha, u32 duration, u32 enableBlend)
{
    u32 resourceAddress;
    u32 result;

    resourceAddress = (u32)MT_Scene_GetRes(resourceId);
    if (resourceAddress != 0)
    {
        result = MT_Scene_SetResColorParam(resourceAddress, alpha, duration, enableBlend);
    }
    else
    {
        result = 0;
    }
    return result;
}



/* Start a field-of-view transition only for a type-7 camera resource. */
// FUN_00269690
s32 MT_Scene_BeginResFovChange(u32 resourceId, f32 fieldOfView, s32 duration) {
    u8 *resource = (u8*)MT_Scene_GetRes(resourceId);

    if (resource == NULL) {
        return 0;
    }
    if (resource == NULL) {
        return 0;
    }
    if (((*(u16 *)resource & 0xFFC00) >> 0xA) != 7) {
        return 0;
    }
    *(s32 *)&((ResrcHeader *)resource)->flags |= 0x400;
    ((ResrcHeader *)resource)->fovStart = *(f32 *)&((ResrcRecord *)resource)->slotHandle[0];
    ((ResrcHeader *)resource)->fovEnd = fieldOfView;
    ((ResrcHeader *)resource)->fovDuration = duration;
    ((ResrcHeader *)resource)->fovElapsed = 0;
    return 1;
}


// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003b93c0 (verified MATCH
// there). 003b5d10 -> func_00145270, 003b8ff0 -> MT_Scene_SetResMotion,
// 003b9260 -> MT_Scene_SetResMotionRecord.


/* Cancel active transform, animation, alpha and orbit transition flags without changing their stored values. */
// FUN_00269740
s32 MT_Scene_ResetResMotion(u32 resourceId)
{
    u8 *resource = MT_Scene_GetRes(resourceId);

    if (resource == NULL) return 0;
    if (resource == NULL) return 0;
    ((ResrcHeader *)resource)->flags &= ~1;
    ((ResrcHeader *)resource)->flags &= ~4;
    ((ResrcHeader *)resource)->flags &= 0xFFFF7FFF;
    ((ResrcHeader *)resource)->flags &= ~0x40;
    ((ResrcHeader *)resource)->flags &= ~0x400;
    ((ResrcHeader *)resource)->flags &= ~0x800;
    ((ResrcHeader *)resource)->flags &= ~0x1000;
    ((ResrcHeader *)resource)->flags &= ~0x2000;
    ((ResrcHeader *)resource)->flags &= ~0x4000;
    ((ResrcHeader *)resource)->flags &= ~0x10;
    ((ResrcHeader *)resource)->flags &= 0xF7FFFFFF;
    return 1;
}

/* Select the kind-specific model handle and dispatch a nonempty animation layer. */
// FUN_00269820
u32 MT_Scene_SetResMotion(u16 *resource, s32 layer, s32 animation, s32 frame, s32 restart, s32 startTime,
                  f32 weight)
{
    s32 flags;
    s32 model;

    if (resource == NULL) return 0;
    switch (((s32)(resource[0] & 0xFFC00)) >> 10) {
    case 1:
        model = *(s32 *)&((ResrcRecord *)resource)->modelHandle164;
        break;
    case 2:
        model = *(s32 *)&((ResrcRecord *)resource)->modelHandle158;
        break;
    case 3:
        model = *(s32 *)&((ResrcRecord *)resource)->modelHandle164;
        break;
    case 10:
        model = *(s32 *)&((ResrcRecord *)resource)->slotHandle[1];
        break;
    default:
        return 0;
    }
    flags = 0;
    if (restart == 1) {
        flags |= 1;
    }
    if (mdlIsLayerKeyEmpty(model, layer, (s16)animation) == 0) {
        mdlSetLayerWeight(model, layer, weight);
        mdlDispatchAnimIfPresent((u8*)model, (u16)layer, (s16)animation, (u16)frame, flags & 0xFFFF);
        if (startTime > 0) {
            mdlSetLayerTime(model, layer, (f32)startTime);
        }
    }
    *(s32 *)&((ResrcHeader *)resource)->flags &= ~0x2000;
    return 1;
}
/* Store the six-field queued animation record at the model-kind-specific tail offset. */
// FUN_002699D0
u32 MT_Scene_SetResMotionRecord(u32 *resource, u32 layer, u32 animation, u32 frame, u32 flags, u32 blend, f32 speed)
{
    u8 *animationRecord;

    if (resource == NULL) return 0;
    switch (((s32)(*(u16 *)resource & 0xFFC00)) >> 10) {
    case 1:
        animationRecord = (u8 *)resource + 0x14C;
        break;
    case 2:
        animationRecord = (u8 *)resource + 0x140;
        break;
    case 3:
        animationRecord = (u8 *)resource + 0x14C;
        break;
    default:
        return 0;
    }
    ((ResrcHeader *)resource)->flags |= 0x2000;
    *(u32 *)&((SceneQueuedAnimation *)animationRecord)->layer = layer;
    *(u32 *)&((SceneQueuedAnimation *)animationRecord)->animation = animation;
    *(u32 *)&((SceneQueuedAnimation *)animationRecord)->frame = frame;
    *(u32 *)&((SceneQueuedAnimation *)animationRecord)->flags = flags;
    *(u32 *)&((SceneQueuedAnimation *)animationRecord)->blend = blend;
    ((SceneQueuedAnimation *)animationRecord)->speed = speed;
    return 1;
}

/* Play an NPC animation immediately and optionally queue the next animation. */
// FUN_00269A90
void MT_Scene_SetResMotionSlot(u32 resourceId, s16 firstAnimation, s16 firstFrame, s16 nextAnimation,
                   s16 nextFrame)
{
    u32 npcResourceId;
    u32 queuedAnimation;
    u32 resourceAddress;
    u32 currentResourceAddress;

    npcResourceId = (u16)resourceId;
    npcResourceId = (u16)(npcResourceId & 0x3ff | 0xc00);

    queuedAnimation = (u32)nextAnimation;
    if (queuedAnimation == -1) {
        resourceAddress = (u32)MT_Scene_GetRes(npcResourceId);
        if (resourceAddress != 0) {
            MT_Scene_SetResMotion((u16 *)resourceAddress, 0, firstAnimation, firstFrame, 1, 0, 1.0f);
        }
        goto end;
    }

    currentResourceAddress = (u32)MT_Scene_GetRes(npcResourceId);
    if (currentResourceAddress == 0) {
        goto second_done;
    }
    MT_Scene_SetResMotion((u16 *)currentResourceAddress, 0, firstAnimation, firstFrame, 0, 0, 1.0f);

second_done:
    resourceAddress = (u32)MT_Scene_GetRes(npcResourceId);
    if (resourceAddress != 0) {
        MT_Scene_SetResMotionRecord((u32 *)resourceAddress, 0, queuedAnimation, nextFrame, 1, 0, 1.0f);
    }

end:
    return;
}



/* Set or clear the resource draw-active bit (bit 1). */
// FUN_00269BD0
u32 MT_Scene_SetResActive(void* resource, s32 enabled)
{
    u32 result;
    s32 address;

    address = (s32)resource;
    if (resource == NULL)
    {
        result = 0;
    }
    else
    {
        if (enabled == 1)
        {
            ((ResrcHeader *)address)->flags |= 2;
        }
        else
        {
            ((ResrcHeader *)address)->flags &= 0xfffffffd;
        }
        result = 1;
    }

    return result;
}



/* Resolve the resource id before updating its draw-active flag; return zero when absent. */
// FUN_00269C20
s32 MT_Scene_SetResActiveById(u32 resourceId, s32 enabled) {
    u8 *resource = (u8*)MT_Scene_GetRes(resourceId);

    if (resource != NULL) {
        return MT_Scene_SetResActive(resource, enabled);
    }
    return 0;
}



#pragma push
/* measured: opt_propagation off closes first-target nd 9 -> 0 by preserving
   absolute-global and early source-pointer load order; direct stores remain exact. */
/* measured: baseline differs by 9 words; packed-vector copy/direct field stores leave nd8/nd29; retain propagation off. */
#pragma opt_propagation off
/* Rotate a unit offset by two angles, scale it and add it to the supplied center. */
// FUN_00269C70
void MT_Scene_GetAnglePoint(f32 *out, f32 *base, f32 angle0, f32 angle1, f32 scale)
{
    f32 transformed[4];
    f32 vector1[4];
    f32 vector0[4];
    u8 matrix[64];
    u64 xy;
    f32 z;
    f32 *vectorPointer;

    xy = *(u64 *)D_0063B0F0;
    z = *(f32 *)D_0063B0F8;
    *(u64 *)vector1 = xy;
    vector1[2] = z;
    vectorPointer = vector0;

    xy = *(u64 *)D_0063B100;
    z = *(f32 *)D_0063B108;
    *(u64 *)vector0 = xy;
    vector0[2] = z;

    RwMatrixRotate(matrix, vectorPointer, -angle1, 0);
    func_003e4320(vector1, vector1, matrix);
    vector0[0] = 0.0f;
    vector0[1] = 1.0f;
    vector0[2] = 0.0f;
    RwMatrixRotate(matrix, vector0, angle0, 0);
    func_003e4320(transformed, vector1, matrix);
    RwV3dNormalize(transformed, transformed);
    transformed[0] *= scale;
    transformed[1] *= scale;
    transformed[2] *= scale;
    out[0] = transformed[0] + base[0];
    out[1] = transformed[1] + base[1];
    out[2] = transformed[2] + base[2];
}

/* measured: opt_propagation off closes nd 5 -> 0 for global-load ordering. */
/* measured: baseline differs by 5 words; direct axis stores and scale lifetime changes leave nd14; retain propagation off. */
/* Build an orthonormal basis and recover Euler angles, including the vertical-direction fallback. */
// FUN_00269DB0
void MT_Scene_GetDirectionAngles(f32 *angles, f32 *direction)
{
    typedef struct SceneMatrixAngles {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } SceneMatrixAngles;
    SceneMatrixAngles matrix;
    RwV3d input;
    RwV3d zero = {0.0f, 0.0f, 0.0f};
    RwV3d axis;
    f32 atX;
    f32 axisX;
    f32 scale;
    f32 value;
    s32 adjusted;

    {
        s64 xy = *(s64 *)D_0063B110_abs;
        f32 z = ((SceneVecBits *)D_0063B110_abs)->z;
        *(s64 *)&axis.x = xy;
        axis.z = z;
    }
    adjusted = 0;
    RwV3dNormalize(&input, direction);
    matrix.pos = zero;
    matrix.at = input;
    RwV3dNormalize(&matrix.at, &matrix.at);

    matrix.right.x = matrix.at.y * axis.z - matrix.at.z * axis.y;
    atX = matrix.at.x;
    axisX = axis.x;
    matrix.right.y = matrix.at.z * axisX - atX * axis.z;
    matrix.right.z = atX * axis.y - matrix.at.y * axisX;
    RwV3dNormalize(&matrix.right, &matrix.right);

    matrix.up.x = matrix.at.y * matrix.right.z - matrix.at.z * matrix.right.y;
    matrix.up.y = matrix.at.z * matrix.right.x - matrix.at.x * matrix.right.z;
    matrix.up.z = matrix.at.x * matrix.right.y - matrix.at.y * matrix.right.x;
    RwV3dNormalize(&matrix.up, &matrix.up);
    RwMatrixUpdate(&matrix);

    angles[1] = func_0044b950(matrix.at.x, matrix.at.z);
    angles[0] = -func_0044b938(matrix.at.y);
    if (cosf(angles[0]) != 0.0f) {
        angles[2] =
            func_0044b938(matrix.right.y / cosf(angles[0]));
        adjusted = 1;
    } else {
        angles[1] = func_0044b950(-matrix.right.z, matrix.right.x);
        angles[0] = -func_0044b938(matrix.at.y);
        angles[2] = 0.0f;
    }

    value = angles[0];
    scale = fGpffff8048;
    angles[0] = value * scale;
    angles[1] = angles[1] * scale;
    angles[2] = angles[2] * scale;
    if (adjusted != 0 && matrix.up.y < 0.0f) {
        angles[0] = 180.0f - angles[0];
    }
}
#pragma pop

/* Resource fields recovered from the P4 setters and update retail. */

typedef struct Model Model;

typedef union SceneEffectColor {
    s32 packed;
    RwRGBA rgba;
} SceneEffectColor;

extern void MT_Scene_ApplyResTransform(u8 *resource, u8 *position, u8 *rotation, u8 *scaleInput);
extern void MT_Scene_GetAngleDelta(f32 *start, f32 *end, f32 *output);
extern f32 MT_Scene_SampleCurveTable(u32 kind, f32 duration, f32 elapsed);
extern s32 MT_Scene_GetTerrainAtPoint(u16 *position);
extern void mdlSetColor(Model *model, const RwRGBA *color);
extern void mdlSetAlphaBlend(void *model);
extern void mdlClearAlphaBlend(void *model);
extern void mdlEffectSetPackedColor(void *object, s32 *packedColor);
/* The companion forwarding provider requires this same object parameter. */

extern s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);





/* Test whether a movement step has not yet reached its destination, including unordered distances. */
/* measured: expanding its one remaining call changes MT_Scene_UpdateResource from 6708 to 6688 executable bytes and changes allocation/branches. */
static inline s32 sceneUpdateStepContinues(f32 distance, f32 step)
{
    return !(distance <= step);
}

/* Compute the displacement between two resource positions. */
static inline void sceneUpdateDifference(RwV3d *out, const RwV3d *end,
                                         const RwV3d *start)
{
    out->x = end->x - start->x;
    out->y = end->y - start->y;
    out->z = end->z - start->z;
}

/* Interpolate all three position components between endpoints. */
static inline void sceneUpdateInterpolate(RwV3d *out, const RwV3d *start,
                                          const RwV3d *end, f32 amount)
{
    out->x = ((start->x) + (amount) * ((end->x) - (start->x)));
    out->y = ((start->y) + (amount) * ((end->y) - (start->y)));
    out->z = ((start->z) + (amount) * ((end->z) - (start->z)));
}



/* Attached-effect slots follow the fixed character-resource prefix. */
/* Locate an attached-effect slot after the character-resource prefix. */
/* measured: direct effects[index] at either call changes whole-owner code generation; the byte cursor retains the slot calculation. */
static inline u8 *sceneUpdateAttachedEffect(SceneCharacterUpdate *character, s32 index)
{
    u8 *slot = (u8 *)character + index * sizeof(character->effects[0]);
    return ((SceneCharacterUpdate *)slot)->effects[0];
}

/* Submit the queued motion parameters for this resource. */
static inline void sceneUpdateQueuedAnimation(ResrcHeader *resource,
                                               SceneQueuedAnimation *animation)
{
    s32 layer = animation->layer;
    s32 motion = animation->animation;
    s32 frame = animation->frame;
    s32 flags = animation->flags;
    s32 blend = animation->blend;
    f32 speed = animation->speed;
    MT_Scene_SetResMotion(&resource->id, layer, motion, frame, flags, blend, speed);
}

/* Sample resource position and rotation at the elapsed path distance. */
static inline void sceneUpdatePath(ResrcHeader *resource,
                                   RwV3d *position, RwV3d *rotation)
{
    f32 total = resource->moveDuration.distance;
    f32 elapsed = resource->moveElapsed.distance;
    s8 *path = resource->path;
    MT_Scene_SamplePath(path, elapsed, total, &position->x, &rotation->x);
}



/* Play the current terrain or fixed-bank footstep and cycle its four-note sequence. */
static inline void sceneUpdateFootstep(ResrcHeader *resource)
{
    s32 terrain = MT_Scene_GetTerrainAtPoint((u16 *)&resource->position);
    SceneFootstepUpdate *foot = &resource->footsteps;
    switch (foot->surface) {
    case 0:
        {
            s32 note = foot->sequence;
            s16 sound;
            s16 stream;
            note += terrain * 4;
            sound = note;
            stream = foot->sound;
            sdkSndStartStream(0, stream, 1, sound);
        }
        break;
    case 1:
        {
            s32 sound = operandOrderAddReversed(foot->sequence, 0x18);
            s16 stream = foot->sound;
            sdkSndStartStream(0, stream, 2, (s16)sound);
        }
        break;
    }
    foot->sequence++;
    if (foot->sequence >= 4) {
        foot->sequence = 0;
    }
}

/* Recovered Scene update: native unsigned conversions, resource views,
   queued animation snapshots and footstep bank indexing reproduce the retail
   body. Full owner/data proof: build/next-wave-20260921/event/release-closure-v3. */
// FUN_0026A020
void MT_Scene_UpdateResource(u8 *resourceData)
{
    ResrcHeader *resource = (ResrcHeader *)resourceData;
    s32 frames = 0;

    if (resource == NULL) {
        return;
    }
    if (resource->flags & 0x20) {
        frames = resource->forcedFrames;
        resource->flags &= ~0x20;
        resource->forcedFrames = 0;
    } else if (!(resource->flags & 8)) {
        frames = 1;
    }
    if (frames < 0) {
        frames = 0;
    }

    if (resource->flags & 0x10) {
        RwV3d startCenter;
        RwV3d endCenter;
        RwV3d center;
        RwV3d startPosition;
        RwV3d endPosition;
        RwV3d position;
        RwV3d direction;
        f32 startYaw;
        f32 startPitch;
        f32 startDistance;
        f32 endYaw;
        f32 endPitch;
        f32 endDistance;

        resource->flags |= 0x8000000;
        startCenter = resource->orbitStart;
        startYaw = resource->yawStart;
        startPitch = resource->pitchStart;
        startDistance = resource->distanceStart;
        MT_Scene_GetAnglePoint(&startPosition.x, &startCenter.x,
                     startYaw, startPitch, startDistance);
        resource->position = startPosition;
        resource->rotation = resource->orbitStart;
        endCenter = resource->orbitEnd;
        endYaw = resource->yawEnd;
        endPitch = resource->pitchEnd;
        endDistance = resource->distanceEnd;
        MT_Scene_GetAnglePoint(&endPosition.x, &endCenter.x,
                     endYaw, endPitch, endDistance);
        sceneUpdateDifference(&direction, &resource->orbitEnd, &resource->orbitStart);
        if (resource->orbitDuration == 0) {
            resource->position = endPosition;
            sceneUpdateDifference(&direction, &endCenter, &endPosition);
            MT_Scene_GetDirectionAngles(&resource->rotation.x, &direction.x);
            resource->flags &= ~0x10;
            resource->flags &= ~0x8000000;
        } else {
            u32 ease = resource->orbitEase;
            switch (ease) {
            case 0: {
                f32 amount = (f32)resource->orbitElapsed / (f32)resource->orbitDuration;
                sceneUpdateInterpolate(&center, &startCenter, &endCenter, amount);
                MT_Scene_GetAnglePoint(&position.x, &center.x,
                    ((startYaw) + (amount) * ((endYaw) - (startYaw))),
                    ((startPitch) + (amount) * ((endPitch) - (startPitch))),
                    ((startDistance) + (amount) * ((endDistance) - (startDistance))));
                resource->position = position;
                resource->rotation = center;
                break;
            }
            case 1: case 2: case 3: case 4: case 5: {
                f32 amount = MT_Scene_SampleCurveTable(ease,
                    (f32)resource->orbitDuration, (f32)resource->orbitElapsed);
                amount /= (f32)resource->orbitDuration;
                sceneUpdateInterpolate(&center, &startCenter, &endCenter, amount);
                MT_Scene_GetAnglePoint(&position.x, &center.x,
                    ((startYaw) + (amount) * ((endYaw) - (startYaw))),
                    ((startPitch) + (amount) * ((endPitch) - (startPitch))),
                    ((startDistance) + (amount) * ((endDistance) - (startDistance))));
                resource->position = position;
                resource->rotation = center;
                break;
            }
            }
            if (resource->orbitElapsed >= resource->orbitDuration) {
                resource->position = endPosition;
                sceneUpdateDifference(&direction, &endCenter, &endPosition);
                MT_Scene_GetDirectionAngles(&resource->rotation.x, &direction.x);
                resource->flags &= ~0x10;
                resource->flags &= ~0x8000000;
            } else {
                resource->orbitElapsed += frames;
            }
        }
    } else {
        if (resource->flags & 1) {
            RwV3d end = resource->moveEnd;
            RwV3d current = resource->position;
            RwV3d delta;
            RwV3d unit;
            RwV3d position;
            RwV3d rotation;

            if (resource->moveKind == 0) {
                f32 length;
                s32 remaining;
                sceneUpdateDifference(&delta, &end, &current);
                length = RwV3dLength((const RwV3d *)&delta.x);
                remaining = frames;
                do {
                    if (!sceneUpdateStepContinues(length, resource->moveSpeed)) {
                        resource->position = end;
                        resource->flags &= ~1;
                        break;
                    }
                    RwV3dNormalize(&unit.x, &delta.x);
                    if (remaining > 0) {
                        resource->position.x += unit.x * resource->moveSpeed;
                        resource->position.y += unit.y * resource->moveSpeed;
                        resource->position.z += unit.z * resource->moveSpeed;
                    }
                    remaining--;
                } while (remaining > 0);
                MT_Scene_ApplyResTransform(resourceData, (u8 *)&resource->position, NULL, NULL);
            } else if (resource->moveKind == 1) {
                sceneUpdateDifference(&delta, &end, &resource->moveStart);
                if (resource->moveDuration.frame == 0) {
                    resource->position = end;
                    resource->flags &= ~1;
                } else {
                    u32 ease;
                    delta.x /= (f32)resource->moveDuration.frame;
                    delta.y /= (f32)resource->moveDuration.frame;
                    delta.z /= (f32)resource->moveDuration.frame;
                    ease = resource->moveEase;
                    switch (ease) {
                    case 0:
                        resource->position.x = delta.x * (f32)resource->moveElapsed.frame + resource->moveStart.x;
                        resource->position.y = delta.y * (f32)resource->moveElapsed.frame + resource->moveStart.y;
                        resource->position.z = delta.z * (f32)resource->moveElapsed.frame + resource->moveStart.z;
                        break;
                    case 1: case 2: case 3: case 4: case 5: {
                        f32 amount = MT_Scene_SampleCurveTable(ease,
                            (f32)resource->moveDuration.frame, (f32)resource->moveElapsed.frame);
                        resource->position.x = ((resource->moveStart.x) + (delta.x) * (amount));
                        resource->position.y = ((resource->moveStart.y) + (delta.y) * (amount));
                        resource->position.z = ((resource->moveStart.z) + (delta.z) * (amount));
                        break;
                    }
                    }
                    if (resource->moveElapsed.frame >= resource->moveDuration.frame) {
                        resource->position = end;
                        resource->flags &= ~1;
                    } else {
                        resource->moveElapsed.frame += frames;
                    }
                }
                MT_Scene_ApplyResTransform(resourceData, (u8 *)&resource->position, NULL, NULL);
            } else if (resource->moveKind == 2) {
                s32 i;
                sceneUpdatePath(resource, &position, &rotation);
                if (!(resource->moveElapsed.distance < resource->moveDuration.distance)) {
                    if (resource->flags & 0x40) {
                        resource->moveElapsed.distance -= resource->moveDuration.distance;
                    } else {
                        resource->flags &= ~1;
                    }
                }
                resource->position = position;
                for (i = 0; i < frames; i++) {
                    resource->moveElapsed.distance += resource->moveSpeed;
                }
                MT_Scene_ApplyResTransform(resourceData, (u8 *)&resource->position, NULL, NULL);
                if (!(resource->flags & 8)) {
                    resource->rotation = rotation;
                    MT_Scene_ApplyResTransform(resourceData, NULL, (u8 *)&resource->rotation, NULL);
                }
            }
        }
        if (resource->flags & 4) {
            if (resource->rotationDuration == 0) {
                resource->rotation = resource->rotationEnd;
                resource->flags &= ~4;
                MT_Scene_ApplyResTransform(resourceData, NULL, (u8 *)&resource->rotation, NULL);
            } else if (resource->rotationElapsed == 0) {
                resource->rotationElapsed += frames;
            } else {
                RwV3d delta;
                RwV3d rotation;
                f32 x;
                f32 y;
                f32 z;
                f32 duration;
                MT_Scene_GetAngleDelta(&resource->rotationStart.x, &resource->rotationEnd.x, &delta.x);
                duration = (f32)resource->rotationDuration;
                x = delta.x / duration;
                y = delta.y / duration;
                z = delta.z / duration;
                switch (resource->rotationEase) {
                case 0: {
                    u32 elapsed = resource->rotationElapsed;
                    rotation.x = ((resource->rotationStart.x) + (x) * ((f32)elapsed));
                    rotation.y = ((resource->rotationStart.y) + (y) * ((f32)elapsed));
                    rotation.z = ((resource->rotationStart.z) + (z) * ((f32)elapsed));
                    break;
                }
                case 1: case 2: case 3: case 4: case 5: {
                    f32 amount = MT_Scene_SampleCurveTable(resource->rotationEase,
                        (f32)resource->rotationDuration, (f32)resource->rotationElapsed);
                    rotation.x = ((resource->rotationStart.x) + (x) * (amount));
                    rotation.y = ((resource->rotationStart.y) + (y) * (amount));
                    rotation.z = ((resource->rotationStart.z) + (z) * (amount));
                    break;
                }
                }
                resource->rotation = rotation;
                if (resource->rotationElapsed >= resource->rotationDuration) {
                    resource->rotation = resource->rotationEnd;
                    resource->flags &= ~4;
                } else {
                    resource->rotationElapsed += frames;
                }
                if (frames != 0) {
                    MT_Scene_ApplyResTransform(resourceData, NULL, (u8 *)&resource->rotation, NULL);
                }
            }
        }
        if (!(resource->flags & 0x8000000)) {
            MT_Scene_WrapAngles(&resource->rotation.x);
        }
    }

    if (resource->flags & 0x8000) {
        SceneScaleUpdate *scale = &resource->scaleUpdate;
        if (scale->duration == 0) {
            resource->scale = scale->end;
            resource->flags &= ~0x8000;
            MT_Scene_ApplyResTransform(resourceData, NULL, NULL, (u8 *)&resource->scale);
        } else {
            f32 duration = (f32)scale->duration;
            u32 elapsed = scale->elapsed;
            RwV3d result;
            result.x = operandOrderAddProduct(scale->start.x, (scale->end.x - scale->start.x) / duration, (f32)elapsed);
            result.y = operandOrderAddProduct(scale->start.y, (scale->end.y - scale->start.y) / duration, (f32)elapsed);
            result.z = operandOrderAddProduct(scale->start.z, (scale->end.z - scale->start.z) / duration, (f32)elapsed);
            resource->scale = result;
            if (scale->elapsed >= scale->duration) {
                resource->scale = scale->end;
                resource->flags &= ~0x8000;
            } else {
                scale->elapsed += frames;
            }
            if (frames != 0) {
                MT_Scene_ApplyResTransform(resourceData, NULL, NULL, (u8 *)&resource->scale);
            }
        }
    }

    if (resource->flags & 0x4000) {
        u8 alpha;
        if (resource->alphaDuration == 0) {
            alpha = resource->alphaEnd;
            resource->flags &= ~0x4000;
        } else if (resource->alphaElapsed >= resource->alphaDuration) {
            alpha = resource->alphaEnd;
            resource->flags &= ~0x4000;
        } else {
            f32 start = (f32)(u32)resource->alphaStart;
            f32 end = (f32)(u32)resource->alphaEnd;
            f32 delta = (end - start) / (f32)resource->alphaDuration;
            alpha = (u8)((start) + (delta) * ((f32)resource->alphaElapsed));
            resource->alphaElapsed += frames;
        }
        switch ((((resource)->id & 0xFFC00) >> 10)) {
        case 3: {
            SceneCharacterUpdate *character = (SceneCharacterUpdate *)resource;
            RwRGBA color = *(RwRGBA *)mdlGetColor((Model *)character->model);
            color.alpha = alpha;
            if (color.alpha < 0xFF) {
                if (resource->alphaBlend != 0) {
                    mdlSetAlphaBlend(character->model);
                } else {
                    mdlClearAlphaBlend(character->model);
                }
            } else {
                mdlClearAlphaBlend(character->model);
            }
            mdlSetColor((Model *)character->model, &color);
            break;
        }
        case 6: {
            SceneEffectUpdate *effect = (SceneEffectUpdate *)resource;
            SceneEffectColor color;
            mdlEffectGetPackedColor(effect->effect, &color.packed);
            color.rgba.alpha = alpha;
            mdlEffectSetPackedColor(effect->effect, &color.packed);
            break;
        }
        }
    }
    if (resource->flags & 0x400) {
        switch ((((resource)->id & 0xFFC00) >> 10)) {
        case 7: {
            SceneCameraUpdate *camera = (SceneCameraUpdate *)resource;
            s32 duration = resource->fovDuration;
            f32 start = resource->fovStart;
            f32 end = resource->fovEnd;
            s32 elapsed = resource->fovElapsed;
            if (duration <= 0) {
                camera->fov = end;
                resource->flags &= ~0x400;
            } else {
                f32 delta = (end - start) / (f32)duration;
                /* Retail uses the movement timer for the value, then its
                   separate FOV timer to decide when the transition ends. */
                camera->fov = ((start) + (delta) * ((f32)resource->moveElapsed.frame));
                if (elapsed >= duration) {
                    camera->fov = end;
                    resource->flags &= ~0x400;
                } else {
                    resource->fovElapsed += frames;
                }
            }
            break;
        }
        }
    }

    {
        s32 type = (((resource)->id & 0xFFC00) >> 10);
    if (type == 1) {
        SceneCharacterUpdate *character = (SceneCharacterUpdate *)resource;
        s32 i;
        for (i = 0; i < 2; i++) {
            u8 *effect = sceneUpdateAttachedEffect(character, i);
            if (effect != NULL) {
                mdlEffectCommitAndAdvance(effect);
            }
        }
    } else if (type == 3) {
        SceneCharacterUpdate *character = (SceneCharacterUpdate *)resource;
        s32 i;
        for (i = 0; i < 2; i++) {
            u8 *effect = sceneUpdateAttachedEffect(character, i);
            if (effect != NULL) {
                mdlEffectCommitAndAdvance(effect);
            }
        }
    } else if (type == 6) {
        SceneEffectUpdate *effect = (SceneEffectUpdate *)resource;
        if (effect->effect != NULL) {
            mdlEffectCommitAndAdvance(effect->effect);
        }
    }
    }
    if (resource->flags & 0x2000) {
        SceneQueuedAnimation *animation = NULL;
        u8 *model = NULL;
        switch ((((resource)->id & 0xFFC00) >> 10)) {
        case 1:
            animation = &((SceneCharacterUpdate *)resource)->animation;
            model = ((SceneCharacterUpdate *)resource)->model;
            break;
        case 2:
            animation = &((SceneObjectUpdate *)resource)->animation;
            model = ((SceneObjectUpdate *)resource)->model;
            break;
        case 3:
            animation = &((SceneCharacterUpdate *)resource)->animation;
            model = ((SceneCharacterUpdate *)resource)->model;
            break;
        }
        if (animation != NULL && model[animation->layer * 0xA4 + 0xEE] == 1) {
            sceneUpdateQueuedAnimation(resource, animation);
            resource->flags &= ~0x2000;
        }
    }
    {
        SceneFootstepUpdate *foot = &resource->footsteps;
        switch (foot->mode) {
        case 0:
            break;
        case 1:
        case 2:
            if (foot->mode == 1) {
                if (!(resource->flags & 1)) {
                    foot->mode = 0;
                    sceneUpdateFootstep(resource);
                    break;
                }
            } else if (foot->mode == 2) {
                if (!(resource->flags & 4)) {
                    foot->mode = 0;
                    sceneUpdateFootstep(resource);
                    break;
                }
            } else {
                break;
            }
            if (frames != 0) {
                if (foot->delay > 0) {
                    foot->delay--;
                } else {
                    if (foot->elapsed == 0) {
                        sceneUpdateFootstep(resource);
                    }
                    foot->elapsed++;
                    if (foot->elapsed >= foot->period) {
                        if (foot->period <= 0) {
                            foot->mode = 0;
                        } else {
                            foot->elapsed = 0;
                        }
                    }
                }
            }
            break;
        }
    }
}
/* measured: ported from m2c + P3FES idioms. Best nd 60 (obj 428B/window 432B)
   with hoisted temp_3[0]/temp_3[4] loads + sp40p base pointer. Residual:
   retail materializes func_00168ec0 arg3 (&sp40) via addiu $a2,$sp,0x40 at the
   loop top (before the D_0063B080/B088 loads); a sp40p local forces it early
   but spills to callee-saved $s3 (frame 0x70 vs 0x60). Without sp40p, nd 84
   with frame 0x60. Argument-materialization + load-position scheduling floor. */
/* measured: opt_propagation off plus block-scoped stack-address and global-load
   temporaries closes MT_Scene_GetTerrainAtPoint (normalized_diff 0). */
/* measured: baseline differs by 18 words; aggregate reference copy/direct stores leave nd9/nd50; retain propagation off. */
#pragma push
#pragma opt_propagation off
/* Search both triangles of each type-21 quad within a 100-unit vertical band; otherwise use the field terrain table. */
/* The field-terrain byte load retains base+index order: array syntax swaps the addu operands (one differing word). */
// FUN_0026BA60
s32 MT_Scene_GetTerrainAtPoint(u16 *position)
{
    typedef struct {
        u64 referenceXy;
        f32 referenceZ;
        u32 pad4c;
        u8 *firstCorner;
        u8 *secondCorner;
        u8 *thirdCorner;
    } LocalFrame;
    u8 *terrainTypes;
    LocalFrame frame;
    u64 xy;
    f32 z;
    f32 pointHeight;
    f32 secondPointHeight;
    f32 cornerHeight;
    f32 secondCornerHeight;
    s32 terrainTable;
    s32 index;
    s32 offset;
    s32 terrain;
    u8 *scene;
    u8 *quad;

    quad = (u8 *)MT_Scene_GetResListHead(0x15);
    scene = (u8 *)PTR_DAT_00762ea0;
    index = ((SceneContext *)scene)->majorId;
    offset = ((SceneContext *)scene)->minorId;
    terrainTable = D_005F08B0[index];
    if (terrainTable == 0) {
        return 0;
    }
    terrainTypes = (u8 *)terrainTable;
    terrain = terrainTypes[offset];
    for (; quad != NULL; quad = *(u8 * *)&((ResrcHeader *)quad)->next) {
        {
            u8 *referencePoint = (u8 *)&frame.referenceXy;
            xy = *(u64 *)D_0063B080;
            z = *(f32 *)D_0063B088;
            frame.referenceXy = xy;
            frame.referenceZ = z;
            frame.firstCorner = quad + 0x15C;
            frame.secondCorner = quad + 0x168;
            frame.thirdCorner = quad + 0x174;
            if ((K_FldFrame_IsPointInTriangle(position, &frame.firstCorner, referencePoint) == 1) &&
                (cornerHeight = ((RwV3d *)frame.firstCorner)->y,
                 pointHeight = ((RwV3d *)position)->y,
                 (pointHeight < (100.0f + cornerHeight))) &&
                !(pointHeight <= (cornerHeight - 100.0f))) {
                terrain = ((SceneQuadResource *)quad)->terrain;
                break;
            }
        }
        frame.firstCorner = quad + 0x168;
        frame.secondCorner = quad + 0x174;
        frame.thirdCorner = quad + 0x180;
        {
            u8 *referencePoint = (u8 *)&frame.referenceXy;
            if ((K_FldFrame_IsPointInTriangle(position, &frame.firstCorner, &frame.referenceXy) == 1) &&
                (secondCornerHeight = ((RwV3d *)frame.firstCorner)->y,
                 secondPointHeight = ((RwV3d *)position)->y,
                 (secondPointHeight < (100.0f + secondCornerHeight))) &&
                !(secondPointHeight <= (secondCornerHeight - 100.0f))) {
                terrain = ((SceneQuadResource *)quad)->terrain;
                break;
            }
        }
    }
    return terrain;
}
#pragma pop

/* Spawn the selected low-byte icon for an existing resource and report task creation success. */
// FUN_0026BC10
s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 icon)
{
    u8 *resource = MT_Scene_GetRes(resourceId);

    if (resource == NULL) return 0;
    if (resource == NULL) return 0;
    if (mtSceneIconSpawnTask(*(u16 *)resource, icon & 0xFF) != 0) goto done;
    return 0;
done:
    return 1;
}

/* Toggle the kind-specific shadow caster when a supported model resource has one. */
// FUN_0026BC90
s32 MT_Scene_SetResShadowCaster(u8 *resource, s32 enabled)
{
    s32 caster = 0;

    if (resource == NULL) return 0;
    switch (((s32)(*(u16 *)resource & 0xFFC00)) >> 10) {
    case 1:
        caster = ((ResrcRecord *)resource)->handle224;
        break;
    case 3:
        caster = ((ResrcRecord *)resource)->handle230;
        break;
    default:
        break;
    }
    if (caster == 0) return 0;
    if (enabled == 1) {
        FldShadow_SetCasterFlag(caster, 0, caster);
    } else {
        FldShadow_SetCasterFlag(caster, 1, caster);
    }
    return 1;
}

/* Resolve the resource id and toggle its supported shadow caster; return zero when absent. */
// FUN_0026BD50
s32 MT_Scene_SetResShadowCasterById(u32 resourceId, s32 enabled) {
    u8 *resource = (u8*)MT_Scene_GetRes(resourceId);

    if (resource != NULL) {
        return MT_Scene_SetResShadowCaster(resource, enabled);
    }
    return 0;
}



/* Reset the footstep state and install mode, sound, period, delay and surface selection. */
// FUN_0026BDA0
s32 MT_Scene_SetResSoundRange(u32 resourceId, s32 mode, u8 sound, s16 period, s16 delay, s16 surface)
{
    u8 *resource = MT_Scene_GetRes(resourceId);

    if (resource == NULL) return 0;
    if (resource == NULL) return 0;
    {
        u8 *footsteps = resource + 0xE8;
        memset(footsteps, 0, 0xA);
        ((SceneFootstepUpdate *)footsteps)->mode = mode;
        ((SceneFootstepUpdate *)footsteps)->sequence = 0;
        ((SceneFootstepUpdate *)footsteps)->sound = sound;
        ((SceneFootstepUpdate *)footsteps)->period = period;
        ((SceneFootstepUpdate *)footsteps)->delay = delay;
        ((SceneFootstepUpdate *)footsteps)->surface = surface;
    }
    return 1;
}

/* Make a type-7 camera the only selected camera in its resource list. */
// FUN_0026BE60
s32 MT_Scene_SetExclusiveRes(s32 resourceId)
{
    u8 *resource = MT_Scene_GetRes(resourceId);

    if (resource == NULL) return 0;
    if (resource == NULL) return 0;
    if ((((s32)(*(u16 *)resource & 0xFFC00)) >> 10) != 7) return 0;
    {
        u8 *camera = MT_Scene_GetResListHead(7);

        while (camera != NULL) {
            ((ResrcRecord *)camera)->cameraRes[0] = 0;
            camera = *(u8 * *)&((ResrcHeader *)camera)->next;
        }
        ((ResrcRecord *)resource)->cameraRes[0] = 1;
    }
    return 1;
}

/* Clear selection on every type-7 camera resource. */
// FUN_0026BF20
void MT_Scene_ClearExclusiveRes(void) {
    u8 *camera = MT_Scene_GetResListHead(7);

    while (camera != NULL) {
        ((ResrcRecord *)camera)->cameraRes[0] = 0;
        camera = *(u8 * *)&((ResrcHeader *)camera)->next;
    }
}


/* Clear a type-7 camera anchor id and anchor distance. */
// FUN_0026BF70
void MT_Scene_ClearResState(u32 resourceId)
{
    if (((s32)((u16)resourceId & 0xFFC00) >> 10) == 7) {
        u8 *resource = MT_Scene_GetRes(resourceId);
        if (resource != NULL) {
            *(u16 *)&((ResrcRecord *)resource)->cameraRes[1] = 0;
            *(u32 *)&((ResrcRecord *)resource)->slotHandle[1] = 0;
        }
    }
}

/* measured: ported from P3FES FUN_003bb450 with the P4 global addresses and
   interleaved func_003e0870 declaration. Corrected func_003e4320's return
   declaration to u8 * (verified definition); initial plain C was nd 9, object
   460B/window 464B. The initial fndiff residual rows were offset 0x70
   (axis2's retail lwc1 versus mwcc's second aggregate ld), 0x78 (retail swc1
   versus mwcc sd), and offsets 0x80/0x88/0x8C (axis3 global-load order and
   register assignment). Direct axis2-width, direct axis3-load, typed-component,
   and load-order variants all measured worse or unchanged in the initial
   probes. The final opt_propagation-off form below uses named axis2_xy/axis2_z
   field temporaries and a block-scoped axis2p, closing normalized_diff 0 with
   object 460B/window 464B; the retail six-op COP1 adda.s/msub.s chain is
   reproduced by the natural float subtraction. */
/* measured: opt_propagation off plus axis2 field temporaries and block-scoped
   pointer closes normalized_diff 0; object 460B/window 464B. */
/* measured: baseline differs by 32 words; aggregate axis copies/direct fields leave nd16/nd80; retain propagation off. */
#pragma push
#pragma opt_propagation off
// FUN_0026BFC0

void MT_Scene_OffsetPointByRotation(f32 *input, f32 distance, f32 pitch, f32 yaw, f32 roll, f32 *result) {
    typedef struct SceneMatrixLocal {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } SceneMatrixLocal;
    typedef union SceneVectorLocal {
        RwV3d value;
        struct {
            u64 xy;
            f32 z;
            u32 pad;
        } raw;
    } SceneVectorLocal;
    extern SceneVecBits D_0063B120[];
    extern f32 D_0063B128[];
    extern SceneVecBits D_0063B130[];
    extern f32 D_0063B138[];
    extern SceneVecBits D_0063B140[];
    extern f32 D_0063B148[];
    extern SceneVecBits D_0063B150[];
    extern f32 D_0063B158[];
    SceneVectorLocal axis0;
    SceneVectorLocal transformed;
    SceneVectorLocal source;
    SceneVectorLocal output;
    SceneVectorLocal axis1;
    SceneVectorLocal axis2;
    SceneVectorLocal axis3;
    SceneMatrixLocal matrix;
    SceneVectorLocal *axisPointer;
    u64 xy;
    u64 axisPair;
    f32 axisZValue;
    f32 z;

    xy = *(u64 *)D_0063B120;
    z = *(f32 *)D_0063B128;
    axis0.raw.xy = xy;
    axis0.raw.z = z;
    xy = *(u64 *)D_0063B130;
    z = *(f32 *)D_0063B138;
    axis1.raw.xy = xy;
    axis1.raw.z = z;
    axisPointer = &axis2;
    axisPair = *(u64 *)D_0063B140;
    axisZValue = *(f32 *)D_0063B148;
    axis2.raw.xy = axisPair;
    axis2.raw.z = axisZValue;
    xy = *(u64 *)D_0063B150;
    z = *(f32 *)D_0063B158;
    axis3.raw.xy = xy;
    axis3.raw.z = z;

    matrix.at.z = 1.0f;
    matrix.up.y = 1.0f;
    matrix.right.x = 1.0f;
    matrix.up.x = 0.0f;
    matrix.right.z = 0.0f;
    matrix.right.y = 0.0f;
    matrix.at.y = 0.0f;
    matrix.at.x = 0.0f;
    matrix.up.z = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.x = 0.0f;
    matrix.flags |= 0x20003;

    RwMatrixRotate(&matrix, axisPointer, yaw, 1);
    RwMatrixRotate(&matrix, &axis1.value, pitch, 1);
    RwMatrixRotate(&matrix, &axis3.value, roll, 1);
    func_003e4320(&transformed, &axis0, &matrix);
    source.value = *(RwV3d *)input;
    output.value.x = source.value.x - transformed.value.x * distance;
    output.value.y = source.value.y - transformed.value.y * distance;
    output.value.z = source.value.z - transformed.value.z * distance;
    *(RwV3d *)result = output.value;
}



/* measured: direction field temporaries plus opt_propagation off close nd 4 -> 0,
   preserving retail ld/lwc1/sd/swc1 ordering; object 376B fits the 384B window. */
/* measured: baseline differs by 5 words; aggregate direction copy/direct fields leave nd6/nd13; retain propagation off. */
/* Resolve an optional anchor resource, apply the 15-unit backward offset and rotate the requested distance. */
// FUN_0026C190
void MT_Scene_GetResAnchor(f32 *out, void *resource, f32 scale)
{
    typedef struct SceneDirectionLocal {
        u64 xy;
        f32 z;
        u32 pad;
    } SceneDirectionLocal;
    f32 base[4];
    f32 axis[4];
    f32 output[4];
    SceneDirectionLocal direction;
    f32 normalized[4];
    u8 matrixCopy[64];
    u8 matrix[64];
    u8 *handle;
    u8 *directionPointer;
    s32 *src;
    s32 *dst;
    s32 count;
    u32 first;
    u32 second;
    f32 directionZ;
    u64 directionXy;

    *(RwV3d *)base = ((ResrcHeader *)resource)->position;
    *(RwV3d *)axis = ((ResrcHeader *)resource)->rotation;
    if (*(u16 *)&((ResrcRecord *)resource)->cameraRes[1] != 0) {
        handle = MT_Scene_GetRes(*(u16 *)&((ResrcRecord *)resource)->cameraRes[1]);
        if (handle != NULL) {
            base[0] = *(f32 *)&((ResrcHeader *)handle)->position;
            base[1] = ((ResrcHeader *)handle)->position.y;
            base[2] = ((ResrcHeader *)handle)->position.z;
            scale = *(f32 *)&((ResrcRecord *)resource)->slotHandle[1];
            MT_Scene_BuildResMatrix((u32 *)matrix, base, (u32 *)axis);
            src = (s32 *)matrix;
            dst = (s32 *)matrixCopy;
            count = 8;
            do {
                first = (u32)src[0];
                second = (u32)src[1];
                src += 2;
                count -= 1;
                dst[0] = (s32)first;
                dst[1] = (s32)second;
                dst += 2;
            } while (count > 0);
            directionPointer = (u8 *)&direction;
            directionXy = *(u64 *)matrixCopy;
            directionZ = ((SceneDirectionLocal *)matrixCopy)->z;
            direction.xy = directionXy;
            direction.z = directionZ;
            RwV3dNormalize(normalized, directionPointer);
            base[0] = base[0] - 15.0f * normalized[0];
            base[2] = base[2] - 15.0f * normalized[2];
        }
    }
    MT_Scene_OffsetPointByRotation(base, scale, axis[0], axis[1], axis[2], output);
    *(RwV3d *)out = *(RwV3d *)output;
}

/* measured: opt_propagation off closes 15 load-order differences; lverify MATCH. */
/* measured: baseline differs by 12 words; aggregate camera-axis copies/direct fields leave nd16/nd32; retain propagation off. */
/* Apply resource orientation or look-at basis, screen shake and field of view to the active camera. */
/* measured: a shared typed local for the look-at flag/position accesses preserves MATCH; access-site casts alone grow this body beyond its 880-byte window. */
// FUN_0026C310
void MT_Scene_UpdateCameraResource(u8 *resource)
{
    ResrcHeader *cameraResource;
    typedef struct SceneCameraMatrix {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } SceneCameraMatrix;
    typedef struct SceneCameraLocals {
        u64 leadingPad;
        union {
            u64 raw;
            struct {
                f32 x;
                f32 y;
            } value;
        } axis;
        union {
            f32 axisZ;
            u64 scratchPad;
        } overlap;
        f32 scratch[6];
        f32 vec2[4];
        f32 vec1[4];
        f32 vec0[4];
        f32 outv[4];
    } SceneCameraLocals;
    u8 *scene;
    s32 model;
    s32 result;
    SceneCameraMatrix *matrix;
    SceneCameraLocals locals;
    f32 fc;
    f32 fb;
    f32 fa;
    f32 axisY;
    f32 axisZ;
    f32 axisX;

    scene = kwlnGetCamera();

    {
        u64 xy = *(u64 *)D_0063B160_abs;
        f32 z = ((SceneVecBits *)D_0063B160_abs)->z;
        *(u64 *)locals.vec0 = xy;
        locals.vec0[2] = z;
    }
    {
        u64 xy = *(u64 *)D_0063B170_abs;
        f32 z = ((SceneVecBits *)D_0063B170_abs)->z;
        *(u64 *)locals.vec1 = xy;
        locals.vec1[2] = z;
    }
    {
        u64 xy = *(u64 *)D_0063B180_abs;
        f32 z = ((SceneVecBits *)D_0063B180_abs)->z;
        *(u64 *)locals.vec2 = xy;
        locals.vec2[2] = z;
    }

    model = ((KwlnView *)scene)->camera;
    if (((resource == NULL) || (scene == NULL)) || (model == 0)) {
        return;
    }

    MT_Scene_GetResAnchor(locals.outv, resource, 0.0f);
    fb = locals.outv[0];
    fc = locals.outv[1];
    fa = locals.outv[2];
    *(f32 *)&((ResrcHeader *)resource)->position.x = fb;
    *(f32 *)&((ResrcHeader *)resource)->position.y = fc;
    *(f32 *)&((ResrcHeader *)resource)->position.z = fa;

    matrix = (SceneCameraMatrix *)func_003e0f80();
    {
        u64 xy = *(u64 *)D_0063B190_abs;
        f32 z = ((SceneVecBits *)D_0063B190_abs)->z;
        locals.axis.raw = xy;
        locals.overlap.axisZ = z;
    }
    if ((*(u32 *)&((ResrcHeader *)resource)->flags & 0x08000000) != 0) {
        cameraResource = (ResrcHeader *)resource;
        *(u32 *)&cameraResource->flags &= ~0x08000000;
        fb = *(f32 *)&cameraResource->position.x;
        fc = *(f32 *)&cameraResource->position.y;
        fa = *(f32 *)&cameraResource->position.z;
        matrix->pos.x = fb;
        matrix->pos.y = fc;
        matrix->pos.z = fa;
        matrix->at.x = *(f32 *)&((ResrcHeader *)resource)->rotation.x - matrix->pos.x;
        matrix->at.y = *(f32 *)&((ResrcHeader *)resource)->rotation.y - matrix->pos.y;
        matrix->at.z = *(f32 *)&((ResrcHeader *)resource)->rotation.z - matrix->pos.z;
        RwV3dNormalize(&matrix->at, &matrix->at);

        axisY = locals.axis.value.y;
        axisZ = locals.overlap.axisZ;
        matrix->right.x =
            matrix->at.y * axisZ - matrix->at.z * axisY;
        fc = matrix->at.x;
        fa = matrix->at.z;
        axisX = locals.axis.value.x;
        matrix->right.y = fa * axisX - fc * axisZ;
        matrix->right.z =
            matrix->at.x * axisY - matrix->at.y * axisX;
        RwV3dNormalize(&matrix->right, &matrix->right);

        matrix->up.x =
            matrix->at.y * matrix->right.z -
            matrix->at.z * matrix->right.y;
        matrix->up.y =
            matrix->at.z * matrix->right.x -
            matrix->at.x * matrix->right.z;
        matrix->up.z =
            matrix->at.x * matrix->right.y -
            matrix->at.y * matrix->right.x;
        RwV3dNormalize(&matrix->up, &matrix->up);
        RwMatrixUpdate(matrix);
    } else {
        matrix->at.z = 1.0f;
        matrix->up.y = 1.0f;
        matrix->right.x = 1.0f;
        matrix->up.x = 0.0f;
        matrix->right.z = 0.0f;
        matrix->right.y = 0.0f;
        matrix->at.y = 0.0f;
        matrix->at.x = 0.0f;
        matrix->up.z = 0.0f;
        matrix->pos.z = 0.0f;
        matrix->pos.y = 0.0f;
        matrix->pos.x = 0.0f;
        matrix->flags |= 0x20003;

        RwMatrixRotate(matrix, locals.vec0, *(f32 *)&((ResrcHeader *)resource)->rotation.y, 1);
        RwMatrixRotate(matrix, locals.vec1, *(f32 *)&((ResrcHeader *)resource)->rotation.x, 1);
        RwMatrixRotate(matrix, locals.vec2, *(f32 *)&((ResrcHeader *)resource)->rotation.z, 1);
        RwMatrixTranslate(matrix, locals.outv, 2);
    }

    result = MT_Scene_GetShakeOffset(&locals.scratch[4]);
    if (result == 1) {
        locals.scratch[0] = locals.scratch[4];
        locals.scratch[1] = locals.scratch[5];
        locals.scratch[2] = 0.0f;
        RwMatrixTranslate(matrix, locals.scratch, 1);
    }

    func_003e9df0((void *)model);
    func_003e9cb0((void *)model, matrix, 0);
    func_003e0f40(matrix);
    K_View_SetFov(scene, *(f32 *)&((SceneCameraUpdate *)resource)->fov);
}
#pragma pop

#pragma push
/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bb9b0 (verified MATCH there). */
/* Removing this loses FUN_003bb9b0 (MATCH nd0 -> MISMATCH nd143) - measured W161. */
/* measured: baseline differs by 46 words; component-pointer traversal leaves nd144; retain hoisting. */
#pragma opt_loop_invariants on

/* Normalize each degree-valued component into the half-open interval [0, 360). */
// FUN_0026C680
void MT_Scene_WrapAngles(f32 *angles)
{
    s32 axisIndex;
    f32 wrapped [4];

    wrapped[0] = *angles;
    wrapped[1] = angles[1];
    wrapped[2] = angles[2];
    for (axisIndex = 0; axisIndex < 3; axisIndex = axisIndex + 1) {
        while (wrapped[axisIndex] >= 360.0f) {
            wrapped[axisIndex] = wrapped[axisIndex] - 360.0f;
        }
        while (wrapped[axisIndex] < 0.0f) {
            wrapped[axisIndex] = wrapped[axisIndex] + 360.0f;
        }
    }

    *angles = wrapped[0];
    angles[1] = wrapped[1];
    angles[2] = wrapped[2];
    return;
}



// FUN_0026C740
void MT_Scene_WrapObjectAngles(s32 object)
{
    (MT_Scene_WrapAngles)(&((ResrcHeader *)object)->rotation.x);
}


// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbaa0 (verified MATCH
// there). 003bb9b0 -> MT_Scene_WrapAngles.

/* opt_loop_invariants on: measured off nd 95, object 236/240; on nd 0, object 228/240 (MATCH); retain on. */
/* measured: baseline differs by 33 words; component-pointer traversal leaves nd92; retain hoisting. */

/* Return the shortest signed degree difference on each axis, keeping positive 180 unchanged. */
// FUN_0026C770
void MT_Scene_GetAngleDelta(f32 *start, f32 *end, f32 *output)
{
    s32 axisIndex;
    f32 delta[4];
    f32 adjusted[4];
    const f32 wrap = 360.0f;
    const f32 limit = 180.0f;

    delta[0] = end[0] - start[0];
    delta[1] = end[1] - start[1];
    delta[2] = end[2] - start[2];
    MT_Scene_WrapAngles(delta);
    adjusted[0] = delta[0];
    adjusted[1] = delta[1];
    adjusted[2] = delta[2];
    for (axisIndex = 0; axisIndex < 3; axisIndex = axisIndex + 1) {
        if (adjusted[axisIndex] <= limit) {
            continue;
        }
        adjusted[axisIndex] = -(wrap - adjusted[axisIndex]);
    }
    output[0] = adjusted[0];
    output[1] = adjusted[1];
    output[2] = adjusted[2];
}
#pragma pop


// The volatile-qualified staging of the D_0063b1a0/D_0063b1a8 header into the
// local SceneVecBits is carried from the P3 donor (FUN_003bbb90), which is
// MATCH nd0 there with the same construct. measured in P4: removing the four
// volatile qualifiers regressed 0026c860 MATCH nd0 -> MISMATCH nd10 (object
// 256/256 both ways); retained to reproduce retail's load/store sequence.


/* Project a normalized direction onto the horizontal plane and return its signed yaw. */
// FUN_0026C860
void MT_Scene_GetDirectionYaw(const f32 *direction, f32 *angles)
{
    u32 angleBits;
    f32 heading;
    u64 sourceXy;
    f32 sourceZ;
    SceneVecBits source;
    f32 normalized[4];

    sourceXy = ((volatile SceneVecBits *)D_0063b1a0)->xy;
    sourceZ = *(volatile f32 *)D_0063b1a8;
    *(volatile u64 *)&source.xy = sourceXy;
    *(volatile f32 *)&source.z = sourceZ;

    heading = RwV3dNormalize(normalized, direction);
    if (heading == 0.0f) {
        angles[0] = 0.0f;
        angles[1] = 0.0f;
        angles[2] = 0.0f;
    }
    else {
        normalized[1] = 0.0f;
        angleBits = fptodp(normalized[0] * ((f32 *)&source.xy)[0] +
                              normalized[1] * ((f32 *)&source.xy)[1] +
                              normalized[2] * source.z);
        angleBits = func_0044b8d8(angleBits);
        heading = fGpffff8428 * dptofp(angleBits);
        if (normalized[0] < 0.0f) {
            heading = heading * -1.0f;
        }
        angles[1] = heading;
        angles[0] = 0.0f;
        angles[2] = 0.0f;
    }
}



/* Evaluate a cubic Bezier with four independent control coordinates per axis. */
// FUN_0026C960
void MT_Scene_EvalCubicBezier(f32 t, f32 *x, f32 *y, f32 *z, f32 *outX,
                   f32 *outY, f32 *outZ)
{
    f32 oneMinus = 1.0f - t;
    f32 oneMinusSquared = oneMinus * oneMinus;
    f32 w0;
    f32 w1;
    f32 w2;
    f32 w3;
    f32 tSquared;
    f32 rx;

    RwV3d result;
    w0 = oneMinus * oneMinusSquared;
    rx = x[0] * w0;
    w1 = t * (3.0f * oneMinusSquared);
    rx += x[1] * w1;
    tSquared = t * t;
    w2 = (3.0f * oneMinus) * tSquared;
    rx += x[2] * w2;
    w3 = t * tSquared;
    rx += x[3] * w3;
    result.x = rx;
    rx = y[0] * w0;
    rx += y[1] * w1;
    rx += y[2] * w2;
    rx += y[3] * w3;
    result.y = rx;
    rx = z[0] * w0;
    rx += z[1] * w1;
    rx += z[2] * w2;
    rx += z[3] * w3;
    result.z = rx;

    *outX = result.x;
    *outY = result.y;
    *outZ = result.z;
}


/* measured: branch-local control-point counters retain the 400-byte MATCH under baseline lifetimes. */

/* Sample a packed cubic path; neighboring segments share their endpoint and use a 0x24-byte stride. */
// FUN_0026CA10
void MT_Scene_SampleCurve(char *path, f32 time, f32 *output)
{
    char segmentCount;
    s32 segmentIndex;
    f32 segmentDuration;
    f32 controlX [4];
    f32 controlY [4];
    f32 controlZ [4];

    segmentCount = *path;
    if ('\0' < segmentCount) {
        if (!(time < 1.0f)) {
            s32 controlIndex;
            controlIndex = 0;
            segmentIndex = segmentCount - 1;
            path += segmentIndex * 0x24;
            for (; controlIndex < 4; controlIndex = controlIndex + 1) {
                controlX[controlIndex] = ((ScenePath *)path)->points[controlIndex].x;
                controlY[controlIndex] = ((ScenePath *)path)->points[controlIndex].y;
                controlZ[controlIndex] = ((ScenePath *)path)->points[controlIndex].z;
            }
            MT_Scene_EvalCubicBezier(1.0f, controlX, controlY, controlZ, output, output + 1, output + 2);
        }
        else {
            s32 controlIndex;
            segmentDuration = 1.0f / (f32)(s32)segmentCount;
            segmentIndex = (s32)(time / segmentDuration);
            controlIndex = 0;
            path += segmentIndex * 0x24;
            for (; controlIndex < 4; controlIndex = controlIndex + 1) {
                controlX[controlIndex] = ((ScenePath *)path)->points[controlIndex].x;
                controlY[controlIndex] = ((ScenePath *)path)->points[controlIndex].y;
                controlZ[controlIndex] = ((ScenePath *)path)->points[controlIndex].z;
            }
            while (time > segmentDuration) {
                time = time - segmentDuration;
            }
            MT_Scene_EvalCubicBezier(time / segmentDuration, controlX, controlY, controlZ, output, output + 1, output + 2);
        }
    }
    return;
}



/* Construct a one-segment easing curve from the selected four-float table entry. */
/* Retain byte-addressed scratch storage: the sampler output begins at +0x130 inside the original 0x138-byte stack allocation. */
// FUN_0026CBA0
f32 MT_Scene_SampleCurveTable(u32 kind, f32 duration, f32 elapsed)
{
    typedef struct SceneCurveScratch {
        u8 path[0x130];
        f32 sampleX;
        f32 sampleY;
    } SceneCurveScratch;
    u8 *controlPoints;
    u8 pathBuffer[0x138];

    if (kind >= 6) {
        kAssertFail(D_0063B090, 0xA24);
    }
    if (duration == 0.0f) {
        elapsed = 1.0f;
    }
    else {
        elapsed = elapsed / duration;
    }
    pathBuffer[0] = 1;
    *(u32 *)&((ScenePath *)pathBuffer)->points[0].x = 0;
    *(u32 *)&((ScenePath *)pathBuffer)->points[0].y = 0;
    *(u32 *)&((ScenePath *)pathBuffer)->points[0].z = 0;
    controlPoints = resrcMngGetTableEntry(kind);
    ((ScenePath *)pathBuffer)->points[1].x = ((f32 *)controlPoints)[0];
    ((ScenePath *)pathBuffer)->points[1].y = ((f32 *)controlPoints)[2];
    *(u32 *)&((ScenePath *)pathBuffer)->points[1].z = 0;
    ((ScenePath *)pathBuffer)->points[2].x = ((f32 *)controlPoints)[1];
    ((ScenePath *)pathBuffer)->points[2].y = ((f32 *)controlPoints)[3];
    *(u32 *)&((ScenePath *)pathBuffer)->points[2].z = 0;
    *(u32 *)&((ScenePath *)pathBuffer)->points[3].x = 0x3F800000;
    *(u32 *)&((ScenePath *)pathBuffer)->points[3].y = 0x3F800000;
    *(u32 *)&((ScenePath *)pathBuffer)->points[3].z = 0;
    MT_Scene_SampleCurve((char *)pathBuffer, elapsed, (f32 *)(pathBuffer + 0x130));
    return ((SceneCurveScratch *)pathBuffer)->sampleY * duration;
}
/* Evaluate two positions on a cubic segment and return their straight-line distance. */
// FUN_0026CCA0
f32 MT_Scene_GetCurveSegmentLength(f32 firstTime, f32 secondTime, f32 *controlX, f32 *controlY,
                    f32 *controlZ, f32 *firstPoint, f32 *secondPoint)
{
    RwV3d delta;
    f32 firstX;
    f32 secondX;
    f32 firstY;
    f32 secondY;
    f32 firstZ;
    f32 secondZ;
    f32 length;

    MT_Scene_EvalCubicBezier(firstTime, controlX, controlY, controlZ, &firstX, &firstY, &firstZ);
    MT_Scene_EvalCubicBezier(secondTime, controlX, controlY, controlZ, &secondX, &secondY, &secondZ);
    delta.x = secondX - firstX;
    delta.y = secondY - firstY;
    delta.z = secondZ - firstZ;
    length = RwV3dLength(&delta);
    *firstPoint = firstX;
    firstPoint[1] = firstY;
    firstPoint[2] = firstZ;
    *secondPoint = secondX;
    secondPoint[1] = secondY;
    secondPoint[2] = secondZ;
    return length;
}



/* Approximate path length with twenty equal-parameter samples per cubic segment. */
// FUN_0026CDB0
f32 MT_Scene_GetCurveLength(char *path)
{
    s32 segmentIndex;
    s32 sampleIndex;
    f32 sampleLength;
    f32 totalLength;
    f32 segmentLength;
    f32 scale;
    f32 firstPoint [4];
    f32 secondPoint [4];
    f32 controlX [4];
    f32 controlY [4];
    f32 controlZ [4];

    totalLength = 0.0f;
    for (segmentIndex = 0; segmentIndex < *path; segmentIndex = segmentIndex + 1) {
        {
            char *curve;
            s32 copyIndex;

            copyIndex = 0;
            curve = path + segmentIndex * 0x24;
            for (; copyIndex < 4; copyIndex = copyIndex + 1) {
                controlX[copyIndex] = ((ScenePath *)curve)->points[copyIndex].x;
                controlY[copyIndex] = ((ScenePath *)curve)->points[copyIndex].y;
                controlZ[copyIndex] = ((ScenePath *)curve)->points[copyIndex].z;
            }
        }

        segmentLength = 0.0f;
        for (sampleIndex = 0; sampleIndex < 0x14; sampleIndex = sampleIndex + 1) {
            sampleLength = (f32)sampleIndex;
            scale = D_007614c0;
            sampleLength = sampleLength * scale;
            sampleLength = MT_Scene_GetCurveSegmentLength(sampleLength, (f32)(sampleIndex + 1) * scale,
                                  controlX, controlY, controlZ, firstPoint, secondPoint);
            segmentLength = segmentLength + sampleLength;
        }
        totalLength = totalLength + segmentLength;
    }
    return totalLength;
}



/* measured: removing this pragma takes MT_Scene_GetShakeOffset nd 0 -> nd 17 (object 60 -> 56, window 64). */
#pragma optimization_level 1

/* Read the two adjacent global shake outputs while shake state is enabled. */
// FUN_0026D400
u32 MT_Scene_GetShakeOffset(f32* offset)
{
    extern f32 D_00881500[4];
    if (*(u16*)&D_00764580 == 0)
    {
        return 0;
    }

    offset[0] = D_00881500[0];
    offset[1] = D_00881500[1];
    return 1;
}
#pragma optimization_level 2
/* measured: b210 -O2, 824 executable bytes / 832B window; all 28
   relocations resolve exactly, including the 0.01f literal and 0.6f pair.
   Expiry disables first; the following disabled update clears the outputs. */
// FUN_0026D440
void MT_Scene_UpdateShake(void)
{
    extern u32 RpRandom(void);
    extern f32 fabsf(f32);
    extern f32 D_00881500[4];
    extern s32 D_00881504[], D_00881508[], D_0088150C[];
    f32 delta[2];
    f32 initial[2] = {0.6f, 0.6f};
    s32 i;
    f32 *output;
    f32 step;
    s32 timing;

    if (*(u16 *)&D_00764580 == 0) {
        D_00881500[0] = 0.0f;
        D_00881504[0] = 0;
        D_00881508[0] = 0;
        D_0088150C[0] = 0;
        return;
    }
    if (*(s16 *)&D_00764584 == 0) {
        *(u16 *)&D_00764580 = 0;
        return;
    }
    delta[0] = 0.01f * (f32)(u32)*(u16 *)&D_00764588;
    delta[1] = 0.01f * (f32)(u32)*(u16 *)&D_0076458C;
    for (i = 0; i < 2; i++) {
        f32 d = delta[i];
        if (d != 0.0f) {
            f32 random = (f32)RpRandom() / 2147483648.0f;
            f32 amplitude = delta[i];
            step = 0.5f * amplitude + 0.5f * (amplitude * random);
            output = D_00881500 + i;
            if (!(fabsf(*output) < delta[i] * initial[i])) {
                if (*output <= 0.0f) *output += step;
                else *output -= step;
            } else {
                *output = 0.0f + *output + 2.0f * (step * ((f32)RpRandom() / 2147483648.0f - 0.5f));
            }
            if (*output < -d) *output = -d;
            if (!(*output <= d)) *output = d;
        }
    }
    timing = *(s16 *)&D_00764584;
    if (timing > 0) {
        s32 divisor = timing + 5;
        s32 value = *(u16 *)&D_00764588;
        *(u16 *)&D_00764588 = value - (u16)((s32)value / divisor);
        value = *(u16 *)&D_0076458C;
        *(u16 *)&D_0076458C = value - (u16)((s32)value / divisor);
    }
    if (timing > 0) *(s16 *)&D_00764584 = *(s16 *)&D_00764584 - 1;
}
/* Enable shake with a finite duration or -1 for indefinite duration; derive separate horizontal and vertical amplitudes. */
// FUN_0026D780
void MT_Scene_StartShake(s32 first, s32 second)
{
    if (second == 0)
    {
        *(u16*)&D_00764580 = 0;
    }
    else
    {
        *(u16*)&D_00764580 = 1;
        if (first == 0)
        {
            *(s16*)&D_00764584 = -1;
        }
        else
        {
            *(u16*)&D_00764584 = (s16)first;
        }
        *(u16*)&D_0076458C = second * 10;
        *(u16*)&D_00764588 = (*(u16*)&D_0076458C << 2) / 10;
        mdlEffectSeqStart(first, (s16)second);
    }
}
/* Disable shake and stop its associated effect sequence. */
// FUN_0026D810
void MT_Scene_StopShake(void)
{
    *(u16 *)&D_00764580 = 0;
    mdlEffectSeqStop();
    return;
}
