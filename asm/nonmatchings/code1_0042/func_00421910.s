.section .text
.set noat
.set noreorder
glabel func_00421910
    /* 321910 00421910 ADFF0324 */  addiu      $3, $0, -0x53
    /* 321914 00421914 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321918 00421918 0800E003 */  jr         $31
    /* 32191C 0042191C 00000000 */   nop
.size func_00421910, 0x10
