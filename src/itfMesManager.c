/* Source unit: src/itfMesManager_002770d0.c */
#include "type.h"

s32 func_0029d030(void);
s32 func_0029cc00(s32 index);
void func_00277f70(s32 mesHandleIdx, u32 param_2);
void func_00440b68();
extern char D_0063BE20[];
void func_002782c0(int param_1,int param_2,int param_3,u32 param_4);
u32 func_002786c0(int param_1,int param_2,int param_3);

extern void func_00278640(s32 arg0, s16 arg1, s32 arg2);

typedef struct {
    u8 *unk0;
    u8 pad[28];
} D_00881808_t;

extern D_00881808_t D_00881808[];

void func_002746c0(int param_1, u32 param_2);

void func_002727f0(int param_1);
extern u8 DAT_008817EC_abs[];
extern u8 DAT_008817E4_abs[];
void func_0027b310(u32 param_1);



// FUN_002770D0
u32 func_002770d0(void)
{
  int value;
  u32 other;

  value = func_0029d030();
  if (value < 0)
    return 1;

  other = func_0029cc00(0);
  func_00277f70(value, other);
  return 1;
}



// FUN_00277370
u32 func_00277370(void)
{
  int lVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;

  lVar1 = func_0029d030();
  if (lVar1 < 0) {
    return 1;
  }
  uVar2 = func_0029cc00(0);
  uVar3 = func_0029cc00(1);
  uVar4 = func_0029cc00(2);
  func_00440b68(D_0063BE20,uVar2,uVar3,uVar4);
  uVar2 = func_0029cc00(0);
  uVar3 = func_0029cc00(1);
  uVar4 = func_0029cc00(2);
  func_002782c0(lVar1,uVar2,uVar3,uVar4);
  return 1;
}



// FUN_00277450
u32 func_00277450(void)
{
  s32 lVar1;
  u32 uVar2;
  u32 uVar3;

  lVar1 = func_0029d030();
  if (lVar1 < 0) {
    return 1;
  }
  uVar2 = func_0029cc00(0);
  uVar3 = func_0029cc00(1);
  func_002786c0(lVar1,uVar2,uVar3);
  return 1;
}



// FUN_00278610
s32 func_00278610(s32 arg0, s16 arg1)
{
    func_00278640(arg0, arg1, 0);
    return 0;
}



// FUN_00278C60
void func_00278c60(int *param_1, int param_2, u8 *param_3, int param_4)
{
  u8 bVar1;
  u8 *pbVar3;
  int iVar4;
  int iVar5;
  int updateOffset;

  pbVar3 = param_3;
  goto check;
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    if ((bVar1 & 1) == 0) {
      updateOffset = (int)(u32)bVar1 >> 1;
      goto update;
    }
    if ((bVar1 & 2) == 0) {
      updateOffset = (bVar1 | ((int)*pbVar3 << 8)) >> 2;
      pbVar3 = pbVar3 + 1;
      goto update;
    }
    if ((bVar1 & 4) == 0) {
      updateOffset = ((bVar1 | ((int)*pbVar3 << 8)) | ((int)pbVar3[1] << 16)) >> 3;
      pbVar3 = pbVar3 + 2;
      goto update;
    }
    iVar5 = ((int)(u32)bVar1 >> 3) + 2;
    for (iVar4 = 0; iVar4 < iVar5; iVar4 = iVar4 + 1) {
      param_1 = param_1 + 1;
      *param_1 = *param_1 + param_2;
    }
    goto check;
update:
    param_1 = param_1 + updateOffset;
    *param_1 = *param_1 + param_2;
check:
    updateOffset = ((int)pbVar3 - (int)param_3 < param_4);
    if (updateOffset == 0) {
      return;
    }
  } while (1);
}



// FUN_00278DE0
int func_00278de0(int param_1,int param_2)
{
  s32 base;
  s32 index;

  base = *(volatile /* Removing this qualifier loses FUN_00278DE0 (MATCH nd0 -> MISMATCH nd9, size 24 -> 24) - measured W170. */ s32 *)(param_1 + 4);
  index = param_2 * 8;
  return index + base + 0x20;
}



// FUN_00278E00
int func_00278e00(int param_1)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x18) * 8;
  return iVar1 + param_1 + 0x20;
}



// FUN_00278FB0
s32 func_00278fb0(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x20);
}



// FUN_00278FD0
s32 func_00278fd0(s32 arg0)
{
    return *(s32 *)(D_00881808[arg0].unk0 + 0x14);
}



