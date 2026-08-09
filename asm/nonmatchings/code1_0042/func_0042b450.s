.section .text
.set noat
.set noreorder
glabel func_0042b450
    /* 32B450 0042B450 58000324 */  addiu      $3, $0, 0x58
    /* 32B454 0042B454 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B458 0042B458 0800E003 */  jr         $31
    /* 32B45C 0042B45C 00000000 */   nop
.size func_0042b450, 0x10
