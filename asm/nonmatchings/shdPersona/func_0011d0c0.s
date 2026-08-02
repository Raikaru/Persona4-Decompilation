.section .text
.set noat
.set noreorder
glabel func_0011d0c0
    /* 1D0C0 0011D0C0 3800828C */  lw         $2, 0x38($4)
    /* 1D0C4 0011D0C4 05054290 */  lbu        $2, 0x505($2)
    /* 1D0C8 0011D0C8 0800E003 */  jr         $31
    /* 1D0CC 0011D0CC 00000000 */   nop
.size func_0011d0c0, 0x10
