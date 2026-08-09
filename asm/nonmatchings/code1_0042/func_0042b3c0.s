.section .text
.set noat
.set noreorder
glabel func_0042b3c0
    /* 32B3C0 0042B3C0 55000324 */  addiu      $3, $0, 0x55
    /* 32B3C4 0042B3C4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B3C8 0042B3C8 0800E003 */  jr         $31
    /* 32B3CC 0042B3CC 00000000 */   nop
.size func_0042b3c0, 0x10
