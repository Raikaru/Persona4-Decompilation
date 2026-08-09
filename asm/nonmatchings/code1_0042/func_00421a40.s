.section .text
.set noat
.set noreorder
glabel func_00421a40
    /* 321A40 00421A40 62000324 */  addiu      $3, $0, 0x62
    /* 321A44 00421A44 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A48 00421A48 0800E003 */  jr         $31
    /* 321A4C 00421A4C 00000000 */   nop
.size func_00421a40, 0x10
