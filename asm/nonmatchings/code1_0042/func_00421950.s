.section .text
.set noat
.set noreorder
glabel func_00421950
    /* 321950 00421950 57000324 */  addiu      $3, $0, 0x57
    /* 321954 00421954 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321958 00421958 0800E003 */  jr         $31
    /* 32195C 0042195C 00000000 */   nop
.size func_00421950, 0x10
