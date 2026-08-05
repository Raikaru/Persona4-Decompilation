/* Consolidated Persona 4 source units. */
/* Original translation unit evtMessage.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void func_002777f0();
extern void func_0043f9c8();
/* Source unit: src/Event/mt_evtMessage_00290a50.c (donor FUN_0039f2a0) */

extern void func_0046d730(u8 *file, s32 line);
extern u8 D_0063C820[];
extern void func_00278e20(s32 arg0, s32 arg1);

extern void func_00276e70();
extern void func_00277250();
extern void func_00277ad0();
extern void func_002781e0();
extern void func_00276e70_typed(s32, u8);
extern void func_00277250_typed(s32);
extern void func_00277ad0_typed(s32, s32);
extern void func_002781e0_typed(s32, u32);
/* Source unit: src/Event/mt_evtMessage_00290e10.c (donor FUN_0039f710) */

extern u32 func_00278e90(int param_1);

// FUN_00290880
INCLUDE_ASM("asm/nonmatchings/evtMessage", func_00290880);
/* measured: retail booleanises the test (sltu $v1,$0,$v1) and branches on the result;
   mwcc b210 collapses it into a bare beqz. A named boolean local, a doubled != 0, and
   #pragma opt_rebuildconditionals off all give the identical nd 16 - the pragma governs
   the opposite direction (collapsing branches INTO booleans), so it has no effect here. */
// FUN_00290940
extern void func_00290b00_narg(void);
extern void func_00290a50_narg(void);

void func_00290940(int *param_1)
{
  int *piVar1;
  u8 bVar1;

  piVar1 = param_1;

  bVar1 = *piVar1 != 0;
  if (bVar1) {
    func_00290b00_narg();
    func_002777f0(piVar1[2]);
    *piVar1 = 0;
    func_0043f9c8(param_1, 0, 0x34);
  }
  return;
}
// FUN_002909B0
void func_002909b0(int *param_1, int a2, int a3, int a4, int a5)
{
  if ((u8)(*param_1 != 0)) {
    if (param_1[3] != 0) {
      func_00290a50_narg();
    }
    param_1[3] = 1;
    param_1[1] = a2;
    param_1[4] = a3;
    param_1[5] = a4;
    param_1[6] = a5;
    param_1[7] = -1;
  }
  return;
}




// FUN_00290A50
void func_00290a50(int *param_1)
{
  int iVar1;

  iVar1 = param_1[2];
  if ((u8)(*param_1 != 0)) {
    if (param_1[3] != 0) {
      func_00276e70(iVar1,0);
      func_00277250(iVar1);
      func_00277ad0(iVar1,0);
      func_002781e0(iVar1,0x800000);
      func_002781e0(iVar1,0x100000);
      func_00276e70(iVar1,1);
      param_1[3] = 0;
    }
  }
  return;
}



// FUN_00290B00
void func_00290b00(int *param_1)
{
  int iVar1;
  u8 bVar1;

  bVar1 = *param_1 != 0;
  if (bVar1 && (param_1[3] != 0)) {
    iVar1 = param_1[2];
    if (bVar1 && (param_1[3] != 0)) {
      func_00276e70_typed(iVar1,0);
      func_00277250_typed(iVar1);
      func_00277ad0_typed(iVar1,0);
      func_002781e0_typed(iVar1,0x800000);
      func_002781e0_typed(iVar1,0x100000);
      func_00276e70_typed(iVar1,1);
      param_1[3] = 0;
    }
  }
  return;
}

// FUN_00290BC0
void func_00290bc0(int *param_1)
{
  u32 bVar0;
  int iVar2;
  int lVar3;
  u32 uVar4;
  int iVar5;

  bVar0 = *param_1 != 0;
  if (bVar0) {
    iVar2 = param_1[2];
    switch (param_1[3]) {
    case 0:
      break;
    case 1:
      iVar5 = param_1[4];
      if (iVar5 >= 0) {
        func_00278610(param_1[2], param_1[1]);
        func_00278170(param_1[2], 0x200000);
        func_002778c0(param_1[2], param_1[4], 0);
        func_00277010(param_1[2], -1);
        param_1[3] = 2;
      } else {
        param_1[3] = 3;
      }
      break;
    case 2:
      lVar3 = func_00276e10(iVar2);
      if (lVar3 < 0) {
        param_1[3] = 3;
      }
      break;
    case 3:
      if (param_1[5] >= 0) {
        func_00277fd0(iVar2, 0);
        func_00277be0(iVar2, param_1[5]);
        param_1[3] = 4;
      } else {
        param_1[3] = 5;
      }
      break;
    case 4:
      lVar3 = func_00276fb0(iVar2);
      if (lVar3 < 0) {
        uVar4 = func_00278260(iVar2);
        iVar2 = param_1[6];
        if ((iVar2 >= 0) && (iVar2 < 10)) {
          func_0028d020(iVar2, uVar4);
        }
        param_1[7] = (int)uVar4;
        param_1[3] = 5;
      }
      break;
    case 5:
      if (bVar0 && (param_1[3] != 0)) {
        func_00276e70(iVar2, 0);
        func_00277250(iVar2);
        func_00277ad0(iVar2, 0);
        func_002781e0(iVar2, 0x800000);
        func_002781e0(iVar2, 0x100000);
        func_00276e70(iVar2, 1);
        param_1[3] = 0;
      }
      break;
    }
  }
  return;
}


/* Source unit: src/Event/mt_evtMessage_00290de0.c (donor FUN_0039f6e0) */


// FUN_00290DE0
u8 func_00290de0(int *param_1)
{
  if ((u8)(*param_1 != 0)) goto nonzero;
  return 1;

nonzero:
  return param_1[3] == 0;
}



// FUN_00290E10
u32 func_00290e10(int *param_1)
{
  if ((u8)(*param_1 != 0)) goto nonzero;
  return 0;

nonzero:
  return func_00278e90(param_1[2]);
}

// FUN_00290E50
void func_00290e50(u8 *arg0, s32 arg1)
{
    if (!(u8)(*(u32 *)arg0 != 0)) {
        func_0046d730(D_0063C820, 0x122);
    }
    func_00278e20(*(s32 *)(arg0 + 8), arg1);
}
