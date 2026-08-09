.section .text
.set noat
.set noreorder
glabel func_00421970
    /* 321970 00421970 59000324 */  addiu      $3, $0, 0x59
    /* 321974 00421974 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321978 00421978 0800E003 */  jr         $31
    /* 32197C 0042197C 00000000 */   nop
.size func_00421970, 0x10
