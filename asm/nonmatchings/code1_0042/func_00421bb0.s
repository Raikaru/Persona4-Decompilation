.section .text
.set noat
.set noreorder
glabel func_00421bb0
    /* 321BB0 00421BB0 89FF0324 */  addiu      $3, $0, -0x77
    /* 321BB4 00421BB4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321BB8 00421BB8 0800E003 */  jr         $31
    /* 321BBC 00421BBC 00000000 */   nop
.size func_00421bb0, 0x10
