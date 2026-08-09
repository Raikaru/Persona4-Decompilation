.section .text
.set noat
.set noreorder
glabel func_00421b10
    /* 321B10 00421B10 90FF0324 */  addiu      $3, $0, -0x70
    /* 321B14 00421B14 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B18 00421B18 0800E003 */  jr         $31
    /* 321B1C 00421B1C 00000000 */   nop
.size func_00421b10, 0x10
