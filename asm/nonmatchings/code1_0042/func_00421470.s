.section .text
.set noat
.set noreorder
glabel func_00421470
    /* 321470 00421470 0B000324 */  addiu      $3, $0, 0xB
    /* 321474 00421474 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321478 00421478 0800E003 */  jr         $31
    /* 32147C 0042147C 00000000 */   nop
.size func_00421470, 0x10
