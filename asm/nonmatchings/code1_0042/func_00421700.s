.section .text
.set noat
.set noreorder
glabel func_00421700
    /* 321700 00421700 32000324 */  addiu      $3, $0, 0x32
    /* 321704 00421704 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321708 00421708 0800E003 */  jr         $31
    /* 32170C 0042170C 00000000 */   nop
.size func_00421700, 0x10
