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

// FUN_004E3D88
u8 *func_004e3d88(u8 arg0) {
    u8 *segment = (u8 *)0x00730000;
    segment[0x1C7C] = arg0;
    return segment;
}
/* measured: sb uses $v0 base because zero-lo segment is the live return (void store colors $v1, nd 2; returning 0x00731C7C adds ori, nd 3); schedule on fills the jr delay slot (nd 3 -> 0, tail nop is padding) */
#pragma schedule off


#pragma schedule on

// FUN_004E3D98
s32 *func_004e3d98(s32 arg0) {
    s32 *segment = (s32 *)0x00730000;
    segment[0x71E] = arg0;
    return segment;
}
/* measured: sw uses $v0 base because zero-lo segment is the live return (void store colors $v1, nd 2; returning 0x00731C78 adds ori, nd 3); schedule on fills the jr delay slot (nd 3 -> 0, tail nop is padding) */
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
/* measured: schedule on fills the lbu jr delay slot; absolute-array form required (scalar extern compiles GPREL16, nd 4); address reuses $v0 in every shape tried (literal, pointer, segment, volatile, const) vs retail $v1 - allocator floor, same residual in code1_004d/P3FES cri_adx.c */
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
/* measured: schedule on fills the lw jr delay slot; absolute-array form required (scalar extern compiles GPREL16, nd 4); address reuses $v0 in every shape tried (literal, pointer, segment, volatile, const) vs retail $v1 - allocator floor, same residual in code1_004d/P3FES cri_adx.c */
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
/* measured: schedule on fills the lw jr delay slot; absolute-array form required (scalar extern compiles GPREL16, nd 4); address reuses $v0 vs retail $v1 - allocator floor, same residual in code1_004d/P3FES cri_adx.c */
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
/* measured: schedule on fills the lb jr delay slot; absolute-array form required (scalar extern compiles GPREL16, nd 4); address reuses $v0 vs retail $v1 - allocator floor, same residual in code1_004d/P3FES cri_adx.c */
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
/* measured: schedule on fills the lw jr delay slot; absolute-array form required (scalar extern compiles GPREL16, nd 4); address reuses $v0 vs retail $v1 - allocator floor, same residual in code1_004d/P3FES cri_adx.c */
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
/* measured: schedule on fills the lw jr delay slot; absolute-array form required (scalar extern compiles GPREL16, nd 4); address reuses $v0 vs retail $v1 - allocator floor, same residual in code1_004d/P3FES cri_adx.c */
#pragma schedule off
