.section .text
.set noat
.set noreorder
glabel func_00421a00
    /* 321A00 00421A00 5F000324 */  addiu      $3, $0, 0x5F
    /* 321A04 00421A04 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A08 00421A08 0800E003 */  jr         $31
    /* 321A0C 00421A0C 00000000 */   nop
.size func_00421a00, 0x10
