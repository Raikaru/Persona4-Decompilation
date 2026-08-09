.section .text
.set noat
.set noreorder
glabel func_00421720
    /* 321720 00421720 CCFF0324 */  addiu      $3, $0, -0x34
    /* 321724 00421724 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321728 00421728 0800E003 */  jr         $31
    /* 32172C 0042172C 00000000 */   nop
.size func_00421720, 0x10
