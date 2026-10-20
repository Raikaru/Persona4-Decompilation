#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"

#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern void memset(void *dst, s32 value, s32 size);
extern s32 func_003bbb60(u8 *value);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern void (*jtbl_008873EC[])(void *);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];

extern u8 *D_0076449C;
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *value);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern u32 iGpffffa0b8;
extern void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode);
extern void btlCameraStartEffect(u8 *camera, u8 *script, s32 options);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern s32 btlCameraFrameActionStart(u8 *camera, u8 *work);
extern u8 *btlCameraGetCurrentEntry(u8 *work);
extern void btlCameraInitWork(u8 *work, s32 firstAction, s32 secondAction, u8 *script, s32 options);
extern void btlCameraUpdateEffectList(u8 *camera);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern void btlCameraSuppressEncounterCallback(void);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern void primQuad3D(f32 *pos, u8 *col, s32 size, f32 saveAndRestoreRenderState);
extern void primAxisLine3D(f32 *mat, s32 length, f32 saveAndRestoreRenderState);
extern u8 *btlEncounterGetRecord(s32 index);
extern void func_003e9cb0(void *frame, void *transform, s32 combine);
extern s32 kwlnGetCamera(void);
extern void K_View_SetFov(void *camera, f32 fov);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void btlCameraUpdateUnitInRangeFlags(void);
extern u8 *func_003e8180(u8 *value, f32 option);
extern s32 func_003bbbe0(s32 value, s32 option, void *data);
extern void func_001d12e0(void *value);
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;






#pragma push
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001b; members 001bd7d0-001bdeb0 */

/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
/* measured: scoped opt_lifetimes on with these disjoint work-pointer
 * lifetimes reproduces the complete 4156-byte retail body; all 122 owner
 * siblings, allocated data and 122 exact-position references are preserved.
 * The separate retained-height caller-domain proof remains required. */
#pragma push
#pragma pop
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_propagation off probe for bc240 table-address order. */
/* measured: close opt_propagation probe for bc240. */
#pragma push
#pragma pop
/* measured: disabling propagation preserves retail's independent outer-index
   materialisation after the preheader branch. */
/* measured: disabling common-subexpression folding preserves retail's second
   masked loop-counter use. */
/* measured: closes opt_common_subs for the following translation-unit code. */
/* measured: closes opt_propagation for the following translation-unit code. */
/* measured: opt_common_subs off preserves the retail per-use masked index. */
/* measured: restore common-subexpression optimization after btlCameraUpdateUnitInRangeFlags. */
// FUN_001BD7D0
/* Run the active camera callback unless delayed/suppressed, build its quaternion basis, and apply view position/FOV. The external view handle and encounter callback record remain opaque. */
void btlCameraApplyView(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } CameraBasisVector;
    typedef struct {
        CameraBasisVector right;
        u32 flags;
        CameraBasisVector up;
        u32 pad1;
        CameraBasisVector at;
        u32 pad2;
        CameraBasisVector pos;
        u32 pad3;
    } CameraBasisMatrix;
    CameraBasisMatrix matrix;
    f32 normalization;
    f32 scaledZ;
    f32 xw;
    f32 quatZ;
    f32 quatX;
    f32 scaledY;
    f32 scaledX;
    f32 xy;
    f32 quatW;
    f32 xz;
    f32 quatY;
    f32 yz;
    f32 zz;
    f32 yy;
    f32 xx;
    f32 zw;
    f32 yw;
    void (*callback)(u8 *value);
    s32 delay;
    u16 state;
    u8 *view;
    u8 *record;

    if ((((BtlBattleState *)D_0076449C)->camera.flags & 1) == 0) {
        delay = ((BtlBattleState *)D_0076449C)->camera.delay;
        if (delay <= 0) {
            state = ((BtlBattleState *)D_0076449C)->camera.state;
            record = btlEncounterGetRecord(state);
            if (record == NULL) {
                record = D_005F74C0 + ((state & 0xFFFF) * 0x14);
            }
            callback = *(void (**)(u8 *))(record + 4);
            if (callback != NULL) {
                callback(D_0076449C + 0x24);
            }
            btlCameraUpdateTransition(D_0076449C + 0x24);
            ((BtlBattleState *)D_0076449C)->camera.frame =
                ((BtlBattleState *)D_0076449C)->camera.frame + 1;
        } else {
            ((BtlBattleState *)D_0076449C)->camera.delay = delay - 1;
        }
        quatY = ((BtlBattleState *)D_0076449C)->camera.pose.rot.imag.y;
        quatX = ((BtlBattleState *)D_0076449C)->camera.pose.rot.imag.x;
        quatZ = ((BtlBattleState *)D_0076449C)->camera.pose.rot.imag.z;
        quatW = ((BtlBattleState *)D_0076449C)->camera.pose.rot.real;
        normalization =
            2.0f / ((quatX * quatX) +
                    (quatY * quatY) +
                    (quatZ * quatZ) +
                    (quatW * quatW));
        scaledX = quatX * normalization;
        scaledY = quatY * normalization;
        scaledZ = quatZ * normalization;
        xw = scaledX * quatW;
        yw = scaledY * quatW;
        zw = scaledZ * quatW;
        xx = quatX * scaledX;
        yy = quatY * scaledY;
        zz = quatZ * scaledZ;
        yz = quatY * scaledZ;
        xz = quatZ * scaledX;
        xy = quatX * scaledY;
        matrix.right.x = 1.0f - (yy + zz);
        matrix.right.y = xy + zw;
        matrix.right.z = xz - yw;
        matrix.up.x = xy - zw;
        matrix.up.y = 1.0f - (zz + xx);
        matrix.up.z = yz + xw;
        matrix.at.x = xz + yw;
        matrix.at.y = yz - xw;
        matrix.at.z = 1.0f - (xx + yy);
        matrix.pos.x = 0.0f;
        matrix.pos.y = 0.0f;
        matrix.pos.z = 0.0f;
        matrix.flags = 3;
        matrix.pos = *(CameraBasisVector *)&((BtlBattleState *)D_0076449C)->camera.pose.pos;
        view = ((u8 *)kwlnGetCamera());
        func_003e9cb0(*(u8 **)(view + 4), &matrix, 0);
        K_View_SetFov(((u8 *)kwlnGetCamera()),
                      fGpffff8048 * ((BtlBattleState *)D_0076449C)->camera.fovRad);
    }
    if ((((BtlBattleState *)D_0076449C)->camera.flags & 2) != 0) {
        btlCameraUpdateUnitInRangeFlags();
    }
}

