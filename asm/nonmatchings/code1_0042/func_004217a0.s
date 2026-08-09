.section .text
.set noat
.set noreorder
glabel func_004217a0
    /* 3217A0 004217A0 3C000324 */  addiu      $3, $0, 0x3C
    /* 3217A4 004217A4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3217A8 004217A8 0800E003 */  jr         $31
    /* 3217AC 004217AC 00000000 */   nop
.size func_004217a0, 0x10
