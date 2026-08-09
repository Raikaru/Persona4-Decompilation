.section .text
.set noat
.set noreorder
glabel func_004214d0
    /* 3214D0 004214D0 10000324 */  addiu      $3, $0, 0x10
    /* 3214D4 004214D4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3214D8 004214D8 0800E003 */  jr         $31
    /* 3214DC 004214DC 00000000 */   nop
.size func_004214d0, 0x10
