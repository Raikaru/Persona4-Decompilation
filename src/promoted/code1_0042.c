/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */

/* PS2 kernel syscall trampolines: load the syscall number into $v1, then
 * execute the `syscall` instruction.  There is no C expression for this,
 * so whole-function asm is the honest representation (Category B: kernel
 * syscall convention, cf. tools/decomp_lint.py H009 allowance).  Encoded
 * as .word literals because MWCC's assembler rejects the syscall mnemonic. */

#include "type.h"

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
