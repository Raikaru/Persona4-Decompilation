/* Source unit: src/nmCmdList_002baa90.c */
#include "include_asm.h"
#include "type.h"
#include "message_handle.h"

extern u8 DAT_00882F60_abs[];
extern u8 DAT_00882F64_abs[];
extern u8 DAT_00882F65_abs[];
extern u32 DAT_00882F68_abs[];
extern u8 DAT_00882F6C_abs[];
extern u8 DAT_00882F6D_abs[];
extern u8 *D_00882F40[];
extern u8 *nmMesWindowCurrent(void);
extern s32 nmMesWindowApplyStyle(s32* param_1, s32 param_2);
extern void nmMesWindowSetCurrentRunning(int param_1);
extern s32 itfMesWindowSetStyle(s32 arg0, s16 arg1);
extern int itfMesWindowGetAnim(int param_1);

extern u32 DAT_0063F2B0_abs[];
extern void itfMesWindowReleaseIfActive(s32 param_1);
extern s8 iGpffffb578;


#pragma push


// FUN_002BAA90
void nmMesWindowInitRecord(int param_1)

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
u8 nmMesWindowOpenCurrent(u8* message)
{
    extern s32 itfMesWindowInstall(u8* message);
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

    command = (s32*)nmMesWindowCurrent();
    if (*command < 0)
    {
        *command = itfMesWindowInstall(message);
        nmMesWindowApplyStyle(command, 0);
        return 1;
    }

    return 0;
}

#pragma pop


#pragma push


// FUN_002BB050
void nmMesWindowSetCurrentFlag(u8 param_1)

{

  u8 *lVar1;

  

  lVar1 = nmMesWindowCurrent();

  if (lVar1 == 0)
    return;

  if (*(int *)lVar1 < 0)
    return;

  *(u8 *)(lVar1 + 0xc) = param_1;

  return;

}

#pragma pop


#pragma push


// FUN_002BB0A0
void nmMesWindowSetSlotFlag(s64 arg0, s8 arg1)
{
    u8 *temp_4;

    temp_4 = D_00882F40[(s8)arg0];
    if ((temp_4 != NULL) && (*(s32 *)temp_4 >= 0)) {
        *(s8 *)(temp_4 + 0xC) = arg1;
    }
}
// FUN_002BB0E0
u32 nmMesWindowCurrentAnim(void)

{
  int *piVar1;
  u32 uVar2;
  piVar1 = (int *)nmMesWindowCurrent();

  if (piVar1 == 0) {
    uVar2 = 0xffffffffffffffff;
  } else if (0 > *piVar1) {
    uVar2 = 0xffffffffffffffff;
  } else {
    uVar2 = itfMesWindowGetAnimAux(*piVar1);
  }

  return uVar2;
}

#pragma pop


#pragma push


