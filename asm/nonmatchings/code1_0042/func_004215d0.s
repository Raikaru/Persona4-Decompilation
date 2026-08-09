.section .text
.set noat
.set noreorder
glabel func_004215d0
    /* 3215D0 004215D0 01FF0324 */  addiu      $3, $0, -0xFF
    /* 3215D4 004215D4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3215D8 004215D8 0800E003 */  jr         $31
    /* 3215DC 004215DC 00000000 */   nop
.size func_004215d0, 0x10
