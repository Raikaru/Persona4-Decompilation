.section .text
.set noat
.set noreorder
glabel func_00421b30
    /* 321B30 00421B30 8FFF0324 */  addiu      $3, $0, -0x71
    /* 321B34 00421B34 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B38 00421B38 0800E003 */  jr         $31
    /* 321B3C 00421B3C 00000000 */   nop
.size func_00421b30, 0x10
