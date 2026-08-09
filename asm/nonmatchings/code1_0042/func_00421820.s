.section .text
.set noat
.set noreorder
glabel func_00421820
    /* 321820 00421820 44000324 */  addiu      $3, $0, 0x44
    /* 321824 00421824 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321828 00421828 0800E003 */  jr         $31
    /* 32182C 0042182C 00000000 */   nop
.size func_00421820, 0x10
