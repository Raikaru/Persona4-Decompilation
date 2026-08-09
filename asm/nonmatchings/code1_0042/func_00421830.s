.section .text
.set noat
.set noreorder
glabel func_00421830
    /* 321830 00421830 45000324 */  addiu      $3, $0, 0x45
    /* 321834 00421834 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321838 00421838 0800E003 */  jr         $31
    /* 32183C 0042183C 00000000 */   nop
.size func_00421830, 0x10
