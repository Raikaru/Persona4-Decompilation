.section .text
.set noat
.set noreorder
glabel func_00421af0
    /* 321AF0 00421AF0 6F000324 */  addiu      $3, $0, 0x6F
    /* 321AF4 00421AF4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321AF8 00421AF8 0800E003 */  jr         $31
    /* 321AFC 00421AFC 00000000 */   nop
.size func_00421af0, 0x10
