.section .text
.set noat
.set noreorder
glabel func_004215a0
    /* 3215A0 004215A0 E4FF0324 */  addiu      $3, $0, -0x1C
    /* 3215A4 004215A4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3215A8 004215A8 0800E003 */  jr         $31
    /* 3215AC 004215AC 00000000 */   nop
.size func_004215a0, 0x10
