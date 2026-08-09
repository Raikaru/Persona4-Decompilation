.section .text
.set noat
.set noreorder
glabel func_00421490
    /* 321490 00421490 0D000324 */  addiu      $3, $0, 0xD
    /* 321494 00421494 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321498 00421498 0800E003 */  jr         $31
    /* 32149C 0042149C 00000000 */   nop
.size func_00421490, 0x10
