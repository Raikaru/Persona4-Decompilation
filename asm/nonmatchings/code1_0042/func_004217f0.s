.section .text
.set noat
.set noreorder
glabel func_004217f0
    /* 3217F0 004217F0 41000324 */  addiu      $3, $0, 0x41
    /* 3217F4 004217F4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3217F8 004217F8 0800E003 */  jr         $31
    /* 3217FC 004217FC 00000000 */   nop
.size func_004217f0, 0x10
