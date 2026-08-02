/* Source unit: src/Battle/btlEffect_001db100.c */
#include "type.h"
#include "include_asm.h"

typedef u8 bool;
typedef int (*code)(...);

extern u32 func_001d94d0(int param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, code *param_6);
extern bool btlCond_MYWEAK(int param_1, short param_2);

s32 func_001db360(u64 formation, u16 index, s32 enabled);
/* definition (FUN_001DB580) is byte-verified; the extern's `int` first
   parameter was a guessed prototype and clashed with the merged definition */
extern void btlCond_MYNOMAL(u64 formation, u16 index);

extern u64 func_0010f460();

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

typedef void (*FormationCallback)(void);

void func_001dbba0(u64 formation, u32 flags, s32 arg2, s32 arg3, s32 variant, FormationCallback callback);
void btlCond_MYBAD(void);

extern u64 func_00452490();

extern u8 *func_001b0cc0();
extern s32 func_001de000();
extern s64 func_0029cc00();
extern void func_0029cf50();
extern u8 *func_0029d050();


// FUN_001DAF40
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001daf40);

// FUN_001DB040
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db040);

// FUN_001DB0A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db0a0);

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB100 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB100
void btlCond_ENWEAK_DW_PAI(int param_1, u32 param_2)
{
  u32 shift;

  {
      if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  func_001d94d0(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 7,
                 (code *)&btlCond_MYWEAK);
  return;
}
#pragma opt_rebuildconditionals on



// FUN_001DB160
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db160);

// FUN_001DB360
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db360);

// FUN_001DB580
void btlCond_MYNOMAL(u64 formation, u16 index)
{
    func_001db360(formation, index, 1);
}



// FUN_001DB5B0
void func_001db5b0(u64 formation, u16 index)
{
    func_001db360(formation, index, 0);
}


// FUN_001DB5E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db5e0);

// FUN_001DB620
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db620);

// FUN_001DB680
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db680);

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB6E0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB6E0
void btlCond_ENNOMAL_DW(int param_1, u32 param_2)
{
  u32 shift;

  {
      if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  func_001d94d0(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0xb,
                 (code *)&btlCond_MYNOMAL);
  return;
}
#pragma opt_rebuildconditionals on



// FUN_001DB740
bool btlCond_ANALYZE(int param_1)
{
  long lVar2 = 0;
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 1) {
    return 0;
  }
  lVar2 = func_0010f460(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4));
  return lVar2 != 0;
}



// FUN_001DB790
s32 btlCond_DOWN(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 8) ? 0 : 1;
}



// FUN_001DB7B0
s32 btlCond_SLIP(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 0x10) ? 0 : 1;
}



// FUN_001DB7D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db7d0);

// FUN_001DB8D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db8d0);

// FUN_001DB900
s32 btlCond_MYTAISEI(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x10000000) != 0);
}



// FUN_001DB940
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db940);

// FUN_001DB990
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db990);

// FUN_001DB9F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001db9f0);

// FUN_001DBA90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dba90);

// FUN_001DBAF0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dbaf0);

// FUN_001DBB90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dbb90);

// FUN_001DBBA0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dbba0);

// FUN_001DBF20
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dbf20);

// FUN_001DC380
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc380);

// FUN_001DC480
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc480);

// FUN_001DC5B0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc5b0);

// FUN_001DC5C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc5c0);

// FUN_001DC600
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc600);

// FUN_001DC640
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc640);

// FUN_001DC6A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc6a0);

// FUN_001DC7A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc7a0);

// FUN_001DC7E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc7e0);

// FUN_001DC820
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc820);

// FUN_001DC860
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc860);

// FUN_001DC8A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc8a0);

// FUN_001DC8E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc8e0);

// FUN_001DC920
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc920);

// FUN_001DC960
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc960);

// FUN_001DC9A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dc9a0);

// FUN_001DCA60
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dca60);

// FUN_001DCB50
void func_001dcb50(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 0, btlCond_MYBAD);
}



// FUN_001DCB90
void func_001dcb90(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 1, btlCond_MYBAD);
}



// FUN_001DCBD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcbd0);

// FUN_001DCC10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcc10);

// FUN_001DCC50
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcc50);

// FUN_001DCC90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcc90);

// FUN_001DCCD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dccd0);

// FUN_001DCD10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcd10);

// FUN_001DCD50
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcd50);

// FUN_001DCD90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcd90);

// FUN_001DCDD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcdd0);

// FUN_001DCE10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dce10);

// FUN_001DCE50
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dce50);

// FUN_001DCE90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dce90);

// FUN_001DCED0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dced0);

// FUN_001DCF10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcf10);

// FUN_001DCFD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dcfd0);

// FUN_001DD010
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd010);

// FUN_001DD050
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd050);

// FUN_001DD090
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd090);

// FUN_001DD0D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd0d0);

