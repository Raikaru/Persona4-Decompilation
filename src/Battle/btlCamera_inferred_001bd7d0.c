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

typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern void memset(void *dst, s32 value, s32 size);
extern s32 func_003bbb60(u8 *arg0);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern u32 datCalcIsDead(s32 arg0, s32 arg1);
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
extern void (*D_005F6E20[])(u8 *arg0);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern u32 iGpffffa0b8;
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern void btlCameraStartEffect(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern s32 btlCameraFrameActionStart(u8 *arg0, u8 *arg1);
extern u8 *btlCameraGetCurrentEntry(u8 *arg0);
extern void btlCameraInitWork(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void btlCameraUpdateEffectList(u8 *arg0);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern void func_001bdd60(void);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern void primQuad3D(f32 *arg0, u8 *arg1, s32 arg2, f32 arg3);
extern void primAxisLine3D(f32 *arg0, s32 arg1, f32 arg2);
extern u8 *btlEncounterGetRecord(s32 arg0);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern s32 func_00457120(void);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void btlCameraUpdateUnitInRangeFlags(void);
extern u8 *func_003e8180(u8 *arg0, f32 arg1);
extern s32 func_003bbbe0(s32 arg0, s32 arg1, void *arg2);
extern void func_001d12e0(void *arg0);
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

/* Source unit: src/promoted/code1_001b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001b.c; members 001bd7d0-001bdeb0 */

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
void btlCameraApplyView(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Bd7Vec3;
    typedef struct {
        Bd7Vec3 right;
        u32 flags;
        Bd7Vec3 up;
        u32 pad1;
        Bd7Vec3 at;
        u32 pad2;
        Bd7Vec3 pos;
        u32 pad3;
    } Bd7Matrix;
    Bd7Matrix matrix;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f10;
    f32 temp_f11;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f5;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    void (*callback)(u8 *arg0);
    s32 temp_2;
    u16 temp_16;
    u8 *temp_6;
    u8 *temp_7;

    if ((*(s32 *)(D_0076449C + 0xF8) & 1) == 0) {
        temp_2 = *(s32 *)(D_0076449C + 0x100);
        if (temp_2 <= 0) {
            temp_16 = *(u16 *)(D_0076449C + 0xF4);
            temp_7 = btlEncounterGetRecord(temp_16);
            if (temp_7 == NULL) {
                temp_7 = D_005F74C0 + ((temp_16 & 0xFFFF) * 0x14);
            }
            callback = *(void (**)(u8 *))(temp_7 + 4);
            if (callback != NULL) {
                callback(D_0076449C + 0x24);
            }
            btlCameraUpdateTransition(D_0076449C + 0x24);
            *(s32 *)(D_0076449C + 0xFC) =
                *(s32 *)(D_0076449C + 0xFC) + 1;
        } else {
            *(s32 *)(D_0076449C + 0x100) = temp_2 - 1;
        }
        temp_f4 = *(f32 *)(D_0076449C + 0xD0);
        temp_f12 = *(f32 *)(D_0076449C + 0xCC);
        temp_f11 = *(f32 *)(D_0076449C + 0xD4);
        temp_f3 = *(f32 *)(D_0076449C + 0xD8);
        temp_f0 =
            2.0f / ((temp_f12 * temp_f12) +
                    (temp_f4 * temp_f4) +
                    (temp_f11 * temp_f11) +
                    (temp_f3 * temp_f3));
        temp_f2 = temp_f12 * temp_f0;
        temp_f1 = temp_f4 * temp_f0;
        temp_f0_2 = temp_f11 * temp_f0;
        temp_f10 = temp_f2 * temp_f3;
        temp_f9 = temp_f1 * temp_f3;
        temp_f8 = temp_f0_2 * temp_f3;
        temp_f7 = temp_f12 * temp_f2;
        temp_f6 = temp_f4 * temp_f1;
        temp_f5 = temp_f11 * temp_f0_2;
        temp_f4_2 = temp_f4 * temp_f0_2;
        temp_f3_2 = temp_f11 * temp_f2;
        temp_f2_2 = temp_f12 * temp_f1;
        matrix.right.x = 1.0f - (temp_f6 + temp_f5);
        matrix.right.y = temp_f2_2 + temp_f8;
        matrix.right.z = temp_f3_2 - temp_f9;
        matrix.up.x = temp_f2_2 - temp_f8;
        matrix.up.y = 1.0f - (temp_f5 + temp_f7);
        matrix.up.z = temp_f4_2 + temp_f10;
        matrix.at.x = temp_f3_2 + temp_f9;
        matrix.at.y = temp_f4_2 - temp_f10;
        matrix.at.z = 1.0f - (temp_f7 + temp_f6);
        matrix.pos.x = 0.0f;
        matrix.pos.y = 0.0f;
        matrix.pos.z = 0.0f;
        matrix.flags = 3;
        matrix.pos = *(Bd7Vec3 *)(D_0076449C + 0xC0);
        temp_6 = ((u8 *)func_00457120());
        func_003e9cb0(*(u8 **)(temp_6 + 4), &matrix, 0);
        K_View_SetFov(((u8 *)func_00457120()),
                      fGpffff8048 * *(f32 *)(D_0076449C + 0xDC));
    }
    if ((*(s32 *)(D_0076449C + 0xF8) & 2) != 0) {
        btlCameraUpdateUnitInRangeFlags();
    }
}

/* measured: plain C candidate is 380 bytes in the 384-byte retail window with normalized_diff 6; residual is limited to the global-position load order and one retail tail padding word. */
// Committed at nd 6.
// FUN_001BD9E0
void btlCameraDrawDebug(void)
{
  typedef struct 
  {
    f32 x;
    f32 y;
    f32 z;
  } Bd9Vec3;
  typedef struct 
  {
    Bd9Vec3 right;
    u32 flags;
    Bd9Vec3 up;
    u32 pad1;
    Bd9Vec3 at;
    u32 pad2;
    Bd9Vec3 pos;
    u32 pad3;
  } Bd9Matrix;
  u8 color[4];
  Bd9Matrix matrix;
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f10;
  f32 temp_f11;
  f32 temp_f12;
  f32 temp_f1;
  f32 temp_f2;
  f32 temp_f2_2;
  f32 temp_f3;
  f32 temp_f3_2;
  f32 temp_f4;
  f32 temp_f4_2;
  f32 temp_f5;
  f32 temp_f6;
  f32 temp_f7;
  f32 temp_f8;
  f32 temp_f9;
  s32 temp_4;
  u8 *temp_5;
  u8 *temp_6;
  temp_5 = D_0076449C;
  if (((*((s32 *) (temp_5 + 0xC))) & 4) == 0)
  {
    temp_4 = *((s32 *) (temp_5 + 0x14));
    if (((temp_4 & 4) == 0) && ((temp_4 & 8) != 0))
    {
      color[0] = 0xFF;
      color[1] = 0xFF;
      color[2] = 0;
      color[3] = 0xFF;
      temp_f4 = *((f32 *) (temp_5 + 0xD0));
      temp_f12 = *((f32 *) (temp_5 + 0xCC));
      temp_f11 = *((f32 *) (temp_5 + 0xD4));
      temp_f3 = *((f32 *) (temp_5 + 0xD8));
      temp_f0 = 2.0f / ((((temp_f12 * temp_f12) + (temp_f4 * temp_f4)) + (temp_f11 * temp_f11)) + (temp_f3 * temp_f3));
      temp_f2 = temp_f12 * temp_f0;
      temp_f1 = temp_f4 * temp_f0;
      temp_f0_2 = temp_f11 * temp_f0;
      temp_f10 = temp_f2 * temp_f3;
      temp_f9 = temp_f1 * temp_f3;
      temp_f8 = temp_f0_2 * temp_f3;
      temp_f7 = temp_f12 * temp_f2;
      temp_f6 = temp_f4 * temp_f1;
      temp_f5 = temp_f11 * temp_f0_2;
      temp_f4_2 = temp_f4 * temp_f0_2;
      temp_f3_2 = temp_f11 * temp_f2;
      temp_f2_2 = temp_f12 * temp_f1;
      if (((!temp_f3) && (!temp_f3)) && (!temp_f3))
      {
      }
      matrix.right.x = 1.0f - (temp_f6 + temp_f5);
      matrix.right.y = temp_f2_2 + temp_f8;
      matrix.right.z = temp_f3_2 - temp_f9;
      matrix.up.x = temp_f2_2 - temp_f8;
      matrix.up.y = 1.0f - (temp_f5 + temp_f7);
      matrix.up.z = temp_f4_2 + temp_f10;
      matrix.at.x = temp_f3_2 + temp_f9;
      matrix.at.y = temp_f4_2 - temp_f10;
      matrix.at.z = 1.0f - (temp_f7 + temp_f6);
      matrix.pos.x = 0.0f;
      matrix.pos.y = 0.0f;
      matrix.pos.z = 0.0f;
      matrix.flags = 3;
      temp_6 = temp_5 + 0xC0;
      temp_f2 = *((f32 *) temp_6);
      temp_f1 = *((f32 *) (temp_6 + 4));
      temp_f0 = *((f32 *) (temp_6 + 8));
      matrix.pos.x = temp_f2;
      matrix.pos.y = temp_f1;
      matrix.pos.z = temp_f0;
      primQuad3D((f32 *) temp_6, color, 1, 6.0f);
      primAxisLine3D((f32 *) (&matrix), 1, 150.0f);
    }
  }
}

// FUN_001BDB60
void btlCameraInitSystem(void)
{
    s32 temp_2;
    s32 var_4;
    u16 temp_4;
    u8 *temp_3;
    u8 *temp_3_2;

    func_003e8180(((u8 *)func_00457120()), 35.0f);
    K_View_SetFov(((u8 *)func_00457120()), 40.0f);
    {
        u8 *base;

        base = D_0076449C;
        temp_3 = base + 0x24;
        *(s16 *)(base + 0x24) = 1;
        *(s16 *)(base + 0x98) = 0;
        *(s16 *)(base + 0x9A) = 0;
        *(s16 *)(base + 0x9C) = 0;
        *(s32 *)(base + 0xA4) = 0;
        *(s32 *)(base + 0xA0) = 0;
    }
    chkmemAllocSiteTag(&D_005F72B0, 0x3A);
    temp_3_2 = temp_3;
    temp_2 = (s32)(*jtbl_008873E8)(0x30, 0x40000);
    memset((void *)temp_2, 0, 0x30);
    *(s32 *)(temp_3_2 + 0x98) = func_003bbbe0(4, 1, (void *)temp_2);
    (*jtbl_008873EC)((u8 *)temp_2);
    func_00457120();
    *(f32 *)(D_0076449C + 0xD8) = fGpffff8314;
    *(f32 *)(D_0076449C + 0xCC) = fGpffff8318;
    *(f32 *)(D_0076449C + 0xD0) = fGpffff831c;
    *(f32 *)(D_0076449C + 0xD4) = fGpffff8320;
    *(f32 *)(D_0076449C + 0xC0) = fGpffff8324;
    *(f32 *)(D_0076449C + 0xC4) = fGpffff8328;
    *(f32 *)(D_0076449C + 0xC8) = fGpffff832c;
    *(f32 *)(D_0076449C + 0xDC) = fGpffff8184;
    *(s16 *)(D_0076449C + 0xF4) = 0;
    *(s16 *)(D_0076449C + 0x10E) = 0;
    var_4 = 0;
    goto loop_test;
loop_body:
    temp_4 = var_4;
    *(s16 *)(D_0076449C + (temp_4 * 2) + 0x108) = 0;
    var_4 = (var_4 + 1) & 0xFFFF;
loop_test:
    if ((var_4 & 0xFFFF) < 3) {
        goto loop_body;
    }
    *(s32 *)(D_0076449C + 0xF8) |= 2;
    func_001d12e0(D_0076449C + 0x110);
}

// FUN_001BDD30
void btlCameraResetWorkList(void)
{
    s32 temp_4;

    temp_4 = *(s32 *)(D_0076449C + 0xBC);
    if (temp_4 != 0) {
        func_003bbb60((u8 *)temp_4);
    }
}

// FUN_001BDD60
void func_001bdd60(void) {
    *(u32 *)(D_0076449C + 0xF8) |= 1;
}

/* measured: opt_propagation off probe for bdd80 nd28 float scheduling. */
// FUN_001BDD80
void btlCameraStartEffect(u8 *arg0, u8 *arg1, s32 arg2)
{
    u16 var_7;
    u16 temp_16;
    f32 temp_f12;
    u8 *temp_2;
    u8 *temp_5;

    *(s32 *)(arg0 + 0x134) = *(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x38);
    *(u16 *)(arg0 + 0x140) = *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6A);
    temp_5 = *(u8 **)(arg0 + 0xE0);
    temp_16 = (u16)arg2;
    temp_16 = temp_16 | 1;
    btlCameraInitWork(arg0 + 0xEC, (s32)temp_5, *(s32 *)(temp_5 + 0x38), arg1,
                  temp_16);
    *(u16 *)(arg0 + 0x142) = *(u8 *)(arg1 + 1);
    temp_2 = btlCameraGetCurrentEntry(arg0 + 0xEC);
    if (temp_2 != NULL) {
        if ((*(u16 *)(temp_2 + 0x1C) == 1) &&
            ((*(u16 *)(arg0 + 0x142) & 2) == 0)) {
            btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
            btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 8);
            *(s32 *)(arg0 + 0x138) = 1;
        } else {
            temp_f12 = 0.0f;
            if ((*(u16 *)(arg0 + 0x142) & 4) != 0) {
                var_7 = 0x18;
            } else {
                var_7 = 0xA;
            }
            btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, temp_f12,
                          var_7);
            *(s32 *)(arg0 + 0x138) = 0;
        }
    }
    *(s32 *)(arg0 + 0x13C) = 0;
}

