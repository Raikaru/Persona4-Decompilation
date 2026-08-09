.section .text
.set noat
.set noreorder
glabel func_00421850
    /* 321850 00421850 47000324 */  addiu      $3, $0, 0x47
    /* 321854 00421854 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321858 00421858 0800E003 */  jr         $31
    /* 32185C 0042185C 00000000 */   nop
.size func_00421850, 0x10
