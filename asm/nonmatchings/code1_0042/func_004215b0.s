.section .text
.set noat
.set noreorder
glabel func_004215b0
    /* 3215B0 004215B0 E3FF0324 */  addiu      $3, $0, -0x1D
    /* 3215B4 004215B4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3215B8 004215B8 0800E003 */  jr         $31
    /* 3215BC 004215BC 00000000 */   nop
.size func_004215b0, 0x10
