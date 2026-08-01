.section .text
.set noat
.set noreorder
glabel func_0052ba10
    /* 42BA10 0052BA10 7400033C */  lui        $3, %hi(D_00745C6C)
    /* 42BA14 0052BA14 0800E003 */  jr         $31
    /* 42BA18 0052BA18 6C5C628C */   lw        $2, %lo(D_00745C6C)($3)
    /* 42BA1C 0052BA1C 00000000 */  nop
.size func_0052ba10, 0x10
