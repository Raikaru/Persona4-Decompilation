/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
/* Retail saves callee-saved `$s` registers with `sd`; MWCCPS2 3.0.1 emits `sq`; toolchain-blocked, see build/ORCH_sd_toolchain_blocked.txt. */

/* PS2 kernel syscall trampolines: load the syscall number into $v1, then
 * execute the `syscall` instruction.  There is no C expression for this,
 * so whole-function asm is the honest representation (Category B: kernel
 * syscall convention, cf. tools/decomp_lint.py H009 allowance).  Encoded
 * as .word literals because MWCC's assembler rejects the syscall mnemonic. */

#include "include_asm.h"
#include "type.h"

extern u8 D_00753E10[];
extern void func_004244c8();
extern s32 D_0088DCD8[];
extern void func_0042b480();
extern void func_00421800();
extern s32 D_0070C684[];
extern void func_00429d90();
extern void func_0042a330();
extern void func_0042a940();
extern void func_0042aba8();
extern void func_0042e2b8();
extern void func_00427dd8(u8 *arg0, u8 *arg1);
extern void func_00422030();
extern void func_00422170();
extern s32 func_0042ba20();
extern s32 func_0042cd10();
extern s32 func_0042ced0();
extern s32 func_0042cfd0();
extern s32 func_0042d1d0();
extern s32 func_0042d268();
// FUN_00420148
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420148);
// FUN_00420208
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420208);
// FUN_00420298
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420298);
// FUN_00420458
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420458);
// FUN_00420930
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420930);
// FUN_00420A78
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420a78);
/* measured: tailcall on emits the bare jump to the global wrapper. */
#pragma tailcall on
/* measured: schedule on places the global address addiu in the tail-call delay slot. */
#pragma schedule on
// FUN_00420B50
void func_00420b50(u8 *arg0)
{
    func_004244c8(D_00753E10, arg0);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
/* measured: end of the function-local tailcall override. */
#pragma tailcall off
// FUN_00420B60
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420b60);
// FUN_00420C00
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420c00);
// FUN_00420CC8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420cc8);
// FUN_00420D20
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420d20);
// FUN_00420D60
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420d60);
// FUN_00420DD8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420dd8);
// FUN_00420E50
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420e50);
// FUN_00420F38
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00420f38);
// FUN_00421088
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421088);
// FUN_004210F0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004210f0);
// FUN_00421168
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421168);
// FUN_004213C0
asm void func_004213c0(void)
{
    .set noreorder
    .word 0x24030000 /* addiu $v1, $zero, 0 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004213D0
asm void func_004213d0(void)
{
    .set noreorder
    .word 0x24030001 /* addiu $v1, $zero, 1 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004213E0
asm void func_004213e0(void)
{
    .set noreorder
    .word 0x24030002 /* addiu $v1, $zero, 2 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004213F0
asm void func_004213f0(void)
{
    .set noreorder
    .word 0x24030003 /* addiu $v1, $zero, 3 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421400
asm void func_00421400(void)
{
    .set noreorder
    .word 0x24030004 /* addiu $v1, $zero, 4 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421410
asm void func_00421410(void)
{
    .set noreorder
    .word 0x24030005 /* addiu $v1, $zero, 5 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421420
asm void func_00421420(void)
{
    .set noreorder
    .word 0x24030006 /* addiu $v1, $zero, 6 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421430
asm void func_00421430(void)
{
    .set noreorder
    .word 0x24030007 /* addiu $v1, $zero, 7 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421440
asm void func_00421440(void)
{
    .set noreorder
    .word 0x24030008 /* addiu $v1, $zero, 8 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421450
asm void func_00421450(void)
{
    .set noreorder
    .word 0x24030009 /* addiu $v1, $zero, 9 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421460
asm void func_00421460(void)
{
    .set noreorder
    .word 0x2403000A /* addiu $v1, $zero, 10 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421470
asm void func_00421470(void)
{
    .set noreorder
    .word 0x2403000B /* addiu $v1, $zero, 11 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421480
asm void func_00421480(void)
{
    .set noreorder
    .word 0x2403000C /* addiu $v1, $zero, 12 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421490
asm void func_00421490(void)
{
    .set noreorder
    .word 0x2403000D /* addiu $v1, $zero, 13 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004214A0
asm void func_004214a0(void)
{
    .set noreorder
    .word 0x2403000E /* addiu $v1, $zero, 14 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004214B0
asm void func_004214b0(void)
{
    .set noreorder
    .word 0x2403000F /* addiu $v1, $zero, 15 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004214C0
asm void func_004214c0(void)
{
    .set noreorder
    .word 0x24030010 /* addiu $v1, $zero, 16 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004214D0
asm void func_004214d0(void)
{
    .set noreorder
    .word 0x24030010 /* addiu $v1, $zero, 16 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004214E0
asm void func_004214e0(void)
{
    .set noreorder
    .word 0x24030011 /* addiu $v1, $zero, 17 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004214F0
asm void func_004214f0(void)
{
    .set noreorder
    .word 0x24030012 /* addiu $v1, $zero, 18 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421500
asm void func_00421500(void)
{
    .set noreorder
    .word 0x24030012 /* addiu $v1, $zero, 18 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421510
asm void func_00421510(void)
{
    .set noreorder
    .word 0x24030013 /* addiu $v1, $zero, 19 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421520
asm void func_00421520(void)
{
    .set noreorder
    .word 0x24030014 /* addiu $v1, $zero, 20 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421530
asm void func_00421530(void)
{
    .set noreorder
    .word 0x24030015 /* addiu $v1, $zero, 21 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421540
asm void func_00421540(void)
{
    .set noreorder
    .word 0x24030016 /* addiu $v1, $zero, 22 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421550
asm void func_00421550(void)
{
    .set noreorder
    .word 0x24030017 /* addiu $v1, $zero, 23 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421560
asm void func_00421560(void)
{
    .set noreorder
    .word 0x240300FC /* addiu $v1, $zero, 252 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421570
asm void func_00421570(void)
{
    .set noreorder
    .word 0x240300FD /* addiu $v1, $zero, 253 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421580
asm void func_00421580(void)
{
    .set noreorder
    .word 0x2403FFE6 /* addiu $v1, $zero, 65510 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421590
asm void func_00421590(void)
{
    .set noreorder
    .word 0x2403FFE5 /* addiu $v1, $zero, 65509 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004215A0
asm void func_004215a0(void)
{
    .set noreorder
    .word 0x2403FFE4 /* addiu $v1, $zero, 65508 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004215B0
asm void func_004215b0(void)
{
    .set noreorder
    .word 0x2403FFE3 /* addiu $v1, $zero, 65507 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004215C0
asm void func_004215c0(void)
{
    .set noreorder
    .word 0x2403FF02 /* addiu $v1, $zero, 65282 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004215D0
asm void func_004215d0(void)
{
    .set noreorder
    .word 0x2403FF01 /* addiu $v1, $zero, 65281 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004215E0
asm void func_004215e0(void)
{
    .set noreorder
    .word 0x24030020 /* addiu $v1, $zero, 32 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004215F0
asm void func_004215f0(void)
{
    .set noreorder
    .word 0x24030021 /* addiu $v1, $zero, 33 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421600
asm void func_00421600(void)
{
    .set noreorder
    .word 0x24030022 /* addiu $v1, $zero, 34 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421610
asm void func_00421610(void)
{
    .set noreorder
    .word 0x24030023 /* addiu $v1, $zero, 35 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421620
asm void func_00421620(void)
{
    .set noreorder
    .word 0x24030024 /* addiu $v1, $zero, 36 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421630
asm void func_00421630(void)
{
    .set noreorder
    .word 0x24030025 /* addiu $v1, $zero, 37 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421640
asm void func_00421640(void)
{
    .set noreorder
    .word 0x2403FFDA /* addiu $v1, $zero, 65498 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421650
asm void func_00421650(void)
{
    .set noreorder
    .word 0x24030027 /* addiu $v1, $zero, 39 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421660
asm void func_00421660(void)
{
    .set noreorder
    .word 0x24030028 /* addiu $v1, $zero, 40 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421670
asm void func_00421670(void)
{
    .set noreorder
    .word 0x24030029 /* addiu $v1, $zero, 41 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421680
asm void func_00421680(void)
{
    .set noreorder
    .word 0x2403FFD6 /* addiu $v1, $zero, 65494 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421690
asm void func_00421690(void)
{
    .set noreorder
    .word 0x2403002B /* addiu $v1, $zero, 43 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004216A0
asm void func_004216a0(void)
{
    .set noreorder
    .word 0x2403FFD4 /* addiu $v1, $zero, 65492 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004216B0
asm void func_004216b0(void)
{
    .set noreorder
    .word 0x2403002D /* addiu $v1, $zero, 45 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004216C0
asm void func_004216c0(void)
{
    .set noreorder
    .word 0x2403FFD2 /* addiu $v1, $zero, 65490 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004216D0
asm void func_004216d0(void)
{
    .set noreorder
    .word 0x2403002F /* addiu $v1, $zero, 47 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004216E0
asm void func_004216e0(void)
{
    .set noreorder
    .word 0x24030030 /* addiu $v1, $zero, 48 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004216F0
asm void func_004216f0(void)
{
    .set noreorder
    .word 0x2403FFCF /* addiu $v1, $zero, 65487 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421700
asm void func_00421700(void)
{
    .set noreorder
    .word 0x24030032 /* addiu $v1, $zero, 50 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421710
asm void func_00421710(void)
{
    .set noreorder
    .word 0x24030033 /* addiu $v1, $zero, 51 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421720
asm void func_00421720(void)
{
    .set noreorder
    .word 0x2403FFCC /* addiu $v1, $zero, 65484 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421730
asm void func_00421730(void)
{
    .set noreorder
    .word 0x24030035 /* addiu $v1, $zero, 53 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421740
asm void func_00421740(void)
{
    .set noreorder
    .word 0x2403FFCA /* addiu $v1, $zero, 65482 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421750
asm void func_00421750(void)
{
    .set noreorder
    .word 0x24030037 /* addiu $v1, $zero, 55 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421760
asm void func_00421760(void)
{
    .set noreorder
    .word 0x2403FFC8 /* addiu $v1, $zero, 65480 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421770
asm void func_00421770(void)
{
    .set noreorder
    .word 0x24030039 /* addiu $v1, $zero, 57 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421780
asm void func_00421780(void)
{
    .set noreorder
    .word 0x2403FFC6 /* addiu $v1, $zero, 65478 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421790
asm void func_00421790(void)
{
    .set noreorder
    .word 0x2403003B /* addiu $v1, $zero, 59 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004217A0
asm void func_004217a0(void)
{
    .set noreorder
    .word 0x2403003C /* addiu $v1, $zero, 60 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004217B0
asm void func_004217b0(void)
{
    .set noreorder
    .word 0x2403003D /* addiu $v1, $zero, 61 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004217C0
asm void func_004217c0(void)
{
    .set noreorder
    .word 0x2403003E /* addiu $v1, $zero, 62 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004217D0
asm void func_004217d0(void)
{
    .set noreorder
    .word 0x2403003F /* addiu $v1, $zero, 63 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004217E0
asm void func_004217e0(void)
{
    .set noreorder
    .word 0x24030040 /* addiu $v1, $zero, 64 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004217F0
asm void func_004217f0(void)
{
    .set noreorder
    .word 0x24030041 /* addiu $v1, $zero, 65 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421800
asm void func_00421800(s32 arg0)
{
    .set noreorder
    .word 0x24030042 /* addiu $v1, $zero, 66 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421810
asm void func_00421810(void)
{
    .set noreorder
    .word 0x2403FFBD /* addiu $v1, $zero, 65469 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421820
asm void func_00421820(void)
{
    .set noreorder
    .word 0x24030044 /* addiu $v1, $zero, 68 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421830
asm void func_00421830(void)
{
    .set noreorder
    .word 0x24030045 /* addiu $v1, $zero, 69 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421840
asm void func_00421840(void)
{
    .set noreorder
    .word 0x2403FFBA /* addiu $v1, $zero, 65466 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421850
asm void func_00421850(void)
{
    .set noreorder
    .word 0x24030047 /* addiu $v1, $zero, 71 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421860
asm void func_00421860(void)
{
    .set noreorder
    .word 0x2403FFB8 /* addiu $v1, $zero, 65464 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421870
asm void func_00421870(void)
{
    .set noreorder
    .word 0x24030049 /* addiu $v1, $zero, 73 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421880
asm void func_00421880(void)
{
    .set noreorder
    .word 0x2403004A /* addiu $v1, $zero, 74 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421890
asm void func_00421890(void)
{
    .set noreorder
    .word 0x2403004B /* addiu $v1, $zero, 75 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004218A0
asm void func_004218a0(void)
{
    .set noreorder
    .word 0x2403004C /* addiu $v1, $zero, 76 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004218B0
asm void func_004218b0(void)
{
    .set noreorder
    .word 0x2403004D /* addiu $v1, $zero, 77 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004218C0
asm void func_004218c0(void)
{
    .set noreorder
    .word 0x2403004E /* addiu $v1, $zero, 78 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004218D0
asm void func_004218d0(void)
{
    .set noreorder
    .word 0x2403004F /* addiu $v1, $zero, 79 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004218E0
asm void func_004218e0(void)
{
    .set noreorder
    .word 0x24030050 /* addiu $v1, $zero, 80 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004218F0
asm void func_004218f0(void)
{
    .set noreorder
    .word 0x24030051 /* addiu $v1, $zero, 81 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421900
asm void func_00421900(void)
{
    .set noreorder
    .word 0x24030052 /* addiu $v1, $zero, 82 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421910
asm void func_00421910(void)
{
    .set noreorder
    .word 0x2403FFAD /* addiu $v1, $zero, 65453 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421920
asm void func_00421920(void)
{
    .set noreorder
    .word 0x24030054 /* addiu $v1, $zero, 84 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421930
asm void func_00421930(void)
{
    .set noreorder
    .word 0x2403FFAB /* addiu $v1, $zero, 65451 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421940
asm void func_00421940(void)
{
    .set noreorder
    .word 0x24030056 /* addiu $v1, $zero, 86 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421950
asm void func_00421950(void)
{
    .set noreorder
    .word 0x24030057 /* addiu $v1, $zero, 87 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421960
asm void func_00421960(void)
{
    .set noreorder
    .word 0x2403FFA8 /* addiu $v1, $zero, 65448 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421970
asm void func_00421970(void)
{
    .set noreorder
    .word 0x24030059 /* addiu $v1, $zero, 89 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421980
asm void func_00421980(void)
{
    .set noreorder
    .word 0x2403FFA6 /* addiu $v1, $zero, 65446 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421990
asm void func_00421990(void)
{
    .set noreorder
    .word 0x2403005B /* addiu $v1, $zero, 91 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004219A0
asm void func_004219a0(void)
{
    .set noreorder
    .word 0x2403005C /* addiu $v1, $zero, 92 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004219B0
asm void func_004219b0(void)
{
    .set noreorder
    .word 0x2403FFA4 /* addiu $v1, $zero, 65444 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004219C0
asm void func_004219c0(void)
{
    .set noreorder
    .word 0x2403005D /* addiu $v1, $zero, 93 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004219D0
asm void func_004219d0(void)
{
    .set noreorder
    .word 0x2403FFA3 /* addiu $v1, $zero, 65443 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004219E0
asm void func_004219e0(void)
{
    .set noreorder
    .word 0x2403005E /* addiu $v1, $zero, 94 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_004219F0
asm void func_004219f0(void)
{
    .set noreorder
    .word 0x2403FFA2 /* addiu $v1, $zero, 65442 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A00
asm void func_00421a00(void)
{
    .set noreorder
    .word 0x2403005F /* addiu $v1, $zero, 95 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A10
asm void func_00421a10(void)
{
    .set noreorder
    .word 0x2403FFA1 /* addiu $v1, $zero, 65441 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A20
asm void func_00421a20(void)
{
    .set noreorder
    .word 0x24030060 /* addiu $v1, $zero, 96 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A30
asm void func_00421a30(void)
{
    .set noreorder
    .word 0x24030061 /* addiu $v1, $zero, 97 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A40
asm void func_00421a40(void)
{
    .set noreorder
    .word 0x24030062 /* addiu $v1, $zero, 98 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A50
asm void func_00421a50(void)
{
    .set noreorder
    .word 0x24030063 /* addiu $v1, $zero, 99 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A60
asm void func_00421a60(void)
{
    .set noreorder
    .word 0x24030064 /* addiu $v1, $zero, 100 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A70
asm void func_00421a70(void)
{
    .set noreorder
    .word 0x24030066 /* addiu $v1, $zero, 102 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A80
asm void func_00421a80(void)
{
    .set noreorder
    .word 0x2403FF99 /* addiu $v1, $zero, 65433 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421A90
asm void func_00421a90(void)
{
    .set noreorder
    .word 0x2403FF98 /* addiu $v1, $zero, 65432 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421AA0
asm void func_00421aa0(void)
{
    .set noreorder
    .word 0x2403FF96 /* addiu $v1, $zero, 65430 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421AB0
asm void func_00421ab0(void)
{
    .set noreorder
    .word 0x2403006B /* addiu $v1, $zero, 107 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421AC0
asm void func_00421ac0(void)
{
    .set noreorder
    .word 0x2403006C /* addiu $v1, $zero, 108 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421AD0
asm void func_00421ad0(void)
{
    .set noreorder
    .word 0x2403006D /* addiu $v1, $zero, 109 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421AE0
asm void func_00421ae0(void)
{
    .set noreorder
    .word 0x2403006E /* addiu $v1, $zero, 110 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421AF0
asm void func_00421af0(void)
{
    .set noreorder
    .word 0x2403006F /* addiu $v1, $zero, 111 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B00
asm void func_00421b00(void)
{
    .set noreorder
    .word 0x24030070 /* addiu $v1, $zero, 112 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B10
asm void func_00421b10(void)
{
    .set noreorder
    .word 0x2403FF90 /* addiu $v1, $zero, 65424 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B20
asm void func_00421b20(void)
{
    .set noreorder
    .word 0x24030071 /* addiu $v1, $zero, 113 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B30
asm void func_00421b30(void)
{
    .set noreorder
    .word 0x2403FF8F /* addiu $v1, $zero, 65423 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B40
asm void func_00421b40(void)
{
    .set noreorder
    .word 0x24030072 /* addiu $v1, $zero, 114 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B50
asm void func_00421b50(void)
{
    .set noreorder
    .word 0x24030073 /* addiu $v1, $zero, 115 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B60
asm void func_00421b60(void)
{
    .set noreorder
    .word 0x24030074 /* addiu $v1, $zero, 116 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B70
asm void func_00421b70(void)
{
    .set noreorder
    .word 0x24030075 /* addiu $v1, $zero, 117 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B80
asm void func_00421b80(void)
{
    .set noreorder
    .word 0x24030076 /* addiu $v1, $zero, 118 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421B90
asm void func_00421b90(void)
{
    .set noreorder
    .word 0x2403FF8A /* addiu $v1, $zero, 65418 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421BA0
asm void func_00421ba0(void)
{
    .set noreorder
    .word 0x24030077 /* addiu $v1, $zero, 119 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421BB0
asm void func_00421bb0(void)
{
    .set noreorder
    .word 0x2403FF89 /* addiu $v1, $zero, 65417 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421BC0
asm void func_00421bc0(void)
{
    .set noreorder
    .word 0x24030078 /* addiu $v1, $zero, 120 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421BD0
asm void func_00421bd0(void)
{
    .set noreorder
    .word 0x2403FF88 /* addiu $v1, $zero, 65416 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421BE0
asm void func_00421be0(void)
{
    .set noreorder
    .word 0x24030079 /* addiu $v1, $zero, 121 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421BF0
asm void func_00421bf0(void)
{
    .set noreorder
    .word 0x2403007A /* addiu $v1, $zero, 122 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421C00
asm void func_00421c00(void)
{
    .set noreorder
    .word 0x2403007B /* addiu $v1, $zero, 123 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421C10
asm void func_00421c10(void)
{
    .set noreorder
    .word 0x2403007C /* addiu $v1, $zero, 124 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421C20
asm void func_00421c20(void)
{
    .set noreorder
    .word 0x2403007D /* addiu $v1, $zero, 125 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421C30
asm void func_00421c30(void)
{
    .set noreorder
    .word 0x2403007E /* addiu $v1, $zero, 126 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421C40
asm void func_00421c40(void)
{
    .set noreorder
    .word 0x2403007F /* addiu $v1, $zero, 127 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_00421C50
asm void func_00421c50(void)
{
    .set noreorder
    .word 0x24030082 /* addiu $v1, $zero, 130 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

/* measured: schedule on places the absolute store in the jr delay slot. */
#pragma schedule on
// FUN_00421C60
u32 func_00421c60(void)
{
    u32 segment = 0x00710000;
    *(u32 *)(segment - 0x3A30) = 0;
    return segment;
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00421C70
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421c70);
// FUN_00421D00
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421d00);
// FUN_00421DA8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421da8);
// FUN_00421E28 NONMATCHING
#ifdef NON_MATCHING
s32 func_00421e28(s32 arg0, s32 arg1, s32 arg2)
{
 extern s32 D_0070C5D0[];
 extern s32 func_00423180(s32);
 extern s32 func_004230b0(s32, s32);
 u32 segment = ((u32)D_0070C5D0) & 0xFFFF0000;

 if (arg0 == 0) {
  if (*(s32 *)(segment - 0x3A30) == 0) {
   if (func_00423180(arg1) == 0) {
    goto block_fail;
   }
   *(s32 *)(segment - 0x3A30) = 1;
  }
  return func_004230b0(arg1, arg2);
block_fail:
  return -1;
 }
 return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421e28);
