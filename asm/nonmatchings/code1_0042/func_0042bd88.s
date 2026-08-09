.section .text
.set noat
.set noreorder
glabel func_0042bd88
    /* 32BD88 0042BD88 5B000324 */  addiu      $3, $0, 0x5B
    /* 32BD8C 0042BD8C 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32BD90 0042BD90 0800E003 */  jr         $31
    /* 32BD94 0042BD94 00000000 */   nop
.size func_0042bd88, 0x10
