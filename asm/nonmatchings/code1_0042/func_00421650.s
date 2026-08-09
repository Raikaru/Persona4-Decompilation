.section .text
.set noat
.set noreorder
glabel func_00421650
    /* 321650 00421650 27000324 */  addiu      $3, $0, 0x27
    /* 321654 00421654 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321658 00421658 0800E003 */  jr         $31
    /* 32165C 0042165C 00000000 */   nop
.size func_00421650, 0x10
