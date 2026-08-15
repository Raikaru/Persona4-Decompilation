/* Source unit: src/Battle/btlCamera_001bc3a0.c */
#include "include_asm.h"
#include "type.h"

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern f32 fabsf(f32 x);
extern RwV3d D_0060A0F0;
RwV3d* RtQuatTransformVectors(RwV3d* vectorsOut, const RwV3d* vectorsIn,
                     s32 numPoints, const RtQuat* quat);

typedef struct BtlUnit BtlUnit;
typedef struct BtlCamera BtlCamera;

s16 func_00198810(BtlUnit* unit);
s16 func_001991c0(BtlUnit* unit, u16 id, f32 scale);
s16 func_00199830(BtlUnit* unit);

typedef struct BtlAction BtlAction;

typedef struct BtlCameraPacketSetState
{
    BtlAction* action; // 0x00
    u16 state;         // 0x04
} BtlCameraPacketSetState;

void func_001bc660(u16 state, BtlAction* action, u32 param_3);

typedef u32 (*BtlPacketFunc)(void* work);

typedef struct BtlPacket
{
    u8 _pad00[0x68];
    BtlPacketFunc initFunc;    // 0x68
    BtlPacketFunc updateFunc;  // 0x6c
    BtlPacketFunc destroyFunc; // 0x70
    u8 _pad74[4];
    void* workData;            // 0x78
} BtlPacket;

BtlPacket* func_00194470(u32 id, s32 workDataSize);
u32 btlCameraUpdateSetStatePacket(void* work);

void func_001bd620(float *param_1,float *param_2,float *param_3,float *param_4);
void RtQuatConvertFromMatrix(void* out, void* in);

u16 func_001c0e50(void* camera);
void func_001be050(void* camera, f32 angle, f32 distance);
void func_001c5500(void* camera, s32 arg);
void func_001c5b80(void* camera, s32 arg);
void func_001c1040(void* camera, u32 arg);

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
f32 RwV3dNormalize(RwV3d* out, RwV3d* in);
RwMatrix* RwMatrixRotate(RwMatrix* matrix, const RwV3d* axis, f32 angle, s32 mode);
RwV3d* func_003e4320(RwV3d* out, const RwV3d* in, const RwMatrix* matrix);
void func_001bd780(void* out, const void* first, const void* second, const void* config);
void func_001bcd40(f32 param_1, u8* param_2, u8* param_3, u8* param_4, u32 param_5);
extern f32 func_00196040(u32, u32, void*, f32*, void*, u32);
extern void func_001958f0(s32, void*);
extern f32 func_0044b868(f32 x);
extern f32 func_003e40b0(f32 *out, f32 *in);
extern void func_00195850(u8 *arg0, f32 *arg1);
extern void func_0019de70(u8 *arg0, u16 arg1);
extern void func_001959d0(u8 *arg0, f32 *arg1);
extern void func_003dcb40(void *out, const void *in, s32 count,
                          const void *quat);
extern void func_001bab00(u8 *arg0, void *arg1);
void func_001bac20(u8* camera, RwV3d* first, RwV3d* second, s32 mode);
void func_001bd560(f32 *out, f32 *in);
void func_001cc5d0(u8 *camera, f32 *out);
void func_001bdd80(u8* camera, void* data, s32 mode);
extern s32 func_004bd050(s32 arg0);
static inline u32 cd600Add(u32 flagOffset, u32 tableAddr)
{
    return flagOffset + tableAddr;
}
extern u8 D_005FC900[];
extern s32 func_002428f0(s32 arg0, s32 arg1);
extern u8 D_005FDE00[];
void func_001bbef0(u8* camera, f32 step);

void func_001c6760(void *camera, float angle, float distanceScale, float heightScale, float minimumDistance);

typedef struct F32Vec4
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} F32Vec4;
struct BtlUnit
{
    u8 _pad00[0x1c];
    RtQuat rot;        // 0x1c
    f32 scale;         // 0x2c
    u8 _pad30[0x5c];
    f32 unk_8c;        // 0x8c
    f32 sphereRadius;  // 0x90
};
struct BtlAction
{
    u8 _pad00[0x30];
    BtlUnit* unit; // 0x30
};
struct BtlCamera
{
    u8 _pad00[0xb8];
    f32 fovRad;        // 0xb8
    u8 _padbc[0x24];
    BtlAction* action; // 0xe0
};

