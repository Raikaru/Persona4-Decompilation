#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultFriendPsLvUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0046d730(u8 *arg0, s32 arg1);

extern u8 *func_00452560(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern s32 func_00452380(u8 *arg0);
extern s32 func_00117780(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_0011d100(s32 arg0, void *arg1);
extern void func_0011bb90(s32 arg0);
extern void func_00117580(s32 arg0, s32 arg1);
extern u8 *func_0010a900(u16 arg0);
extern s32 func_00106330(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern void func_0011b480(s32 a0, u16 a1, u8 *a2, s32 a3);
extern s32 func_00455ea0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0011f410(s32 a0, s32 a1, u8 *a2, s32 a3, s32 a4, void *a5);
extern u32 func_00231d70(u32 max);
extern void func_001f86d0(void);
extern void func_001f9a50(u16 arg0, s32 arg1);
extern void func_001f9a90(void);
extern void func_001f8690(u16 arg0);
extern void func_002bb4e0(void);
extern s32 func_0011f560(s32 arg0);
extern void func_0011f580(s32 arg0);
extern s32 func_0021de60(void);
extern u8 D_00795F20[];
extern u8 D_005E4810[];
extern u16 D_008C024C;
extern u16 D_008C024E;
extern u8 D_00629720[];



// FUN_002238F0
s32 func_002238f0(s64 arg0)
{
    s64 temp_2;

    temp_2 = (s64)(arg0 << 0x30) >> 0x30;
    switch (temp_2) {
    case 2:
        return 0xE2;
    case 3:
        return 0x16C;
    case 4:
        return 0x1F3;
    case 6:
        return 0x27A;
    case 7:
        return 0x301;
    case 8:
        return 0x387;
    default:
        func_0046d730(D_00629720, 0x2C);
        return 0;
    }
}

// FUN_002239A0
INCLUDE_ASM("asm/nonmatchings/btlResultFriendPsLvUp", func_002239a0);
