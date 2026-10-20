#include "btl_unit_internal.h"
#include "datCalc_internal.h"
#include "btl_motion_internal.h"
/* Source unit: src/Battle/btlCamera_001bc3a0.c */
#include "include_asm.h"
#include "btl_action_internal.h"
#include "effect_instance_internal.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_effect_internal.h"
#include "member_access.h"

typedef struct P4Vec4_001EC2B0 { f32 x, y, z, w; } P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 { P4Vec4_001EC2B0 quat; } P4Vec4Holder_001EC2B0;
typedef struct P4CameraFrame { RwV3d pos; P4Vec4Holder_001EC2B0 rot; } P4CameraFrame;
typedef struct P4CameraBlend {
    P4Vec4Holder_001EC2B0 first, second;
    f32 scalar;
    s32 flag;
} P4CameraBlend;
typedef struct P4CameraVec2 { f32 x, y; } P4CameraVec2;


extern f32 fabsf(f32 x);
extern RwV3d D_0060A0F0;
RwV3d* RtQuatTransformVectors(RwV3d* vectorsOut, const RwV3d* vectorsIn,
                     s32 numPoints, const RtQuat* quat);

typedef struct BtlCamera BtlCamera;

s16 btlUnitGetMotionState(BtlUnit* unit);
s16 btlUnitModelAnimFrame(BtlUnit* unit);

typedef struct BtlUnitStateWork BtlUnitStateWork;

typedef struct BtlCameraPacketSetState
{
    BtlAction* action; // 0x00
    u16 state;         // 0x04
} BtlCameraPacketSetState;

void btlCameraSetState(s32 state, BtlAction* action, u32 clearUnitFlags);


BtlPacket* btlPacketAlloc(u32 packetType, s32 workSize);
u32 btlCameraUpdateSetStatePacket(void* work);

void btlCameraBuildLookAtFrame(float *matrix,float *target,float *eye,float *up);
void RtQuatConvertFromMatrix(void* out, void* in);

u16 btlCameraSelectMode(void* camera);
void btlCameraFrameActionDegrees(u8* camera, f32 nearDegrees, f32 farDegrees);
void btlCameraFrameTargetPose(u8* camera, s32 first);
void btlCameraFrameFlagged(void* camera, s32 first);
void btlCameraFrameRandomOrbit(void* camera, u32 unused);
void btlCameraSetLimitFrame(u8* camera, f32 suppliedLimit, s32 reverse, s32 preserveSide);
extern u8 D_005FE1D0[];
extern u32 datCalcRandomBelow(u32 limit);
void FUN_0043f9c8(void* memory, s32 value, u32 size);
u32 btlCameraIsEnabled(void *camera);

typedef struct RwMatrix RwMatrix;
struct RwMatrix
{
    RwV3d right;    // 0x00
    u32 flags;      // 0x0c
    RwV3d up;       // 0x10
    u32 pad1;       // 0x1c
    RwV3d at;       // 0x20
    u32 pad2;       // 0x2c
    RwV3d pos;      // 0x30
    u32 pad3;       // 0x3c
};
extern RwV3d D_0060A0E0;
extern f32 DAT_00761200;
extern f32 DAT_0076112c;
extern f32 DAT_00761278;
f32 tanf(f32 x);
f32 RwV3dNormalize(RwV3d* out, const RwV3d* in);
RwMatrix* RwMatrixRotate(RwMatrix* matrix, const RwV3d* axis, f32 angle, s32 mode);
RwV3d* func_003e4320(RwV3d* out, const RwV3d* in, const RwMatrix* matrix);
void btlCameraLookAtQuat(void* out, const void* first, const void* second, const void* config);
void btlCameraSetupActionGeometry(u8* action, u8* first, f32* second, f32 radius, u16 mode);

static inline void cameraApplyVisibility(f32 radius, u8 *camera, u16 mode)
{
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, radius, mode);
}
extern f32 btlUnitGetGroupBounds(u32, u32, void*, f32*, void*, u32);
extern void btlUnitGetGridSphereCenter(BtlUnit*, RwV3d*);
extern f32 tanf(f32 x);
extern void btlUnitGetSphereWorldCenter(void *unit, void *dst);
extern void btlUnitSetChildValue(BtlUnitStateWork *work, u16 value);
extern void btlUnitGetAnimBoundsWorldCenter(BtlUnit *unit, RwV3d *outPosition);
extern RwV3d* RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count,
                          const RtQuat *quat);
extern void btlMainCurveReset(u16 *curve, f32 *pose);
void btlMainCurveSetPoses(u16* curve, f32* firstPose, f32* lastPose, u16 mode);
void btlCameraCopyPose(f32 *destination, f32 *source);
void btlCameraFrameSlerpTarget(u8 *camera, f32 *out);
void btlCameraStartEffect(u8* camera, void* script, s32 options);
extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0* right, P4Vec4Holder_001EC2B0* left);
extern void func_003dcc70(f32* first, f32* second, void* result);
extern f32 func_003e41e0(f32* out, f32* in);
extern f32 fGpffff8104;
extern f32 fGpffff8184;
extern f32 fGpffff811c;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;
extern f32 fGpffff80e8;
extern f32 fGpffff80d8[2];
extern f32 fGpffff8110;
extern f32 fGpffff8094;
extern f32 D_0076122C;
extern f32 D_00761278;
extern RwV3d D_0060A100;
extern void btlTargetBlendVectors(void* rotation, void* first, void* second);
typedef struct BtlCameraSlerpResult
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
} BtlCameraSlerpResult;
static inline u32 cd600Add(u32 flagOffset, u32 tableAddr)
{
    return flagOffset + tableAddr;
}
extern u8 D_005FC900[];
extern u8 D_005FDE00[];
void btlCameraSetDuration(u8* work, f32 value);

void btlCameraFrameOrbit(void *camera, float angle, float distanceScale, float heightScale, float minimumDistance);

typedef struct F32Vec4
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} F32Vec4;

extern f32 DAT_00761254;
extern f32 DAT_00761188;
extern f32 DAT_00761258;
extern u8 *iGpffffb3ac;
extern void btlCameraEnterRandomFrame(void *value, s32 option);
extern void btlCameraUpdateEffectList(void);
void btlCameraApplyPreset(u8* camera, f32 duration, s32 initialize);
extern f32 fGpffff80e8;
extern f32 fGpffff8180;
extern f32 fGpffff8170;
extern void btlMainApplyUnitBaseColors();
extern u8 *btlActionGetQueueSecond(void);
extern u32 btlCameraBuildFramePair(u8 *, s32, s32, P4CameraFrame *, P4CameraFrame *);


typedef struct BtlCameraKeyFrame
{
    RwV3d pos;  // 0x00
    RtQuat rot; // 0x0c
} BtlCameraKeyFrame;
void btlMainCurveSetFourPoses(void* camera, void* first, void* second, void* third, void* fourth, u16 mode);



/* Test the square arena limit (|X| or |Z| > 1500); optionally project the pose forward to the boundary. */
// FUN_001BC3A0
u32 btlCameraClampOffsetToLimit(float *pose,float *clampedPosition)
{
  f32 direction[3];
  f32 excess;
  f32 magnitude;
  u32 outside;

  outside = 0;
  magnitude = fabsf(pose[0]);
  if (magnitude > 1500) {
    if (clampedPosition != 0) {
      excess = magnitude - 1500;
      RtQuatTransformVectors((RwV3d*)direction,&D_0060A0F0,1,(RtQuat*)(pose + 3));
      if (direction[0] != 0.0f) {
        magnitude = fabsf(direction[0]);
        excess = excess / magnitude;
        direction[0] = direction[0] * excess;
        direction[1] = direction[1] * excess;
        direction[2] = direction[2] * excess;
        clampedPosition[0] = pose[0] + direction[0];
        clampedPosition[1] = pose[1] + direction[1];
        clampedPosition[2] = pose[2] + direction[2];
      }
    }
    outside = 1;
  }
  magnitude = fabsf(pose[2]);
  if (magnitude > 1500) {
    if (clampedPosition != 0) {
      excess = magnitude - 1500;
      RtQuatTransformVectors((RwV3d*)direction,&D_0060A0F0,1,(RtQuat*)(pose + 3));
      if (direction[2] != 0.0f) {
        magnitude = fabsf(direction[2]);
        excess = excess / magnitude;
        direction[0] = direction[0] * excess;
        direction[1] = direction[1] * excess;
        direction[2] = direction[2] * excess;
        clampedPosition[0] = pose[0] + direction[0];
        clampedPosition[1] = pose[1] + direction[1];
        clampedPosition[2] = pose[2] + direction[2];
      }
    }
    outside = 1;
  }
  return outside;
}



/* Report completion only for a visible unit with an active model animation. */
// FUN_001BC560
s32 btlCameraUnitAnimFinished(BtlCamera* camera, u32 unit)
{
  BtlUnit *unitPtr;
  s32 result;
  s16 frameCount;
  s16 animFrame;

  unitPtr = (BtlUnit *)(uintptr_t)unit;
  if (unitPtr == 0) {
    result = 0;
  }
  else if (unitPtr->cols[0].alpha == '\0') {
    result = 0;
  }
  else if ((((BtlUnit *)(u8 *)unitPtr)->flags2 & 2) == 0) {
    result = 0;
  }
  else {
    frameCount = btlUnitMotionFrames(
      (u8 *)unitPtr, (u16)(s32)btlUnitGetMotionState(unitPtr), 1.0f);
    animFrame = btlUnitModelAnimFrame(unitPtr);
    result = animFrame < frameCount;
    result = result ^ 1;
  }
  return result;
}



/* Read bit 0x4000 of the active action skill record. The skill-table address carrier is retained while its flags are typed. */
// FUN_001BC630
s32 btlCameraStateRecordFlag(u8 *camera)
{
    u32 offset;

    offset = (u32)((BtlAction *)(u8 *)((BtlCamera *)camera)->action)->unk_6e * 4;
    offset += (u32)iGpffffb3bc;
    return (s32)((((BtlSkillFlags *)offset)->flags & 0x4000) != 0);
}
/* measured: no COP1 here despite the old "accumulator-chain floor" archive.
   The state-history shift is retail's dead `while ((n = i) == 0)` (beq to the
   body); the u16 counter's fresh andi on the store side needs the fused
   `[i--]` subscript (raw byte-offset forms CSE it with n, nd185), and the
   pointer-plus-index spelling with the constant last gives addu base,index. */
/* Select the encounter-specific camera callback, reset timing, and optionally clear unit visibility flags. */
// FUN_001BC660
void btlCameraSetState(s32 state, BtlAction* action, u32 clearUnitFlags)
{
    extern u8 *btlEncounterGetRecord(s32 index);
    extern void btlCameraClearAllUnitFlags(void);
    extern u8 D_005F74C0[];
    u8 *entry;
    u8 *camera;
    u16 historyIndex;
    s32 stateId;
    s32 previousIndex;
    void (*callback)(u8 *);

    if ((entry = btlEncounterGetRecord(state)) == NULL) {
        entry = &D_005F74C0[(u16)state * 0x14];
    }
    stateId = (u16)state;
    if (((BtlBattleState *)iGpffffb3ac)->camera.state != stateId || ((BtlCameraStateRecord *)entry)->forceReset != 0) {
        historyIndex = 2;
        while ((previousIndex = historyIndex) == 0) {
            camera = iGpffffb3ac;
            *((u16 *)camera + historyIndex-- + 0x84) = *((u16 *)camera + previousIndex + 0x83);
        }
        camera = iGpffffb3ac;
        ((BtlBattleState *)camera)->camera.stateHistory[0] = ((BtlBattleState *)camera)->camera.state;
        camera = iGpffffb3ac;
        if (((BtlBattleState *)camera)->camera.state == stateId) {
            ((BtlBattleState *)camera)->camera.repeatedStateCount += 1;
        } else {
            ((BtlBattleState *)camera)->camera.repeatedStateCount = 0;
        }
        ((BtlBattleState *)iGpffffb3ac)->camera.state = state;
        ((BtlBattleState *)iGpffffb3ac)->camera.frame = 0;
        ((BtlBattleState *)iGpffffb3ac)->camera.delay = 0;
        ((BtlBattleState *)iGpffffb3ac)->camera.action = action;
        if (((BtlCameraStateRecord *)entry)->updateRange != 0) {
            camera = iGpffffb3ac;
            ((BtlBattleState *)camera)->camera.flags |= 2;
        } else {
            camera = iGpffffb3ac;
            ((BtlBattleState *)camera)->camera.flags &= ~2;
        }
        if (clearUnitFlags != 0) {
            btlCameraClearAllUnitFlags();
        }
        callback = *(void (**)(u8 *))entry;
        if (callback != NULL) {
            callback((u8 *)&((BtlBattleState *)iGpffffb3ac)->camera);
        }
    }
}
// FUN_001BC7F0
u16 btlCameraGetState(void)
{
    return ((BtlBattleState *)iGpffffb3ac)->camera.state;
}
/* Clear camera-held references whose action ID matches the released action. */
// FUN_001BC800
void btlCameraReleaseActionRefs(u8 *releasedAction)
{
    u8 *camera;
    u8 *action;
    u8 *actionSlot;
    u8 *stateAction;
    u8 *stateActionSlot;
    u8 *stateAction2;
    u8 *stateActionSlot2;
    u16 state;
    BtlAction *released = (BtlAction *)releasedAction;

    camera = iGpffffb3ac;
    actionSlot = (u8 *)&((BtlBattleState *)camera)->camera.action;
    action = *(u8 **)actionSlot;
    if (action != NULL) {
        if ((s32)((BtlAction *)action)->id == (s32)((BtlAction *)releasedAction)->id) {
            *(u8 **)actionSlot = NULL;
        }
        camera = iGpffffb3ac;
        state = ((BtlBattleState *)camera)->camera.state;
        switch (state) {
        case 13:
            stateActionSlot = (u8 *)&((BtlBattleState *)camera)->camera.presetTarget;
            stateAction = *(u8 **)stateActionSlot;
            if (stateAction != NULL &&
                
                (s32)((BtlAction *)stateAction)->id == (s32)released->id) {
                *(u8 **)stateActionSlot = NULL;
                return;
            }
            break;
        case 20:
        case 16:
        case 18:
        case 19:
        case 42:
            stateActionSlot2 = (u8 *)&((BtlBattleState *)camera)->camera.effectTarget;
            stateAction2 = *(u8 **)stateActionSlot2;
            if (stateAction2 != NULL &&
                
                (s32)((BtlAction *)stateAction2)->id == (s32)released->id) {
                *(u8 **)stateActionSlot2 = NULL;
            }
            break;
        default:
            break;
        }
    }
}
/* Apply a queued camera-state change and finish the packet. */
// FUN_001BC8E0
u32 btlCameraUpdateSetStatePacket(void* work)
{
    BtlCameraPacketSetState* packet;

    packet = (BtlCameraPacketSetState*)work;

    btlCameraSetState(packet->state, packet->action, 1);

    return 1;
}



