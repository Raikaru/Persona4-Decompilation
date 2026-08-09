.section .text
.set noat
.set noreorder
glabel func_004216a0
    /* 3216A0 004216A0 D4FF0324 */  addiu      $3, $0, -0x2C
    /* 3216A4 004216A4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3216A8 004216A8 0800E003 */  jr         $31
    /* 3216AC 004216AC 00000000 */   nop
.size func_004216a0, 0x10
