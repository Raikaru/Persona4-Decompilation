.section .text
.set noat
.set noreorder
glabel func_00421be0
    /* 321BE0 00421BE0 79000324 */  addiu      $3, $0, 0x79
    /* 321BE4 00421BE4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321BE8 00421BE8 0800E003 */  jr         $31
    /* 321BEC 00421BEC 00000000 */   nop
.size func_00421be0, 0x10
