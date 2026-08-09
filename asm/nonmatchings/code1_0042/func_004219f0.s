.section .text
.set noat
.set noreorder
glabel func_004219f0
    /* 3219F0 004219F0 A2FF0324 */  addiu      $3, $0, -0x5E
    /* 3219F4 004219F4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3219F8 004219F8 0800E003 */  jr         $31
    /* 3219FC 004219FC 00000000 */   nop
.size func_004219f0, 0x10
