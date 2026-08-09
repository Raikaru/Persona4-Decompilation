.section .text
.set noat
.set noreorder
glabel func_004219b0
    /* 3219B0 004219B0 A4FF0324 */  addiu      $3, $0, -0x5C
    /* 3219B4 004219B4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3219B8 004219B8 0800E003 */  jr         $31
    /* 3219BC 004219BC 00000000 */   nop
.size func_004219b0, 0x10
