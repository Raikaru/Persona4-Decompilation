.section .text
.set noat
.set noreorder
glabel func_004cc1f0
    /* 3CC1F0 004CC1F0 7200033C */  lui        $3, %hi(D_00719994)
    /* 3CC1F4 004CC1F4 9499628C */  lw         $2, %lo(D_00719994)($3)
    /* 3CC1F8 004CC1F8 0800E003 */  jr         $31
    /* 3CC1FC 004CC1FC 2B100200 */   sltu      $2, $0, $2
.size func_004cc1f0, 0x10
