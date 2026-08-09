.section .text
.set noat
.set noreorder
glabel func_0042bef0
    /* 32BEF0 0042BEF0 74000324 */  addiu      $3, $0, 0x74
    /* 32BEF4 0042BEF4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32BEF8 0042BEF8 0800E003 */  jr         $31
    /* 32BEFC 0042BEFC 00000000 */   nop
.size func_0042bef0, 0x10
