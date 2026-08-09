.section .text
.set noat
.set noreorder
glabel func_004218f0
    /* 3218F0 004218F0 51000324 */  addiu      $3, $0, 0x51
    /* 3218F4 004218F4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3218F8 004218F8 0800E003 */  jr         $31
    /* 3218FC 004218FC 00000000 */   nop
.size func_004218f0, 0x10