// FUN_001DD1C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd1c0);

// FUN_001DD3A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd3a0);

// FUN_001DD570
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd570);

// FUN_001DD920
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dd920);

// FUN_001DE000
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001de000);

// FUN_001DE370
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001de370);

// FUN_001DE640
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001de640);

// FUN_001DE800
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001de800);

// FUN_001DEA90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dea90);

// FUN_001DEBB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001debb0);

// FUN_001DED30
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001ded30);

// FUN_001DEEE0
u32 func_001deee0(int param_1)
{
  u32 uVar1 = 0;
  long lVar2 = 0;

  if (*(u8 *)(param_1 + 0x30) == 0) {
    uVar1 = 1;
  }
  else if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 1;
  }
  else {
    lVar2 = func_00452490(*(int *)(param_1 + 0x4c));
    if (lVar2 == 0) {
      *(u8 *)(param_1 + 0x30) = 0;
      *(u32 *)(param_1 + 0x4c) = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// FUN_001DEF60
u32 func_001def60(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = (char *)func_0029d050();

  func_001de640(pVar1, pVar1 + 0x38, 0x8000);
  return 1;
}



// FUN_001DEFA0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001defa0);

// FUN_001DF040
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df040);

// FUN_001DF0C0
u32 func_001df0c0(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8001);
  return 1;
}



// FUN_001DF100
u32 func_001df100(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8002);
  return 1;
}



// FUN_001DF140
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df140);

// FUN_001DF1A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df1a0);

// FUN_001DF230
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df230);

// FUN_001DF2D0
u32 func_001df2d0(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8007);
  return 1;
}



// FUN_001DF310
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df310);

// FUN_001DF3C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df3c0);

// FUN_001DF470
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df470);

// FUN_001DF520
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df520);

// FUN_001DF5D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df5d0);

// FUN_001DF680
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df680);

// FUN_001DF730
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df730);

// FUN_001DF7E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df7e0);

// FUN_001DF890
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df890);

// FUN_001DF940
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df940);

// FUN_001DF9F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001df9f0);

// FUN_001DFAA0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dfaa0);

// FUN_001DFB50
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dfb50);

// FUN_001DFC00
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dfc00);

// FUN_001DFCB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dfcb0);

// FUN_001DFD60
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dfd60);

// FUN_001DFE10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dfe10);

// FUN_001DFEC0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dfec0);

// FUN_001DFF70
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dff70);

// FUN_001DFFC0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001dffc0);

// FUN_001E0010
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0010);

// FUN_001E0060
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0060);

// FUN_001E0110
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0110);

// FUN_001E01C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e01c0);

// FUN_001E0270
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0270);

// FUN_001E0320
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0320);

// FUN_001E03D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e03d0);

// FUN_001E0480
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0480);

// FUN_001E0530
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0530);

// FUN_001E05E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e05e0);

// FUN_001E0690
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0690);

// FUN_001E0740
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0740);

// FUN_001E07F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e07f0);

// FUN_001E08A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e08a0);

// FUN_001E0950
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0950);

// FUN_001E0A00
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0a00);

// FUN_001E0AB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0ab0);

// FUN_001E0B60
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0b60);

// FUN_001E0C10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0c10);

// FUN_001E0CC0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0cc0);

// FUN_001E0D10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0d10);

// FUN_001E0D60
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0d60);

// FUN_001E0DB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0db0);

// FUN_001E0E60
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0e60);

// FUN_001E0F10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0f10);

// FUN_001E0F60
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0f60);

// FUN_001E0FB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e0fb0);

// FUN_001E1060
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1060);

// FUN_001E1110
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1110);

// FUN_001E11C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e11c0);

// FUN_001E1270
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1270);

// FUN_001E1320
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1320);

// FUN_001E13D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e13d0);

// FUN_001E1480
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1480);

// FUN_001E1530
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1530);

// FUN_001E1620
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1620);

// FUN_001E1710
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1710);

// FUN_001E1800
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1800);

// FUN_001E1940
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1940);

// FUN_001E19F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e19f0);

// FUN_001E1AE0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1ae0);

// FUN_001E1BD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1bd0);

// FUN_001E1CC0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1cc0);

// FUN_001E1DB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1db0);

// FUN_001E1EA0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1ea0);

// FUN_001E1F90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e1f90);

// FUN_001E2030
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2030);

// FUN_001E20D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e20d0);

// FUN_001E21E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e21e0);

// FUN_001E22F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e22f0);

// FUN_001E2400
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2400);

// FUN_001E2550
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2550);

// FUN_001E26C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e26c0);

// FUN_001E2850
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2850);

// FUN_001E2910
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2910);

// FUN_001E2A80
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2a80);

// FUN_001E2C10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2c10);

// FUN_001E2D20
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2d20);

// FUN_001E2E30
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2e30);

