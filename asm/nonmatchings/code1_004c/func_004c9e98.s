.section .text
.set noat
.set noreorder
glabel func_004c9e98
    /* 3C9E98 004C9E98 7200033C */  lui        $3, %hi(D_00718888)
    /* 3C9E9C 004C9E9C 88886324 */  addiu      $3, $3, %lo(D_00718888)
    /* 3C9EA0 004C9EA0 0000628C */  lw         $2, 0x0($3)
    /* 3C9EA4 004C9EA4 0800E003 */  jr         $31
    /* 3C9EA8 004C9EA8 2B100200 */   sltu      $2, $0, $2
    /* 3C9EAC 004C9EAC 00000000 */  nop
.size func_004c9e98, 0x18
