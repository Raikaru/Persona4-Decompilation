.section .text
.set noat
.set noreorder
glabel func_004215f0
    /* 3215F0 004215F0 21000324 */  addiu      $3, $0, 0x21
    /* 3215F4 004215F4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3215F8 004215F8 0800E003 */  jr         $31
    /* 3215FC 004215FC 00000000 */   nop
.size func_004215f0, 0x10
