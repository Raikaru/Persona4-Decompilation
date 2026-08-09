.section .text
.set noat
.set noreorder
glabel func_0042b2e8
    /* 32B2E8 0042B2E8 74000324 */  addiu      $3, $0, 0x74
    /* 32B2EC 0042B2EC 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B2F0 0042B2F0 0800E003 */  jr         $31
    /* 32B2F4 0042B2F4 00000000 */   nop
.size func_0042b2e8, 0x10
