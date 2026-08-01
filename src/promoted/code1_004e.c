#include "include_asm.h"
#include "type.h"

extern s8 D_00923640[];

extern u8 D_00731C7C[];

extern s32 D_00731C78[];

extern s32 D_00731C3C[];

extern s8 D_00731C01[];

extern s32 D_00731C34[];

extern s32 D_00731C70[];


#pragma schedule on

// FUN_004E1C20
s8 *func_004e1c20(void) {
    return D_00923640;
}
/* measured: without scheduling the addiu leaves the jr $ra delay slot; nd 0 -> 6 */
#pragma schedule off


#pragma schedule on

// FUN_004E3D88 NONMATCHING
#ifdef NON_MATCHING
void func_004e3d88(u8 arg0) {
    D_00731C7C[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3d88);
#endif
/* measured: retail puts the sb in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off


#pragma schedule on

// FUN_004E3D98 NONMATCHING
#ifdef NON_MATCHING
void func_004e3d98(s32 arg0) {
    D_00731C78[0] = arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3d98);
#endif
/* measured: retail puts the sw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off


#pragma schedule on

// FUN_004E3DA8 NONMATCHING
#ifdef NON_MATCHING
u8 func_004e3da8(void) {
    return D_00731C7C[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3da8);
#endif
/* measured: retail puts the lbu in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off


#pragma schedule on

// FUN_004E3DB8 NONMATCHING
#ifdef NON_MATCHING
s32 func_004e3db8(void) {
    return D_00731C78[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3db8);
#endif
/* measured: retail puts the lw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off


#pragma schedule on

// FUN_004E4180 NONMATCHING
#ifdef NON_MATCHING
s32 func_004e4180(void) {
    return D_00731C3C[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4180);
#endif
/* measured: retail puts the lw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off


#pragma schedule on

// FUN_004E4280 NONMATCHING
#ifdef NON_MATCHING
s8 func_004e4280(void) {
    return D_00731C01[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4280);
#endif
/* measured: retail puts the lb in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off


#pragma schedule on

// FUN_004E4290 NONMATCHING
#ifdef NON_MATCHING
s32 func_004e4290(void) {
    return D_00731C34[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4290);
#endif
/* measured: retail puts the lw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off


#pragma schedule on

// FUN_004E4688 NONMATCHING
#ifdef NON_MATCHING
s32 func_004e4688(void) {
    return D_00731C70[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4688);
#endif
/* measured: retail puts the lw in the jr $ra delay slot; only scheduling reproduces it */
#pragma schedule off
