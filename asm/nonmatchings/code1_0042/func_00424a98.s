.section .text
.set noat
.set noreorder
glabel func_00424a98
    /* 324A98 00424A98 8900033C */  lui        $3, %hi(D_0088DCD8)
    /* 324A9C 00424A9C D8DC6324 */  addiu      $3, $3, %lo(D_0088DCD8)
    /* 324AA0 00424AA0 0C00628C */  lw         $2, 0xC($3)
    /* 324AA4 00424AA4 100065AC */  sw         $5, 0x10($3)
    /* 324AA8 00424AA8 0800E003 */  jr         $31
    /* 324AAC 00424AAC 0C0064AC */   sw        $4, 0xC($3)
.size func_00424a98, 0x18
