.section .text
.set noat
.set noreorder
glabel func_004e4290
    /* 3E4290 004E4290 7300033C */  lui        $3, %hi(D_00731C34)
    /* 3E4294 004E4294 0800E003 */  jr         $31
    /* 3E4298 004E4298 341C628C */   lw        $2, %lo(D_00731C34)($3)
    /* 3E429C 004E429C 00000000 */  nop
.size func_004e4290, 0x10
