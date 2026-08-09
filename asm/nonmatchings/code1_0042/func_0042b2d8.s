.section .text
.set noat
.set noreorder
glabel func_0042b2d8
    /* 32B2D8 0042B2D8 5B000324 */  addiu      $3, $0, 0x5B
    /* 32B2DC 0042B2DC 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B2E0 0042B2E0 0800E003 */  jr         $31
    /* 32B2E4 0042B2E4 00000000 */   nop
.size func_0042b2d8, 0x10
