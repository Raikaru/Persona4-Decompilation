#include "include_asm.h"
#include "type.h"
/* Consolidated Persona 4 source units. */
/* Ported from Persona 3 FES datScript.c (FUN_0030fc40/FUN_0030fdf0/
   FUN_003111f0/FUN_00311250 counterparts), adapted to the P4 build. */

extern char D_00635980[];          /* "datScript.c" assert file name */
extern void func_0046d730(const char* file, u32 line);

#define K_ASSERT(condition, line) \
    if (!(condition)) { func_0046d730(D_00635980, (line)); }

/* Script command dispatch table (0xB entries). */
extern void* D_00635950[];

extern u16* D_00881460[];   /* current command target unit 1 */
extern u16* D_00881464[];   /* current command target unit 2 */
extern s32 D_00881468[];    /* last calculation result */
extern u16 D_0088146C[];    /* current command id */
extern s32 D_00881470[];    /* current command parameter */
extern u16 D_00881474[];    /* command flags (bit0 = has result) */

extern u8* DAT_0076449c;    /* battle global work base */
extern u8* DAT_007644A8;    /* command data table (0x28-byte entries) */
extern u8* DAT_007644E4;    /* level-difference float table */
extern u8* DAT_007644E8;    /* level-difference float table (0x18 offset) */
extern u8* DAT_007644F0;    /* parameter table (s16 entries) */
extern u8* DAT_007644F4;    /* parameter table (s16 entries) */

s32 func_00231e20(u16* unit);
s32 func_00231ed0(u16* unit);
s32 func_00231f80(u16* unit);
s32 func_00232290(u16* unit);
s32 func_00232c70(u16* unit, u32 param);
s32 func_0023a6b0(u16* unit, s16 param);
s32 func_0023d740(s16 cmd, s32 param);
s32 func_0023d8e0(u16* unit, u16 cmd);
s32 func_0023e3e0(u16* unit, s32 param);
s32 func_0023e5b0(u16* unit, s32 param);
s32 func_00243ce0(u16* unit);

// FUN_00244F60
s32 func_00244f60(u32 arg0, u16* arg1, u16* arg2, u16 arg3, s32 arg4)
{
    D_0088146C[0] = arg3;
    D_00881460[0] = arg1;
    D_00881464[0] = arg2;
    D_00881470[0] = arg4;
    D_00881474[0] &= 0xFFFE;
    K_ASSERT(arg0 < 0xB, 0x7A);
    ((void (*)())D_00635950[arg0])();
    K_ASSERT(D_00881474[0] & 1, 0x82);
    return D_00881468[0];
}

// FUN_00245030
INCLUDE_ASM("asm/nonmatchings/datScript", func_00245030);

// FUN_00246480
s32 func_00246480(void)
{
    K_ASSERT(D_00881460[0] != 0, 0x1FD);
    return !(*D_00881460[0] & 4);
}

// FUN_002464E0
s32 func_002464e0(void)
{
    K_ASSERT(D_0088146C[0] < 0x1B8, 0x21A);
    return (DAT_007644A8[(u32)D_0088146C[0] * 0x28] & 2) != 0;
}
