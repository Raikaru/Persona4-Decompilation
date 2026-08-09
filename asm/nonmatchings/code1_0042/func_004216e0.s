.section .text
.set noat
.set noreorder
glabel func_004216e0
    /* 3216E0 004216E0 30000324 */  addiu      $3, $0, 0x30
    /* 3216E4 004216E4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3216E8 004216E8 0800E003 */  jr         $31
    /* 3216EC 004216EC 00000000 */   nop
.size func_004216e0, 0x10
