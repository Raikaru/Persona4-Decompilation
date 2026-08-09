.section .text
.set noat
.set noreorder
glabel func_00421c00
    /* 321C00 00421C00 7B000324 */  addiu      $3, $0, 0x7B
    /* 321C04 00421C04 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321C08 00421C08 0800E003 */  jr         $31
    /* 321C0C 00421C0C 00000000 */   nop
.size func_00421c00, 0x10
