.section .text
.set noat
.set noreorder
glabel func_0042bd40
    /* 32BD40 0042BD40 5A000324 */  addiu      $3, $0, 0x5A
    /* 32BD44 0042BD44 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32BD48 0042BD48 0800E003 */  jr         $31
    /* 32BD4C 0042BD4C 00000000 */   nop
.size func_0042bd40, 0x10
