.section .text
.set noat
.set noreorder
glabel func_00421b50
    /* 321B50 00421B50 73000324 */  addiu      $3, $0, 0x73
    /* 321B54 00421B54 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B58 00421B58 0800E003 */  jr         $31
    /* 321B5C 00421B5C 00000000 */   nop
.size func_00421b50, 0x10
