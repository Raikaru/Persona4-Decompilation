.section .text
.set noat
.set noreorder
glabel func_00421810
    /* 321810 00421810 BDFF0324 */  addiu      $3, $0, -0x43
    /* 321814 00421814 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321818 00421818 0800E003 */  jr         $31
    /* 32181C 0042181C 00000000 */   nop
.size func_00421810, 0x10
