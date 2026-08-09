.section .text
.set noat
.set noreorder
glabel func_00421a90
    /* 321A90 00421A90 98FF0324 */  addiu      $3, $0, -0x68
    /* 321A94 00421A94 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A98 00421A98 0800E003 */  jr         $31
    /* 321A9C 00421A9C 00000000 */   nop
.size func_00421a90, 0x10
