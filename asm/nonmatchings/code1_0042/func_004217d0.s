.section .text
.set noat
.set noreorder
glabel func_004217d0
    /* 3217D0 004217D0 3F000324 */  addiu      $3, $0, 0x3F
    /* 3217D4 004217D4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3217D8 004217D8 0800E003 */  jr         $31
    /* 3217DC 004217DC 00000000 */   nop
.size func_004217d0, 0x10
