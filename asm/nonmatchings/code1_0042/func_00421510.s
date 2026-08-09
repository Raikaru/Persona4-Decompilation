.section .text
.set noat
.set noreorder
glabel func_00421510
    /* 321510 00421510 13000324 */  addiu      $3, $0, 0x13
    /* 321514 00421514 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321518 00421518 0800E003 */  jr         $31
    /* 32151C 0042151C 00000000 */   nop
.size func_00421510, 0x10
