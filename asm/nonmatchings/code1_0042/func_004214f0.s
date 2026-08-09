.section .text
.set noat
.set noreorder
glabel func_004214f0
    /* 3214F0 004214F0 12000324 */  addiu      $3, $0, 0x12
    /* 3214F4 004214F4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3214F8 004214F8 0800E003 */  jr         $31
    /* 3214FC 004214FC 00000000 */   nop
.size func_004214f0, 0x10
