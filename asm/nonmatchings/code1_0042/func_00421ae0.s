.section .text
.set noat
.set noreorder
glabel func_00421ae0
    /* 321AE0 00421AE0 6E000324 */  addiu      $3, $0, 0x6E
    /* 321AE4 00421AE4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321AE8 00421AE8 0800E003 */  jr         $31
    /* 321AEC 00421AEC 00000000 */   nop
.size func_00421ae0, 0x10
