.section .text
.set noat
.set noreorder
glabel func_00421a50
    /* 321A50 00421A50 63000324 */  addiu      $3, $0, 0x63
    /* 321A54 00421A54 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A58 00421A58 0800E003 */  jr         $31
    /* 321A5C 00421A5C 00000000 */   nop
.size func_00421a50, 0x10
