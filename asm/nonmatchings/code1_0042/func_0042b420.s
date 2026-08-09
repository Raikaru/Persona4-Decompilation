.section .text
.set noat
.set noreorder
glabel func_0042b420
    /* 32B420 0042B420 AAFF0324 */  addiu      $3, $0, -0x56
    /* 32B424 0042B424 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B428 0042B428 0800E003 */  jr         $31
    /* 32B42C 0042B42C 00000000 */   nop
.size func_0042b420, 0x10
