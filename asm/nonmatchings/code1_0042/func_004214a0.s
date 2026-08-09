.section .text
.set noat
.set noreorder
glabel func_004214a0
    /* 3214A0 004214A0 0E000324 */  addiu      $3, $0, 0xE
    /* 3214A4 004214A4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3214A8 004214A8 0800E003 */  jr         $31
    /* 3214AC 004214AC 00000000 */   nop
.size func_004214a0, 0x10
