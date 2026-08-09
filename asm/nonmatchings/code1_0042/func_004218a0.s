.section .text
.set noat
.set noreorder
glabel func_004218a0
    /* 3218A0 004218A0 4C000324 */  addiu      $3, $0, 0x4C
    /* 3218A4 004218A4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3218A8 004218A8 0800E003 */  jr         $31
    /* 3218AC 004218AC 00000000 */   nop
.size func_004218a0, 0x10