/* measured: plain C candidate is 380 bytes in the 384-byte retail window with normalized_diff 6; residual is limited to the global-position load order and one retail tail padding word. */
// Committed at nd 6.
// FUN_001BD9E0
/* Draw the camera position and orientation axes when the debug resource flags allow it. */
void btlCameraDrawDebug(void)
{
  typedef struct 
  {
    f32 x;
    f32 y;
    f32 z;
  } CameraDebugVector;
  typedef struct 
  {
    CameraDebugVector right;
    u32 flags;
    CameraDebugVector up;
    u32 pad1;
    CameraDebugVector at;
    u32 pad2;
    CameraDebugVector pos;
    u32 pad3;
  } CameraDebugMatrix;
  u8 color[4];
  CameraDebugMatrix matrix;
  f32 normalization;
  f32 scaledZ;
  f32 xw;
  f32 quatZ;
  f32 quatX;
  f32 scaledY;
  f32 scaledX;
  f32 xy;
  f32 quatW;
  f32 xz;
  f32 quatY;
  f32 yz;
  f32 zz;
  f32 yy;
  f32 xx;
  f32 zw;
  f32 yw;
  s32 resourceFlags;
  u8 *battle;
  u8 *position;
  battle = D_0076449C;
  if (((((BtlBattleState *)battle)->flags) & 4) == 0)
  {
    resourceFlags = ((BtlBattleState *)battle)->resourceFlags;
    if (((resourceFlags & 4) == 0) && ((resourceFlags & 8) != 0))
    {
      color[0] = 0xFF;
      color[1] = 0xFF;
      color[2] = 0;
      color[3] = 0xFF;
      quatY = ((BtlBattleState *)battle)->camera.pose.rot.imag.y;
      quatX = ((BtlBattleState *)battle)->camera.pose.rot.imag.x;
      quatZ = ((BtlBattleState *)battle)->camera.pose.rot.imag.z;
      quatW = ((BtlBattleState *)battle)->camera.pose.rot.real;
      normalization = 2.0f / ((((quatX * quatX) + (quatY * quatY)) + (quatZ * quatZ)) + (quatW * quatW));
      scaledX = quatX * normalization;
      scaledY = quatY * normalization;
      scaledZ = quatZ * normalization;
      xw = scaledX * quatW;
      yw = scaledY * quatW;
      zw = scaledZ * quatW;
      xx = quatX * scaledX;
      yy = quatY * scaledY;
      zz = quatZ * scaledZ;
      yz = quatY * scaledZ;
      xz = quatZ * scaledX;
      xy = quatX * scaledY;
      if (((!quatW) && (!quatW)) && (!quatW))
      {
      }
      matrix.right.x = 1.0f - (yy + zz);
      matrix.right.y = xy + zw;
      matrix.right.z = xz - yw;
      matrix.up.x = xy - zw;
      matrix.up.y = 1.0f - (zz + xx);
      matrix.up.z = yz + xw;
      matrix.at.x = xz + yw;
      matrix.at.y = yz - xw;
      matrix.at.z = 1.0f - (xx + yy);
      matrix.pos.x = 0.0f;
      matrix.pos.y = 0.0f;
      matrix.pos.z = 0.0f;
      matrix.flags = 3;
      position = battle + 0xC0;
      scaledX = *((f32 *) position);
      scaledY = *((f32 *) (position + 4));
      normalization = *((f32 *) (position + 8));
      matrix.pos.x = scaledX;
      matrix.pos.y = scaledY;
      matrix.pos.z = normalization;
      primQuad3D((f32 *) position, color, 1, 6.0f);
      primAxisLine3D((f32 *) (&matrix), 1, 150.0f);
    }
  }
}

