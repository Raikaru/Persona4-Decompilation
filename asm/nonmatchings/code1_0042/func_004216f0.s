.section .text
.set noat
.set noreorder
glabel func_004216f0
    /* 3216F0 004216F0 CFFF0324 */  addiu      $3, $0, -0x31
    /* 3216F4 004216F4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3216F8 004216F8 0800E003 */  jr         $31
    /* 3216FC 004216FC 00000000 */   nop
.size func_004216f0, 0x10
