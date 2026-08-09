.section .text
.set noat
.set noreorder
glabel func_004e46f0
    /* 3E46F0 004E46F0 7300033C */  lui        $3, %hi(D_00731C74)
    /* 3E46F4 004E46F4 0800E003 */  jr         $31
    /* 3E46F8 004E46F8 741C628C */   lw        $2, %lo(D_00731C74)($3)
    /* 3E46FC 004E46FC 00000000 */  nop
.size func_004e46f0, 0x10
