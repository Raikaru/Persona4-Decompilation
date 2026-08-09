.section .text
.set noat
.set noreorder
glabel func_00421b00
    /* 321B00 00421B00 70000324 */  addiu      $3, $0, 0x70
    /* 321B04 00421B04 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B08 00421B08 0800E003 */  jr         $31
    /* 321B0C 00421B0C 00000000 */   nop
.size func_00421b00, 0x10
