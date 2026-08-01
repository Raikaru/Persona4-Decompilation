/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00482730)
/* Source unit: src/Graphics/Model/mdlEffect_00482730.c */
#include "type.h"

/* Removing this loses FUN_00482730 (MATCH nd0 -> MISMATCH nd45) - measured W161. */
// FUN_00482730
#pragma opt_loop_invariants on
void func_00482730(int param_1, u32 param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = *(int *)(param_1 + 0xc);
  for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    iVar2 = *(int *)(param_1 + 0x10) + iVar3 * 0x14;
    *(u32 *)(iVar2 + 4) = param_2 % *(u32 *)(*(int *)(iVar2 + 0xc) + 0xc);
    *(u32 *)(iVar2 + 8) = 1;
  }
  return;
}
#pragma opt_loop_invariants off
#endif /* P4_UNIT_00482730 */

#if defined(P4_UNIT_004839D0)
/* Source unit: src/Graphics/Model/mdlEffect_004839d0.c */
#include "type.h"

// FUN_004839D0
void func_004839d0(int param_1, u32 *param_2)
{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)**(int **)(param_1 + 0x14);
  param_2[2] = (u32)piVar1;

  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    *param_2 = *(u32 *)(iVar2 + 0xc);
    param_2[1] = *(u32 *)(iVar2 + 0x10);
  }

  return;
}
#endif /* P4_UNIT_004839D0 */

#if defined(P4_UNIT_00484490)
/* Source unit: src/Graphics/Model/mdlEffect_00484490.c */
#include "type.h"

// FUN_00484490
int func_00484490(int param_1)
{
  int value;

  if (*(int *)(param_1 + 0x18) == 0) {
    goto check;
  }

  value = *(int *)(param_1 + 0x10);
  goto done;
check:
  value = *(int *)(param_1 + 0x10);
  if (value == 0) {
    goto zero;
  }

  value = (int)((u8 *)param_1 + value);
  goto done;
zero:
  value = 0;
done:
  return value;
}
#endif /* P4_UNIT_00484490 */

#if defined(P4_UNIT_004844D0)
/* Source unit: src/Graphics/Model/mdlEffect_004844d0.c */
#include "type.h"

// FUN_004844D0
int func_004844d0(int param_1)
{
  int value;

  if (*(int *)(param_1 + 0x28) == 0) {
    goto check;
  }

  value = *(int *)(param_1 + 0x20);
  goto done;
check:
  value = *(int *)(param_1 + 0x20);
  if (value == 0) {
    goto zero;
  }

  value = (int)((u8 *)param_1 + value);
  goto done;
zero:
  value = 0;
done:
  return value;
}
#endif /* P4_UNIT_004844D0 */

#if defined(P4_UNIT_00486740)
/* Source unit: src/Graphics/Model/mdlEffect_00486740.c */
#include "type.h"

// FUN_00486740
#pragma push
int func_00486740(int param_1, int param_2)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x8c);
  while (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x90) == param_2) {
      return iVar1;
    }
    iVar1 = *(int *)(iVar1 + 0xac);
  }

  return 0;
}
#pragma pop
#endif /* P4_UNIT_00486740 */

#if defined(P4_UNIT_0048A810)
/* Source unit: src/Graphics/Model/mdlEffect_0048a810.c */
#include "type.h"

