.section .text
.set noat
.set noreorder
glabel func_004216b0
    /* 3216B0 004216B0 2D000324 */  addiu      $3, $0, 0x2D
    /* 3216B4 004216B4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3216B8 004216B8 0800E003 */  jr         $31
    /* 3216BC 004216BC 00000000 */   nop
.size func_004216b0, 0x10
