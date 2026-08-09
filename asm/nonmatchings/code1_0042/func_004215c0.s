.section .text
.set noat
.set noreorder
glabel func_004215c0
    /* 3215C0 004215C0 02FF0324 */  addiu      $3, $0, -0xFE
    /* 3215C4 004215C4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3215C8 004215C8 0800E003 */  jr         $31
    /* 3215CC 004215CC 00000000 */   nop
.size func_004215c0, 0x10
