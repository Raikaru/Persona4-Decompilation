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

void btlCameraSetState(s32 state, BtlAction* action, u32 third);


BtlPacket* btlPacketAlloc(u32 id, s32 workDataSize);
u32 btlCameraUpdateSetStatePacket(void* work);

void btlCameraBuildLookAtFrame(float *first,float *second,float *third,float *fourth);
void RtQuatConvertFromMatrix(void* out, void* in);

u16 btlCameraSelectMode(void* camera);
void btlCameraFrameActionDegrees(u8* camera, f32 angle, f32 distance);
void btlCameraFrameTargetPose(u8* camera, s32 arg);
void btlCameraFrameFlagged(void* camera, s32 arg);
void btlCameraFrameRandomOrbit(void* camera, u32 arg);
void btlCameraSetLimitFrame(u8* camera, f32 suppliedLimit, s32 reverse, s32 preserveSide);
extern u8 D_005FE1D0[];
extern u32 datCalcRandomBelow(u32 value);
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
void btlCameraSetupActionGeometry(u8* second, u8* third, f32* fourth, f32 first, u16 mode);

static inline void cameraApplyVisibility(f32 radius, u8 *camera, u16 mode)
{
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, radius, mode);
}
extern f32 btlUnitGetGroupBounds(u32, u32, void*, f32*, void*, u32);
extern void btlUnitGetGridSphereCenter(BtlUnit*, RwV3d*);
extern f32 tanf(f32 x);
extern void btlUnitGetSphereWorldCenter(void *unit, void *center);
extern void btlUnitSetChildValue(BtlUnitStateWork *work, u16 value);
extern void btlUnitGetAnimBoundsWorldCenter(BtlUnit *value, RwV3d *option);
extern RwV3d* RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count,
                          const RtQuat *quat);
extern void btlMainCurveReset(u16 *value, f32 *option);
void btlMainCurveSetPoses(u16* work, f32* first, f32* second, u16 mode);
void btlCameraCopyPose(f32 *out, f32 *in);
void btlCameraFrameSlerpTarget(u8 *camera, f32 *out);
void btlCameraStartEffect(u8* camera, void* data, s32 mode);
extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0* first, P4Vec4Holder_001EC2B0* second);
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
extern void btlTargetBlendVectors(void* out, void* first, void* second);
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
void btlCameraSetDuration(u8* camera, f32 step);

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



// FUN_001BC3A0
/* Test the square arena limit (|X| or |Z| > 1500); optionally project the pose forward to the boundary. */
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



