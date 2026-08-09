.section .text
.set noat
.set noreorder
glabel func_00421a20
    /* 321A20 00421A20 60000324 */  addiu      $3, $0, 0x60
    /* 321A24 00421A24 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321A28 00421A28 0800E003 */  jr         $31
    /* 321A2C 00421A2C 00000000 */   nop
.size func_00421a20, 0x10
