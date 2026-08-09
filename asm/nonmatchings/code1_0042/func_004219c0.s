.section .text
.set noat
.set noreorder
glabel func_004219c0
    /* 3219C0 004219C0 5D000324 */  addiu      $3, $0, 0x5D
    /* 3219C4 004219C4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3219C8 004219C8 0800E003 */  jr         $31
    /* 3219CC 004219CC 00000000 */   nop
.size func_004219c0, 0x10