// FUN_00279740
u32 func_00279740(int param_1,int param_2)
{
  u32 uVar1;
  int count = *(short *)(param_1 + 0x18);

  if ((param_2 < 0) || (param_2 >= count)) {
    uVar1 = 0;
  }
  else {
    int address = param_2 * 4;
    address = address + param_1;
    uVar1 = *(u32 *)(address + 0x1c);
  }
  return uVar1;
}



// FUN_00279CE0
void func_00279ce0(int param_1)
{
  int iVar1;

  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {
    func_002746c0(iVar1,*(u32 *)(param_1 + iVar1 * 4));
  }

  return;
}



// FUN_00279FD0
int func_00279fd0(int param_1,u32 param_2)
{
  int iVar1;

  iVar1 = 0;
  for (; 0 < param_1;) {
    if ((param_2 & 1) == 0) {
      iVar1 = iVar1 + 1;
    }
    param_1 = param_1 + -1;
    param_2 = param_2 >> 1;
  }
  return iVar1;
}



// FUN_0027A370
/* Not `static`: the symbol must stay global so the linker can resolve the
 * retail asm blob's jal to this address (measured: mwldps2 reports Undefined
 * "func_0027a370" if local).
 * The K&R parameter list below is the donor's form and is load-bearing. */
int func_0027a370(param_1,param_2,param_3,param_4)
int param_1;
int param_2;
int param_3;
u8 param_4;
{
  int color;
  int diff;
  int cat;
  int candidate;

  diff = param_3 - param_2;
  param_2 = diff - 1;
  cat = *(int *)(param_1 + 8);
  goto count_check;

advance:
  param_1 = *(int *)(param_1 + 0x24);
  if (param_1 == 0) {
    goto done;
  }

load:
  candidate = *(int *)(param_1 + 8);
  if (cat == candidate) {
    goto advance;
  }
  param_2 = param_2 - 1;
  cat = candidate;

count_check:
  if (param_2 > 0) {
    goto load;
  }

set_start:
  color = (u8)param_4;
set_load:
  candidate = *(int *)(param_1 + 0x1c);
  goto set_check;

set_store:
  *(u8 *)(candidate + 0x14) = (u8)color;
  candidate = *(int *)(candidate + 0x28);

set_check:
  if (candidate != 0) {
    goto set_store;
  }
  param_1 = *(int *)(param_1 + 0x24);
  switch (param_1) {
  case 0:
    goto done;
  }
  candidate = *(int *)(param_1 + 8);
  if (cat == candidate) {
    goto set_load;
  }
  goto done;
done:
  return;
}


/* Removing this loses FUN_0027A4D0 (MATCH nd0 -> MISMATCH nd24) - measured W161. */
#pragma opt_loop_invariants on

// FUN_0027A4D0
void func_0027a4d0(int param_1,u32 param_2)
{
  int iVar1;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {
      *(u32 *)(iVar1 + 0x10) = *(u32 *)(iVar1 + 0x10) & 0xffffff00 | param_2;
    }
  }
  return;
}
#pragma opt_loop_invariants off



// FUN_0027A520
int func_0027a520(int param_1)
{
  int iVar3;
  int iVar1;
  int iVar2;

  iVar3 = 0;
  goto outer_test;
outer_body:
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0;
  do {
    iVar2 += *(int *)(param_1 + 0xc);
    param_1 = *(int *)(param_1 + 0x24);
    if (param_1 == 0) {
      break;
    }
  } while (iVar1 == *(int *)(param_1 + 8));
  if (iVar3 < iVar2) {
    iVar3 = iVar2;
  }
outer_test:
  if (param_1 != 0) {
    goto outer_body;
  }
  return iVar3 << 4;
}



// FUN_0027A580
void func_0027a580(int param_1)
{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {
    if (*(u8 *)(*(int *)(param_1 + 0x1c) + 0x16) == '\0') {
      func_002727f0(param_1);
    }
  }

  return;
}



// FUN_0027A6C0
void func_0027a6c0(int param_1)
{
  int iVar1;

  for (iVar1 = 0; iVar1 < 0x20; iVar1 = iVar1 + 1) {
    *(u32 *)(param_1 + iVar1 * 4) = 0;
  }

  return;
}


#pragma alias DAT_008817EC_abs DAT_008817EC
#pragma alias DAT_008817E4_abs DAT_008817E4


// FUN_0027B620
u64 func_0027b620(void)
{
    int current;
    u32 count;

    current = *(int*)DAT_008817EC_abs;
    while (current != 0) {
        func_0027b310(*(u32*)(current + 0xc));
        current = *(int*)(current + 4);
    }
    count = *(u32*)DAT_008817E4_abs;
    *(u32*)DAT_008817E4_abs = count + 1;
    return 0;
}