#endif
// FUN_00421EA0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421ea0);
/* measured: schedule on places the constant return in the jr delay slot. */
#pragma schedule on
// FUN_00421EC8
s32 func_00421ec8(void)
{
    return -1;
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
/* measured: schedule on places the constant return in the jr delay slot. */
#pragma schedule on
// FUN_00421ED0
s32 func_00421ed0(void)
{
    return -1;
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
/* measured: schedule on places the constant return in the jr delay slot. */
#pragma schedule on
// FUN_00421ED8
s32 func_00421ed8(void)
{
    return -1;
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00421EE0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421ee0);
/* measured: schedule on places the constant return in the jr delay slot. */
#pragma schedule on
// FUN_00421F90
s32 func_00421f90(void)
{
    return 1;
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00421F98
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421f98);
/* measured: schedule on places the constant return in the jr delay slot. */
#pragma schedule on
// FUN_00421FB0
s32 func_00421fb0(void)
{
    return 1;
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
/* measured: schedule on preserves the retail store/epilogue ordering. */
#pragma schedule on
// FUN_00421FB8
s32 func_00421fb8(s32 arg0, u8 *arg1)
{
    extern void func_0042c0d8(u8 *value);
    if (arg0 == 1) {
        func_0042c0d8(arg1);
    }
    return 0;
}
/* measured: close the function-local scheduling override. */
#pragma schedule off
// FUN_00421FE0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00421fe0);
// FUN_00422008
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422008);
// FUN_00422030
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422030);
// FUN_004220D8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004220d8);
/* Measured: tail-wrapper body has the correct two-argument mask/call semantics but b210 materializes 0xFFFFFFC0 as addiu -0x40 and emits a 16B object against the 24B window (nd 5); no mask spelling or O-level probe produced the retail lui/ori pair. Committed at nd 10 in-file (nd 5 measured in isolation). */
// FUN_00422158 NONMATCHING
#ifdef NON_MATCHING
/* measured: tailcall on emits the bare jump to the cache-range helper. */
#pragma tailcall on
/* measured: schedule on places the second mask in the tail-call delay slot. */
#pragma schedule on
void func_00422158(u8 *arg0, u8 *arg1)
{
    func_00422030((u8 *)((u32)arg0 & 0xFFFFFFC0), (u8 *)((u32)arg1 & 0xFFFFFFC0));
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
/* measured: end of the function-local tailcall override. */
#pragma tailcall off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422158);
#endif
// FUN_00422170
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422170);
// FUN_00422218
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422218);
/* Measured: tail-wrapper body has the correct two-argument mask/call semantics but b210 materializes 0xFFFFFFC0 as addiu -0x40 and emits a 16B object against the 24B window (nd 5); no mask spelling or O-level probe produced the retail lui/ori pair. Committed at nd 10 in-file (nd 5 measured in isolation). */
// FUN_00422298 NONMATCHING
#ifdef NON_MATCHING
/* measured: tailcall on emits the bare jump to the cache-range helper. */
#pragma tailcall on
/* measured: schedule on places the second mask in the tail-call delay slot. */
#pragma schedule on
void func_00422298(u8 *arg0, u8 *arg1)
{
    func_00422170((u8 *)((u32)arg0 & 0xFFFFFFC0), (u8 *)((u32)arg1 & 0xFFFFFFC0));
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
/* measured: end of the function-local tailcall override. */
#pragma tailcall off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422298);
#endif
// FUN_004222C0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004222c0);
// FUN_00422328
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422328);
// FUN_00422390
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422390);
// FUN_004223F8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004223f8);
/* measured: schedule on keeps the permitted sync after the real call and
   reproduces the retail leaf wrapper's epilogue. */
