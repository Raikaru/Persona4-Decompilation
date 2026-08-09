.section .text
.set noat
.set noreorder
glabel func_0042c1a8
    /* 32C1A8 0042C1A8 5B000324 */  addiu      $3, $0, 0x5B
    /* 32C1AC 0042C1AC 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32C1B0 0042C1B0 0800E003 */  jr         $31
    /* 32C1B4 0042C1B4 00000000 */   nop
.size func_0042c1a8, 0x10
