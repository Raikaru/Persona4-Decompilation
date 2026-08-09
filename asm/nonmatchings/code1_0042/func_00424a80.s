.section .text
.set noat
.set noreorder
glabel func_00424a80
    /* 324A80 00424A80 8900033C */  lui        $3, %hi(D_0088DCD8)
    /* 324A84 00424A84 D8DC6324 */  addiu      $3, $3, %lo(D_0088DCD8)
    /* 324A88 00424A88 1400628C */  lw         $2, 0x14($3)
    /* 324A8C 00424A8C 180065AC */  sw         $5, 0x18($3)
    /* 324A90 00424A90 0800E003 */  jr         $31
    /* 324A94 00424A94 140064AC */   sw        $4, 0x14($3)
.size func_00424a80, 0x18
