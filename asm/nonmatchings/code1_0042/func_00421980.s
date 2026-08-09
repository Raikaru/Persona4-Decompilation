.section .text
.set noat
.set noreorder
glabel func_00421980
    /* 321980 00421980 A6FF0324 */  addiu      $3, $0, -0x5A
    /* 321984 00421984 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321988 00421988 0800E003 */  jr         $31
    /* 32198C 0042198C 00000000 */   nop
.size func_00421980, 0x10
