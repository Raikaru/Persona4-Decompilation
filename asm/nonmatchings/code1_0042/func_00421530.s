.section .text
.set noat
.set noreorder
glabel func_00421530
    /* 321530 00421530 15000324 */  addiu      $3, $0, 0x15
    /* 321534 00421534 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321538 00421538 0800E003 */  jr         $31
    /* 32153C 0042153C 00000000 */   nop
.size func_00421530, 0x10
