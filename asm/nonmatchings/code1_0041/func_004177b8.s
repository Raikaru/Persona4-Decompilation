.section .text
.set noat
.set noreorder
glabel func_004177b8
    /* 3177B8 004177B8 80000324 */  addiu      $3, $0, 0x80
    /* 3177BC 004177BC 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3177C0 004177C0 0800E003 */  jr         $31
    /* 3177C4 004177C4 00000000 */   nop
.size func_004177b8, 0x10
