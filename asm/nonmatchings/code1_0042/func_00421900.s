.section .text
.set noat
.set noreorder
glabel func_00421900
    /* 321900 00421900 52000324 */  addiu      $3, $0, 0x52
    /* 321904 00421904 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321908 00421908 0800E003 */  jr         $31
    /* 32190C 0042190C 00000000 */   nop
.size func_00421900, 0x10
