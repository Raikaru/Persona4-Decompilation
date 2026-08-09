.section .text
.set noat
.set noreorder
glabel func_00421480
    /* 321480 00421480 0C000324 */  addiu      $3, $0, 0xC
    /* 321484 00421484 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321488 00421488 0800E003 */  jr         $31
    /* 32148C 0042148C 00000000 */   nop
.size func_00421480, 0x10
