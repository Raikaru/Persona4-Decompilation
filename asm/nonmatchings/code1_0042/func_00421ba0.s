.section .text
.set noat
.set noreorder
glabel func_00421ba0
    /* 321BA0 00421BA0 77000324 */  addiu      $3, $0, 0x77
    /* 321BA4 00421BA4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321BA8 00421BA8 0800E003 */  jr         $31
    /* 321BAC 00421BAC 00000000 */   nop
.size func_00421ba0, 0x10
