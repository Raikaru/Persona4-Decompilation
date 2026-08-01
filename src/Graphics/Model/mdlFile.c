/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00230BC0)
/* Source unit: src/Graphics/Model/mdlFile_00230bc0.c (1 function markers) */
#include "type.h"

#define MODEL_TYPE_BTLCHAR 1
#define MODEL_TYPE_ENEMY 2

// FUN_00230BC0
u8 mdlFileIsTypePac(u16 type)
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

#if defined(P4_UNIT_0047DE50)
/* Source unit: src/Graphics/Model/mdlFile_0047de50.c (1 function markers) */
#include "type.h"

extern u64 func_004b5f20();

// FUN_0047DE50
void func_0047de50(int param_1)
{
  if (*(int *)(param_1 + 4) != 0) {
    func_004b5f20(*(int *)(param_1 + 4));
    *(u32 *)(param_1 + 4) = 0;
  }
  return;
}
#endif /* P4_UNIT_0047DE50 */

#if defined(P4_UNIT_00480580)
/* Source unit: src/Graphics/Model/mdlFile_00480580.c (1 function markers) */
#include "type.h"

extern u32 func_00480430(u32 param_1,u32 *param_2);

// FUN_00480580
u32 func_00480580(u32 param_1,u32 param_2)
{
  int iVar1;
  int iVar2;
  u32 lVar3;
  int iVar4;

  iVar1 = *(int *)((int)param_1 + 0x18);
  iVar2 = *(int *)(iVar1 + 0x24);
  iVar4 = 0;
  goto check;
loop:
  lVar3 = func_00480430((int)(*(u32 *)(*(int *)(iVar1 + 0x20) + iVar4 * 4)),(u32 *)(param_2));
  if (lVar3 != 0) {
    goto increment;
  }
  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 0x40;
  goto done;
increment:
  iVar4 = iVar4 + 1;
check:
  if (iVar4 < iVar2) {
    goto loop;
  }
done:
  return param_1;
}
#endif /* P4_UNIT_00480580 */

#if defined(P4_UNIT_00480630)
/* Source unit: src/Graphics/Model/mdlFile_00480630.c (1 function markers) */
#include "type.h"

extern u64 func_003bff30();
extern u32 func_00480580(u32 param_1,u32 param_2);

// FUN_00480630
u64 func_00480630(u64 param_1,u64 param_2)
{
  func_003bff30(param_1,(void (*)())func_00480580,param_2);
  return param_1;
}
#endif /* P4_UNIT_00480630 */

#if defined(P4_UNIT_00480800)
/* Source unit: src/Graphics/Model/mdlFile_00480800.c (1 function markers) */
#include "type.h"

extern u32 func_00480670(u32 param_1,u32 *param_2);
#pragma alias func_003bff30_typed func_003bff30
extern void func_003bff30_typed(u64 param_1,void *param_2,void *param_3);

// FUN_00480800
u16 func_00480800(u64 param_1,u32 param_2)
{
  struct {
    u32 input;
    u16 output;
  } stack;

  stack.input = param_2;
  stack.output = 0;
  func_003bff30_typed(param_1,(void *)&func_00480670,&stack);
  return stack.output;
}
#endif /* P4_UNIT_00480800 */

#if defined(P4_UNIT_004808B0)
/* Source unit: src/Graphics/Model/mdlFile_004808b0.c (1 function markers) */
#include "type.h"

// FUN_004808B0
void func_004808b0(int param_1)
{
  *(u16 *)(param_1 + 8) = *(u16 *)(param_1 + 8) - 1;
  if (*(u16 *)(param_1 + 8) == 0) {
    ((void (*)(...))(*(u32 *)0x008873ec))();
  }
  return;
}
#endif /* P4_UNIT_004808B0 */

#if defined(P4_UNIT_0047F2C0)
/* Source unit: src/Graphics/Model/mdlFile_0047f2c0.c (1 function markers) */
#include "type.h"

#pragma alias func_004578b0_ptr K_Clump_MatUsrDataGetInt
extern u32 K_Clump_MatUsrDataGetInt();
extern u32 func_004578b0_ptr(u32 param_1,u8 *param_2);
#pragma alias DAT_00713200_abs DAT_00713200
extern u8 DAT_00713200[];
extern u8 DAT_00713200_abs[];
extern u64 func_004586f0();

static inline u8 mdlFileToU8(f32 value)
{
  return (u8)value;
}

/* W409 measured: P3 donor carried NONMATCHING 204/224 nd74 -> MATCH 216/224 nd0 annotation; ported verbatim. */
// FUN_0047F2C0
void func_0047f2c0(f32 *param_1,u32 param_2)
{
  u32 uVar1;
  float fVar2;
  u8 rgba[4];
  u32 alpha;

  uVar1 = func_004578b0_ptr(param_2,DAT_00713200_abs);

  fVar2 = (1.0f - param_1[1]) * 255.0f;

  alpha = mdlFileToU8(fVar2);
  rgba[2] = (u8)uVar1;
  rgba[1] = (u8)((u32)uVar1 >> 8);
  rgba[0] = (u8)((u32)uVar1 >> 0x10);
  rgba[3] = (u8)alpha;

  func_004586f0(param_2,rgba);
  return;
}
#endif /* P4_UNIT_0047F2C0 */

