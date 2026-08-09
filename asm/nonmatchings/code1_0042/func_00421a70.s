.section .text
.set noat
.set noreorder
glabel func_00421a70
    /* 321A70 00421A70 66000324 */  addiu      $3, $0, 0x66
    /* 321A74 00421A74 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A78 00421A78 0800E003 */  jr         $31
    /* 321A7C 00421A7C 00000000 */   nop
.size func_00421a70, 0x10
