.section .text
.set noat
.set noreorder
glabel func_00421840
    /* 321840 00421840 BAFF0324 */  addiu      $3, $0, -0x46
    /* 321844 00421844 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321848 00421848 0800E003 */  jr         $31
    /* 32184C 0042184C 00000000 */   nop
.size func_00421840, 0x10