/* Allocate a state-change packet carrying the action and 16-bit state. */
// FUN_001BC920
BtlPacket* btlCameraCreateSetStatePacket(BtlAction* action, u16 state)
{
    BtlPacket* packet;
    BtlCameraPacketSetState* work;

    packet = btlPacketAlloc(0x200, 8);

    packet->updateFunc = btlCameraUpdateSetStatePacket;

    work = (BtlCameraPacketSetState*)packet->workData;

    work->action = action;
    work->state = state;

    return packet;
}



/* Copy position and all four quaternion lanes of a contiguous camera pose. */
// FUN_001BD560
void btlCameraCopyPose(f32 *destination, f32 *source)
{
    ((BtlCameraPose *)destination)->pos = ((BtlCameraPose *)source)->pos;
    ((BtlCameraPose *)destination)->rot = ((BtlCameraPose *)source)->rot;
}
/* Copy a complete pose into the camera snapshot. */
// FUN_001BD5A0
void btlCameraCopyPoseSnapshot(f32 *destination, f32 *source)
{
    ((BtlCameraPose *)destination)->pos = ((BtlCameraPose *)source)->pos;
    ((BtlCameraPose *)destination)->rot = ((BtlCameraPose *)source)->rot;
}
/* Copy a complete pose into the camera target. */
// FUN_001BD5E0
void btlCameraCopyPoseTarget(f32 *destination, f32 *source)
{
    ((BtlCameraPose *)destination)->pos = ((BtlCameraPose *)source)->pos;
    ((BtlCameraPose *)destination)->rot = ((BtlCameraPose *)source)->rot;
}

/* Build an orthonormal look-at matrix from eye, target, and supplied up vector. Matrix fields retain the existing 16-byte row stride. */
// FUN_001BD620
void btlCameraBuildLookAtFrame(float *matrix,float *target,float *eye,float *up)
{
  extern float RwV3dNormalize();
  RwV3d forward;
  RwV3d right;
  RwV3d correctedUp;

  ((RwMatrix *)matrix)->pos = *(RwV3d*)eye;
  forward.x = *target - *eye;
  forward.y = target[1] - eye[1];
  forward.z = target[2] - eye[2];
  RwV3dNormalize(&forward,&forward);
  ((RwMatrix *)matrix)->at = forward;
  right.x = up[1] * forward.z - up[2] * forward.y;
  right.y = up[2] * forward.x - *up * forward.z;
  right.z = *up * forward.y - up[1] * forward.x;
  RwV3dNormalize(&right,&right);
  ((RwMatrix *)matrix)->right = right;
  correctedUp.x = forward.y * right.z - forward.z * right.y;
  correctedUp.y = forward.z * right.x - forward.x * right.z;
  correctedUp.z = forward.x * right.y - forward.y * right.x;
  ((RwMatrix *)matrix)->up = correctedUp;
  return;
}



/* Build the look-at basis and convert its matrix to a quaternion. */
// FUN_001BD780
void btlCameraLookAtQuat(void* out, const void* first, const void* second, const void* config)
{
  u8 matrix[64];

  btlCameraBuildLookAtFrame((float*)matrix, (float*)second, (float*)first,
               (float*)config);
  RtQuatConvertFromMatrix(out, matrix);
}



/* Exact P4 action framing from the P3 FES 04d95e2 structural donor,
   with P4 distance/angle branches and typed complete poses.
   See docs/probe_archive/Action_camera_001be050_20260920.md. */
/* Frame the acting unit while limiting angular change using near/far degree thresholds. */
// FUN_001BE050
void btlCameraFrameActionDegrees(u8 *camera, f32 nearDegrees, f32 farDegrees)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    typedef RwV3d Vec3;
    typedef struct { f32 x, y; } Vec2;
    typedef P4Vec4Holder_001EC2B0 Quat;
    typedef struct { Vec3 pos; Quat rot; } Pose;
    typedef struct { Quat first, second; f32 scalar; s32 flag; } Blend;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, Vec3 *);
    extern f32 RwV3dNormalize(Vec3 *, const Vec3 *);
    extern f32 RwV3dLength(const Vec3 *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern void btlCameraSetDuration(u8 *, f32);
    extern f32 tanf(f32);
    extern u32 btlCameraClampOffsetToLimit(f32 *, f32 *);
    extern void btlAct_ENEMY_ALL(u8 *);
    extern s32 CrossfadeRequest(s16);
    extern RwV3d D_0060A100;
    extern f32 fGpffff807c, fGpffff8110, fGpffff8118;
    extern f32 fGpffff8128, fGpffff8140, fGpffff816c, fGpffff8180;
    Vec3 candidate;
    Vec3 delta;
    Vec3 pointNear;
    Vec3 center;
    Vec2 horizontal;
    Quat blended;
    Blend blend;
    Pose frames[2];
    u8 *unit;
    f32 halfDistance;
    f32 desiredDistance;
    f32 angle;
    f32 ratio;
    f32 sideOffset;
    f32 x;
    f32 xSquared;
    f32 r;
    f32 r2;
    f32 nearAngle;
    f32 duration;
    f32 middleY;
    f32 radius;
    f32 height;
    BtlUnit *unitData;

    unit = (u8*)((BtlAction *)(u8*)((BtlCamera *)camera)->action)->unit;
    unitData = (BtlUnit *)unit;
    radius = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale;
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)&((BtlCamera *)camera)->pose);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &center);
    
    x = unitData->scale;
    height = ((BtlUnit *)unit)->unk_8c * x;
    middleY = center.y + 0.5f * height;
    if (radius < 180.0f) {
        center.y += fGpffff8118 * height;
        desiredDistance = (1.5f * radius) / tanf(0.5f * ((BtlCamera *)camera)->fovRad);
    } else {
        center.y += 0.25f * height;
        desiredDistance = (2.5f * radius) / tanf(0.5f * ((BtlCamera *)camera)->fovRad);
    }
    delta.x = frames[0].pos.x - center.x;
    delta.y = frames[0].pos.y - center.y;
    delta.z = frames[0].pos.z - center.z;
    halfDistance = RwV3dLength(&delta);
    halfDistance *= fGpffff8140;
    if (!(desiredDistance <= halfDistance)) halfDistance = desiredDistance;
    RtQuatTransformVectors(&delta, &D_0060A0F0, 1, (const RtQuat *)&((BtlUnit *)unit)->rot);
    candidate.x = delta.x * (0.5f * radius);
    candidate.y = delta.y * (0.5f * radius);
    candidate.z = delta.z * (0.5f * radius);
    pointNear.x = center.x + candidate.x;
    pointNear.y = center.y + candidate.y;
    pointNear.z = center.z + candidate.z;
    candidate.x = delta.x * desiredDistance;
    candidate.y = delta.y * desiredDistance;
    candidate.z = delta.z * desiredDistance;
    candidate.x += center.x;
    candidate.y += center.y;
    candidate.z += center.z;
    
    
    candidate.y += fGpffff8128 * (unitData->unk_8c * unitData->scale);
    delta.x = candidate.x - center.x;
    delta.y = candidate.y - center.y;
    delta.z = candidate.z - center.z;
    RwV3dNormalize(&delta, &delta);
    candidate.x = delta.x * desiredDistance;
    candidate.y = delta.y * desiredDistance;
    candidate.z = delta.z * desiredDistance;
    candidate.x += pointNear.x;
    candidate.y += pointNear.y;
    candidate.z += pointNear.z;
    btlCameraLookAtQuat(&frames[1].rot, &candidate, &pointNear, &D_0060A0E0);
    angle = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
    nearAngle = fGpffff816c * nearDegrees;
    if (!(angle <= nearAngle)) {
        if (!(angle <= fGpffff816c * farDegrees)) {
            u16 mode = ((BtlCamera *)camera)->stateHistory[0];
            if (mode != 2 && mode != 0x29 && mode != 0x24 && mode != 0x22 && mode != 0x21) {
                btlAct_ENEMY_ALL(camera);
                CrossfadeRequest(5);
                return;
            }
        }
        candidate.x = frames[0].pos.x;
        candidate.z = frames[0].pos.z;
        if (middleY < frames[0].pos.y) {
            candidate.y = middleY + 0.25f * (frames[0].pos.y - middleY);
        } else {
            candidate.y = frames[0].pos.y;
        }
        btlCameraLookAtQuat(&blended, &candidate, &pointNear, &D_0060A0E0);
        if (btlTargetQuatAngle(&frames[0].rot, &blended) <= nearAngle) {
            frames[1].rot = blended;
        } else {
            ratio = nearAngle / angle;
            func_003dcc70((f32 *)&frames[0].rot, (f32 *)&frames[1].rot, (f32 *)&blend);
            if (ratio <= 0.0f) {
                blended = frames[0].rot;
            } else if (1.0f <= ratio) {
                blended = frames[1].rot;
            } else {
                f32 firstWeight;
                firstWeight = 1.0f - ratio;
                if (blend.flag == 0) {
                    x = firstWeight * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8180 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    firstWeight = r * r2 + x;
                    x = ratio * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8180 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    ratio = r * r2 + x;
                }
                blended.quat.x = blend.first.quat.x * firstWeight;
                blended.quat.y = blend.first.quat.y * firstWeight;
                blended.quat.z = blend.first.quat.z * firstWeight;
                blended.quat.x = 0.0f + blended.quat.x + blend.second.quat.x * ratio;
                blended.quat.y = 0.0f + blended.quat.y + blend.second.quat.y * ratio;
                blended.quat.z = 0.0f + blended.quat.z + blend.second.quat.z * ratio;
                blended.quat.w = blend.first.quat.w * firstWeight + blend.second.quat.w * ratio;
            }
            RtQuatTransformVectors(&delta, &D_0060A100, 1, (const RtQuat *)(&blended));
            candidate.x = pointNear.x + delta.x;
            candidate.y = pointNear.y + delta.y;
            candidate.z = pointNear.z + delta.z;
            btlCameraLookAtQuat(&frames[1].rot, &candidate, &pointNear, &D_0060A0E0);
        }
    }
    if (halfDistance < (f32)(s32)550) halfDistance = (f32)(s32)550;
    RtQuatTransformVectors(&delta, &D_0060A100, 1, (const RtQuat *)(&frames[1].rot));
    delta.x *= halfDistance;
    delta.y *= halfDistance;
    delta.z *= halfDistance;
    
    sideOffset = halfDistance * tanf(fGpffff8110 * (0.5f * cameraData->fovRad));
    sideOffset *= 0.21875f;
    horizontal.x = delta.x;
    horizontal.y = delta.z;
    func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
    pointNear.x = 0.0f + pointNear.x + horizontal.y * sideOffset;
    pointNear.z = 0.0f + pointNear.z - horizontal.x * sideOffset;
    frames[1].pos.x = pointNear.x + delta.x;
    frames[1].pos.y = pointNear.y + delta.y;
    frames[1].pos.z = pointNear.z + delta.z;
    if (frames[0].pos.y < 100.0f) frames[0].pos.y = 100.0f;
    if (frames[1].pos.y < 100.0f) frames[1].pos.y = 100.0f;
    angle = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
    duration = 1.75f;
    if (!(angle <= 0.0f)) {
        ratio = nearAngle / angle;
        if (!(ratio <= 1.0f)) duration = ratio * fGpffff807c;
        else duration = fGpffff807c;
        if (!(duration <= 1.75f)) duration = 1.75f;
    }
    btlCameraClampOffsetToLimit((f32 *)&frames[0], (f32 *)&frames[0]);
    btlCameraClampOffsetToLimit((f32 *)&frames[1], (f32 *)&frames[1]);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, duration);
}

// FUN_001BE8D0
void btlCameraSetDefaultDistanceA(void* camera)
{
    btlCameraFrameActionDegrees((u8 *)camera, 45.0f, 200.0f);
}

/* Ported from current P3FES src/Battle/btlCamera.c btlCameraFrameActionTarget
 * (0x002a7390, donor 04d95e2). Historical donor verification is
 * recorded in the recovery note; no fresh P3 retail run is claimed.
 * Complete pose and quaternion objects retain the retail copy boundaries.
 * measured: 1156/1168 bytes; all executable bytes and relocations exact. */
/* Ease the current camera toward the action unit anchor, limiting angular change. */
// FUN_001C09B0
void btlCameraFrameActionTarget(u8* camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    extern void btlCameraCopyPose(f32*, f32*);
    extern RwV3d D_0060A100;
    extern void btlUnitGetAnchorPose(u8*, u8*, f32*, f32*);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0* right, P4Vec4Holder_001EC2B0* left);
    extern void func_003dcc70(f32*, f32*, void*);
    extern f32 tanf(f32);
    extern f32 func_003e41e0(f32*, f32*);
    extern f32 fGpffff8118, fGpffff815c, fGpffff804c, fGpffff8160, fGpffff8110, fGpffff818c;
    extern f32 fGpffff8180;
    extern f32 fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060, fGpffff8108;
    extern RtQuat* func_003dc740(RtQuat*, const RwV3d*, f32, s32);
    f32 horiz[2];
    RwV3d eyeAdj;
    RwV3d center;
    P4Vec4Holder_001EC2B0 blended;
    P4CameraBlend blend;
    P4CameraFrame frames[2];
    u8* unit;
    f32 height;
    f32 angle;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dist;
    f32 sideOffset;
    BtlUnit *unitData;

    unit = (u8*)((BtlAction *)(u8*)((BtlCamera *)camera)->action)->unit;
    unitData = (BtlUnit *)unit;
    btlCameraCopyPose((f32*)&frames[0], (f32*)&((BtlCamera *)camera)->pose);
    btlUnitGetAnchorPose(unit, (u8*)&center, NULL, NULL);
    
    height = ((BtlUnit *)unit)->sphereCenter.y * unitData->scale;
    
    height += fGpffff8118 * (((BtlUnit *)unit)->unk_8c * unitData->scale);
    center.y = height;
    eyeAdj = frames[0].pos;
    eyeAdj.y = height;
    btlCameraLookAtQuat(&frames[1].rot, &eyeAdj, &center, &D_0060A0E0);
    angle = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff815c)
    {
        ratio = fGpffff815c / angle;
        func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot, &blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8180 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                w1 = x + r * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8180 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                ratio = x + r * r2;
            }
            blended.quat.x = blend.first.quat.x * w1;
            blended.quat.y = blend.first.quat.y * w1;
            blended.quat.z = blend.first.quat.z * w1;
            blended.quat.x = 0.0f + blended.quat.x + blend.second.quat.x * ratio;
            blended.quat.y = 0.0f + blended.quat.y + blend.second.quat.y * ratio;
            blended.quat.z = 0.0f + blended.quat.z + blend.second.quat.z * ratio;
            blended.quat.w = blend.first.quat.w * w1 + blend.second.quat.w * ratio;
        }
        RtQuatTransformVectors(&eyeAdj, &D_0060A100, 1, (const RtQuat*)&blended);
        eyeAdj.x = eyeAdj.x + center.x;
        eyeAdj.y = eyeAdj.y + center.y;
        eyeAdj.z = eyeAdj.z + center.z;
        btlCameraLookAtQuat(&frames[1].rot, &eyeAdj, &center, &D_0060A0E0);
    }
    else if (angle < fGpffff804c)
    {
        func_003dc740((RtQuat*)&frames[1].rot, (const RwV3d*)&D_0060A0E0, fGpffff8160, 2);
    }
    RtQuatTransformVectors(&eyeAdj, &D_0060A100, 1, (const RtQuat*)&frames[1].rot);
    dist = 375 / tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    eyeAdj.x = eyeAdj.x * dist;
    eyeAdj.y = eyeAdj.y * dist;
    eyeAdj.z = eyeAdj.z * dist;
    
    sideOffset = dist * tanf(fGpffff8110 * (0.5f * cameraData->fovRad));
    sideOffset = sideOffset * 0.21875f;
    horiz[0] = eyeAdj.x;
    horiz[1] = eyeAdj.z;
    func_003e41e0(horiz, horiz);
    center.x = 0.0f + center.x + horiz[1] * sideOffset;
    center.z = 0.0f + center.z - horiz[0] * sideOffset;
    frames[1].pos.x = center.x + eyeAdj.x;
    frames[1].pos.y = center.y + eyeAdj.y;
    frames[1].pos.z = center.z + eyeAdj.z;
    if (frames[1].pos.y < 25.0f)
    {
        frames[1].pos.y = 25.0f;
    }
    btlMainCurveSetPoses((u16*)camera, (f32*)&frames[0], (f32*)&frames[1], 1);
    btlCameraSetDuration(camera, fGpffff818c);
}

