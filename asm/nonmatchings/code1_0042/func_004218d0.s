.section .text
.set noat
.set noreorder
glabel func_004218d0
    /* 3218D0 004218D0 4F000324 */  addiu      $3, $0, 0x4F
    /* 3218D4 004218D4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3218D8 004218D8 0800E003 */  jr         $31
    /* 3218DC 004218DC 00000000 */   nop
.size func_004218d0, 0x10
