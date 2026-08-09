.section .text
.set noat
.set noreorder
glabel func_00421630
    /* 321630 00421630 25000324 */  addiu      $3, $0, 0x25
    /* 321634 00421634 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321638 00421638 0800E003 */  jr         $31
    /* 32163C 0042163C 00000000 */   nop
.size func_00421630, 0x10
