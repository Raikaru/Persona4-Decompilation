.section .text
.set noat
.set noreorder
glabel func_0011dec0
    /* 1DEC0 0011DEC0 3800828C */  lw         $2, 0x38($4)
    /* 1DEC4 0011DEC4 0800428C */  lw         $2, 0x8($2)
    /* 1DEC8 0011DEC8 0800E003 */  jr         $31
    /* 1DECC 0011DECC 00000000 */   nop
.size func_0011dec0, 0x10