// FUN_001E2F40
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e2f40);

// FUN_001E3050
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3050);

// FUN_001E3160
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3160);

// FUN_001E3270
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3270);

// FUN_001E3320
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3320);

// FUN_001E33D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e33d0);

// FUN_001E34B0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e34b0);

// FUN_001E3560
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3560);

// FUN_001E3610
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3610);

// FUN_001E36C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e36c0);

// FUN_001E3770
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3770);

// FUN_001E3820
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3820);

// FUN_001E38D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e38d0);

// FUN_001E3980
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3980);

// FUN_001E3A30
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3a30);

// FUN_001E3AE0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3ae0);

// FUN_001E3B90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3b90);

// FUN_001E3C40
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3c40);

// FUN_001E3C90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3c90);

// FUN_001E3CE0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3ce0);

// FUN_001E3D30
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3d30);

// FUN_001E3DE0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3de0);

// FUN_001E3F10
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3f10);

// FUN_001E3FD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e3fd0);

// FUN_001E4090
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4090);

// FUN_001E4150
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4150);

// FUN_001E4210
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4210);

// FUN_001E42E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e42e0);

// FUN_001E43D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e43d0);

// FUN_001E4430
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4430);

// FUN_001E4520
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4520);

// FUN_001E45D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e45d0);

// FUN_001E4600
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4600);

// FUN_001E46B0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e46b0);

// FUN_001E4760
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4760);

// FUN_001E4810
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4810);

// FUN_001E4880
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4880);

// FUN_001E48F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e48f0);

// FUN_001E4960
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4960);

// FUN_001E49D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e49d0);

// FUN_001E4A80
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4a80);

// FUN_001E4B30
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4b30);

// FUN_001E4BB0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4bb0);

// FUN_001E4C60
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4c60);

// FUN_001E4CD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4cd0);

// FUN_001E4D40
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4d40);

// FUN_001E4DF0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4df0);

// FUN_001E4EA0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4ea0);

// FUN_001E4F50
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e4f50);

// FUN_001E5000
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5000);

// FUN_001E50B0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e50b0);

// FUN_001E5160
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5160);

// FUN_001E5210
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5210);

// FUN_001E52C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e52c0);

// FUN_001E5330
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5330);

// FUN_001E53A0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e53a0);

// FUN_001E5410
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5410);

// FUN_001E54C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e54c0);

// FUN_001E5570
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5570);

// FUN_001E5620
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5620);

// FUN_001E56D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e56d0);

// FUN_001E5780
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5780);

// FUN_001E5830
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5830);

// FUN_001E58E0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e58e0);

// FUN_001E5990
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5990);

// FUN_001E5A20
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5a20);

// FUN_001E5AD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5ad0);

// FUN_001E5B40
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5b40);

// FUN_001E5BF0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5bf0);

// FUN_001E5CA0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5ca0);

// FUN_001E5D20
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5d20);

// FUN_001E5D90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5d90);

// FUN_001E5E40
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5e40);

// FUN_001E5EC0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5ec0);

// FUN_001E5F40
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5f40);

// FUN_001E5F90
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5f90);

// FUN_001E5FD0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e5fd0);

// FUN_001E6050
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6050);

// FUN_001E60F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e60f0);

// FUN_001E6160
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6160);

// FUN_001E61D0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e61d0);

// FUN_001E6240
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6240);

// FUN_001E62B0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e62b0);

// FUN_001E6320
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6320);

// FUN_001E6390
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6390);

// FUN_001E6400
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6400);

// FUN_001E6450
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6450);

// FUN_001E64C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e64c0);

// FUN_001E6530
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6530);

// FUN_001E6570
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6570);

// FUN_001E65B0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e65b0);

// FUN_001E65F0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e65f0);

// FUN_001E66C0
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e66c0);

// FUN_001E6740
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6740);

// FUN_001E6820
s32 func_001e6820(void) {
    s64 temp_16;
    s64 temp_17;
    u8 *temp_18;

    temp_18 = (u8 *)(func_0029d050());
    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_0029cf50(~func_001de000(temp_18, func_001b0cc0((u64) temp_17 & 0xFFFFFFF), (s16) temp_16, 0) != 0);
    return 1;
}



// FUN_001E68C0
s32 func_001e68c0(void) {
    s64 temp_16;

    func_0029d050();
    temp_16 = func_0029cc00(0);
    func_0029cc00(1);
    func_001b0cc0((u64) temp_16 & 0xFFFFFFF);
    func_0029cf50(0U);
    return 1;
}



// FUN_001E6930
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6930);

// FUN_001E6A00
s32 func_001e6a00(void) {
    func_0029cf50(*(u8 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA2) == 0);
    return 1;
}
// FUN_001E6A50
INCLUDE_ASM("asm/nonmatchings/btlAICommand", func_001e6a50);

