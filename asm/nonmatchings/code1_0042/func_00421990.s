.section .text
.set noat
.set noreorder
glabel func_00421990
    /* 321990 00421990 5B000324 */  addiu      $3, $0, 0x5B
    /* 321994 00421994 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321998 00421998 0800E003 */  jr         $31
    /* 32199C 0042199C 00000000 */   nop
.size func_00421990, 0x10
