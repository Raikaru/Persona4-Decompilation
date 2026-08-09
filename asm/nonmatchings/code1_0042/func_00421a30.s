.section .text
.set noat
.set noreorder
glabel func_00421a30
    /* 321A30 00421A30 61000324 */  addiu      $3, $0, 0x61
    /* 321A34 00421A34 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A38 00421A38 0800E003 */  jr         $31
    /* 321A3C 00421A3C 00000000 */   nop
.size func_00421a30, 0x10
