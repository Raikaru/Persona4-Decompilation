.section .text
.set noat
.set noreorder
glabel func_00421b60
    /* 321B60 00421B60 74000324 */  addiu      $3, $0, 0x74
    /* 321B64 00421B64 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B68 00421B68 0800E003 */  jr         $31
    /* 321B6C 00421B6C 00000000 */   nop
.size func_00421b60, 0x10
