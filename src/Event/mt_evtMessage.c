/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#include "type.h"

/* Ported from Persona 3 FES src/Event/mt_evtMessage.c. Callee addresses
   translated via tools/map_shared_p3.py (report in C:/tmp/wave2/). */

#if defined(P4_UNIT_00290DE0)
/* Source unit: src/Event/mt_evtMessage_00290de0.c (donor FUN_0039f6e0) */

// FUN_00290DE0
u8 func_00290de0(int *param_1)
{
  if ((u8)(*param_1 != 0)) goto nonzero;
  return 1;

nonzero:
  return param_1[3] == 0;
}
#endif /* P4_UNIT_00290DE0 */

#if defined(P4_UNIT_00290E10)
/* Source unit: src/Event/mt_evtMessage_00290e10.c (donor FUN_0039f710) */

extern u32 func_00278e90(int param_1);

// FUN_00290E10
u32 func_00290e10(int *param_1)
{
  if ((u8)(*param_1 != 0)) goto nonzero;
  return 0;

nonzero:
  return func_00278e90(param_1[2]);
}
#endif /* P4_UNIT_00290E10 */

#if defined(P4_UNIT_00290A50)
/* Source unit: src/Event/mt_evtMessage_00290a50.c (donor FUN_0039f2a0) */

extern void func_00276e70();
extern void func_00277250();
extern void func_00277ad0();
extern void func_002781e0();

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
#endif /* P4_UNIT_00290A50 */

#if defined(P4_UNIT_00290B00)
/* Source unit: src/Event/mt_evtMessage_00290b00.c (donor FUN_0039f350) */

extern void func_00276e70();
extern void func_00277250();
extern void func_00277ad0();
extern void func_002781e0();
#pragma alias func_00276e70_typed func_00276e70
extern void func_00276e70_typed(s32, u8);
#pragma alias func_00277250_typed func_00277250
extern void func_00277250_typed(s32);
#pragma alias func_00277ad0_typed func_00277ad0
extern void func_00277ad0_typed(s32, s32);
#pragma alias func_002781e0_typed func_002781e0
extern void func_002781e0_typed(s32, u32);

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
#endif /* P4_UNIT_00290B00 */