extern f32 DAT_00761254;
extern f32 DAT_00761188;
extern f32 DAT_00761258;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3bc;
extern void func_001c1f70(void *arg0, s32 arg1);
extern void func_001bdeb0(void);
void func_001cb970(void* camera, f32 speed, int param_3);
extern f32 fGpffff80e8;
extern void func_001b73f0();
extern u32 func_001c6f40();

typedef struct BtlCameraKeyFrame
{
    RwV3d pos;  // 0x00
    RtQuat rot; // 0x0c
} BtlCameraKeyFrame;
void func_001bb3d0(void* camera, void* first, void* second, void* third, void* fourth, u16 mode);



// FUN_001BC3A0
u32 func_001bc3a0(float *param_1,float *param_2)
{
  f32 tmp[3];
  f32 t;
  f32 a;
  u32 ret;

  ret = 0;
  a = fabsf(param_1[0]);
  if (a > 1500) {
    if (param_2 != 0) {
      t = a - 1500;
      RtQuatTransformVectors((RwV3d*)tmp,&D_0060A0F0,1,(RtQuat*)(param_1 + 3));
      if (tmp[0] != 0.0f) {
        a = fabsf(tmp[0]);
        t = t / a;
        tmp[0] = tmp[0] * t;
        tmp[1] = tmp[1] * t;
        tmp[2] = tmp[2] * t;
        param_2[0] = param_1[0] + tmp[0];
        param_2[1] = param_1[1] + tmp[1];
        param_2[2] = param_1[2] + tmp[2];
      }
    }
    ret = 1;
  }
  a = fabsf(param_1[2]);
  if (a > 1500) {
    if (param_2 != 0) {
      t = a - 1500;
      RtQuatTransformVectors((RwV3d*)tmp,&D_0060A0F0,1,(RtQuat*)(param_1 + 3));
      if (tmp[2] != 0.0f) {
        a = fabsf(tmp[2]);
        t = t / a;
        tmp[0] = tmp[0] * t;
        tmp[1] = tmp[1] * t;
        tmp[2] = tmp[2] * t;
        param_2[0] = param_1[0] + tmp[0];
        param_2[1] = param_1[1] + tmp[1];
        param_2[2] = param_1[2] + tmp[2];
      }
    }
    ret = 1;
  }
  return ret;
}



// FUN_001BC560
s32 func_001bc560(BtlCamera* camera, u32 unit)
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
    frameCount = func_001991c0(
      unitPtr, (u16)(s32)func_00198810(unitPtr), 1.0f);
    animFrame = func_00199830(unitPtr);
    result = animFrame < frameCount;
    result = result ^ 1;
  }
  return result;
}



// FUN_001BC630
s32 func_001bc630(u8 *param_1)
{
    u32 offset;

    offset = (u32)*(u16 *)(*(u8 **)(param_1 + 0xE0) + 0x6E) * 4;
    offset += (u32)iGpffffb3bc;
    return (s32)((*(u16 *)(offset + 2) & 0x4000) != 0);
}
// FUN_001BC660
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001bc660);
// FUN_001BC7F0
u16 func_001bc7f0(void)
{
    return *(u16 *)(iGpffffb3ac + 0xf4);
}
// FUN_001BC800
void func_001bc800(u8 *arg0)
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
        if (*(s32 *)(action + 8) == *(s32 *)(arg0 + 8)) {
            *(u8 **)actionSlot = NULL;
        }
        camera = iGpffffb3ac;
        state = *(u16 *)(camera + 0xF4);
        switch (state) {
        case 13:
            stateActionSlot = camera + 0x124;
            stateAction = *(u8 **)stateActionSlot;
            if (stateAction != NULL &&
                *(s32 *)(stateAction + 8) == *(s32 *)(arg0 + 8)) {
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
                *(s32 *)(stateAction2 + 8) == *(s32 *)(arg0 + 8)) {
                *(u8 **)stateActionSlot2 = NULL;
            }
            break;
        default:
            break;
        }
    }
}
// FUN_001BC8E0
u32 btlCameraUpdateSetStatePacket(void* work)
{
    BtlCameraPacketSetState* packet;

    packet = (BtlCameraPacketSetState*)work;

    func_001bc660(packet->state, packet->action, 1);

    return 1;
}