// FUN_001BDB60
/* Initialize the camera curve/list, default pose/FOV, state history, and script work. Raw history indexing retains the three-halfword array stride. */
void btlCameraInitSystem(void)
{
    s32 listConfigAddress;
    s32 historyIndex;
    u16 slotIndex;
    u8 *camera;
    u8 *cameraAfterTag;

    func_003e8180(((u8 *)kwlnGetCamera()), 35.0f);
    K_View_SetFov(((u8 *)kwlnGetCamera()), 40.0f);
    {
        u8 *base;

        base = D_0076449C;
        camera = base + 0x24;
        ((BtlBattleState *)base)->camera.curveFlags = 1;
        ((BtlBattleState *)base)->camera.curveIndex = 0;
        ((BtlBattleState *)base)->camera.curveNext = 0;
        ((BtlBattleState *)base)->camera.curveCount = 0;
        ((BtlBattleState *)base)->camera.unk80 = 0;
        ((BtlBattleState *)base)->camera.unk7C = 0;
    }
    chkmemAllocSiteTag(&D_005F72B0, 0x3A);
    cameraAfterTag = camera;
    listConfigAddress = (s32)(*jtbl_008873E8)(0x30, 0x40000);
    memset((void *)listConfigAddress, 0, 0x30);
    ((BtlCamera *)cameraAfterTag)->workList = func_003bbbe0(4, 1, (void *)listConfigAddress);
    (*jtbl_008873EC)((u8 *)listConfigAddress);
    kwlnGetCamera();
    ((BtlBattleState *)D_0076449C)->camera.pose.rot.real = fGpffff8314;
    ((BtlBattleState *)D_0076449C)->camera.pose.rot.imag.x = fGpffff8318;
    ((BtlBattleState *)D_0076449C)->camera.pose.rot.imag.y = fGpffff831c;
    ((BtlBattleState *)D_0076449C)->camera.pose.rot.imag.z = fGpffff8320;
    ((BtlBattleState *)D_0076449C)->camera.pose.pos.x = fGpffff8324;
    ((BtlBattleState *)D_0076449C)->camera.pose.pos.y = fGpffff8328;
    ((BtlBattleState *)D_0076449C)->camera.pose.pos.z = fGpffff832c;
    ((BtlBattleState *)D_0076449C)->camera.fovRad = fGpffff8184;
    ((BtlBattleState *)D_0076449C)->camera.state = 0;
    ((BtlBattleState *)D_0076449C)->camera.repeatedStateCount = 0;
    historyIndex = 0;
    goto loop_test;
loop_body:
    slotIndex = historyIndex;
    *(s16 *)(D_0076449C + (slotIndex * 2) + 0x108) = 0;
    historyIndex = (historyIndex + 1) & 0xFFFF;
loop_test:
    if ((historyIndex & 0xFFFF) < 3) {
        goto loop_body;
    }
    ((BtlBattleState *)D_0076449C)->camera.flags |= 2;
    func_001d12e0(D_0076449C + 0x110);
}