// FUN_001BC560
/* Report completion only for a visible unit with an active model animation. Remaining raw accesses preserve external records or address-carrier boundaries not represented by this object type. */
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
  else if (((u8 *)unitPtr)[0x33] == '\0') {
    result = 0;
  }
  else if ((*(u32 *)((u8 *)unitPtr + 0x98) & 2) == 0) {
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



// FUN_001BC630
/* Read bit 0x4000 of the active action skill record. The skill-table address carrier retains its external record access. */
s32 btlCameraStateRecordFlag(u8 *camera)
{
    u32 offset;

    offset = (u32)((BtlAction *)(u8 *)((BtlCamera *)camera)->action)->unk_6e * 4;
    offset += (u32)iGpffffb3bc;
    return (s32)((*(u16 *)(offset + 2) & 0x4000) != 0);
}
/* measured: no COP1 here despite the old "accumulator-chain floor" archive.
   The state-history shift is retail's dead `while ((n = i) == 0)` (beq to the
   body); the u16 counter's fresh andi on the store side needs the fused
   `[i--]` subscript (raw byte-offset forms CSE it with n, nd185), and the
   pointer-plus-index spelling with the constant last gives addu base,index. */
// FUN_001BC660
/* Select the encounter-specific camera callback, reset timing, and optionally clear unit visibility flags. Remaining raw accesses preserve external records or address-carrier boundaries not represented by this object type. */
void btlCameraSetState(s32 state, BtlAction* action, u32 clearUnitFlags)
{
    extern u8 *btlEncounterGetRecord(s32 value);
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
    if (((BtlBattleState *)iGpffffb3ac)->camera.state != stateId || *(s32 *)(entry + 8) != 0) {
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
        if (*(s32 *)(entry + 0xC) != 0) {
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
            callback(iGpffffb3ac + 0x24);
        }
    }
}
// FUN_001BC7F0
u16 btlCameraGetState(void)
{
    return ((BtlBattleState *)iGpffffb3ac)->camera.state;
}
// FUN_001BC800
/* Clear camera-held references whose action ID matches the released action. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
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

    camera = iGpffffb3ac;
    actionSlot = camera + 0x104;
    action = *(u8 **)actionSlot;
    if (action != NULL) {
        if (*(s32 *)(action + 8) == *(s32 *)(releasedAction + 8)) {
            *(u8 **)actionSlot = NULL;
        }
        camera = iGpffffb3ac;
        state = *(u16 *)(camera + 0xF4);
        switch (state) {
        case 13:
            stateActionSlot = camera + 0x124;
            stateAction = *(u8 **)stateActionSlot;
            if (stateAction != NULL &&
                *(s32 *)(stateAction + 8) == *(s32 *)(releasedAction + 8)) {
                *(u8 **)stateActionSlot = NULL;
                return;
            }
            break;
        case 20:
        case 16:
        case 18:
        case 19:
        case 42:
            stateActionSlot2 = camera + 0x158;
            stateAction2 = *(u8 **)stateActionSlot2;
            if (stateAction2 != NULL &&
                *(s32 *)(stateAction2 + 8) == *(s32 *)(releasedAction + 8)) {
                *(u8 **)stateActionSlot2 = NULL;
            }
            break;
        default:
            break;
        }
    }
}
// FUN_001BC8E0
/* Apply a queued camera-state change and finish the packet. */
u32 btlCameraUpdateSetStatePacket(void* work)
{
    BtlCameraPacketSetState* packet;

    packet = (BtlCameraPacketSetState*)work;

    btlCameraSetState(packet->state, packet->action, 1);

    return 1;
}



// FUN_001BC920
/* Allocate a state-change packet carrying the action and 16-bit state. */
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



// FUN_001BD560
/* Copy position and all four quaternion lanes of a contiguous camera pose. */
void btlCameraCopyPose(f32 *destination, f32 *source)
{
    ((BtlCameraPose *)destination)->pos = ((BtlCameraPose *)source)->pos;
    ((BtlCameraPose *)destination)->rot = ((BtlCameraPose *)source)->rot;
}
// FUN_001BD5A0
/* Copy a complete pose into the camera snapshot. */
void btlCameraCopyPoseSnapshot(f32 *destination, f32 *source)
{
    ((BtlCameraPose *)destination)->pos = ((BtlCameraPose *)source)->pos;
    ((BtlCameraPose *)destination)->rot = ((BtlCameraPose *)source)->rot;
}
// FUN_001BD5E0
/* Copy a complete pose into the camera target. */
void btlCameraCopyPoseTarget(f32 *destination, f32 *source)
{
    ((BtlCameraPose *)destination)->pos = ((BtlCameraPose *)source)->pos;
    ((BtlCameraPose *)destination)->rot = ((BtlCameraPose *)source)->rot;
}

// FUN_001BD620
/* Build an orthonormal look-at matrix from eye, target, and supplied up vector. Raw matrix-vector stores retain the existing 16-byte row stride. */
void btlCameraBuildLookAtFrame(float *matrix,float *target,float *eye,float *up)
{
  extern float RwV3dNormalize();
  RwV3d forward;
  RwV3d right;
  RwV3d correctedUp;

  *(RwV3d*)(matrix + 0xc) = *(RwV3d*)eye;
  forward.x = *target - *eye;
  forward.y = target[1] - eye[1];
  forward.z = target[2] - eye[2];
  RwV3dNormalize(&forward,&forward);
  *(RwV3d*)(matrix + 8) = forward;
  right.x = up[1] * forward.z - up[2] * forward.y;
  right.y = up[2] * forward.x - *up * forward.z;
  right.z = *up * forward.y - up[1] * forward.x;
  RwV3dNormalize(&right,&right);
  *(RwV3d*)matrix = right;
  correctedUp.x = forward.y * right.z - forward.z * right.y;
  correctedUp.y = forward.z * right.x - forward.x * right.z;
  correctedUp.z = forward.x * right.y - forward.y * right.x;
  *(RwV3d*)(matrix + 4) = correctedUp;
  return;
}



// FUN_001BD780
/* Build the look-at basis and convert its matrix to a quaternion. */
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
// FUN_001BE050
/* Frame the acting unit while limiting angular change using near/far degree thresholds. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameActionDegrees(u8 *camera, f32 nearDegrees, f32 farDegrees)
{
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

    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    radius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &center);
    x = *(f32 *)(unit + 0x2C);
    height = *(f32 *)(unit + 0x8C) * x;
    middleY = center.y + 0.5f * height;
    if (radius < 180.0f) {
        center.y += fGpffff8118 * height;
        desiredDistance = (1.5f * radius) / tanf(0.5f * *(f32 *)(camera + 0xB8));
    } else {
        center.y += 0.25f * height;
        desiredDistance = (2.5f * radius) / tanf(0.5f * *(f32 *)(camera + 0xB8));
    }
    delta.x = frames[0].pos.x - center.x;
    delta.y = frames[0].pos.y - center.y;
    delta.z = frames[0].pos.z - center.z;
    halfDistance = RwV3dLength(&delta);
    halfDistance *= fGpffff8140;
    if (!(desiredDistance <= halfDistance)) halfDistance = desiredDistance;
    RtQuatTransformVectors(&delta, &D_0060A0F0, 1, (const RtQuat *)(unit + 0x1C));
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
    candidate.y += fGpffff8128 * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
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
            u16 mode = *(u16 *)(camera + 0xE4);
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
    sideOffset = halfDistance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
// FUN_001C09B0
/* Ease the current camera toward the action unit anchor, limiting angular change. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameActionTarget(u8* camera)
{
    extern void btlCameraCopyPose(f32*, f32*);
    extern RwV3d D_0060A100;
    extern void btlUnitGetAnchorPose(u8*, u8*, f32*, f32*);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0* first, P4Vec4Holder_001EC2B0* second);
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

    unit = *(u8**)(*(u8**)(camera + 0xe0) + 0x30);
    btlCameraCopyPose((f32*)&frames[0], (f32*)(camera + 0x9c));
    btlUnitGetAnchorPose(unit, (u8*)&center, NULL, NULL);
    height = *(f32*)(unit + 0x84) * *(f32*)(unit + 0x2c);
    height += fGpffff8118 * (*(f32*)(unit + 0x8c) * *(f32*)(unit + 0x2c));
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
    dist = 375 / tanf(fGpffff8110 * (0.5f * *(f32*)(camera + 0xb8)));
    eyeAdj.x = eyeAdj.x * dist;
    eyeAdj.y = eyeAdj.y * dist;
    eyeAdj.z = eyeAdj.z * dist;
    sideOffset = dist * tanf(fGpffff8110 * (0.5f * *(f32*)(camera + 0xb8)));
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

// FUN_001C6560
/* Select a framing mode and invoke its setup handler. */
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



// FUN_001C6650
/* Update tracking geometry or restore the orbit unit value once animation completes. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraUpdateFrameForState(u8 *camera)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } center;
    u16 state;
    u8 *unit;
    u8 *orbitAction;
    u8 *action;
    f32 scale;

    state = *(u16 *)(camera + 0x110);
    switch (state) {
    case 1:
        action = *(u8 **)(camera + 0xE0);
        if ((action != NULL) && ((*(u16 *)(action + 0x1A) & 1) != 0)) {
            unit = *(u8 **)(action + 0x30);
            btlUnitGetSphereWorldCenter(unit, &center.value);
            scale = 0.5f * (*(f32 *)(unit + 0x90) *
                            *(f32 *)(unit + 0x2C));
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), camera + 0x9C, (f32 *)&center.value,
                          scale, 0xC1);
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    case 6:
        orbitAction = *(u8 **)(camera + 0xE0);
        if ((orbitAction != NULL) &&
            ((*(u16 *)(orbitAction + 0x1A) & 1) != 0) &&
            (btlCameraUnitAnimFinished((BtlCamera *)camera, *(u32 *)(camera + 0x12C)) != 0)) {
            btlUnitSetChildValue(*(BtlUnitStateWork **)(camera + 0x12C),
                          *(u16 *)(camera + 0x130));
        }
        break;
    default:
        break;
    }
}
// FUN_001C6760
/* Construct two opposite-angle orbit poses around the acting unit. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
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

  cameraAddress = (int)camera;
  unitBytes = (u8 *)(uintptr_t)*(int *)(*(int *)(cameraAddress + 0xe0) + 0x30);
  btlUnitGetSphereWorldCenter((BtlUnit *)unitBytes, &scratch.sphereCenter.value);
  radius = *(float *)(unitBytes + 0x90) * *(float *)(unitBytes + 0x2c);
  halfHeight = *(float *)(unitBytes + 0x8c) * *(float *)(unitBytes + 0x2c) * 0.5f;
  centerXY = *(volatile /* Removing this function's qualifier batch loses func_001c6760 (MATCH nd0 -> MISMATCH nd6, size 936 -> 936) - measured W170. */ u64 *)&scratch.sphereCenter.value;
  centerZ = *(volatile /* Removing this function's qualifier batch loses func_001c6760 (MATCH nd0 -> MISMATCH nd6, size 936 -> 936) - measured W170. */ f32 *)&scratch.sphereCenter.value.z;
  *(u64 *)&scratch.center.value = centerXY;
  scratch.center.value.z = centerZ;
  scratch.center.value.y = halfHeight * heightScale + scratch.center.value.y;
  if (radius > halfHeight) {
    requiredDistance = (radius * distanceScale) /
      tanf(DAT_00761200 * (*(float *)(cameraAddress + 0xb8) * 0.5f));
  } else {
    requiredDistance = (halfHeight * distanceScale) /
      tanf(*(float *)(cameraAddress + 0xb8) * 0.5f);
  }
  if (requiredDistance < minimumDistance) {
    requiredDistance = minimumDistance;
  }
  RtQuatTransformVectors(&scratch.forward.value, &D_0060A0F0, 1, (void *)(unitBytes + 0x1c));
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
  btlCameraSetupActionGeometry(*(u8 **)(cameraAddress + 0xe0), NULL, NULL, 0.0f, 1);
  btlMainCurveSetPoses((u16 *)camera, (f32 *)&scratch.firstPosition, (f32 *)&scratch.secondPosition, 1);
  btlCameraSetDuration((u8 *)camera, 3.5f);
}



