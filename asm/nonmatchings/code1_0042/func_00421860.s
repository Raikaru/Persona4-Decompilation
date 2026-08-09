.section .text
.set noat
.set noreorder
glabel func_00421860
    /* 321860 00421860 B8FF0324 */  addiu      $3, $0, -0x48
    /* 321864 00421864 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321868 00421868 0800E003 */  jr         $31
    /* 32186C 0042186C 00000000 */   nop
.size func_00421860, 0x10
