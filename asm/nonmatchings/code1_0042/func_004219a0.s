.section .text
.set noat
.set noreorder
glabel func_004219a0
    /* 3219A0 004219A0 5C000324 */  addiu      $3, $0, 0x5C
    /* 3219A4 004219A4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3219A8 004219A8 0800E003 */  jr         $31
    /* 3219AC 004219AC 00000000 */   nop
.size func_004219a0, 0x10
