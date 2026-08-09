.section .text
.set noat
.set noreorder
glabel func_00421500
    /* 321500 00421500 12000324 */  addiu      $3, $0, 0x12
    /* 321504 00421504 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321508 00421508 0800E003 */  jr         $31
    /* 32150C 0042150C 00000000 */   nop
.size func_00421500, 0x10
