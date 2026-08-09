.section .text
.set noat
.set noreorder
glabel func_004214e0
    /* 3214E0 004214E0 11000324 */  addiu      $3, $0, 0x11
    /* 3214E4 004214E4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3214E8 004214E8 0800E003 */  jr         $31
    /* 3214EC 004214EC 00000000 */   nop
.size func_004214e0, 0x10
