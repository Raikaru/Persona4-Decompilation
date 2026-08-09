.section .text
.set noat
.set noreorder
glabel func_004218e0
    /* 3218E0 004218E0 50000324 */  addiu      $3, $0, 0x50
    /* 3218E4 004218E4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3218E8 004218E8 0800E003 */  jr         $31
    /* 3218EC 004218EC 00000000 */   nop
.size func_004218e0, 0x10