// FUN_002BB140
s32 nmMesWindowCurrentAnimFlag(void)
{
  s32 uVar1;

  u8 *lVar2;

  

  lVar2 = nmMesWindowCurrent();

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
u32 nmMesWindowCloseCurrent(int param_1)

{

  u32 uVar1;

  u8 *lVar2;

  int *piVar3;

  

  lVar2 = nmMesWindowCurrent();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      itfMesWindowSetState(*piVar3,0);

      if (param_1 != 0) {

        itfMesWindowRelease(*piVar3);

      }

      itfMesWindowClear(*piVar3,0);

      nmMesWindowSetCurrentRunning(1);

      *(u8 *)(piVar3 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}

#pragma pop


#pragma push


// measured target CSE probe
#pragma optimization_level 1
// FUN_002BB290
s32 nmMesWindowCloseSlot(s64 arg0, s32 arg1)
{
    extern void itfMesWindowSetState(s32 arg0, s8 arg1);
    extern void itfMesWindowRelease(s32 arg0);
    extern void itfMesWindowClear(s32 arg0, s32 arg1);
    extern void nmMesWindowSetSlotRunning(s64 arg0, s32 arg1);
    u8 **temp_18;
    u8 *temp_2;
    s32 temp_4;
    s32 **temp_16;

    temp_18 = &D_00882F40[(s8)arg0];
    temp_2 = *temp_18;
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)temp_2;
    if (temp_4 < 0) {
        return 0;
    }
    itfMesWindowSetState(temp_4, 0);
    if (arg1 != 0) {
        itfMesWindowRelease(*(s32 *)*temp_18);
    }
    temp_16 = (s32 **)&D_00882F40[(s8)arg0];
    itfMesWindowClear(**temp_16, 0);
    nmMesWindowSetSlotRunning(arg0, 1);
    *(s8 *)((u8 *)*temp_16 + 4) = 0;
    return 1;
}
// measured target CSE probe
#pragma optimization_level 2
// FUN_002BB380
u32 nmMesWindowReleaseCurrent(void)

{

  u32 uVar1;

  u8 *lVar2;

  int *piVar3;

  

  lVar2 = nmMesWindowCurrent();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      itfMesWindowSetState(*piVar3,0);

      itfMesWindowRelease(*piVar3);

      itfMesWindowClear(*piVar3,0);

      nmMesWindowSetCurrentRunning(1);

      *(u8 *)(piVar3 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}

#pragma pop


#pragma push


// FUN_002BB600
s32 nmMesWindowCurrentOpenState(void)
{
  s32 uVar1;
  int *piVar2;
  u8 *lVar3;

  lVar3 = nmMesWindowCurrent();
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
u32 nmMesWindowLatchAnimAux(void)

{

  u32 uVar1;

  u32 uVar2;

  u8 *lVar3;
  int lVar4;
  u8 *p;

  

  lVar3 = nmMesWindowCurrent();

  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else if (*(int *)lVar3 < 0) {

    uVar2 = 0;

  }

  else {

    lVar4 = itfMesWindowGetAnim(*(int *)lVar3);

    if (lVar4 < 0) {

      uVar2 = 0;

    }

    else {

      p = nmMesWindowCurrent();

      if (p == 0) {

        uVar1 = -1;

      }

      else if (*(int *)p < 0) {

        uVar1 = -1;

      }

      else {

        uVar1 = itfMesWindowGetAnimAux(*(int *)p);

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
void nmMesWindowSetCurrentString(s32 param_1,void *param_2)

{

  u8 *lVar1;

  

  lVar1 = nmMesWindowCurrent();

  if (lVar1 != 0) {

    itfMesWindowSetString(*(u32 *)lVar1,param_1,param_2);

  }

  return;

}

#pragma pop


#pragma push


// FUN_002BBDD0
void nmMesWindowSetCurrentRunning(int param_1)

{

  extern u8 *nmMesWindowCurrent(void);
  u32 lVar1;

  u32 *puVar2;

  

  lVar1 = (u32)nmMesWindowCurrent();

  if (lVar1 != 0) {

    puVar2 = (u32 *)lVar1;

    if (param_1 != 0) {

      itfMesWindowClearFlagBits(*puVar2,0x800000);

      itfMesWindowClearFlagBits(*puVar2,0x100000);

      *(u8 *)((int)puVar2 + 5) = 0;

      itfMesWindowSetState(*puVar2,1);

      *(u8 *)(puVar2 + 1) = 1;

    }

    else {

      itfMesWindowSetFlagBits(*puVar2,0x800000);

      itfMesWindowSetFlagBits(*puVar2,0x100000);

      *(u8 *)((int)puVar2 + 5) = 1;

    }

  }

  return;

}

#pragma pop


#pragma push


// FUN_002BBE90
void nmMesWindowSetSlotRunning(s64 arg0, s32 arg1)
{
    u8 **temp_16;
    u8 *temp_3;
    s32 index;

    index = (s8)arg0;
    temp_16 = D_00882F40 + index;
    temp_3 = *temp_16;
    if (temp_3 != NULL) {
        if (arg1 != 0) {
            itfMesWindowClearFlagBits(*(s32 *)(temp_3 + 0), 0x800000);
            itfMesWindowClearFlagBits(*(s32 *)(*temp_16 + 0), 0x100000);
            *(s8 *)(*temp_16 + 5) = 0;
            itfMesWindowSetState(*(s32 *)(*temp_16 + 0), 1);
            *(s8 *)(*temp_16 + 4) = 1;
            return;
        }
        itfMesWindowSetFlagBits(*(s32 *)(temp_3 + 0), 0x800000);
        itfMesWindowSetFlagBits(*(s32 *)(*temp_16 + 0), 0x100000);
        *(s8 *)(*temp_16 + 5) = 1;
    }
}
// FUN_002BBF60
void nmMesWindowRequestRefresh(void)
{
    iGpffffb578 = 1;
}
// FUN_002BBF70
u8 *nmMesWindowCurrent(void)
{
    return (u8 *)DAT_00882F60_abs;
}
// FUN_002BBF80
s32 nmMesWindowApplyStyle(s32 *arg0, s32 arg1)
{
    switch (arg1) {
    case 0:
        itfMesWindowSetStyle(*arg0, 0);
        break;
    case 1:
        itfMesWindowSetStyle(*arg0, 2);
        break;
    case 2:
        itfMesWindowSetStyle(*arg0, 1);
        break;
    }
    return 0;
}
// FUN_002BC010
void nmMesWindowInstallHandle(int param_1,u8 *param_2)

{

  u32 uVar1;

  

  uVar1 = itfMesWindowInstall(param_2);

  DAT_0063F2B0_abs[param_1] = uVar1;

  return;

}

#pragma pop


#pragma push


// FUN_002BC060
void nmMesWindowReleaseHandle(int param_1)
{
  s32 value;

  value = DAT_0063F2B0_abs[param_1];
  if (value >= 0) {
    itfMesWindowReleaseIfActive(value);
    DAT_0063F2B0_abs[param_1] = -1;
  }
}

#pragma pop