// FUN_001C6B10
void btlCameraFrameOrbitTight(void* camera)
{
  btlCameraFrameOrbit(camera,10.0f,2.0f,0.0f,250.0f);
  return;
}



// FUN_001C6B50
void func_001c6b50(void)
{
}
// FUN_001C6B60
void btlAct_SKILL_EXEC_ONE(void* camera)
{
    btlCameraFrameOrbit(camera, 15.0f, 2.0f, 0.25f, 400.0f);
}
// FUN_001C6BA0
void func_001c6ba0(void)
{
}
// FUN_001C6BB0
void btlCameraResetToDefault(void *camera)
{
    btlCameraEnterRandomFrame(camera, 1);
}
// FUN_001C6BE0
void func_001c6be0(void)
{
}
// FUN_001C6BF0
/* Construct a short orbit around the first target unit and clamp both poses above the floor. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameOrbitUnit(u8 *camera)
{
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

    targetUnit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x38);
    targetUnit = *(u8 **)(targetUnit + 0x30);
    btlUnitGetAnimBoundsWorldCenter((BtlUnit *)targetUnit, (RwV3d *)&work.center.x);
    work.center.y = 0.0f + work.center.y +
                    DAT_00761278 *
                    (*(f32 *)(targetUnit + 0x8C) *
                     *(f32 *)(targetUnit + 0x2C));
    RtQuatTransformVectors(&work.direction, &D_0060A0F0, 1, (const RtQuat*)(targetUnit + 0x1C));
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
                      (0.5f * *(f32 *)(camera + 0xB8)));
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
                      (0.5f * *(f32 *)(camera + 0xB8)));
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
    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 2);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&work.firstPosition, (f32 *)&work.secondPosition, 1);
    btlCameraSetDuration(camera, 1.5f);
}
// FUN_001C6F30
void func_001c6f30(void)
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
// FUN_001C6F40
/* Build current/target poses framing the acting unit against the group bounds. */
u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                 P4CameraFrame *firstOut, P4CameraFrame *secondOut)
{
    extern RwV3d D_0060A0D0;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
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
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)(camera + 0x9C));
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

