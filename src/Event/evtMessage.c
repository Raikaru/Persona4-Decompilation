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
INCLUDE_ASM("asm/nonmatchings/evtMessage", func_00290940);
// FUN_002909B0
INCLUDE_ASM("asm/nonmatchings/evtMessage", func_002909b0);




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

#pragma alias func_00276e70_typed func_00276e70
#pragma alias func_00277250_typed func_00277250
#pragma alias func_00277ad0_typed func_00277ad0
#pragma alias func_002781e0_typed func_002781e0


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
INCLUDE_ASM("asm/nonmatchings/evtMessage", func_00290bc0);


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
