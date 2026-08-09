.section .text
.set noat
.set noreorder
glabel func_00421c20
    /* 321C20 00421C20 7D000324 */  addiu      $3, $0, 0x7D
    /* 321C24 00421C24 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321C28 00421C28 0800E003 */  jr         $31
    /* 321C2C 00421C2C 00000000 */   nop
.size func_00421c20, 0x10
