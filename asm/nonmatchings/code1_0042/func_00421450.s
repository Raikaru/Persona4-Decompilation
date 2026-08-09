.section .text
.set noat
.set noreorder
glabel func_00421450
    /* 321450 00421450 09000324 */  addiu      $3, $0, 0x9
    /* 321454 00421454 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321458 00421458 0800E003 */  jr         $31
    /* 32145C 0042145C 00000000 */   nop
.size func_00421450, 0x10
