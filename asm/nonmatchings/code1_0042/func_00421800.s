.section .text
.set noat
.set noreorder
glabel func_00421800
    /* 321800 00421800 42000324 */  addiu      $3, $0, 0x42
    /* 321804 00421804 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321808 00421808 0800E003 */  jr         $31
    /* 32180C 0042180C 00000000 */   nop
.size func_00421800, 0x10
