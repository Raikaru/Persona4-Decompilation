.section .text
.set noat
.set noreorder
glabel func_00421c40
    /* 321C40 00421C40 7F000324 */  addiu      $3, $0, 0x7F
    /* 321C44 00421C44 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321C48 00421C48 0800E003 */  jr         $31
    /* 321C4C 00421C4C 00000000 */   nop
.size func_00421c40, 0x10
