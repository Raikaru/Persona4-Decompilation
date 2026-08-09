.section .text
.set noat
.set noreorder
glabel func_00421b70
    /* 321B70 00421B70 75000324 */  addiu      $3, $0, 0x75
    /* 321B74 00421B74 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B78 00421B78 0800E003 */  jr         $31
    /* 321B7C 00421B7C 00000000 */   nop
.size func_00421b70, 0x10
