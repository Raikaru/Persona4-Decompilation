.section .text
.set noat
.set noreorder
glabel func_004c7e28
    /* 3C7E28 004C7E28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C7E2C 004C7E2C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7E30 004C7E30 7100103C */  lui        $16, %hi(D_00716720)
    /* 3C7E34 004C7E34 0800BFFF */  sd         $31, 0x8($29)
    /* 3C7E38 004C7E38 20671026 */  addiu      $16, $16, %lo(D_00716720)
    /* 3C7E3C 004C7E3C A422130C */  jal        func_004c8a90
    /* 3C7E40 004C7E40 0000048E */   lw        $4, 0x0($16)
    /* 3C7E44 004C7E44 000000AE */  sw         $0, 0x0($16)
    /* 3C7E48 004C7E48 0800BFDF */  ld         $31, 0x8($29)
    /* 3C7E4C 004C7E4C 7100023C */  lui        $2, %hi(D_0071671C)
    /* 3C7E50 004C7E50 0000B0DF */  ld         $16, 0x0($29)
    /* 3C7E54 004C7E54 7100033C */  lui        $3, %hi(D_00716734)
    /* 3C7E58 004C7E58 1C6740AC */  sw         $0, %lo(D_0071671C)($2)
    /* 3C7E5C 004C7E5C 346760AC */  sw         $0, %lo(D_00716734)($3)
    /* 3C7E60 004C7E60 0800E003 */  jr         $31
    /* 3C7E64 004C7E64 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c7e28, 0x40