#pragma schedule on
// FUN_00422460
void func_00422460(void)
{
    func_00421580();
    __asm__ volatile ("sync" : : : "memory");
}
/* measured: closes schedule on around func_00422460. */
#pragma schedule off
/* measured: schedule on keeps the permitted sync after the real call and
   reproduces the retail leaf wrapper's epilogue. */
#pragma schedule on
// FUN_00422480
void func_00422480(void)
{
    func_00421590();
    __asm__ volatile ("sync" : : : "memory");
}
/* measured: closes schedule on around func_00422480. */
#pragma schedule off
/* measured: schedule on keeps the permitted sync after the real call and
   reproduces the retail leaf wrapper's epilogue. */
#pragma schedule on
// FUN_004224A0
void func_004224a0(void)
{
    func_004215a0();
    __asm__ volatile ("sync" : : : "memory");
}
/* measured: closes schedule on around func_004224a0. */
#pragma schedule off
/* measured: schedule on keeps the permitted sync after the real call and
   reproduces the retail leaf wrapper's epilogue. */
#pragma schedule on
// FUN_004224C0
void func_004224c0(void)
{
    func_004215b0();
    __asm__ volatile ("sync" : : : "memory");
}
/* measured: closes schedule on around func_004224c0. */
#pragma schedule off
// FUN_004224E0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004224e0);
// FUN_004225B8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004225b8);
// FUN_004226A8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004226a8);
// FUN_00422740
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422740);
// FUN_004227C0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004227c0);
// FUN_00422858
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422858);
// FUN_00422920
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422920);
// FUN_00422A98
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422a98);
// FUN_00422AC0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422ac0);
// FUN_00422B08
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422b08);
// FUN_00422B30
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422b30);
// FUN_00422B60
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422b60);
// FUN_00422B88
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422b88);
// FUN_00422BB8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422bb8);
// FUN_00422BE0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422be0);
// FUN_00422C18
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422c18);
// FUN_00422C50
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422c50);
// FUN_00422C80
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422c80);
// FUN_00422CA8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422ca8);
// FUN_00422CD0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422cd0);
// FUN_00422CF8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422cf8);
// FUN_00422D20
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422d20);
// FUN_00422D60
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422d60);
// FUN_00422DA0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422da0);
// FUN_00422F38
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00422f38);
// FUN_004230B0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004230b0);
// FUN_00423180
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00423180);
// FUN_00423240
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00423240);
// FUN_00423278
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00423278);
// FUN_00423328
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00423328);
// FUN_00423360
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00423360);
// FUN_004233F0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004233f0);
// FUN_004235C8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004235c8);
// FUN_004242E0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004242e0);
// FUN_00424338
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424338);
// FUN_00424360
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424360);
// FUN_00424388
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424388);
// FUN_004243D8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004243d8);
// FUN_00424410
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424410);
// FUN_00424458
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424458);
// FUN_004244C8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004244c8);
// FUN_00424548
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424548);
// FUN_004245C8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004245c8);
/* measured: schedule on places the copied value store in the jr delay slot. */
#pragma schedule on
// FUN_004245E8
s32 func_004245e8(u8 *arg0, u8 *arg1)
{
    s32 value = *(s32 *)(arg0 + 0x10);
    *(s32 *)(arg1 + 8) = value;
    return value;
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_004245F8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004245f8);
// FUN_00424610
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424610);
/* measured: schedule on places the global address addiu in the jr delay slot. */
#pragma schedule on
// FUN_00424630
u8 *func_00424630(void)
{
    return (u8 *)D_0088DCD8;
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00424640
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424640);
// FUN_00424708
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424708);
// FUN_00424790
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424790);
// FUN_004247C8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004247c8);
// FUN_00424A48
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424a48);
extern s32 D_0088DCD8[];
/* measured: schedule on places the final store in the jr delay slot. */
#pragma schedule on
// FUN_00424A80
s32 func_00424a80(s32 arg0, s32 arg1)
{
    u8 *base = (u8 *)D_0088DCD8;
    s32 result = *(s32 *)(base + 0x14);
    *(s32 *)(base + 0x18) = arg1;
    *(s32 *)(base + 0x14) = arg0;
    return result;
}
/* measured: close the function-local scheduling override. */
#pragma schedule off
/* measured: schedule on places the final store in the jr delay slot. */
#pragma schedule on
// FUN_00424A98
s32 func_00424a98(s32 arg0, s32 arg1)
{
    u8 *base = (u8 *)D_0088DCD8;
    s32 result = *(s32 *)(base + 0xC);
    *(s32 *)(base + 0x10) = arg1;
    *(s32 *)(base + 0xC) = arg0;
    return result;
}
/* measured: close the function-local scheduling override. */
#pragma schedule off
// FUN_00424AB0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424ab0);
// FUN_00424B28
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424b28);
// FUN_00424B78
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424b78);
// FUN_00424CB0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424cb0);
// FUN_00424CF0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424cf0);
// FUN_00424D30
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424d30);
// FUN_00424E78
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424e78);
// FUN_00424F24
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424f24);
// FUN_00424F28
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00424f28);
// FUN_004250C8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004250c8);
// FUN_004250F0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004250f0);
// FUN_00425198
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425198);
// FUN_004251B8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004251b8);
// FUN_004251E8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004251e8);
// FUN_00425228
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425228);
// FUN_004252F8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004252f8);
// FUN_00425338
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425338);
// FUN_00425408
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425408);
// FUN_00425570
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425570);
// FUN_004255C0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004255c0);
// FUN_00425600
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425600);
// FUN_004256D0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004256d0);
// FUN_00425820
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425820);
// FUN_004258B0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004258b0);
// FUN_00425AB0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425ab0);
// FUN_00425AF0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425af0);
// FUN_00425B88
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425b88);
// FUN_00425C58
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425c58);
// FUN_00425CF0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425cf0);
// FUN_00425D80
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425d80);
// FUN_00425DD8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425dd8);
// FUN_00425FA0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425fa0);
// FUN_00425FE0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00425fe0);
// FUN_00426050
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426050);
// FUN_004260D0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004260d0);
// FUN_00426158
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426158);
// FUN_00426248
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426248);
// FUN_004262B8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004262b8);
// FUN_00426670
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426670);
// FUN_004266C8
/* measured: schedule on preserves the second-call global load and return sequence. */
#pragma schedule on
s32 func_004266c8(void)
{
    extern void func_00426670();
    extern void func_00421820();
    func_00426670();
    func_00421820(D_0070C684[0]);
    return 0;
}
/* measured: close the function-local scheduling override. */
#pragma schedule off
/* measured: tailcall on emits the bare jump to the syscall wrapper. */
#pragma tailcall on
/* measured: schedule on places the global load in the tail-call delay slot. */
#pragma schedule on
// FUN_004266F8
void func_004266f8(void)
{
    func_00421800(D_0070C684[0]);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
/* measured: end of the function-local tailcall override. */
#pragma tailcall off
// FUN_00426708
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426708);
// FUN_004267A8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004267a8);
// FUN_004267F0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004267f0);
// FUN_004269F8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004269f8);
// FUN_00426A88
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426a88);
// FUN_00426AC0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426ac0);
// FUN_00426C00
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426c00);
// FUN_00426CF0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426cf0);
// FUN_00426F80
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00426f80);
// FUN_004270F8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004270f8);
// FUN_00427338
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00427338);
// FUN_004275A8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004275a8);
// FUN_00427868
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00427868);
// FUN_00427BF0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00427bf0);
// FUN_00427DD8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00427dd8);
/* measured: schedule on places the constant argument and epilogue delay slots. */
#pragma schedule on
// FUN_00427F88
void func_00427f88(u8 *arg0)
{
    func_00427dd8(arg0, (u8 *)6);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00427FA8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00427fa8);
