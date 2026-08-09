.section .text
.set noat
.set noreorder
glabel func_00421ad0
    /* 321AD0 00421AD0 6D000324 */  addiu      $3, $0, 0x6D
    /* 321AD4 00421AD4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321AD8 00421AD8 0800E003 */  jr         $31
    /* 321ADC 00421ADC 00000000 */   nop
.size func_00421ad0, 0x10
