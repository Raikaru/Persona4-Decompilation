.section .text
.set noat
.set noreorder
glabel func_0042baf8
    /* 32BAF8 0042BAF8 5A000324 */  addiu      $3, $0, 0x5A
    /* 32BAFC 0042BAFC 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32BB00 0042BB00 0800E003 */  jr         $31
    /* 32BB04 0042BB04 00000000 */   nop
.size func_0042baf8, 0x10