// FUN_001C73E0
/* Reset immediately for incompatible prior states; otherwise interpolate the frame pair. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraApplyFrameTransition(u8 *camera)
{
    P4CameraFrame frames[2];
    s32 resetImmediately;
    u16 previousState;

    previousState = *(u16 *)(iGpffffb3ac + 0x108);
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
    if (*(s32 *)(camera + 0x148) != 0)
    {
        resetImmediately = 1;
        *(s32 *)(camera + 0x148) = 0;
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
void func_001c7500(void)
{
}
// FUN_001C7510
/* Move from an offset pose toward the acting unit using its projected size. Raw aggregate copies preserve the packed pose/vector scratch layout. */
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
  *(F32Vec4 *)(posesAndVectors + 10) = *(F32Vec4 *)(posesAndVectors + 3);
  posesAndVectors[7] = posesAndVectors[20] * distance + centerX;
  posesAndVectors[8] = posesAndVectors[21] * distance + centerY;
  posesAndVectors[9] = posesAndVectors[22] * distance + centerZ;
  btlCameraSetupActionGeometry((u8 *)camera->action, 0, 0, 0.0f, 1);
  btlMainCurveSetPoses((u16 *)camera, (f32 *)posesAndVectors, (f32 *)(posesAndVectors + 7), 1);
  btlCameraSetDuration((u8 *)camera, 2.5f);
}



// FUN_001C7770
void func_001c7770(void)
{
}

// FUN_001C7780
/* Traverse the acting-unit pose pair in the opposite order with wider framing. Raw aggregate copies preserve the packed pose/vector scratch layout. */
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
  *(F32Vec4 *)(posesAndVectors + 10) = *(F32Vec4 *)(posesAndVectors + 3);
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

// FUN_001CBFE0
/* Apply the next preset while the current action still owns the same single target. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraSelectPreset(int cameraAddress)
{
  int actionAddress;
  f32 speed;

  actionAddress = *(int *)(cameraAddress + 0xe0);
  if ((((actionAddress != 0) && (*(u16 *)(actionAddress + 0x6a) == 1)) &&
      (*(int *)(cameraAddress + 0x100) == *(int *)(actionAddress + 0x38))) && ((*(u16 *)(actionAddress + 0x1a) & 1) != 0)
     ) {
    if (*(u16 *)(cameraAddress + 0x10e) <= *(u16 *)(cameraAddress + 0x10c)) {
      speed = (*(int *)(cameraAddress + 0x108) != 0) ? DAT_00761254 : DAT_00761188;
    }
    else {
      speed = DAT_00761258;
    }
    btlCameraApplyPreset((u8*)cameraAddress, speed, *(u16 *)(cameraAddress + 0x10c) == 0);
    *(short *)(cameraAddress + 0x10c) = *(u16 *)(cameraAddress + 0x10c) + 1;
  }
  return;
}



extern f32 fGpffff8118;
extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *out);
extern f32 RwV3dLength(f32 *vector);
extern RwV3d D_0060A0D0;

// FUN_001CC0A0
/* Measured: 1300 executable bytes, 23 resolved relocations, twelve zero
   alignment bytes. Both aggregates contain only initialized live values. */
/* Frame actor and first target using their relative heights and horizontal directions. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameFreshPose(u8 *camera)
{
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

    cameraWork = *(u8 **)(camera + 0xE0);
    actor1 = *(u8 **)(cameraWork + 0x30);
    flag = *(u8 *)(actor1 + 0xA2);
    actor2 = *(u8 **)(*(u8 **)(cameraWork + 0x38) + 0x30);

    scale2 = *(f32 *)(actor2 + 0x90) * *(f32 *)(actor2 + 0x2C);

    btlUnitGetSphereWorldCenter(actor2, (f32 *)&pos2);
    btlUnitGetSphereWorldCenter(actor1, (f32 *)&pos1);

    if (pos2.y > pos1.y) {
        pos2.y = (0.0f + pos2.y) - (*(f32 *)(actor2 + 0x8C) * *(f32 *)(actor2 + 0x2C)) * fGpffff8118;
        pos1.y = (0.0f + pos1.y) + (*(f32 *)(actor1 + 0x8C) * *(f32 *)(actor1 + 0x2C)) * DAT_00761278;
    } else {
        factor = *(f32 *)(actor2 + 0x8C) * *(f32 *)(actor2 + 0x2C);
        pos2.y = (0.0f + pos2.y) + fGpffff8118 * factor;
        pos1.y = (0.0f + pos1.y) - fGpffff8118 * (*(f32 *)(actor1 + 0x8C) * *(f32 *)(actor1 + 0x2C));
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

    dir.x = pos2.x - *(f32 *)(camera + 0x9C);
    dir.y = pos2.y - *(f32 *)(camera + 0xA0);
    dir.z = pos2.z - *(f32 *)(camera + 0xA4);

    xz.dir1XZ[0] = dir.x;
    xz.dir1XZ[1] = dir.z;
    func_003e41e0(xz.dir1XZ, xz.dir1XZ);

    RtQuatTransformVectors(&dir, &D_0060A0D0, 1, (const RtQuat*)(actor2 + 0x1C));

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

    tanVal = tanf(DAT_00761200 * (0.5f * *(f32 *)(camera + 0xB8)));
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

    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), (u8 *)&work.pos, (f32 *)&target, 400.0f, 3);
    btlMainCurveReset((u16 *)(camera), (f32 *)(&work.pos));
}
// FUN_001CC5C0
void func_001cc5c0(void)
{
}
// FUN_001CC5D0
/* Build a group-target pose with bounded quaternion interpolation and a minimum distance. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameSlerpTarget(u8 *camera, f32 *out)
{
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
                               (0.5f * *(f32 *)(camera + 0xB8)));
    angleScale = value / angleScale;
    work.position[0] = 0.0f;
    work.position[1] = work.distance;
    work.position[2] = -value;
    btlCameraLookAtQuat(out + 3, work.position, work.target, &D_0060A0E0);
    blend = btlTargetQuatAngle((P4Vec4Holder_001EC2B0*)(camera + 0xA8), (P4Vec4Holder_001EC2B0*)(out + 3));
    if (blend > fGpffff80d8[1]) {
        blend = fGpffff80d8[1] / blend;
        func_003dcc70((f32 *)(camera + 0xA8), out + 3, &work.result);
        if (blend <= 0.0f) {
            sample = *(f32 *)(camera + 0xA8);
            componentY = *(f32 *)(camera + 0xAC);
            coefficient = *(f32 *)(camera + 0xB0);
            term = *(f32 *)(camera + 0xB4);
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
                                (0.5f * *(f32 *)(camera + 0xB8)));
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
// FUN_001CC9E0
/* Interpolate from the current pose to the group-target framing over ten seconds. */
void btlAct_TARGET(u8 *camera)
{
    struct C9Work {
        f32 first[7];
        f32 second[7];
    } work;

    btlCameraCopyPose(work.first, (f32 *)(camera + 0x9C));
    btlCameraFrameSlerpTarget(camera, work.second);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)work.first, (f32 *)work.second, 1);
    btlCameraSetDuration(camera, 10.0f);
}
// FUN_001CCA50
void func_001cca50(void)
{
}

