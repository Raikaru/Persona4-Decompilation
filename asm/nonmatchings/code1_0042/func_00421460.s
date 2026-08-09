.section .text
.set noat
.set noreorder
glabel func_00421460
    /* 321460 00421460 0A000324 */  addiu      $3, $0, 0xA
    /* 321464 00421464 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321468 00421468 0800E003 */  jr         $31
    /* 32146C 0042146C 00000000 */   nop
.size func_00421460, 0x10
