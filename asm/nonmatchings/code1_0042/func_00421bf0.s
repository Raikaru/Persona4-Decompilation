.section .text
.set noat
.set noreorder
glabel func_00421bf0
    /* 321BF0 00421BF0 7A000324 */  addiu      $3, $0, 0x7A
    /* 321BF4 00421BF4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321BF8 00421BF8 0800E003 */  jr         $31
    /* 321BFC 00421BFC 00000000 */   nop
.size func_00421bf0, 0x10
