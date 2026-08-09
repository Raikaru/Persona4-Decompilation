.section .text
.set noat
.set noreorder
glabel func_0042b440
    /* 32B440 0042B440 A9FF0324 */  addiu      $3, $0, -0x57
    /* 32B444 0042B444 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B448 0042B448 0800E003 */  jr         $31
    /* 32B44C 0042B44C 00000000 */   nop
.size func_0042b440, 0x10
