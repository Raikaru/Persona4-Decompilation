.section .text
.set noat
.set noreorder
glabel func_00421780
    /* 321780 00421780 C6FF0324 */  addiu      $3, $0, -0x3A
    /* 321784 00421784 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321788 00421788 0800E003 */  jr         $31
    /* 32178C 0042178C 00000000 */   nop
.size func_00421780, 0x10
