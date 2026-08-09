.section .text
.set noat
.set noreorder
glabel func_00421770
    /* 321770 00421770 39000324 */  addiu      $3, $0, 0x39
    /* 321774 00421774 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321778 00421778 0800E003 */  jr         $31
    /* 32177C 0042177C 00000000 */   nop
.size func_00421770, 0x10
