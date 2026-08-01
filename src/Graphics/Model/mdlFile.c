/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00230BC0)
/* Source unit: src/Graphics/Model/mdlFile_00230bc0.c (1 function markers) */
#include "type.h"

#define MODEL_TYPE_BTLCHAR 1
#define MODEL_TYPE_ENEMY 2

// FUN_00230BC0
u8 func_00230bc0(u16 type)
{
    switch (type)
    {
        case MODEL_TYPE_BTLCHAR: // fallthrough
        case MODEL_TYPE_ENEMY:   return 1;
    }

    return 0;
}
#endif /* P4_UNIT_00230BC0 */

#if defined(P4_UNIT_0047FFC0)
/* Source unit: src/Graphics/Model/mdlFile_0047ffc0.c (1 function markers) */
#include "type.h"

// FUN_0047FFC0
void func_0047ffc0(int *param_1)
{
  u8 uVar0;

  u8 uVar1;

  u8 uVar2;

  u8 uVar3;

  u32 uVar4;

  int *piVar5;

  int iVar6;

  int iVar8;

  u32 uVar7;

  f32 fVar9;

  f32 fVar11;
  f32 fVar10;

  iVar8 = *param_1;
  for (; iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x54)) {

    piVar5 = *(int **)(iVar8 + 0x50);

    uVar4 = *(u16 *)(piVar5 + 1);

    for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
      iVar6 = *(int *)(*piVar5 + uVar7 * 4);
      uVar0 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ u8 *)(iVar8 + 0x40);
      uVar1 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ u8 *)(iVar8 + 0x41);
      uVar2 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ u8 *)(iVar8 + 0x42);
      uVar3 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ u8 *)(iVar8 + 0x43);
      *(u8 *)(iVar6 + 4) = uVar0;
      *(u8 *)(iVar6 + 5) = uVar1;
      *(u8 *)(iVar6 + 6) = uVar2;
      *(u8 *)(iVar6 + 7) = uVar3;
      iVar6 = *(int *)(*piVar5 + uVar7 * 4);
      fVar9 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ f32 *)(iVar8 + 0x44);
      fVar10 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ f32 *)(iVar8 + 0x48);
      fVar11 = *(volatile /* Removing this function's qualifier batch loses FUN_0047FFC0 (MATCH nd0 -> MISMATCH nd14, size 152 -> 152) - measured W170, ported from P3 FUN_00320770. */ f32 *)(iVar8 + 0x4c);
      *(f32 *)(iVar6 + 0xc) = fVar9;
      *(f32 *)(iVar6 + 0x10) = fVar10;
      *(f32 *)(iVar6 + 0x14) = fVar11;
    }


  }

  return;

}
#endif /* P4_UNIT_0047FFC0 */

#if defined(P4_UNIT_004808F0)
/* Source unit: src/Graphics/Model/mdlFile_004808f0.c (1 function markers) */
#include "type.h"

// FUN_004808F0
u32 func_004808f0(int param_1)
{
  *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) + 1;

  return param_1;

}
#endif /* P4_UNIT_004808F0 */

#if defined(P4_UNIT_00480910)
/* Source unit: src/Graphics/Model/mdlFile_00480910.c (1 function markers) */
#include "type.h"

// FUN_00480910
void func_00480910(int *param_1,u32 param_2)
{
  *(u32 *)(*param_1 + (u32)*(u16 *)(param_1 + 1) * 4) = param_2;

  *(short *)(param_1 + 1) = (u16)param_1[1] + 1;

  return;

}
#endif /* P4_UNIT_00480910 */

#if defined(P4_UNIT_0047D2D0)
/* Source unit: src/Graphics/Model/mdlFile_0047d2d0.c (1 function markers) */
#include "type.h"

typedef int (*code)(...);
#pragma alias DAT_008873ec_abs DAT_008873ec
extern code DAT_008873ec_abs[];
extern void func_0047d990(u32 *param_1);

// FUN_0047D2D0
void func_0047d2d0(u32 *param_1)
{
  func_0047d990(param_1);

  DAT_008873ec_abs[0](param_1);
}
#endif /* P4_UNIT_0047D2D0 */

#if defined(P4_UNIT_0047D840)
/* Source unit: src/Graphics/Model/mdlFile_0047d840.c (1 function markers) */
#include "type.h"

extern void func_004b1170();

// FUN_0047D840
void func_0047d840(u32 *param_1)
{
  int *piVar1;

  for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {

    if ((piVar1[2] != 0) && ((*(u32 *)(*piVar1 + 0xc) & 1) != 0)) {

      func_004b1170(piVar1[2]);
    }


  }

  return;

}
#endif /* P4_UNIT_0047D840 */

#if defined(P4_UNIT_0047D900)
/* Source unit: src/Graphics/Model/mdlFile_0047d900.c (1 function markers) */
#include "type.h"

extern void func_004b13d0(float param_1,u8 (*param_2) [16]);