/* measured: schedule on places the constant argument and epilogue delay slots. */
#pragma schedule on
// FUN_00428160
void func_00428160(u8 *arg0)
{
    func_00427dd8(arg0, (u8 *)8);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00428180
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00428180);
// FUN_00428400
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00428400);
// FUN_00428530
/* measured: schedule on places the constant argument and epilogue delay slots. */
#pragma schedule on
void func_00428530(u8 *arg0)
{
    func_00427dd8(arg0, (u8 *)0x10);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00428550
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00428550);
// FUN_00428618
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00428618);
// FUN_00428780
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00428780);
// FUN_004288D8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004288d8);
// FUN_00428A90
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00428a90);
// FUN_00428CE0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00428ce0);
// FUN_00428EE8
/* measured: schedule on places the constant argument and epilogue delay slots. */
#pragma schedule on
void func_00428ee8(u8 *arg0)
{
    func_00427dd8(arg0, (u8 *)0x12);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00428F08
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00428f08);
// FUN_004290B8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_004290b8);
// FUN_00429338
/* measured: schedule on places the constant argument and epilogue delay slots. */
#pragma schedule on
void func_00429338(u8 *arg0)
{
    func_00427dd8(arg0, (u8 *)0x15);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00429358
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429358);
// FUN_00429598
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429598);
// FUN_00429840
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429840);
// FUN_00429A38
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429a38);
// FUN_00429C18
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429c18);
// FUN_00429CA0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429ca0);
// FUN_00429D10
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429d10);
// FUN_00429D90
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429d90);
/* measured: schedule on places the stack restore in the jr delay slot. */
#pragma schedule on
// FUN_00429E08
void func_00429e08(void)
{
    func_00429d90();
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_00429E28
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429e28);
// FUN_00429F18
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429f18);
// FUN_00429F88
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429f88);
// FUN_00429FF8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_00429ff8);
// FUN_0042A068
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a068);
// FUN_0042A0E8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a0e8);
// FUN_0042A168
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a168);
// FUN_0042A268
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a268);
// FUN_0042A2F8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a2f8);
// FUN_0042A330
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a330);
// FUN_0042A538
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a538);
// FUN_0042A740
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a740);
// FUN_0042A7D0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a7d0);
// FUN_0042A870
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a870);
// FUN_0042A900
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a900);
/* measured: schedule on places the stack restore in the jr delay slot. */
#pragma schedule on
// FUN_0042A920
void func_0042a920(void)
{
    func_0042a330();
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_0042A940
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042a940);
// FUN_0042AB68
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ab68);
/* measured: schedule on moves the zero fifth argument into the jal delay slot. */
#pragma schedule on
// FUN_0042AB88
void func_0042ab88(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    func_0042a940(arg0, arg1, arg2, arg3, 0);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_0042ABA8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042aba8);
/* measured: schedule on moves the constant fourth argument into the jal delay slot. */
#pragma schedule on
// FUN_0042ACB0
void func_0042acb0(u8 *arg0, u8 *arg1, u8 *arg2)
{
    func_0042aba8(arg0, arg1, arg2, (u8 *)1);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_0042ACD0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042acd0);
