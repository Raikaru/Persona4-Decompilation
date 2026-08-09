.section .text
.set noat
.set noreorder
glabel func_00421660
    /* 321660 00421660 28000324 */  addiu      $3, $0, 0x28
    /* 321664 00421664 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321668 00421668 0800E003 */  jr         $31
    /* 32166C 0042166C 00000000 */   nop
.size func_00421660, 0x10
