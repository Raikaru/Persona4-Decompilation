.section .text
.set noat
.set noreorder
glabel func_004217c0
    /* 3217C0 004217C0 3E000324 */  addiu      $3, $0, 0x3E
    /* 3217C4 004217C4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3217C8 004217C8 0800E003 */  jr         $31
    /* 3217CC 004217CC 00000000 */   nop
.size func_004217c0, 0x10