// FUN_001BC920
BtlPacket* btlCameraCreateSetStatePacket(BtlAction* action, u16 state)
{
    BtlPacket* packet;
    BtlCameraPacketSetState* work;

    packet = func_00194470(0x200, 8);

    packet->updateFunc = btlCameraUpdateSetStatePacket;

    work = (BtlCameraPacketSetState*)packet->workData;

    work->action = action;
    work->state = state;

    return packet;
}



// FUN_001BD620
void func_001bd620(float *param_1,float *param_2,float *param_3,float *param_4)
{
  extern float RwV3dNormalize();
  RwV3d diff;
  RwV3d cross1;
  RwV3d cross2;

  *(RwV3d*)(param_1 + 0xc) = *(RwV3d*)param_3;
  diff.x = *param_2 - *param_3;
  diff.y = param_2[1] - param_3[1];
  diff.z = param_2[2] - param_3[2];
  RwV3dNormalize(&diff,&diff);
  *(RwV3d*)(param_1 + 8) = diff;
  cross1.x = param_4[1] * diff.z - param_4[2] * diff.y;
  cross1.y = param_4[2] * diff.x - *param_4 * diff.z;
  cross1.z = *param_4 * diff.y - param_4[1] * diff.x;
  RwV3dNormalize(&cross1,&cross1);
  *(RwV3d*)param_1 = cross1;
  cross2.x = diff.y * cross1.z - diff.z * cross1.y;
  cross2.y = diff.z * cross1.x - diff.x * cross1.z;
  cross2.z = diff.x * cross1.y - diff.y * cross1.x;
  *(RwV3d*)(param_1 + 4) = cross2;
  return;
}



// FUN_001BD780
void func_001bd780(void* out, const void* first, const void* second, const void* config)
{
  u8 auStack_40[64];

  func_001bd620((float*)auStack_40, (float*)second, (float*)first,
               (float*)config);
  RtQuatConvertFromMatrix(out, auStack_40);
}



// FUN_001C6560
void func_001c6560(void* camera)
{
  u16 uVar1;

  uVar1 = func_001c0e50(camera);
  *(u16 *)((int)camera + 0x110) = uVar1;
  switch(*(u16 *)((int)camera + 0x110)) {
  case 1:
    func_001be050(camera, 45.0f, 200.0f);
    break;
  case 2:
    func_001c5500(camera,1);
    break;
  case 3:
    func_001c5b80(camera,1);
    break;
  case 4:
    func_001c5500(camera,1);
    break;
  case 5:
    func_001c5b80(camera,1);
    break;
  case 6:
    func_001c1040(camera,1);
  }
  return;
}



// FUN_001C6650
void func_001c6650(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u16 state;
    u8 *temp17;
    u8 *temp3_2;
    u8 *temp4;
    f32 scale;

    state = *(u16 *)(arg0 + 0x110);
    switch (state) {
    case 1:
        temp4 = *(u8 **)(arg0 + 0xE0);
        if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
            temp17 = *(u8 **)(temp4 + 0x30);
            func_00195850(temp17, &local.value);
            scale = 0.5f * (*(f32 *)(temp17 + 0x90) *
                            *(f32 *)(temp17 + 0x2C));
            func_001bcd40(scale, *(u8 **)(arg0 + 0xE0), arg0 + 0x9C,
                          (u8 *)&local.value, 0xC1);
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    case 6:
        temp3_2 = *(u8 **)(arg0 + 0xE0);
        if ((temp3_2 != NULL) &&
            ((*(u16 *)(temp3_2 + 0x1A) & 1) != 0) &&
            (func_001bc560((BtlCamera *)arg0, *(u32 *)(arg0 + 0x12C)) != 0)) {
            func_0019de70(*(u8 **)(arg0 + 0x12C),
                          *(u16 *)(arg0 + 0x130));
        }
        break;
    default:
        break;
    }
}
// FUN_001C6760
void func_001c6760(void *camera, float angle, float distanceScale, float heightScale, float minimumDistance)
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
  func_001bd780(scratch.firstView, &scratch.candidate.value, &scratch.center.value, &D_0060A0E0);
  scratch.firstPosition.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.firstPosition.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.firstPosition.z = scratch.center.value.z + scratch.direction.value.z;
  RwMatrixRotate(&scratch.rotation, &D_0060A0E0, -angle, 0);
  func_003e4320(&scratch.direction.value, &scratch.scaledOffset.value, &scratch.rotation);
  scratch.candidate.value.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.direction.value.z;
  func_001bd780(scratch.secondView, &scratch.candidate.value, &scratch.center.value, &D_0060A0E0);
  scratch.secondPosition.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.secondPosition.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.secondPosition.z = scratch.center.value.z + scratch.direction.value.z;
  func_001bcd40(0.0f, *(u8 **)(cameraAddress + 0xe0), NULL, NULL, 1);
  func_001bac20((u8 *)camera, &scratch.firstPosition, &scratch.secondPosition, 1);
  func_001bbef0((u8 *)camera, 3.5f);
}



