.section .text
.set noat
.set noreorder
glabel func_00421760
    /* 321760 00421760 C8FF0324 */  addiu      $3, $0, -0x38
    /* 321764 00421764 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321768 00421768 0800E003 */  jr         $31
    /* 32176C 0042176C 00000000 */   nop
.size func_00421760, 0x10