/* Retail's 368-byte Catmull-Rom interpolator builds tangents and returns its VU0 vector in vf10. */
// FUN_0048A810
void func_0048a810(float param_1, u8 (*param_2)[16])
{
  float work[7][4];
  float square;
  float cube;
  float coefficient;

  square = param_1 * param_1;
  cube = square * param_1;

  work[4][0] = 0.5f;
  work[4][1] = 0.5f;
  work[4][2] = 0.5f;

  /* VU0 builds the two Catmull-Rom tangent vectors in work[6] and work[5]. */
  asm volatile (
      ".set noreorder                         \n"
      "lqc2        $vf10, 0x10($a0)           \n"
      "lqc2        $vf11, 0x0($a0)            \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "lqc2        $vf10, 0x20($a0)           \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      "addiu       $v1, $sp, 0x40              \n"
      "lqc2        $vf11, 0x0($v1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "addiu       $a2, $sp, 0x60              \n"
      "sqc2        $vf10, 0x0($a2)            \n"
      "lqc2        $vf10, 0x20($a0)           \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "lqc2        $vf10, 0x30($a0)           \n"
      "lqc2        $vf11, 0x20($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      "lqc2        $vf11, 0x0($v1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "addiu       $a1, $sp, 0x50              \n"
      "sqc2        $vf10, 0x0($a1)            \n"
      ".set reorder"
      :
      :
      : "memory"
  );

  coefficient = cube * 2.0f - square * 3.0f + 1.0f;
  work[0][0] = coefficient;
  work[0][1] = coefficient;
  work[0][2] = coefficient;

  coefficient = param_1 + (cube - square * 2.0f);
  work[1][0] = coefficient;
  work[1][1] = coefficient;
  work[1][2] = coefficient;

  coefficient = cube - square;
  work[2][0] = coefficient;
  work[2][1] = coefficient;
  work[2][2] = coefficient;

  coefficient = cube * -2.0f + square * 3.0f;
  work[3][0] = coefficient;
  work[3][1] = coefficient;
  work[3][2] = coefficient;

  /* VU0 evaluates the Hermite basis and leaves the interpolated vector in vf10. */
  asm volatile (
      ".set noreorder                         \n"
      "addiu       $v1, $sp, 0x0               \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "addiu       $v1, $sp, 0x10              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x0($a2)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf12, $vf12, $vf10        \n"
      "addiu       $v1, $sp, 0x20              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x0($a1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf12, $vf12, $vf10        \n"
      "addiu       $v1, $sp, 0x30              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x20($a0)           \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      ".set reorder"
      :
      :
      : "memory"
  );
}
#endif /* P4_UNIT_0048A810 */

#if defined(P4_UNIT_00492DB0)
/* Source unit: src/Graphics/Model/mdlEffect_00492db0.c */
#include "type.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

// FUN_00492DB0
u_long128 func_00492db0(int param_1, u32 *param_2)
{
  u_long128 value = *(u_long128 *)(*(int *)(param_1 + 0x20));
  *(u_long128 *)param_2 = value;
  return value;
}
#endif /* P4_UNIT_00492DB0 */

#if defined(P4_UNIT_00492DD0)
/* Source unit: src/Graphics/Model/mdlEffect_00492dd0.c */
#include "type.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

#pragma push
#pragma opt_propagation off
// FUN_00492DD0
u_long128 func_00492dd0(int param_1, u32 *param_2)
{
  u_long128 *dst;
  u_long128 value;

  dst = *(u_long128 **)(param_1 + 0x20);
  value = *(u_long128 *)param_2;
  *dst = value;
  return value;
}
#pragma pop
#endif /* P4_UNIT_00492DD0 */

#if defined(P4_UNIT_00492DF0)
/* Source unit: src/Graphics/Model/mdlEffect_00492df0.c */
#include "type.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

// FUN_00492DF0
u_long128 func_00492df0(int param_1, u32 *param_2)
{
  return *(u_long128 *)param_2 =
      *(u_long128 *)(*(int *)(param_1 + 0x20) + 0x10);
}
#endif /* P4_UNIT_00492DF0 */

#if defined(P4_UNIT_00492E10)
/* Source unit: src/Graphics/Model/mdlEffect_00492e10.c */
#include "type.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

#pragma push
#pragma opt_propagation off
// FUN_00492E10
u_long128 func_00492e10(int param_1, u32 *param_2)
{
  u_long128 *dst;
  u_long128 value;

  dst = (u_long128 *)(*(int *)(param_1 + 0x20) + 0x10);
  value = *(u_long128 *)param_2;
  *dst = value;
  return value;
}
#pragma pop
#endif /* P4_UNIT_00492E10 */

#if defined(P4_UNIT_004946D0)
/* Source unit: src/Graphics/Model/mdlEffect_004946d0.c */
#include "type.h"

// FUN_004946D0
void func_004946d0(int param_1, u32 param_2)
{
  u32 index;
  u8 *base;

  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  *(u16 *)(base + index) = 0;

  return;
}
#endif /* P4_UNIT_004946D0 */

#if defined(P4_UNIT_004946F0)
/* Source unit: src/Graphics/Model/mdlEffect_004946f0.c */
#include "type.h"

// FUN_004946F0
void func_004946f0(int param_1, u32 param_2)
{
  s16 value;
  u32 index;
  u8 *base;

  value = -1;
  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  *(s16 *)(base + index) = value;

  return;

}
#endif /* P4_UNIT_004946F0 */

#if defined(P4_UNIT_00482700)
/* Source unit: src/Graphics/Model/mdlEffect_00482700.c */
#include "type.h"

extern void func_004824a0(int *param_1, u8 *param_2, float *param_3);

// FUN_00482700
void func_00482700(int param_1, float *param_2)
{
  func_004824a0((int *)(u32)param_1, (u8 *)(u32)*(u32 *)(param_1 + 0x10), param_2);
}
#endif /* P4_UNIT_00482700 */

#if defined(P4_UNIT_00486710)
/* Source unit: src/Graphics/Model/mdlEffect_00486710.c */
#include "type.h"

extern u64 memcpy();

// FUN_00486710
void func_00486710(u64 param_1, u64 param_2)
{
  memcpy(param_1, param_2, 0x90);
  return;
}
#endif /* P4_UNIT_00486710 */

#if defined(P4_UNIT_00487C00)
/* Source unit: src/Graphics/Model/mdlEffect_00487c00.c */
#include "type.h"

extern void func_00492d00(int param_1);

// FUN_00487C00
void func_00487c00(int param_1)
{
  if (*(int *)(param_1 + 0x4c) != 0) {
    func_00492d00(*(int *)(param_1 + 0x4c));
  }
  return;
}
#endif /* P4_UNIT_00487C00 */

#if defined(P4_UNIT_00489E50)
/* Source unit: src/Graphics/Model/mdlEffect_00489e50.c */
#include "type.h"

extern void func_00487fb0(float param_1, int param_2);
#pragma alias func_00487fb0_evt func_00487fb0
extern void func_00487fb0_evt(float param_1);

// FUN_00489E50
void func_00489e50(void)
{
  func_00487fb0_evt(1.0f);
}
#endif /* P4_UNIT_00489E50 */

#if defined(P4_UNIT_00489F50)
/* Source unit: src/Graphics/Model/mdlEffect_00489f50.c */
#include "type.h"

extern void func_00492e30(u16 *param_1);

// FUN_00489F50
void func_00489f50(f32 param_1, int param_2)
{
  *(f32 *)(param_2 + 8) = param_1;
  func_00492e30((u16 *)*(u32 *)(param_2 + 0x4c));
  return;
}
#endif /* P4_UNIT_00489F50 */

#if defined(P4_UNIT_00494710)
/* Source unit: src/Graphics/Model/mdlEffect_00494710.c */
#include "type.h"

// FUN_00494710
u8 func_00494710(int param_1, u32 param_2)
{
  u32 index;
  u8 *base;
  s16 value;

  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  value = *(s16 *)(base + index);

  return value == -1;
}
#endif /* P4_UNIT_00494710 */

#if defined(P4_UNIT_004A6E50)
/* Source unit: src/Graphics/Model/mdlEffect_004a6e50.c */
#include "type.h"

// FUN_004A6E50
void func_004a6e50(int param_1)
{
  *(u32 *)(param_1 + 0x10) = *(u32 *)(param_1 + 0x10) + 1;
}
#endif /* P4_UNIT_004A6E50 */

#if defined(P4_UNIT_004A77A0)
/* Source unit: src/Graphics/Model/mdlEffect_004a77a0.c */
#include "type.h"

// FUN_004A77A0
void func_004a77a0(u32 *param_1, u32 param_2)
{
  param_1[5] = param_2;
}
#endif /* P4_UNIT_004A77A0 */

#if defined(P4_UNIT_004AC2C0)
/* Source unit: src/Graphics/Model/mdlEffect_004ac2c0.c */
#include "type.h"

// FUN_004AC2C0
void func_004ac2c0(u32 *param_1)
{
  if ((param_1[0x23] >= param_1[0x26]) || (param_1[0x23] == 0)) {
    *(f32 *)(param_1 + 9) = 1.0f;
    param_1[0x26] = param_1[0x26] + 1;
  }
}
#endif /* P4_UNIT_004AC2C0 */

#if defined(P4_UNIT_004AC620)
/* Source unit: src/Graphics/Model/mdlEffect_004ac620.c */
#include "type.h"

// FUN_004AC620
void func_004ac620(int param_1, int param_2)
{
  *(int *)(param_1 + 0x28) = param_2;
}
#endif /* P4_UNIT_004AC620 */

#if defined(P4_UNIT_004AE020)
/* Source unit: src/Graphics/Model/mdlEffect_004ae020.c */
#include "type.h"

// FUN_004AE020
u32 *func_004ae020(u32 *param_1, u8 *param_2)
{
  u32 *t2;
  int t1;
  int t3;
  u8 *t0;

  u8 c0;
  u8 c1;
  u8 c2;
  u8 c3;

  t2 = *(u32 **)((u8 *)param_1 + 0x18);
  t1 = t2[9];
  t3 = 0;
  goto check;
loop:
  t0 = *(u8 **)(t2[8] + t3 * 4);
  c0 = param_2[0];
  c1 = param_2[1];
  c2 = param_2[2];
  c3 = param_2[3];
  c0 = c0;
  c1 = c1;
  c2 = c2;
  c3 = c3;
  t0[4] = c0;
  t0[5] = c1;
  t0[6] = c2;
  t0[7] = c3;
  t3 = t3 + 1;
check:
  if (t3 < t1) goto loop;
  return param_1;
}
#endif /* P4_UNIT_004AE020 */

#if defined(P4_UNIT_004AE080)
/* Source unit: src/Graphics/Model/mdlEffect_004ae080.c */
#include "type.h"

// FUN_004AE080
u32 *func_004ae080(u32 *param_1)
{
  u32 *p;

  p = *(u32 **)((u8 *)param_1 + 0x18);
  p[2] = p[2] | 0x40;
  return param_1;
}
#endif /* P4_UNIT_004AE080 */

#if defined(P4_UNIT_004B1580)
/* Source unit: src/Graphics/Model/mdlEffect_004b1580.c */
#include "type.h"

// FUN_004B1580
u32 func_004b1580(int param_1)
{
  return *(u32 *)(param_1 + 0x84);
}
#endif /* P4_UNIT_004B1580 */

#if defined(P4_UNIT_004B2770)
/* Source unit: src/Graphics/Model/mdlEffect_004b2770.c */
#include "type.h"

// FUN_004B2770
void func_004b2770(u32 *param_1, u32 param_2)
{
  *param_1 = param_2;
}
#endif /* P4_UNIT_004B2770 */
