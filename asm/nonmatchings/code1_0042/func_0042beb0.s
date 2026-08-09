.section .text
.set noat
.set noreorder
glabel func_0042beb0
    /* 32BEB0 0042BEB0 5A000324 */  addiu      $3, $0, 0x5A
    /* 32BEB4 0042BEB4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32BEB8 0042BEB8 0800E003 */  jr         $31
    /* 32BEBC 0042BEBC 00000000 */   nop
.size func_0042beb0, 0x10
