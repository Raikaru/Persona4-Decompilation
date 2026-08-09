.section .text
.set noat
.set noreorder
glabel func_00420b50
    /* 320B50 00420B50 2D288000 */  daddu      $5, $4, $0
    /* 320B54 00420B54 7500043C */  lui        $4, %hi(D_00753E10)
    /* 320B58 00420B58 32911008 */  j          func_004244c8
    /* 320B5C 00420B5C 103E8424 */   addiu     $4, $4, %lo(D_00753E10)
.size func_00420b50, 0x10