/* Select a framing mode and invoke its setup handler. */
// FUN_001C6560
void btlCameraDispatchFrameMode(void* camera)
{
  u16 frameMode;

  frameMode = btlCameraSelectMode(camera);
  ((BtlCamera *)(int)camera)->frameMode = frameMode;
  switch(((BtlCamera *)(int)camera)->frameMode) {
  case 1:
    btlCameraFrameActionDegrees((u8 *)camera, 45.0f, 200.0f);
    break;
  case 2:
    btlCameraFrameTargetPose((u8 *)camera, 1);
    break;
  case 3:
    btlCameraFrameFlagged(camera,1);
    break;
  case 4:
    btlCameraFrameTargetPose((u8 *)camera, 1);
    break;
  case 5:
    btlCameraFrameFlagged(camera,1);
    break;
  case 6:
    btlCameraFrameRandomOrbit(camera,1);
  }
  return;
}



/* Update tracking geometry or restore the orbit unit value once animation completes. */
// FUN_001C6650
void btlCameraUpdateFrameForState(u8 *camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    struct {
        f32 value;
        u8 pad[0xC];
    } center;
    u16 state;
    u8 *unit;
    u8 *orbitAction;
    u8 *action;
    f32 scale;

    state = ((BtlCamera *)camera)->frameMode;
    switch (state) {
    case 1:
        action = (u8*)((BtlCamera *)camera)->action;
        if ((action != NULL) && ((((BtlAction *)action)->unk_1a & 1) != 0)) {
            unit = (u8*)((BtlAction *)action)->unit;
            btlUnitGetSphereWorldCenter(unit, &center.value);
            scale = 0.5f * (((BtlUnit *)unit)->sphereRadius *
                            ((BtlUnit *)unit)->scale);
            
            btlCameraSetupActionGeometry((u8 *)cameraData->action, (u8 *)&((BtlCamera *)camera)->pose, (f32 *)&center.value,
                          scale, 0xC1);
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    case 6:
        orbitAction = (u8*)((BtlCamera *)camera)->action;
        if ((orbitAction != NULL) &&
            ((((BtlAction *)orbitAction)->unk_1a & 1) != 0) &&
            (btlCameraUnitAnimFinished((BtlCamera *)camera, ((BtlCamera *)camera)->animationUnit) != 0)) {
            
            btlUnitSetChildValue((BtlUnitStateWork *)cameraData->animationUnit,
                          ((BtlCamera *)camera)->animationValue);
        }
        break;
    default:
        break;
    }
}
/* Construct two opposite-angle orbit poses around the acting unit. */
// FUN_001C6760
void btlCameraFrameOrbit(void *camera, float angle, float distanceScale, float heightScale, float minimumDistance)
{
  typedef struct CameraVectorSlot {
    RwV3d value;
    u32 padding;
  } CameraVectorSlot;
  struct CameraOrbitScratch {
    RwMatrix rotation;
    RwV3d firstPosition;
    u8 firstView[16];
    RwV3d secondPosition;
    u8 secondView[24];
    CameraVectorSlot scaledOffset;
    CameraVectorSlot candidate;
    CameraVectorSlot direction;
    CameraVectorSlot forward;
    CameraVectorSlot center;
    CameraVectorSlot sphereCenter;
  } scratch;
  u8 *unitBytes;
  int cameraAddress;
  float radius;
  float halfHeight;
  float requiredDistance;
  u64 centerXY;
  float centerZ;
    BtlUnit *unitData;
    BtlCamera *cameraData = (BtlCamera *)camera;

  cameraAddress = (int)camera;
  unitBytes = (u8 *)(uintptr_t)(int)((BtlAction *)(int)((BtlCamera *)cameraAddress)->action)->unit;
    unitData = (BtlUnit *)unitBytes;
  btlUnitGetSphereWorldCenter((BtlUnit *)unitBytes, &scratch.sphereCenter.value);
  
  radius = (float)((BtlUnit *)unitBytes)->sphereRadius * unitData->scale;
  
  halfHeight = (float)((BtlUnit *)unitBytes)->unk_8c * unitData->scale * 0.5f;
  centerXY = *(volatile /* Removing this function's qualifier batch loses func_001c6760 (MATCH nd0 -> MISMATCH nd6, size 936 -> 936) - measured W170. */ u64 *)&scratch.sphereCenter.value;
  centerZ = *(volatile /* Removing this function's qualifier batch loses func_001c6760 (MATCH nd0 -> MISMATCH nd6, size 936 -> 936) - measured W170. */ f32 *)&scratch.sphereCenter.value.z;
  *(u64 *)&scratch.center.value = centerXY;
  scratch.center.value.z = centerZ;
  scratch.center.value.y = halfHeight * heightScale + scratch.center.value.y;
  if (radius > halfHeight) {
    requiredDistance = (radius * distanceScale) /
      tanf(DAT_00761200 * ((float)((BtlCamera *)cameraAddress)->fovRad * 0.5f));
  } else {
    requiredDistance = (halfHeight * distanceScale) /
      tanf((float)((BtlCamera *)cameraAddress)->fovRad * 0.5f);
  }
  if (requiredDistance < minimumDistance) {
    requiredDistance = minimumDistance;
  }
  RtQuatTransformVectors(&scratch.forward.value, &D_0060A0F0, 1, (void *)&((BtlUnit *)unitBytes)->rot);
  scratch.scaledOffset.value.x = scratch.forward.value.x * radius;
  scratch.scaledOffset.value.y = scratch.forward.value.y * radius;
  scratch.scaledOffset.value.z = scratch.forward.value.z * radius;
  scratch.candidate.value.x = scratch.center.value.x + scratch.scaledOffset.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.scaledOffset.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.scaledOffset.value.z;
  scratch.candidate.value.y = DAT_0076112c * halfHeight + scratch.candidate.value.y;
  scratch.direction.value.x = scratch.candidate.value.x - scratch.center.value.x;
  scratch.direction.value.y = scratch.candidate.value.y - scratch.center.value.y;
  scratch.direction.value.z = scratch.candidate.value.z - scratch.center.value.z;
  RwV3dNormalize(&scratch.direction.value, &scratch.direction.value);
  scratch.scaledOffset.value.x = scratch.direction.value.x * requiredDistance;
  scratch.scaledOffset.value.y = scratch.direction.value.y * requiredDistance;
  scratch.scaledOffset.value.z = scratch.direction.value.z * requiredDistance;
  RwMatrixRotate(&scratch.rotation, &D_0060A0E0, angle, 0);
  func_003e4320(&scratch.direction.value, &scratch.scaledOffset.value, &scratch.rotation);
  scratch.candidate.value.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.direction.value.z;
  btlCameraLookAtQuat(scratch.firstView, &scratch.candidate.value, &scratch.center.value, &D_0060A0E0);
  scratch.firstPosition.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.firstPosition.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.firstPosition.z = scratch.center.value.z + scratch.direction.value.z;
  RwMatrixRotate(&scratch.rotation, &D_0060A0E0, -angle, 0);
  func_003e4320(&scratch.direction.value, &scratch.scaledOffset.value, &scratch.rotation);
  scratch.candidate.value.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.direction.value.z;
  btlCameraLookAtQuat(scratch.secondView, &scratch.candidate.value, &scratch.center.value, &D_0060A0E0);
  scratch.secondPosition.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.secondPosition.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.secondPosition.z = scratch.center.value.z + scratch.direction.value.z;
  
  btlCameraSetupActionGeometry((u8 *)cameraData->action, NULL, NULL, 0.0f, 1);
  btlMainCurveSetPoses((u16 *)camera, (f32 *)&scratch.firstPosition, (f32 *)&scratch.secondPosition, 1);
  btlCameraSetDuration((u8 *)camera, 3.5f);
}



/* Use a shallow ten-degree orbit with a 250-unit minimum viewing distance. */
// FUN_001C6B10
void btlCameraFrameOrbitTight(void* camera)
{
  btlCameraFrameOrbit(camera,10.0f,2.0f,0.0f,250.0f);
  return;
}



// FUN_001C6B50
void btlCameraOrbitTightUpdateNoop(void)
{
}
// FUN_001C6B60
void btlAct_SKILL_EXEC_ONE(void* camera)
{
    btlCameraFrameOrbit(camera, 15.0f, 2.0f, 0.25f, 400.0f);
}
// FUN_001C6BA0
void btlCameraSkillExecOneUpdateNoop(void)
{
}
// FUN_001C6BB0
void btlCameraResetToDefault(void *camera)
{
    btlCameraEnterRandomFrame(camera, 1);
}
// FUN_001C6BE0
void btlCameraResetToDefaultUpdateNoop(void)
{
}
/* Construct a short orbit around the first target unit and clamp both poses above the floor. */
// FUN_001C6BF0
void btlCameraFrameOrbitUnit(u8 *camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    struct {
        RwV3d firstPosition;
        u8 firstView[0x10];
        RwV3d secondPosition;
        u8 secondView[0x18];
        RwMatrix rotation;
        RwV3d center;
        u8 padBC[4];
        RwV3d direction;
        u8 padCC[4];
        RwV3d scaled;
        u8 padDC[4];
    } work;
    u8 *targetUnit;
    f32 angleScale;
    f32 rotationAngle;
    f32 y;

    targetUnit = ((BtlAction *)(u8*)((BtlCamera *)camera)->action)->targets[0];
    targetUnit = (u8*)((BtlAction *)targetUnit)->unit;
    btlUnitGetAnimBoundsWorldCenter((BtlUnit *)targetUnit, (RwV3d *)&work.center.x);
    work.center.y = 0.0f + work.center.y +
                    DAT_00761278 *
                    (((BtlUnit *)targetUnit)->unk_8c *
                     ((BtlUnit *)targetUnit)->scale);
    RtQuatTransformVectors(&work.direction, &D_0060A0F0, 1, (const RtQuat*)((u8 *)&((BtlUnit *)targetUnit)->rot));
    work.scaled.x = work.direction.x * 200.0f;
    work.scaled.y = work.direction.y * 200.0f;
    work.scaled.z = work.direction.z * 200.0f;
    y = (work.center.y + work.scaled.y) - 10.0f;
    work.direction.x = (work.center.x + work.scaled.x) - work.center.x;
    work.direction.y = y - work.center.y;
    work.direction.z = (work.center.z + work.scaled.z) - work.center.z;
    RwV3dNormalize(&work.direction, &work.direction);

    rotationAngle = -10.0f;
    RwMatrixRotate(&work.rotation, &D_0060A0E0,
                   0.5f * -rotationAngle, 0);
    func_003e4320(&work.scaled, &work.direction, &work.rotation);
    angleScale = 180.0f /
                 tanf(DAT_00761200 *
                      (0.5f * ((BtlCamera *)camera)->fovRad));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.firstPosition.x = work.center.x + work.scaled.x;
    work.firstPosition.y = work.center.y + work.scaled.y;
    work.firstPosition.z = work.center.z + work.scaled.z;
    btlCameraLookAtQuat(work.firstView, &work.firstPosition, &work.center,
                  &D_0060A0E0);

    RwMatrixRotate(&work.rotation, &D_0060A0E0, -5.0f, 0);
    func_003e4320(&work.scaled, &work.direction, &work.rotation);
    angleScale = 110.0f /
                 tanf(DAT_00761200 *
                      
                      (0.5f * cameraData->fovRad));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.secondPosition.x = work.center.x + work.scaled.x;
    work.secondPosition.y = work.center.y + work.scaled.y;
    work.secondPosition.z = work.center.z + work.scaled.z;
    btlCameraLookAtQuat(work.secondView, &work.secondPosition, &work.center,
                  &D_0060A0E0);
    if (work.firstPosition.y < 25.0f) {
        work.firstPosition.y = 25.0f;
    }
    if (work.secondPosition.y < 25.0f) {
        work.secondPosition.y = 25.0f;
    }
    
    btlCameraSetupActionGeometry((u8 *)cameraData->action, NULL, NULL, 0.0f, 2);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&work.firstPosition, (f32 *)&work.secondPosition, 1);
    btlCameraSetDuration(camera, 1.5f);
}
// FUN_001C6F30
void btlCameraOrbitUnitUpdateNoop(void)
{
}
static inline f32 cameraProjection(register f32 angle, register f32 extent, register f32 distance)
{
    f32 tangent = tanf(angle);
    extent = extent / tangent;
    return extent + distance;
}

static inline f32 cameraChooseDistance(f32 current, f32 minimum)
{
    if (!(current <= minimum)) {
        return current;
    }
    return minimum;
}

