.section .text
.set noat
.set noreorder
glabel func_00421520
    /* 321520 00421520 14000324 */  addiu      $3, $0, 0x14
    /* 321524 00421524 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321528 00421528 0800E003 */  jr         $31
    /* 32152C 0042152C 00000000 */   nop
.size func_00421520, 0x10
