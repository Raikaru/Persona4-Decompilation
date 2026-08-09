.section .text
.set noat
.set noreorder
glabel func_00421690
    /* 321690 00421690 2B000324 */  addiu      $3, $0, 0x2B
    /* 321694 00421694 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321698 00421698 0800E003 */  jr         $31
    /* 32169C 0042169C 00000000 */   nop
.size func_00421690, 0x10