#if defined(P4_UNIT_0047F3A0)
/* Source unit: src/Graphics/Model/mdlFile_0047f3a0.c (1 function markers) */
#include "type.h"

#pragma alias DAT_00922c30_abs DAT_00922c30
extern u32 DAT_00922c30;
extern u8 DAT_00922c30_abs[];

// FUN_0047F3A0
u32 * func_0047f3a0(float param_1,int *param_2)
{
  float *key;
  float fraction;
  float start;
  float output;
  float difference;
  int high;
  int low;
  int stride;
  u8 *data;
  int mid;
  u32 address;

  data = (u8 *)param_2[3];
  low = 0;
  high = *param_2 - 1;
  stride = param_2[2];
  do {
    mid = (low + high + 1) >> 1;
    if (param_1 < *(float *)(data + stride * mid)) {
      high = --mid;
    }
    else {
      low = mid;
    }
  } while (low < high);
  if ((u32)mid >= (u32)(*param_2 - 1)) {
    address = mid * 0x10;
    address += (u32)data;
    *(float *)(DAT_00922c30_abs + 4) = *(float *)(address + 4);
    *(float *)(DAT_00922c30_abs + 8) = *(float *)(address + 8);
    *(float *)(DAT_00922c30_abs + 12) = *(float *)(address + 0xc);
  }
  else {
    key = (float *)((u32)(mid * 0x10) + (u32)data);
    start = key[0];
    fraction = param_1 - start;
    fraction /= key[4] - start;
    output = key[1];
    difference = key[5] - output;
    *(float *)(DAT_00922c30_abs + 4) = fraction * difference + output;
    output = key[2];
    difference = key[6] - output;
    *(float *)(DAT_00922c30_abs + 8) = fraction * difference + output;
    output = key[3];
    difference = key[7] - output;
    *(float *)(DAT_00922c30_abs + 12) = fraction * difference + output;
  }
  *(float *)DAT_00922c30_abs = param_1;
  return (u32 *)DAT_00922c30_abs;
}
#endif /* P4_UNIT_0047F3A0 */

#if defined(P4_UNIT_0047FA60)
/* Source unit: src/Graphics/Model/mdlFile_0047fa60.c (1 function markers) */
#include "type.h"

typedef int (*code)(...);
#pragma alias DAT_008873ec_abs DAT_008873ec
extern code DAT_008873ec_abs[];
extern void func_004808b0(int param_1);

// FUN_0047FA60
void func_0047fa60(int param_1)
{
  int iVar2;
  int iVar1;
  u32 uVar4;
  u32 *puVar3;

  iVar2 = *(int *)param_1;
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x54);
    for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
      puVar3 = (u32 *)(iVar2 + uVar4 * 0x10);
      if (puVar3[3] != 0) {
        ((void (*)(...))DAT_008873ec_abs[0])(puVar3[3]);
        puVar3[3] = 0;
      }
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
    }
    func_004808b0(*(u32 *)(iVar2 + 0x50));
    ((void (*)(...))DAT_008873ec_abs[0])(iVar2);
    iVar2 = iVar1;
  }
  ((void (*)(...))DAT_008873ec_abs[0])(param_1);
  return;
}
#endif /* P4_UNIT_0047FA60 */

#if defined(P4_UNIT_00480430)
/* Source unit: src/Graphics/Model/mdlFile_00480430.c (1 function markers) */
#include "type.h"

extern s32 func_003bcfb0();
extern s32 func_003bd000();
extern s32 func_003bd040();
extern s32 func_003bd050();
extern s32 func_003bd060();
extern s32 func_003bd0b0();
extern s32 strcmp();
extern void func_00480910(int *param_1,u32 param_2);
extern u8 DAT_007641e0;

// FUN_00480430
u32 func_00480430(u32 param_1,u32 *param_2)
{
  s32 arrayCount;
  s32 dataCount;
  s32 arrayIndex;
  s32 dataIndex;
  void *userData;
  char *name;
  char *data;

  arrayCount = func_003bcfb0();
  arrayIndex = 0;
  while (arrayIndex < arrayCount) {
    userData = (void *)func_003bd000(param_1,arrayIndex);
    name = (char *)func_003bd040((u32)userData);
    if (strcmp(name,(char *)&DAT_007641e0) == 0) {
      dataCount = func_003bd060((u32)userData);
      dataIndex = 0;
      while (dataIndex < dataCount) {
        if (func_003bd050((u32)userData) == 3) {
          data = (char *)func_003bd0b0((u32)userData,dataIndex);
          if (strcmp((char *)param_2[1],data) == 0) {
            func_00480910((int *)*param_2,param_1);
            return 0;
          }
        }
        dataIndex++;
      }
    }
    arrayIndex++;
  }
  return param_1;
}
#endif /* P4_UNIT_00480430 */
