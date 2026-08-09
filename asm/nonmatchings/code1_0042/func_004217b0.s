.section .text
.set noat
.set noreorder
glabel func_004217b0
    /* 3217B0 004217B0 3D000324 */  addiu      $3, $0, 0x3D
    /* 3217B4 004217B4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3217B8 004217B8 0800E003 */  jr         $31
    /* 3217BC 004217BC 00000000 */   nop
.size func_004217b0, 0x10
