.section .text
.set noat
.set noreorder
glabel func_00421920
    /* 321920 00421920 54000324 */  addiu      $3, $0, 0x54
    /* 321924 00421924 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321928 00421928 0800E003 */  jr         $31
    /* 32192C 0042192C 00000000 */   nop
.size func_00421920, 0x10