// FUN_001CCA60
/* Fit group bounds and the selected unit, then clamp the resulting pose to arena limits. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
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

    cameraAddress = (int)camera;
    unitAddress = *(int*)(cameraAddress + 0xe0);
    if (unitAddress != 0)
    {
        unitAddress = *(int*)(unitAddress + 0x30);
    }
    else
    {
        unitAddress = *(int*)(*(int*)(iGpffffb3ac + 0x170) + 0x30);
    }
    distance = btlUnitGetGroupBounds(3, 1, &scratch.target, &height, 0, 1);
    btlUnitGetGridSphereCenter((BtlUnit*)unitAddress, &scratch.pos);
    scratch.target.y = 0.0f;
    scratch.pos.y = 0.0f;
    if ((scratch.pos.x == scratch.target.x) &&
        (scratch.pos.z == scratch.target.z))
    {
        btlUnitGetGridSphereCenter((BtlUnit*)*(int*)(*(int*)(iGpffffb3ac + 0x170) + 0x30),
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
                  (*(f32*)(unitAddress + 0x8c) *
                   *(f32*)(unitAddress + 0x2c));
    norm = fGpffff8170 * height;
    norm = (!(norm > minDistance)) ? minDistance : norm;
    scratch.pos.y = norm;
    btlCameraLookAtQuat(&scratch.unk, &scratch.pos, &scratch.target, &D_0060A0E0);
    minDistance = (0.75f * distance) /
                  tanf(fGpffff8110 *
                                 (0.5f * *(f32*)(cameraAddress + 0xb8)));
    scratch.diff.x = scratch.pos.x - scratch.target.x;
    scratch.diff.y = scratch.pos.y - scratch.target.y;
    scratch.diff.z = scratch.pos.z - scratch.target.z;
    norm = RwV3dNormalize((RwV3d *)&scratch.diff.x, (const RwV3d *)&scratch.diff.x);
    distance = tanf(fGpffff8110 *
                             (0.5f * *(f32*)(cameraAddress + 0xb8)));
    candidate = norm +
                (*(f32*)(unitAddress + 0x90) *
                 *(f32*)(unitAddress + 0x2c) * 2.0f) /
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
    btlCameraCopyPoseSnapshot((f32*)(cameraAddress + 0x9c), (f32*)&scratch.out);
}
// FUN_001CCDA0
void func_001ccda0(void)
{
}
/* The battle-start mode is 0..2 (001ef8c0); the group queries require
 * nonempty eligible unit sets. Three complete poses retain the first,
 * interpolated and final camera frames consumed by 001baff0.
 * measured b210 -O2: 2124/2128 bytes, four zero alignment bytes.
 * Whole quaternion assignment preserves the grouped copy; strict >1
 * participant tests retain the retail large-angle-first branch layout. */
// FUN_001CCDB0
/* Build the battle-opening camera sequence according to opening side and participant count. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlAct_NOP(u8 *camera)
{
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, RwV3d *);
    extern f32 btlUnitGetGroupBounds(u32, u32, RwV3d *, f32 *, f32 *, u32);
    extern void mdlBlendTranslationRotation(f32 *out, f32 *first, f32 *second, f32 weight);
    extern void btlMainCurveSetThreePoses(u16 *camera, f32 *first, f32 *middle, f32 *last, u16 mode);
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

    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
        switch (*(u16 *)(iGpffffb3ac + 0x1A)) {
        case 0:
        case 1:
            distance = btlUnitGetGroupBounds(3, 0, NULL, &height, NULL, 0);
            btlUnitGetGroupBounds(2, 0, &groupCenter, NULL, NULL, 0);
            groupCenter.y = 0.25f * height;
            btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
            unitCenter.y = 0.0f + unitCenter.y - fGpffff803c *
                           (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
            btlCameraLookAtQuat(&frames[0].rot, &unitCenter, &groupCenter, &D_0060A0E0);
            distance = (0.75f * distance) /
                       tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
            if (*(u8 *)(iGpffffb3ac + 0xC64) > 1) {
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
            unitCenter.y = fGpffff8030 * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
            btlCameraLookAtQuat(&frames[0].rot, &unitCenter, &groupCenter, &D_0060A0E0);
            direction.x = unitCenter.x - groupCenter.x;
            direction.y = unitCenter.y - groupCenter.y;
            direction.z = unitCenter.z - groupCenter.z;
            distance = RwV3dLength(&direction);
            distance += (4.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C))) /
                        tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
            unitCenter.y = *(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C);
            direction.x = unitCenter.x - groupCenter.x;
            direction.y = unitCenter.y - groupCenter.y;
            direction.z = unitCenter.z - groupCenter.z;
            distance = RwV3dLength(&direction);
            distance += (5.0f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C))) /
                        tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
            btlCameraLookAtQuat(&frames[2].rot, &unitCenter, &groupCenter, &D_0060A0E0);
            if (*(u8 *)(iGpffffb3ac + 0xC64) > 1) {
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
                   tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        if (*(u8 *)(iGpffffb3ac + 0xC64) > 1) {
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
    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 1);
    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
    btlMainCurveSetThreePoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], (f32 *)&frames[2], 1);
    btlCameraSetDuration(camera, duration);
}
// FUN_001CD600
/* Choose one of two effect scripts for the acting unit ID. */
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
// FUN_001CD6C0
/* Choose an effect script based on whether all four party units remain alive. */
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
// FUN_001CD7D0
/* Build four victory orbit keyframes with successive angle and distance changes. */
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



