.section .text
.set noat
.set noreorder
glabel func_004e6480
    /* 3E6480 004E6480 7300033C */  lui        $3, %hi(D_007330CC)
    /* 3E6484 004E6484 0800E003 */  jr         $31
    /* 3E6488 004E6488 CC30628C */   lw        $2, %lo(D_007330CC)($3)
    /* 3E648C 004E648C 00000000 */  nop
.size func_004e6480, 0x10
