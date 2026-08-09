.section .text
.set noat
.set noreorder
glabel func_00421930
    /* 321930 00421930 ABFF0324 */  addiu      $3, $0, -0x55
    /* 321934 00421934 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321938 00421938 0800E003 */  jr         $31
    /* 32193C 0042193C 00000000 */   nop
.size func_00421930, 0x10
