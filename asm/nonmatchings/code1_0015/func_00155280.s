.section .text
.set noat
.set noreorder
glabel func_00155280
    /* 55280 00155280 7D00023C */  lui        $2, %hi(D_007D2510)
    /* 55284 00155284 10254224 */  addiu      $2, $2, %lo(D_007D2510)
    /* 55288 00155288 0800E003 */  jr         $31
    /* 5528C 0015528C 00000000 */   nop
.size func_00155280, 0x10