// FUN_001C6B10
void func_001c6b10(void* camera)
{
  func_001c6760(camera,10.0f,2.0f,0.0f,250.0f);
  return;
}



// FUN_001C6B50
void func_001c6b50(void)
{
}
// FUN_001C6B60
void func_001c6b60(void* camera)
{
    func_001c6760(camera, 15.0f, 2.0f, 0.25f, 400.0f);
}
// FUN_001C6BA0
void func_001c6ba0(void)
{
}
// FUN_001C6BB0
void func_001c6bb0(void *arg0)
{
    func_001c1f70(arg0, 1);
}
// FUN_001C6BE0
void func_001c6be0(void)
{
}
// FUN_001C6BF0
void func_001c6bf0(u8 *arg0)
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
    u8 *temp17;
    f32 angleScale;
    f32 rotationAngle;
    f32 y;

    temp17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x38);
    temp17 = *(u8 **)(temp17 + 0x30);
    func_001959d0(temp17, &work.center.x);
    work.center.y = 0.0f + work.center.y +
                    DAT_00761278 *
                    (*(f32 *)(temp17 + 0x8C) *
                     *(f32 *)(temp17 + 0x2C));
    func_003dcb40(&work.direction, &D_0060A0F0, 1, temp17 + 0x1C);
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
                      (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.firstPosition.x = work.center.x + work.scaled.x;
    work.firstPosition.y = work.center.y + work.scaled.y;
    work.firstPosition.z = work.center.z + work.scaled.z;
    func_001bd780(work.firstView, &work.firstPosition, &work.center,
                  &D_0060A0E0);

    RwMatrixRotate(&work.rotation, &D_0060A0E0, -5.0f, 0);
    func_003e4320(&work.scaled, &work.direction, &work.rotation);
    angleScale = 110.0f /
                 tanf(DAT_00761200 *
                      (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.secondPosition.x = work.center.x + work.scaled.x;
    work.secondPosition.y = work.center.y + work.scaled.y;
    work.secondPosition.z = work.center.z + work.scaled.z;
    func_001bd780(work.secondView, &work.secondPosition, &work.center,
                  &D_0060A0E0);
    if (work.firstPosition.y < 25.0f) {
        work.firstPosition.y = 25.0f;
    }
    if (work.secondPosition.y < 25.0f) {
        work.secondPosition.y = 25.0f;
    }
    func_001bcd40(0.0f, *(u8 **)(arg0 + 0xE0), NULL, NULL, 2);
    func_001bac20(arg0, &work.firstPosition, &work.secondPosition, 1);
    func_001bbef0(arg0, 1.5f);
}
// FUN_001C6F30
void func_001c6f30(void)
{
}
// FUN_001C6F40
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6f40);
// FUN_001C73E0
void func_001c73e0(u8 *arg0)
{
    struct
    {
        s32 first;
        u8 gap[0x18];
        f32 last;
        u8 tail[0x20];
    } work;
    s32 var_5;
    u16 temp_4;

    temp_4 = *(u16 *)(iGpffffb3ac + 0x108);
    switch (temp_4)
    {
    case 2:
        return;
    case 34:
    case 40:
    case 41:
        var_5 = 0;
        break;
    default:
        var_5 = 1;
        break;
    }
    if (*(s32 *)(arg0 + 0x148) != 0)
    {
        var_5 = 1;
        *(s32 *)(arg0 + 0x148) = 0;
    }
    if (func_001c6f40(arg0, var_5, 0,
                      &work.first, &work.last) != 0)
    {
        func_001b73f0(0);
        func_001bcd40(
            0.0f,
            (u8 *)(uintptr_t)*(u32 *)(arg0 + 0xE0),
            NULL, NULL, 0x100);
        func_001bab00(arg0, &work.last);
        return;
    }
    func_001bac20(arg0, (RwV3d *)&work.first,
                  (RwV3d *)&work.last, 1);
    func_001bbef0(arg0, fGpffff80e8);
}
// FUN_001C7500
void func_001c7500(void)
{
}
// FUN_001C7510
void func_001c7510(BtlCamera* camera)
{
  BtlUnit* unit;
  f32 buf[28];
  f32 fVar4;
  f32 fVar20;
  f32 fVar23;
  f32 fVar22;
  f32 fVar21;
  f32 fVar9;
  f32 fVar8;
  f32 fVar7;

  unit = camera->action->unit;
  btlUnitGetSphereWorldCenter(unit, (RwV3d *)(buf + 24));
  fVar20 = unit->sphereRadius * unit->scale;
  fVar21 = unit->unk_8c * unit->scale * 0.5f;
  buf[25] = fVar21 * 0.25f + buf[25];
  if (fVar20 > fVar21) {
    fVar20 = (1.25f * fVar20) /
      tanf(DAT_00761200 * (camera->fovRad * 0.5f));
  }
  else {
    fVar20 = (1.25f * fVar21) /
      tanf(camera->fovRad * 0.5f);
  }
  RtQuatTransformVectors((RwV3d *)(buf + 20), &D_0060A0F0, 1, &unit->rot);
  fVar4 = fVar20 + 125.0f;
  fVar23 = buf[20] * fVar4;
  fVar22 = buf[21] * fVar4;
  fVar21 = buf[22] * fVar4;
  buf[16] = buf[24] + fVar23;
  buf[17] = buf[25] + fVar22;
  buf[18] = buf[26] + fVar21;
  func_001bd780(&buf[3], &buf[16], (RwV3d *)(buf + 24), &D_0060A0E0);
  fVar9 = buf[24];
  buf[0] = fVar9 + fVar23;
  fVar8 = buf[25];
  buf[1] = fVar8 + fVar22;
  fVar7 = buf[26];
  buf[2] = fVar7 + fVar21;
  *(F32Vec4 *)(buf + 10) = *(F32Vec4 *)(buf + 3);
  buf[7] = buf[20] * fVar20 + fVar9;
  buf[8] = buf[21] * fVar20 + fVar8;
  buf[9] = buf[22] * fVar20 + fVar7;
  func_001bcd40(0.0f, (u8 *)camera->action, 0, 0, 1);
  func_001bac20((u8 *)camera, (RwV3d *)buf, (RwV3d *)(buf + 7), 1);
  func_001bbef0((u8 *)camera, 2.5f);
}



// FUN_001C7770
void func_001c7770(void)
{
}

// FUN_001C7780
void func_001c7780(BtlCamera* camera)
{
  BtlUnit* unit;
  f32 buf[28];
  f32 fVar4;
  f32 fVar20;
  f32 fVar23;
  f32 fVar22;
  f32 fVar21;
  f32 fVar9;
  f32 fVar8;
  f32 fVar7;

  unit = camera->action->unit;
  btlUnitGetSphereWorldCenter(unit, (RwV3d *)(buf + 24));
  fVar20 = unit->sphereRadius * unit->scale;
  fVar21 = unit->unk_8c * unit->scale * 0.5f;
  buf[25] = fVar21 * 0.25f + buf[25];
  if (fVar20 > fVar21) {
    fVar20 = (1.5f * fVar20) /
      tanf(DAT_00761200 * (camera->fovRad * 0.5f));
  }
  else {
    fVar20 = (1.5f * fVar21) /
      tanf(camera->fovRad * 0.5f);
  }
  RtQuatTransformVectors((RwV3d *)(buf + 20), &D_0060A0F0, 1, &unit->rot);
  fVar4 = fVar20 + 125.0f;
  fVar23 = buf[20] * fVar4;
  fVar22 = buf[21] * fVar4;
  fVar21 = buf[22] * fVar4;
  buf[16] = buf[24] + fVar23;
  buf[17] = buf[25] + fVar22;
  buf[18] = buf[26] + fVar21;
  func_001bd780(&buf[3], &buf[16], (RwV3d *)(buf + 24), &D_0060A0E0);
  fVar9 = buf[24];
  buf[0] = fVar9 + fVar23;
  fVar8 = buf[25];
  buf[1] = fVar8 + fVar22;
  fVar7 = buf[26];
  buf[2] = fVar7 + fVar21;
  *(F32Vec4 *)(buf + 10) = *(F32Vec4 *)(buf + 3);
  buf[7] = buf[20] * fVar20 + fVar9;
  buf[8] = buf[21] * fVar20 + fVar8;
  buf[9] = buf[22] * fVar20 + fVar7;
  func_001bcd40(0.0f, (u8 *)camera->action, 0, 0, 1);
  func_001bac20((u8 *)camera, (RwV3d *)(buf + 7), (RwV3d *)buf, 1);
  func_001bbef0((u8 *)camera, 2.5f);
}



// FUN_001CBFE0
void func_001cbfe0(int param_1)
{
  int iVar1;
  f32 speed;

  iVar1 = *(int *)(param_1 + 0xe0);
  if ((((iVar1 != 0) && (*(u16 *)(iVar1 + 0x6a) == 1)) &&
      (*(int *)(param_1 + 0x100) == *(int *)(iVar1 + 0x38))) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)
     ) {
    if (*(u16 *)(param_1 + 0x10e) <= *(u16 *)(param_1 + 0x10c)) {
      speed = (*(int *)(param_1 + 0x108) != 0) ? DAT_00761254 : DAT_00761188;
    }
    else {
      speed = DAT_00761258;
    }
    func_001cb970((void*)param_1, speed, *(u16 *)(param_1 + 0x10c) == 0);
    *(short *)(param_1 + 0x10c) = *(u16 *)(param_1 + 0x10c) + 1;
  }
  return;
}



