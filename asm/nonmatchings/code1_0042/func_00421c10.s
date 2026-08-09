.section .text
.set noat
.set noreorder
glabel func_00421c10
    /* 321C10 00421C10 7C000324 */  addiu      $3, $0, 0x7C
    /* 321C14 00421C14 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321C18 00421C18 0800E003 */  jr         $31
    /* 321C1C 00421C1C 00000000 */   nop
.size func_00421c10, 0x10
