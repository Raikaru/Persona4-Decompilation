.section .text
.set noat
.set noreorder
glabel func_0042b470
    /* 32B470 0042B470 59000324 */  addiu      $3, $0, 0x59
    /* 32B474 0042B474 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B478 0042B478 0800E003 */  jr         $31
    /* 32B47C 0042B47C 00000000 */   nop
.size func_0042b470, 0x10