// FUN_001BDD30
/* Reset the optional camera work list. */
void btlCameraResetWorkList(void)
{
    s32 workList;

    workList = ((BtlBattleState *)D_0076449C)->camera.workList;
    if (workList != 0) {
        func_003bbb60((u8 *)workList);
    }
}

// FUN_001BDD60
/* Set the camera flag that suppresses encounter callback and transition updates. */
void btlCameraSuppressEncounterCallback(void) {
    ((BtlBattleState *)D_0076449C)->camera.flags |= 1;
}

/* measured: opt_propagation off probe for bdd80 nd28 float scheduling. */
// FUN_001BDD80
/* Capture the current target and initialize an effect script with its visibility options. Raw offsets retained: the proven camera/action struct rewrite changed whole-file MWCC instructions. */
void btlCameraStartEffect(u8 *camera, u8 *script, s32 options)
{
    u16 visibilityMode;
    u16 workOptions;
    f32 radius;
    u8 *entry;
    u8 *action;

    *(s32 *)(camera + 0x134) = *(s32 *)(*(u8 **)(camera + 0xE0) + 0x38);
    *(u16 *)(camera + 0x140) = *(u16 *)(*(u8 **)(camera + 0xE0) + 0x6A);
    action = *(u8 **)(camera + 0xE0);
    workOptions = (u16)options;
    workOptions = workOptions | 1;
    btlCameraInitWork(camera + 0xEC, (s32)action, *(s32 *)(action + 0x38), script,
                  workOptions);
    *(u16 *)(camera + 0x142) = *(u8 *)(script + 1);
    entry = btlCameraGetCurrentEntry(camera + 0xEC);
    if (entry != NULL) {
        if ((((BtlCameraScriptEntry *)entry)->focusSource == 1) &&
            ((*(u16 *)(camera + 0x142) & 2) == 0)) {
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 1);
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 8);
            *(s32 *)(camera + 0x138) = 1;
        } else {
            radius = 0.0f;
            if ((*(u16 *)(camera + 0x142) & 4) != 0) {
                visibilityMode = 0x18;
            } else {
                visibilityMode = 0xA;
            }
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, radius,
                          visibilityMode);
            *(s32 *)(camera + 0x138) = 0;
        }
    }
    *(s32 *)(camera + 0x13C) = 0;
}

/* measured: close opt_propagation probe for bdd80. */
// FUN_001BDEB0
/* Advance the effect script only while action, target count, and target identity remain valid. Raw offsets retained: the proven camera/action struct rewrite changed whole-file MWCC instructions. */
void btlCameraUpdateEffectList(u8 *camera)
{
    u16 visibilityMode;
    s32 mode;
    u8 *entry;
    u8 *target;
    u8 *action;

    action = *(u8 **)(camera + 0xE0);
    if ((action != NULL) &&
        (*(u16 *)(action + 0x6A) == *(u16 *)(camera + 0x140)) &&
        (target = *(u8 **)(camera + 0x134), target != NULL) &&
        (target == *(u8 **)(action + 0x38)) &&
        ((*(u16 *)(action + 0x1A) & 1) != 0)) {
        if (btlCameraIsEnabled(camera + 0xEC) != 0) {
            btlCameraFrameActionStart(camera, camera + 0xEC);
        }
        entry = btlCameraGetCurrentEntry(camera + 0xEC);
        if (entry != NULL) {
            if ((((BtlCameraScriptEntry *)entry)->focusSource == 1) &&
                ((*(u16 *)(camera + 0x142) & 2) == 0)) {
                if (*(s32 *)(camera + 0x13C) != 0) {
                    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x201);
                }
                *(s32 *)(camera + 0x138) = 1;
                return;
            }
            if (*(s32 *)(camera + 0x138) == 1) {
                mode = 3;
            } else {
                mode = 0xC3;
            }
            visibilityMode = mode & 0xFFFF;
            if (*(s32 *)(camera + 0x13C) == 0) {
                if (datCalcIsDead(*(s32 *)(*(u8 **)(*(u8 **)(camera + 0x134) + 0x30) + 0xA64),
                                  0) == 0) {
                    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), camera + 0x9C,
                                  (f32 *)(*(u8 **)(*(u8 **)(camera + 0x134) + 0x30) + 4),
                                  50.0f, visibilityMode);
                }
            } else {
                btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, visibilityMode);
            }
            *(s32 *)(camera + 0x138) = 0;
        }
    }
}