/* The P3 func_002add10 draft supplies the broad camera operation; the P4
 * source below is recovered against 001c6f40's own retail window.
 * Ordinary vectors and the two complete poses reproduce the 0x120 frame
 * and the twelve-byte ld/lwc1 vector copy. The projection record retains
 * the half-angle argument before the scaled extent is evaluated. */
/* Build current/target poses framing the acting unit against the group bounds. */
// FUN_001C6F40
u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                 P4CameraFrame *firstOut, P4CameraFrame *secondOut)
{
    extern RwV3d D_0060A0D0;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
    f32 distance;
    RwV3d direction;
    RwV3d diff;
    RwV3d candidate;
    RwV3d unitPosition;
    RwV3d target;
    P4CameraFrame frames[2];
    RtQuat position;
    BtlUnit *unit;
    BtlCamera *cam;
    f32 groupRadius;
    f32 scaledRadius;
    f32 normal;
    f32 height;
    f32 minRequired;
    f32 factor;

    cam = (BtlCamera *)camera;
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)&((BtlCamera *)camera)->pose);
    groupRadius = btlUnitGetGroupBounds(2, 0, &target, &distance, NULL, 1);
    if (distance < 350.0f) {
        target.y = 0.25f * distance;
    } else {
        target.y = D_0076122C * distance;
    }
    unit = cam->action->unit;
    if (useAlternate != 0) {
        btlUnitGetGridSphereCenter(unit, &unitPosition);
    } else {
        btlUnitGetSphereWorldCenter(unit, &unitPosition);
    }
    scaledRadius = unit->sphereRadius * unit->scale;
    scaledRadius = scaledRadius * 2.5f;
    btlTargetBlendVectors(&position, &unitPosition, &target);
    unitPosition.y = 0.0f + unitPosition.y + D_0076122C * (unit->unk_8c * unit->scale);
    RtQuatTransformVectors(&direction, &D_0060A0D0, 1, &position);
    direction.x = direction.x * scaledRadius;
    direction.y = direction.y * scaledRadius;
    direction.z = direction.z * scaledRadius;
    unitPosition.x = unitPosition.x + direction.x;
    unitPosition.y = unitPosition.y + direction.y;
    unitPosition.z = unitPosition.z + direction.z;
    diff.x = unitPosition.x - target.x;
    diff.y = unitPosition.y - target.y;
    diff.z = unitPosition.z - target.z;
    normal = RwV3dNormalize(&diff, &diff);
    height = fGpffff811c * normal;
    candidate.x = diff.x * height;
    candidate.y = diff.y * height;
    candidate.z = diff.z * height;
    candidate.x = candidate.x + target.x;
    candidate.y = candidate.y + target.y;
    candidate.z = candidate.z + target.z;
    direction = unitPosition;
    btlCameraLookAtQuat(&frames[1].rot, &direction, &candidate, &D_0060A0E0);
    if (!(btlTargetQuatAngle(&frames[0].rot, &frames[1].rot) <= fGpffff8094)) {
        resultCode = 1;
    }
    {
        struct { f32 extent; f32 angle; } projection;
        projection.angle = 0.5f * cam->fovRad;
        projection.extent = fGpffff811c * (unit->unk_8c * unit->scale);
        normal = cameraProjection(projection.angle, projection.extent, normal);
    }
    minRequired = fGpffff811c * groupRadius / tanf(0.5f * cam->fovRad);
    normal = cameraChooseDistance(normal, minRequired);
    RtQuatTransformVectors(&direction, &D_0060A100, 1, (const RtQuat *)&frames[1].rot);
    factor = normal * tanf(DAT_00761200 * (0.5f * cam->fovRad));
    factor = factor * 0.109375f;
    factor = factor * 1.25f;
    target.x = 0.0f + target.x + direction.z * factor;
    target.z = (0.0f + target.z) - direction.x * factor;
    direction.x = direction.x * normal;
    direction.y = direction.y * normal;
    direction.z = direction.z * normal;
    frames[1].pos.x = target.x + direction.x;
    frames[1].pos.y = target.y + direction.y;
    frames[1].pos.z = target.z + direction.z;
    if (frames[0].pos.y < 25.0f) {
        frames[0].pos.y = 25.0f;
    }
    if (frames[1].pos.y < 25.0f) {
        frames[1].pos.y = 25.0f;
    }
    if (firstOut != NULL) {
        *firstOut = frames[0];
    }
    if (secondOut != NULL) {
        *secondOut = frames[1];
    }
    return resultCode;
}

/* Reset immediately for incompatible prior states; otherwise interpolate the frame pair. */
// FUN_001C73E0
void btlCameraApplyFrameTransition(u8 *camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    P4CameraFrame frames[2];
    s32 resetImmediately;
    u16 previousState;

    previousState = ((BtlBattleState *)iGpffffb3ac)->camera.stateHistory[0];
    switch (previousState)
    {
    case 2:
        return;
    case 34:
    case 40:
    case 41:
        resetImmediately = 0;
        break;
    default:
        resetImmediately = 1;
        break;
    }
    if (((BtlCamera *)camera)->forceTransition != 0)
    {
        resetImmediately = 1;
        
        cameraData->forceTransition = 0;
    }
    if (btlCameraBuildFramePair(camera, resetImmediately, 0,
                      &frames[0], &frames[1]) != 0)
    {
        btlMainApplyUnitBaseColors(0);
        cameraApplyVisibility(0.0f, camera, 0x100);
        btlMainCurveReset((u16 *)(camera), (f32 *)(&frames[1]));
        return;
    }
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0],
                  (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, fGpffff80e8);
}
// FUN_001C7500
void btlCameraFrameTransitionUpdateNoop(void)
{
}
/* Move from an offset pose toward the acting unit using its projected size. The packed scratch starts with two contiguous seven-float poses. */
// FUN_001C7510
void btlCameraFrameActionUnitPose(BtlCamera* camera)
{
  BtlUnit* unit;
  f32 posesAndVectors[28];
  f32 startDistance;
  f32 distance;
  f32 offsetX;
  f32 offsetY;
  f32 heightOrOffsetZ;
  f32 centerX;
  f32 centerY;
  f32 centerZ;

  unit = camera->action->unit;
  btlUnitGetSphereWorldCenter(unit, (RwV3d *)(posesAndVectors + 24));
  distance = unit->sphereRadius * unit->scale;
  heightOrOffsetZ = unit->unk_8c * unit->scale * 0.5f;
  posesAndVectors[25] = heightOrOffsetZ * 0.25f + posesAndVectors[25];
  if (distance > heightOrOffsetZ) {
    distance = (1.25f * distance) /
      tanf(DAT_00761200 * (camera->fovRad * 0.5f));
  }
  else {
    distance = (1.25f * heightOrOffsetZ) /
      tanf(camera->fovRad * 0.5f);
  }
  RtQuatTransformVectors((RwV3d *)(posesAndVectors + 20), &D_0060A0F0, 1, &unit->rot);
  startDistance = distance + 125.0f;
  offsetX = posesAndVectors[20] * startDistance;
  offsetY = posesAndVectors[21] * startDistance;
  heightOrOffsetZ = posesAndVectors[22] * startDistance;
  posesAndVectors[16] = posesAndVectors[24] + offsetX;
  posesAndVectors[17] = posesAndVectors[25] + offsetY;
  posesAndVectors[18] = posesAndVectors[26] + heightOrOffsetZ;
  btlCameraLookAtQuat(&posesAndVectors[3], &posesAndVectors[16], (RwV3d *)(posesAndVectors + 24), &D_0060A0E0);
  centerX = posesAndVectors[24];
  posesAndVectors[0] = centerX + offsetX;
  centerY = posesAndVectors[25];
  posesAndVectors[1] = centerY + offsetY;
  centerZ = posesAndVectors[26];
  posesAndVectors[2] = centerZ + heightOrOffsetZ;
  ((BtlCameraPose *)posesAndVectors)[1].rot = ((BtlCameraPose *)posesAndVectors)[0].rot;
  posesAndVectors[7] = posesAndVectors[20] * distance + centerX;
  posesAndVectors[8] = posesAndVectors[21] * distance + centerY;
  posesAndVectors[9] = posesAndVectors[22] * distance + centerZ;
  btlCameraSetupActionGeometry((u8 *)camera->action, 0, 0, 0.0f, 1);
  btlMainCurveSetPoses((u16 *)camera, (f32 *)posesAndVectors, (f32 *)(posesAndVectors + 7), 1);
  btlCameraSetDuration((u8 *)camera, 2.5f);
}



// FUN_001C7770
void btlCameraActionUnitPoseUpdateNoop(void)
{
}

/* Traverse the acting-unit pose pair in the opposite order with wider framing. The packed scratch starts with two contiguous seven-float poses. */
// FUN_001C7780
void btlCameraFrameActionUnitPoseMirror(BtlCamera* camera)
{
  BtlUnit* unit;
  f32 posesAndVectors[28];
  f32 startDistance;
  f32 distance;
  f32 offsetX;
  f32 offsetY;
  f32 heightOrOffsetZ;
  f32 centerX;
  f32 centerY;
  f32 centerZ;

  unit = camera->action->unit;
  btlUnitGetSphereWorldCenter(unit, (RwV3d *)(posesAndVectors + 24));
  distance = unit->sphereRadius * unit->scale;
  heightOrOffsetZ = unit->unk_8c * unit->scale * 0.5f;
  posesAndVectors[25] = heightOrOffsetZ * 0.25f + posesAndVectors[25];
  if (distance > heightOrOffsetZ) {
    distance = (1.5f * distance) /
      tanf(DAT_00761200 * (camera->fovRad * 0.5f));
  }
  else {
    distance = (1.5f * heightOrOffsetZ) /
      tanf(camera->fovRad * 0.5f);
  }
  RtQuatTransformVectors((RwV3d *)(posesAndVectors + 20), &D_0060A0F0, 1, &unit->rot);
  startDistance = distance + 125.0f;
  offsetX = posesAndVectors[20] * startDistance;
  offsetY = posesAndVectors[21] * startDistance;
  heightOrOffsetZ = posesAndVectors[22] * startDistance;
  posesAndVectors[16] = posesAndVectors[24] + offsetX;
  posesAndVectors[17] = posesAndVectors[25] + offsetY;
  posesAndVectors[18] = posesAndVectors[26] + heightOrOffsetZ;
  btlCameraLookAtQuat(&posesAndVectors[3], &posesAndVectors[16], (RwV3d *)(posesAndVectors + 24), &D_0060A0E0);
  centerX = posesAndVectors[24];
  posesAndVectors[0] = centerX + offsetX;
  centerY = posesAndVectors[25];
  posesAndVectors[1] = centerY + offsetY;
  centerZ = posesAndVectors[26];
  posesAndVectors[2] = centerZ + heightOrOffsetZ;
  ((BtlCameraPose *)posesAndVectors)[1].rot = ((BtlCameraPose *)posesAndVectors)[0].rot;
  posesAndVectors[7] = posesAndVectors[20] * distance + centerX;
  posesAndVectors[8] = posesAndVectors[21] * distance + centerY;
  posesAndVectors[9] = posesAndVectors[22] * distance + centerZ;
  btlCameraSetupActionGeometry((u8 *)camera->action, 0, 0, 0.0f, 1);
  btlMainCurveSetPoses((u16 *)camera, (f32 *)(posesAndVectors + 7), (f32 *)posesAndVectors, 1);
  btlCameraSetDuration((u8 *)camera, 2.5f);
}



// FUN_001CA550
void btlCameraSetDefaultLimit(u8 *camera) {
    btlCameraSetLimitFrame(camera, 50.0f, 0, 0);
}

/* Apply the next preset while the current action still owns the same single target. */
// FUN_001CBFE0
void btlCameraSelectPreset(int cameraAddress)
{
    BtlCamera *cameraData = (BtlCamera *)cameraAddress;
  int actionAddress;
  f32 speed;

  actionAddress = (int)((BtlCamera *)cameraAddress)->action;
  if ((((actionAddress != 0) && (((BtlAction *)actionAddress)->unk_6a == 1)) &&
      ((int)((BtlCamera *)cameraAddress)->presetTarget == (int)((BtlAction *)actionAddress)->targets[0])) && ((((BtlAction *)actionAddress)->unk_1a & 1) != 0)
     ) {
    
    if (((BtlCamera *)cameraAddress)->presetRepeatCount <= cameraData->presetUseCount) {
      speed = ((int)((BtlCamera *)cameraAddress)->presetAlternate != 0) ? DAT_00761254 : DAT_00761188;
    }
    else {
      speed = DAT_00761258;
    }
    
    btlCameraApplyPreset((u8*)cameraAddress, speed, cameraData->presetUseCount == 0);
    ((BtlCamera *)cameraAddress)->presetUseCount = ((BtlCamera *)cameraAddress)->presetUseCount + 1;
  }
  return;
}



extern f32 fGpffff8118;
extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *projection);
extern f32 RwV3dLength(f32 *vector);
extern RwV3d D_0060A0D0;

/* Measured: 1300 executable bytes, 23 resolved relocations, twelve zero
   alignment bytes. Both aggregates contain only initialized live values. */
