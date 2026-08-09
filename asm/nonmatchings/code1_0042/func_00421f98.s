.section .text
.set noat
.set noreorder
glabel func_00421f98
    /* 321F98 00421F98 00200224 */  addiu      $2, $0, 0x2000
    /* 321F9C 00421F9C 4800A0FC */  sd         $0, 0x48($5)
    /* 321FA0 00421FA0 0400A2AC */  sw         $2, 0x4($5)
    /* 321FA4 00421FA4 0800E003 */  jr         $31
    /* 321FA8 00421FA8 2D100000 */   daddu     $2, $0, $0
    /* 321FAC 00421FAC 00000000 */  nop
.size func_00421f98, 0x18
