.section .text
.set noat
.set noreorder
glabel func_0042c150
    /* 32C150 0042C150 74000324 */  addiu      $3, $0, 0x74
    /* 32C154 0042C154 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32C158 0042C158 0800E003 */  jr         $31
    /* 32C15C 0042C15C 00000000 */   nop
.size func_0042c150, 0x10