// FUN_001CDAF0
/* Ease rotation toward the second queued action unit and update its visibility geometry. Remaining raw accesses preserve external records or address-carrier boundaries not represented by this object type. */
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

    btlCameraCopyPose((f32 *)&work.currentPosition, (f32 *)(camera + 0x9c));
    unit = *(u8 **)(btlActionGetQueueSecond() + 0x30);
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
// FUN_001CDE50
/* Frame the acting unit grid center while limiting the quaternion turn. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameActionFocus(u8* camera)
{
    extern void btlCameraCopyPose(f32*, f32*);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0* first, P4Vec4Holder_001EC2B0* second);
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

    unit = *(u8**)(*(u8**)(camera + 0xe0) + 0x30);
    radius = *(f32*)(unit + 0x90) * *(f32*)(unit + 0x2c);
    btlCameraCopyPose((f32*)&frames[0], (f32*)(camera + 0x9c));
    btlUnitGetGridSphereCenter((BtlUnit*)unit, &center);

    delta.x = frames[0].pos.x - center.x;
    delta.y = frames[0].pos.y - center.y;
    delta.z = frames[0].pos.z - center.z;
    halfDistance = RwV3dLength((f32*)&delta);
    halfDistance = halfDistance * 0.5f;
    desiredDistance = (1.5f * radius) /
                      tanf(0.5f * *(f32*)(camera + 0xb8));

    RtQuatTransformVectors(&delta, (const RwV3d*)&D_0060A0F0, 1, (const RtQuat*)(unit + 0x1c));
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
        fGpffff811c * (*(f32*)(unit + 0x8c) * *(f32*)(unit + 0x2c));

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
                              (0.5f * *(f32*)(camera + 0xb8)));
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

// FUN_001CE390
/* Track an eligible action unit using half its scaled bounding radius. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameTrackUnitScaled(u8 *camera)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } center;
    u8 *unit;
    u8 *action;
    f32 scale;

    action = *(u8 **)(camera + 0xE0);
    if ((action != NULL) && ((*(u16 *)(action + 0x1A) & 1) != 0)) {
        unit = *(u8 **)(action + 0x30);
        btlUnitGetSphereWorldCenter(unit, &center.value);
        scale = 0.5f * (*(f32 *)(unit + 0x90) *
                        *(f32 *)(unit + 0x2C));
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), camera + 0x9C, (f32 *)&center.value,
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

// FUN_001D05E0
/* Track the active action unit center with a scaled-radius visibility corridor. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameTrackUnit(u8 *camera)
{
    f32 center[3];
    u8 *unit;
    u8 *action;

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL) {
        if ((*(u16 *)(action + 0x1A) & 1) != 0) {
            unit = *(u8 **)(action + 0x30);
            btlUnitGetSphereWorldCenter(unit, center);
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), camera + 0x9C, center, 0.5f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)),
                          0xC1);
        }
    }
}
// FUN_001D0670
void btlCameraSetDefaultDistanceC(void* camera)
{
    btlCameraFrameActionDegrees((u8 *)camera, 45.0f, 200.0f);
}

// FUN_001D06A0
/* Track the active action unit center with a scaled-radius visibility corridor. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraFrameTrackUnitAlt(u8 *camera)
{
    f32 center[3];
    u8 *unit;
    u8 *action;

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL) {
        if ((*(u16 *)(action + 0x1A) & 1) != 0) {
            unit = *(u8 **)(action + 0x30);
            btlUnitGetSphereWorldCenter(unit, center);
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), camera + 0x9C, center, 0.5f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C)),
                          0xC1);
        }
    }
}
// FUN_001D0730
/* Select the fixed third entry or one of two random entries in a preset triplet. */
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

