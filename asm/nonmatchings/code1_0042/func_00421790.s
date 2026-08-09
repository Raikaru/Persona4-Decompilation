.section .text
.set noat
.set noreorder
glabel func_00421790
    /* 321790 00421790 3B000324 */  addiu      $3, $0, 0x3B
    /* 321794 00421794 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321798 00421798 0800E003 */  jr         $31
    /* 32179C 0042179C 00000000 */   nop
.size func_00421790, 0x10