/* Frame actor and first target using their relative heights and horizontal directions. */
// FUN_001CC0A0
void btlCameraFrameFreshPose(u8 *camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    RwV3d pos2;
    RwV3d pos1;
    RwV3d eye;
    RwV3d target;
    RwV3d dir;
    f32 actor2XZ[2];
    struct {
        f32 targetXZ[2];
        f32 eyeXZ[2];
        f32 dir2XZ[2];
        f32 dir1XZ[2];
    } xz;
    struct {
        RwV3d pos;
        RtQuat quat;
    } work;

    u8 *cameraWork;
    u8 *actor1;
    u8 *actor2;
    u16 flag;
    f32 scale2;
    f32 dot;
    f32 dist;
    f32 len;
    f32 tanVal;
    f32 factor;
    BtlUnit *targetUnitData;

    cameraWork = (u8*)((BtlCamera *)camera)->action;
    actor1 = (u8*)((BtlAction *)cameraWork)->unit;
    flag = ((BtlUnit *)actor1)->genus;
    actor2 = (u8*)((BtlAction *)((BtlAction *)cameraWork)->targets[0])->unit;
    targetUnitData = (BtlUnit *)actor2;

    scale2 = ((BtlUnit *)actor2)->sphereRadius * ((BtlUnit *)actor2)->scale;

    btlUnitGetSphereWorldCenter(actor2, (f32 *)&pos2);
    btlUnitGetSphereWorldCenter(actor1, (f32 *)&pos1);

    if (pos2.y > pos1.y) {
        
        pos2.y = (0.0f + pos2.y) - (((BtlUnit *)actor2)->unk_8c * targetUnitData->scale) * fGpffff8118;
        pos1.y = (0.0f + pos1.y) + (((BtlUnit *)actor1)->unk_8c * ((BtlUnit *)actor1)->scale) * DAT_00761278;
    } else {
        
        factor = ((BtlUnit *)actor2)->unk_8c * targetUnitData->scale;
        pos2.y = (0.0f + pos2.y) + fGpffff8118 * factor;
        pos1.y = (0.0f + pos1.y) - fGpffff8118 * (((BtlUnit *)actor1)->unk_8c * ((BtlUnit *)actor1)->scale);
    }

    if (pos2.y < 65.0f) {
        pos2.y = 65.0f;
    }

    dir.x = pos1.x - pos2.x;
    dir.y = pos1.y - pos2.y;
    dir.z = pos1.z - pos2.z;
    dir.x *= D_0076122C;
    dir.y *= D_0076122C;
    dir.z *= D_0076122C;

    target.x = pos2.x + dir.x;
    target.y = pos2.y + dir.y;
    target.z = pos2.z + dir.z;

    dir.x = pos2.x - ((BtlCamera *)camera)->pose.pos.x;
    dir.y = pos2.y - ((BtlCamera *)camera)->pose.pos.y;
    dir.z = pos2.z - ((BtlCamera *)camera)->pose.pos.z;

    xz.dir1XZ[0] = dir.x;
    xz.dir1XZ[1] = dir.z;
    func_003e41e0(xz.dir1XZ, xz.dir1XZ);

    RtQuatTransformVectors(&dir, &D_0060A0D0, 1, (const RtQuat*)&((BtlUnit *)actor2)->rot);

    xz.dir2XZ[0] = dir.x;
    xz.dir2XZ[1] = dir.z;
    func_003e41e0(xz.dir2XZ, xz.dir2XZ);

    dot = xz.dir2XZ[0] * xz.dir1XZ[0] + xz.dir2XZ[1] * xz.dir1XZ[1];

    if ((flag & 0xFFFF) == 0) {
        eye = pos2;
    } else {
        factor = 1.5f * scale2;

        dir.x *= factor;
        dir.y *= factor;
        dir.z *= factor;

        if (dot < 0.0f) {
            eye.x = pos2.x + dir.x;
            eye.y = pos2.y + dir.y;
            eye.z = pos2.z + dir.z;
        } else {
            eye.x = pos2.x - dir.x;
            eye.y = pos2.y - dir.y;
            eye.z = pos2.z - dir.z;
        }
    }

    btlCameraLookAtQuat(&work.quat, &eye, &target, &D_0060A0E0);

    xz.targetXZ[0] = target.x;
    xz.targetXZ[1] = target.z;
    xz.eyeXZ[0] = eye.x;
    xz.eyeXZ[1] = eye.z;
    actor2XZ[0] = pos2.x;
    actor2XZ[1] = pos2.z;

    dist = btlTargetAngleBetween((u8 *)xz.targetXZ, (u8 *)xz.eyeXZ, (u8 *)actor2XZ, NULL);

    if ((flag & 0xFFFF) == 0) {
        scale2 = scale2 > 100.0f ? scale2 : 100.0f;
        dist += scale2;
    } else {
        scale2 = scale2 > 125.0f ? scale2 : 125.0f;
        dist += scale2;
    }

    if (dist < 160.0f) {
        dist = 160.0f;
    }

    dir.x = target.x - eye.x;
    dir.y = target.y - eye.y;
    dir.z = target.z - eye.z;

    len = RwV3dLength((f32 *)&dir);

    tanVal = tanf(DAT_00761200 * (0.5f * ((BtlCamera *)camera)->fovRad));
    dist = len + (dist / tanVal);

    dist = dist > 0.0f ? dist : 0.0f;

    RtQuatTransformVectors(&dir, &D_0060A100, 1, &work.quat);

    dir.x *= dist;
    dir.y *= dist;
    dir.z *= dist;

    work.pos.x = target.x + dir.x;
    work.pos.y = target.y + dir.y;
    work.pos.z = target.z + dir.z;

    if (work.pos.y < 25.0f) {
        work.pos.y = 25.0f;
    }

    
    btlCameraSetupActionGeometry((u8 *)cameraData->action, (u8 *)&work.pos, (f32 *)&target, 400.0f, 3);
    btlMainCurveReset((u16 *)(camera), (f32 *)(&work.pos));
}
// FUN_001CC5C0
void btlCameraFreshPoseUpdateNoop(void)
{
}
/* Build a group-target pose with bounded quaternion interpolation and a minimum distance. */
// FUN_001CC5D0
void btlCameraFrameSlerpTarget(u8 *camera, f32 *out)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    struct C5Scratch
    {
        BtlCameraSlerpResult result;
        u8 pad0[8];
        f32 selected[4];
        f32 horizontal[2];
        f32 target[3];
        f32 pad1;
        f32 direction[3];
        f32 pad2;
        f32 position[3];
        f32 pad3;
        f32 aux;
        f32 distance;
    } work;
    f32 angleScale;
    f32 value;
    f32 blend;
    f32 inverse;
    f32 term;
    f32 coefficient;
    f32 sample;
    f32 componentY;
    f32 weightedAngle;
    f32 minDistance;
    f32 factor;

    value = btlUnitGetGroupBounds(3, 1, work.target, &work.distance,
                           &work.aux, 1);
    angleScale = tanf(DAT_00761200 *
                               (0.5f * ((BtlCamera *)camera)->fovRad));
    angleScale = value / angleScale;
    work.position[0] = 0.0f;
    work.position[1] = work.distance;
    work.position[2] = -value;
    btlCameraLookAtQuat(out + 3, work.position, work.target, &D_0060A0E0);
    /* measured: using the typed pose.rot address here loses MATCH (nd746). */
    blend = btlTargetQuatAngle((P4Vec4Holder_001EC2B0*)(camera + 0xA8), (P4Vec4Holder_001EC2B0*)(out + 3));
    if (blend > fGpffff80d8[1]) {
        blend = fGpffff80d8[1] / blend;
        /* measured: using the typed pose.rot address here loses MATCH (nd742). */
        func_003dcc70((f32 *)(camera + 0xA8), out + 3, &work.result);
        if (blend <= 0.0f) {
            sample = ((BtlCamera *)camera)->pose.rot.imag.x;
            componentY = ((BtlCamera *)camera)->pose.rot.imag.y;
            coefficient = ((BtlCamera *)camera)->pose.rot.imag.z;
            term = ((BtlCamera *)camera)->pose.rot.real;
            work.selected[0] = sample;
            work.selected[1] = componentY;
            work.selected[2] = coefficient;
            work.selected[3] = term;
        }
        else if (1.0f <= blend) {
            sample = out[3];
            componentY = out[4];
            coefficient = out[5];
            term = out[6];
            work.selected[0] = sample;
            work.selected[1] = componentY;
            work.selected[2] = coefficient;
            work.selected[3] = term;
        }
        else {
            inverse = 1.0f - blend;
            if (work.result.mode == 0) {
                weightedAngle = inverse * work.result.angle;
                sample = weightedAngle * weightedAngle;
                term = fGpffff8180 * sample + fGpffff8054;
                term = sample * term + fGpffff8058;
                term = sample * term + fGpffff805c;
                term = sample * term + fGpffff8060;
                coefficient = sample * term + fGpffff8108;
                term = sample * weightedAngle;
                inverse = term * coefficient + weightedAngle;

                weightedAngle = blend * work.result.angle;
                sample = weightedAngle * weightedAngle;
                term = fGpffff8180 * sample + fGpffff8054;
                term = sample * term + fGpffff8058;
                term = sample * term + fGpffff805c;
                term = sample * term + fGpffff8060;
                coefficient = sample * term + fGpffff8108;
                term = sample * weightedAngle;
                blend = term * coefficient + weightedAngle;
            }
            work.selected[0] = work.result.current0 * inverse;
            work.selected[1] = work.result.current1 * inverse;
            work.selected[2] = work.result.current2 * inverse;
            work.selected[0] = work.result.next0 * blend +
                               work.selected[0];
            work.selected[1] = work.result.next1 * blend +
                               work.selected[1];
            work.selected[2] = work.result.next2 * blend +
                               work.selected[2];
            work.selected[3] = work.result.current3 * inverse +
                               work.result.next3 * blend;
        }
        RtQuatTransformVectors((RwV3d*)work.direction, &D_0060A100, 1, (const RtQuat*)work.selected);
        work.position[0] = work.target[0] + work.direction[0];
        work.position[1] = work.target[1] + work.direction[1];
        work.position[2] = work.target[2] + work.direction[2];
        btlCameraLookAtQuat(out + 3, work.position, work.target,
                      &D_0060A0E0);
    }
    if (angleScale < 700.0f) {
        angleScale = 700.0f;
    }
    RtQuatTransformVectors((RwV3d*)work.direction, &D_0060A100, 1, (const RtQuat*)(out + 3));
    work.direction[0] = work.direction[0] * angleScale;
    work.direction[1] = work.direction[1] * angleScale;
    work.direction[2] = work.direction[2] * angleScale;
    minDistance = tanf(DAT_00761200 *
                                
                                (0.5f * cameraData->fovRad));
    coefficient = angleScale * minDistance;
    factor = 0.21875f;
    minDistance = coefficient * factor;
    work.horizontal[0] = work.direction[0];
    work.horizontal[1] = work.direction[2];
    func_003e41e0(work.horizontal, work.horizontal);
    work.target[0] = work.horizontal[1] * minDistance +
                     work.target[0] + 0.0f;
    work.target[2] = (work.target[2] + 0.0f) -
                    work.horizontal[0] * minDistance;
    out[0] = work.target[0] + work.direction[0];
    out[1] = work.target[1] + work.direction[1];
    out[2] = work.target[2] + work.direction[2];
}
/* measured: plain-C aggregate reconstruction reproduces every retail
   instruction; the object is 112B against the 128B window, with the retail
   trailing jr/nop pair left as window padding. */
/* Interpolate from the current pose to the group-target framing over ten seconds. */
// FUN_001CC9E0
void btlAct_TARGET(u8 *camera)
{
    struct C9Work {
        f32 first[7];
        f32 second[7];
    } work;

    btlCameraCopyPose(work.first, (f32 *)&((BtlCamera *)camera)->pose);
    btlCameraFrameSlerpTarget(camera, work.second);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)work.first, (f32 *)work.second, 1);
    btlCameraSetDuration(camera, 10.0f);
}
// FUN_001CCA50
void btlCameraTargetUpdateNoop(void)
{
}

