.section .text
.set noat
.set noreorder
glabel func_004214b0
    /* 3214B0 004214B0 0F000324 */  addiu      $3, $0, 0xF
    /* 3214B4 004214B4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3214B8 004214B8 0800E003 */  jr         $31
    /* 3214BC 004214BC 00000000 */   nop
.size func_004214b0, 0x10
