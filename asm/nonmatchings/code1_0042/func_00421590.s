.section .text
.set noat
.set noreorder
glabel func_00421590
    /* 321590 00421590 E5FF0324 */  addiu      $3, $0, -0x1B
    /* 321594 00421594 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321598 00421598 0800E003 */  jr         $31
    /* 32159C 0042159C 00000000 */   nop
.size func_00421590, 0x10
