.section .text
.set noat
.set noreorder
glabel func_004cc1e0
    /* 3CC1E0 004CC1E0 7200033C */  lui        $3, %hi(D_00719998)
    /* 3CC1E4 004CC1E4 0800E003 */  jr         $31
    /* 3CC1E8 004CC1E8 9899628C */   lw        $2, %lo(D_00719998)($3)
    /* 3CC1EC 004CC1EC 00000000 */  nop
.size func_004cc1e0, 0x10
