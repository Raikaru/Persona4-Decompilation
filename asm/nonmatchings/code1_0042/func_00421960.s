.section .text
.set noat
.set noreorder
glabel func_00421960
    /* 321960 00421960 A8FF0324 */  addiu      $3, $0, -0x58
    /* 321964 00421964 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321968 00421968 0800E003 */  jr         $31
    /* 32196C 0042196C 00000000 */   nop
.size func_00421960, 0x10
