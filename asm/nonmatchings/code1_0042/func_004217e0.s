.section .text
.set noat
.set noreorder
glabel func_004217e0
    /* 3217E0 004217E0 40000324 */  addiu      $3, $0, 0x40
    /* 3217E4 004217E4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3217E8 004217E8 0800E003 */  jr         $31
    /* 3217EC 004217EC 00000000 */   nop
.size func_004217e0, 0x10