/* Fit group bounds and the selected unit, then clamp the resulting pose to arena limits. */
// FUN_001CCA60
void btlCameraFrameClampedDistance(BtlCamera* camera)
{
    int unitAddress;
    int cameraAddress;
    f32 distance;
    f32 minDistance;
    f32 norm;
    f32 height;
    f32 candidate;
    struct {
        RwV3d out;
        RtQuat unk;
        f32 pad0;
        RwV3d diff;
        f32 pad1;
        RwV3d pos;
        f32 posPad;
        RwV3d target;
    } scratch;
    BtlUnit *selectedUnitData;
    BtlCamera *cameraData = camera;

    cameraAddress = (int)camera;
    unitAddress = (int)((BtlCamera *)cameraAddress)->action;
    if (unitAddress != 0)
    {
        unitAddress = (int)((BtlAction *)unitAddress)->unit;
    }
    else
    {
        unitAddress = (int)((BtlAction *)(int)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit;
    }
    selectedUnitData = (BtlUnit *)unitAddress;
    distance = btlUnitGetGroupBounds(3, 1, &scratch.target, &height, 0, 1);
    btlUnitGetGridSphereCenter((BtlUnit*)unitAddress, &scratch.pos);
    scratch.target.y = 0.0f;
    scratch.pos.y = 0.0f;
    if ((scratch.pos.x == scratch.target.x) &&
        (scratch.pos.z == scratch.target.z))
    {
        btlUnitGetGridSphereCenter((BtlUnit*)(int)((BtlAction *)(int)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit,
                      &scratch.pos);
        scratch.pos.y = 0.0f;
    }
    scratch.diff.x = scratch.pos.x - scratch.target.x;
    scratch.diff.y = scratch.pos.y - scratch.target.y;
    scratch.diff.z = scratch.pos.z - scratch.target.z;
    RwV3dNormalize((RwV3d *)&scratch.diff.x, (const RwV3d *)&scratch.diff.x);
    scratch.diff.x = scratch.diff.x * distance;
    scratch.diff.y = scratch.diff.y * distance;
    scratch.diff.z = scratch.diff.z * distance;
    scratch.pos.x = scratch.target.x + scratch.diff.x;
    scratch.pos.y = scratch.target.y + scratch.diff.y;
    scratch.pos.z = scratch.target.z + scratch.diff.z;
    minDistance = 0.75f *
                  (((BtlUnit *)unitAddress)->unk_8c *
                   ((BtlUnit *)unitAddress)->scale);
    norm = fGpffff8170 * height;
    norm = (!(norm > minDistance)) ? minDistance : norm;
    scratch.pos.y = norm;
    btlCameraLookAtQuat(&scratch.unk, &scratch.pos, &scratch.target, &D_0060A0E0);
    minDistance = (0.75f * distance) /
                  tanf(fGpffff8110 *
                                 (0.5f * ((BtlCamera *)cameraAddress)->fovRad));
    scratch.diff.x = scratch.pos.x - scratch.target.x;
    scratch.diff.y = scratch.pos.y - scratch.target.y;
    scratch.diff.z = scratch.pos.z - scratch.target.z;
    norm = RwV3dNormalize((RwV3d *)&scratch.diff.x, (const RwV3d *)&scratch.diff.x);
    distance = tanf(fGpffff8110 *
                             
                             (0.5f * cameraData->fovRad));
    candidate = norm +
                (((BtlUnit *)unitAddress)->sphereRadius *
                 
                 selectedUnitData->scale * 2.0f) /
                distance;
    if (!(minDistance <= candidate))
    {
        minDistance = minDistance;
    }
    else
    {
        minDistance = candidate;
    }
    scratch.diff.x = scratch.diff.x * minDistance;
    scratch.diff.y = scratch.diff.y * minDistance;
    scratch.diff.z = scratch.diff.z * minDistance;
    scratch.out.x = scratch.diff.x + scratch.target.x;
    scratch.out.y = scratch.diff.y + scratch.target.y;
    scratch.out.z = scratch.diff.z + scratch.target.z;
    btlCameraClampOffsetToLimit((f32*)&scratch.out, (f32*)&scratch.out);
    btlCameraSetupActionGeometry((u8*)0, (u8*)0, (f32 *)0, 0.0f, 0x100);
    btlMainCurveReset((u16 *)(uintptr_t)cameraAddress, (f32 *)&scratch.out);
    btlCameraCopyPoseSnapshot((f32*)&((BtlCamera *)cameraAddress)->pose, (f32*)&scratch.out);
}
// FUN_001CCDA0
void btlCameraClampedDistanceUpdateNoop(void)
{
}
/* The battle-start mode is 0..2 (001ef8c0); the group queries require
 * nonempty eligible unit sets. Three complete poses retain the first,
 * interpolated and final camera frames consumed by 001baff0.
 * measured b210 -O2: 2124/2128 bytes, four zero alignment bytes.
 * Whole quaternion assignment preserves the grouped copy; strict >1
 * participant tests retain the retail large-angle-first branch layout. */
/* Build the battle-opening camera sequence according to opening side and participant count. */
// FUN_001CCDB0
void btlAct_NOP(u8 *camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, RwV3d *);
    extern f32 btlUnitGetGroupBounds(u32, u32, RwV3d *, f32 *, f32 *, u32);
    extern void mdlBlendTranslationRotation(f32 *result, f32 *from, f32 *to, f32 blend);
    extern void btlMainCurveSetThreePoses(u16 *curve, f32 *firstPose, f32 *middlePose, f32 *lastPose, u16 mode);
    extern RtQuat *func_003dc740(RtQuat *rotation, const RwV3d *axis, f32 angle, s32 mode);
    extern f32 RwV3dLength(const RwV3d *vector);
    extern f32 fGpffff8128;
    extern f32 fGpffff8030;
    extern f32 fGpffff803c;
    extern f32 uGpffff81a0;
    f32 height;
    RwV3d unitCenter;
    RwV3d groupCenter;
    RwV3d direction;
    P4CameraFrame frames[3];
    u8 *unit;
    f32 distance;
    f32 duration;
    BtlUnit *unitData;

    unit = (u8*)((BtlAction *)(u8*)((BtlCamera *)camera)->action)->unit;
    unitData = (BtlUnit *)unit;
    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x20000000) == 0) {
        switch (((BtlBattleState *)iGpffffb3ac)->openingSide) {
        case 0:
        case 1:
            distance = btlUnitGetGroupBounds(3, 0, NULL, &height, NULL, 0);
            btlUnitGetGroupBounds(2, 0, &groupCenter, NULL, NULL, 0);
            groupCenter.y = 0.25f * height;
            btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
            unitCenter.y = 0.0f + unitCenter.y - fGpffff803c *
                           (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale);
            btlCameraLookAtQuat(&frames[0].rot, &unitCenter, &groupCenter, &D_0060A0E0);
            distance = (0.75f * distance) /
                       tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
            if (((BtlBattleState *)iGpffffb3ac)->unkC64 > 1) {
                func_003dc740((RtQuat *)&frames[0].rot, &D_0060A0E0, 12.0f, 2);
            } else {
                func_003dc740((RtQuat *)&frames[0].rot, &D_0060A0E0, 5.0f, 2);
            }
            RtQuatTransformVectors(&direction, (const RwV3d *)&D_0060A100, 1, (const RtQuat *)&frames[0].rot);
            direction.x *= distance;
            direction.y *= distance;
            direction.z *= distance;
            frames[0].pos.x = groupCenter.x + direction.x;
            frames[0].pos.y = groupCenter.y + direction.y;
            frames[0].pos.z = groupCenter.z + direction.z;
            btlCameraClampOffsetToLimit((f32 *)&frames[0], (f32 *)&frames[0]);
            if (frames[0].pos.y < 25.0f) {
                frames[0].pos.y = 25.0f;
            }
            btlCameraBuildFramePair(camera, 1, 1, NULL, &frames[2]);
            mdlBlendTranslationRotation((f32 *)&frames[1], (f32 *)&frames[0], (f32 *)&frames[2], 0.5f);
            frames[1].pos.y = frames[0].pos.y;
            duration = uGpffff81a0;
            break;
        case 2:
            btlUnitGetGroupBounds(2, 0, &groupCenter, &height, NULL, 0);
            groupCenter.y = fGpffff8128 * height;
            btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
            unitCenter.y = fGpffff8030 * (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale);
            btlCameraLookAtQuat(&frames[0].rot, &unitCenter, &groupCenter, &D_0060A0E0);
            direction.x = unitCenter.x - groupCenter.x;
            direction.y = unitCenter.y - groupCenter.y;
            direction.z = unitCenter.z - groupCenter.z;
            distance = RwV3dLength(&direction);
            
            distance += (4.0f * (((BtlUnit *)unit)->sphereRadius * unitData->scale)) /
                        tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
            func_003dc740((RtQuat *)&frames[0].rot, &D_0060A0E0, -5.0f, 2);
            RtQuatTransformVectors(&direction, (const RwV3d *)&D_0060A100, 1, (const RtQuat *)&frames[0].rot);
            direction.x *= distance;
            direction.y *= distance;
            direction.z *= distance;
            frames[0].pos.x = groupCenter.x + direction.x;
            frames[0].pos.y = groupCenter.y + direction.y;
            frames[0].pos.z = groupCenter.z + direction.z;
            btlCameraClampOffsetToLimit((f32 *)&frames[0], (f32 *)&frames[0]);
            if (frames[0].pos.y < 25.0f) {
                frames[0].pos.y = 25.0f;
            }
            btlUnitGetGridSphereCenter((BtlUnit *)unit, &unitCenter);
            
            
            unitCenter.y = unitData->unk_8c * unitData->scale;
            direction.x = unitCenter.x - groupCenter.x;
            direction.y = unitCenter.y - groupCenter.y;
            direction.z = unitCenter.z - groupCenter.z;
            distance = RwV3dLength(&direction);
            
            
            distance += (5.0f * (unitData->sphereRadius * unitData->scale)) /
                        
                        tanf(fGpffff8110 * (0.5f * cameraData->fovRad));
            btlCameraLookAtQuat(&frames[2].rot, &unitCenter, &groupCenter, &D_0060A0E0);
            if (((BtlBattleState *)iGpffffb3ac)->unkC64 > 1) {
                func_003dc740((RtQuat *)&frames[2].rot, &D_0060A0E0, 14.0f, 2);
            } else {
                func_003dc740((RtQuat *)&frames[2].rot, &D_0060A0E0, 2.5f, 2);
            }
            RtQuatTransformVectors(&direction, (const RwV3d *)&D_0060A100, 1, (const RtQuat *)&frames[2].rot);
            direction.x *= distance;
            direction.y *= distance;
            direction.z *= distance;
            frames[2].pos.x = groupCenter.x + direction.x;
            frames[2].pos.y = groupCenter.y + direction.y;
            frames[2].pos.z = groupCenter.z + direction.z;
            mdlBlendTranslationRotation((f32 *)&frames[1], (f32 *)&frames[0], (f32 *)&frames[2], 0.5f);
            frames[1].pos.y = frames[0].pos.y;
            duration = 3.5f;
            break;
        }
    } else {
        btlCameraBuildFramePair(camera, 1, 1, NULL, &frames[2]);
        distance = btlUnitGetGroupBounds(1, 0, NULL, &height, NULL, 0);
        btlUnitGetGroupBounds(2, 0, &groupCenter, NULL, NULL, 0);
        if (!(200.0f <= distance)) {
            distance = 200.0f;
        }
        groupCenter.y = 0.5f * height;
        frames[0].rot = frames[2].rot;
        distance = (0.75f * distance) /
                   tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
        if (((BtlBattleState *)iGpffffb3ac)->unkC64 > 1) {
            func_003dc740((RtQuat *)&frames[0].rot, &D_0060A0E0, 12.0f, 2);
        } else {
            func_003dc740((RtQuat *)&frames[0].rot, &D_0060A0E0, 5.0f, 2);
        }
        RtQuatTransformVectors(&direction, (const RwV3d *)&D_0060A100, 1, (const RtQuat *)&frames[0].rot);
        direction.x *= distance;
        direction.y *= distance;
        direction.z *= distance;
        frames[0].pos.x = groupCenter.x + direction.x;
        frames[0].pos.y = groupCenter.y + direction.y;
        frames[0].pos.z = groupCenter.z + direction.z;
        btlCameraClampOffsetToLimit((f32 *)&frames[0], (f32 *)&frames[0]);
        if (frames[0].pos.y < 25.0f) {
            frames[0].pos.y = 25.0f;
        }
        mdlBlendTranslationRotation((f32 *)&frames[1], (f32 *)&frames[0], (f32 *)&frames[2], 0.5f);
        frames[1].pos.y = frames[0].pos.y;
        duration = 2.0f;
    }
    
    btlCameraSetupActionGeometry((u8 *)cameraData->action, NULL, NULL, 0.0f, 1);
    
    btlCameraSetupActionGeometry((u8 *)cameraData->action, NULL, NULL, 0.0f, 0x100);
    btlMainCurveSetThreePoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], (f32 *)&frames[2], 1);
    btlCameraSetDuration(camera, duration);
}
/* Choose one of two effect scripts for the acting unit ID. */
// FUN_001CD600
void btlCameraSpawnRandomEffect(u8 *camera)
{
    u16 unitId;

    unitId = ((BtlUnit *)(u8 *)((BtlAction *)(u8 *)((BtlCamera *)camera)->action)->unit)->charId;
    btlCameraStartEffect(
        camera,
        (void *)(uintptr_t)cd600Add(
            (effMiscRand(0) & 1) * 0xF4,
            (u32)((uintptr_t)D_005FC900 +
                  ((unitId & 0xFFFF) * 0x1E8))),
        2);
}
// FUN_001CD6A0
void btlCameraStopEffects(void)
{
    btlCameraUpdateEffectList();
}
/* Choose an effect script based on whether all four party units remain alive. */
// FUN_001CD6C0
void btlCameraCountLiveUnits(u8 *camera)
{
    s32 liveCount;
    BtlUnit *unit;

    liveCount = 0;
    unit = (BtlUnit *)((BtlBattleState *)iGpffffb3ac)->unitLists[1];
    goto loop_cond;
loop_body:
    if ((unit->flags3 & 8) &&
        (datCalcIsDead(unit->datUnit, 0) == 0))
    {
        liveCount = (liveCount + 1) & 0xFFFF;
    }
    unit = unit->prevUnit;
loop_cond:
    if (unit != NULL)
    {
        goto loop_body;
    }
    liveCount = (liveCount & 0xFFFF) != 4;
    btlCameraStartEffect(
        camera,
        (void *)(uintptr_t)cd600Add(
            (effMiscRand(0) & 1) * 0xF4,
            (u32)((uintptr_t)D_005FDE00 + (liveCount * 0x1E8))),
        2);
}
// FUN_001CD7B0
void btlCameraStopEffectsAlt(void)
{
    btlCameraUpdateEffectList();
}
/* Build four victory orbit keyframes with successive angle and distance changes. */
// FUN_001CD7D0
void btlAct_WIN_P(BtlCamera* camera)
{
  RwV3d center;
  RwV3d transformed;
  struct {
    u8 frameBytes[0x70];
    RwMatrix matrix;
    f32 directionX;
    f32 directionY;
    f32 directionZ;
  } scratch;
  BtlUnit* unit;
  f32 radius;
  f32 halfHeight;
  f32 distance;
  f32 angle;
  s32 i;

  unit = camera->action->unit;
  btlUnitGetSphereWorldCenter(unit, &center);
  radius = unit->sphereRadius * unit->scale;
  halfHeight = 0.5f * (unit->unk_8c * unit->scale);
  center.y = 0.0f + center.y + DAT_0076112c * halfHeight;
  RtQuatTransformVectors(&transformed, &D_0060A0F0, 1, &unit->rot);
  scratch.directionX = 350.0f * transformed.x;
  scratch.directionY = 350.0f * transformed.y;
  scratch.directionZ = 350.0f * transformed.z;
  distance = (center.y + scratch.directionY) - 35.0f;
  transformed.x = (center.x + scratch.directionX) - center.x;
  transformed.y = distance - center.y;
  transformed.z = (center.z + scratch.directionZ) - center.z;
  RwV3dNormalize(&transformed, &transformed);
  if (!(radius < halfHeight))
  {
    distance = 1.75f * radius /
               tanf(DAT_00761200 * (0.5f * camera->fovRad));
  }
  else
  {
    distance = DAT_00761200 * halfHeight /
               tanf(0.5f * camera->fovRad);
  }
  angle = 65.0f;
  i = 0;
  while ((i & 0xffff) < 4)
  {
    RwMatrixRotate(&scratch.matrix, &D_0060A0E0, angle, 0);
    func_003e4320((RwV3d*)&scratch.directionX, &transformed,
                 &scratch.matrix);
    ((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.x =
        0.0f + center.x + scratch.directionX * distance;
    ((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.y =
        0.0f + center.y + scratch.directionY * distance;
    ((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.z =
        0.0f + center.z + scratch.directionZ * distance;
    if (((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.y < 5.0f)
    {
      ((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos.y = 5.0f;
    }
    btlCameraLookAtQuat(&((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].rot,
                 &((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos,
                 &center, &D_0060A0E0);
    angle = angle + -25.0f;
    distance = distance + 25.0f;
    i = (i + 1) & 0xffff;
  }
  btlCameraSetupActionGeometry((u8*)camera->action, 0, 0, 0.0f, 1);
  btlMainCurveSetFourPoses(camera, &scratch.frameBytes[0],
               &scratch.frameBytes[0x1c],
               &scratch.frameBytes[0x38],
               &scratch.frameBytes[0x54], 1);
  btlCameraSetDuration((u8*)camera, 10.0f);
}



/* Ease rotation toward the second queued action unit and update its visibility geometry. */
// FUN_001CDAF0
void btlAct_CONDITION(u8 *camera)
{
    struct CdaWork
    {
        f32 selected[4];
        BtlCameraSlerpResult slerp;
        u8 pad38[8];
        RwV3d currentPosition;
        RtQuat currentRotation;
        RwV3d targetPosition;
        f32 targetRotation[6];
        f32 transformed[4];
        f32 candidate[4];
        f32 unitPosition[4];
    } work;
    u8 *unit;
    f32 blend;
    f32 inverse;
    f32 term;
    f32 coefficient;
    f32 componentY;
    f32 sample;
    f32 weightedAngle;

    btlCameraCopyPose((f32 *)&work.currentPosition, (f32 *)&((BtlCamera *)camera)->pose);
    unit = (u8*)((BtlAction *)btlActionGetQueueSecond())->unit;
    btlUnitGetSphereWorldCenter(unit, work.unitPosition);
    work.unitPosition[1] = work.unitPosition[1] + 0.0f +
                           0.25f * (((BtlUnit *)unit)->unk_8c *
                                    ((BtlUnit *)unit)->scale);
    btlCameraLookAtQuat(work.targetRotation, &work.currentPosition,
                  work.unitPosition, &D_0060A0E0);
    work.targetPosition = work.currentPosition;
    blend = btlTargetQuatAngle((P4Vec4Holder_001EC2B0*)(&work.currentRotation), (P4Vec4Holder_001EC2B0*)(work.targetRotation));
    if (blend > fGpffff8184)
    {
        blend = fGpffff8184 / blend;
    }
    else
    {
        blend = fGpffff811c;
    }
    func_003dcc70((f32 *)&work.currentRotation, work.targetRotation,
                  &work.slerp);
    if (blend <= 0.0f)
    {
        *(F32Vec4 *)work.selected = *(F32Vec4 *)&work.currentRotation;
    }
    else
    {
        if (1.0f <= blend)
        {
            *(F32Vec4 *)work.selected = *(F32Vec4 *)work.targetRotation;
        }
        else
        {
            inverse = 1.0f - blend;
            if (work.slerp.mode == 0)
            {
                weightedAngle = inverse * work.slerp.angle;
                sample = weightedAngle * weightedAngle;
                term = fGpffff8180 * sample + fGpffff8054;
                term = sample * term + fGpffff8058;
                term = sample * term + fGpffff805c;
                term = sample * term + fGpffff8060;
                coefficient = sample * term + fGpffff8108;
                term = sample * weightedAngle;
                inverse = term * coefficient + weightedAngle;

                weightedAngle = blend * work.slerp.angle;
                sample = weightedAngle * weightedAngle;
                term = fGpffff8180 * sample + fGpffff8054;
                term = sample * term + fGpffff8058;
                term = sample * term + fGpffff805c;
                term = sample * term + fGpffff8060;
                coefficient = sample * term + fGpffff8108;
                term = sample * weightedAngle;
                blend = term * coefficient + weightedAngle;
            }
            work.selected[0] = work.slerp.current0 * inverse;
            work.selected[1] = work.slerp.current1 * inverse;
            work.selected[2] = work.slerp.current2 * inverse;
            work.selected[0] = work.slerp.next0 * blend +
                               work.selected[0];
            work.selected[1] = work.slerp.next1 * blend +
                               work.selected[1];
            work.selected[2] = work.slerp.next2 * blend +
                               work.selected[2];
            work.selected[3] = work.slerp.current3 * inverse +
                               work.slerp.next3 * blend;
        }
    }
    RtQuatTransformVectors((RwV3d*)work.transformed, &D_0060A0F0, 1, (const RtQuat*)work.selected);
    work.candidate[0] = work.currentPosition.x + work.transformed[0];
    work.candidate[1] = work.currentPosition.y + work.transformed[1];
    work.candidate[2] = work.currentPosition.z + work.transformed[2];
    btlCameraLookAtQuat(work.targetRotation, &work.currentPosition,
                  work.candidate, &D_0060A0E0);
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, (u8 *)&work.currentPosition,
                  (f32 *)work.unitPosition,
                  60.0f, 0x8c0);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&work.currentPosition,
                  (f32 *)&work.targetPosition, 1);
    btlCameraSetDuration(camera, 0.75f);
}
/* Ported from current P3FES src/Battle/btlCamera.c FUN_002b41e0
 * (0x002b41e0, donor 04d95e2). Historical donor verification is
 * recorded in the recovery note; no fresh P3 retail run is claimed.
 * Complete pose and quaternion objects retain the retail copy boundaries.
 * measured: 1336/1344 bytes; all executable bytes and relocations exact. */
/* Frame the acting unit grid center while limiting the quaternion turn. */
// FUN_001CDE50
void btlCameraFrameActionFocus(u8* camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    extern void btlCameraCopyPose(f32*, f32*);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0* right, P4Vec4Holder_001EC2B0* left);
    extern void func_003dcc70(f32*, f32*, void*);
    extern f32 tanf(f32);
    extern f32 func_003e41e0(f32*, f32*);
    extern f32 RwV3dLength(f32*);
    extern f32 fGpffff8110;
    extern f32 fGpffff811c, fGpffff80dc, fGpffff8194;
    extern f32 fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060, fGpffff8108;
    RwV3d candidate;
    RwV3d delta;
    RwV3d pointNear;
    RwV3d center;
    P4CameraVec2 horizontal;
    P4Vec4Holder_001EC2B0 blendedRot;
    P4CameraBlend blend;
    P4CameraFrame frames[2];
    u8* unit;
    f32 halfDistance;
    f32 desiredDistance;
    f32 radius;
    f32 angle;
    f32 ratio;
    f32 sideOffset;
    f32 x;
    f32 xSquared;
    f32 cube;

    unit = (u8*)((BtlAction *)(u8*)((BtlCamera *)camera)->action)->unit;
    radius = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale;
    btlCameraCopyPose((f32*)&frames[0], (f32*)&((BtlCamera *)camera)->pose);
    btlUnitGetGridSphereCenter((BtlUnit*)unit, &center);

    delta.x = frames[0].pos.x - center.x;
    delta.y = frames[0].pos.y - center.y;
    delta.z = frames[0].pos.z - center.z;
    halfDistance = RwV3dLength((f32*)&delta);
    halfDistance = halfDistance * 0.5f;
    desiredDistance = (1.5f * radius) /
                      tanf(0.5f * ((BtlCamera *)camera)->fovRad);

    RtQuatTransformVectors(&delta, (const RwV3d*)&D_0060A0F0, 1, (const RtQuat*)&((BtlUnit *)unit)->rot);
    x = 0.5f * radius;
    candidate.x = delta.x * x;
    candidate.y = delta.y * x;
    candidate.z = delta.z * x;
    pointNear.x = center.x + candidate.x;
    pointNear.y = center.y + candidate.y;
    pointNear.z = center.z + candidate.z;

    candidate.x = delta.x * desiredDistance;
    candidate.y = delta.y * desiredDistance;
    candidate.z = delta.z * desiredDistance;
    candidate.x = candidate.x + pointNear.x;
    candidate.y = candidate.y + pointNear.y;
    candidate.z = candidate.z + pointNear.z;
    candidate.y = candidate.y +
        /* measured: direct, typed-local and array scale loads give nd991/1348B; retain byte-base aliasing. */
        fGpffff811c * (((BtlUnit *)unit)->unk_8c * MEMBER(f32, unit, BtlUnit, scale));

    btlCameraLookAtQuat(&frames[1].rot, &candidate,
                 &pointNear, &D_0060A0E0);
    angle = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff80dc)
    {
        ratio = fGpffff80dc / angle;
        func_003dcc70((f32*)&frames[0].rot,
                     (f32*)&frames[1].rot,
                     &blend);
        if (ratio <= 0.0f)
        {
            blendedRot = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blendedRot = frames[1].rot;
        }
        else
        {
            f32 firstWeight;

            firstWeight = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = firstWeight * blend.scalar;
                xSquared = x * x;
                cube = xSquared * x;
                firstWeight = fGpffff8194 * xSquared + fGpffff8054;
                firstWeight = xSquared * firstWeight + fGpffff8058;
                firstWeight = xSquared * firstWeight + fGpffff805c;
                firstWeight = xSquared * firstWeight + fGpffff8060;
                firstWeight = xSquared * firstWeight + fGpffff8108;
                firstWeight = cube * firstWeight + x;

                x = ratio * blend.scalar;
                xSquared = x * x;
                ratio =
                    xSquared * x *
                    (xSquared *
                     (xSquared *
                      (xSquared *
                       (xSquared *
                        (fGpffff8194 * xSquared +
                         fGpffff8054) +
                        fGpffff8058) +
                       fGpffff805c) +
                      fGpffff8060) +
                     fGpffff8108) +
                    x;
            }

            blendedRot.quat.x =
                blend.first.quat.x * firstWeight;
            blendedRot.quat.y =
                blend.first.quat.y * firstWeight;
            blendedRot.quat.z =
                blend.first.quat.z * firstWeight;
            blendedRot.quat.x = blendedRot.quat.x +
                blend.second.quat.x * ratio;
            blendedRot.quat.y = blendedRot.quat.y +
                blend.second.quat.y * ratio;
            blendedRot.quat.z = blendedRot.quat.z +
                blend.second.quat.z * ratio;
            blendedRot.quat.w =
                blend.first.quat.w * firstWeight +
                blend.second.quat.w * ratio;
        }

        RtQuatTransformVectors(&delta, (const RwV3d*)&D_0060A100, 1, (const RtQuat*)&blendedRot);
        candidate.x = pointNear.x + delta.x;
        candidate.y = pointNear.y + delta.y;
        candidate.z = pointNear.z + delta.z;
        btlCameraLookAtQuat(&frames[1].rot, &candidate,
                     &pointNear, &D_0060A0E0);
    }

    if (halfDistance < 600.0f)
    {
        halfDistance = 600.0f;
    }
    RtQuatTransformVectors(&delta, (const RwV3d*)&D_0060A100, 1, (const RtQuat*)&frames[1].rot);
    delta.x *= halfDistance;
    delta.y *= halfDistance;
    delta.z *= halfDistance;

    sideOffset = halfDistance *
                 tanf(fGpffff8110 *
                              
                              (0.5f * cameraData->fovRad));
    sideOffset = sideOffset * 0.21875f;
    horizontal.x = delta.x;
    horizontal.y = delta.z;
    func_003e41e0((f32*)&horizontal,
                 (f32*)&horizontal);
    pointNear.x += horizontal.y * sideOffset;
    pointNear.z -= horizontal.x * sideOffset;

    frames[1].pos.x = pointNear.x + delta.x;
    frames[1].pos.y = pointNear.y + delta.y;
    frames[1].pos.z = pointNear.z + delta.z;
    btlMainCurveSetPoses((u16*)camera, (f32*)&frames[0], (f32*)&frames[1], 1);
    btlCameraSetDuration(camera, 1.25f);
}

/* Track an eligible action unit using half its scaled bounding radius. */
// FUN_001CE390
void btlCameraFrameTrackUnitScaled(u8 *camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    struct {
        f32 value;
        u8 pad[0xC];
    } center;
    u8 *unit;
    u8 *action;
    f32 scale;

    action = (u8*)((BtlCamera *)camera)->action;
    if ((action != NULL) && ((((BtlAction *)action)->unk_1a & 1) != 0)) {
        unit = (u8*)((BtlAction *)action)->unit;
        btlUnitGetSphereWorldCenter(unit, &center.value);
        scale = 0.5f * (((BtlUnit *)unit)->sphereRadius *
                        ((BtlUnit *)unit)->scale);
        
        btlCameraSetupActionGeometry((u8 *)cameraData->action, (u8 *)&((BtlCamera *)camera)->pose, (f32 *)&center.value,
                      scale, 0xC1);
    }
}
// FUN_001CE420
void btlAct_ENCOUNT(void)
{
}
// FUN_001CE430
void btlCameraSetVisibility(int cameraAddress)
{
  cameraApplyVisibility(0.0f, (u8 *)(uintptr_t)cameraAddress, 0);
}

// FUN_001D05B0
void btlCameraSetDefaultDistanceB(void* camera)
{
    btlCameraFrameActionDegrees((u8 *)camera, 45.0f, 200.0f);
}

/* Track the active action unit center with a scaled-radius visibility corridor. */
// FUN_001D05E0
void btlCameraFrameTrackUnit(u8 *camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    f32 center[3];
    u8 *unit;
    u8 *action;

    action = (u8*)((BtlCamera *)camera)->action;
    if (action != NULL) {
        if ((((BtlAction *)action)->unk_1a & 1) != 0) {
            unit = (u8*)((BtlAction *)action)->unit;
            btlUnitGetSphereWorldCenter(unit, center);
            
            btlCameraSetupActionGeometry((u8 *)cameraData->action, (u8 *)&((BtlCamera *)camera)->pose, center, 0.5f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale),
                          0xC1);
        }
    }
}
// FUN_001D0670
void btlCameraSetDefaultDistanceC(void* camera)
{
    btlCameraFrameActionDegrees((u8 *)camera, 45.0f, 200.0f);
}

/* Track the active action unit center with a scaled-radius visibility corridor. */
// FUN_001D06A0
void btlCameraFrameTrackUnitAlt(u8 *camera)
{
    BtlCamera *cameraData = (BtlCamera *)camera;
    f32 center[3];
    u8 *unit;
    u8 *action;

    action = (u8*)((BtlCamera *)camera)->action;
    if (action != NULL) {
        if ((((BtlAction *)action)->unk_1a & 1) != 0) {
            unit = (u8*)((BtlAction *)action)->unit;
            btlUnitGetSphereWorldCenter(unit, center);
            
            btlCameraSetupActionGeometry((u8 *)cameraData->action, (u8 *)&((BtlCamera *)camera)->pose, center, 0.5f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale),
                          0xC1);
        }
    }
}
/* Select the fixed third entry or one of two random entries in a preset triplet. */
// FUN_001D0730
u8 *btlCameraRandomTableEntry(s32 tableIndex, s32 useFixedEntry)
{
    if (useFixedEntry != 0) {
        return (u8 *)((s32)&D_005FE1D0 + ((((tableIndex & 0xFFFF) * 3) + 2) * 0x34));
    }
    return (u8 *)((s32)&D_005FE1D0 + ((((tableIndex & 0xFFFF) * 3) + (effMiscRand(0) & 1)) * 0x34));
}

static inline u8 *btlCamera_add_index(s32 index, u8 *base)
{
    return (u8 *)(index + (u32)base);
}

/* Round the Y/Z displacement products before adding their focus coordinates. */
static inline f32 btlCamera_product(f32 left, f32 right)
{
    return left * right;
}

/* Advance a camera script row, derive actor-relative positions/foci, and select the timing curve. */
// FUN_001D07E0
s32 btlCameraFrameActionStart(u8 *camera, u8 *work)
{
    extern u8 *btlActionFindByUnit(s32 unit);
    extern void btlUnitGetSphereCenterTowardTarget(BtlUnit *unit, BtlUnit *target, RwV3d *outPosition);
    extern void btlTargetBlendVectors(u8 *rotation, u8 *first, u8 *second);
    extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
    extern void btlUnitGetAnimBoundsWorldCenter(BtlUnit *unit, RwV3d *outPosition);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
    extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
    extern RwMatrix *RwMatrixRotate(RwMatrix *matrix, const RwV3d *axis, f32 angle, s32 mode);
    extern RwV3d *func_003e4320(RwV3d *out, const RwV3d *in, const RwMatrix *matrix);
    extern void btlMainCurveSetPoses(u16 *curve, f32 *firstPose, f32 *lastPose, u16 mode);
    extern void btlCameraSetSpringDuration(u8 *camera, f32 seconds);
    extern void btlCameraSetDuration(u8 *work, f32 value);
    extern void btlCameraSetTransitionDuration(u8 *camera, f32 seconds);
    extern RwV3d D_0060A0E0;
    extern RwV3d D_0060A0F0;
    extern RwV3d D_0060A100;
    RwV3d direction;
    RwV3d position;
    RwV3d offsetA;
    RwV3d offsetB;
    RwV3d up;
    RwV3d centerA;
    RwV3d centerB;
    P4CameraFrame poses[2];
    RwMatrix matrix;
    RtQuat rotationA;
    RtQuat rotationB;
    RwV3d transformed[2];
    RwV3d focus[2];
    u8 *base;
    s16 index;
    s16 next;
    u8 *entry;
    u8 *unit0;
    u8 *unit1;
    u8 *tmpUnit;
    f32 angle;
    u16 entryElapsed;
    s16 duration;
    u16 positionSource;
    u16 focusSource;
    BtlCameraScriptWork *scriptWork = (BtlCameraScriptWork *)work;

    if (btlCameraIsEnabled(work) == 0) {
        return 0;
    }
    base = ((BtlCameraScriptWork *)work)->script;
    index = ((BtlCameraScriptWork *)work)->index;
    if (base == NULL) {
        return 0;
    }
    if (index >= 4) {
        return 0;
    }
    if (index == -1) {
        goto next_entry;
    }
    entryElapsed = ((BtlCameraScriptWork *)work)->entryElapsed;
    duration = ((BtlCameraScriptEntry *)(btlCamera_add_index(index * 0x3C, base) + 4))->duration;
    if ((s32)entryElapsed < (s32)duration) {
        goto bump_tick;
    }
next_entry:
    next = index;
    ++next;
    if ((s32)next >= (s32)((BtlCameraScript *)base)->count) {
        goto clear_flag;
    }
    if ((u8*)((BtlCameraScriptWork *)work)->firstAction == NULL) {
        goto clear_flag;
    }
    if (btlActionFindByUnit((s32)((BtlAction *)(u8*)((BtlCameraScriptWork *)work)->firstAction)->unit) == NULL) {
        goto clear_flag;
    }
    if ((u8*)((BtlCameraScriptWork *)work)->secondAction == NULL) {
        goto clear_flag;
    }
    if (btlActionFindByUnit((s32)((BtlAction *)(u8*)((BtlCameraScriptWork *)work)->secondAction)->unit) == NULL) {
        goto clear_flag;
    }
    entry = base + next * 0x3C + 4;
    
    unit1 = (u8*)((BtlAction *)(u8 *)scriptWork->secondAction)->unit;
    unit0 = (u8*)((BtlAction *)(u8*)((BtlCameraScriptWork *)work)->firstAction)->unit;
    if (unit0 != unit1) {
        if ((((BtlCameraScriptWork *)work)->flags & 0x20) == 0) {
            btlTargetBlendVectors((u8 *)&rotationA, (u8 *)&((BtlUnit *)unit0)->pos, (u8 *)&((BtlUnit *)unit1)->pos);
            
            btlTargetBlendVectors((u8 *)&rotationB, (u8 *)&((BtlUnit *)(u8*)((BtlAction *)(u8 *)scriptWork->secondAction)->unit)->pos, (u8 *)&((BtlUnit *)(u8*)((BtlAction *)(u8*)((BtlCameraScriptWork *)work)->firstAction)->unit)->pos);
        } else {
            btlUnitGetSphereCenterTowardTarget((BtlUnit *)unit0, (BtlUnit *)unit1, &centerA);
            
            btlUnitGetSphereCenterTowardTarget(((BtlAction *)(u8 *)scriptWork->secondAction)->unit, ((BtlAction *)(u8*)((BtlCameraScriptWork *)work)->firstAction)->unit, &centerB);
            btlTargetBlendVectors((u8 *)&rotationA, (u8 *)&centerA, (u8 *)&centerB);
            btlTargetBlendVectors((u8 *)&rotationB, (u8 *)&centerB, (u8 *)&centerA);
        }
    } else {
        rotationA = ((BtlUnit *)unit0)->rot;
        tmpUnit = (u8*)((BtlAction *)(u8*)((BtlCameraScriptWork *)work)->firstAction)->unit;
        rotationB = ((BtlUnit *)tmpUnit)->rot;
    }
    offsetA = *(RwV3d *)&((BtlCameraScriptEntry *)entry)->firstPosition;
    offsetB = *(RwV3d *)&((BtlCameraScriptEntry *)entry)->secondPosition;
    if ((((BtlCameraScriptWork *)work)->flags & 2) != 0) {
        offsetA.x = offsetA.x * -1.0f;
        offsetB.x = offsetB.x * -1.0f;
    }
    positionSource = ((BtlCameraScriptEntry *)entry)->positionSource;
    switch (positionSource) {
    case 1:
        tmpUnit = (u8*)((BtlAction *)(u8*)((BtlCameraScriptWork *)work)->firstAction)->unit;
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationA);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationA);
        poses[0].pos.x = ((BtlUnit *)tmpUnit)->pos.x + transformed[0].x;
        poses[0].pos.y = ((BtlUnit *)tmpUnit)->pos.y + transformed[0].y;
        poses[0].pos.z = ((BtlUnit *)tmpUnit)->pos.z + transformed[0].z;
        poses[1].pos.x = ((BtlUnit *)tmpUnit)->pos.x + transformed[1].x;
        poses[1].pos.y = ((BtlUnit *)tmpUnit)->pos.y + transformed[1].y;
        poses[1].pos.z = ((BtlUnit *)tmpUnit)->pos.z + transformed[1].z;
        break;
    case 2:
        
        tmpUnit = (u8*)((BtlAction *)(u8 *)scriptWork->secondAction)->unit;
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationB);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationB);
        poses[0].pos.x = ((BtlUnit *)tmpUnit)->pos.x + transformed[0].x;
        poses[0].pos.y = ((BtlUnit *)tmpUnit)->pos.y + transformed[0].y;
        poses[0].pos.z = ((BtlUnit *)tmpUnit)->pos.z + transformed[0].z;
        poses[1].pos.x = ((BtlUnit *)tmpUnit)->pos.x + transformed[1].x;
        poses[1].pos.y = ((BtlUnit *)tmpUnit)->pos.y + transformed[1].y;
        poses[1].pos.z = ((BtlUnit *)tmpUnit)->pos.z + transformed[1].z;
        break;
    }
    offsetA = *(RwV3d *)&((BtlCameraScriptEntry *)entry)->firstFocus;
    offsetB = *(RwV3d *)&((BtlCameraScriptEntry *)entry)->secondFocus;
    
    if ((scriptWork->flags & 2) != 0) {
        offsetA.x = offsetA.x * -1.0f;
        offsetB.x = offsetB.x * -1.0f;
    }
    focusSource = ((BtlCameraScriptEntry *)entry)->focusSource;
    switch (focusSource) {
    case 1:
        tmpUnit = (u8*)((BtlAction *)(u8*)((BtlCameraScriptWork *)work)->firstAction)->unit;
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationA);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationA);
        focus[0].x = ((BtlUnit *)tmpUnit)->pos.x + transformed[0].x;
        focus[0].y = ((BtlUnit *)tmpUnit)->pos.y + transformed[0].y;
        focus[0].z = ((BtlUnit *)tmpUnit)->pos.z + transformed[0].z;
        focus[1].x = ((BtlUnit *)tmpUnit)->pos.x + transformed[1].x;
        focus[1].y = ((BtlUnit *)tmpUnit)->pos.y + transformed[1].y;
        focus[1].z = ((BtlUnit *)tmpUnit)->pos.z + transformed[1].z;
        break;
    case 2:
        
        tmpUnit = (u8*)((BtlAction *)(u8 *)scriptWork->secondAction)->unit;
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationB);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationB);
        focus[0].x = ((BtlUnit *)tmpUnit)->pos.x + transformed[0].x;
        focus[0].y = ((BtlUnit *)tmpUnit)->pos.y + transformed[0].y;
        focus[0].z = ((BtlUnit *)tmpUnit)->pos.z + transformed[0].z;
        focus[1].x = ((BtlUnit *)tmpUnit)->pos.x + transformed[1].x;
        focus[1].y = ((BtlUnit *)tmpUnit)->pos.y + transformed[1].y;
        focus[1].z = ((BtlUnit *)tmpUnit)->pos.z + transformed[1].z;
        break;
    case 3:
        
        tmpUnit = (u8*)((BtlAction *)(u8 *)scriptWork->secondAction)->unit;
        if ((((BtlUnit *)tmpUnit)->flags3 & 0x8000) == 0) {
            btlUnitGetAnimBoundsWorldCenter((BtlUnit *)tmpUnit, &position);
        } else {
            btlUnitGetSphereWorldCenter((BtlUnit *)tmpUnit, &position);
        }
        RtQuatTransformVectors(&direction, &D_0060A100, 1, &rotationA);
        {
            RwV3d displacement;
            displacement.x = direction.x * (((BtlUnit *)tmpUnit)->sphereRadius * ((BtlUnit *)tmpUnit)->scale);
            displacement.y = btlCamera_product(direction.y, (((BtlUnit *)tmpUnit)->sphereRadius * ((BtlUnit *)tmpUnit)->scale));
            displacement.z = btlCamera_product(direction.z, (((BtlUnit *)tmpUnit)->sphereRadius * ((BtlUnit *)tmpUnit)->scale));
            focus[0].x = 0.0f + position.x + displacement.x;
            focus[0].y = position.y + displacement.y;
            focus[0].z = position.z + displacement.z;
        }
        if (focus[0].y < 100.0f) {
            focus[0].y = 100.0f;
        } else {
            
            if ((scriptWork->flags & 8) != 0) {
                if (focus[0].y > 250.0f) {
                    focus[0].y = 250.0f;
                }
            
            } else if ((scriptWork->flags & 0x10) != 0) {
                if (focus[0].y > 500.0f) {
                    focus[0].y = 500.0f;
                }
            
            } else if (((scriptWork->flags & 4) != 0) && (focus[0].y > 150.0f)) {
                focus[0].y = 150.0f;
            }
        }
        focus[1] = focus[0];
        break;
    }
    btlCameraLookAtQuat(&poses[0].rot, &poses[0].pos, &focus[0], &D_0060A0E0);
    angle = ((BtlCameraScriptEntry *)entry)->roll;
    if (angle != 0.0f) {
        RwMatrixRotate(&matrix, &D_0060A0F0, angle, 0);
        func_003e4320(&up, &D_0060A0E0, &matrix);
    } else {
        up = D_0060A0E0;
    }
    btlCameraLookAtQuat(&poses[1].rot, &poses[1].pos, &focus[1], &up);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses[0], (f32 *)&poses[1], 1);
    switch (((BtlCameraScript *)base)->curveMode) {
    case 0:
        btlCameraSetTransitionDuration(camera, (f32)*(s16 *)entry / 30.0f);
        break;
    case 1:
        btlCameraSetSpringDuration(camera, (f32)*(s16 *)entry / 30.0f);
        break;
    case 2:
        btlCameraSetDuration(camera, (f32)*(s16 *)entry / 30.0f);
        break;
    }
    
    scriptWork->index = (s16)(index + 1);
    ((BtlCameraScriptWork *)work)->entryElapsed = 0;
    goto tick;
