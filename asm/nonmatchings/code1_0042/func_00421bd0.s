.section .text
.set noat
.set noreorder
glabel func_00421bd0
    /* 321BD0 00421BD0 88FF0324 */  addiu      $3, $0, -0x78
    /* 321BD4 00421BD4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321BD8 00421BD8 0800E003 */  jr         $31
    /* 321BDC 00421BDC 00000000 */   nop
.size func_00421bd0, 0x10
