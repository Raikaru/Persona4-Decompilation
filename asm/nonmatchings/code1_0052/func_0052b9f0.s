.section .text
.set noat
.set noreorder
glabel func_0052b9f0
    /* 42B9F0 0052B9F0 7400033C */  lui        $3, %hi(D_00745C84)
    /* 42B9F4 0052B9F4 0800E003 */  jr         $31
    /* 42B9F8 0052B9F8 845C628C */   lw        $2, %lo(D_00745C84)($3)
    /* 42B9FC 0052B9FC 00000000 */  nop
.size func_0052b9f0, 0x10
