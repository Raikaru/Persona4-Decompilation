.section .text
.set noat
.set noreorder
glabel func_0042bcc8
    /* 32BCC8 0042BCC8 74000324 */  addiu      $3, $0, 0x74
    /* 32BCCC 0042BCCC 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32BCD0 0042BCD0 0800E003 */  jr         $31
    /* 32BCD4 0042BCD4 00000000 */   nop
.size func_0042bcc8, 0x10
