.section .text
.set noat
.set noreorder
glabel func_00421b20
    /* 321B20 00421B20 71000324 */  addiu      $3, $0, 0x71
    /* 321B24 00421B24 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B28 00421B28 0800E003 */  jr         $31
    /* 321B2C 00421B2C 00000000 */   nop
.size func_00421b20, 0x10