// FUN_001CC0A0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cc0a0);
// FUN_001CC5C0
void func_001cc5c0(void)
{
}
// FUN_001CC5D0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cc5d0);
/* measured: plain-C aggregate reconstruction reproduces every retail
   instruction; the object is 112B against the 128B window, with the retail
   trailing jr/nop pair left as window padding. */
// FUN_001CC9E0
void func_001cc9e0(u8 *arg0)
{
    struct C9Work {
        f32 first[7];
        f32 second[7];
    } work;

    func_001bd560(work.first, (f32 *)(arg0 + 0x9C));
    func_001cc5d0(arg0, work.second);
    func_001bac20(arg0, (RwV3d *)work.first, (RwV3d *)work.second, 1);
    func_001bbef0(arg0, 10.0f);
}
// FUN_001CCA50
void func_001cca50(void)
{
}

// FUN_001CCA60
void func_001cca60(BtlCamera* camera)
{
    int iVar1;
    int iVar2;
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

    iVar2 = (int)camera;
    iVar1 = *(int*)(iVar2 + 0xe0);
    if (iVar1 != 0)
    {
        iVar1 = *(int*)(iVar1 + 0x30);
    }
    else
    {
        iVar1 = *(int*)(*(int*)(iGpffffb3ac + 0x170) + 0x30);
    }
    distance = func_00196040(3, 1, &scratch.target, &height, 0, 1);
    func_001958f0(iVar1, &scratch.pos);
    scratch.target.y = 0.0f;
    scratch.pos.y = 0.0f;
    if ((scratch.pos.x == scratch.target.x) &&
        (scratch.pos.z == scratch.target.z))
    {
        func_001958f0(*(int*)(*(int*)(iGpffffb3ac + 0x170) + 0x30),
                      &scratch.pos);
        scratch.pos.y = 0.0f;
    }
    scratch.diff.x = scratch.pos.x - scratch.target.x;
    scratch.diff.y = scratch.pos.y - scratch.target.y;
    scratch.diff.z = scratch.pos.z - scratch.target.z;
    func_003e40b0(&scratch.diff.x, &scratch.diff.x);
    scratch.diff.x = scratch.diff.x * distance;
    scratch.diff.y = scratch.diff.y * distance;
    scratch.diff.z = scratch.diff.z * distance;
    scratch.pos.x = scratch.target.x + scratch.diff.x;
    scratch.pos.y = scratch.target.y + scratch.diff.y;
    scratch.pos.z = scratch.target.z + scratch.diff.z;
    minDistance = 0.75f *
                  (*(f32*)(iVar1 + 0x8c) *
                   *(f32*)(iVar1 + 0x2c));
    norm = fGpffff80e8 * height;
    norm = (!(norm > minDistance)) ? minDistance : norm;
    scratch.pos.y = norm;
    func_001bd780(&scratch.unk, &scratch.pos, &scratch.target, &D_0060A0E0);
    minDistance = (0.75f * distance) /
                  func_0044b868(DAT_00761188 *
                                 (0.5f * *(f32*)(iVar2 + 0xb8)));
    scratch.diff.x = scratch.pos.x - scratch.target.x;
    scratch.diff.y = scratch.pos.y - scratch.target.y;
    scratch.diff.z = scratch.pos.z - scratch.target.z;
    norm = func_003e40b0(&scratch.diff.x, &scratch.diff.x);
    distance = func_0044b868(DAT_00761188 *
                             (0.5f * *(f32*)(iVar2 + 0xb8)));
    candidate = norm +
                (*(f32*)(iVar1 + 0x90) *
                 *(f32*)(iVar1 + 0x2c) * 2.0f) /
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
    func_001bc3a0((f32*)&scratch.out, (f32*)&scratch.out);
    func_001bcd40(0.0f, (u8*)0, (u8*)0, (u8*)0, 0x100);
    func_001bab00((u8*)(uintptr_t)iVar2, (void*)&scratch.out);
    func_001bd5a0((f32*)(iVar2 + 0x9c), (f32*)&scratch.out);
}
// FUN_001CCDA0
void func_001ccda0(void)
{
}
// FUN_001CCDB0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001ccdb0);
// FUN_001CD600
void func_001cd600(u8 *arg0)
{
    u16 temp_16;

    temp_16 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA4);
    func_001bdd80(
        arg0,
        (void *)(uintptr_t)cd600Add(
            (func_004bd050(0) & 1) * 0xF4,
            (u32)((uintptr_t)D_005FC900 +
                  ((temp_16 & 0xFFFF) * 0x1E8))),
        2);
}
// FUN_001CD6A0
void func_001cd6a0(void)
{
    func_001bdeb0();
}
// FUN_001CD6C0
void func_001cd6c0(u8 *arg0)
{
    s32 var_16;
    u8 *var_18;

    var_16 = 0;
    var_18 = *(u8 **)(iGpffffb3ac + 0x17C);
    goto loop_cond;
loop_body:
    if ((*(s32 *)(var_18 + 0x9C) & 8) &&
        (func_002428f0(*(s32 *)(var_18 + 0xA64), 0) == 0))
    {
        var_16 = (var_16 + 1) & 0xFFFF;
    }
    var_18 = *(u8 **)(var_18 + 0xA68);
loop_cond:
    if (var_18 != NULL)
    {
        goto loop_body;
    }
    var_16 = (var_16 & 0xFFFF) != 4;
    func_001bdd80(
        arg0,
        (void *)(uintptr_t)cd600Add(
            (func_004bd050(0) & 1) * 0xF4,
            (u32)((uintptr_t)D_005FDE00 + (var_16 * 0x1E8))),
        2);
}
// FUN_001CD7B0
void func_001cd7b0(void)
{
    func_001bdeb0();
}
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
    func_001bd780(&((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].rot,
                 &((BtlCameraKeyFrame*)scratch.frameBytes)[(u16)i].pos,
                 &center, &D_0060A0E0);
    angle = angle + -25.0f;
    distance = distance + 25.0f;
    i = (i + 1) & 0xffff;
  }
  func_001bcd40(0.0f, (u8*)camera->action, 0, 0, 1);
  func_001bb3d0(camera, &scratch.frameBytes[0],
               &scratch.frameBytes[0x1c],
               &scratch.frameBytes[0x38],
               &scratch.frameBytes[0x54], 1);
  func_001bbef0((u8*)camera, 10.0f);
}



// FUN_001CDAF0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cdaf0);
// FUN_001CDE50
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cde50);
// FUN_001CE390
void func_001ce390(u8 *arg0)
{
    struct {
        f32 value;
        u8 pad[0xC];
    } local;
    u8 *temp16;
    u8 *temp4;
    f32 scale;

    temp4 = *(u8 **)(arg0 + 0xE0);
    if ((temp4 != NULL) && ((*(u16 *)(temp4 + 0x1A) & 1) != 0)) {
        temp16 = *(u8 **)(temp4 + 0x30);
        func_00195850(temp16, &local.value);
        scale = 0.5f * (*(f32 *)(temp16 + 0x90) *
                        *(f32 *)(temp16 + 0x2C));
        func_001bcd40(scale, *(u8 **)(arg0 + 0xE0), arg0 + 0x9C,
                      (u8 *)&local.value, 0xC1);
    }
}
// FUN_001CE420
void func_001ce420(void)
{
}
// FUN_001CE430
void func_001ce430(int param_1)
{
  func_001bcd40(0.0f, (u8 *)(uintptr_t)*(int *)(param_1 + 0xe0), 0, 0, 0);
}