// FUN_0047D900
void func_0047d900(int *param_1,float *param_2)
{
    int current;
    float average;

    average = (param_2[0] + param_2[1] + param_2[2]) / 3.0f;
    for (current = *param_1; current != 0; current = *(int*)(current + 0x10)) {
        if (*(int*)(current + 8) != 0) {
            func_004b13d0(average,(u8 (*)[16])*(u32*)(current + 8));
        }
    }
}
#endif /* P4_UNIT_0047D900 */

#if defined(P4_UNIT_0047D990)
/* Source unit: src/Graphics/Model/mdlFile_0047d990.c (1 function markers) */
#include "type.h"

typedef int (*code)(...);
#pragma alias DAT_008873ec_abs DAT_008873ec
extern code DAT_008873ec_abs[];
extern void func_0047dae0(u32 *param_1);

// FUN_0047D990
void func_0047d990(u32 *param_1)
{
    int *current;
    int *next;

    func_0047dae0(param_1);
    current = (int*)*param_1;
    while (current != 0) {
        next = (int*)current[4];
        *(int*)(*current + 8) = *(int*)(*current + 8) - 1;
        if (*(int*)(*current + 8) == 0) {
            ((void (*)(...))DAT_008873ec_abs[0])(*current);
        }
        ((void (*)(...))DAT_008873ec_abs[0])(current);
        current = next;
    }
    *param_1 = 0;
}
#endif /* P4_UNIT_0047D990 */

#if defined(P4_UNIT_0047DA30)
/* Source unit: src/Graphics/Model/mdlFile_0047da30.c (1 function markers) */
#include "type.h"

#pragma alias func_004b1150_i func_004b1150
extern void func_004b1150_i(int param_1);
#pragma alias func_004b1130_u32 func_004b1130
extern u32 func_004b1130_u32(u32 param_1);
extern u32 func_004b11b0();

// FUN_0047DA30
void func_0047da30(u32 *param_1)
{
    int *current;
    u32 value;

    for (current = (int*)*param_1; current != 0; current = (int*)current[4]) {
        if (current[2] != 0) {
            if (current[2] == *(int*)(*current + 4)) {
                *(u32*)(*current + 4) = 0;
            }
            func_004b1150_i(current[2]);
        }
        if (((u32*)*current)[1] == 0) {
            value = func_004b1130_u32(*(u32*)*current);
            current[2] = value;
            *(u32*)(*current + 4) = value;
        } else {
            value = func_004b11b0((u64*)((u32*)*current)[1]);
            current[2] = value;
        }
    }
}
#endif /* P4_UNIT_0047DA30 */

#if defined(P4_UNIT_0047DAE0)
/* Source unit: src/Graphics/Model/mdlFile_0047dae0.c (1 function markers) */
#include "type.h"

#pragma alias func_004b1150_i func_004b1150
extern void func_004b1150_i(int param_1);

// FUN_0047DAE0
void func_0047dae0(u32 *param_1)
{
  int *piVar1;

  for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {

    if (piVar1[2] != 0) {

      if (piVar1[2] == *(int *)(*piVar1 + 4)) {

        *(u32 *)(*piVar1 + 4) = 0;

      }

      func_004b1150_i(piVar1[2]);

      piVar1[2] = 0;

    }

  }

  return;

}
#endif /* P4_UNIT_0047DAE0 */

#if defined(P4_UNIT_0047DCC0)
/* Source unit: src/Graphics/Model/mdlFile_0047dcc0.c (1 function markers) */
#include "type.h"

typedef int (*code)(...);
#pragma alias DAT_008873ec_abs DAT_008873ec
extern code DAT_008873ec_abs[];
extern u64 func_004b5f20();

// FUN_0047DCC0
void func_0047dcc0(int *param_1)
{
    if (param_1[1] != 0) {
        func_004b5f20(param_1[1]);
    }
    *(int*)(*param_1 + 4) = *(int*)(*param_1 + 4) - 1;
    if (*(int*)(*param_1 + 4) == 0) {
        ((void (*)(...))DAT_008873ec_abs[0])(*param_1);
    }
    ((void (*)(...))DAT_008873ec_abs[0])(param_1);
}
#endif /* P4_UNIT_0047DCC0 */

#if defined(P4_UNIT_0047DE00)
/* Source unit: src/Graphics/Model/mdlFile_0047de00.c (1 function markers) */
#include "type.h"

#pragma alias func_0047de90_wide func_0047de90
extern u64 func_0047de90_wide(u32 *param_1);
#pragma alias func_004b57a0_u32 func_004b57a0
extern u32 func_004b57a0_u32(u64 param_1, u64 param_2);

// FUN_0047DE00
void func_0047de00(int param_1,u64 param_2)
{
  u64 uVar1;

  u32 uVar2;

  uVar1 = func_0047de90_wide((u32 *)param_1);

  uVar2 = func_004b57a0_u32(uVar1,param_2);

  *(u32 *)(param_1 + 4) = uVar2;

  return;

}
#endif /* P4_UNIT_0047DE00 */
