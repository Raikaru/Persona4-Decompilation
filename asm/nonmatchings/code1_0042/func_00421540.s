.section .text
.set noat
.set noreorder
glabel func_00421540
    /* 321540 00421540 16000324 */  addiu      $3, $0, 0x16
    /* 321544 00421544 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321548 00421548 0800E003 */  jr         $31
    /* 32154C 0042154C 00000000 */   nop
.size func_00421540, 0x10
