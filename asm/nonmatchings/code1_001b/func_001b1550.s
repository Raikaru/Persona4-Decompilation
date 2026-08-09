.section .text
.set noat
.set noreorder
glabel func_001b1550
    /* B1550 001B1550 ACB3828F */  lw         $2, -0x4C54($28)
    /* B1554 001B1554 CC02428C */  lw         $2, 0x2CC($2)
    /* B1558 001B1558 0800E003 */  jr         $31
    /* B155C 001B155C 00000000 */   nop
.size func_001b1550, 0x10
