/* Source unit: src/nmCmdList_002baa90.c */
#include "type.h"

extern u8 DAT_00882F60_abs[];
extern u8 DAT_00882F64_abs[];
extern u8 DAT_00882F65_abs[];
extern u32 DAT_00882F68_abs[];
extern u8 DAT_00882F6C_abs[];
extern u8 DAT_00882F6D_abs[];
extern u8 *func_002bbf70(void);
extern u64 func_002bbf80(s32* param_1, int param_2);
extern u32 func_00277070(int param_1);
extern void func_002bbdd0(int param_1);
extern int func_00276fb0(int param_1);

extern u32 DAT_0063F2B0_abs[];
extern void func_002777f0(s32 param_1);


#pragma push


// FUN_002BAA90
void func_002baa90(int param_1)

{

  u32 *puVar1;

  

  puVar1 = (u32 *)param_1;

  if (param_1 != 0) {

    *puVar1 = 0xffffffff;

    *(u8 *)(puVar1 + 1) = 0;

    *(u8 *)((int)puVar1 + 5) = 0;

    puVar1[2] = 0xffffffff;

    *(u8 *)(puVar1 + 3) = 1;

    *(u8 *)((int)puVar1 + 0xd) = 1;

  }

  return;

}

#pragma pop


#pragma push


// FUN_002BAAC0
u8 func_002baac0(u64 param_1)
{
    s32* command;

    if (DAT_00882F60_abs != NULL)
    {
        *(u32*)DAT_00882F60_abs = 0xffffffff;
        DAT_00882F64_abs[0] = 0;
        DAT_00882F65_abs[0] = 0;
        DAT_00882F68_abs[0] = 0xffffffff;
        DAT_00882F6C_abs[0] = 1;
        DAT_00882F6D_abs[0] = 1;
    }

    command = (s32*)func_002bbf70();
    if (*command < 0)
    {
        *command = func_002774d0(param_1);
        func_002bbf80(command, 0);
        return 1;
    }

    return 0;
}

#pragma pop


#pragma push


// FUN_002BB050
void func_002bb050(u8 param_1)

{

  u8 *lVar1;

  

  lVar1 = func_002bbf70();

  if (lVar1 == 0)
    return;

  if (*(int *)lVar1 < 0)
    return;

  *(u8 *)(lVar1 + 0xc) = param_1;

  return;

}

#pragma pop


#pragma push


// FUN_002BB0E0
u32 func_002bb0e0(void)

{
  int *piVar1;
  u32 uVar2;
  piVar1 = (int *)func_002bbf70();

  if (piVar1 == 0) {
    uVar2 = 0xffffffffffffffff;
  } else if (0 > *piVar1) {
    uVar2 = 0xffffffffffffffff;
  } else {
    uVar2 = func_00277070(*piVar1);
  }

  return uVar2;
}

#pragma pop


#pragma push


// FUN_002BB140
s8 func_002bb140(void)
{
  s8 uVar1;

  u8 *lVar2;

  

  lVar2 = func_002bbf70();

  if (lVar2 == 0) {

    uVar1 = 1;

  }

  else {

    uVar1 = *(s8 *)(lVar2 + 0xd);

  }

  return uVar1;

}

#pragma pop


#pragma push


// FUN_002BB1E0
u32 func_002bb1e0(int param_1)

{

  u32 uVar1;

  u8 *lVar2;

  int *piVar3;

  

  lVar2 = func_002bbf70();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      func_00276e70(*piVar3,0);

      if (param_1 != 0) {

        func_00277250(*piVar3);

      }

      func_00277ad0(*piVar3,0);

      func_002bbdd0(1);

      *(u8 *)(piVar3 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}

#pragma pop


#pragma push


// FUN_002BB380
u32 func_002bb380(void)

{

  u32 uVar1;

  u8 *lVar2;

  int *piVar3;

  

  lVar2 = func_002bbf70();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      func_00276e70(*piVar3,0);

      func_00277250(*piVar3);

      func_00277ad0(*piVar3,0);

      func_002bbdd0(1);

      *(u8 *)(piVar3 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}

#pragma pop


#pragma push


// FUN_002BB600
s8 func_002bb600(void)
{
  s8 uVar1;
  int *piVar2;
  u8 *lVar3;

  lVar3 = func_002bbf70();
  if (lVar3 == 0) {
    uVar1 = 0;
  }
  else {
    piVar2 = (int *)lVar3;
    if (*piVar2 < 0) {
      uVar1 = 0;
    }
    else {
      if (*(char *)((int)piVar2 + 5) == '\0') {
        goto value;
      }
      if ((char)piVar2[1] != '\x02') {
        goto value;
      }
      uVar1 = 0;
      goto done;
value:
      uVar1 = *(s8 *)((int)piVar2 + 4);
done:
      ;
    }
  }
  return uVar1;
}

#pragma pop


#pragma push


// FUN_002BB700
u32 func_002bb700(void)

{

  u32 uVar1;

  u32 uVar2;

  u8 *lVar3;
  int lVar4;
  u8 *p;

  

  lVar3 = func_002bbf70();

  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else if (*(int *)lVar3 < 0) {

    uVar2 = 0;

  }

  else {

    lVar4 = func_00276fb0(*(int *)lVar3);

    if (lVar4 < 0) {

      uVar2 = 0;

    }

    else {

      p = func_002bbf70();

      if (p == 0) {

        uVar1 = -1;

      }

      else if (*(int *)p < 0) {

        uVar1 = -1;

      }

      else {

        uVar1 = func_00277070(*(int *)p);

      }

      *(u8 *)((int)(int *)lVar3 + 0xd) = uVar1;

      uVar2 = 1;

    }

  }

  return uVar2;

}

#pragma pop


#pragma push


// FUN_002BBD20
void func_002bbd20(u64 param_1,u64 param_2)

{

  u8 *lVar1;

  

  lVar1 = func_002bbf70();

  if (lVar1 != 0) {

    func_00278450(*(u32 *)lVar1,param_1,param_2);

  }

  return;

}

#pragma pop


#pragma push


// FUN_002BBDD0
void func_002bbdd0(int param_1)

{

  extern u8 *func_002bbf70(void);
  u32 lVar1;

  u32 *puVar2;

  

  lVar1 = (u32)func_002bbf70();

  if (lVar1 != 0) {

    puVar2 = (u32 *)lVar1;

    if (param_1 != 0) {

      func_002781e0(*puVar2,0x800000);

      func_002781e0(*puVar2,0x100000);

      *(u8 *)((int)puVar2 + 5) = 0;

      func_00276e70(*puVar2,1);

      *(u8 *)(puVar2 + 1) = 1;

    }

    else {

      func_00278170(*puVar2,0x800000);

      func_00278170(*puVar2,0x100000);

      *(u8 *)((int)puVar2 + 5) = 1;

    }

  }

  return;

}

#pragma pop


#pragma push


// FUN_002BC010
void func_002bc010(int param_1,u64 param_2)

{

  u32 uVar1;

  

  uVar1 = func_002774d0(param_2);

  DAT_0063F2B0_abs[param_1] = uVar1;

  return;

}

#pragma pop


#pragma push


// FUN_002BC060
void func_002bc060(int param_1)
{
  s32 value;

  value = DAT_0063F2B0_abs[param_1];
  if (value >= 0) {
    func_002777f0(value);
    DAT_0063F2B0_abs[param_1] = -1;
  }
}

#pragma pop
