.section .text
.set noat
.set noreorder
glabel func_00421550
    /* 321550 00421550 17000324 */  addiu      $3, $0, 0x17
    /* 321554 00421554 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321558 00421558 0800E003 */  jr         $31
    /* 32155C 0042155C 00000000 */   nop
.size func_00421550, 0x10
