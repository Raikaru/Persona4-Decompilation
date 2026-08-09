.section .text
.set noat
.set noreorder
glabel func_00421c50
    /* 321C50 00421C50 82000324 */  addiu      $3, $0, 0x82
    /* 321C54 00421C54 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321C58 00421C58 0800E003 */  jr         $31
    /* 321C5C 00421C5C 00000000 */   nop
.size func_00421c50, 0x10
