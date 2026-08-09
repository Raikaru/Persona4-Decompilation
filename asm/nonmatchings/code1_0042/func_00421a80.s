.section .text
.set noat
.set noreorder
glabel func_00421a80
    /* 321A80 00421A80 99FF0324 */  addiu      $3, $0, -0x67
    /* 321A84 00421A84 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A88 00421A88 0800E003 */  jr         $31
    /* 321A8C 00421A8C 00000000 */   nop
.size func_00421a80, 0x10
