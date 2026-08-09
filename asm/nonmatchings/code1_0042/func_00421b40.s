.section .text
.set noat
.set noreorder
glabel func_00421b40
    /* 321B40 00421B40 72000324 */  addiu      $3, $0, 0x72
    /* 321B44 00421B44 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321B48 00421B48 0800E003 */  jr         $31
    /* 321B4C 00421B4C 00000000 */   nop
.size func_00421b40, 0x10
