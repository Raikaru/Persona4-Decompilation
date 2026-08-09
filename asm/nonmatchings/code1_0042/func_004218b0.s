.section .text
.set noat
.set noreorder
glabel func_004218b0
    /* 3218B0 004218B0 4D000324 */  addiu      $3, $0, 0x4D
    /* 3218B4 004218B4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3218B8 004218B8 0800E003 */  jr         $31
    /* 3218BC 004218BC 00000000 */   nop
.size func_004218b0, 0x10
