.section .text
.set noat
.set noreorder
glabel func_00421640
    /* 321640 00421640 DAFF0324 */  addiu      $3, $0, -0x26
    /* 321644 00421644 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321648 00421648 0800E003 */  jr         $31
    /* 32164C 0042164C 00000000 */   nop
.size func_00421640, 0x10
