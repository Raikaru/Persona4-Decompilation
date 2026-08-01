.section .text
.set noat
.set noreorder
glabel func_004e4180
    /* 3E4180 004E4180 7300033C */  lui        $3, %hi(D_00731C3C)
    /* 3E4184 004E4184 0800E003 */  jr         $31
    /* 3E4188 004E4188 3C1C628C */   lw        $2, %lo(D_00731C3C)($3)
    /* 3E418C 004E418C 00000000 */  nop
.size func_004e4180, 0x10
