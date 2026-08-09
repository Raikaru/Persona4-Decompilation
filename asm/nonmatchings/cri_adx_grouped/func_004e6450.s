.section .text
.set noat
.set noreorder
glabel func_004e6450
    /* 3E6450 004E6450 7300033C */  lui        $3, %hi(D_00733DC8)
    /* 3E6454 004E6454 0800E003 */  jr         $31
    /* 3E6458 004E6458 C83D628C */   lw        $2, %lo(D_00733DC8)($3)
    /* 3E645C 004E645C 00000000 */  nop
.size func_004e6450, 0x10
