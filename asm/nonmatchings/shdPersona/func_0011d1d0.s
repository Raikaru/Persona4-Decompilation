.section .text
.set noat
.set noreorder
glabel func_0011d1d0
    /* 1D1D0 0011D1D0 3800838C */  lw         $3, 0x38($4)
    /* 1D1D4 0011D1D4 3C056CE4 */  swc1       $f12, 0x53C($3)
    /* 1D1D8 0011D1D8 0800E003 */  jr         $31
    /* 1D1DC 0011D1DC 00000000 */   nop
.size func_0011d1d0, 0x10
