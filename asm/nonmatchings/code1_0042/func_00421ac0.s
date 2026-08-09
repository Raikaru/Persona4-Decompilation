.section .text
.set noat
.set noreorder
glabel func_00421ac0
    /* 321AC0 00421AC0 6C000324 */  addiu      $3, $0, 0x6C
    /* 321AC4 00421AC4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321AC8 00421AC8 0800E003 */  jr         $31
    /* 321ACC 00421ACC 00000000 */   nop
.size func_00421ac0, 0x10
