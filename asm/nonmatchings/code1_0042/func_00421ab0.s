.section .text
.set noat
.set noreorder
glabel func_00421ab0
    /* 321AB0 00421AB0 6B000324 */  addiu      $3, $0, 0x6B
    /* 321AB4 00421AB4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321AB8 00421AB8 0800E003 */  jr         $31
    /* 321ABC 00421ABC 00000000 */   nop
.size func_00421ab0, 0x10
