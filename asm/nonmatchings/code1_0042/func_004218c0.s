.section .text
.set noat
.set noreorder
glabel func_004218c0
    /* 3218C0 004218C0 4E000324 */  addiu      $3, $0, 0x4E
    /* 3218C4 004218C4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3218C8 004218C8 0800E003 */  jr         $31
    /* 3218CC 004218CC 00000000 */   nop
.size func_004218c0, 0x10
