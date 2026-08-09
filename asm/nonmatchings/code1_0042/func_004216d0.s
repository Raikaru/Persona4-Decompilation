.section .text
.set noat
.set noreorder
glabel func_004216d0
    /* 3216D0 004216D0 2F000324 */  addiu      $3, $0, 0x2F
    /* 3216D4 004216D4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3216D8 004216D8 0800E003 */  jr         $31
    /* 3216DC 004216DC 00000000 */   nop
.size func_004216d0, 0x10
