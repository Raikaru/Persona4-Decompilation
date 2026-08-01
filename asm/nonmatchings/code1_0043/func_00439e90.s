.section .text
.set noat
.set noreorder
glabel func_00439e90
    /* 339E90 00439E90 24000324 */  addiu      $3, $0, 0x24
    /* 339E94 00439E94 8B00023C */  lui        $2, %hi(D_008AC788)
    /* 339E98 00439E98 18188300 */  mult       $3, $4, $3
    /* 339E9C 00439E9C 88C74224 */  addiu      $2, $2, %lo(D_008AC788)
    /* 339EA0 00439EA0 21104300 */  addu       $2, $2, $3
    /* 339EA4 00439EA4 32E71008 */  j          func_00439cc8
    /* 339EA8 00439EA8 1400488C */   lw        $8, 0x14($2)
    /* 339EAC 00439EAC 00000000 */  nop
.size func_00439e90, 0x20
