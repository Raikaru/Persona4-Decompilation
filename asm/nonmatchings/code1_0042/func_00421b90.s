.section .text
.set noat
.set noreorder
glabel func_00421b90
    /* 321B90 00421B90 8AFF0324 */  addiu      $3, $0, -0x76
    /* 321B94 00421B94 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B98 00421B98 0800E003 */  jr         $31
    /* 321B9C 00421B9C 00000000 */   nop
.size func_00421b90, 0x10
