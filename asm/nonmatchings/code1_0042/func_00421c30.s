.section .text
.set noat
.set noreorder
glabel func_00421c30
    /* 321C30 00421C30 7E000324 */  addiu      $3, $0, 0x7E
    /* 321C34 00421C34 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321C38 00421C38 0800E003 */  jr         $31
    /* 321C3C 00421C3C 00000000 */   nop
.size func_00421c30, 0x10
