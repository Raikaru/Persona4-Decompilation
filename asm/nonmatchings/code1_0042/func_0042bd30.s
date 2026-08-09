.section .text
.set noat
.set noreorder
glabel func_0042bd30
    /* 32BD30 0042BD30 74000324 */  addiu      $3, $0, 0x74
    /* 32BD34 0042BD34 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32BD38 0042BD38 0800E003 */  jr         $31
    /* 32BD3C 0042BD3C 00000000 */   nop
.size func_0042bd30, 0x10
