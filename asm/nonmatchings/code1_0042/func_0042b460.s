.section .text
.set noat
.set noreorder
glabel func_0042b460
    /* 32B460 0042B460 A8FF0324 */  addiu      $3, $0, -0x58
    /* 32B464 0042B464 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B468 0042B468 0800E003 */  jr         $31
    /* 32B46C 0042B46C 00000000 */   nop
.size func_0042b460, 0x10
