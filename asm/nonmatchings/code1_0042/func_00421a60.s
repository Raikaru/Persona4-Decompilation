.section .text
.set noat
.set noreorder
glabel func_00421a60
    /* 321A60 00421A60 64000324 */  addiu      $3, $0, 0x64
    /* 321A64 00421A64 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A68 00421A68 0800E003 */  jr         $31
    /* 321A6C 00421A6C 00000000 */   nop
.size func_00421a60, 0x10