// FUN_0042ACF8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042acf8);
// FUN_0042ADE8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ade8);
// FUN_0042AEC8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042aec8);
// FUN_0042B020
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b020);
// FUN_0042B048
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b048);
// FUN_0042B098
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b098);
// FUN_0042B1A8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b1a8);
// FUN_0042B208
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b208);
// FUN_0042B290
asm void func_0042b290(void)
{
    .set noreorder
    .word 0x2403005A /* addiu $v1, $zero, 90 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B2A0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b2a0);
// FUN_0042B2D8
asm void func_0042b2d8(void)
{
    .set noreorder
    .word 0x2403005B /* addiu $v1, $zero, 91 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B2E8
asm void func_0042b2e8(void)
{
    .set noreorder
    .word 0x24030074 /* addiu $v1, $zero, 116 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B2F8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b2f8);
// FUN_0042B3C0
asm void func_0042b3c0(void)
{
    .set noreorder
    .word 0x24030055 /* addiu $v1, $zero, 85 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B3D0
asm void func_0042b3d0(void)
{
    .set noreorder
    .word 0x2403FFAB /* addiu $v1, $zero, 65451 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B3E0
asm void func_0042b3e0(void)
{
    .set noreorder
    .word 0x24030056 /* addiu $v1, $zero, 86 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B3F0
/* measured: schedule on places the saved-ra store in the guard branch delay slot. */
#pragma schedule on
s32 func_0042b3f0(s32 arg0)
{
    extern s32 func_0042b3e0();
    if ((u32)(arg0 - 0xD) >= 0x23U) {
        return -1;
    }
    return func_0042b3e0();
}
/* measured: close the function-local scheduling override. */
#pragma schedule off
// FUN_0042B420
asm void func_0042b420(void)
{
    .set noreorder
    .word 0x2403FFAA /* addiu $v1, $zero, 65450 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B430
asm void func_0042b430(void)
{
    .set noreorder
    .word 0x24030057 /* addiu $v1, $zero, 87 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B440
asm void func_0042b440(void)
{
    .set noreorder
    .word 0x2403FFA9 /* addiu $v1, $zero, 65449 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B450
asm void func_0042b450(void)
{
    .set noreorder
    .word 0x24030058 /* addiu $v1, $zero, 88 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B460
asm void func_0042b460(void)
{
    .set noreorder
    .word 0x2403FFA8 /* addiu $v1, $zero, 65448 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B470
asm void func_0042b470(void)
{
    .set noreorder
    .word 0x24030059 /* addiu $v1, $zero, 89 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042B480
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b480);
// FUN_0042B4C0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b4c0);
// FUN_0042B6C0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042b6c0);
// FUN_0042BA20
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ba20);
// FUN_0042BA70
asm s32 func_0042ba70(void)
{
    .set noreorder
    .word 0x40026000 /* mfc0 $v0, $12 */
    .word 0x3C030001 /* lui $v1, 0x1 */
    .word 0x00431024 /* and $v0, $v0, $v1 */
    .word 0x42000038 /* ei */
    .word 0x03E00008 /* jr $ra */
    .word 0x0002102B /* sltu $v0, $zero, $v0 */
}
// FUN_0042BA88
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ba88);
// FUN_0042BAE8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bae8);
// FUN_0042BAF8
asm void func_0042baf8(void)
{
    .set noreorder
    .word 0x2403005A /* addiu $v1, $zero, 90 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042BB08
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bb08);
// FUN_0042BB40
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bb40);
// FUN_0042BB80
asm void func_0042bb80(void)
{
    .set noreorder
    .word 0x24030083 /* addiu $v1, $zero, 131 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042BB90
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bb90);
// FUN_0042BBC8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bbc8);
// FUN_0042BCC8
asm void func_0042bcc8(void)
{
    .set noreorder
    .word 0x24030074 /* addiu $v1, $zero, 116 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042BCD8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bcd8);
// FUN_0042BD30
asm void func_0042bd30(void)
{
    .set noreorder
    .word 0x24030074 /* addiu $v1, $zero, 116 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042BD40
asm void func_0042bd40(void)
{
    .set noreorder
    .word 0x2403005A /* addiu $v1, $zero, 90 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042BD50
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bd50);
// FUN_0042BD88
asm void func_0042bd88(void)
{
    .set noreorder
    .word 0x2403005B /* addiu $v1, $zero, 91 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042BD98
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bd98);
// FUN_0042BE00
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042be00);
// FUN_0042BEB0
asm void func_0042beb0(void)
{
    .set noreorder
    .word 0x2403005A /* addiu $v1, $zero, 90 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042BEC0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bec0);
// FUN_0042BEF0
asm void func_0042bef0(void)
{
    .set noreorder
    .word 0x24030074 /* addiu $v1, $zero, 116 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042BF00
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042bf00);
/* measured: tailcall on emits the bare jump to the direct wrapper. */
#pragma tailcall on
// FUN_0042C018
void func_0042c018(void)
{
    func_0042b480();
}
/* measured: end of the function-local tailcall override. */
#pragma tailcall off
// FUN_0042C020
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c020);
// FUN_0042C090
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c090);
// FUN_0042C0D8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c0d8);
// FUN_0042C100
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c100);
// FUN_0042C150
asm void func_0042c150(void)
{
    .set noreorder
    .word 0x24030074 /* addiu $v1, $zero, 116 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042C160
asm void func_0042c160(void)
{
    .set noreorder
    .word 0x2403005A /* addiu $v1, $zero, 90 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042C170
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c170);
// FUN_0042C1A8
asm void func_0042c1a8(void)
{
    .set noreorder
    .word 0x2403005B /* addiu $v1, $zero, 91 */
    .word 0x0000000C /* syscall */
    .word 0x03E00008 /* jr $ra */
    .word 0x00000000 /* nop */
}

