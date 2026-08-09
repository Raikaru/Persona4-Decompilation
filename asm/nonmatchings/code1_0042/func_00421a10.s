.section .text
.set noat
.set noreorder
glabel func_00421a10
    /* 321A10 00421A10 A1FF0324 */  addiu      $3, $0, -0x5F
    /* 321A14 00421A14 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A18 00421A18 0800E003 */  jr         $31
    /* 321A1C 00421A1C 00000000 */   nop
.size func_00421a10, 0x10
