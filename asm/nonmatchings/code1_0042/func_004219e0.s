.section .text
.set noat
.set noreorder
glabel func_004219e0
    /* 3219E0 004219E0 5E000324 */  addiu      $3, $0, 0x5E
    /* 3219E4 004219E4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3219E8 004219E8 0800E003 */  jr         $31
    /* 3219EC 004219EC 00000000 */   nop
.size func_004219e0, 0x10
