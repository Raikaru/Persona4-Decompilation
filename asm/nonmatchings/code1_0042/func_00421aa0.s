.section .text
.set noat
.set noreorder
glabel func_00421aa0
    /* 321AA0 00421AA0 96FF0324 */  addiu      $3, $0, -0x6A
    /* 321AA4 00421AA4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321AA8 00421AA8 0800E003 */  jr         $31
    /* 321AAC 00421AAC 00000000 */   nop
.size func_00421aa0, 0x10
