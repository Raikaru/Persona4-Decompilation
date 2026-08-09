.section .text
.set noat
.set noreorder
glabel func_00421bc0
    /* 321BC0 00421BC0 78000324 */  addiu      $3, $0, 0x78
    /* 321BC4 00421BC4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321BC8 00421BC8 0800E003 */  jr         $31
    /* 321BCC 00421BCC 00000000 */   nop
.size func_00421bc0, 0x10
