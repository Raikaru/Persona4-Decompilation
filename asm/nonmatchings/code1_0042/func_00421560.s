.section .text
.set noat
.set noreorder
glabel func_00421560
    /* 321560 00421560 FC000324 */  addiu      $3, $0, 0xFC
    /* 321564 00421564 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321568 00421568 0800E003 */  jr         $31
    /* 32156C 0042156C 00000000 */   nop
.size func_00421560, 0x10
