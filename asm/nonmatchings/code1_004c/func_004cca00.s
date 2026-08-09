.section .text
.set noat
.set noreorder
glabel func_004cca00
    /* 3CCA00 004CCA00 7200033C */  lui        $3, %hi(D_007199D0)
    /* 3CCA04 004CCA04 0800E003 */  jr         $31
    /* 3CCA08 004CCA08 D099628C */   lw        $2, %lo(D_007199D0)($3)
    /* 3CCA0C 004CCA0C 00000000 */  nop
.size func_004cca00, 0x10
