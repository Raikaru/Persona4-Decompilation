.section .text
.set noat
.set noreorder
glabel func_0042b290
    /* 32B290 0042B290 5A000324 */  addiu      $3, $0, 0x5A
    /* 32B294 0042B294 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B298 0042B298 0800E003 */  jr         $31
    /* 32B29C 0042B29C 00000000 */   nop
.size func_0042b290, 0x10
