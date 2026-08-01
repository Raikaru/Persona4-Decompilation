.section .text
.set noat
.set noreorder
glabel func_004e4688
    /* 3E4688 004E4688 7300033C */  lui        $3, %hi(D_00731C70)
    /* 3E468C 004E468C 0800E003 */  jr         $31
    /* 3E4690 004E4690 701C628C */   lw        $2, %lo(D_00731C70)($3)
    /* 3E4694 004E4694 00000000 */  nop
.size func_004e4688, 0x10