clear_flag:
    ((BtlCameraScriptWork *)work)->flags = (u16)(((BtlCameraScriptWork *)work)->flags & 0xFFFE);
    goto tick;
bump_tick:
    
    scriptWork->entryElapsed = (u16)(((BtlCameraScriptWork *)work)->entryElapsed + 1);
tick:
    ((BtlCameraScriptWork *)work)->elapsed = (u16)(((BtlCameraScriptWork *)work)->elapsed + 1);
    return 1;
}

/* Return bit 0 of the script-work flags. */
// FUN_001D10D0
u32 btlCameraIsEnabled(void* camera)
{
    return (((BtlCameraScriptWork *)(u8*)camera)->flags & 1) != 0;
}

/* Initialize script actors/timers and translate options into mirroring and focus-height flags. */
// FUN_001D10F0
void btlCameraInitWork(u8 *work, s32 firstAction, s32 secondAction, u8 *script, s32 options)
{
    s32 flags;
    BtlCameraScriptWork *scriptWork = (BtlCameraScriptWork *)work;

    ((BtlCameraScriptWork *)work)->firstAction = firstAction;
    ((BtlCameraScriptWork *)work)->secondAction = secondAction;
    ((BtlCameraScriptWork *)work)->script = script;
    ((BtlCameraScriptWork *)work)->elapsed = 0;
    ((BtlCameraScriptWork *)work)->index = -1;
    ((BtlCameraScriptWork *)work)->entryElapsed = 0;
    ((BtlCameraScriptWork *)work)->flags |= 1;
    ((BtlCameraScriptWork *)work)->flags &= 0xFFFD;
    flags = options & 0xFFFF;
    if ((flags & 1) && !(((BtlCameraScript *)script)->flags & 1) && (datCalcRandomBelow(0x64) >= 0x32U)) {
        
        scriptWork->flags |= 2;
    }
    if (flags & 2) {
        
        scriptWork->flags |= 4;
    }
    if (flags & 4) {
        
        scriptWork->flags |= 8;
    }
    if (flags & 8) {
        
        scriptWork->flags |= 0x10;
    }
    if (flags & 0x10) {
        
        scriptWork->flags |= 0x20;
    }
}
/* Return the current or next script row while enabled and within the four-entry limit. */
// FUN_001D1200
u8 *btlCameraGetCurrentEntry(u8 *work)
{
    /* measured: direct script-row indexing changes one byte; type the helper-addressed duration instead. */
    u8 *base;
    s16 index;
    s32 condition;

    if ((((BtlCameraScriptWork *)work)->flags & 1) == 0) {
        return 0;
    }
    base = ((BtlCameraScriptWork *)work)->script;
    index = ((BtlCameraScriptWork *)work)->index;
    if (base == 0) {
        return 0;
    }
    if (index == -1) {
        goto increment;
    }
    condition = ((BtlCameraScriptWork *)work)->entryElapsed < ((BtlCameraScriptEntry *)(btlCamera_add_index(index * 0x3C, base) + 4))->duration;
    if (condition != 0) {
        goto done;
    }
increment:
    index++;
done:
    if (((BtlCameraScript *)base)->count > index) {
        goto bound_ok;
    }
    return 0;
bound_ok:
    if (index >= 4) {
        return 0;
    }
    return base + index * 0x3C + 4;
}
/* Clear the complete 0x14-byte camera script work. */
// FUN_001D12E0
void btlCameraResetWork(void* work)
{
    FUN_0043f9c8(work, 0, 0x14);
}
