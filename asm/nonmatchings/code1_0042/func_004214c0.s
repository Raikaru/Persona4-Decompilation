.section .text
.set noat
.set noreorder
glabel func_004214c0
    /* 3214C0 004214C0 10000324 */  addiu      $3, $0, 0x10
    /* 3214C4 004214C4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3214C8 004214C8 0800E003 */  jr         $31
    /* 3214CC 004214CC 00000000 */   nop
.size func_004214c0, 0x10
