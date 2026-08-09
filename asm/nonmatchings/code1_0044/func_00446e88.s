.section .text
.set noat
.set noreorder
glabel func_00446e88
    /* 346E88 00446E88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 346E8C 00446E8C 71000F3C */  lui        $15, %hi(D_00710070)
    /* 346E90 00446E90 0000BFFF */  sd         $31, 0x0($29)
    /* 346E94 00446E94 2D30A000 */  daddu      $6, $5, $0
    /* 346E98 00446E98 7000EE8D */  lw         $14, %lo(D_00710070)($15)
    /* 346E9C 00446E9C 2D288000 */  daddu      $5, $4, $0
    /* 346EA0 00446EA0 0000BFDF */  ld         $31, 0x0($29)
    /* 346EA4 00446EA4 0800C48D */  lw         $4, 0x8($14)
    /* 346EA8 00446EA8 FE111108 */  j          func_004447f8
    /* 346EAC 00446EAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00446e88, 0x28
