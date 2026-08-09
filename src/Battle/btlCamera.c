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
void btlUnitGetSphereWorldCenter(BtlUnit* unit, RwV3d* dst);
f32 tanf(f32 x);
f32 RwV3dNormalize(RwV3d* out, RwV3d* in);
RwMatrix* RwMatrixRotate(RwMatrix* matrix, const RwV3d* axis, f32 angle, s32 mode);
RwV3d* func_003e4320(RwV3d* out, const RwV3d* in, const RwMatrix* matrix);
void func_001bd780(void* out, const void* first, const void* second, const void* config);
void func_001bcd40(f32 param_1, u8* param_2, u8* param_3, u8* param_4, u32 param_5);
void func_001bac20(u8* camera, RwV3d* first, RwV3d* second, s32 mode);
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
void func_001cb970(void* camera, f32 speed, int param_3);

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
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001bc630);
// FUN_001BC660
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001bc660);
// FUN_001BC7F0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001bc7f0);
// FUN_001BC800
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001bc800);
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
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6650);
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
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6b50);
// FUN_001C6B60
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6b60);
// FUN_001C6BB0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6bb0);
// FUN_001C6BE0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6be0);
// FUN_001C6BF0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6bf0);
// FUN_001C6F30
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6f30);
// FUN_001C6F40
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c6f40);
// FUN_001C73E0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c73e0);
// FUN_001C7500
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001c7500);
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
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cc5c0);
// FUN_001CC5D0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cc5d0);
// FUN_001CC9E0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cc9e0);
// FUN_001CCA60
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cca60);
// FUN_001CCDA0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001ccda0);
// FUN_001CCDB0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001ccdb0);
// FUN_001CD600
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cd600);
// FUN_001CD6A0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cd6a0);
// FUN_001CD6C0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cd6c0);
// FUN_001CD7B0
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001cd7b0);
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
INCLUDE_ASM("asm/nonmatchings/btlCamera", func_001ce390);
// FUN_001CE430
void func_001ce430(int param_1)
{
  func_001bcd40(0.0f, (u8 *)(uintptr_t)*(int *)(param_1 + 0xe0), 0, 0, 0);
}