/* measured: close opt_propagation probe for bdd80. */
// FUN_001BDEB0
void btlCameraUpdateEffectList(u8 *arg0)
{
    u16 temp_16;
    s32 var_2;
    u8 *temp_2;
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if ((temp_5 != NULL) &&
        (*(u16 *)(temp_5 + 0x6A) == *(u16 *)(arg0 + 0x140)) &&
        (temp_4 = *(u8 **)(arg0 + 0x134), temp_4 != NULL) &&
        (temp_4 == *(u8 **)(temp_5 + 0x38)) &&
        ((*(u16 *)(temp_5 + 0x1A) & 1) != 0)) {
        if (btlCameraIsEnabled(arg0 + 0xEC) != 0) {
            btlCameraFrameActionStart(arg0, arg0 + 0xEC);
        }
        temp_2 = btlCameraGetCurrentEntry(arg0 + 0xEC);
        if (temp_2 != NULL) {
            if ((*(u16 *)(temp_2 + 0x1C) == 1) &&
                ((*(u16 *)(arg0 + 0x142) & 2) == 0)) {
                if (*(s32 *)(arg0 + 0x13C) != 0) {
                    btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x201);
                }
                *(s32 *)(arg0 + 0x138) = 1;
                return;
            }
            if (*(s32 *)(arg0 + 0x138) == 1) {
                var_2 = 3;
            } else {
                var_2 = 0xC3;
            }
            temp_16 = var_2 & 0xFFFF;
            if (*(s32 *)(arg0 + 0x13C) == 0) {
                if (datCalcIsDead(*(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0x134) + 0x30) + 0xA64),
                                  0) == 0) {
                    btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C,
                                  (f32 *)(*(u8 **)(*(u8 **)(arg0 + 0x134) + 0x30) + 4),
                                  50.0f, temp_16);
                }
            } else {
                btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, temp_16);
            }
            *(s32 *)(arg0 + 0x138) = 0;
        }
    }
}

