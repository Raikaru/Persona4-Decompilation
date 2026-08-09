.section .text
.set noat
.set noreorder
glabel func_00421600
    /* 321600 00421600 22000324 */  addiu      $3, $0, 0x22
    /* 321604 00421604 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321608 00421608 0800E003 */  jr         $31
    /* 32160C 0042160C 00000000 */   nop
.size func_00421600, 0x10
