.section .text
.set noat
.set noreorder
glabel func_00421b80
    /* 321B80 00421B80 76000324 */  addiu      $3, $0, 0x76
    /* 321B84 00421B84 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B88 00421B88 0800E003 */  jr         $31
    /* 321B8C 00421B8C 00000000 */   nop
.size func_00421b80, 0x10
