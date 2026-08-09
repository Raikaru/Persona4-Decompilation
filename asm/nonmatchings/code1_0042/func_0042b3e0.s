.section .text
.set noat
.set noreorder
glabel func_0042b3e0
    /* 32B3E0 0042B3E0 56000324 */  addiu      $3, $0, 0x56
    /* 32B3E4 0042B3E4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B3E8 0042B3E8 0800E003 */  jr         $31
    /* 32B3EC 0042B3EC 00000000 */   nop
.size func_0042b3e0, 0x10
