.section .text
.set noat
.set noreorder
glabel func_00421710
    /* 321710 00421710 33000324 */  addiu      $3, $0, 0x33
    /* 321714 00421714 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321718 00421718 0800E003 */  jr         $31
    /* 32171C 0042171C 00000000 */   nop
.size func_00421710, 0x10