// FUN_0042C1B8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c1b8);
// FUN_0042C290
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c290);
// FUN_0042C300
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c300);
// FUN_0042C310
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c310);
// FUN_0042C320
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c320);
// FUN_0042C330
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c330);
// FUN_0042C488
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c488);
// FUN_0042C540
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c540);
// FUN_0042C570
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c570);
// FUN_0042C600
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c600);
// FUN_0042C680
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c680);
// FUN_0042C810
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c810);
// FUN_0042C898
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c898);
// FUN_0042C8D0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042c8d0);
// FUN_0042CB88
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042cb88);
// FUN_0042CBD8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042cbd8);
// FUN_0042CC58
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042cc58);
// FUN_0042CCC8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ccc8);
// FUN_0042CD10
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042cd10);
// FUN_0042CDD0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042cdd0);
// FUN_0042CE20
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ce20);
// FUN_0042CE70
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ce70);
// FUN_0042CED0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ced0);
// FUN_0042CF80
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042cf80);
// FUN_0042CFD0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042cfd0);
// FUN_0042D0B0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d0b0);
// FUN_0042D100
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d100);
// FUN_0042D1D0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d1d0);
// FUN_0042D218
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d218);
// FUN_0042D268
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d268);
// FUN_0042D2D8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d2d8);
// FUN_0042D328
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d328);
// FUN_0042D438
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d438);
// FUN_0042D4B8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d4b8);
// FUN_0042D560
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d560);
// FUN_0042D5D0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d5d0);
// FUN_0042D628
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d628);
// FUN_0042D660
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d660);
// FUN_0042D6B0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d6b0);
// FUN_0042D710
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d710);
// FUN_0042D840
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d840);
// FUN_0042D930
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d930);
// FUN_0042D9D8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042d9d8);
// FUN_0042DA50
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042da50);
// FUN_0042DA78
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042da78);
// FUN_0042DAF8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042daf8);
// FUN_0042DBB0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042dbb0);
// FUN_0042DC08
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042dc08);
// FUN_0042DCB0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042dcb0);
// FUN_0042DD18
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042dd18);
// FUN_0042DDB8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ddb8);
// FUN_0042DF28
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042df28);
// FUN_0042DFE0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042dfe0);
// FUN_0042E0C8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e0c8);
// FUN_0042E168
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e168);
// FUN_0042E1E8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e1e8);
// FUN_0042E240
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e240);
// FUN_0042E2B8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e2b8);
/* measured: schedule on moves the zero third argument into the jal delay slot. */
#pragma schedule on
// FUN_0042E5B8
void func_0042e5b8(u8 *arg0, u8 *arg1)
{
    func_0042e2b8(arg0, arg1, 0);
}
/* measured: end of the function-local scheduling override. */
#pragma schedule off
// FUN_0042E5D8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e5d8);
// FUN_0042E730
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e730);
// FUN_0042E7C8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e7c8);
// FUN_0042E868
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e868);
// FUN_0042E8D8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042e8d8);
// FUN_0042EA30
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ea30);
// FUN_0042EAE0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042eae0);
// FUN_0042EDC8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042edc8);
// FUN_0042EFE0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042efe0);
// FUN_0042F200
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f200);
// FUN_0042F3E0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f3e0);
// FUN_0042F4B0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f4b0);
// FUN_0042F548
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f548);
// FUN_0042F600
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f600);
// FUN_0042F6D0
/* measured: schedule on preserves the pre-call global materialization and return delay slot. */
#pragma schedule on
s32 func_0042f6d0(void)
{
    extern u8 D_007546F0[];
    extern void func_004244c8();
    func_004244c8(D_007546F0);
    return 2;
}
/* measured: close the function-local scheduling override. */
#pragma schedule off
// FUN_0042F6F8
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f6f8);
// FUN_0042F848
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f848);
// FUN_0042F890
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f890);
// FUN_0042F988
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042f988);
// FUN_0042FA38
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042fa38);
// FUN_0042FB50
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042fb50);
// FUN_0042FD38
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042fd38);
// FUN_0042FDF0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042fdf0);
// FUN_0042FF48
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ff48);
// FUN_0042FFA0
INCLUDE_ASM("asm/nonmatchings/code1_0042", func_0042ffa0);