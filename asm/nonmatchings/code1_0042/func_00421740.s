.section .text
.set noat
.set noreorder
glabel func_00421740
    /* 321740 00421740 CAFF0324 */  addiu      $3, $0, -0x36
    /* 321744 00421744 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321748 00421748 0800E003 */  jr         $31
    /* 32174C 0042174C 00000000 */   nop
.size func_00421740, 0x10
