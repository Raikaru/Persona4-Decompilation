/* Consolidated Persona 4 source units. */
/* Original translation unit mdlMatAnim.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];
extern void func_004808b0(int param_1);

extern s32 func_003bcfb0();
extern s32 func_003bd000();
extern s32 func_003bd040();
extern s32 func_003bd050();
extern s32 func_003bd060();
extern s32 func_003bd0b0();
extern s32 strcmp();
extern void func_00480910(int *param_1,u32 param_2);
extern u8 DAT_007641e0;

extern u32 func_00480430(u32 param_1,u32 *param_2);

extern u64 func_003bff30();
extern u32 func_00480580(u32 param_1,u32 param_2);

extern u32 func_00480670(u32 param_1,u32 *param_2);
extern void func_003bff30_typed(u64 param_1,void *param_2,void *param_3);

#pragma alias DAT_008873ec_abs DAT_008873ec


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



// FUN_00480630
u64 func_00480630(u64 param_1,u64 param_2)
{
  func_003bff30(param_1,(void (*)())func_00480580,param_2);
  return param_1;
}

#pragma alias func_003bff30_typed func_003bff30


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
