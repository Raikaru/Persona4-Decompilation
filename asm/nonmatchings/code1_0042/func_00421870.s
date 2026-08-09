.section .text
.set noat
.set noreorder
glabel func_00421870
    /* 321870 00421870 49000324 */  addiu      $3, $0, 0x49
    /* 321874 00421874 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321878 00421878 0800E003 */  jr         $31
    /* 32187C 0042187C 00000000 */   nop
.size func_00421870, 0x10
