.section .text
.set noat
.set noreorder
glabel func_004216c0
    /* 3216C0 004216C0 D2FF0324 */  addiu      $3, $0, -0x2E
    /* 3216C4 004216C4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3216C8 004216C8 0800E003 */  jr         $31
    /* 3216CC 004216CC 00000000 */   nop
.size func_004216c0, 0x10
