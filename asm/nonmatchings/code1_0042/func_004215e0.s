.section .text
.set noat
.set noreorder
glabel func_004215e0
    /* 3215E0 004215E0 20000324 */  addiu      $3, $0, 0x20
    /* 3215E4 004215E4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3215E8 004215E8 0800E003 */  jr         $31
    /* 3215EC 004215EC 00000000 */   nop
.size func_004215e0, 0x10