// FUN_001D07E0
/* Advance a camera script row, derive actor-relative positions/foci, and select the timing curve. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
s32 btlCameraFrameActionStart(u8 *camera, u8 *work)
{
    extern u8 *btlActionFindByUnit(s32 camera);
    extern void btlUnitGetSphereCenterTowardTarget(BtlUnit *unit, BtlUnit *target, RwV3d *out);
    extern void btlTargetBlendVectors(u8 *out, u8 *first, u8 *second);
    extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
    extern void btlUnitGetAnimBoundsWorldCenter(BtlUnit *unit, RwV3d *out);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
    extern RwMatrix *RwMatrixRotate(RwMatrix *matrix, const RwV3d *axis, f32 angle, s32 mode);
    extern RwV3d *func_003e4320(RwV3d *out, const RwV3d *in, const RwMatrix *matrix);
    extern void btlMainCurveSetPoses(u16 *camera, f32 *first, f32 *second, u16 mode);
    extern void btlCameraSetSpringDuration(u8 *camera, f32 work);
    extern void btlCameraSetDuration(u8 *camera, f32 work);
    extern void btlCameraSetTransitionDuration(u8 *camera, f32 work);
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

    if (btlCameraIsEnabled(work) == 0) {
        return 0;
    }
    base = *(u8 **)(work + 0x10);
    index = *(s16 *)(work + 0xA);
    if (base == NULL) {
        return 0;
    }
    if (index >= 4) {
        return 0;
    }
    if (index == -1) {
        goto next_entry;
    }
    entryElapsed = *(u16 *)(work + 0xC);
    duration = *(s16 *)(btlCamera_add_index(index * 0x3C, base) + 4);
    if ((s32)entryElapsed < (s32)duration) {
        goto bump_tick;
    }
next_entry:
    next = index;
    ++next;
    if ((s32)next >= (s32)*(u8 *)base) {
        goto clear_flag;
    }
    if (*(u8 **)(work + 0) == NULL) {
        goto clear_flag;
    }
    if (btlActionFindByUnit(*(s32 *)(*(u8 **)(work + 0) + 0x30)) == NULL) {
        goto clear_flag;
    }
    if (*(u8 **)(work + 4) == NULL) {
        goto clear_flag;
    }
    if (btlActionFindByUnit(*(s32 *)(*(u8 **)(work + 4) + 0x30)) == NULL) {
        goto clear_flag;
    }
    entry = base + next * 0x3C + 4;
    unit1 = *(u8 **)(*(u8 **)(work + 4) + 0x30);
    unit0 = *(u8 **)(*(u8 **)(work + 0) + 0x30);
    if (unit0 != unit1) {
        if ((*(u16 *)(work + 0xE) & 0x20) == 0) {
            btlTargetBlendVectors((u8 *)&rotationA, (u8 *)(unit0 + 4), (u8 *)(unit1 + 4));
            btlTargetBlendVectors((u8 *)&rotationB, (u8 *)(*(u8 **)(*(u8 **)(work + 4) + 0x30) + 4), (u8 *)(*(u8 **)(*(u8 **)(work + 0) + 0x30) + 4));
        } else {
            btlUnitGetSphereCenterTowardTarget((BtlUnit *)unit0, (BtlUnit *)unit1, &centerA);
            btlUnitGetSphereCenterTowardTarget(*(BtlUnit **)(*(u8 **)(work + 4) + 0x30), *(BtlUnit **)(*(u8 **)(work + 0) + 0x30), &centerB);
            btlTargetBlendVectors((u8 *)&rotationA, (u8 *)&centerA, (u8 *)&centerB);
            btlTargetBlendVectors((u8 *)&rotationB, (u8 *)&centerB, (u8 *)&centerA);
        }
    } else {
        rotationA = *(RtQuat *)(unit0 + 0x1C);
        tmpUnit = *(u8 **)(*(u8 **)(work + 0) + 0x30);
        rotationB = *(RtQuat *)(tmpUnit + 0x1C);
    }
    offsetA = *(RwV3d *)(entry + 4);
    offsetB = *(RwV3d *)(entry + 16);
    if ((*(u16 *)(work + 0xE) & 2) != 0) {
        offsetA.x = offsetA.x * -1.0f;
        offsetB.x = offsetB.x * -1.0f;
    }
    positionSource = *(u16 *)(entry + 2);
    switch (positionSource) {
    case 1:
        tmpUnit = *(u8 **)(*(u8 **)(work + 0) + 0x30);
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationA);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationA);
        poses[0].pos.x = *(f32 *)(tmpUnit + 4) + transformed[0].x;
        poses[0].pos.y = *(f32 *)(tmpUnit + 8) + transformed[0].y;
        poses[0].pos.z = *(f32 *)(tmpUnit + 12) + transformed[0].z;
        poses[1].pos.x = *(f32 *)(tmpUnit + 4) + transformed[1].x;
        poses[1].pos.y = *(f32 *)(tmpUnit + 8) + transformed[1].y;
        poses[1].pos.z = *(f32 *)(tmpUnit + 12) + transformed[1].z;
        break;
    case 2:
        tmpUnit = *(u8 **)(*(u8 **)(work + 4) + 0x30);
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationB);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationB);
        poses[0].pos.x = *(f32 *)(tmpUnit + 4) + transformed[0].x;
        poses[0].pos.y = *(f32 *)(tmpUnit + 8) + transformed[0].y;
        poses[0].pos.z = *(f32 *)(tmpUnit + 12) + transformed[0].z;
        poses[1].pos.x = *(f32 *)(tmpUnit + 4) + transformed[1].x;
        poses[1].pos.y = *(f32 *)(tmpUnit + 8) + transformed[1].y;
        poses[1].pos.z = *(f32 *)(tmpUnit + 12) + transformed[1].z;
        break;
    }
    offsetA = *(RwV3d *)(entry + 32);
    offsetB = *(RwV3d *)(entry + 44);
    if ((*(u16 *)(work + 0xE) & 2) != 0) {
        offsetA.x = offsetA.x * -1.0f;
        offsetB.x = offsetB.x * -1.0f;
    }
    focusSource = *(u16 *)(entry + 28);
    switch (focusSource) {
    case 1:
        tmpUnit = *(u8 **)(*(u8 **)(work + 0) + 0x30);
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationA);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationA);
        focus[0].x = *(f32 *)(tmpUnit + 4) + transformed[0].x;
        focus[0].y = *(f32 *)(tmpUnit + 8) + transformed[0].y;
        focus[0].z = *(f32 *)(tmpUnit + 12) + transformed[0].z;
        focus[1].x = *(f32 *)(tmpUnit + 4) + transformed[1].x;
        focus[1].y = *(f32 *)(tmpUnit + 8) + transformed[1].y;
        focus[1].z = *(f32 *)(tmpUnit + 12) + transformed[1].z;
        break;
    case 2:
        tmpUnit = *(u8 **)(*(u8 **)(work + 4) + 0x30);
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationB);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationB);
        focus[0].x = *(f32 *)(tmpUnit + 4) + transformed[0].x;
        focus[0].y = *(f32 *)(tmpUnit + 8) + transformed[0].y;
        focus[0].z = *(f32 *)(tmpUnit + 12) + transformed[0].z;
        focus[1].x = *(f32 *)(tmpUnit + 4) + transformed[1].x;
        focus[1].y = *(f32 *)(tmpUnit + 8) + transformed[1].y;
        focus[1].z = *(f32 *)(tmpUnit + 12) + transformed[1].z;
        break;
    case 3:
        tmpUnit = *(u8 **)(*(u8 **)(work + 4) + 0x30);
        if ((*(u32 *)(tmpUnit + 0x9C) & 0x8000) == 0) {
            btlUnitGetAnimBoundsWorldCenter((BtlUnit *)tmpUnit, &position);
        } else {
            btlUnitGetSphereWorldCenter((BtlUnit *)tmpUnit, &position);
        }
        RtQuatTransformVectors(&direction, &D_0060A100, 1, &rotationA);
        {
            RwV3d displacement;
            displacement.x = direction.x * (*(f32 *)(tmpUnit + 0x90) * *(f32 *)(tmpUnit + 0x2C));
            displacement.y = btlCamera_product(direction.y, (*(f32 *)(tmpUnit + 0x90) * *(f32 *)(tmpUnit + 0x2C)));
            displacement.z = btlCamera_product(direction.z, (*(f32 *)(tmpUnit + 0x90) * *(f32 *)(tmpUnit + 0x2C)));
            focus[0].x = 0.0f + position.x + displacement.x;
            focus[0].y = position.y + displacement.y;
            focus[0].z = position.z + displacement.z;
        }
        if (focus[0].y < 100.0f) {
            focus[0].y = 100.0f;
        } else {
            if ((*(u16 *)(work + 0xE) & 8) != 0) {
                if (focus[0].y > 250.0f) {
                    focus[0].y = 250.0f;
                }
            } else if ((*(u16 *)(work + 0xE) & 0x10) != 0) {
                if (focus[0].y > 500.0f) {
                    focus[0].y = 500.0f;
                }
            } else if (((*(u16 *)(work + 0xE) & 4) != 0) && (focus[0].y > 150.0f)) {
                focus[0].y = 150.0f;
            }
        }
        focus[1] = focus[0];
        break;
    }
    btlCameraLookAtQuat(&poses[0].rot, &poses[0].pos, &focus[0], &D_0060A0E0);
    angle = *(f32 *)(entry + 56);
    if (angle != 0.0f) {
        RwMatrixRotate(&matrix, &D_0060A0F0, angle, 0);
        func_003e4320(&up, &D_0060A0E0, &matrix);
    } else {
        up = D_0060A0E0;
    }
    btlCameraLookAtQuat(&poses[1].rot, &poses[1].pos, &focus[1], &up);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses[0], (f32 *)&poses[1], 1);
    switch (*(s16 *)(base + 2)) {
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
    *(s16 *)(work + 0xA) = (s16)(index + 1);
    *(u16 *)(work + 0xC) = 0;
    goto tick;
clear_flag:
    *(u16 *)(work + 0xE) = (u16)(*(u16 *)(work + 0xE) & 0xFFFE);
    goto tick;
bump_tick:
    *(u16 *)(work + 0xC) = (u16)(*(u16 *)(work + 0xC) + 1);
tick:
    *(u16 *)(work + 0x8) = (u16)(*(u16 *)(work + 0x8) + 1);
    return 1;
}

// FUN_001D10D0
/* Return bit 0 of the script-work flags. */
u32 btlCameraIsEnabled(void* camera)
{
    return (((BtlCameraScriptWork *)(u8*)camera)->flags & 1) != 0;
}

