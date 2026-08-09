.section .text
.set noat
.set noreorder
glabel func_00421750
    /* 321750 00421750 37000324 */  addiu      $3, $0, 0x37
    /* 321754 00421754 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321758 00421758 0800E003 */  jr         $31
    /* 32175C 0042175C 00000000 */   nop
.size func_00421750, 0x10
