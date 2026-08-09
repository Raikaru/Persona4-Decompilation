.section .text
.set noat
.set noreorder
glabel func_0042bb80
    /* 32BB80 0042BB80 83000324 */  addiu      $3, $0, 0x83
    /* 32BB84 0042BB84 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32BB88 0042BB88 0800E003 */  jr         $31
    /* 32BB8C 0042BB8C 00000000 */   nop
.size func_0042bb80, 0x10