// FUN_001D10F0
/* Initialize script actors/timers and translate options into mirroring and focus-height flags. Raw offsets retained: the proven struct rewrite changed whole-file MWCC instructions. */
void btlCameraInitWork(u8 *work, s32 firstAction, s32 secondAction, u8 *script, s32 options)
{
    s32 flags;

    *(s32 *)(work + 0) = firstAction;
    *(s32 *)(work + 4) = secondAction;
    *(u8 **)(work + 0x10) = script;
    *(s16 *)(work + 8) = 0;
    *(s16 *)(work + 0xA) = -1;
    *(s16 *)(work + 0xC) = 0;
    *(u16 *)(work + 0xE) |= 1;
    *(u16 *)(work + 0xE) &= 0xFFFD;
    flags = options & 0xFFFF;
    if ((flags & 1) && !(script[1] & 1) && (datCalcRandomBelow(0x64) >= 0x32U)) {
        *(u16 *)(work + 0xE) |= 2;
    }
    if (flags & 2) {
        *(u16 *)(work + 0xE) |= 4;
    }
    if (flags & 4) {
        *(u16 *)(work + 0xE) |= 8;
    }
    if (flags & 8) {
        *(u16 *)(work + 0xE) |= 0x10;
    }
    if (flags & 0x10) {
        *(u16 *)(work + 0xE) |= 0x20;
    }
}
// FUN_001D1200
/* Return the current or next script row while enabled and within the four-entry limit. Remaining raw accesses preserve external records or address-carrier boundaries not represented by this object type. */
u8 *btlCameraGetCurrentEntry(u8 *work)
{
    /* Typed script-row indexing changes one instruction byte under MWCC; retain the measured byte-address helper. */
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
    condition = ((BtlCameraScriptWork *)work)->entryElapsed < *(s16 *)(btlCamera_add_index(index * 0x3C, base) + 4);
    if (condition != 0) {
        goto done;
    }
increment:
    index++;
done:
    if (base[0] > index) {
        goto bound_ok;
    }
    return 0;
bound_ok:
    if (index >= 4) {
        return 0;
    }
    return base + index * 0x3C + 4;
}
// FUN_001D12E0
/* Clear the complete 0x14-byte camera script work. */
void btlCameraResetWork(void* work)
{
    FUN_0043f9c8(work, 0, 0x14);
}
